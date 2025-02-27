#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int data;
    struct nodo *next;
};
typedef struct nodo nodo;
void inserisciNodo(nodo **testa, int data);
void printList(nodo *testa);
void insertionSortLista(nodo **testa);
int main(int argc, char** argv){

    int numberOfNodes = atoi(argv[1]);
    nodo *testa = NULL;

    for(int i = 0;i<numberOfNodes;i++){
        inserisciNodo(&testa,rand()%100+1);
    }
    printList(testa);

    insertionSortLista(&testa);

    printList(testa);

    return 0;
}

void insertionSortLista(nodo **testa) {
    // Se la lista è vuota o contiene un solo elemento, è già ordinata
    if (*testa == NULL || (*testa)->next == NULL) {
        return;
    }

    nodo *sorted = NULL; // Lista ordinata (inizialmente vuota)
    nodo *current = *testa;

    // Itera attraverso ogni nodo della lista originale
    while (current != NULL) {
        // Salva il prossimo nodo
        nodo *next = current->next;

        // Trova la posizione corretta nella lista ordinata per `current`
        if (sorted == NULL || sorted->data >= current->data) {
            // Inserisce all'inizio della lista ordinata
            current->next = sorted;
            sorted = current;
        } else {
            // Trova il punto di inserimento
            nodo *temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }

            // Inserisce il nodo corrente nella posizione corretta
            current->next = temp->next;
            temp->next = current;
        }

        // Passa al prossimo nodo nella lista originale
        current = next;
    }

    // Aggiorna la testa per puntare alla lista ordinata
    *testa = sorted;
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
