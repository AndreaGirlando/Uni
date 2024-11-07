#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define numeroLanci 36000
int lanciaDado();
int main() /* in C */
{

    int freq[11] = {0,0,0,0,0,0,0,0,0,0,0};
    srand(time(NULL));
    for(int i = 0;i < numeroLanci; i++){
        int sum = lanciaDado()+lanciaDado();
        freq[sum - 2] = freq[sum - 2] + 1;
    }

    for(int i = 0; i < 11; i++){
        printf("Frequenza del numero %2d: %4d\n", i+2, freq[i]);
    }

}

int lanciaDado(){
    return rand()%6 + 1;
}