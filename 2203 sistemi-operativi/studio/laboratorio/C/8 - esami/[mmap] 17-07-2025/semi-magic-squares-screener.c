#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

int isSemimagica(int* matrix, int N){
    int sommaDiRiferimento = 0;
    for(int i = 0; i < N; i++){
        sommaDiRiferimento+=matrix[i];
    }

    for(int i = 0; i < N; i++){
        int sommaRiga = 0;
        int sommaColonna = 0;

        for(int j = 0; j<N; j++){
            sommaRiga+=matrix[i*N+j];
            sommaColonna+=matrix[j*N+i];
        }

        if(sommaRiga != sommaDiRiferimento || sommaColonna != sommaDiRiferimento) return 0;
    }

    return 1;
}

int isEnding(int* matrix, int N){
    for(int i = 0; i < N; i++){
        if(matrix[i] != -1)  return 0;
    }
    return 1;
}

void stampaMatrice(int* matrix, int N){
    for(int i = 0; i < N; i++){
        printf("%d ", matrix[i]);
    }
    printf("\n");
}

struct queue{
    int** coda;
    pthread_mutex_t mutex;
    sem_t full;
    sem_t empty;
    int tail;
    int head;
    int max;
};

struct queue* init(struct queue* q, int max){
    q->max = max;
    q->coda = malloc(sizeof(int*)*q->max);
    pthread_mutex_init((&q->mutex), 0);
    sem_init(&(q->full),0,0);
    sem_init(&(q->empty),0,q->max);
    q->tail = 0;
    q->head = 0;
    return q;
}

void enqueue(struct queue* q, int* matrix){
    sem_wait(&(q->empty));
    pthread_mutex_lock(&(q->mutex));
    q->coda[q->tail] = matrix;
    q->tail = (q->tail+1)%q->max;
    pthread_mutex_unlock(&(q->mutex));
    sem_post(&(q->full));
}

int* dequeue(struct queue* q){
    sem_wait(&(q->full));
    pthread_mutex_lock(&(q->mutex));
    int *element = q->coda[q->head];
    q->head = (q->head+1)%q->max;
    pthread_mutex_unlock(&(q->mutex));
    sem_post(&(q->empty));

    return element;
}

void stampaCoda(struct queue* q, int dimensioneMatrice){
    for(int i = 0; i<(q->tail); i++){
        stampaMatrice(q->coda[i], dimensioneMatrice);
    }
}

struct sharedData{
    struct queue* codaIntermedia;
    struct queue* codaFinale;
};

struct threadData{
    int id;
    char* path;
    int N;
    int M;

    struct sharedData* shared;
};


void* lettore(void* arg){
    struct threadData* th = (struct threadData*)arg;
    printf("[Lettore-%d]: inizio a leggere il file: %s\n", th->id, th->path);

    int fd = open(th->path, O_RDONLY);
    struct stat sb;
    fstat(fd, &sb);
    unsigned char *p = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);

    int itemInMatrix = th->M*th->M;
    int counter = sb.st_size/(itemInMatrix); // con matrici 5x5 dovrò creare st_size/25 matrici diverse
    for(int i = 0; i < counter; i++){
        int *mx = malloc(sizeof(int) * itemInMatrix);
        for(int j = 0; j < itemInMatrix; j++){
            mx[j] = p[i*itemInMatrix+j]; //indice dove i*itemInMatrix è l'inizio della matrice i-esima e j è l'offset dello specifico elemento
        }
        enqueue(th->shared->codaIntermedia, mx);
    }

    int* matrix = malloc(sizeof(int)*itemInMatrix);
    for(int i = 0; i < itemInMatrix; i++){
        matrix[i] = -1;
    }
    enqueue(th->shared->codaIntermedia, matrix);

    printf("[Lettore-%d]: Finito di leggere il file: %s\n", th->id, th->path);
}

void* verificatore(void* arg){
    struct threadData* th = (struct threadData*)arg;
    printf("[Verificatore-%d]: Inizio verifica\n", th->id);
    int countLettori = 0;
    while(1){
        int* value = dequeue(th->shared->codaIntermedia);
        int dimMatrix = (th->M)*(th->M);
        if(isEnding(value, dimMatrix)){
            countLettori++;
            if(countLettori == th->N){
                enqueue(th->shared->codaFinale, value);
                break;
            };
        }
        else if(isSemimagica(value, th->M)){
            enqueue(th->shared->codaFinale, value);
        }
    }
    printf("[Verificatore-%d]: Fine verifica\n", th->id);
}


int main(int argc, char* argv[]){
    int M = atoi(argv[1]);
    int N = argc-2;
    pthread_t lettori[N];
    pthread_t verificaId;

    printf("[Main]: Inizio con la creazione di %d lettori e un verificatore\n", N);

    struct sharedData* sh = malloc(sizeof(struct sharedData));
    sh->codaIntermedia = malloc(sizeof(struct queue));
    sh->codaIntermedia = init(sh->codaIntermedia, 5);
    sh->codaFinale = malloc(sizeof(struct queue));
    sh->codaFinale = init(sh->codaFinale, 1);

    struct threadData* verificatoreTh = malloc(sizeof(struct threadData));
    verificatoreTh->id = 1;
    verificatoreTh->shared = sh;
    verificatoreTh->N = N;
    verificatoreTh->M = M;

    // Creazione thread lettori
    for(int i = 0; i < N; i++){
        struct threadData* th = malloc(sizeof(struct threadData));
        th->id = i;
        th->path = argv[i+2];
        th->shared = sh;
        th->N = N;
        th->M = M;
        pthread_create(&lettori[i], NULL, lettore, (void*)th);
    }

    //Creazione thread verificatore
    pthread_create(&verificaId, NULL, verificatore, (void*)verificatoreTh);

    int count = 0;
    while(1){
        int* res = dequeue(sh->codaFinale);
        if(isEnding(res, M*M)){
            break;
        }
        count++;
        flockfile(stdout);
        printf("[Main]: Trovata una matrice semimagica: ");
        stampaMatrice(res, M*M);
        funlockfile(stdout);
    }

    for(int i = 0; i < N; i++){
        pthread_join(lettori[i], NULL);
    }

    pthread_join(verificaId, NULL);

    printf("[Main]: Fine con %d matrici semimagiche", count);

}