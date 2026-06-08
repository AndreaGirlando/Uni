/**
 * reimplementa il comando `cat`: legge un file di testo specificato
 * (o, altrimenti, lo standard input) e lo manda sullo standard output
 */

#include "lib-misc.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *in;
    char buffer[BUFSIZ];

    if (argc >= 2) { // viene specificato almeno un parametro
        if ((in = fopen(argv[1], "r")) == NULL)
            exit_with_sys_err(argv[1]);
    } else { // legge dallo standard input
        in = stdin;
    }

    // copia i dati dalla sorgente alla destinazione una riga alla volta
    while ((fgets(buffer, sizeof(buffer), in)) != NULL)
        printf("%s", buffer); // fputs(buffer, stdout);

    // chiude lo stream
    fclose(in);

    exit(EXIT_SUCCESS);
}
