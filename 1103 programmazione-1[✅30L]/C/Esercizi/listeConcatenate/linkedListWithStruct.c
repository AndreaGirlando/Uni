#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct data{
    int id;
    char nome[30];
    char cognome[30];
};
typedef struct data data;
struct nodo{
    data *data;
    struct nodo *next;
};
typedef struct nodo nodo;

void insertInList(nodo **testa, data newData);
void cancellaNodo(nodo **testa, int key);
void printList(nodo *testa);
int main(){
    system("cls");
    /*
        ? Creo i nodi, li collego e li stampo tutto manualmente
        nodo n1 = {5,NULL};
        nodo n2 = {6,NULL};
        nodo n3 = {12,NULL};
        nodo *testa = &n1;
        n1.next = &n2;
        n2.next = &n3;
        printf("n1(%p): {%d,%p}\n",&n1,n1.d,n1.next);
        printf("n2(%p): {%d,%p}\n",&n2,n2.d,n2.next);
        printf("n3(%p): {%d,%p}\n",&n3,n3.d,n3.next);
    */

    nodo *testa = NULL;
    int numbers[5] = {1,2,3,4,5};

    for(int i = 0;i < 5;i++){
        data temp = {numbers[i],"Andrea","Girlando"};
        insertInList(&testa,temp);
        printList(testa);
    }

    for(int i = 0;i < 5;i++){
        cancellaNodo(&testa,numbers[i]);
        printList(testa);
    }

    return 0;
}

//! La funzione cancellaNodo elimina un nodo da una lista collegata basandosi su una chiave intera (key) fornita come parametro.
void cancellaNodo(nodo **testa, int key) {
    // Crea un puntatore locale per scorrere la lista.
    nodo *testaPtr = *testa;
    // Puntatore che tiene traccia del nodo precedente durante l'iterazione.
    nodo *prec = NULL;
    // Ciclo per scorrere i nodi della lista.
    while (testaPtr != NULL) {
        // Accede alla struttura dati associata al nodo corrente.
        data *dataPtr = testaPtr->data;
        // Controlla se l'ID del nodo corrente corrisponde alla chiave da cercare.
        if (dataPtr->id == key) {
            //! Caso: il nodo da eliminare è il primo nodo della lista.
            if (testaPtr == *testa) {
                // Aggiorna il puntatore della testa al nodo successivo.
                *testa = testaPtr->next;
            } else {
                //! Caso: il nodo da eliminare non è il primo.
                // Collega il nodo precedente al nodo successivo.
                prec->next = testaPtr->next;
            }
            // Libera la memoria allocata per i dati e per il nodo.
            free(dataPtr);
            free(testaPtr);
            // Termina la funzione poiché il nodo è stato trovato e rimosso.
            return;
        }
        // Aggiorna il puntatore del nodo precedente.
        prec = testaPtr;
        // Passa al nodo successivo.
        testaPtr = testaPtr->next;
    }
}


void insertInList(nodo **testa, data newData){
    //Alloco il nuovo nodo nella memoria
    nodo *nuovo = (nodo*)malloc(sizeof(nodo));
    data *dataPtr = (data*)malloc(sizeof(data));
    if(nuovo == NULL){
        printf("Errore di allocazione");
        exit(0);
    }

    dataPtr->id = newData.id;
    strcpy(dataPtr->nome,newData.nome);
    strcpy(dataPtr->cognome,newData.cognome);

    nuovo->data = dataPtr;
    nuovo->next = (*testa);

    //Cambio il valore della testa facendolo puntare all'elemento appena aggiunto

    (*testa) = nuovo;

}

void printList(nodo *tempTesta){
    printf("\n");
    while (tempTesta != NULL) {
        data *dataPtr = tempTesta->data;
        printf("|%d %s %s| -> ",dataPtr->id,dataPtr->nome,dataPtr->cognome);
        tempTesta = tempTesta->next;
    }
    printf("NULL\n");
}