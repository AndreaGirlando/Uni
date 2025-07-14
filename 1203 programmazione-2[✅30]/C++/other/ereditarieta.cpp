#include <iostream>
using namespace std;

//TODO capire in modo approfondito che cosa vuol dire dichiarare una funzione virtual

class Figura{
    //? la seguente è una classe astratta ovverro non può essere instanziata
    public:
        Figura(int valx, int valy): x(valx), y(valy) {} //costruttore vuoto con vettore di inizzializzazione

    virtual void stampa(){
        cout << "x = " << this->x << endl;
        cout << "y = " << this->y << endl;
    }
    //virtual float calcolaArea() { return 0;} //? al posto di definirla cosi che non ha senso facciamo come sotto
    virtual float calcolaArea() = 0; //basta una funzione virtuale pura e la classe diventa astratta
    private:
    int x;
    int y;
};

class Cerchio: public Figura{
    public:
        //? Costruttore dove prendo tutti i parametri necessari e poi passo i primi due a Figura cosi si inizzializza e poi inizzializzo r
        Cerchio(int valx, int valy, int valr): Figura(valx,valy), r(valr) {}

        virtual void stampa(){
            //specifico la classe di riferimento per fare in modo che venga richiamata la funzione stampa di Figura
            Figura::stampa();
            cout << "raggio = " << this->r << endl;
        }
        virtual float calcolaArea(){
            return r*r*PI;
        }

    private:
    int r;
    const float PI = 3.14;
};

class Rettangolo: public Figura{

    public:
        Rettangolo(int valx, int valy, int valh, int valb): Figura(valx,valy), h(valh), b(valb) {}
        virtual void stampa(){
            Figura::stampa();
            cout << "base = " << this->b << endl;
            cout << "altezza = " << this->h << endl;
        }
        virtual float calcolaArea(){
            return b*h;
        }

    private:
        int h;
        int b;
};

int main(){

    //! il codice di seguito non può essere compilato perchè Figura è una classe astratta
    // Figura fig(25, 25);
    // fig.stampa();

    Cerchio cer(10, 15, 5);
    // cer.stampa();

    Rettangolo r(10, 15, 5, 5);
    // r.stampa();

    //? array di tutte le figure
    Figura* figure[] = {&cer,&r};
    //? l'ereditarieta serve a questo, possiamo creare un'array di figure, e per ogni figura avremo i metodo specifici della sottoclasse

    cout << "\n\n\n\n";

    float areaTotale = 0.0;
    for(int i = 0; i < sizeof(figure)/sizeof(figure[0]); i++){
        figure[i]->stampa();
        float area  = figure[i]->calcolaArea();
        areaTotale += area;
        cout << "Area:" << area << "\n\n";
    }

    cout << "Totale delle aree: " << areaTotale;









    //Se volessimo usare un riferiment/puntatore
    // cout << "Classe figura (stampata usando il puntatore): " << endl;
    // Cerchio* p = &cer;
    // p->stampa();
    // Figura* p2 = p; //! Questa cosa farà il casting automatico di p (Cerchio*) in p2 (Figura*)

    //? Chiaramente questa cosa al contrario non si può fare
    // Cerchio* p3 = (Cerchio*) p2;

    //! Se vogliamo comunque forzare il casting possiamo usare il dynamic_cast ma l'oggetto deve essere polimorfico

    cout << endl;
    return 0;
}