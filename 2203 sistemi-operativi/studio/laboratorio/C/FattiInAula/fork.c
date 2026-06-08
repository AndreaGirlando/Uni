/**
 * il processo lanciato usa `fork` per crea un processo figlio: di default il
 * padre effettua una pausa e termina dopo il figlio; se viene specificata
 * l'opzione 'slow-child' il ruolo si inverte ed è utile osservare cosa succede
 *
 * > ./fork
 * > ./fork slow-child
 */

#include "lib-misc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PAUSE 8

int main(int argc, char *argv[]) {
    pid_t pid;
    char *process_name = "P";
    int X = 5;
    int pause_father, pause_child;

    if (argc > 1 && strcmp(argv[1], "slow-child") == 0) {
        printf("test con figlio lento che termina dopo il padre\n");
        pause_child = PAUSE;
        pause_father = 0;
    } else {
        printf("test con padre lento che termina dopo il figlio\n");
        pause_child = 0;
        pause_father = PAUSE;
    }

    printf("[%s] pid=%d ppid=%d X=%d\n", process_name, getpid(), getppid(), X);

    // crea un processo figlio
    printf("[%s] fork...\n", process_name);
    if ((pid = fork()) == -1)
        exit_with_sys_err("fork");

    if (pid == 0) {
        // questo codice viene eseguito solo dentro il figlio
        process_name = "F";
        printf("[%s] X++\n", process_name);
        X++;

        if (pause_child) {
            printf("[%s] pausa...\n", process_name);
            sleep(pause_child);
        }
    } else {
        // questo codice viene eseguito solo dentro il padre
        process_name = "P";
        printf("[%s] X--\n", process_name);
        X--;

        if (pause_father > 0) {
            printf("[%s] pausa...\n", process_name);
            sleep(pause_father);
        }
    }

    // il seguente codice viene eseguito sia dal padre che dal figlio
    printf("[%s] pid=%d ppid=%d X=%d\n", process_name, getpid(), getppid(), X);

    printf("[%s] terminato\n", process_name);
    
    exit(EXIT_SUCCESS);
}
