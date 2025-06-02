#include <iostream>

using namespace std;

template <typename T>
int scambia(T& a, T& b)
{
    static int n = 0;
    T t = a;
    a = b;
    b = t;
    n += 1;
    return n;
}

class Libro {
public:
    Libro(const char * t) : titolo(t) {}
    string titolo;
};

int main()
{
    float i=5.0f, j=7.6f;
    cout << "Valore di ritorno di scambia: " << scambia(i,j) << endl;
    cout << "Valori scambiati: i = " << i << ", j = " << j << endl;

    int k = 5, l = 7;
    cout << "Valore di ritorno di scambia: " << scambia(k,l) << endl;
    cout << "Valori scambiati: k = " << k << ", l = " << l << endl;
    cout << "Valore di ritorno di scambia: " << scambia(k,l) << endl;
    cout << "Valori scambiati di nuovo: k = " << k << ", l = " << l << endl;

    Libro l1("Introduzione al C++"), l2("C++ avanzato");
    cout << "Valore di ritorno di scambia: " << scambia(l1,l2) << endl;
    cout << "Valori scambiati: l1 = " << l1.titolo << ", l2 = " << l2.titolo << endl;
}