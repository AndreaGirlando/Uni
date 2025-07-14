#include <iostream>

using namespace std;

class Studente{
    public:
    Studente(int number, string name, string surname, float m):matricola(number),nome(name),cognome(surname),media(m){}
    Studente(){}

    virtual void inserisciStudente(int number, string name, string surname, float m,bool flag, int import){
        matricola = number;
        nome = name;
        cognome = surname;
        media = m;
        return;
    }

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
        cout << matricola << ": " << nome << " " << cognome << " - " << media;
    }

    virtual int get_importo_borsa(){
    }

    protected:
    int matricola;
    string nome;
    string cognome;
    float media;

};

class  StudenteBorsista;
class BorsaDiStudio{
    public:
    BorsaDiStudio():importo(0),durata(0){}
    friend class StudenteBorsista;
    private:
    int importo;
    int durata;
};

class  StudenteBorsista : public Studente{
    public:
    StudenteBorsista(){
        borsa = new BorsaDiStudio;
    }

    void inserisciStudente(int number, string name, string surname, float m,bool flag, int import){
        if(flag == true){
            borsa->importo = import;
            //cout << borsa->importo;
        }
        matricola = number;
        nome = name;
        cognome = surname;
        media = m;
        return;
    }

    int get_importo_borsa(){
        return borsa->importo;
    }

    void print(){
        cout << matricola << ": " << nome << " " << cognome << " - " << media;
        if(borsa->importo != 0){
            cout << " borsa di importo euro: " << borsa->importo;
        }
    }

    private:
    BorsaDiStudio *borsa;
};

int main(){

    Studente **array = new Studente*[10];
    
    array[0] = new StudenteBorsista();
    array[1] = new StudenteBorsista();
    array[2] = new StudenteBorsista();
    array[3] = new StudenteBorsista();
    array[4] = new StudenteBorsista();
    array[5] = new StudenteBorsista();


    array[0]->inserisciStudente(1001,"Mario","Rossi",25.5,false,0);
    array[1]->inserisciStudente(1002,"Anna","Verdi",28.0,true,880);
    array[2]->inserisciStudente(1003,"Luca","Bianchi",26.5,false,0);
    array[3]->inserisciStudente(1004,"Sara","Neri",27.5,false,0);
    array[4]->inserisciStudente(1005,"Marco","Gialli",24.5,true,500);
    array[5]->inserisciStudente(1006,"Laura","Marroni",29.5,true,600);

    cout << "Stampa Studenti: " <<endl;
    for(int i = 0; i < 6; i++){
        array[i]->print();
        cout << endl;
    }
    int n = 6;
    for(int i = 0; i < n; i++){
        if(array[i]->getMedia() < 25){
            cout << "Rimuovo questo studente perche' ha una media inferiore al 25" <<endl;
            array[i]->print();
            delete array[i];
            array[i] = nullptr;

            for(int j = i; j < 6-1; j++){
                array[j] = array[j+1];
            }
            n--;
            array[n] = nullptr;
        }
    }
    int somma = 0;
   cout << endl << "Calcolo l'importo totale delle borse di studio " <<endl;
    for(int i = 0; i < 6; i++){
        if(array[i] != nullptr){
            somma = somma + (array[i]->get_importo_borsa());
        }
        
    }
    cout << "La somma totale e': " << somma <<endl;

    return 0;
}