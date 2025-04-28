I template vengono usati per generalizzare ancora di più l'uso di una funzione, usando i template infatti riusciamo a generalizzare il tipo richiesto/ritornato da una funzione. Questa cosa la facciamo con la seguente sintassi
```cpp
template<typename nomeTipoGenerico> tipoDiRitornoFunzione nomeFunzione(nomeTipoGenerico valore){}
```
Una possibile applicazione dei template è quella di seguito
```cpp
template<typename Type> void Print(Type valore){
    cout << valore << endl;
}

int main(){
    Print(5);
    Print("Ciao");
    Print(5.5f);
    Print<int>(12);//Possiamo anche specificare il tipo, il compilatore ci segnalerà eventuali errori di sintassi
    return 0;
}
```
```Output
5
Ciao
5.5
```
Questo codice senza usare i template diventava molto più lungo, in quanto andavano create delle funzioni Print() per ogni nuovo tipo necessario. Come tipo possiamo usare ovviamente delle classi come fatto di seguito.
```cpp
#include <iostream>
using namespace std;

//definizione di una classe molto semplice
class Libro{
    public:
	    Libro(string _isbn): isbn(_isbn){}
	    friend ostream& operator<<(ostream& stream, Libro& libro);
    private:
	    string isbn;
};
//overload dell'operatore << per far funzionare il cout usato nella funzione print
ostream& operator<<(ostream& stream, Libro& libro){
    stream << libro.isbn << endl;
    return stream;
}

//Template funzione di stampa
template<typename Type> void Print(Type valore){
    cout << valore << endl;
}


int main(){
    Print(5);
    Print("Ciao");
    Print(5.5f);
    Print(*(new Libro("Codice123")));//l'overload dell'operatore vuole la reference per stampare, new ritorna il puntatore
    return 0;
}
```