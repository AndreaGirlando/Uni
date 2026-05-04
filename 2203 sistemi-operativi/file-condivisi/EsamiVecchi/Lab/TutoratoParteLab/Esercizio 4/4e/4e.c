/*
 * 4.e  Statistiche «live» su più liste di numeri
 *
 *  Uso:
 *      ./stats_live  N  M  T
 *
 *         N  quante liste / quanti thread osservatori   (≥1, default 4)
 *         M  quanti numeri per lista                    (≥1, default 1000)
 *         T  millisecondi fra due modifiche del server  (≥1, default 500)
 *
 *  Compilazione:
 *      gcc -std=gnu11 -O2 -pthread stats_live.c -o stats_live
 */
#define _GNU_SOURCE
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

/* --------------------------------------------------------- */
typedef struct {
    double          *buf;           /* array di M double          */
    size_t           M;             /* lunghezza                  */
    pthread_mutex_t  mtx;
    pthread_cond_t   cond;
    int              dirty;         /* 1 se il server ha scritto  */
} slot_t;

/* funzioni statistiche su un vettore ----------------------- */
static int cmp_double(const void *a, const void *b)
{
    double x = *(const double*)a, y = *(const double*)b;
    return (x > y) - (x < y);
}

static void compute_stats(double *v, size_t n,
                          double *mean, double *median,
                          double *var,  double *mn, double *mx)
{
    double sum = 0, min = v[0], max = v[0];
    for (size_t i = 0; i < n; ++i) {
        sum += v[i];
        if (v[i] < min) min = v[i];
        if (v[i] > max) max = v[i];
    }
    *mean = sum / n;

    /* copia e ordina per la mediana e varianza */
    double *tmp = malloc(n * sizeof *tmp);
    memcpy(tmp, v, n * sizeof *tmp);
    qsort(tmp, n, sizeof *tmp, cmp_double);
    *median = (n & 1) ? tmp[n/2] : 0.5*(tmp[n/2-1] + tmp[n/2]);

    double var_sum = 0;
    for (size_t i = 0; i < n; ++i) {
        double d = v[i] - *mean;
        var_sum += d*d;
    }
    *var = var_sum / n;
    *mn  = min;
    *mx  = max;
    free(tmp);
}

/* --------------------------------------------------------- */
static volatile sig_atomic_t done = 0;
static void on_sigint(int sig) { (void)sig; done = 1; }

/* thread osservatore -------------------------------------- */
typedef struct {
    unsigned id;
    slot_t  *slot;
} obs_arg_t;

static void *observer(void *arg)
{
    obs_arg_t *a = (obs_arg_t*)arg;
    slot_t *s = a->slot;
    size_t M = s->M;

    while (!done) {
        pthread_mutex_lock(&s->mtx);
        while (!s->dirty && !done)
            pthread_cond_wait(&s->cond, &s->mtx);
        if (done) { pthread_mutex_unlock(&s->mtx); break; }

        /* copia locale dei dati */
        double *local = malloc(M * sizeof *local);
        memcpy(local, s->buf, M * sizeof *local);
        s->dirty = 0;
        pthread_mutex_unlock(&s->mtx);

        /* calcola statistiche */
        double mean, med, var, mn, mx;
        compute_stats(local, M, &mean, &med, &var, &mn, &mx);

        printf("[lista %u] mean=%.3f  med=%.3f  var=%.3f  min=%.3f  max=%.3f\n",
               a->id, mean, med, var, mn, mx);
        fflush(stdout);
        free(local);
    }
    return NULL;
}

/* --------------------------------------------------------- */
static double drand01(void) { return rand() / (double)RAND_MAX; }

int main(int argc, char *argv[])
{
    /* ---- parametri ---- */
    unsigned N = 4;
    size_t   M = 1000;
    unsigned T = 500;

    if (argc > 1) N = (unsigned)strtoul(argv[1], NULL, 10);
    if (argc > 2) M = strtoull(argv[2], NULL, 10);
    if (argc > 3) T = (unsigned)strtoul(argv[3], NULL, 10);
    if (N == 0 || M == 0 || T == 0) {
        fprintf(stderr, "Parametri non validi\n");
        return EXIT_FAILURE;
    }

    srand((unsigned)time(NULL));
    signal(SIGINT, on_sigint);

    /* ---- alloca liste e thread ---- */
    slot_t *slots = calloc(N, sizeof *slots);
    pthread_t *tid = malloc(N * sizeof *tid);
    obs_arg_t *args = malloc(N * sizeof *args);

    for (unsigned i = 0; i < N; ++i) {
        slots[i].buf = malloc(M * sizeof *slots[i].buf);
        slots[i].M   = M;
        pthread_mutex_init(&slots[i].mtx, NULL);
        pthread_cond_init(&slots[i].cond, NULL);
        for (size_t k = 0; k < M; ++k)
            slots[i].buf[k] = drand01();           /* inizializza */
        slots[i].dirty = 1;                        /* prima stampa */

        args[i].id = i;
        args[i].slot = &slots[i];
        pthread_create(&tid[i], NULL, observer, &args[i]);
    }

    /* ---- thread main: modifica casualmente le liste ---- */
    while (!done) {
        for (unsigned i = 0; i < N; ++i) {
            size_t k = rand() % M;
            double v = drand01();
            pthread_mutex_lock(&slots[i].mtx);
            slots[i].buf[k] = v;
            slots[i].dirty  = 1;
            pthread_cond_signal(&slots[i].cond);
            pthread_mutex_unlock(&slots[i].mtx);
        }
        usleep(T * 1000);
    }

    /* ---- termina ---- */
    for (unsigned i = 0; i < N; ++i) {
        pthread_mutex_lock(&slots[i].mtx);
        pthread_cond_signal(&slots[i].cond);   /* sveglia se dorme */
        pthread_mutex_unlock(&slots[i].mtx);
    }
    for (unsigned i = 0; i < N; ++i)
        pthread_join(tid[i], NULL);

    /* ---- cleanup ---- */
    for (unsigned i = 0; i < N; ++i) {
        free(slots[i].buf);
        pthread_mutex_destroy(&slots[i].mtx);
        pthread_cond_destroy(&slots[i].cond);
    }
    free(slots); free(tid); free(args);
    puts("Fine (SIGINT ricevuto)");
    return EXIT_SUCCESS;
}
