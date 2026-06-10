/**
 * data una semplice struttura dati dinamica che gestione un insieme di numeri,
 * vengono creati diversi agenti per leggere (massimo, totale) e modificare
 * (inserimento, estrazioni random) tale insieme; per la sincronizzazione viene
 * usato un lock di tipo lettore-scrittore, dando anche la possibilità di
 * disabilitare la sincronizzazione da riga di comando
 *
 * > ./thread-number-set-with-rwlock
 * > ./thread-number-set-with-rwlock no-sync
 */

#include "lib-misc.h"
#include <assert.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define NUM_INSERTER_AGENTS 2
#define NUM_EXTRACTOR_AGENTS 2
#define NUM_GETTER_TOTAL_AGENTS 1
#define NUM_GETTER_MAX_AGENTS 1
#define NUM_AGENTS                                                             \
    (NUM_INSERTER_AGENTS + NUM_EXTRACTOR_AGENTS + NUM_GETTER_TOTAL_AGENTS +    \
     NUM_GETTER_MAX_AGENTS)
#define NUM_INSERTIONS 500

/* < number-set >
 * strutture e funzioni elementari per gestire un set dinamico di numeri interi
 * tramite un buffer statico raddoppiato all'occorrenza */
#define NUMBER_SET_BASE_CAPACITY 8

typedef struct {
    unsigned long capacity;
    unsigned long size;
    long *data;
} number_set_t;

void number_set_init(number_set_t *set_ptr, unsigned long initial_capacity) {
    assert(set_ptr);

    set_ptr->capacity = (initial_capacity >= NUMBER_SET_BASE_CAPACITY
                             ? initial_capacity
                             : NUMBER_SET_BASE_CAPACITY);
    set_ptr->size = 0;
    set_ptr->data = malloc(set_ptr->capacity * sizeof(long));
    assert(set_ptr->data);
}

void number_set_destroy(number_set_t *set_ptr) {
    assert(set_ptr);
    assert(set_ptr->capacity > 0);
    assert(set_ptr->data);

    free(set_ptr->data);
    set_ptr->data = NULL;
    set_ptr->capacity = set_ptr->size = 0;
}

bool number_set_is_empty(number_set_t *const set_ptr) {
    assert(set_ptr);

    return (set_ptr->size == 0);
}

bool number_set_is_present(number_set_t *const set_ptr, long num) {
    assert(set_ptr);

    // una semplice ricerca lineare
    for (unsigned long i = 0; i < set_ptr->size; i++)
        if (set_ptr->data[i] == num)
            return true;

    return false;
}

bool number_set_insert(number_set_t *set_ptr, long num) {
    assert(set_ptr);
    assert(set_ptr->size <= set_ptr->capacity);

    if (number_set_is_present(set_ptr, num))
        return false;

    // controllo sulla capienza pre-inserimento
    if (set_ptr->capacity == set_ptr->size) {
        // un buffer pieno viene raddoppiato in capienza
        set_ptr->capacity *= 2;
        set_ptr->data =
            realloc(set_ptr->data, set_ptr->capacity * sizeof(long));
        assert(set_ptr);
    }

    set_ptr->data[set_ptr->size++] = num;

    return true;
}

bool number_set_pop_random(long *extr_num_ptr, number_set_t *set_ptr) {
    assert(set_ptr);
    assert(extr_num_ptr);

    if (set_ptr->size == 0)
        return false;

    unsigned long i = rand() % set_ptr->size;
    *extr_num_ptr = set_ptr->data[i];

    set_ptr->data[i] = set_ptr->data[--set_ptr->size];

    return true;
}

void number_set_print(const char *prefix, number_set_t *const set_ptr) {
    assert(set_ptr);

    flockfile(stdout);
    printf("%s{ ", prefix);
    for (unsigned long i = 0; i < set_ptr->size; i++)
        printf("%lu%s", set_ptr->data[i], (i + 1 < set_ptr->size ? ", " : ""));
    printf(" } [%lu/%lu]\n", set_ptr->size, set_ptr->capacity);
    funlockfile(stdout);
}

long number_set_get_total(number_set_t *const set_ptr) {
    assert(set_ptr);
    long total = 0;

    for (unsigned long i = 0; i < set_ptr->size; i++)
        total += set_ptr->data[i];

    return total;
}

bool number_set_get_max(long *max_num_ptr, number_set_t *const set_ptr) {
    assert(set_ptr);

    if (set_ptr->size == 0)
        return false;

    *max_num_ptr = set_ptr->data[0];
    for (unsigned long i = 1; i < set_ptr->size; i++)
        *max_num_ptr =
            (*max_num_ptr < set_ptr->data[i] ? set_ptr->data[i] : *max_num_ptr);

    return true;
}
/* < number-set > */

typedef enum { INSERTER, EXTRACTOR, GETTER_TOTAL, GETTER_MAX } agent_type_t;

typedef struct {
    number_set_t set;
    unsigned long insertions_to_do;
    pthread_rwlock_t lock;
    bool do_sync;
} shared_data_t;

typedef struct {
    pthread_t tid;
    unsigned int id;
    agent_type_t type;

    shared_data_t *shared_data_ptr;
} thread_data_t;

void *thread_function(void *arg) {
    assert(arg);
    unsigned long counter_to_return = 0;

    int err;
    thread_data_t *data_ptr = (thread_data_t *)arg;

    switch (data_ptr->type) {
    case (INSERTER):
        printf("[I%u] agente inseritore (writer) attivato...\n", data_ptr->id);
        {
            bool run = true;
            unsigned long insertions = 0;
            do {
                // acquisizione lock in scrittura
                if (data_ptr->shared_data_ptr->do_sync &&
                    (err = pthread_rwlock_wrlock(
                         &data_ptr->shared_data_ptr->lock)))
                    exit_with_err("pthread_rwlock_rdlock", err);

                // controllo sulla presenza di ulteriori inserimenti da fare
                if (data_ptr->shared_data_ptr->insertions_to_do <= 0)
                    run = false;
                else {
                    long number = rand();
                    number_set_insert(&data_ptr->shared_data_ptr->set, number);
                    printf("[I%u] nuovo inserimento: %lu \n", data_ptr->id,
                           number);
                    counter_to_return += number;
                    insertions++;
                    data_ptr->shared_data_ptr->insertions_to_do--;
                }

                // rilascio lock
                if (data_ptr->shared_data_ptr->do_sync &&
                    (err = pthread_rwlock_unlock(
                         &data_ptr->shared_data_ptr->lock)))
                    exit_with_err("pthread_rwlock_unlock", err);

            } while (run);
            printf("[I%u] terminazione agente con %lu inserimenti con valore "
                   "totale di %lu \n",
                   data_ptr->id, insertions, counter_to_return);
        }
        break;
    case (EXTRACTOR):
        printf("[E%u] agente estrattore (writer) attivato...\n", data_ptr->id);
        {
            bool run = true;
            unsigned long extractions = 0;
            do {
                // acquisizione lock in scrittura
                if (data_ptr->shared_data_ptr->do_sync &&
                    (err = pthread_rwlock_wrlock(
                         &data_ptr->shared_data_ptr->lock)))
                    exit_with_err("pthread_rwlock_rdlock", err);

                // controllo sulla presenza di ulteriori operazioni di modifica
                if (data_ptr->shared_data_ptr->insertions_to_do == 0 &&
                    number_set_is_empty(&data_ptr->shared_data_ptr->set))
                    run = false;
                else {
                    long number;
                    if (number_set_pop_random(
                            &number, &data_ptr->shared_data_ptr->set)) {
                        printf("[E%u] estrazione: %lu \n", data_ptr->id,
                               number);
                        counter_to_return += number;
                        extractions++;
                    } else
                        printf("[E%u] nessuna estrazione: insieme vuoto\n",
                               data_ptr->id);
                }

                // rilascio lock
                if (data_ptr->shared_data_ptr->do_sync &&
                    (err = pthread_rwlock_unlock(
                         &data_ptr->shared_data_ptr->lock)))
                    exit_with_err("pthread_rwlock_unlock", err);

            } while (run);
            printf("[E%u] terminazione agente con %lu estrazioni con valore "
                   "totale di %lu \n",
                   data_ptr->id, extractions, counter_to_return);
        }
        break;
    case (GETTER_MAX):
        printf("[T%u] agente totalizzatore (reader) attivato...\n",
               data_ptr->id);
        {
            bool run = true;
            long total;
            do {
                // acquisizione lock in lettura
                if (data_ptr->shared_data_ptr->do_sync &&
                    (err = pthread_rwlock_rdlock(
                         &data_ptr->shared_data_ptr->lock)))
                    exit_with_err("pthread_rwlock_rdlock", err);

                total = number_set_get_total(&data_ptr->shared_data_ptr->set);

                // controllo sulla presenza di ulteriori operazioni di modifica
                if (data_ptr->shared_data_ptr->insertions_to_do == 0 &&
                    number_set_is_empty(&data_ptr->shared_data_ptr->set))
                    run = false;

                // rilascio lock
                if (data_ptr->shared_data_ptr->do_sync &&
                    (err = pthread_rwlock_unlock(
                         &data_ptr->shared_data_ptr->lock)))
                    exit_with_err("pthread_rwlock_unlock", err);

                printf("[T%u] totale attuale: %lu \n", data_ptr->id, total);
            } while (run);
        }
        printf("[T%u] terminazione agente\n", data_ptr->id);
        break;
    case (GETTER_TOTAL):
        printf("[M%u] agente massimizzatore (reader) attivato...\n",
               data_ptr->id);
        {
            bool run = true;
            long max;
            do {
                // acquisizione lock in lettura
                if (data_ptr->shared_data_ptr->do_sync &&
                    (err = pthread_rwlock_rdlock(
                         &data_ptr->shared_data_ptr->lock)))
                    exit_with_err("pthread_rwlock_rdlock", err);

                if (number_set_get_max(&max, &data_ptr->shared_data_ptr->set))
                    printf("[M%u] massimo attuale: %lu \n", data_ptr->id, max);
                else
                    printf("[M%u] massimo attuale non disponibile (insieme "
                           "vuoto)\n",
                           data_ptr->id);

                // controllo sulla presenza di ulteriori operazioni di modifica
                if (data_ptr->shared_data_ptr->insertions_to_do == 0 &&
                    number_set_is_empty(&data_ptr->shared_data_ptr->set))
                    run = false;

                // rilascio lock
                if (data_ptr->shared_data_ptr->do_sync &&
                    (err = pthread_rwlock_unlock(
                         &data_ptr->shared_data_ptr->lock)))
                    exit_with_err("pthread_rwlock_unlock", err);
            } while (run);
        }
        printf("[M%u] terminazione agente\n", data_ptr->id);
        break;
    default:
        assert(false);
    }

    return ((void *)counter_to_return);
}

int main(int argc, char *argv[]) {
    int err, next_index = 0;
    bool do_sync = true;

    srand(time(NULL));

    if (argc > 1 && strcmp(argv[1], "no-sync") == 0) {
        printf("[main] ATTENZIONE: non verranno usati i meccanismi di "
               "sincronizzazione!\n");
        do_sync = false;
    }

    // preparazione dati condivisi
    shared_data_t shared;
    number_set_init(&shared.set, 0);
    shared.insertions_to_do = NUM_INSERTIONS;
    if ((err = pthread_rwlock_init(&shared.lock, NULL)))
        exit_with_err("pthread_rwlock_init", err);
    shared.do_sync = do_sync;

    // preparazione dati privati degli agenti
    thread_data_t datas[NUM_AGENTS];
    for (int i = 0; i < NUM_INSERTER_AGENTS; i++) {
        datas[next_index].id = i + 1;
        datas[next_index].shared_data_ptr = &shared;
        datas[next_index].type = INSERTER;
        next_index++;
    }
    for (int i = 0; i < NUM_EXTRACTOR_AGENTS; i++) {
        datas[next_index].id = i + 1;
        datas[next_index].shared_data_ptr = &shared;
        datas[next_index].type = EXTRACTOR;
        next_index++;
    }
    for (int i = 0; i < NUM_GETTER_TOTAL_AGENTS; i++) {
        datas[next_index].id = i + 1;
        datas[next_index].shared_data_ptr = &shared;
        datas[next_index].type = GETTER_TOTAL;
        next_index++;
    }
    for (int i = 0; i < NUM_GETTER_MAX_AGENTS; i++) {
        datas[next_index].id = i + 1;
        datas[next_index].shared_data_ptr = &shared;
        datas[next_index].type = GETTER_MAX;
        next_index++;
    }

    // creazione dei thread
    for (int i = 0; i < NUM_AGENTS; i++) {
        if ((err = pthread_create(&datas[i].tid, NULL, thread_function,
                                  (void *)(&datas[i]))))
            exit_with_err("pthread_create", err);
    }

    // attesa della terminazione dei thread
    unsigned long returned_counters[NUM_AGENTS] = {0};
    for (int i = 0; i < NUM_AGENTS; i++)
        if ((err = pthread_join(datas[i].tid, (void **)&returned_counters[i])))
            exit_with_err("pthread_join", err);

    // non indispensabile ma è una buona abitudine...
    number_set_destroy(&shared.set);
    pthread_rwlock_destroy(&shared.lock);

    // controllo dei totali degli inserimenti ed estrazioni
    unsigned long total_insertions = 0, total_extractions = 0;
    for (int i = 0; i < NUM_INSERTER_AGENTS; i++)
        total_insertions += returned_counters[i];
    for (int i = NUM_INSERTER_AGENTS;
         i < NUM_INSERTER_AGENTS + NUM_EXTRACTOR_AGENTS; i++)
        total_extractions += returned_counters[i];
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
