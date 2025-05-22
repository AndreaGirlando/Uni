Si dice **grafo diretto** un insieme di nodi collegati mediante archi, un albero è un grafo diretto in cui ogni nodo può avere un solo arco entrante ed un qualunque numero di archi uscenti. In generale possiamo dire che: 
- Se una nodo non ha archi uscenti si dice **"foglia"** 
- se un nodo non ha archi entranti questo si chiama  **"radice"** ed è unico


Un albero è un insieme di nodi che è:
- è vuoto
- oppure ha un nodo radice da cui discendono zero o più sottoalberi

Il **livello** di un nodo è la sua distanza dalla radice, la radice ha livello 0, i figli diretti hanno livello 1.
la **profondità** di un albero è la lunghezza del cammino più lungo e viene definita per induzione:
- **Caso base**: la radice ha profondità 0
- **Caso induttivo**: la profondità di un nodo non radice è 1+la profondità del genitore
```txt
Profondita(u){
	p = 0;
	while(u.genitore != null){
		p=p+1;
		u = u.genitore;
	}
}
```

Un **albero è bilanciato** se:
1. Tutte le foglie si trovano allo stesso livello
2. Dato k numero massimo di figli per nodo, ogni nodo interno ha al max k figli

Un **albero binario** è un albero dove ogni nodo ha al massimo due nodi figli

Un **albero degenere** è un albero dove ogni nodo diverso da quello foglia ha un solo figlio

Un albero di profondità $n$ può contenere al massimo $2^{(n+1)}-1$ se l'albero è bilanciato allora questa diventa $O(\log n)$   

![[Pasted image 20250522145320.png]]
Un albero viene implementato usando nel nodo un puntatore al figlio destro e uno a quello sinistro

---

**Albero binario di ricerca**: preso  $x$ nodo generico. 
- Se $y$ è un nodo nel sotto-albero sinistro di radice $x$ allora $y.valore < x.valore$. 
- Se $y$ è un nodo del sotto-albero destro di radice $x$ allora $y.valore \ge x.valore$
> [!tip] 
> è importante garantire questa proprietà sempre, ogni volta che inseriamo o eliminiamo nodi

![[Pasted image 20250522150225.png]]
il problema principale si ha durante la fase di eliminazione del nodo, perché eliminiamo il nodo "2" cosa mettiamo al suo posto? di seguito verrà chiarita questa cosa
- **Inserimento**: riusciamo a capire dove inserire il nodo usando la proprietà di prima, se l'elemento che dobbiamo inserire è minore del nodo dove ci troviamo scendiamo a sx sennò a dx.
- **Eliminazione**: guarda implementazione
[[Primo anno/secondo-semestre/programmazione-2/C++/Alberi/main.cpp|Implementazione]]

Visitiamo un albero in tre modi:
1. **preorder**: visito prima la radice e quindi i sottoalberi da sinistra verso destra
2. **inorder**: visito il sottoalbero sinistro quindi la radice e poi il sottoalbero destro (stampiamo albero in ordine)
3. **postorder**: visito il sottoalbero sinistro, destro e poi la radice