#include <fcntl.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <time.h>

#define OBJ_BUFSZ 256
#define LINE_BUFSZ 512

typedef struct {
    // ─────────────────────────────────────────────────────────────────────────
    // Metadati dell’asta corrente (impostati dal Giudice ad ogni round)
    // ─────────────────────────────────────────────────────────────────────────
    int  auction_index;                         // numero progressivo dell’asta (1..M)
    char object_description[OBJ_BUFSZ];         // nome/descrizione dell’oggetto
    int  minimum_offer;                         // offerta minima ammessa (inclusiva)
    int  maximum_offer;                         // offerta massima ammessa (inclusiva)

    // ─────────────────────────────────────────────────────────────────────────
    // Primitive di sincronizzazione (richieste dalla consegna)
    // ─────────────────────────────────────────────────────────────────────────
    pthread_cond_t  cond_start;   // J → Bidders: "è iniziata una nuova asta (round)"
    pthread_cond_t  cond_report;  // Bidders → J: "è arrivata una nuova offerta"
    pthread_mutex_t mutex;        // protegge TUTTI i campi condivisi di questa struct

    // ─────────────────────────────────────────────────────────────────────────
    // Controllo del ciclo di vita
    // ─────────────────────────────────────────────────────────────────────────
    int round_id;    // identificatore del round; aumenta di 1 all’inizio di ogni asta
                     // (i bidders offrono al più una volta per round confrontando questo valore)
    int exit_flag;   // posto a 1 dal Giudice quando non ci sono più aste → chiusura threads

    // ─────────────────────────────────────────────────────────────────────────
    // Contatori/indicatori per la raccolta concorrente delle offerte
    // ─────────────────────────────────────────────────────────────────────────
    int num_bidders; // numero totale di thread offerenti
    int received;    // quante offerte sono già state depositate in questo round (0..N)
    int reported;    // quante offerte il Giudice ha già "riconosciuto" a video con il log
                     // (serve a stampare "[J] ricevuta offerta da Bx" nell’ordine di arrivo)
    int arrival_seq; // sequenziatore 0..N-1 per assegnare un "ordine di arrivo" ad ogni offerta

    // ─────────────────────────────────────────────────────────────────────────
    // Buffer per i risultati per-round (dimensione = num_bidders)
    // Tutti questi array sono riempiti dai bidders e letti dal Giudice,
    // SEMPRE a mutex bloccato.
    // ─────────────────────────────────────────────────────────────────────────
    int *offers;   // offers[i]  = valore offerto dal bidder i nel round corrente
    int *valid;    // valid[i]   = 1 se offers[i] ∈ [minimum_offer, maximum_offer], altrimenti 0
    int *rank;     // rank[i]    = ordine di arrivo dell’offerta di i (0 = arrivato per primo)
    int *order;    // order[k]   = indice del bidder che ha depositato la k-esima offerta
                   //             (permite al Giudice di loggare "ricevuta offerta" in tempo reale)
} shared_data_t;

typedef struct {
    int index;            // identità del bidder: B1→0, B2→1, ...
    shared_data_t *S;     // puntatore ai dati condivisi
    pthread_t     tid;    // id del thread (utile per pthread_join nel main)
} bidder_arg_t;

// Uscita immediata con messaggio d'errore di sistema.
// - perror(msg) stampa msg + descrizione dell'errno corrente.
// - exit(EXIT_FAILURE) termina il processo con codice di errore.
static void die(const char *msg) { perror(msg);exit(EXIT_FAILURE);}

// Rimuove eventuali terminatori di riga alla fine della stringa:
// gestisce sia '\n' (LF) sia '\r' (CR) per coprire file Windows (CRLF) e Unix (LF).
static void rstrip_newline(char *s) {
    size_t n = strlen(s);
    while (n > 0 && (s[n-1] == '\n' || s[n-1] == '\r')) {
        s[--n] = '\0';
    }
}

// Parsing di una riga nel formato:
//   <object-description>,<minimum-offer>,<maximum-offer>
//
// Ritorna 0 se il parsing ha successo, -1 altrimenti.
// 'line' VIENE MODIFICATA da strtok (inserisce '\0' sui separatori).
static int parse_line(char *line, char *name, int *minv, int *maxv) {
    rstrip_newline(line);              // normalizza la riga rimuovendo CR/LF finali

    // Tokenizzazione semplice separata da virgole.
    char *p1 = strtok(line, ",");      // descrizione oggetto
    char *p2 = strtok(NULL, ",");      // minimo NULL per indicare "continua da dove eri rimasto sulla stessa stringa"
    char *p3 = strtok(NULL, ",");      // massimo

    if (!p1 || !p2 || !p3)             // richiede esattamente 3 campi
        return -1;

    // Copia sicura con troncamento: garantiamo terminazione '\0'.
    strncpy(name, p1, OBJ_BUFSZ - 1);
    name[OBJ_BUFSZ - 1] = '\0';

    // Conversione numerica. atoi:
    // - ignora spazi iniziali
    // - restituisce 0 se la stringa non è numerica (ma non segnala l'errore)
    *minv = atoi(p2);
    *maxv = atoi(p3);

    return 0;
}

static void bidder_send_offer_locked(shared_data_t *S, int idx, int offer) {
    // Precondizione: mutex già bloccato
    S->offers[idx] = offer;
    S->valid[idx]  = (offer >= S->minimum_offer && offer <= S->maximum_offer) ? 1 : 0;
    S->rank[idx]   = S->arrival_seq;
    S->order[S->arrival_seq] = idx;

    S->arrival_seq++;
    S->received++;

    // Notifica al Giudice che una nuova offerta è arrivata
    pthread_cond_signal(&S->cond_report);
}

static void *bidder_thread(void *arg) {
    bidder_arg_t *B = (bidder_arg_t*)arg;
    shared_data_t *S = B->S;
    int idx = B->index;

    // Random seed leggermente "diverso" per ciascun thread
    unsigned int seed = (unsigned int)(B->index + time(NULL));

    int last_seen_round = -1;

    pthread_mutex_lock(&S->mutex);
    // Annuncio di disponibilità (facoltativo)
    printf("[B%d] offerente pronto\n", idx + 1);

    for (;;) {
        // Attendo un nuovo round o l'exit
        while (!S->exit_flag && S->round_id == last_seen_round) {
            pthread_cond_wait(&S->cond_start, &S->mutex);
        }
        if (S->exit_flag) {
            pthread_mutex_unlock(&S->mutex);
            break;
        }

        // Nuovo round visibile
        last_seen_round = S->round_id;
        int my_auction_index = S->auction_index;
        int maxv = S->maximum_offer;

        // Genero l'offerta in [1, max]
        // Nota: la consegna chiede "compresa tra 1 e maximum-offer"
        int offer = 1 + (rand_r(&seed) % (maxv));

        // Stampo e deposito l'offerta (mantengo il lock per garantire ordine coerente di messaggi)
        printf("[B%d] invio offerta di %d EUR per asta n.%d\n", idx + 1, offer, my_auction_index);
        bidder_send_offer_locked(S, idx, offer);

        // Torno ad attendere il prossimo round
        // (il lock rimane detenuto: il ciclo riparte e farà wait su cond_start)
    }
    return NULL;
}

// Determina il vincitore tra le offerte valide.
// In caso di ex aequo vince chi ha rank minore (arrivato prima).
static int pick_winner(const shared_data_t *S, int *best_value, int *n_valid) {
    int max_offer = -1;
    int winner = -1;
    int count_valid = 0;

    for (int i = 0; i < S->num_bidders; ++i) {
        if (!S->valid[i]) continue;
        count_valid++;
        if (S->offers[i] > max_offer) {
            max_offer = S->offers[i];
            winner = i;
        } else if (S->offers[i] == max_offer && winner >= 0) {
            if (S->rank[i] < S->rank[winner]) {
                winner = i; // arrivato prima
            }
        }
    }
    *best_value = (winner >= 0 ? max_offer : -1);
    *n_valid = count_valid;
    return winner; // -1 se nessuna offerta valida
}

// ------------------------------------------------------------

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <auction-file> <num-bidders>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *auction_filename = argv[1];
    int num_bidders = atoi(argv[2]);
    if (num_bidders <= 0) {
        fprintf(stderr, "Errore: <num-bidders> deve essere > 0\n");
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(auction_filename, "r");
    if (!fp) die("Impossibile aprire il file di aste");

    shared_data_t S;
    memset(&S, 0, sizeof(S));
    S.num_bidders = num_bidders;
    S.round_id = -1;

    if (pthread_mutex_init(&S.mutex, NULL) != 0) die("pthread_mutex_init");
    if (pthread_cond_init(&S.cond_start, NULL) != 0) die("pthread_cond_init cond_start");
    if (pthread_cond_init(&S.cond_report, NULL) != 0) die("pthread_cond_init cond_report");

    // Alloco gli array condivisi una sola volta (riutilizzati a ogni round)
    S.offers = (int*)calloc((size_t)num_bidders, sizeof(int));
    S.valid  = (int*)calloc((size_t)num_bidders, sizeof(int));
    S.rank   = (int*)calloc((size_t)num_bidders, sizeof(int));
    S.order  = (int*)calloc((size_t)num_bidders, sizeof(int));
    if (!S.offers || !S.valid || !S.rank || !S.order) die("calloc");

    // Creo i thread offerenti
    bidder_arg_t *B = (bidder_arg_t*)calloc((size_t)num_bidders, sizeof(bidder_arg_t));
    if (!B) die("calloc bidders");

    for (int i = 0; i < num_bidders; ++i) {
        B[i].index = i;
        B[i].S = &S;
        if (pthread_create(&B[i].tid, NULL, bidder_thread, &B[i]) != 0) die("pthread_create");
    }

    // Riepilogo
    int total_auctions = 0;
    int assigned = 0;
    int voided = 0;
    long long total_revenue = 0;

    char line[LINE_BUFSZ];
    int auction_index = 1;

    // Ciclo sulle aste del file
    while (fgets(line, sizeof(line), fp) != NULL) {
        char name[OBJ_BUFSZ];
        int minv, maxv;
        if (parse_line(line, name, &minv, &maxv) != 0) {
            fprintf(stderr, "Formato riga non valido: %s\n", line);
            continue; // o exit, se si preferisce interrompere
        }

        pthread_mutex_lock(&S.mutex);

        // Imposta stato round
        S.auction_index = auction_index;
        strncpy(S.object_description, name, OBJ_BUFSZ - 1);
        S.object_description[OBJ_BUFSZ - 1] = '\0';
        S.minimum_offer = minv;
        S.maximum_offer = maxv;

        // Reset contatori e array per il round
        S.received = 0;
        S.reported = 0;
        S.arrival_seq = 0;
        for (int i = 0; i < S.num_bidders; ++i) {
            S.offers[i] = 0;
            S.valid[i]  = 0;
            S.rank[i]   = 0;
            S.order[i]  = -1;
        }

        // Annuncio lancio d'asta
        printf("[J] lancio asta n.%d per %s con offerta minima di %d EUR e massima di %d EUR\n",
               auction_index, S.object_description, S.minimum_offer, S.maximum_offer);

        // Avanza il round e sveglia tutti gli offerenti
        S.round_id++;
        pthread_cond_broadcast(&S.cond_start);

        // Raccoglie le offerte mentre arrivano, stampando nell'ordine di arrivo
        // Finché non ne abbiamo N, aspettiamo segnali dai bidder
        while (S.received < S.num_bidders) {
            // Se sono arrivate offerte non ancora "riconosciute", stampale
            while (S.reported < S.received) {
                int idx = S.order[S.reported];
                // potrebbero esserci buchi solo se bug, ma difendiamoci
                if (idx >= 0 && idx < S.num_bidders) {
                    printf("[J] ricevuta offerta da B%d\n", idx + 1);
                }
                S.reported++;
            }
            if (S.received < S.num_bidders) {
                pthread_cond_wait(&S.cond_report, &S.mutex);
            }
        }
        // All’arrivo dell’ultima, stampa eventuali rimanenze (in pratica già zero)
        while (S.reported < S.received) {
            int idx = S.order[S.reported];
            if (idx >= 0 && idx < S.num_bidders) {
                printf("[J] ricevuta offerta da B%d\n", idx + 1);
            }
            S.reported++;
        }

        // Determina esito
        int best_value = -1, n_valid = 0;
        int winner = pick_winner(&S, &best_value, &n_valid);

        if (winner >= 0) {
            printf("[J] l'asta n.%d per %s si è conclusa con %d offerte valide su %d; "
                   "il vincitore è B%d che si aggiudica l'oggetto per %d EUR\n",
                   auction_index, S.object_description, n_valid, S.num_bidders,
                   winner + 1, best_value);
            assigned++;
            total_revenue += best_value;
        } else {
            printf("[J] l'asta n.%d per %s si è conclusa senza alcuna offerta valida "
                   "pertanto l'oggetto non risulta assegnato\n",
                   auction_index, S.object_description);
            voided++;
        }

        pthread_mutex_unlock(&S.mutex);

        total_auctions++;
        auction_index++;
    }

    fclose(fp);

    // Terminazione ordinata dei bidder
    pthread_mutex_lock(&S.mutex);
    S.exit_flag = 1;
    pthread_cond_broadcast(&S.cond_start); // sblocca eventuali bidder in attesa
    pthread_mutex_unlock(&S.mutex);

    for (int i = 0; i < num_bidders; ++i) {
        pthread_join(B[i].tid, NULL);
    }

    // Riepilogo finale (come da esempio)
    printf("[J] sono state svolte %d aste di cui %d assegnate e %d andate a vuoto; "
           "il totale raccolto è di %lld EUR\n",
           total_auctions, assigned, voided, total_revenue);

    // Cleanup
    free(B);
    free(S.offers);
    free(S.valid);
    free(S.rank);
    free(S.order);

    pthread_cond_destroy(&S.cond_start);
    pthread_cond_destroy(&S.cond_report);
    pthread_mutex_destroy(&S.mutex);

    return EXIT_SUCCESS;
}
