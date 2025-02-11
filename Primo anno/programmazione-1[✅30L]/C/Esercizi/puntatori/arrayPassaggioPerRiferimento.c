#include <stdio.h>
#include <stdlib.h>
void modifyArrayByReference(int *arrayPtr, int elementiDaModificare);
int main(){
    system("cls");

    int array[3] = {1,2,3};
    printf("Array prima della modifica: \n");
    for(int i = 0; i < 3; i++){
        printf("%4d", array[i]);
    }

    modifyArrayByReference(array, 3);

    printf("\nArray dopo la modifica:\n");
    for(int i = 0; i < 3; i++){
        printf("%4d", array[i]);
    }

}
void modifyArrayByReference(int *arrayPtr, int elementiDaModificare){
    for(int i = 0; i < elementiDaModificare; i++){
        arrayPtr[i] = arrayPtr[i] * 5;
    }
}