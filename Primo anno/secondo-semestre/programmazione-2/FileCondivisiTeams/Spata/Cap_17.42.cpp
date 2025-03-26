// 17.42


/* Scrivere una classe lista semplice-
mente concatenata circolare che permetta
di decidere se la lista è vuota, di vedere
qual è il primo della lista, di aggiungere un
elemento come primo della lista, di cancel-
lare il primo elemento della lista e infine di
cancellare la prima apparizione di un ele-
mento x nella lista
*/

#include <iostream>
using namespace std;

typedef int Tipo_elem;

class Nodo {
    protected:
        Tipo_elem info;
        Nodo* suc;
    public:
        Nodo(){}	                       // costruttore vuoto
        Nodo(Tipo_elem x);	                     // costruttore
        Nodo(Tipo_elem x, Nodo* s);	             // costruttore
        ~Nodo(){}	                             // distruttore
        Tipo_elem get();           // restituisce info elemento
        void put(Tipo_elem info);        // determina info elem
        Nodo* get_suc(); // restituisce puntatore al successivo
        void put_suc(Nodo *p);       // determina il successivo
 };
 
typedef Nodo* lista;
 
Nodo::Nodo(Tipo_elem x) {	
  info = x;  // costruttore che inizializza e ad x e suc a NULL
  suc = NULL;
}
Nodo::Nodo(Tipo_elem x, Nodo* s) {	
  info = x;    // costruttore che inizializza e ad x e suc ad s
  suc = s;
}
Tipo_elem Nodo::get() {	
  return info;//restituisce una copia del contenuto informativo
}
void Nodo::put(Tipo_elem x) {	
  info = x;      // determina il contenuto informativo del nodo
}
Nodo* Nodo::get_suc() {	
  return suc;   //  restituisce il puntatore al nodo successivo
}
void Nodo::put_suc(Nodo *p) {
  suc = p; 	       // determina il puntatore al nodo successore
}

void stampaLista(lista p) {
	while (p != NULL) {
		cout << p->get() << ' ';
		p = p->get_suc();
	}
	cout << ' ' << endl;
}

void inserisci_in_testa(lista& inizio, Tipo_elem e) {
   lista nuovo = new Nodo(e, inizio);   // genera nuovo Nodo
   inizio = nuovo ;               // inizio punta il nuovo Nodo
}

void inserisci_in_coda(lista& inizio, Tipo_elem e) {
 lista p, q = inizio;
 while (q != NULL) {
	 p = q;
	 q = q->get_suc();
 }
 q = new Nodo(e); // inizializza info ad e e suc a NULL
 if (inizio == 0) inizio->put_suc(q);
     else p->put_suc(q);
}

void inserisci_ordinatamente(lista& inizio, Tipo_elem e) {
 lista r, p = NULL, q = inizio;
 while ((q != NULL) && (q->get() < e)) {
	 p = q;
	 q = q->get_suc();
 }
 r = new Nodo(e,q);
 if (q == inizio) inizio = r;  // se si deve inserire in testa
     else p->put_suc(r);
}

bool estrai_dalla_testa(lista& inizio, Tipo_elem& e) {
 lista p = inizio;
 if (inizio == NULL) return false;
 e = p->get();
 inizio = p->get_suc();
 delete p;
 return true;
}

bool estrai_dalla_coda(lista& inizio, Tipo_elem& e) {
 lista p, q = inizio;
 if (inizio == NULL) return false;
  while (q->get_suc() != NULL) {
	 p = q;
	 q = q->get_suc();
 }
 e = q->get();
 if (q == inizio) inizio = NULL; // se si estrae il primo elemento
     else p->put_suc(NULL);
 delete q;
 return true;
}

bool estrai_elem_dato(lista& inizio, Tipo_elem& e) {
	lista p, q = inizio;
	while ((q != NULL) && (q->get() != e)) {
	 p = q;
	 q = q->get_suc();
 }		
 if (q == NULL) return false;   // l'elemento non è stato trovato
 if (q == inizio) inizio = q->get_suc();   // l'elemento cercato era il primo
     else p->put_suc(q->get_suc());
 e = q->get();
 delete q;
 return true;
}

int conta_elem_dato(lista& inizio, Tipo_elem& e) {
	int cont=0;
	lista q = inizio;
    while (q != NULL) {
	  if (e==q->get()) cont++;
	  q = q->get_suc();
    }
    return cont;
}

int sommatoria(lista& inizio) {
	int somma=0;
	lista q = inizio;
    while (q != NULL) {
		somma += q->get();
	    q = q->get_suc();
    }
    return somma;
}


int main() {
	char r;
	lista scritto = 0;
	Tipo_elem el;
	do {
		cout << "i: inserisci in testa\n" 
			 << "c: inserisci in coda\n" 
		     << "o: inserisci ordinatamente\n"
		     << "t: estrai dalla testa\n" << "e: estrai dalla coda\n"
		     << "f: estrai un particolare elemento\n"
		     << "s: stampa la lista\n"
		     << "r: conta occorenze elemento dato\n";
		cin >> r;
		switch (r) {
			case 'i': cin >> el; inserisci_in_testa(scritto, el); break;
			case 'c': cin >> el; inserisci_in_coda(scritto, el); break;
			case 'o': cin >> el; inserisci_ordinatamente(scritto, el); break;
            case 't': estrai_dalla_testa(scritto, el); cout << "Ho tolto " << el; break;
            case 'e': estrai_dalla_coda(scritto, el); cout << "Ho tolto " << el; break;
            case 'f': cout << "Da togliere?  "; cin >> el;estrai_elem_dato(scritto, el);  break;
            case 's': stampaLista(scritto); break;
            case 'r': cin >> el; cout << conta_elem_dato(scritto, el) << endl; break;
    }
  }
 while (r == 'i' || r == 'c' || r== 'o' || r == 't' || r == 'e' || r== 'f' || r== 's' || r== 'r');
 return 0;
}
