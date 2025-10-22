# Le Notazioni Asintotiche e l’Analisi della Complessità degli Algoritmi

### Concetti preliminari di analisi asintotica
###### Confronto tra le principali funzioni di crescita
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

### Le notazioni asintotiche
Con il termine **asintotico** indichiamo il comportamento di una funzione quando la variabile indipendente cresce senza limiti, quindi possiamo dire che:

*Una notazione asintotica è un modo sintetico per descrivere il modo in cui una funzione cresce rispetto a un'altra. Essa non ci dice quanto vale esattamente una funzione, ma quanto rapidamente aumenta rispetto ad altre funzioni al crescere di n*

**Esempio**: dire che $T(n)$ è "dell'ordine $n^2$ " significa che per input molto grandi il numero di operazioni richieste dall'algoritmo cresce in modo proporzionale a $n^2$ 

In generale le notazioni asintotiche forniscono un linguaggio per esprimere relazioni del tipo:
- $f(n)$ cresce non più rapidamente / alla stessa velocità / più rapidamente di $g(n)$
Esse si basano quindi sul confronto tra le due funzione nel limite per $n \rightarrow \infty$ cioè osservando il loro comportamento quando la dimensione diventa molto grande 

**Esempio**: date queste due funzioni: $$f(n) = 3n^2 + 5n +7, \ g(n) = n^2$$ la differenza può sembrare significativa, ma man mano che $n$ cresce il termine $3n^2$ diventa dominante, quindi possiamo affermare che $f(n)$ e $g(n)$ hanno la stessa crescita asintotica

###### La notazione Θ (theta)
La notazione $\theta$ fornisce un **vincolo asintotico stretto** ovvero *rappresenta l'insieme di tutte le funzioni che crescono alla stessa velocità di una funzione di riferimento g(n)*. Formalmente scriviamo che: $$\theta(g(n)) = \{ f(n) | \exists c_1,c_2, n_0 > 0 \text{ tali che } 0 \le c_1g(n) \le f(n) \le c_2g(n), \forall n \ge n_0 \}$$In altre parole, a partire da una certa soglia $n_0$ la funzione $f(n)$ è sempre compresa tra due multipli costanti della funzione di riferimento $g(n)$.
Praticamente la notazione $\theta$ descrive una crescita bilanciata: $f(n)$ cresce in modo simile a $g(n)$ differendo al più per un fattore costante. Questo significa che per input di $n$ molto grandi possiamo dire che: $$\frac{f(n)}{g(n)} \rightarrow k \text{ con } 0<k<\infty $$
![[Pasted image 20251022150331.png|500]]
da questa immagine capiamo subito il significato della definizione formale infatti dopo un certo $n$ (in questo caso $n=7$) la nostra funzione resta confinata nella fascia delimitata dalla linea tratteggiata

**Esempi**:
- $5n + 20 = \theta(n)$ perché la costante additiva non influisce sul comportamento
- $\frac{1}{2}n^3 + 100 = \theta(n^3)$

La notazione $\theta$ è la più informativa poiché fornisce sia un limite superiore sia uno inferiore, se $f(n) = \theta(g(n))$ allora $f(n)$ è simultaneamente:
- $O(g(n))$
- $\Omega(g(n))$
Capiremo successivamente il perché

###### La notazione O (Big-Oh)
La notazione $O$ rappresenta un **limite superiore asintotico** ovvero descrive *funzioni che per n sufficientemente grandi non crescono più rapidamente di una funzione di riferimento g(n)*, formalmente si definisce come:
$$O(g(n)) = \{ f(n) | \exists c > 0, n_0 > 0 \text{ tali che } 0 \le f(n) \le cg(n), \forall n \ge n_0\}$$direi che $f(n) = O(g(n))$ significa che, a partire da una cerca soglia $n_0$ il valore di $f(n)$ non supera mai quello di $c g(n)$   

Praticamente la notazione $O$ serve per stabilire una stima superiore del comportamento asintotico infatti garantisce che $f(n)$ non crescerà mai più velocemente di $g(n)$ per $n$ grandi

![[Pasted image 20251022153246.png|500]]
Attraverso questa immagine riusciamo subito a capire la definizione formale, infatti dopo una $n$ la funzione $f(n)$ non cresce più velocemente di $g(n)$
 
**Esempi:** 
- $7n + 200 = O(n)$
- $\log n = O(n)$
- $n = O(n^2)$

la notazione $O$ indica solo un **limite superiore** se diciamo che $T(n) = O(n^2)$ stiamo affermando che l'algoritmo non richiede mai più di un tempo proporzionale a $n^2$ ma potrebbe essere anche più efficiente. Di solito questa notazione viene usata per descrivere il **caso peggiore**


###### La notazione Ω (Big-Omega)
La notazione $\Omega$ rappresenta un **limite inferiore asintotico** ovvero descrive funzioni *che per n sufficientemente grande crescono almeno tanto rapidamente quanto una funzione di riferimento g(n)* formalmente si definisce come:
$$\Omega(g(n)) = \{f(n) | \exists c > 0, n_0 > 0 \text{ tali che } 0\le cg(n) \le f(n), \forall n \ge n_0 \}$$
Ciò significa che a partire da un certo punto $n_0$ il valore di $f(n)$ è sempre maggiore o uguale a una constante moltiplicativa di $g(n)$ 

Praticamente la notazione $\Omega$ descrive una crescita minima garantita, infatti oltre una scelta soglia la funzione $f(n)$ rimane sempre al di sopra della funzione di riferimento

![[Pasted image 20251022155042.png|500]]
Attraverso questa immagine è abbastanza intuitiva la definizione formale, oltre una certa $n$ la nostra funzione $f(n)$ rimane sempre al di sopra della curva $cg(n)$

La notazione $\Omega$ indica un **limite inferiore** e appunto per questo viene utilizzata per descrivere il **caso migliore** 

**Esempi**:
- $5n+200 = \Omega(n)$
- $n^3 = \Omega(n^2)$

###### Le notazioni o e ω (piccole)