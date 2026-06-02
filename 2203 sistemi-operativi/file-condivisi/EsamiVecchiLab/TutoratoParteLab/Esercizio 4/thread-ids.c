#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void print_info(const char *thread_name){
    pid_t pid = getpid();
    pthread_t tid = pthread_self();

    printf("[%s] pid: %d, tid: %lu\n", thread_name, pid, (unsigned long)tid);   
}

void *thread_function(void *arg){
    printf("[%s] is running...\n", (char *)arg);
    print_info((char *)arg);
    printf("[%s] is finished.\n", (char *)arg);
    return NULL;
}

int main(int argc, char *argv[]){
    int err;
    pthread_t thread1, thread2;

    print_info("main");

    if((err = pthread_create(&thread1, NULL, thread_function, "thread1")) != 0){
        fprintf(stderr, "Error creating thread1: %s\n", strerror(err));
        exit(EXIT_FAILURE);
    }

    if((err = pthread_create(&thread2, NULL, thread_function, "thread2")) != 0){
        fprintf(stderr, "Error creating thread2: %s\n", strerror(err));
        exit(EXIT_FAILURE);
    }

    // Wait for threads to finish
    if((err = pthread_join(thread1, NULL)) != 0){
        fprintf(stderr, "Error joining thread1: %s\n", strerror(err));
        exit(EXIT_FAILURE);
    }

    if((err = pthread_join(thread2, NULL)) != 0){
        fprintf(stderr, "Error joining thread2: %s\n", strerror(err));
        exit(EXIT_FAILURE);
    }

    printf("main has finished.\n");
    exit(EXIT_SUCCESS);
}