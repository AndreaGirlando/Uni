#include <iostream>

/*
    - Implementare la ricerca in modo ricorsivo
*/

using namespace std;
class BST;
class BSTNode{
    public:
        BSTNode(int _d, BSTNode* _dx = nullptr, BSTNode* _sx = nullptr, BSTNode* _padre = nullptr)
            : d(_d), dx(_dx), sx(_sx), padre(_padre){}
        friend ostream& operator<<(ostream& stream, BSTNode& temp);
        friend class BST;
    private:
        BSTNode* padre;
        BSTNode* dx;
        BSTNode* sx;
        int d;
};
ostream& operator<<(ostream& stream, BSTNode& temp){
    stream << "Self: "<< &temp << " Padre: " << temp.padre << " Dx: " << temp.dx << " Sx: " << temp.sx << " D: " <<  temp.d << endl;

    return stream;
}

class BST{
    public:
        BST(): root(nullptr){}
        ~BST();
        BST& Insert(int d);
        void Print();
    private:
        void Print(BSTNode* x);
        void Delete(BSTNode* x);
        BSTNode* root;
};
void BST::Print(){
    cout << endl;
    Print(root);
}
BST::~BST(){
    Delete(root);
}
void BST::Delete(BSTNode* node){
    if(node){
        Delete(node->sx);
        Delete(node->dx);
        delete node;
    }
}
void BST::Print(BSTNode* x){
    if(x == nullptr){
        return;
    }
    cout << *(x) << endl;
    Print(x->sx);
    Print(x->dx);
}
BST& BST::Insert(int d){
    BSTNode* x = root;
    BSTNode* y = nullptr;

    while(x != nullptr){
        y = x;
        if(d < x->d){
            x = x->sx;
        } else {
            x = x->dx;
        }
    }

    BSTNode* nodo = new BSTNode(d);
    nodo->padre = y;

    if(y == nullptr){
        root = nodo; // Albero vuoto
    } else if(d < y->d){
        y->sx = nodo;
    } else {
        y->dx = nodo;
    }

    return *this;
}

int main(){

    BST tree;
    tree.Insert(56).Insert(12).Insert(10).Insert(65);
    tree.Print();

    return 0;
}