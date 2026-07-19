// 13.9

/* Definire un template di funzione che
restituisca il valore assoluto di qualunque
tipo di dato passatole
*/

#include <iostream>
using namespace std;
  

template <typename T> T abs (T& e) {
	return ((e < 0) ? -e : e);
}
  
int main() {
    int a = -2;
    int b = 3;
    cout << abs(a) << endl;
    cout << abs(b) << endl;
  return 0;
}
