/*---------------------------------------------------------------------------
 * count-mmap.c
 * ------------
 * Conta righe e parole in un file usando mmap.
 *
 * Uso:
 *      ./count-mmap <file>
 *
 * Compilazione (GCC):
 *      gcc -Wall -Wextra count-mmap.c -o count-mmap
 *---------------------------------------------------------------------------*/

#include <fcntl.h>      /* open(), O_RDONLY, ecc.                         */
#include <stdio.h>      /* printf(), perror()                             */
#include <stdlib.h>     /* exit(), EXIT_FAILURE / SUCCESS                 */
#include <sys/mman.h>   /* mmap(), munmap(), PROT_READ, MAP_PRIVATE       */
#include <sys/stat.h>   /* struct stat, fstat()                           */
#include <unistd.h>     /* close()                                        */
#include <ctype.h>      /* isspace() per riconoscere spazi bianchi        */

/*-------------------------------------------------------------
 * Gestione errori di sistema (errno)                         */
static void exit_with_error(const char *msg)
{
    perror(msg);        /* Stampa "msg: descrizione_errore"                */
    exit(EXIT_FAILURE);
}

/*-------------------------------------------------------------
 * Gestione errori logici (nessun errno significativo)        */
static void exit_with_msg(const char *msg)
{
    fprintf(stderr, "[Error] %s\n", msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    /*---------------------------------------------------------
     * Variabili principali                                   */
    int fd;                 /* File descriptor del file sorgente         */
    struct stat sb;         /* Info sul file (dimensione, tipo, …)       */
    char *data;             /* Puntatore ai byte mappati                 */
    size_t lines = 0;       /* Contatore righe                           */
    size_t words = 0;       /* Contatore parole                          */
    int in_word = 0;        /* Stato automa: 0 = fuori, 1 = dentro word  */

    /* -- 1. Controllo argomenti ----------------------------------------- */
    if (argc != 2)
        exit_with_msg("Usage: count-mmap <file>");

    /* -- 2. Apertura file in sola lettura ------------------------------- */
    if ((fd = open(argv[1], O_RDONLY)) < 0)
        exit_with_error(argv[1]);

    /* -- 3. Stat del file per ottenerne la dimensione ------------------- */
    if (fstat(fd, &sb) < 0)
        exit_with_error("fstat");

    if (!S_ISREG(sb.st_mode))
        exit_with_msg("Not a regular file");

    if (sb.st_size == 0)
        exit_with_msg("Source file is empty");

    /* -- 4. mmap: mappiamo l’intero file in sola lettura ---------------- */
    /*  - NULL        → lasciamo scegliere l’indirizzo al kernel
     *  - sb.st_size  → lunghezza da mappare
     *  - PROT_READ   → sola lettura
     *  - MAP_PRIVATE → copia privata; non modifichiamo il file            */
    data = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (data == MAP_FAILED)
        exit_with_error("mmap");

    /* Una volta mappato possiamo già chiudere il file descriptor          */
    if (close(fd) < 0)
        exit_with_error("close");

    /* -- 5. Scansione del buffer per contare righe e parole ------------- */
    for (off_t i = 0; i < sb.st_size; ++i) { // off_t è un tipo di dato per gestire offset nei file
        char c = data[i];

        /* Conteggio righe ------------------------------------------------ */
        if (c == '\n')
            ++lines;

        /* Conteggio parole ---------------------------------------------- */
        if (isspace((unsigned char)c)) {
            /* Fine parola se eravamo “dentro”                              */
            if (in_word) {
                in_word = 0;
            }
        } else {
            /* Primo carattere non‐spazio ⇒ nuova parola                   */
            if (!in_word) {
                in_word = 1;
                ++words;
            }
        }
    }

    /* Gestione speciale: se il file non termina con \n, la riga finale
       non è stata contata; la parola finale invece è già inclusa.         */
    if (sb.st_size > 0 && data[sb.st_size - 1] != '\n')
        ++lines;

    /* -- 6. Usiamo munmap per liberare la memoria ----------------------- */
    if (munmap(data, sb.st_size) < 0)
        exit_with_error("munmap");

    /* -- 7. Stampa risultati ------------------------------------------- */
    printf("File: %s\n", argv[1]);
    printf("Linee : %zu\n", lines);
    printf("Parole: %zu\n", words);

    exit(EXIT_SUCCESS); // Termina il programma con successo
}
