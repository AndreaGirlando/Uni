#include <iostream>
using namespace std;

class A{
    public:
        A(int _value) : value(_value){}
        void virtual stampa(){
            cout << "Classe A, Valore: " << this->value << endl;
        }
    private:
        int value;
};
class B : public A{
    public:
        B(int _value) : value(_value), A(_value){}
        void stampa(){
            cout << "Classe B, Valore: " << this->value << endl;
        }
    private:
        int value;
};

int main(){

    A a(5);
    a.stampa(); //In questo caso viene richiamato normalmente A::stampa()
    B b(5);
    b.stampa(); //In questo caso viene richiamato normalmente B::stampa()

    A* ptr = new B(24);
    ptr->stampa();
    //* se ad A::stampa() mettiamo virtual
    //?  stamperà "Classe B, Valore: 24"
    //?  sennò "Classe A, Valore: 24"

    return 0;
}