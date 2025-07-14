#include <iostream>

using namespace std;

class List;
ostream& operator<<(ostream& stream, const List& list);

class Node {
public:
    Node(int d, Node* p=nullptr) : dato(d), next(p) {}
    friend class List;
    friend ostream& operator<<(ostream& stream, const List& list);
private:
    int dato;
    Node* next;
};

class List {
public:
    List() : head(nullptr) {}

    List& InsertHead(int d);
    void Insert(int d, Node* p);
    Node* Search(int d);
    bool Remove(int d);

    friend ostream& operator<<(ostream& stream, const List& list);
private:
    Node* head;
};

List& List::InsertHead(int d) 
{
    head = new Node(d, head);
    return *this;
}

void List::Insert(int d, Node* p)
{
    Node* n = new Node(d, p->next);
    p->next = n;
}

Node* List::Search(int d)
{
    Node* p = head;
    while (p != nullptr) {
        if (p->dato == d)
            return p;
        p = p->next;
    }
    return nullptr;
}

bool List::Remove(int d)
{
    Node* ant = nullptr;
    Node* cur = head; 

    while(cur != nullptr)
    {
        if (d == cur->dato)
            break;
        ant = cur;
        cur = cur->next;
    }

    if (cur == nullptr)
        return false;
        
    if (ant == nullptr)
        head = cur->next;
    else
        ant->next = cur->next;
    
    delete cur;

    return true;
}


ostream& operator<<(ostream& stream, const List& list)
{
    stream << "Gli elementi della lista sono: ";
    Node* p = list.head;
    while (p != nullptr) {
        stream << p->dato << ", ";
        p = p->next;
    }
    stream << endl;
    return stream;
}

int main() 
{
    List lista;
    cout << lista;
    lista.InsertHead(5);
    cout << lista;
    lista.InsertHead(3).InsertHead(7);
    cout << lista;
    cout << "Il puntatore al nodo 3 è: " << lista.Search(3) << endl;
    cout << "Il puntatore al nodo 11 è: " << lista.Search(11) << endl;
    cout << "Elemento 3 rimosso: " << lista.Remove(3) << endl;
    cout << lista;
    cout << "Elemento 3 rimosso: " << lista.Remove(3) << endl;
    cout << lista;
    cout << "Elemento 5 rimosso: " << lista.Remove(5) << endl;
    cout << lista;
    cout << "Elemento 7 rimosso: " << lista.Remove(7) << endl;
    cout << lista;
    cout << "Elemento 11 rimosso: " << lista.Remove(11) << endl;
    cout << lista;

    return 0;
}
