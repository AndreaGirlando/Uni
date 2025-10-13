Rielaborazione del file [[1-Ricorsione.pdf]]

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