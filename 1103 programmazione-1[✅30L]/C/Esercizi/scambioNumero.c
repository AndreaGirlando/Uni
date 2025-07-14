#include <stdio.h>
#include <math.h>
int main()
{
    int numero = 0;
    int reverseNumber(int numero);

    printf("Inserisci un numero:");
    scanf("%d",&numero);


    printf("\nNumero con le cifre invertite: %d\n", reverseNumber(numero));

    return 0;
}

int reverseNumber(int numero){
    int resto = 0;
    int reverse = 0;
    while(numero > 0){
        resto = numero % 10;
        numero = numero / 10;
        reverse = reverse * 10 + resto;
    }
    return reverse;
}