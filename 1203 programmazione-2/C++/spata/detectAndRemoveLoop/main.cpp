#include <iostream>
using namespace std;
class Nodo{
    public:
        Nodo(int _dato, Nodo* _next):dato(_dato),next(_next) {}
        int get(){
            return dato;
        }
        Nodo* get_suc(){
            return next;
        }
        void setNext(Nodo* _next){
            next = _next;
        }
    private:
        int dato;
        Nodo* next;
};

void InsertHead(int n, Nodo** head){
    Nodo* newNode = new Nodo(n, *(head));
    *(head) = newNode;
}

void printList(Nodo* head){
    Nodo* tempTesta = head;
    while(tempTesta != nullptr){
        // cout << "elemento";
        cout << tempTesta->get() << "->";
        tempTesta = tempTesta->get_suc();
    }
    cout << "NULL";
}





bool detectAndRemoveLoop(Nodo* head){
    Nodo* tempTesta = head;

    Nodo* current = head;
    Nodo* next = head->get_suc();


    while(tempTesta != nullptr){
        if(current == next->get_suc()->get_suc()){
            next->get_suc()->setNext(nullptr);
            return true;
        }

        tempTesta = tempTesta->get_suc();
        current = tempTesta;
        next = tempTesta->get_suc();
    }
    return false;
}
int main(){

    Nodo* head = nullptr;

    for(int i = 0;i < 5; i++){
        InsertHead(rand()%255,&head);
    }

    Nodo* tempTesta = head;
    Nodo* prev = NULL;

    while(tempTesta->get_suc() != nullptr){
        tempTesta = tempTesta->get_suc();
    }
    tempTesta->setNext(head->get_suc()->get_suc());

    detectAndRemoveLoop(head);
    printList(head);

    cout << "\n\n\n";


    return 0;
}