/**
 * esempio che mostra come 1+n (il thread principale più altri n addizionali) si
 * possono coordinare su alcuni passaggi (partenza e terminazione) utilizzando
 * una barriera; gli 1+n thread sono trattati alla pari e alla fine viene usato
 * il thread prescelto dalla barriera come gestore dell'ultima fase
 */

#include "lib-misc.h"
#include <assert.h>
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_ADDITIONAL_THREADS 5
#define NUM_TOTAL_THREADS (NUM_ADDITIONAL_THREADS + 1)
#define MAX_RANDOM_PAUSE 5

typedef struct {
    pthread_t tid;
    unsigned int id;

    pthread_barrier_t *barrier_ptr;
} thread_data_t;

void *thread_function(void *arg) {
    assert(arg);
    int err;
    thread_data_t *data_ptr = (thread_data_t *)arg;

    if ((err = pthread_barrier_wait(data_ptr->barrier_ptr)) > 0)
        exit_with_err("pthread_barrier_wait", err);

    printf("[T%u] thread partito!\n", data_ptr->id);

    sleep((rand() % MAX_RANDOM_PAUSE)+1); // range: [1 ... MAX]

    printf("[T%u] thread terminato!\n", data_ptr->id);

    if ((err = pthread_barrier_wait(data_ptr->barrier_ptr)) > 0)
        exit_with_err("pthread_barrier_wait", err);

    if (err == PTHREAD_BARRIER_SERIAL_THREAD) {
        printf("[T%u] thread eletto come coordinatore sull'ultima "
               "sincronizzazione sulla barriera\n",
               data_ptr->id);
        printf("[T%u] tutti i thread (tranne il sottoscritto) hanno terminato "
               "il loro compito\n",
               data_ptr->id);

        // non indispensabile ma è una buona abitudine...
        if ((err = pthread_barrier_destroy(data_ptr->barrier_ptr)))
            exit_with_err("pthread_barrier_destroy", err);
        // NB: questa operazione sarà fatta una sola volta dal thread
        // coordinatore
    }

    return (NULL);
}

int main(int argc, char *argv[]) {
    int err;

    srand(time(NULL));

    printf(
        "creazione di %d+1 thread con sincronizzazione tramite barriera...\n",
        NUM_ADDITIONAL_THREADS);

    // alloco i dati privati e condivisi dei vari thread sull'heap: in questo
    // esempio, a differenza di tutti gli altri visti fino ad ora, verrà gestito
    // come un thread alla pari di tutti gli altri e non eseguirà la `exit` (ma
    // invece la `pthread_exit`); questo comporterà che, in linea di principio,
    // potrebbe terminare prima degli altri thread e quindi i dati allocati nel
    // suo stack potrebbero non essere più integri quando consultati dagli altri
    // thread (precauzione!)
    thread_data_t *thread_data_ptr = malloc (NUM_TOTAL_THREADS * sizeof(thread_data_t));
    assert(thread_data_ptr);
    pthread_barrier_t *barrier_ptr = malloc (sizeof(pthread_barrier_t));
    assert(barrier_ptr);
    if ((err = pthread_barrier_init(barrier_ptr, NULL, NUM_TOTAL_THREADS)))
        exit_with_err("pthread_barrier_init", err);

    // il thread principale verrà gestito alla pari come tutti gli altri
    thread_data_ptr[0].id = 0;
    thread_data_ptr[0].barrier_ptr = barrier_ptr;

    // creazione dei thread addizionali (oltre quello principale del main)
    for (int i = 1; i <= NUM_ADDITIONAL_THREADS; i++) {
        thread_data_ptr[i].id = i;
        thread_data_ptr[i].barrier_ptr = barrier_ptr;
        if ((err = pthread_create(&thread_data_ptr[i].tid, NULL, thread_function,
                                  (void *)(&thread_data_ptr[i]))))
            exit_with_err("pthread_create", err);
    }

    sleep(2); // gli altri comunque devono aspettare il thread principale (T0)

    printf("pronti alla partenza...\n");

    // il thread principale (T0) eseguirà un'altra istanza della funzione
    // `thread_function` alla pari con tutti gli altri
    pthread_exit(thread_function((void *)(&thread_data_ptr[0])));

    // il flusso di esecuzione non arriverà mai qui
    assert(false);

    // NB: il processo terminerà solo quando l'ultimo thread avrà terminato (a
    // prescindere da chi sarà)
}