/*
    Gestione di una lista di libri in una Biblioteca
    Crea un programma in c++ utilizzando la programmazione orientata agli oggetti
    per gestire una lista collegata di libri in una biblioteca
    Requisiti:
    Definisci una classe Book con i seguenti attributi
    Titolo string
    Autore string
    Anno int
    Definisci una classe BookList che implementa una lista collegata semplice per gestire i libri
    Metodo addBook(const Book&) aggiunge un libro
    Metodo removeBook(const string title)
    Metodo displaybooks()
    Metodo findBook(); cerca un libro per titolo e ne stampa i dettagli
*/
#include <iostream>
#include <fstream> //libreria che contiene ofstream e ifstream le classi utili per la gestione dei file
#include <cstring>
#include <limits>  // Includere per numeric_limits
using namespace std;
class Book{
    public:
        Book(){}
        Book(string _titolo, string _autore, int _anno): titolo(_titolo), autore(_autore), anno(_anno){}
        string getTitolo(){
            return titolo;
        }
        string getAutore(){
            return autore;
        }
        int getAnno(){
            return anno;
        }
        Book* getNext(){
            return next;
        }

        void setTitolo(string _titolo){
            titolo = _titolo;
        }
        void setAutore(string _autore){
            autore = _autore;
        }
        void setAnno(int _anno){
            anno = _anno;
        }
        void setNext(Book* _next){
            next = _next;
        }


    private:
        string titolo;
        string autore;
        int anno;
        Book* next;
};

ostream& operator<<(ostream& stream,Book& book){
    stream << "Titolo: " << book.getTitolo();
    stream << " Autore: " << book.getAutore();
    stream << " Anno: " << book.getAnno();
    stream << " Next: " << book.getNext() << "\n\n";
    return stream;
}

class BookList{
    public:
        BookList():head(nullptr){};

        void scriviSuArchivio(string nomeFile){
            ofstream file(nomeFile, ios::out);
            if(file.fail()){
                cout << "Errore nell'apertura del file";
                return;
            }
            Book* tempHead = head;
            file << this->getLen() << endl;
            while(tempHead != nullptr){
                file << tempHead->getTitolo() << endl;
                file << tempHead->getAutore() << endl;
                file << tempHead->getAnno() << endl;

                tempHead = tempHead->getNext();
            }
            file.close();
            return;
        }
        void caricaDaArchivio(string nomeFile){
            ifstream file(nomeFile, ios::in);
            if(file.fail()){
                cout << "Errore nell'apertura del file";
                return;
            }
            int len = 0;
            file >> len;
            string titolo,autore;
            int anno;

            for (int i = 0;i<len;i++){
                file >> titolo;
                file >> autore;
                file >> anno;
                this->addBook(new Book(titolo,autore,anno));
            }

        }
        void addBook(Book* newBook){
            newBook->setNext(head);
            head = newBook;
        }
        void displayBooks(){
            cout << "\n\nLista dei libri:\n\n";
            Book* tempHead = head;
            if(tempHead == nullptr) cout << "Nessun libro trovato\n";
            while(tempHead != nullptr){
                cout << *(tempHead);
                tempHead = tempHead->getNext();
            }
        }
        void removeBook(const string title){
            cout << "\nRimozione del libro in corso... \n";

            Book* tempHead = head;
            Book* prev = nullptr;
            while(tempHead != nullptr){
                if(tempHead->getTitolo() == title){

                    if(prev == nullptr){
                        head = tempHead->getNext();
                        return;
                    }else{
                        prev->setNext(tempHead->getNext());
                        return;
                    }

                    delete tempHead;
                }
                prev = tempHead;
                tempHead = tempHead->getNext();
            }

        }
        Book* findBook(const string title){
            cout << "\nRicerca del libro in corso...\n";
            Book* tempHead = head;
            while(tempHead != nullptr){
                // cout << tempHead << endl;
                if(tempHead->getTitolo() == title){
                    cout << *(tempHead);
                    return tempHead;
                }
                tempHead = tempHead->getNext();
            }
            cout << "Libro non trovato";
            return nullptr;
        }

    private:
        int getLen(){
            Book* tempHead = head;
            int len = 0;
            while(tempHead != nullptr){
                len++;
                tempHead = tempHead->getNext();
            }
            return len;
        }
        Book* head;
};

int main(){
    int choice = 0;
    string tempTitolo, tempAutore;
    int tempAnno;
    BookList libreria;

    do{
        if(choice != 0) cout << "\n\n\n";
        cout << "\n\n<------------------>\n";
        cout << "0) Chiudi" << endl;
        cout << "1) Aggiungi libro" << endl;
        cout << "2) Rimuovi libro (by titolo)" << endl;
        cout << "3) Stampa lista dei libri" << endl;
        cout << "4) Cerca info su un libro (by titolo)" << "\n\n";
        cout << "5) Carica archivio" << endl;
        cout << "6) Salva in archivio" << endl;
        cout << "Che cosa vuoi fare?" << endl;

        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Inserisci il titolo: ";
            getline(cin, tempTitolo);
            cout << "Inserisci l'autore: ";
            getline(cin, tempAutore);
            cout << "Inserisci l'anno di uscita: ";
            cin >> tempAnno;
            cin.ignore(); // elimina il newline dopo l’int

            libreria.addBook(new Book(tempTitolo, tempAutore, tempAnno));
            break;

        case 2:
            cout << "Inserisci il titolo: ";
            getline(cin, tempTitolo);
            libreria.removeBook(tempTitolo);
            break;

        case 3:
            libreria.displayBooks();
            break;

        case 4:
            cout << "Inserisci il titolo: ";
            getline(cin, tempTitolo);
            libreria.findBook(tempTitolo);
            break;

        case 5:
            cout << "Inserisci il nome del file: ";
            getline(cin, tempTitolo); // niente ignore dopo
            if (strstr(tempTitolo.c_str(), ".txt") == nullptr)
                tempTitolo += ".txt";

            libreria.caricaDaArchivio(tempTitolo);
            break;

        case 6:
            cout << "Inserisci il nome del file: ";
            getline(cin, tempTitolo); // niente ignore dopo
            if (strstr(tempTitolo.c_str(), ".txt") == nullptr)
                tempTitolo += ".txt";

            libreria.scriviSuArchivio(tempTitolo);
            break;

        default:
            cout << "Inserisci un valore valido\n";
            break;
        }

    } while (choice != 0);

    cout << "\nUscita dal programma...\n";
    return 0;
}
