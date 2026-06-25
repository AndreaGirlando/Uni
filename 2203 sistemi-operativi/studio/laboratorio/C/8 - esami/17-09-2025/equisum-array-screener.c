//! Leggere usando mmap e non come viene fatto qui
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <fcntl.h>

#define lenArray 10
#define numberInArrray 12
#define NUM_VERIFICATORI 3

void printArray(int* v, int N){
    for(int i = 0; i < N; i++){
        printf("%d ", v[i]);
    }
}

int isEquisomma(int* v, int N){
    int sommaPari = 0;
    int sommaDispari = 0;

    for(int i = 0; i < N; i++){
        if(i % 2 == 0) sommaPari += v[i];
        else sommaDispari += v[i];
    }

    return sommaPari == sommaDispari;
}

struct coda{
    int** vettore;
    int tail;
    int head;
    pthread_mutex_t mutex;
    sem_t full;
    sem_t empty;
};

struct coda* codaInit(struct coda* q){
    q->vettore = malloc(sizeof(int*) * lenArray);
    q->tail = 0;
    q->head = 0;

    pthread_mutex_init(&(q->mutex), NULL);
    sem_init(&(q->full), 0, 0);
    sem_init(&(q->empty), 0, lenArray);

    return q;
}

void codaEnqueue(struct coda* q, int* n){
    sem_wait(&(q->empty));

    pthread_mutex_lock(&(q->mutex));
    q->vettore[q->tail] = n;
    q->tail = (q->tail + 1) % lenArray;
    pthread_mutex_unlock(&(q->mutex));

    sem_post(&(q->full));
}

int* codaDequeue(struct coda* q){
    sem_wait(&(q->full));

    pthread_mutex_lock(&(q->mutex));
    int* r = q->vettore[q->head];
    q->head = (q->head + 1) % lenArray;
    pthread_mutex_unlock(&(q->mutex));

    sem_post(&(q->empty));

    return r;
}

struct sharedData{
    struct coda* codaIntermedia;

    int* recordFinale;
    sem_t recordPieno;
    sem_t recordVuoto;

    int lettoriTerminati;
    int numeroLettori;
    pthread_mutex_t mutexLettori;
};

struct threadData{
    int id;
    char* path;
    struct sharedData* shared;
};

void* lettore(void* arg){
    struct threadData* data = (struct threadData*)arg;

    flockfile(stdout);
    printf("[Lettore-%d] Start\n", data->id);
    funlockfile(stdout);

    int fd = open(data->path, O_RDONLY);
    if(fd < 0){
        perror("open");
        return NULL;
    }

    unsigned char buffer[numberInArrray];

    while(read(fd, buffer, numberInArrray) == numberInArrray){
        int* temp = malloc(sizeof(int) * numberInArrray);

        for(int i = 0; i < numberInArrray; i++){
            temp[i] = buffer[i];
        }

        codaEnqueue(data->shared->codaIntermedia, temp);
    }

    close(fd);

    pthread_mutex_lock(&(data->shared->mutexLettori));

    data->shared->lettoriTerminati++;

    if(data->shared->lettoriTerminati == data->shared->numeroLettori){
        for(int j = 0; j < NUM_VERIFICATORI; j++){
            int* stop = malloc(sizeof(int) * numberInArrray);
            stop[0] = -1;
            codaEnqueue(data->shared->codaIntermedia, stop);
        }
    }

    pthread_mutex_unlock(&(data->shared->mutexLettori));

    flockfile(stdout);
    printf("[Lettore-%d] End\n", data->id);
    funlockfile(stdout);

    return NULL;
}

void* verificatore(void* arg){
    struct threadData* data = (struct threadData*)arg;

    flockfile(stdout);
    printf("[Verificatore-%d] Start\n", data->id);
    funlockfile(stdout);

    while(1){
        int* r = codaDequeue(data->shared->codaIntermedia);

        if(r[0] == -1){
            free(r);

            sem_wait(&(data->shared->recordVuoto));
            data->shared->recordFinale = NULL;
            sem_post(&(data->shared->recordPieno));

            break;
        }

        if(isEquisomma(r, numberInArrray)){
            sem_wait(&(data->shared->recordVuoto));
            data->shared->recordFinale = r;
            sem_post(&(data->shared->recordPieno));
        } else {
            free(r);
        }
    }

    flockfile(stdout);
    printf("[Verificatore-%d] End\n", data->id);
    funlockfile(stdout);

    return NULL;
}

int main(int argc, char* argv[]){
    if(argc < 2){
        printf("Uso: %s file1 [file2 ...]\n", argv[0]);
        return 1;
    }

    int N = argc - 1;

    pthread_t thLettori[N];
    pthread_t thVerificatori[NUM_VERIFICATORI];

    struct sharedData* cond = malloc(sizeof(struct sharedData));

    cond->codaIntermedia = malloc(sizeof(struct coda));
    codaInit(cond->codaIntermedia);

    cond->recordFinale = NULL;
    sem_init(&(cond->recordPieno), 0, 0);
    sem_init(&(cond->recordVuoto), 0, 1);

    cond->lettoriTerminati = 0;
    cond->numeroLettori = N;
    pthread_mutex_init(&(cond->mutexLettori), NULL);

    for(int i = 0; i < N; i++){
        struct threadData* data = malloc(sizeof(struct threadData));
        data->id = i;
        data->shared = cond;
        data->path = argv[i + 1];

        pthread_create(&thLettori[i], NULL, lettore, data);
    }

    for(int i = 0; i < NUM_VERIFICATORI; i++){
        struct threadData* data = malloc(sizeof(struct threadData));
        data->id = i + 1;
        data->shared = cond;
        data->path = NULL;

        pthread_create(&thVerificatori[i], NULL, verificatore, data);
    }

    int verificatoriTerminati = 0;

    while(verificatoriTerminati < NUM_VERIFICATORI){
        sem_wait(&(cond->recordPieno));

        int* r = cond->recordFinale;

        if(r == NULL){
            verificatoriTerminati++;
        } else {
            printf("[MAIN] Vettore equisomma: ");
            printArray(r, numberInArrray);
            printf("\n");

            free(r);
        }

        cond->recordFinale = NULL;
        sem_post(&(cond->recordVuoto));
    }

    for(int i = 0; i < N; i++){
        pthread_join(thLettori[i], NULL);
    }

    for(int i = 0; i < NUM_VERIFICATORI; i++){
        pthread_join(thVerificatori[i], NULL);
    }

    return 0;
}