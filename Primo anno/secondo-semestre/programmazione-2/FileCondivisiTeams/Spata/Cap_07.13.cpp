// 7.13

#include <iostream>
using namespace std;

double* cerca(double* v, int m, double k) {
	for (int j=0; j<m; j++)
		if (*v == k) return v;
		else v++;
	return 0;
}

int main() {
	double elemento;
	double vettore[10]={0.0,1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9};
	cout << "Che elemento vuoi cercare?\n";
	cin >> elemento;
	cout << "è all'indirizzo " << cerca(vettore,10,elemento) << endl;
	return 0;
}


