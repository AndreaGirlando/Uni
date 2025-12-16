## Lezione 1 - Ricorsione

# Concetto di ricorsione

###### La ricorsione
La **ricorsione** rappresenta uno dei concetti più eleganti e profondi della programmazione. Essa si fonda sull'idea che un problema complesso possa essere affrontato non direttamente nella sua interezza, ma scomponendolo in sotto-problemi più semplici, ciascuno dei quali conserva la stessa natura e struttura del problema originario, ma su scala ridotta.

> [!TIP] Definizione
> Un **programma ricorsivo** è una funzione o una procedura che durante la propria esecuzione richiama se stessa per risolvere versioni sempre più piccole dello stesso problema

Questo meccanismo sembra apparentemente circolare, ma è in realtà estremamente potente a condizione che esista un punto di arresto ben definito: ovvero **la condizione base**

L'idea alla base della ricorsione può essere illustrata con un semplice principio: per risolvere il problema complesso $P$ il programmatore non cerca di affrontarlo direttamente ma lo suddivide in $K$ problemi più piccoli  ($P_1,P_2,\dots,S_K$) che è in grado di risolvere (o si assume che sappia risolvere), ognuno di questi sotto problemi viene risolto, le soluzioni ottenute vengono combinate per ottenere la soluzione complessiva $S$

Un esempio classico di questo meccanismo è il calcolo del fattoriale di un numero intero non negativo $n$
![[Pasted image 20251012172214.png|500]]
in breve si afferma che per calcolare $n!$ non è necessario conoscere direttamente il risultato ma basta sapere come calcolare il fattoriale di un numero più piccolo $n-1$, questa definizione *auto-riferita* è perfettamente lecita e diventa computazionalmente potente perché il caso base (quello sopra) interrompe la catena di richiami e garantisce la terminazione (cosa molto importante in un programma)

###### Fasi della ricorsione
La chiave del pensiero ricorsivo risiede nella riduzione del problema invece di cercare una soluzione diretta e immediata, osservando questa prospettiva emergono due aspetti fondamentali:
- **Suddivisione**: del problema in sotto problemi di minore complessità
- **Ricombinazione**: dei risultati parziali nella soluzione complessiva
Questa duplice operazione è ciò che rende la ricorsione tanto elegante quanto potente infatti permette di passare da una visione monolitica del calcolo a una visione **gerarchica e modulare** 

###### La ricorsione come forma di arte
Nel mondo informatico e in particolare nella cultura degli hacker e dei programmatori più esperti si ha una senso di soddisfazione estetica quando si riesce a trovare una soluzione ricorsiva che pur essendo breve riesca a risolvere il problema

###### Definizioni ricorsive delle strutture dati
La ricorsione non riguarda solo gli algoritmi o le funzioni ma anche le **strutture dati**, di seguito degli esempi:
- **Lista**: non è altro che un *elemento iniziale* seguito da un'altra lista dello stesso tipo ![[Pasted image 20251012173553.png|500]]
-  **Array**: un array di lunghezza $n$ può essere definito come un elemento iniziale seguito da un array di lunghezza $n-1$: $$A_n = \{a_0\} \cup A_{n-1}$$
- **Alberi**: ogni nodo dell'albero può essere considerato come la radice di un nuovo albero, composto dai suoi sottoalberi![[Pasted image 20251012174314.png|500]]
Questo non è solo un dettaglio tecnico, ma un riflesso profondo della natura gerarchica di molte strutture logiche e computazionali, per queste ragioni la ricorsione non è soltanto un modo per **operare** sulle strutture dati, ma anche un modo per definirle, quando questo accade, la sua manipolazione di ricorsiva risulta non solo naturale, ma anche concettualmente più chiara e formalmente elegante.

###### Struttura generale di un programma ricorsivo
Ogni programma ricorsivo si fonda su una struttura concettuale ben precisa, che ne garantisce la correttezza logica e la terminazione formata da:
1. **Il caso base**: il caso base è una condizione che ne interrompe la prosecuzione infinita di una ricorsione, matematicamente corrisponde alla condizione di terminazione dell'equazione definita ricorsivamente
2. **Il passo ricorsivo**: In questo punto la funzione richiama sé stessa per risolvere uno o più sotto problemi di dimensione minore, se indichiamo con $P$ il problema principale e con $P_1,P_2, \dots, P_K$ i sotto problemi derivati, il passo ricorsivo può essere espresso formalmente come: $$S = \text{Combina}(F(P_1), F(P_2), \dots, F(P_K))$$
3. **La combinazione dei risultati**: Una volta risolti i sotto problemi occorre un meccanismo per ricomporre le soluzioni parziali e ottenere la soluzione complessiva del problema principale. Questo processo detto fase di combinazione è spesso ciò che distingue una ricorsione semplice da una più sofisticata

Una funzione ricorsiva $F(n)$ può essere definita in modo generale nel seguente modo: ![[Pasted image 20251012180931.png|500]]
Dal punto di vista operativo l'esecuzione di un programma ricorsivo può essere immaginata come una serie di scatole annidate ogni funzione apre un nuovo livello di esecuzione, questa dinamica viene gestita in modo automatico dallo **stack** che conserva lo stato di ciascuna chiamata, ogni nuova chiamata viene accodata in cima alla pila. 

In una funzione ricorsiva ben progettata la profondità della ricorsione deve sempre essere finita infatti in caso contrario si potrebbe incappare in problemi di **stack overflow** (troppe chiamate nello stack)

###### Dimensione del problema
Un aspetto cruciale nella progettazione di un algoritmo ricorsivo riguarda la definizione della **dimensione del problema**, spesso indicata con la variabile $n$, in alcuni casi questa grandezza è intuitiva, per esempio nel calcolo del fattoriale o della potenza, $n$ coincide con un numero intero che viene progressivamente decrementato fino a raggiungere lo zero. La scelta del parametro che rappresenti la dimensione del problema non è una semplice formalità: essa influisce profondamente sul comportamento dell'algoritmo e sulla sua **complessità computazionale**


###### L'equazione di ricorrenza 
Ogni algoritmo ricorsivo possiede una propria **struttura quantitativa** che descrive come il costo del calcolo cresce in funzione delle dimensione del problema, questa struttura prende il nome di **equazione di ricorrenza**. Un'equazione di ricorrenza esprime il tempo di esecuzione di un algoritmo ricorsivo come funzione del tempo necessario per risolvere uno o più sotto problemi più piccoli più un termine che rappresenta il costo delle operazioni non ricorsive, la funzione del tempo per risolvere un problema di dimensione $n$ viene indicato con $T(n)$ ovvero:
$$T(n) = \Sigma_{i = 0}^{K} T(n_i)+f(n)$$
dove $T(n_i)$ rappresenta il tempo necessario per risolvere il sotto problema i-esimo (di dimensione $n_i<n$) e $f(n)$ rappresenta il tempo impiegato per la fase di divisione e riunificazione (le fasi che non comportano chiamate ricorsive)


###### Costruzione di una equazione di ricorrenza
Per costruire l'equazione di ricorrenza corrispondente a un algoritmo occorre osservare come esso si comporta rispetto alla dimensione del problema. Ogni chiamata ricorsiva può essere vista come un nodo dell'albero di ricorsione e il numero di nodi totali determina il tempo totale.

**Esempi**
- **Fattoriale**:  in questo algoritmo la ricorsione riduce la dimensione del problema di $1$ ad ogni chiamata (per ogni chiamata ricorsiva viene fatta una sola moltiplicazione) quindi la sua equazione di ricorrenza è: $T(n) = T(n-1)+O(1)$ risolvendo questa ricorrenza otteniamo che $T(n) = O(n)$ 
- **Somma di un array**: in un algoritmo che calcola la somma di una array dividendolo in due metà il tempo di esecuzione ha equazione: $$2T(\frac{n}{2})+O(i)$$ poiché ogni chiamata genera due sotto problemi di metà dimensione, è la fase di combinazione richiede solo un tempo costante per sommare i risultati. Risolvendola otteniamo sempre $T(n) = O(n)$ ma con una struttura di chiamate ricorsive estremamente diversa.
- **Merge sort**: in questo algoritmo ogni livello di ricorsione comporta una divisione in due sottoarray ma la fase di riunificazione (il merging) richiede un tempo lineare $O(n)$. L'equazione di ricorrenza corrispondente diventa quindi: $$T(n) = 2T(\frac{n}{2})+O(n) \rightarrow O(n \log n)$$
  Questo risultato è uno dei più noti nell'analisi algoritmica e mostra come la ricorsione possa amplificare o ridurre l'efficienza di un algoritmo.

> [!INFO] Come risolvere queste equazioni
> Come arrivare alle soluzioni delle equazioni di ricorrenza è un problema futuro

Dal punto di vista concettuale, un' equazione di ricorrenza è una **descrizione dinamica** del comportamento di un algoritmo, infatti una delle ragioni per cui lo studio delle equazione di ricorrenza è fondamentale risiede nel loro potere predittivo, ci permettono di capire cosa accade lungo tutto l'algoritmo, essa rivela, per esempio, la crescita del nostro algoritmo (se questa è lineare, logaritmica o esponenziale). Infine un equazione di ricorrenza ci permette di capire quale algoritmo è il "migliore" tra due algoritmi ricorsivi.


# Esempi introduttivi di ricorsione

Per comprendere a fondi il funzionamento della ricorsione, è utile analizzare alcuni analizzare alcuni esempi elementari ma emblematici, mostrano come un problema ricorsivo si risolve sempre creando le due fasi:
- **Fase di divisione**: il problema viene suddiviso in versioni più semplici
- **Fase di riunificazione**: le soluzioni vengono combinate per ottenere la soluzione finale

###### Il fattoriale
Il calcolo del **fattoriale** di un numero intero non negativo $n$ è forse l'esempio più iconico di funzione ricorsiva

> [!ATTENTION] Che cosa è un fattoriale
> Il fattoriale indicato con $n!$ rappresenta il prodotto di tutti i numeri interi positivi minori o uguali ad $n$

La sua definizione sottoforma di funzione ricorsiva è la seguente:![[Pasted image 20251013090946.png|500]]
- **Fase di divisione**: consiste nel ridurre il problema $F(n)$ a un sotto problema di dimensione minore ovvero $F(n-1)$ 
- **Fase di riunificazione**: avviene durante il ritorno delle chiamate: ciascuna moltiplica il valore ottenuto dalla chiamata successiva per il proprio parametro $n$

```
int fattoriale ( int n ) { 
	if ( n == 0) return 1; 
	else return n*fattoriale(n-1)
}
```

Questo è l'albero di ricorsione con $n = 4$![[Pasted image 20251013091533.png]]
###### Moltiplicazione come somma ripetuta
Per due numeri interi non negativi possiamo esprimere il prodotto come:
![[Pasted image 20251013092039.png]]
- **Fase divisione**: riduce il secondo argomento $b$ di una unità ad ogni chiamata, il problema $P(a,b)$ viene trasformato in un sotto problema $P(a,b-1)$ di dimensione più piccola
- **Fase di riunificazione**: consiste nel sommare $a$ al risultato ottenuto dalla chiamata successiva

```
int moltiplica ( int a , int b ) { 
	if ( b == 0) 3 return 0; 
	else return a + moltiplica (a , b - 1);  
}
```

Questo è l'albero di ricorsione di $3 \times 4$  ![[Pasted image 20251013092859.png]]
###### Potenza con moltiplicazione ripetuta
La potenza dati due numeri viene definita così
![[Pasted image 20251013093143.png]]
- **Fase di divisione**: consiste nel ridurre progressivamente l'esponente $n$ fino a raggiungere lo zero
- **Fase di riunificazione**: avviene moltiplicando ogni valore intermedio per $a$ nel momento in cui le chiamate ritornano

```
int potenza ( int a , int n ) { 
	if (n == 0) return 1; 
	else return a * potenza (a , n - 1)
}
```

L'albero di ricorsione per il calcolo di $2^4$ ha la seguente forma: ![[Pasted image 20251013093604.png]]
###### Conclusioni
Questi tre esempi mostrano un principio comune: **la ricorsione separa il processo in due momenti distinti ma complementari**, questa struttura logica è ciò ritroveremo in forma più articolata nei grandi algoritmi


# Problemi di somma e soglia su array

Come abbiamo visto nei punti precedenti gli **array** offrono un contesto ideale per applicare e comprendere la logica ricorsiva, le operazioni definite su un array possono essere descritte ricorsivamente in molti modi diversi, nei prossimi esempi vedremo come la ricorsione può essere utilizzata per risolvere problemi di natura sia quantitativa che logica.


In generale i problemi sugli array posso essere risolti in modo ricorsivo seguendo due schemi generali:
- **Ricorsione in coda**: in cui l'array viene ridotto progressivamente di un elemento alla volta
- **Doppia ricorsione**: in cui l'array viene suddiviso in due sottoarray di dimensioni più piccole che vengono risolti e poi ricombinati
###### Somma dei valori di un array
Supponiamo di avere un array di interi: $$A = [3,7,2,9,4]$$ in questo caso la somma totale degli elementi sarà: $3+7+2+9+4 = 25$ quindi il nostro obbiettivo è quello di scrivere una procedura in grado di restituire per qualsiasi array $A$ di dimensione $n$, il valore:
$$S(A,n) = \Sigma_{i = 0}^{n-1}A[i]$$
Si tratta di un problema apparentemente semplice ma utile per comprendere la differenza tra un approccio **iterativo** e **ricorsivo**:
- **Approccio iterativo**: supponendo di avere un array di $n$ elementi ci basta scorrere l'array da destra verso sinistra e accumulando progressivamente il valore in una variabile che chiameremo **somma**
  ![[Pasted image 20251013161930.png|700]]
- **Approccio ricorsivo**: Invece di accumulare progressivamente i risultati per usare un approccio ricorsivo dobbiamo scomporre il problema in problemi più piccoli, ciò significa nel caso della somma immaginare l'azione di scorrimento iterativo dell'array come una funzione che richiama ste stessa su versioni ridotte dello stesso array, questa cosa si può fare in due modi:  
	1. *Ricorsione di coda* ![[Pasted image 20251013162320.png]]
		- **Fase di divisione**: consiste nel passare da un array di $n$ elementi a uno di $n-1$
		- **Fase di riunificazione**: consiste nel sommare il valore corrente $A[n-1]$ al risultato ottenuto ricorsivamente
		- *Codice*![[Pasted image 20251013162520.png|700]]
		- *Albero di ricorsione*: La complessità dell'albero è $n$ e ogni chiamata ricorsiva genera una sola nuova chiamata quindi la complessità temporale è $O(n)$
	2. *Doppia ricorsione* ![[Pasted image 20251013163348.png]]
		- **Fase di divisione**: suddivide il problema in due sottoproblemi di dimensione $n/2$
		- **Fase di riunificazione**: consiste nel sommare i due risultati parziali
		- *Codice*![[Pasted image 20251013163558.png|700]]
		- *Albero di ricorsione* ![[Pasted image 20251013163705.png]]Questo è un albero bilanciato e completo con profondità $\log_2n$ la complessità temporale complessiva è: $T(n) = 2T(\frac{n}{2})+O(1)$ 	 
 


###### Verificare se la somma supera una soglia
Nel problema che consideriamo ora non vogliamo calcolare il valore della somma, ma soltanto stabilire se la somma degli elementi di un array $A$ supera una certa soglia $T$ come risultato vogliamo un esito logico $\text{true\\false}$, quello che facciamo è facciamo scorrere la soglia $T$ verso il basso man mano che consumiamo l'array: a ogni passo sottraiamo l'ultimo elemento e chiediamo se la somma rimanente super la nuova soglia ![[Pasted image 20251013164534.png]]
- **Fase di divisione**: il problema viene suddiviso in problemi più piccoli con una soglia sempre più bassa
- **Fase di riunificazione**: il valore dell'ultima chiamata ricorsiva risale

È naturale chiedersi se un approccio a doppia ricorsione possa offrire vantaggi, ma in questo caso la risposta è no, infatti se si suddividesse l'array in due sottoarray ciascuna chiamata fornirebbe la risposta "la sinistra da sola non supera $T$" che non ci dice nulla sull'esito finale che dipende da $\text{sinistra+destra}$, ne consegue che la ricorsione binaria in forma puramente booleana è insufficiente e quindi si dovrebbe complicare il tutto per renderla funzionante

**Quando l'obiettivo è un esito booleano con possibile arresto anticipato, la ricorsione lineare con soglia residua è la forma più naturale chiara ed efficace**

# Approccio ricorsivo e iterativo

###### Analisi
Dopo aver analizzato vari esempi di funzioni ricorsive e la loro costruzione passo dopo passo, è naturale chiedersi quale sia la differenza sostanziale tra un approccio ricorsivo e uno iterativo:
- **Ricorsione**: 
	- **Concettualmente:** rappresenta un modo di ragionare *dall'altro verso il basso*, infatti parte dalla formulazione del problema generale e lo scompone in sottoproblemi più piccoli
	- **Computazionalmente**:  richiede una quantità di memoria proporzionale alla profondità della ricorsione
- **Iterazione**: 
	- **Concettualmente:** rappresenta il modo di ragionare *dal basso verso l'alto*, la soluzione viene costruita passo passo mantenendo esplicitamente lo stato intermedio della computazione
	- **Computazionalmente**:  usa una quantità di memoria costante poiché le variabili utilizzate vengono riutilizzate a ogni passo.

Le funzioni ricorsive hanno molto spesso una maggiore **chiarezza espressiva** e questo permette una ottima **modularità**, naturalmente presenta anche dei **limiti pratici**, come quando la profondità di una chiamata è molto grande o anche nella gestione dei bug durante la fase di debug (le funzioni ricorsive sono difficili da debuggare)

###### Conclusioni
Possiamo dire che l’approccio iterativo privilegia l’efficienza e la concretezza del controllo esplicito, mentre la ricorsione privilegia l’astrazione, la chiarezza concettuale e la naturale corrispondenza con la definizione logica del problema. 

**Nell’equilibrio tra i due approcci si trova una delle lezioni più profonde della programmazione: la tensione costante tra eleganza e concretezza, tra astrazione e controllo.**

## Lezione 2 - Ottimizzazione con la ricorsione


# Il problema dello zaino

La ricorsione è uno strumento naturale per affrontare problemi di ottimizzazione in cui una scelta locale induce problemi residui della stessa natura. Il **problema dello zaino** che consiste in:

*dato un insieme di oggetti, ciascuno con un valore e un peso, si vuole scegliere un sottoinsieme che massimizza il valore totale senza superare una capacità massima $K$*

in questa prospettiva il problema dello zaino diventa una sfida di equilibrio tra costo e beneficio: ogni decisione di includere un oggetto implica la rinuncia a un altro, quello che possiamo fare, a ogni passo due possibilità - prendere un oggetto oppure lasciarlo riducendo così il problema ad una versione più piccola di se stesso.


###### Versione 0.1: pesi unitari, valori diversi
In questo caso abbiamo oggetto tutti con lo stesso peso ma valori differenti, il suo zaino può contenere solo un numero limitato di pezzi, pari alla capacità $K$, inoltre gli oggetti sono già disposti in ordine crescente di valore, dal meno prezioso al più prezioso, questa rappresenta la forma più semplice di questo problema. Infatti la scelta ottimale e abbastanza logica consiste nel prendere i $K$ oggetti che hanno il valore più alto

**Formalizzazione**: 
- Abbiamo $n$ oggetti ordinati per valore crescente: $$v_1 \le v_2 \le \dots \le v_n$$ tutti di peso unitario. 
- Vogliamo massimizzare il valore complessivo: $$max\{\Sigma_{i \in S} v_i: S ⊆ \{1,\dots,n\}, |S| \le K\}$$ poiché i pesi sono unitari e i valori ordinati, la soluzione ottima è semplicemente: $$S^* = \{n-K+1, n-K+2, \dots, n\}, V^* = \Sigma_{i=n-K+1}v_i$$
- Il problema si risolve in maniera lineare in un tempo di esecuzione $O(K)$ poiché non sono necessarie né scelte condizionali né chiamate ricorsive
  
```C++
int zainoLineare ( int v [] , int n , int K ) { 
	int somma = 0; 
	for ( int i = n - K ; i < n ; i ++) { 
		if ( i >= 0) somma += v [ i ]; 
	} 
	return somma;
}
```

Anche se non prettamente necessario per fini didattici esprimiamo la stessa soluzione anche in modo ricorsivo ![[Pasted image 20251018093624.png]]
Ricordiamo che: poiché gli oggetti sono già ordinati non è necessario scegliere se includere o meno l'oggetto $i$: se c'è ancora spazio nello zaino ($k>0$) lo si prende automaticamente

```C++
int F ( int v [] , int i , int k ) { 
	if ( i == 0 || k == 0) return 0; 
	return v [i -1] + F (v , i -1 , k -1);
}
```

La funzione viene richiamata inizialmente con $F(v,n,K)$ e termina dopo $K$ chiamate ricorsive

**Conclusioni**: questo esempio ci permette di capire che un algoritmo iterativo può essere riscritto anche in forma ricorsiva anche quando la ricorsione non offre dei vantaggi in termini di efficienza

###### Versione generale 0/1: pesi e valori variabili
Il problema si evolve, gli oggetti non sono più simili tra loro: ogni oggetto ha dunque il proprio peso $w_i$ e un valore $v_i$ differente. La strategia di risoluzione del problema precedente non funziona più infatti: *un oggetto di grande valore ma troppo pesante potrebbe impedire di portare con se più oggetti leggeri complessivamente più vantaggiosi*,  devono essere valutate tutte le possibili combinazioni e in questo la ricorsione diventa uno strumento fondamentale

**Formalizzazione**: Per ogni oggetto $i$ abbiamo peso $w_i \in N_{>0}$ e valore $v_i \ge 0$ la capacità massima dello zaino è $K \in N$. Vogliamo massimizzare $max\{\Sigma_{i \in S}v_i : S ⊆ {1,\dots,n}, \Sigma w_i \le K\}$ 
- Occorre confrontare sistematicamente le scelte *includo/escludo* 
- Definiamo $F(i,k)$ come prima, i suoi **casi base** sono:
	- $F(i,k) = 0$ se $i=0$ o $k = 0$
	- $F(i, k) = -\infty$ se $k<0$
	- visto che andremo a controllare tutte le possibili combinazioni il $-\infty$ ci serve per squalificare tutte le ricorsioni che superano la capacità massima.
- il suo caso **caso ricorsivo** è: $F(i,k) = max\{F(i-1,k), v_i+F(i-1, k-w_i)\}$

Si osservi che se una soluzione ottima non include $i$ allora è ottima su $(i-1, k)$. Se include $i$ allora la soluzione residua è ottima su $(i-1, k-w_i)$. Massimizzando i due casi otteniamo il valore ottimo.
```C++
int F ( int i , int k , int v [] , int w []) { 
	if ( k < 0) return INT_MIN /4; // rappresenta - infinito 
	if ( i == 0 || k == 0) return 0;
	int senza = F (i -1 , k , v , w ) ; 
	int con = v [ i ] + F (i -1 , k - w [ i ] , v , w ) ; 
	return ( senza > con ) ? senza : con ; 
}
```

La ricorsione da sola restituisce il valore ottimo, per ottenere una soluzione concreta facciamo un confronto locale per capire se $i$ è preso o escluso. Questa semplice soluzione ha complessità $O(n)$ 

###### Esercizi sulla ricorsione
La ricorsione è uno strumento potente per affrontare i problemi di ottimizzazione, gli esercizi dove ci viene chiesto di trova una soluzione ad un problema di ottimizzazione usando la ricorsione devono essere sviluppati seguendo questi passi:
 - **1.** Individuare i casi base che rendono la ricorsione terminante
 - **2.** Determinare la scomposizione del problema in sottoproblemi più piccoli
 - **3.** Stabilire una regola per combinare le soluzioni

## Lezione 3 - Notazioni asintotiche


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
Accanto a $O$ e $\Omega$ che rappresentano limiti asintotici ampi, esistono le loro controparti minuscole $o$ e $\omega$ che esprimo limiti stretti 

- La prima $o(g(n))$ esprime che $f(n)$ cresce **più lentamente** di $g(n)$:$$f(n) = o(g(n)) \Leftrightarrow \forall c > 0, \exists n_o > 0 \text{ tale che } f(n) < cg(n), \forall n \ge n_o$$Significa che il rapporto $\frac{f(n)}{g(n)}$ tende a zero quindi $f(n)$ cresce in modo più lento di $g(n)$ che per $n$ grandi il suo contributo diventa trascurabile
  
  Praticamente possiamo dire che un tempo di esecuzione $o(n^2)$ significa che esso cresce più lentamente di qualunque funzione proporzionale a $n^2$
- La seconda $\omega(g(n))$ ha un significato opposto descrive infatti funzioni che crescono **più rapidamente** di $g(n)$:$$f(n) = \omega(g(n)) \Leftrightarrow \forall c>0, \ \exists n_0 > 0 \text{ tale che } f(n)>cg(n), \forall n \ge n_0$$Significa che il rapporto $\frac{f(n)}{g(n)}$ tende a infinito 
  Praticamente possiamo dire che un tempo di esecuzione $\omega(n^2)$ significa che la nostra funzione cresce più velocemente di qualunque funzione proporzionale a $n^2$ 

Possiamo dunque pensare alle notazioni $o$ e $\omega$ come versioni esclusive di $O$ e $\Omega$ che indicano una crescita più lenta o più rapida che non raggiunge mai quella della funzione di riferimento


###### Conclusioni sulle notazioni asintotiche
La scala delle notazioni è la seguente
$$\omega(g(n)) \supseteq \Omega(g(n)) \supseteq \Theta(g(n)) \subseteq O(g(n)) \subseteq o(g(n))$$


### Oltre i casi limite
Le notazioni asintotiche descrivono il comportamento di un algoritmo per input molto grandi, ma nella realtà le cose possono essere più sfumate, le costanti o termini minori possono influenzare le prestazioni più di quanto le formule suggeriscano

###### Cosa accade davvero in pratica
Le notazioni asintotiche sono strumenti potenti per classificare gli algoritmi, ma è importante ricordare che esse rappresentano un modello astratto del comportamento di un programma. Dire che un algoritmo ha complessità $O(g(n))$ non significa che esegua esattamente $g(n)$ operazioni ma solo che per $n$ grandi il suo tempo di esecuzione non cresce più rapidamente di una funzione $g(n)$, di solito in questo tipo di analisi si distinguono tre casi:
- $O(g(n))$ che descrive il **caso peggiore** ovvero il limite superiore del tempo di esecuzione
- $\Omega(g(n))$ che descrive il **caso migliore** ovvero il limite inferiore del tempo di esecuzione
- $\Theta(g(n))$ indica che il tempo di esecuzione è compreso tra i due limiti precedenti, fornisce quindi una descrizione asintoticamente esatta di quello che è il tempo di esecuzione
![[Pasted image 20251022183909.png|700]]
Questi esempi ci mostrano che le notazioni non devono essere interpretate come previsioni puntuali, ma come **descrizioni qualitative del comportamento**, le notazioni vanno interpretate in questo modo:
- **Caso peggio** ci garantisce la soglia di sicurezza, utile in contesti critici
- **Caso migliore**: indica il limite di ottimalità teorica, ma non sempre raggiungibile
- **Caso medio**: è spesso quello più significativo nella valutazione pratica

###### Quando le costanti contano
Nell'analisi asintotica degli algoritmi, è prassi trascurare i **fattori costanti** e i **termini di ordine inferiore**, questo approccio consente di concentrarsi sulla crescita dominante della funzione per $n$ molto grandi, tuttavia questa cosa nella pratica quotidiana per input di piccole o medie dimensioni dovrebbe essere attenzionata

**Esempio**: $$T_1(n) = 100n, \ T_2(n) = 5n \log_2 n$$dal punto di vista asintotico $T_1$ è più efficiente, tuttavia il fattore costante $100$ nel primo algoritmo può renderlo più lento del secondo per una vasta gamma di valori realistici di $n$, vediamolo con $n = 100$
$$T_1(100) = 10000 , \ T_2(100) = 5\times100\times \log_2 100 ≈ 5 \times 100 \times 6.64 = 3320 $$
In questo caso, l'algoritmo con complessità peggiore risulta più veloce

Questo esempio mette in evidenza un punto importante: le notazioni asintotiche descrivono il comportamento per $n$ grandi, ma non sempre riflettono le prestazioni reali su input di dimensioni moderate

**In sintesi** possiamo dire che:
- Le notazioni asintotiche descrivono il comportamento a lungo termine
- I fattori costanti e i termini minori influenzano le prestazioni nel breve termine
- un algoritmo asintoticamente migliore può essere più lento di un altro per una vasta gamma di input reali

## Lezione 4 - Risoluzione delle Equazioni di Ricorrenza


# Risoluzione delle equazioni di ricorrenza

### Introduzione alle equazioni di ricorrenza
Per analizzare il tempo di esecuzione di tutti gli algoritmi (e in particolare dei ricorsivi) si fa uso delle *equazioni di ricorrenza* che esprimono il costo totale $T(n)$ in funzione del costo dei sotto-problemi e del lavoro aggiuntivo

###### Definizione
Un'equazione di ricorrenza è una relazione del tipo: $$T(n) = aT(\frac{n}{b})+f(n)$$con:
- $T(n)$ costo per il risolvere il problema di dimensione $n$
- $a$ è il numero di sotto-problemi in cui il problema viene suddiviso
- ciascun sotto-problema ha dimensione $\frac{n}{b}$
- $f(n)$ rappresenta il lavoro non ricorsivo (cioè il costo per dividere, combinare o gestire i sotto-problemi)

###### Risoluzione dell'equazione di ricorrenza
La *soluzione* (anche detta *forma esplicita*) indica un'espressione chiusa per $T(n)$, utile per comprendere come cresce il tempo di esecuzione al crescere di $n$. Per fare questa cosa usiamo tre metodi:
1. **Metodo dell'albero di ricorsione**: si rappresenta la ricorsione come un albero, si calcola il costo per livello poi sommati per conoscere il costo totale, questo metodo viene usato principalmente per capire dove si concentra il lavoro (livelli iniziali o finali).
2. **Metodo della sostituzione**: si formula un'ipotesi sul comportamento asintotico di $T(n)$ e la si dimostra per induzione
3. **Metodo Master**: fornisce un risultato generale che consente di determinare l'ordine di grandezza di $T(n)$ confrontando $f(n)$ con $n^{\log_b a}$

### Identificare l'equazione di ricorrenza
###### Fasi della ricorsione
Ogni algoritmo ricorsivo può essere idealmente scomposto in tre momenti:
1. *fase di suddivisione*: il problema viene suddiviso in più sotto-problemi di dimensione minore 
2. *fase di risoluzione*: ciascun sotto-problema viene affrontato a sua volta in modo ricorsivo
3. *fasi di composizione*: i risultati parziali vengono combinati
Detto ciò possiamo aggiungere alla spiegazione dell'equazione di ricorrenza le seguenti cose: $$T(n) = aT(\frac{n}{b})+f(n)$$
- $a$ è il numero di sotto-problemi prodotti
- $b$ il fattore di riduzione
- $f(n)$ il costo complessivo delle operazioni non ricorsive

###### Esempio - Ricerca binaria
Nel caso della ricerca binaria, l'algoritmo esami un intervallo ordinato, ne calcola il pinto medio e confronta il valore cercato con l'elemento corrispondente. Se il valore coincide la ricerca termina, altrimenti viene richiamata ricorsivamente sull'altra metà
```C
int binarySearch(int A[], int low, int high, int x) { 
	if (low > high) return -1; 
	
	int mid = (low + high) / 2; 
	if (A[mid] == x) 
		return mid; 
	else if (A[mid] > x) 
		return binarySearch(A, low, mid - 1, x); 
	else 
		return binarySearch(A, mid + 1, high, x); 
	}
```

In ogni chiamata si effettua al massimo una sola chiamata ricorsiva su metà dell'intervallo, mentre il lavoro non ricorsivo è costante. L'equazione di ricorrenza quindi è: $$T(n) = T(\frac{n}{2})+1$$
Ci sono altri esempio nel file [[4-risoluzione delle Equazioni di Ricorrenza.pdf|pdf]]

### Ricorrenze non uniformi
Non tutti gli algoritmi ricorsivi possono essere descritti mediante un'equazione del tipo: $$T(n) = aT(\frac{n}{b})+f(n)$$in cui il problema viene suddiviso in un numero costante di sotto-problemi. In molti casi reali, la dimensione dei sotto-problemi può variare a seconda dei dati.

###### Esempio - quickSort
- **Caso ideale**: l'elemento *pivot* scelto divide l'array esattamente in due parti uguali, ciascuna di dimensione $\frac{n}{2}$
- **Caso reale**: il *pivot* scelto non divide il nostro array in due array di dimensioni diverse
Nel caso medio possiamo dire che:
$$T(n) = T(\alpha n) + T((1-\alpha)n) + n$$dove il parametro $\alpha$ rappresenta la frazione di elementi che ricadono nella prima metà dopo la partizione ($0< \alpha <1$). 
Quando $\alpha = \frac{1}{2}$ siamo nel caso bilanciato (il caso ideale), quando $\alpha$ si avvicina a 0 o a 1 il costo peggiora fino al caso limite.

###### Analisi
L'esempio appena fatto ci mostra come occorre analizzare la ricorrenza caso per caso, e non sempre possibili applicare le formule standard.

### Il metodo dell'albero di ricorsione
Il metodo dell'albero di ricorsione nasce dall'idea di visualizzare come vengono effettuate le chiamate ricorsive. In questo modo diventa possibili analizzare passo dopo passo come si distribuisce il lavoro complesso nei diversi livelli di ricorsione, tutto ciò viene fatto con la seguente notazione

###### Notazione
ricordiamo sempre l'equazione di ricorrenza generale: $T(n) = aT(\frac{n}{b})+f(n)$
- La *radice* corrisponde al problema iniziale di dimensione $n$
- i *nodi interni* rappresentano le chiamate ricorsive generate a ciascun livello
- ogni *nodo* è etichettato con il costo del lavoro locale $f(n_i)$ dove $n_i$ è la dimensione del sotto-problema corrispondente
- i *figli* di un nodo rappresentano le chiamate generate da quel nodo, ognuna di dimensione ridotta di un fattore $b$

###### Analisi
La costruzione di questo albero permette di scomporre la ricorsione in livelli. A ogni livello $k$ il numero di nodi è $a^k$  di conseguenza la dimensione dei sotto-problemi è $\frac{n}{b^k}$. Il costo totale associato al livello $k$ viene descritto come: $$C_k = a^k f(\frac{n}{b^k})$$cioè il numero di nodi di quel livello moltiplicato per il costo del lavoro svolto in ciascun nodo. Quindi il costo totale diventa: $$
T(n) = \sum_{k=0}^{L} C_k \text{ ovvero } \sum_{k=0}^{L} a^k f\left(\frac{n}{b^k}\right),
$$con $L$ che rappresenta la profondità dell'albero ossia il numero di livello fino a quando la dimensione del problema non si riduce a una costante

 Questo approccio fornisce un modo intuitivo per stimare l'andamento del lavoro, ma è anche il modo migliore per averne una rappresentazione visiva. Il comportamento della somma può essere descritto come una serie geometrica, in cui ogni livello contribuisce con un costo proporzionale al precedente. Da cui distinguiamo tre casi:
 1. **Primi livelli**: somma dominata dai primi livelli  quindi il costo è determinato dal lavoro iniziale
 2. **Livelli intermedi:** tutti i livelli hanno lo stesso ordine di grandezza quindi il costo aumenta con l'aumentare dei livelli
 3. **Livelli finali**: Somma dominata dai livelli inferiori quindi il costo dominante si sposta alla fine dell'albero

###### Esempi
**Esempio 1 - Ricerca binaria**: consideriamo l'equazione della ricerca binaria trovata prima: $$T(n) = T(\frac{n}{2})+1$$Possiamo immaginare l'albero della ricorsione come una catena di chiamate successive, in cui ogni nodo produce un unico figlio di dimensione dimezzata. Ad ogni livello il lavoro è constante (ovvero $1$). Il costo totale si ottiene sommando il contributi di tutti i livelli:
$$T(n) = 1+1+1+1+\dots+1$$dove il numero dei termini è pari a $\log_2n+1$. Da qui risulta immediatamente che: $T(n) = O(\log n)$ 

**Altri esempi disponibili nel file originale**

### Il metodo della sostituzione
Un secondo approccio è il metodo della sostituzione, dove al posto di avere un'analisi attraverso una rappresentazione visiva abbiamo un'analisi più analitica

###### Definizione
Questo approccio consiste nel: formulare un'ipotesi sulla forma asintotica della soluzione e nel dimostrare che tale ipotesi è corretta attraverso un ragionamento induttivo. 

**Praticamente**: Si parte dall'equazione di ricorrenza e, osservando la struttura del problema, si tenta di indovinare la crescita di $T(n)$ ad esempio $O(n), O(n \log n)$ o $O(n^2)$. Una volta formulata questa ipotesi la si sostituisce nell'equazione e si verifica se l'uguaglianza risulta soddisfatta per valori sufficientemente grandi.

###### Step da seguire
1. Si formula un'ipotesi sul comportamento asintotico di $T(n)$ (spesso lo si fa attraverso metodi più intuitivi come l'albero di ricorsione)
2. Si sostituisce questa ipotesi all'interno dell'equazione di ricorrenza e si verifica se l'uguaglianza risulta soddisfatta
3. Se necessario si aggiusta l'ipotesi e si riparte dallo step 1

**Ricordiamo che**: questo metodo non si limita a fornire una soluzione numerica: esso insegna a riconoscere e controllare la correttezza delle ipotesi che emergono in modo intuitivo

###### Esempi
**Esempio 1 - Ricerca binaria**: consideriamo l'equazione della ricerca binaria trovata prima: $$T(n) = T(\frac{n}{2})+1$$
L'intuizione (l'albero di ricorsione)n suggerisce una crescita logaritmica. Supponiamo quindi: $$T(n) \le c \log_2 n$$sostituendo otteniamo che:
$$T(n) \le c \log_2 \frac{n}{2}+1 =$$
$$= c(\log_2 n - 1) + 1$$
$$= c \log_2 n -c + 1$$Affinché la disuguaglianza $T(n) \le c \log_2 n$ sia rispettata, è sufficiente che: $$-c+1 \le 0 \text{ cioè } c \ge 1$$Anche in questo caso la nostra ipotesi è coerente ed è $T(n) = O(\log n)$

**Altri esempi nel file originale**

### Metodo basato sul teorema Master
Il teorema Master fornisce una regola generale per determinare in modo sistematico l'ordine di grandezza.

###### Definizione
 Le equazioni che questo teorema risolve sono del tipo: $$T(n) = aT(\frac{n}{b})+f(n)$$dove:
 - $a \ge 1$ è il numero di sotto-problemi in cui viene suddiviso il problema 
 - $b>1$ è il fattore di riduzione della dimensione
 - $f(n)$ è il costo del lavoro non ricorsivo
L'idea del teorema master è confrontare la funzione $f(n)$ con la quantità $n^{\log_b a}$, a seconda di quale dei due termini cresce più rapidamente, si individuano tre comportamenti distinti.

###### Enunciato del teorema Master
Sia $$T(n) = aT(\frac{n}{b})+f(n) \text{ con } a\ge1, b>1 \text{ e } f(n) \text{ una funzione positiva } $$
**Caso 1: Il lavoro ricorsivo domina**
Se esiste una costante $\varepsilon > 0$ tale che
$$f(n) = O(n^{\log_{b} a - \varepsilon}),$$
cioè il lavoro non ricorsivo $f(n)$ è asintoticamente più piccolo del lavoro interno alla ricorsione $n^{\log_{b} a}$ (polinomialmente), allora la complessità è:
$$T(n) = \Theta(n^{\log_{b} a}).$$
In questo caso domina il costo generato dalla parte ricorsiva dell'algoritmo (le chiamate interne).
Esempio tipico: Moltiplicazione di Strassen, dove $a=7$, $b=2$, $f(n)=n^2$.

**Caso 2: I lavori sono equivalenti (a meno di un fattore logaritmico)**
Se
$$f(n) = \Theta(n^{\log_{b} a} \log^{k} n),$$
ossia il lavoro non ricorsivo ha lo stesso ordine di grandezza del lavoro ricorsivo $n^{\log_{b} a}$ (a meno di un fattore logaritmico $\log^{k} n$, con $k \ge 0$), allora la complessità è:
$$T(n) = \Theta(n^{\log_{b} a} \log^{k+1} n).$$
In questo caso, tutti i livelli dell'albero di ricorsione contribuiscono in modo equivalente al costo totale, e la moltiplicazione per un fattore $\log n$nel termine $T(n)$ si traduce in un incremento di un ordine logaritmico nel costo complessivo.
(Generalizzato per $k=0$): Se $f(n) = \Theta(n^{\log_{b} a})$, allora $T(n) = \Theta(n^{\log_{b} a} \log n)$.


**Caso 3: Il lavoro non ricorsivo domina**
Se esiste una costante $\varepsilon > 0$ tale che
$$f(n) = \Omega(n^{\log_{b} a + \varepsilon}),$$
cioè il lavoro non ricorsivo $f(n)$ cresce più velocemente del lavoro interno $n^{\log_{b} a}$ (polinomialmente), e se inoltre è verificata una condizione di regolarità (detta condizione di dominanza):
$$a f\left(\frac{n}{b}\right) \le c f(n)$$
per una costante $c < 1$ e per $n$ sufficientemente grande, allora la complessità è:
$$T(n) = \Theta(f(n)).$$
In questo caso, la parte ricorsiva diventa trascurabile rispetto al lavoro non ricorsivo.

Esempio tipico: Una ricorrenza come $T(n) = 2T(n/2) + n^2$, dove il termine $n^2$ domina.

###### Interpretazione intuitiva
Il teorema Master può essere interpretato come un modo sintetico per stabilire quale parte dell'albero di ricorsione domina il costo complessivo:
1. nel *primo caso* domina il livello inferiore, dove si accumula la maggior parte di lavoro ricorsivo
2. nel *secondo caso* ogni livello contribuisce in egual misura, e il numero di livelli aggiunge un ulteriore fattore logaritmico
3. nel *terzo caso* domina il livello superiore, dove il lavoro ricorsivo è prevalente
Pur non essendo applicabile in tutti i casi (ad esempio quando i sotto-problemi hanno dimensioni diverse) rimare uno degli strumenti più rapidi per l'analisi asintotica

###### Confronto tra funzioni
Uno degli aspetti più delicati del teorema master consiste nel comprendere come confrontare la funzione non ricorsiva $f(n)$ con la quantità $n^{log_b a}$. Ricordiamo che:
- $n^{log_b a}$ descrive quanto grande diventa l'albero di ricorsione
- $f(n)$ misura il costo aggiuntivo sostenuto a ciascun livello

Se $f(n)$ cresce molto meno di $n^{log_b a}$, il termine ricorsivo domina, se cresce di più, prevale il termine non ricorsivo; se le due funzioni hanno crescita simile, i contributi si equilibrano. Viene introdotto il parametro $\epsilon$ per formalizzare questa differenza di crescita.
![[Pasted image 20251211114615.png|500]]
In generale, il ruolo di $\epsilon$ non è quello di un valore da calcolare ma di un indicatore concettuale: serve a **distinguere** tra crescite *molto piccole* o *molto più grandi* rispetto a $n^{\log_b a}$  

###### Esempi
**Esempio 1 - Ricerca binaria**
La ricerca binaria è descritta dalla ricorrenza
$$T(n) = T(n/2) + 1.$$
In questo caso $a = 1$, $b = 2$ e $f(n) = 1$. Calcoliamo il termine di riferimento $n^{\log_{b} a}$: poiché $\log_{2} 1 = 0$, si ottiene $n^{\log_{2} 1} = n^{0} = 1$. Confrontiamo ora $f(n)$ con questo valore:

$$f(n) = 1 = \Theta(1) = \Theta(n^{\log_{2} 1}).$$

Siamo dunque nel **secondo caso** del Teorema Master, quello in cui $f(n)$ ha lo stesso ordine di grandezza del termine ricorsivo.

Applicando la formula corrispondente, otteniamo:

$$T(n) = \Theta(n^{\log_{2} 1} \log n) = \Theta(\log n).$$

In ogni passo della ricerca binaria, il problema viene dimezzato, ma il lavoro svolto ad ogni livello (una sola comparazione) è costante. Poiché ci sono $\log_{2} n$ livelli fino a ridurre il problema a un singolo elemento, il costo totale cresce in modo logaritmico. Il Teorema Master, in questo caso, conferma in modo immediato ciò che l'intuizione suggerisce: ogni livello contribuisce in modo uniforme, e il numero di livelli determina la crescita complessiva.

**Ci sono altri esempi nel file originale**

## Lezione 5 - Heap e limiti ordinamento


## Heap

### Introduzione
Si usa l'heap per implementare efficientemente le **code con priorità**. Questo tipo di coda non serve gli elementi in base al momento di arrivo, ma in base a una caratteristica intrinseca chiamata **chiave** (o priorità). Spesso viene astratta come un albero (successivamente la implementiamo come array)

###### Caratteristiche principali
Lo heap è un albero con le seguenti caratteristiche:
- *Binario*: ogni nodo ha al massimo due figli.
- *Posizionale*: è possibile distinguere figlio destro e figlio sinistro
- *Completo*: In ogni livello $i$ dell'albero sono presenti $2^i$ nodi 
- *Parzialmente ordinato*: Il valore di un nodo sarà sempre maggiore o uguale a quella dei suoi figli
###### Esempio - il pronto soccorso
Un esempio reale di coda con priorità è il triage ospedaliero. I codici colore rappresentano le priorità (chiavi):
*   Bianco/Verde (codici bassi/meno urgenti).
*   Giallo/Rosso (codici alti/urgenti).
Se un paziente arriva in codice giallo, supera automaticamente tutti quelli in attesa con codice verde, indipendentemente da quanto tempo stiano aspettando. La fila viene rispettata solo tra pazienti con lo stesso codice.

### Confronto con altre implementazioni delle code con priorità

###### Specifiche iniziali
Per capire perché nasce lo heap dobbiamo prima fare un'analisi di come le varie strutture dati si comportano (in termini di complessità algoritmica) quando si lavora con una coda con priorità. Una implementazione di una coda con priorità deve avere necessariamente i seguenti metodi:
1.  **Inserimento:** Aggiungere un nuovo elemento.
2.  **Estrazione (del minimo):** Rimuovere e restituire l'elemento prioritario.
3.  **Decremento (Decrease Key):** Aumentare la priorità di un elemento e quindi diminuire il valore della sua chiave
4.  **Minimo:** Consultare l'elemento prioritario senza estrarlo.

Le analisi successive verranno fatte supponendo $n$ nodi
###### Vs Array Disordinato
*   **Inserimento:** $O(1)$. Basta mettere l'elemento nella prima posizione libera
*   **Estrazione/Minimo:** $\Theta(n)$. Bisogna scorrere tutto l'array per trovare il valore più piccolo.
*   **Decremento:** $O(1)$ se abbiamo il puntatore all'elemento, ma non aiuta l'estrazione successiva.

*Vantaggio:* Inserimento immediato.
*Svantaggio:* Costo lineare per trovare il minimo, inaccettabile per code frequenti.

###### Vs Array Ordinato
*   **Minimo:** $O(1)$. Il minimo è sempre in prima posizione (o ultima, a seconda dell'ordinamento).
*   **Inserimento:** $O(n)$. Per inserire un valore e mantenere l'ordine, bisogna "shiftare" (spostare) tutti gli elementi successivi.
*   **Estrazione:** $O(n)$. Anche togliendo il primo elemento, bisogna riorganizzare l'array (shift verso sinistra).

*Vantaggio:* Accesso rapido al minimo.
*Svantaggio:* Inserimento ed estrazione costosi.

###### Vs Alberi Binari di Ricerca Bilanciati (BBST)
Utilizzando un BBST (*Balanced Binary Search Tree*), l'altezza dell'albero è garantita essere logaritmica ($O(\log n)$).
*   **Tutte le operazioni (Inserimento, Estrazione, Ricerca, Decremento):** $O(\log n)$.

Sebbene $O(\log n)$ sia ottimo i BBST sono strutture complesse da implementare e mantenere (richiedono puntatori e ribilanciamenti).

L'obiettivo dello **Heap** è ottenere le stesse prestazioni asintotiche dei BBST ($O(\log n)$) ma con una struttura molto più semplice, gestibile tramite un array e senza l'uso esplicito di puntatori.

### Come è fatto uno Heap

###### Introduzione
Un heap è un albero binario completo dove a differenza di un BST (dove tutto il sottoalbero sinistro è minore del nodo e tutto il destro è maggiore), nello Heap c'è solo una relazione verticale:
$$ \text{Key}[parent] \le \text{Key}[figlio] $$
Non c'è alcuna relazione d'ordine specifica tra fratello destro e fratello sinistro. Questo è definito **ordinamento parziale**.
![[Pasted image 20251211180612.png|500]]
###### Tipi di Heap
Esistono due varianti di Heap, simmetriche tra loro:
1. **Min Heap:** La chiave di un nodo è sempre **minore o uguale** a quella dei suoi figli. La radice contiene il minimo assoluto.
2. **Max Heap:** La chiave di un nodo è sempre **maggiore o uguale** a quella dei suoi figli. La radice contiene il massimo.

### Operazioni sullo Heap
Di seguito la complessità e le implementazioni delle varie funzionalità di uno heap.
###### Minimo
Poiché usiamo un Min Heap, il minimo si trova sempre alla radice.
**Costo:** $\Theta(1)$ (Accesso diretto all'indice 1 dell'array).
*Nota*: la stessa cosa vale per il massimo in un MaxHeap
###### Decrease Key (Decremento di una chiave)
Se riduciamo il valore di una chiave (es. un nodo passa da 7 a 1), potremmo violare la proprietà dello heap (il figlio diventa più piccolo del padre).
**Procedura:**
1.  Si aggiorna il valore.
2.  Si confronta il nodo con il padre.
3.  Se il nodo è minore del padre, si scambiano (**swap**).
4.  Si ripete il procedimento risalendo verso la radice finché la proprietà non è ripristinata o si raggiunge la radice.

**Costo:** Nel caso peggiore si risale tutta l'altezza dell'albero. $O(\log n)$.
```
DECREASE-KEY(H,x,k) 
	key(x) = k 
	p = parent(x) 
	while(p != NULL and key(p)>key(x)) do 
		swap(x,p) 
		x = p 
		p = parent(x)
```
###### Inserimento
L'inserimento sfrutta la logica del *Decrease Key*:
1. Inseriamo il nuovo nodo con valore $\infty$ nella prima posizione libera
2. Poi facciamo una *Decrease Key* al nodo inserito con il suo valore reale.
3. L'elemento "risale" (bubble-up) fino alla sua posizione corretta.

**Costo:** Proporzionale all'altezza dell'albero. $O(\log n)$.
```
INSERT(H,k) 
	x = new node(H) 
	key(x) = k 
	p = parent(x) 
	while(p != NULL and key(p)>key(x)) do 
		swap(x,p) 
		x = p 
		p = parent(x)
```
###### Procedura Heapify(i):
Si applica a un nodo $i$ assumendo che i sottoalberi sinistro e destro siano già heap validi.
1.  Confronto la chiave di $i$ con il figlio sinistro ($l$) e il figlio destro ($r$).
2.  Individuo il più piccolo tra $i$, $l$ e $r$.
3.  Se il minimo non è $i$, scambio $i$ con il figlio minore.
4.  Chiamo ricorsivamente *Heapify* sul figlio appena scambiato.

**Analisi della complessità di Heapify:**
L'equazione di ricorrenza (nel caso peggiore su un albero quasi completo) è approssimabile dal Teorema Master (Caso 2):
$$ T(n) \le T(2/3 n) + \Theta(1) \implies T(n) = \Theta(\log n) $$
Il fattore $2/3$ deriva dal fatto che, in un albero non perfettamente bilanciato nell'ultimo livello, il sottoalbero più grande può contenere circa i 2/3 dei nodi totali. Tuttavia, la complessità rimane legata all'altezza: **$O(\log n)$**.

```
HEAPIFY(H,x) 
	y = left(x) 
	z = right(x) 
	min = x 
	IF y != NULL AND key(y)<key(x) 
		min = y 
	IF y \neq NULL AND key(z)<key(min) 
		min = z 
	IF min != x 
		swap(x, min) 
	heapify(H,min)
```
###### Estrazione del Minimo
Per estrarre il minimo (la radice), non possiamo lasciare un buco.
1.  Prendiamo l'ultimo elemento dell'array (quello più in basso a destra) e lo spostiamo alla radice al posto del minimo rimosso.
2.  Ora la struttura è integra, ma l'ordinamento è violato (un elemento grande è in testa).
3.  Bisogna far "scendere" questo elemento nella posizione corretta e lo facciamo usando la funzione heapify.
**Costo**: richiamando heapify questa procedura costa **$O(\log n)$**.

### Heap usando un array
Il vero segreto dello Heap è che può essere implementato facilmente usando un **array**, eliminando la necessità di puntatori. E lo si fa usando le seguenti convenzioni:
* La radice è all'indice $1$ (o $0$, a seconda dell'implementazione; qui useremo l'indice 1 per semplificare le formule).
* Dato un nodo all'indice $i$:
	*   Il **figlio sinistro** (*Left*) si trova a $2i$.
	*   Il **figlio destro** (*Right*) si trova a $2i + 1$.
	*   Il **genitore** (*Parent*) si trova a $\lfloor i/2 \rfloor$.

Queste operazioni possono essere eseguite in modo estremamente efficiente tramite **operazioni bitwise** (shift dei bit):
*   Moltiplicare per 2 corrisponde a uno *shift a sinistra* (`i << 1`).
*   Dividere per 2 corrisponde a uno *shift a destra* (`i >> 1`).
![[Pasted image 20251211181500.png|500]]
Di seguito tutte le funzioni ridefinite per l'implementazione sottoforma di array del heap
###### Funzioni left, right, parent
```C++
int left(int i){
	return (2*i)+1; //Mettiamo +1 perché gli array partono da 0
}

int right(int i){
	return (2*i)+2;
}

int parent(int i){
	return (i-1)/2;
}
```
###### Heapify
``` C++
void min_heapify(int i){
    int l = left(i);
    int r = right(i);
    int min = i;

    if(l < size && array[l] < array[min]) min = l;
    if(r < size && array[r] < array[min]) min = r;

    if(min != i){
        int scambio = array[i];
        array[i] = array[min];
        array[min] = scambio;
        min_heapify(min);
    }
}  

```

```C++
void max_heapify(int i){

	int l = left(i);
	int r = right(i);
	int max = i;

	if(l < size && array[l] > array[max]) max = l;
	if(r < size && array[r] > array[max]) max = r;

	if(max != i){
		int scambio = array[i];
		array[i] = array[max];
		array[max] = scambio;
		heapify(max);
	}

}

```

###### Insert
```C++
void insert(int k){
	array[size++] = k;
	int i = size - 1;
	int p = parent(i);
	//Questa insert mantiene una struttura max-heap, per min-heap modificare in: array[p]>array[i]
	while(i>0 && array[p]<array[i]){
		int scambio = array[i];
		array[i] = array[p];
		array[p] = scambio;
		i = p;
		p = parent(i);
	}
}
```
###### Extract-min
```C++
int extractMax(){
	int max = array[0];
	
	int scambio = array[0];
	array[0] = array[size-1];
	array[size-1] = scambio;
	
	size--;
	max_heapify(0);
	
	return max;
}
```

### Costruzione dello Heap
Come si costruisce uno heap partendo da un array disordinato di $n$ elementi? di seguito due metodi per farlo
###### Metodo 1: Inserimenti successivi
Possiamo inserire gli elementi uno alla volta in uno heap vuoto (usando la funzione insert). Poiché ogni inserimento costa $O(\log n)$, per $n$ elementi il costo totale è:
$$ O(n \log n) $$
###### Metodo 2: Procedura Build-Min-Heap (Ottimizzata)
Esiste un metodo più efficiente che sfrutta la struttura. Prendiamo l'array così com'è e chiamiamo **Heapify** a ritroso, partendo dall'ultimo nodo interno fino alla radice.

**Algoritmo:**
```PSEUDOCODICE
FOR i = floor(n/2) DOWN TO 1:
    Min-Heapify(array, i)
```
In pratica, sistemiamo prima i sottoalberi piccoli in basso, poi quelli medi, e infine la radice.

**Analisi della complessità**
A prima vista potrebbe sembrare $O(n \log n)$ perché chiamiamo Heapify $n/2$ volte. Tuttavia, l'altezza dei nodi varia:
*   La maggior parte dei nodi è vicino al fondo (altezza bassa, costo Heapify basso).
*   Pochissimi nodi sono in alto (altezza $\log n$).

La somma dei costi è data dalla serie:
$$ \sum_{h=0}^{\log n} \frac{n}{2^{h+1}} \cdot O(h) = n \sum_{h=0}^{\infty} \frac{h}{2^h} $$
Poiché la serie $\sum \frac{h}{2^h}$ converge a una costante, il costo totale è:
$$ \Theta(n) $$
Costruire uno heap da zero quindi richiede **tempo lineare**.

###### Metodo 3: procedura Build-Max-Heap
Questa procedura è uguale a quella del min-heap ma richiamiamo max-heapify 
```C++
void buildMaxHeap(){
	for(int i = size/2-1; i >= 0; i--){
		max_heapify(i);
	}
}
```

### Heapsort

###### Analisi
Prendendo in esame il selection sort, capiamo subito che il problema principale di questo tipo di algoritmo è il tempo perso durante la ricerca del massimo, cosa che in un max-heap facciamo in tempo $O(1)$, da qui nasce l'heapsort

###### Algoritmo e implementazione
L'algoritmo heapsort inizia utilizzando *Build-max-heap* per costruire un max-heap nella array in input, l'elemento più grande è memorizzato nella radice, quindi ci basta scambiarlo con l'ultimo elemento nell'array per ordinarlo, poi richiamiamo max-heapify sull'array ma escludendo gli elementi ordinati, facendo questa cosa per ogni elemento otteniamo il nostro array ordinato.

```C++
void HeapSort(){
	buildMaxHeap();
	int len = size;
	for(int i = len-1; i > 2; i--){
		int scambio = array[i];
		array[i] = array[0];
		array[0] = scambio;
		size--;
		max_heapify(0);
	}
	size = len; //Nell'implementazione fatta serve per stampare il lo heap
}
```
Questo algoritmo ha complessità $O(n \log n)$

### Esami
Nel file [[6 - 29 ottobre 2025.pdf]] ci sono alla fine degli esempi di esercizi di esame:
- Effettuare 13 estrazioni del minimo e mostrare cosa succede al nostro array
- Scrivere la procedura HeapMerge
- Scrivere la procedura ListMerge che segua delle regole specifiche
- Top-ten di punteggi più alti
- ecc...

## Limiti degli ordinamenti con confronti

### Albero di decisione
###### Definizione
Gli ordinamenti per confronti possono essere visti in modo astratto come degli alberi di decisione. Un albero di decisione è un albero binario pieno che rappresenta i confronti fra elementi fatti in un particolare algoritmo preso in esame.

###### Esempio
Attraverso un esempio è abbastanza intuitivo capire come funziona un albero di decisione:
Con $A = [1,2,3]$ abbiamo un albero di decisione del tipo: ![[Pasted image 20251213105444.png|500]]Notiamo subito che il caso peggiore nell'ordinamento corrisponde all'altezza di questo albero

### Teorema e dimostrazione
###### Teorema
Qualsiasi algoritmo di ordinamento per confronti richiede $\Omega(n \log n)$

###### Dimostrazione
Come abbiamo visto nell'esempio dell'albero di decisione ci basta determinare l'altezza di un albero di decisione dove possibile permutazione degli elementi compare come foglia. 
Consideriamo quindi un albero di decisione:
- elementi da ordinare $n$
- altezza $h$
- numero di foglie $l$
ciascuna delle $n!$ permutazioni dell'input compare in una foglia, si ha quindi $n! \le l$. Dal momento che un albero binario di altezza $h$ non ha più di $2^h$ foglie si ha: $$n! \le l \le 2^h$$da questo estraiamo: $$n! \le 2^h \rightarrow \log_2(n!) \le h$$che ci indica una complessità di $$\Omega (n \log n)$$ 
###### Conclusioni
Da questo capiamo che algoritmi come *heapSort* e *MergeSort* sono ottimi algoritmi di ordinamento usando i confronti

## Lezione 6 - Ordinare senza confronti


# Algoritmi di ordinamento senza confronti 

### Counting sort

###### Premesse
Per superare la barriera imposta dall'albero di decisione abbiamo bisogno di algoritmi di ordinamento che non fanno confronti, e quindi presentiamo il counting sort. Per fare questa cosa il counting sort suppone che ciascuno degli $n$ elementi in input sia un intero compreso tra $0$ e $k$

###### Algoritmo
Per usare il counting sort abbiamo bisogno:
- $A$ un array in input di $n$ elementi interi che vanno da $0-k$
- $C$ un array con $k$ celle i cui valori indicano il numero di occorrenze di $k$ in $A$
- $B$ array di output

```
Counting-Sort(A, B, n):
    k = max(A)                     // valore massimo in A
    C = new Array(k+1)

    // inizializza C a 0
    for i = 0 to k:
        C[i] = 0

    // conta le occorrenze
    for i = 0 to n-1:
        C[A[i]] = C[A[i]] + 1

    // calcola le posizioni cumulative
    for i = 1 to k:
        C[i] = C[i] + C[i-1]

    // costruisci l'array ordinato B in maniera stabile
    for i = n-1 downto 0:
        B[C[A[i]] - 1] = A[i]     // -1 perché B è 0-indexed
        C[A[i]] = C[A[i]] - 1

```

Di seguito per step la spiegazione:
1. Cerchiamo il nostro $k$ che sarebbe il massimo di $A$
2. Creiamo il nostro array $C$ con $k+1$ posizioni
3. *Primo FOR*: inizializza a 0 l'array C
4. *Secondo FOR*: controlliamo ogni elemento di $A$ e incrementiamo di uno l'indice corrispondente in $C$
	- Dopo questo passo $C[i]$ contiene il numero di occorrenze di $i$ in $A$
5. *Terzo FOR*: contiamo il numero di elementi in $A$ minore o uguali $i$
6. *Quarto FOR*: Inseriamo ogni elemento di $A$ dentro $B$ usando come indice il valore calcolato nel terzo passaggio, la riduzione di $C[A[i]]$ serve per fare in modo che il successivo elemento con valore uguale ad $A[j]$ venga inserito una posizione prima

###### Implementazione
```C++
void countingSort(int *A, int* B, int n){
    int k = max(A, n);
    int* C = new int[k+1];
   
    for(int i = 0; i <= k; i++)
        C[i] = 0;

    for(int i = 0; i < n; i++)
        C[A[i]] = C[A[i]] + 1;

    for(int i = 1; i <= k; i++)
        C[i] = C[i]+C[i-1];

    for(int i = n-1; i >= 0; i--){
        B[C[A[i]]-1] = A[i];
        C[A[i]] = C[A[i]] - 1;
    }
   
}
```
Questa implementazione se avviata sull'array: $A = \{2,6,1,7,8\}$ da il seguente output:
```
Array di base: 2 - 6 - 1 - 7 - 8
Primo For: 0 - 0 - 0 - 0 - 0 - 0 - 0 - 0
Secondo For: 0 - 1 - 1 - 0 - 0 - 0 - 1 - 1
Terzo For: 0 - 1 - 2 - 2 - 2 - 2 - 3 - 4
Quarto For: 1 - 2 - 6 - 7 - 8
```
###### Complessità
- il primo ciclo impiega $\Theta(k)$
- il secondo $\Theta(n)$
- il terzo $\Theta(n)$
- il quarto $\Theta(k)$
Quindi il tempo totale è $\Theta(n+k)$
Inoltre è **stabile**: ovvero i numeri con lo stesso valore si presentano nell'array di output nello stesso ordine in cui si trovano nell'array di input, questa cosa solitamente è importante solo quando abbiamo dati satellite, ma nel counting è sempre importante perché molte volte viene usato come subroutine per implementare il radix sort.

### Radix sort

###### Premesse
Il radix sort è l'algoritmo di ordinamento usato in principio per ordinare le schede perforate, ma ai giorni nostri viene utilizzato per ordinare in base a più chiavi contemporaneamente (es: anno, mese e giorno)

###### Algoritmo
Dati:
- $n$ numeri
- ogni numero ha $h$ cifre
- ogni cifra può avere fino a $k$ valori

quello che fa questo algoritmo è ordinare rispetto considerando solo una cifra dei numeri, partendo da quella meno significativa.  La sua implementazione tramite pseudocodice è molto semplice ma implica anche l'implementazione di un algoritmo di ordinamento stabile interno per ordinare rispetto ad una cifra (per noi sempre il counting sort)

```
RadixSort(A, n, h)
	for i <= 0 to h = 1 do:
		countingSort(A, n, i)
```

###### Implementazione
Ricordiamo che le cifre di un numero si estraggo facendo il modulo 10 nel nostro caso la formula per calcolare una cifra di un numero alle i-esima posizione diventa $$(A[i] \backslash 10^h) \% 10$$
```C++
int scegliCifra(int numero, int digit){
    return (numero/(int)pow(10,digit))%10;
}

void countingSortConCifraSpecifica(int *A, int n, int cifra) {
    const int k = 9;
    int* B = new int[n];
    int* C = new int[k + 1];
    
    for(int j = 0; j <= k; j++)
        C[j] = 0;
        
    for(int j = 0; j < n; j++) {
        C[scegliCifra(A[j], cifra)] = C[scegliCifra(A[j], cifra)] + 1;
    }
  
    for(int j = 1; j <= k; j++)
        C[j] = C[j] + C[j-1];
     
    for(int j = n - 1; j >= 0; j--) {
        int d = scegliCifra(A[j], cifra);
        B[C[d] - 1] = A[j];
        C[d] = C[d] - 1;
    }

    for (int j = 0; j < n; j++) {
        A[j] = B[j];
    }

}

void radixSort(int* A, int len, int h){
    for(int i = 0; i < h; i++){
        countingSortConCifraSpecifica(A, len, i);
    }
}
```

###### Complessità
La sua complessità dipende dall'algoritmo di ordinamento usato al suo interno, nel nostro caso abbiamo usato il counting sort quindi abbiamo una complessità: $$O(h(n+k)) \in O(n)$$



## Lezione 7 - Dizionari e tabelle hash


# Tabelle Hash

### Introduzione alle Hash table
Introdurremo il concetto di Tabella Hash partendo da un problema di implementazione: dobbiamo implementare un dizionario. Quale è il modo migliore di farlo?
###### Cos'è un dizionario?
Un dizionario è un insieme su cui possiamo effettuare operazioni di:
- inserimento
- cancellazione 
- ricerca
Questa struttura dati viene usata principalmente per la ricerca. La ricerca di un elemento in un dizionario può portare a due esiti differenti:
* *Ricerca con successo*: ricerca di un elemento presente nella tabella
* *Ricerca senza successo*: ricerca di un elemento non-presente nella tabella.
######  Possibili implementazioni e complessità con strutture già note
* **Array non-ordinato**:
    * Inserimento: $O(1)$
    * Cancellazione: $O(1)$
    * Ricerca: $O(n)$
* **Array ordinato**:
    * Inserimento: $O(n)$
    * Cancellazione: $O(n)$
    * Ricerca: $O(\log n)$ Ricerca Binaria
* **Lista non-ordinata**:
    * Inserimento: $O(1)$
    * Cancellazione: $O(1)$
    * Ricerca: $O(n)$
* **Lista ordinata**:
    * Inserimento: $O(1)$
    * Cancellazione: $O(1)$
    * Ricerca: $O(n)$
* **BST**:
    * Inserimento: $O(\log n)$
    * Cancellazione: $O(\log n)$
    * Ricerca: $O(\log n)$
* **Tabella a Indirizzamento Diretto**:
    * Inserimento: $O(1)$
    * Cancellazione: $O(1)$
    * Ricerca: $O(1)$

### Tabelle a Indirizzamento Diretto
###### Definizione
Una tabella a indirizzamento diretto è una soluzione molto conveniente, nei casi in cui l'insieme universo $U$ (l'insieme di tutti i numeri registrabili) è un insieme relativamente **piccolo**. Una tabella a indirizzamento diretto avrà uno slot per ogni elemento $x \in U$. Ad ogni elemento è associata una chiave $k$, ovvero un indice della tabella a indirizzamento diretto.
###### Implementazione
*Inserimento*:
```
Insert(T,k)
	T[k] = 1
```

*Rimozione*:
```
Insert(T,k)
	T[k] = 0
```

*Ricerca:*
```
Search(T,k)
	IF T[k]=1
		RETURN true
	ELSE RETURN false
```
 Hanno tutte complessità $O(1)$
###### Svantaggi di questa struttura
Apparentemente, le tabelle a indirizzamento diretto sono perfette; tuttavia, esistono dei casi in cui non sono veramente consone, e in cui anzi, non possono essere proprio utilizzate:
* **Insieme U molto grande rispetto a K**: se l'insieme universo $U$ è molto grande, ma l'insieme $K$ delle chiavi da memorizzare è piccolo, la memoria da allocare sarà quasi del tutto sprecata. 
  ![[Pasted image 20251214113221.png|500]]
* **L'insieme universo è infinito.**
    Un calcolatore non ha memoria infinita, e una tabella a indirizzamento diretto ha bisogno di un numero finito di indici.

Per risolvere questi problemi e poter utilizzare le tabelle ad indirizzamento diretto e quindi i dizionari nascono le funzioni di **hash**, una funzione che assegna ad un valore una specifica chiave.

### Funzione hashing

###### Definizione
Il ruolo della funzione hashing (detta $h$) è quello di associare ad un elemento $k$ dell'insieme $S \subseteq U$, un indice della tabella hash. $$h: k \rightarrow T[h(k)]$$
In questo modo lo spazio richiesto da una **tabella Hash** (una tabella ad indirizzamento diretto ma che usa l'hashing) sarà ridotto a $\Theta(|K|)$,  quindi sarà uguale al numero di chiavi da memorizzare, molto di meno rispetto a $\Theta(|U|)$, riuscendo a conservare i vantaggi di una tabella ad indirizzamento diretto (ovvero la ricerca in $O(1)$)
###### Collisioni
La funzione $h(k)$, avendo solitamente un codominio di cardinalità inferiore al dominio, non è una funzione biunivoca. Per il *pigeonhole principle*, se gli elementi da inserire nella Hash Table sono più degli indirizzi, almeno due chiavi finiranno allo stesso indirizzo. Quando due chiavi finiscono nella stessa cella, abbiamo un fenomeno chiamato **collisione**, dall'evitare le collisioni nascono tutti modi per implementare una tabella hash.
### Implementazioni delle tabelle hash

Data una chiave $k$ sono tanti i metodi che possiamo utilizzare per indirizzare, di seguito ne vediamo alcuni.
###### Metodo della divisione
Dati:
- $k \in U$, 
- $h: U \rightarrow \{0,1,..,m-1\}$
$$h(k) = k \ mod \ m$$
![[Pasted image 20251214155300.png|500]]
Quando utilizziamo questo metodo evitiamo certi valori di $m$, per esempio non può essere una potenza di $2$, perché se $m = 2^p$ allora $h(k)$ allora la creazione delle chiave si baserà solo sui $p$ meno significativi e non su tutto il valore creando poca uniformità.
![[Pasted image 20251214155907.png|500]]

###### Metodo della moltiplicazione
Dati:
- $k \in U$
- $h: U \rightarrow \{0,1,..,m-1\}$ 
- e $0 < A < 1$
$$h(k)=\lfloor (k \cdot A \mod 1) m \rfloor$$
Spieghiamo il principio di di questo metodo:
1.  $k \cdot A$ ci ritorna un valore compreso tra 0 e $k$.
2. Il resto della divisione per 1 con un numero reale, ritornerà il valore della parte decimale, ottenendo un valore compreso tra 0 e 1, 1 escluso.
3. Moltiplicando per $m$, otteniamo valori compresi tra 0 e $m$, $m$ escluso.
4. La funzione *floor* ci permette di prendere solo la parte intera
In questo metodo il valore di $m$ non è critico, solitamente scegliamo una potenza di $2$ perché rende più veloce l'implementazione nei calcolatori moderni
### Risolviamo le collisioni usando l'hashing con concatenazione

###### Definizione
Nell'hashing con concatenazione poniamo tutti gli elementi che sono associati alla stessa cella in una lista concatenata. Praticamente la cella $j$ contiene un puntatore alla testa della list adi tutti gli elementi memorizzati che vengono mappati in $j$; se non c'è ne sono, la cella $j$ contiene la costante $NIL$

###### Implementazioni
*Inserimento:*
```
Insert(T,k)
	List-Insert(T[h(k)], k)
```
*Costo:* avrà $O(1)$ come l'inserimento in lista.

*Rimozione:*
```
Insert(T,k)
	List-Delete(T[h(k)], k)
```
*Costo:* avrà $O(1)$ come la cancellazione dalla lista.

*Ricerca:*
```
Search(T,k)
	RETURN List-Search(T[h(k)], k)
```
*Costo:* Il caso peggiore sarà quello in cui ogni elemento è inserito nella stessa posizione della tabella. $O(n)$, come la ricerca in una lista di $n$ elementi. Andiamo a studiare tuttavia il caso medio, introducendo il concetto di uniformità.

###### Analisi

> [!Attention]
> Data una tavola hash $T$ con $m$ celle dove sono memorizzati $n$ elementi, definiamo **fattore di carico** $\alpha$ della tavola $T$ il rapporto $\frac{n}{m}$, ossia il numero medio di elementi che memorizzati in una lista, la nostra analisi sarà fatta in funzione di $\alpha$ che può essere minore, uguale o maggiore di $1$. 

**Caso peggiore**: il comportamento nel caso peggiore dell'hashing con concatenamento è pessimo, tutte le chiavi vengono associate alla stessa cella, quindi stiamo lavorando praticamente con una lista, con tutte le inefficienze del caso ovvero: Ricerca in $\Theta(n)$

**Caso medio**: il comportamento nel caso medio dipende dal modo in cui la funzione hash distribuisce mediamente l'insieme delle chiavi da memorizzare tra le $m$ celle. Per adesso supponiamo che qualsiasi elemento abbia la stessa probabilità di essere mandato in un qualsiasi posizione. Questa ipotesi si chiama *Hashing uniforme semplice*. Se indichiamo con $n_j$ la lunghezza della lista $T[j]$ per $j = 0,1,\dots,m-1$ avremo $n = n_0+n_1+  \dots n_{m-1}$ da questo possiamo dire che la lunghezza media delle liste è: $$\alpha = \frac{n}{m}$$per fare un'analisi della complessità dobbiamo necessariamente distinguere due casi:
- **Ricerca senza successo**: una ricerca senza successo richiede un tempo di $\Theta(1+\alpha)$ nel caso medio
  *Dimostrazione*: Il tempo atteso per ricercare senza successo una chiave $k$ è il tempo atteso per svolgere ricerche fino alla fine della lista $T[h(k)]$ che ha lunghezza attesa di $\alpha$ quindi il tempo totale richiesto (incluso quello per calcolare $h(k)$ che ipotizziamo sia $O(1)$) è $$\Theta(1+\alpha)$$
- **Ricerca con successo**: una ricerca con successo richiede un tempo di $\Theta(1+\alpha)$ nel caso medio
  *Dimostrazione*: il numero di elementi esaminati durante una ricerca con successo di un elemento $x$ è uno in più del numero di elementi che si trovano prima di $x$ nella lista di $x$. Gli elementi prima di $x$ li troviamo facendo: $$1+\sum_{j=i+1}^{n}Pr(x_{ij})$$Ricordiamo che $Pr(x_{ij}) = \frac{1}{m}$. Dunque il numero atteso di elementi esaminati con successo è:$$\frac{1}{n} \sum^n_{i=1}(1+\sum^n_{j = n+1} Pr\{x_{ij}\})$$Di seguito la risoluzione:
	- Distribuiamo la sommatoria dentro la parentesi e sostituiamo $Pr\{x_{ij}\}$:$$\frac{1}{n}(\sum^n_{i=1}1+\sum^n_{i=1}\sum^n_{j = n+1}\frac{1}{m})$$
	- Riscrivo la prima sommatoria semplicemente come $n$ e sposto fuori la costante $\frac{1}{m}$: $$\frac{1}{n}(n+\frac{1}{m}\sum^n_{i=1}\sum^n_{j = n+1}1)$$
	- Riscrivo la sommatoria con $j$ come $n-i$: $$\frac{1}{n}(n+\frac{1}{m}\sum^n_{i=1}(n-i))$$
	- Riscrivo le sommatorie come differenza di sommatorie $$\frac{1}{n}\Big(n+\frac{1}{m}(\sum^n_{i=1} n \ -\sum^n_{j = n+1}i)\Big)$$
	- Risolvo le sommatorie $$\frac{1}{n}\Big(n+\frac{1}{m}(n^2-\frac{n(n+1)}{2})\Big)$$
	- Risolvo i calcoli rimanenti $$1+\frac{1}{mn}\Big(n^2-\frac{n(n+1)}{2}\Big) = 1 + \frac{n}{m} - \frac{n+1}{2m} \in O(1+\alpha)$$

### Risolviamo le collisioni usando l'hashing a indirizzamento aperto

###### Definizione
Un altro metodo che permette di risolvere le collisioni, è l'**indirizzamento aperto**. Supponiamo di avere una tabella con un numero $m$ di slot. Se cercando di effettuare un inserimento nella tabella, la posizione calcolata dalla funzione di hashing risulta già occupata, verrà calcolato e ispezionato un altro slot. Ciò avverrà fino a quando non si troverà uno slot libero (contenente **NULL** o **D**, ne parleremo dopo), o fino a quando non si saranno controllati tutti gli $m$ slot della tabella.

##### Sequenza di ispezione
La funzione di hashing all'interno di una tabella con indirizzamento aperto al posto di ritornare una singola posizione, sarà così definita:
$$h: U \times \{0,1,...,m-1\} \rightarrow \{0,1,....m-1\}$$
Definiamo **sequenza di ispezione** di una chiave $k$, la sequenza di indici che viene generata dalla funzione di hashing calcolata su $k$, ovvero:
$$\langle h(k, 0), h(k, 1),..., h(k,m-1) \rangle$$
La sequenza di ispezione conterrà tutti gli slot della tabella e rappresenta tutte le possibili posizioni che $k$ potrebbe prendere se non sono occupate.

###### Implementazioni funzioni di base
*Inserimento*
```
hash_insert(T, k)
    IF n = m
        RETURN // tabella piena
    i = 0
    WHILE (T[h(k, i)] != NULL AND T[h(k, i)] != D): //D spiegato in "Funzione di cancellazione"
        i = i + 1
    T[h(k, i)] = k
    n = n + 1
```
*Ricerca*
```
hash_search(T, k)
    i = 0
    WHILE T[h(k, i)] != NULL AND i < m: 
        IF T[h(k, i)] = k
            RETURN True
        i++
    RETURN False
```
##### Funzione di cancellazione
La funzione di cancellazione, all'interno di una tabella hash che risolve le collisioni tramite l'indirizzamento aperto, richiederà una modifica fondamentale per il funzionamento corretto della funzione di ricerca. Cancellato un elemento dalla tabella, esso non dovrà essere sostituito da **NULL**. Esso dovrà infatti essere contrassegnato come **D** di **DELETED**. L'esempio di seguito aiuta a capire perché usiamo $D$

**Esempio**:
- Prendiamo una tabella hash con $m=4$ contiene i numeri $[1, 2, 3, 5]$.
- Eliminiamo il numero 3 dalla tabella, ottenendo $[1, 2, \text{NULL}, 5]$.
- Calcoliamo la sequenza di ispezione della chiave 5 che sarebbe: 
	- $h(5,0)=1$
	- $h(5,1) = 0$
	- $h(5,2) = 2$
	- $h(5,3) = 3$
Supponiamo adesso di usare la funzione di ricerca per verificare la presenza (evidente) del numero 5

La ricerca si interromperà a $h(5,2)=2$. Ciò non sarebbe avvenuto prima dell'eliminazione del numero 3, ed è causato proprio dal NULL in posizione 2.

Contrassegnare lo slot con **DELETED** espliciterà il fatto che lo slot è libero in caso di inserimento, ma anche che la ricerca non andrà interrotta nonostante lo slot vuoto.

```
hash_delete(T, k)
    i <- 0
    WHILE (T[h(k, i)] != NULL AND i < m):
        IF T[h(k, i)] = k:
            T[h(k, i)] = DELETED
            RETURN True
        i = i + 1
    RETURN False
```

Essendo l'eliminazione abbastanza macchinosa usiamo l'indirizzamento aperto solo quando non dobbiamo eliminare elementi.
###### Requisiti di una funzioni hash per indirizzamento aperto
Dati:
- $P_m$ è l'insieme di tutte le permutazioni sull'insieme $\{0,...,m-1\}$. 
- La cardinalità di $P_m$ è $m!$.
Sia $p \in P_m$ una permutazione. La probabilità che $h(k)=p$ deve essere la stessa per qualsiasi permutazione.
$$Pr[h(k)=p]=\frac{1}{m!} \forall p \in P_m$$
Questa ipotesi si chiama **hashing uniforme**. Costruire funzioni hash per l'indirizzamento aperto che rispettino questa proprietà è piuttosto complesso. Successivamente vengono analizzate tre tecniche usate per creare la sequenza di ispezione

###### Analisi
La nostra analisi dell'indirizzamento aperto è espressa in termini del fattore di carico $\alpha = \frac{n}{m}$. Supponiamo venga applicata l'hashing uniforme quindi la sequenza $$\langle h(k, 0), h(k, 1),..., h(k,m-1) \rangle$$utilizzata per inserire o ricercare una chiave $k$ ha la stessa probabilità di essere una qualsiasi permutazione di $\langle 0,1,\dots,m-1 \rangle$.  Analizziamo il numero atteso di ispezioni dell'hashing con indirizzamento aperto, facendo differenza tra una ricerca con e senza successo:
**Ricerca senza successo**: data una tavola hash con un fattore di carico $\alpha = n/m < 1$ il numero atteso di ispezioni in una ricerca senza successo è al massimo $\frac{1}{1-\alpha}$
*Dimostrazione*: ![[Pasted image 20251214181345.png|600]]

**Ricerca con successo**: data una tavola hash con un fattore di carico $\alpha = n/m < 1$ il numero atteso di ispezioni in una ricerca senza successo è al massimo $\frac{1}{\alpha}\ln\frac{1}{1-\alpha}$
*Dimostrazione*: ![[Pasted image 20251214181414.png|600]]
### Tecniche per creare una sequenza di ispezione

###### Ispezione lineare
La funzione di hashing per la scansione lineare è definita in questo modo
$$h(k,i)=(h'(k)+i) \mod m$$
Con $h': U \rightarrow \{0,1,...,m-1\}$. Le sequenze della nostra funzione di hashing saranno del tipo
$$\langle h'(k),h'(k)+1 \ mod \ m ,h'(k)+2\ mod \ m,...,h'(k)+(m-1) \ mod \ m \rangle$$
Questa funzione di hashing non gode della proprietà di hashing uniforme, in quanto, le permutazioni ottenute non possono non iniziare con $h'(k)$. Moltissime permutazioni avranno probabilità $0$, e le restanti $\frac{1}{m}$. Un'altro problema di questo tipo di ispezione è l'**agglomerazione primaria**. In breve, la probabilità che le chiavi siano inserite in slot successivi aumenta ad ogni inserimento, favorendo agglomerati di chiavi e allungando le tempistiche relative alle operazioni.
![[Pasted image 20251214171538.png|700]]

###### Ispezione quadratica
Cambia solo la funzione di hashing e diventa: $$h(k,i) = (h'(x)+c_1+c_2i^2) \ mod \ m$$Con $c_1$ e $c_2$ costanti scelte in modo tale che l'intera tabella venga scansionata dalla funzione $h(k,i)$ ed evitare l'agglomerazione primaria.
###### Ispezione doppio hashing
In questa funzione vengono usate due funzione di hashing: $$h(k,i) = (h'(k)+ih''(k)) \ mod \ m$$Il numero totale di permutazioni totale è $m \times m = m^2$, in quanto la prima funzione di hashing da la prima posizione, la seconda le successive, e quindi $m$ possibili posizioni dopo altre $m$. 