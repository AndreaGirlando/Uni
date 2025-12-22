# Ricorsione

### Introduzione alla ricorsione

###### La ricorsione
La **ricorsione** rappresenta uno dei concetti più eleganti e profondi della programmazione. Essa si fonda sull'idea che un problema complesso possa essere affrontato scomponendolo in sotto-problemi più semplici, ciascuno dei quali conserva la stessa natura e struttura del problema originario, ma su scala ridotta.

> [!TIP] Definizione
> Un **programma ricorsivo** è una funzione o una procedura che durante la propria esecuzione richiama se stessa per risolvere versioni sempre più piccole dello stesso problema

Questo meccanismo sembra apparentemente circolare, ma è in realtà estremamente potente a condizione che esista un punto di arresto ben definito: ovvero **la condizione base**

Un esempio classico di questo meccanismo è il calcolo del fattoriale di un numero intero non negativo $n$
![[Pasted image 20251012172214.png|500]]
in breve si afferma che per calcolare $n!$ non è necessario conoscere direttamente il risultato ma basta sapere come calcolare il fattoriale di un numero più piccolo $n-1$. Questa definizione *auto-riferita* è perfettamente lecita e diventa potente perché il caso base (quello sopra) interrompe la catena di richiami e garantisce la terminazione (cosa molto importante in un programma)

###### Fasi della ricorsione
Le fasi della ricorsione sono:
- **Fase di suddivisione**: del problema in sotto problemi di minore complessità
- **Fase di ricombinazione**: dei risultati parziali nella soluzione complessiva
Questa duplice operazione è ciò che rende la ricorsione tanto elegante quanto potente infatti permette di passare da una visione monolitica del calcolo a una visione *gerarchica e modulare* 

###### Definizioni ricorsive delle strutture dati
La ricorsione non riguarda solo gli algoritmi o le funzioni ma anche le **strutture dati**, di seguito degli esempi:
- **Lista**: non è altro che un *elemento iniziale* seguito da un'altra lista dello stesso tipo $$\text{Lista} = \begin{cases} \text{Lista vuota,} & \text{oppure} \\ (\text{Elemento, Lista}) & \text{se contiene almeno un elemento.} \end{cases}$$
-  **Array**: un array di lunghezza $n$ può essere definito come un elemento iniziale seguito da un array di lunghezza $n-1$: $$A_n = \{a_0\} \cup A_{n-1}$$
- **Alberi**: ogni nodo dell'albero può essere considerato come la radice di un nuovo albero, composto dai suoi sottoalberi$$\text{Albero} = \begin{cases} \text{nodo vuoto,} & \text{(albero nullo)} \\ (\text{valore, sottoalbero sinistro, sottoalbero destro}) & \text{(albero non vuoto).} \end{cases}$$
###### Struttura generale di un programma ricorsivo
Ogni programma ricorsivo si fonda su una struttura concettuale ben precisa, che ne garantisce la correttezza logica e la terminazione formata da:
1. **Il caso base**: il caso base è una condizione che ne interrompe la prosecuzione infinita di una ricorsione, matematicamente corrisponde alla condizione di terminazione dell'equazione definita ricorsivamente
2. **Il passo ricorsivo**: In questo punto la funzione richiama sé stessa per risolvere uno o più sotto problemi di dimensione minore, se indichiamo con $P$ il problema principale e con $P_1,P_2, \dots, P_K$ i sotto problemi derivati, il passo ricorsivo può essere espresso formalmente come: $$S = \text{Combina}(F(P_1), F(P_2), \dots, F(P_K))$$
3. **La combinazione dei risultati**: Una volta risolti i sotto problemi occorre un meccanismo per ricomporre le soluzioni parziali e ottenere la soluzione complessiva del problema principale. Questo processo detto fase di combinazione è spesso ciò che distingue una ricorsione semplice da una più sofisticata

Una funzione ricorsiva $F(n)$ può essere definita in modo generale nel seguente modo: ![[Pasted image 20251012180931.png|500]]
L'esecuzione di questo tipo di funzioni viene gestito automaticamente dallo *stack* che conserva lo stato di ciascuna chiamata, nel caso in cui la profondità di ricorsione non fosse finita si potrebbe incappare in problemi di *stack overflow*
Dal punto di vista operativo l'esecuzione di un programma ricorsivo può essere immaginata come una serie di scatole 

###### Dimensione del problema
Un aspetto cruciale nella progettazione di un algoritmo ricorsivo è la definizione della **dimensione del problema**, spesso indicata con la variabile $n$, in alcuni casi questa grandezza è intuitiva.

**Esempio**: nel calcolo del fattoriale o della potenza, la dimensione del problema $n$ coincide con un numero intero che viene progressivamente decrementato fino a raggiungere lo zero. 

La scelta del parametro che rappresenti la dimensione del problema non è una semplice formalità: essa influisce profondamente sul comportamento dell'algoritmo e sulla sua **complessità computazionale**


###### L'equazione di ricorrenza 
Ogni algoritmo ricorsivo possiede una propria **struttura quantitativa** che descrive come il costo del calcolo cresce in funzione delle dimensione del problema, questa struttura prende il nome di **equazione di ricorrenza**. 
Un'equazione di ricorrenza esprime il tempo di esecuzione di un algoritmo ricorsivo come funzione del tempo necessario per risolvere uno o più sotto problemi più piccoli più un termine che rappresenta il costo delle operazioni non ricorsive, la funzione del tempo per risolvere un problema di dimensione $n$ viene indicato con $T(n)$ ovvero:
$$T(n) = \Sigma_{i = 0}^{K} T(n_i)+f(n)$$
dove $T(n_i)$ rappresenta il tempo necessario per risolvere il sotto problema i-esimo (di dimensione $n_i<n$) e $f(n)$ rappresenta il tempo impiegato per la fase di divisione e riunificazione (le fasi che non comportano chiamate ricorsive)


###### Costruzione di una equazione di ricorrenza
Per costruire l'equazione di ricorrenza corrispondente a un algoritmo occorre osservare come esso si comporta rispetto alla dimensione del problema. Ogni chiamata ricorsiva può essere vista come un nodo dell'albero di ricorsione e il numero di nodi totali determina il tempo totale.

**Esempi**
- **Fattoriale**:  in questo algoritmo la ricorsione riduce la dimensione del problema di $1$ ad ogni chiamata (per ogni chiamata ricorsiva viene fatta una sola moltiplicazione) quindi la sua equazione di ricorrenza è: $T(n) = T(n-1)+O(1)$ risolvendo questa ricorrenza otteniamo che $T(n) = O(n)$ 
- **Somma di un array**: in un algoritmo che calcola la somma di una array dividendolo in due metà il tempo di esecuzione ha equazione: $$2T(\frac{n}{2})+O(i)$$ poiché ogni chiamata genera due sotto problemi di metà dimensione, è la fase di combinazione richiede solo un tempo costante per sommare i risultati. Risolvendola otteniamo sempre $T(n) = O(n)$ ma con una struttura di chiamate ricorsive estremamente diversa.
- **Merge sort**: in questo algoritmo ogni livello di ricorsione comporta una divisione in due sottoarray ma la fase di riunificazione (il merging) richiede un tempo lineare $O(n)$. L'equazione di ricorrenza corrispondente diventa quindi: $$T(n) = 2T(\frac{n}{2})+O(n) \rightarrow O(n \log n)$$
  Questo risultato è uno dei più noti nell'analisi algoritmica e mostra come la ricorsione possa amplificare o ridurre l'efficienza di un algoritmo.


### Applicazioni pratiche della ricorsione

Per comprendere a fondi il funzionamento della ricorsione, è utile analizzare alcuni analizzare alcuni esempi elementari ma emblematici, mostrano come un problema ricorsivo si risolve sempre creando le due fasi:
- **Fase di divisione**: il problema viene suddiviso in versioni più semplici
- **Fase di riunificazione**: le soluzioni vengono combinate per ottenere la soluzione finale

###### Il fattoriale
Il calcolo del **fattoriale** di un numero intero non negativo $n$ è forse l'esempio più iconico di funzione ricorsiva

> [!ATTENTION] Che cosa è un fattoriale
> Il fattoriale indicato con $n!$ rappresenta il prodotto di tutti i numeri interi positivi minori o uguali ad $n$

La sua definizione sottoforma di funzione ricorsiva è la seguente:$$n! = \begin{cases} 1 & \text{se } n = 0, \\ n \cdot (n - 1)! & \text{se } n > 0. \end{cases}$$
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
$$a \times b = \begin{cases} 0 & \text{se } b = 0, \\ a + (a \times (b - 1)) & \text{se } b > 0. \end{cases}$$
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
$$a^n = \begin{cases} 1 & \text{se } n = 0, \\ a \times a^{n-1} & \text{se } n > 0. \end{cases}$$
- **Fase di divisione**: consiste nel ridurre progressivamente l'esponente $n$ fino a raggiungere lo zero
- **Fase di riunificazione**: avviene moltiplicando ogni valore intermedio per $a$ nel momento in cui le chiamate ritornano

```
int potenza ( int a , int n ) { 
	if (n == 0) return 1; 
	else return a * potenza (a , n - 1)
}
```

L'albero di ricorsione per il calcolo di $2^4$ ha la seguente forma: ![[Pasted image 20251013093604.png]]
### Problemi di somma e soglia su array

###### Premessa
Gli array sono un ottimo terreno per mettere alla prova la ricorsione, soprattutto in contrapposizione ad una approccio iterativo. 
I problemi sugli array possono essere risolti in modo ricorsivo seguendo due schemi generali:
- **Ricorsione in coda**: in cui l'array viene ridotto progressivamente di un elemento alla volta
- **Doppia ricorsione**: in cui l'array viene suddiviso in due sotto array di dimensioni più piccole che vengono risolti e poi ricombinati
###### Somma dei valori di un array
Supponiamo di avere un array di interi, il nostro obbiettivo è quello di scrivere una procedura in grado di restituire per qualsiasi array $A$ di dimensione $n$, il valore:
$$S(A,n) = \Sigma_{i = 0}^{n-1}A[i] \text{ somma di n numeri di un array}$$
Si tratta di un problema apparentemente semplice ma utile per comprendere la differenza tra un approccio **iterativo** e **ricorsivo**:

- **Approccio iterativo**: supponendo di avere un array di $n$ elementi ci basta scorrere l'array da destra verso sinistra e accumulando progressivamente il valore in una variabile che chiameremo **somma**
```cpp
int sommaIterativa(int A[], int n) {
    int somma = 0;
    for (int i = 0; i < n; i++) {
        somma += A[i];    // accumula il valore corrente
    }
    return somma;
}
```

---

- **Approccio ricorsivo**: per usare un approccio ricorsivo dobbiamo scomporre il problema in problemi più piccoli, ciò significa nel caso della somma dobbiamo immaginare l'azione di scorrimento iterativo dell'array come una funzione che richiama ste stessa su versioni ridotte dello stesso array, questa cosa si può fare in due modi:
1. *Ricorsione di coda*: usando al ricorsione in coda definiamo $S$ come: $$S(A, n) = \begin{cases} A[0] & \text{se } n = 1, \\ A[n-1] + S(A, n-1) & \text{se } n > 1. \end{cases}$$*Fase di divisione*: consiste nel passare da un array di $n$ elementi a uno di $n-1$
   *Fase di riunificazione*: consiste nel sommare il valore corrente $A[n-1]$ al risultato ottenuto ricorsivamente
```cpp
int somma(int A[], int n) {
    if (n == 1)
        return A[0];                   // caso base
    else
        return A[n-1] + somma(A, n-1); // divisione e riunificazione
}
```
*Albero di ricorsione*: la complessità dell'albero di ricorsione è $n$ e ogni chiamata ricorsiva genera una sola nuova chiamata quindi la complessità temporale è $O(n)$.

2. *Doppia ricorsione* : usando la doppia ricorsione definiamo $S$ come: $$S(A, n) = \begin{cases} A[0] & \text{se } n = 1, \\ S(A_{\text{sx}}, n/2) + S(A_{\text{dx}}, n/2) & \text{se } n > 1. \end{cases}$$
- *Fase di divisione*: suddivide il problema in due sotto problemi di dimensione $n/2$
- *Fase di riunificazione*: consiste nel sommare i due risultati parziali
```cpp
int sommaDivisa(int A[], int inizio, int fine) {
    if (inizio == fine)
        return A[inizio]; // caso base
        
    int medio = (inizio + fine) / 2;
    int sinistra = sommaDivisa(A, inizio, medio);    // divisione 1
    int destra   = sommaDivisa(A, medio + 1, fine); // divisione 2
    
    return sinistra + destra; // riunificazione
}
```
*Albero di ricorsione*: L'albero di seguito è bilanciato e completo con profondità $\log_2n$ questo ci indica una complessità temporale complessiva è: $T(n) = 2T(\frac{n}{2})+O(1)$ ![[Pasted image 20251013163705.png|700]]

---

###### Verificare se la somma supera una soglia
Vogliamo stabilire se la somma degli elementi di un array $A$ supera una certa soglia $T$  e vogliamo come risultato un esito logico $\text{true\\false}$, quello che facciamo è facciamo scorrere la soglia $T$ verso il basso man mano che consumiamo l'array: a ogni passo sottraiamo l'ultimo elemento e chiediamo se la somma rimanente super la nuova soglia 

```cpp
bool supera(int A[], int n, int T) {
    if (T < 0) 
        return true;  // soglia gia' superata
    if (n == 0) 
        return false; // array esaurito, soglia non superata
        
    return supera(A, n - 1, T - A[n - 1]);
}
```
- *Fase di divisione*: il problema viene suddiviso in problemi più piccoli con una soglia sempre più bassa
- *Fase di riunificazione*: il valore dell'ultima chiamata ricorsiva risale

È naturale chiedersi se un approccio a doppia ricorsione possa offrire vantaggi, ma in questo caso la risposta è no, infatti se si suddividesse l'array in due sotto array ciascuna chiamata fornirebbe la risposta "la sinistra da sola non supera $T$" che non ci dice nulla sull'esito finale che dipende da $\text{sinistra+destra}$, ne consegue che la ricorsione binaria in forma puramente booleana è insufficiente e quindi si dovrebbe complicare il tutto per renderla funzionante

*Quando l'obiettivo è un esito booleano con possibile arresto anticipato, la ricorsione lineare con soglia residua è la forma più naturale chiara ed efficace*

### Approccio ricorsivo e iterativo

###### Analisi
Dopo aver analizzato vari esempi di funzioni ricorsive e la loro costruzione passo dopo passo, è naturale chiedersi quale sia la differenza sostanziale tra un approccio ricorsivo e uno iterativo:
- **Ricorsione**: 
	- *Concettualmente*: rappresenta un modo di ragionare *dall'altro verso il basso*, infatti parte dalla formulazione del problema generale e lo scompone in sotto problemi più piccoli
	- *Computazionalmente*:  richiede una quantità di memoria proporzionale alla profondità della ricorsione
- **Iterazione**: 
	- *Concettualmente*: rappresenta il modo di ragionare *dal basso verso l'alto*, la soluzione viene costruita passo passo mantenendo esplicitamente lo stato intermedio della computazione
	- *Computazionalmente*:  usa una quantità di memoria costante poiché le variabili utilizzate vengono riutilizzate a ogni passo.
Le funzioni ricorsive hanno molto spesso una maggiore *chiarezza espressiva* e questo permette una ottima *modularità*, naturalmente presenta anche dei *limiti pratici*, come quando la profondità di una chiamata è molto grande o anche nella gestione dei bug durante la fase di debug.
