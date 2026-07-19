#include <stdio.h>
<<<<<<< HEAD:2203 sistemi-operativi/studio/laboratorio/C/8 - esami/17-07-2025/mutex/semi-magic-squares-screener.c
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

struct coda{
    int** values;
    pthread_mutex_t mutex;
    pthread_cond_t not_full;
    pthread_cond_t not_emtpy;
    int tail;
    int head;
    int size;
    int count;
};

struct sharedData{
    struct coda* codaIntermedia;

    int* valueFinale;
    int valueFinaleReady;
    pthread_cond_t not_ready;
    pthread_mutex_t mutex;

    int numeroLettori;
    int lettoriFiniti;
};

struct threadData{
    int id;
    char* path;
    int M;

    struct sharedData* shared;
};

struct coda* codaInit(struct coda* q, int n){
    q->values = malloc(sizeof(int*)*n);
    pthread_mutex_init(&(q->mutex), 0);
    pthread_cond_init(&(q->not_emtpy), 0);
    pthread_cond_init(&(q->not_full), 0);
    q->tail = q->head = q->count = 0;
    q->size = n;

    return q;
}

void enqueue(struct coda* q, int* valori){
    pthread_mutex_lock(&(q->mutex));
    while(q->count == q->size){
        pthread_cond_wait(&(q->not_full),&(q->mutex));
    }
    q->values[q->tail] = valori;
    q->tail = (q->tail+1)%q->size;
    q->count++;

    pthread_cond_broadcast(&(q->not_emtpy));
    pthread_mutex_unlock(&(q->mutex));
}

int* dequeue(struct sharedData* sh){
    pthread_mutex_lock(&(sh->codaIntermedia->mutex));

    while(sh->codaIntermedia->count == 0 && sh->lettoriFiniti < sh->numeroLettori){
        pthread_cond_wait(&(sh->codaIntermedia->not_emtpy),&(sh->codaIntermedia->mutex));
    }

    if(sh->codaIntermedia->count == 0 && sh->lettoriFiniti == sh->numeroLettori){
        pthread_mutex_unlock(&(sh->codaIntermedia->mutex));
        return NULL;
    }

    int* values = sh->codaIntermedia->values[sh->codaIntermedia->head];
    sh->codaIntermedia->head = (sh->codaIntermedia->head+1)%sh->codaIntermedia->size;
    sh->codaIntermedia->count--;


    pthread_cond_broadcast(&(sh->codaIntermedia->not_full));
    pthread_mutex_unlock(&(sh->codaIntermedia->mutex));

    return values;
}

void safePrintMatrix(char* chiSei, int id, char* text, int* matrix, int n){
    flockfile(stdout);
    printf("[%s-%d] %s", chiSei, id, text);
    for(int i = 0; i < n; i++){
        printf("%d ", matrix[i]);
    }
    printf("\n");
    funlockfile(stdout);
}

void* lettori(void* args){
    struct threadData* data = (struct threadData*)args;
    printf("[LETTORE-%d] Inizio la lettura di %s\n", data->id, data->path);

    int fd = open(data->path, O_RDONLY);
    struct stat sb;
    fstat(fd, &sb);
    void* p = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    int dimensioneMatrice = (data->M*data->M);
    int numeroMatrici = sb.st_size/dimensioneMatrice;

    for(int i = 0; i < numeroMatrici; i++){
        int* valori = malloc(sizeof(int)*dimensioneMatrice);
        for(int j  = 0; j < dimensioneMatrice; j++){
            int offset = i*dimensioneMatrice+j;
            valori[j] = ((uint8_t*)p)[offset];
        }
        safePrintMatrix("LETTORE", data->id, "Stampo il candidato: ", valori, dimensioneMatrice);
        enqueue(data->shared->codaIntermedia, valori);
    }

    pthread_mutex_lock(&(data->shared->mutex));
    data->shared->lettoriFiniti++;
    pthread_mutex_unlock(&(data->shared->mutex));


    printf("[LETTORE-%d] Finisco la lettura di %s\n", data->id, data->path);
    return NULL;
}

int isSemimagico(int* valori, int N) {
    // Somma della prima riga
    int somma = 0;
    for (int j = 0; j < N; j++) {
        somma += valori[j];
    }

    // Controllo delle altre righe
    for (int i = 1; i < N; i++) {
        int s = 0;
        for (int j = 0; j < N; j++) {
            s += valori[i * N + j];
        }
        if (s != somma)
            return 0;
    }

    // Controllo delle colonne
    for (int j = 0; j < N; j++) {
        int s = 0;
        for (int i = 0; i < N; i++) {
            s += valori[i * N + j];
        }
        if (s != somma)
            return 0;
=======
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
>>>>>>> 3b87fc038ba2a10f04d0b47add143c0ab6e11aee:2203 sistemi-operativi/studio/laboratorio/C/8 - esami/[mmap] 17-07-2025/mutex/semi-magic-squares-screener.c
    }

    return 1;
}

<<<<<<< HEAD:2203 sistemi-operativi/studio/laboratorio/C/8 - esami/17-07-2025/mutex/semi-magic-squares-screener.c
void* verificatori(void* args){
    struct threadData* data = (struct threadData*)args;
    printf("[VERIFICATORE-%d] Inizio la verifica\n", data->id);

    while(1){
        int* valori = dequeue(data->shared);
        if(valori == NULL){
            break;
        }
        safePrintMatrix("VERIFICATORE", data->id, "Stampo il candidato appena estratto: ", valori, data->M*data->M);
        if(isSemimagico(valori, data->M) == 1){

            pthread_mutex_lock(&(data->shared->mutex));
            while(data->shared->valueFinaleReady){
                pthread_cond_wait(&(data->shared->not_ready), &(data->shared->mutex));
            }
            data->shared->valueFinale = valori;
            data->shared->valueFinaleReady = 1;
            pthread_mutex_unlock(&(data->shared->mutex));
            pthread_cond_broadcast(&(data->shared->not_ready));
        }
    }

    pthread_mutex_lock(&(data->shared->mutex));
    while(data->shared->valueFinaleReady){
        pthread_cond_wait(&(data->shared->not_ready), &(data->shared->mutex));
    }
    data->shared->valueFinale = NULL;
    data->shared->valueFinaleReady = 1;
    pthread_mutex_unlock(&(data->shared->mutex));
    pthread_cond_broadcast(&(data->shared->not_ready));

    printf("[VERIFICATORE-%d] Finisco la verifica\n", data->id);
=======
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
>>>>>>> 3b87fc038ba2a10f04d0b47add143c0ab6e11aee:2203 sistemi-operativi/studio/laboratorio/C/8 - esami/[mmap] 17-07-2025/mutex/semi-magic-squares-screener.c
}


int main(int argc, char* argv[]){
<<<<<<< HEAD:2203 sistemi-operativi/studio/laboratorio/C/8 - esami/17-07-2025/mutex/semi-magic-squares-screener.c
    int N = argc-2;
    int M = atoi(argv[1]); //Dimensione matrice

    struct sharedData* sh = malloc(sizeof(struct sharedData));
    sh->codaIntermedia = malloc(sizeof(struct coda));
    sh->codaIntermedia = codaInit(sh->codaIntermedia, 5);
    sh->numeroLettori = N;
    sh->valueFinale = malloc(sizeof(int)*(M*M));
    sh->lettoriFiniti = 0;
    sh->valueFinaleReady = 0;
    pthread_mutex_init(&(sh->mutex),0);
    pthread_cond_init(&(sh->not_ready), 0);

    pthread_t lettoriTh[N];
    for(int i = 0; i < N; i++){
        struct threadData* data = malloc(sizeof(struct threadData));
        data->id = i;
        data->M = M;
        data->shared = sh;
        data->path = argv[i+2];

        pthread_create(&lettoriTh[i], NULL, lettori, (void*)data);
    }

    pthread_t verificatoreTh;
    struct threadData* data = malloc(sizeof(struct threadData));
    data->id = 1;
    data->M = M;
    data->shared = sh;
    pthread_create(&verificatoreTh, NULL, verificatori, (void*)data);

    int counter = 0;
    while(1){
        int* valori;
        pthread_mutex_lock(&(data->shared->mutex));
        while(!data->shared->valueFinaleReady){
            pthread_cond_wait(&(data->shared->not_ready), &(data->shared->mutex));
        }
        valori = data->shared->valueFinale;
        if(valori == NULL){
            break;
        }
        safePrintMatrix("MAIN", 0, "Matrice semimagica trovata: ", valori, M*M);
        counter++;
        data->shared->valueFinaleReady = 0;

        pthread_mutex_unlock(&(data->shared->mutex));
        pthread_cond_signal(&(data->shared->not_ready));
    }


    for(int i = 0; i < N; i++){
        pthread_join(lettoriTh[i], NULL);
    }

    pthread_join(verificatoreTh, NULL);

    printf("[MAIN] Terminazione con %d matrici semimagiche trovate", counter);
    return 0;
=======
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

>>>>>>> 3b87fc038ba2a10f04d0b47add143c0ab6e11aee:2203 sistemi-operativi/studio/laboratorio/C/8 - esami/[mmap] 17-07-2025/mutex/semi-magic-squares-screener.c
}