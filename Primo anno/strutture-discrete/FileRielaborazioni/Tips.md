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