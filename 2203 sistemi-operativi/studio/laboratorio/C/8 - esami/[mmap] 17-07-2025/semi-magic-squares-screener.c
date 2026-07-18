#include <stdio.h>
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
    }

    return 1;
}

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
}


int main(int argc, char* argv[]){
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
}