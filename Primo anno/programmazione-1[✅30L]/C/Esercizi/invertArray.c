#include <stdio.h>
#include <math.h>
#include <time.h>
int main()
{
    int n = 3;
    int V[4] = {5,7,23,11};
    int reversedV[4];

    for(int i = 0; i <= n; i++){
        reversedV[i] = V[n-i];
        printf("%d\n", reversedV[i]);
    }

    int somma = 0;
    for(int i = 0; i <= n; i++){
        somma += reversedV[i];
    }
    printf("\n\nLa somma è: %d", somma);

}