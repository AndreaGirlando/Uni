#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

// definiamo questa macro che stampa l'errore e poi un uscita con error code -1
#define exit_with_sys_err(s){ perror((s)); exit(EXIT_FAILURE); }

void my_exit1(void) { printf("primo handler di uscita attivato!\n"); }
void my_exit2(void) { printf("secondo handler di uscita attivato!\n"); }

int main(int argc, char *argv[]) {

    // Settiamo gli handler, se ritorna un valore diverso da 0 allora c'è stato un errore nel setting
    if (atexit(my_exit1) != 0) exit_with_sys_err("my_exit1");
    if (atexit(my_exit2) != 0) exit_with_sys_err("my_exit1");

    exit(EXIT_FAILURE); // gli handler vengono eseguiti automaticamente in ordine LIFO
}
