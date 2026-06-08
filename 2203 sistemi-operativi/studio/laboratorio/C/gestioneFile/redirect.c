#include "../eserciziLaboratorio/lib-misc.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#define LOGNAME "test.log"

int main(int argc, char *argv[]) {
    int FileId;
    char buffer1[] = "abcdefghij";

    if ((FileId = open(LOGNAME, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)) == -1)
        exit_with_sys_err(LOGNAME);

    int newFileID = dup(FileId);

    write(FileId, buffer1, sizeof(buffer1) - 1);
    write(newFileID, buffer1, sizeof(buffer1) - 1);

    int standardOutput = dup(STDOUT_FILENO);
    dup2(FileId, STDOUT_FILENO);
    printf("\n Sto scrivendo nel file usando printf \n");
    fflush(stdout);
    dup2(standardOutput, STDOUT_FILENO);
    printf("\n Sto scrivendo nella console \n");

    close(standardOutput);
    exit(EXIT_SUCCESS);
}
