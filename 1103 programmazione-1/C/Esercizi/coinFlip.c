#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define numeroCicli 1000000
int coinFlip();
int main() /* in C */
{
    srand(time(NULL));
    int testa = 0;
    int croce = 0;
    for(int i = 0; i<numeroCicli ;i++){
        int flip = coinFlip();
        if(flip == 1){
            testa++;
        }
        else{
            croce++;
        }
    }
    system("cls");
    printf("Testa: %4d, Croce: %8d", testa, croce);

    return 0;
}
int coinFlip(){
    return rand()%2;
}
