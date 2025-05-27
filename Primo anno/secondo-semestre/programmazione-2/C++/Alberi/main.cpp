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

//*Dichiarazione del operatore per la stampa del nodo binario
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
        BSTNode* Search(int d);
        BSTNode* Next(BSTNode* node);
        BSTNode* Min();
    private:
        BSTNode* Min(BSTNode* x);
        void Print(BSTNode* x);
        void Delete(BSTNode* x);
        BSTNode* Search(BSTNode* T,int d);
        BSTNode* root;
};

//* Funzione che ritorna il next di un dato nodo
//! Capire bene come funziona questo metodo !!è importante
BSTNode* BST::Next(BSTNode* x){
    if(x->dx) {
        return Min(x->dx);
    }
    BSTNode* y = x->padre;
    while(y != nullptr && x == y->dx){
        x = y;
        y = y->padre;
    }
    return y;
}

//* Funzione che cerca il minimo partendo da un nodo
BSTNode* BST::Min(){
    return Min(root);
}
BSTNode* BST::Min(BSTNode* x){
    BSTNode* node = x;
    while(node->sx != nullptr){
        node = node->sx;
    }
    return node;
}

//* funzione Search ricorsiva (caso base - caso ricorsivo)
BSTNode* BST::Search(int d){
    return Search(root, d);
}

BSTNode* BST::Search(BSTNode* T,int d){

    if(T == nullptr || T->d == d){
        return T;
    }
    if(d<T->d){
        return Search(T->sx, d);
    }
    return Search(T->dx, d);

}

//* funzione Print ricorsiva (caso base - caso ricorsivo)
void BST::Print(){
    cout << endl;
    Print(root);
}
void BST::Print(BSTNode* x){
    if(x == nullptr){
        return;
    }
    cout << *(x) << endl;
    Print(x->sx);
    Print(x->dx);
}
//* Distruttore che richiama la funzione Delete per cancellare tutto l'albero
BST::~BST(){
    Delete(root);
}
//* Funzione delete che fa uso della strategia postorder per cancellare tutto l'albero
void BST::Delete(BSTNode* node){
    if(node){
        Delete(node->sx);
        Delete(node->dx);
        delete node;
    }
}


//* Funzione che inserisce un nodo in modo ordinato all'interno dell'albero
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
    tree.Insert(56).Insert(12).Insert(10).Insert(65).Insert(123).Insert(1).Insert(23);
    tree.Print();

    cout << "l'elemento cercato è: " << *(tree.Search(12));
    cout << "l'elemento minimo è: " << *(tree.Min());

    cout << *(tree.Next(tree.Search(10)));
    cout << *(tree.Next(tree.Min()));

    return 0;
}