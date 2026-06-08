#include "stdio.h"
#include "stdlib.h"
#include "fcntl.h"
#include "unistd.h"

// definiamo questa macro che stampa l'errore e poi un uscita con error code -1
#define exit_with_sys_err(s){ perror((s)); exit(EXIT_FAILURE); }


int main(int argc, char *argv[]) {

    int file1 = open("meme.txt", O_RDONLY); // Apre il file in modalità lettura
    int file2 = open("meme1.txt", O_RDONLY); // Apre il file in modalità lettura

    if(file1 == -1) exit_with_sys_err("Errore nel file1")
    if(file2 == -1) exit_with_sys_err("Errore nel file2")

    close(file1); // Prende l'identificativo del file e lo chiude
    close(file2); // Prende l'identificativo del file e lo chiude
    exit(EXIT_SUCCESS);
}
