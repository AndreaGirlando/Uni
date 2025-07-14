#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(){
    /*
        *Di seguito introduciamo l'utilizzo della libreria ctype.h per la manipolazione dei caratteri
        ? Quasi tutti i metodi di qeusta funzione verificano qualcosa del nostro carattere
        ? Tutte prendono in input un unsigned int (che sarebbe il tipo char)
    */
    system("cls");
    char carattere = 'a';//! i caratteri vanno specificati tra singoli apici

    printf("\nRestituisce un valore vero se il carattere e' vuoto: %d", isblank(carattere));
    printf("\nRestituisce un valore vero se il carattere e' una cifra: %d", isdigit(carattere));
    printf("\nRestituisce un valore vero se il carattere e' una lettera: %d", isalpha(carattere));
    printf("\nRestituisce un valore vero se il carattere e' in minuscolo: %d", islower(carattere));
    printf("\nRestituisce un valore vero se il carattere e' in maiuscolo: %d", isupper(carattere));
    printf("\nRestituisce il carattere in maiuscolo: %c", toupper(carattere));
    printf("\nRestituisce il carattere in minuscolo: %c", tolower(carattere));
    //? La funzione ritorna sempre un int ma cambiando il segnaposto questo verra converito
    //* Tutte le funzioni le trovi qua: https://devdocs.io/c/string/byte
}