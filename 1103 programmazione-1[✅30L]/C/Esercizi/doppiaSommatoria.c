#include<stdio.h>
int main() {

    int k = 0;
    printf("\nInserisci K:");
    scanf("%d", &k);

    while(k<0){
        printf("Inserisci un numero positivo\n");
        printf("\nInserisci K:");
        scanf("%d", &k);
    }

    int i = 1;
    int j = 0;
    double y = 0;
    double sommaInterna = 0;
    while( i <= k ){
        j = 1;
        sommaInterna = 0;
        while( j<=i ){
            sommaInterna = sommaInterna + (1 / (double)(i+j));
            //Si puo scommentare questa riga per vedere il cambiamento di y ad ogni ciclo
            // printf("i:%d j:%d sommaInterna:%f  \n",i,j,sommaInterna);
            j++;
        }
        sommaInterna = sommaInterna * sommaInterna;
        y = y + sommaInterna;
        i++;
    }

    printf("\n\nLa sommatoria e': %f\n", y);

}
