// 19.15
/* Scrivere un programma che decida
se un numero naturale è pari o dispari
mediante una funzione ricorsiva indiretta.
* 
SUGGERIMENTO
Si tenga conto delle seguenti banali osservazioni:
pari(n)= dispari(n-1) se n>1
pari(0)= true
dispari(n)= pari(n-1) se n>1
dispari(0)= false
*/

#include <iostream>
using namespace std;

bool pari(unsigned);
bool dispari(unsigned);

bool pari(unsigned n) {
	if (n==0) return true;
	else return dispari(n-1);
}

bool dispari(unsigned n) {
	if (n==0) return false;
	else return pari(n-1);
}

int main() {
	unsigned numero;
	cin >> numero;
	if (pari(numero)) cout << "PARI" << endl;
	if (dispari(numero)) cout << "DISPARI" << endl;
}

