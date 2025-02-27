#include <stdio.h>
void cubeByReference(int *nPtr);
int main(){

    int n = 5;
    printf("Il valore iniziale di n: %d" ,n);
    cubeByReference(&n);
    printf("\nIl valore finale di n: %d" ,n);


    return 0;
}
void cubeByReference(int *nPtr){
    *nPtr = *nPtr * *nPtr;
}