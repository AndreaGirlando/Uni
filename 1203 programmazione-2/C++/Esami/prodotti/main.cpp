#include <iostream>
#include <fstream>
using namespace std;

class Prodotto{
    public:
        Prodotto() : codiceProdotto(0), prezzo(0) {}
        Prodotto(int _codiceProdotto, double _prezzo) : codiceProdotto(_codiceProdotto), prezzo(_prezzo) {}
        virtual int getCodiceProdotto() { return codiceProdotto; };
        virtual void setCodiceProdotto(int _codiceProdotto) { codiceProdotto = _codiceProdotto; }
        virtual double getPrezzo() { return prezzo; };
        virtual void setPrezzo(double _prezzo) { prezzo = _prezzo; };
        void leggi(ifstream& stream){
            stream >> codiceProdotto;
            stream >> prezzo;
        }
    private:
        int codiceProdotto;
        double prezzo;
};

ostream& operator<<(ostream& stream, Prodotto& item){
    stream << "Prodotto(" << item.getCodiceProdotto()<< "): " << item.getPrezzo() << "€";
    return stream;
}

class ProdottoAlimentare: public Prodotto{
    public:
        ProdottoAlimentare() : dataScadenza(0), Prodotto() {};
        ProdottoAlimentare(int _dataScadenza, Prodotto* _prodotto) : dataScadenza(_dataScadenza), Prodotto(_prodotto->getCodiceProdotto(),_prodotto->getPrezzo()) {};
        bool verifica(){
            return dataScadenza > 0;
        }
        int getDataScadenza() { return dataScadenza; };
        void setPrezzo(int _dataScadenza) { dataScadenza = _dataScadenza; };
    private:
        int dataScadenza;//espressa in giorni dalla scadenza
};

ostream& operator<<(ostream& stream, ProdottoAlimentare& item){
    stream << "Prodotto alimentare(" << item.getCodiceProdotto()<< "): " << item.getPrezzo() << "€ (scade tra: " << item.getDataScadenza() << " giorni)";;
    return stream;
}

enum Fascia {
    non_settata = 0,
    fascia1 = 1,
    fascia2 = 2,
    fascia3 = 3,
    fascia4 = 4
};

class ProdottoBambini: public Prodotto{
    public:
        ProdottoBambini() : fascia(non_settata), Prodotto() {};
        ProdottoBambini(enum Fascia _fascia, Prodotto* _prodotto) : fascia(_fascia), Prodotto(_prodotto->getCodiceProdotto(),_prodotto->getPrezzo()) {};

        int getFascia() { return fascia; };
        void setPrezzo(enum Fascia _fascia) { fascia = _fascia; };
    private:
        enum Fascia fascia;
};

ostream& operator<<(ostream& stream, ProdottoBambini& item){
    stream << "Prodotto per bambini(" << item.getCodiceProdotto()<< "): " << item.getPrezzo() << "€ (fascia: " << item.getFascia()<<")";
    return stream;
}


class Venditore{
    public:
        Venditore():codiceVenditore(0), prodotti(nullptr), numeroProdotti(0), maxProdotti(5){}
        Venditore(int _codiceVenditore):codiceVenditore(_codiceVenditore), prodotti(nullptr), numeroProdotti(0), maxProdotti(5) {}
        ~Venditore() {
            for (int i = 0; i < numeroProdotti; ++i) {
                delete prodotti[i];
            }
            delete[] prodotti;
        }
        void leggi(ifstream& stream){
            stream >> codiceVenditore;
        }
        double calcolaPrezzoTotale(){
            double res = 0.0;
            for(int i = 0;i<numeroProdotti;i++){
                res += prodotti[i]->getPrezzo();
            }
            return res;
        }
        double calcolaValoreMagazzino(){
            //esclusi i prodotti scaduti
            double res = 0.0;
            for(int i = 0;i<numeroProdotti;i++){
                if(dynamic_cast<ProdottoAlimentare*>(prodotti[i])){
                    ProdottoAlimentare* temp = dynamic_cast<ProdottoAlimentare*>(prodotti[i]);
                    if(temp->verifica()){
                        res += temp->getPrezzo();
                    }
                }else{
                    res += prodotti[i]->getPrezzo();
                }
            }
            return res;
        }
        void aggiungiProdotto(Prodotto* temp){
            if(prodotti == nullptr){
                prodotti = new Prodotto*[maxProdotti];
                prodotti[0] = temp;
                numeroProdotti++;
                return;
            }
            if(numeroProdotti == maxProdotti){
                maxProdotti = maxProdotti*2;
                Prodotto** prodottiTemp = new Prodotto*[maxProdotti];
                for(int i = 0;i < numeroProdotti; i++){
                    prodottiTemp[i] = prodotti[i];
                }
                delete prodotti;
                prodotti = prodottiTemp;
                prodotti[numeroProdotti] = temp;
                numeroProdotti++;
                return;
            }

            prodotti[numeroProdotti] = temp;
            numeroProdotti++;


        }


        friend ostream& operator<<(ostream& stream, Venditore& item);
    private:
        int codiceVenditore;
        Prodotto** prodotti;
        int numeroProdotti;
        int maxProdotti;
};

ostream& operator<<(ostream& stream, Venditore& item){
    stream << "Il venditore " << item.codiceVenditore << " vende " << item.numeroProdotti << " prodotti e sono i seguenti: " << endl;
    for(int i = 0;i<item.numeroProdotti;i++){
        if(dynamic_cast<ProdottoAlimentare*>(item.prodotti[i])){
            cout << *(dynamic_cast<ProdottoAlimentare*>(item.prodotti[i]));
        }else if(dynamic_cast<ProdottoBambini*>(item.prodotti[i])){
            cout << *(dynamic_cast<ProdottoBambini*>(item.prodotti[i]));
        }else{
            cout << *(item.prodotti[i]) << endl;
        }
    }
    cout << "\n\n";
    return stream;
}

int main(){

    ifstream fileProdotti("prodotti.txt", ios::in);
    ifstream fileVenditori("venditori.txt", ios::in);
    int lenFileProdotti = 0;
    fileProdotti >> lenFileProdotti;

    Venditore vend1;
    Venditore vend2;
    Venditore vend3;
    vend1.leggi(fileVenditori);
    vend2.leggi(fileVenditori);
    vend3.leggi(fileVenditori);

    for(int i = 0;i<lenFileProdotti;i++){
        Prodotto* temp = new Prodotto;
        temp->leggi(fileProdotti);
        temp->setCodiceProdotto(temp->getCodiceProdotto()*rand()%10);
        temp->setPrezzo(temp->getPrezzo()*(rand()%150));
        vend1.aggiungiProdotto(temp);
    }
    fileProdotti.seekg(1); //istruzione per ritornare all'inizio del file
    for(int i = 0;i<lenFileProdotti;i++){
        Prodotto* temp = new Prodotto;
        temp->leggi(fileProdotti);
        temp->setCodiceProdotto(temp->getCodiceProdotto()*rand()%150);
        temp->setPrezzo(temp->getPrezzo()*(rand()%150));
        vend2.aggiungiProdotto(temp);
    }
    fileProdotti.seekg(1);
    for(int i = 0;i<lenFileProdotti;i++){
        Prodotto* temp = new Prodotto;
        temp->leggi(fileProdotti);
        temp->setCodiceProdotto(temp->getCodiceProdotto()*rand()%150);
        temp->setPrezzo(temp->getPrezzo()*(rand()%150));
        vend3.aggiungiProdotto(temp);
    }



    vend1.aggiungiProdotto(new ProdottoAlimentare(5,new Prodotto(451,50)));
    vend3.aggiungiProdotto(new ProdottoAlimentare(0,new Prodotto(4126,50)));
    vend2.aggiungiProdotto(new ProdottoBambini(fascia1,new Prodotto(415,50)));

    int scelta = 0;

    do{
        cout << "\n\n\n";
        cout << "1. Stampa i prezzi totali in ordine crescente" << endl;
        cout << "2. Stampa i prezzi totali in ordine decrescente" << endl;
        cout << "3. Stampa venditori e prodotti" << endl;
        cout << "Che cosa vuoi fare: ";
        cin >> scelta;

        int* array = new int[3];
        array[0] = vend1.calcolaPrezzoTotale();
        array[1] = vend2.calcolaPrezzoTotale();
        array[2] = vend3.calcolaPrezzoTotale();

        if(scelta == 1){
            for(int i = 0;i < 3; i++){
                for(int j = 0; j<3;j++){
                    if(array[j] > array[i]){
                        int temp = array[j];
                        array[j] = array[i];
                        array[i] = temp;
                    }
                }
            }
            for(int i = 0;i < 3; i++){
                cout << array[i] << " ";
            }
        }
        else if(scelta == 2){
            for(int i = 0;i < 3; i++){
                for(int j = 0; j<3;j++){
                    if(array[j] < array[i]){
                        int temp = array[j];
                        array[j] = array[i];
                        array[i] = temp;
                    }
                }
            }
            for(int i = 0;i < 3; i++){
                cout << array[i] << " ";
            }
        }
        else if(scelta == 3){
            cout << vend1;
            cout << vend2;
            cout << vend3;
        }

    }while(scelta != 0);


    cout << endl;
    return 0;
}