// 9.24

#include <iostream>  
#include <cstring>  
using namespace std;

unsigned moltiplica(char *s, unsigned n) {
	unsigned i=atoi(s);
	return i*n;
}

int main() {
	unsigned numero1;
	char numero2[100];
	cout << "scriva due numeri\n";
	cin >> numero1 >> numero2;
	cout << numero1 << " moltiplicato " << numero2 << " fa "
	     << moltiplica(numero2,numero1)<< endl;
	return 0;
}
