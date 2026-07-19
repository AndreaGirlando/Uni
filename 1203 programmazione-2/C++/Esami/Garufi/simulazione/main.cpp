//simulazione d'esame

#include <iostream>

using namespace std;

class Bst;

class BstNode{
    public:
    BstNode():dato(0),padre(nullptr),left(nullptr),right(nullptr){}
    friend class Bst;

    private:
    int dato;
    BstNode *padre;
    BstNode *left;
    BstNode *right;
};


class Bst{
    public:
    Bst():root(nullptr){}

    void insert(int d);
    void printRicorsiva();
    void print(BstNode *r);
    void minMax();
    bool search(int d);
    void cancellazione(BstNode *z);

    private:
    BstNode *root;
};

void Bst::cancellazione(BstNode *z){
    
}

bool Bst::search(int d){
    BstNode *current = root;

    while(current != nullptr){
        if(current->dato == d){
            cout << "Valore trovato: " << current->dato;
            return true;
        }else if(current->dato > d){
            current = current->left;
        }else{
            current = current->right;
        }
    }

    cout << "Valore non trovato " <<endl;
    return false;
}

void Bst::minMax(){
    BstNode *current = root;

    while(current->left != nullptr){
        current = current->left;
    }
    cout << "Il valore minimo e' " << current->dato <<endl;

    current = root;

    while(current->right != nullptr){
        current = current->right;
    }
    cout << "Il valore massimo e' " << current->dato <<endl;

    return;
}

void Bst::printRicorsiva(){
    print(root);
    cout << endl;
    return;
}

void Bst::print(BstNode *r){

    if(r != nullptr){
        print(r->left);
        cout << r->dato << " ";
        print(r->right);
    }
    return;

}


void Bst::insert(int d){

    BstNode *x = root;
    BstNode *y = nullptr;

    while(x != nullptr){
        y = x;

        if(x->dato < d){
            x = x->right;
        }else{
            x = x->left;
        }
    }
        BstNode *newNode = new BstNode;
        newNode->dato = d;
        newNode->padre = y;
        newNode->left = nullptr;
        newNode->right = nullptr;

        if(y == nullptr){
            root = newNode;
        }else if(d < y->dato){
            y->left = newNode;
        }else{
            y->right = newNode;
        }
    
}

int main(){

    Bst albero;

    int numero = 0;

    do{
        cout << "Inserisci un numero intero positivo da mettere nell'albero (-1 per uscire)" <<endl;
        cin >> numero;
        if(numero != -1){
            albero.insert(numero);
        }
        
    }while(numero != -1);
    cout << "Elementi dell'albero in ordine crescente" <<endl;
    albero.printRicorsiva();

    cout << "Stampo il massimo e il minimo nell'albero" <<endl;
    albero.minMax();

    cout << "Inserisci un valore da cercare: " <<endl;
    cin >> numero;
    albero.search(numero);
    cout <<endl;
    cout << "Inserisci un valore da cercare: " <<endl;
    cin >> numero;
    albero.search(numero);


    return 0;
}