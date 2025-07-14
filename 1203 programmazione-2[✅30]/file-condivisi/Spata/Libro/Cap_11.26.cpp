// 11.26
/* 
Implementare una classe Stringa.
Ogni oggetto della classe rappresenta una stringa di caratteri.
I membri dato sono la lunghezza della stringa e la stringa di
caratteri attuale.
Inoltre, si debbono aggiungere costruttori, distruttori, funzioni di 
accesso e funzioni per visualizzare, e anche includere una funzione
carattere(int i)
che restituisca il carattere situato nell’indice i della stringa
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Stringa {
private:
	int lunghezza;                            // lunghezza della stringa
	char *ptrStringa;       //puntatore al primo carattere della stringa
	void setStringa(const char *s);    //funzione che imposta la stringa
public:
	Stringa(const char *s = "");                  // costruttore default
	Stringa(const Stringa &s);                   // costruttore di copia
	~Stringa();                                           // distruttore
	int getLunghezza() const;   //restituisce la lunghezza della stringa
	void Visualizza();
	char Carattere(int);
	int Lunghezza(); 
};

// la lunghezza è 0 oppure lunghezza di s
Stringa::Stringa(const char *s) :lunghezza(s != NULL ? strlen(s) : 0) {
	cout << "costruttore di default e di conversione: " << s << endl;
	setStringa(s);       // utilizzata per creare l'istanza dell'oggetto
}
//costruttore di copia
Stringa::Stringa(const Stringa & s) : lunghezza(s.lunghezza) {
	cout << "costruttore di copia: " << s.ptrStringa << endl;
	setStringa(s.ptrStringa);// ancora per creare l'istanza dell'oggetto
}

Stringa::~Stringa() {
	cout << "distruttore: " << ptrStringa << endl;
	delete [] ptrStringa;
}

int Stringa::getLunghezza() const {
	return lunghezza;
}

// funzione alla base dell'inizializzazione della classe
void Stringa::setStringa(const char * s) {
	ptrStringa = new char[lunghezza + 1];
	if (s != 0) strcpy(ptrStringa, s); //se s punta una stringa la copio
	else  ptrStringa[0] = '\0';     //altrimenti copio una stringa vuota
}

void Stringa::Visualizza() {
	cout << ptrStringa << endl;
}

char Stringa::Carattere(int i) {
	if (i<lunghezza) return *(ptrStringa+i);
	else return '@';
}

int main() {
	Stringa prova1("questa è una prova");
	prova1.Visualizza();
	cout << prova1.Carattere(15) << endl;
	cout << prova1.getLunghezza() << endl;
	Stringa prova2("questa è un'altra");
	prova2.Visualizza();
	cout << prova2.Carattere(15) << endl;
	cout << prova2.getLunghezza() << endl;
	Stringa prova3;
	prova3.Visualizza();
	cout << prova3.Carattere(15) << endl;
	cout << prova3.getLunghezza() << endl;
	return 0;
}

