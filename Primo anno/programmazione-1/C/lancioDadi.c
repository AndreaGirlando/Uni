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
        // if(sum == 2){
        //     freq[0] = freq[0] + 1;
        // }
        // if(sum == 3){
        //     freq[1] = freq[1] + 1;
        // }
        // if(sum == 4){
        //     freq[2] = freq[2] + 1;
        // }
        // if(sum == 5){
        //     freq[3] = freq[3] + 1;
        // }
        // if(sum == 6){
        //     freq[4] = freq[4] + 1;
        // }
        // if(sum == 7){
        //     freq[5] = freq[5] + 1;
        // }
        // if(sum == 8){
        //     freq[6] = freq[6] + 1;
        // }
        // if(sum == 9){
        //     freq[7] = freq[7] + 1;
        // }
        // if(sum == 10){
        //     freq[8] = freq[8] + 1;
        // }
        // if(sum == 11){
        //     freq[9] = freq[9] + 1;
        // }
        // if(sum == 12){
        //     freq[10] = freq[10] + 1;
        // }
        freq[sum - 2] = freq[sum - 2] + 1;
    }

    for(int i = 0; i < 11; i++){
        printf("Frequenza del numero %2d: %4d\n", i+2, freq[i]);
    }

}

int lanciaDado(){
    return rand()%6 + 1;
}