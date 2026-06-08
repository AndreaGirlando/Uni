/**
 * crea due nuovi file con la stessa maschera dei permessi ma con maschere di
 * creazione (umask) differenti
 *
 * nota: controllare i permessi effettivi applicati ai file dalla shell con:
 * > ./creation-mask
 * > ls -l test1.txt test2.txt
 */

#include "eserciziLaboratorio/lib-misc.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define RWRWRW_MASK (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(int argc, char *argv[]) {
    // azzera la maschera di creazione: tutti i permessi sono autorizzati
    umask(0);

    if (creat("test1.txt", RWRWRW_MASK) < 0)
        exit_with_sys_err("test1.txt");

    // inibisce la possibilità di dare permessi di lettura e scrittura al gruppo
    // e agli altri in fase di creazione di file e cartelle
    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

    if (creat("test2.txt", RWRWRW_MASK) < 0)
        exit_with_sys_err("test2.txt");

    exit(EXIT_SUCCESS);
}
