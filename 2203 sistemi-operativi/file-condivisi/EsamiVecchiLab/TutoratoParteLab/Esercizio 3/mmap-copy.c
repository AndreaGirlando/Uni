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
    int fdin, fdout;
    // Dichiarazione di due file descriptor:
    // fdin sarà usato per aprire il file di input (origine)
    // fdout sarà usato per aprire o creare il file di output (destinazione)
    
    // Puntatori a char che serviranno per mappare in memoria
    // il contenuto dei file (origine e destinazione).
    char *src, *dst;
    
    // Struttura stat che conterrà informazioni sul file di input,
    // come la sua dimensione, utile per sapere quanto mappare in memoria.
    struct stat sb; // sb è una variabile di tipo struct stat, riempita da stat() o fstat().
    
    if (argc != 3)
        exit_with_error("Usage: mmap-copy <source file> <destination file>");

    // apriamo il file di input in modalità lettura
    if((fdin = open(argv[1], O_RDONLY)) < 0) 
        exit_with_error(argv[1]);


    // recuperiamo le informazioni sul file sorgente
    if(fstat(fdin, &sb) < 0)
        exit_with_error("fstat");

    // apriamo il file di output in modalità scrittura troncandolo o creandolo se non esiste
    umask(0); // Imposta la maschera dei permessi a 0 per permettere i permessi di default
    if((fdout = open(argv[2], O_RDWR | O_CREAT | O_TRUNC),
                    (sb.st_mode & 0777)) < 0) 
        exit_with_error(argv[2]);
    /*
        sb.st_mode potrebbe contenere qualcosa come 0100644, dove:
        0100000 indica che è un file regolare (S_IFREG)
        0644 sono i permessi POSIX (rw-r--r--)    
        L’operatore & (AND bit-a-bit) serve a filtrare i soli permessi, 
        scartando le altre informazioni (come il tipo di file):
    */
    
    //dobbiamo controllare se il file sorgente è vuoto
    //perchè in questo caso si creerebbero problemi sia con lseek che con mmap
    if(sb.st_size == 0)
        exit_with_msg("Source file is empty");


    //espandiamo il file di destinazione alla dimensione voluta prima del mapping
    if(ftruncate(fdout, sb.st_size) < 0) //ftruncate serve a impostare la dimensione del file, 
    //prende in input il file descriptor e la nuova dimensione
        exit_with_error("ftruncate");

    // mappiamo il file di input in memoria
    /** 
         * Mappiamo il file di input in memoria.
         * 
         * - `mmap(...)` crea una mappatura tra un file e una porzione di memoria del processo.
         * - `NULL` indica che il kernel può scegliere l'indirizzo dove posizionare la mappatura.
         * - `sb.st_size` è la dimensione del file da mappare (ottenuta prima con `fstat`).
         * - `PROT_READ` indica che la memoria sarà accessibile in sola lettura.
         * - `MAP_PRIVATE` crea una copia privata: le modifiche in memoria non verranno scritte nel file.
         * - `fdin` è il file descriptor del file sorgente (aperto in sola lettura).
         * - `0` è l'offset iniziale del file da cui partire per la mappatura.
         * 
         * Se `mmap` fallisce, restituisce `MAP_FAILED`, e in tal caso il programma termina con errore.
    */
    if((src = (char *)mmap(NULL, sb.st_size,PROT_READ, MAP_PRIVATE, fdin, 0)) == MAP_FAILED)
        exit_with_error("mmap source file");

    // mappiamo il file di destinazione
    /* Mappiamo il file di destinazione in scrittura con MAP_SHARED, 
    così le modifiche in memoria vengono salvate direttamente sul file */
    if((dst = (char *)mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fdout, 0)) == MAP_FAILED)
        exit_with_error("mmap destination file");

    // Chiudiamo i descrittori
    close(fdin);
    close(fdout);

    // Copiamo il contenuto della sorgente sulla destinazione
    memcpy(dst, src, sb.st_size);

    //operazione di demappatura (non obbligatoria)
    munmap(src, sb.st_size);
    munmap(dst, sb.st_size);

    exit(EXIT_SUCCESS); // Termina il programma con successo
}