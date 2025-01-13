#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 50

// Struct per memorizzare i parametri presi in input
typedef struct {
    char in_filename[MAX_SIZE];
    char out_filename[MAX_SIZE];
    char c;
} Parameters;

// La struct nodo della lista usata per creare la lista concatenata
struct listNode {
    char data;
    struct listNode *next;
};

// Una abbreviazione per la struct listNode
typedef struct listNode ListNode;

// Inserisce un nuovo nodo in testa
bool insertHead(ListNode **head, char data) {
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
bool insertTail(ListNode **head, char data) {
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

// Effettua la cancellazione di un nodo 
bool deleteNode(ListNode **head, ListNode *node) {
    if(*head==NULL)
        return false;
    // se trovo il valore in testa
    if(*head == node)
        return deleteHead(head); //elimino il nodo in testa

    // mantengo un riferimento allo scorso nodo
    ListNode *lastPtr = NULL;
    ListNode *currentPtr = *head; // cursore per scorrere fino al nodo da cancellare

    // scorriamo finché il currentPtr è non NULL e accountNumber corrente è diverso dal numero di account da rimuovere
    while(currentPtr && currentPtr != node) {
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
        printf("%c", currentNode->data);
        // continuo a scorrere la lista
        currentNode = currentNode->next;
    }
    
    return true;
}

// Funzione per decodificare i parametri dalla riga di comando
Parameters decodeParameters(int argc, char *argv[]) {
    Parameters params;
    if (argc != 4) {
        fprintf(stderr, "Errore: numero di argomenti errato.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(params.in_filename, argv[1]);
    strcpy(params.out_filename, argv[2]);
    params.c = argv[3][0];
    return params;
}

// Funzione per leggere il contenuto del file e restituire la lista L
ListNode* readFile(const char *filename) {
    ListNode *L = NULL;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Errore nell'apertura del file.\n");
        exit(EXIT_FAILURE);
    }
    char value;
    while (fscanf(file, "%c\n", &value) != EOF) {
        insertTail(&L, value);
    }
    fclose(file);
    return L;
}



// Funzione per calcolare il numero di occorrenze di c in L
int countOccurrences(ListNode **L, char c) {
    // cursore per scorre la lsita
    ListNode *currentNode = *L;

    int o = 0;

    // finché il nodo corrente non è NULL
    while(currentNode) {
        // stampo account
        if (c==currentNode->data) 
            o++;
        // continuo a scorrere la lista
        currentNode = currentNode->next;
    }
    
    return o;
}

void processL(ListNode **L, int o) {
    ListNode *currentNode = *L;

    while(currentNode) {
        int p = countOccurrences(L, currentNode->data);


        if (p>=o) {
            deleteNode(L, currentNode);
            
            currentNode = *L; //ricomincia
        } else {
            // continuo a scorrere la lista
            currentNode = currentNode->next;
        }
    }
}


// Funzione per scrivere il contenuto della list L su file
void writeToFile(const char *filename, ListNode **L) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Errore nell'apertura del file.\n");
        exit(EXIT_FAILURE);
    }
    
    // cursore per scorre la lsita
    ListNode *currentNode = *L;

    // finché il nodo corrente non è NULL
    while(currentNode) {
        // stampo account
        fprintf(file, "%c", currentNode->data);
        // continuo a scorrere la lista
        currentNode = currentNode->next;
    }
}

int main(int argc, char *argv[]) {
    Parameters params = decodeParameters(argc, argv);
    printf("==========PUNTO A==========\n");
    printf("Nome del file di input: %s\n", params.in_filename);
    printf("Nome del file ouput: %s\n", params.out_filename);
    printf("Valore di c: %c\n", params.c);

    printf("\n==========PUNTO B==========\n");
    ListNode *L = readFile(params.in_filename);
    printf("Contenuto della lista:\n");
    printList(L);

    printf("\n==========PUNTO C==========\n");
    int o = countOccurrences(&L, params.c);
    printf("Occorrenze di %c in L: %d\n", params.c, o);
    
    printf("==========PUNTO D==========\n");
    processL(&L, o);
    printf("Contenuto della lista:\n");
    printList(L);
    puts("");

    // PUNTO E
    writeToFile(params.out_filename, &L);
    
    return 0;
}
