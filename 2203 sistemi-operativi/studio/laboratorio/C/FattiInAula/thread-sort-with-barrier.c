/**
 * esempio che utilizza la routine di libreria `heapsort` per ordinare array di
 * long: in una strategia utilizza `n` thread per ordinare dei sotto-array
 * assegnati per poi utilizzare una procedura di `merge` per fondere tale liste;
 * in una seconda strategia utilizza un singolo thread (il main) per farlo in
 * modo classico con la stessa routine; alla fine viene fatto anche un confronto
 * sommario delle prestazioni.
 *
 * la soluzione proposta impiega una barriera per sincronizzare le varie fasi:
 * la usa una prima volta per far si che i thread attendano che il main abbia
 * finito di predisporre i sotto array su cui operare e, infine, per attendere
 * che questi abbiano finito.
 */

#include "lib-misc.h"
#include <assert.h>
#include <limits.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#ifdef __linux
#include <bsd/stdlib.h> // header necessaria solo sotto Linux per usare `heapsort`
#endif

#define MAX_NUM_OF_SORTING_THREADS 8
#define DEFAULT_NUM_OF_SORTING_THREADS 4
#define QUANTITY_OF_NUMBERS_TO_SORT                                            \
    (840 * 100000L) // NB: 840=lcm(1,2,3,4,5,6,7,8)

typedef struct {
    long *data;
    long full_array_length;

    pthread_barrier_t barrier;
} shared_data_t;

typedef struct {
    pthread_t tid;
    unsigned int id;
    long sub_array_offset;
    long sub_array_length;

    shared_data_t *shared_data_ptr;
} thread_data_t;

int long_compare(const void *arg1, const void *arg2) {
    assert(arg1);
    assert(arg2);
    long n1 = *((long *)arg1);
    long n2 = *((long *)arg2);

    if (n1 == n2)
        return 0;
    else if (n1 < n2)
        return -1;
    else
        return 1;
}

void *thread_function(void *arg) {
    assert(arg);
    int err;
    thread_data_t *data_ptr = (thread_data_t *)arg;

    printf("[T%u] thread attivato...\n", data_ptr->id);
    printf("[T%u] aspetto che i dati da ordinare siano pronti...\n",
           data_ptr->id);

    // bloccaggio sulla barriera per attendere i dati da ordinare
    if ((err = pthread_barrier_wait(&data_ptr->shared_data_ptr->barrier)) > 0)
        exit_with_err("pthread_barrier_wait", err);

    printf("[T%u] ordinamento del sotto-vettore di %lu elementi (su %lu)...\n",
           data_ptr->id, data_ptr->sub_array_length,
           data_ptr->shared_data_ptr->full_array_length);

    if (heapsort(data_ptr->shared_data_ptr->data + data_ptr->sub_array_offset,
                 data_ptr->sub_array_length, sizeof(long), long_compare) != 0)
        exit_with_sys_err("heapsort");

    printf("[T%u] ordinamento completato: segnalo la terminazione...\n",
           data_ptr->id);

    // nuova sincronizzazione sulla barriera che risveglierà il `main`
    if ((err = pthread_barrier_wait(&data_ptr->shared_data_ptr->barrier)) > 0)
        exit_with_err("pthread_barrier_wait", err);

    return (NULL);
}

void print_array(const long *data, unsigned long size) {
    printf("{ ");
    for (unsigned long i = 0; i < size; i++)
        printf("%lu%s", data[i], (i + 1 < size ? ", " : ""));
    printf(" } [%lu]\n", size);
}

void merge_sub_arrays(long *output_merged_data,
                      const thread_data_t *thread_data,
                      unsigned int num_threads) {
    assert(thread_data);
    assert(num_threads > 0);

    long indexes[num_threads];
    for (unsigned int i = 0; i < num_threads; i++)
        indexes[i] = thread_data[i].sub_array_offset;
    for (unsigned long current_index = 0;
         current_index < thread_data->shared_data_ptr->full_array_length;
         current_index++) {
        long min = LONG_MAX;
        unsigned int min_index;
        for (unsigned int i = 0; i < num_threads; i++) {
            if ((indexes[i] < thread_data[i].sub_array_offset +
                                  thread_data[i].sub_array_length) &&
                (thread_data->shared_data_ptr->data[indexes[i]] < min)) {
                min = thread_data->shared_data_ptr->data[indexes[i]];
                min_index = i;
            }
        }
        output_merged_data[current_index] =
            thread_data->shared_data_ptr->data[indexes[min_index]];
        indexes[min_index]++;
    }
}

int main(int argc, char *argv[]) {
    int err;
    unsigned int num_threads = DEFAULT_NUM_OF_SORTING_THREADS;

    shared_data_t shared_data;
    long *merged_sorted_data, *single_thread_sorted_data;

    time_t timestamp;
    unsigned long multi_thread_timing, merge_sub_arrays_timing,
        single_thread_timing;

    srand(time(NULL));

    if (argc > 1)
        if ((num_threads = atoi(argv[1])) < 1 ||
            (num_threads > MAX_NUM_OF_SORTING_THREADS))
            exit_with_err_msg("numero di thread (%d) non valido!\n",
                              num_threads);

    // preparazione barriera
    if ((err =
             pthread_barrier_init(&shared_data.barrier, NULL, num_threads + 1)))
        exit_with_err("pthread_barrier_init", err);

    // creazione e avvio dei thread senza i dati da ordinare
    printf("[main] avvio dei thread senza dati da ordinare...\n");
    thread_data_t thread_data[num_threads];
    shared_data.full_array_length = QUANTITY_OF_NUMBERS_TO_SORT;
    assert(shared_data.full_array_length % num_threads == 0);
    for (unsigned int i = 0; i < num_threads; i++) {
        thread_data[i].id = i + 1;
        thread_data[i].shared_data_ptr = &shared_data;
        if ((err = pthread_create(&thread_data[i].tid, NULL, thread_function,
                                  (void *)&thread_data[i])))
            exit_with_err("pthread_create", err);
    }

    // generazione dei dati da ordinare
    printf("[main] generazione del vettore con %lu elementi casuali da "
           "ordinare...\n",
           shared_data.full_array_length);
    if ((shared_data.data =
             malloc(shared_data.full_array_length * sizeof(long))) == NULL)
        exit_with_sys_err("malloc");
    for (unsigned long i = 0; i < shared_data.full_array_length; i++)
        shared_data.data[i] = rand() % 256;
    for (int i = 0; i < num_threads; i++) {
        thread_data[i].sub_array_length =
            shared_data.full_array_length / num_threads;
        thread_data[i].sub_array_offset = i * thread_data[i].sub_array_length;
    }

    // preparazione della copia dell'array da ordinare
    if ((single_thread_sorted_data =
             malloc(shared_data.full_array_length * sizeof(long))) == NULL)
        exit_with_sys_err("malloc");
    memcpy(single_thread_sorted_data, shared_data.data,
           shared_data.full_array_length * sizeof(long));

    // campionatura per il benchmark multi-thread
    timestamp = time(NULL);

    // prima sincronizzazione sulla barriera che risveglierà tutti i thread
    if ((err = pthread_barrier_wait(&shared_data.barrier)) > 0)
        exit_with_err("pthread_barrier_wait", err);

    printf("[main] attesa della terminazione dei thread...\n");
    // nuovo bloccaggio sulla barriera per attendere la fine dell'ordinamento
    // dei sotto-array
    if ((err = pthread_barrier_wait(&shared_data.barrier)) > 0)
        exit_with_err("pthread_barrier_wait", err);

    // altra campionatura la fase parallela multi-thread
    multi_thread_timing = time(NULL) - timestamp;
    timestamp = time(NULL);

    printf("[main] fusione dei sotto-array pre-ordinati...\n");
    if ((merged_sorted_data =
             malloc(shared_data.full_array_length * sizeof(long))) == NULL)
        exit_with_sys_err("malloc");
    merge_sub_arrays(merged_sorted_data, thread_data, num_threads);

    // campionatura finale il benchmark dell'ordinamento multi-thread
    merge_sub_arrays_timing = time(NULL) - timestamp;
    multi_thread_timing += merge_sub_arrays_timing;
    printf("[main] terminazione dell'ordinamento multi-thread in ~%lu secondi "
           "(di cui ~%lu per la fusione)\n",
           multi_thread_timing, merge_sub_arrays_timing);

    printf("[main] ordinamento classico single-thread...\n");
    timestamp = time(NULL);
    if (heapsort(single_thread_sorted_data, shared_data.full_array_length,
                 sizeof(long), long_compare) != 0)
        exit_with_sys_err("heapsort");
    single_thread_timing = time(NULL) - timestamp;
    printf(
        "[main] terminazione dell'ordinamento single-thread in ~%lu secondi\n",
        single_thread_timing);

    printf("[main] confronto del tempo richiesto: multi-thread ~%lu secondi "
           "vs. single-thread ~%lu secondi\n",
           multi_thread_timing, single_thread_timing);

    // confronto delle due liste ordinate
    printf("[main] confronto delle due liste ordinate...\n");
    if (memcmp(merged_sorted_data, single_thread_sorted_data,
               shared_data.full_array_length * sizeof(long)) == 0) {
        printf("[main] risultato corretto!\n");
        exit(EXIT_SUCCESS);
    } else {
        printf("[main] risultato ERRATO!\n");
        exit(EXIT_FAILURE);
    }
}
