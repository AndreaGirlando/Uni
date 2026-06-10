/**
 * come l'esempio `thread-number-set-with-rwlock.c` ma integrando i meccanismi
 * di sincronizzazione (lettore-scrittore) all'interno delle funzioni di
 * gestione della struttura dati; resta necessario prevedere un semplice mutex
 * lock per proteggere il contatore degli inserimenti residui
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

/* < safe-number-set >
 * variante thread-safe di `number-set` */
#define NUMBER_SET_BASE_CAPACITY 8

typedef struct {
    unsigned long capacity;
    unsigned long size;
    long *data;
    pthread_rwlock_t lock;
} number_set_t;

void number_set_init(number_set_t *set_ptr, unsigned long initial_capacity) {
    assert(set_ptr);
    int err;

    set_ptr->capacity = (initial_capacity >= NUMBER_SET_BASE_CAPACITY
                             ? initial_capacity
                             : NUMBER_SET_BASE_CAPACITY);
    set_ptr->size = 0;
    set_ptr->data = malloc(set_ptr->capacity * sizeof(long));
    assert(set_ptr->data);
    if ((err = pthread_rwlock_init(&set_ptr->lock, NULL)))
        exit_with_err("pthread_rwlock_init", err);
}

void number_set_destroy(number_set_t *set_ptr) {
    assert(set_ptr);
    assert(set_ptr->capacity > 0);
    assert(set_ptr->data);
    int err;

    free(set_ptr->data);
    set_ptr->data = NULL;
    set_ptr->capacity = set_ptr->size = 0;
    if ((err = pthread_rwlock_destroy(&set_ptr->lock)))
        exit_with_err("pthread_rwlock_destroy", err);
}

bool number_set_is_empty(number_set_t *const set_ptr) {
    assert(set_ptr);
    bool return_value;
    int err;

    if ((err = pthread_rwlock_rdlock(&set_ptr->lock)))
        exit_with_err("pthread_rwlock_rdlock", err);

    // return (set_ptr->size == 0); // MAI!!!

    return_value = (set_ptr->size == 0);

    if ((err = pthread_rwlock_unlock(&set_ptr->lock)))
        exit_with_err("pthread_rwlock_unlock", err);

    // NB: in questa funzione, facendo una unica lettura puntuale, il meccanismo
    // di lock non era strettamente necessario

    return (return_value);
}

/* funzione interna senza lock riutilizzata più volte: altrimenti avremmo un
 * doppio lock (wr+rd) su `number_set_insert` */
static bool __number_set_is_present(number_set_t *const set_ptr, long num) {
    assert(set_ptr);

    // una semplice ricerca lineare
    for (unsigned long i = 0; i < set_ptr->size; i++)
        if (set_ptr->data[i] == num)
            return true;

    return false;
}

bool number_set_is_present(number_set_t *const set_ptr, long num) {
    assert(set_ptr);
    bool return_value = false;
    int err;

    if ((err = pthread_rwlock_rdlock(&set_ptr->lock)))
        exit_with_err("pthread_rwlock_rdlock", err);

    // usa la funzione interna (senza lock) per la ricerca
    return_value = __number_set_is_present(set_ptr, num);

    if ((err = pthread_rwlock_unlock(&set_ptr->lock)))
        exit_with_err("pthread_rwlock_unlock", err);

    return return_value;
}

bool number_set_insert(number_set_t *set_ptr, long num) {
    assert(set_ptr);
    assert(set_ptr->size <= set_ptr->capacity);
    bool return_value;
    int err;

    if ((err = pthread_rwlock_wrlock(&set_ptr->lock)))
        exit_with_err("pthread_rwlock_wrlock", err);

    if (__number_set_is_present(set_ptr, num)) // funzione interna (senza lock)
        return_value = false;
    else {
        if (set_ptr->capacity == set_ptr->size) {
            set_ptr->capacity *= 2;
            set_ptr->data =
                realloc(set_ptr->data, set_ptr->capacity * sizeof(long));
            assert(set_ptr);
        }

        set_ptr->data[set_ptr->size++] = num;

        return_value = true;
    }

    if ((err = pthread_rwlock_unlock(&set_ptr->lock)))
        exit_with_err("pthread_rwlock_unlock", err);

    return return_value;
}

bool number_set_pop_random(long *extr_num_ptr, number_set_t *set_ptr) {
    assert(set_ptr);
    assert(extr_num_ptr);
    bool return_value;
    int err;

    if ((err = pthread_rwlock_wrlock(&set_ptr->lock)))
        exit_with_err("pthread_rwlock_wrlock", err);

    if (set_ptr->size == 0)
        return_value = false;
    else {
        unsigned long i = rand() % set_ptr->size;
        *extr_num_ptr = set_ptr->data[i];

        set_ptr->data[i] = set_ptr->data[--set_ptr->size];
        return_value = true;
    }

    if ((err = pthread_rwlock_unlock(&set_ptr->lock)))
        exit_with_err("pthread_rwlock_unlock", err);

    return return_value;
}

void number_set_print(const char *prefix, number_set_t *const set_ptr) {
    assert(set_ptr);
    int err;

    if ((err = pthread_rwlock_rdlock(&set_ptr->lock)))
        exit_with_err("pthread_rwlock_rdlock", err);

    printf("%s{ ", prefix);
    for (unsigned long i = 0; i < set_ptr->size; i++)
        printf("%lu%s", set_ptr->data[i], (i + 1 < set_ptr->size ? ", " : ""));
    printf(" } [%lu/%lu]\n", set_ptr->size, set_ptr->capacity);

    if ((err = pthread_rwlock_unlock(&set_ptr->lock)))
        exit_with_err("pthread_rwlock_unlock", err);
}

long number_set_get_total(number_set_t *const set_ptr) {
    assert(set_ptr);
    long total = 0;
    int err;

    if ((err = pthread_rwlock_rdlock(&set_ptr->lock)))
        exit_with_err("pthread_rwlock_rdlock", err);

    for (unsigned long i = 0; i < set_ptr->size; i++)
        total += set_ptr->data[i];

    if ((err = pthread_rwlock_unlock(&set_ptr->lock)))
        exit_with_err("pthread_rwlock_unlock", err);

    return total;
}

bool number_set_get_max(long *max_num_ptr, number_set_t *const set_ptr) {
    assert(set_ptr);
    bool return_value;
    int err;

    if ((err = pthread_rwlock_rdlock(&set_ptr->lock)))
        exit_with_err("pthread_rwlock_rdlock", err);

    if (set_ptr->size == 0)
        return_value = false;
    else {

        *max_num_ptr = set_ptr->data[0];
        for (unsigned long i = 1; i < set_ptr->size; i++)
            *max_num_ptr = (*max_num_ptr < set_ptr->data[i] ? set_ptr->data[i]
                                                            : *max_num_ptr);
        return_value = true;
    }

    if ((err = pthread_rwlock_unlock(&set_ptr->lock)))
        exit_with_err("pthread_rwlock_unlock", err);

    return return_value;
}
/* < safe-number-set > */

typedef enum { INSERTER, EXTRACTOR, GETTER_TOTAL, GETTER_MAX } agent_type_t;

typedef struct {
    number_set_t set;
    unsigned long insertions_to_do;
    pthread_mutex_t counter_lock; // protegge `insertions_to_do`
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
                // acquisizione lock sul contatore
                if ((err = pthread_mutex_lock(
                         &data_ptr->shared_data_ptr->counter_lock)))
                    exit_with_err("pthread_mutex_lock", err);

                // controllo sulla presenza di ulteriori inserimenti da fare
                if (data_ptr->shared_data_ptr->insertions_to_do <= 0)
                    run = false;
                else
                    data_ptr->shared_data_ptr->insertions_to_do--;

                // rilascio lock sul contatore
                if ((err = pthread_mutex_unlock(
                         &data_ptr->shared_data_ptr->counter_lock)))
                    exit_with_err("pthread_mutex_unlock", err);

                if (run) {
                    long number = rand();
                    number_set_insert(&data_ptr->shared_data_ptr->set, number);
                    printf("[I%u] nuovo inserimento: %lu \n", data_ptr->id,
                           number);
                    counter_to_return += number;
                    insertions++;
                }
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
                // acquisizione lock sul contatore
                if ((err = pthread_mutex_lock(
                         &data_ptr->shared_data_ptr->counter_lock)))
                    exit_with_err("pthread_mutex_lock", err);

                // controllo sulla presenza di ulteriori operazioni di modifica
                if (data_ptr->shared_data_ptr->insertions_to_do == 0 &&
                    number_set_is_empty(&data_ptr->shared_data_ptr->set))
                    run = false;
                // NB: sopra, per un momento, acquisiamo entrambi i lock!

                // rilascio lock sul contatore
                if ((err = pthread_mutex_unlock(
                         &data_ptr->shared_data_ptr->counter_lock)))
                    exit_with_err("pthread_mutex_unlock", err);

                if (run) {
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
                // acquisizione lock sul contatore
                if ((err = pthread_mutex_lock(
                         &data_ptr->shared_data_ptr->counter_lock)))
                    exit_with_err("pthread_mutex_lock", err);

                // controllo sull'attività degli agenti scrittori
                if (data_ptr->shared_data_ptr->insertions_to_do == 0 &&
                    number_set_is_empty(&data_ptr->shared_data_ptr->set))
                    run = false;

                // rilascio lock sul contatore
                if ((err = pthread_mutex_unlock(
                         &data_ptr->shared_data_ptr->counter_lock)))
                    exit_with_err("pthread_mutex_unlock", err);

                if (run) {
                    total =
                        number_set_get_total(&data_ptr->shared_data_ptr->set);
                    printf("[T%u] totale attuale: %lu \n", data_ptr->id, total);
                }

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
                // acquisizione lock sul contatore
                if ((err = pthread_mutex_lock(
                         &data_ptr->shared_data_ptr->counter_lock)))
                    exit_with_err("pthread_mutex_lock", err);

                // controllo sull'attività degli agenti scrittori
                if (data_ptr->shared_data_ptr->insertions_to_do == 0 &&
                    number_set_is_empty(&data_ptr->shared_data_ptr->set))
                    run = false;

                // rilascio lock sul contatore
                if ((err = pthread_mutex_unlock(
                         &data_ptr->shared_data_ptr->counter_lock)))
                    exit_with_err("pthread_mutex_unlock", err);

                if (run) {
                    if (number_set_get_max(&max,
                                           &data_ptr->shared_data_ptr->set))
                        printf("[M%u] massimo attuale: %lu \n", data_ptr->id,
                               max);
                    else
                        printf("[M%u] massimo attuale non disponibile (insieme "
                               "vuoto)\n",
                               data_ptr->id);
                }
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

    srand(time(NULL));

    // preparazione dati condivisi
    shared_data_t shared;
    number_set_init(&shared.set, 0);
    shared.insertions_to_do = NUM_INSERTIONS;
    if ((err = pthread_mutex_init(&shared.counter_lock, NULL)))
        exit_with_err("pthread_mutex_init", err);

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
    pthread_mutex_destroy(&shared.counter_lock);

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
