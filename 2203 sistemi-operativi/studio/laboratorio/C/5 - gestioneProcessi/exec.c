/**
 * utilizza le diverse varianti di exec* per eseguire:
 *  - una sequenza prefissata di comandi usando `execlp` all'interno di
 *    altrettanti processi figli e controllando l'esito, oppure
 *  - un comando, con relativi argomenti, passati sulla riga di comando usando
 *    `execvp` e costruendo dinamicamente il vettore atteso
 *
 * > ./exec
 * > ./exec cal 6 2023
 * > ./exec comando-che-non-esiste
 */

#include "lib-misc.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void exec_fixed_sequence_of_commands() {
    int exit_status;

    printf("[P] invoco una sequenza di comandi prefissati usando altrettanti "
           "figli...\n");

    if (!fork()) {
        printf("\n[F1] eseguo il comando `whoami` assegnato...\n");
        execlp("whoami", "whoami", NULL);
        exit_with_sys_err("exec in F1");
    } else {
        wait(&exit_status);
        printf("[P] figlio F1 terminato con exit-code %d\n",
               WEXITSTATUS(exit_status));
    }

    if (!fork()) {
        printf("\n[F2] eseguo il comando `cal 6 2023` assegnato...\n");
        execlp("cal", "cal", "6", "2023", NULL);
        exit_with_sys_err("exec in F2");
    } else {
        wait(&exit_status);
        printf("[P] figlio F2 terminato con exit-code %d\n",
               WEXITSTATUS(exit_status));
    }

    if (!fork()) {
        printf("\n[F3] eseguo il comando `non-esiste` assegnato...\n");
        execlp("non-esiste", "non-esiste", "123", "abc", NULL);
        exit_with_sys_err("exec in F3");
    } else {
        wait(&exit_status);
        printf("[P] figlio F3 terminato con exit-code %d\n",
               WEXITSTATUS(exit_status));
    }

    if (!fork()) {
        printf("\n[F4] eseguo il comando `cat file-che-non-esiste` "
               "assegnato...\n");
        execlp("cat", "cat", "file-che-non-esiste", NULL);
        exit_with_sys_err("exec in F4");
    } else {
        wait(&exit_status);
        printf("[P] figlio F4 terminato con exit-code %d\n",
               WEXITSTATUS(exit_status));
    }

    printf("\n[P] fine della sequenza di comandi da eseguire\n");
}

void exec_passed_command(int argc, char *const argv[]) {
    char *pathname;
    char *command_args[(argc - 1) + 1]; // serve un ultimo slot posto a NULL

    assert(argc >= 2); // almeno il comando da eseguire deve essere presente
                       // (controllo ridondante)

    printf("[P] invoco direttamente il comando, con argomenti, indicato sulla "
           "command-line...\n");

    pathname = strdup(argv[1]);
    command_args[0] = pathname;
    printf("[P] comando da eseguire: '%s'\n", pathname);
    printf("[P]   argomento args[0]: '%s'\n", command_args[0]);
    for (int i = 1; i < argc - 1; i++) {
        command_args[i] = strdup(argv[i + 1]);
        printf("[P]   argomento args[%d]: '%s'\n", i, command_args[i]);
    }
    command_args[argc - 1] = NULL; // sentinella per fine sequenza
    printf("[P]   argomento args[%d]: %s\n", argc - 1, command_args[argc - 1]);

    printf("\n[P] eseguo il comando...\n");
    execvp(pathname, command_args);
    exit_with_sys_err("exec");
}

int main(int argc, char *argv[]) {
    if (argc == 1) // nessun parametro passato
        exec_fixed_sequence_of_commands();
    else
        exec_passed_command(argc, argv);

    exit(EXIT_SUCCESS);
}
