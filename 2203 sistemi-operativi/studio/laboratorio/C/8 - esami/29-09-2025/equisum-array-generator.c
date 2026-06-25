#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdlib.h>
#include <time.h>

#define RECORDSLEN 5


int* generaDati(int N){

    int* vett = malloc(sizeof(int)*N);
    for(int i = 0; i < N; i++){
        vett[i] = rand()%99;
    }
    return vett;
}

void stampaArray(int N, int* vett){
    for(int i = 0; i < N; i++){
        printf("%d ", vett[i]);
    }
}

int isEquisomma(int N, int* vett){
    int sommaPari = 0;
    int sommaDispari = 0;
    for(int i = 0; i < N; i++){
        if(i%2==0) sommaPari+=vett[i];
        else sommaDispari+=vett[i];
    }
    return sommaDispari == sommaPari;
}


struct record{
    int* vettore;
    int round;
};

struct coda{
    struct record** records;
    pthread_mutex_t mutex;
    int tail;
    int head;
    int maxLen;
    sem_t full;
    sem_t empty;
};

void codaPrint(struct coda* q){
    pthread_mutex_lock(&(q->mutex));
    for(int i = 0; i < q->tail; i++){
        printf("%d\t", q->records[i]->round);
        stampaArray(q->maxLen,q->records[i]->vettore);
        printf("\n");
    }
    pthread_mutex_unlock(&(q->mutex));
}

void codaInit(struct coda* q, int N){
    q->records = malloc(sizeof(struct record* )*RECORDSLEN);
    pthread_mutex_init(&(q->mutex), NULL);
    sem_init(&(q->full), 0, 0);
    sem_init(&(q->empty), 0, RECORDSLEN);
    q->head = 0;
    q->tail = 0;
    q->maxLen = N;
}

void codaEnqueue(struct coda* q, struct record* r){
    sem_wait(&(q->empty));
    pthread_mutex_lock(&(q->mutex));
    q->records[q->tail] = r;
    q->tail = (q->tail+1)%RECORDSLEN;
    pthread_mutex_unlock(&(q->mutex));
    sem_post(&(q->full));
}

struct record* codaDequeue(struct coda* q){
    sem_wait(&(q->full));
    pthread_mutex_lock(&(q->mutex));
    struct record* temp = q->records[q->head];
    q->head = (q->head+1)%RECORDSLEN;
    pthread_mutex_unlock(&(q->mutex));
    sem_post(&(q->empty));

    return temp;
}

struct sharedData{
    struct coda* codaProposte;
    struct coda* codaScartati;
};

struct threadData{
    int id;
    int N;
    int T;
    int R;

    struct sharedData* shared;
};

void* generatore(void* arg){
    struct threadData* data = (struct threadData*)arg;
    printf("[Generatore] Start \n");
    for(int i = 0; i < data->T; i++){
        int* v = generaDati(data->N);
        flockfile(stdout);
        printf("[Generatore] inserisco nella coda: ");
        stampaArray(data->N, v);
        printf("\n");
        funlockfile(stdout);

        struct record* r = malloc(sizeof(struct record));
        r->round = 0;
        r->vettore = v;

        codaEnqueue(data->shared->codaProposte, r);
    }
    printf("[Generatore] End");
    return NULL;
}

void* verificatore(void* arg){
    struct threadData* data = (struct threadData*)arg;
    printf("\n[Verificatore] Start \n");
    int verificati = 0;
    while(true){
        struct record* r = codaDequeue(data->shared->codaProposte);
        flockfile(stdout);
        printf("[Verificatore] Ho appena letto: ");
        stampaArray(data->N, r->vettore);
        printf("\n");
        funlockfile(stdout);
        if(isEquisomma(data->N, r->vettore) == 0)
            codaEnqueue(data->shared->codaScartati, r);
        else verificati++;

        if(verificati == data->T) break;
    }
    printf("\n[Verificatore] Array verificati: %d\n", verificati);
    printf("\n[Verificatore] End \n");
    for(int i = 0; i < data->R; i++){
        struct record* r = malloc(sizeof(struct record));
        r->vettore = NULL;
        r->round = -1;
        codaEnqueue(data->shared->codaScartati, r);
    }
    return NULL;
}

void* riparatore(void* arg){
    struct threadData* data = (struct threadData*)arg;
    printf("\n[Riparatore-%d]: Start\n", data->id);
    while(true){
        struct record* r = codaDequeue(data->shared->codaScartati);
        if(r->vettore == NULL && r->round == -1) break;
        flockfile(stdout);
        printf("\n[Riparatore-%d] Ho appena letto: ", data->id);
        stampaArray(data->N, r->vettore);
        printf("\n");
        funlockfile(stdout);
        r->round++;
        r->vettore[rand()%data->N] = rand()%99;
        codaEnqueue(data->shared->codaProposte, r);
    }
    printf("\n[Riparatore-%d]: End\n", data->id);
    return NULL;
}


int main(int argc, char* argv[]){
    srand(time(NULL));
    int N = atoi(argv[1]);
    int T = atoi(argv[2]);
    int R = atoi(argv[3]);

    struct sharedData cond;
    cond.codaProposte = malloc(sizeof(struct coda));
    cond.codaScartati = malloc(sizeof(struct coda));
    codaInit(cond.codaProposte, N);
    codaInit(cond.codaScartati, N);


    struct threadData dataGen = {1, N, T, R, &cond};
    struct threadData dataVer = {1, N, T, R, &cond};

    pthread_t thGen;
    pthread_t thVer;

    pthread_create(&thGen, NULL, generatore, ((void*)&dataGen));
    pthread_create(&thVer, NULL, verificatore, ((void*)&dataVer));

    pthread_t thRip[R];
    for(int i = 0; i < R; i++){
        struct threadData* dataThread = malloc(sizeof(struct threadData));
        dataThread->id = i;
        dataThread->N = N;
        dataThread->T = T;
        dataThread->R = R;
        dataThread->shared = &cond;
        pthread_create(&thRip[i], NULL, riparatore, ((void*)dataThread));
    }
    pthread_join(thGen, NULL);
    pthread_join(thVer, NULL);
    for(int i = 0; i < R; i++){
        pthread_join(thRip[i], NULL);
    }



    return 0;
}