#include <iostream>

using namespace std;

class Libreria{
    public:
    Libreria(string title,string autor):titolo(title),autore(autor){}

    virtual void print(){
        cout << "Libro o DVD" <<endl;
    }

    virtual void insert(string title,string autor,float n){

        cout << "Inserimento " <<endl;
        titolo = title;
        autore = autor;
    }

    virtual void search(string title){
        if(title == titolo){
            cout << "Elemento trovato "<<endl;
            print();
            return;
        }else{
            cout << "Elemento non trovato" <<endl;
        }
    }

    protected:
    string titolo;
    string autore;
};


class Libro : public Libreria{
    
    public: //Libro prende 2 stringhe titolo e autore e le passa al costruttore di Libreria dove vengono inizializzate
    Libro(string title, string autor, int n):Libreria(title,autor),nPagine(n){}

    void print(){
        cout << "Libro" <<endl;

        cout << "Titolo -> " << titolo <<endl;
        cout << "Autore -> " << autore <<endl;
        cout << "Numero Pagine -> " << nPagine <<endl;
        cout <<endl;
    }

    void insert(string title,string autor,float n){

        cout << "Inserimento Libro" <<endl;
        titolo = title;
        autore = autor;
        nPagine = n;
    }

    void search(string title){
        if(title == titolo){
            cout << "Elemento trovato "<<endl;
            print();
            return;
        }else{
            cout << "Elemento non trovato" <<endl;
        }
    }

    private:
    int nPagine;
};


class Dvd : public Libreria{
    public:
    Dvd(string title, string autor, float n):Libreria(title,autor),durataOre(n){}

    void print() {
        cout << "DVD" <<endl;

        cout << "Titolo -> " << titolo <<endl;
        cout << "Autore -> " << autore <<endl;
        cout << "Durata (in ore) -> " << durataOre <<endl;
        cout <<endl;
    }

    void insert(string title,string autor,float n){

        cout << "Inserimento Dvd" <<endl;
        titolo = title;
        autore = autor;
        durataOre = n;
    }

    void search(string title){
        if(title == titolo){
            cout << "Elemento trovato "<<endl;
            print();
            return;
        }else{
            cout << "Elemento non trovato" <<endl;
        }
    }

    private:
    float durataOre;
};


int main(){

/*Libro dati("1984","Meloso",100);
dati.print();

dati.insert("Harry Potter","J.K.Rowling",1000);
dati.print();

dati.search("HarryPotter");*/

Libreria **array = new Libreria*[4];

cout << "Inserisco 2 libri e 2 dvd" <<endl;

array[0] = new Libro("Harry Potter","J.K.Rowling",1000);

array[1] = new Libro("","",0);
array[1]->insert("1984","Meloso",300);

array[2] = new Dvd("Cars","Pixar",1.40);

array[3] = new Dvd("","",0);
array[3]->insert("Sherk","DreamWorks",1.50);

cout << "Stampo tutto" <<endl;
for(int i = 0; i < 4; i++){
    array[i]->print();
}

cout << "Cerco un titolo esistente e uno non esistente" <<endl;

for(int i = 0; i < 4; i++){     //esiste
    array[i]->search("Cars");
}

for(int i = 0; i < 4; i++){     //non esiste
    array[i]->search("Coco");
}

}