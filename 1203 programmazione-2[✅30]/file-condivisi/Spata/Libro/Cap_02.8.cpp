// 2.8
#include <iostream>
using namespace std;
int main( ) {
	int numero_pezzi;
	float peso_unitario, prezzo_unitario;
	cout << "Introduca il numero dei pezzi: ";
	cin >> numero_pezzi;
	cout << "Introduca peso unitario e prezzo unitario: ";
	cin >> peso_unitario >> prezzo_unitario;
	cout << " pezzi: " << numero_pezzi << "\n";
	cout << peso_unitario << ", " << prezzo_unitario << endl;
	return 0;
}
