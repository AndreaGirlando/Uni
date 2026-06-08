#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

/* definiamo questa macro per gestire in modo compatto gli errori: la metteremo,
 * insieme ad altre, nella libreria ufficiosa `misc.h` */
#define exit_with_sys_err(s)                                                   \
    {                                                                          \
        perror((s));                                                           \
        exit(EXIT_FAILURE);                                                    \
    }

void my_exit1(void) { printf("primo handler di uscita attivato!\n"); }
void my_exit2(void) { printf("secondo handler di uscita attivato!\n"); }

int main(int argc, char *argv[]) {
    printf("avvio del programma...\n");

    // programmiamo gli handler di uscita
    if (atexit(my_exit2) != 0) {
        // gestione standard degli errori: da ora in poi useremo la macro
        perror("my_exit2");
        exit(EXIT_FAILURE);
    }
    if (atexit(my_exit1) != 0)
        exit_with_sys_err("my_exit1");
    if (atexit(my_exit1) != 0)
        exit_with_sys_err("my_exit1");

    printf("aspetto un po'...\n");
    sleep(3);

    printf("chiudo il processo...\n");

    exit(EXIT_SUCCESS); // gli handler vengono eseguiti automaticamente
}
