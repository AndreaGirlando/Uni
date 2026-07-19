#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int data;
    struct nodo *next;
};
typedef struct nodo nodo;
void inserisciNodo(nodo **testa, int data);
void printList(nodo *testa);
void bubbleSortLista(nodo *testa);
int main(int argc, char** argv){

    int numberOfNodes = atoi(argv[1]);
    nodo *testa = NULL;

    for(int i = 0;i<numberOfNodes;i++){
        inserisciNodo(&testa,rand()%100+1);
    }
    printList(testa);

    bubbleSortLista(testa);

    printList(testa);

    return 0;
}

void bubbleSortLista(nodo *testa){

    nodo *tempTesta = NULL;
    int swapped;

    do{
        swapped = 0;      // Nessuno scambio all'inizio
        tempTesta = testa; // Ricomincia dall'inizio della lista
        while (tempTesta != NULL && tempTesta->next != NULL){
            if (tempTesta->data > (tempTesta->next)->data){
                // Scambia i dati
                int temp = tempTesta->data;
                tempTesta->data = (tempTesta->next)->data;
                (tempTesta->next)->data = temp;
                swapped = 1; // Indica che è stato fatto uno scambio
            }
            tempTesta = tempTesta->next; // Passa al nodo successivo
        }
    } while (swapped);


}

void inserisciNodo(nodo **testa, int data){

    nodo *newNodo = malloc(sizeof(nodo));
    newNodo -> data = data;
    newNodo -> next = NULL;

    if((*testa) == NULL){
        (*testa) = newNodo;
    }else{
        newNodo -> next = (*testa);
        (*testa) = newNodo;
    }

}

void printList(nodo *testa){
    printf("\n");
    nodo *tempTesta = testa;
    while(tempTesta != NULL){
        printf("|%p,%d| -> ",tempTesta->next, tempTesta->data);
        tempTesta = tempTesta -> next;
    }
    printf("NULL");
}
