# Grafi

### Proprietà dei grafi
###### Definizione e proprietà
Un grafo è definito come $$G=(V,E)$$con 
- $V = \{v_1,v_2,v_3 \dots v_n\}$ insieme di vertici
- $E = \{\;(a_i,a_j)\;: i,j \in V\}$ insieme di archi

Se $(v_i, v_j) = (v_j, v_i)$ allora il grafo si dice **non orientato**
Se $(v_i, v_j) \not = (v_j, v_i)$ allora il grafo si dice **orientato**

###### Cammino
Dato un percorso $P= \; <u_1,u_2,u_3,\dots u_k>$ è un cammino se:
- $u_i \in V \quad \forall i \in 1\le i \le k$ (tutti gli elementi devono essere vertici del grafo)
- $(u_i, u_{i+1}) \in E  \quad \forall i \in 1\le i \le k$ (ogni coppia di nodi consecutivi deve essere collegata da un arco)

Se nel cammino abbiamo che $u_1 = u_k$ allora c'è un **ciclo**

###### Cammino semplice
I nodi devono essere tutti diversi, quindi è un cammino senza cicli

###### Grafo aciclico
Un grafo è detto aciclico quando non ha cicli
*Se un grafo ha un ciclo allora ne ha infiniti*

###### Grafo pesato
Un grafo è pesato se ad ogni arco diamo un peso una la funzione peso: $$w: E \rightarrow R$$quindi il costo totale di un eventuale cammino è: $$w(P) = \sum_{i=1}^{k-1}w(u_i,u_{i+1})$$*la maggior parte dei grafi pesati ha valori positivi negli archi*

###### Ordinamento topologico
Un ordinamento topologico è un ordinamento lineare dei nodi in modo che valga la relazione: $$\exists (u,v) \in R \Rightarrow u < v$$
*Ovviamente se c'è un ciclo questa caratteristica non può essere rispettata*
![[Pasted image 20251222154733.png]]Un eventuale ordinamento di questo grafo è: $A-F-D-G-C-E-B$

###### Componente connessa e fortemente connessa
**Componente connessa**: dato un grafo $G = (V, E)$ diciamo che due vertici $u, v$ sono connessi se esiste un cammino da $u$ a $v$

**Componente fortemente connessa**: dato un grafo orientato $G = (V , E)$, diciamo che due vertici $u, v$ sono fortemente connessi se esiste sia un cammino da $u$ a $v$ che un cammino da $v$ ad $u$.

###### Rappresentazioni dei grafi
**Tramite matrice di adiacenza**: Dato un grafo $G = (V,E)$ con $|V| = n$. La matrice $M$ detta matrice di adiacenza del grafo ha dimensione $n \times n$ dove $n$ è il numero di vertici, ed è formata in questo modo:
- $M[i, j] = 1$ se i vertici $i$ e $j$ sono connessi da un arco
- $M[i, j] = 0$ se i vertici $i$ e  $j$ non sono connessi da un arco
![[Pasted image 20250108163003.png|500]]
**Tramite lista di adiacenza**: un grafo può essere rappresentato pure con le liste di adiacenza, ovvero un array i cui elementi sono i nodi e per ogni nodo viene associato un altro array con la lista dei nodi collegati ad esso. 
![[Pasted image 20250110135330.png|500]]
### BFS
###### Definizione 
La Breadth-First-Search ovvero ricerca in ampiezza è una algoritmo di ricerca nei grafi. Dato un grafo $G = (V,E)$ e un vertice distinto $s$ detto *sorgente*, la visita in ampiezza ispeziona sistematicamente gli archi di $G$ per "scoprire" tutti i vertici che sono raggiungibili da $s$. 
###### Implementazione
Per tenere traccia del lavoro svolto, la visita in ampiezza colora i vertici di:
- *bianco*: nodo non ancora visitato
- *grigio*: nodo scoperto ma non ancora visitato
- *nero*: nodo visitato

All'inizio tutti i nodi sono bianchi, si sceglie un nodo iniziale (la sorgente $s$) e da li:
- Aggiungiamo ad una coda tutti i nodi adiacenti a $s$ da (colorandoli di grigio)
- Per ogni nodo aggiunto alla coda calcoliamo la sua distanza da $s$

```
BFS(V, s)
	Foreach v in V //for di inizializzazione
		color[v] = White
		d[v] = +infinito
		
	d[s] = 0; // la distanza della sorgente da stessa è 0
	Q = { } // inizializzazione della coda come vuota
	Q.enqueue(s)
	While Q != {} DO
		v = Q.dequeue(Q)
		foreach u in ADJ(v) //scorriamo tutti i nodi adiacenti a v
			if(color[u] == W) 
				d[u] = d[v]+1
				color[u] = Gray
				Q.enqueue(u)
		color[v] = Black
```

La ricerca oltre a calcolare la distanza di ogni nodo dalla sorgente $s$ crea un albero, detto albero BFS dove il cammino che va da $s$ ad un generico $v$ corrisponde al *cammino minimo* da $s$ a $v$

![[Pasted image 20251223125121.png]]

### DFS
###### Definizione
Un altro algoritmo di ispezione dei grafi è il depth first search, a differenza del BFS dove la ricerca era in ampiezza qui abbiamo una ricerca in profondità, vedremo successivamente che questo algoritmo ci permette di trarre dal nostro grafo diverse informazioni utili come:
- la composizione delle componenti connesse
- un ordinamento topologico
tutto questo lo facciamo grazie all'albero DFS che crea durante la ricerca. Vedremo diverse implementazioni

###### Premesse comuni alle implementazioni fatte
I nodi sono colorati in modo diverso in base allo stato in cui si trovano:
- *bianco*: nodo non ancora visitato
- *grigio*: nodo scoperto ma non visitato
- *nero*: nodo visitato
Nella nostra implementazione teniamo traccia del tempo di inizio e fine visita di un nodo usando due array $d$ e $F$, con $d[v]$ e $d[F]$ indichiamo rispettivamente il tempo di inizio e fine di $v$ ($T$ sarà una variabile che scandirà il tempo di esecuzione)![[Pasted image 20251223124440.png]]Avremo anche altri due array:
- $color[v]$: che ci indicherà il colore del nodo v
- $\Pi[v]$: che ci indicherà il padre di quel nodo nel albero DFS 
Inoltre useremo una funzione $adj(v)$ che ritorna una lista dei nodi adiacenti a $v$

###### Prima implementazione
```
DFS-visit(v):
	color[v] = gray;
	foreach u in adj(v)
		if color[u] = white
			π[u] = v
			DFS-visit(u)
		color[v] = black

DFS(G,s):
	foreach v in V DO:
		color[v] = white
		π[] = null
DFS-visit(s);
```
Questa è l'implementazione più grezza, infatti ci potrebbero essere dei nodi non visitati, ad esempio quelli non collegati a nulla. Da queste problematiche nasce la seconda implementazione.

###### Seconda implementazione
In questa implementazione aggiungiamo un for che scorre la lista dei nodi, in modo che qualsiasi nodo verrà sicuramente visitato, il fatto che ogni nodo può essere una ipotetica sorgente potrebbe creare più alberi DFS ovvero una *foresta DFS*
```
DFS-visit(v):
	color[v] = gray;
	foreach u in adj(v)
		if color[u] = white
			π[u] = v
			DFS-visit(u)
		color[v] = black

DFS(G,s):
	foreach v in V DO:
		color[v] = white
		π[] = null
	foreach v in V DO:
		if color[v] = white:
			DFS-visit(s);
```
Questa implementazione è perfetta, ma non raccoglie nessuna informazione sul nostro grafo, da qui nasce la necessità di introdurre $d$ e $F$ per scandire il tempo, usati nella terza implementazione

###### Terza implementazione
```
DFS-visit(v):
	d[v] = T
	T = T+1
	color[v] = gray;
	foreach u in adj(v)
		if color[u] = white
			π[u] = v
			DFS-visit(u)
		color[v] = black
	F[v] = t
	t = t+1

DFS(G,s):
	foreach v in V DO:
		color[v] = white
		π[] = null
	foreach v in V DO:
		if color[v] = white:
			DFS-visit(s);
```
Alla fine avremo alla fine di questo algoritmo negli array $d$ ed $F$ il tempo di inizio e fine, molto utile nell'utilizzo della DFS per scopi terzi. Di seguito un grafo con le informazioni ottenute dopo una DFS:
![[Screenshot_20251223_142604_Samsung capture.jpg|500]]
###### Etichette degli archi
Nel nostro grafo etichettiamo gli archi in base al ruolo che hanno durante l'esplorazione del grafo, e sono:
- *T* archi consecutivi: sono gli archi usati dalla DFS per scoprire nuovi nodi
- *I* archi all'indietro: collegano un nodo a un suo antenato nell'albero DFS
- *F* archi in avanti: collegano un nodo al suo discendente
- *C* archi trasversali: collegano nodi che non hanno relazione antenato-discendente

###### Per cosa usiamo la DFS
**Ordinamento topologico**: dato il tempo di inizio e fine visita di ogni vertice del grafo otteniamo un ordinamento topologico valido se mettiamo i vertici in ordine rispetto a di fine visita:
![[Screenshot 2025-12-23 143622.png|500]]
Dai tempi di fine visita otteniamo un ordinamento topologico: $D-G-B-A-E-F-C$
**Identificazione delle componenti connesse**: per identificare le componenti connesse di un grafo facciamo uso della DFS nel seguente modo:
1. Faccio una DFS e metto in ordine rispetto al tempo di inizio visita
2. Creo il grafo trasposto di quello dato in input (inverto le direzioni di tutti gli archi)
3. Faccio la DFS sul grafo trasposto usando nel foreach principale la lista di nodi definita nel punto 1
Otteniamo una foresta di alberi DFS, tanti alberi quanti sono le componenti connesse. Di seguito un esempio: ![[Pasted image 20251223144742.png|500]]
# Ricerca dei cammini minimi

### Introduzione
###### Definizioni
In un *problema dei cammini minimi* sono dati:
- un grafo orientato pesato $G = (V,E)$
- funzione peso $w: E \rightarrow R$ che associa agli archi dei pesi
Il peso di un cammino $p = <v_0, v_1, \dots, v_k>$ è la somma dei pesi degli archi che lo compongono: $$w(p) = \sum_{i=1}^{k}w(v_{i-1},v_i)$$il peso di un cammino minimo $\delta(u,v)$ da $u$ a $v$ è definito in questo modo:
$$
\delta(u, v) = \begin{cases} 
\min \{ w(p) : u \stackrel{p}{\leadsto} v \} & \text{se esiste un cammino da } u \text{ a } v \\
\infty & \text{negli altri casi}
\end{cases}
$$

Un **cammino minimo** è definito come un cammino qualsiasi $p$ con peso $w(p) = \delta(u,v)$

###### Varianti di questo problema
Esistono 4 varianti del problema dei cammini minimi:
1. *Problema dei cammini minimi da sorgente unica(single source)*: dato un grafo vogliamo trovare un cammino minimo che va da un dato vertice sorgente $s \in V$ a ciascun vertice $v \in V$ 
2. *Problema dei cammini minimi con destinazione unica(single destination)*: trovare un cammino minimo da ciascun vertice $v$ a un dato vertice $t$ destinazione. (Invertendo la direzione di ciascun argo nel grafo lo possiamo ricondurre la primo caso)
3. *Problema del cammino minimo per una coppia di vertici(single pair)*: trovare un cammino minimo da $u$ a $v$, e una variante del primo problema.
4. *Problema dei cammini minimi fra tutte le coppie di vertici(all-pairs)*: trovare un cammino minimo da $u$ a $v$ per ogni coppia di vertici.
Di seguito affronteremo il primo e il quarto.

### Proprietà dei cammini minimi
###### Sottostruttura ottima
**Teorema**: Dati
- un grafo orientato $G = (V,E)$ 
- la funzione peso $w: E \rightarrow R$ 
- sia $p = (v_0,v_1, \dots, v_k)$ un cammino minimo dal vertice $v_0$ al $v_k$ 
per qualsiasi $i$ e $j$ tali che $0\le i \le j \le k$ sia $p_{ij}$ un sotto-cammino di $p$ dal vertice $v_i$ al vertice $v_j$ allora $P_{ij}$ è un cammino minimo da $v_i$ a $v_j$
**Dimostrazione**: Se scomponiamo il cammino $p$ in $$\nu_0 \overset{p_{0i}}{\leadsto} \nu_i \overset{p_{ij}}{\leadsto} \nu_j \overset{p_{jk}}{\leadsto} \nu_k $$abbiamo $w(p) = w(p_{0i})+w(p_{ij})+w(p_{jk})$. 
Supponiamo adesso che ci sia un cammino $p'_{ij}$ da $v_i$ a $v_j$ con peso $w(p'_{ij})<w(p_{ij})$. Allora $\nu_0 \overset{p_{0i}}{\leadsto} \nu_i \overset{p'_{ij}}{\leadsto} \nu_j \overset{p_{jk}}{\leadsto} \nu_k$ è un cammino da $v_0$ a $v_k$ il cui peso è minore di $w(p)$ che contraddice l'ipotesi che $p$ sia un cammino minimo da $v_0$ a $v_k$
###### Archi di peso negativo e cicli
All'interno del nostro grafo potrebbero essere contenuti dei cammini di peso negativo, o anche dei cicli:
- Quando *non sono presenti* dei cicli di peso complessivo negativo raggiungibili è sempre possibile definire $\delta(s,v)$
- Quando *sono presenti* dei cicli di peso complessivo negativo non sarà possibile individuare di $\delta(s,v)$ in quanto sarà sempre possibile diminuirlo effettuando un numero indefinito di passi all'interno del ciclo. In tal caso diremo che $\delta(s,v) = -\infty$
###### Rilassamento dei cammini minimi
Il processo di *rilassamento di un arco* consiste nel verificare se passando per $u$, è possibile migliorare il cammino minimo per $v$ da $s$ precedentemente trovato. Nelle nostre implementazioni avremo un array $d$ dove $d[v]$ è peso del cammino da $v$ ad $s$, con ogni passo di rilassamento possiamo ridurre questo valore.

```
RELAX(u,v,w):
	if(d[v]>d[u]+w(u,v))
		d[v] = d[u]+w(u,v)
```

Alla creazione del nostro grafo tutti i valori del nostro array $d$ vengono inizializzati a $+\infty$. 

###### Proprietà dei cammini minimi
1. *Disuguaglianza triangolare*
   Per qualsiasi arco $(u, v) \in E$, si ha $\delta(s, v) \le \delta(s, u) + w(u, v)$.
2. *Proprietà del limite superiore*
   Per tutti i vertici $v \in V$, si ha sempre $v.d \ge \delta(s, v)$ e, una volta che il limite superiore $v.d$ assume il valore $\delta(s, v)$, esso non cambia più.
3. *Proprietà dell'assenza di un cammino*
   Se non c'è un cammino da $s$ a $v$, allora si ha sempre $v.d = \delta(s, v) = \infty$.
4. *Proprietà della convergenza*
   Se $s \leadsto u \to v$ è un cammino minimo in $G$ per qualche $u, v \in V$ e se $u.d = \delta(s, u)$ in un istante qualsiasi prima del rilassamento dell'arco $(u, v)$, allora $v.d = \delta(s, v)$ in tutti gli istanti successivi.
5. *Proprietà del rilassamento del cammino*
   Se $p = \langle v_0, v_1, \dots, v_k \rangle$ è un cammino minimo da $s = v_0$ a $v_k$ e gli archi di $p$ vengono rilassati nell'ordine $(v_0, v_1), (v_1, v_2), \dots, (v_{k-1}, v_k)$, allora $v_k.d = \delta(s, v_k)$. Questa proprietà è soddisfatta indipendentemente da altri passi di rilassamento effettuati.
6. *Proprietà del sotto grafo dei predecessori*
   Una volta che $v.d = \delta(s, v)$ per ogni $v \in V$, il sotto grafo dei predecessori è un albero di cammini minimi radicato in $s$.

### Single-Source Shortest Path
###### Generic SSSP
Di seguito vediamo il primo algoritmo per la ricerca di un cammino minimo ovvero il *Single-Source Shortest Path* che risolve il primo problema dei cammini minimi. 
```
Generic-SSSP(G,s)
	d = new array(len(V))
	foreach v in V do
		d[v] = +infinito
	d[s] = 0
	while esiste (u, v) in E tale che d[u] + w(u, v) < d[v]:
	    RELAX(u, v)
	return d
```


###### SSSP in un grafo orientato aciclico (DAG)
Rilassando gli archi di un dag (Directed Acyclic Graph) pesato $G = (V,E)$ secondo un ordine topologico dei suoi vertici è possibile calcolare i cammini minimi da una sorgente unica nel tempo $\Theta(V+E)$. L'algoritmo inizia ordinando topologicamente il dag, se esiste un cammino dal vertice $u$ al vertice $v$, allora $u$ precede $v$ nell'ordine topologico. Effettuiamo un passaggio sui vertici secondo l'ordine topologico. Durante l'elaborazione vengono rilassati tutti gli archi che escono dal vertice 

```
DAG-SHORTEST-PATHS(G, w, s)
	U = getTopologicalOrder(G);
	foreach v in U:
	  foreach v in G.Adj[u]
		  RELAX(u, v, w)
```
![[Pasted image 20251227181327.png|500]]
### Algoritmo di Bellam-Ford

###### Definizione
Questo algoritmo si basa su un cavillo logico molto semplice, visto che non so quali archi rilassare li rilasso sempre tutti. Li rilasso $n-1$ volte dove $n$ è la lunghezza del cammino più lungo (che consiste nel numero di nodi), dopo aver fatto $n-1$ rilassamenti degli archi sono sicuro che anche il cammino più lungo sarà rilassato. Questo algoritmo a differenza di tutti gli altri è in grado di capire se l'output che sta ritornando è valido, aggiungendo infatti un rilassamento ulteriore dopo le $n-1$ passate verifichiamo se il nostro grafo contiene dei cicli negativi.
###### Implementazione

```text
Bellman-Ford(G, s, w)
    // 1. Inizializzazione
    d = new Array(len(V))
    for each v ∈ V do
        d[v] = +∞
        π[v] = NIL
    d[s] = 0

    // 2. Rilassamento iterativo degli archi
    for i ← 1 to |V|-1 do
        for each (u, v) ∈ E do
            relax(u, v, w)

    // 3. Controllo dei cicli di peso negativo
    for each (u, v) ∈ E do
        if (d[v] > d[u] + w(u, v)) then
            return false

    return d
```
La parte iniziale viene utilizzata per inizializzare gli array $d$ e $\pi$ che rappresentano:
- $d[v]$ rappresenta la distanza di $v$ da $s$
- $\pi[v]$ è il nodo padre di $v$ nell'albero dei cammini minimi 

Il punto tre verifica la validità del risultato, stiamo controllando se si possono effettuare altri relax, se questo succede vuol dire che il nostro grafo contiene dei cicli negativi, e quindi la ricerca di un cammino minimo non può esistere
###### Esempio
Di seguito un esempio di come dovremmo implementare questo algoritmo in sede di esame
![[Screenshot_20260110_103629_Samsung capture.jpg|500]]
###### Complessità
La complessità di questo algoritmo cambia in base al tipo di implementazione utilizzata per rappresentare i grafi:
- *Lista di adiacenza*: $O(VE)$
- *Matrice di adiacenza*: $O(V^3)$


### Algoritmo di Dijkstra

###### Definizione
Per poter funzionare questo algoritmo ha bisogno che tutti i pesi nel grafo siano positivi. Questo algoritmo si basa sull'idea che se troviamo un nodo convergente (quindi completamente rilassato) possiamo rilassare i tutti i suoi archi uscenti. Dati due insiemi:
- *insieme dei nodi in convergenza*
- *insieme dei nodi non in convergenza*
Un nodo convergente sarà sicuramente il nodo con il valore più piccolo nell'insieme dei nodi non in convergenza questo poiché tutti i pesi degli archi sono positivi (o nulli), non esiste alcun cammino alternativo che, passando per altri nodi non ancora visitati, possa "tornare indietro" e ridurre ulteriormente la distanza di quel nodo specifico.
###### Implementazione
```
Dijkstra(G, s, w)
    d = new Array(len(V))
    for each v ∈ V do
        d[v] = +∞
        π[v] = NIL
    d[s] = 0

    Q ← build-min-heap(V)
    
    while Q ≠ ∅ do
        v ← extract-min(Q)
        foreach u ∈ ADJ(v)
            if d[u] > d[v] + w(v, u) then
                decrease-key(Q, u, d[v] + w(v, u))
```
La parte iniziale viene utilizzata per inizializzare gli array $d$ e $\pi$ che rappresentano:
- $d[v]$ rappresenta la distanza di $v$ da $s$
- $\pi[v]$ è il nodo padre di $v$ nell'albero dei cammini minimi 
Quello che fa il resto del algoritmo consiste nel creare un min-heap rispetto al valore che hanno i nodi in $d$ e poi rilassare tutti gli archi uscenti dai minimi della coda fino a quando la coda non è vuota
###### Esempio
Di seguito un esempio di come dovremmo implementare questo algoritmo in sede di esame
![[Pasted image 20260110111329.png|500]]

###### Complessità
Questa analisi deve essere divisa in varie sezioni:
- *Inizializzazione*: scorre tutti i nodi quindi ha un costo pari a: $O(V)$
- *Costruzione min-heap*: la costruzione del min-heap è lineare al numero di elementi quindi nel nostro caso avremo un costo pari a: $O(V)$
- *While principale*: la funzione extractMin di un min-heap come è noto impiega tempo $O(\log n)$ nel nostro caso viene eseguita $V$ volte, quindi si avrà un costo pari a: $O(V \times \log V)$ 
- *Foreach interno*: la funzione decreaseKey di un min-heap come è noto impiega tempo $O(\log n)$, viene richiamata ogni volta che troviamo un cammino più breve, quindi nel caso peggiore avviene per tutti gli archi quindi si avrà un costo pari a: $O(E \times \log V)$
Quindi il costo complessivo di questo algoritmo sarà:
$$O((V \times \log V) + (E \times \log V)) \rightarrow O((V+E)\times \log V)$$

### Conclusioni sul problema dei cammini minimi da una sorgente
###### Conclusioni
Per la risoluzione di questo problema abbiamo presentato tre algoritmi:
- Single-Source Shortest Path
- Bellam-Ford
- Dijkstra
Sia SSSP che Dijkstra hanno delle condizioni sul grafo per poter funzionare, questo li porta ad avere una complessità migliore rispetto a Bellam-Ford che resta però il più generalista.