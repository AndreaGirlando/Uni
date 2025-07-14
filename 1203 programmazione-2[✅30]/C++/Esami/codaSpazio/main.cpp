#include <iostream>
using namespace std;

class Coda;
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
        friend class Coda;
    private:
        int valore;
        string ente;
};

class AstronautaPremiato:public Astronauta{
    public:
        AstronautaPremiato(Astronauta* _astronauta, Bonus* _bonus):Astronauta(*(_astronauta)), bonus(_bonus){}
        friend ostream& operator<<(ostream& stream, AstronautaPremiato& data);
        friend class Coda;
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
        Coda():head(nullptr), tail(nullptr), len(0){}
        ~Coda(){
            Nodo* tempHead = head;
            int tempLen = len;
            for(int i = 0; i<tempLen; i++){
                dequeue();
            }
        }
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
        Astronauta* dequeue(){
            if(head == nullptr) return nullptr;
            Nodo* res = head;
            Astronauta* astronauta = head->data;
            if(head == tail){
                head = nullptr;
                tail = nullptr;
                delete res;
                len--;
                return astronauta;
            }else{
                head = head->next;
                delete res;
                len--;
                return astronauta;
            }
        }
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
        int getValoreBonus(){
            Nodo* tempHead = head;
            int sum = 0;
            while(tempHead != nullptr){
                if(dynamic_cast<AstronautaPremiato*>(tempHead->data)){
                    sum += dynamic_cast<AstronautaPremiato*>(tempHead->data)->bonus->getValore();
                }
            }
            return sum;
        }
        void checkAndRemoveByHours(int ore){
            int tempLen = len;
            Astronauta** array = new Astronauta*[tempLen];
            for(int i = 0; i<tempLen; i++){
                array[i] = dequeue();
            }
            for(int i = 0; i<tempLen; i++){
                if(array[i]->getOreVolo() >= ore){
                    enqueue(new Nodo(array[i]));
                    // delete array[i];
                }
            }
            delete array;
        }
    private:
        int len;
        Nodo* head;
        Nodo* tail;
};
class BST;
class Missione{
    public:
        Missione(int _codiceMissione, string _nomeMissione, int _annoLancio):codiceMissione(_codiceMissione),nomeMissione(_nomeMissione),annoLancio(_annoLancio){}
        friend class BST;
        friend ostream& operator<<(ostream& stream, Missione& missione);
    private:
        int codiceMissione;
        string nomeMissione;
        int annoLancio;
};
ostream& operator<<(ostream& stream, Missione& missione){
    cout << "Codice: " << missione.codiceMissione;
    cout << " Nome: " << missione.nomeMissione;
    cout << " Anno di lancio: " << missione.annoLancio;
    return stream;
}

class BSTNode{
    public:
        BSTNode(Missione* _missione = nullptr, BSTNode* _sx = nullptr, BSTNode* _dx = nullptr, BSTNode* _padre = nullptr):missione(_missione), padre(_padre), sx(_sx), dx(_dx){}
        friend class BST;
    private:
        BSTNode* padre;
        BSTNode* sx;
        BSTNode* dx;
        Missione* missione;
};

class BST{
    public:
        BST():root(nullptr){}
        void insert(BSTNode* newNodo){
            BSTNode* tempRoot = root;
            BSTNode* prev = nullptr;
            if(root == nullptr){
                root = newNodo;
            }else{
                while(tempRoot != nullptr){
                    prev = tempRoot;
                    if(newNodo->missione->codiceMissione > tempRoot->missione->codiceMissione){
                        tempRoot = tempRoot->dx;
                    }else{
                        tempRoot = tempRoot->sx;
                    }
                }

                if(newNodo->missione->codiceMissione > prev->missione->codiceMissione){
                    prev->dx = newNodo;
                }else{
                    prev->sx = newNodo;
                }

            }
        }
        Missione* search(int codiceMissione){
            BSTNode* tempRoot = root;
            while(tempRoot != nullptr){
                if(tempRoot->missione->codiceMissione == codiceMissione){
                    return tempRoot->missione;
                }else if(codiceMissione > tempRoot->missione->codiceMissione){
                    tempRoot = tempRoot->dx;
                }else{
                    tempRoot = tempRoot->sx;
                }
            }
            return nullptr; //sarà nullptr
        }
    private:
        BSTNode* root;
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
    coda.checkAndRemoveByHours(1000);
    coda.printCoda();


    cout << "\n\n\n\n\n";


    BST tree;
    tree.insert(new BSTNode(new Missione(1001, "Marte", 2021)));
    tree.insert(new BSTNode(new Missione(1001, "Marte", 2021)));
    tree.insert(new BSTNode(new Missione(1003, "Marte", 2021)));
    tree.insert(new BSTNode(new Missione(1001, "Marte", 2021)));

    cout << *(tree.search(1003));
    cout << endl;
    return 0;
}


