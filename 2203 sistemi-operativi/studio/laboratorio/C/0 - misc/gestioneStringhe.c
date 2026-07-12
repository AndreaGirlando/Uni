#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER 1024

struct data {
    char* nome;
    char* cognome;
    char* platform;
};

int main(){

    char string[] = "Andrea;Girlando;Github";
    char** dividedString = malloc(sizeof(char*)*10);
    char* token;


    token = strtok(string, ";");
    int counter = 0;
    while(token != NULL){
        dividedString[counter] = token;
        counter++;
        token = strtok(NULL, ";");
    }

    printf("Contiene 'Andrea': %d\n", strstr(string, "Andrea")!=NULL);
    printf("Uguale ad 'Andrea': %d\n", strcmp(dividedString[0], "Andrea"));
    printf("Uguale ad 'Github': %d\n", strcmp(dividedString[0], "Github"));
    printf("Lughezza stringa dividedString[0]: %d", strlen(dividedString[0]));

    char string2[] = "Andrea;Girlando;Github";
    struct data* values = malloc(sizeof(struct data));
    values->nome = strtok(string2, ";");
    values->cognome = strtok(NULL, ";");
    values->platform = strtok(NULL, ";");

    printf("\n\n");

    printf("Nome: %s\nCognome: %s\nPlatform: %s\n", values->nome, values->cognome, values->platform);

    return 0;
}