#include <stdio.h>
#include <stdlib.h> //malloc, free
#include <string.h> 
#include <pthread.h>
#include <unistd.h>
#include "lib-misc.h"

#define DEST_FOLDER "keys_files"

typedef struct {
    FILE * kf;
    size_t bytes;
    size_t len;
    char * line; // = NULL;
    int n_keys; // = 0;
    size_t capacity; // = 16;
    char ** final_keys;
    pthread_mutex_t mutex1;
} readingResources_t;

typedef struct{
    char * key;
    int index;
} thread_keys_t;

void cleanup(char * line, FILE * fd, int n_keys, char ** keys, char * ERR){
    if(line!=NULL){free(line);}
    if(fd!=NULL){fclose(fd);}
    for(int i = 0; i <n_keys; i++){
        free(keys[i]);
    }
    free(keys);
    exit_with_err(ERR, 1);
}

static void* writing_thread(void * args){
    thread_keys_t * thread_arg = (thread_keys_t *)args;
    printf("[T_WRITE] Thread %d started\n", thread_arg->index);
    printf("[T_WRITE] Processing key : %s\n", thread_arg->key);

    char filename[32];
    int fileTarget = snprintf(filename, sizeof(filename), "%s/%d.txt", DEST_FOLDER, thread_arg->index);
    if(fileTarget>= (int)sizeof(filename)){
        fprintf(stderr, "ERROR snprintf");
        return (NULL);
    }
    fflush(stdout);
    printf("[T_WRITE] Thread %d writes key %s in the file %s\n",thread_arg->index, thread_arg->key, filename);

    FILE * out = fopen(filename, "w");
    if(!out){
        fprintf(stderr, "ERROR FOPEN");
        return NULL;
    }
    fprintf(out, "%s\n", thread_arg->key);
    if(fclose(out)!=0){
        fprintf(stderr,"ERROR FCLOSE");
    }
    //cleanup
    printf("[T_WRITE] Thread %d has completed\n", thread_arg->index);
    //free(thread_arg);
    return NULL;
}

void * read_thread(void * args){
    readingResources_t * readRes = (readingResources_t *)args;
    pthread_mutex_lock(&readRes->mutex1);
    char ** keys = malloc(readRes->capacity *sizeof(char*));
    if(!keys){
        cleanup(NULL, readRes->kf, readRes->n_keys, keys, "malloc Keys");
    }
    while((readRes->bytes = getline(&readRes->line, &readRes->len, readRes->kf))!= -1){
        printf("[T_READ] Read %zu bytes\n", readRes->bytes);
        
        if(readRes->bytes>0 && readRes->line[readRes->bytes-1]=='\n'){
            readRes->line[readRes->bytes-1] = '\0';
        }else if(readRes->bytes == 0){
            printf("[T_READ] Line was blank\n");
        }
        char * key_copy = strdup(readRes->line);
        if(!key_copy){
            cleanup(readRes->line, readRes->kf, readRes->n_keys, keys, "strdup failed");
        }
        printf("[T_READ] key saved: %s\n", key_copy);
        //char ** tmp = realloc(keys, (n_keys+1) * sizeof(char *));
        if(readRes->n_keys>=readRes->capacity){
            readRes->capacity= readRes->capacity *2;
            keys = realloc(keys, readRes->capacity *(sizeof(char*)));
            printf("[T_READ] realloc; capacity: %ld\n", readRes->capacity);
            if(!keys){
            cleanup(readRes->line, readRes->kf, readRes->n_keys, keys, "malloc error");
            }
        }
        
        readRes->n_keys++;
        keys[readRes->n_keys-1] = key_copy;
    }
    if(readRes->n_keys<0){
        cleanup(readRes->line, readRes->kf, readRes->n_keys, keys,"TOO FEW KEYS");
    }
    readRes->final_keys = keys;
    printf("[T_READ] final resources cleanup...\n");
    free(readRes->line);
    fclose(readRes->kf);
    pthread_mutex_unlock(&readRes->mutex1);
    printf("[T_READ] READ finished\n");
    return (void *)keys;
}

int main(int argc, char * argv[]){
    if(argc!=2){
        printf("[MAIN] Usage: %s <keys-file>\n",argv[0]);
        exit_with_err("Wrong Usage", 1);
    }

    FILE * kf;
    if((kf = fopen(argv[1], "r"))<0){
        exit_with_sys_err("File Open");
    }
    readingResources_t readRes = {.line =NULL, .n_keys=0, .capacity = 16};
    readRes.kf=kf;

    printf("[MAIN] Enter reading phase\n");
    
    pthread_t threadRead;
    pthread_create(&threadRead, NULL, (void *)read_thread, (void*)&readRes);
    readRes.final_keys = (char **) pthread_join(threadRead,NULL);
    
    printf("[MAIN] back to main now\n");
    
    /*debug checker: everything seems to work
    for(int i = 1; i <= readRes.n_keys; i++){
        printf("[MAIN] PRINTING %d KEY: %s\n", i, readRes.final_keys[i]);
    }
    */

    //allocating memory for as many threads as I need = exactly n_keys
    pthread_t * thread_list = malloc(readRes.n_keys * sizeof(pthread_t));
    thread_keys_t * thread_args = malloc(readRes.n_keys * sizeof(thread_keys_t));
    if((thread_list == NULL) || (thread_args==NULL)){
        free(thread_list);
        free(thread_args);
        cleanup(NULL,NULL,readRes.n_keys, readRes.final_keys, "Error: pthread creation failed");
    }

    int create_result=0, join_result=0;
    printf("[MAIN]: Starting the threads...\n");
    for(int i = 0; i<readRes.n_keys; i++){
        thread_args[i].index = i+1;
        thread_args[i].key = readRes.final_keys[i];
        printf("[MAIN]: Start thread %d -- key: %s\n", thread_args[i].index, thread_args[i].key);

        create_result+=pthread_create(&thread_list[i], NULL, (void *)writing_thread, &thread_args[i]);
    }
    pthread_mutex_destroy(&readRes.mutex1);

    for(int i =0; i <readRes.n_keys; i++){
        join_result+=pthread_join(thread_list[i], NULL);
        if(join_result!=0){
            fprintf(stderr, "JOIN ERROR");
        }else{
            printf("[MAIN] Thread %d has been joined\n", i+1);
        }
        free(readRes.final_keys[i]);
    }

    printf("[MAIN] Every thread finished. All's right with the world\n");
    free(readRes.final_keys);
    free(thread_args);
    free(thread_list);
    exit(EXIT_SUCCESS);
}