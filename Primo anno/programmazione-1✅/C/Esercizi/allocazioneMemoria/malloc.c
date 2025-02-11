#include <stdlib.h>
#define size 100
int main(){

    //? Dichiarazione di un array
    int *array = calloc(size, sizeof(int));

    for(int i = 0; i < size; i++){
        printf("%4d", array[i]);
    }
    free(array);
    //? Dichiarazione di una matrice allocata dinamicamente
    //* Dichiaro un puntatore a puntatori
    int **matrix = calloc(size, sizeof(int*));
    for(int i = 0; i < size; i++){
        //*Per ogni puntatore alloco un vettore
        matrix[i] = calloc(size, sizeof(int));
    }

    printf("\n\n\n\n\n\n");
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < size; i++){
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}