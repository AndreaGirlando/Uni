#include <iostream>
using namespace std;
class Macchina{
    public:
        Macchina(int _cilindrata, int _numeroPorte, int _numeroPosti) :
            cilindrata(_cilindrata),
            numeroRuote(_numeroPorte),
            numeroPosti(_numeroPosti) {}
        void virtual print(){
            cout << "Macchina" << endl;
            cout << cilindrata << endl;
            cout << numeroRuote << endl;
            cout << numeroPosti << endl;
        }
    private:
    int cilindrata;
    int numeroRuote;
    int numeroPosti;
};


class Fiat : public Macchina{
    public:
        Fiat(int _cilindrata, int _numeroPorte, int _numeroPosti, int _kilometri):
            cilindrata(_cilindrata),
            numeroRuote(_numeroPorte),
            numeroPosti(_numeroPosti),
            kilometri(_kilometri),
            Macchina(_cilindrata, _numeroPorte, _numeroPosti){}
        void print(){
            cout << "Fiat" << endl;
            cout << cilindrata << endl;
            cout << numeroRuote << endl;
            cout << numeroPosti << endl;
            cout << kilometri << endl;
        }
    private:
        int cilindrata;
        int numeroRuote;
        int numeroPosti;
        int kilometri;
};

int main(){

    Macchina *temp = new Fiat(600,4,3,6050);
    temp->print();


    return 0;
}