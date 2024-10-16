Gli algoritmi possono essere rappresentati attraverso un diagramma a blocchi o attraverso del pseudocodice. Di seguito un algoritmo rappresentato in un diagramma a blocchi
![[Pasted image 20241010142803.png]]
Questo algoritmo scambia il contenuto di 2 variabili. Vengono usati diversi tipi di blocchi:
- Blocco di inizio e di fine dentro un'ellisse
- I blocchi usate per le azioni di input/output in un parallelepipedo
- I blocchi usati per le operazioni dentro blocchi quadrati
![[Pasted image 20241010143334.png]]
Di seguito la rappresentazione in pseudocodice
`INIZIO` 
`Leggi X` 
`Leggi Y` 
`IF X < Y THEN`
	`Stampa Y` 
`ELSE` 
	`Stampa X` 
`END IF` 
`FINE`

In questo diagramma a blocchi abbiamo un nuovo tipo di blocco: il blocco condizionale che in questo caso viene usato per verificare se X < Y questa operazione avrà come risultato un booleano che potrà avere valore vero o falso. Questo valore determina la direzione che verrà presa dal blocco condizionale. Esistono vari operatori relazioni che vengono utilizzati per creare delle condizioni più complesse:
- = o ≠
- < o <=
- > o >=
Di seguito un'algoritmo che calcola il fattoriale di un numero sempre scritto in un diagramma a blocchi:
![[Pasted image 20241010145028.png]]
Qui viene introdotto un nuovo blocco: il blocco di loop (quello arancione) fino a quando quella condizione sarà falsa il ciclo andrà avanti. Di seguito lo stesso algoritmo scritto in pseudocodice
`INIZIO` 
	`Leggi N` 
	`F <- 1` 
	`M <- 1` 
	`while (M > N)` 
		`F <- F * M` 
		`M <- M + 1` 
	`Stampa F` 
`FINE`
