#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct nodo{
    int d;
    struct nodo *next;
};
typedef struct nodo nodo;

void insertInList(nodo **testa, int newData);
void printList(nodo *testa);

nodo* linearSearchInList(nodo *tempTesta, int key);
int cancellaNodo(nodo **testa, int key);

void linearSearchInListAndPrint(nodo *tempTesta, int key);
int main(){
    srand(time(NULL));
    system("cls");

    nodo *testa = NULL;
    int numbers[5];
    for(int i = 0;i < 5;i++){
        numbers[i] = rand()%2000+1;
        insertInList(&testa,numbers[i]);
        printList(testa);
    }
    linearSearchInListAndPrint(testa,numbers[0]);
    printList(testa);
    for(int i = 0;i < 5;i++){
        cancellaNodo(&testa,numbers[i]);
        printList(testa);
    }
    linearSearchInListAndPrint(testa,numbers[0]);


    return 0;
}

//! funzione che fa la ricerca nella lista e la formatta in modo accettabile
void linearSearchInListAndPrint(nodo *tempTesta, int key){
    printf("\n<--------------------------------->\n");
    nodo *tempNodo = linearSearchInList(tempTesta,key);
    if(tempNodo == NULL){
        printf("Il nodo (con key: %d) non trovato",key);
    }else{
        printf("Il nodo (con key: %d) e' stato trovato all'indirizzo %p e contiene i seguenti dati: |%d, %p|",key,tempNodo,tempNodo->d,tempNodo->next);
    }
    printf("\n<--------------------------------->\n\n");
}

//! funzione che cerca il nodo con la key specificata, se non lo trova ritorna NULL
nodo* linearSearchInList(nodo *tempTesta, int key){
    while(tempTesta != NULL){

        if(tempTesta->d == key){
            return tempTesta;
        }

        tempTesta = tempTesta->next;
    }
    return NULL;
}

//! funzione che cancella il nodo
//? 1 se cancella l'elemento specificato dalla key
//? 0 se non trova l'elemento specificato con la key
int cancellaNodo(nodo **testa, int key){

    if(*testa == NULL) return 0;

    nodo *tempTesta = *testa;
    nodo *prec = NULL;
    while(tempTesta != NULL){

        if(tempTesta->d == key){
            if(tempTesta == *testa){
                *testa = tempTesta->next;
            }else{
                prec->next = tempTesta->next;
            }
            free(tempTesta);
            return 1;
        }
        prec = tempTesta;
        tempTesta = tempTesta->next;
    }

    return 0;
}

//! funzione che inserisce in ordine
void insertInList(nodo **testa, int newData){
    nodo *newNodo = malloc(sizeof(nodo));
    newNodo->d = newData;
    if(*testa == NULL){
        //*Caso: lista vuota aggiungo in testa
        newNodo->next = NULL;
        *testa = newNodo;
        return;
    }else{
        //*Caso: aggiungo cercando quello più grande
        nodo *tempNodo = *testa;
        nodo *prec = NULL;
        while(tempNodo != NULL){
            if(newNodo->d > tempNodo->d ){//? Il nodo che cerchiamo di inserire è piu grande di quello che controlliamo
                if(prec == NULL){
                    //*Caso: il nodo che stiamo cercando di inserire è il più grande
                    //Inseriamo il nodo in testa
                    newNodo->next = *testa;
                    *testa = newNodo;
                    return;
                }else{
                    //*Caso: il nodo che stiamo cercando di inserire va inserito dove ci troviamo
                    //Inseriamo il nodo cambiando il valore next del nodo precedecente
                    newNodo->next = prec->next;
                    prec->next = newNodo;
                    return;
                }
            }
            prec = tempNodo;
            tempNodo = tempNodo->next;
        }
        //*Caso: il nodo che stiamo cercando di inserire è il più piccolo
        //Inseriamo il nodo in coda
        newNodo->next = NULL;
        prec->next = newNodo;
        return;
    }
}

//! funzione che stampa la lista
void printList(nodo *tempTesta){
    while (tempTesta != NULL) {
        printf("|d: %d,next: %p| -> ", tempTesta->d,tempTesta->next);
        tempTesta = tempTesta->next;
    }
    printf("NULL\n");
}