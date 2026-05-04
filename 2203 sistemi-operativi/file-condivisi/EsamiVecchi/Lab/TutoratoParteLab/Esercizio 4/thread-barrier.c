/**
 * esempio che mostra come 1+n (il thread principale più altri n addizionali) si
 * possono coordinare su alcuni passaggi (partenza e terminazione) utilizzando
 * una barriera; gli 1+n thread sono trattati alla pari e alla fine viene usato
 * il thread prescelto dalla barriera come gestore dell'ultima fase
 */

#define _GNU_SOURCE
/* ---------------------------------------------------------------------------
 * Perché serve il #define _GNU_SOURCE?
 *
 *  - <pthread.h> espone le funzioni e i tipi POSIX (es. pthread_barrier_t
 *    e pthread_barrier_wait()) **solo** se prima del primo #include viene
 *    definita una “feature-test macro”.
 *
 *  - Compilando con gcc -std=c11 / -std=c99 / -ansi il compilatore entra in
 *    modalità ISO-C stretta (macro interna __STRICT_ANSI__) e glibc nasconde
 *    tutto ciò che non appartiene allo standard C puro, barriere incluse.
 *
 *  - Definendo **_GNU_SOURCE** (oppure _POSIX_C_SOURCE 200112L o
 *    _XOPEN_SOURCE 600) chiediamo a glibc di abilitare le API POSIX.1-2001
 *    e quindi di rendere visibili i prototipi delle barrier.
 *
 *  - In pratica:
 *        #define _GNU_SOURCE      // deve stare PRIMA di qualsiasi #include
 *        #include <pthread.h>
 *
 *    senza questa riga il compilatore segnerebbe pthread_barrier_t come
 *    “undeclared” e il programma non compilerebbe.
 * ------------------------------------------------------------------------- */

#include <assert.h>
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define NUM_ADDITIONAL_THREADS 5
#define NUM_TOTAL_THREADS (NUM_ADDITIONAL_THREADS + 1)
#define MAX_RANDOM_PAUSE 5

void exit_with_err(const char *msg, int err) {
    fprintf(stderr, "%s: %s\n", msg, strerror(err));
    exit(EXIT_FAILURE);
}

void exit_with_err_msg(const char *msg, int value) {
    fprintf(stderr, msg, value);
    exit(EXIT_FAILURE);
}

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

    /* ------------------------------------------------------------------------
    *  Allocazione e inizializzazione delle strutture condivise tra i thread
    * -------------------------------------------------------------------- */

    /* 1) Array di strutture private per ciascun thread (main incluso).
    *    - Heap invece dello stack: se il thread main dovesse terminare prima
    *      degli altri, la memoria resta valida per chiunque la stia usando.
    *    - NUM_TOTAL_THREADS = 1 (main) + NUM_ADDITIONAL_THREADS.
    */
    thread_data_t *thread_data_ptr = malloc(NUM_TOTAL_THREADS * sizeof(thread_data_t));
    assert(thread_data_ptr);          // abort se malloc fallisce

    /* 2) Oggetto barriera anch’esso su heap.
    *    Potremmo dichiararlo “pthread_barrier_t barrier;” staticamente, ma
    *    in questo esempio preferiamo un puntatore da condividere nelle struct.
    */
    pthread_barrier_t *barrier_ptr = malloc(sizeof(pthread_barrier_t));
    assert(barrier_ptr);              // abort se malloc fallisce

    /* 3) Inizializzazione della barriera:
    *      – 1° arg: puntatore all’oggetto da inizializzare
    *      – 2° arg: attributi → NULL = default
    *      – 3° arg: soglia di sblocco = numero totale di thread che devono
    *                chiamare pthread_barrier_wait() prima che la barriera “apra”.
    */
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