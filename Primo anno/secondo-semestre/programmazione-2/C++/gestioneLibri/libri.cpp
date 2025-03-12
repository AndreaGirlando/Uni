#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct Libro{
    string titolo;//Classe string per la gestione delle stringhe
    string autore;
    int annoPubblicazione;
    float prezzo;
    char genere[21];

    void stampa(){
        cout << "Titolo: " << this->titolo << endl;
        cout << "Autore: " << this->autore << endl;
        cout << "Anno pubblicazione: " << this->annoPubblicazione << endl;
        cout << "Prezzo: " << this->prezzo << endl;
        cout << "Genere: " << this->genere << endl;
    }
};

const int MAX_LIBRI = 20;
Libro archivio[MAX_LIBRI];//variabile globale che contiene 20 libri
int numLibri = 0;


bool inserisciLibro(Libro *libro);
void stampaLibri();
void MemorizzaArchivio();
void CaricaArchivio();
void cercaLibro(string titolo);
int main(){
    int scelta = 0;
    CaricaArchivio();
    do{
        cout << "1. Inserisci un libro" << endl;
        cout << "2. Stampa tutti i libri dell'archivio" << endl;
        cout << "3. Cerca un libro per titolo" << endl;
        cout << "4. Memoriazza archivio su file" << endl;
        cout << "0. Termina il programma" << endl;
        cout << "Scegli l'operazione: " << endl;

        cin >> scelta;
        cin.get(); //per togliere lo \n dal buffer di tastiera
        Libro libro;
        string titolo;

        switch(scelta){
            case 0:
                break;
            case 1:

                cout << "Inserisci il titolo: ";
                getline(cin,libro.titolo);

                cout << "Inserisci l'autore: ";
                getline(cin,libro.autore);//definito nella standard library

                cout << "Inserisci anno di pubblicazione: ";
                cin >> libro.annoPubblicazione;

                cout << "Inserisci il prezzo: ";
                cin >> libro.prezzo;

                cout << "Inserisci il genere: ";
                cin.ignore();
                cin.getline(libro.genere,21);

                if(!inserisciLibro(&libro)){
                    cout << "Archivio Pieno" << endl;
                }

                break;

            case 2:
                stampaLibri();
                break;
            case 3:
                cout << "Inserisci il titolo: ";
                getline(cin,titolo);
                cercaLibro(titolo);
                break;
            case 4:
                cout << "Memorizzo l'archivio su file" << endl;
                MemorizzaArchivio();
                break;
            default:
                cout << "Scelta non valida" << endl;
        }




    }while(scelta != 0);

    cout << "Fine programma" << endl;
    return 0;
}

bool inserisciLibro(Libro* libro){
    if(numLibri >= MAX_LIBRI) return false;
    cout << "\n\n\n";
    // libro->stampa();
    archivio[numLibri].titolo = libro->titolo;
    archivio[numLibri].autore = libro->autore;
    archivio[numLibri].annoPubblicazione = libro->annoPubblicazione;
    archivio[numLibri].prezzo = libro->prezzo;
    strcpy(archivio[numLibri].genere, libro->genere);

    numLibri++;
    return true;
}

void stampaLibri(){
    for(int i = 0; i<numLibri; i++){
        cout << "<---------------->" << endl;
        archivio[i].stampa();
        cout << "<---------------->" << endl;
    }
}

void cercaLibro(string titolo){
    for(int i = 0; i<numLibri; i++){
        if(archivio[i].titolo == titolo){
            cout << "<---------------->" << endl;
            archivio[i].stampa();
            cout << "<---------------->" << endl;
            break;
        }
        cout << "<---------------->" << endl;
        cout << "Libro non trovato" << endl;
        cout << "<---------------->" << endl;
    }
}

void MemorizzaArchivio(){
    ofstream file("archivio.txt", ios::out); //instanza del tipo file, ios::out ci indica che fa aperto in modalità "w"
    if(file.fail()){
        cout << "Errore nell'apertura del file";
        return;
    }
    file << numLibri << endl;

    for(int i = 0; i<numLibri;i++){
        file << archivio[i].titolo << endl;
        file << archivio[i].autore << endl;
        file << archivio[i].annoPubblicazione << endl;
        file << archivio[i].prezzo << endl;
        file << archivio[i].genere << endl;
    }
    file.close();

    return;
}

void CaricaArchivio(){
    ifstream file("archivio.txt",ios::in);

    if(file.fail()){
        cout << "Errore nell'apertura del file";
        return;
    }

    file >> numLibri; //Carico il numero di libri

    for(int i = 0; i<numLibri;i++){ //Carino ogni libro
        file >> archivio[i].titolo;
        file >> archivio[i].autore;
        file >> archivio[i].annoPubblicazione;
        file >> archivio[i].prezzo;
        file >> archivio[i].genere;
    }
    cout << "Hai caricato " << numLibri << " libri dall'archivio con successo!\n\n";
    return;
}
