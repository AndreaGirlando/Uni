#include <iostream>
using namespace std;

class List;
ostream& operator<<(ostream& stream,const List& list);//! Dichirazione prototipo dell'operatore

class Node {
	public:
        //? se non passiamo niente il next viene inizzializzato a null
        Node(int d,Node* n = nullptr): next(n), dato(d){} //costruttore che inizzializza il nodo
        friend class List;
        friend ostream& operator<<(ostream& stream,const List& list);
    private:
		int dato;
		Node* next;
};

class List {
    public:
        List() : head(nullptr) {} //Dobbiamo sempre inizzializzare la testa
        List& InsertHead(int d);
        void Insert(int d, Node* p);
        Node* Search(int d);
        bool Remove(int d);


        friend ostream& operator<<(ostream& stream,const List& list);
    private:
        Node* head;


};

bool List::Remove(int d){
    Node* ant = nullptr;
    Node* curr = head;

    while(curr != nullptr){
        if(d == curr -> dato){
            break;
        }
        ant = curr;
        curr = curr->next;
    }

    if(curr == nullptr){
        return false; //la lista è vuota
    }
    if(ant == nullptr){
        head = curr->next; //devo eliminare il primo elemento
    }else{
        ant->next = curr->next; //tutti gli altri elementi
    }
    delete curr;
    return true;
}

Node* List::Search(int d){
    Node* p = head;
    while(p != nullptr){
        if(p->dato == d){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void List::Insert(int d, Node* p){ //Funzione che inserisce un elemento in uno specifico indirizzo
    Node* n = new Node(d,p->next);
    p->next = n;
}

List& List::InsertHead(int d){
    head = new Node(d, head); //creiamo un nuovo nodo che punta alla testa, e il suo indirizzo diventa la testa
    return *this; //ritorniamo la lista in modo da usare la notazione compatta list.InsertHead(10).InsrtHead(25)
}


ostream& operator<<(ostream& stream,const List& list){ //mettiamo entrambi come reference in modo che vengano passate per riferimento
    stream << "Gli elementi della lista sono: ";
    Node* p = list.head;
    while(p != nullptr){
        stream << p->dato << ", ";
        p = p->next;
    }
    stream << endl;
    return stream;
}

int main(){

    List lista;

    lista.InsertHead(10).InsertHead(15).InsertHead(50).InsertHead(100);
    cout << lista << endl;
    cout << "Il puntatore al nodo 2 è: " << lista.Search(15) << endl; //stampa l'indirizzo del nodo
    cout << "Il puntatore al nodo 2 è: " << lista.Search(25) << endl; //stampa 0 perchè il nodo non esiste
    cout << "\n";
    cout << "Elemento 10 rimosso: " << lista.Remove(10) << endl;
    cout << "Elemento 10 rimosso: " << lista.Remove(10) << endl;
    cout << "Elemento 15 rimosso: " << lista.Remove(15) << endl;
    cout << "Elemento 50 rimosso: " << lista.Remove(50) << endl;
    cout << "Elemento 100 rimosso: " << lista.Remove(100) << endl;
    cout << "Elemento 100 rimosso: " << lista.Remove(100) << endl;


    cout << endl;
    return 0;
}