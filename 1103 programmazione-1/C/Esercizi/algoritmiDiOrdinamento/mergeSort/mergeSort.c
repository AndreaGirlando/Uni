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



    return 0;
}

void printArray(int tempV[dim]){
    printf("\n\n");
    for(int i = 0; i < dim; i++){
        printf("%5d",tempV[i]);
    }
}