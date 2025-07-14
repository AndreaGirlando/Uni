#include <iostream>
#include <string>

using namespace std;

class Elemento 
{
public:
    Elemento(const char* t, const char* a) : titolo(t), autore(a) {}

    string getTitolo() {return titolo;}
    string getAutore() {return autore;}

    virtual void Stampa(ostream& s=cout) const {
        s << "Titolo: " << titolo << endl;
        s << "Autore: " << autore << endl;
    }
private:
    string titolo;
    string autore;
};

ostream& operator<<(ostream& s, const Elemento* e)
{
    if (e==nullptr)
        s << "Elemento non trovato" << endl;
    else
        e->Stampa(s);
    return s;
}

class Libro : public Elemento
{
public:
    Libro(const char* t, const char* a, int p) : Elemento(t,a), pagine(p) {}

    int getPagine() {return pagine;}

    virtual void Stampa(ostream& s=cout) const {
        s << "L'elemento è un libro" << endl;
        Elemento::Stampa(s);
        s << "Pagine: " << pagine << endl;
    }
private:
    int pagine;
};

class DVD : public Elemento
{
public:
    DVD(const char* t, const char* a, float d) : Elemento(t,a), durata(d) {}

    int getDurata() {return durata;}

    virtual void Stampa(ostream& s=cout) const {
        s << "L'elemento è un DVD" << endl;
        Elemento::Stampa(s);
        s << "Durata: " << durata << endl;
    }
private:
    float durata;
};

class Libreria 
{
public:
    Libreria(int max) : n(0), max_n(max)
    {
        array = new Elemento*[max];
    }
    ~Libreria() 
    {
        delete [] array;
    }

    bool Inserisci(Elemento* e)
    {
        if (n >= max_n)
            return false;
        array[n] = e;
        n++;
        return true;
    }

    void Stampa() const
    {
        cout << "Ci sono " << n << " elementi" << endl << endl;
        for (int i=0; i<n; i++) {
            array[i]->Stampa();
            cout << endl;
        }
    } 

    Elemento* Ricerca(const char* titolo) {
        for (int i=0; i<n; i++) 
            if (array[i]->getTitolo() == titolo)
                return array[i];
        return nullptr;
    }

private:
    Elemento** array;
    int n;
    int max_n;
};

int main()
{
    Libreria lib(10);
    lib.Inserisci(new DVD("Documentario", "Piero Angela", 1.5f));
    lib.Inserisci(new Libro("Introduzione al c++", "Deitel", 400));
    
    lib.Stampa();
    
    const char* titolo = "Documentario";
    cout << endl << "Cerco l'elemento con titolo " << titolo << endl;
    Elemento* p = lib.Ricerca(titolo);
    cout << p;
/*    if (p == nullptr)
        cout <<  "Elemento non trovato" << endl;
    else
        p->Stampa();
*/
    titolo = "Scary movie";
    cout << endl << "Cerco l'elemento con titolo " << titolo << endl;    
    p = lib.Ricerca(titolo);
    cout << p;
 /*   if (p == nullptr)
        cout <<  "Elemento non trovato" << endl;
    else
        p->Stampa();
 */   
    return 0;
}