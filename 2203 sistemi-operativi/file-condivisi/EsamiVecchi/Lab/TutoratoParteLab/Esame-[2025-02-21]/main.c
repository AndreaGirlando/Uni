// calc-verifier-5.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

typedef struct {
    pthread_mutex_t mtx;
    pthread_cond_t  cv_calc;  // producer <-> CALC (slot libero / dati pronti / risultato consumato)
    pthread_cond_t  cv_ops;   // CALC -> OPS (risultato pronto) e OPS -> CALC (consumato)

    long long op1, op2, result;
    char op; // '+', '-', 'x'

    bool have_op1, have_op2, have_op;
    bool result_valid;

    // flag di terminazione
    bool op1_done, op2_done;     // file operandi terminati
    bool ops_deposits_done;      // nessuna altra "operazione" da depositare
    bool all_done;               // OPS ha verificato il risultato finale
} Shared;

// Struttura di supporto per passare argomenti ai thread lettori (OP1 e OP2)
typedef struct {
    Shared *S; // Puntatore alla struct condivisa con mutex, condvar e dati
    const char *path; // Path del file da cui leggere gli operandi
} ReaderArgs;

// Stampa un messaggio di errore (con perror) e termina il processo
static void die(const char *msg) {
    perror(msg); // Stampa msg + descrizione dell'errno corrente
    exit(EXIT_FAILURE); // Termina il programma con codice di errore
}

// Rimuove eventuali spazi iniziali da una stringa
// Restituisce il puntatore al primo carattere non-spazio
static char* ltrim(char *s) {
    //while (*s && isspace((unsigned char)*s)) ++s;
    return s;
}

// Rimuove eventuali spazi finali da una stringa
// Modifica la stringa in place sostituendo gli spazi con '\0'
static void rtrim(char *s) {
    size_t n = strlen(s);
    while (n && isspace((unsigned char)s[n-1])) s[--n] = '\0';
    return;
}

// Verifica se un carattere è un'operazione valida: '+', '-' o 'x'
static int is_op_char(char c) {
    return (c=='+' || c=='-' || c=='x');
}

// Thread "OP1": legge i valori del primo operando da file e li deposita in Shared
static void* th_op1(void *arg) {
    ReaderArgs *A = (ReaderArgs*)arg;   // Cast degli argomenti ricevuti
    Shared *S = A->S;                   // Puntatore alla struct condivisa
    FILE *f = fopen(A->path, "r");      // Apre il file contenente i valori del primo operando
    if (!f) die("fopen op1");

    printf("[OP1] leggo gli operandi dal file '%s'\n", A->path);

    char line[256];
    int idx = 1; // contatore del numero di operando letto
    while (fgets(line, sizeof line, f)) {  // Legge il file riga per riga
        rtrim(line);                       // Rimuove spazi finali
        char *p = ltrim(line);             // Salta spazi iniziali
        if (*p == '\0') continue;          // Salta righe vuote

        errno = 0;
        char *end = NULL;
        long long v = strtoll(p, &end, 10); // Converte la riga in long long
        if (errno || (end==p)) continue;    // Se errore o stringa non valida, passa oltre

        // Sezione critica: deposito del valore in Shared
        pthread_mutex_lock(&S->mtx);
        while (S->have_op1)                      // Aspetta che lo slot op1 sia libero
            pthread_cond_wait(&S->cv_calc, &S->mtx);
        S->op1 = v;                              // Salva l'operando
        S->have_op1 = true;                      // Segna che op1 è disponibile
        printf("[OP1] primo operando n.%d: %lld\n", idx, v);
        pthread_cond_broadcast(&S->cv_calc);     // Risveglia CALC e gli altri eventuali in attesa
        pthread_mutex_unlock(&S->mtx);

        idx++;
    }

    // Segnala che il file degli op1 è terminato
    pthread_mutex_lock(&S->mtx);
    S->op1_done = true;
    pthread_cond_broadcast(&S->cv_calc); // Avvisa CALC nel caso sia in attesa
    pthread_mutex_unlock(&S->mtx);

    printf("[OP1] termino\n");
    fclose(f); // Chiude il file
    return NULL;
}

// Thread "OP2": legge i valori del secondo operando da file e li deposita in Shared
static void* th_op2(void *arg) {
    ReaderArgs *A = (ReaderArgs*)arg;   // Cast degli argomenti ricevuti
    Shared *S = A->S;                   // Puntatore alla struct condivisa
    FILE *f = fopen(A->path, "r");      // Apre il file contenente i valori del secondo operando
    if (!f) die("fopen op2");

    printf("[OP2] leggo gli operandi dal file '%s'\n", A->path);

    char line[256];
    int idx = 1; // contatore del numero di operando letto
    while (fgets(line, sizeof line, f)) {   // Legge il file riga per riga
        rtrim(line);                        // Rimuove spazi finali
        char *p = ltrim(line);              // Salta spazi iniziali
        if (*p == '\0') continue;           // Salta righe vuote

        errno = 0;
        char *end = NULL;
        long long v = strtoll(p, &end, 10); // Converte la riga in long long
        if (errno || (end==p)) continue;    // Se errore o stringa non valida, ignora

        // Sezione critica: deposito del valore in Shared
        pthread_mutex_lock(&S->mtx);
        while (S->have_op2)                      // Aspetta che lo slot op2 sia libero
            pthread_cond_wait(&S->cv_calc, &S->mtx);
        S->op2 = v;                              // Salva l’operando
        S->have_op2 = true;                      // Segna che op2 è disponibile
        printf("[OP2] secondo operando n.%d: %lld\n", idx, v);
        pthread_cond_broadcast(&S->cv_calc);     // Risveglia CALC o altri thread in attesa
        pthread_mutex_unlock(&S->mtx);

        idx++;
    }

    // Segnala che il file degli op2 è terminato
    pthread_mutex_lock(&S->mtx);
    S->op2_done = true;
    pthread_cond_broadcast(&S->cv_calc); // Avvisa CALC che non arriveranno altri op2
    pthread_mutex_unlock(&S->mtx);

    printf("[OP2] termino\n");
    fclose(f); // Chiude il file
    return NULL;
}

typedef struct {
    Shared *S;
    const char *path;
} OpsArgs;

// Thread "OPS": legge le operazioni (+, -, x) e il risultato atteso dal file
// Deposita ogni operazione in Shared, attende il risultato da CALC e aggiorna la somma parziale
static void* th_ops(void *arg) {
    OpsArgs *A = (OpsArgs*)arg;         // Cast degli argomenti ricevuti
    Shared *S = A->S;                   // Puntatore alla struct condivisa
    FILE *f = fopen(A->path, "r");      // Apre il file contenente operazioni e risultato atteso
    if (!f) die("fopen ops");

    printf("[OPS] leggo le operazioni e il risultato atteso dal file '%s'\n", A->path);

    char line[256];
    int idx = 1;            // contatore del numero di operazione letta
    long long somma = 0;    // accumulatore della somma dei risultati parziali
    long long atteso = 0;   // valore finale atteso (ultima riga del file)
    bool atteso_letto = false;

    // Ciclo di lettura del file riga per riga
    while (fgets(line, sizeof line, f)) {
        rtrim(line);             // elimina spazi finali
        char *p = ltrim(line);   // elimina spazi iniziali
        if (*p == '\0') continue; // ignora righe vuote

        if (strlen(p) == 1 && is_op_char(p[0])) {
            // Caso: la riga contiene un'operazione
            char op = (char)tolower((unsigned char)p[0]);

            // Deposita l'operazione in Shared
            pthread_mutex_lock(&S->mtx);
            while (S->have_op) pthread_cond_wait(&S->cv_calc, &S->mtx);
            S->op = (op=='x') ? 'x' : p[0];     // memorizza l’operazione
            S->have_op = true;                  // segna che op è disponibile
            printf("[OPS] operazione n.%d: %c\n", idx, S->op);
            pthread_cond_broadcast(&S->cv_calc); // risveglia CALC

            // Attende che CALC produca il risultato
            while (!S->result_valid) pthread_cond_wait(&S->cv_ops, &S->mtx);
            long long r = S->result;

            // Aggiorna la somma parziale con il nuovo risultato
            somma += r;
            printf("[OPS] sommatoria dei risultati parziali dopo %d operazione/i: %lld\n", idx, somma);
            idx++;

            // Segnala che il risultato è stato consumato
            S->result_valid = false;
            pthread_cond_broadcast(&S->cv_calc);
            pthread_mutex_unlock(&S->mtx);

        } else {
            // Caso: ultima riga con il risultato atteso della sommatoria
            errno = 0;
            char *end = NULL;
            long long v = strtoll(p, &end, 10);
            if (errno || (end==p)) continue; // riga non valida → ignora
            atteso = v;
            atteso_letto = true;
            break; // fine lettura, non ci sono più operazioni
        }
    }

    // Segnala che non ci saranno più operazioni
    pthread_mutex_lock(&S->mtx);
    S->ops_deposits_done = true;
    pthread_cond_broadcast(&S->cv_calc);
    pthread_mutex_unlock(&S->mtx);

    // Verifica finale: confronto tra somma calcolata e valore atteso
    if (atteso_letto) {
        printf("[OPS] risultato finale atteso: %lld (%s)\n",
               atteso, (somma == atteso ? "corretto" : "errato"));
    } else {
        fprintf(stderr, "[OPS] ERRORE: riga di risultato atteso mancante o invalida\n");
    }

    // Segnala la terminazione globale (CALC può uscire)
    pthread_mutex_lock(&S->mtx);
    S->all_done = true;
    pthread_cond_broadcast(&S->cv_calc);
    pthread_mutex_unlock(&S->mtx);

    printf("[OPS] termino\n");
    fclose(f); // chiude il file
    return NULL;
}


static long long apply_op(long long a, long long b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case 'x':
        case 'X': return a * b;
        default:  return 0; // non dovrebbe accadere
    }
}

static void* th_calc(void *arg) {
    Shared *S = (Shared*)arg;
    int idx = 1;

    for (;;) {
        long long a=0, b=0;
        char op=0;

        pthread_mutex_lock(&S->mtx);
        // Attesa dati: tre pezzi presenti e nessun risultato in sospeso
        while ((!(S->have_op1 && S->have_op2 && S->have_op) || S->result_valid)) {
            // Termine pulito: nessun lavoro residuo e tutti i sorgenti chiusi
            if (S->all_done &&
                !S->have_op1 && !S->have_op2 && !S->have_op &&
                !S->result_valid) {
                pthread_mutex_unlock(&S->mtx);
                printf("[CALC] termino\n");
                return NULL;
            }
            pthread_cond_wait(&S->cv_calc, &S->mtx);
        }

        // Copia i dati e libera lo slot per i prossimi
        a = S->op1; b = S->op2; op = S->op;
        S->have_op1 = S->have_op2 = S->have_op = false;
        pthread_cond_broadcast(&S->cv_calc);
        pthread_mutex_unlock(&S->mtx);

        // Calcolo fuori dal lock
        long long r = apply_op(a, b, op);

        pthread_mutex_lock(&S->mtx);
        S->result = r;
        S->result_valid = true;
        printf("[CALC] operazione minore n.%d: %lld %c %lld = %lld\n", idx, a, op, b, r);
        pthread_cond_signal(&S->cv_ops);
        // Attende consumo del risultato
        while (S->result_valid) pthread_cond_wait(&S->cv_calc, &S->mtx);
        pthread_mutex_unlock(&S->mtx);

        idx++;
    }
}

// Punto d’ingresso: crea le risorse condivise, avvia i thread e attende la loro terminazione
int main(int argc, char **argv) {
    // Controllo argomenti: servono 3 file (op1, op2, ops)
    if (argc != 4) {
        fprintf(stderr, "Uso: %s <first-operands> <second-operands> <operations>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("[MAIN] creo i thread ausiliari\n");

    Shared S = {0};                                  // Inizializza a zero tutta la shared state
    if (pthread_mutex_init(&S.mtx, NULL)) die("mutex_init");     // Mutex per proteggere S
    if (pthread_cond_init(&S.cv_calc, NULL)) die("cond_init");   // Condvar: dati/slot/consumo risultato
    if (pthread_cond_init(&S.cv_ops, NULL)) die("cond_init");    // Condvar: risultato pronto per OPS

    // Identificatori dei thread
    pthread_t t_op1, t_op2, t_ops, t_calc;

    // Argomenti per i thread lettori e per OPS
    ReaderArgs a1 = { .S = &S, .path = argv[1] };    // file con i primi operandi
    ReaderArgs a2 = { .S = &S, .path = argv[2] };    // file con i secondi operandi
    OpsArgs    ao = { .S = &S, .path = argv[3] };    // file con operazioni e atteso finale

    // Creazione dei thread ausiliari
    if (pthread_create(&t_op1, NULL, th_op1, &a1)) die("pthread_create op1");
    if (pthread_create(&t_op2, NULL, th_op2, &a2)) die("pthread_create op2");
    if (pthread_create(&t_ops, NULL, th_ops, &ao)) die("pthread_create ops");
    if (pthread_create(&t_calc, NULL, th_calc, &S)) die("pthread_create calc");

    // Attesa terminazione di tutti i thread
    pthread_join(t_op1, NULL);
    pthread_join(t_op2, NULL);
    pthread_join(t_ops, NULL);
    pthread_join(t_calc, NULL);

    // Cleanup risorse di sincronizzazione
    pthread_cond_destroy(&S.cv_ops);
    pthread_cond_destroy(&S.cv_calc);
    pthread_mutex_destroy(&S.mtx);

    printf("[MAIN] termino il processo\n");
    return 0;
}
