/* Esercizio 3c — Ricerca carattere con mmap
Scrivere un programma in C denominato search-mmap.c che utilizza mmap per cercare tutte le
occorrenze di un carattere specificato in un file. Il programma deve:
1. aprire il file in lettura;
2. mappare il file in memoria;
3. contare e stampare tutte le posizioni in cui appare il carattere cercato;
4. gestire errori, chiudere il file e liberare le risorse
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "lib-misc.h"

int main(int argc, char * argv[]){
    if(argc!=3 || strlen(argv[2])!=1){
        printf("Usage: %s <file.txt> <character to search>\n", argv[0]);
        exit_with_sys_err("Wrong usage");
    }
    bool isaletter = false;
    char chartosearch = argv[2][0];
    char oppositeCaseChar;

    if(islower(chartosearch)){
        oppositeCaseChar = toupper(chartosearch);
        isaletter = true;
    }else if(isupper(chartosearch)){
        oppositeCaseChar = tolower(chartosearch);
        isaletter = true;
    }
    int fd;
    struct stat fileStats;

    if((fd = open(argv[1], O_RDONLY, 0700))<0){
        close(fd);
        exit_with_sys_err("open");
    }
    if((fstat(fd, &fileStats))<0){
        close(fd);
        exit_with_sys_err("fstat");
    }
    if(!(S_ISREG(fileStats.st_mode))){
        close(fd);
        exit_with_sys_err("Not a regular file");
    }

    char * filemap;
    if((filemap = (char *) mmap(NULL, fileStats.st_size, PROT_READ, MAP_PRIVATE, fd, 0))==MAP_FAILED){
        close(fd);
        exit_with_sys_err("mmap failed");
    }
    
    //Beginning the search and the count...
    int tot = 0;

    //If it is a letter I check both cases, instead i check only against 'chartosearch'. I implemented this with a bool condition in two separate loops so I avoid checking filemap[i] against an uninitialized char every single loop - and I avoid many unnecessary ifs checking too. 
    if(isaletter){
        for(int i =0; i <fileStats.st_size;i++){
            if(filemap[i]==chartosearch|| filemap[i]==oppositeCaseChar){
                tot++;
                if(filemap[i]==chartosearch){
                    printf("Found %c at position %d\n", chartosearch, i);
                }else{
                  printf("Found %c at position %d\n", oppositeCaseChar, i);
                }
            
            }
        }
    }else{
        for(int i =0; i <fileStats.st_size;i++){
            if(filemap[i]==chartosearch){
                tot++;
                printf("Found %c at position %d\n", chartosearch, i);
            }
        }
    }
    printf("%d occurrences of %c found in %s\n", tot, chartosearch, argv[1]);

    if((munmap(filemap, fileStats.st_size))<0){
        exit_with_sys_err("munmap");
    }
    close(fd);
    printf("Finished!\n");
    exit(EXIT_SUCCESS);
}