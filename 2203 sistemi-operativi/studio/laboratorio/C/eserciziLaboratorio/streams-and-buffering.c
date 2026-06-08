/**
 * visualizza, carattere-per-carattere, una serie di righe per evidenziare la
 * differenza in termini di buffering tra lo standard output (line buffered) e
 * lo standard error (unbuffered)
 */

#include "lib-misc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define PHRASE "Hello World!"
#define LINES 3

void print_phrases(FILE *channel) {
    char phrase[] = PHRASE;
    struct timespec pause = {0, 100 * 1000000};

    for (int i = 0; i < LINES; i++) {
        for (int j = 0; j < strlen(phrase); j++) {
            nanosleep(&pause, NULL);
            fputc(phrase[j], channel);
        }
        fputc('\n', channel);
    }
}

int main(int argc, char *argv[]) {

    printf("Messaggio sullo standard error (unbuffered): \n");
    print_phrases(stderr);

    printf("\nMessaggio sullo standard output (line buffered): \n");
    print_phrases(stdout);

    printf("\nDisabilito buffering su standard output...\n");
    setbuf(stdout, NULL);
    printf("\nMessaggio sullo standard output (unbuffered): \n");
    print_phrases(stdout);

    exit(EXIT_SUCCESS);
}
