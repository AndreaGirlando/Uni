# Risoluzione delle equazioni di ricorrenza

### Introduzione alle equazioni di ricorrenza
Per analizzare il tempo di esecuzione di tutti gli algoritmi (e in particolare dei ricorsivi) si fa uso delle *equazioni di ricorrenza* che esprimono il costo totale $T(n)$ in funzione del costo dei sotto-problemi e del lavoro aggiuntivo

###### Definizione
Un'equazione di ricorrenza è una relazione del tipo: $$T(n) = aT(\frac{n}{b})+f(n)$$con:
- $T(n)$ costo per il risolvere il problema di dimensione $n$
- $a$ è il numero di sotto-problemi in cui il problema viene suddiviso
- ciascun sotto-problema ha dimensione $\frac{n}{b}$
- $f(n)$ rappresenta il lavoro non ricorsivo (cioè il costo per dividere, combinare o gestire i sotto-problemi)

###### Risoluzione dell'equazione di ricorrenza
La *soluzione* (anche detta *forma esplicita*) indica un'espressione chiusa per $T(n)$, utile per comprendere come cresce il tempo di esecuzione al crescere di $n$. Per fare questa cosa usiamo tre metodi:
1. **Metodo dell'albero di ricorsione**: si rappresenta la ricorsione come un albero, si calcola il costo per livello poi sommati per conoscere il costo totale, questo metodo viene usato principalmente per capire dove si concentra il lavoro (livelli iniziali o finali).
2. **Metodo della sostituzione**: si formula un'ipotesi sul comportamento asintotico di $T(n)$ e la si dimostra per induzione
3. **Metodo Master**: fornisce un risultato generale che consente di determinare l'ordine di grandezza di $T(n)$ confrontando $f(n)$ con $n^{\log_b a}$

### Identificare l'equazione di ricorrenza
###### Fasi della ricorsione
Ogni algoritmo ricorsivo può essere idealmente scomposto in tre momenti:
1. *fase di suddivisione*: il problema viene suddiviso in più sotto-problemi di dimensione minore 
2. *fase di risoluzione*: ciascun sotto-problema viene affrontato a sua volta in modo ricorsivo
3. *fasi di composizione*: i risultati parziali vengono combinati
Detto ciò possiamo aggiungere alla spiegazione dell'equazione di ricorrenza le seguenti cose: $$T(n) = aT(\frac{n}{b})+f(n)$$
- $a$ è il numero di sotto-problemi prodotti
- $b$ il fattore di riduzione
- $f(n)$ il costo complessivo delle operazioni non ricorsive

###### Esempio - Ricerca binaria
Nel caso della ricerca binaria, l'algoritmo esami un intervallo ordinato, ne calcola il pinto medio e confronta il valore cercato con l'elemento corrispondente. Se il valore coincide la ricerca termina, altrimenti viene richiamata ricorsivamente sull'altra metà
```C
int binarySearch(int A[], int low, int high, int x) { 
	if (low > high) return -1; 
	
	int mid = (low + high) / 2; 
	if (A[mid] == x) 
		return mid; 
	else if (A[mid] > x) 
		return binarySearch(A, low, mid - 1, x); 
	else 
		return binarySearch(A, mid + 1, high, x); 
	}
```

In ogni chiamata si effettua al massimo una sola chiamata ricorsiva su metà dell'intervallo, mentre il lavoro non ricorsivo è costante. L'equazione di ricorrenza quindi è: $$T(n) = T(\frac{n}{2})+1$$
Ci sono altri esempio nel file [[4-risoluzione delle Equazioni di Ricorrenza.pdf|pdf]]

### Ricorrenze non uniformi
Non tutti gli algoritmi ricorsivi possono essere descritti mediante un'equazione del tipo: $$T(n) = aT(\frac{n}{b})+f(n)$$in cui il problema viene suddiviso in un numero costante di sotto-problemi. In molti casi reali, la dimensione dei sotto-problemi può variare a seconda dei dati.

###### Esempio - quickSort
- **Caso ideale**: l'elemento *pivot* scelto divide l'array esattamente in due parti uguali, ciascuna di dimensione $\frac{n}{2}$
- **Caso reale**: il *pivot* scelto non divide il nostro array in due array di dimensioni diverse
Nel caso medio possiamo dire che:
$$T(n) = T(\alpha n) + T((1-\alpha)n) + n$$dove il parametro $\alpha$ rappresenta la frazione di elementi che ricadono nella prima metà dopo la partizione ($0< \alpha <1$). 
Quando $\alpha = \frac{1}{2}$ siamo nel caso bilanciato (il caso ideale), quando $\alpha$ si avvicina a 0 o a 1 il costo peggiora fino al caso limite.

###### Analisi
L'esempio appena fatto ci mostra come occorre analizzare la ricorrenza caso per caso, e non sempre possibili applicare le formule standard.

### Il metodo dell'albero di ricorsione
Il metodo dell'albero di ricorsione nasce dall'idea di visualizzare come vengono effettuate le chiamate ricorsive. In questo modo diventa possibili analizzare passo dopo passo come si distribuisce il lavoro complesso nei diversi livelli di ricorsione, tutto ciò viene fatto con la seguente notazione

###### Notazione
ricordiamo sempre l'equazione di ricorrenza generale: $T(n) = aT(\frac{n}{b})+f(n)$
- La *radice* corrisponde al problema iniziale di dimensione $n$
- i *nodi interni* rappresentano le chiamate ricorsive generate a ciascun livello
- ogni *nodo* è etichettato con il costo del lavoro locale $f(n_i)$ dove $n_i$ è la dimensione del sotto-problema corrispondente
- i *figli* di un nodo rappresentano le chiamate generate da quel nodo, ognuna di dimensione ridotta di un fattore $b$

###### Analisi
La costruzione di questo albero permette di scomporre la ricorsione in livelli. A ogni livello $k$ il numero di nodi è $a^k$  di conseguenza la dimensione dei sotto-problemi è $\frac{n}{b^k}$. Il costo totale associato al livello $k$ viene descritto come: $$C_k = a^k f(\frac{n}{b^k})$$cioè il numero di nodi di quel livello moltiplicato per il costo del lavoro svolto in ciascun nodo. Quindi il costo totale diventa: $$
T(n) = \sum_{k=0}^{L} C_k = \sum_{k=0}^{L} a^k f\left(\frac{n}{b^k}\right),
$$

 