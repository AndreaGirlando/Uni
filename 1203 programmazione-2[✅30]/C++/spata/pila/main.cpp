/*
    Scrivere una funzione copia pila che copia il contenuto di una pila in un'altra
    La funzione deve avere due argomenti di tipo pila, uno per la pila sorgente e un altro per la pila destinazione
    SPIEGAZIONE: uso una pila d'appoggio per la copia temporanea e poi la uso per riempire di nuovo le due pile
*/

#include <iostream>
using namespace std;
class Nodo{
    public:
        Nodo(){};
        Nodo(int _n, Nodo* _next = nullptr): n(_n), next(_next) {}
        int n;
        Nodo* next;
};

class Pila{
    public:
        Pila(): head(nullptr), len(0){};
        bool isEmpty(){
            return head == nullptr;
        }
        int getLen(){
            return len;
        }
        void push(Nodo* newNodo){
            newNodo->next = head;
            head = newNodo;
            len++;
        }
        Nodo* pop(){
            if(this->isEmpty()) return nullptr;
            Nodo* tempHead = head;
            head = tempHead->next;
            return tempHead;
        }

    private:
        Nodo* head;
        int len;
};

void copiaPila(Pila& src, Pila& dst){
    int* array = new int[src.getLen()];

    for(int i = 0; i < src.getLen(); i++){
        array[i] = src.pop()->n;
    }
    for(int i = 3; i >= 0; i--){
        dst.push(new Nodo(array[i]));
    }


    // cout << src.getLen();
}

int main(){

    Pila temp;
    temp.push(new Nodo(5));
    temp.push(new Nodo(8));
    temp.push(new Nodo(2));
    temp.push(new Nodo(14));

    Pila temp2;
    copiaPila(temp,temp2);

    cout << (temp2.pop())->n << "\t";
    cout << (temp2.pop())->n << "\t";
    cout << (temp2.pop())->n << "\t";
    cout << (temp2.pop())->n << "\t";

    cout << endl;
    return 0;
}