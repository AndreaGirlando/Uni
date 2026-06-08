/**
 * effettua la manipolazione dei canali standard output ed error
 */

#include "lib-misc.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#define LOGNAME "test.log"

int main(int argc, char *argv[]) {
    int fd;

    // invia due messaggi distinti sui canali standard output e error
    printf("messaggio n.1 sullo standard output\n");
    dprintf(STDERR_FILENO, "errore n.1 simulato sullo standard error\n");

    if ((fd = open(LOGNAME, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)) ==
        -1)
        exit_with_sys_err(LOGNAME);

    // sostituisce con `dup` lo standard output con il file descriptor `fd`
    close(STDOUT_FILENO);
    dup(fd);
    printf("messaggio n.2 sullo standard output\n");
    dprintf(STDERR_FILENO, "errore n.2 simulato sullo standard error\n");

    // sostituisce con `dup2` lo standard error con il file descriptor `fd`
    dup2(fd, STDERR_FILENO);
    close(fd);  // il file descriptor originale non serve piu'
    printf("messaggio n.3 sullo standard output\n");
    dprintf(STDERR_FILENO, "errore n.3 simulato sullo standard error\n");

    exit(EXIT_SUCCESS);
}
