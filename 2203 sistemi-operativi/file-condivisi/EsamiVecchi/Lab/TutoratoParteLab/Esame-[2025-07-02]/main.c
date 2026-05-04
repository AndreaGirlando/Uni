#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include <sys/time.h>   /* gettimeofday */
#include <stdarg.h> 

#define TS_PRINT(fmt, ...) do {                                  \
    struct timeval ts_tv;                                        \
    gettimeofday(&ts_tv, NULL);                                  \
    struct tm ts_tm;                                             \
    localtime_r(&ts_tv.tv_sec, &ts_tm);                          \
    printf("[%02d:%02d:%02d.%03ld] " fmt,                        \
           ts_tm.tm_hour, ts_tm.tm_min, ts_tm.tm_sec,            \
           ts_tv.tv_usec / 1000,                                 \
           ##__VA_ARGS__);                                       \
} while (0)

#define SQ_SIDE 3
#define SQ_SIZE (SQ_SIDE * SQ_SIDE)
#define INTER_CAP 10
#define FINAL_CAP 3

void exit_with_msg(const char *msg){ fprintf(stderr, "%s\n", msg); exit(EXIT_FAILURE);}

void exit_with_error(const char *msg){ perror(msg); exit(EXIT_FAILURE);}

void check_args(int argc, char *argv[]){
    if(argc < 3)
        exit_with_msg("Uso: ./magic-squares-screener <M-verifiers> <file-1> ... <file-N>");
}
// Structures
typedef struct {
    int v[SQ_SIZE];
    int reader_id;  // ID del lettore che ha letto questa matrice
    int seq_no;
} Square;

typedef struct {                 /* coda circolare thread‑safe           */
    Square *buf;
    int capacity, head, tail, count;
    pthread_mutex_t mtx;
    pthread_cond_t  not_full;
} Queue;
// operazioni sulla coda (init, destroy, push, pop)
static void queue_init(Queue *q, int capacity){
    q->buf = malloc(sizeof(Square)*capacity);
    if(!q->buf) exit_with_error("malloc");
    q->capacity = capacity;
    q->head = q->tail = q->count = 0;
    pthread_mutex_init(&q->mtx, NULL);
    pthread_cond_init(&q->not_full, NULL);
}

static void queue_destroy(Queue *q){
    free(q->buf);
    pthread_mutex_destroy(&q->mtx);
    pthread_cond_destroy(&q->not_full);
}

//PUSH e POP
static void queue_push(Queue *q, const Square *s){
    pthread_mutex_lock(&q->mtx);
    while(q->count == q->capacity){
        pthread_cond_wait(&q->not_full, &q->mtx);
    }

    q->buf[q->tail] = *s;
    q->tail = (q->tail + 1) % q->capacity;
    q->count++;

    pthread_mutex_unlock(&q->mtx);
}

static bool queue_try_pop(Queue *q, Square *out){
    bool ok = false;
    pthread_mutex_lock(&q->mtx);
    if(q->count > 0){
        *out = q->buf[q->head];
        q->head = (q->head + 1) % q->capacity;
        q->count--;
        pthread_cond_signal(&q->not_full);
        ok = true;
    }
    pthread_mutex_unlock(&q->mtx);
    return ok;
}

static int parse_line(const char *line, int *out){
    int n = sscanf(line, "%d,%d,%d,%d,%d,%d,%d,%d,%d",
            &out[0], &out[1], &out[2], &out[3], &out[4],
                &out[5], &out[6], &out[7], &out[8]);
    return (n == SQ_SIZE) ? 0 : -1;
}
/*
    0 1 2
    3 4 5
    6 7 8
*/
static int is_magic(const int *v){
    int m = v[0] + v[1] + v[2];
    for(int r = 1; r < SQ_SIDE; ++r) if(v[r*SQ_SIDE] + v[r*SQ_SIDE+1] + v[r*SQ_SIDE+2] != m) return -1;
    for(int c = 0; c < SQ_SIDE; ++c) if(v[c] + v[c+3] + v[c+6] != m) return -1;
    if(v[0]+v[4]+v[8] != m || v[2]+v[4]+v[6] != m) return -1;
    return m;
}
// reader -push-> coda intermedia <-pop- verifier -push-> coda finale <-pop- main

//Argomenti per i thread
typedef struct{
    const char *filename;
    int id;
    Queue *inter_q;
    int *active_readers;
    pthread_mutex_t *readers_mtx;
} ReaderArg;

typedef struct{
    int id;
    Queue *inter_q;
    Queue *final_q;
    int *active_readers;
    int *running_verifs;
    pthread_mutex_t *readers_mtx;
    pthread_mutex_t *verifs_mtx;
} VerifArg;

// reader -push-> coda intermedia
static void *reader_thread(void *arg){
    ReaderArg *ra = (ReaderArg*)arg;
    FILE *fp = fopen(ra->filename, "r");
    if(!fp) exit_with_error("fopen");

    TS_PRINT("[READER-%d] file '%s'\n", ra->id + 1, ra->filename); /* LOG */
    char *line = NULL;
    size_t len = 0;
    ssize_t n;
    int seq = 1;

    while((n = getline(&line, &len, fp)) != -1){
        if(n&&line[n-1] == '\n') line[n-1] = '\0';
        Square s = {.reader_id = ra->id +1, .seq_no = seq};
        if(parse_line(line, s.v) == 0){
            TS_PRINT("[READER-%d] quadrato candidato n.%d: "
                    "(%d,%d,%d)(%d,%d,%d)(%d,%d,%d)\n",
                    ra->id+1,seq,
                    s.v[0],s.v[1],s.v[2],s.v[3],s.v[4],s.v[5],s.v[6],s.v[7],s.v[8]);
            queue_push(ra->inter_q, &s);
            ++seq;
        }
    }
    free(line); fclose(fp);

    pthread_mutex_lock(ra->readers_mtx);
    printf("attivi %d\n", *ra->active_readers); /* LOG */
    --(*ra->active_readers);
    pthread_mutex_unlock(ra->readers_mtx);

    TS_PRINT("[READER-%d] terminazione\n", ra->id + 1); /* LOG */
    return NULL;
}
/*
    cosa ci serve?
    coda intermedia <-pop- verifier -push-> coda finale && funzione is magic

    Square s = coda_intermedia.pop()
    if(is_magic(s.values) == true)
        coda_finale.push(s);
    else
        discard s;
*/
static void *verifier_thread(void *arg){
    VerifArg *va = (VerifArg*)arg;
    while(1){
        Square sq;
        if(queue_try_pop(va->inter_q, &sq)){
            TS_PRINT("[VERIF-%d] verifico quadrato: " /* LOG */
                    "(%d,%d,%d)(%d,%d,%d)(%d,%d,%d)\n",
                    va->id+1,
                    sq.v[0],sq.v[1],sq.v[2],sq.v[3],sq.v[4],sq.v[5],
                    sq.v[6],sq.v[7],sq.v[8]);
            int m = is_magic(sq.v);
            if(m != -1){
                TS_PRINT("[VERIF-%d] trovato quadrato magico!\n", va->id + 1);
                queue_push(va->final_q, &sq);
            }
        }
        pthread_mutex_lock(va->readers_mtx);
        bool done = (*va->active_readers == 0);
        pthread_mutex_unlock(va->readers_mtx);
        if(done) break;
        usleep(500);
    }
    pthread_mutex_lock(va->verifs_mtx);
    --(*va->running_verifs);
    pthread_mutex_unlock(va->verifs_mtx);
    TS_PRINT("[VERIF-%d] terminazione\n", va->id + 1); /* LOG */
    return NULL;
}

int main(int argc, char *argv[]){
    check_args(argc, argv);
    int M = atoi(argv[1]); if(M <= 0) exit_with_msg("M deve essere >0");
    int N = argc - 2;

    TS_PRINT("[MAIN] creazione di %d thread lettori e %d thread verificatori\n", N, M); /* LOG */
    Queue inter_q, final_q;
    queue_init(&inter_q, INTER_CAP);
    queue_init(&final_q, FINAL_CAP);

    int active_readers = N;
    int running_verifs = M;
    pthread_mutex_t readers_mtx, verifs_mtx;
    pthread_mutex_init(&readers_mtx, NULL);
    pthread_mutex_init(&verifs_mtx, NULL);

    pthread_t *rth = malloc(sizeof(pthread_t)*N);
    pthread_t *vth = malloc(sizeof(pthread_t)*M);
    ReaderArg *rarg = malloc(sizeof(ReaderArg)*N);
    VerifArg *varg = malloc(sizeof(VerifArg)*M);

    for(int i = 0; i<N; ++i){
        rarg[i] = (ReaderArg){argv[i+2],i,&inter_q,&active_readers,&readers_mtx};
        if(pthread_create(&rth[i], NULL, reader_thread, &rarg[i])) exit_with_error("pthread_create reader");
    }
    for(int j = 0; j<M; ++j){
        varg[j] = (VerifArg){j,&inter_q,&final_q,&active_readers,&running_verifs,&readers_mtx,&verifs_mtx};
        if(pthread_create(&vth[j], NULL, verifier_thread, &varg[j])) exit_with_error("pthread_create verifier");
    }

    // coda finale <-pop- main -printf-> stdout
    while(1){
        Square s;
        if(queue_try_pop(&final_q, &s)){
            int sum=  s.v[0] + s.v[1] + s.v[2]; // sum = is_magic(s.v); ci farebbe un controllo in più
            TS_PRINT("[MAIN] quadrato magico trovato da lettore %d, sequenza %d, somma magica %d:\n"
                   "(%d,%d,%d)\n(%d,%d,%d)\n(%d,%d,%d)\n",
                   s.reader_id, s.seq_no,
                   s.v[0], s.v[1], s.v[2], s.v[3], s.v[4], s.v[5],
                   s.v[6], s.v[7], s.v[8], sum  );
            continue;
        }
        pthread_mutex_lock(&verifs_mtx);
        bool done = (running_verifs == 0);
        pthread_mutex_unlock(&verifs_mtx);
        if(done && final_q.count==0) break;
        usleep(1000);
    }

    // join threads ? serve in questo caso? 
    //  Non ci servono perchè in questo punto di codice ci siamo solo se running_verifs == 0, e running_verifs == 0 se è solo se active_readers == 0;
    // ciò vuol dire che tutti i lettori hanno terminato e anche i verificatori hanno terminato.
    // le lasciamo solo per completezza
    for(int i = 0; i < N; ++i) if(pthread_join(rth[i], NULL)) exit_with_error("pthread_join reader");
    for(int j = 0; j < M; ++j) if(pthread_join(vth[j], NULL)) exit_with_error("pthread_join verifier");

    TS_PRINT("[MAIN] terminazione\n"); /* LOG */

    queue_destroy(&inter_q); queue_destroy(&final_q); free(rth); free(vth); free(rarg); free(varg);
    return EXIT_SUCCESS;
} 