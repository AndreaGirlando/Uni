// Scrivere un programma in C++ per gestire un archivio di libri

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

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
        cout << endl;
    }   
};

const int MAX_LIBRI = 20;
// non è buona norma usare variabili globali, ma per il momento va bene
Libro archivio[MAX_LIBRI];
int num_libri = 0;

bool InserisciLibro(Libro* libro); 
void StampaLibri();
void CercaLibro(string titolo);
void MemorizzaArchivio(const char* nomefile);
bool CaricaArchivio(const char* nomefile);

int main() {
    if (CaricaArchivio("archivio.txt") == false)
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
            cout << endl;
            if (InserisciLibro(&libro)== false)
                cout << "Archivio pieno. Impossibile inserire" << endl;
            else
                cout << "Libro inserito" << endl;
            break;
        case 2:
            StampaLibri();
            break;
        case 3:
            cout << "Inserisci il titolo del libro da cercare: ";
            getline(cin, titolo);
            cout << endl;
            CercaLibro(titolo);
            break;
        case 4:
            cout << "Memorizzo l'archivio su file" << endl;
            MemorizzaArchivio("archivio.txt");
            break;
        case 5:
            cout << "Carico l'archivio da file" << endl;
            if (CaricaArchivio("archivio.txt") == false)
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

void CercaLibro(string titolo) {
    for(int i = 0; i < num_libri; i++) {
        if(titolo==archivio[i].titolo) {
            cout << "Libro trovato:" << endl;
            archivio[i].stampa();
            return;
        }
    }
    cout << "Libro non trovato" << endl;
    cout << endl;
}

void MemorizzaArchivio(const char* nomefile) {
    fstream file(nomefile, ios::out);
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

bool CaricaArchivio(const char* nomefile) {
    ifstream file(nomefile, ios::in);
    if (file.fail()) {
        return false;
    }
    file >> num_libri;
    file.get();
    for (int i = 0; i < num_libri; i++) {
        getline(file, archivio[i].titolo);
        getline(file, archivio[i].autore);
        file >> archivio[i].annoPubblicazione;
        file.get();
        file >> archivio[i].prezzo;
        file.get();
        file.getline(archivio[i].genere, 21);
    }
    file.close();
    return true;
}
    
