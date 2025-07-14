/*
    Crea la classe listaInteri, una lista di numeri che devono essere inseriti dall'utente nel main
    Questa classe deve avere i seguenti metodi:
    - InsertHead
    - StampaLista
    - OrdinaDispari
    - OrdinaPari
*/

#include <iostream>
using namespace std;
class Nodo{
    public:
        Nodo(char _dato, Nodo* _next = nullptr):dato(_dato), next(_next) {}
        int dato;
        Nodo* next;
};

class listaInteri{
    public:
        listaInteri():head(nullptr){};
        void add(int dato){
            head = new Nodo(dato, head);
        }
        void StampaLista(){
            Nodo* tempHead = head;
            while(tempHead != nullptr){
                cout << tempHead->dato << endl;
                tempHead = tempHead -> next;
            }
        }
    private:
        Nodo* head;

};

int main(){

    listaInteri list;
    list.add(5);
    list.add(8);
    list.add(1);
    list.StampaLista();

    return 0;
}