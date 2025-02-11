#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodo{
    int d;
    struct nodo *next;
};
typedef struct nodo nodo;

void enqueue(nodo **head, nodo **tail, int d);
void printCoda(nodo *testa);
int dequeue(nodo **head, nodo **tail);

int main(){

    nodo *head = NULL;
    nodo *tail = NULL;

    enqueue(&head,&tail,5);
    enqueue(&head,&tail,3);
    enqueue(&head,&tail,2);
    enqueue(&head,&tail,1);
    dequeue(&head,&tail);
    dequeue(&head,&tail);
    dequeue(&head,&tail);
    dequeue(&head,&tail);
    dequeue(&head,&tail);
    printCoda(head);

    return 0;

}

int dequeue(nodo **head, nodo **tail){
    nodo * tempNodo = *(head);
    if(*(head) == *(tail)){
        int res = tempNodo->d;
        *(head) = tempNodo->next;
        *(tail) = tempNodo->next;
        free(tempNodo);

        return res;
    }else{
        int res = tempNodo->d;
        *(head) = tempNodo->next;
        free(tempNodo);
        return res;
    }
}

void enqueue(nodo **head, nodo **tail, int d){
    nodo *newNodo = malloc(sizeof(nodo));
    newNodo->next = NULL;
    newNodo->d = d;

    if(*(head) == NULL && *(tail) == NULL ){
        *(head) = newNodo;
        *(tail) = newNodo;
    }else{
        (*tail)->next = newNodo;
        *(tail) = newNodo;
    }


}


void printCoda(nodo *head){
    while(head != NULL){
        printf("%d->", head->d);
        head = head->next;
    }
    printf("NULL");
}


