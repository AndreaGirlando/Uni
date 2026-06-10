/**
 * crea due thread elementari e visualizza PID e TID (thread id) da tutti i
 * thread (thread padre/principale e thread figli/secondari)
 */

#include "../FattiInAula/lib-misc.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_info(const char *name) {
    pid_t pid = getpid();
    pthread_t tid = pthread_self();

    printf("[%s] pid=%d tid=%lu (0x%lx)\n", name, pid, (unsigned long)tid,
           (unsigned long)tid);
}

void *thread_function(void *arg) {
    print_info((char *)arg);

    return (NULL);
}

int main(int argc, char *argv[]) {
    int err;
    pthread_t tid1, tid2;

    print_info("main"); // thread padre/principale

    // creazione thread figli/secondari con passaggio del nome come argomento
    if ((err = pthread_create(&tid1, NULL, thread_function, "T1")) != 0)
        exit_with_err("pthread_create", err);

    if ((err = pthread_create(&tid2, NULL, thread_function, "T2")) != 0)
        exit_with_err("pthread_create", err);

    sleep(1);

    //exit(EXIT_SUCCESS);
}