/**
 * il padre e il figlio si limitano a visualizzare dei messaggi di servizio
 * sullo standard output: in una normale esecuzione il messaggio marcato con
 * '(*)' verrà visualizzato due volte sul terminale a causa del buffering degli
 * stream; se si usa l'opzione `unbuffered` sulla riga di comando lo standard
 * output non usarà buffering e il problema non si presenterà
 *
 * > ./fork-buffer-glitch
 * > ./fork-buffer-glitch unbuffered
 */

#include "stdlib.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define PAUSE 2

int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], "unbuffered") == 0) {
        setbuf(stdout, NULL);
        printf("[P] disabilito il buffering sullo standard output...\n");
    }

    printf(
        "[P] sono il padre e sono appena partito... (*)"); // NB: manca il
                                                           // ritorno a capo...

    if (fork() == 0) {
        // codice eseguito solo dal figlio
        printf("\n[F] sono il figlio e sono appena partito...\n");
        sleep(PAUSE);
        printf("[F] sono il figlio e sto per terminare\n");

        exit(EXIT_SUCCESS);
    }

    // codice eseguito solo da padre
    printf("\n[P] sono sempre il padre e ho appena creato il figlio...\n");
    sleep(PAUSE * 2);
    printf("[P] sono il padre e sto per terminare\n");

    exit(EXIT_SUCCESS);
}
