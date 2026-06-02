/*---------------------------------------------------------------------------
 * concat-mmap.c
 * -------------
 * Concatena due file in un terzo usando mmap.
 *
 * Uso:
 *      ./concat-mmap <file1> <file2> <dest>
 *
 * Compilazione (GCC):
 *      gcc -Wall -Wextra concat-mmap.c -o concat-mmap
 *---------------------------------------------------------------------------*/

#include <fcntl.h>      /* open(), O_RDONLY, O_RDWR, O_CREAT …            */
#include <stdio.h>      /* printf(), perror()                              */
#include <stdlib.h>     /* exit(), EXIT_FAILURE / SUCCESS                  */
#include <sys/mman.h>   /* mmap(), munmap(), PROT_READ/WRITE, MAP_*        */
#include <sys/stat.h>   /* struct stat, fstat()                            */
#include <unistd.h>     /* close(), ftruncate()                            */
#include <string.h>     /* memcpy()                                        */

/*-------------------------------------------------------------
 * Gestione errori di sistema (errno)                         */
static void exit_with_error(const char *msg)
{
    perror(msg);
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
    /* =========== 1. Controllo argomenti ==================== */
    if (argc != 4)
        exit_with_msg("Usage: concat-mmap <file1> <file2> <dest>");

    /* =========== 2. Apertura file ========================== */
    int fd1  = open(argv[1], O_RDONLY);
    int fd2  = open(argv[2], O_RDONLY);
    if (fd1 < 0 || fd2 < 0)
        exit_with_error("open source");

    /* Stat dei due sorgenti per dimensione e permessi -------- */
    struct stat sb1, sb2;
    if (fstat(fd1, &sb1) < 0 || fstat(fd2, &sb2) < 0)
        exit_with_error("fstat");

    if (!S_ISREG(sb1.st_mode) || !S_ISREG(sb2.st_mode))
        exit_with_msg("Source files must be regular files");

    off_t len1 = sb1.st_size;
    off_t len2 = sb2.st_size;
    off_t total_len = len1 + len2;

    if (total_len == 0)
        exit_with_msg("Both source files are empty");

    /* Apertura/creazione file destinazione ------------------- */
    umask(0);  /* nessuna restrizione sui permessi richiesti    */
    mode_t dest_mode = (sb1.st_mode | sb2.st_mode) & 0777; /* somma permessi */
    int fdd = open(argv[3], O_RDWR | O_CREAT | O_TRUNC, dest_mode);
    if (fdd < 0)
        exit_with_error("open dest");

    /* =========== 3. Preparazione file destinazione ========= */
    if (ftruncate(fdd, total_len) < 0)
        exit_with_error("ftruncate dest");

    /* =========== 4. Mappature ============================== */
    char *p1 = mmap(NULL, len1, PROT_READ,
                    MAP_PRIVATE, fd1, 0);
    if (p1 == MAP_FAILED)
        exit_with_error("mmap file1");

    char *p2 = mmap(NULL, len2, PROT_READ,
                    MAP_PRIVATE, fd2, 0);
    if (p2 == MAP_FAILED)
        exit_with_error("mmap file2");

    /* Destinazione in lettura/scrittura condivisa ------------
       In questo modo le scritture su memoria finiscono davvero
       nel file su disco.                                      */
    char *pd = mmap(NULL, total_len,
                    PROT_READ | PROT_WRITE,
                    MAP_SHARED, fdd, 0);
    if (pd == MAP_FAILED)
        exit_with_error("mmap dest");

    /* I file descriptor possono essere chiusi dopo mmap ------ */
    close(fd1);
    close(fd2);
    close(fdd);

    /* =========== 5. Copia contenuti ========================= */
    memcpy(pd,           p1, len1);       /* copia file1       */
    memcpy(pd + len1,    p2, len2);       /* copia file2       */

    /* =========== 6. Cleanup ================================ */
    munmap(p1, len1);
    munmap(p2, len2);
    munmap(pd, total_len);

    printf("Concatenazione completata: %s + %s → %s\n",
           argv[1], argv[2], argv[3]);

    return EXIT_SUCCESS;
}
