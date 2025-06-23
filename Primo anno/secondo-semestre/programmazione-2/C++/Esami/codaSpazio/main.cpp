#include <iostream>
using namespace std;

class Astronauta{
    public:
        Astronauta(int _codiceId, string _nome, string _nazionalita, float _oreVolo):codiceId(_codiceId),nome(_nome),nazionalita(_nazionalita), oreVolo(_oreVolo){}
        virtual int getCodice(){return codiceId;}
        string getNome(){return nome;}
        string getNazionalita(){return nazionalita;}
        float getOreVolo(){return oreVolo;}
    private:
        int codiceId;
        string nome;
        string nazionalita;
        float oreVolo;
};

ostream& operator<<(ostream& stream, Astronauta data){
    cout << data.getCodice() << ": " << data.getNome() << "("<< data.getNazionalita() << ") - " << "ore di volo: " << data.getOreVolo() << "h";
    return stream;
}
class AstronautaPremiato;
class Bonus{
    public:
        Bonus(int _valore, string _ente):valore(_valore), ente(_ente){}
        int getValore(){return valore;}
        string getEnte(){return ente;}
        friend ostream& operator<<(ostream& stream, AstronautaPremiato& data);
    private:
        int valore;
        string ente;
};

class AstronautaPremiato:public Astronauta{
    public:
        AstronautaPremiato(Astronauta* _astronauta, Bonus* _bonus):Astronauta(*(_astronauta)), bonus(_bonus){}
        friend ostream& operator<<(ostream& stream, AstronautaPremiato& data);
    private:
        Bonus* bonus;
};

ostream& operator<<(ostream& stream, AstronautaPremiato& data){
    cout << data.getCodice() << ": " << data.getNome() << "("<< data.getNazionalita() << ") - " << "ore di volo: " << data.getOreVolo() << "h";
    cout << " [bonus di " << data.bonus->getValore() << " da " << data.bonus->getEnte() << "]";
    return stream;
}

class Nodo{
    public:
        Nodo(Astronauta* _data = nullptr, Nodo* _next = nullptr):next(_next), data(_data){}
        friend class Coda;
    private:
        Nodo* next;
        Astronauta* data;
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
        }
        // dequeue(){

        // }
        void printCoda(){
            cout << "Di seguito la coda: " << endl;
            Nodo* tempHead = head;
            while(tempHead != nullptr){
                if(dynamic_cast<AstronautaPremiato*>(tempHead->data)){
                    cout << *(dynamic_cast<AstronautaPremiato*>(tempHead->data)) << endl;
                }else{
                    cout << *(tempHead->data)<< endl;
                }
                tempHead = tempHead->next;
            }
        }
    private:
        Nodo* head;
        Nodo* tail;
};

int main(){

    Coda coda;
    coda.enqueue(new Nodo(new Astronauta(1,"Neil","USA",2000)));
    coda.enqueue(new Nodo(new AstronautaPremiato(new Astronauta(2,"Yuri","Russia",1500), new Bonus(50000, "Roscosmos"))));
    coda.enqueue(new Nodo(new Astronauta(3,"Samantha","IT",1800)));
    coda.enqueue(new Nodo(new Astronauta(4,"Buzz","USA",900)));
    coda.enqueue(new Nodo(new AstronautaPremiato(new Astronauta(5,"Valentina","Russia",800), new Bonus(30000, "ESA"))));
    coda.enqueue(new Nodo(new Astronauta(6,"Chris","Canada",1700)));
    coda.enqueue(new Nodo(new Astronauta(7,"Pedro","Spagna",400)));
    coda.enqueue(new Nodo(new AstronautaPremiato(new Astronauta(8,"Jessica","USA",2200), new Bonus(60000, "NASA"))));
    coda.printCoda();

    return 0;
}


