// Scrivere un programma in C++ per gestire un archivio di libri

#include <iostream>
#include <fstream>

using namespace std;

struct Libro {
    string titolo;
    string autore;
    int annoPubblicazione;
    float prezzo;
    char genere[21];

    void stampa() {
        cout << "Titolo: " << titolo << endl;
        cout << "Autore: " << autore << endl;
        cout << "Anno di pubblicazione: " << annoPubblicazione << endl;
        cout << "Prezzo: " << prezzo << endl;
        cout << "Genere: " << genere << endl;
    }   
};

const int MAX_LIBRI = 20;
Libro archivio[MAX_LIBRI];
int num_libri = 0;

bool InserisciLibro(Libro* libro); 
void StampaLibri();
void CercaLibro(string titolo);
void MemorizzaArchivio();

int main() {
    int scelta;
    do {
        cout << "1. Inserisci un libro" << endl;
        cout << "2. Stampa tutti i libri dell'archivio" << endl;
        cout << "3. Cerca un libro per titolo" << endl;
        cout << "4. Memorizza l'archivio su file" << endl;
        cout << "0. Termina il programma" << endl;
        cout << "Scegli l'operazione: ";
        cin >> scelta;
        cin.get(); 

        Libro libro;
        string titolo;
        switch (scelta)
        {
        case 1:
            cout << "Inserisci il titolo: ";
            getline(cin, libro.titolo);
            cout << "Inserisci l'autore: ";
            getline(cin, libro.autore);
            cout << "Inserisci l'anno di pubblicazione: ";
            cin >> libro.annoPubblicazione;
            cin.get();
            cout << "Inserisci il prezzo: ";
            cin >> libro.prezzo;
            cin.get();
            cout << "Inserisci il genere: ";
            cin.getline(libro.genere, 21);
            if (InserisciLibro(&libro)== false)
                cout << "Archivio pieno" << endl;
            break;
        case 2:
            StampaLibri();
            break;
        case 3:
            CercaLibro(titolo);
            break;
        case 4:
            cout << "Memorizzo l'archivio su file" << endl;
            MemorizzaArchivio();
            break;
        default:
            cout << "Scelta non valida" << endl;
        }


    } while(scelta != 0);

    cout << "A presto" << endl;
    return 0;
}

bool InserisciLibro(Libro* libro) {
    if (num_libri >= MAX_LIBRI) 
        return false;
    archivio[num_libri].titolo = libro->titolo;
    archivio[num_libri].autore = libro->autore;
    archivio[num_libri].annoPubblicazione = libro->annoPubblicazione;
    archivio[num_libri].prezzo = libro->prezzo;
    strcpy(archivio[num_libri].genere, libro->genere); 
    num_libri++;
    return true;
}
    
void StampaLibri() {
    for (int i = 0; i < num_libri; i++) {
        archivio[i].stampa();
    }
}

void CercaLibro(string titolo) {}

void MemorizzaArchivio() {
    fstream file("archivio.txt", ios::out);
    if (file.fail()) {
        cout << "Errore nel file" << endl;
        return;
    }
    file << num_libri << endl;
    for (int i = 0; i < num_libri; i++) {
        file << archivio[i].titolo << endl;
        file << archivio[i].autore << endl;
        file << archivio[i].annoPubblicazione << endl;
        file << archivio[i].prezzo << endl;
        file << archivio[i].genere << endl;
    }
    file.close();
}
    
