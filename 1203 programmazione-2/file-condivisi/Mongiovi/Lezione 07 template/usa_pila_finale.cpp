#include <iostream>

using namespace std;

#include "pila_finale.h"

int main()
{
    Pila<int> pila_interi;
    pila_interi.Push(5);
    pila_interi.Push(7);
    pila_interi.Push(9);
    for (int i=0; i<50; i++)
        pila_interi.Push(i);
    cout << "Elementi estratti dalla pila: " << endl;
    while(!pila_interi.IsEmpty()) 
        cout << pila_interi.Pop() << endl;
 }