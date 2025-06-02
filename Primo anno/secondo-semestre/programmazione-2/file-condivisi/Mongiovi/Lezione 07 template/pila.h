// header file per la gestione di una pila mediante array nativi

#ifndef PILA_H
#define PILA_H

const int MAX_PILA = 20;

template <typename T>
class Pila
{
public:
    Pila();    
    void Push(T elem);
    T Pop();
private:
    T array[MAX_PILA];
    int top;
};

#include "pila.cpp"

#endif