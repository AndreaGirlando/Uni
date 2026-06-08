/**
 * reimplementazione del comando `mv` usando gli hard-link: limitato al caso di
 * file sullo stesso file-system
 */

#include "lib-misc.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3)
        exit_with_err_msg(
            "utilizzo: %s <file-esistente> <nuovo-nome-e-o-posizione>\n",
            argv[0]);

    // crea un hard-link a partire dal file esistente
    if (link(argv[1], argv[2]) == -1)
        exit_with_sys_err(argv[1]);

    // rimuove il vecchio riferimento al file
    if (unlink(argv[1]) == -1)
        exit_with_sys_err(argv[1]);

    // il file è stato spostato e/o rinominato istantaneamente (a prescindere
    // dalla sua dimensione)

    exit(EXIT_SUCCESS);
}
