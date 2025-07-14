#include <stdio.h>
#include <math.h>
#include <time.h>
int main()
{
    srand(time(NULL));
    int guess = 0;
    char reboot = 'S';

    while(reboot == 'S'){
        int n = 1 + rand()%1000;
        printf("Ho scelto un numero casuale!%d", n);
        do{
            printf("\nInserisci qui la tua scelta: ");
            scanf("%d", &guess);
            if(guess > n){
                printf("\nIl numero è troppo alto");
            }
            if(guess < n){
                printf("\nIl numero è troppo basso");
            }
        }while(guess != n);
        printf("Il numero inserito è corretto!");
        printf("Vuoi continuare a giocare? S => Si,  N => No\n\n");
        scanf(" %c", &reboot);
    }

}