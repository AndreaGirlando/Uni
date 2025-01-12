#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct param {
    char input_filename[50];
    char output_filename[50];
};
typedef struct param param;

struct nodo {
    char string[50];
    struct nodo *next;
};
typedef struct nodo nodo;

param decodeParameters(int numeroArgomenti, char ** argv);
void readFile(nodo **testa, char filename[50]);
void inserisciNodo(nodo **testa,char inputString[50]);
void printList(nodo *testa);
int getLenOfList(nodo *testa);
void filterList(nodo **testa, int media, int *array, int arrayLen);
int* getArray(nodo *testa, int arrayLen);
void writeFile(nodo *testa, char filename[50]);

int main(int argc, char **argv){

    param dati = decodeParameters(argc, argv);
    printf("input_filename: %s\n", dati.input_filename);
    printf("output_filename: %s\n\n", dati.output_filename);

    nodo *testa = NULL;

    readFile(&testa, dati.input_filename);
    printList(testa);
    int lenOfList = getLenOfList(testa);

    int *array = getArray(testa,lenOfList);
    float media = 0;
    for(int i = 0;i<lenOfList;i++){
        printf("\nV[%d] = %d", i,array[i]);
        media = media + array[i];
    }
    media = media / lenOfList;
    printf("\n\nLa media di Y: %.2f\n\n",media);

    filterList(&testa,media,array,lenOfList);
    printList(testa);
    writeFile(testa,dati.output_filename);
    return 0;
}

void filterList(nodo **testa, int media, int *array, int arrayLen){

    nodo * tempTesta =  *(testa);
    nodo * prec = NULL;
    int position = arrayLen;
    while(tempTesta != NULL){

        if(array[arrayLen - position]>media){
            if(tempTesta == *(testa)){
                *(testa) = tempTesta->next;
                free(tempTesta);
                tempTesta = *(testa);
            }else{
                prec->next = tempTesta->next;
                free(tempTesta);
                tempTesta = prec;
            }
        }
        position--;
        prec = tempTesta;
        tempTesta = tempTesta ->next;
    }

}



int* getArray(nodo *testa, int arrayLen){

    nodo *tempTesta = testa;
    int *array = calloc(sizeof(int),arrayLen);
    int position = arrayLen;
    while(tempTesta != NULL){
        int numeroVocali = 0;

        for(int k = 0; k<strlen(tempTesta->string);k++){
            if(tempTesta->string[k] == 'a' || tempTesta->string[k] == 'e' || tempTesta->string[k] == 'i' || tempTesta->string[k] == 'o' || tempTesta->string[k] == 'u'){
                // printf("\n%c",tempTesta->string[k]);
                numeroVocali++;
            }
        }

        array[arrayLen - position] = numeroVocali;
        position--;
        tempTesta = tempTesta->next;
    }

    return array;

}

int getLenOfList(nodo *testa){
    nodo *tempTesta = testa;
    int len = 0;
    while(tempTesta != NULL){
        len++;
        tempTesta = tempTesta->next;
    }
    return len;
}

void inserisciNodo(nodo **testa,char inputString[50]){
    nodo *newNodo = malloc(sizeof(nodo));
    newNodo->next = NULL;
    strcpy(newNodo->string,inputString);

    if(*(testa) == NULL){
        *(testa) = newNodo;
    }else{
        nodo *tempTesta = *(testa);
        nodo *prec = NULL;
        int stringLen = strlen(inputString);//! 5
        while(tempTesta != NULL){

            if(stringLen<strlen(tempTesta->string)){
                if(prec == NULL){
                    newNodo->next = *(testa);
                    *(testa) = newNodo;
                }else{
                    newNodo->next = prec->next;
                    prec->next = newNodo;
                }
                return;
            }else{
                prec = tempTesta;
                tempTesta = tempTesta->next;
            }
        }
        prec->next = newNodo;
    }

}

void printList(nodo *testa){

    nodo *tempTesta = testa;
    while(tempTesta != NULL){
        printf("%s, %d\n",tempTesta->string, strlen(tempTesta->string));
        tempTesta = tempTesta->next;
    }

}

void readFile(nodo **testa, char filename[50]){

    FILE *file = fopen(filename,"r");
    if(file == NULL){
        printf("Impossibile aprire il file specificato");
        exit(EXIT_FAILURE);
    }
    while(!feof(file)){
        char string[50];
        fscanf(file,"%s\n",string);
        // printf("%s ",string);
        inserisciNodo(testa,string);
    }



}

void writeFile(nodo *testa, char filename[50]){
    FILE *file = fopen(filename,"w");
    if(file == NULL){
        printf("Impossibile aprire il file specificato");
        exit(EXIT_FAILURE);
    }
    nodo *tempTesta = testa;
    while(tempTesta != NULL){
        fprintf(file,"%s\n",tempTesta->string);
        tempTesta = tempTesta->next;
    }
}


param decodeParameters(int numeroArgomenti, char ** argv){
    param res;
    if(numeroArgomenti == 3){
        if(strstr(argv[1], ".text")){
            strcpy(res.input_filename,argv[1]);
        }else{
            printf("il file di input deve avere l'estensione '.text' ");
            exit(EXIT_FAILURE);
        }
        if(strstr(argv[2], ".output")){
            strcpy(res.output_filename,argv[2]);
        }else{
            printf("il file di output deve avere l'estensione '.output' ");
        }
        return res;
    }else{
        printf("Numero di argomenti errato");
        exit(EXIT_FAILURE);
    }
}