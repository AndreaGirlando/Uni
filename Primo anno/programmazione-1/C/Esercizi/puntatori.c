#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define len 10
int main()
{
    srand(time(NULL));
    system("cls");
    int y = 12458;

    //! Dichiariamo i puntatori mettendo un * prima del nome della variabile,
    //! per inserire un valore vuoto dentro ad un puntatore usiamo NULL
    //? L'istruzione sottostante dichiara un puntatore inizializzandolo a NULL
    int *genericPtr = NULL;

    //! Con l'operando & indichiamo l'indirizzo di memoria di una variabile
    //? L'istruzione sottostante dichiara un puntatore inizializzando il suo valore con l'indirizzo della variabile y
    int *yPtr = &y;

    //! Per stampare un'indirizzo usiamo il segnaposto %p
    //? L'istruzione sottostante stampa 'La variabile y con il valore 12458 si trova nell'indirizzo 0061FF14'
    printf("\n\nLa variabile y con il valore %d si trova nell'indirizzo %p",y,yPtr);
    //? La stessa cosa poteva essere scritta in questo modo
    printf("\n\nLa variabile y con il valore %d si trova nell'indirizzo %p",y,&y);

    system("cls");

    //! Con l'operando * indichiamo il valore della variabile puntato da quella variabile indirizzo
    //? L'istruzione sottostante stampa '12458 - 12458 - 0061FF14'
    printf("%d - %d - %p",y,*yPtr,yPtr);

    system("cls");

    //Implementazione dal libro
    int a = 7;
    int *aPtr = &a; // imposta aPtr all'indirizzo di a

    printf("The address of a is %p"
            "\nThe value of aPtr is %p", &a, aPtr);

    printf("\n\nThe value of a is %d"
            "\nThe value of *aPtr is %d", a, *aPtr);

    printf("\n\nShowing that * and & are complements of "
            "each other\n&*aPtr = %p"
            "\n*&aPtr = %p\n", &*aPtr, *&aPtr);

}