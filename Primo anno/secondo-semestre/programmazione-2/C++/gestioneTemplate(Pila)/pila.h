// header file per la gestione di una pila mediante array nativi

#ifndef PILA_H
#define PILA_H

template <typename T> class Pila {
    public:
        Pila();
        ~Pila();
        void Push(T elem);
        T Pop();
        int Len(); //massimo numero di elementi della Pila
        void copyArray(T elem[]);
    private:
        T *array;
        int dim;
        int top;
};

#include "pila.cpp"

#endif