/**
 * implementazione problematica `thread-conc-problem` resa corretta attraverso
 * l'uso di un mutex lock sui dati condivisi
 * 
 * > ./thread-conc-problem-fixed-with-mutex
 * > ./thread-conc-problem-fixed-with-mutex 6
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define DEFAULT_NUM_THREADS 3
#define MIN_NUM_THREADS 1
#define MAX_NUM_THREADS 6
#define THREAD_NAMES                                                           \
    { "Qui", "Quo", "Qua", "Zio Paperone", "Paperino", "Pippo" }
#define INITIAL_TOTAL_VALUE 0
#define INCREMENTS_PER_THREAD 10000000

void exit_with_err(const char *msg, int err) {
    fprintf(stderr, "%s: %s\n", msg, strerror(err));
    exit(EXIT_FAILURE);
}

void exit_with_err_msg(const char *msg, int value) {
    fprintf(stderr, msg, value);
    exit(EXIT_FAILURE);
}

struct shared_data {
    unsigned long total;
    pthread_mutex_t lock;
};

struct thread_data {
    // dati privati:
    pthread_t tid;
    char *name;
    unsigned long increments;

    // dati condivisi:
    struct shared_data *shared;
};

void *thread_function(void *arg) {
    int err;
    struct thread_data *data_ptr = (struct thread_data *)arg;

    printf("[%s] applicazione progressiva dei %lu incrementi...\n",
           data_ptr->name, data_ptr->increments);

    while (data_ptr->increments > 0) {
        // acquisizione lock
        if ((err = pthread_mutex_lock(&data_ptr->shared->lock)) != 0)
            exit_with_err("pthread_mutex_lock", err);
        
        data_ptr->shared->total++; // sezione critica

        // rilascio lock
        if ((err = pthread_mutex_unlock(&data_ptr->shared->lock)) != 0)
            exit_with_err("pthread_mutex_lock", err);

        data_ptr->increments--; // sezione non critica
    }

    printf("[%s] incrementi applicati!\n", data_ptr->name);

    return (NULL);
}

int main(int argc, char *argv[]) {
    int err;
    unsigned int num_threads = DEFAULT_NUM_THREADS;
    char *thread_names[] = THREAD_NAMES;

    // inizializzazione dei dati condivisi e del relativo lock
    struct shared_data shared = {INITIAL_TOTAL_VALUE,
                                 PTHREAD_MUTEX_INITIALIZER};

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
        datas[i].shared = &shared;
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
    printf("[main] controllo valore finale: reale=%lu atteso=%lu\n",
           shared.total, expected_total);
    if (shared.total == expected_total) {
        printf("[main] risultato corretto!\n");
        exit(EXIT_SUCCESS);
    } else {
        printf("[main] risultato ERRATO!\n");
        exit(EXIT_FAILURE);
    }
}
