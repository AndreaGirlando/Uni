# Il problema dello zaino

Il **problema dello zaino** che consiste in:
*dato un insieme di oggetti, ciascuno con un valore e un peso, si vuole scegliere un sottoinsieme che massimizza il valore totale senza superare una capacità massima $K$*. 
Affronteremo questo problema in due versioni
###### Versione 0.1: pesi unitari, valori diversi
In questo caso abbiamo oggetto tutti con lo stesso peso ma valori differenti, lo zaino può contenere solo un numero limitato di pezzi, pari alla capacità $K$, inoltre gli oggetti sono già disposti in ordine crescente di valore, dal meno prezioso al più prezioso, questa rappresenta la forma più semplice di questo problema. Infatti la scelta ottimale e abbastanza logica consiste nel prendere i $K$ oggetti che hanno il valore più alto

**Formalizzazione**: 
- Abbiamo $n$ oggetti ordinati per valore crescente: $$v_1 \le v_2 \le \dots \le v_n \text{ tutti di peso unitario.}$$
- Vogliamo massimizzare il valore complessivo: $$max\{\Sigma_{i \in S} v_i: S ⊆ \{1,\dots,n\}, |S| \le K\}$$ poiché i pesi sono unitari e i valori ordinati, la soluzione ottima è semplicemente: $$S^* = \{n-K+1, n-K+2, \dots, n\}, V^* = \Sigma_{i=n-K+1}v_i$$
- Il problema si risolve in maniera lineare in un tempo di esecuzione $O(K)$ poiché non sono necessarie né scelte condizionali né chiamate ricorsive
  
```C++
int zainoLineare ( int v [] , int n , int K ) { 
	int somma = 0; 
	for ( int i = n - K ; i < n ; i ++) { 
		if ( i >= 0) somma += v [ i ]; 
	} 
	return somma;
}
```

Anche se non prettamente necessario per fini didattici esprimiamo la stessa soluzione anche in modo ricorsivo
$$F(i, k) = \begin{cases} 0 & \text{se } k = 0 \text{ o } i = 0, \\ v_i + F(i - 1, k - 1) & \text{se } k > 0. \end{cases}$$
Ricordiamo che: poiché gli oggetti sono già ordinati non è necessario scegliere se includere o meno l'oggetto $i$: se c'è ancora spazio nello zaino ($k>0$) lo si prende automaticamente

```C++
int F ( int v [] , int i , int k ) { 
	if ( i == 0 || k == 0) return 0; 
	return v [i -1] + F (v , i -1 , k -1);
}
```

La funzione viene richiamata inizialmente con $F(v,n,K)$ e termina dopo $K$ chiamate ricorsive

**Conclusioni**: questo esempio ci permette di capire che un algoritmo iterativo può essere riscritto anche in forma ricorsiva anche quando la ricorsione non offre dei vantaggi in termini di efficienza

###### Versione generale 0/1: pesi e valori variabili
Il problema si evolve, gli oggetti non sono più simili tra loro: ogni oggetto ha dunque il proprio peso $w_i$ e un valore $v_i$ differente. La strategia di risoluzione del problema precedente non funziona più infatti: *un oggetto di grande valore ma troppo pesante potrebbe impedire di portare con se più oggetti leggeri complessivamente più vantaggiosi*,  devono essere valutate tutte le possibili combinazioni e in questo la ricorsione diventa uno strumento fondamentale

**Formalizzazione**: Per ogni oggetto $i$ abbiamo peso $w_i \in N_{>0}$ e valore $v_i \ge 0$ la capacità massima dello zaino è $K \in N$. Vogliamo massimizzare $max\{\Sigma_{i \in S}v_i : S ⊆ {1,\dots,n}, \Sigma w_i \le K\}$ 
- Occorre confrontare sistematicamente le scelte *includo/escludo* 
- Definiamo $F(i,k)$ come prima, i suoi **casi base** sono:
	- $F(i,k) = 0$ se $i=0$ o $k = 0$
	- $F(i, k) = -\infty$ se $k<0$
	- visto che andremo a controllare tutte le possibili combinazioni il $-\infty$ ci serve per squalificare tutte le ricorsioni che superano la capacità massima.
- il suo caso **caso ricorsivo** è: $F(i,k) = max\{F(i-1,k), v_i+F(i-1, k-w_i)\}$

Si osservi che se una soluzione ottima non include $i$ allora è ottima su $(i-1, k)$. Se include $i$ allora la soluzione residua è ottima su $(i-1, k-w_i)$. Massimizzando i due casi otteniamo il valore ottimo.
```C++
int F ( int i , int k , int v [] , int w []) { 
	if ( k < 0) return INT_MIN /4; // rappresenta - infinito 
	if ( i == 0 || k == 0) return 0;
	int senza = F (i -1 , k , v , w ) ; 
	int con = v [ i ] + F (i -1 , k - w [ i ] , v , w ) ; 
	return ( senza > con ) ? senza : con ; 
}
```

La ricorsione da sola restituisce il valore ottimo, per ottenere una soluzione concreta facciamo un confronto locale per capire se $i$ è preso o escluso. Questa semplice soluzione ha complessità $O(n)$ 

###### Esercizi sulla ricorsione
La ricorsione è uno strumento potente per affrontare i problemi di ottimizzazione, gli esercizi dove ci viene chiesto di trova una soluzione ad un problema di ottimizzazione usando la ricorsione devono essere sviluppati seguendo questi passi:
 - **1.** Individuare i casi base che rendono la ricorsione terminante
 - **2.** Determinare la scomposizione del problema in sottoproblemi più piccoli
 - **3.** Stabilire una regola per combinare le soluzioni