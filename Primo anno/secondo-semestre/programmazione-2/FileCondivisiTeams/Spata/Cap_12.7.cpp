// 12.7

/* Progettare la seguente gerarchia di
classi:
...
Scrivere un programma che gestisca la
gerarchia di classi, legga un oggetto di
ogni classe e lo visualizzi a schermo:
a) senza utilizzare funzioni virtuali;
b) utilizzando funzioni virtuali.
* */

// per valutare la differenza togliere la parola "virtual"
// i nomi scrivili senza spazi

#include <iostream>  
using namespace std;

class Persona {
protected: 
	char nome[30];
	short unsigned eta;
public:
	Persona();
	~Persona(){cout << "elimino una persona\n";};
	virtual void Visualizza();
};

Persona::Persona(){
	cout << "Come si chiama la persona?\n";
	cin >> nome;
	cout << "Che età ha?\n";
	cin >> eta;
}

void Persona::Visualizza() {
	cout << "La persona si chiama " << nome << " e ha " 
	     << eta << " anni\n";
}

class Studente : public Persona {
private:
	short unsigned id;
public:
	Studente();
	~Studente(){cout << "elimino uno studente\n";};
	void Visualizza();
};

Studente::Studente() {
	cout << "Qual'è l'ID dello studente?\n";
	cin >> id;
}

void Studente::Visualizza() {
	cout << "Lo studente si chiama " << nome << ", ha come ID " 
	     << id << " ed ha " << eta << " anni\n";
}

class Professore : public Persona {
private:
	short unsigned salario;
public:
	Professore();
	~Professore(){cout << "elimino un professore\n";};
};

Professore::Professore() {
	cout << "Qual'è il salario del professore?\n";
	cin >> salario;
}


int main() {
  Persona a;
  Studente b;
  Professore c;
  Persona * personaggi[3];
  personaggi[0]=&a; personaggi[1]=&b; personaggi[2]=&c;
  for (int i=0; i<3; i++) personaggi[i]->Visualizza();
  return 0;
}
