#include <stdio.h>
#include <ctype.h>

/*
    ? In questo file troviamo un'esempio di funzione che usa un puntatore costante a dati costanti
    * Il valore puntato da 'ptr' non può cambiare
    * il valore contenuto dentro la locazione di memoria puntata da 'ptr' non può cambiare
    * 'const int * const ptr' si legge 'un puntatore costante ad un intero costante'
*/

int main(){

    int x = 5;
    int y = 7;
    const int * const ptr = &x;
    *ptr = 500; //! Errore: il valore puntato non può cambiare
    ptr = &y; //! Errore: il valore del puntatore non può cambiare

    return 0;
}