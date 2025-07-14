#include <stdio.h>
#include <stdlib.h>
struct nodo {
    int dato;
    struct nodo* next;
};
typedef struct nodo nodo;

int isEmpty(nodo **tempHead, nodo **tempTail);
void enqueue(nodo **tempHead, nodo **tempTail, int dato);
void dequeue(nodo **tempHead, nodo **tempTail);
void printQueue(nodo *tempHead);


int main(){

    nodo *head = NULL;
    nodo *tail = NULL;

    enqueue(&head,&tail,5);
    enqueue(&head,&tail,12);
    enqueue(&head,&tail,13);
    printQueue(head);
    dequeue(&head,&tail);
    printQueue(head);

    return 0;
}

void dequeue(nodo **tempHead, nodo **tempTail){

    if(isEmpty(tempHead,tempTail)){
        return;
    }else{
        nodo *temp = (*tempHead)->next;
        free((*tempHead));
        (*tempHead) = temp;
    }

}

void enqueue(nodo **tempHead, nodo **tempTail, int dato){

    nodo *newNodo = malloc(sizeof(nodo));
    newNodo -> dato = dato;
    newNodo -> next = NULL;
    if(isEmpty(tempHead,tempTail)){
        *tempHead = newNodo;
        *tempTail = newNodo;
    }else{
        (*tempTail)->next = newNodo;
        *tempTail = newNodo;
    }

}

int isEmpty(nodo **tempHead, nodo **tempTail){
    if((*tempHead) == NULL && (*tempTail) == NULL){
        return 1;
    }
    return 0;
}

void printQueue(nodo *tempHead){
    printf("\n\n");
    while(tempHead != NULL){
        printf("|%d,%p|->", tempHead->dato,tempHead->next);
        tempHead = tempHead->next;
    }
    printf("NULL");
}


