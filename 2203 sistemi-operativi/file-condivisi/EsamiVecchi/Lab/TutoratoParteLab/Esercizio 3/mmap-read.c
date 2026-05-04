#include <fcntl.h>      // Include per l'uso di open(), O_RDONLY, O_RDWR, O_CREAT, etc.
// Questa libreria contiene le definizioni per operazioni sui file come open e le relative flag.

#include <stdio.h>      // Libreria standard di input/output
// Include funzioni come printf(), fprintf(), fopen(), fclose(), etc.

#include <stdlib.h>     // Libreria standard per funzioni di utilità generale
// Include malloc(), free(), exit(), atoi(), rand(), e altro.

#include <sys/mman.h>   // Libreria per memory mapping (mmap, munmap, PROT_READ, MAP_SHARED, ecc.)
// Serve per mappare un file o una porzione di memoria nel proprio spazio di indirizzamento,
// utile per lavorare con file di grandi dimensioni senza caricarli interamente in memoria.

#include <sys/stat.h>   // Include strutture e funzioni per gestire attributi dei file (stat, fstat, chmod, etc.)
// Ad esempio, la struct stat serve a recuperare informazioni su un file.

#include <unistd.h>     // Include chiamate di sistema POSIX come read(), write(), close(), lseek()
// Molte funzioni fondamentali per la gestione dei file e dei processi sono definite qui.

#include <string.h>     // Include funzioni per la manipolazione di stringhe (strcpy, strlen, memcmp, etc.)

void exit_with_error(const char *msg){
    // Funzione per gestire gli errori, stampa un messaggio e termina il programma.
    perror(msg); // Stampa l'errore associato al messaggio passato.
    exit(EXIT_FAILURE); // Termina il programma con un codice di errore.
}

void exit_with_msg(const char *msg){
    // Funzione per gestire gli errori, stampa un messaggio e termina il programma.
    fprintf(stderr, "[Error]: %s\n", msg); // Stampa il messaggio di errore su stderr.
    exit(EXIT_FAILURE); // Termina il programma con un codice di errore.
}

int main(int argc, char *argv[]) {
    struct stat sb; // sb è una variabile di tipo struct stat, riempita da stat() o fstat().
    off_t offset;   // Variabile per gestire l'offset del file, utile per mmap.
    char *p;        // Puntatore a char che servirà per leggere il contenuto mappato in memoria il contenuto del file.
    int fd;         // File descriptor per il file da leggere.

    if(argc != 2)
        exit_with_msg("Usage: mmap-read <file>");

    if((fd = open(argv[1], O_RDONLY)) < 0) 
        exit_with_error(argv[1]);

    //recuperiamo le informazioni sul file
    if(fstat(fd, &sb) < 0)
        exit_with_error("fstat");
 
    if(!S_ISREG(sb.st_mode)) // Verifica se il file è un file regolare
        exit_with_error("Not a regular file");

    if((p = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
        exit_with_error("mmap");

    if(close(fd) < 0) // Chiudiamo il file descriptor dopo mmap
        exit_with_error("close");

    int i; // Dichiarazione della variabile i
    for(i = 0; i < sb.st_size; i++) {
        // Stampa il contenuto del file mappato in memoria
        putchar(p[i]);
    }
    putchar('\n'); // Aggiunge una nuova riga alla fine dell'output

    if(munmap(p, sb.st_size) < 0) // Unmapping della memoria mappata
        exit_with_error("munmap");
}