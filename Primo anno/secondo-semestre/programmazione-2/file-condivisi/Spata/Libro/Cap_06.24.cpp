// 6.24
#include <iostream>
using namespace std;

struct studente {
	string nome;
	string cognome;
	int eta;
	int voto;
};

studente uno_studente;

void visualizza_nome(studente s) {
	cout << s.cognome << ' ' << s.nome << endl;
}

void visualizza_studente(studente s) {
	cout << s.cognome << ' ' << s.nome << ' ' 
	     << s.eta << ' ' << s.voto << endl;	
}

int main() {
	cout << "Per favore, immetta nome, cognome, età e voto dello studente\n";
	cin >> uno_studente.nome >> uno_studente.cognome
	    >> uno_studente.eta >> uno_studente.voto;
	visualizza_nome(uno_studente);
	visualizza_studente(uno_studente);
	return 0;
}
