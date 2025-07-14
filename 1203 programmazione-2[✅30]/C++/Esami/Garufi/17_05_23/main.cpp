#include <iostream>

using namespace std;

class Prodotto{
    public:
    Prodotto():codice(0),prezzo(0){}                    //doppio costruttore (si può fare basta che abbiano parametri diversi)
    Prodotto(int code,double price):codice(code),prezzo(price){}

    virtual int getCodice(){
        return codice;
    }
    virtual void setCodice(int code){
        codice = code;
    }

    virtual double getPrezzo(){
        return prezzo;
    }
    virtual void setPrezzo(double price){
        prezzo = price;
    }

    virtual void print(){   //andrebbe fatto un overloading di << ma uso una funzione print
        cout << "Codice: " << codice << endl << "Prezzo: " << prezzo <<endl;
    }

    protected:
    int codice;
    double prezzo;
};

class ProdottoAlimentare : public Prodotto{
    public:
    ProdottoAlimentare(int scad, int code, double price):Prodotto(code,price),scadenza(scad){}

    bool verifica(){
        return true;
    }

    int getCodice(){
        return codice;
    }
    void setCodice(int code){
        codice = code;
    }

    double getPrezzo(){
        return prezzo;
    }
    void setPrezzo(double price){
        prezzo = price;
    }

    void print(){   //andrebbe fatto un overloading di << ma uso una funzione print
        cout << "Codice: " << codice << endl << "Prezzo: " << prezzo << endl << "Scadenza: " << scadenza <<endl;
    }

    private:
    int scadenza;
};


class ProdottoPerBambini : public Prodotto{
    public:
    ProdottoPerBambini(int anno, int code, double price):Prodotto(code,price),eta(anno){}

    int getCodice(){
        return codice;
    }
    void setCodice(int code){
        codice = code;
    }

    double getPrezzo(){
        return prezzo;
    }
    void setPrezzo(double price){
        prezzo = price;
    }

    void print(){   //andrebbe fatto un overloading di << ma uso una funzione print
        cout << "Codice: " << codice << endl << "Prezzo: " << prezzo << endl << "Fascia di eta': " << eta <<endl;
    }

    private:
    int eta;
};

class Venditore{
    public:                         //doppio costruttore (si può fare basta che abbiano parametri diversi)
    Venditore():codiceVenditore(0),prodottiArray(0),array(nullptr){}
    Venditore(int codeV):codiceVenditore(codeV){}
    ~Venditore(){}  //distruttore da sistemare (credo)

    void printVenditore(){
        cout << "Prodotti Venduti"<<endl;

    }

    double calcolaPrezzoTotale();
    double calcolaValoreMagazzino();
    void aggiungiProdotto();

    private:
    int codiceVenditore;
    int prodottiArray;
    Prodotto **array;
};

double Venditore::calcolaPrezzoTotale(){
    double x = 0;
    cout << "Calcolo il prezzo totale dei prodotti venduti" <<endl;
    return x;
}

double Venditore::calcolaValoreMagazzino(){
    double x = 0;
    cout << "Calcolo il valore totale dei prodotti nel magazzino" <<endl;

    return x;
}

void Venditore::aggiungiProdotto(){
    cout << "Aggiungi un prodotto" <<endl;
    array = new Prodotto*[5];

    array[0] = new ProdottoAlimentare(2026,1313,35);
    //array[0]->print(); 

}


int main(){

    Venditore **arrayV = new Venditore*[3];
    cout << "Creo 3 venditori e inserisco 5 prodotti in ognuno di loro... Venditori creati" <<endl;
    arrayV[0] = new Venditore();
    arrayV[1] = new Venditore();
    arrayV[2] = new Venditore();
    
    arrayV[0]->aggiungiProdotto();





}