#include <iostream>
#include <time.h>
using namespace std;

class Steam;
class Gioco{
    public:
    Gioco(string _nome, string _genere, int _durata, float _voto, Gioco* _next = nullptr)
    :nome(_nome),genere(_genere),durata(_durata),voto(_voto), next(_next){}
    friend ostream& operator<<(ostream& stream, Gioco& gioco);
    friend class Steam;
    private:
    string nome;
    string genere;
    int durata;
    float voto;
    Gioco* next;
};

ostream& operator<<(ostream& stream, Gioco& gioco){

    if(&gioco == nullptr){
        stream << "null";
        return stream;
    }
    stream << "----------------------------------------\n";
    stream << "Campo\t\tValore\n";
    stream << "----------------------------------------\n";
    stream << "Nome:\t\t" << gioco.nome << "\n";
    stream << "Genere:\t\t" << gioco.genere << "\n";
    stream << "Durata:\t\t" << gioco.durata << "\n";
    stream << "Voto:\t\t" << gioco.voto << "\n";
    stream << "Next:\t\t" << gioco.next << "\n";
    stream << "----------------------------------------\n";

    return stream;
}

class Steam{
    public:
        Steam(Gioco* _head = nullptr): head(_head){};
        ~Steam(){
            Gioco* tempHead = head;
            while(tempHead != nullptr){
                Gioco* temp = tempHead;
                tempHead = tempHead->next;
                delete temp;
            }
        }
        void addGiocoHead(Gioco* newGame){
            newGame->next = head;
            head = newGame;
        };
        void addGiocoOrdered(Gioco* newGame){

            Gioco* tempHead = head;
            Gioco* prev = nullptr;

            while(tempHead != nullptr && newGame->durata < tempHead->durata){
                prev = tempHead;
                tempHead = tempHead->next;
            }

            if(head == nullptr || prev == nullptr){
                newGame->next = head;
                head = newGame;
                return;
            }

            newGame->next = prev->next;
            prev->next = newGame;

        };
        void removeGiocoHead(){
            cout << "Eliminazione elemento in testa..." << endl;
            Gioco* temp = head;
            head = head->next;
            delete temp;
        }
        void removeGioco(string nome){
            if(head == nullptr) return;

            Gioco* tempHead = head;
            Gioco* prev = nullptr;
            while(tempHead != nullptr){

                if(tempHead->nome == nome){
                    if(prev == nullptr){
                        this->removeGiocoHead();
                        return;
                    }

                    Gioco* temp = prev->next;
                    prev->next = tempHead->next;
                    delete temp;
                    return;
                }

                prev = tempHead;
                tempHead = tempHead->next;
            }

        }
        Gioco* findGioco(string nome){
            cout << "Ricerca del gioco in corso..." << endl;
            Gioco* tempHead = head;
            while(tempHead != nullptr){
                if(tempHead->nome == nome){
                    return tempHead;
                }
                tempHead = tempHead->next;
            }
            return nullptr;
        }
        void stampaLibreria(){
            cout << "Di seguito la libreria dei tuoi giochi: \n";
            if(head == nullptr){
                cout << "Nessun gioco trovato." << endl;
                return;
            }
            Gioco* tempHead = head;
            while(tempHead != nullptr){
                cout << *(tempHead);
                tempHead = tempHead->next;
            }

        }

    private:
        Gioco *head;
};

int main(){
    // srand(time(NULL));
    Steam steam;

    for(int i = 0; i<5; i++){
        steam.addGiocoOrdered(new Gioco(to_string(rand()%256),to_string(rand()%256),rand()%256,rand()%256));
    }
    steam.stampaLibreria();

    for(int i = 0; i<5; i++){
        steam.removeGiocoHead();
    }

    steam.stampaLibreria();
    cout << "\n\n\n";
    return 0;
}