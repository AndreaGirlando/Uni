// header file per la gestione di una pila mediante array nativi

#ifndef PILA_H
#define PILA_H

const int MAX_PILA = 20;

template <typename T>
class Pila
{
public:
    Pila();    
    ~Pila();    
    void Push(T elem);
    T Pop();
    bool IsEmpty();
private:
    T* array;
    int size;
    int top;
};

#include "pila_finale.cpp"

#endif