#include "stdio.h"
#include "stdlib.h"
#include "fcntl.h"
#include "unistd.h"
#include "../FattiInAula/lib-misc.h"
int main(){

    int fileId = open("test1.txt", O_RDONLY);
    FILE * file = fopen("test1.txt", "r");
    if(file == NULL) exit_with_sys_err("File");
    FILE * file1 = fdopen(fileId, "r"); // "r" è coerente con O_RDONLY
    if(file1 == NULL) exit_with_sys_err("File1");
    fclose(file);
    fclose(file1);

    return 0;
}