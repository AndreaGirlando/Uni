#include <stdio.h>
int celleAdiacenti(int matr[5][5],int m,int n,int i,int j);
int main() /* in C */
{
    int matrice[5][5] = {{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};

    //? Gli indici i,j da scrivere vanno scritti in forma vettoriale(togliendo 1 dall'indice reale)
    printf("Il numero delle celle adiacenti e': %d",celleAdiacenti(matrice,5,5,1,1));

    return 0;
}

int celleAdiacenti(int matr[5][5],int m,int n,int i,int j){
    int numeroCelle = 0;
    for(int h = 0; h < m; h++){
        for(int k = 0; k < n; k++){
            if(h >= i-1 && h <= i+1 && k >= j-1 && k <= j+1 && !(h == i && k == j)){
                if(matr[h][k] > 0){
                    printf("Cella adiacente in %d-%d\n", h,k);
                    numeroCelle++;
                }
            }
        }
        printf("\n");
    }
    return numeroCelle;
}