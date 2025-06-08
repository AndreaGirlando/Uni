#include <iostream>
using namespace std;


int main(){
    int n = 104;
    int& r = n; //riferimento alla variabile n (praticamente un'alias)

    cout << n << endl;
    cout << r << endl;

    cout << "Indirizzo n: " << &n << endl;
    cout << "Indirizzo r: " << &r << endl;

    int* p = new int; //? Alloco memoria dinamica senza usare malloc con la parola chiave new
    *p = 5;
    cout << "Indirizzo p: " << p << endl;
    cout << "Valore p: " << *p;

    cout << endl;
    return 0;
}