#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdint.h>

struct stack{
    int* array;
    pthread_mutex_t mutex;
    sem_t full;
    sem_t empty;
    int head;
    int dim;
};

struct stack* stackInit(struct stack* st, int s){
    st->array = malloc(sizeof(int)*s);
    pthread_mutex_init(&(st->mutex), 0);
    sem_init(&(st->empty), 0, s);
    sem_init(&(st->full), 0, 0);
    st->head = 0;
    st->dim = s;
}

void enqueue(struct stack* st, int n){
    sem_wait(&(st->empty));
    pthread_mutex_lock(&(st->mutex));
    st->array[st->head] = n;
    st->head++;
    pthread_mutex_unlock(&(st->mutex));
    sem_post(&(st->full));
}

int dequeue(struct stack* st){
    sem_wait(&(st->full));
    pthread_mutex_lock(&(st->mutex));
    st->head--;
    int n = st->array[st->head];
    pthread_mutex_unlock(&(st->mutex));
    sem_post(&(st->empty));

    return n;
}


int main(){

    int fd = open("5x5-matrix-sample-a.bin", O_RDONLY);
    struct stat sb;
    fstat(fd, &sb);
    int fileSize = sb.st_size;
    void* puntatoreAllaMemoria;
    puntatoreAllaMemoria = mmap(NULL, fileSize, PROT_READ, MAP_PRIVATE, fd, 0);

    for(int i = 0; i < fileSize; i++){
        printf("%d\n", ((unsigned char*)puntatoreAllaMemoria)[i]);
    }

    printf("%d", sizeof(unsigned short int));
    printf("%d", sizeof(unsigned char));


    // FILE* file = fopen("tickets-1.txt", "r");
    // char buffer[1024];
    // while(fgets(buffer, 1024, file)!=NULL){
    //     printf("\n<-------------------------------->\n");
    //     printf("Codice: %s\n", strtok(buffer, ";"));
    //     printf("Numero: %s\n", strtok(NULL, ","));
    //     printf("Numero: %s\n", strtok(NULL, ","));
    //     printf("Numero: %s\n", strtok(NULL, ","));
    //     printf("Numero: %s\n", strtok(NULL, ","));
    //     printf("Numero: %s\n", strtok(NULL, ","));
    //     printf("Numero: %s\n", strtok(NULL, ","));
    //     printf("Numero: %s\n", strtok(NULL, ","));
    //     printf("<-------------------------------->\n");
    // }

    return 0;
}