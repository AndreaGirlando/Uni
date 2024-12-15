#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int d;
    struct nodo *next;
};
typedef struct nodo nodo;

void insertInList(nodo **testa, int newData);
void printList(nodo *testa);
nodo* linearSearchInList(nodo *tempTesta, int key);
void cancellaNodo(nodo **testa, int key);

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
    int numbers[5] = {2,1,3,8,98};

    for(int i = 0;i < 5;i++){
        insertInList(&testa,numbers[i]);
        printList(testa);
    }
    printList(testa);

    nodo *elementoTrovatoPtr = linearSearchInList(testa,3);
    if(elementoTrovatoPtr == NULL){
        printf("\n\nElemento non trovato\n\n");
    }else{
        printf("\n\nL'elemento e' stato trovato all'indirizzo %p e contiene questi elementi: {d: %d  next: %p}\n\n",elementoTrovatoPtr,elementoTrovatoPtr->d,elementoTrovatoPtr->next);
    }

    printList(testa);
    for(int i = 0;i < 5;i++){
        cancellaNodo(&testa,numbers[i]);
        printList(testa);
    }



    elementoTrovatoPtr = linearSearchInList(testa,3);
    if(elementoTrovatoPtr == NULL){
        printf("\n\nElemento non trovato\n\n");
    }else{
        printf("\n\nL'elemento e' stato trovato all'indirizzo %p e contiene questi elementi: {d: %d  next: %p}\n\n",elementoTrovatoPtr,elementoTrovatoPtr->d,elementoTrovatoPtr->next);
    }

    return 0;
}

//! Funzione che cerca ed elimina un nodo da una lista collegata (linked list) basandosi su una chiave `key`.
void cancellaNodo(nodo **testa, int key) {
    // Puntatore temporaneo che scorre la lista, inizializzato alla testa della lista.
    nodo *tempTesta = *testa;
    // Puntatore per tracciare il nodo precedente durante l'iterazione.
    nodo *prec = NULL;
    // Ciclo che itera su tutti i nodi della lista finché non viene trovato il nodo con la chiave specificata.
    while (tempTesta != NULL) {
        // Controlla se il campo `d` del nodo corrente corrisponde alla chiave da cercare.
        if (tempTesta->d == key) {
            // Caso: il nodo da eliminare è il primo nella lista.
            if (tempTesta == *testa) {
                // Aggiorna la testa della lista per puntare al nodo successivo.
                *testa = tempTesta->next;
            } else {
                // Caso: il nodo da eliminare non è il primo.
                // Collega il nodo precedente con il successivo, escludendo il nodo corrente.
                prec->next = tempTesta->next;
            }
            // Libera la memoria del nodo corrente.
            free(tempTesta);
            // Termina la funzione poiché il nodo è stato trovato e rimosso.
            return;
        }
        // Aggiorna il puntatore del nodo precedente per l'iterazione successiva.
        prec = tempTesta;
        // Passa al nodo successivo nella lista.
        tempTesta = tempTesta->next;
    }
}


//! funzione che cerca e ritorna l'indirizzo di un nodo data una chiave
nodo* linearSearchInList(nodo *tempTesta, int key){
    while(tempTesta != NULL){
        if(tempTesta->d == key){
            return tempTesta;
        }
        tempTesta = tempTesta->next;
    }

    return NULL;

}

//! funzione che inserisce il nodo in testa
void insertInList(nodo **testa, int newData){
    //? nodo **testa mi serve l'indirizzo del puntatore per poterlo modificare
    nodo *nuovo = (nodo*)malloc(sizeof(nodo)); //Alloco il nuovo nodo nella memoria
    if(nuovo == NULL){
        printf("Errore di allocazione");
        exit(0);
    }
    nuovo->d = newData; //Inizzializzo il suo valore
    nuovo->next = (*testa); // il next di questo nodo sarà proprio la testa
    //Cambio il valore della testa facendolo puntare all'elemento appena aggiunto
    (*testa) = nuovo;
}

//! funzione che stampa la lista
void printList(nodo *tempTesta){
    printf("\n");
    //Scorro la lista fino a quando non trovo il valore di next che punta a NULL
    while (tempTesta != NULL) {
        printf("|%d| -> ", tempTesta->d);
        tempTesta = tempTesta->next;
    }
    printf("NULL\n");
}