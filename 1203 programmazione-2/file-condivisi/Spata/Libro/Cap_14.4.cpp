// 14.4

/* Data la classe Punto introdotta in que-
sto capitolo, sovrascrivere l’operatore -
per calcolare la distanza di due punti.
*/
#include <iostream>  
using namespace std;

#include <ostream>
#include <istream>
#include <cmath>
class punto {
private:
	int x, y;
public:
	punto() {x = 0; y = 0;}
	punto (int xx, int yy) {x = xx; y = yy;}
	void assegnaX(int xx) {x = xx;}
	void assegnaY(int yy) {y = yy;}
	int leggeX() {return x;}
	int leggeY() {return y;}
	friend ostream& operator << (ostream & , const punto &);
	friend istream& operator >> (istream & , punto &);
	friend float operator - (punto &, punto &);
};

int main() {
	punto p,q; 
	cout << p << '\n'; 
	p.assegnaX(50);
	p.assegnaY(100);
	cout << p << '\n';
	cout << "Introdurre i valori di x ed y del secondo punto\n";
	cin >> q;
	cout << "\nHa introdotto: " << q << endl;
	cout << "La distanza fra i due è " << p - q << endl;
	return 0;
}

float operator - (punto & p, punto & q) {
	return sqrt(pow(p.x - q.x,2) + pow(p.y - q.y,2));
}

ostream& operator << (ostream& os, const punto &p) {
	os << "x = " << p.x << ", y = " << p.y;
	return os;
}

istream& operator >>(istream& is, punto &p) {
	is >> p.x >> p.y;
	return is;
}
