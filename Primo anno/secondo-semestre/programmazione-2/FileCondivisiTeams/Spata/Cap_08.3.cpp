// 8.3

#include <iostream>
using namespace std;

int main() {
	int* entrata;
	int sommatoria;
	entrata = new int[10];
	for (int i=0; i<10 ; i++) {
		cin >> entrata[i];
		sommatoria += entrata[i];
	}
	cout << "Risultato somma: " << sommatoria;
	return 0;
}

