// 5.13
// numero perfetto numero naturale che coincide con 
// la somma dei suoi divisori distinti da sé stesso; 
// per esempio 6 e 28 sono numeri perfetti, in quanto 6 = 1 + 2 + 3 e 28 = 1 + 2 + 4 + 7 + 14.

#include <iostream>
using namespace std;

bool Perfetto (int n) {
	int i, acc = 0;
	for (i=1; i<n; i++) if (n % i == 0) acc += i;
	return (acc == n);
}

int main() {
	int  intero;
	cin >> intero;
	if (Perfetto(intero)) cout << intero << " e' numero perfetto\n";
	else cout << intero << " non e' numero perfetto\n";
	return 0;
}


