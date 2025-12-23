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
### Ricerca dei cammini minimi
Lezione 18