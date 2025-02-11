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

    for(int i = 0; i < dim;i++){
        for(int j = 0; j < dim-1; j++){
            if(array[i] > array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    printArray(array);
    return 0;
}

void printArray(int tempV[dim]){
    printf("\n\n");
    for(int i = 0; i < dim; i++){
        printf("%5d",tempV[i]);
    }
}