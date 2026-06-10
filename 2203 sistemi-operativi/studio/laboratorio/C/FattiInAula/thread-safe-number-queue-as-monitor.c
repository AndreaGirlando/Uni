/**
 * altro esempio sul modello produttori-consumatori (con agenti multipli) con
 * una coda di numeri di dimensione prestabilita usando mutex e variabili
 * condizione (nello stile dei monitor)
 */

#include "lib-misc.h"
#include <assert.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define QUEUE_CAPACITY 10
#define NUM_PRODUCERS 3
#define NUM_CONSUMERS 2
#define NUM_OF_ITEMS_TO_PRODUCE 300

/* < safe-number-queue >
 * variante thread-safe di `number-queue` di `thread-prod-cons-with-sem.c`
 * utilizzando mutex e variabili condizione direttamente integrati nella
 * struttura dati */
typedef struct {
    unsigned long capacity;
    unsigned long size;
    unsigned long in, out;
    long *data;
    pthread_mutex_t mutex;
    pthread_cond_t full;  // potrebbe anche essere chiamata `more_space`
    pthread_cond_t empty; // e questa `more_data`
    unsigned int active_producers;
} number_queue_t;

void number_queue_init(number_queue_t *queue_ptr, unsigned long capacity,
                       unsigned int producers) {
    assert(queue_ptr);
    assert(capacity > 0);
    assert(producers > 0);
    int err;

    queue_ptr->capacity = capacity;
    queue_ptr->size = queue_ptr->in = queue_ptr->out = 0;
    queue_ptr->data = malloc(queue_ptr->capacity * sizeof(long));
    assert(queue_ptr->data);

    if ((err = pthread_mutex_init(&queue_ptr->mutex, NULL)))
        exit_with_err("pthread_mutex_init", err);
    if ((err = pthread_cond_init(&queue_ptr->full, NULL)))
        exit_with_err("pthread_cond_init", err);
    if ((err = pthread_cond_init(&queue_ptr->empty, NULL)))
        exit_with_err("pthread_cond_init", err);

    queue_ptr->active_producers = producers;
}

void number_queue_destroy(number_queue_t *queue_ptr) {
    assert(queue_ptr);
    assert(queue_ptr->capacity > 0);
    assert(queue_ptr->data);
    int err;

    free(queue_ptr->data);
    queue_ptr->data = NULL;
    queue_ptr->capacity = queue_ptr->size = 0;
    queue_ptr->in = queue_ptr->out = 0;

    if ((err = pthread_mutex_destroy(&queue_ptr->mutex)))
        exit_with_err("pthread_mutex_destroy", err);
    if ((err = pthread_cond_destroy(&queue_ptr->full)))
        exit_with_err("pthread_cond_destroy", err);
    if ((err = pthread_cond_destroy(&queue_ptr->empty)))
        exit_with_err("pthread_cond_destroy", err);
}

bool number_queue_is_empty(number_queue_t *const queue_ptr) {
    assert(queue_ptr);
    int err;
    bool return_value;

    if ((err = pthread_mutex_lock(&queue_ptr->mutex)))
        exit_with_err("pthread_mutex_wait", err);

    return_value = (queue_ptr->size == 0);

    if ((err = pthread_mutex_unlock(&queue_ptr->mutex)))
        exit_with_err("pthread_mutex_wait", err);

    return return_value;
}

bool number_queue_is_full(number_queue_t *const queue_ptr) {
    assert(queue_ptr);
    int err;
    bool return_value;

    if ((err = pthread_mutex_lock(&queue_ptr->mutex)))
        exit_with_err("pthread_mutex_wait", err);

    return_value = (queue_ptr->size == queue_ptr->capacity);

    if ((err = pthread_mutex_unlock(&queue_ptr->mutex)))
        exit_with_err("pthread_mutex_wait", err);

    return return_value;
}

void number_queue_push(number_queue_t *queue_ptr, long num, bool last) {
    // `last`: se a `true` (1) indica che è l'ultimo inserimento del produttore
    assert(queue_ptr);
    int err;

    if ((err = pthread_mutex_lock(&queue_ptr->mutex)))
        exit_with_err("pthread_mutex_wait", err);

    // NB: al ritorno di `wait` reitera sempre il controllo!
    while (queue_ptr->size == queue_ptr->capacity)
        if ((err = pthread_cond_wait(&queue_ptr->full, &queue_ptr->mutex)))
            exit_with_err("pthread_cond_wait", err);
    // NB: qui avrei potuto usare `number_queue_is_empty` nella condizione ma
    // avrei acquisito due volte il lock (errore `EDEADLK` sulla wait)

    queue_ptr->data[queue_ptr->in] = num;
    queue_ptr->in = (queue_ptr->in + 1) % queue_ptr->capacity;
    queue_ptr->size++;

    if (last) {
        assert(queue_ptr->active_producers > 0);
        queue_ptr->active_producers--;
    }

    if (queue_ptr->size == 1)
        if ((err = pthread_cond_broadcast(&queue_ptr->empty)))
            exit_with_err("pthread_cond_broadcast", err);
    // usando `pthread_cond_signal` con più consumatori possono esserci dei
    // blocchi per consumatori che restano dormienti pur avendo visto uscire
    // anche l'ultimo produttore

    if ((err = pthread_mutex_unlock(&queue_ptr->mutex)))
        exit_with_err("pthread_mutex_wait", err);
}

bool number_queue_pop(long *extr_num_ptr, number_queue_t *queue_ptr) {
    assert(queue_ptr);
    assert(extr_num_ptr);
    int err;
    bool return_value;

    if ((err = pthread_mutex_lock(&queue_ptr->mutex)))
        exit_with_err("pthread_mutex_wait", err);

    while (queue_ptr->size == 0 && queue_ptr->active_producers > 0)
        if ((err = pthread_cond_wait(&queue_ptr->empty, &queue_ptr->mutex)))
            exit_with_err("pthread_cond_wait", err);

    if (queue_ptr->size == 0 && queue_ptr->active_producers == 0)
        return_value = false; // se la coda è vuota e non ci sono più produttori
    else {
        *extr_num_ptr = queue_ptr->data[queue_ptr->out];
        queue_ptr->out = (queue_ptr->out + 1) % queue_ptr->capacity;
        queue_ptr->size--;

        return_value = true;

        if (queue_ptr->size == queue_ptr->capacity - 1)
            if ((err = pthread_cond_broadcast(&queue_ptr->full)))
                exit_with_err("pthread_cond_broadcast", err);
        // anche qui, usando `pthread_cond_signal` con più produttori possono
        // esserci dei blocchi per produttori che restano dormienti
    }

    if ((err = pthread_mutex_unlock(&queue_ptr->mutex)))
        exit_with_err("pthread_mutex_wait", err);

    return return_value;
}

void number_queue_print(number_queue_t *const queue_ptr) {
    assert(queue_ptr);
    int err;

    if ((err = pthread_mutex_lock(&queue_ptr->mutex)))
        exit_with_err("pthread_mutex_wait", err);

    printf("{ ");
    for (unsigned long i = 0; i < queue_ptr->size; i++)
        printf("%lu%s",
               queue_ptr->data[(queue_ptr->out + i) % queue_ptr->capacity],
               (i + 1 < queue_ptr->size ? ", " : ""));
    printf(" } [%lu/%lu]\n", queue_ptr->size, queue_ptr->capacity);

    if ((err = pthread_mutex_unlock(&queue_ptr->mutex)))
        exit_with_err("pthread_mutex_wait", err);
}
/* < safe-number-queue > */

typedef struct {
    pthread_t tid;
    unsigned int id;
    unsigned long items_to_produce;
    long total;

    number_queue_t
        *queue_ptr; // non serve una struttura `shared`: è l'unica condivisa
} producer_data_t;

typedef struct {
    pthread_t tid;
    unsigned int id;
    long total;

    number_queue_t *queue_ptr;
} consumer_data_t;

void *producer_function(void *arg) {
    assert(arg);

    long number;
    producer_data_t *data_ptr = (producer_data_t *)arg;

    printf("[P%u] produttore attivato...\n", data_ptr->id);

    while (data_ptr->items_to_produce > 0) {
        // "produzione dell'elemento": un numero a caso
        number = rand();
        data_ptr->total += number;
        printf("[P%u] numero '%lu' prodotto\n", data_ptr->id, number);
        data_ptr->items_to_produce--;

        // inserimento elemento con bloccaggio automatico con eventuale
        // indicazione dell'ultimo inserimento
        number_queue_push(data_ptr->queue_ptr, number,
                          (data_ptr->items_to_produce == 0));

        printf("[P%u] numero '%lu' inserito nella coda\n", data_ptr->id,
               number);

        flockfile(stdout);
        printf("[P%u] coda attuale: ", data_ptr->id);
        number_queue_print(data_ptr->queue_ptr);
        funlockfile(stdout);
    }

    printf("[P%u] produttore terminato con un valore totale di inserimenti "
           "pari a %lu\n",
           data_ptr->id, data_ptr->total);

    return (NULL); // il totale lo ritorniamo usando la struttura privata
}

void *consumer_function(void *arg) {
    assert(arg);

    long number;
    consumer_data_t *data_ptr = (consumer_data_t *)arg;

    printf("[C%u] consumatore attivato...\n", data_ptr->id);

    while (true) {
        // estrazione elemento con fallimento su esaurimento senza produttori
        if (!number_queue_pop(&number, data_ptr->queue_ptr))
            break;
        data_ptr->total += number;

        printf("[C%u] numero '%lu' estratto dalla coda\n", data_ptr->id,
               number);

        flockfile(stdout);
        printf("[C%u] coda attuale:", data_ptr->id);
        number_queue_print(data_ptr->queue_ptr);
        funlockfile(stdout);
    }

    printf("[C%u] consumatore terminato con un valore totale di inserimenti "
           "pari a %lu\n",
           data_ptr->id, data_ptr->total);

    return (NULL);
}

int main(int argc, char *argv[]) {
    int err;

    srand(time(NULL));

    // creazione della coda condivisa
    number_queue_t queue;
    number_queue_init(&queue, QUEUE_CAPACITY, NUM_PRODUCERS);

    // creazione dei produttori
    producer_data_t prod_data[NUM_PRODUCERS];
    for (int i = 0; i < NUM_PRODUCERS; i++) {
        prod_data[i].queue_ptr = &queue;
        prod_data[i].id = i + 1;
        prod_data[i].items_to_produce = NUM_OF_ITEMS_TO_PRODUCE / NUM_PRODUCERS;
        prod_data[i].total = 0;
        if ((err = pthread_create(&prod_data[i].tid, NULL, producer_function,
                                  (void *)(&prod_data[i]))))
            exit_with_err("pthread_create", err);
    }

    // creazione dei consumatori
    consumer_data_t cons_data[NUM_CONSUMERS];
    for (int i = 0; i < NUM_CONSUMERS; i++) {
        cons_data[i].queue_ptr = &queue;
        cons_data[i].id = i + 1;
        cons_data[i].total = 0;
        if ((err = pthread_create(&cons_data[i].tid, NULL, consumer_function,
                                  (void *)(&cons_data[i]))))
            exit_with_err("pthread_create", err);
    }

    // attesa della terminazione dei produttori e dei consumatori
    unsigned long total_insertions = 0, total_extractions = 0;
    for (int i = 0; i < NUM_CONSUMERS; i++) {
        if ((err = pthread_join(cons_data[i].tid, NULL)))
            exit_with_err("pthread_join", err);
        total_extractions += cons_data[i].total;
    }
    for (int i = 0; i < NUM_PRODUCERS; i++) {
        if ((err = pthread_join(prod_data[i].tid, NULL)))
            exit_with_err("pthread_join", err);
        total_insertions += prod_data[i].total;
    }
    // non indispensabile ma è una buona abitudine...
    number_queue_destroy(&queue);

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
