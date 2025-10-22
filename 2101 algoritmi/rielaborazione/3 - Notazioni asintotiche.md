# Le Notazioni Asintotiche e l’Analisi della Complessità degli Algoritmi

###### Concetti preliminari di analisi asintotica
Quando si analizza l'efficienza di un algoritmo, non ci si limita a misurare il tempo effettivo di esecuzione sul computer, poiché tale misura dipende da fattori cangianti da macchina a macchina, quello che si punta a fare è descrivere in modo astratto e generale il comportamento dell'algoritmo, indipendentemente dal contesto. In particolare si studia come il **tempo di esecuzione** cresce al crescere della dimensione dell'input $n$. 
- $T(n)$ rappresenta la **funzione di costo dell'algoritmo**. 
Un algoritmo è fatto di vari passi, un **passo** può essere considerato come un'operazione di base che richiede un tempo costante.

Diremo che due algoritmi sono più o meno efficienti a seconda di come cresce la loro funzione $T(n)$: **un algoritmo la cui funzione di costo cresce più lentamente sarà, per input sufficientemente grandi, più efficiente di uno con crescita più rapida**. 

Dalla necessità di classificare i vari algoritmi nascono le **notazioni asintotiche**, che ci permettono per l'appunto di rappresentare questa idea di crescita trascurando i dettagli che non influiscono sul comportamento generale dell'algoritmo. 


###### Confronto tra le principali funzioni di crescita
Alcune funzioni crescono lentamente, altre molto rapidamente. Immaginiamo di avere diversi algoritmi che risolvono lo stesso problema, ma con funzioni di costo differente: uno è proporzionale a $a \log n$, un altro a $n$, un altro ancora a $n^2$. Per valori piccoli di $n$ le differenze possono sembrare trascurabili, ma per input abbastanza grandi la situazione cambia, ad esempio con $n=1000$: $$\log_2 n ≈ 10,\ n = 1000,\ n^2 = 10^6, \ 2^n ≈ 10^{301}$$
In generale abbiamo diversi tipi di crescita:
1. **Funzioni costanti** $T(n) = 1$ rappresentano algoritmi che impiegano sempre lo stesso numero di operazioni indipendentemente da $n$
	- Accesso ad un elemento di un array
2. **Funzioni logaritmiche** $T(n) = \log n$ descrivono algoritmi che riducono il problema di un fattore costante a ogni passo
	- Ricerca binaria
3. **Funzioni lineari** $T(n) = n$ corrispondono ad algoritmi che analizzano tutti gli elementi dell'input una sola volta
	- Scansione di un array
4. **Funzioni linearitmiche** $T(n) = n \log n$ caratterizzano algoritmi efficienti di ordinamento 
	- Merge sort e Heap sort
5. **Funzioni polinomiali** $T(n) = n^k$ includono molti algoritmi praticabili ma diventano rapidamente onerose per $k>2$
	- Bubble sort
6. **Funzioni esponenziali e fattoriali**: descrivono problemi di natura combinatoria per i quali il numero di soluzioni cresce esplosivamente con $n$
	- Calcolo di tutte le permutazioni
Sono elencate in ordine di crescita crescente: una funzione situata più in basso cresce più rapidamente di tutte quelle sopra di essa

###### Termini e fattori dominanti e trascurabili
Quando si analizza il tempo di esecuzione di un algoritmo la funzione di costo $T(n)$ può contenere più termini, si chiama termine dominante quello che determina l'andamento complessivo della funzione per valori grandi di $n$, quando abbiamo più termini quello che dobbiamo fare è:
- Eliminare i termini di ordine inferiore, cioè quelli che crescono più lentamente
- Si ignorano i fattori costanti che moltiplicano i termini
- Si conserva solo il termine che domina
Di seguito degli esempi:
1. $T(n) = 3n^2 + 5n + 10$ in questa funzione domina il $3n^2$ ed essendo $3$ un coefficiente moltiplicativo questo è trascurabile quindi possiamo dire che questo algoritmo viene descritto da $n^2$
2. $T (n) = n \log n + 100n$ qui il termine che cresce più velocemente è $n \log n$