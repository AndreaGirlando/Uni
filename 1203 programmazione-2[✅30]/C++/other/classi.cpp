#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class punto {
    public: //* Etichetta per indicare tutti i metodi public

    //? Questo è un costruttore ovvero un metodo (che ha sempre lo stesso nome della classe)
    //? che viene richiamato alla creazione dell'oggetto
    punto(int tempValore, string tempNome){
        valore = tempValore;
        nome = tempNome;
    }
    //? Questo è un distruttore ovvero un metodo (che ha sempre lo stesso nome della classe)
    //? di solito viene usato per deallocare la memoria
    ~punto(){
        valore = 0;
        nome = "";
    }

    //! Campi della classe
    int valore;
    string nome;


    //! Metodi della classe
    void printString(string req){
        cout << req;
    }
    void show(){
        cout << valore;
        cout << nome;
    }
    private: //* Etichetta per indicare tutti i metodi private
};

int main(){
    //? Questi sono i 2 modi per allocare gli oggetti in memoria
    punto primoPunto(5, "ciao");
    primoPunto.printString("Ciao");
    primoPunto.show();

    cout << endl;

    punto *secondoPunto = new punto(6,"Prova");
    secondoPunto->printString("Ciao");
    secondoPunto->show();

    cout << endl;
    return 0;
}