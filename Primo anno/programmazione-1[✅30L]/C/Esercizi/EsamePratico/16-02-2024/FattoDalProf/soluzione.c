// 17.40
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct data {
    char nome[255];
    char cognome[255];
    int eta;
    int peso;
    int altezza;
    char sesso;
};

typedef struct data Data;

struct node {
    Data data;
    struct node *next;
};

typedef struct node Node;

void printData(Data d) {
    printf("%12s %12s %4d %4d %4d %4c\n", d.nome, d.cognome, d.eta, d.peso, d.altezza, d.sesso);
}


void printList(Node **head) {
    Node *aux = *head;

    while(aux) {
        printData(aux->data);
        aux = aux->next;
    }
}



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
    if(isEmpty(*head) || d.eta < (*head)->data.eta) {
        insertHead(head, d);
        return;
    }

    Node *tmp = *head;
    Node *prev = NULL;

    while(tmp != NULL && tmp->data.eta < d.eta) {
        prev = tmp;
        tmp = tmp->next;
    }

    insertAfter(prev, d);
}

void delete(Node **head, Node *node) {
    if(*head == node) {
        Node *tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }

    Node *tmp = *head;
    Node *prev = NULL;

    while(tmp->next && tmp != node) {
        prev = tmp;
        tmp = tmp->next;
    }

    if(tmp && tmp == node) {
        prev->next = tmp->next;
        free(tmp);
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
        fscanf(f, "%s %s %d %d %d %c", d.nome, d.cognome, &d.eta, &d.peso, &d.altezza, &d.sesso);
        if(!feof(f)){
            insertOrdered(head, d);
        }
    }
    fclose(f);

    return head;
}

float imc(Data d) {
    float a = d.altezza/100.0;
    return d.peso/(a*a);
}

Node* getMax(Node *head) {
    Node *aux = head;
    Node *max = head;

    while(aux) {
        if(aux && imc(aux->data)>imc(max->data)) {
            max = aux;
        }
        aux = aux->next;
    }

    return max;
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
        fprintf(f, "%s %s %d %d %d %c\n", d.nome, d.cognome, d.eta, d.peso, d.altezza, d.sesso);
        aux = aux->next;
    }

    fclose(f);
}

int main(int argc, char* argv[]) {
    // PUNTO A
    Parameters p = readInput(argv, argc);

    printf("=======PUNTO A=======\n");
    printf("input = %s, output = %s\n", p.input, p.output);

    // PUNTO B
    Node **A = readFile(p.input);
    printf("\n=======PUNTO B=======\n");
    printList(A);

    // PUNTO C
    Node *max = getMax(*A);
    printf("\n=======PUNTO C=======\n");
    printData(max->data);

    // PUNTO D
    printf("\n=======PUNTO D=======\n");
    Node** B = malloc(sizeof(Node*));
    for (int i=0; i<3; i++){
        Node *max = getMax(*A);
        Data d = max->data;
        delete(A, max);
        insertHead(B, d);
    }

    printf("A:\n");
    printList(A);
    printf("B:\n");
    printList(B);
        
    writeFile(B, p.output);
}