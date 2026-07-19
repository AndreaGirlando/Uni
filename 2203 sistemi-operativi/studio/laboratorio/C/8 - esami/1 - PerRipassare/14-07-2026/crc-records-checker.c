#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>

struct record {
    uint8_t* valori;
    uint8_t checksum;
    uint8_t checksumRicalcolato;
    int id;
    char* filePath;
    int fileId;
};

struct coda{
    struct record** records;
    char* file;
    pthread_cond_t not_full;
    pthread_cond_t not_empty;
    pthread_mutex_t mutex;
    int tail;
    int head;
    int len;
    int count;
};

struct ternaCounter{
    int dichiarati;
    int integri;
    int corrotti;
    int numeroRecord;
    char* file;
};

struct sharedData{
    struct coda* codaCandidati;
    struct coda* codaScartati;

    struct ternaCounter* tc;

    pthread_mutex_t mutexTerna;

    int lettoriFiniti;
    int verificatoriFiniti;
    int lettoriTotali;
    int verificatoriTotali;
};

struct threadData{
    int id;
    char* path;
    int N;
    int M;

    struct sharedData* shared;
};

struct coda* codaInit(struct coda* q, int len){
    pthread_mutex_init(&(q->mutex),0);
    pthread_cond_init(&(q->not_full), 0);
    pthread_cond_init(&(q->not_empty), 0);
    q->records = malloc(sizeof(struct record*)*len);
    q->tail = q->head =  q->count = 0;
    q->len = len;

    return q;
}

void enqueue(struct coda* q, struct record* rc){
    pthread_mutex_lock(&(q->mutex));
    while(q->count == q->len){
        pthread_cond_wait(&(q->not_full), &(q->mutex));
    }

    q->records[q->tail] = rc;
    q->tail = (q->tail+1)%q->len;
    q->count++;

    pthread_cond_signal(&(q->not_empty));
    pthread_mutex_unlock(&(q->mutex));
}

struct record* dequeueCandidati(struct sharedData* sh){
    pthread_mutex_lock(&(sh->codaCandidati->mutex));
    while(sh->codaCandidati->count == 0 && sh->lettoriFiniti < sh->lettoriTotali){
        pthread_cond_wait(&(sh->codaCandidati->not_empty), &(sh->codaCandidati->mutex));
    }

    if(sh->codaCandidati->count == 0 && sh->lettoriFiniti == sh->lettoriTotali){
        pthread_mutex_unlock(&(sh->codaCandidati->mutex));
        return NULL;
    }

    struct record* rc = sh->codaCandidati->records[sh->codaCandidati->head];
    sh->codaCandidati->head = (sh->codaCandidati->head+1)%sh->codaCandidati->len;
    sh->codaCandidati->count--;

    pthread_cond_signal(&(sh->codaCandidati->not_full));
    pthread_mutex_unlock(&(sh->codaCandidati->mutex));

    return rc;
}

struct record* dequeueScartati(struct sharedData* sh){
    pthread_mutex_lock(&(sh->codaScartati->mutex));
    while(sh->codaScartati->count == 0 && sh->verificatoriFiniti < sh->verificatoriTotali){
        pthread_cond_wait(&(sh->codaScartati->not_empty), &(sh->codaScartati->mutex));
    }

    if(sh->codaScartati->count == 0 && sh->verificatoriFiniti == sh->verificatoriTotali){
        pthread_mutex_unlock(&(sh->codaScartati->mutex));
        return NULL;
    }

    struct record* rc = sh->codaScartati->records[sh->codaScartati->head];
    sh->codaScartati->head = (sh->codaScartati->head+1)%sh->codaScartati->len;
    sh->codaScartati->count--;

    pthread_cond_signal(&(sh->codaScartati->not_full));
    pthread_mutex_unlock(&(sh->codaScartati->mutex));

    return rc;
}

uint8_t ricalcolaChecksum(uint8_t* array, int n){
    uint8_t sm = 0;
    for(int i = 0; i < n; i++){
        sm+=array[i];
    }
    return sm%256;
}

void* lettori(void* args){
    struct threadData* data = (struct threadData*)args;
    printf("[LETTORE-%d] Inizio a leggere il file: %s\n", data->id, data->path);
    int fd = open(data->path, O_RDONLY);
    struct stat sb;
    fstat(fd, &sb);

    void* p = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    uint32_t header = ((uint32_t*)p)[0];
    int numeroRecord = (sb.st_size-4)/16;

    data->shared->tc[data->id].numeroRecord = numeroRecord;
    data->shared->tc[data->id].dichiarati = header;

    printf("[LETTORE] file: %s: %d record totali, %d dichiarati integri\n", data->path, numeroRecord, header);

    for(int i = 0; i < numeroRecord; i++){
        struct record* rc = malloc(sizeof(struct record));
        rc->valori = malloc(sizeof(uint8_t)*15);
        rc->id = i;
        rc->fileId = data->id;
        rc->filePath = data->path;
        for(int j = 0; j < 15; j++){
            int offset = 4+i*16+j;
            rc->valori[j] = ((uint8_t*)p)[offset];
        }
        rc->checksum = ((uint8_t*)p)[4+i*16+15];
        enqueue(data->shared->codaCandidati, rc);
    }

    pthread_mutex_lock(&(data->shared->codaCandidati->mutex));
    data->shared->lettoriFiniti++;
    pthread_cond_broadcast(&data->shared->codaCandidati->not_empty);
    pthread_mutex_unlock(&(data->shared->codaCandidati->mutex));

    printf("[LETTORE-%d] Finito di leggere il file: %s (%d record letti)\n", data->id, data->path, numeroRecord);
    return NULL;
}

void* verificatori(void* args){
    struct threadData* data = (struct threadData*)args;
    printf("[VERIFICATORE-%d] Inizio la verifica\n", data->id);
    while(1){
        struct record* rc = dequeueCandidati(data->shared);
        if(rc == NULL){
            break;
        }
        rc->checksumRicalcolato = ricalcolaChecksum(rc->valori, 15);
        pthread_mutex_lock(&(data->shared->mutexTerna));
        if(rc->checksum == rc->checksumRicalcolato){
            data->shared->tc[rc->fileId].integri++;
        }else{
            data->shared->tc[rc->fileId].corrotti++;
            enqueue(data->shared->codaScartati, rc);
        }
        pthread_mutex_unlock(&(data->shared->mutexTerna));

    }

    pthread_mutex_lock(&(data->shared->codaScartati->mutex));
    data->shared->verificatoriFiniti++;
    pthread_cond_broadcast(&data->shared->codaScartati->not_empty);
    pthread_mutex_unlock(&(data->shared->codaScartati->mutex));

    printf("[VERIFICATORE-%d] Fine verifica\n", data->id);
    return NULL;
}

int main(int argc, char* argv[]){
    int N = argc - 2;
    int M = atoi(argv[1]);
    printf("[MAIN] Creo %d verificatori e %d lettori\n", M, N);

    pthread_t lettTh[N];
    pthread_t verifTh[M];

    struct sharedData* sh = malloc(sizeof(struct sharedData));
    sh->codaCandidati = malloc(sizeof(struct coda));
    sh->codaScartati = malloc(sizeof(struct coda));

    sh->codaCandidati = codaInit(sh->codaCandidati, 10);
    sh->codaScartati = codaInit(sh->codaScartati, 5);
    pthread_mutex_init(&(sh->mutexTerna),0);


    sh->lettoriFiniti = 0;
    sh->verificatoriFiniti = 0;
    sh->lettoriTotali = N;
    sh->verificatoriTotali = M;

    sh->tc = malloc(sizeof(struct ternaCounter)*N);
    for(int i = 0; i < N; i++){
        sh->tc[i].corrotti = 0;
        sh->tc[i].dichiarati = 0;
        sh->tc[i].integri = 0;
        sh->tc[i].numeroRecord = 0;
        sh->tc[i].file = argv[i+2];
    }

    for(int i = 0; i < N; i++){
        struct threadData* th = malloc(sizeof(struct threadData));
        th->id = i;
        th->M = M;
        th->N = N;
        th->shared = sh;
        th->path = argv[i+2];
        pthread_create(&lettTh[i], NULL, lettori, (void*)th);
    }

    for(int i = 0; i < M; i++){
        struct threadData* th = malloc(sizeof(struct threadData));
        th->id = i;
        th->M = M;
        th->N = N;
        th->shared = sh;
        pthread_create(&verifTh[i], NULL, verificatori, (void*)th);
    }

    while(1){
        struct record* rc = dequeueScartati(sh);
        if(rc == NULL){
            break;
        }
        flockfile(stdout);
        printf("[MAIN] Record corrotto: n. %d del file %s: checksum dichiarato %d, checksum ricalcolato %d\n",
            rc->id, rc->filePath, rc->checksum, rc->checksumRicalcolato
        );
        funlockfile(stdout);
    }


    for(int i = 0; i < N; i++){
        pthread_join(lettTh[i], NULL);
    }

    for(int i = 0; i < M; i++){
        pthread_join(verifTh[i], NULL);
    }

    int counterGiusti = 0;
    for(int i = 0; i < N; i++){
        flockfile(stdout);
        printf("[MAIN] file %s: %d integri e %d corrotti su %d record -> verifica automatica %s\n",
            sh->tc[i].file,  sh->tc[i].integri, sh->tc[i].corrotti, sh->tc[i].numeroRecord, sh->tc[i].integri == sh->tc[i].dichiarati? "superata":"fallita"
        );
        if(sh->tc[i].integri == sh->tc[i].dichiarati) counterGiusti++;
        funlockfile(stdout);
    }
    printf("[MAIN] Terminazione con %d/%d verifiche superate\n", counterGiusti, N);
    return 0;
}