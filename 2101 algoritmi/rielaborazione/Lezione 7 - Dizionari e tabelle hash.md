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