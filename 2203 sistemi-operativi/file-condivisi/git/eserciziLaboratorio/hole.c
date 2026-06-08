/**
 * crea un nuovo file effettuando la scrittura di due blocchi di dati usando uno
 * spostamento di 256K byte: questo creerà un buco (hole) che viene riempito di
 * byte nulli (0) e che verrà implementato dal file-system come un hole che non
 * richiede allocazione di blocchi sul disco
 *
 * è possibile ispezionare il contenuto e la dimensione effettiva del file con:
 * > ls -l test.hole
 * > od -c test.hole
 * > du --block-size=1 --apparent-size test.hole
 * > du --block-size=1 test.hole
 */

#include "lib-misc.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#define FILENAME "test.hole"

int main(void) {
    int fd;
    char buffer1[] = "abcdefghij";
    char buffer2[] = "ABCDEFGHIJ";

    if ((fd = creat(FILENAME, S_IRUSR | S_IWUSR)) < 0)
        exit_with_sys_err(FILENAME);

    // scrive il primo blocco di 10 byte sul file (offset 0): notare che il
    // buffer avrà dimensione 11 byte poiché è inizializzato con una stringa C
    // con il byte nullo finale
    if (write(fd, buffer1, sizeof(buffer1) - 1) != 10)
        exit_with_sys_err("write");
    // adesso il file offset sarà a 10 (sizeof(buffer1) - 1)

    // sposta il file offset di 256K byte in avanti
    if (lseek(fd, 256 * 1024, SEEK_CUR) == -1)
        exit_with_sys_err("lseek");
    // adesso il file offset sarà a 262144+10

    // scrive il secondo blocco di 10 byte
    if (write(fd, buffer2, sizeof(buffer2) - 1) != 10)
        exit_with_sys_err("write");
    // adesso il file offset sarà a 262144+10+10

    printf("file '%s' con buchi creato!\n", FILENAME);

    exit(EXIT_SUCCESS);
}
