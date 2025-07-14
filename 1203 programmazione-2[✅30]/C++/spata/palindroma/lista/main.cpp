#include <iostream>
using namespace std;
/*
    Scrivere una classe Parola che gestice una stringa e fornisce un metodo per verificare se è palindroma

    creare metodo isPalindroma()
    creare metodo stampa()

    ! Usando le liste
*/

class Nodo{
    public:
        Nodo(char _dato, Nodo* _next = nullptr, Nodo* _prec = nullptr):dato(_dato), next(_next) {}
        char dato;
        Nodo* next;
};

class Lista{
    public:
        Lista(): head(nullptr){};
        void add(char dato){
            head = new Nodo(dato, head);
        }

        void stampaLista(){
            Nodo* tempHead = head;
            while(tempHead != nullptr){
                cout << tempHead->dato << endl;
                tempHead = tempHead->next;
            }
        }
    private:
        Nodo* head;
        Nodo* tail;
};

class Parola{
    public:
        Parola(string _word): word(_word){}
        bool isPalindroma(){
            const char* string = word.c_str();
            for(int i = 0; i < getLen()/2; i++){
                if(string[i] != string[getLen()-1-i]){
                    return false;
                }
            }
            return true;
        }
        void stampa(){
            cout << word;
        }
    private:
        int getLen(){
            return word.length();
        }
        string word;
};


int main(){

    Lista list;

    list.stampaLista();

    return 0;
}