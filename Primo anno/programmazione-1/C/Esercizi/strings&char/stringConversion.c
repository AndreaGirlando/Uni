#include <stdio.h>
#include <stdlib.h>
/*
    ? Di seguito introduciamo la conversione di stringhe con numeri in numeri utilizzabili in operazioni
    ? Sono 3 le funzioni che ci permettono di fare questa cosa:
    * double strtod(const char *nPtr, char **endPtr);
        ? Questa funzione prende in input una stringa (ptr) e se prima del primo spazio c'è un numero lo ritorna in double
        ? Se la prima parte della stringa non è un numero questo funzione ritorna 0
        ? Dentro **endPtr troviamo la parte di stringa rimanente
    * long strtol(const char *nPtr, char **endPtr, int base);
        ? Questa funzione prende in input una stringa (ptr) e se prima del primo spazio c'è un numero lo ritorna in long
        ? Se la prima parte della stringa non è un numero questo funzione ritorna 0
        ? Dentro **endPtr troviamo la parte di stringa rimanente
    * unsigned long strtoul(const char *nPtr, char **endPtr, int base);
        ? Questa funzione prende in input una stringa (ptr) e se prima del primo spazio c'è un numero lo ritorna in unsigned long quindi
        ? quindi ingorando il segno
        ? Se la prima parte della stringa non è un numero questo funzione ritorna 0
        ? Dentro **endPtr troviamo la parte di stringa rimanente
*/
int main(){
    system("cls");
    char *string = "25.27 euro nel tuo wallet";
    char *stringGarbage;

    printf("<--------------------------------------------->\n");
    double numeroDouble = strtod(string, &stringGarbage);
    printf("%f\n", numeroDouble);
    printf("%s", stringGarbage);

    printf("\n<--------------------------------------------->\n");

    char *stringLong = "-1234567abc";
    long numeroLong = strtod(stringLong, &stringGarbage);
    printf("%ld\n", numeroLong);
    printf("%s", stringGarbage);

    printf("\n<--------------------------------------------->\n");

    char *stringUnsignedLong = "1234567abc";
    unsigned long int numeroUnsignedLong = strtoul(stringUnsignedLong, &stringGarbage, 0);
    printf("%lu\n", numeroUnsignedLong);
    printf("%s", stringGarbage);

    printf("\n<--------------------------------------------->\n");
}