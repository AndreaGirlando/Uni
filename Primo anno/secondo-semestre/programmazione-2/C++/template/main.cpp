#include <iostream>
using namespace std;


class Libro{
    public:
    Libro(string _isbn): isbn(_isbn){}
    friend ostream& operator<<(ostream& stream, Libro& libro);
    private:
    string isbn;
};
ostream& operator<<(ostream& stream, Libro& libro){
    stream << libro.isbn << endl;
    return stream;
}



template<typename Type> void Print(Type valore){
    cout << valore << endl;
}

int main(){

    Print(5);
    Print("Ciao");
    Print(5.5f);

    Print(*(new Libro("Codice123")));


    return 0;
}