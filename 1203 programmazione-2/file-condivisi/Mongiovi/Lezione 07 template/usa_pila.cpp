#include <iostream>

#include "pila.h"

using namespace std;

int main()
{
    Pila<int> pila_interi;
    pila_interi.Push(5);
    pila_interi.Push(7);
    pila_interi.Push(9);
    cout << "Elementi estratti dalla pila: " << endl;
    cout << pila_interi.Pop() << endl;
    cout << pila_interi.Pop() << endl;
    cout << pila_interi.Pop() << endl;
 }