#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

unsigned int get_random() {
    static unsigned int m_w = 424242;
    static unsigned int m_z = 242424;
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return (m_z << 16) + m_w;
}

struct parametri {
    char* simboli;
    int n;
    char* output;
};

struct node {
    char value[20];
    struct node *next;
};

typedef struct node Node;

bool isEmpty(Node *head){
    return head==NULL;
}

bool push(Node **head, char *value) {
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL)
        return false;

    strcpy(newNode->value, value);
    if(isEmpty(*head)) {
        newNode->next = NULL;
        *head = newNode;
        return true;
    }

    newNode->next = *head;
    *head = newNode;
    return true;
}

char* pop(Node **head) {
    if(isEmpty(*head))
        return NULL;

    Node *tmp = *head;
    *head = tmp->next;
    char* out = tmp->value;
    char* copy = calloc(strlen(out), sizeof(char));
    strcpy(copy, out);
    free(tmp);
    return copy;
}

struct parametri decodeParameters(int argc, char* argv[]) {
    if(argc!=4) {
        fprintf(stderr, "Errore: il numero di parametri passati al programma deve essere pari a 3.\n");
        fprintf(stderr, "Uso corretto: %s simboli n output\n", argv[0]);
        exit(-1);
    }

    struct parametri p;

    p.simboli = argv[1];
    p.output = argv[3];

    char *end;
    p.n = (int) strtol(argv[2], &end, 10);

    if(*end) {
        fprintf(stderr, "Errore: n non è un intero valido.\n");
        exit(-1);
    }

    if(p.n<8 || p.n>18) {
        fprintf(stderr, "Errore: n deve essere compreso tra 8 e 18 (inclusi).\n");
        exit(-1);
    }

    if(strlen(p.simboli)<10 || strlen(p.simboli)>20) {
        fprintf(stderr, "Errore: la lunghezza di simboli deve essere compresa tra 10 e 20 caratteri (inclusi).\n");
        exit(-1);
    }

    return p;
}

int fact(int x) {
    int y = 1;
    for(int i=1; i<=x; i++) {
        y*=i;
    }
    return y;
}

int* readInput(int n) {
    int* W = calloc(n, sizeof(int));


    int x;
    for(int i = 0; i<n; i++) {
        scanf("%d", &x);
        W[i] = fact(x);
    }

    return W;
}

char* sampleString(char* simboli, int h) {
    char* out = calloc(h+1, sizeof(char));
    int L = strlen(simboli);
    printf("\n\nL: %d\n\n",L);
    for(int i=0; i<h; i++) {
        out[i] = simboli[get_random()%L];
    }
    out[h] = 0;
    return out;
}

char **getStringArray(int *W, int n, char* simboli) {
    int L = strlen(simboli);
    char **Q = calloc(n, sizeof(char*));
    for(int i=0; i<n; i++) {
        Q[i] = sampleString(simboli, W[i]%L);
    }
    return Q;
}

char* common(char *a, char *b) {
    char* out = calloc(strlen(a), sizeof(char));
    int h = 0;
    for(int i =0; i<strlen(a); i++) {
        for(int j=0; j<strlen(b); j++) {
            if(a[i]==b[j]) {
                out[h++] = a[i];
                break;
            }
        }
    }
    return out;
}

Node ** getStack(char **Q, int n) {
    Node **head = malloc(sizeof(Node*));

    push(head, Q[0]);

    for(int i=1; i<n; i++) {
        char *to_insert;
        if(strlen(Q[i])%2==0)
            to_insert = Q[i];
        else {
            char *top = pop(head);
            to_insert = common(Q[i], top);
        }
        push(head, to_insert);
    }

    return head;
}

void stampaStack(Node **head) {
    Node *aux = *head;

    while(aux) {
        printf("%s\n", aux->value);
        aux = aux->next;
    }
}


void writeStackToFile(Node **head, char* output) {
    FILE *f = fopen(output, "w");
    if(f==NULL) {
        fprintf(stderr, "Errore nell'apertura del file %s.\n", output);
        exit(-1);
    }

    Node *aux = *head;

    while(aux) {
        fprintf(f, "%s\n", aux->value);
        aux = aux->next;
    }
    fclose(f);
}

void stampaArray(int arr[], int N) {
    for(int i=0; i<N; i++) {
        printf("%5d", arr[i]);
    }
}

void stampaStringArray(char** arr, int N) {
    for(int i=0; i<N; i++) {
        printf("%s\n", arr[i]);
    }
}

int main(int argc, char* argv[]) {
    struct parametri p = decodeParameters(argc, argv);
    printf("Punto A - Parametri: simboli = %s, output=%s, n = %d\n", p.simboli, p.output, p.n);

    int* W = readInput(p.n);
    printf("\nPunto B - Contenuto di W:\n");
    stampaArray(W, p.n);

    char **Q = getStringArray(W, p.n, p.simboli);
    printf("\n\nPunto C - Contenuto di Q:\n");
    stampaStringArray(Q, p.n);


    Node **head = getStack(Q, p.n);
    printf("\n\nPunto D - Contenuto della pila:\n");
    stampaStack(head);

    writeStackToFile(head, p.output);
}