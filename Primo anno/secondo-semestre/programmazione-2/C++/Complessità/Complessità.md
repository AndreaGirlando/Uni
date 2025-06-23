La complessità computazione serve per stabilire il **costo di un algoritmo** in termini di numero di operazioni fatte in RAM e dalla memoria occupata durante la sua esecuzione. Quando andiamo parliamo di costo computazionale prendiamo in esame 
- **il caso peggiore**: ovvero il costo massimo tra tutti i possibili input
- **il caso medio**: costo mediato tra tutte le istanze di input
è importante per definire un costo totale di un algoritmo definire il costo unitario di ogni singola operazione, in questo modo contando le operazioni si riesce a definire il costo totale, inoltre è necessario definire il comportamento dell'algoritmo in caso di dimensioni dell'input che tendono ad infinito e questo lo facciamo attraverso la notazione asintotica. Le notazioni principali sono:
- **Grande O**: denotiamo con O(g(n)) l'insieme delle funzioni
  $O(g(n)) = \{f(n:$ esistono delle constanti positive $c, n_0$ tale che $0 \le f(n) \le c \times g(n)$ per ogni $n > n_o$
  usando questa notazione facciamo riferimento ai casi peggiori ovvero ad un limite superiore per $f(n)$. Esistono diverse classe di equivalenza in cui i vari algoritmi in base alla loro complessità vengono raggruppate, le classi sono: 
	- **Costante**: 1
	- **Sotto-lineare**: $\log n, n^c$
	- **Lineare**: $n$
	- **Polinomiale**: $n \times \log n,n^2, ecc..$
	- **Esponenziale**: $c^n, \dots n^n,...$ (quello peggiore) 
- **Grande Beta**: 
- **Grande Theta**: 

---
### Rielaborazione
Esistono due tipi di complessità:
- complessità temporale
- complessità spaziale
di seguito parleremo solo di complessità temporale:
la complessità di un'algoritmo varia in base a quello che quel algoritmo fa:
- **O(1)**: complessità constante
- **O(n)**: complessità di un ciclo quando le sue variabili sono incrementate/decrementate si una quantità costante.
- **O(n^c)**: c è il numero di cicli annidati in cui le variabili contatore sono incrementate/decrementate di una quantità constante
- **O(log n)**: complessità di un ciclo quando le sue variabili sono incrementate/decrementate moltiplicandole o dividendole per una costante.
- **O(log log n)**: complessità di un ciclo quando le sue variabili sono incrementate/decrementate esponenzialmente

###### Notazione asintotica
Le notazioni utilizzate vengono dette asintotiche perché studiano la complessità computazionale al tendere n (numeri di dati in input) all'infinito e sono 3:
- $O$ **Notazione big O**: che definisce il **limite asintotico superiore** ovvero il caso peggiore al tendere di $n$ all'infinito.
- $\Omega$ **Notazione Omega**: che definisce il **limite asintotico inferiore** ovvero il caso migliore al tendere di $n$ all'infinito.
- $\Theta$ **Notazione Theta**: che definisce il **limite asintotico stretto** ovvero una condizione più stringente alla notazione big O infatti per definire questa notazione le notazioni O e Omega devono corrispondere

###### Ricerca lineare
Prendendo in esame la ricerca lineare in un array di $n$ elementi possiamo dire che:
 - **Caso migliore**: $1$ (notazione big O)
 - **Caso peggiore**: $n$ (notazione big Beta)
 - **Caso medio**: ?
Per riuscire a calcolare il caso medio abbiamo bisogno della funzione $Prob(i)$ che ritorna la probabilità che uno specifico elemento si trovi nella posizione $i$ passata, se ogni elemento è equiprobabile, allora la funzione diventa: $Prob(i) = \frac{1}{N}$, e quindi per il calcolo del [[Strutture#^09a8d0|valore atteso]]:$$\sum_{i=1}^{N} \left(\frac{1}{N} \cdot i\right) = $$
ovvero:
$$=\frac{1}{N} \cdot \sum_{i=1}^{N} i \text{ e quindi } \frac{1}{N} \cdot \frac{N(N+1)}{2}$$
da questo deduciamo che il caso medio é:
$$\text{caso medio} = \frac{N+1}{2}$$
![[Pasted image 20250623152650.png]]
