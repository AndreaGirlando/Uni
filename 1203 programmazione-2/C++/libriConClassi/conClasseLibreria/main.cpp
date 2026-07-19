

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include "libro.cpp"
using namespace std;

const int MAX_LIBRI = 20;
const string FILENAME = "archivio.txt";

class Libreria{
    public:
        Libreria(int _maxLibri)
            :maxLibri(_maxLibri), counterLibri(0)
        {
            this->archivio = new Libro[this->maxLibri];
        }

        void printInfo(){
            cout << this->counterLibri << endl;
            cout << this->maxLibri << endl;
        }
        bool inserisciLibro(Libro& libro){
            if(this->counterLibri >= MAX_LIBRI) return false;

            archivio[this->counterLibri].copia_da(libro);

            this->counterLibri++;
            return true;
        }

        void stampaLibri(){
            for(int i = 0; i<this->counterLibri; i++){
                cout << "<---------------->";
                this->archivio[i].stampa();
                cout << "<---------------->" << endl;
            }
        }

        void MemorizzaArchivio(string nomeFile){
            ofstream file(nomeFile, ios::out); //instanza del tipo file, ios::out ci indica che fa aperto in modalità "w"
            if(file.fail()){
                cout << "Errore nell'apertura del file";
                return;
            }
            file << this->counterLibri << endl;

            for(int i = 0; i<this->counterLibri;i++){
                this->archivio[i].scriviSuFile(file);
            }
            file.close();

            return;
        }
        void CaricaArchivio(string nomeFile){
            ifstream file(nomeFile,ios::in);

            file >> this->counterLibri;
            file.get();
            for(int i = 0; i<this->counterLibri;i++){ //Carico ogni libro
                this->archivio[i].leggiDaFile(file);
            }
            cout << "Hai caricato " << this->counterLibri << " libri dall'archivio con successo!\n\n";
            file.close();
            return;
        }

        void cercaLibro(string titolo){
            for(int i = 0; i<this->counterLibri; i++){
                if(this->archivio[i].getTitolo() == titolo){
                    cout << "<---------------->";
                    this->archivio[i].stampa();
                    cout << "<---------------->" << endl;
                    return;
                }
            }
            cout << "<---------------->" << endl;
            cout << "Libro non trovato" << endl;
            cout << "<---------------->" << endl;
            return;
        }
    private:
        int counterLibri;
        int maxLibri;
        Libro* archivio;
};


int main(){
    int scelta = 0;
    Libreria archivio(20);//dichiarazione archivio
    archivio.CaricaArchivio(FILENAME);
    do{
        cout << "Premi un tasto per continuare...";
        getchar();
        system("clear");
        cout << "1. Inserisci un libro" << endl;
        cout << "2. Stampa tutti i libri dell'archivio" << endl;
        cout << "3. Cerca un libro per titolo" << endl;
        cout << "4. Memoriazza archivio su file" << endl;
        cout << "0. Termina il programma" << endl;
        cout << "Scegli l'operazione: " << endl;

        cin >> scelta;
        cin.get(); //per togliere lo \n dal buffer di tastiera si puo usare anche cin.ignore()

        string titolo;
        string autore;
        int annoPubblicazione;
        float prezzo;
        char genere[MAX_LEN_GENERE];

        switch(scelta){
            case 0: {
                break;
            }
            case 1:{

                cout << "Inserisci il titolo: ";
                getline(cin,titolo);

                cout << "Inserisci l'autore: ";
                getline(cin,autore);//definito nella standard library

                cout << "Inserisci anno di pubblicazione: ";
                cin >> annoPubblicazione;

                cout << "Inserisci il prezzo: ";
                cin >> prezzo;

                cout << "Inserisci il genere: ";
                cin.ignore();//usare questo comando ci permette di cancella lo \n del cin precendente
                cin.getline(genere,21);

                Libro l(titolo,autore,annoPubblicazione,prezzo,genere);

                if(!archivio.inserisciLibro(l)){
                    cout << "Archivio Pieno" << endl;
                }
                break;
            }

            case 2: {
                archivio.stampaLibri();
                break;
            }
            case 3: {
                cout << "Inserisci il titolo: ";
                getline(cin,titolo);
                archivio.cercaLibro(titolo);
                break;
            }
            case 4: {
                cout << "Memorizzo l'archivio su file" << endl;
                archivio.MemorizzaArchivio(FILENAME);
                break;
            }
            default: {
                cout << "Scelta non valida" << endl;
            }
        }

    }while(scelta != 0);

    cout << "Fine programma" << endl;
    return 0;

    return 0;
}


