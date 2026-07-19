// 21:44
#include <iostream>
#include <fstream>
using namespace std;
class Studente{
    public:
        Studente(string _matricola, string _nome, string _cognome, float _media):matricola(_matricola), nome(_nome), cognome(_cognome), media(_media){}
        string getMatricola(){ return matricola; }
        string getNome(){ return nome; }
        string getCognome(){ return cognome; }
        float getMedia(){ return media; }
        virtual void stampa(){
            cout << matricola << ": " << nome << " " << cognome << " - " << media;
        }
    private:
        string matricola;
        string nome;
        string cognome;
        float media;
};

class BorsaDiStudio{
    public:
        BorsaDiStudio(float _importo, int _durata): durata(_durata), importo(_importo) {}
        float getImporto() { return importo; }
        void setImporto(float tempImporto) { importo = tempImporto; }
        int getDurata() { return durata; }
        void setDurata(float tempDurata) { durata = tempDurata; }
    private:
        float importo;
        int durata; //numero di giorni
};

class StudenteBorsista: public Studente{
    public:
        StudenteBorsista(string _matricola, string _nome, string _cognome, float _media, float _importo, int _durata):Studente(_matricola,_nome,_cognome,_media){
            borsa = new BorsaDiStudio(_importo, _durata);
        }
        float get_importo_borsa(){
            return  borsa->getImporto();
        }
        void stampa(){
            //matricola: nome cognome - media [borsa di importo euro]",
            cout << getMatricola() << ": " << getNome() << " " << getCognome() << " - " << getMedia() << " [borsa di " << borsa->getImporto() << " euro]";
        }
    private:
        BorsaDiStudio* borsa;
};

class Pila;
class Nodo{
    public:
        Nodo(StudenteBorsista* _data, Nodo* _next = nullptr): data(_data), next(_next){}
        friend class Pila;
    private:
        StudenteBorsista* data;
        Nodo* next;
};

class Pila{
    public:
        Pila():head(nullptr), len(0){}

        void push(Nodo* newNodo){
            newNodo->next = head;
            head = newNodo;
            len++;
        }

        Nodo* pop(){
            if(isEmpty()) return nullptr;
            Nodo* tempHead = head;
            head = head->next;
            len--;
            return tempHead;
        }

        void checkMediaAndRemove(int media){
            int lenPila = len;
            Nodo** array = new Nodo*[lenPila];
            for(int i = lenPila-1; i>=0; i--){
                array[i] = this->pop();
            }
            for(int i = 0;i<lenPila;i++){
                if(array[i]->data->getMedia() > media){
                    push(array[i]);
                }else{
                    cout << "Studente insufficiente rimosso: ";
                    array[i]->data->stampa();
                }
            }
        }

        void printPilaAndTotal(){
            cout << "\n\n";
            float sum = 0;
            Nodo* tempHead = head;
            while(tempHead != nullptr){
                tempHead->data->stampa();
                cout << endl;
                sum += tempHead->data->get_importo_borsa();
                tempHead = tempHead->next;
            }
            cout << "\n\nTotale delle borse di studio: " << sum << " euro \n\n\n";
        }

        void importFromFile(string filename){
            ifstream file(filename);
            if(file.fail()){
                cout << "Errore nella lettura del file";
                exit(EXIT_FAILURE);
            }
            while(!file.eof()){
                string matricola,nome,cognome;
                float media,importo;
                int durata;

                file >> matricola;
                file >> nome;
                file >> cognome;
                file >> media;
                file >> importo;
                file >> durata;


                push(new Nodo(new StudenteBorsista(matricola,nome,cognome,media,importo,durata)));
            }
        }
        bool isEmpty(){
            return head == nullptr;
        }
    private:
        Nodo* head;
        int len;
};



int main(){

    Pila pila;


    pila.importFromFile("input.txt");
    pila.checkMediaAndRemove(25);
    pila.printPilaAndTotal();


    cout << "\n\n\n\n\n";
    return 0;;
}