#include <stdio.h>
main() /* in C */
{
    int n = 0;
    float sum = 0;
    int counter = 0;
    while(n != -1){

        int litri,kilometri = 0;
        printf("Inserisci il numero di litri: ");
        scanf("%d", &litri);

        printf("Inserisci il numero di kilometri: ");
        scanf("%d", &kilometri);

        printf("Consumo: %f", (float)kilometri/litri);
        sum = sum + (float)kilometri/litri;
        counter++;

        printf("\nInserisci -1 se vuoi uscire.");
        scanf("%d", &n);
    }

    printf("Il numero di kilometri al litro medi sono: %f\n", sum/counter);

}