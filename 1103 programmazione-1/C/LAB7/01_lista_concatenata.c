#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

// Una struct per conservare i dati dell'account
typedef struct {
    int accountNumber;
    char firstName[255]; // puntatori per allocare stringhe in maniera dinamica
    char lastName[255]; // verranno allocate quando creiamo una nuova struct
    float balance;
} Account;

// La struct nodo della lista usata per creare la lista concatenata
struct listNode {
    Account data;
    struct listNode *next;
};

// Una abbreviazione per la struct listNode
typedef struct listNode ListNode;

// Inserisce un nuovo nodo in testa
bool insertHead(ListNode **head, Account data) {
    // prendiamo in input doppio puntatore a head
    // necessario se vogliamo cambiare l'indirizzo di
    // memoria del puntatore alla testa

    // Nuovo nodo da inserire
    ListNode *newHead = malloc(sizeof(ListNode));

    // se non sono riuscito ad allocare memoria
    if(newHead == NULL)
        return false; //restituisci false, indica che c'è stato un problema
        // questa istruzione termina anche l'esecuzione della funzione

    newHead->next = *head; // la nuova testa avrà come next la vecchia testa
    newHead->data = data; // inseriamo i dati nella nuova testa

    // cambia l'indirizzo della testa
    *head = newHead;

    return true; // restituisci true, l'inserimento è andato a buon fine
}

// Inserisce un nuovo nodo in coda
bool insertTail(ListNode **head, Account data) {
    if(*head == NULL) { // Se la testa è NULL
        // inseriamo un nodo in testa
        // inserire in testa è equivalente a inserire
        // in coda in questo contesto
        return insertHead(head, data);
    }
    
    // Devo scorrere tutti i nodi della lista
    // Uso questo puntatore come "cursore" per scorrere
    // I vari nodi, iniziando dalla testa
    ListNode *currentPtr = *head; //copia l'indirizzo della testa in currentPtr
    while(currentPtr->next != NULL) { // finché il prossimo nodo non è NULL
        // non siamo ancora alla fine della lista, quindi scorro il cursore
        currentPtr = currentPtr->next; // il nuovo cursore è il prossimo nodo
    } // Una volta terminato, currentPtr contiene la coda (il next è NULL)

    // Creo il nuovo nodo
    ListNode* newNode = malloc(sizeof(ListNode)); 
    
    // Se newNode è NULL, non sono riuscito ad allocare correttamente
    if(newNode == NULL)
        return false; // indica che c'è stato un problema e esci dalla funzione
        
    // inserisci i dati nel nuovo nodo
    newNode->data = data;
    newNode->next = NULL; //next punta a NULL, è la nuova coda

    currentPtr->next = newNode; // la vecchia coda punta al nuovo nodo

    return true; // restituisco true, tutto è andato a buon fine
}

// Funzione di utilità per inserire un nodo dopo un dato nodo
bool insertAfter(ListNode **node, Account data) {
    // Alloco il nuovo nodo
    ListNode* newNode = malloc(sizeof(ListNode));

    if(!newNode) //errore se non riesco ad allocare
        return false;

    // inserisoc i dati
    newNode->data = data;
    newNode->next = (*node)->next; // il nuovo nodo punta al next del nodo dopo il quale inserire

    // il nodo dopo il quale inserire avrà il nodo corrente come next
    (*node)->next = newNode;

    return true; // nessun errore
}

// Effettua un inserimento ordinato per accountNumber
bool insertOrdered(ListNode **head, Account data) {
    ListNode *currentPtr = *head; // cursore per scorrere fino al punto di inserimento
    ListNode *lastPtr = NULL; // tengo anche un riferimento allo scorso puntatore
    // ci servirà per effettuare un inserimento con insertAfter
    
    //2 4 5 6 7
    // finché il puntatore corrente non è NULL
    // e l'account number del nodo corrente è inferiore all'account number da inserire
    while(currentPtr != NULL && currentPtr->data.accountNumber < data.accountNumber) {
        lastPtr = currentPtr; // aggiorna riferimento allo scorso puntatore
        currentPtr = currentPtr->next; // aggiorna riferimento al puntatore corrente
    }

    if(lastPtr == NULL) //se lastPtr è NULL, non siamo entrati nel while e quindi data.accountNumber è inferiore a tutti
    // i numeri di account o non è presente nessun nodo
        return insertHead(head, data); // in entrambi i casi va effettuato un inserimento in testo

    // se siamo arrivati qui, abbiamo un lastPtr valido e dobbiamo effettuare l'inserimento dopo quello
    return insertAfter(&lastPtr, data);
}

// Effettua la cancellazione della testa
bool deleteHead(ListNode **head) {
    // se la lista è vuota (la head è NULL)
    if(*head==NULL)
        return false; // indichiamo che non abbiamo trovato la testa

    // nodo temporaneo per non perdere 
    // l'indirizzo di head in modo da poter liberare la memoria
    ListNode *tmpNode = *head;

    // la nuova head è il secondo nodo
    *head = (*head)->next;
    free(tmpNode); // liberiamo la memoria occupata da tmpNode
    return true; // restituiamo true, abbiamo cancellato con successo
}

// Effettua la cancellazione di un nodo con un certo accountNumber
bool deleteNode(ListNode **head, int accountNumber) {
    if(*head==NULL)
        return false;
    // se trovo il valore in testa
    if(accountNumber == (*head)->data.accountNumber)
        return deleteHead(head); //elimino il nodo in testa

    // mantengo un riferimento allo scorso nodo
    ListNode *lastPtr = NULL;
    ListNode *currentPtr = *head; // cursore per scorrere fino al nodo da cancellare

    // scorriamo finché il currentPtr è non NULL e accountNumber corrente è diverso dal numero di account da rimuovere
    while(currentPtr && currentPtr->data.accountNumber != accountNumber) {
        // aggiorna riferimenti
        lastPtr = currentPtr;
        currentPtr = currentPtr->next;
    }

    if(currentPtr == NULL) //se currentPtr è NULL, siamo a fine lista
        return false; // non abbiamo trovato l'elemento da cancellare

    // altrimenti, colleghiamo lo scorso puntatore al prossimo
    lastPtr->next = currentPtr->next; // "saltiamo" il nodo da rimuovere
    free(currentPtr); //liberiamo memoria nodo

    return true; //cancellazione corretta
}

// Funzione di utilità che stampa la lista
bool printList(ListNode *head) { //stampiamo la lista
    if(head == NULL) //se è vuota non posso stampare
        return false;

    // cursore per scorre la lsita
    ListNode *currentNode = head;

    // finché il nodo corrente non è NULL
    while(currentNode) {
        // stampo account
        printf("%d %s %s %f\n", currentNode->data.accountNumber, currentNode->data.firstName, currentNode->data.lastName, currentNode->data.balance);
        // continuo a scorrere la lista
        currentNode = currentNode->next;
    }
    
    return true;
}

// Funzione di utilità che calcola la lunghezza della lista
int listlen(ListNode *head) {
    ListNode *cursor = head;

    int i = 0;
    while(cursor){
        cursor = cursor->next; //scorro la lista
        i++; // incremento contatore
    }

    return i;
}

int main() {
    ListNode *head = NULL;

    int accountNumber = 0;

    int tipoInserimento;

    puts("Scegli un tipo di inserimento (default: coda):");
    puts(" 1 in testa");
    puts(" 2 ordinato");
    puts(" 3 in coda");
    

    scanf("%d", &tipoInserimento);

    printf("Scelto inserimento ");
    switch(tipoInserimento) {
        case 1:
            printf("in testa");
            break;
        case 2:
            printf("ordinato");
            break;
        default:
            printf("in coda");
    }
    puts("");
    puts("");

    puts("Inserisci dati account nel formato \"accountNumber firstName lastName balance\".");
    puts("Ad esempio: 1234 John Doe 123.5");
    puts("Termina l'inserimento inserendo -1 -1 -1 -1");
    while(accountNumber!=-1) {
        Account data;

        printf("?: ");
        scanf("%d %s %s %f", &data.accountNumber, data.firstName, data.lastName, &data.balance);
        accountNumber = data.accountNumber;
        if(accountNumber==-1) {
            break;
        }

        bool result;
        switch(tipoInserimento) {
            case 1:
                result = insertHead(&head, data);
                break;
            case 2:
                result = insertOrdered(&head, data);
                break;
            default:
                result = insertTail(&head, data);
        }
            
        if(!result)
            fprintf(stderr, "Errore inserendo l'elemento!\n");
    }

    puts("\nEcco i dati da te inseriti:");
    printList(head);

    printf("Quale account vuoi eliminare? ");
    int toRemove;
    scanf("%d", &toRemove);

    printf("Rimuovo %d\n", toRemove);

    if(deleteNode(&head, toRemove)) {
        puts("\n\nEcco la lista dopo la cancellazione:");
        printList(head);
    } else {
        printf("L'account %d non esiste\n", toRemove);
    }

    printf("\nLunghezza della lista: %d\n", listlen(head));
}