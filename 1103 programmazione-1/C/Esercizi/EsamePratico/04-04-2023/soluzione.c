#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_N 7
#define MIN_N 3
#define MAX_M 7
#define MIN_M 3

struct parametri {
    int n;
    int m;
    char* filename;
};

struct parametri decodeParameters(int argc, char *argv[]) {
    struct parametri p;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s n m file.txt\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    p.n = atoi(argv[1]);
    p.m = atoi(argv[2]);

    char *end;
    p.n = (int) strtol(argv[1], &end, 10);

    if(*end) {
        fprintf(stderr, "Errore: n non è un intero valido.\n");
        exit(-1);
    }

    p.m = (int) strtol(argv[2], &end, 10);

    if(*end) {
        fprintf(stderr, "Errore: m non è un intero valido.\n");
        exit(-1);
    }

    p.filename = argv[3];

    if (p.n < MIN_N || p.n > MAX_N || p.m < MIN_M || p.m > MAX_M) {
        fprintf(stderr, "Error: n and m must be integers between %d and %d.\n", MIN_N, MAX_N);
        exit(EXIT_FAILURE);
    }

    if (strcmp(p.filename + strlen(p.filename) - 4, ".txt") != 0) {
        fprintf(stderr, "Error: file must have .txt extension.\n");
        exit(EXIT_FAILURE);
    }

    return p;
}

void printParameters(struct parametri p) {
    printf("======Stampa Parametri======\n");
    printf("n = %d\n", p.n);
    printf("m = %d\n", p.m);
    printf("filename = %s\n", p.filename);
    puts("\n");
}

double **readFile(char *filename, int n, int m) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: cannot open file %s.\n", filename);
        exit(EXIT_FAILURE);
    }
    
    double **X = (double**) malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        X[i] = (double*) malloc(m * sizeof(double));
        for (int j = 0; j < m; j++) {
            fscanf(fp, "%lf,", &X[i][j]);
        }
    }
    fclose(fp);

    return X;
}

void printMatrix(double **X, int n, int m, const char *name) {
    printf("======Stampa %s======\n", name);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%5.2f ", X[i][j]);
        }
        printf("\n");
    }
    puts("\n");
}

int* getArray(double **X, int n, int m) {
    int *Y = (int*) calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) { //righe
        double q = 0;
        double max = INT_MIN;
        double min = INT_MAX;
        for (int j=0; j<m; j++) {
            q += X[i][j];
            if(X[i][j]<min)
                min=X[i][j];
            if(X[i][j]>max)
                max=X[i][j];
        }
        q = q/m;

        float a = q - (max-min)*0.3;
        float b = q + (max-min)*0.3;
        Y[i] = 0;
        for (int j = 0; j < m; j++) {
            if (X[i][j] > a && X[i][j] < b) {
                Y[i] += 1;
            }
        }
    }
    return Y;
}

void printArray(int *array, int n, const char *name) {
    printf("======Stampa %s======\n", name);
    for(int i=0; i<n; i++) {
        printf("%d ", array[i]);
    }
    puts("\n");
}

void insertionSort(int *Y, int n) {
    // insertion sort
    for (int i = 1; i < n; i++) {
        int key = Y[i];
        int j = i - 1;

        while (j >= 0 && Y[j] > key) {
            Y[j + 1] = Y[j];
            j--;
        }
        Y[j + 1] = key;
    }
}

int *getCumulative(int *Y, int n) {
    int *Z = (int*) malloc(n * sizeof(int));
    Z[0] = Y[0];
    for (int i = 1; i < n; i++) {
        Z[i] = Z[i - 1] + Y[i];
    }

    return Z;
}

int main(int argc, char *argv[]) {
    struct parametri p = decodeParameters(argc, argv);
    printParameters(p);
    
    double **X = readFile(p.filename, p.n, p.m);
    printMatrix(X, p.n, p.m, "X");

    int *Y = getArray(X, p.n, p.m);
    printArray(Y, p.n, "Y");

    insertionSort(Y, p.n);
    printArray(Y, p.n, "Y ordinato");

    int *Z = getCumulative(Y, p.n);
    printArray(Z, p.n, "Z");
}
