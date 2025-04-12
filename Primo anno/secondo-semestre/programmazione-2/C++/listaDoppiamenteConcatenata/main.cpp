#include <iostream>
using namespace std;

//! Implementare le classi Node e List. Implementare i metodi InsertHead, Insert, Search, Remove e l'operatore << (vedi implementazione lista semplice nel materiale didattico)

class List;

class Node{
    public:
        Node(Node* p, Node* s, int d) : prec(p), next(s), data(d) {}
        friend ostream& operator<<(ostream& stream,const List& list);
        friend class List;
    private:
        Node* prec;
        Node* next;
        int data;
};

class List{
    public:
        List() : head(nullptr) {}
        List& InsertHead(int d);
        void Insert(int d, Node* p);
        Node* Search(int d);
        bool Remove(Node* r);
        friend ostream& operator<<(ostream& stream,const List& list);
    private:
        Node* head;
};

bool List::Remove(Node* r){
    // cout << r->next->data;

    if(head == nullptr || r == nullptr){
        return false;
    }

    if(r->prec == nullptr && r->next == nullptr){ //caso di un singolo elemento
        head = nullptr;
    }
    else if(r->prec == nullptr){ //mi trovo in testa
        head = r->next;
        r->next->prec = nullptr;
    }
    else if(r->next == nullptr){ //mi trovo nell'ultimo elemento
        r->prec->next = nullptr;
    }
    else{
        r->prec->next = r->next;
        r->next->prec = r->prec;
    }
    delete r;

    return true;
};

void List::Insert(int d, Node* p){
    Node* newNodo = new Node(p,p->next,d);
    p->next = newNodo;
}

Node* List::Search(int d){

    Node* temp = head;
    while(temp != nullptr){
        if(temp->data == d){
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;

}

List& List::InsertHead(int d){
    Node* newNodo = new Node(nullptr,head,d);
    if(head != nullptr) head->prec = newNodo;
    head = newNodo;

    return *this;
}

ostream& operator<<(ostream& stream,const List& list){
    stream << "\n";
    stream << "I nodi della lista sono: " << endl;
    Node* temp = list.head;
    while(temp != nullptr){
        stream << "(" << temp->prec << "|" << temp->data << "|" << temp->next << ")" << endl;
        temp = temp->next;
    }
    stream << "\n";
    return stream;
};

int main(){

    List list;

    list.InsertHead(5).InsertHead(10);


    cout << list;
    cout << "Il nodo è stato trovato all'indirizzo: " << list.Search(10) << "\n\n\n";

    list.Insert(22,list.Search(5));
    cout << list;

    cout << "Elemento numero 22 rimosso: " << (list.Remove(list.Search(22))? "Si": "No");
    cout << list;
    cout << "Elemento numero 10 rimosso: " << (list.Remove(list.Search(10))? "Si": "No");
    cout << list;
    cout << "Elemento numero 5 rimosso: " << (list.Remove(list.Search(5))? "Si": "No");
    cout << list;
    cout << "Elemento numero 50 rimosso: " << (list.Remove(list.Search(50))? "Si": "No");
    cout << list;


    cout << "\n\n\n";
    return 0;
}