#include <iostream>

using namespace std;

class List;
ostream& operator<<(ostream& stream, const List& list);


class Node{
    public:
    Node(int d, Node *p): dato(d),next(p){}
    
    friend class List;
    friend ostream& operator<<(ostream& stream, const List& list);

    private:
    int dato;
    Node *next;
};


class List{
    public:
    List():head(nullptr){}

    friend ostream& operator<<(ostream& stream, const List& list);
    void inCoda(int d);
    bool detectAndRemoveLoop();

    private:
    Node *head;

};

void List::inCoda(int d){           //inserimento in coda e formazione del loop

    Node *controllo = head;
    Node *newNode = nullptr;
    Node *riferimento = head;

    if(head == nullptr){
        head = new Node(d,head);
        return;
    }

    bool flag = false;
    while(controllo->next != nullptr){      //scorro finche mi trovo in coda

        if(riferimento->dato != 15 && flag == false){
            riferimento = riferimento->next->next;    //mi fermo al 15 cosi ho il riferimento per linkare
            flag = true;
        }
        
        controllo = controllo->next;
    }


    newNode = new Node(d,nullptr);
    if(d == 10){
        newNode->next = riferimento;
    }
    controllo->next = newNode;

    return;
}

bool List::detectAndRemoveLoop(){
    cout << "Procedo a trovare il loop" <<endl;
    int i = 0;

    Node *controllo = head;

    while(controllo != nullptr){

        if(controllo->next != nullptr && controllo->next->dato == 15){
            i++;
        }
        if(i == 2){
            cout << "Trovato loop al nodo: "<< controllo <<endl;
            controllo->next = nullptr;
            return true;
        }
        
        controllo = controllo->next;
        
    }
    cout << "Loop non trovato" <<endl;;
    return false;

}


ostream& operator<<(ostream& stream, const List& list){ //è importante mettere il riferimento & perche altrimenti faccio una copia

    stream << "Gli elementi della lista sono: ";
    Node *p = list.head;
    while(p != nullptr){
        stream << p->dato << ", ";  
        p = p->next;
    }
    stream <<endl;
    return stream;
}


int main(){

    List lista;

    lista.inCoda(50);
    lista.inCoda(20);
    lista.inCoda(15);
    lista.inCoda(4);
    lista.inCoda(10);
    //cout << lista;    non stampo perche essendoci un loop stamperebbe all'infinito

    lista.detectAndRemoveLoop();
    cout << lista;

    lista.detectAndRemoveLoop();
    cout << lista;
}
