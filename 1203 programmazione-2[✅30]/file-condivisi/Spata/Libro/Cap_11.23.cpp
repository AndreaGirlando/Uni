// 11.23

/* Implementare una classe Punto che
rappresenti punti in tre dimensioni (x, y, z).
Includere un costruttore di default, un
costruttore di copia, una funzione negare()
che trasformi il punto nel suo contrario
(negativo), una funzione norma() che ritorni
la distanza dal punto all’origine (0,0,0) e
una funzione visualizzare() .
*/

#include <iostream>  
using namespace std;

class Punto {
private:
	int x, y;
public:
	Punto() {
		cout << "costruttore di default per nuovo oggetto" << endl;
		}; 
    ~Punto(){}; // distruttore
    Punto(const int &a, const int &b) {
		x = a;
		y = b;
		cout << "costruttore parametrizzato per nuovo oggetto"  << endl;
		}
	Punto(const Punto& originale) {
		x = originale.x;
		y = originale.y;
		cout << "costruttore DI COPIA per nuovo oggetto" << endl;
		}
	void Visualizza() {
		cout << "l'ascissa del punto e' " << x << endl;
		cout << "l'ordinata del punto e' " << y << endl;
		}
};
  
int main() {
  Punto p1;           // costruttore di default
  Punto p2(10, 20);   // costruttore parametrizzato
  Punto cp(p1);       // costruttore DI COPIA
  cout << "visualizzo p1" << endl;
  p1.Visualizza();
  cout << "visualizzo p2" << endl;
  p2.Visualizza();
  cout << "visualizzo c2" << endl;
  cp.Visualizza();
  return 0;
}
