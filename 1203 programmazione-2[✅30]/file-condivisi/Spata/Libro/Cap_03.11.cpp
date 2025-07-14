// 3.11 Scrivere un programma in C++ che prende in input
// il raggio di una circonferenza, verifica se il valore 
// è maggiore di zero e fino a quando questo valore 
// non è maggiore di zero deve chiedere in input un 
// valore di raggio e poi ne calcoli superfice e volume

#include <iostream>
#define PI 3.2141592
using namespace std;

int main() {
	float raggio, superficie, volume;
	do {
		cout << "inserisca il valore del raggio (>0): ";
		cin >> raggio;
	} while (raggio <= 0);
	superficie = 4 * PI * raggio * raggio;
	volume = 4.0 / 3 * PI * raggio * raggio * raggio;
	cout << "la superficie ed il volume della sfera di raggio " << raggio << " sono:\n";
	cout << "superficie: " << superficie << endl;
	cout << "volume: " << volume << endl;
	return 0;
}
