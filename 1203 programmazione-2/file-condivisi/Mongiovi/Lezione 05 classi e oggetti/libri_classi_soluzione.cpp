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
        copia_da(altro);
    }

    void copia_da(const Libro& altro)
    {
        titolo = altro.titolo;
        autore = altro.autore;
        annoPubblicazione = altro.annoPubblicazione;
        prezzo = altro.prezzo;
        strncpy(genere, altro.genere,MAX_LEN_GENERE);        
        genere[MAX_LEN_GENERE-1]='\0';
    }

    string GetTitolo()
    {
        return titolo;
    }

    void scrivi(fstream& file) {
        file << titolo << endl;
        file << autore << endl;
        file << annoPubblicazione << endl;
        file << prezzo << endl;
        file << genere << endl;
    }

    void leggi(ifstream& file) {
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

class Libreria
{
public:
    Libreria() : num_libri(0) {}
    bool InserisciLibro(const Libro& libro); 
    void StampaLibri();
    void CercaLibro(string titolo);
    void MemorizzaArchivio(const char* nomefile);
    bool CaricaArchivio(const char* nomefile);
private:
    static const int MAX_LIBRI = 20;
    Libro archivio[MAX_LIBRI];
    int num_libri;
};

int main() {
    Libreria lib;

    if (lib.CaricaArchivio("archivio.txt") == false)
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
            if (lib.InserisciLibro(libro) == false)
                cout << "Archivio pieno. Impossibile inserire" << endl;
            else
                cout << "Libro inserito" << endl;
            break;}
        case 2:
            lib.StampaLibri();
            break;
        case 3:
            cout << "Inserisci il titolo del libro da cercare: ";
            getline(cin, t);
            cout << endl;
            lib.CercaLibro(t);
            break;
        case 4:
            cout << "Memorizzo l'archivio su file" << endl;
            lib.MemorizzaArchivio("archivio.txt");
            break;
        case 5:
            cout << "Carico l'archivio da file" << endl;
            if (lib.CaricaArchivio("archivio.txt") == false)
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

bool Libreria::InserisciLibro(const Libro& libro) {
    if (num_libri >= MAX_LIBRI) 
        return false;
    archivio[num_libri].copia_da(libro);
    num_libri++;
    return true;
}
    
void Libreria::StampaLibri() {
    for (int i = 0; i < num_libri; i++) {
        archivio[i].stampa();
    }
}

void Libreria::CercaLibro(string titolo) {
    for(int i = 0; i < num_libri; i++) {
        if(titolo==archivio[i].GetTitolo()) {
            cout << "Libro trovato:" << endl;
            archivio[i].stampa();
            return;
        }
    }
    cout << "Libro non trovato" << endl;
    cout << endl;
}

void Libreria::MemorizzaArchivio(const char* nomefile) {
    fstream file(nomefile, ios::out);
    if (file.fail()) {
        cout << "Errore nel file" << endl;
        return;
    }
    file << num_libri << endl;
    for (int i = 0; i < num_libri; i++) {
        archivio[i].scrivi(file);
    }
    file.close();
}

bool Libreria::CaricaArchivio(const char* nomefile) {
    ifstream file(nomefile, ios::in);
    if (file.fail()) {
        return false;
    }
    file >> num_libri;
    file.get();
    for (int i = 0; i < num_libri; i++) {
        archivio[i].leggi(file);
    }
    file.close();
    return true;
}
    
