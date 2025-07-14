#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Definizione della struttura Persona
typedef struct {
    char nome[50];
    char cognome[50];
    int eta;
    float altezza;
} Persona;

// Funzione per decodificare i parametri da riga di comando
void decodeParameters(int argc, char *argv[], char **input_filename, char **output_filename) {
    if (argc != 3) {
        fprintf(stderr, "Errore: numero di parametri errato. Uso: ./soluzione input.txt output.txt\n");
        exit(EXIT_FAILURE);
    }

    *input_filename = argv[1];
    *output_filename = argv[2];

    size_t len_input = strlen(*input_filename);
    size_t len_output = strlen(*output_filename);

    if ((len_input < 4 || strcmp(*input_filename + len_input - 4, ".txt") != 0) ||
        (len_output < 4 || strcmp(*output_filename + len_output - 4, ".txt") != 0)) {
        fprintf(stderr, "Errore: i file devono avere estensione .txt\n");
        exit(EXIT_FAILURE);
    }
}

// Funzione per leggere il valore n dalla prima riga del file
int readHeader(FILE *file) {
    int n;
    // Legge un intero dalla prima riga del file e lo memorizza in 'n'
    if (fscanf(file, "%d\n", &n) != 1) {
        // Se la lettura fallisce, stampa un messaggio di errore e termina il programma
        fprintf(stderr, "Errore: impossibile leggere il numero di righe dal file\n");
        exit(EXIT_FAILURE);
    }
    // Restituisce il valore letto
    return n;
}

// Funzione per leggere i dati dal file e popolare l'array di strutture Persona
Persona *readFile(FILE *file, int n) {
    Persona *array = malloc(n * sizeof(Persona));
    if (!array) {
        fprintf(stderr, "Errore: memoria insufficiente\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        if (fscanf(file, "%s %s %d %f\n", array[i].nome, array[i].cognome, &array[i].eta, &array[i].altezza) != 4) {
            fprintf(stderr, "Errore: formato non valido nel file di input\n");
            free(array);
            exit(EXIT_FAILURE);
        }
    }
    return array;
}

// Funzione per estrarre le età e creare l'array Z
int *extractAges(Persona *array, int n) {
    int *Z = malloc(n * sizeof(int));
    if (!Z) {
        fprintf(stderr, "Errore: memoria insufficiente\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        Z[i] = array[i].eta;
    }
    return Z;
}

// Funzione per ordinare un array di interi (es. bubble sort)
void sortArray(int *array, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Funzione per calcolare l'altezza media delle persone con età > mediana
float calculateAverageHeight(Persona *array, int n, int mediana) {
    float somma = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (array[i].eta > mediana) {
            somma += array[i].altezza;
            count++;
        }
    }

    if (count == 0) return 0;
    return somma / count;
}

// Funzione per scrivere le persone con altezza > media su file di output
void writeOutput(FILE *file, Persona *array, int n, float media) {
    for (int i = 0; i < n; i++) {
        if (array[i].altezza > media) {
            fprintf(file, "%s %s, Et\u00e0: %d, Altezza: %.2f\n", array[i].nome, array[i].cognome, array[i].eta, array[i].altezza);
        }
    }
}

int main(int argc, char *argv[]) {
    char *input_filename, *output_filename;
    decodeParameters(argc, argv, &input_filename, &output_filename);

    // Stampa dei parametri ricevuti
    printf("======A Stampa Parametri======\n");
    printf("input_filename = %s\n", input_filename);
    printf("output_filename = %s\n\n", output_filename);

    // Apertura del file di input
    FILE *input_file = fopen(input_filename, "r");
    if (!input_file) {
        fprintf(stderr, "Errore: impossibile aprire il file di input %s\n", input_filename);
        exit(EXIT_FAILURE);
    }

    // Lettura dell'header
    int n = readHeader(input_file);

    // Lettura dei dati dal file
    Persona *array = readFile(input_file, n);
    fclose(input_file);

    // Stampa delle strutture lette
    printf("======B Contenuto dell'array di strutture======\n");
    for (int i = 0; i < n; i++) {
        printf("%d. Nome: %s, Cognome: %s, Età: %d, Altezza: %.2f\n", i + 1, array[i].nome, array[i].cognome, array[i].eta, array[i].altezza);
    }

    // Creazione dell'array Z (età)
    int *Z = extractAges(array, n);

    // Stampa dell'array Z prima dell'ordinamento
    printf("\n======C Array Z (età======\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", Z[i]);
    }
    printf("\n");

    // Ordinamento dell'array Z e calcolo della mediana
    sortArray(Z, n);
    printf("\n======C Array Z Ordinato======\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", Z[i]);
    }
    printf("\n\nMediana delle età: %d\n", Z[n / 2]);

    // Calcolo dell'altezza media
    float media = calculateAverageHeight(array, n, Z[n / 2]);
    printf("\n======D Altezza media delle persone con età superiore alla mediana======\n");
    printf("Media: %.2f\n", media);

    // Apertura del file di output
    FILE *output_file = fopen(output_filename, "w");
    if (!output_file) {
        fprintf(stderr, "Errore: impossibile creare il file di output %s\n", output_filename);
        free(array);
        free(Z);
        exit(EXIT_FAILURE);
    }

    // Scrittura delle persone con altezza > media su file
    writeOutput(output_file, array, n, media);
    fclose(output_file);
    printf("\n======E Scrittura su file %s======\nFile scritto correttamente.\n", output_filename);

    // Deallocazione della memoria
    free(array);
    free(Z);

    return 0;
}
