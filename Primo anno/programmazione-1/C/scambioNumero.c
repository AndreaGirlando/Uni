#include <stdio.h>
#include <math.h>
int main()
{
    int numero = 0;

    printf("Inserisci un numero:");
    scanf("%d",&numero);

    printf("\nNumero con le cifre invertite: ");

    int resto = 0;

    while(numero > 0){

        resto = numero % 10;
        numero = numero / 10;
        printf("%d", resto);
        // printf("\nResto: %d e quoziente: %.1f",resto, (float)numero / 10);
    }

    printf("\n");
    return 0;
}