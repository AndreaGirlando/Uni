#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <string.h>

#define bufferSize 1024

struct record{
    char* id;
    int* numeri;
    char*  path;
};

struct coda{
    struct record** records;
    int len;
    sem_t full;
    sem_t empty;
    pthread_mutex_t mutex;
    int tail;
    int head;
};

void printArray(int* v, int n, char* chiSei, int Id, char* text){
    flockfile(stdout);
    printf("[%s-%d] %s", chiSei, Id, text);
    for(int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    funlockfile(stdout);
}

struct coda* codaInit(struct coda* q, int len){
    q->records = malloc(sizeof(struct record*)*len);
    pthread_mutex_init(&(q->mutex), 0);
    sem_init(&(q->full),0, 0);
    sem_init(&(q->empty),0, len);
    q->len = len;
    q->tail = q->head = 0;

    return q;
}

void enqueue(struct coda* q, struct record* rc){
    sem_wait(&(q->empty));
    pthread_mutex_lock(&(q->mutex));
    q->records[q->tail] = rc;
    q->tail = (q->tail+1)%q->len;
    pthread_mutex_unlock(&(q->mutex));
    sem_post(&(q->full));
}

struct record* dequeue(struct coda* q){
    sem_wait(&(q->full));
    pthread_mutex_lock(&(q->mutex));
    struct record* rc = q->records[q->head];
    q->head = (q->head+1)%q->len;
    pthread_mutex_unlock(&(q->mutex));
    sem_post(&(q->empty));

    return rc;
}

struct sharedData{
    struct coda* codaCandidati;
    struct coda* codaVincenti;
    int* vincenti;

    int lettoriRimanenti;
    int numeroVerificatori;
    pthread_mutex_t mutex;

};

struct threadData{
    int id;
    char* path;
    struct sharedData* shared;
};

struct record* stringToRecord(char* string, char* path){
    char* saveptr = NULL;
    struct record* r = malloc(sizeof(struct record));
    r->path = path;
    r->id = malloc(sizeof(char)*20);
    strcpy(r->id, strtok_r(string, ";", &saveptr));
    r->numeri = malloc(sizeof(int)*6);
    r->numeri[0] = atoi(strtok_r(NULL, ",", &saveptr));
    r->numeri[1] = atoi(strtok_r(NULL, ",", &saveptr));
    r->numeri[2] = atoi(strtok_r(NULL, ",", &saveptr));
    r->numeri[3] = atoi(strtok_r(NULL, ",", &saveptr));
    r->numeri[4] = atoi(strtok_r(NULL, ",", &saveptr));
    r->numeri[5] = atoi(strtok_r(NULL, ",", &saveptr));
    return r;
}

int numeriIndovinati(int* win, int* verify, int n){
    int counter = 0;
    for(int i = 0;  i < n; i++){
        for(int j = 0;  j < n; j++){
            if(win[i] == verify[j]){
                counter++;
            }
        }
    }
    return counter;
}


struct record* createEndRecord(){
    struct record* r = malloc(sizeof(struct record));
    r->id = NULL;
    r->numeri = malloc(sizeof(int)*6);
    r->numeri[0] = -1;
    return r;
}

void* lettore(void* args){
    struct threadData* data = (struct threadData*)args;
    printf("[READER-%d] Inizio la lettura di %s\n", data->id, data->path);

    FILE* fd = fopen(data->path, "r");
    char *buffer = malloc(sizeof(char)*bufferSize);
    while(fgets(buffer, bufferSize, fd) != NULL){
        struct record* rh = stringToRecord(buffer, data->path);
        enqueue(data->shared->codaCandidati, rh);
        printArray(rh->numeri, 6, "READER", data->id, "Aggiunto un nuovo candidato ");
    }

    //Race condition per modificare il numeri di lettori rimanenti
    pthread_mutex_lock(&data->shared->mutex);
    data->shared->lettoriRimanenti--;
    if (data->shared->lettoriRimanenti == 0) {
        for (int i = 0; i < data->shared->numeroVerificatori; i++) {
            enqueue(data->shared->codaCandidati, createEndRecord());
        }
    }
    pthread_mutex_unlock(&data->shared->mutex);

    printf("[READER-%d] Fine lettura di %s\n", data->id, data->path);
    return NULL;
}

void* verificatore(void* args){
    struct threadData* data = (struct threadData*)args;
    printf("[CHECKER-%d] Inizio con la verifica\n", data->id);

    while(1){
        struct record* rh = dequeue(data->shared->codaCandidati);
        if(rh->numeri[0] == -1) break;
        if(numeriIndovinati(data->shared->vincenti, rh->numeri, 6) >= 3){
            printArray(rh->numeri, 6, "CHECKER", data->id, "Trovato un candidato valido ");
            enqueue(data->shared->codaVincenti, rh);
        }
    }

    // Per far finire il main
    enqueue(data->shared->codaVincenti, createEndRecord());

    printf("[CHECKER-%d] Fine verifica\n", data->id);
    return NULL;
}

int main(int argc, char* argv[]){

    int N = argc-3;
    int M = atoi(argv[2]);
    char* win = argv[1];

    printf("[MAIN] Inizio con la creazione di %d lettori e %d verificatori (file con numeri vincenti: %s)\n", N, M, win);

    pthread_t lettori[N];
    pthread_t verificatori[M];

    struct sharedData* sh = malloc(sizeof(struct sharedData));
    sh->codaCandidati = malloc(sizeof(struct coda));
    sh->codaVincenti = malloc(sizeof(struct coda));
    sh->codaCandidati = codaInit(sh->codaCandidati, 10);
    sh->codaVincenti = codaInit(sh->codaVincenti, 5);
    sh->lettoriRimanenti = N;
    sh->numeroVerificatori = M;
    pthread_mutex_init(&(sh->mutex), 0);

    sh->vincenti = malloc(sizeof(int)*6);
    FILE* winFile = fopen(win, "r");
    fscanf(winFile, "%d, %d, %d, %d, %d, %d",
        &(sh->vincenti[0]), &(sh->vincenti[1]), &(sh->vincenti[2]),
        &(sh->vincenti[3]), &(sh->vincenti[4]), &(sh->vincenti[5])
    );

    for(int i = 0; i < N; i ++){
        struct threadData* data = malloc(sizeof(struct threadData));
        data->id = i;
        data->path = argv[i+3];
        data->shared = sh;

        pthread_create(&lettori[i], NULL, lettore, (void*)data);
    }

    for(int i = 0; i < M; i ++){
        struct threadData* data = malloc(sizeof(struct threadData));
        data->id = i;
        data->shared = sh;

        pthread_create(&verificatori[i], NULL, verificatore, (void*)data);
    }

    int finishCounter = 0;


    int p4 = 0;
    int p3 = 0;
    int p2 = 0;
    int p1 = 0;

    while(1){
        struct record* rh = dequeue(sh->codaVincenti);
        if(rh->numeri[0] == -1) {
            finishCounter++;
            if(finishCounter >= M){
                break;
            }
        }

        int n = numeriIndovinati(sh->vincenti, rh->numeri, 6);
        if(n>=3){
            if(n == 3){
                printArray(rh->numeri, 6, "MAIN", 0, "Biglietto vincente -> quarto premio ");
                p4++;
            }
            if(n == 4){
                printArray(rh->numeri, 6, "MAIN", 0, "Biglietto vincente -> terzo premio ");
                p3++;
            }
            if(n == 5){
                printArray(rh->numeri, 6, "MAIN", 0, "Biglietto vincente -> secondo premio ");
                p2++;
            }
            if(n == 6){
                printArray(rh->numeri, 6, "MAIN", 0, "Biglietto vincente -> jackpot ");
                p1++;
            }
        }
    }

    for(int i = 0; i < N; i ++){
        pthread_join(lettori[i], NULL);
    }
    for(int i = 0; i < M; i ++){
        pthread_join(verificatori[i], NULL);
    }


    printf("Riepilogo finale: \n");
    printf("Quarto premio: %d\n", p4);
    printf("Terzo premio: %d\n", p3);
    printf("Secondo premio: %d\n", p2);
    printf("Jackpot: %d\n", p1);
    printf("Totale biglietti vincenti: %d\n", p1+p2+p3+p4);



    printf("[MAIN] Fine");
    return 0;
}