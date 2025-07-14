

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
const int MAX_LEN_GENERE = 21;
const int MAX_LIBRI = 20;

//TODO creare la classe libreria che contenga tutti i vari metodi

class Libro{

    public://! Sezione pubblica

        //inizzializzatore di un costruttore vuoto per poter instanziare il vettore
        Libro(){}

        //?  Costruttore con vettore inizzializzazione
        Libro(string _titolo, string _autore, int _annoPubblicazione, float _prezzo, const char* _genere)
            : titolo(_titolo), autore(_autore), annoPubblicazione(_annoPubblicazione), prezzo(_prezzo)
        {
            strncpy(genere,_genere,MAX_LEN_GENERE); //Usiamo questa sintassi per in questo caso la stringa è nativa del C
            genere[MAX_LEN_GENERE-1] = '\0';
        }


        Libro(const Libro& altro){
            copia_da(altro);
        }

        //? Funzione che copia il il libro passato in this.libro
        void copia_da(const Libro& altro){
            titolo = altro.titolo;
            autore = altro.autore;
            annoPubblicazione = altro.annoPubblicazione;
            prezzo = altro.prezzo;
            strncpy(genere,altro.genere,MAX_LEN_GENERE);
            genere[MAX_LEN_GENERE-1] = '\0';
        }


        string getTitolo(){
            return titolo;
        }

        void stampa(){
            cout << endl;
            cout << "Titolo: " << this->titolo << endl;
            cout << "Autore: " << this->autore << endl;
            cout << "Anno pubblicazione: " << this->annoPubblicazione << endl;
            cout << "Prezzo: " << this->prezzo << endl;
            cout << "Genere: " << this->genere << endl;
        }


        void scriviSuFile(ofstream& file){
            if(file.fail()){
                cout << "Errore nell'apertura del file";
                return;
            }
            file << this->titolo << endl;
            file << this->autore << endl;
            file << this->annoPubblicazione << endl;
            file << this->prezzo << endl;
            file << this->genere << endl;
        }

        void leggiDaFile(ifstream& file){
            if(file.fail()){
                cout << "Errore nell'apertura del file";
                return;
            }
            getline(file,this->titolo);
            getline(file,this->autore);
            file >> this->annoPubblicazione;
            file.get(); //Per per leggere lo \n
            file >> this->prezzo;
            file.getline(this->genere,MAX_LEN_GENERE);
        }


    private://! Sezione privata
        string titolo;
        string autore;
        int annoPubblicazione;
        float prezzo;
        char genere[MAX_LEN_GENERE];
};

Libro archivio[MAX_LIBRI];//variabile globale che contiene 20 libri
int numLibri = 0;

//TODO implementare tutte queste funzioni
bool inserisciLibro(Libro& libro);
void stampaLibri();
void MemorizzaArchivio();
void CaricaArchivio();
void cercaLibro(string titolo);

int main(){
    int scelta = 0;
    do{
        cout << "\n\n";
        cout << "1. Inserisci un libro" << endl;
        cout << "2. Stampa tutti i libri dell'archivio" << endl;
        cout << "3. Cerca un libro per titolo" << endl;
        cout << "4. Memoriazza archivio su file" << endl;
        cout << "0. Termina il programma" << endl;
        cout << "Scegli l'operazione: " << endl;

        cin >> scelta;
        cin.get(); //per togliere lo \n dal buffer di tastiera si puo usare anche cin.ignore()

        CaricaArchivio();


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

                if(!inserisciLibro(l)){
                    cout << "Archivio Pieno" << endl;
                }
                break;
            }

            case 2: {
                stampaLibri();
                break;
            }
            case 3: {
                cout << "Inserisci il titolo: ";
                getline(cin,titolo);
                cercaLibro(titolo);
                break;
            }
            case 4: {
                cout << "Memorizzo l'archivio su file" << endl;
                MemorizzaArchivio();
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


bool inserisciLibro(Libro& libro){
    if(numLibri >= MAX_LIBRI) return false;

    archivio[numLibri].copia_da(libro);

    numLibri++;
    return true;
}

void stampaLibri(){
    for(int i = 0; i<numLibri; i++){
        cout << "<---------------->";
        archivio[i].stampa();
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
        archivio[i].scriviSuFile(file);
    }
    file.close();

    return;
}
void CaricaArchivio(){
    ifstream file("archivio.txt",ios::in);

    file >> numLibri;
    file.get();
    for(int i = 0; i<numLibri;i++){ //Carico ogni libro
        archivio[i].leggiDaFile(file);
    }
    cout << "Hai caricato " << numLibri << " libri dall'archivio con successo!\n\n";
    file.close();
    return;
}

void cercaLibro(string titolo){
    for(int i = 0; i<numLibri; i++){
        if(archivio[i].getTitolo() == titolo){
            cout << "<---------------->" << endl;
            archivio[i].stampa();
            cout << "<---------------->" << endl;
            return;
        }
    }
    cout << "<---------------->" << endl;
    cout << "Libro non trovato" << endl;
    cout << "<---------------->" << endl;
    return;
}