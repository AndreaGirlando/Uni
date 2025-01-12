#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct params{
    char in_filename[50];
    char out_filename[50];
    char c;
};
typedef struct params params;


struct nodo {
    char dato;
    struct nodo *next;
};
typedef struct nodo nodo;

params decodeParameters(int numberOfParameters, char **tempArgv);
nodo* readFile(char filename[50]);
void writeToFile(nodo *testa, char filename[50]);
void addNodo(nodo **testa, char dato);
void readAllNodi(nodo *testa);
int countOccurrences(nodo *testa, char key);
void processL(nodo **testa, int o);

int main(int argc, char **argv){

    params data = decodeParameters(argc, argv);
    printf("\n\nin_filename: %s \nout_filename: %s \nc: %c", data.in_filename,data.out_filename,data.c);

    nodo *testa = readFile(data.in_filename);
    readAllNodi(testa);

    int o = countOccurrences(testa,data.c);
    printf("\n\nIl carattere %c si ripete %d volte", data.c, o);

    processL(&testa, o);

    readAllNodi(testa);

    writeToFile(testa,data.out_filename);


    return 0;
}

void processL(nodo **testa, int o){

    nodo *tempTesta = *testa;
    nodo *prec = NULL;
    while(tempTesta!=NULL){

        int p = countOccurrences(tempTesta, tempTesta->dato);


        if(p >= o){
            // printf("\nIl valore %c e stato trovato %d volte\n", tempTesta->dato,p);
            if(prec != NULL){
                prec->next = tempTesta->next;
                free(tempTesta);
                tempTesta = prec->next;
            }else{
                *(testa) = tempTesta->next;
                free(tempTesta);
                tempTesta = *(testa);
            }
        }else{
            prec = tempTesta;
            tempTesta = tempTesta -> next;
        }


    }

}

int countOccurrences(nodo *testa, char key){

    nodo *tempTesta = testa;
    int res = 0;
    while(tempTesta != NULL){
        if(tempTesta->dato == key){
            res++;
        }
        tempTesta = tempTesta -> next;
    }
    return res;

}

void addNodo(nodo **testa, char dato){
    nodo *newNodo = malloc(sizeof(nodo));
    newNodo -> dato = dato;
    newNodo -> next = NULL;

    if((*testa) == NULL){
        (*testa) = newNodo;
    }else{

        nodo *tempTesta = (*testa);

        while(tempTesta->next != NULL){
            tempTesta = tempTesta->next;
        }
        tempTesta->next = newNodo;
        // newNodo->next = (*testa);
        // (*testa) = newNodo;
    }
}

void readAllNodi(nodo *testa){
    printf("\n\n<------------------->\n\n");
    nodo *tempTesta = testa;
    while(tempTesta != NULL){
        printf("%c", tempTesta->dato);
        tempTesta = tempTesta->next;
    }
    printf("\n\n<------------------->");
}

params decodeParameters(int numberOfParameters, char **tempArgv){

    params res;
    if(numberOfParameters == 4){
        strcpy(res.in_filename, tempArgv[1]);
        strcpy(res.out_filename, tempArgv[2]);
        res.c = tempArgv[3][0];
        return res;
    }else{
        printf("Numero di parametri sbagliato");
        exit(EXIT_FAILURE);
    }


}

nodo* readFile(char filename[50]){

    nodo* tempTesta = NULL;
    FILE *file = fopen(filename,"r");
    while(!feof(file)){
        char c;
        fscanf(file, "%c\n", &c);
        addNodo(&tempTesta,c);
    }

    return tempTesta;
}

void writeToFile(nodo *testa, char filename[50]){
    nodo *tempTesta = testa;
    FILE *file = fopen(filename,"w");
    while(tempTesta != NULL){
        fprintf(file,"%c\n",tempTesta->dato);
        tempTesta = tempTesta->next;
    }
}