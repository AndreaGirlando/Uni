#include <iostream>
#include <fstream>
using namespace std;

class Stack;
class Studente{
    public:
    Studente(int number, string name, string surname,float m):matricola(number),nome(name),cognome(surname),media(m){}
    Studente(){}

    int getMatricola(){
        return matricola;
    }
    string getNome(){
        return nome;
    }
    string getCognome(){
        return cognome;
    }
    float getMedia(){
        return media;
    }

    virtual void print(){
        cout << matricola << ": " << nome << " " << cognome << " " << media <<endl;
    }

    protected:
    int matricola;
    string nome;
    string cognome;
    float media;
};

class StudenteBorsista;
class BorsaDiStudio{
    public:
    BorsaDiStudio():importo(0),durata(0){}
    friend class StudenteBorsista;
    friend class Stack;
    int getImporto(){
        return importo;
    }
    
    int getDurata(){
        return durata;
    }

    void setImporto(int import){
        importo = import;
    }
    void setDurata(int duration){
        durata = duration;
    }

    private:
    int importo;
    int durata; //in mesi
};

class StudenteBorsista : public Studente{       //sarà il mio nodo della pila
    public:                                                                                     //next
    StudenteBorsista(int number, string name, string surname,float m,int import,int duration, StudenteBorsista *p):Studente(number,name,surname,m),next(p){
        borsa = new BorsaDiStudio;
        borsa->importo = import;
        borsa->durata = duration;
    }
    StudenteBorsista(){}
    friend class Stack;
    int getImportoBorsa(){
        return borsa->importo;
    }

    void print(){
        if(borsa->importo != 0){
            cout << matricola << ": " << nome << " " << cognome << " " << media << " borsa di importo euro " << borsa->importo << " Durata " << borsa->durata <<endl;
        }else{
            cout << matricola << ": " << nome << " " << cognome << " " << media <<endl;
        }
    }
    private:
    BorsaDiStudio *borsa;

    //zona pila
    StudenteBorsista *next;
};

class Stack{        //pila
    public:
    Stack():head(nullptr),lun(0){}
    void inserisciStudenteFile();    //funzione che legge dal file i dati degli studenti e chiama push
    void push(int number, string name, string surname,float m,int import,int duration);
    void pop();
    void printPila();
    void checkPila();

    private:
    StudenteBorsista *head;
    int lun;
};

void Stack::checkPila(){

    StudenteBorsista **arrayPila = new StudenteBorsista*[lun];
    StudenteBorsista *current = head;

    int i = 0;
    while(current != nullptr && i < lun){       //qui copio la pila
        arrayPila[i] = new StudenteBorsista(current->matricola,current->nome,current->cognome,current->media,current->borsa->importo,current->borsa->durata,nullptr);
        current = current->next;
        i++;
    }

    int dim = i;

    for(int i = 0; i < dim; i++){       //elimino la pila vecchia
        pop();
    }
    lun = 0;

    for(int i = dim-1; i >= 0; i--){

        if(arrayPila[i]->media > 25){
            push(arrayPila[i]->matricola,arrayPila[i]->nome,arrayPila[i]->cognome,arrayPila[i]->media,arrayPila[i]->borsa->importo,arrayPila[i]->borsa->durata);  
        }else{
            cout << "Studente con media insufficente, rimuovo..." <<endl;
            arrayPila[i]->print();
            cout <<endl;
        }
    }

    for(int i = 0; i < dim; i++){
        delete arrayPila[i];
    }
    delete[] arrayPila;

    return;
}

void Stack::pop(){
    StudenteBorsista *current = head;
    head = head->next;
    delete current;
    lun--;
}

void Stack::printPila(){

    StudenteBorsista *current = head;

    while(current != nullptr){
        current->print();
        current = current->next;
    }
    return;
}

void Stack::push(int number, string name, string surname,float m,int import,int duration){
   head = new StudenteBorsista(number,name,surname,m,import,duration,head);
   lun++;
}

void Stack::inserisciStudenteFile(){
    fstream file("input.txt", ios::in);
    if(file.fail()){
        cout << "Errore nell'apertura del file" <<endl;
        exit(-1);
    }
    string name, surname;
    int number, import, duration;
    float m;

    while(file >> number >> name >> surname >> m >> import >> duration){

        push(number,name,surname,m,import,duration);
    }

    file.close();

    return;
}

int main(){

    cout << "Inserisco e stampo gli studenti" <<endl;

    Stack pila;
    pila.inserisciStudenteFile();
    pila.printPila();

   cout << endl << "Rimuovo gli studenti con media inferiore a 25" <<endl;
   pila.checkPila();
   pila.printPila();



   //calcola importo totale borse di studio

    return 0;
}