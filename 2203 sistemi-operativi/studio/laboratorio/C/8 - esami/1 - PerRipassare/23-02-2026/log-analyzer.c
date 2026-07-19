#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <string.h>

typedef struct record{
    int id;
    char* timestamp;
    int severita;
    char* messaggio;
    char* path;
} record;

typedef struct coda{
    struct record** records;
    pthread_mutex_t mutex;
    sem_t full;
    sem_t empty;
    int head;
    int tail;
    int size;
} coda;

typedef struct sharedData{
    coda* codaGrezza;
    coda* codaFiltrata;

    int lettoriTotali;
    int lettoriFiniti;
    int filtriTotali;
    int filtriFiniti;
    pthread_mutex_t mutexFine;

} sharedData;

typedef struct threadData{
    int id;
    char* path;
    int N;
    int R;
    int threshold;

    sharedData* shared;
}threadData;

int getSeverita(char* s){
    if(strcmp(s, "DEBUG") == 0) return 1;
    if(strcmp(s, "INFO") == 0) return 2;
    if(strcmp(s, "WARNING") == 0) return 3;
    if(strcmp(s, "ERROR") == 0) return 4;
    if(strcmp(s, "CRITICAL") == 0) return 5;
    return 0;
}

coda* codaInit(coda* q, int n){
    q->records = malloc(sizeof(record*)*n);
    pthread_mutex_init(&(q->mutex),0);
    sem_init(&(q->full),0, 0);
    sem_init(&(q->empty),0, n);
    q->head = q->tail = 0;
    q->size = n;

    return q;
}

void enqueue(coda* q, record* rc){
    sem_wait(&(q->empty));
    pthread_mutex_lock(&(q->mutex));

    q->records[q->tail] = rc;
    q->tail = (q->tail+1)%q->size;

    pthread_mutex_unlock(&(q->mutex));
    sem_post(&(q->full));
}

record* dequeue(coda* q){
    sem_wait(&(q->full));
    pthread_mutex_lock(&(q->mutex));

    record* rc = q->records[q->head];
    q->head = (q->head+1)%q->size;


    pthread_mutex_unlock(&(q->mutex));
    sem_post(&(q->empty));

    return rc;
}

void safePrintRecord(char* chiSei, int id, char* text, record* rc){
    flockfile(stdout);
    if(rc!=NULL){
        printf("[%s-%d] %s n°%d: %s|%d|%s", chiSei, id, text, rc->id, rc->timestamp, rc->severita, rc->messaggio);
    }
    funlockfile(stdout);
}

void* lettore(void* args){
    threadData* data = (threadData*)args;
    printf("[LETTORE-%d] Inizio la lettura del file: %s\n", data->id, data->path);
    FILE* file = fopen(data->path, "r");
    char buffer[512];
    char* savePtr;
    int counter = 0;
    while(fgets(buffer, 512, file) != NULL){
        record* rc = malloc(sizeof(record));
        rc->timestamp = malloc(sizeof(char)*20);
        rc->messaggio = malloc(sizeof(char)*200);

        rc->path = data->path;
        rc->id = counter;
        strcpy(rc->timestamp, strtok_r(buffer, "|", &savePtr));
        rc->severita = getSeverita(strtok_r(NULL, "|", &savePtr));
        strcpy(rc->messaggio, strtok_r(NULL, "|", &savePtr));

        safePrintRecord("LETTORE", data->id, "Letto candidato", rc);
        enqueue(data->shared->codaGrezza, rc);
        counter++;
    }

    pthread_mutex_lock(&(data->shared->mutexFine));
    data->shared->lettoriFiniti++;

    if(data->shared->lettoriFiniti == data->shared->lettoriTotali){
        for(int i = 0; i < data->shared->filtriTotali; i++){
            enqueue(data->shared->codaGrezza, NULL);
        }
    }
    pthread_mutex_unlock(&(data->shared->mutexFine));

    printf("[LETTORE-%d] Fine lettura del file: %s\n (%d righe lette)", data->id, data->path, counter);
    return NULL;
}

void* filtro(void* args){
    threadData* data = (threadData*)args;
    printf("[FILTRO-%d] Inizio filtraggio\n", data->id);

    while(1){
        record* rc = dequeue(data->shared->codaGrezza);
        if(rc == NULL){
            break;
        }
        if(rc->severita >= data->threshold){
            safePrintRecord("FILTRO", data->id, "Trovato candidato filtrato", rc);
            enqueue(data->shared->codaFiltrata, rc);
        }else{
            free(rc->messaggio);
            free(rc->timestamp);
            free(rc);
        }
    }

    pthread_mutex_lock(&(data->shared->mutexFine));
    data->shared->filtriFiniti++;

    if(data->shared->filtriFiniti == data->shared->filtriTotali){
        for(int i = 0; i < data->shared->filtriTotali; i++){
            enqueue(data->shared->codaFiltrata, NULL);
        }
    }
    pthread_mutex_unlock(&(data->shared->mutexFine));


    printf("[FILTRO-%d] Fine filtraggio\n", data->id);
    return NULL;
}


int main(int argc, char* argv[]){
    int N = argc-3;
    int R = atoi(argv[2]);
    int threshold = getSeverita(argv[1]);

    sharedData* sh = malloc(sizeof(sharedData));
    sh->codaGrezza = malloc(sizeof(coda));
    sh->codaFiltrata = malloc(sizeof(coda));
    sh->codaGrezza = codaInit(sh->codaGrezza, 10);
    sh->codaFiltrata = codaInit(sh->codaFiltrata, 5);

    sh->filtriTotali = R;
    sh->lettoriTotali = N;
    sh->lettoriFiniti = sh->filtriFiniti = 0;
    pthread_mutex_init(&(sh->mutexFine),0);

    pthread_t lettoriTh[N];
    pthread_t filtriTh[R];

    for(int i = 0; i < N; i++){
        threadData* data = malloc(sizeof(threadData));
        data->id = i;
        data->N = N;
        data->R = R;
        data->path = argv[i+3];
        data->threshold = threshold;
        data->shared = sh;

        pthread_create(&lettoriTh[i], NULL, lettore, (void*)data);
    }

    for(int i = 0; i < R; i++){
        threadData* data = malloc(sizeof(threadData));
        data->id = i;
        data->N = N;
        data->R = R;
        data->threshold = threshold;
        data->shared = sh;

        pthread_create(&filtriTh[i], NULL, filtro, (void*)data);
    }


    int filtriFiniti = 0;
    int counterSev[6] = {0, 0, 0, 0, 0, 0};
    while (1){
        record* rc = dequeue(sh->codaFiltrata);
        if(rc == NULL){
            filtriFiniti++;
            if(filtriFiniti == R){
                break;
            }
        }else{
            safePrintRecord("MAIN", 0, "Estratto candidato filtrato", rc);
            counterSev[rc->severita]++;
            free(rc->messaggio);
            free(rc->timestamp);
            free(rc);
        }
    }

    for(int i = 0; i < N; i++){
        pthread_join(lettoriTh[i], NULL);
    }
    for(int i = 0; i < R; i++){
        pthread_join(filtriTh[i], NULL);
    }

    printf("Riepilogo: (soglia %d)\n", threshold);
    printf("DEBUG: %d\n", counterSev[1]);
    printf("INFO: %d\n", counterSev[2]);
    printf("WARNING: %d\n", counterSev[3]);
    printf("ERROR: %d\n", counterSev[4]);
    printf("CRITICAL: %d\n", counterSev[5]);



    return 0;
}