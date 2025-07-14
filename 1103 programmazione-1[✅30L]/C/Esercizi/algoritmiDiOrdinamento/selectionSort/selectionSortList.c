#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int dato;
    struct nodo *next;
};

typedef struct nodo nodo;
void insertInList(nodo **testa, int dato);
void printList(nodo *testa);
void selectionSort(nodo *testa);
int main(){

    nodo *testa = NULL;

    insertInList(&testa, rand()%100+1);
    insertInList(&testa, rand()%100+1);
    insertInList(&testa, rand()%100+1);
    insertInList(&testa, rand()%100+1);
    insertInList(&testa, rand()%100+1);
    printList(testa);
    selectionSort(testa);
    printList(testa);


    return 0;
}
void selectionSort(nodo *testa){

    if (testa == NULL) {
        return;
    }

    nodo* current = testa;


    while(current != NULL){
        nodo *iterator = current;
        nodo* smallest = current;

        while(iterator != NULL){
            if(smallest->dato > iterator->dato){
                printf("Dentro");
                smallest = iterator;
            }
            iterator = iterator->next;
        }

        if(smallest != current){
            int temp = current->dato;
            current->dato = smallest->dato;
            smallest->dato = temp;
        }
        current = current->next;
    }

}
void insertInList(nodo **testa, int dato){

    nodo *newNodo = malloc(sizeof(nodo));
    newNodo->dato = dato;
    newNodo->next = NULL;
    if((*testa) == NULL){
        (*testa) = newNodo;
    }else{
        newNodo->next = (*testa);
        (*testa) = newNodo;
    }


}
void printList(nodo *testa){
    printf("\n\n\n\n");
    nodo* tempTesta = testa;
    while(tempTesta != NULL){
        printf("|%d,%p|-> ", tempTesta->dato,tempTesta->next);
        tempTesta = tempTesta->next;
    }
    printf("NULL");
}