// 20.2
/* Scrivere una funzione che accetta
un albero in input e restituisce il numero
dei suoi nodi.
* 
* METODO: unsigned NumeroNodi() {NumeroNodi(radice);};
*/

#include <iostream>
using namespace std;

struct nodo {
  char info;
  nodo *sx;
  nodo *dx;
};

unsigned contatore;

class btree {
public:
	btree() {radice = NULL;};
	~btree() {distruggi(radice);};
	void I(char chiave) {I(chiave, radice);};
	void E(char chiave) {E(chiave, radice);};
	void In(){In(radice);};
	void Pr(){Pr(radice);};
	void Po(){Po(radice);};
	unsigned NumeroNodi() {NumeroNodi(radice);};
private:
    nodo *radice;
    void distruggi(nodo* &);
    void I(char, nodo* &);
    void E(char, nodo* &);
	void In(nodo*);
	void Pr(nodo*);
	void Po(nodo*);
	unsigned NumeroNodi(nodo*);
};

unsigned btree::NumeroNodi(nodo* p) {
	if(p) {
		NumeroNodi(p->sx);
		NumeroNodi(p->dx);
		contatore++;
	}
	return contatore;
}

void btree::distruggi(nodo* &p) {
	if(p) {
		distruggi(p->sx);
		distruggi(p->dx);
		delete p;
  }
}

void btree::I(char chiave, nodo* &p) {
	if (p != NULL) {
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
	if (p != NULL) {
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
	btree albero;
	albero.I('e');
	albero.I('d');
	albero.I('b');
	albero.I('c');
	albero.I('a');
	albero.I('z');
	contatore=0; cout << "Numero Nodi: " << albero.NumeroNodi() << endl;
	cout << "InOrdine: ";
	albero.In(); cout << endl;
	cout << "PreOrdine: ";
	albero.Pr(); cout << endl;
	cout << "PostOrdine: ";
	albero.Po(); cout << endl;
	albero.E('d');
	cout << "InOrdine: ";
	albero.In(); cout << endl;
	cout << "PreOrdine: ";
	albero.Pr(); cout << endl;
	cout << "PostOrdine: ";
	albero.Po(); cout << endl;
	contatore=0; cout << "Numero Nodi: " << albero.NumeroNodi() << endl;
}
