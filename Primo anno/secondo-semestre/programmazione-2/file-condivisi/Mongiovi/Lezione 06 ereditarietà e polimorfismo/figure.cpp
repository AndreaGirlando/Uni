#include <iostream>

using namespace std;

class Figura 
{
public:
    Figura(int valx, int valy) : x(valx), y(valy) {}
    virtual void stampa() 
    {
        cout << endl;
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }
    virtual float CalcolaArea() = 0;
private:
    int x;
    int y;
};

class Cerchio : public Figura
{
public:
    Cerchio(int valx, int valy, int valr) : Figura(valx,valy), r(valr), PI(3.1415f) {}

    virtual void stampa() 
    {
        Figura::stampa();
        cout << "raggio = " << r << endl;
    }
    virtual float CalcolaArea()
    {
        return r*r*PI;
    }

private:
    const float PI;
    int r;
};

class Rettangolo : public Figura
{
public:
    Rettangolo(int valx, int valy, int valbase, int valaltezza) 
        : Figura(valx,valy), base(valbase), altezza(valaltezza) {}

   virtual void stampa() 
    {
        Figura::stampa();
        cout << "Base: " << base << endl;
        cout << "Altezza: " << altezza << endl;
    }
    virtual float CalcolaArea() 
    {
        return base * altezza;
    }    
private:
    int base;
    int altezza;
};


int main()
{
    Rettangolo fig(7,5,10,5);
    fig.stampa();

    Cerchio cer(10,15,5);
    cer.stampa();

    Rettangolo r(14, 35, 10, 20);
    r.stampa();

    Figura* figure[] = {&fig, &cer, &r};

    float areaTotale = 0.0f;
    for (int i=0; i<sizeof(figure)/sizeof(figure[0]); i++) {
        figure[i]->stampa();
        float area = figure[i]->CalcolaArea();
        cout << "Area: " << area << endl;
        areaTotale += area;
    }
    cout << endl << "L'area totale e': " << areaTotale << endl;

    return 0;
}