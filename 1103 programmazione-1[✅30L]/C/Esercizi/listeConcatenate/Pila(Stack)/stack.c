#include <stdio.h>
#include <stdlib.h>
struct nodo {
    int dato;
    struct nodo* next;
};
typedef struct nodo nodo;

void push(nodo** tempTesta, int dato);
void displayAll(nodo *testa);
int isEmpty(nodo* tempTesta);
void pop(nodo** tempTesta);

int main(int argc, char *argv[]){
    system("cls");



    nodo* testa = NULL;
    int numberOfNodes = atoi(argv[1]);

    push(&testa,5);

    displayAll(testa);
    pop(&testa);
    pop(&testa);
    pop(&testa);
    displayAll(testa);
    return 0;
}

int isEmpty(nodo* tempTesta){
    if(tempTesta == NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(nodo** tempTesta, int dato){
    nodo* newNodo = (nodo*)malloc(sizeof(nodo));
    newNodo->dato = dato;
    newNodo->next = NULL;
    if(isEmpty(*tempTesta)){
        *tempTesta = newNodo;
    }else{
        newNodo->next = *tempTesta;
        *tempTesta = newNodo;
    }

}

void pop(nodo** tempTesta){
    if(isEmpty(*tempTesta)){
        printf("\nErrore: Lo stack e' vuoto\n");
        return;
    }
    nodo* temp = (*tempTesta)->next;
    free(tempTesta);
    *tempTesta = temp;
}

void displayAll(nodo* testa){
    if(isEmpty(testa)){
        return;
    }
    printf("\n\n");
    nodo* tempTesta = testa;
    while(tempTesta != NULL){
        printf("|%d,%p|\n",tempTesta->dato,tempTesta->next);
        printf("%7s","|\n");
        printf("%7s","v\n");
        tempTesta = tempTesta->next;
    }
    printf("%7s","NULL");

}