#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#include <time.h>

#define sizeOfQueue 20

struct record{
    int id;
    int *vettore;
    int round;
};

struct coda{
    pthread_mutex_t mutex;
    sem_t full;
    sem_t empty;
    struct record** records;
    int tail;
    int head;
    int M;
};

struct coda* initCoda(struct coda* q, int M){
    pthread_mutex_init(&(q->mutex),0);
    sem_init(&(q->full),1, 0);
    sem_init(&(q->empty),1, sizeOfQueue);
    q->records = malloc(sizeof(struct record)*sizeOfQueue);
    q->tail = q->head = 0;
    q->M = M;
    return q;
}

void enqueue(struct coda* q, struct record* req){
    sem_wait(&(q->empty));
    pthread_mutex_lock(&(q->mutex));

    q->records[q->tail] = req;
    q->tail = (q->tail+1)%sizeOfQueue;

    pthread_mutex_unlock(&(q->mutex));
    sem_post(&(q->full));
}

struct record* dequeue(struct coda* q){
    sem_wait(&(q->full));
    pthread_mutex_lock(&(q->mutex));

    struct record* rh = q->records[q->head];
    q->head = (q->head+1)%sizeOfQueue;

    pthread_mutex_unlock(&(q->mutex));
    sem_post(&(q->empty));

    return rh;
}

void printArray(char* chiSei, int idChiamante, char* words, int id, int* array, int M, int round){
    flockfile(stdout);
    printf("[%s-%d] %s n°%d (round: %d): ",chiSei, idChiamante, words, id, round);
    for(int j = 0; j < M; j++){
        printf("%d ", array[j]);
    }
    printf("\n");
    funlockfile(stdout);
}

int isSpecchio(int *array, int M){
    int prima = 0;
    int seconda = 0;

    for(int i = 0; i < M/2; i++){
        prima+=array[i];
    }

    for(int i = M/2; i < M; i++){
        seconda+=array[i];
    }

    return prima == seconda;
}

struct sharedData{
    struct coda* codaProposte;
    struct coda* codaScartati;
    pthread_mutex_t mutex;
    int counter;
};

int checkCounter(struct sharedData* sh, int N){
    pthread_mutex_lock(&(sh->mutex));
    int ret = sh->counter < N;
    // printf("%d<%d = %d\n", sh->counter, N, sh->counter < N);
    pthread_mutex_unlock(&(sh->mutex));
    return ret;
}

void increaseCounter(struct sharedData* sh){
    pthread_mutex_lock(&(sh->mutex));
    sh->counter++;
    pthread_mutex_unlock(&(sh->mutex));
}

struct threadData{
    int id;
    int N;
    int M;
    struct sharedData* shared;
};

void* Generatore(void* args){
    struct threadData* data = (struct threadData*)args;
    printf("[GEN] Inizio la generazione\n");

    for(int i  = 0; i < data->N; i++){
        int* v = malloc(sizeof(int)*data->M);
        for(int j  = 0; j < data->M; j++){
            v[j] = rand()%99;
        }
        struct record* rec = malloc(sizeof(struct record));
        rec->id = i;
        rec->vettore = v;
        rec->round = 0;
        enqueue(data->shared->codaProposte, rec);
        printArray("GEN", 0, "Generato candidato" ,rec->id, rec->vettore, data->M, rec->round);
    }

    printf("[GEN] Finita la generazione\n");
    return NULL;
}
void* Verificatore(void* args){
    struct threadData* data = (struct threadData*)args;
    printf("[Ver-%d] Inizio la verifica\n", data->id);
    int counter = 0;

    while(checkCounter(data->shared, data->N)){
        struct record* rec = dequeue(data->shared->codaProposte);
        if(rec->id == -1 && rec->vettore == NULL && rec->round == 0){
            // Se ricevo questo record speciale lo rinvio indietro e poi finisco
            rec->id = -1;
            rec->vettore = NULL;
            rec->round = 0;
            enqueue(data->shared->codaScartati, rec);
            break;
        }
        if(isSpecchio(rec->vettore, data->M)){
            printArray("VER", data->id, "array accettato" ,rec->id, rec->vettore, data->M, rec->round);
            counter++;
            increaseCounter(data->shared);
        }else{
            printArray("VER", data->id, "array scartato" ,rec->id, rec->vettore, data->M, rec->round);
            enqueue(data->shared->codaScartati, rec);
        }
    }
    // Record speciale che innesca la chiusura di un riparatore (e a cascata di tutti i verifica/riparatori)
    struct record* rec = malloc(sizeof(struct record));
    rec->id = -1;
    rec->vettore = NULL;
    rec->round = 0;
    enqueue(data->shared->codaScartati, rec);

    printf("[Ver-%d] Terminato con %d vettori specchio trovati\n", data->id, counter);
    return NULL;
}
void* Riparatore(void* args){
    struct threadData* data = (struct threadData*)args;
    printf("[Rip-%d] Inizio la riparazione\n", data->id);

    while(1){
        struct record* rec = dequeue(data->shared->codaScartati);
        if(rec->id == -1 && rec->vettore == NULL && rec->round == 0){
            // Se ricevo questo record speciale lo rinvio indietro e poi finisco
            rec->id = -1;
            rec->vettore = NULL;
            rec->round = 0;
            enqueue(data->shared->codaProposte, rec);
            break;
        }
        int index = rand()%(data->M);
        rec->round += 1;
        rec->vettore[index] = rand()%99;
        printArray("RIP", data->id, "array scartato" ,rec->id, rec->vettore, data->M, rec->round);

        enqueue(data->shared->codaProposte, rec);
    }

    printf("[Rip-%d] Finito la riparazione\n", data->id);
    return NULL;
}


int main(int argc, char* argv[]){

    int N = atoi(argv[1]);
    int M = atoi(argv[2]);


    printf("[MAIN] Generazione 3 thread riparatori, 3 thread verificatori e un thread generatore (N = %d, M = %d)", N, M);


    struct sharedData* sh = malloc(sizeof(struct sharedData));
    sh->codaProposte = malloc(sizeof(struct coda));
    sh->codaScartati = malloc(sizeof(struct coda));

    sh->codaProposte = initCoda(sh->codaProposte, M);
    sh->codaScartati = initCoda(sh->codaScartati, M);

    sh->counter = 0;
    pthread_mutex_init(&(sh->mutex),0);

    pthread_t gen;
    struct threadData genTh = {1, N, M, sh};

    pthread_t verif1;
    struct threadData verif1Th = {1, N, M, sh};
    pthread_t verif2;
    struct threadData verif2Th = {2, N, M, sh};
    pthread_t verif3;
    struct threadData verif3Th = {3, N, M, sh};

    pthread_t rip1;
    struct threadData rip1Th = {1, N, M, sh};
    pthread_t rip2;
    struct threadData rip2Th = {2, N, M, sh};
    pthread_t rip3;
    struct threadData rip3Th = {3, N, M, sh};

    pthread_create(&gen, NULL, Generatore, &genTh);

    pthread_create(&verif1, NULL, Verificatore, &verif1Th);
    pthread_create(&verif2, NULL, Verificatore, &verif2Th);
    pthread_create(&verif3, NULL, Verificatore, &verif3Th);

    pthread_create(&rip1, NULL, Riparatore, &rip1Th);
    pthread_create(&rip2, NULL, Riparatore, &rip2Th);
    pthread_create(&rip3, NULL, Riparatore, &rip3Th);

    pthread_join(gen, NULL);
    pthread_join(verif1, NULL);
    pthread_join(verif2, NULL);
    pthread_join(verif3, NULL);

    pthread_join(rip1, NULL);
    pthread_join(rip2, NULL);
    pthread_join(rip3, NULL);

    printf("[MAIN] Finito");

    return 0;
}