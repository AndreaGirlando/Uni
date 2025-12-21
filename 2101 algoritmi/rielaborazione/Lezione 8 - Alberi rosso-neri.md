# Alberi rosso-neri

### Alberi bilanciati
Lavorando con gli alberi ci capita di incappare in alberi sbilanciati, nel peggiore dei casi questi sono praticamente delle liste, dalla necessità di rendere l'albero autobilanciante nascono gli alberi rosso-neri

###### Definizione di albero bilanciato
Definiamo albero bilanciato quell'albero che ha entrambi i sottoalberi con una quantità di lavoro asintoticamente uguale. Dato questo albero: ![[Pasted image 20251221095203.png|500]]possiamo dire che: $$|h'-h''| \le 2$$
###### Ripasso proprietà del BST
Un albero binario di ricerca è costituito esclusivamente da nodi che rispettano la seguente proprietà: 
- ogni nodo è maggiore o uguale a tutti i nodi del proprio sottoalbero sinistro
- ogni nodo è minore o uguale a tutti i nodi del proprio sottoalbero destro

**Algoritmo di inserimento**: inizia confrontando il valore da inserire con la radice, vado a sinistra o a destra in base alle proprietà di prima, ripeto questo passaggio fino a quando non trovo un posto libero.  

### Proprietà di una albero rosso-nero
###### Proprietà di un albero rosso-nero 
Un albero rosso-nero è *bilanciato* questo è possibile grazie a queste regole:
1. Ogni nodo è *rosso o nero*
2. La radice è *nera*
3. le foglie sono *nere*
	- Questa proprietà può anche non essere rispettata se consideriamo foglie gli ultimi nodi dell'albero quelli NIL (l'altezza aumenta di $1$ e la dimensione diventa $2n$)
4. I figli di un nodo *rosso* sono *neri*
   ![[Pasted image 20251221100753.png|500]]
5. Per ogni nodo, tutti i cammini che vanno dal nodo alle foglie discendenti contengono lo stesso numero di nodi neri
   ![[Pasted image 20251221100824.png]]
Ogni nodo dell'albero è formato da: 
- *color*: il colore del nodo
- *key*: valore del nodo
- *left*: puntatore al figlio sinistro
- *right*: puntatore al figlio destro
- *p*: puntatore al padre
Se manca un figlio o un padre di un nodo il suo valore sarà *NIL*, i nodi NIL sono considerati come nodi neri

Esistono diversi modi per colorare un albero, basta che le proprietà vengano rispettate

###### Rappresentazione di un albero rosso-nero
La rappresentazione di un albero rosso nero viene fatta in questo modo:
1. Si decide di creare un nodo NIL ogni volta che è necessario
2. Tutti i NIL si fanno corrispondere ad un singolo nodo detto *sentinella NIL*
![[Pasted image 20251221095814.png|500]]
Il secondo approccio rispetto al primo risparmia della memoria ma è graficamente meno intuitivo. 

###### Definizione altezza nera lemma altezza massima

**Definizione altezza nera:** definiamo *altezza nera* di un nodo $x$, indicata con $bh(x)$ il numero di nodi neri lungo un cammino semplice che inizia dal nodo $x$ (ma non lo include) e finisce in un foglia. L'altezza nera di un albero è $hb(root)$. 

**Definizione altezza massima**: l'altezza massima di un albero rosso-nero con $n$ nodi interni è $2 \log_2(n+1)$

***Dimostrazione:*** Iniziamo dimostrando che il sottoalbero con radice in un nodo $x$ qualsiasi contiene almeno $2^{bh(x)}-1$ nodi interni, lo faremo per induzione:
- *caso base*: Se l'altezza di $x$ è $0$ allora $x$ deve essere una foglia e il sottoalbero con radice in $x$ contiene: $2^0 - 1 = 1-1 = 0$
- *passo induttivo*: consideriamo un nodo $x$ che ha un altezza positiva ed è quindi un nodo interno con due figli. 
  Possiamo dire che ogni figlio ha un altezza nera pari a:
	- se rosso ha $bh(x)$
	- se nero ha $bh(x)-1$ (perché escludo il nodo stesso dal conteggio)
  Poiché l'altezza di un figlio di $x$ è minore dell'altezza di $x$ possiamo applicare l'ipotesi induttiva per concludere che ogni figlio ha almeno $$2^{bh(x)-1}-1 \text{ nodi interni }$$e quindi possiamo concludere che il sottoalbero con radice in $x$ contiene: $$
\underbrace{(2^{bh(x)-1}-1)}_{\text{nodi interni albero sx}} + \underbrace{(2^{bh(x)-1}-1)}_{\text{nodi interni albero dx}} + 1 = 2^{bh(x)} - 1 \;\text{nodi interni}
$$il che dimostra l'asserzione iniziale. 

Per completare la dimostrazione indichiamo con $h$ l'altezza dell'albero, sappiamo che almeno metà dei nodi in qualsiasi cammino semplice della radice ad una foglia deve essere nera, di conseguenza l'altezza nera della radice è $h/2$ (perché lungo il cammino i nodi si alternano rosso/nero) quindi abbiamo che: $$n \ge 2^{h/2}-1$$dove $n$ è il numero di nodi interni del nostro albero. Spostando $1$ nel lato sinistro e prendendo i logaritmi di entrambi i lati otteniamo: $$log_2(n+1) \ge h/2 \; \text{ ovvero } \; h \le 2\log_2(n+1)$$
### Operazioni negli alberi rosso-neri: rotazioni

###### Definizione
Le operazioni di inserimento e eliminazione di un nodo modificano l'albero,  questo di conseguenza potrebbe violare le proprietà discusse prima, per rispristinarle facciamo uso delle rotazioni che ci permettono attraverso la modifica dei colori e della struttura dei puntatori di sistemare l'albero. ![[Pasted image 20251221110620.png|500]]
**Rotazione a sinistra**: la rotazione a sinistra si basa sul collegamento tra $x$ e $y$: 
- il nodo $y$ diventa la nuova radice
- $x$ come figlio sinistro di $y$
- il figlio sinistro di $y$ diventa il figlio destro di $x$

```
LEFT-ROTATE(T,x)
	y = x.right // Imposta y
	x.right = y.left // Sposta il sottoalbero sx di y nel sottoalbero dx di x
	if y.left != T.NIL
		y.left.p = x
	y.p = x.p // Collega il padre di x a y
	
	if x.p == T.NIL
		T.root = y
	elseif x == x.p.left
		x.p.left = y
	else x.p.right = y
		y.left = x // Pone x a sinistra di y
		x.p = y
```

**Rotazione a destra**: la rotazione a destra si basa sul collegamento tra $x$ e il suo figlio sinistro:
- $x$ diventa la nuova radice
- $y$ come figlio destro di $x$
- il figlio destro di $x$ diventa il figlio sinistro di $y$


> [!TIP]
> Quando applichiamo una rotazione su un albero i nodi che si invertono di posizione dovranno scambiare la propria colorazione


###### Esempi
![[Pasted image 20251221114952.png|500]]
![[Pasted image 20251221115209.png|500]]

### Operazioni negli alberi rosso-neri: inserimento
###### Definizione
Non esiste un modo per implementare l'inserimento che data una qualsiasi configurazione di un albero rosso-nero riesco ad inserire un nuovo nodo senza violare le proprietà fondamentali. Avremo quindi:
1. Creazione del nuovo nodo rosso
2. Inserimento analogo ai BST
3. Chiamata a funzione RB-Insert-Fixup sul nuovo nodo

```
RB-INSERT(T, z)
	y = T.nil              // Inizializza y a NIL
	x = T.root             // Inizia la ricerca dalla radice dell'albero T
	
	while x ≠ T.nil        // Scendi nell'albero finché non trovi una foglia (nil)
	    y = x              // Tieni traccia dell'ultimo nodo non nullo visitato
	    if z.key < x.key   // Se la chiave da inserire è minore della corrente...
	        x = x.left     // ...vai a sinistra
	    else               // Altrimenti...
	        x = x.right    // ...vai a destra
	        
	z.p = y                // Imposta y come padre del nuovo nodo z
	if y == T.nil          // Se l'albero era vuoto...
	    T.root = z         // ...il nuovo nodo diventa la radice
	elseif z.key < y.key   // Altrimenti, se z è minore del padre...
	    y.left = z         // ...diventa il figlio sinistro
	else                   // Se z è maggiore o uguale...
	    y.right = z        // ...diventa il figlio destro
	    
	z.left = T.nil         // Inizializza il figlio sinistro a NIL
	z.right = T.nil        // Inizializza il figlio destro a NIL
	z.color = RED          // Colora il nuovo nodo di ROSSO
	RB-INSERT-FIXUP(T, z)  // Ripristina le proprietà dell'albero Red-Black
```

l'inserimento è praticamente identico a quello di un BST normale, abbiamo solo che il nodo viene colorato di rosso e che viene chiamata insert-fixup che si occupa di sistemare e rendere valido il nostro albero come rosso-nero
###### Definizione di insert-fixup
Questa funzione si basa sulla definizione di 3 casi, supponendo che **z** sia il nuovo nodo rosso inserito abbiamo:
**Caso 1:** lo zio $y$ di $z$ è rosso
![[Pasted image 20251221150446.png|500]]La colorazione del nonno di $z$ viene messa ad entrambi i figli, e richiamiamo insert-fixup sul nonno, per correggere possibili violazioni nel resto dell'albero

**Caso 2**: questo caso è definito su due condizioni
- lo zio $y$ di $z$ è nero
- $z$ è interno
![[Pasted image 20251221150916.png|500]]
Ruotiamo il padre di $z$ in modo tale da mettere $z$ nella posizione del padre, ci saremo ricondotti al caso 3 e richiamiamo la procedura sulla nuova $z$

**Caso 3**: questo caso è definito su due condizioni
- lo zio $y$ di $z$ è nero
- $z$ è esterno
![[Pasted image 20251221151352.png|500]]Ruotiamo il padre di $z$  con il nonno in maniera tale da metterlo al posto del nonno

###### Esempio
![[Screenshot_20251221_162142_Samsung capture.jpg|700]]

### Operazioni negli alberi rosso-neri: eliminazione
