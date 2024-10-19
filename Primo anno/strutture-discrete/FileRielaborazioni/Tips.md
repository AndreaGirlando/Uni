###### Come creare tutte le combinazioni tra le variabili senza confondersi
![[Pasted image 20241009133640.png]]
Numero variabili da rappresentare: 4 (P,Q,R,S)
Numero casi possibili: nCasi = $2^4$ = $16$
Per la prima variabile:
- scrivi 8 volte V e 8 volte F
Per la seconda variabile scrivi: 
- 4 volte V -  4 volte F - 4 volte V - 4 volte F
Per la terza variabile scrivi: 
- 2 volte V -  2 volte F - 2volte V - 2 volte F - 2 volte V -  2 volte F - 2 volte V - 2 volte F
Per la quarta variabile scrivi: 
- VERO - FALSO - VERO - FALSO … fino a quando non arrivi a nCasi 

Se hai una tabella con 6 variabili sono 64 casi e la prima variabile sarà 32 volte vero e 32 volte falso, ogni volta che cambi variabile dividi per 2 i casi veri e quelli falsi



##### Come distribuire le congiunzioni sulle disgiunzioni e viceversa
Formula iniziale: $p ∧ (q ∨ r )$

1. Riscrivo la variabile e l'operatore logico che sono fuori dalla parentesi e tra le 2 (2 sono il numero di variabili dentro la parentesi) parantesi che avrò metto l'operatore logico che c'è dentro la parentesi.
	- ($p ∧ ...$) ∨ ($p∧...$)
2. Metto al posto dei puntini le variabili che ho dentro la parentesi, non è importante l'ordine
	-  ($p ∧ q$) ∨ ($p∧r$)

Formula finale: ($p ∧ q$) ∨ ($p∧r$)

##### Come calcolare la chiusura di una famiglia rispetto ad unione/intersezione
$F$  = {1, 2, … , m}
$\mathcal{F}_U$ = ??? famiglia più piccola che contiene $F$ ed è chiusa rispetto all'unione
1. Costruiamo la famiglia $F^1$ mettendoci tutti gli elementi di $F$.
2. Per ogni i (partendo da 2) sino a m calcoliamo $F_i$ utilizzando tutte le coppie di elementi $X$ , $Y$ con $X ∈ F$ e $Y ∈ \mathcal{F}_{i-1}$ e mettendo $X ∪ Y$ in $F_i$ .
3. Poniamo infine $\mathcal{F}_U = \bigcup_{i=1}^{m} \mathcal{F}_i$ 