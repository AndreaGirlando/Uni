/**
 * duplica un file utilizzando 'mmap' per operare sui file
 */

#include "lib-misc.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fdin, fdout;
    char *src, *dst;
    struct stat sb;

    if (argc < 3)
        exit_with_err_msg("uso: %s <file-sorgente> <file-destinazione>\n",
                          argv[0]);

    // apre il file sorgente in lettura
    if ((fdin = open(argv[1], O_RDONLY)) == -1)
        exit_with_sys_err(argv[1]);

    // recupera le informazioni sul file sorgente
    if (fstat(fdin, &sb) < 0)
        exit_with_sys_err(argv[1]);

    // apre il file destinazione troncandolo o creandolo
    umask(0);
    if ((fdout = open(argv[2], O_RDWR | O_CREAT | O_TRUNC,
                      (sb.st_mode & 0777))) == -1)
        exit_with_sys_err(argv[2]);

    // controlla se il file sorgente è vuoto: creerebbe problemi sia con
    // `lseek` che con mmap
    if (sb.st_size == 0)
        exit(EXIT_FAILURE);

    // espande il file destinazione alla dimensione voluta prima di mapparlo:
    // utilizza `ftruncate`
    if (ftruncate(fdout, sb.st_size) == -1)
        exit_with_sys_err("ftruncate");

    // mappa il file sorgente
    if ((src = (char *)mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fdin,
                            0)) == MAP_FAILED)
        exit_with_sys_err("mmap");

    // mappa il file destinazione
    if ((dst = (char *)mmap(NULL, sb.st_size, PROT_WRITE, MAP_SHARED, fdout,
                            0)) == MAP_FAILED)
        exit_with_sys_err("mmap");

    // chiudo i descrittori: non servono più!
    close(fdin);
    close(fdout);

    // copia il contenuto della sorgente sulla destinazione: usa 'memcpy' per
    // maggiore efficienza
    memcpy(dst, src, sb.st_size);

    // operazione di de-mappatura (non indispensabile)
    munmap(src, sb.st_size);
    munmap(dst, sb.st_size);

    exit(EXIT_SUCCESS);
}
