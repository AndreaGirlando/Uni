/* Esercizio 3a - 
* Scrivere un programma in C denominato count-mmap.c
* che utilizza mmap per contare il numero di righe e parole in un file. Il programma deve:
1 - aprire il file in modalità lettura; 
2 - mappare il contenuto in memoria con mmap;
3 - contare righe e parole;
4 - stampare i risultati a video;
5 - gestire correttamente eventuali errori e liberare le risorse con munmap
*/
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "lib-misc.h"
#include <pthread.h>

typedef struct{
    int lines;
    int words;
    char * mapAddress;
    struct stat st_len;
} thread_reading_resources;

void * thread_read(void * args){
    thread_reading_resources * threadRes = (thread_reading_resources *)args;
    printf("[T_READ] Starting to read...\n");
    for(int i = 0; i < threadRes->st_len.st_size; i++){
        if(threadRes->mapAddress[i]=='\n'){
            threadRes->lines++;
            printf("[T_READ] Read line #%d\n", threadRes->lines);
        }
        if(threadRes->mapAddress[i]==' '){
            threadRes->words++;
            //printf("[T_READ] Add word n %d\n", threadRes->words);
        }
    }
    //adding latter words and lines - because they starts at 0
    threadRes->words++;
    threadRes->lines++;
    //unmapping 
    if((munmap(threadRes->mapAddress, threadRes->st_len.st_size))!=0){
        free(threadRes->mapAddress);
        exit_with_sys_err("munmap");
    }
    threadRes->mapAddress=NULL; //avoiding a dangling pointer?
    printf("[T_READ] Exiting...\n");
    pthread_exit((void*)threadRes);
}

int main(int argc, char *argv[]){
    if(argc !=2){
        printf("Usage: %s <file_to_count>", argv[0]);
        exit_with_err("Usage error", 1);
    }

    int fdToCount;
    char * mapped;
    struct stat state_checker;
    if((fdToCount = open(argv[1], O_RDONLY))==-1){ //opening the item
        close(fdToCount);
        exit_with_sys_err("open failed");
    }
    if((fstat(fdToCount, &state_checker))!= 0){ //creating a stat out of the item
        close(fdToCount);
        exit_with_sys_err("fstat failed");
    }

    if(!S_ISREG(state_checker.st_mode)){ //checking if it is a regular file
        close(fdToCount);
        exit_with_sys_err("item provided is not a file");
    }
    //mapping the file
    if((mapped = (char * )mmap(NULL, state_checker.st_size, PROT_READ, MAP_PRIVATE, fdToCount, 0))==MAP_FAILED){
        close(fdToCount);
        munmap(mapped, state_checker.st_size);
        exit_with_sys_err("mmap failed");
    }
    pthread_t readingThread;
    //assigning the resources
    thread_reading_resources readRes = {.lines=0, .words=0, .mapAddress=mapped, .st_len = state_checker};
    if((close(fdToCount))!=0){
        exit_with_sys_err("file close error");
    }

    //starting the thread with resources and function
    if((pthread_create(&readingThread, NULL, thread_read, (void *)&readRes))!=0){
        exit_with_sys_err("pthread_create");
    }

    int ret;
    thread_reading_resources newStructure;
    //join - and assignign the return value to the new structure
    if((ret = pthread_join(readingThread, (void *)&newStructure))!=0){
        exit_with_sys_err("pthread_join");
    }
    //print results to video
    printf("[MAIN] Successfully counted: %d lines, %d words\n", readRes.lines, readRes.words);
    exit(EXIT_SUCCESS);
}