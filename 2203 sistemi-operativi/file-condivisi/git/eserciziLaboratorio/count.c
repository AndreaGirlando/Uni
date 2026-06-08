/**
 * conteggia il numero di byte contenuti in un file specificato
 * sulla riga di comando usando le chiamate `read`: esistono altri modi più
 * efficienti per ottenere questa informazione (vedi `stat`)
 */

#include "lib-misc.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int fd, size;
    int total = 0;
    char buffer[BUFSIZE];

    if (argc < 2)
        exit_with_err_msg("utilizzo: %s <file>\n", argv[0]);

    // apre il file sorgente in sola lettura
    if ((fd = open(argv[1], O_RDONLY)) == -1)
        exit_with_sys_err(argv[1]);

    // copia tutti i dati in memoria per conteggiare la dimensione
    do {
        if ((size = read(fd, buffer, BUFSIZE)) == -1)
            exit_with_sys_err(argv[1]);
        total += size;
        printf("ho letto %d byte\n", size);
    } while (size > 0);

    printf("La dimensione totale e' di %d byte\n", total);

    close(fd);

    exit(EXIT_SUCCESS);
}
