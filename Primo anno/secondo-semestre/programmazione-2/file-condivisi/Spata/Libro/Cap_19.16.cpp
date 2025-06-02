// 19.16
/* Scrivere una funzione ricorsiva che
sommi le cifre di un numero naturale.
* 
SUGGERIMENTO
La somma delle cifre di un numero naturale si può calcolare ricorsivamente mediante l'espressione.
SommaRicorsiva(n)= n mod 10 + SommaRicorsiva(n dic 10)se n>0
SommaRicorsiva(0)= 0
*/

#include <iostream>
using namespace std;

unsigned SommaRicorsiva(unsigned n) {
	if (n==0) return 0;
	else return ((n%10) + SommaRicorsiva(n / 10));
}


int main() {
	unsigned numero;
	cin >> numero;
	cout << SommaRicorsiva(numero) << endl;
}

