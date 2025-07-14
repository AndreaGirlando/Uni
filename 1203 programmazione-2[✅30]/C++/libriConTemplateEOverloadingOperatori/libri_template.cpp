// Scrivere un programma in C++ per gestire un archivio di libri

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

const int MAX_LEN_GENERE = 21;

class Libro {
public:
    Libro() {}

    Libro(const char* _titolo, const char* _autore, int _annoPubl, float _prezzo, const char* _genere)
        : titolo(_titolo), autore(_autore), annoPubblicazione(_annoPubl),prezzo(_prezzo)
    {
        strncpy(genere,_genere,MAX_LEN_GENERE);
        genere[MAX_LEN_GENERE-1]='\0';
    }

    Libro(const Libro& altro)
    {
        *this = altro;
    }

    Libro& operator=(const Libro& altro){
        cout << "Effettuo la copia del libro usando l'operatore implementato" << endl;
        titolo = altro.titolo;
        autore = altro.autore;
        annoPubblicazione = altro.annoPubblicazione;
        prezzo = altro.prezzo;
        strncpy(genere, altro.genere,MAX_LEN_GENERE);
        genere[MAX_LEN_GENERE-1]='\0';
        return *this;
    }

    // void copia_da(const Libro& altro)
    // {
    //     titolo = altro.titolo;
    //     autore = altro.autore;
    //     annoPubblicazione = altro.annoPubblicazione;
    //     prezzo = altro.prezzo;
    //     strncpy(genere, altro.genere,MAX_LEN_GENERE);
    //     genere[MAX_LEN_GENERE-1]='\0';
    // }

    string GetTitolo()
    {
        return titolo;
    }

    void scrivi(ostream& file) {
        file << titolo << endl;
        file << autore << endl;
        file << annoPubblicazione << endl;
        file << prezzo << endl;
        file << genere << endl;
    }

    void leggi(istream& file) {
        getline(file, titolo);
        getline(file, autore);
        file >> annoPubblicazione;
        file.get();
        file >> prezzo;
        file.get();
        file.getline(genere, 21);
    }

    void stampa() {
        cout << "Titolo: " << titolo << endl;
        cout << "Autore: " << autore << endl;
        cout << "Anno di pubblicazione: " << annoPubblicazione << endl;
        cout << "Prezzo: " << prezzo << endl;
        cout << "Genere: " << genere << endl;
        cout << endl;
    }
private:
    string titolo;
    string autore;
    int annoPubblicazione;
    float prezzo;
    char genere[MAX_LEN_GENERE];
};

template <typename T>
class Archivio
{
public:
    Archivio() : num_items(0) {}
    bool Inserisci(const T& libro);
    void Stampa();
    void Save(const char* nomefile);
    bool Load(const char* nomefile);
protected:
    static const int MAX_ITEMS = 20;
    Libro archivio[MAX_ITEMS];
    int num_items;
};

class Libreria : public Archivio<Libro>
{
public:
    void CercaLibro(string titolo);
};

int main() {
    Libreria lib;

    if (lib.Load("archivio.txt") == false)
        cout << "Archivio non presente" << endl;

    int scelta;
    do {
        cout << "_____________________________________________________" << endl;
        cout << "1. Inserisci un libro" << endl;
        cout << "2. Stampa tutti i libri dell'archivio" << endl;
        cout << "3. Cerca un libro per titolo" << endl;
        cout << "4. Memorizza l'archivio su file" << endl;
        cout << "5. Carica l'archivio da file" << endl;
        cout << "0. Termina il programma" << endl;
        cout << "_____________________________________________________" << endl;
        cout << "Scegli l'operazione: ";
        cin >> scelta;
        cin.get();
        cout << endl;

        string t,a;
        int anno;
        float p;
        char g[MAX_LEN_GENERE];
        switch (scelta)
        {
        case 1: {
            cout << "Inserisci il titolo: ";
            getline(cin, t);
            cout << "Inserisci l'autore: ";
            getline(cin, a);
            cout << "Inserisci l'anno di pubblicazione: ";
            cin >> anno;
            cin.get();
            cout << "Inserisci il prezzo: ";
            cin >> p;
            cin.get();
            cout << "Inserisci il genere: ";
            cin.getline(g, MAX_LEN_GENERE);
            cout << endl;
            Libro libro(t.c_str(),a.c_str(),anno,p,g);
            if (lib.Inserisci(libro) == false)
                cout << "Archivio pieno. Impossibile inserire" << endl;
            else
                cout << "Libro inserito" << endl;
            break;}
        case 2:
            lib.Stampa();
            break;
        case 3:
            cout << "Inserisci il titolo del libro da cercare: ";
            getline(cin, t);
            cout << endl;
            lib.CercaLibro(t);
            break;
        case 4:
            cout << "Memorizzo l'archivio su file" << endl;
            lib.Save("archivio.txt");
            break;
        case 5:
            cout << "Carico l'archivio da file" << endl;
            if (lib.Load("archivio.txt") == false)
                cout << "Errore nel caricamento dell'archivio" << endl;
            break;
        case 0:
            break;
        default:
            cout << "Scelta non valida" << endl;
        }
    } while(scelta != 0);

    cout << "A presto" << endl << endl;
    return 0;
}

template <typename T>
bool Archivio<T>::Inserisci(const T& libro) {
    if (num_items >= MAX_ITEMS)
        return false;
    archivio[num_items] = libro; // andrebbe implementato con l'operatore di copia
    num_items++;
    return true;
}

template <typename T>
void Archivio<T>::Stampa() {
    for (int i = 0; i < num_items; i++) {
        archivio[i].stampa();
    }
}

template <typename T>
void Archivio<T>::Save(const char* nomefile) {
    ofstream file(nomefile, ios::out);
    if (file.fail()) {
        cout << "Errore nel file" << endl;
        return;
    }
    file << num_items << endl;
    for (int i = 0; i < num_items; i++) {
        archivio[i].scrivi(file);
    }
    file.close();
}

template <typename T>
bool Archivio<T>::Load(const char* nomefile) {
    ifstream file(nomefile, ios::in);
    if (file.fail()) {
        return false;
    }
    file >> num_items;
    file.get();
    for (int i = 0; i < num_items; i++) {
        archivio[i].leggi(file);
    }
    file.close();
    return true;
}

void Libreria::CercaLibro(string titolo) {
    for(int i = 0; i < num_items; i++) {
        if(titolo==archivio[i].GetTitolo()) {
            cout << "Libro trovato:" << endl;
            archivio[i].stampa();
            return;
        }
    }
    cout << "Libro non trovato" << endl;
    cout << endl;
}
