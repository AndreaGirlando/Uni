#include <iostream>
#include <iomanip>
using namespace std;

class BST;
class BSTNode {
    public:
        BSTNode(int _d, BSTNode* _dx = nullptr, BSTNode* _sx = nullptr, BSTNode* _padre = nullptr)
            : d(_d), dx(_dx), sx(_sx), padre(_padre) {}
        friend ostream& operator<<(ostream& stream, BSTNode& temp);
        friend class BST;
    private:
        BSTNode* padre;
        BSTNode* dx;
        BSTNode* sx;
        int d;
};

ostream& operator<<(ostream& stream, BSTNode& temp) {
    stream << "Self: " << &temp << " Padre: " << temp.padre << " Dx: " << temp.dx << " Sx: " << temp.sx << " D: " << temp.d << endl;
    return stream;
}

class BST {
    public:
        BST() : root(nullptr) {}//* costruttore
        ~BST();//* distruttore

        void Trapianta(BSTNode* u, BSTNode* v);
        void Delete(BSTNode* z);
        BSTNode* Min();

        void Print();

        BSTNode* Search(int d);

        BST& Insert(int d);

        BSTNode* Next(BSTNode* node);
    private:
        BSTNode* Min(BSTNode* x);
        void PrintTree(BSTNode* node, string prefix = "", bool isLeft = true);
        void DeleteAllTree(BSTNode* x);
        BSTNode* Search(BSTNode* T, int d);
        BSTNode* root;
};

void BST::Delete(BSTNode* nodoDaEliminare) {
    //? se non ha figli sinistri allora trapianto il suo sottoalbero destro al suo posto
    if (nodoDaEliminare->sx == nullptr) Trapianta(nodoDaEliminare, nodoDaEliminare->dx);
    //? se non ha figli destri allora trapianto il suo sottoalbero sinistro al suo posto
    else if (nodoDaEliminare->dx == nullptr) Trapianta(nodoDaEliminare, nodoDaEliminare->sx);
    //? ha sia un figlio destro che sinistro
    else {
        BSTNode* y = Min(nodoDaEliminare->dx); //? cerco il minimo del del sottoalbero destro ergo il successore del nodoDaEliminare
        if (y->padre != nodoDaEliminare) { //? se il successore non è un diretto figlio del nodo da eliminare
            Trapianta(y, y->dx);//? la posizione del successore deve essere presa dal suo sottoalbero destro
            y->dx = nodoDaEliminare->dx; //? eredita il figlio destro
            y->dx->padre = y; //? il padre del figlio destro va aggiornato
        }
        Trapianta(nodoDaEliminare, y);//? y prende il posto del padre
        y->sx = nodoDaEliminare->sx;//? y eredita il figlio sinistro
        y->sx->padre = y; //? aggiorniamo il padre del figlio sinistro
    }
    delete nodoDaEliminare;
}

void BST::Trapianta(BSTNode* oldNode, BSTNode* newNode) {
    if (oldNode->padre == nullptr) { //? se il padre è null allora oldNode è la root quindi vado a sostituirla
        root = newNode;
    } else if (oldNode == oldNode->padre->sx) { //? se è un figlio sinistro lo sostituisco come figlio sinistro
        oldNode->padre->sx = newNode;
    } else { //? se è un figlio destro lo sostituisco come figlio destro
        oldNode->padre->dx = newNode;
    }
    if (newNode != nullptr) { //! il pdare di u diventa il padre di u
        newNode->padre = u->padre;
    }
}
//* Cerchiamo il nodo successivo a quello dato in input
BSTNode* BST::Next(BSTNode* x) {
    //? Caso 1: se esiste un sottoalbero destro, il successore è il minimo del sottoalbero destro
    if (x->dx) {
        return Min(x->dx);  // la funzione Min trova il nodo con valore minimo nel sottoalbero dx
    }

    //? Caso 2: se NON esiste un sottoalbero destro,
    // risalgo verso il padre finché x è un figlio destro
    BSTNode* y = x->padre;  // inizializzo y come il padre di x
    while (y != nullptr && x == y->dx) {  // finché non arrivo alla radice o trovo un nodo in cui x è figlio sinistro
        x = y;           // risalgo: x diventa il padre
        y = y->padre;    // y diventa il padre del nuovo x
    }

    // Quando esco dal ciclo, y è il primo antenato di x in cui x è nel sottoalbero sinistro.
    // Se y è nullptr significa che ho raggiunto la radice e non esiste successore (x era il massimo dell'albero)
    return y;
}

//* Caso base del minimo
BSTNode* BST::Min() {
    return Min(root);
}
//* Funzione ricorsiva che cerca il minimo dentro l'albero e scende verso sinistra
BSTNode* BST::Min(BSTNode* x) {
    BSTNode* node = x;
    while (node->sx != nullptr) {
        node = node->sx;
    }
    return node;
}

//* Caso base ricerca
BSTNode* BST::Search(int d) {
    return Search(root, d);
}
//* funzione ricorsiva che cerca dentro l'albero (quest'ultimo deve essere ordinato)
BSTNode* BST::Search(BSTNode* T, int d) {
    if (T == nullptr || T->d == d) {
        return T;
    }
    if (d < T->d) {
        return Search(T->sx, d);
    }
    return Search(T->dx, d);
}

//* caso base stampa
void BST::Print() {
    cout << "\nAlbero:\n";
    PrintTree(root, "", false);
}
//* funzione ricorsiva di stampa che utilzza dei suffisi/prefissi per creare una visualizzazione migliore
void BST::PrintTree(BSTNode* node, string prefix, bool isLeft) {
    if (node != nullptr) {
        cout << prefix;
        cout << (isLeft ? "├──" : "└──" );
        cout << (node == root? "root:":(isLeft ? "sx:" : "dx:") );
        cout << node->d << endl;

        PrintTree(node->sx, prefix + (isLeft ? "│   " : "    "), true);
        PrintTree(node->dx, prefix + (isLeft ? "│   " : "    "), false);
    }
}

BST::~BST() {
    DeleteAllTree(root);
}
//* Viene richiamata dal distruttore del BST in modo che ricorsivamente elimini tutti i nodi
void BST::DeleteAllTree(BSTNode* node) {
    if (node) {
        DeleteAllTree(node->sx);
        DeleteAllTree(node->dx);
        delete node;
    }
}

//* Inserisco il nuovo nodo facendo attenzione all'ordine tra i nodi
BST& BST::Insert(int d) {
    BSTNode* x = root;
    BSTNode* y = nullptr;

    while (x != nullptr) {
        y = x;
        if (d < x->d) {
            x = x->sx;
        } else {
            x = x->dx;
        }
    }

    BSTNode* nodo = new BSTNode(d);
    nodo->padre = y;

    if (y == nullptr) {
        root = nodo;
    } else if (d < y->d) {
        y->sx = nodo;
    } else {
        y->dx = nodo;
    }

    return *this;
}

int main() {
    BST tree;
    tree.Insert(56).Insert(12).Insert(10).Insert(65).Insert(123).Insert(1).Insert(23);
    tree.Print();

    // cout << "\nElemento cercato (12): " << *(tree.Search(12));
    // cout << "Elemento minimo: " << *(tree.Min());
    // cout << "Next di 10: " << *(tree.Next(tree.Search(10)));
    // cout << "Next del minimo: " << *(tree.Next(tree.Min())) << endl;

    tree.Delete(tree.Search(12));
    tree.Print();

    return 0;
}
