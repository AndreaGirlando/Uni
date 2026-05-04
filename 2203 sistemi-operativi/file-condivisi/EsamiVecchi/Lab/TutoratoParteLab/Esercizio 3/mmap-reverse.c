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
    struct stat sb;
    int i;
    char *p;
    int fd;
    char tmp;

    if(argc != 2)
        exit_with_msg("Usage: mmap-reverse <file>");

    if((fd = open(argv[1], O_RDWR)) < 0)
        exit_with_error(argv[1]);
    
    if(fstat(fd, &sb) < 0)
        exit_with_error("fstat");

    if(!S_ISREG(sb.st_mode)) // Verifica se il file è un file regolare
        exit_with_error("Not a regular file");

    if((p = (char *)mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0)) == MAP_FAILED)
        exit_with_error("mmap");

    if(close(fd) < 0) // Chiudiamo il file descriptor dopo mmap
        exit_with_error("close");

    for(int i = 0; i < sb.st_size / 2; i++) {
        tmp = p[i]; // Salva il byte corrente in una variabile temporanea
        p[i] = p[sb.st_size - i - 1]; // Scambia il byte corrente con il byte corrispondente dall'altra estremità
        p[sb.st_size - i - 1] = tmp; // Ripristina il byte salvato nella posizione opposta
    }

    printf("file %s reversed successfully\n", argv[1]);

    if(munmap(p, sb.st_size) < 0) // Unmapping della memoria mappata
        exit_with_error("munmap");
    
    exit(EXIT_SUCCESS); // Termina il programma con successo
}