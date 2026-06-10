/**
 * implementazione basata su thread del problema classico dei conti correnti con
 * relativa race-condition: è possibile variare il numero di thread dalla riga
 * di comando (minimo 1, massimo 6); si tratta anche di un esempio su come si
 * può predisporre una struttura dati per thread che comprenda molteplici dati
 * privati ma anche riferimenti a strutture dati condivise
 */

#include "../FattiInAula/lib-misc.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define DEFAULT_NUM_THREADS 3
#define MIN_NUM_THREADS 1
#define MAX_NUM_THREADS 6
#define THREAD_NAMES                                                           \
    { "Qui", "Quo", "Qua", "Zio Paperone", "Paperino", "Pippo" }
#define INITIAL_TOTAL_VALUE 0
#define INCREMENTS_PER_THREAD 10000000

struct thread_data {
    // dati privati:
    pthread_t tid;
    char *name;
    unsigned long increments;

    // dati condivisi:
    unsigned long *shared_total;
};

void *thread_function(void *arg) {
    struct thread_data *data_ptr = (struct thread_data *)arg;

    printf("[%s] applicazione progressiva dei %lu incrementi...\n",
           data_ptr->name, data_ptr->increments);

    while (data_ptr->increments > 0) {
        (*data_ptr->shared_total)++;    // modifica della variabile condivisa
        data_ptr->increments--;
    }

    printf("[%s] incrementi applicati!\n", data_ptr->name);

    return (NULL);
}

int main(int argc, char *argv[]) {
    int err;
    unsigned long total = 0;
    unsigned int num_threads = DEFAULT_NUM_THREADS;
    char *thread_names[] = THREAD_NAMES;

    if (argc > 1) {
        if ((num_threads = atoi(argv[1])) < MIN_NUM_THREADS ||
            (num_threads > MAX_NUM_THREADS))
            exit_with_err_msg("numero di thread (%d) non valido!\n",
                              num_threads);
    }

    struct thread_data datas[num_threads];
    unsigned long expected_total =
        INITIAL_TOTAL_VALUE + (num_threads * INCREMENTS_PER_THREAD);

    // preparazione delle strutture dati da passare ai thread
    for (int i = 0; i < num_threads; i++) {
        // dati privati
        datas[i].name = thread_names[i];
        datas[i].increments = INCREMENTS_PER_THREAD;

        // dati condivisi
        datas[i].shared_total = &total;
    }

    // creazione dei thread
    for (int i = 0; i < num_threads; i++) {
        printf("[main] creazione del thread '%s'...\n", datas[i].name);
        if ((err = pthread_create(&datas[i].tid, NULL, thread_function,
                                  (void *)(&datas[i]))) != 0)
            exit_with_err("pthread_create", err);
    }

    // attesa della terminazione dei thread
    for (int i = 0; i < num_threads; i++) {
        printf("[main] attesa terminazione del thread '%s'...\n",
               datas[i].name);
        if ((err = pthread_join(datas[i].tid, NULL)) != 0)
            exit_with_err("pthread_join", err);
        printf("[main] thread '%s' terminato!\n", datas[i].name);
    }

    // controllo del risultato
    printf("[main] controllo valore finale: reale=%lu atteso=%lu\n", total,
           expected_total);
    if (total == expected_total) {
        printf("[main] risultato corretto!\n");
        exit(EXIT_SUCCESS);
    } else {
        printf("[main] risultato ERRATO!\n");
        exit(EXIT_FAILURE);
    }
}
