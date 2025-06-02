// implementazione delle funzioni per la classe Pila 

#include <iostream>
#include "pila_finale.h"

using namespace std;

template <typename T> 
Pila<T>::Pila() : top(0)
{
    array = new T[MAX_PILA];
    size = MAX_PILA;
    cout << "Allocata memoria per Pila: " << MAX_PILA << endl;
}

template <typename T> 
Pila<T>::~Pila() 
{
    delete [] array;
}

template <typename T>
void Pila<T>::Push(T elem)
{
    if (top >= size) {
        //cout << "Pila piena. Aumento la memoria." << endl;
        T* newarray = new T[size * 2];
        for (int i=0; i<size; i++)
            newarray[i] = array[i];
        delete [] array;
        array = newarray;
        size = size * 2;
    }
    //cout << "Inserisco un nuovo elemento alla posizione " << top << endl;
    array[top] = elem;
    top++;
}

template <typename T>
T Pila<T>::Pop()
{
    top--;
    return array[top];
}

template <typename T>
bool Pila<T>::IsEmpty()
{
    return (top==0);
}