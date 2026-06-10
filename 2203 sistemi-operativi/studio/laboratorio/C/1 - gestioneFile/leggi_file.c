/**
 * conteggia il numero di byte contenuti in un file specificato
 * sulla riga di comando usando le chiamate `read`: esistono altri modi più
 * efficienti per ottenere questa informazione (vedi `stat`)
*/

#include "../FattiInAula/lib-misc.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 1024 //numero abbastanza grande da contenere tutto il file

int main(int argc, char *argv[]) {
    int IdFile, size;
    int total = 0;
    char buffer[BUFSIZE]; // buffer abbstanza grande da contenere tutto il file

    if (argc < 2)
        exit_with_err_msg("utilizzo: %s <file>\n", argv[0]);

    // apre il file sorgente in sola lettura
    if ((IdFile = open(argv[1], O_RDONLY)) == -1) exit_with_sys_err(argv[1]);

    // copia tutti i dati in memoria per conteggiare la dimensione
    do {
        if ((size = read(IdFile, buffer, BUFSIZE)) == -1)
            exit_with_sys_err(argv[1]);
        total += size;
        // printf("ho letto %d byte\n", size);
    } while (size > 0);

    printf("La dimensione totale e' di %d byte\n", total);
    printf("La stringa letta e: %s", buffer);

    close(IdFile);

    exit(EXIT_SUCCESS);
}
