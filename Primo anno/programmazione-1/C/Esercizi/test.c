#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define nElementi 5
void printArray(int array[]);
int main(){
    srand(time(NULL));
    system("clear");

    //? void* malloc(size_t size);
    int* array = (int*) malloc(nElementi * sizeof(int));

    printf("Stampo il vettore allocato con malloc (dimensione: %d byte): \n", nElementi * sizeof(int));
    printArray(array);

    free(array);


    //? void* calloc(size_t num, size_t size);
    array = (int*) calloc(nElementi,sizeof(int));
    printf("\n\nStampo il vettore allocato con calloc (dimensione: %d byte): \n", nElementi * sizeof(int));
    for(int i = 0; i<nElementi; i++){
        array[i] = rand()%nElementi + 15;
    }
    printArray(array);

    //? void* realloc(void* ptr, size_t size);
    array = (int*)realloc(array, 3 * sizeof(int));
    //! Qualsiasi sia la dimensione dell'array lo sto facendo diventare di 3 elementi
    printf("\n\nStampo il vettore reallocato con realloc (dimensione: %d byte): \n", 3 * sizeof(int));
    printArray(array);

    printf("\n\n\n");
    return 0;
}

void printArray(int array[]){
    for(int i = 0; i < nElementi; i++){
        printf("array[%d] = %4d \n", i,array[i]);
    }
}