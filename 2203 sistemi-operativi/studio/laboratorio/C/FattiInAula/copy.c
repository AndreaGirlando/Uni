/**
 * copia il contenuto di un file sorgente su un file di destinazione usando
 * read` e `write`
 */

#include "lib-misc.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

/* la costante `BUFSIZ` è già definita in stdio.h e viene usata per i buffer
 * interni alla libreria (vedi stream): può cambiare da piattaforma a\
 * piattaforma, ha una dimensione minimo da 256 e in genere garantisce un I/O
 * efficiente */
// #define BUFSIZ 8192

int main(int argc, char *argv[]) {
    int sd, dd, size, result;
    char buffer[BUFSIZ];

    // controlla il numero di parametri
    if (argc != 3)
        exit_with_err_msg("utilizzo: %s <sorgente> <destinazione>\n", argv[0]);

    printf("creo una copia di '%s' su '%s'\n", argv[1], argv[2]);

    // apre il file sorgente in sola lettura
    if ((sd = open(argv[1], O_RDONLY)) == -1)
        exit_with_sys_err(argv[1]);

    // apre il file destinazione in sola scrittura, con troncamento e creazione
    if ((dd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)) ==
        -1)
        exit_with_sys_err(argv[2]);

    // copia i dati dalla sorgente alla destinazione
    do {
        // legge fino ad un massimo di BUFSIZ byte dalla sorgente
        if ((size = read(sd, buffer, BUFSIZ)) == -1)
            exit_with_sys_err(argv[1]);

        // scrive i byte letti
        if ((result = write(dd, buffer, size)) == -1)
            exit_with_sys_err(argv[2]);
    } while (size == BUFSIZ);

    // chiude i file prima di uscire
    close(sd);
    close(dd);

    exit(EXIT_SUCCESS);
}
