/**
 * il padre crea il numero indicato di figli (default 2) e tutti visualizzeranno
 * una serie di messaggi sul terminale
 *
 * > ./multi-fork
 * > ./multi-fork 5
 * > ./multi-fork 5 > test.log
 *
 * nota: nell'ultimo caso l'output riversato sul file di log sembra il risultato
 * di una esecuzione seriale (e non parallela) dei vari processi: questa
 * impressione è data dal fatto che lo standard output è "fully buffered"
 * (essendo associato ad un file)
 */

#include "lib-misc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define DEFAULT_NUM_CHILDREN 2
#define MAX_NUM_CHILDREN 20
#define NUM_STEPS 100

// funzione comune eseguita sia dal padre che da tutti i figli
void workload_function(const char *name, int child_num) {
    char buffer[10];

    if (child_num > 0)
        snprintf(buffer, sizeof(buffer), "[%s%d]", name, child_num);
    else
        snprintf(buffer, sizeof(buffer), "[%s]", name);

    for (int i = 0; i < NUM_STEPS; i++) {
        printf("%s %d\n", buffer, i);
    }

    printf("%s terminato!\n", buffer);

    exit(EXIT_SUCCESS); // importante!
}

int main(int argc, char *argv[]) {
    int num_children = DEFAULT_NUM_CHILDREN;

    if (argc > 1) {
        if ((num_children = atoi(argv[1])) < 1 ||
            (num_children > MAX_NUM_CHILDREN))
            exit_with_err_msg("numero di figlio (%d) non valido!\n",
                              num_children);
    }

    // creazione degli `num_children` figli
    for (int i = 1; i <= num_children; i++) {
        if (fork() == 0) {
            workload_function("F", i);
            // NB: la funzione precedente non ritornerà mai per l'exit finale
        }
    }

    // anche il padre eseguirà gli stessi passi
    workload_function("P", 0);
}
