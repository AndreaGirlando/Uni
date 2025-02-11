#include<stdio.h>
#include<time.h>
#define Size 500
int main() {
    srand(time(NULL));

    // while(1){
    //     printf("%d\n", rand());//Questa funzione genera un numero da 0 a rand_max (circa 32K)
    // }
    int i = 0;
    while(i < 100){
        int random = rand();
        int offset = random%100;
        printf("%d - %d\n",random, offset);
        i++;
    }
    // La funzione rand() usata in questo ciclo ritorna numeri da 0 a 99 perchè facendo il modulo 100 di un qualsiasi numeri il resto
    // è compreso tra 0 e 99
    // se vogliamo prendere un'intervallo che va da 0 a 100  basta aggiungere un'offset di 1
}