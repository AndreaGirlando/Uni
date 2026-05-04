/*
 * 4.d  Thread-pool — conteggio parole in parallelo
 *
 *  Uso (due modalità):
 *      1) Percorsi da riga di comando
 *            ./wpool  P  file1.txt  file2.txt ...
 *
 *      2) Percorsi da stdin (uno per riga)
 *            ./wpool  P  < lista_file.txt
 *
 *      P = numero di thread lavoratori (>=1)
 *
 *  Compilazione:
 *      gcc -std=gnu11 -O2 -pthread wpool.c -o wpool
 */
#define _GNU_SOURCE               /* per getline() */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* -------------------- coda di job protetta ------------------------- */
typedef struct job {
    char         *path;
    struct job   *next;
} job_t;

typedef struct {
    job_t         *head, *tail;
    pthread_mutex_t mtx;
    pthread_cond_t  cond;
    int             closed;
} queue_t;

static void queue_init(queue_t *q)
{
    q->head = q->tail = NULL;
    q->closed = 0;
    pthread_mutex_init(&q->mtx, NULL);
    pthread_cond_init(&q->cond, NULL);
}

static void queue_push(queue_t *q, job_t *j)
{
    j->next = NULL;
    if (q->tail) q->tail->next = j;
    else         q->head       = j;
    q->tail = j;
    pthread_cond_signal(&q->cond);
}

static job_t *queue_pop(queue_t *q)
{
    job_t *j = q->head;
    if (j) {
        q->head = j->next;
        if (!q->head) q->tail = NULL;
    }
    return j;
}

/* -------------------- lista risultati protetta --------------------- */
typedef struct result {
    char            *path;
    unsigned long    words;
    struct result   *next;
} res_t;

static res_t          *rhead = NULL;
static pthread_mutex_t rmtx  = PTHREAD_MUTEX_INITIALIZER;

/* -------------------- conta parole in un file ---------------------- */
static unsigned long count_words(const char *path)
{
    FILE *f = fopen(path, "r");
    if (!f) {
        perror(path);
        return 0;
    }
    unsigned long cnt = 0;
    int inword = 0, c;
    while ((c = fgetc(f)) != EOF) {
        if (isspace(c))
            inword = 0;
        else if (!inword) {
            inword = 1;
            ++cnt;
        }
    }
    fclose(f);
    return cnt;
}

/* -------------------- funzione dei worker -------------------------- */
static void *worker(void *arg)
{
    queue_t *q = (queue_t *)arg;

    for (;;) {
        pthread_mutex_lock(&q->mtx);
        while (!q->head && !q->closed)
            pthread_cond_wait(&q->cond, &q->mtx);

        if (!q->head && q->closed) {          /* finito il lavoro */
            pthread_mutex_unlock(&q->mtx);
            break;
        }

        job_t *j = queue_pop(q);
        pthread_mutex_unlock(&q->mtx);
        if (!j) continue;

        unsigned long w = count_words(j->path);

        res_t *r = malloc(sizeof *r);
        r->path  = j->path;   /* riuso la stringa allocata */
        r->words = w;
        pthread_mutex_lock(&rmtx);
        r->next  = rhead;
        rhead    = r;
        pthread_mutex_unlock(&rmtx);

        free(j);              /* libera struct job (non la path) */
    }
    return NULL;
}

/* ------------------------------ MAIN ------------------------------- */
int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Uso: %s P  [file1 file2 ...]  (o percorsi su stdin)\n", argv[0]);
        return EXIT_FAILURE;
    }
    int P = atoi(argv[1]);
    if (P < 1) { fputs("P deve essere >=1\n", stderr); return EXIT_FAILURE; }

    queue_t q;
    queue_init(&q);

    /* --------- 1) job da argv (se presenti) ---------- */
    for (int i = 2; i < argc; ++i) {
        job_t *j = malloc(sizeof *j);
        j->path  = strdup(argv[i]);
        pthread_mutex_lock(&q.mtx);
        queue_push(&q, j);
        pthread_mutex_unlock(&q.mtx);
    }

    /* --------- 2) job da stdin se non in argv -------- */
    if (argc == 2) {
        char *line = NULL;
        size_t len = 0;
        ssize_t nread;
        while ((nread = getline(&line, &len, stdin)) != -1) {
            if (nread && line[nread - 1] == '\n') line[nread - 1] = '\0';
            if (*line == '\0') continue;
            job_t *j = malloc(sizeof *j);
            j->path  = strdup(line);
            pthread_mutex_lock(&q.mtx);
            queue_push(&q, j);
            pthread_mutex_unlock(&q.mtx);
        }
        free(line);
    }

    /* --------- chiude la coda e sveglia eventuali worker in attesa --- */
    pthread_mutex_lock(&q.mtx);
    q.closed = 1;
    pthread_cond_broadcast(&q.cond);
    pthread_mutex_unlock(&q.mtx);

    /* --------- avvia i worker --------- */
    pthread_t *tid = malloc(P * sizeof *tid);
    for (int i = 0; i < P; ++i)
        pthread_create(&tid[i], NULL, worker, &q);

    /* --------- aspetta la fine -------- */
    for (int i = 0; i < P; ++i)
        pthread_join(tid[i], NULL);
    free(tid);

    /* --------- stampa i risultati ------ */
    unsigned long total = 0;
    for (res_t *p = rhead; p; p = p->next) {
        printf("%-40s  %lu\n", p->path, p->words);
        total += p->words;
    }
    printf("\nTotale parole: %lu\n", total);

    /* --------- pulizia finale ---------- */
    for (res_t *p = rhead; p;) {
        res_t *tmp = p->next;
        free(p->path);
        free(p);
        p = tmp;
    }
    pthread_mutex_destroy(&q.mtx);
    pthread_cond_destroy(&q.cond);
    pthread_mutex_destroy(&rmtx);
    return EXIT_SUCCESS;
}
