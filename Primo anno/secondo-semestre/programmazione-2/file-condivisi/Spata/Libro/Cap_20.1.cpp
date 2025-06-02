// 20.1
/* Scrivere un programma che processa un albero binario i cui nodi conten-
gono caratteri; le funzioni sono le seguenti:
I (seguito da un carattere): inserisce un carattere
E (seguito da un carattere): elimina un carattere
In : Visita inordine
Pr : Visita in preordine
Po : Visita in postordine
*/

#include <iostream>
using namespace std;

struct nodo {
  char info;
  nodo *sx;
  nodo *dx;
};

class btree {
public:
	btree() {radice = NULL;};
	~btree() {distruggi(radice);};
	void I(char chiave) {I(chiave, radice);};
	void E(char chiave) {E(chiave, radice);};
	void In(){In(radice);};
	void Pr(){Pr(radice);};
	void Po(){Po(radice);};
private:
    nodo *radice;
    void distruggi(nodo* &);
    void I(char, nodo* &);
    void E(char, nodo* &);
	void In(nodo*);
	void Pr(nodo*);
	void Po(nodo*);
};

void btree::distruggi(nodo* &p) {
  if(p) {
    distruggi(p->sx);
    distruggi(p->dx);
    delete p;
  }
}

void btree::I(char chiave, nodo* &p) {
	if (p) {
		if(chiave < p->info) {
			if(p->sx != NULL) I(chiave, p->sx);
			else {
				p->sx = new nodo;
				p->sx->info = chiave;
				p->sx->sx = NULL; // il figlio sx del nuovo nodo è NULL
				p->sx->dx = NULL; // il figlio dx del nuovo nodo è NULL
			}  
		}
	else if(p->dx != NULL) I(chiave, p->dx);
		 else {
				p->dx = new nodo;
				p->dx->info = chiave;
				p->dx->sx = NULL; // il figlio sx del nuovo nodo è NULL
				p->dx->dx = NULL; // il figlio dx del nuovo nodo è NULL
			}
	}
	else {
		p = new nodo;
		p->info = chiave;
		p->sx = NULL;
		p->dx = NULL;
	}	
}

void btree::E(char chiave, nodo* &p) {
	nodo* temp;
	if (p) {
		if(chiave < p->info) E(chiave, p->sx);
		else if(chiave > p->info) E(chiave, p->dx);
		     else {
		     if (p->sx==NULL && p->dx==NULL) {
				 temp = p;
				 p = NULL;
				 delete temp;
			 }
			 else if (p->sx == NULL) {
				temp = p;
				p = p->dx;
				delete temp;
				}
				else if (p->dx == NULL) {
					temp = p;
					p = p->sx;
					delete temp;
					}
				else {
					temp = p->dx;
					while (temp->sx != NULL) temp = temp->sx;
					p->info = temp->info;
            		E(temp->info, p->dx);
				}
		}	
	}
}

void btree:: In(nodo* p) {
	if (p) {
		In(p -> sx);
		cout << p->info << ' ';
		In(p -> dx);
		}
}

void btree:: Pr(nodo* p) {
	if (p) {
		cout << p->info << ' ';
		Pr(p -> sx);
		Pr(p -> dx);
		}
}

void btree:: Po(nodo* p) {
	if (p) {
		Po(p -> sx);
		Po(p -> dx);
		cout << p->info << ' ';
		}
}

int main() {
	btree albero;                                  // generiamo l'albero
	albero.I('e');                                 // popoliamo l'albero
	albero.I('d');
	albero.I('b');
	albero.I('c');
	albero.I('a');
	albero.I('z');
	cout << "InOrdine: ";
	albero.In(); cout << endl;        // visualizziamo l'albero InOrdine
	cout << "PreOrdine: ";
	albero.Pr(); cout << endl;       // visualizziamo l'albero PreOrdine
	cout << "PostOrdine: ";
	albero.Po(); cout << endl;      // visualizziamo l'albero PostOrdine
	albero.E('d');                                 // eliminiamo un nodo
	cout << "InOrdine: ";
	albero.In(); cout << endl;
	cout << "PreOrdine: ";
	albero.Pr(); cout << endl;
	cout << "PostOrdine: ";
	albero.Po(); cout << endl;
}
