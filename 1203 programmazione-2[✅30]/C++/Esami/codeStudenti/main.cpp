#include <iostream>
using namespace std;

class StudenteBorsista;
class Studente{
    public:
        Studente(string _nome, string _cognome, int _matricola, double _media):nome(_nome), cognome(_cognome), matricola(_matricola), media(_media){}
        virtual ~Studente(){}
        string getNome(){return nome;}
        void setNome(string _nome){nome = _nome;}
        string getCognome(){return cognome;}
        void setCognome(string _cognome){cognome = _cognome;}
        int getMatricola(){return matricola;}
        void setMatricola(int _matricola){matricola = _matricola;}
        double getMedia(){return media;}
        void setMedia(double _media){media = _media;}
        friend ostream& operator<<(ostream& stream, Studente& studente);
        friend ostream& operator<<(ostream& stream, StudenteBorsista& studente);

    private:
        string nome;
        string cognome;
        int matricola;
        double media;
};
//"matricola: nome cognome - media [borsa di importo euro]",
ostream& operator<<(ostream& stream, Studente& studente){
    cout <<studente.matricola << ": " << studente.nome << " " << studente.cognome << " - " << studente.media;
    return stream;
}

class BorsaDiStudio{
    public:
        BorsaDiStudio(int _importo, int _durata):importo(_importo),durata(_durata){}
        int getDurata(){return durata;}
        void setDurata(int _durata){durata=_durata;}
        int getImporto(){return importo;}
        void setImporto(int _importo){importo=_importo;}
    private:
        int importo;
        int durata; //in giorni
};

class StudenteBorsista:public Studente{
    public:
        StudenteBorsista(Studente _studente, BorsaDiStudio* _borsa = nullptr):borsa(_borsa), Studente(_studente){}
        int getImportoBorsa(){
            return borsa->getImporto();
        }
        friend ostream& operator<<(ostream& stream, StudenteBorsista& studente);
    private:
        BorsaDiStudio* borsa;
};

ostream& operator<<(ostream& stream, StudenteBorsista& studente){
    cout <<studente.matricola << ": " << studente.nome << " " << studente.cognome << " - " << studente.media << " [borsa di " << studente.borsa->getImporto() << " euro]";
    return stream;
}

class Coda;
class Nodo{
    public:
        Nodo(Studente* _studente = nullptr, Nodo* _next = nullptr):studente(_studente), next(_next){}
        friend class Coda;
    private:
        Studente* studente;
        Nodo* next;
};

class Coda{
    public:
        Coda():head(nullptr), tail(nullptr){}
        void enqueue(Nodo* newNodo){
            if(head == nullptr && tail == nullptr){
                head = newNodo;
                tail = newNodo;
            }else{
                tail->next = newNodo;
                tail = newNodo;
            }
            len++;
        }
        Studente* dequeue(){
            Nodo* temp = head;
            Studente* res = nullptr;
            if(head == nullptr && tail == nullptr) return res;
            if(head == tail){
                head = nullptr;
                tail = nullptr;
                res = temp->studente;
                delete temp;
            }else{
                res = temp->studente;
                head = head->next;
                delete temp;
            }
            len--;
            return res;
        }
        void stampaCoda(){//metodo teoricamente illegale ma utile
            cout << "Di seguito la coda: " << endl;
            Nodo* tempHead = head;
            while(tempHead != nullptr){
                if(dynamic_cast<StudenteBorsista*>(tempHead->studente)){
                    cout << *(dynamic_cast<StudenteBorsista*>(tempHead->studente)) << endl;
                    tempHead = tempHead->next;
                }else{
                    cout << *(tempHead->studente) << endl;;
                    tempHead = tempHead->next;
                }
            }
            cout << "\n\n";
        }
        void checkMediaAndRemove(int media){
            int tempLen = len;
            Studente** studenti = new Studente*[tempLen];
            for(int i = 0; i<tempLen;i++){
                studenti[i] = dequeue();
            }
            for(int i = 0;i<tempLen;i++){
                if(studenti[i]->getMedia()>media){
                    enqueue(new Nodo(studenti[i]));
                }else{
                    cout << "Studente con media insufficiente (" << studenti[i]->getNome() << " " << studenti[i]->getMatricola() << ")" << endl;
                }
            }
        }
        int totaleBorseDiStudio(){
            Nodo* tempHead = head;
            int res = 0;
            while(tempHead!=nullptr){
                if(dynamic_cast<StudenteBorsista*>(tempHead->studente)){
                    res += dynamic_cast<StudenteBorsista*>(tempHead->studente)->getImportoBorsa();
                }
                tempHead = tempHead->next;
            }
            return res;
        }
    private:
        int len;
        Nodo* head;
        Nodo* tail;
};

int main(){

    Coda coda;
    coda.enqueue(new Nodo(new Studente("Mario","Rossi",1001,25.5)));
    coda.enqueue(new Nodo(new StudenteBorsista(*(new Studente("Anna","Verdi",1002,28.0)),new BorsaDiStudio(880,15))));
    coda.enqueue(new Nodo(new Studente("Luca","Bianchi",1003,26.0)));
    coda.enqueue(new Nodo(new Studente("Sara","Neri",1004,27.5)));
    coda.enqueue(new Nodo(new StudenteBorsista(*(new Studente("Marco","Gialli",1005,24.0)),new BorsaDiStudio(500,15))));
    coda.enqueue(new Nodo(new StudenteBorsista(*(new Studente("Laura","Marroni",1006,29.0)),new BorsaDiStudio(600,15))));

    coda.checkMediaAndRemove(25);
    coda.stampaCoda();
    cout << "Totale degli importi delle borse di studio: " << coda.totaleBorseDiStudio();
    cout << endl;
    return 0;
}