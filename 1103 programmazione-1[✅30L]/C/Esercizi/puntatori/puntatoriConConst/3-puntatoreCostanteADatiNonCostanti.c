#include <stdio.h>
#include <ctype.h>

/*
    ? In questo file troviamo un'esempio di funzione che usa un puntatore costante a dati non costanti
    * Il valore puntato da 'ptr' non può cambiare
    * il valore contenuto dentro la locazione di memoria puntata da 'ptr' può cambiare
    * 'int * const ptr' si legge 'un puntatore costante ad int'
*/

int main(){

    int x = 5;
    int y = 7;
    int * const ptr = &x;
    *ptr = 500; //* Questa è un'operazione permessa perchè il valore puntato da ptr può cambiare
    ptr = &y; //! Errore: il valore del puntatore non può cambiare

    return 0;
}