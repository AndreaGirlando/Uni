/**
 *  un abbozzo di funzionamento di una mini-shell
 */

#include "lib-misc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER_LEN 1024
#define MAX_ARGS 20
#define ARG_DELIM " "
#define PROMPT "nano-shell>"

int main(int argc, char *argv[]) {
    char command[BUFFER_LEN];
    int pid, len, j;
    char *args[MAX_ARGS] = {NULL};
    char *token;

    while (1) {
        printf(PROMPT " ");
        fgets(command, sizeof(command), stdin);

        // rimozione eventuale ritorno a capo ('\n') finale
        len = strlen(command);
        if (command[len - 1] == '\n')
            command[len - 1] = '\0';

        if (strlen(command) == 0)
            continue;

        if (strcmp(command, "exit") == 0)
            break;

        // parsing del comando per separare i vari argomenti
        token = strtok(command, ARG_DELIM); // estrazione del primo token
        if (token == NULL)
            continue;
        j = 0;
        args[j++] = strdup(token);

        while ((token = strtok(NULL, ARG_DELIM)) !=
               NULL) { // estrazione degli altri token
            args[j++] = strdup(token);
        }

        // visualizzazione del vettore degli argomenti ottenuto
        for (int i = 0; i < MAX_ARGS; i++) {
            printf(" args[%d] = '%s'", i, args[i]);
            if (!args[i])
                break;
        }
        printf("\n");

        // creazione del figlio destinato ad eseguire il comando con `execvp`
        if ((pid = fork()) == -1) {
            exit_with_sys_err("fork");
        } else if (pid == 0) {
            // il figlio esegue il comando
            execvp(args[0], args);
            exit_with_sys_err("exec");
        } else {
            // il padre attende la terminazione del figlio
            int exit_status, exit_code;
            waitpid(pid, &exit_status,
                    0); // andava bene anche `wait(&exit_status)`
            exit_code = WEXITSTATUS(exit_status);
            if (exit_code > 0)
                fprintf(stderr, " esecuzione fallita con exit-code %d\n",
                        exit_code);
        }
        for (int i = 0; i < MAX_ARGS; i++) {
            if (args[i])
                free(args[i]); // strdup alloca memoria dinamica che va liberata
            args[i] = NULL;
        }
    }

    exit(EXIT_SUCCESS);
}
