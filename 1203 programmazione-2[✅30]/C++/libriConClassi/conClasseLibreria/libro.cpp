#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
const int MAX_LEN_GENERE = 21;
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
            file.get();
            file.getline(this->genere,MAX_LEN_GENERE);
        }


    private://! Sezione privata
        string titolo;
        string autore;
        int annoPubblicazione;
        float prezzo;
        char genere[MAX_LEN_GENERE];
};