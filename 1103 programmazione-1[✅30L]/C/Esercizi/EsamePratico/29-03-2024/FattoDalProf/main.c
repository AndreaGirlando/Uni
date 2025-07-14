#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Struct per memorizzare i parametri presi in input
typedef struct {
    char filename[MAX_SIZE];
} Parameters;

struct stackNode {
    int data;
    struct stackNode *next;
};

typedef struct stackNode StackNode;

// Effettua push nello stack
bool push(StackNode **top, int data) {
    // Nuovo nodo
    StackNode *newNode = malloc(sizeof(StackNode));

    // se non siamo riusciti ad allocare memoria
    if(newNode==NULL)
        return false; // restituisco false

    // copio la stringa in name e imposto la vecchia cima come next
    newNode->data = data;
    newNode->next = *top;

    // top deve puntare alla nuova cima
    *top = newNode;

    return true;
}

// effettua il pop
int pop(StackNode **top) {
    // teniamo un riferimento alla cima corrente
    StackNode *tmp = *top;
    // prendiamo un riferimento alla stringa dentro la cima corrente
    int data = tmp->data;
    // scorriamo la cima al prossimo nodo
    *top = tmp->next;
    free(tmp); // liberiamo la memoria occupata dal nodo
    // da notare che non facciamo free(data) perché la stringa la vogliamo restituire al chiamante
    return data; //restituiamo la stringa
}

// Una funzione che controlla se la pila è vuota
bool isEmpty(StackNode *top) {
    return top==NULL;
}

// Funzione per decodificare i parametri dalla riga di comando
Parameters decodeParameters(int argc, char *argv[]) {
    Parameters params;
    if (argc != 2) {
        fprintf(stderr, "Errore: numero di argomenti errato.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(params.filename, argv[1]);
    return params;
}

// Funzione per leggere il contenuto del file e restituire la pila P
StackNode* readFile(const char *filename) {
    StackNode *P = NULL;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Errore nell'apertura del file.\n");
        exit(EXIT_FAILURE);
    }
    int value;
    while (fscanf(file, "%d", &value) != EOF) {
        push(&P, value);
    }
    fclose(file);
    return P;
}

// Funzione per calcolare la media dei valori nella pila P
double getMean(StackNode **P) {
    double mean = 0;
    int count = 0;
    while(!isEmpty(*P)) {
        int val = pop(P);
        mean+=val;
        count++;
    }
    mean/=count;

    return mean;
}

// Funzione per riempire la pila P secondo le specifiche date
void fillP(const char *filename, double mean, StackNode **P) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Errore nell'apertura del file.\n");
        exit(EXIT_FAILURE);
    }
    int value;
    if (fscanf(file, "%d", &value) == EOF) {
        fprintf(stderr, "Errore: il file è vuoto.\n");
        exit(EXIT_FAILURE);
    }
    push(P, value);
    while (fscanf(file, "%d", &value) != EOF) {
        if (value > mean) {
            push(P, value);
        } else {
            int y = pop(P);
            push(P, (value + y) / 2);
        }
    }
    fclose(file);
}

// Funzione per scrivere il contenuto della pila P su file
void writeToFile(const char *filename, StackNode **P) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Errore nell'apertura del file.\n");
        exit(EXIT_FAILURE);
    }
    while(!isEmpty(*P)){
        fprintf(file, "%d\n", pop(P));
    }
    fclose(file);
}

void printStack(StackNode *P) {
    StackNode *top = P;
    if (top!=NULL)
        while(top){
            printf("%d\n", top->data);
            top = top->next;
        }
}

int len(StackNode *P) {
    int l = 0;
    StackNode *top = P;
    if (top!=NULL)
        while(top){
            top = top->next;
            l++;
        }
    return l;
}

int *transferP(StackNode **P) {
    int *A = calloc(len(*P),sizeof(int));

    int i=0;
    while(!isEmpty(*P)) {
        A[i++] = pop(P);
    }
    return A;
}

void printArray(int *A, int l) {
    for(int i=0; i<l; i++) {
        printf("%d\n", A[i]);
    }
}

void sort(int a[], int n) {
    // SelectionSort
    // Fa n-1 passate
    // Ad ogni passata, seleziona il minimo
    // della sequenza che va dall'indice pass alla fine
    // e scambia l'elemento all'indice pass con il minomo
    for(int pass = 0; pass < n-1; pass++) {
        // inizializziamo l'indice del minimo
        int idx_min = pass;
        for(int i = pass+1; i<n; i++) { //una semplice ricerca del minimo
            // in cui conserviamo l'indice del minimo
            if(a[i]<a[idx_min])
                idx_min = i;
        }
        // scambiamo i valori agli indici
        // pass e idx_min

        int tmp = a[pass];
        a[pass] = a[idx_min];
        a[idx_min] = tmp;
    }
}

int main(int argc, char *argv[]) {
    Parameters params = decodeParameters(argc, argv);
    printf("==========PUNTO A==========\n");
    printf("Nome del file: %s\n", params.filename);

    printf("\n==========PUNTO B==========\n");
    StackNode *P = readFile(params.filename);
    printf("Contenuto della pila:\n");
    printStack(P);

    printf("\n==========PUNTO C==========\n");
    double m = getMean(&P);
    printf("Media dei valori in P: %.2f\n", m);
    
    printf("\n==========PUNTO D==========\n");
    fillP(params.filename, m, &P);
    printf("Contenuto della pila:\n");
    printStack(P);

    printf("\n==========PUNTO E==========\n");
    int l = len(P);
    int *A = transferP(&P);
    
    sort(A,l);
    printArray(A, l);

    //printf("Contenuto della pila P:\n");
    //fillP(params.filename);

    return 0;
}
