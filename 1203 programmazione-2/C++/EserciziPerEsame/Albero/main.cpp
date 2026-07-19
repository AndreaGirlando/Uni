#include <iostream>
using namespace std;
class Albero;
class Nodo{
    public:
        Nodo(int _n, Nodo* _sx = nullptr, Nodo* _dx = nullptr, Nodo* _padre = nullptr) : sx(_sx), dx(_dx), n(_n), padre(_padre) {}
        friend ostream& operator<<(ostream& stream, Nodo& nodo);
        friend class Albero;
    private:
        Nodo* sx;
        Nodo* dx;
        Nodo* padre;
        int n;
};

ostream& operator<<(ostream& stream, Nodo& nodo){
    stream << "Nodo: " << &nodo;
    stream << " n: " << nodo.n;
    stream << " (padre: " << nodo.padre << " sx: " << nodo.sx << " dx: " << nodo.dx << ")\t";
    return stream;
}

class Albero{
    public:
        Albero(Nodo* _root = nullptr):root(_root){}
        ~Albero(){
            deleteAlberoRecursive(root);
        }
        Albero& inserisciNodo(Nodo* newNodo);

        Nodo* ricercaBinaria(int n){
            return ricercaBinaria(root, n);
        }

        Nodo* ricercaIterativa(int n){
            Nodo* tempNodo = root;
            while(tempNodo != nullptr){
                if(n == tempNodo->n){
                    return tempNodo;
                }
                if(n > tempNodo->n){
                    tempNodo = tempNodo -> dx;
                }else{
                    tempNodo = tempNodo -> sx;
                }
            }
            return nullptr;
        }

        Nodo* Max(){
            return Max(root);
        }
        Nodo* Min(){
            return Min(root);
        }

        Nodo* nextNodo(Nodo* temp){
            if(temp == nullptr) { return temp; }

            if(temp->dx != nullptr){
                return Min(temp->dx);
            }else{
                Nodo* padre = temp->padre;
                while(padre != nullptr && temp == padre->dx){
                    temp = padre;
                    padre = padre->padre;
                }
                return padre;
            }
        }

        void printAlbero();
    private:
        void printAlberoRecursive(string prefix,Nodo* temp);
        void deleteAlberoRecursive(Nodo* temp){
            if(temp == nullptr) return;
            deleteAlberoRecursive(temp->sx);
            deleteAlberoRecursive(temp->dx);
            delete temp;
        }
        Nodo* ricercaBinaria(Nodo* nodo, int n){
            if(nodo == nullptr || nodo->n == n) return nodo;
            if(n > nodo->n){
                return ricercaBinaria(nodo->dx, n);
            }else{
                return ricercaBinaria(nodo->sx, n);
            }
        }
        Nodo* Max(Nodo* tempRoot){
            Nodo* max = root;
            while(tempRoot != nullptr){
                max = tempRoot;
                tempRoot = tempRoot->dx;
            }

            return max;
        }
        Nodo* Min(Nodo* tempRoot){
            Nodo* min = root;
            while(tempRoot != nullptr){
                min = tempRoot;
                tempRoot = tempRoot->sx;
            }

            return min;
        }
        Nodo* root;

};

void Albero::printAlbero(){
    printAlberoRecursive("", root);
}

void Albero::printAlberoRecursive(string prefix, Nodo* temp){
    if(temp != nullptr){
        cout << prefix << *(temp) << endl;
        printAlberoRecursive(prefix + "\t", temp->sx);
        printAlberoRecursive(prefix + "\t", temp->dx);
    }
}

Albero& Albero::inserisciNodo(Nodo* newNodo){

    if(root == nullptr){
        root = newNodo;
        return *(this);
    }

    Nodo* tempRoot = root;
    Nodo* prec = nullptr;
    while(tempRoot != nullptr){
        prec = tempRoot;
        if(newNodo->n > tempRoot->n){
            tempRoot = tempRoot->dx;
        }else{
            tempRoot = tempRoot->sx;
        }
    }

    newNodo->padre = prec;

    if(newNodo->n > prec->n){
        prec->dx = newNodo;
    }else{
        prec->sx = newNodo;
    }


    return *(this);
}


int main(){

    Albero tree;
    tree.inserisciNodo(new Nodo(5)).inserisciNodo(new Nodo(1)).inserisciNodo(new Nodo(6)).inserisciNodo(new Nodo(2)).inserisciNodo(new Nodo(1)).inserisciNodo(new Nodo(8));
    tree.inserisciNodo(new Nodo(45)).inserisciNodo(new Nodo(15)).inserisciNodo(new Nodo(26)).inserisciNodo(new Nodo(62)).inserisciNodo(new Nodo(21)).inserisciNodo(new Nodo(18));

    cout << "Il massimo è: " << *(tree.Max()) << endl;
    cout << "Il minimo è: " << *(tree.Min()) << endl;


    // cout << *(tree.ricercaIterativa(15)) << endl;
    // cout << *(tree.ricercaBinaria(1)) << endl;


    cout << *(tree.nextNodo(tree.ricercaIterativa(15))) << endl;

    // tree.printAlbero();
    cout << "\n\n\n";
    return 0;
}