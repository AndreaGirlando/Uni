#include <stdio.h>
#include <stdlib.h>
int main(){
    system("cls");
    char string[] = "Questa e' una stringa";
    char *stringPtr = "Questa e' una stringa";
    printf("%s \n", string);
    printf("%s \n", stringPtr);

    char word[20];
    printf("\nInserisci una stringa: ");
    //? non abbiamo bisogno di mettere & perchè word è gia un indirizzo
    //scanf("%20s",word);
    //* Questa istruzione di scanf metterà dentro l'array word una stringa lunga 20 caratteri
    //* Indipedentemente da quanti caratteri l'utente inserisce
    //! scanf legge i caratteri finché non incontra uno spazio, una tabulazione, un newline o l’indicatore della fine del file

    printf("\n<-------------------------------------------->\n");

    //? Di seguito altre funzioni di base con le stringhe

    puts("Ciao");

    char carattere = 'c';
    int parsedChar = putchar(carattere);
    printf("\nCarattere in int: %d", parsedChar);

    printf("\n<-------------------------------------------->\n");




}