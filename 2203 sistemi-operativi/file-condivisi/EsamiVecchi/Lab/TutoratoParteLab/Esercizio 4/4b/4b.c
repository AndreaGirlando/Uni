/*
 * 4.b  Staffetta cronometrata con barriera
 *
 * Uso:
 *      ./race  N  max_delay_ms
 *          N              numero di corridori (thread)   ≥ 2
 *          max_delay_ms   tempo massimo di “corsa” (ms)  ≥ 1
 *
 * Compilazione:
 *      gcc -std=gnu11 -O2 -pthread race.c -o race
 */
#define _GNU_SOURCE
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>

/* ------------------------------------------------------------------ */
/* struttura che registra il tempo impiegato dal singolo corridore    */
typedef struct {
    unsigned id;
    double   elapsed_ms;
} runner_t;

/* ------------------------------------------------------------------ */
/* funzione che restituisce il tempo corrente in millisecondi         */
static double now_ms(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000.0 + ts.tv_nsec / 1e6;
}

/* ------------------------------------------------------------------ */
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
static unsigned        Nthreads;      /* corridori totali                  */
static unsigned        max_delay;     /* ritardo massimo in millisecondi   */
static runner_t       *table;         /* classifica condivisa              */
static pthread_barrier_t start_bar, fin_bar;

/* ------------------------------------------------------------------ */
/* funzione eseguita da ciascun corridore                             */
static void *runner(void *arg)
{
    unsigned idx   = (uintptr_t)arg;                 /* 0 … Nthreads-1   */
    unsigned seed  = idx ^ (unsigned)time(NULL);     /* seme diverso     */

    /* sincronizza la partenza */
    pthread_barrier_wait(&start_bar);

    double t0 = now_ms();
    unsigned d = rand_r(&seed) % (max_delay + 1);    /* delay casuale   */
    usleep(d * 1000);                                /* ms → µs         */
    double t1 = now_ms();

    table[idx].id         = idx;
    table[idx].elapsed_ms = t1 - t0;

    /* sincronizza l’arrivo */
    int rc = pthread_barrier_wait(&fin_bar);

    /* il thread designato stampa la classifica */
    if (rc == PTHREAD_BARRIER_SERIAL_THREAD) {
        /* selection sort in-place su tutte le righe */
        for (unsigned i = 0; i < Nthreads - 1; ++i) {
            unsigned min = i;
            for (unsigned j = i + 1; j < Nthreads; ++j)
                if (table[j].elapsed_ms < table[min].elapsed_ms)
                    min = j;
            if (min != i) {
                runner_t tmp = table[i];
                table[i]     = table[min];
                table[min]   = tmp;
            }
        }

        /* stampa risultati */
        puts("Pos Corridore  Δt(ms)");
        double sum = 0, mn = table[0].elapsed_ms, mx = table[0].elapsed_ms;

        for (unsigned i = 0; i < Nthreads; ++i) {
            printf("%2u   %2u      %.1f\n",
                   i + 1, table[i].id, table[i].elapsed_ms);
            sum += table[i].elapsed_ms;
            if (table[i].elapsed_ms < mn) mn = table[i].elapsed_ms;
            if (table[i].elapsed_ms > mx) mx = table[i].elapsed_ms;
        }

        printf("min=%.1f  max=%.1f  mean=%.1f\n",
               mn, mx, sum / Nthreads);
    }
    return NULL;
}

/* ------------------------------------------------------------------ */
int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Uso: %s N max_delay_ms\n", argv[0]);
        return EXIT_FAILURE;
    }

    Nthreads  = strtoul(argv[1], NULL, 10);
    max_delay = strtoul(argv[2], NULL, 10);

    if (Nthreads < 2 || max_delay == 0) {
        fprintf(stderr, "Parametri non validi.\n");
        return EXIT_FAILURE;
    }

    table = calloc(Nthreads, sizeof *table);
    if (!table) { perror("calloc"); return EXIT_FAILURE; }

    pthread_t *tid = malloc(Nthreads * sizeof *tid);
    if (!tid) { perror("malloc"); return EXIT_FAILURE; }

    pthread_barrier_init(&start_bar, NULL, Nthreads);
    pthread_barrier_init(&fin_bar,   NULL, Nthreads);

    /* crea i corridori */
    for (unsigned i = 0; i < Nthreads; ++i)
        pthread_create(&tid[i], NULL, runner, (void*)(uintptr_t)i);

    /* attende la loro conclusione */
    for (unsigned i = 0; i < Nthreads; ++i)
        pthread_join(tid[i], NULL);

    pthread_barrier_destroy(&start_bar);
    pthread_barrier_destroy(&fin_bar);
    free(tid);
    free(table);
    return EXIT_SUCCESS;
}
