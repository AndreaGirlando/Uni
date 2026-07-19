#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Funzione per generare numeri casuali
unsigned int get_random() {
    static unsigned int m_w = 424242;
    static unsigned int m_z = 242424;
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return (m_z << 16) + m_w;
}

struct parameters {
    int n;
    int m;
};

typedef struct parameters Parameters;


Parameters decodeParameters(int argc, char *argv[]) {
    Parameters p;

    if(argc != 3) {
        fprintf(stderr, "Errore, il numero di parametri deve essere uguale a 2\n");
        exit(-1);
    }

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

    if(p.n<3 || p.n>7 || p.m<3 || p.m>7) {
        fprintf(stderr, "Errore: n e m devono essere compresi tra 3 e 7.\n");
        exit(-1);
    }

    return p;
}

int getInput() {
    int x;
    printf("Inserisci un numero compreso tra 10 e 100:\n");
    scanf("%d", &x);

    if(x<10 || x>100)
        fprintf(stderr, "Errore, numero non compreso tra 10 e 100\n");

    return x;
}

int*** getRandomMatrix(int n, int m, int h) {
    int*** A = calloc(n, sizeof(int**));
    for(int i=0; i<n; i++) {
        A[i] = calloc(m, sizeof(int*));
        for (int j=0; j<m; j++) {
            A[i][j] = malloc(sizeof(int));
            *A[i][j] = get_random()%(h+1);
        }
    }
    return A;
}

int*** printMatrix(int ***A, int n, int m) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(A[i][j])
                printf("%5d",*A[i][j]);
            else
                printf("    *");
        }
        printf("\n");
    }
}

void removeMax(int ***A, int n, int col){
    int max;
    bool init = false;
    int idxmax = -1;
    for(int i=0; i<n; i++) {
        if(A[i][col]) {
            if(!init || max<*A[i][col]) {
                max = *A[i][col];
                idxmax = i;
                init = true;
            }
        }
    }
    if(idxmax>=0) {
        free(A[idxmax][col]);
        A[idxmax][col] = NULL;
    }
}

void modifyMatrix(int*** A, int n, int m) {
    for(int col=0; col<m; col++) { //scorri le colonne
        for(int rep=0; rep<3; rep++)
            removeMax(A, n, col);
    }
}

int rowMinNull(int*** A, int n, int m) {
    int min = m;
    int idxmin = -1;
    for(int i=0; i<n; i++) {
        int numnull = 0;
        for(int j=0; j<m; j++){
            if(!A[i][j])
                numnull++;
        }
        if(numnull<min) {
            min=numnull;
            idxmin=i;
        }
    }

    return idxmin;
}

void printRow(int*** A, int row, int m) {
    for(int i=0; i<m; i++) {
        if(A[row][i])
            printf("%5d",*A[row][i]);
        else
            printf("    *");
    }
}

int main(int argc, char* argv[]) {
    Parameters p = decodeParameters(argc, argv);
    printf("Punto A - Parametri inseriti: n=%d, m=%d\n", p.n, p.m);
    
    int h = getInput();

    printf("\nPunto B - Contenuto di A:\n");
    int*** A = getRandomMatrix(p.n, p.m, h);
    printMatrix(A, p.n, p.m);

    printf("\nPunto C - Contenuto di A dopo la modifica:\n");

    modifyMatrix(A, p.n, p.m);
    printMatrix(A, p.n, p.m);

    printf("\nPunto D - Riga con minor numero di NULL:\n");
    int row = rowMinNull(A, p.n, p.m);
    printRow(A, row, p.m);
    printf("\n");
}
