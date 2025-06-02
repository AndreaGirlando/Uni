#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Studente
{
public:
    Studente(int m, const string& n, const string& c, float med)
        : matricola(m), nome(n), cognome(c), media(med) {}

    int GetMatricola() const {return matricola;}
    const string& GetNome() const {return nome;}
    const string& GetCognome() const {return cognome;}
    float GetMedia() const {return media;}

    virtual void print() {cout << matricola << ": "<< nome << " " << cognome << " - media " << media;} 
private:
    int matricola;
    string nome;
    string cognome;
    float media;
};

class BorsaDiStudio
{
public:
    BorsaDiStudio(int imp, int dur) 
        : importo(imp), durata(dur) {}

    int GetImporto() const {return importo;}
    int GetDurata() const {return durata;}    
    void SetImporto(int imp) {importo = imp;}
    void SetDurata(int dur) {durata = dur;}
private:
    int importo;
    int durata;
};

class StudenteBorsista : public Studente
{
public:
    StudenteBorsista(int m, const string& n, const string& c, float med, BorsaDiStudio* b=nullptr)
        : Studente(m,n,c,med), borsa(b) {}
    ~StudenteBorsista() {if (borsa) delete borsa;}

    int get_importo_borsa() const 
    
    {
        if (borsa != nullptr) 
            return borsa->GetImporto();
        return 0;
    }
    
    virtual void print() 
    {
        Studente::print(); 
        if (borsa != nullptr) 
            cout << " [borsa di " << get_importo_borsa() << " euro]"; 
    }
private:
    BorsaDiStudio* borsa;
};

// implementazione con i template ma non era esplicitamente richiesto 
// quindi andava bene anche senza

template <typename T>
class Pila;

template <typename T>
class PilaElem 
{
public:
    PilaElem(T d) : data(d) {}
    T GetData() const {return data;}
    PilaElem<T>* GetNext() const {return next;}
private:
    T data;
    PilaElem<T>* next;
    friend class Pila<T>;
};

template <typename T>
class Pila
{
public:
    Pila() : head(nullptr) {}
    ~Pila() {while(!IsEmpty()) Pop();}
    
    Pila& Push(T data) 
    {
        PilaElem<T>* newelem = new PilaElem<T>(data);
        newelem->next = head;
        head = newelem;
        return *this;
    }

    T Pop() 
    {
        if (head == nullptr)
            return nullptr;
        PilaElem<T>* elem = head;
        head = elem->next;
        T ret = elem->data;
        delete elem;
        return ret;
    }

    PilaElem<T>* GetHead() const {return head;}
    
    void Remove(PilaElem<T>* elem) 
    {
        if (elem == head)
            Pop();
        else
        {
            PilaElem<T>* prec = head;
            while (prec->next && prec->next != elem)
                prec = prec->next;
            if (prec->next != elem)
                return;
            prec->next = elem->next;
            delete elem;
        }
    }

    bool IsEmpty() const {return (head==nullptr);}
private:
    PilaElem<T>* head;
};

int main()
{
    int matricola;
    string nome;
    string cognome;
    float media;
    int importo;
    int durata;

    Pila<Studente*> pila;

    // legge gli studenti da file e li inserisce in una pila
    fstream file;
    file.open("input.txt");
    while(!file.eof() && file.good())
    {
        file >> matricola >> nome >> cognome >> media >> importo >> durata;

        Studente* studente;
        BorsaDiStudio* borsa = nullptr;
        if (importo != 0)
        {
            borsa = new BorsaDiStudio(importo,durata);
            studente = new StudenteBorsista(matricola,nome,cognome,media,borsa);
        }
        else
        {
            studente = new Studente(matricola,nome,cognome,media);
        }
        // studente->print(); cout << endl; // per controllare che sia tutto ok
        pila.Push(studente);
    }

    Pila<Studente*>& nuovaPila = pila;
    PilaElem<Studente*>* p = pila.GetHead();
    while (p != nullptr)
    {
        Studente* studente = p->GetData();
        PilaElem<Studente*>* next = p->GetNext();
        if (studente->GetMedia() < 25)
        {
            pila.Remove(p);
            cout << "Studente insufficiente rimosso: " << studente->GetNome() << " " << studente->GetCognome() << " - Matricola: " << studente->GetMatricola() << endl;
        }
        p = next;
    }

/*    
    // in alternativa (più semplice) elimina gli studenti con media < 25 inserendo gli altri in una nuova pila
    Pila<Studente*> nuovaPila;
    while (!pila.IsEmpty())
    {
        Studente* studente = pila.Pop();
        if (studente->GetMedia() < 25)
            cout << "Studente insufficiente rimosso: " << studente->GetNome() << " " << studente->GetCognome() << " - Matricola: " << studente->GetMatricola() << endl;
        else
            nuovaPila.Push(studente);
    }
*/
    cout << endl;

    int importi = 0;
    while (!nuovaPila.IsEmpty())
    {
        Studente* studente = nuovaPila.Pop();
        studente->print();
        cout << endl;
        // si potrebbe definire get_importo_borsa anche su Studente come virtual 
        // ed evitare il dynamic_cast, ma non era richiesto dal testo
        StudenteBorsista* borsista = dynamic_cast<StudenteBorsista*>(studente);
        if (borsista)
            importi += borsista->get_importo_borsa();
    }

    cout << endl << "Totale importi borse di studio: " << importi << " euro." << endl;
}
