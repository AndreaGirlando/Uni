#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    ? char *strcpy(char *s1, const char *s2)
        * copia la stringa s2 nell’array s1. Viene restituito il valore di s1.
    ? char *strncpy(char *s1, const char *s2, size_t n)
        * copia al massimo n caratteri della stringa s2 nell’array s1 e restituisce s1.
    ? char *strcat(char *s1, const char *s2)
        * Aggiunge la stringa s2 in coda alla stringa contenuta nell’array s1. Il
        * primo carattere di s2 sovrascrive il carattere nullo di terminazione di
        * s1. Viene restituito il valore di s1.
    ? char *strncat(char *s1, const char *s2)
        * Aggiunge al massimo n caratteri della stringa s2 in coda alla stringa
        * contenuta nell’array s1. Il primo carattere di s2 sovrascrive il
        * carattere nullo di terminazione di s1.
    ? int strcmp(const char *s1, const char *s2);
        * Confronta la stringa s1 con la stringa s2.
        * La funzione restituisce 0 se le stringhe sono uguali
    ? int strncmp(const char *s1, const char *s2, size_t n)
        * Confronta fino a n caratteri della stringa s1 con la stringa s2.
        * La funzione restituisce 0 se le stringhe sono uguali
*/
int main(){
    system("cls");


    char x[] = "Test123456"; // inizializza l'array x di char
    char y[15];
    char z[5];

    strcpy(y, x); //? Copia x in y
    printf("%s\n",y);

    strncpy(z, x, 5); //? Copia i primi 5 caratteri di x dentro z
    z[5-1] = '\0';//? Questo serve per indicare dove finisce la stringa
    printf("%s",z);

    printf("\n<------------------------------------------>\n",y);

    char string1[] = "Ciao";
    char string2[] = " a tutti";

    char finalString[30] = "";

    //? In queste 2 righe con strcat concateno entrambe le stringhe dentro finalString
    strcat(finalString, string1);
    strcat(finalString, string2);

    printf("Prima stringa: %s\n",string1);
    printf("Seconda stringa: %s\n",string2);
    printf("\nStringhe concatenate: %s", finalString);

    //? In queste 2 righe con strcat concateno entrambe le stringhe dentro finalString
    //? Prendo solo le prime 3 lettere di ogni stringa
    char finalString2[30] = "";
    strncat(finalString2, string1,3);
    strncat(finalString2, string2,3);

    printf("Prima stringa: %s\n",string1);
    printf("Seconda stringa: %s\n",string2);
    printf("\nStringhe concatenate: %s", finalString2);

    printf("\n<------------------------------------------>\n",y);

    const char *s1 = "Happy New Year";
    const char *s2 = "Happy New Year";
    const char *s3 = "Ciao";

    printf("strcmp(s1,s2): %d\n", strcmp(s1,s2));
    printf("strcmp(s1,s3): %d\n", strcmp(s1,s3));
    printf("strcmp(s1,s2,3): %d\n", strncmp(s1,s2,3));
    printf("strcmp(s1,s3,3): %d\n", strncmp(s1,s3,3));

    printf("Errore: %s\n", strerror( 2 ));

}