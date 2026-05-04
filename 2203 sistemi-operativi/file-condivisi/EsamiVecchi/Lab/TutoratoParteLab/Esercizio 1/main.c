#define MODE 0600 // Permessi di accesso: lettura/scrittura solo per il proprietario
#define BUFFER_SIZE 2048 // Dimensione del buffer per la lettura/scrittura
#define PATH_MAX 4096 // Lunghezza massima di un path (conservativa)

/*librerie standard*/
#include <stdio.h>      // printf, perror: per la stampa su stdout e la gestione degli errori
#include <stdlib.h>     // exit, EXIT_SUCCESS, EXIT_FAILURE: per la terminazione del programma e valori di ritorno

/* Librerie di sistema per operazioni su file */
#include <fcntl.h>      // open, O_RDONLY, O_CREAT, O_TRUNC, O_WRONLY: per aprire/creare file con flag specifici
#include <unistd.h>     // read, write, close: funzioni di I/O su file descriptor
#include <sys/stat.h>   // mode_t e definizioni per i permessi dei file (come MODE)
#include <errno.h>      // errno e messaggi d'errore associati, usato da perror

/* Libreria per la gestione dei percorsi*/
#include <libgen.h>     // basename(), dirname(): per ottenere nome file e directory da un path

void copy(char *source, char *dest){
    /*
        input = "src/file1.txt"
        output = "dir"
    */

    char path_destination[PATH_MAX];
    sprintf(path_destination, "%s/%s", dest, basename(source));

    /*
        basename("src/file1.txt") -> "file1.txt"
        dirname("src/file1.txt") -> "src"
    */

    int fin;
    int fout;
    int size;
    char buffer[BUFFER_SIZE];
    if((fin = open(source, O_RDONLY)) < 0) {
        perror("Errore nell'apertura del file di origine");
        exit(EXIT_FAILURE); // Exit with failure status
    }

    if((fout = open(path_destination, O_CREAT | O_TRUNC | O_WRONLY, MODE)) < 0) {
        perror("Errore nell'apertura del file di destinazione");
        close(fin);
        exit(EXIT_FAILURE); // Exit with failure status
    }

    do
    {
        size = read(fin, buffer, BUFFER_SIZE);
        if (size < 0){
            perror("Errore nella lettura del file");
            exit(EXIT_FAILURE); // Exit with failure status
        }
        else if(size > 0){
            if(write(fout, buffer, size) < 0){
                perror("Errore nella scrittura del file");
                exit(EXIT_FAILURE); // Exit with failure status
            }
        }
    } while (size == BUFFER_SIZE);

    /*
        Supponiamo che il file sia di 5000 byte e BUFFER_SIZE = 2048. Le letture saranno:
        prima lettura → 2048 byte
        seconda lettura → 2048 byte
        terza lettura → 904 byte → size < BUFFER_SIZE ⇒ esce dal ciclo
    */
    close(fin);
    close(fout);
    printf("File %s copiato in %s\n", source, path_destination);
    
}

int main(int argc, char **argv) {
    if (argc < 3){
        perror("Argomenti insufficienti. Inserire almeno un file ed una directory.");
        exit(EXIT_FAILURE); // Exit with failure status
    }

    for(int i = 1; i < argc - 1; i++){
        copy(argv[i], argv[argc - 1]);
    }

    exit(EXIT_SUCCESS); // Exit with success status
}