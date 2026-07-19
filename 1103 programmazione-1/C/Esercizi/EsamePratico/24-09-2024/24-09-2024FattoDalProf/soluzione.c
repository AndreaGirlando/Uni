#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Nodo della lista concatenata per le stringhe
struct Nodo {
    char *str;
    struct Nodo *next;
};

// Struttura per i parametri di input
struct parametri {
    char *input_filename;
    char *output_filename;
};

// Funzione per controllare e decodificare i parametri
struct parametri decodeParameters(int argc, char *argv[]) {
    struct parametri p;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s input_filename.text output_filename.output\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    p.input_filename = argv[1];
    p.output_filename = argv[2];

    if (strcmp(p.input_filename + strlen(p.input_filename) - 5, ".text") != 0) {
        fprintf(stderr, "Error: input file must have .text extension.\n");
        exit(EXIT_FAILURE);
    }

    if (strcmp(p.output_filename + strlen(p.output_filename) - 7, ".output") != 0) {
        fprintf(stderr, "Error: output file must have .output extension.\n");
        exit(EXIT_FAILURE);
    }

    return p;
}

// Funzione per inserire una stringa nella lista ordinata per lunghezza
struct Nodo *inserisciOrdinato(struct Nodo *head, char *str) {
    struct Nodo *nuovo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nuovo->str = strdup(str);
    nuovo->next = NULL;

    if (!head || strlen(str) < strlen(head->str)) {
        nuovo->next = head;
        return nuovo;
    }

    struct Nodo *current = head;
    while (current->next && strlen(current->next->str) <= strlen(str)) {
        current = current->next;
    }
    nuovo->next = current->next;
    current->next = nuovo;

    return head;
}

// Funzione per leggere il file e creare la lista concatenata
struct Nodo *readFile(FILE *fp) {
    struct Nodo *head = NULL;
    char buffer[256];

    while (fgets(buffer, sizeof(buffer), fp)) {
        buffer[strcspn(buffer, "\n")] = '\0';  // Rimuovi newline
        head = inserisciOrdinato(head, buffer);
    }

    return head;
}

// Funzione per contare il numero di vocali in una stringa
int contaVocali(const char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (strchr("AEIOUaeiou", str[i])) {
            count++;
        }
    }
    return count;
}

// Funzione per ottenere l'array Y con il numero di vocali per stringa
short *getArray(struct Nodo *head, int n) {
    short *Y = (short *)calloc(n, sizeof(short));
    int i = 0;
    while (head) {
        Y[i++] = contaVocali(head->str);
        head = head->next;
    }
    return Y;
}

// Funzione per calcolare la media dell'array Y
double calcolaMedia(short *Y, int n) {
    int somma = 0;
    for (int i = 0; i < n; i++) {
        somma += Y[i];
    }
    return (double)somma / n;
}

// Funzione per rimuovere dalla lista le stringhe con più vocali della media
struct Nodo *filterList(struct Nodo *head, short *Y, double media) {
    struct Nodo *prev = NULL, *current = head;

    int i = 0;
    while (current) {
        if (Y[i] > media) {
            struct Nodo *toDelete = current;
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            current = current->next;
            free(toDelete->str);
            free(toDelete);
        } else {
            prev = current;
            current = current->next;
        }
        i++;
    }

    return head;
}

// Funzione per stampare la lista su un file
void writeToFile(FILE *fp, struct Nodo *head) {
    while (head) {
        fprintf(fp, "%s\n", head->str);
        head = head->next;
    }
}

// Funzione per stampare la lista su standard error
void printToStderr(struct Nodo *head) {
    while (head) {
        fprintf(stderr, "%s\n", head->str);
        head = head->next;
    }
}

int main(int argc, char *argv[]) {
    struct parametri p = decodeParameters(argc, argv);
    
    printf("====== A Stampa Parametri ======\n");
    printf("input_filename = %s\n", p.input_filename);
    printf("output_filename = %s\n", p.output_filename);

    FILE *input_file = fopen(p.input_filename, "r");
    if (!input_file) {
        fprintf(stderr, "Error: cannot open file %s.\n", p.input_filename);
        exit(EXIT_FAILURE);
    }

    struct Nodo *lista = readFile(input_file);
    fclose(input_file);

    int n = 0;
    struct Nodo *temp = lista;
    while (temp) {
        n++;
        temp = temp->next;
    }

    printf("\n====== B Lista ordinata per lunghezza ======\n");
    temp = lista;
    while (temp) {
        printf("%s\n", temp->str);
        temp = temp->next;
    }

    short *Y = getArray(lista, n);
    
    printf("\n====== C Array Y (numero di vocali) ======\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", Y[i]);
    }
    printf("\n");

    double media = calcolaMedia(Y, n);

    lista = filterList(lista, Y, media);

    printf("\n====== D Media di Y e lista dopo filtro ======\n");
    printf("Media di Y: %0.1f\n",media);
    printf("Contenuto di X:\n");
    temp = lista;
    while (temp) {
        printf("%s\n", temp->str);
        temp = temp->next;
    }

    FILE *output_file = fopen(p.output_filename, "w");
    if (!output_file) {
        fprintf(stderr, "Error: cannot open file %s.\n", p.output_filename);
        exit(EXIT_FAILURE);
    }

    writeToFile(output_file, lista);
    fclose(output_file);

    return 0;
}
