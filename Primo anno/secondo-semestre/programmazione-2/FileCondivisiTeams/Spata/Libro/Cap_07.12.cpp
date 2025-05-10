// 7.12

#include <iostream>
using namespace std;

int main() {
	double vettore[10]={0.1,1.1,2.1,3.1,4.1,5.1,6.1,7.1,8.1,9.1};
	double copia[10];
	for (int i=0; i<10; i++) {
		*(copia +i) = *(vettore +i);
		cout << copia[i] << ' ';
	}
	return 0;
}


