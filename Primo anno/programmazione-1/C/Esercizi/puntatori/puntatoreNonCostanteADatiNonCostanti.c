#include <stdio.h>
#include <ctype.h>

/*
    ? In questo file troviamo un'esempio di funzione che usa un puntatore non costante a dati non costanti
    * Il valore puntato da 'stringPtr' può cambiare
    * Anche il valore contenuto dentro l'array 'string' può essere cambiato
    ! Questo è un semplice passaggio per riferimento ad una funzione di un vettore (in questo caso un vettore di char)
*/

void convertToUpperCase(char *stringPtr);
main(){

    char string[] = "stringa 123";

    printf("\nStringa normale: %s", string);
    convertToUpperCase(string);
    printf("\nStringa maiuscola: %s", string);

}
void convertToUpperCase(char *stringPtr){
    while(*stringPtr != '\0'){
        *stringPtr = toupper(*stringPtr);
        ++stringPtr;
    }
}