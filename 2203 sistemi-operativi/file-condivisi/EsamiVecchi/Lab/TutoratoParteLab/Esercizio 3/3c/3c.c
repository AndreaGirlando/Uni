/*---------------------------------------------------------------------------
 * search-mmap.c
 * -------------
 * Cerca un carattere in un file usando mmap e stampa tutti gli offset.
 *
 * Uso:
 *      ./search-mmap <file> <carattere>
 *
 * Compilazione:
 *      gcc -Wall -Wextra search-mmap.c -o search-mmap
 *---------------------------------------------------------------------------*/

#include <fcntl.h>      /* open(), O_RDONLY …                              */
#include <stdio.h>      /* printf(), perror()                              */
#include <stdlib.h>     /* exit(), EXIT_FAILURE / SUCCESS                  */
#include <sys/mman.h>   /* mmap(), munmap(), PROT_READ, MAP_PRIVATE        */
#include <sys/stat.h>   /* struct stat, fstat()                            */
#include <unistd.h>     /* close()                                         */
#include <ctype.h>      /* isprint() per validazione char                 */
#include <stdint.h>     /* intmax_t per stampa offset                     */

/* -----------------------------------------------------------
Helper per errori di sistema (errno)                       
*/
static void exit_with_error(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

/* -----------------------------------------------------------
 * Helper per errori logici                                  */
static void exit_with_msg(const char *msg)
{
    fprintf(stderr, "[Error] %s\n", msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    /* ===== 1. Validazione argomenti ======================= */
    if (argc != 3)
        exit_with_msg("Usage: search-mmap <file> <char>");

    if (argv[2][1] != '\0')
        exit_with_msg("Second argument must be a single character");

    char target = argv[2][0];
    if (!isprint((unsigned char)target))
        exit_with_msg("Character must be printable");

    /* ===== 2. Apertura file e stat ======================== */
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        exit_with_error(argv[1]);

    struct stat sb;
    if (fstat(fd, &sb) < 0)
        exit_with_error("fstat");

    if (!S_ISREG(sb.st_mode))
        exit_with_msg("Not a regular file");

    if (sb.st_size == 0)
        exit_with_msg("Source file is empty");

    /* ===== 3. Memory mapping (sola lettura) =============== */
    char *data = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (data == MAP_FAILED)
        exit_with_error("mmap");

    /* Il file descriptor non serve più una volta mappato     */
    if (close(fd) < 0)
        exit_with_error("close");

    /* ===== 4. Scansione e stampa offset =================== */
    size_t count = 0;
    for (off_t i = 0; i < sb.st_size; ++i) {
        if (data[i] == target) { 
            /* 
             * Ovviamente per trovare caratteri che siano sia maiuscoli
             * che minuscoli dobbiamo utilizzare nell'if la seguente
             * tolower(data[i]) == tolower(target);
             * oppure strcasecmp() se vogliamo ignorare il case
             * strcasecmp(data[i], target) == 0
             */
            printf("Trovato '%c' all'offset %jd\n", target, (intmax_t)i);
            ++count;
        }
    }

    printf("Occorrenze totali di '%c': %zu\n", target, count);

    /* ===== 5. Cleanup ===================================== */
    if (munmap(data, sb.st_size) < 0)
        exit_with_error("munmap");

    return EXIT_SUCCESS;
}
