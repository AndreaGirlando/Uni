/*
 * 4.a  Somma di vettori in parallelo
 *
 * Uso:
 *      ./vecsum  N  T
 *          N  lunghezza dei vettori ( > 1 )
 *          T  numero di thread     ( >= 1 )
 *
 * Produce una riga del tipo:
 *      N=100000000  T=8  sum_time=0.142 s  speedup=5.9
 *
 * Compilazione:
 *      gcc -O2 -std=gnu11 -pthread vecsum.c -o vecsum
 */
#define _GNU_SOURCE
/*
#define _GNU_SOURCE attiva le estensioni GNU nella libreria C del sistema (glibc). 
È una feature che sblocca funzioni e costrutti che non fanno parte dello standard POSIX o ISO C, 
ma che sono comunque molto utili e comunemente usati su sistemi Linux.
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

typedef struct {
    size_t  start;          /* indice iniziale (incluso)   */
    size_t  end;            /* indice finale   (escluso)    */
    const double *A;
    const double *B;
    double *C;
} slice_t;

/* ---------- utilità tempo ---------- */
static double seconds_now(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec * 1e-9; //serve a convertire il valore del tempo da struct timespec in un singolo double che rappresenta il numero totale di secondi trascorsi.
}
//La costante CLOCK_MONOTONIC è una funzionalità POSIX, 
// ma in alcune implementazioni (specie più vecchie o non standard), 
//l'uso di clock_gettime() richiede #define _GNU_SOURCE prima di qualunque #include.
/* ---------- thread worker ---------- */
static void *worker(void *arg)
{
    slice_t *s = (slice_t *)arg;
    for (size_t i = s->start; i < s->end; ++i)
        s->C[i] = s->A[i] + s->B[i];
    return NULL;
}

/* ---------- main ---------- */
int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Uso: %s N T\n", argv[0]);
        return EXIT_FAILURE;
    }

    const size_t N = strtoull(argv[1], NULL, 10);
    int T         = atoi(argv[2]);
    if (N < 2 || T < 1) {
        fprintf(stderr, "Parametri non validi\n");
        return EXIT_FAILURE;
    }

    /* ---- allocazione + inizializzazione ---- */
    double t0 = seconds_now();

    double *A = malloc(N * sizeof *A);
    double *B = malloc(N * sizeof *B);
    double *C = malloc(N * sizeof *C);
    double *Cseq = malloc(N * sizeof *Cseq);   /* per la versione sequenziale */

    if (!A || !B || !C || !Cseq) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    srand48((long)time(NULL));
    for (size_t i = 0; i < N; ++i) {
        A[i] = drand48();
        B[i] = drand48();
    }

    double t_alloc = seconds_now() - t0;

    /* ---- somma sequenziale (baseline) ---- */
    double ts0 = seconds_now();
    for (size_t i = 0; i < N; ++i)
        Cseq[i] = A[i] + B[i];
    double t_seq = seconds_now() - ts0;

    /* ---- somma parallela (T thread) ---- */
    if (T == 1) {          /* caso “sequenziale dichiarato” */
        for (size_t i = 0; i < N; ++i)
            C[i] = A[i] + B[i];
    } else {
        pthread_t *tid  = malloc(T * sizeof *tid);
        slice_t   *job  = malloc(T * sizeof *job);
        size_t base = N / (size_t)T;
        size_t rest = N % (size_t)T;

        double tp0 = seconds_now();

        size_t offset = 0;
        for (int i = 0; i < T; ++i) {
            size_t step = base + (i < (int)rest);   /* distribuisce il resto */
            job[i] = (slice_t){ .start = offset,
                                .end   = offset + step,
                                .A = A, .B = B, .C = C };
            offset += step;
            pthread_create(&tid[i], NULL, worker, &job[i]);
        }
        for (int i = 0; i < T; ++i)
            pthread_join(tid[i], NULL);

        double t_par = seconds_now() - tp0;

        /* ---- verifica veloce di correttezza ---- */
        for (size_t i = 0; i < N; ++i)
            if (C[i] != Cseq[i]) {
                fprintf(stderr, "errore: risultato diverso a i=%zu\n", i);
                return EXIT_FAILURE;
            }

        /* ---- stampa risultato ---- */
        double speedup = (T == 1) ? 1.0 : t_seq / t_par;
        printf("N=%zu  T=%d t_seq=%.3f s t_par=%.3f s speedup=%.2f\n",
               N, T, t_seq, t_par, speedup);

        free(tid);
        free(job);
    }

    // (facoltativo) stampa tempi di allocazione/sequenziale
    printf("alloc+init = %.3f s, seq = %.3f s\n", t_alloc, t_seq);
    

    free(A); free(B); free(C); free(Cseq);
    return EXIT_SUCCESS;
}
