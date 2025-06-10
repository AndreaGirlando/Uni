#include <iostream>
using namespace std;
class BST;
class Nodo{
    public:
        Nodo(int _dato, Nodo* _sx = nullptr, Nodo* _dx = nullptr): sx(_sx), dx(_dx), dato(_dato) {}
        friend ostream& operator<<(ostream& stream, Nodo& nodo);
        friend class BST;
    private:
        Nodo* sx;
        Nodo* dx;
        Nodo* padre;
        int dato;
};

ostream& operator<<(ostream& stream, Nodo& nodo){
    // stream << "Nodo: " << nodo.dato;
    // stream << " (dx: " << nodo.dx << " sx: " << nodo.sx << " padre: " << nodo.padre << ")" << endl;
    cout << nodo.dato;
    return stream;
};

class BST{
    public:
        BST():root(nullptr){}
        ~BST(){
            deleteAllTree(root);
        }
        BST& inserisciNodo(Nodo* temp);
        BST& eliminaNodo(Nodo* nodoDaEliminare);
        void trapianta(Nodo* src, Nodo* dst);
        Nodo* ricerca(int dato);
        int Max(){
            return (Max(root))->dato;
        }
        int Min(){
            return (Min(root))->dato;
        }

        void stampaInOrder(){
            cout << "Elementi dell'albero in ordine crescente: ";
            stampa(root);
        }
    private:
        Nodo* Min(Nodo* tempRoot){
            while(tempRoot->sx != nullptr){
                tempRoot = tempRoot->sx;
            }
            return tempRoot;
        }
        Nodo* Max(Nodo* tempRoot){
            while(tempRoot->dx != nullptr){
                tempRoot = tempRoot->dx;
            }
            return tempRoot;
        }
        void deleteAllTree(Nodo* temp){
            if(temp){
                deleteAllTree(temp->sx);
                deleteAllTree(temp->dx);
                delete temp;
            }
        }
        void stampa(Nodo* nodo){
            if(nodo){
                stampa(nodo->sx);
                cout << *(nodo) << " ";
                stampa(nodo->dx);
            }
        }
        Nodo* root;
};

int main(){

    BST tree;
    int temp = 0;
    while(temp != -1){
        cout << "\nInserisci un numero intero positivo da inserire nell'albero (-1 per terminare): ";
        cin >> temp;
        if(temp < 0){
            continue;
        }
        if(temp == -1){
            break;
        }
        tree.inserisciNodo(new Nodo(temp));

    }
    tree.stampaInOrder();
    cout << "\nIl valore massimo è: " << tree.Max() << endl;
    cout << "\nIl valore minimo è: " << tree.Min() << endl;

    Nodo* found;
    do{
        int n;
        cout << "\nInserisci un valore da cercare all'interno dell'albero: ";
        cin>>n;
        found = tree.ricerca(n);
        if(found == nullptr){
            cout << "Il valore " << n << " NON è presente nell'albero";
        }else{
            cout << "Il valore " << n << " è presente nell'albero";
        }
    }while(found != nullptr);



    cout << "\n\n\n";
    return 0;
}
BST& BST::inserisciNodo(Nodo* temp){
    if(root == nullptr){
        root = temp;
        return *(this);
    }

    Nodo* tempRoot = root;
    Nodo* prec = nullptr;
    while(tempRoot != nullptr){
        prec = tempRoot;
        if(temp->dato > tempRoot->dato){
            tempRoot = tempRoot->dx;
        }else{
            tempRoot = tempRoot->sx;
        }
    }

    temp->padre = prec;

    if(temp->dato > prec->dato){
        prec->dx = temp;
    }else{
        prec->sx = temp;
    }


    return *(this);
}

Nodo* BST::ricerca(int dato){
    Nodo* tempRoot = root;
    while(tempRoot != nullptr){
        if(tempRoot->dato == dato){
            return tempRoot;
        }
        if(dato>tempRoot->dato){
            tempRoot = tempRoot->dx;
        }else{
            tempRoot = tempRoot->sx;
        }
    }
    return tempRoot;
}


