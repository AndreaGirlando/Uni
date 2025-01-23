// 17.40
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct data {
    char nome[255];
    char cognome[255];
    int numero_conto;
    int anno_apertura;
    float saldo;
};

typedef struct data Data;

struct node {
    Data data;
    struct node *next;
};

typedef struct node Node;

bool isEmpty(Node *head) {
    return head==NULL;
}

void insertHead(Node **head, Data d) {
    Node *new = malloc(sizeof(Node));
    new->data = d;
    new->next = *head;
    *head = new;
}

void insertAfter(Node *node, Data d) {
    Node *new = malloc(sizeof(Node));
    new->data = d;
    new->next = node->next;
    node->next = new;
}

void insertOrdered(Node **head, Data d) {
    if(isEmpty(*head) || d.anno_apertura < (*head)->data.anno_apertura) {
        insertHead(head, d);
        return;
    }

    Node *tmp = *head;
    Node *prev = NULL;

    while(tmp->next && tmp->data.anno_apertura < d.anno_apertura) {
        prev = tmp;
        tmp = tmp->next;
    }

    if(prev)
        insertAfter(prev, d);
    else
        insertAfter(tmp, d);
}

void delete(Node **head, Data d) {
    if((*head)->data.numero_conto == d.numero_conto) {
        Node *tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }

    Node *tmp = *head;
    Node *prev = NULL;

    while(tmp->next && tmp->data.numero_conto != d.numero_conto) {
        prev = tmp;
        tmp = tmp->next;
    }

    if(tmp && tmp->data.numero_conto == d.numero_conto) {
        prev->next = tmp->next;
        free(tmp);
    }
}

void printData(Data d) {
    printf("%12s %12s %12d %12d %0.2f\n", d.nome, d.cognome, d.numero_conto, d.anno_apertura, d.saldo);
}

void printList(Node **head) {
    Node *aux = *head;

    while(aux) {
        printData(aux->data);
        aux = aux->next;
    }
}

int len(Node **head) {
    Node *aux = *head;

    int i = 0;
    while(aux) {
        i++;
        aux = aux->next;
    }
    return i;
}

struct parameters {
    char input[255];
    char output[255];
};

typedef struct parameters Parameters;

bool checkExt(char* s) {
    return (strlen(s)>=4) && (s[strlen(s)-1]=='t') && (s[strlen(s)-2]=='x') && (s[strlen(s)-3]=='t') && (s[strlen(s)-4]=='.');
}

Parameters readInput(char *argv[], int argc) {
    if(argc!=3) {
        fprintf(stderr, "Errore: il numero di parametri deve essere pari a 3.\n");
        fprintf(stderr, "Uso corretto: %s input.txt output.txt\n", argv[0]);
        exit(-1);
    }

    if(!checkExt(argv[1]) || !checkExt(argv[2])) {
        fprintf(stderr, "Errore: i nomi dei file devono avere estensione \".txt\".\n");
        exit(-1);
    }

    Parameters p;

    strcpy(p.input, argv[1]);
    strcpy(p.output, argv[2]);

    return p;
    
}

Node **readFile(char* fname) {
    Node** head = malloc(sizeof(Node*));

    FILE *f = fopen(fname, "r");

    if(!f) {
        fprintf(stderr, "Errore: impossibile aprire il file %s.\n", fname);
        exit(-1);
    }

    while(!feof(f)) {
        Data d;
        fscanf(f, "%s %s %d %d %f", d.nome, d.cognome, &d.numero_conto, &d.anno_apertura, &d.saldo);
        if(!feof(f)){
            insertOrdered(head, d);
        }
    }
    fclose(f);

    return head;
}

float getMax(Node *head) {
    float max = head->data.saldo;
    Node *aux = head;

    while(aux) {
        if(aux && aux->data.saldo>max) {
            max = aux->data.saldo;
        }
        aux = aux->next;
    }

    return max;
}

float computeX(Data d, float m) {
    float x = (float)(2023-d.anno_apertura)/5;
    if (x>1)
        x =1;
    return x*d.saldo/m;
}

void removeAccount(Node **A, float m) {
    Node *aux = *A;

    float max = computeX(aux->data, m);

    Node *tmp = aux;

    Data d;

    while(aux) {
        if(computeX(aux->data, m)>max) {
            max = computeX(aux->data, m);
            d = aux->data;
        }
        aux = aux->next;
    }

    delete(A, d);    
}

void writeFile(Node **head, char* fname) {

    FILE *f = fopen(fname, "w");
    if(!f) {
        fprintf(stderr, "Errore: impossibile aprire il file %s.\n", fname);
    }

    Node *aux = *head;

    while(aux) {
        //printData(aux->data);
        Data d = aux->data;
        fprintf(f, "%s %s %d %d %.2f\n", d.nome, d.cognome, d.numero_conto, d.anno_apertura, d.saldo);
        aux = aux->next;
    }

    fclose(f);
}

int main(int argc, char* argv[]) {
    Parameters p = readInput(argv, argc);

    Node **A = readFile(p.input);

    int n = len(A);
    
    for(int i=0; i<n/2; i++) {
        float m = getMax(*A);
        removeAccount(A, m);
    }
        
    writeFile(A, p.output);
}