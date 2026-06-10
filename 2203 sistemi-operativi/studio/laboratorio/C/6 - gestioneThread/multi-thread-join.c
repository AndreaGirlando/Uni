/**
 * il thread principale crea altri 3 thread secondari attendendone la
 * terminazione ottenendo il return-value (gestito come un intero)
 */

#include "../FattiInAula/lib-misc.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define NUM_SUB_THREADS 3
#define MAX_PAUSE 8
#define MAX_RETURN_VALUE 10

void *thread_function(void *arg) {
    unsigned long id = (unsigned long)arg;

    int pause = rand() % (MAX_PAUSE + 1);
    unsigned long return_value = rand() % (MAX_RETURN_VALUE + 1);

    printf("[T%lu] thread secondario attivato con tid %lu...\n", id,
           (unsigned long)pthread_self());

    printf("[T%lu] pausa causale di %d secondi...\n", id, pause);
    sleep(pause);

    printf("[T%lu] terminazione con return-value casuale %lu\n", id,
           return_value);

    pthread_exit(
        (void *)
            return_value); // andava bene anche `return((void *)return_value)`
}

int main(int argc, char *argv[]) {
    int err;
    pthread_t tids[NUM_SUB_THREADS];

    srand(time(NULL));

    printf("[main] thread principale attivato...\n");

    // creazione dei thread secondari
    for (unsigned long i = 1; i <= NUM_SUB_THREADS; i++) {
        printf("[main] creazione del thread secondario T%lu...\n", i);
        if ((err = pthread_create(&tids[i-1], NULL, thread_function,
                                  (void *)i)) != 0)
            exit_with_err("pthread_create", err);
    }

    // attesa della terminazione dei thread secondari
    for (unsigned long i = 1; i <= NUM_SUB_THREADS; i++) {
        printf(
            "[main] attesa terminazione thread secondario T%lu con tid %lu...\n",
            i, (unsigned long)tids[i-1]);
        void *ret_val;
        if ((err = pthread_join(tids[i-1], &ret_val)) != 0)
            exit_with_err("pthread_join", err);
        printf("[main] thread secondario T%lu terminato con return-value %lu\n",
               i, (unsigned long)ret_val);
    }

    printf("[main] terminazione di tutti i thread secondari avvenuta: "
           "terminazione del thread principale\n");

    exit(EXIT_SUCCESS);
}
