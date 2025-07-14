// 11.29
/* 
Scrivere una classe Insieme che gestisca un insieme di interi con 
l’aiuto di una tabella di dimensione fissa (un insieme contiene un
vettore ordinato di elementi che si caratterizza per il fatto che ogni
elemento è unico). Le operazioni da implementare sono le seguenti:
• svuotare() svuota l’insieme;
• aggiunge() aggiunge un intero all’insieme;
• elimina() rimuove un intero dall’insieme;
• unisce() unisce nell'insieme un altro;
• membro() restituisce un valore booleano che indica se l’insieme con-
tiene un certo intero;
• uguale() restituisce un valore booleano che indica se un insieme è
uguale a un altro;
• stampa() stampa a schermo l’insieme in maniera leggibile.
*/

// SUGGERIMENTO: Supponiamo che i numeri vadano da 1 a 100

#include <iostream>
using namespace std;

class Insieme {
private:
	int v[100];
	int ultimo;
public:  
	Insieme(){ultimo=0; for(int i=0;i<100;i++)v[i]=0;};
	void Svuota() {ultimo=0;};
	void Aggiunge(int);
	void Elimina(int);
	void Unisce(Insieme);
	bool Uguale(Insieme);
	bool Membro(int);
	void Stampa();
};

void Insieme::Aggiunge(int elem) {
	int indice=0;
	while (v[indice]<elem && indice<ultimo) indice++;
	if (v[indice] != elem) {
		for (int i=ultimo; i>indice;i--) v[i]=v[i-1];
		v[indice]=elem;
		ultimo++;
	}
};
	
void Insieme::Elimina(int elem) {
	int indice=0;
	while (v[indice] < elem) indice++;
	if (v[indice] == elem) {
		for (int i=indice; i<ultimo;i++) v[i]=v[i+1];
		ultimo--;
	}
};
	
void Insieme::Unisce(Insieme altro) {
	int indice=0;
	while (indice < altro.ultimo) {
		Aggiunge(altro.v[indice]);
		indice++;
	}
};

bool Insieme::Uguale(Insieme altro) {
	int indice=0;
	if (ultimo != altro.ultimo) return false;
	while ((v[indice]==altro.v[indice]) && indice < ultimo) indice++;
	if (indice != ultimo) return false;
	else return true;
};

	
bool Insieme::Membro(int elem) {
	int indice=0;
	while (indice < ultimo) {
		if (v[indice]==elem) return true;
		indice++;
	};
	return false;
};

void Insieme::Stampa() {
	int i=0;
	while (i < ultimo) cout << v[i++] << ' ';
	cout << endl;
}

int main() {
	int n;
	Insieme prova, prova2,prova3;
	prova.Aggiunge(34);
	prova.Stampa();
	prova.Aggiunge(39);
	prova.Stampa();
	prova.Aggiunge(38);
	prova.Stampa();
	cout << "scrivi un numero da 1 a 100\n";
	cin >> n;
	if (prova.Membro(n)) {
		cout << "C'è!\n";
		prova.Elimina(n);
		}
	else cout << "Non c'è!\n";
	prova.Stampa();
	prova2.Aggiunge(34);
	prova2.Aggiunge(38);
	prova2.Aggiunge(39);
	if (prova.Uguale(prova2))  cout<< "Insiemi uguali!\n";
	else cout << "Insiemi diversi!\n";
	prova3.Aggiunge(37);
	prova.Unisce(prova3);
	prova.Stampa();	
	return 0;
}
