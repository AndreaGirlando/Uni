//BST
#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

class Studente{ //sarà il mio nodo (class BstNode)

    public:
    Studente(int numero,string name, string surname, float m): matricola(numero),nome(name),cognome(surname),media(m){}
    Studente():matricola(0),nome(""),cognome(""),media(0){}
    friend class Bst;

    int getMatricola(){
        return matricola;
    }
    string getNome(){
        return nome;
    }
    string getCognome(){
        return cognome;
    }
    float getMedia(){
        return media;
    }

    void stampa(){
        cout << matricola << ": " << nome << " " << cognome << " " << media <<endl;
    }

    private:
    int matricola;
    string nome;
    string cognome;
    float media;

    Studente *padre;     //zona albero
    Studente *left;
    Studente *right;
};

class Bst{
    public:
    Bst():root(nullptr){}
    void preleva();
    void insert(int numero, string name, string surname,float m);   //verrà chiamata dentro preleva
    void printRicorsiva();
    void print(Studente *nodo);
    Studente* search(int numero);
    void printSearch(Studente *c);   //funzione per stampare le cose cercate da search

    private:
    Studente *root;
};

void Bst::printSearch(Studente *c){
    cout << c->matricola << ": " << c->nome << " " << c->cognome<< " " << c->media <<endl;
}

Studente* Bst::search(int numero){
    Studente *current = root;

    while(current != nullptr && current->matricola != numero){
        if(current->matricola > numero){
            current = current->left;
        }else{
            current = current->right;
        }
    }

    if(current == nullptr){
        cout << "Elemento non trovato" <<endl;
        return nullptr;
    }
    cout << "Elemento trovato" <<endl;
    printSearch(current);
    return current;
}

void Bst::printRicorsiva(){
    print(root);
    cout <<endl;
    return;
}

void Bst::print(Studente *nodo){        //visita in order

    if(nodo != nullptr){
        print(nodo->left);
        cout << nodo->matricola << ": " << nodo->nome << " " << nodo->cognome<< " " << nodo->media <<endl;
        print(nodo->right);
    }

    return;
}

void Bst::preleva(){                    //questa funzione è corretta
    fstream file("input.txt",ios::in);
    if(file.fail()){
        cout << "Errore nell'apertura del file 'input.txt'" <<endl;
        exit(-1);
    }

    string riga;
    while (getline(file, riga)) {
        stringstream ss(riga);
        string numeroStr, name, surname, mStr;
        int numero = 0;
        float m = 0;

        getline(ss, numeroStr, ',');
        getline(ss, name, ',');
        getline(ss, surname, ',');
        getline(ss, mStr, ',');

        numero = stoi(numeroStr);
        m = stof(mStr);

        insert(numero,name,surname,m);
    }
    file.close();
    return;

}

void Bst::insert(int numero, string name, string surname,float m){  //questa funzione è corretta


    Studente *x = root;     //nodo corrente
    Studente *y = nullptr;  //terra conto del padre

    while(x != nullptr){    //questo while scorre fino a trovare la posizione giusta nell'albero, poi esco e creo il nodo
        y = x;

        if(numero < x->matricola){      //se la matricola da inserire è più piccola di quella del nodo corrente vado verso sinistra altrimenti a destra
            x = x->left;
        }else{
            x = x->right;
        }
    }

    //creazione nodo
    Studente *newNode = new Studente;
    newNode->matricola = numero;
    newNode->nome = name;
    newNode->cognome = surname;
    newNode->media = m;

    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->padre = y;

    if(y == nullptr){           //gestisco il padre del nodo appena creato
        root = newNode;         //se il padre è null newNode è la radice
    }else if(numero < y->matricola){      //qui decido se newNode deve essere figlio destro o sinistro
        y->left = newNode;
    }else{
        y->right = newNode;
    }
    
    return;

}


int main(){

    Bst prova;
    prova.preleva();
    prova.search(1004);
    cout << "Stampo tutti gli studenti " <<endl;
    prova.printRicorsiva();
    

    return 0;
}