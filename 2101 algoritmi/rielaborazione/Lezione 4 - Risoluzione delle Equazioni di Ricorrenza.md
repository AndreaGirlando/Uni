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
### Ricorrenze non uniformi
Non tutti gli algoritmi ricorsivi possono essere descritti mediante un'equazione del tipo: $$T(n) = aT(\frac{n}{b})+f(n)$$in cui il problema viene suddiviso in un numero costante di sotto-problemi. In molti casi reali, la dimensione dei sotto-problemi può variare a seconda dei dati.

###### Esempio - QuickSort
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