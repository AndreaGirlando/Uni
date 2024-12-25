#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define dim 10

void printArray(int tempV[dim]);

int main(){
    srand(time(NULL));
    int array[dim];
    for(int i = 0; i < dim; i++){
        array[i] = rand() % 100 + 1;
    }

    printArray(array);

    for (int i = 1; i < dim; i++){
        int j = i - 1;
        int temp = array[i];

        while (j >= 0 && array[j] > temp)
        {
            array[j + 1] = array[j]; //Sposta l'elemento più grande verso destra
            j--;
        }

        // Inserisce temp nella posizione corretta più a sinistra possibile
        array[j + 1] = temp;

        printArray(array);
    }

    return 0;
}

void printArray(int tempV[dim]){
    printf("\n\n");
    for(int i = 0; i < dim; i++){
        printf("%5d",tempV[i]);
    }
}