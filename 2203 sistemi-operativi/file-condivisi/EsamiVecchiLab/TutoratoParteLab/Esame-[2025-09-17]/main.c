#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define M 12          // lunghezza dei vettori richiesti dall’esame
#define QUEUE_CAP 10  // capienza coda intermedia (vincolo d’esame)
#define NUM_VERIF 3   // numero di thread verificatori

// ===============================
// == Record della coda (didatt.) ==
// ===============================
// Usiamo direttamente un array di 12 byte.
// Aggiungiamo un flag didattico "is_end": se vale 1 il record è una sentinella
// di terminazione (poison pill) per i consumatori.
typedef struct {
    uint8_t v[M]; // il vettore da 12 byte
    int     is_end; // 0 = normale, 1 = sentinella di terminazione
} record_t;

// ===============================
// == Coda circolare bounded FIFO ==
// ===============================
// Producer-Consumer con semafori (sem_wait/sem_post) e un mutex.
// - sem_slots: quanti slot liberi ho per inserire
// - sem_items: quanti elementi disponibili per prelevare
// Push e pop sono *bloccanti* (nessun timed-wait).
typedef struct {
    record_t buf[QUEUE_CAP];
    int head;                // prossimo elemento da leggere
    int tail;                // prossimo slot dove scrivere
    int count;               // numero elementi attuali
    pthread_mutex_t mtx;     // mutua esclusione su head/tail/count
    sem_t sem_items;         // elementi disponibili
    sem_t sem_slots;         // slot liberi
} ring_t;

// ===============================
// == Record finale (buffer 1-slot) ==
// ===============================
// Anche qui aggiungiamo is_end per la terminazione del main.
typedef struct {
    record_t slot;        // singolo slot
    pthread_mutex_t mtx;  // protezione accesso a slot
    sem_t sem_empty;      // 1 se slot vuoto
    sem_t sem_full;       // 1 se slot pieno
} final_slot_t;

// ===============================
// == Stato condiviso tra thread ==
// ===============================
typedef struct {
    // Code di comunicazione
    ring_t ring;          // coda intermedia
    final_slot_t out;     // record finale a 1 slot

    // File da leggere
    int n_readers;
    char **filenames;

    // Contatori per coordinare la terminazione (protetti da mutex)
    int readers_left;     // lettori ancora attivi
    int verifiers_left;   // verificatori ancora attivi
    pthread_mutex_t mtx_counts;

    // Statistiche
    unsigned long main_equisum_total;

} shared_t;

// Argomento generico per i thread
typedef struct {
    shared_t *S;
    int idx; // indice umano (1..N per reader, 1..NUM_VERIF per verificatori)
} thread_arg_t;

// ============== Utilità di stampa ordinate ==============
// Evita mescolamento righe tra thread.
static inline void lock_stdout(void)   { flockfile(stdout); }
static inline void unlock_stdout(void) { funlockfile(stdout); }

// Stampa compatta di un vettore
static void print_vec12(const uint8_t v[M]) {
    printf("(%u", v[0]);
    for (int i = 1; i < M; ++i) {
        printf(", %u", v[i]);
    }
    printf(")");
}

// ================== Inizializzazione strutture ==================
static void ring_init(ring_t *r) {
    r->head = r->tail = r->count = 0;
    pthread_mutex_init(&r->mtx, NULL);
    sem_init(&r->sem_items, 0, 0);
    sem_init(&r->sem_slots, 0, QUEUE_CAP);
}
static void ring_destroy(ring_t *r) {
    pthread_mutex_destroy(&r->mtx);
    sem_destroy(&r->sem_items);
    sem_destroy(&r->sem_slots);
}

static void final_init(final_slot_t *f) {
    pthread_mutex_init(&f->mtx, NULL);
    sem_init(&f->sem_empty, 0, 1); // all’inizio lo slot è vuoto
    sem_init(&f->sem_full,  0, 0);
}
static void final_destroy(final_slot_t *f) {
    pthread_mutex_destroy(&f->mtx);
    sem_destroy(&f->sem_empty);
    sem_destroy(&f->sem_full);
}

// ================== Operazioni sulla coda ==================
// PUSH (bloccante): aspetta uno slot libero, scrive, segnala un item.
static void ring_push(ring_t *r, const record_t *rec) {
    sem_wait(&r->sem_slots);              // attendo spazio
    pthread_mutex_lock(&r->mtx);
    r->buf[r->tail] = *rec;
    r->tail = (r->tail + 1) % QUEUE_CAP;
    pthread_mutex_unlock(&r->mtx);
    sem_post(&r->sem_items);              // segnalo nuovo elemento
}

// POP (bloccante): aspetta un item, legge, libera uno slot.
static void ring_pop(ring_t *r, record_t *out) {
    sem_wait(&r->sem_items);              // attendo elemento
    pthread_mutex_lock(&r->mtx);
    *out = r->buf[r->head];
    r->head = (r->head + 1) % QUEUE_CAP;
    pthread_mutex_unlock(&r->mtx);
    sem_post(&r->sem_slots);              // segnalo slot libero
}

// ================== Operazioni sul record finale ==================
static void final_put(final_slot_t *f, const record_t *rec) {
    sem_wait(&f->sem_empty);              // attendo che sia vuoto
    pthread_mutex_lock(&f->mtx);
    f->slot = *rec;
    pthread_mutex_unlock(&f->mtx);
    sem_post(&f->sem_full);               // segnalo che è pieno
}

static void final_get(final_slot_t *f, record_t *out) {
    sem_wait(&f->sem_full);               // attendo che sia pieno
    pthread_mutex_lock(&f->mtx);
    *out = f->slot;
    pthread_mutex_unlock(&f->mtx);
    sem_post(&f->sem_empty);              // segnalo che è tornato vuoto
}

// ================== Logica “equisomma” ==================
static inline void sums_even_odd(const uint8_t v[M], unsigned *sum_even, unsigned *sum_odd) {
    unsigned se = 0, so = 0;
    for (int i = 0; i < M; ++i) {
        if ((i & 1) == 0) se += v[i]; else so += v[i]; // indici: 0,2,4,... pari
    }
    *sum_even = se; *sum_odd = so;
}

// ================== THREAD: LETTORE (produttore) ==================
// - mappa il file con mmap
// - per ogni blocco di 12 byte, stampa il candidato e lo inserisce in coda
// - quando *l’ultimo lettore* termina, inserisce NUM_VERIF poison pill in coda
static void *reader_main(void *arg) {
    thread_arg_t *A = (thread_arg_t*)arg;
    shared_t *S = A->S;
    int idx = A->idx;
    const char *fname = S->filenames[idx - 1];

    lock_stdout(); printf("[READER-%d] file '%s'\n", idx, fname); unlock_stdout();

    int fd = open(fname, O_RDONLY);
    struct stat st;
    fstat(fd, &st);

    size_t sz = (size_t)st.st_size;
    size_t nrec = sz / M;
    void *map = NULL;

    if (sz > 0) {
        map = mmap(NULL, sz, PROT_READ, MAP_PRIVATE, fd, 0);
        if (map == MAP_FAILED) {
            perror("mmap");
        }
    }

    size_t produced = 0;
    for (size_t i = 0; i < nrec; ++i) {
        record_t rec = { .is_end = 0 };
        memcpy(rec.v, (uint8_t*)map + i * M, M);

        lock_stdout();
        printf("[READER-%d] vettore candidato n.%zu: ", idx, i + 1);

        print_vec12(rec.v);
        printf("\n");
        unlock_stdout();

        ring_push(&S->ring, &rec);
        produced++;
    }

    if (map && map != MAP_FAILED) munmap(map, sz);
    close(fd);

    lock_stdout(); printf("[READER-%d] terminazione con %zu vettori letti\n", idx, produced); unlock_stdout();

    // Se questo è l'ULTIMO lettore a finire, metti NUM_VERIF poison pill in coda.
    pthread_mutex_lock(&S->mtx_counts);
    S->readers_left--;
    int last = (S->readers_left == 0);
    pthread_mutex_unlock(&S->mtx_counts);

    if (last) {
        record_t poison = { .is_end = 1 };
        for (int k = 0; k < NUM_VERIF; ++k) ring_push(&S->ring, &poison);
    }
    return NULL;
}

// ================== THREAD: VERIFICATORE (consumatore) ==================
// - preleva dalla coda (bloccante)
// - se sentinella → esce dal ciclo
// - altrimenti verifica equisomma; se sì, invia il vettore allo slot finale
// - l’ULTIMO verificatore che termina inserisce una poison nello slot finale
static void *verifier_main(void *arg) {
    thread_arg_t *A = (thread_arg_t*)arg;
    shared_t *S = A->S;
    int idx = A->idx;

    size_t verified = 0;

    for (;;) {
        record_t rec;
        ring_pop(&S->ring, &rec); // bloccante

        if (rec.is_end) {
            // Fine lavori per questo verificatore
            break;
        }

        verified++;

        unsigned se, so;
        sums_even_odd(rec.v, &se, &so);

        // Log verifica in una singola sezione protetta, ma con una sola printf finale
        lock_stdout();
        if (se == so) {
            printf("[VERIF-%d] verifico vettore: ", idx);
            print_vec12(rec.v);
            printf("\n[VERIF-%d] si tratta di un vettore equisomma con somma %u!\n", idx, se);
        } else {
            printf("[VERIF-%d] verifico vettore: ", idx);
            print_vec12(rec.v);
            printf("\n[VERIF-%d] non è un vettore equisomma (somma pari %u vs. dispari %u)\n",
                   idx, se, so);
        }
        unlock_stdout();

        if (se == so) {
            // Passa al record finale (bloccante se lo slot è occupato)
            record_t out = rec; // is_end=0
            final_put(&S->out, &out);
        }
    }

    // Segno che questo verificatore ha finito; se è l'ULTIMO, sveglio il main
    // inserendo una poison nello slot finale (così il main smette di aspettare).
    int last = 0;
    pthread_mutex_lock(&S->mtx_counts);
    S->verifiers_left--;
    last = (S->verifiers_left == 0);
    pthread_mutex_unlock(&S->mtx_counts);

    lock_stdout();
    printf("[VERIF-%d] terminazione con %zu vettori verificati\n", idx, verified);
    unlock_stdout();

    if (last) {
        record_t poison = { .is_end = 1 }; // segnale di chiusura per il main
        final_put(&S->out, &poison);
    }
    return NULL;
}

// ================== MAIN (stampa i vettori equisomma) ==================
int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <file-bin-1> [file-bin-2 ... file-bin-N]\n", argv[0]);
        return 1;
    }
    setvbuf(stdout, NULL, _IONBF, 0);

    shared_t S;
    ring_init(&S.ring);
    final_init(&S.out);
    pthread_mutex_init(&S.mtx_counts, NULL);

    S.n_readers = argc - 1;
    S.filenames = &argv[1];
    S.readers_left = S.n_readers;
    S.verifiers_left = NUM_VERIF;
    S.main_equisum_total = 0;

    pthread_t *readers = calloc(S.n_readers, sizeof(pthread_t));
    pthread_t verifiers[NUM_VERIF];

    lock_stdout();
    printf("[MAIN] creazione di %d thread lettori e %d thread verificatori\n",
           S.n_readers, NUM_VERIF);
    unlock_stdout();

    // Avvia lettori
    for (int i = 0; i < S.n_readers; ++i) {
        thread_arg_t *arg = malloc(sizeof(thread_arg_t));
        arg->S = &S; arg->idx = i + 1;
        int rc = pthread_create(&readers[i], NULL, reader_main, arg);
        if (rc != 0) {
            lock_stdout(); printf("[MAIN] ERRORE creazione READER-%d: %s\n", i + 1, strerror(rc)); unlock_stdout();
            free(arg);
            // In caso di errore, consideriamo quel lettore "già terminato"
            pthread_mutex_lock(&S.mtx_counts);
            S.readers_left--;
            int last = (S.readers_left == 0);
            pthread_mutex_unlock(&S.mtx_counts);
            if (last) {
                record_t poison = { .is_end = 1 };
                for (int k = 0; k < NUM_VERIF; ++k) ring_push(&S.ring, &poison);
            }
        }
    }

    // Avvia verificatori
    for (int i = 0; i < NUM_VERIF; ++i) {
        thread_arg_t *arg = malloc(sizeof(thread_arg_t));
        arg->S = &S; arg->idx = i + 1;
        int rc = pthread_create(&verifiers[i], NULL, verifier_main, arg);
        if (rc != 0) {
            lock_stdout(); printf("[MAIN] ERRORE creazione VERIF-%d: %s\n", i + 1, strerror(rc)); unlock_stdout();
            free(arg);
            // Se fallisce la creazione, riduciamo il numero atteso di verificatori.
            pthread_mutex_lock(&S.mtx_counts);
            S.verifiers_left--;
            int last = (S.verifiers_left == 0);
            pthread_mutex_unlock(&S.mtx_counts);
            if (last) {
                // Nessun verificatore esiste: sblocco il main con poison sullo slot finale
                record_t poison = { .is_end = 1 };
                final_put(&S.out, &poison);
            }
        }
    }

    // MAIN: consuma i vettori equisomma e li stampa finché arriva la poison dallo slot finale.
    for (;;) {
        record_t rec;
        final_get(&S.out, &rec); // bloccante
        if (rec.is_end) break;   // ultimo verificatore ha segnalato fine
        S.main_equisum_total++;

        lock_stdout();
        printf("[MAIN] ricevuto nuovo vettore equisomma: ");
        print_vec12(rec.v);
        printf("\n");
        unlock_stdout();
    }

    // Join di tutti i thread creati (i verificatori potrebbero essere già usciti)
    for (int i = 0; i < S.n_readers; ++i) {
        if (readers[i]) pthread_join(readers[i], NULL);
    }
    for (int i = 0; i < NUM_VERIF; ++i) {
        pthread_join(verifiers[i], NULL);
    }

    lock_stdout();
    printf("[MAIN] terminazione con %lu vettori equisomma trovati\n", S.main_equisum_total);
    unlock_stdout();

    // Cleanup
    free(readers);
    pthread_mutex_destroy(&S.mtx_counts);
    ring_destroy(&S.ring);
    final_destroy(&S.out);
    return 0;
}
