#include <iostream>
#include <fstream>
using namespace std;

class BST;
class Studente{
    public:
        Studente(int _matricola, string _nome, string _cognome, double _media):matricola(_matricola), nome(_nome), cognome(_cognome), media(_media){}
        Studente(Studente& studente){
            matricola = studente.matricola;
            nome = studente.nome;
            cognome = studente.cognome;
            media = studente.media;
        }
        int getMatricola(){return matricola;}
        string getNome(){return nome;}
        string getCognome(){return cognome;}
        double getMedia(){return media;}
        friend ostream& operator<<(ostream& stream, Studente& studente);
        friend class BST;
    private:
        int matricola;
        string nome;
        string cognome;
        double media;
};

ostream& operator<<(ostream& stream, Studente& studente){
    cout << studente.matricola << ": " << studente.nome << " " << studente.cognome << " - media: " << studente.media;
    return stream;
}

class Nodo{
    public:
        Nodo(Studente* _studente = nullptr, Nodo* _dx = nullptr, Nodo* _sx = nullptr):dx(_dx), sx(_sx), studente(_studente){}
        ~Nodo(){
            delete sx;
            delete dx;
            delete studente;
        }
        friend ostream& operator<<(ostream& stream, Nodo& nodo);
        friend class BST;
    private:
        Nodo* dx;
        Nodo* sx;
        Studente* studente;
};

ostream& operator<<(ostream& stream, Nodo& nodo){
    // cout << "\n\n me: " << &nodo;
    // cout << " sx: " << nodo.sx;
    // cout << " dx: " << nodo.dx;
    cout << " \n\t" << *(nodo.studente) << endl;
    return stream;
}

class BST{
    public:
        BST():root(nullptr){}
        ~BST(){
            deleteBST(root);
        }
        void insert(Nodo* newNodo){
            if(root == nullptr){
                root = newNodo;
            }else{
                Nodo* tempRoot = root;
                Nodo* prev = nullptr;
                while(tempRoot != nullptr){
                    prev = tempRoot;
                    if(newNodo->studente->matricola > tempRoot->studente->matricola){
                        tempRoot = tempRoot->dx;
                    }else{
                        tempRoot = tempRoot->sx;
                    }
                }

                if(newNodo->studente->matricola > prev->studente->matricola){
                    prev->dx = newNodo;
                }else{
                    prev->sx = newNodo;
                }
            }
        }
        Nodo* cerca(int matricola){
            Nodo* tempRoot = root;
            while(tempRoot != nullptr){
                if(tempRoot->studente->matricola == matricola){
                    return tempRoot;
                }else if(matricola > tempRoot->studente->matricola){
                    tempRoot = tempRoot->dx;
                }else{
                    tempRoot = tempRoot->sx;
                }
            }
            return tempRoot;
        }
        void printInOrder(){
            printInOrder(root);
        }
    private:
        void printInOrder(Nodo *temp){
            if(temp){
                printInOrder(temp->sx);
                cout << *(temp);
                printInOrder(temp->dx);
            }
        }
        void deleteBST(Nodo* temp){
            if(temp){
                deleteBST(temp->sx);
                deleteBST(temp->dx);
                delete temp;
            }
        }
        Nodo* root;
};

int main(){

    BST bst;
    ifstream file("input.txt");

    int matricola;
    double media;
    string nome, cognome;

    while(!file.eof()){
        file >> matricola;
        getline(file, nome, ',');
        getline(file, nome, ',');//elimino il carattare ','
        getline(file, cognome, ',');
        file >> media;
        bst.insert(new Nodo(new Studente(matricola, nome, cognome, media)));
    }

    cout << *(bst.cerca(1004)) << "\n\n";

    bst.printInOrder();

    cout << endl;
    return 0;
}