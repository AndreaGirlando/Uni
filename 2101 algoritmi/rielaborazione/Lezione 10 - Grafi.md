# Grafi

Lezione 16
Lezione 17
Lezione 18
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
La Breadth-First-Search ovvero ricerca in ampiezza è una algoritmo di ricerca nei grafi. Dato un grafo $G = (V,E)$ e un vertice distinto $s$ detto *sorgente*, la visita in ampiezza ispeziona sistematicamente gli archi di $G$ per "scoprire" tutti i vertici che sono raggiungibili da $s$. Genera anche un albero detto breadth-first tree, il cammino che va da $s$ ad un generico $v$ nell'albero corrisponde al *cammino minimo* da $s$ a $v$
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


### DFS
### Ricerca dei cammini minimi