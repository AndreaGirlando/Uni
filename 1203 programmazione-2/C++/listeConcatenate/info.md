le liste concatenate vengono usate come strutture dinamiche (per rappresentare **gli insiemi dinamici**) anche su C++. Sono strutture dati sequenziali.
![[Pasted image 20250411103307.png|700]]
in C++ si fa con le classi:
```c++
class Node {
	public:
		int data;
		Node* next;
	Node(Node* n, int d): next(n), data(d){} //costruttore che inizzializza il nodo
}
//next può essere null (se è l'ultimo elemento)
```
