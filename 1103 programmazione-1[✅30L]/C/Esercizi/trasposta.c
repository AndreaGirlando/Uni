#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define row 5
#define col 5
#define maxRandom 20
int setMatriceTrasposta(int m[row][col],int mTrasposta[row][col]);
int generaMatrice(int m[row][col]);
void stampaMatrice(int m[row][col]);

int main(){
    srand(time(NULL));
    int matrice[row][col] = {0};
    int mTrasposta[row][col] = {0};

    generaMatrice(matrice);

    printf("Matrice normale:");
    stampaMatrice(matrice);

    setMatriceTrasposta(matrice,mTrasposta);

    printf("Matrice trasposta:");
    stampaMatrice(mTrasposta);

    return 0;
}

int setMatriceTrasposta(int m[row][col], int mTrasposta[row][col]){
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            mTrasposta[i][j] = m[j][i];
        }
    }
}

int generaMatrice(int m[row][col]){
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            m[i][j] = rand()%maxRandom + 1;
        }
    }
}

void stampaMatrice(int m[row][col]){
    printf("\n");
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            printf("%5d", m[i][j]);
        }
        printf("\n");
    }
}