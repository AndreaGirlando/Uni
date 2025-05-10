// 15.1

#include <iostream>  
using namespace std;

void scambio(int& x, int& y) {
	int aux = x;
	x = y;
	y = aux;
}

void ordinare (int v[], int n) {
	int i, j;
	for (i=0; i<n; ++i)
		for (j=0; j<n; ++j)
			if (v[j] < v[j+1]) scambio(v[j], v[j+1]);
}

int main() {
	int z[12]={14,13,8,7,6,12,11,10,9,-5,1,5};
	ordinare (z, 12);
	for (int i=0; i<12; ++i) cout << z[i] << '\t';
	cout << "ordinato " << endl;
}
