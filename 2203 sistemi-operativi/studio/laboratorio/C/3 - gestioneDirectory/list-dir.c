/**
 * lista ricorsivamente il contenuto di una directory
 */

#include "lib-misc.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

// funzione per listare ricorsivamente una directory 'dir' a profondità 'depth'
void print_dir(const char *dir, int depth) {
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;

    // apre	la directory
    if ((dp = opendir(dir)) == NULL)
        exit_with_sys_err("opendir");

    // cambia la directory corrente
    if (chdir(dir) == -1)
        exit_with_sys_err("chdir");

    // legge le varie voci
    while ((entry = readdir(dp)) != NULL) {
        // prende le informazioni sull'oggetto
        if (lstat(entry->d_name, &statbuf) == -1)
            exit_with_sys_err("lstat");

        if (S_ISDIR(statbuf.st_mode)) { // controlla se e' una sottocartella
            // scarto le directory virtuali '.' e '..' altrimenti vado in loop
            if (strcmp(entry->d_name, ".") == 0 ||
                strcmp(entry->d_name, "..") == 0)
                continue;
            printf("%*s", depth * 4, " "); // indenta
            printf("%s/\n",
                   entry->d_name); // stampa il nome della sottocartella

            // chiama ricorsivamente la funzione sulla sottocartella
            print_dir(entry->d_name, depth + 1);
        } else {                           // e' un file
            printf("%*s", depth * 4, " "); // indenta
            printf("%s\n", entry->d_name); // stampa il nome della sottocartella
        }
    }
    chdir("..");

    closedir(dp);
}

int main(int argc, const char *argv[]) {
    const char *topdir;

    if (argc >= 2) // e' stato specificato almeno un parametro
        topdir = argv[1];
    else // parte dalla cartella corrente
        topdir = ".";

    printf("Scansione della directory '%s' ...\n", topdir);
    print_dir(topdir, 0);

    exit(EXIT_SUCCESS);
}
