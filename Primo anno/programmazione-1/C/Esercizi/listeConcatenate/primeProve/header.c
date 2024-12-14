#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Studente{
    int idStudente;
    char nome[255];
    char cognome[255];
    struct Studente *this;
    struct Studente *next;
};
typedef struct Studente Studente;
void writeStructToFile(FILE *tempFilePtr, Studente temp){
    rewind(tempFilePtr);
    fprintf(tempFilePtr,"%d %s %s %p %p\n",temp.idStudente,temp.nome,temp.cognome,temp.this,temp.next);
    fprintf(tempFilePtr,"%s","<--------------------------->\n");
}