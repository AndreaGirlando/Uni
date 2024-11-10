#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define dimArray 10
#define maxArray 100
void stampaArray(int a[], int n);
main(){
    srand(time(NULL));
    // system("cls");
    int array[dimArray] = {0};

    for(int i = 0; i < dimArray; i++){
        array[i] = rand()%maxArray + 1;
    }

    printf("Array generato: ");
    stampaArray(array,dimArray);

    for(int i = 0; i < dimArray; i++){
        for(int j = 0; j<dimArray; j++){

            if(array[j]%10 > array[j+1]%10){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    printf("Array ordinato: ");
    stampaArray(array,dimArray);

}

void stampaArray(int a[], int n){
    printf("\n");
    for(int i = 0; i<n;i++){
        printf("%6d", a[i]);
    }
    printf("\n");
}