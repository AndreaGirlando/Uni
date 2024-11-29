#include <stdio.h>
#include <ctype.h>

/*
    ? In questo file troviamo un'esempio di funzione che usa un puntatore non costante a dati costanti
    * Il valore puntato da 'stringPtr' può cambiare
    * il valore contenuto dentro la locazione di memoria puntata da 'stringPtr' non può cambiare
    * 'const char *stringPtr' si legge "stringPtr è un puntatore ad un char costante"
    * La funzione 'createErrore' cerca di modificare il valore e non ci riesce generando un'errore
    ! Questa tipo di passaggio a funzione lo usiamo quando dobbiamo elaborare ogni singolo elemento -->
    ! --> che passiamo e dobbiamo essere sicuri che l'elemento sorgente non cambi
*/

void printString(const char *stringPtr);
void createErrore(const int *xPtr);
int main(){

    char string[] = "stringa 123";
    int y;

    printString(string);
    createErrore(&y);
    return 0;
}
void printString(const char *stringPtr){
    while(*stringPtr != '\0'){
        printf("%c", *stringPtr*5);
        ++stringPtr;
    }
}
//? xPtr non puo' essere usato per modificare il valore della variabile alla quale punta
void createErrore(const int *xPtr)
{
    //! L'errore lo da in fase di compilazione, quindi se vuoi vuoi usare questo script commenta la riga sottostante
    *xPtr = 100; // errore: non si puo' modificare un oggetto const
}