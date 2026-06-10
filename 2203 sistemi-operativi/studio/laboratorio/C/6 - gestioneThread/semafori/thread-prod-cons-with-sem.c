/**
 * esempio sul modello produttore-consumatore con una coda di numeri di
 * dimensione fissata usando dei semafori numerici
 */

#include "../FattiInAula/lib-misc.h"
#include <assert.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define QUEUE_CAPACITY 10
#define NUM_OF_ITEMS_TO_PRODUCE 300

/* < number-queue >
 * una coda ciclica per numeri con una capacità fissa prestabilita */
typedef struct {
    unsigned long capacity;
    unsigned long size;
    unsigned long in, out;
    long *data;
} number_queue_t;

void number_queue_init(number_queue_t *queue_ptr, unsigned long capacity) {
    assert(queue_ptr);
    assert(capacity > 0);

    queue_ptr->capacity = capacity;
    queue_ptr->size = queue_ptr->in = queue_ptr->out = 0;
    queue_ptr->data = malloc(queue_ptr->capacity * sizeof(long));
    assert(queue_ptr->data);
}

void number_queue_destroy(number_queue_t *queue_ptr) {
    assert(queue_ptr);
    assert(queue_ptr->capacity > 0);
    assert(queue_ptr->data);

    free(queue_ptr->data);
    queue_ptr->data = NULL;
    queue_ptr->capacity = queue_ptr->size = 0;
    queue_ptr->in = queue_ptr->out = 0;
}

bool number_queue_is_empty(number_queue_t *const queue_ptr) {
    assert(queue_ptr);

    return (queue_ptr->size == 0);
}

bool number_queue_is_full(number_queue_t *const queue_ptr) {
    assert(queue_ptr);

    return (queue_ptr->size == queue_ptr->capacity);
}

bool number_queue_push(number_queue_t *queue_ptr, long num) {
    assert(queue_ptr);

    if (number_queue_is_full(queue_ptr))
        return false;

    queue_ptr->data[queue_ptr->in] = num;
    queue_ptr->in = (queue_ptr->in + 1) % queue_ptr->capacity;
    queue_ptr->size++;

    return true;
}

bool number_queue_pop(long *extr_num_ptr, number_queue_t *queue_ptr) {
    assert(queue_ptr);
    assert(extr_num_ptr);

    if (number_queue_is_empty(queue_ptr))
        return false;

    *extr_num_ptr = queue_ptr->data[queue_ptr->out];
    queue_ptr->out = (queue_ptr->out + 1) % queue_ptr->capacity;
    queue_ptr->size--;

    return true;
}

void number_queue_print(const char* prefix, number_queue_t *const queue_ptr) {
    assert(queue_ptr);

    printf("%s{ ", prefix);
    for (unsigned long i = 0; i < queue_ptr->size; i++)
        printf("%lu%s",
               queue_ptr->data[(queue_ptr->out + i) % queue_ptr->capacity],
               (i + 1 < queue_ptr->size ? ", " : ""));
    printf(" } [%lu/%lu]\n", queue_ptr->size, queue_ptr->capacity);
}
/* < number-queue > */

typedef struct {
    number_queue_t queue;
    sem_t full, empty, mutex;
    bool end_of_work;
} shared_data_t;

typedef struct {
    pthread_t tid;
    unsigned long items_to_produce;

    shared_data_t *shared_data_ptr;
} producer_data_t;

typedef struct {
    pthread_t tid;

    shared_data_t *shared_data_ptr;
} consumer_data_t;

void *producer_function(void *arg) {
    assert(arg);

    long total_to_return = 0;
    long number;
    int err;
    producer_data_t *data_ptr = (producer_data_t *)arg;

    printf("[P] produttore attivato...\n");

    while (data_ptr->items_to_produce > 0) {
        // "produzione dell'elemento": un numero a caso
        number = rand();
        total_to_return += number;
        printf("[P] numero '%lu' prodotto\n", number);

        // down(empty)
        if ((err = sem_wait(&data_ptr->shared_data_ptr->empty)))
            exit_with_err("sem_wait", err);

        // down(mutex)
        if ((err = sem_wait(&data_ptr->shared_data_ptr->mutex)))
            exit_with_err("sem_wait", err);

        // inserimento elemento
        if (!number_queue_push(&data_ptr->shared_data_ptr->queue, number))
            exit_with_err_msg("anomalia: fallimento nell'inserimento!\n");

        flockfile(stdout); // trucco per evitare l'interlacciamento delle linee
        printf("[P] numero '%lu' inserito nella coda\n", number);
        number_queue_print("[P] coda attuale: ", &data_ptr->shared_data_ptr->queue);
        funlockfile(stdout); // rilascia il lock su `stdout` acquisito prima

        // controllo sulla necessità di terminare per il produttore
        if ((--data_ptr->items_to_produce) == 0)
            data_ptr->shared_data_ptr->end_of_work = true;

        // up(mutex)
        if ((err = sem_post(&data_ptr->shared_data_ptr->mutex)))
            exit_with_err("sem_post", err);

        // up(full)
        if ((err = sem_post(&data_ptr->shared_data_ptr->full)))
            exit_with_err("sem_post", err);
    }

    printf("[P] produttore terminato con un valore totale di inserimenti "
           "pari a %lu\n",
           total_to_return);

    return ((void *)total_to_return);
}

void *consumer_function(void *arg) {
    assert(arg);

    long total_to_return = 0;
    long number;
    int err;
    bool run = true;
    consumer_data_t *data_ptr = (consumer_data_t *)arg;

    printf("[C] consumatore attivato...\n");

    do {
        // down(full)
        if ((err = sem_wait(&data_ptr->shared_data_ptr->full)))
            exit_with_err("sem_wait", err);

        // down(mutex)
        if ((err = sem_wait(&data_ptr->shared_data_ptr->mutex)))
            exit_with_err("sem_wait", err);

        // estrazione elemento
        if (!number_queue_pop(&number, &data_ptr->shared_data_ptr->queue))
            exit_with_err_msg("anomalia: fallimento sull'estrazione!\n");
        total_to_return += number;

        flockfile(stdout);
        printf("[C] numero '%lu' estratto dalla coda\n", number);
        number_queue_print("[C] coda attuale: ", &data_ptr->shared_data_ptr->queue);
        funlockfile(stdout);

        // controllo sulla necessità di terminare per il consumatore
        if (data_ptr->shared_data_ptr->end_of_work &&
            number_queue_is_empty(&data_ptr->shared_data_ptr->queue))
            run = false;

        // up(mutex)
        if ((err = sem_post(&data_ptr->shared_data_ptr->mutex)))
            exit_with_err("sem_post", err);

        // up(empty)
        if ((err = sem_post(&data_ptr->shared_data_ptr->empty)))
            exit_with_err("sem_post", err);
    } while (run);

    printf("[C] consumatore terminato con un valore totale di inserimenti "
           "pari a %lu\n",
           total_to_return);

    return ((void *)total_to_return);
}

int main(int argc, char *argv[]) {
    int err;

    // inizializzazione di numeri pseudo-causali con un seed legato al tempo
    // NB: il seed è condiviso tra i thread!
    srand(time(NULL));

    // preparazione dati condivisi
    shared_data_t shared;
    shared.end_of_work = false;
    number_queue_init(&shared.queue, QUEUE_CAPACITY);
    if ((err = sem_init(&shared.full, PTHREAD_PROCESS_PRIVATE, 0)))
        exit_with_err("sem_init", err);
    if ((err =
             sem_init(&shared.empty, PTHREAD_PROCESS_PRIVATE, QUEUE_CAPACITY)))
        exit_with_err("sem_init", err);
    if ((err = sem_init(&shared.mutex, PTHREAD_PROCESS_PRIVATE, 1)))
        exit_with_err("sem_init", err);

    // creazione del thread
    producer_data_t prod_data;
    prod_data.shared_data_ptr = &shared;
    prod_data.items_to_produce = NUM_OF_ITEMS_TO_PRODUCE;
    if ((err = pthread_create(&prod_data.tid, NULL, producer_function,
                              (void *)(&prod_data))))
        exit_with_err("pthread_create", err);
    consumer_data_t cons_data;
    cons_data.shared_data_ptr = &shared;
    if ((err = pthread_create(&cons_data.tid, NULL, consumer_function,
                              (void *)(&cons_data))))
        exit_with_err("pthread_create", err);

    // attesa della terminazione dei thread
    long total_insertions, total_extractions;
    if ((err = pthread_join(prod_data.tid, (void **)&total_insertions)))
        exit_with_err("pthread_join", err);
    if ((err = pthread_join(cons_data.tid, (void **)&total_extractions)))
        exit_with_err("pthread_join", err);

    // non indispensabile ma è una buona abitudine...
    number_queue_destroy(&shared.queue);
    sem_destroy(&shared.full);
    sem_destroy(&shared.empty);
    sem_destroy(&shared.mutex);

    // controllo dei totali degli inserimenti ed estrazioni
    printf("[main] controllo dei totali: inserimenti=%lu estrazioni=%lu\n",
           total_insertions, total_extractions);
    if (total_insertions == total_extractions) {
        printf("[main] risultato corretto!\n");
        exit(EXIT_SUCCESS);
    } else {
        printf("[main] risultato ERRATO!\n");
        exit(EXIT_FAILURE);
    }
}
