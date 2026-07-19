
//? Modificare la classe Pila allegata in maniera da supportare un numero arbitrario di elementi mediante array dinamici.
//? Raggiunta la dimensione massima dell'array allocare dinamicamente un nuovo array di dimensione doppia, copiare i dati e cancellare l'array precedente.

#include <iostream>

#include "pila.h"

using namespace std;

int main()
{
    srand(time(0));
    Pila<int> pila_interi;

    cout << "Dimensione totale pila: " << pila_interi.Len() << endl;

    int elementiInseriti = rand()%100;
    for (int i = 0; i < elementiInseriti; i++){
        pila_interi.Push(rand() % 256);
    }

    cout << "Hai inserito " << elementiInseriti << " elementi nella pila" << endl;
    cout << "Dimensione totale pila: " << pila_interi.Len() << endl;


    //?  Scommentare di seguito per vedere gli elementi della pila
    // cout << endl << "Elementi estratti dalla pila: " << endl;
    // for (int i = 0; i < elementiInseriti; i++){
    //     cout << pila_interi.Pop() <<  endl;
    // }
 }