/* Esercizio 3b - Concatenazione di due file con mmap
* Scrivere un programma in C denominato concat-mmap.c che utilizza mmap per 
concatenare due file in un terzo file. Il programma deve:
1. Aprire i due file sorgente in lettura e il file destinazione in scrittura
2. mappare i file sorgente e il file destinazione
3. scrivere i contenuti dei due file sorgente nel file destinazione usando memcpy
4. gestire errori, chiudere i file e liberare le risorse
*/

#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "lib-misc.h"

#define FILES_DIRECTORY "files/"
#define MAX_PATH 256



int main(int argc, char * argv[]){
    if(argc!=4 && argc !=3){
        printf("Usage: %s <file1.txt> <file2.txt> [file_destination.txt]\n", argv[0]);
        fprintf(stderr, "Usage error");
        exit(EXIT_FAILURE);
    }
    
    char destfile[MAX_PATH];
    char source1Name[MAX_PATH];
    char source2Name[MAX_PATH];

    if(argc == 4){
       if((snprintf(destfile, sizeof(destfile), "%s%s", FILES_DIRECTORY, argv[3]))<0){
            exit_with_sys_err("snprintf error dest");
       }
    }else{
        if((snprintf(destfile, sizeof(destfile), "%s%s", FILES_DIRECTORY, "destination.txt"))<0){
            exit_with_sys_err("snprintf error dest");
        }
    }
    int source1, source2, dest;
    struct stat stats1, stats2, stats3;

    //string management to have the correct names of the files
    if((snprintf(source1Name, sizeof(source1Name), "%s%s", FILES_DIRECTORY, argv[1]))<0){
        exit_with_sys_err("snprintf error source1");
    }
    if((snprintf(source2Name, sizeof(source2Name), "%s%s", FILES_DIRECTORY, argv[2]))<0){
        exit_with_sys_err("snprintf error source2");
    }

    
    //trying to open and check file1 
    if((source1 = open(source1Name, O_RDONLY, 0700))<0){
        exit_with_sys_err("Open file1");
    }
    if((fstat(source1, &stats1))<0){
        exit_with_sys_err("Stats file1");
    }
    if(!(S_ISREG(stats1.st_mode))){
        exit_with_sys_err("Item1 not a file");
    }

    //tryign to open and check file2
    if((source2 = open(source2Name, O_RDONLY, 0700))<0){
        exit_with_sys_err("Open file2");
    }
    if((fstat(source2, &stats2))<0){
        exit_with_sys_err("Stats file2");
    }
    if(!(S_ISREG(stats2.st_mode))){
        exit_with_sys_err("Item2 not a file");
    }
    
    if(argc==4){
        //opening and checking the destination file
        if((dest = open(destfile, O_RDWR, 0700))<0){
            exit_with_sys_err("Open given destination file");
        }
        if((fstat(dest, &stats3))<0){
            exit_with_sys_err("Stats given destination file");
        }
        if(!(S_ISREG(stats3.st_mode))){
            exit_with_sys_err("Item3 not a file");
        }
    }else{
        if((dest = open(destfile, O_RDWR | O_CREAT | O_TRUNC, 0700))<0){
            exit_with_sys_err("Open new destination file");
        }
        if((fstat(dest, &stats3))<0){
            exit_with_sys_err("Stats new destination file");
        }if((fstat(dest, &stats3))<0){
            exit_with_sys_err("Stats given destination file");
        }
    }
    //calculating total length of files - needed for the ftruncate
    off_t len1 = stats1.st_size;
    off_t len2 = stats2.st_size;
    off_t totLen = len1+len2;
    printf("Length of file 1: %ld -- Length of file 2: %ld -- Total Length: %ld\n", (size_t)len1, (size_t)len2, (size_t)totLen);

    //truncate destination file to desired length 
    if((ftruncate(dest, totLen))<0){
        exit_with_sys_err("Ftruncate");
    }
   
    //mapping the files 
    char * source1map;
    char * source2map;
    char * destinationMap;
    printf("Now mapping...\n");
    if((source1map =  mmap(NULL, len1, PROT_READ, MAP_PRIVATE, source1, 0))==MAP_FAILED){
        
        exit_with_sys_err("mmap file1");
    }
    if((source2map =  mmap(NULL, len2, PROT_READ, MAP_PRIVATE, source2, 0))==MAP_FAILED){
        exit_with_sys_err("mmap file2");
    }
    if((destinationMap = mmap(NULL, totLen, PROT_WRITE, MAP_SHARED, dest, 0))==MAP_FAILED){
        exit_with_sys_err("mmap destination");
    }

    //closing the file descriptors after the mapping
    close(source1);
    close(source2);
    close(dest);

    //Note to self: if I were using threads I would probably put a thread barrier here!

    printf("Now copying %s and %s to %s ...\n", argv[1], argv[2], destfile);

    //copying the files. 
    //Note: need to specity dest+len1 for offset here, because destinationMap is the memory address of the mapped file. There's no file pointer dynamic
    memcpy(destinationMap, source1map, len1);
    memcpy(destinationMap+len1, source2map, len2);

    //cleaning up and un-mapping everything
    //Note: even if I had changed something, source1 and 2 would remain unchanged on disk because of the MAP_PRIVATE attributes
    printf("Cleaning up...\n");
    if((munmap(source1map, len1))<0){
        exit_with_sys_err("unmapping1");
    }
    if((munmap(source2map, len2))<0){
        exit_with_sys_err("unmapping2");
    }
    if((munmap(destinationMap, totLen))<0){
        exit_with_sys_err("unmapping dest");
    }
    printf("Concatenation completed successfully!\n");

    exit(EXIT_SUCCESS);

}