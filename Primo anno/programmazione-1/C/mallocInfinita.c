#include <stdio.h>
#include <stdlib.h>
//! Il ciclo sottostante alloca un sacco di memoria in giro di 5 secondi satura la RAM
int main () {

    while(1){
        int* array1 = (int*)malloc(8000 * sizeof(int));
    }




}
