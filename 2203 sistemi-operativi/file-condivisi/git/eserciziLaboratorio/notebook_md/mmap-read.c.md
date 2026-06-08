# File: mmap-read.c
```c
/**
 * legge il contenuto di un file utilizzando il meccanismo di
 * mappatura dei file in memoria
 */

#include "lib-misc.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    struct stat sb;
    off_t i;
    char *p;
    int fd;

    if (argc < 2)
        exit_with_err_msg("uso: %s <file>\n", argv[0]);

    if ((fd = open(argv[1], O_RDONLY)) == -1)
        exit_with_sys_err(argv[1]);

    if (fstat(fd, &sb) == -1)
        exit_with_sys_err(("fstat"));

    if (!S_ISREG(sb.st_mode))
        exit_with_err_msg("%s non è un file\n", argv[1]);

    if ((p = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) ==
        MAP_FAILED)
        exit_with_sys_err("mmap");

    if (close(fd) == -1)
        exit_with_sys_err("close");

    // printf("puntatore: %p\n", p);

    // tentativo di modificare una pagina su una mappatura in sola lettura:
    // p[4]='x';

    for (i = 0; i < sb.st_size; i++)
        putc(p[i], stdout);

    if (munmap(p, sb.st_size) == -1)
        exit_with_sys_err("munmap");

    exit(EXIT_SUCCESS);
}
```
