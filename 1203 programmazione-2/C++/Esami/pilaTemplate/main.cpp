/*
    crea un template per la pila poi testala usando come tipo gli interi
*/

#include <iostream>
using namespace std;
template <typename T> class Nodo{
    public:
        Nodo(T* _dato = nullptr, Nodo<T>* _next = nullptr):dato(_dato), next(_next){}
        template <typename T1> friend ostream& operator<<(ostream& stream, Nodo<T1> nodo);
        template <typename T2> friend class Pila;
        T* dato;
    private:
        Nodo<T>* next;
};

template <typename T1> ostream& operator<<(ostream& stream, Nodo<T1>* nodo){
    cout << *(nodo->dato);
    return stream;
}

template <typename T> class Pila{
    public:
        Pila():head(nullptr){}
        void push(Nodo<T>* newNodo){
            if(head == nullptr){
                head = newNodo;
            }else{
                newNodo->next = head;
                head = newNodo;
            }
        }
        Nodo<T> pop(){
            Nodo<T>* res = head;
            if(head == nullptr) return res;
            head = head->next;
            return res;
        }
        void stampa(){
            Nodo<T>* tempHead = head;
            while(tempHead != nullptr){
                cout << tempHead << endl;
                tempHead = tempHead->next;
            }
        }
    private:
        Nodo<T>* head;
};

int main(){

    Pila<int> pila;
    pila.push(new Nodo<int>(new int(1)));
    pila.push(new Nodo<int>(new int(2)));
    pila.push(new Nodo<int>(new int(3)));
    pila.push(new Nodo<int>(new int(4)));
    pila.push(new Nodo<int>(new int(5)));
    pila.push(new Nodo<int>(new int(6)));
    pila.stampa();
    return 0;
}