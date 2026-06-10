/**
 * vogliamo creare un thread che popola una struttura dati interna (4 numeri) e
 * che la riporta come return-value; a tale scopo vengono  approntate due
 * metodologie;
 *  - la soluzione in `thread_function_with_memory_glitch` prevede di passare
 *    direttamente l'indirizzo della struttura interna; essendo questa allocata
 *    nello stack verrà rimossa non appena lo stack di attivazione della
 *    funzione si chiude: ciò può causare la lettura di valori errati o errori
 *    di violazione della memoria
 *  - la soluzione in `correct_thread_function` prevede di duplicare i dati
 *    nello heap usando una allocazione dinamica fatta all'interno del thread e
 *    passata come valore di ritorno; bisogna solo prestare attenzione al fatto
 *    che l'onere di liberare la memoria resta in mano a chi ha ricevuto il
 *    riferimento, pena il verificarsi di un "memory leak"
 */

#include "lib-misc.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

struct thread_internal_data {
    int a, b;
    unsigned long c, d;
};

void *thread_function_with_memory_glitch(void *arg) {
    unsigned long id = (unsigned long)arg;
    struct thread_internal_data data = {10, 20, 30, 40}; // allocato nello stack

    printf("[T%lu] thread attivato con tid %lu...\n", id, (unsigned long)pthread_self());

    printf("[T%lu] dati interni al thread (%d,%d,%lu,%lu)\n", id, data.a,
           data.b, data.c, data.d);

    sleep(2);

    pthread_exit((void *)&data); // questo è un problema...
}

void *correct_thread_function(void *arg) {
    unsigned long id = (unsigned long)arg;
    struct thread_internal_data data = {100, 200, 300,
                                        400}; // anche questo allocato nello stack!

    printf("[T%lu] thread attivato con tid %lu...\n", id, (unsigned long)pthread_self());

    printf("[T%lu] dati interni al thread (%d,%d,%lu,%lu)\n", id, data.a,
           data.b, data.c, data.d);

    sleep(2);

    // clonazione dati in una struttura allocata nello heap
    struct thread_internal_data *ptr_data_in_heap = malloc(sizeof(data));
    memcpy(ptr_data_in_heap, &data, sizeof(data));

    pthread_exit((void *)ptr_data_in_heap);
}

int main(int argc, char *argv[]) {
    int err;
    pthread_t tids[2];

    printf("[main] creazione del primo thread T1...\n");
    if ((err = pthread_create(&tids[0], NULL, correct_thread_function,
                              (void *)1)) != 0)
        exit_with_err("pthread_create", err);

    printf("[main] creazione del secondo thread T2...\n");
    if ((err = pthread_create(&tids[1], NULL,
                              thread_function_with_memory_glitch, (void *)2)) !=
        0)
        exit_with_err("pthread_create", err);

    for (unsigned long i = 1; i <= 2; i++) {
        struct thread_internal_data *ptr_data;
        printf("[main] attesa terminazione del thread T%lu...\n", i);
        if ((err = pthread_join(tids[i - 1], (void **)&ptr_data)) != 0)
            exit_with_err("pthread_join", err);
        printf("[main] thread T%lu terminato con valori di ritorno "
               "(%d, %d, %lu, %lu)\n",
               i, ptr_data->a, ptr_data->b, ptr_data->c, ptr_data->d);
        if (i == 1)
            free(ptr_data); // l'allocazione nello heap deve essere liberata!
    }

    exit(EXIT_SUCCESS);
}
