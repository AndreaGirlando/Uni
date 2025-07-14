#include <stdio.h>
#define size 10
void bubbleSort(int array[], int dimensioneArray);
void swap(int *element1, int *element2);
/*
    * Di seguito vediamo l'utilizzo dell'algoritmo bubble sort
    * swappando i dati nelle posizioni giuste usando la funzione swap
    ? La funzione swap, swappa il valore dei 2 elementi passati per riferimento senza conoscere l'esistenza dell'array

*/
int main(){

    int a[size] = {1,7,9,11,23,15,88,2,5,0};

    bubbleSort(a, size);

    printf("\n\nArray ordinato: ");
    for(int i=0;i<size;i++){
        printf("%4d", a[i]);
    }
    return 0;
}
//? Dichiariamo in modo const il puntatore all'array per essere sicuri che il suo valore non cambi mai
void bubbleSort(int * const array, int dimensioneArray){

    for(int i = 0; i<size;i++){
        for(int j = 0; j<size; j++){
            if(array[i] < array[j]){
                swap(&array[i],&array[j]);
            }
        }
    }
}

void swap(int *element1, int *element2){
    int hold = *element1;
    *element1 = *element2;
    *element2 = hold;
}