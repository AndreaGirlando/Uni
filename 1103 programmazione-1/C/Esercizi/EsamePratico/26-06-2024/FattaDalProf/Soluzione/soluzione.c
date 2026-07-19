#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

// Struct per i parametri
typedef struct {
    char *inputFile;
    int n;
    char *outputFile;
    char *alfabeto;
} Parameters;

struct queueNode {
    char *data;
    struct queueNode *next;
};

typedef struct queueNode QueueNode;

char* myStringCopy(char* inputString) {
    // allochiamo un array di caratteri di dimensione
    // lunghezza delle stringa +1 (prevediamo il carattere di terminazione)
    char* out = calloc(strlen(inputString)+1, sizeof(char)); // dovremo ricordarci di liberare questa memoria!

    if(out) { // controllo che la memoria sia stata allocata correttamente
        // copio i caratteri dalla stringa di input
        // a quella di output
        strcpy(out, inputString);
    }
    return out; // restituisco il puntatore
}

// Controlla se la coda è vuota
bool isEmpty(QueueNode *head) {
    return head==NULL;
}

void printQueue(QueueNode *head){
    QueueNode *aux = head;

    while(aux) {
        printf("%s\n", aux->data);
        aux = aux->next;
    }
}

// Inserisce nella queue nodo in coda
bool enqueue(QueueNode **head, QueueNode **tail, char* data) {
    // Crea nuovo nodo
    QueueNode *newNode = malloc(sizeof(QueueNode));

    // se l'allocazione non è andata a buon fine
    if(newNode == NULL)
        return false; //restituisci false

    // Copia la stringa all'interno del nodo
    newNode->data = myStringCopy(data);
    newNode->next = NULL; // Imposta next a NULL

    // Se la pila è vuota
    if(isEmpty(*head)) {
        *head = newNode; //il nodo è la nuova testa
    } else {
        (*tail)->next = newNode; //altrimenti aggiungi un nodo in coda
    }

    // in entrambi i casi, la nuova coda sarà il nuovo nodo
    *tail = newNode;

    return true; //enqeue andato a buon fine
}

// Elimina dalla queue un elemento dalla testa
char* dequeue(QueueNode **head, QueueNode **tail) {
    // se la pila è vuota
    if(isEmpty(*head))
        return NULL; //non si può rimuovere dalla coda

    // prendi il riferimento alla stringa
    char* data = (*head)->data;
    QueueNode *tmp = *head; // nodo temporaneo che pongo uguale alla head

    *head = (*head)->next; //faccio avanzare la testa di una posizione

    if(*head==NULL) //se la nuova head è NULL
        *tail = NULL; //la coda è vuota e anche la coda deve diventare NULL

    free(tmp); //libero memoria
    return data; //restituisco la stringa
}

// Funzione per la generazione di numeri casuali
unsigned int get_random() {
    static unsigned int m_w = 424242;
    static unsigned int m_z = 242424;
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return (m_z << 16) + m_w;
}

// Funzione per decodificare i parametri della linea di comando
Parameters decodeParameters(int argc, char *argv[]) {
    Parameters params;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input file> <integer n> <output file>\n", argv[0]);
        exit(1);
    }

    params.inputFile = argv[1];
    params.n = atoi(argv[2]);
    params.outputFile = argv[3];

    if (params.n < 3 || params.n > 12) {
        fprintf(stderr, "Error: n must be between 3 and 6.\n");
        exit(2);
    }

    FILE *file = fopen(params.inputFile, "r");
    if (!file) {
        fprintf(stderr, "Error: Cannot open input file.\n");
        exit(3);
    }

    params.alfabeto = calloc(255,sizeof(char));

    fscanf(file, "%s", params.alfabeto);
    size_t len = strlen(params.alfabeto);
    if (len < 8 || len > 12) {
        fprintf(stderr, "Error: Input string must be between 8 and 12 characters.\n");
        exit(5);
    }

    return params;
}

// Funzione per calcolare la sequenza di Fibonacci
void fibonacci(int n, int *A) {
    if (n >= 1) A[0] = 0;
    if (n >= 2) A[1] = 1;
    for (int i = 2; i < n; ++i) {
        A[i] = A[i-1] + A[i-2];
    }
}

// Funzione per generare una stringa casuale
void sampleString(const char *alphabet, int length, char *result) {
    size_t alphabet_len = strlen(alphabet);
    for (int i = 0; i < length; ++i) {
        result[i] = alphabet[get_random() % alphabet_len];
    }
    result[length] = '\0';
}

// Funzione per ottenere l'array di stringhe B
void getStringArray(int *A, int n, const char *alphabet, char **B) {
    for (int i = 0; i < n; ++i) {
        B[i] = (char *)malloc((A[i] + 1) * sizeof(char));
        sampleString(alphabet, A[i], B[i]);
    }
}

void getQueue(char **B, int n, QueueNode **head, QueueNode **tail) {
    for (int i=0; i<n; i++) {
        if(i==0) {
            enqueue(head, tail, B[i]);
        } else {
            if (strlen(B[i]) % 2 !=0) { //dispari
                char *str = dequeue(head, tail);
                char *newstr = calloc(strlen(str) + strlen(B[i]), sizeof(char));
                strcat(newstr, B[i]);
                strcat(newstr, str);
                enqueue(head, tail, newstr);
                free(str);
                free(newstr);
            } else { //pari 
                enqueue(head, tail, B[i]);
            }
        }
    }
    
}

// Funzione per scrivere il contenuto della coda su file
void writeToFile(const char *outputFile, QueueNode **head, QueueNode **tail) {
    FILE *file = fopen(outputFile, "w");
    if (!file) {
        fprintf(stderr, "Error: Cannot open output file.\n");
        exit(6);
    }
    while(!isEmpty(*head)) {
        fprintf(file, "%s\n", dequeue(head,tail));
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    Parameters params = decodeParameters(argc, argv);

    printf("========================A========================\n");
    printf("Parameters: inputFile=%s, n=%d, outputFile=%s\n", params.inputFile, params.n, params.outputFile);
    printf("Input string: %s\n", params.alfabeto);

    int A[params.n];
    fibonacci(params.n, A);

    printf("========================B========================\n");
    printf("Fibonacci array: ");
    for (int i = 0; i < params.n; ++i) {
        printf("%d ", A[i]);
    }
    printf("\n");

    char *B[params.n];
    getStringArray(A, params.n, params.alfabeto, B);

    printf("========================C========================\n");

    printf("String array B:\n");
    for (int i = 0; i < params.n; ++i) {
        printf("%s\n", B[i]);
    }

    printf("========================D========================\n");
    puts("Queue:");
    int queue_size;
    QueueNode *head = NULL;
    QueueNode *tail = NULL;
    getQueue(B, params.n, &head, &tail);

    printQueue(head);

    
    writeToFile(params.outputFile, &head, &tail);

    for (int i = 0; i < params.n; ++i) {
        free(B[i]);
    }

    return 0;
}
