/**
 * copia un file sorgente su uno destinazione usando gli stream
 */

#include "lib-misc.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    FILE *in, *out;
    int c;

    if (argc != 3)
        exit_with_err_msg("utilizzo: %s <sorgente> <destinazione>\n", argv[0]);

    printf("creo una copia di '%s' su '%s'\n", argv[1], argv[2]);

    // apre lo stream sorgente in sola lettura
    if ((in = fopen(argv[1], "r")) == NULL)
        exit_with_sys_err(argv[1]);

    // apre/crea lo stream destinazione in sola scrittura (con troncamento)
    if ((out = fopen(argv[2], "w")) == NULL)
        exit_with_sys_err(argv[2]);

    // copia i dati dalla sorgente alla destinazione carattere per carattere
    while ((c = fgetc(in)) != EOF)
        fputc(c, out);

    // chiude gli stream
    fclose(in);
    fclose(out);

    exit(EXIT_SUCCESS);
}
