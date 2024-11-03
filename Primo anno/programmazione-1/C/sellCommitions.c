#include <stdio.h>
#include <stdlib.h>
int main() /* in C */
{
    int nAgenti = 0;
    float percentuale = 0.09;
    int fasce[10] = {0,0,0,0,0,0,0,0,0,0};
    printf("Di quanti agenti vuoi calcolare le commissioni?");
    scanf("%d", &nAgenti);

    system("cls");

    int i = 0;
    while(i<nAgenti){

        int lordo = 0;
        printf("\n<---------------------->\n");
        printf("\n\nInserisci il suo introito settimanale lordo: ");
        scanf("%d", &lordo);

        int stipendio = (lordo*percentuale) + 200;
        int index = stipendio/100;
        if(index > 9){
            index = 9;
        }
        printf("\nLo stipendio finale di questo agente e': %d", stipendio);
        printf("\n\n%d", index);
        fasce[ index ] = fasce[ index ] + 1;

        i++;
    }
    system("cls");
    printf("\nDi seguito il numero di dipendenti per fascia: ");
    printf("meno di 200: %d\n", fasce[0]);
    printf("200-299: %d\n", fasce[1]);
    printf("300-399: %d\n", fasce[2]);
    printf("400-499: %d\n", fasce[3]);
    printf("500-599: %d\n", fasce[4]);
    printf("600-699: %d\n", fasce[5]);
    printf("700-799: %d\n", fasce[6]);
    printf("800-899: %d\n", fasce[7]);
    printf("900-999: %d\n", fasce[8]);
    printf("oltre 1000: %d\n", fasce[9]);


    return 0;
}
