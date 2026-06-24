// la stampa della matrice deve farla il main
// le race condition possono essere gestite meglio
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

struct sharedData {
    int countInter;
    int countFinale;
    int** codaInter;
    int** codaFinale;
    pthread_mutex_t lockInter;
    pthread_mutex_t lockFinale;
};

struct threadData {
    pthread_t id;
    char *path;
    //shared

    struct sharedData* shared;
};


bool isMagic(int* matrix){
    int sum1 = matrix[0] + matrix[4] + matrix[8];
    int sum2 = matrix[2] + matrix[4] + matrix[6];

    return sum1 == sum2;
}

void printArray(int* array, int n){
    for(int j = 0; j<n; j++){
        if(j == 0 || j == 3 || j == 6) printf("(");
        printf(" %d ", array[j]);
        if(j == 2 || j == 5 || j == 8) printf(")");
    }
}

void printValue(int** codaInter, int n){
    for(int i = 0; i < n; i++){
        printArray(codaInter[i], 9);
        printf("\n\n");
    }
}



void *producer(void* arg){
    struct threadData* data = (struct threadData*)arg;
    char buffer[BUFSIZ];
    printf("[%lu|Producer] Inizio a leggere: %s\n", data->id, data->path);

    FILE *file = fopen(data->path, "r");

    while ((fgets(buffer, sizeof(buffer), file)) != NULL){
        int count = 0;
        int* record = malloc(9*sizeof(int));
        char* sliced = strtok(buffer, ",");
        while(sliced != NULL){
            record[count] = atoi(sliced);
            count++;
            sliced = strtok(NULL, ",");
        }

        printf("[%lu|Producer] Matrice candidata:", data->id);
        printArray(record, 9);
        printf("\n");


        pthread_mutex_lock(&(data->shared->lockInter));
        data->shared->codaInter[data->shared->countInter] = record;
        data->shared->countInter++;
        pthread_mutex_unlock(&(data->shared->lockInter));

        //TODO questo break deve essere eliminato
        break;
    }

    // printf("[%lu|Producer] Ho finito di leggere: %s\n", data->id, data->path);

    return 0;
}

void *consumer(void* arg){
    struct threadData* data = (struct threadData*)arg;
    unsigned long return_value = rand() % 255;
    printf("[%lu|Consumer] Sto per iniziare a leggere\n", data->id);

    int *record = malloc(sizeof(int)*9);
    while(true){

        pthread_mutex_lock(&(data->shared->lockInter));
        if(data->shared->countInter>0){
            data->shared->countInter--;
            memcpy(record, data->shared->codaInter[data->shared->countInter], 9*sizeof(int));
            pthread_mutex_lock(&(data->shared->lockFinale));
            if(isMagic(record)){
                data->shared->codaFinale[data->shared->countFinale] = record;
                data->shared->countFinale++;
            }
            pthread_mutex_unlock(&(data->shared->lockFinale));
        }
        pthread_mutex_unlock(&(data->shared->lockInter));



        //TODO questo break deve essere eliminato
        break;
    }

    return ((void*)return_value);
}



int main(int argc, char* argv[]){
    int threadLettori = argc-2;
    int threadConsumatori = atoi(argv[1]);
    int numeroThread = threadLettori+threadConsumatori;
    pthread_t threads[numeroThread];

    struct sharedData cond;
    cond.countInter = 0;
    cond.countFinale = 0;
    pthread_mutex_init(&cond.lockInter, NULL);
    pthread_mutex_init(&cond.lockFinale, NULL);
    cond.codaInter = (int**)malloc(sizeof(int*)*10);
    cond.codaFinale = (int**)malloc(sizeof(int*)*3);

    printf("Inizio creazione %d thread\n", numeroThread);

    for(unsigned long i = 0; i < numeroThread; i++){
        // printf("\n%d\n",i);
        struct threadData* data = malloc(sizeof(struct threadData));
        data->id = i;
        data->shared = &cond;
        data->path = malloc(sizeof(char *));
        if(i<threadLettori){
            strcpy(data->path, argv[i+2]);
            if(pthread_create(&threads[i], NULL, producer, ((void*)data)) != 0) perror(("ThreadCreate"));
        }
        else {
            if(pthread_create(&threads[i], NULL, consumer, ((void*)data)) != 0) perror(("ThreadCreate"));
        }


    }
    for(int i = 0; i < numeroThread; i++){
        void* ret_val;
        if(pthread_join(threads[i], &ret_val) != 0) perror("ThreadJoin");
        printf("[main] Thread %d: ha terminato con %lu\n", i, (unsigned long)ret_val);
    }

    //Dovrei fare un main consumer della coda finale

    printValue(cond.codaFinale, cond.countFinale);

    return 0;
}

