#include <iostream>

using namespace std;
class Queue;
class Patient{          //sarà il nodo della coda
    public:                                         //next
    Patient(int code,string name,string condition,Patient *p,bool flag):id(code),nome(name),condizioneMedica(condition),next(p),raccomandazione(flag){}
    Patient(){}
    friend class Queue;
    int getId(){
        return id;
    }
    void setId(int code){
        id = code;
        return;
    }

    string getNome(){
        return nome;
    }
    void setNome(string name){
        nome = name;
        return;
    }

    string getCondizioneMedica(){
        return condizioneMedica;
    }
    void setCondizioneMedica(string condition){
        condizioneMedica = condition;
        return;
    }

    void print(){
        string temp;
        if(raccomandazione == true){
            temp = "SI";
        }else{
            temp = "NO";
        }
        cout << "Nome paziente: " << nome << ", id paziente: " << id << ", condizione medica: " << condizioneMedica << ", raccomandazione: " << temp <<endl;
    }

    private:
    int id;
    string nome;
    string condizioneMedica;
    bool raccomandazione;

    Patient *next;
};

class Queue{
    public:
    Queue():head(nullptr){}

    void enQueue(int code,string name,string condition, bool flag);    //inserisco in testa e levo in coda cosi facendo gestisco una coda
    void deQueue();
    void printCoda();
    bool isEmpty(){
        if(head == nullptr){
            cout << "La coda e' vuota" << endl;
            return true;
        }else{
            cout << "La coda non e' vuota" << endl;
            return false;
        }
    }

    private:
    Patient *head;
};

void Queue::enQueue(int code,string name,string condition,bool flag){
    Patient dati;
    dati.raccomandazione = flag;

    if(flag == true){
        Patient *newNode = nullptr;
        Patient *current = head;
        Patient *ant = nullptr;
        int passi = 0;

        while(current != nullptr && passi <= 3){        //salvo la posizione del paziente raccomandato
            passi++;
            ant = current;
            current = current->next;
        }
        newNode = new Patient(code,name,condition,head,true);
        if(ant != nullptr){
            ant->next = newNode;
        }
        newNode->next = current;

        return;
    }

    head = new Patient(code,name,condition,head,false);
    return;
}

void Queue::deQueue(){

    if(isEmpty() == true){
        cout << "ESCO" <<endl;
        return;
    }

    Patient *current = head;
    Patient *ant = nullptr;
    while(current->next != nullptr){
        ant = current;
        current = current->next;
    }
    current->print();

    if(ant != nullptr){
        ant->next = nullptr;
    }else{
        head = nullptr;
    }

    delete current;
    return;
}

void Queue::printCoda(){
    Patient *current = head;

    while(current != nullptr){
        current->print();
        current = current->next;
    }
    return;
}

int main(){

    cout << "La coda va letta dal basso verso l'alto: (in basso c'e' la testa in alto la coda)" << endl <<endl;

    Queue coda;

    coda.enQueue(143,"Alferdo","malato",false);
    coda.enQueue(555,"Niko Pandetta","scimunito",false);
    coda.enQueue(777,"Melo","pazzo",false);
    coda.enQueue(777,"Andrea","Troppa Bellezza",false);
    coda.enQueue(324,"ScemoDiGuerra","babbitudine cronica",false);
    coda.enQueue(321,"Pepo3393","road to diamod",false);
    coda.enQueue(333,"Danny Lazzarin","tignosita'",false);
    coda.enQueue(123,"xmurry","limiti dell'evoluto",false);

    coda.printCoda();

    cout <<endl;
    cout << endl << "Rimuovo Alferdo, lo stampo e ristampo la coda" <<endl;
    coda.deQueue();
    cout <<endl;
    cout << "Coda" <<endl;
    coda.printCoda();
    cout <<endl;
    cout << "Rimuovo tutti i pazienti" <<endl;
    coda.deQueue();
    coda.deQueue();
    coda.deQueue();
    coda.deQueue();
    coda.deQueue();
    coda.deQueue();
    coda.deQueue();
    coda.deQueue();
    
    cout << endl << "Reinserisco..." <<endl;
    coda.enQueue(143,"Alferdo","malato",false);
    coda.enQueue(555,"Niko Pandetta","scimunito",false);
    coda.enQueue(777,"Melo","pazzo",false);
    coda.enQueue(777,"Andrea","Troppa Bellezza",false);  
    coda.enQueue(324,"ScemoDiGuerra","babbitudine cronica",false);
    coda.enQueue(321,"Pepo3393","road to diamod",false);
    coda.enQueue(333,"Danny Lazzarin","tignosita'",false);
    coda.enQueue(123,"xmurry","limiti dell'evoluto",true);      //raccomandazione


    cout << "Inserisco un paziente raccomandato e stampo" <<endl;
    coda.printCoda();
    return 0;
}