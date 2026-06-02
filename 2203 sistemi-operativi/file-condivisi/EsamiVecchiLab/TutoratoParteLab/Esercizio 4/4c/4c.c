/*
 * 4.c  Logger concorrente con coda circolare
 *
 *  Uso:
 *      ./logger  N  K
 *          N  numero totale di messaggi da produrre (>=1)
 *          K  capacità del buffer circolare           (>=1)
 *
 *  Produce due file di uscita:
 *      – stdout: stampa in tempo reale (consumer C2)
 *      – debug.log: file con le stesse righe (consumer C1)
 *
 *  Compilazione:
 *      gcc -std=gnu11 -O2 -pthread logger.c -o logger
 */
#define _GNU_SOURCE
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdint.h> // For uintptr_t

/* lunghezza massima di ciascun messaggio (incluso il terminatore) */
#define MSG_LEN 128

/* Variabili globali
 *
 * L'uso delle variabili globali non è generalmente considerato una buona pratica,
 * ma in questo esercizio sono utilizzate a scopo didattico.
 * A lezione abbiamo discusso delle variabili globali, della loro inizializzazione
 * e delle problematiche che possono insorgere in caso di errori.
 *
 * Sentitevi liberi di creare una fork del progetto e riscrivere il codice
 * evitando l'uso di variabili globali.
 */
static char   **buf;        /* array di puntatori a stringa */
static size_t   head = 0;   /* prossima posizione di scrittura */
static size_t   tail = 0;   /* prossima posizione di lettura   */
static size_t   count = 0;  /* elementi attualmente nel buffer */
static size_t   K;          /* capacità                       */

static pthread_mutex_t mtx   = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t  not_full  = PTHREAD_COND_INITIALIZER;
static pthread_cond_t  not_empty = PTHREAD_COND_INITIALIZER;

static int done = 0;        /* diventa 1 quando il produttore ha finito */

/* ---------- statistiche ---------- */
static size_t produced = 0;         /* messaggi generati          */
static size_t consumed_c1 = 0;      /* da consumer 1 (file)       */
static size_t consumed_c2 = 0;      /* da consumer 2 (stdout)     */
static unsigned long long occ_sum = 0; /* somma occupazione buffer */
static size_t occ_samples = 0;
static struct timespec t_start, t_end;

/* ---------- funzioni utili ---------- */
static void record_occupancy(void)
{
    occ_sum += count;
    ++occ_samples;
}

/* ---------- thread PRODUCER ---------- */
static void *producer(void *arg)
{
    size_t N = (size_t)(uintptr_t)arg;

    for (size_t i = 0; i < N; ++i) {
        /* prepara il messaggio */
        char msg[MSG_LEN];
        snprintf(msg, sizeof msg, "[seq=%zu] Hello, world!\n", i);

        pthread_mutex_lock(&mtx);
        while (count == K)                    /* buffer pieno */
            pthread_cond_wait(&not_full, &mtx);

        /* copia stringa nel buffer */
        buf[head] = strdup(msg);              /* malloc() interno */
        head = (head + 1) % K;
        ++count; ++produced;
        record_occupancy();

        pthread_cond_signal(&not_empty);
        pthread_mutex_unlock(&mtx);
    }

    /* segnala fine produzione */
    pthread_mutex_lock(&mtx);
    done = 1;
    pthread_cond_broadcast(&not_empty);
    pthread_mutex_unlock(&mtx);

    return NULL;
}

/* ---------- thread CONSUMER generico ---------- */
typedef struct {
    FILE   *out;       /* FILE* di destinazione (stdout o log) */
    size_t *counter;   /* puntatore al contatore personale     */
} consumer_arg_t;

static void *consumer(void *arg)
{
    consumer_arg_t *carg = (consumer_arg_t *)arg;

    for (;;) {
        pthread_mutex_lock(&mtx);
        while (count == 0 && !done)
            pthread_cond_wait(&not_empty, &mtx);

        if (count == 0 && done) {             /* niente più da fare */
            pthread_mutex_unlock(&mtx);
            break;
        }

        /* preleva un messaggio */
        char *msg = buf[tail];
        tail = (tail + 1) % K;
        --count;
        record_occupancy();
        pthread_cond_signal(&not_full);
        pthread_mutex_unlock(&mtx);

        /* usa il messaggio fuori dal lock */
        fputs(msg, carg->out);
        fflush(carg->out);
        free(msg);
        ++(*carg->counter);
    }
    return NULL;
}

/* ------------------- MAIN ---------------------- */
int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Uso: %s N K\n", argv[0]);
        return EXIT_FAILURE;
    }
    size_t N = strtoull(argv[1], NULL, 10);
    K        = strtoull(argv[2], NULL, 10);
    if (N == 0 || K == 0) {
        fprintf(stderr, "Parametri non validi.\n");
        return EXIT_FAILURE;
    }

    buf = calloc(K, sizeof *buf);
    if (!buf) { perror("calloc"); return EXIT_FAILURE; }

    /* apre il file di log */
    FILE *fout = fopen("debug.log", "w");
    if (!fout) { perror("debug.log"); return EXIT_FAILURE; }

    pthread_t prod, c1, c2;
    consumer_arg_t arg1 = { .out = fout,   .counter = &consumed_c1 };
    consumer_arg_t arg2 = { .out = stdout, .counter = &consumed_c2 };

    clock_gettime(CLOCK_MONOTONIC, &t_start);

    pthread_create(&prod, NULL, producer, (void*)(uintptr_t)N);
    pthread_create(&c1,   NULL, consumer, &arg1);
    pthread_create(&c2,   NULL, consumer, &arg2);

    pthread_join(prod, NULL);
    pthread_join(c1,   NULL);
    pthread_join(c2,   NULL);

    clock_gettime(CLOCK_MONOTONIC, &t_end);

    fclose(fout);

    /* ---- stampa statistiche ---- */
    double elapsed = (t_end.tv_sec - t_start.tv_sec) +
                     (t_end.tv_nsec - t_start.tv_nsec) / 1e9;

    double occ_mean = occ_samples ? (double)occ_sum / occ_samples : 0.0;

    printf("\n--- Statistiche ---\n");
    printf("Prodotti:      %zu\n", produced);
    printf("C1 (file):     %zu\n", consumed_c1);
    printf("C2 (stdout):   %zu\n", consumed_c2);
    printf("Occupazione media buffer: %.2f / %zu\n", occ_mean, K);
    printf("Durata totale: %.3f s\n", elapsed);

    /* pulizia finale */
    free(buf);
    return EXIT_SUCCESS;
}
