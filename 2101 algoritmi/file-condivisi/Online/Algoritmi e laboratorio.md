# Lezione 1: La Ricorsione e gli Algoritmi di Ordinamento

## Introduzione alla Ricorsione
Durante tutto il corso di questo insegnamento, la ricorsione sarà una caratteristica ricorrente e fondamentale. Riconoscere la ricorsione è semplice: ci troviamo di fronte a essa quando una funzione chiama sé stessa. Tuttavia, questa definizione, sebbene corretta, non è completa.

Un esempio classico, utile per comprendere la filosofia dietro questo concetto, riguarda **Richard Stallman**, il fondatore del progetto **GNU**. GNU è un movimento e un'associazione per il software libero. Stallman, considerato "l'ultimo degli hacker" nell'accezione positiva del termine (ossia un esperto di tecnologia che mette le sue capacità a beneficio della comunità), fondò il movimento basandosi proprio su un concetto ricorsivo.
Quando si cerca il significato di GNU (al di là del simbolo dello gnu come animale), si scopre che in quel periodo il software libero era legato principalmente al sistema operativo Unix. Molti identificavano il movimento "open" con Unix, ma Stallman voleva distanziarsene. Scelse quindi un nome che fosse un acronimo ricorsivo: **GNU is Not Unix**.
Questo acronimo contiene sé stesso al suo interno, creando un ciclo infinito nella definizione. Questo riflette perfettamente il concetto informatico: una funzione ricorsiva richiama sé stessa.

### La Dimensione del Problema e il Caso Base
Affinché una funzione ricorsiva sia valida e non generi un ciclo infinito (come nell'acronimo), è necessario individuare un valore che identifichi la **dimensione del problema**.
Non esiste un modo unico per assegnare questa dimensione: possiamo usare la fantasia, ma è fondamentale rispettare una regola: **la chiamata ricorsiva deve avvenire su un problema dello stesso tipo identico, ma di dimensione più piccola.**

Man mano che si effettuano le chiamate, la dimensione del problema deve ridursi. Questo processo di riduzione permette, automaticamente, di arrivare a un problema così piccolo da non richiedere ulteriore tempo per essere risolto, poiché la soluzione è banale e già nota. Questo punto di arrivo è il **Caso Base**.

Concettualmente, abbiamo quindi dei punti fermi:
1.  La funzione richiama sé stessa.
2.  Il problema viene suddiviso in uno o più problemi dello stesso tipo, ma di dimensione minore.
3.  Si raggiunge un caso base risolvibile immediatamente.

## Lo Schema Generale della Risoluzione Ricorsiva
Possiamo formalizzare l'approccio ricorsivo attraverso uno schema generale composto da tre fasi fondamentali:

1.  **Suddivisione (Divide):** È il primo passo. Si spezza il problema originale in uno o più sottoproblemi dello stesso tipo, ma di dimensione più piccola. Questa fase può avere un costo computazionale o essere immediata.
2.  **Risoluzione (Conquer):** Si risolvono i sottoproblemi. Quando si progetta un algoritmo ricorsivo, non bisogna preoccuparsi di *come* questi sottoproblemi vengano risolti internamente; bisogna immaginare che l'approccio ricorsivo (o il computer) ci fornisca le soluzioni "per magia". È una sorta di atto di fede: le soluzioni dei sottoproblemi sono considerate già pronte.
3.  **Unione (Combine):** Una volta ottenute le soluzioni dei sottoproblemi, dobbiamo trovare un modo per unirle in un'unica soluzione finale, che sarà la risposta al problema originale.

Lo schema logico è quindi:
*   *Divide* (Suddivisione)
*   *Risoluzione Ricorsiva* (sui sottoproblemi $P_1, P_2, \dots, P_k$)
*   *Unione* (Creazione della soluzione $S$ a partire da $S_1, S_2, \dots, S_k$)

È importante ricordare la regola aurea: **Suddividere, non risolvere**. La nostra mente deve concentrarsi sulla strategia di divisione e unione, non sulla riesecuzione manuale della ricorsione.

### Esempi Matematici
Un esempio classico è il **Fattoriale**:
$$F(n) = n! = 1 \times 2 \times 3 \times \dots \times n$$
In termini ricorsivi:
*   **Caso base:** se $n=1$, il risultato è 1.
*   **Passo ricorsivo:** se $n>1$, il risultato è $n \times F(n-1)$.

Altri esempi includono:
*   **Moltiplicazione** ($x \times y$): può essere vista come $y + (x \times (y-1))$ (sommare $y$ a sé stesso $x$ volte).
*   **Elevamento a potenza** ($y^x$): può essere definito come $y \times y^{x-1}$, con caso base $x=0$ che restituisce 1.

## Strutture Dati Ricorsive
Una volta acquisita dimestichezza, si scopre che molte strutture dati hanno una natura intrinsecamente ricorsiva.

### Albero Binario di Ricerca (BST)
Un albero binario di ricerca è una struttura posizionale dove ogni nodo ha al più due figli, ben distinti in figlio sinistro e figlio destro.
La definizione stessa di BST è ricorsiva:
*   **Caso base:** Un albero vuoto (NULL) è un BST.
*   **Passo ricorsivo:** Un nodo è un BST se ha un valore, un sotto-albero sinistro che è un BST (con elementi più piccoli) e un sotto-albero destro che è un BST (con elementi più grandi).

### Array
Anche gli array possono essere interpretati ricorsivamente. Un array può essere visto come:
*   Una cella iniziale (testa).
*   Concatenata a un array più piccolo (coda/resto dell'array).
Oppure come un array vuoto (caso base).
Questa visione permette di applicare algoritmi ricorsivi direttamente sulla struttura dati array, riducendo la dimensione del problema a ogni passo (passando da un array di dimensione $N$ a uno di dimensione $N-1$).

---

## Analisi degli Algoritmi di Ordinamento Ricorsivi

Sfruttando la natura ricorsiva degli array, possiamo analizzare vari algoritmi di ordinamento.

### Selection Sort Ricorsivo
Il **Selection Sort** seleziona l'elemento più piccolo (o più grande) e lo mette nella prima posizione disponibile.
*   **Logica:** Trovare il minimo nel sotto-array corrente e scambiarlo con l'elemento in prima posizione. Poi richiamare la funzione sulla parte rimanente dell'array ($N-1$).
*   **Analisi:**
    *   La **Suddivisione** ha un costo elevato: bisogna scorrere tutto l'array per trovare il minimo (o il massimo).
    *   L'**Unione** è a costo zero (o quasi): basta effettuare lo scambio.
    *   La ricorsione avviene sulla dimensione $N-1$ (tail recursion).

Questo approccio è semanticamente identico alla versione iterativa, ma la forma ricorsiva può apparire più elegante.

### Insertion Sort Ricorsivo
L'**Insertion Sort** presuppone che la parte a sinistra dell'elemento corrente sia già ordinata e inserisce il successivo elemento nella posizione corretta.
*   **Logica:**
    1.  Ordinare ricorsivamente la parte sinistra ($N-1$ elementi).
    2.  Inserire l'ultimo elemento ($N$-esimo) nella posizione corretta all'interno della parte già ordinata.
*   **Analisi:**
    *   La **Suddivisione** non ha costo (si passa semplicemente la chiamata ricorsiva su $N-1$).
    *   L'**Unione** ha un costo elevato: bisogna scorrere la parte ordinata per inserire l'elemento, spostando gli altri.
*   **Confronto col Selection Sort:** Qui la situazione è ribaltata. Nel Selection Sort la difficoltà era nella suddivisione (trovare il minimo), mentre nell'Insertion Sort la suddivisione è gratis ma l'unione è costosa.

### Merge Sort e Quicksort
Questi due algoritmi nascono naturalmente con una struttura ricorsiva e utilizzano un approccio *Divide et Impera* più bilanciato (spesso dividendo a metà, $N/2$).

1.  **Merge Sort:**
    *   Divide l'array in due metà uguali.
    *   Ordina ricorsivamente le due metà.
    *   Unisce (*Merge*) i due array ordinati in un unico array ordinato.
    *   **Costi:** La suddivisione è gratis (o quasi, calcolo dell'indice mediano). L'unione è la parte costosa e difficile (algoritmo di merge).
    *   **Memoria:** Non è un algoritmo *in loco* (in-place); richiede memoria aggiuntiva per l'array di appoggio durante il merge.

2.  **Quicksort:**
    *   Sceglie un perno (*pivot*) e partiziona l'array in due parti: elementi più piccoli del pivot ed elementi più grandi.
    *   Ordina ricorsivamente le due parti.
    *   **Costi:** La suddivisione (*Partition*) è la parte costosa e complessa. L'unione è a costo zero (gli elementi sono già al loro posto relativo).
    *   **Memoria:** È un algoritmo **in loco**; scambia gli elementi direttamente nell'array originale senza richiedere array ausiliari lineari (sebbene usi lo stack di ricorsione).
    *   **Nota:** Sebbene nel caso peggiore il Quicksort abbia complessità $O(N^2)$, in pratica è spesso più veloce del Merge Sort perché lavora in loco e ha costanti moltiplicative basse.

---

## Caratteristiche degli Algoritmi: Stabilità e Adattività

Per completare il quadro, analizziamo due proprietà fondamentali degli algoritmi di ordinamento.

### 1. Stabilità
Un algoritmo si dice **stabile** se ha la capacità di mantenere l'ordinamento relativo degli elementi che hanno la stessa chiave (lo stesso valore).
*   **Esempio:** Immaginiamo una coda al pronto soccorso dove i pazienti hanno un codice di priorità (rosso, giallo, verde) ma anche un ordine di arrivo temporale. Se devo ordinare per priorità, un algoritmo stabile garantirà che, tra due codici "giallo", quello arrivato prima rimanga davanti a quello arrivato dopo.
*   **Classificazione:**
    *   **Stabili:** Insertion Sort, Merge Sort, Selection Sort (nota: il Selection Sort standard solitamente non è stabile, ma in alcune implementazioni o varianti didattiche può essere considerato tale o reso tale; il testo lo classifica come stabile).
    *   **Non Stabili:** Quicksort (gli scambi durante la partizione possono alterare l'ordine relativo di chiavi uguali).

### 2. Adattività
Un algoritmo si dice **adattivo** quando riesce ad adattarsi all'input fornito, sfruttando l'eventuale ordinamento parziale già presente per ridurre il lavoro.
*   **Insertion Sort:** È l'esempio principe di algoritmo adattivo. Se l'array è già ordinato, la sua complessità scende a $O(N)$ (lineare), perché il ciclo interno di inserimento termina subito.
    *   La complessità può essere espressa come $O(N \cdot K)$, dove $K$ è la distanza massima di un elemento dalla sua posizione finale corretta. Se gli elementi sono vicini alla loro posizione finale, l'algoritmo è velocissimo.
*   **Selection Sort, Merge Sort, Quicksort:** Non sono adattivi. Il Selection Sort, ad esempio, deve comunque scorrere tutto l'array per trovare il minimo, anche se l'array è già ordinato. La loro complessità rimane legata al caso medio o peggiore indipendentemente dallo stato iniziale dei dati (es. $N^2$ o $N \log N$).


Ecco una rielaborazione completa, corretta e ben formattata del contenuto delle dispense. Il testo è stato riorganizzato per garantire fluidità e coerenza logica, mantenendo inalterati i concetti originali e lo stile espositivo della lezione.

---

# Lezione 2: Ricorsione, Analisi della Complessità e Problemi di Ottimizzazione

## 1. Riepilogo e Confronto: Mergesort e Quicksort

Nella lezione precedente abbiamo introdotto due algoritmi di ordinamento fondamentali, puramente ricorsivi: il **Mergesort** e il **Quicksort**. Abbiamo analizzato lo schema logico che permette di passare da un problema $B$ alla sua soluzione attraverso la scomposizione in $K$ sotto-problemi. Questi sotto-problemi, pur essendo della stessa natura del problema originale, sono di dimensioni ridotte.

La logica ricorsiva prevede una chiamata su un'istanza più piccola del problema, procedendo fino al raggiungimento di un **caso base**. Il caso base rappresenta un'istanza del problema sufficientemente piccola da poter essere risolta in maniera istantanea, senza necessità di ulteriori calcoli complessi (solitamente quando la dimensione dell'input è 0 o 1). Una volta risolti i casi base, le soluzioni vengono ricombinate.

È fondamentale comprendere che, nell'approccio ricorsivo, non dobbiamo preoccuparci ossessivamente di *come* vengano risolti i sotto-problemi: essi vengono risolti "in automatico", quasi per magia. Possiamo tracciare un parallelo con il **principio di induzione matematica**:
1.  Dimostriamo che una proprietà è vera per un caso base (es. 0 o 1).
2.  Supponiamo che sia vera per $n-1$ (ipotesi induttiva).
3.  Dimostriamo che, data la veridicità per $n-1$, essa vale anche per $n$.

Nella ricorsione applichiamo una logica simile: suppongo di avere un metodo che risolva il problema per tutti i valori $T$ più piccoli di $P$. Se riesco a trovare una soluzione per $P$ combinando le soluzioni dei sotto-problemi, ho trovato l'algoritmo generale.

### Differenze strutturali tra Mergesort e Quicksort
Sebbene entrambi utilizzino la ricorsione, affrontano il problema con approcci simmetrici opposti riguardo alle fasi di "suddivisione" e "fusione":

*   **Mergesort:** La fase di suddivisione è immediata (tempo costante), poiché taglia semplicemente l'array a metà. Tuttavia, "spende" tutto il tempo di calcolo nella fase di unione (merge) delle soluzioni ordinate.
*   **Quicksort:** Spende la maggior parte del tempo nella fase di suddivisione (partitioning), dove ordina gli elementi rispetto a un pivot. La ricomposizione delle soluzioni, invece, è "gratis" (tempo costante), poiché l'array risulta già ordinato alla fine delle chiamate ricorsive.

Inoltre, il **Quicksort** ha una complessità nel caso peggiore di $O(n^2)$ ma può essere eseguito *in loco* (senza memoria extra significativa), mentre il **Mergesort** ha una complessità di $O(n \log n)$ ma richiede memoria ausiliaria (non è in loco).

---

## 2. La Ricorsione sugli Array: Il Problema della Somma

Iniziamo ad affrontare problemi semplici basati su array utilizzando la ricorsione. Un array è, per sua natura, una struttura dati ricorsiva: può essere visto come una cella collegata a un altro array (il resto degli elementi). Tecnicamente, questo "sotto-array" può essere vuoto.

Solitamente, gli approcci ricorsivi sugli array non fanno altro che dividere la struttura in sotto-array fino ad arrivare a definire dei sotto-problemi banali. Prendiamo come esempio il problema della **somma degli elementi di un array**.

### Approccio Ricorsivo
Per sommare gli elementi in modo ricorsivo, dobbiamo ridurre la dimensione del problema ($n$) di una unità alla volta.
*   **Caso base:** Quando l'array è vuoto (o $n=0$), la somma è 0.
*   **Passo ricorsivo:** Se $n > 0$, il risultato è dato dall'ultimo elemento dell'array sommato al risultato della chiamata ricorsiva sui restanti $n-1$ elementi.

In questo caso specifico, sia la fase di suddivisione (ridurre $n$ a $n-1$) sia la fusione (addizionare un numero alla somma parziale) hanno **tempo costante**. Non ci sono cicli complessi all'interno della singola chiamata; l'algoritmo scorre semplicemente fino alla fine.

---

## 3. L'Albero di Ricorsione

Per visualizzare e comprendere le dinamiche di risoluzione, introduciamo il concetto di **Albero di Ricorsione**. Si tratta di una struttura ad albero dove ogni nodo rappresenta una chiamata ricorsiva effettuata durante la computazione.

Immaginiamo di sommare un array con i valori `[1, 4, 2, 3, 1, 2, 3]`.
L'albero avrà una radice (chiamata principale con $n=7$) che chiama un figlio ($n=6$), che a sua volta chiama $n=5$, e così via, fino al caso base. Ogni cerchio nell'albero rappresenta una chiamata: al suo interno visualizziamo la dimensione dell'array o l'operazione corrente. Risalendo l'albero (fase di ritorno), sommiamo i numeri.

### Gestione della Memoria e Stack
Un aspetto critico evidenziato dall'albero di ricorsione è l'uso della memoria. Ogni chiamata ricorsiva occupa spazio nello **Stack** di sistema.
*   Il calcolatore scende lungo l'albero ed esegue le chiamate.
*   Poi risale sommando i valori.
*   Lo spazio occupato nello stack è **proporzionale al numero di chiamate attive**.

Se il numero di chiamate è molto elevato, questo spazio potrebbe diventare proibitivo, portando a un errore di *Stack Overflow*. L'utente non deve mai dare in input un array vuoto se non gestito, altrimenti la funzione potrebbe non terminare correttamente o dare errore subito.

### Ricorsione di Coda (Tail Recursion)
Esiste una tecnica per mitigare il problema dello spazio: la **Ricorsione di Coda**. Si verifica quando la chiamata ricorsiva è l'ultima istruzione eseguita dalla funzione. In questo caso, molti compilatori possono ottimizzare il codice trasformandolo, di fatto, in un ciclo iterativo ("srotolando" la ricorsione), risparmiando spazio sullo stack. L'esempio della somma può essere facilmente scritto in questa forma.

---

## 4. Esempio Avanzato: "Somma-Bound"

Analizziamo una variante del problema precedente: **Somma-Bound**.
Vogliamo sapere se la somma degli elementi di un array supera un certo limite $\delta$ (Delta). La funzione deve restituire `Vero` o `Falso`.

*   **Soluzione Iterativa:** Sommiamo gli elementi e, non appena la somma parziale supera $\delta$, ci fermiamo e restituiamo `Vero`. È inutile continuare a scorrere l'array.
*   **Soluzione Ricorsiva:** Possiamo vedere il problema in modo sottrattivo. Invece di sommare a una variabile accumulatore, sottraiamo il valore dell'elemento corrente da $\delta$.
    *   Se $\delta$ diventa $\le 0$, restituiamo `True` (il limite è stato superato).
    *   Se l'array finisce e $\delta > 0$, restituiamo `False`.

In questo scenario, l'albero di ricorsione può essere più corto rispetto alla somma completa. La ricorsione si arresta non appena il caso base "limite raggiunto" viene soddisfatto. Il risultato booleano (`True`) si propaga verso l'alto attraverso tutte le chiamate precedenti. Possiamo dire che "gioca tutto l'ultima chiamata": essa determina il risultato che viene poi passato a catena fino alla radice.

Se invece la somma totale non supera mai il limite, l'algoritmo dovrà esplorare tutto l'albero fino alla fine, esattamente come nella somma classica.

---

## 5. Equazioni di Ricorrenza e Analisi della Complessità

L'albero di ricorsione ci fornisce un'idea intuitiva della complessità, ma per un'analisi formale utilizziamo le **Equazioni di Ricorrenza**. Un'equazione di ricorrenza è una formula matematica che descrive il tempo di esecuzione $T(n)$ di un algoritmo ricorsivo in funzione della dimensione dell'input $n$.

### Analisi dell'algoritmo "Somma"
Per l'algoritmo che somma gli elementi di un array staccando un elemento alla volta:
1.  Prendo un elemento (tempo costante).
2.  Risolvo il problema su $n-1$ elementi.
3.  Sommo il risultato (tempo costante).

L'equazione è:
$$T(n) = T(n-1) + O(1)$$

Per risolverla, applichiamo la sostituzione iterativa:
$$T(n) = T(n-1) + 1$$
$$= (T(n-2) + 1) + 1 = T(n-2) + 2$$
$$...$$
$$= T(n-k) + k$$

Arrivando al caso base dove $n-k=0$ (quindi $k=n$), e sapendo che $T(0)$ è una costante (o zero), otteniamo:
$$T(n) = T(0) + n \approx n$$
Quindi la complessità è **$O(n)$** (lineare).

### Analisi del Mergesort
Per algoritmi "divide et impera" come il Mergesort, l'equazione cambia.
Supponiamo di dividere il problema in due parti uguali:
$$T(n) = 2T(n/2) + m$$
Dove:
*   $2T(n/2)$ rappresenta le due chiamate ricorsive su metà dell'input.
*   $m$ (o un termine proporzionale a $n$) rappresenta il costo lineare per la fusione (merge) dei risultati.

Se visualizziamo l'albero di ricorsione del Mergesort:
*   La radice ha dimensione $n$.
*   Il livello successivo ha 2 nodi di dimensione $n/2$.
*   Il livello successivo ha 4 nodi di dimensione $n/4$.
*   L'albero continua a ramificarsi fino alle foglie (dimensione 1).

L'altezza dell'albero è logaritmica ($O(\log n)$), e ad ogni livello il lavoro totale di fusione è proporzionale a $n$. Quindi la complessità totale è $O(n \log n)$.

**Nota sull'implementazione:** Quando dividiamo un array di dimensione dispari, usiamo le funzioni *floor* e *ceiling* per gestire gli indici (es. da $0$ a $m$ e da $m+1$ a $n-1$). I casi base fondamentali sono array di dimensione 0, 1 (già ordinati) o 2 (facilmente ordinabili). È importante gestire correttamente gli indici per evitare ricorsioni infinite su array di 2 elementi.

### Complessità Spaziale del Mergesort
Sebbene l'albero di ricorsione raddoppi il numero di nodi a ogni livello scendendo verso il basso, le chiamate non avvengono tutte contemporaneamente in parallelo. La visita è sequenziale ("in-order"). Quando il calcolatore scende in un ramo, risolve quel sotto-problema e poi ritorna al genitore, liberando lo stack.
Di conseguenza, in ogni istante, viene mantenuto aperto nello stack solo un ramo che va dalla radice a una foglia. La complessità spaziale relativa allo stack delle chiamate dipende quindi dall'altezza dell'albero, che è **$O(\log n)$**.

*Attenzione:* Il Mergesort standard richiede comunque un array ausiliario per la fusione, portando l'occupazione totale di memoria a $O(n)$, ma per quanto riguarda il solo stack di ricorsione, il costo è logaritmico.

---

## 6. Il Teorema Master e Problemi Complessi

Per risolvere equazioni di ricorrenza nella forma $T(n) = aT(n/b) + f(n)$, esiste uno strumento potente chiamato **Teorema Master**. Esso fornisce una "ricetta" per determinare la complessità asintotica basandosi sui parametri $a$, $b$ e sulla funzione $f(n)$, coprendo la stragrande maggioranza (99,9%) dei casi che incontreremo.

Ora spostiamo l'attenzione su problemi dove la strategia ricorsiva è meno banale.

### Il Problema dello Zaino (Knapsack Problem)
Immaginiamo di essere Lupin e di entrare in un museo per rubare degli oggetti. Abbiamo uno zaino con una **capienza massima $K$** (peso massimo trasportabile). Nel museo ci sono vari oggetti, ognuno con un proprio peso.

#### Variante 1: Oggetti con Valore Uguale
Supponiamo che tutti gli oggetti abbiano lo stesso valore (es. sono tutti lingotti d'oro identici, ma di peso diverso). L'obiettivo è massimizzare il numero di oggetti portati via senza superare il peso $K$.

**Strategia (Approccio Greedy):**
In questo caso, la strategia migliore è semplice e intuitiva: prendiamo gli oggetti partendo da quello che pesa meno. Ordinando gli oggetti dal più leggero al più pesante, inseriamo tutto ciò che ci sta.
Possiamo formalizzare questo approccio ricorsivamente:
*   Ordino gli oggetti (o assumo di averli ordinati).
*   Prendo il primo elemento (il più leggero).
*   Se il suo peso è $\le K$, lo metto nello zaino e risolvo il problema per $n-1$ con capacità ridotta ($K - peso$).
*   Se pesa più di $K$, non posso prenderlo (e nemmeno quelli successivi, essendo più pesanti).

#### Variante 2: Oggetti con Valore Diverso
La situazione si complica se ogni oggetto $i$ ha un peso $P(a_i)$ e un **valore $V(a_i)$ diverso**. L'obiettivo è massimizzare il valore totale (guadagno dalla vendita) rispettando il vincolo di peso $K$.
Qui la strategia "prendo il più leggero" non funziona (potrei prendere tante pietre leggere che valgono zero e lasciare un diamante pesante che vale moltissimo). Nemmeno "prendo quello che vale di più" funziona sempre (potrebbe riempire tutto lo zaino impedendomi di prendere altri oggetti che, sommati, varrebbero di più).

**Approccio Ricorsivo (Massimizzazione):**
Dobbiamo esplorare le combinazioni possibili. Per ogni oggetto, abbiamo due scelte:
1.  **Non prenderlo:** Il valore ottenuto è uguale al risultato della chiamata ricorsiva sugli oggetti restanti ($n-1$) con la stessa capacità $K$.
2.  **Prenderlo (solo se entra, $Peso \le K$):** Il valore è il valore dell'oggetto corrente PIÙ il risultato della chiamata ricorsiva sugli oggetti restanti ($n-1$) con capacità ridotta ($K - Peso$).

La funzione ricorsiva dovrà restituire il **massimo** tra queste due possibilità.
Definiamo la funzione $Zaino(n, K)$:
*   **Caso base:** Se $n=0$ o $K=0$, il valore è 0.
*   **Passo ricorsivo:**
    $$Result = \max( Zaino(n-1, K), \quad Valore[n] + Zaino(n-1, K - Peso[n]) )$$
    *(Nota: La seconda opzione è valida solo se $Peso[n] \le K$)*.

Stiamo calcolando un valore numerico ottimale. Se $K$ diminuisce, il problema si riduce. Se $n$ diminuisce, il problema si riduce. Abbiamo definito matematicamente la soluzione e l'abbiamo tradotta in un algoritmo che esplora l'albero delle decisioni (prendere o lasciare) per trovare l'ottimo globale.

Ecco una rielaborazione completa, corretta e ben formattata del contenuto del PDF. Il testo è stato strutturato come un capitolo di un libro di testo per garantire fluidità e chiarezza, unendo gli appunti manoscritti alle spiegazioni testuali.

***

# Lezione 3: Analisi del Costo di un Algoritmo e Notazioni Asintotiche

## 1. Introduzione: L'importanza della crescita
L'analisi degli algoritmi si occupa di determinare l'efficienza di una procedura informatica. Quando parliamo di costo di un algoritmo, indicato con la funzione $T(n)$, non ci riferiamo al tempo fisico in secondi, ma al numero di passi elementari eseguiti in funzione della dimensione dell'input $n$.

Per comprendere intuitivamente la differenza tra i vari tipi di crescita, consideriamo una storiella: quella di Pinocchio e Geppetto.
Pinocchio possiede una sola moneta da 1 euro. Geppetto, saggio e prudente, gli consiglia di depositarla in una banca che offre un rendimento del 3,5% mensile (interesse composto). Pinocchio, tuttavia, incontra il Gatto e la Volpe, che gli propongono un affare apparentemente irresistibile: «Se lasci la tua moneta nella nostra banca, ti daremo 50 euro ogni mese!».
Pinocchio, attratto dal guadagno immediato, sceglie la seconda opzione (crescita lineare). Geppetto sceglie la prima (crescita esponenziale).

Chi ha fatto la scelta migliore?
*   **Strategia del Gatto e la Volpe (Lineare):** Il guadagno è costante. Ogni mese si aggiungono 50 euro. La funzione di costo è $CGV(n) = 50n$.
*   **Strategia di Geppetto (Esponenziale):** Il capitale cresce del 3,5% ogni mese. La funzione è $CG(n) = 1 \times (1,035)^n$.

Inizialmente, la crescita esponenziale sembra lenta e il guadagno lineare di Pinocchio pare imbattibile. Dopo 12 mesi, Pinocchio ha 600 euro, mentre Geppetto solo 1,56 euro. Tuttavia, osservando il comportamento nel lungo periodo (asintotico), la situazione si ribalta drasticamente.
Dopo 60 mesi, Geppetto ha circa 9,3 euro contro i 3.000 di Pinocchio. Ma dopo 240 mesi (20 anni), Geppetto possiede oltre **3 milioni di euro**, mentre il Gatto e la Volpe sono fermi a 12.000 euro.

Questo esempio dimostra un principio fondamentale dell'informatica: **le crescite esponenziali, seppur lente all'inizio, sul lungo periodo superano qualunque crescita lineare.** Saper riconoscere il tipo di crescita di una funzione $T(n)$ è un'abilità essenziale.

## 2. Il concetto di Tempo Computazionale
Quando analizziamo l'efficienza di un algoritmo, non misuriamo il tempo effettivo di esecuzione (che dipende da hardware, processore, linguaggio e sistema operativo), ma descriviamo in modo astratto il comportamento dell'algoritmo.
Definiamo $T(n)$ come il numero di passi elementari (assegnazioni, confronti, accessi a un array) eseguiti su un input di dimensione $n$.

### Gerarchia delle funzioni di costo
Le funzioni possono essere classificate in base alla loro velocità di crescita. Ecco un confronto ordinato dalla più efficiente (crescita lenta) alla meno efficiente (crescita esplosiva):

1.  **Costante ($k$ o $1$):** Il tempo non dipende dall'input (es. accedere al primo elemento di un array).
2.  **Logaritmica ($\log n$):** Cresce molto lentamente. Tipica della Ricerca Dicotomica (Binary Search).
3.  **Lineare ($n$):** Cresce proporzionalmente all'input (es. Ricerca Lineare, scorrere una lista).
4.  **Linearitmica ($n \log n$):** "Quasi lineare", cresce un po' più velocemente di $n$. Tipica degli algoritmi di ordinamento efficienti come il Merge Sort o il Quick Sort.
5.  **Polinomiale ($n^2, n^3, \dots$):**
    *   $n^2$ (Quadratica): Tipica di algoritmi di ordinamento semplici (Selection Sort, Insertion Sort) con cicli annidati.
    *   $n^3$ (Cubica): Cresce ancora più rapidamente.
6.  **Esponenziale ($k^n$):** La crescita diventa intrattabile per input grandi (es. $2^n$).
7.  **Fattoriale ($n!$):** La crescita peggiore tra quelle comuni.

Per dare un'idea concreta: se processiamo un array di $n=1000$ elementi:
*   $\log n \approx 10$ passi.
*   $n = 1.000$ passi.
*   $n^2 = 1.000.000$ passi.
*   $2^n \approx 10^{300}$ passi (un numero astronomico).

## 3. Notazioni Asintotiche
L'obiettivo delle notazioni asintotiche è rappresentare formalmente l'idea di crescita, trascurando i dettagli irrilevanti (costanti moltiplicative e termini di ordine inferiore) per concentrarsi sul termine che domina la funzione quando $n$ tende all'infinito.

Data una funzione complessa come $f(n) = \frac{7}{10}n + 200\sqrt{n} + \frac{1}{2}n^2 + 3000$, per $n$ molto grandi l'unico termine che conta davvero è $n^2$. Possiamo quindi dire che la funzione si comporta asintoticamente come $n^2$.

Esistono cinque notazioni principali per descrivere queste relazioni:

### 3.1 Notazione Theta ($\Theta$): Limite Stretto
La notazione $\Theta$ descrive una crescita "bilanciata". Dire che $f(n) = \Theta(g(n))$ significa che le due funzioni crescono alla stessa velocità, a meno di costanti.
Formalmente:
$$ \Theta(g(n)) = \{ f(n) \mid \exists c_1, c_2, n_0 > 0 \text{ tali che } 0 \le c_1 g(n) \le f(n) \le c_2 g(n), \forall n \ge n_0 \} $$
Intuitivamente, la funzione $f(n)$ rimane "ingabbiata" in una fascia compresa tra due multipli di $g(n)$.
Esempio: $3n^2 + 5n + 7 = \Theta(n^2)$.

### 3.2 Notazione O Grande ($O$): Limite Superiore
La notazione $O$ rappresenta un limite superiore asintotico. Descrive funzioni che non crescono più rapidamente di $g(n)$.
Formalmente:
$$ O(g(n)) = \{ f(n) \mid \exists c, n_0 > 0 \text{ tali che } 0 \le f(n) \le c \cdot g(n), \forall n \ge n_0 \} $$
Questa notazione è usata spesso per descrivere il **caso peggiore** (worst case) di un algoritmo, garantendo che il tempo di esecuzione non supererà mai una certa soglia.
Esempio: $3n + 20 = O(n)$, ma è anche vero che $3n + 20 = O(n^2)$ (anche se è un limite lasco).

### 3.3 Notazione Omega Grande ($\Omega$): Limite Inferiore
La notazione $\Omega$ rappresenta un limite inferiore asintotico. Descrive funzioni che crescono almeno tanto rapidamente quanto $g(n)$.
Formalmente:
$$ \Omega(g(n)) = \{ f(n) \mid \exists c, n_0 > 0 \text{ tali che } 0 \le c \cdot g(n) \le f(n), \forall n \ge n_0 \} $$
Viene usata per descrivere il **caso migliore** (best case) o per stabilire una barriera sotto la quale non si può scendere.

### 3.4 Notazioni "piccole" ($o$ e $\omega$)
Accanto alle versioni "Grandi", esistono le controparti che indicano disuguaglianze strette:
*   **o piccolo ($o$):** $f(n)$ cresce *strettamente* più lentamente di $g(n)$. Matematicamente equivale a dire che il limite del rapporto $f(n)/g(n)$ tende a 0.
*   **omega piccolo ($\omega$):** $f(n)$ cresce *strettamente* più velocemente di $g(n)$. Il limite del rapporto tende a $\infty$.

### Riepilogo analogie
Possiamo pensare alle notazioni asintotiche come alle disuguaglianze numeriche:
*   $f(n) = O(g(n)) \approx f \le g$
*   $f(n) = \Omega(g(n)) \approx f \ge g$
*   $f(n) = \Theta(g(n)) \approx f = g$
*   $f(n) = o(g(n)) \approx f < g$
*   $f(n) = \omega(g(n)) \approx f > g$

## 4. Applicazione agli Algoritmi
Nell'analisi reale, è consuetudine distinguere tre situazioni:
1.  **Caso Peggiore ($O$):** La stima che garantisce che l'algoritmo non sarà mai più lento di quanto previsto. È la misura più sicura.
2.  **Caso Migliore ($\Omega$):** Raggiungibile solo in condizioni ottimali (es. ordinare un array già ordinato).
3.  **Caso Medio ($\Theta$):** Spesso il comportamento più realistico, ma talvolta difficile da calcolare.

Esempio pratico: **Quick Sort**
*   Non ha una complessità fissa.
*   Nel caso medio e migliore: $\Theta(n \log n)$.
*   Nel caso peggiore: $O(n^2)$.
*   Al contrario, algoritmi come il **Merge Sort** hanno una complessità stabile $\Theta(n \log n)$ in tutti i casi.

## 5. Risoluzione delle Equazioni di Ricorrenza
Molti algoritmi ricorsivi (come il Merge Sort o la Ricerca Binaria) hanno un tempo di esecuzione descritto da un'equazione di ricorrenza del tipo $T(n) = aT(n/b) + f(n)$.
Per risolvere queste equazioni e trovare la classe di complessità, una tecnica efficace è l'**Albero di Ricorsione**.

Il metodo consiste nel visualizzare l'esecuzione come un albero dove ogni nodo rappresenta il costo del problema a quel livello e i figli sono le chiamate ricorsive.

### Esempi di risoluzione:

1.  **Merge Sort: $T(n) = 2T(n/2) + n$**
    *   Ad ogni livello dividiamo il problema in 2 parti ($n/2$).
    *   Il lavoro per combinare i risultati (merge) a ogni livello è $n$.
    *   L'altezza dell'albero è $\log_2 n$.
    *   Poiché abbiamo $\log n$ livelli e ogni livello costa $n$, il totale è $T(n) = n \log n$. Quindi $T(n) \in \Theta(n \log n)$.

2.  **Ricerca Binaria: $T(n) = T(n/2) + 1$**
    *   C'è solo una chiamata ricorsiva su metà input. Il costo locale è costante ($1$).
    *   Sommando 1 per ogni livello dell'albero (altezza $\log n$), otteniamo $T(n) \in \Theta(\log n)$.

3.  **Caso sbilanciato: $T(n) = T(n/2) + n$**
    *   Qui il costo diminuisce geometricamente a ogni livello: $n + n/2 + n/4 + \dots$
    *   Questa è una serie geometrica che converge a $2n$.
    *   Quindi $T(n) \in \Theta(n)$.

4.  **Caso complesso: $T(n) = T(n/2) + \log n$**
    *   Ad ogni livello il costo è il logaritmo della dimensione corrente: $\log n + \log(n/2) + \log(n/4) \dots$
    *   Sviluppando la somma, si ottiene che il costo totale è proporzionale a $\log^2 n$ (logaritmo al quadrato).
    *   Quindi $T(n) \in \Theta(\log^2 n)$.

5.  **Dominanza delle foglie: $T(n) = 4T(n/2) + n$**
    *   Il numero di sottoproblemi quadruplica a ogni passo, mentre l'input si dimezza.
    *   Il lavoro alle foglie diventa predominante rispetto alla radice.
    *   Risolvendo la sommatoria, si ottiene $T(n) \in \Theta(n^2)$.

## Conclusione
Lavoreremo su algoritmi descritti da equazioni di ricorrenza standard. Sebbene esistano metodi grafici come l'albero di ricorsione, nella prossima lezione (Lezione 4) introdurremo uno strumento potente e rapido per risolvere equazioni del tipo $T(n) = aT(n/b) + f(n)$: il **Master Theorem**. Ricordiamo infine che la nostra analisi si concentra sulla complessità temporale, tralasciando per ora la complessità spaziale (memoria usata).

Ecco il testo rielaborato, corretto e strutturato come un capitolo di un libro di testo, basato sugli appunti forniti.

***

# Lezione 4: Analisi degli Algoritmi e Strutture Dati: Ricorrenze e Heap

## Lezione 4: Equazioni di Ricorrenza

Nello studio degli algoritmi, lavoriamo spesso con equazioni di ricorrenza in cui $n$ rappresenta la dimensione dell'input (e quindi il tempo o la complessità computazionale) e $T(n)$ è il tempo necessario per la risoluzione del problema. Quando parliamo di tempo computazionale, ci riferiamo a una risorsa astratta, ma il ragionamento può essere applicato a qualsiasi risorsa (come lo spazio usato dall'algoritmo, $S(n)$). In generale, tuttavia, ci concentreremo sulla complessità temporale.

Un'equazione di ricorrenza standard assume solitamente la forma:

$$T(n) = aT(n/b) + F(n)$$

Questa equazione descrive il comportamento di un algoritmo "Divide et Impera" (Divide and Conquer):
*   **$a \ge 1$**: È il numero di sottoproblemi in cui viene diviso il problema originale.
*   **$n/b$**: È la dimensione di ciascun sottoproblema, dove $b > 1$ (il problema deve ridursi, altrimenti la ricorsione sarebbe infinita).
*   **$F(n)$**: È una funzione che descrive il costo aggiuntivo per dividere il problema e ricombinare le soluzioni dei sottoproblemi (il lavoro svolto sulla singola chiamata, escludendo le chiamate ricorsive).

### Esempi Classici

1.  **Ricerca Binaria (Binary Search):**
    L'equazione è $T(n) = T(n/2) + 1$.
    Qui $a=1$ (mi concentro su un solo sottoproblema), $b=2$ (divido a metà l'input), e il lavoro per unire/dividere è costante ($O(1)$).
2.  **Merge Sort:**
    L'equazione è $T(n) = 2T(n/2) + n$.
    L'algoritmo divide l'array in due parti ($a=2, b=2$) e risolve entrambi i sottoproblemi. Successivamente, la procedura di *merge* per riunire i risultati richiede tempo lineare ($F(n) = n$).

### Metodo dell'Albero di Ricorsione

Per risolvere queste equazioni, possiamo visualizzare l'esecuzione dell'algoritmo tramite un **albero di ricorsione**. Analizzando l'albero livello per livello, calcoliamo il costo totale sommando il lavoro svolto a ogni profondità.

1.  **Livello 0 (Radice):** Abbiamo una chiamata di dimensione $n$.
2.  **Livello 1:** Il nodo è diviso in $a$ chiamate di dimensione $n/b$.
3.  **Livello 2:** I nodi hanno dimensione $n/b^2$.
4.  **Livello $h$ (Foglie):** Si scende fino a quando la dimensione dell'input diventa unitaria ($1$).

La condizione di arresto è $n/b^h = 1$, da cui si ricava che l'altezza dell'albero è $h = \log_b n$.
A un generico livello $k$, ci aspettiamo che l'input abbia dimensione $n/b^k$. Il numero di nodi cresce in base ad $a$, mentre la dimensione del problema decresce in base a $b$. Sommando il lavoro di tutti i livelli, otteniamo la complessità totale.

Ad esempio, nel Merge Sort, ogni livello contribuisce per un totale di $n$ (poiché il lavoro è lineare e si distribuisce su più nodi la cui somma delle dimensioni è $n$). Essendoci $\log_2 n$ livelli, la complessità totale è $n \log n$.

---

### Metodo di Sostituzione

Oltre all'approccio grafico dell'albero, esiste il **metodo di sostituzione**, una tecnica formale utilizzata per dimostrare che una ricorrenza $T(n)$ appartiene a una certa classe di complessità (solitamente indicando un limite superiore $O$ o stretto $\Theta$).

Il metodo funziona in modo simile all'induzione matematica:
1.  **Ipotesi:** Ipotizziamo che $T(n) \le c \cdot g(n)$ per una certa costante $c > 0$ e per $n \ge n_0$.
2.  **Passo Induttivo:** Sostituiamo questa ipotesi nella parte ricorsiva dell'equazione e verifichiamo se la disuguaglianza regge.

#### Esempio: $T(n) = T(n/2) + n$
Vogliamo dimostrare che $T(n) = O(n)$.
Ipotizziamo $T(k) \le c \cdot k$ per ogni $k < n$. Sostituendo nella ricorrenza:
$$T(n) \le c(n/2) + n$$
$$T(n) \le (c/2)n + n = n(c/2 + 1)$$
Affinché sia vero che $T(n) \le cn$, dobbiamo avere $c/2 + 1 \le c$, che implica $c \ge 2$. La dimostrazione regge per $c \ge 2$.

#### Esempio: $T(n) = 2T(n/2) + n^2$
Vogliamo dimostrare che $T(n) = O(n^2)$.
Sostituiamo $T(n/2) \le c(n/2)^2$:
$$T(n) \le 2 \cdot c \cdot \frac{n^2}{4} + n^2 = \frac{c}{2}n^2 + n^2 = n^2 \left(\frac{c}{2} + 1\right)$$
Imponiamo $n^2(c/2 + 1) \le cn^2$, che porta a $c/2 + 1 \le c \Rightarrow c \ge 2$. La complessità è quadratica.

### Tecnica dell'Ipotesi Rafforzata

In alcuni casi, la sostituzione diretta fallisce perché rimane un termine residuo che non riusciamo a eliminare. Quando ciò accade, non significa necessariamente che la classe di complessità sia sbagliata, ma che l'ipotesi induttiva è troppo debole. Dobbiamo sottrarre termini di ordine inferiore per far tornare i conti (es. $cn^2 - dn$ invece di $cn^2$).

**Esempio Fallimentare:** $T(n) = 4T(n/2) + n$ con ipotesi $O(n^2)$.
Sostituendo otteniamo:
$$T(n) \le 4c(n/2)^2 + n = cn^2 + n$$
Non possiamo dire che $cn^2 + n \le cn^2$ perché $n > 0$. La dimostrazione fallisce.

**Soluzione (Ipotesi Rafforzata):**
Proviamo a dimostrare $T(n) \le cn^2 - dn$ (con $d \ge 1$).
$$T(n) \le 4(c(n/2)^2 - d(n/2)) + n$$
$$T(n) \le cn^2 - 2dn + n$$
Vogliamo che questo sia $\le cn^2 - dn$.
$$-2dn + n \le -dn \Rightarrow n \le dn \Rightarrow d \ge 1$$
Con l'ipotesi rafforzata, abbiamo dimostrato che la complessità è $O(n^2)$.

Questa tecnica si applica anche a casi con logaritmi, come $T(n) = T(n/2) + \log n$, dove un'ipotesi del tipo $c \log^2 n - d \log n$ può essere necessaria.

---

### Il Teorema Master (Master Theorem)

Il metodo di sostituzione e l'albero di ricorsione possono essere complessi. Il **Teorema Master** fornisce una "ricetta" rapida per risolvere ricorrenze della forma $T(n) = aT(n/b) + F(n)$, con $a \ge 1, b > 1$.

L'idea alla base è confrontare la crescita di due componenti:
1.  **$n^{\log_b a}$**: Il numero di foglie dell'albero di ricorsione (il "peso" della divisione del problema).
2.  **$F(n)$**: Il costo del lavoro svolto alla radice e nei nodi interni per combinare i risultati.

Esistono tre casi principali, determinati da chi "vince" questo confronto:

#### Caso 1: Il lavoro si concentra sulle foglie
Se $F(n)$ è asintoticamente più piccola di $n^{\log_b a}$ (cioè $F(n) = O(n^{\log_b a - \epsilon})$ per $\epsilon > 0$), allora le foglie dominano il costo totale.
$$T(n) = \Theta(n^{\log_b a})$$
*Esempio:* $T(n) = 4T(n/2) + n$.
Qui $a=4, b=2 \Rightarrow \log_2 4 = 2$. Confrontiamo $n^1$ con $n^2$. Poiché $n$ è più piccolo di $n^2$, vince la parte ricorsiva: $T(n) = \Theta(n^2)$.

#### Caso 2: Equilibrio
Se $F(n)$ cresce allo stesso modo di $n^{\log_b a}$ (ovvero $F(n) = \Theta(n^{\log_b a})$), il lavoro è distribuito uniformemente lungo i livelli dell'albero (che ha altezza $\log n$).
$$T(n) = \Theta(n^{\log_b a} \log n)$$
*Estensione:* Se $F(n) = \Theta(n^{\log_b a} \log^k n)$ con $k \ge 0$, allora $T(n) = \Theta(n^{\log_b a} \log^{k+1} n)$.
*Esempio Merge Sort:* $T(n) = 2T(n/2) + n$.
$n^{\log_2 2} = n^1$. Poiché $F(n) = n$, siamo nel caso 2. Soluzione: $\Theta(n \log n)$.

#### Caso 3: Il lavoro domina alla radice
Se $F(n)$ è più grande di $n^{\log_b a}$ (cioè $F(n) = \Omega(n^{\log_b a + \epsilon})$) e soddisfa la **condizione di regolarità** ($aF(n/b) \le cF(n)$ per $c < 1$), allora il lavoro alla radice domina tutto il resto.
$$T(n) = \Theta(F(n))$$
*Esempio:* $T(n) = T(n/3) + n$.
$\log_3 1 = 0$, quindi confrontiamo $n^0 = 1$ con $n$. $F(n)=n$ è polinomialmente più grande. Verificata la regolarità, la complessità è $\Theta(n)$.

**Nota Importante:** Attenzione ai casi "ingannevoli". Ad esempio, per $T(n) = T(n/2) + \log n$, potremmo pensare al Caso 3, ma $n^{\log_2 1} = 1$. $\log n$ è più grande di 1 ma *non* polinomialmente più grande (la differenza è logaritmica, non $n^\epsilon$). Questo ricade nell'**estensione del Caso 2** (con $k=1$), risultando in $\Theta(\log^2 n)$.

---

### Algoritmo di Strassen

Il metodo Master è utile per analizzare l'algoritmo di Strassen per la moltiplicazione di matrici. L'algoritmo classico ha complessità cubica $O(n^3)$. Strassen riduce il numero di moltiplicazioni ricorsive da 8 a 7.
Equazione: $T(n) = 7T(n/2) + n^2$.
*   $a=7, b=2$.
*   Esponente critico: $\log_2 7 \approx 2.81$.
*   Confronto: $n^{2.81}$ vs $n^2$.
Poiché $n^2$ è più piccolo, siamo nel **Caso 1**.
La complessità è $\Theta(n^{\log_2 7})$, che è asintoticamente migliore di $O(n^3)$.

Ecco una rielaborazione completa, corretta e ben strutturata del contenuto presente nel PDF. Il testo è stato organizzato come un capitolo di un libro di testo o una dispensa universitaria, unendo i concetti delle Lezioni 5 e 6 in un discorso fluido e logico.

---

# Lezione 5: Code con Priorità e Struttura Heap

## 1. Preludio Matematico: Metodo di Sostituzione
Prima di addentrarci nelle strutture dati, riprendiamo brevemente la dimostrazione di un'equazione di ricorrenza tramite il metodo di sostituzione, trattata all'inizio della lezione.

Data l'equazione:
$$ T(n) \le c \cdot n^{\log_{3/2} 7} - d \cdot n^2 $$
Applicando il passo induttivo e sostituendo $T(n/2)$, otteniamo una disuguaglianza che ci porta a dover soddisfare la condizione:
$$ -\frac{7}{4}d + 1 \le -d \quad \Rightarrow \quad \frac{3}{4}d \ge 1 \quad \Rightarrow \quad d \ge \frac{4}{3} $$
Siamo quindi riusciti a dimostrare la nostra ipotesi: affinché la limitazione sia valida, è sufficiente scegliere una costante $d \ge 4/3$.

---

## 2. Introduzione alle Code con Priorità (Heap)

Il termine **HEAP** letteralmente significa "mucchio". In informatica, questa struttura è stata introdotta per implementare efficientemente le **code con priorità**.
A differenza di una coda classica (FIFO - *First In First Out*) o di una pila (LIFO - *Last In First Out*), una coda con priorità non serve gli elementi in base al momento di arrivo, ma in base a una caratteristica intrinseca chiamata **chiave** (o priorità).

### Il concetto di priorità
Nelle nostre convenzioni, prediligeremo i valori più piccoli:
*   **Valore piccolo = Alta priorità** (esce prima).
*   **Valore grande = Bassa priorità**.

Solo a parità di valore (chiave), si considera il tempo di arrivo per determinare l'ordine di uscita.

**Esempio pratico: Il Pronto Soccorso**
Un esempio reale di coda con priorità è il triage ospedaliero. I codici colore rappresentano le priorità (chiavi):
*   Bianco/Verde (codici bassi/meno urgenti).
*   Giallo/Rosso (codici alti/urgenti).

Se un paziente arriva in codice giallo, supera automaticamente tutti quelli in attesa con codice verde, indipendentemente da quanto tempo stiano aspettando. La fila viene rispettata solo tra pazienti con lo stesso codice.

---

## 3. Confronto tra Strutture Dati per Code con Priorità

Per capire perché lo Heap sia necessario, analizziamo come si comporterebbero strutture dati più semplici (array) e più complesse (alberi bilanciati) se usate per gestire le priorità.
Le operazioni fondamentali che dobbiamo supportare sono:
1.  **Inserimento:** Aggiungere un nuovo elemento.
2.  **Estrazione (del minimo):** Rimuovere e restituire l'elemento prioritario.
3.  **Decremento (Decrease Key):** Aumentare la priorità di un elemento (diminuire il valore della chiave).
4.  **Minimo:** Consultare l'elemento prioritario senza estrarlo.

Supponiamo di avere $n$ elementi.

### 3.1 Array Disordinato
*   **Inserimento:** $O(1)$. Basta mettere l'elemento nella prima posizione libera (in fondo).
*   **Estrazione/Minimo:** $\Theta(n)$. Bisogna scorrere tutto l'array per trovare il valore più piccolo.
*   **Decremento:** $O(1)$ se abbiamo il puntatore all'elemento, ma non aiuta l'estrazione successiva.

*Vantaggio:* Inserimento immediato.
*Svantaggio:* Costo lineare per trovare il minimo, inaccettabile per code frequenti.

### 3.2 Array Ordinato
*   **Minimo:** $O(1)$. Il minimo è sempre in prima posizione (o ultima, a seconda dell'ordinamento).
*   **Inserimento:** $O(n)$. Per inserire un valore e mantenere l'ordine, bisogna "shiftare" (spostare) tutti gli elementi successivi.
*   **Estrazione:** $O(n)$. Anche togliendo il primo elemento, bisogna riorganizzare l'array (shift verso sinistra).

*Vantaggio:* Accesso rapido al minimo.
*Svantaggio:* Inserimento ed estrazione costosi.

### 3.3 Alberi Binari di Ricerca Bilanciati (BBST)
Utilizzando un BBST (*Balanced Binary Search Tree*), l'altezza dell'albero è garantita essere logaritmica ($O(\log n)$).
*   **Tutte le operazioni (Inserimento, Estrazione, Ricerca, Decremento):** $O(\log n)$.

Sebbene $O(\log n)$ sia ottimo (la funzione logaritmica cresce molto lentamente, quasi come una costante per numeri grandi), i BBST sono strutture complesse da implementare e mantenere (richiedono puntatori e ribilanciamenti).

L'obiettivo dello **Heap** è ottenere le stesse prestazioni asintotiche dei BBST ($O(\log n)$) ma con una struttura molto più semplice, gestibile tramite un array e senza l'uso esplicito di puntatori.

---

## 4. Struttura e Proprietà dello Heap

Lo Heap è, strutturalmente, un **albero binario completo** (o quasi completo).
*   **Completo:** Tutti i livelli sono pieni, eccetto eventualmente l'ultimo.
*   **Allineato:** L'ultimo livello viene riempito da sinistra verso destra.

Esistono due varianti di Heap, simmetriche tra loro:
1.  **Min Heap:** La chiave di un nodo è sempre **minore o uguale** a quella dei suoi figli. La radice contiene il minimo assoluto.
2.  **Max Heap:** La chiave di un nodo è sempre **maggiore o uguale** a quella dei suoi figli. La radice contiene il massimo.

*Nota:* Nel seguito tratteremo il **Min Heap**.

### Ordinamento Parziale
A differenza di un BST (dove tutto il sottoalbero sinistro è minore del nodo e tutto il destro è maggiore), nello Heap c'è solo una relazione verticale:
$$ \text{Key}[parent] \le \text{Key}[figlio] $$
Non c'è alcuna relazione d'ordine specifica tra fratello destro e fratello sinistro. Questo è definito **ordinamento parziale**.

### Rappresentazione in Memoria (Array)
Il vero segreto dello Heap è che può essere implementato facilmente usando un **array**, eliminando la necessità di puntatori. Appiattendo l'albero livello per livello (da sinistra a destra):
*   La radice è all'indice $1$ (o $0$, a seconda dell'implementazione; qui useremo l'indice 1 per semplificare le formule).
*   Dato un nodo all'indice $i$:
    *   Il **figlio sinistro** (*Left*) si trova a $2i$.
    *   Il **figlio destro** (*Right*) si trova a $2i + 1$.
    *   Il **genitore** (*Parent*) si trova a $\lfloor i/2 \rfloor$.

Queste operazioni possono essere eseguite in modo estremamente efficiente tramite **operazioni bitwise** (shift dei bit):
*   Moltiplicare per 2 corrisponde a uno *shift a sinistra* (`i << 1`).
*   Dividere per 2 corrisponde a uno *shift a destra* (`i >> 1`).

---

## 5. Operazioni sullo Heap

Grazie alla struttura ad albero bilanciato (altezza $\log n$) e alla rappresentazione in array, possiamo analizzare le complessità.

### 5.1 Minimo
Poiché usiamo un Min Heap, il minimo si trova sempre alla radice.
*   **Costo:** $\Theta(1)$ (Accesso diretto all'indice 1 dell'array).

### 5.2 Decrease Key (Decremento di una chiave)
Se riduciamo il valore di una chiave (es. un nodo passa da 7 a 1), potremmo violare la proprietà dello heap (il figlio diventa più piccolo del padre).
**Procedura:**
1.  Si aggiorna il valore.
2.  Si confronta il nodo con il padre.
3.  Se il nodo è minore del padre, si scambiano (**swap**).
4.  Si ripete il procedimento risalendo verso la radice finché la proprietà non è ripristinata o si raggiunge la radice.

*   **Costo:** Nel caso peggiore si risale tutta l'altezza dell'albero. $O(\log n)$.

### 5.3 Inserimento
L'inserimento sfrutta la logica del *Decrease Key*:
1.  Inseriamo il nuovo nodo nella prima posizione libera dell'array (in fondo, per mantenere la struttura di albero completo).
2.  Idealmente, inseriamo un valore "infinito" e poi facciamo una *Decrease Key* al valore desiderato.
3.  L'elemento "risale" (bubble-up) fino alla sua posizione corretta.

*   **Costo:** Proporzionale all'altezza dell'albero. $O(\log n)$.

### 5.4 Estrazione del Minimo ed Heapify
Per estrarre il minimo (la radice), non possiamo lasciare un buco.
1.  Prendiamo l'ultimo elemento dell'array (quello più in basso a destra) e lo spostiamo alla radice al posto del minimo rimosso.
2.  Ora la struttura è integra, ma l'ordinamento è violato (un elemento grande è in testa).
3.  Bisogna far "scendere" questo elemento nella posizione corretta. Questa procedura si chiama **HEAPIFY**.

**Procedura Heapify($i$):**
Si applica a un nodo $i$ assumendo che i sottoalberi sinistro e destro siano già heap validi.
1.  Confronto la chiave di $i$ con il figlio sinistro ($l$) e il figlio destro ($r$).
2.  Individuo il più piccolo tra $i$, $l$ e $r$.
3.  Se il minimo non è $i$, scambio $i$ con il figlio minore.
4.  Chiamo ricorsivamente *Heapify* sul figlio appena scambiato.

**Analisi della complessità di Heapify:**
L'equazione di ricorrenza (nel caso peggiore su un albero quasi completo) è approssimabile dal Teorema Master (Caso 2):
$$ T(n) \le T(2/3 n) + \Theta(1) \implies T(n) = \Theta(\log n) $$
Il fattore $2/3$ deriva dal fatto che, in un albero non perfettamente bilanciato nell'ultimo livello, il sottoalbero più grande può contenere circa i 2/3 dei nodi totali. Tuttavia, la complessità rimane legata all'altezza: **$O(\log n)$**.

Quindi, l'estrazione del minimo costa **$O(\log n)$**.

---

## 6. Costruzione dello Heap (Build Heap)

Come si costruisce uno heap partendo da un array disordinato di $n$ elementi?

### Metodo 1: Inserimenti successivi
Possiamo inserire gli elementi uno alla volta in uno heap vuoto. Poiché ogni inserimento costa $O(\log n)$, per $n$ elementi il costo totale è:
$$ O(n \log n) $$

### Metodo 2: Procedura `Build-Min-Heap` (Ottimizzata)
Esiste un metodo più efficiente che sfrutta la struttura.
Prendiamo l'array così com'è. Le foglie (l'ultima metà dell'array, indici da $\lfloor n/2 \rfloor + 1$ a $n$) sono, per definizione, heap validi (non hanno figli).
La strategia è chiamare **Heapify** a ritroso, partendo dall'ultimo nodo interno fino alla radice.

**Algoritmo:**
```
FOR i = floor(n/2) DOWN TO 1:
    Heapify(array, i)
```
In pratica, sistemiamo prima i sottoalberi piccoli in basso, poi quelli medi, e infine la radice.

**Analisi della complessità (Sorprendente):**
A prima vista potrebbe sembrare $O(n \log n)$ perché chiamiamo Heapify $n/2$ volte. Tuttavia, l'altezza dei nodi varia:
*   La maggior parte dei nodi è vicino al fondo (altezza bassa, costo Heapify basso).
*   Pochissimi nodi sono in alto (altezza $\log n$).

La somma dei costi è data dalla serie:
$$ \sum_{h=0}^{\log n} \frac{n}{2^{h+1}} \cdot O(h) = n \sum_{h=0}^{\infty} \frac{h}{2^h} $$
Poiché la serie $\sum \frac{h}{2^h}$ converge a una costante, il costo totale è:
$$ \Theta(n) $$
Costruire uno heap da zero richiede quindi **tempo lineare**. Questo è un risultato eccellente.
Ecco il testo rielaborato, corretto e formattato come una dispensa universitaria coerente e fluida.

***

# Lezione 6: L’Heap e l'Ordinamento Ottimo

In questa lezione esploreremo come l'utilizzo di una struttura dati avanzata migliori la nostra capacità di risolvere problemi computazionali. Vedremo situazioni in cui l'uso dell'**Heap** ci permette di semplificare operazioni che prima svolgevamo in modo più complesso. Un concetto fondamentale sarà imparare a utilizzare correttamente l'Heap e capire quando questa struttura può semplificare il compito.

Partiamo da un caso molto semplice: il problema dell'ordinamento. Conosciamo già diverse soluzioni classiche, che abbiamo realizzato da zero basandoci sul nostro intuito e senza utilizzare strumenti ausiliari complessi:

*   **Insertion Sort**: $O(n^2)$
*   **Selection Sort**: $\Theta(n^2)$
*   **Quick Sort**: $O(n^2)$ (nel caso peggiore)
*   **Merge Sort**: $\Theta(n \log n)$

Questi algoritmi, pur efficaci, possono essere migliorati o reinterpretati utilizzando le strutture dati. Immaginiamo di affacciarci per la prima volta al problema dell'ordinamento, ma avendo questa volta a disposizione uno strumento chiamato Heap.

Uno degli algoritmi più banali in assoluto è il **Selection Sort**. L'idea alla base è semplice: prendo l'elemento più grande dell'array, lo sposto nell'ultima posizione e ripeto l'operazione per gli elementi rimanenti ($n-1, n-2, \dots$) fino a quando non ho visitato tutti gli elementi. Questo approccio ha un costo quadratico perché, per trovare il massimo a ogni passo, devo scorrere linearmente l'array.

Tuttavia, se utilizziamo un'estrazione del massimo basata su un Heap, il costo cambia drasticamente. Non pensiamo più ad una ricerca lineare, ma ad un'operazione di estrazione che costa molto meno.

### Dal Selection Sort all'Heapsort

Vediamo come si trasforma l'algoritmo se, invece di usare la ricerca lineare, usiamo l'estrazione del massimo tramite Heap.

Per prendere il massimo costruiamo un **Max-Heap**.
Partendo da un array completamente disordinato, utilizziamo la procedura `Build-Max-Heap` (che visualizziamo come un albero). Questa operazione ha una complessità temporale di $\Theta(n)$, il che è un ottimo risultato poiché è lineare. Applichiamo `Heapify` sui nodi fino a ottenere un Heap (dove la radice contiene il nodo più grande).

Sembra di aver peggiorato le cose perché stiamo "ordinando al contrario", ma in realtà l'Heap ha la capacità di individuare in modo immediato quale è l'elemento più grande del nostro array (si trova nella radice). A questo punto seguiamo una procedura simile al Selection Sort:

1.  Prendiamo il massimo (la radice).
2.  Lo "stacchiamo" dall'albero scambiandolo con l'ultimo elemento dell'array (una foglia).
3.  Ristabiliamo le proprietà dell'Heap che sono state violate tramite la procedura `Heapify`.

La procedura di estrazione (`Extract-Max`) sposta il valore 18 (esempio) dalla radice al posto dell'ultimo nodo (es. 2), e il nodo che era l'ultimo viene messo momentaneamente in testa. Successivamente, si chiama `Heapify`.
Questo scambio e ripristino costa $O(\log n)$. Poiché dobbiamo ripetere questa operazione per $n$ elementi, e trovare il massimo è diventato facile, otteniamo l'algoritmo **Heapsort**.

### Algoritmo Heapsort

Lo pseudocodice dell'Heapsort è il seguente:

```text
HEAPSORT(A, n)
  BUILD-MAX-HEAP(A, n)
  FOR i <- 1 TO n-1 DO
    SWAP(A[1], A[n-i+1])
    n <- n - 1
    HEAPIFY(A, 1)
```

La complessità totale è $\Theta(n \log n)$.
Questa è l'idea del Selection Sort potenziata dall'Heap. Nella procedura di estrazione scambiamo il primo elemento con l'ultimo, diminuiamo la dimensione dell'heap ("size") e chiamiamo `Heapify` sull'elemento 1.

Mentre il Selection Sort classico ha una complessità di $O(n^2)$ (passi lineari per $n$ volte), l'algoritmo Heapsort ha una complessità di $O(n \log n)$ (passi logaritmici per $n$ volte). Questa è una complessità molto più bassa, uguale a quella del Merge Sort. Poiché $O(n \log n)$ è considerato un limite ottimo per gli ordinamenti basati su confronti, non possiamo fare di meglio in termini asintotici.

**Confronto con Merge Sort:**
*   Il **Merge Sort** raggiunge la stessa complessità temporale, ma utilizza memoria aggiuntiva per la fusione degli array.
*   L'**Heapsort** è "in loco" (in-place): utilizza una memoria aggiuntiva costante, ovvero $O(1)$ circa (non necessita di array di appoggio).

### L'Albero di Decisione e il Limite Inferiore

Ci serve dimostrare che, nel caso peggiore, nessun algoritmo basato su confronti può avere una complessità inferiore a $\Omega(n \log n)$. Per farlo, utilizziamo il modello dell'**Albero di Decisione**.

Un albero di decisione rappresenta l'esecuzione dell'algoritmo su un input di dimensione $n$.
*   Ogni nodo interno rappresenta un confronto tra due elementi $a_i$ e $a_j$.
*   I rami rappresentano l'esito del confronto (minore, maggiore o uguale).
*   Ogni foglia rappresenta una permutazione dell'array iniziale, ovvero un possibile risultato finale dell'algoritmo (l'array ordinato).

Se l'array ha $n$ elementi, il numero di possibili permutazioni (e quindi il numero minimo di foglie nell'albero) è $n!$ (n fattoriale).
Per un albero binario di altezza $h$, il numero massimo di foglie è $2^h$. Affinché l'albero possa distinguere tra tutte le $n!$ permutazioni, deve valere:
$$ n! \le 2^h $$
Passando ai logaritmi in base 2:
$$ h \ge \log_2(n!) $$

L'altezza $h$ rappresenta il numero di confronti nel caso peggiore. Utilizzando l'**approssimazione di Stirling** ($\ln n! \approx n \ln n - n$), possiamo dire che:
$$ \log(n!) = \Theta(n \log n) $$

Quindi, l'altezza dell'albero di decisione non può essere inferiore a $n \log n$.
Questo significa che qualsiasi algoritmo che opera su confronti deve fare almeno $\Omega(n \log n)$ confronti nel caso peggiore. Poiché l'Heapsort raggiunge questo limite superiore ($O(n \log n)$), è un algoritmo asintoticamente ottimale.

---

## Esercitazione ed Esami Precedenti

Di seguito analizziamo alcuni esercizi tipici riguardanti gli Heap e la loro manipolazione.
*Nota importante:* Se durante un esame viene richiesto di disegnare l'albero, si può scrivere direttamente la soluzione finale. Se vengono chiamate procedure esterne, queste vanno scritte a parte. Se per risolvere un problema ci complichiamo la vita inutilmente, la soluzione potrebbe non essere considerata corretta.

### Esercizio 1 (6/9/2024)
**Testo:** Dato l'array $A = [1, 3, 4, 7, 8, 11, 12, 13, 15, 18, 22, 24, 25]$ contenente 13 elementi, che rappresenta la configurazione iniziale di un **Min-Heap** binario, eseguire 13 operazioni di estrazione del minimo su questa struttura dati. Dopo ciascuna operazione di estrazione, fornire la configurazione dell'array risultante.

**Risoluzione:**
Dobbiamo scrivere la configurazione finale dopo ogni estrazione.
Ad ogni step, estraggo la radice (il minimo). Per mantenere la struttura di Heap:
1.  Porto l'ultimo elemento dell'array (es. il 25) al posto della radice (posizione 1).
2.  Diminuisco la dimensione dell'Heap.
3.  Chiamo la procedura `Heapify` (verso il basso) per ripristinare la proprietà di Min-Heap.

Il grafico rimane invariato nel lato in cui non chiamo heapify, velocizzando il disegno.
*(Nota: Nella soluzione grafica, ad ogni estrazione eliminiamo un nodo, il più grande va alla radice e poi scende in basso. Il numero di passi è logaritmico).*

### Esercizio 2 (14 Maggio 2025)
**Testo:** Scrivere una procedura `UpdateKey(H, i, k)` che aggiorni, in un Heap Binario Massimo, la chiave in posizione $i$ con il nuovo valore $k$, e ripristini le proprietà dell'heap massimo. L'algoritmo deve gestire correttamente entrambi i casi in cui $k > H[i]$ e $k < H[i]$. Analizzare la complessità nel caso peggiore.

**Risoluzione:**
A differenza della classica `IncreaseKey`, questa procedura è generica (la chiave può diminuire o aumentare) e deve gestire entrambi i casi.
Immaginiamo un Max-Heap. Prendiamo una chiave qualsiasi e facciamo un update.
*   **Caso 1 (Increase Key):** Se la chiave aumenta ($k > H[i]$), potrebbe violare la proprietà con il padre. Deve "salire" verso l'alto (Increase Key).
*   **Caso 2 (Decrease Key):** Se la chiave diminuisce ($k < H[i]$), potrebbe violare la proprietà con i figli. Deve "scendere" verso il basso tramite `Heapify`.

Possiamo verificare se $i$ è un indice valido; se non è presente facciamo un return.
Lo pseudocodice è:

```text
UPDATE-KEY(H, i, k)
  IF i > heap-size RETURN
  IF k > H[i] THEN
     INCREASE-KEY(H, i, k)  // Sale verso l'alto
  ELSE
     H[i] <- k
     HEAPIFY(H, i)          // Scende verso il basso
```
La complessità è $O(\log n)$ in entrambi i casi, poiché l'altezza dell'albero è logaritmica.

### Esercizio 3 (16 Giugno 2025)
**Testo:** Scrivere lo pseudocodice di una procedura `HeapMerge(H1, H2, n)` che prenda in input due heap binari massimi, $H_1$ e $H_2$, contenenti entrambi esattamente $n$ chiavi, e restituisca in output un nuovo heap binario massimo ottenuto dall'unione di $H_1$ e $H_2$, contenente esattamente $2n$ chiavi. La procedura deve avere una complessità asintotica temporale pari a $O(n)$.

**Risoluzione:**
Prendiamo in input due heap binari e vogliamo creare un unico heap.
*   *Soluzione ingenua:* Parto da un heap vuoto, prendo gli elementi di $H_1$ ad uno ad uno e li inserisco, poi faccio lo stesso con $H_2$. L'inserimento ha tempo $\log n$, ripetuto per $2n$ volte. La complessità totale sarebbe $O(n \log n)$. **Questa soluzione non rispetta la consegna.**
*   *Soluzione ottima:* Metto i due array in un array unico e chiamo `Build-Max-Heap`. La copia degli elementi mi costa $2n$, poi chiamo la costruzione dell'heap che, come sappiamo, ha costo lineare $O(n)$ se fatta su un array disordinato.

Pseudocodice corretto:
```text
HEAP-MERGE(H1, H2, n)
  H <- new Array(2n)
  FOR i <- 1 TO n DO
      H[i] <- H1[i]      // Copio H1 nella parte sinistra
      H[i + n] <- H2[i]  // Copio H2 nella parte destra
  BUILD-MAX-HEAP(H, 2n)  // Costruisco l'heap in tempo O(n)
  RETURN H
```
Grazie al fatto che `Build-Max-Heap` è lineare, la complessità totale rimane $O(n)$.

### Esercizio 4 (1 Settembre 2025)
**Testo:** Scrivere lo pseudocodice di una funzione che, preso un insieme $P = \{(x_i, y_i) \mid 0 \le i < n\}$ di $n$ punti, un punto $A = (a, b)$ ed un parametro $k < n$, restituisca i $k$ punti di $P$ più vicini al punto $A$. La soluzione deve avere una complessità pari a $O(n \log k)$.
*Nota:* La soluzione diretta prevede l'ordinamento degli elementi ($O(n \log n)$) e la selezione dei primi $k$. Qui si richiede un'efficienza maggiore.

**Risoluzione:**
Passo controintuitivo: mi servono i punti più *vicini* (minimi), ma userò un **Max-Heap**.
Non viene detto espressamente di usare un heap, ma è la strada per la risoluzione efficiente.

L'idea è mantenere un "insieme temporaneo" dei $k$ punti più vicini trovati finora.
1.  Costruisco un Max-Heap inizialmente vuoto o con i primi $k$ elementi di $P$. Questo costa $O(k)$ (o $O(k \log k)$ se inseriti uno alla volta).
2.  Nell'insieme $P$ rimangono $n-k$ elementi da controllare.
3.  Scorro gli elementi rimanenti uno ad uno. Per ogni elemento, calcolo la sua distanza da $A$.
4.  Confronto questa distanza con la distanza del punto che si trova nella radice del Max-Heap (che è il punto *più lontano* tra i $k$ vicini attuali).
5.  Se il nuovo punto è più vicino di quello nella radice (distanza minore), allora ho trovato un punto migliore. Estraggo il massimo (scarto il più lontano) e inserisco il nuovo punto.
6.  Se il nuovo punto è più lontano della radice, lo ignoro (perché è peggiore di tutti i $k$ che ho già).

Poiché l'heap ha dimensione fissa $k$, ogni operazione di inserimento/sostituzione costa $O(\log k)$.
Nel caso peggiore, devo fare l'operazione per tutti gli $n-k$ elementi rimanenti.
Complessità totale: $O(k) + O((n-k) \log k) = O(n \log k)$.

### Esercizio 5 (15 Settembre 2025)
**Testo:** Scrivere lo pseudocodice di una funzione che, prese in input $m$ liste ordinate, restituisca in output la lista ordinata contenente tutti e soli gli $n$ elementi delle liste ricevute in input ($n$ è il numero totale di elementi). La soluzione deve avere complessità pari a $O(n \log m)$.

**Risoluzione:**
Le liste sono strutture lineari (nodo dopo nodo) e sono già ordinate (testa = elemento più piccolo).
Il vincolo è la cardinalità totale $n$.
Se facessi un merge iterativo (due alla volta), la complessità salirebbe troppo.

La strategia ottima prevede l'uso di un **Min-Heap** di dimensione $m$ (il numero delle liste).
1.  Inserisco nell'Heap i primi elementi (le teste) di ciascuna delle $m$ liste.
2.  Ad ogni passo, estraggo il minimo dall'Heap (che sarà sicuramente il minimo globale corrente). Lo aggiungo alla lista/array di output.
3.  Dopo aver estratto un elemento proveniente dalla lista $L_i$, prendo il successivo elemento della stessa lista $L_i$ e lo inserisco nell'Heap.
4.  Se la lista $L_i$ è vuota, riduco la dimensione dell'Heap.

Ripeto questo procedimento per tutti gli $n$ elementi.
Ogni passo di estrazione e inserimento costa $O(\log m)$ (perché l'heap contiene al massimo $m$ elementi).
Poiché eseguo queste operazioni $n$ volte, la complessità totale è $O(n \log m)$.

Pseudocodice semplificato:
```text
LIST-MERGE(L, m)
  H <- new Heap()
  // Inserisco le teste delle m liste
  FOR i <- 1 TO m DO
     INSERT(H, L[i].head)

  Output <- new List()
  WHILE NOT IS-EMPTY(H) DO
     min_node <- EXTRACT-MIN(H)
     APPEND(Output, min_node.value)
     
     // Inserisco il prossimo elemento della lista da cui proveniva il minimo
     next_node <- min_node.next
     IF next_node IS NOT NULL THEN
        INSERT(H, next_node)
        
  RETURN Output
```

### Esercizio 6 (27/10/2025)
**Testo:** Un sistema registra in tempo reale i punteggi dei giocatori di un videogioco online. Si vuole mantenere in ogni momento la Top-Ten dei giocatori con i punteggi più alti, aggiornandola in tempo efficiente man mano che arrivano nuovi risultati. Descrivere l'idea di base e stimare la complessità.

**Risoluzione:**
L'approccio è simile all'esercizio 4. Usiamo un **Min-Heap** di dimensione fissa 10.
L'Heap conterrà i 10 punteggi migliori. La radice del Min-Heap sarà il *minimo* tra i migliori (ovvero il decimo classificato).

Quando arriva un nuovo punteggio $P_{new}$ di un giocatore:
1.  **Il giocatore non è in classifica:**
    *   Confronto $P_{new}$ con la radice dell'Heap (il decimo posto).
    *   Se $P_{new} > \text{Radice}$, allora il nuovo punteggio merita di entrare in Top-Ten. Sostituisco la radice con $P_{new}$ e chiamo `Min-Heapify` per riposizionarlo. Il vecchio decimo viene scartato.
    *   Se $P_{new} \le \text{Radice}$, il punteggio non è sufficiente per entrare in classifica. Ignoro.

2.  **Il giocatore è già in classifica (aggiornamento):**
    *   Se il giocatore migliora il suo punteggio, aggiorno il nodo corrispondente nell'Heap.
    *   Poiché il punteggio aumenta, potrebbe dover scendere verso il basso nel Min-Heap (violazione con i figli). Chiamo `Min-Heapify` sul nodo aggiornato.
    *   *Nota:* Se usassimo un Max-Heap, l'aumento del punteggio richiederebbe `Increase-Key` (salire). Con un Min-Heap per la Top-Ten, un valore più alto "pesa" di più e tende ad andare verso le foglie, quindi usiamo Heapify.

La complessità per ogni aggiornamento è costante rispetto a $n$ (numero totale giocatori) e dipende solo dalla dimensione della classifica ($k=10$). Quindi è $O(\log 10) \approx O(1)$.

Ecco il testo rielaborato, corretto e formattato come un capitolo di un libro di testo.

***

## Note sulla gestione degli Heap e Introduzione agli Ordinamenti Lineari

*Riprendiamo brevemente la discussione precedente riguardante l'esercizio sul min-heap.*

L'esercizio richiedeva semplicemente di descrivere l'idea di base e di stimare la complessità; non era necessario scrivere lo pseudocodice completo. Si poteva sintetizzare l'approccio dicendo: "Manteniamo un min-heap dove, ad ogni passo, se succede questo eseguo una determinata azione, se succede quello ne eseguo un'altra...". Questa descrizione logica era sufficiente.

---

# Lezione 7: Ordinamento in Tempo Lineare

L'ordinamento in tempo lineare, ovvero con complessità $O(n)$, si può ottenere solamente se non basiamo l'algoritmo sui confronti tra elementi. È dimostrato che, utilizzando un modello basato sui confronti (decision tree), non si può fare meglio di $\Theta(n \log n)$ (come avviene ad esempio nell'Heap Sort o nel Merge Sort). Tuttavia, non è sempre necessario risolvere i problemi di ordinamento tramite confronti; se ci svincoliamo da questo obbligo, possiamo abbattere il limite inferiore di complessità.

Introduciamo un algoritmo in tempo lineare per risolvere il problema: il **Counting Sort**. Si tratta di un algoritmo molto semplice e lineare che nasconde un pizzico di genialità.

## Il Counting Sort

L'idea alla base del Counting Sort è quella di ordinare un array disordinato contenente elementi che possono ripetersi. Come suggerisce il nome, l'algoritmo non effettua confronti diretti (come "è $A[i] > A[j]$?"), ma ordina *contando* quante volte ogni elemento occorre nell'input.

### Funzionamento dell'algoritmo

Supponiamo di avere un array $A$ da ordinare e di creare un array ausiliario $C$ (l'array dei contatori). La dimensione dell'array $C$ deve essere sufficiente a contenere almeno l'elemento più grande presente in $A$.

L'algoritmo procede in fasi:

1.  **Fase di conteggio:** Scorriamo l'array $A$ da sinistra a destra. Inizialmente, l'array $C$ ha tutti i valori a 0. Per ogni elemento letto in $A$, incrementiamo il valore nella posizione corrispondente in $C$.
    *   Esempio: Se in $A$ leggiamo il numero 4, scriviamo 1 nella posizione 4 di $C$. Se leggiamo un altro 4, incrementiamo quella posizione a 2. Se leggiamo 5, mettiamo 1 nella posizione 5, e così via. Nelle posizioni corrispondenti a numeri non presenti in $A$, il valore resterà 0.
    *   Formalmente: $C[i]$ contiene il numero di volte in cui l'elemento $i$ occorre nell'array $A$. Qui $i$ in $C$ rappresenta l'indice, mentre in $A$ rappresenta il valore (l'elemento).

    *Nota:* La somma di tutti gli elementi nell'array $C$ deve corrispondere alla dimensione totale dell'array $A$ ($n$). Se così non fosse, abbiamo commesso un errore nel conteggio.

2.  **Fase delle somme cumulative:** Successivamente, modifichiamo l'array $C$ (che chiameremo ora $C'$) affinché ogni cella contenga la somma del suo valore attuale con quello della cella precedente.
    *   Operazione: $C[i] = C[i] + C[i-1]$.
    *   Questo si realizza con un ciclo `for` da 1 a $k$ (dimensione di $C$).
    *   **Significato:** In $C'[i]$ troviamo ora il numero di elementi in $A$ che sono *minori o uguali* a $i$.
    *   *Esempio:* Se $C'[3] = 5$, significa che ci sono 5 elementi in $A$ che sono più piccoli o uguali a 3 (ossia la somma delle occorrenze di 0, 1, 2 e 3).

3.  **Costruzione dell'array ordinato (B):** Creiamo una versione ordinata di $A$, chiamata $B$, utilizzando le informazioni contenute in $C'$.
    *   Per garantire la **stabilità** dell'algoritmo (proprietà fondamentale quando si ordinano oggetti complessi), scansioniamo l'array $A$ **da destra verso sinistra** (dall'ultimo indice allo 0).
    *   Prendiamo l'elemento $A[i]$. Guardiamo in $C[A[i]]$ per sapere dove questo elemento deve andare nell'array $B$.
    *   Il valore $C[A[i]]$ ci dice quanti elementi sono minori o uguali a $A[i]$, quindi ci indica l'ultima posizione disponibile per quel valore in $B$. Poiché gli indici partono da 0, la posizione corretta sarà `C[A[i]] - 1`.
    *   Inseriamo l'elemento in $B$ e decrementiamo di 1 il valore in $C[A[i]]$.
    *   *Perché decrementiamo?* Se ci sono più elementi uguali (es. due numeri 5), il primo che incontriamo (che è l'ultimo dell'array originale dato che procediamo a ritroso) viene messo nella posizione più alta possibile. Decrementando il contatore, il prossimo 5 che incontreremo verrà posizionato nella cella immediatamente precedente, preservando l'ordine relativo originale (stabilità).

### Analisi e Complessità

Lo pseudocodice può essere riassunto in quattro cicli:
1.  Trovare il massimo ($K$) per dimensionare $C$: Tempo $O(n)$.
2.  Inizializzare e riempire $C$ con le frequenze: Tempo $O(n)$.
3.  Calcolare le somme cumulative in $C$: Tempo $O(k)$.
4.  Costruire l'array $B$ scansionando $A$ all'indietro: Tempo $O(n)$.

La complessità totale è $O(n + k)$.
*   L'algoritmo è stabile.
*   **Aspetto negativo:** Non lavora *in loco* (in-place). Richiede memoria aggiuntiva per l'array $C$ e l'array $B$. Tuttavia, l'incapacità di lavorare in loco è un compromesso accettabile per ottenere una complessità lineare, superando il limite $\Theta(n \log n)$.

Se $k$ (il valore massimo o il range dei valori) è dell'ordine di $n$, l'algoritmo è $O(n)$. Se però $k$ è molto grande rispetto a $n$, la complessità degrada e lo spazio richiesto diventa eccessivo.

---

## Il Radix Sort

Il problema del Counting Sort è la dipendenza da $k$. Se i numeri sono molto grandi, l'array $C$ diventa ingestibile. Qui entra in gioco il **Radix Sort**, un'estensione del Counting Sort che funziona bene anche per $k$ grandi. È uno degli algoritmi più antichi, storicamente usato dalle macchine per schede perforate.

### Idea di base
L'idea è ordinare i numeri cifra per cifra, invece che considerare il loro valore intero globale.
Possiamo operare in due modi: partendo dalla cifra più significativa o da quella meno significativa. L'approccio standard (LSD - *Least Significant Digit*) parte dalla cifra meno significativa (unità) verso quella più significativa.

Prendiamo come esempio dei numeri in base 10 (ma vale per qualsiasi base, anche esadecimale):
`329, 457, 657, 839, 436, 720, 355`.

1.  **Prima passata (unità):** Ordiniamo i numeri basandoci solo sull'ultima cifra.
    *   La complessità è $O(n)$ perché le cifre variano solo da 0 a 9 ($k$ è piccolo e costante).
2.  **Passate successive:** Ordiniamo rispetto alla seconda cifra (decine), poi alla terza (centinaia), e così via.

È fondamentale che l'algoritmo usato per ordinare le singole cifre sia **stabile**. Se due numeri hanno la stessa cifra delle decine (es. 3**2**9 e 7**2**0), il loro ordine relativo determinato dalla passata precedente (sulle unità) deve essere preservato. Il Counting Sort è perfetto per questo scopo.

### Complessità del Radix Sort
Se $h$ è il numero di cifre del valore massimo e $n$ è il numero di elementi:
*   Applichiamo il Counting Sort $h$ volte.
*   Ogni passata costa $O(n)$ (dato che il range delle cifre è fisso e piccolo, ad es. 10).
*   Complessità totale: $O(h \cdot n)$.

Per estrarre l' $h$-esima cifra di un numero, usiamo operazioni aritmetiche:
*   Unità: `num % 10`
*   Decine: `(num / 10) % 10`
*   Centinaia: `(num / 100) % 10`
*   Formula generale per la cifra in posizione $h$: `(num / 10^h) % 10`.

In sostanza, il Radix Sort applica il Counting Sort sull'array $h$ volte e, alla fine della sequenza, l'array sarà completamente ordinato.

---

# Lezione 8: Dizionario e tabelle Hash
## Strutture Dati: Il Dizionario

Finora abbiamo parlato di ordinamento. Cambiamo argomento parlando di una struttura dati fondamentale: il **Dizionario**.
Un dizionario rappresenta un insieme dinamico di elementi che supporta tre operazioni principali:
1.  **Insert:** Inserimento di un elemento.
2.  **Delete:** Cancellazione di un elemento.
3.  **Search:** Ricerca di un elemento.

### Confronto con altre strutture
Se utilizziamo un Albero Binario di Ricerca (BST - *Binary Search Tree*), queste operazioni hanno un costo medio di $O(\log n)$. Tuttavia, per i dizionari, il nostro obiettivo è l'efficienza massima: vogliamo eseguire queste operazioni in tempo medio **costante**, ovvero $O(1)$.

Possiamo riuscirci? Sì, analizzando due approcci: la tabella a indirizzamento diretto e le tabelle hash.

## Tabella a Indirizzamento Diretto

Immaginiamo un insieme universo $U$ di chiavi possibili. Se $U$ è piccolo, possiamo usare una **Tabella a Indirizzamento Diretto** (una semplice array $T$).
*   Ogni posizione dell'array corrisponde a una chiave dell'universo.
*   Se l'elemento con chiave $k$ è presente, lo inseriamo nella cella $T[k]$.
*   Se non è presente, la cella $T[k]$ contiene `NULL` (o 0).
*   Non ci sono collisioni (ogni chiave ha il suo posto univoco).

Le operazioni sono banalmente $O(1)$:
*   `Insert(T, k)`: $T[k] \leftarrow \text{elemento}$
*   `Delete(T, k)`: $T[k] \leftarrow \text{NULL}$
*   `Search(T, k)`: Restituisce $T[k]$

### Limiti dell'Indirizzamento Diretto
Il problema sorge quando l'universo delle chiavi $U$ è molto più grande del numero di elementi effettivamente memorizzati ($|S| \ll |U|$).
*   *Esempio:* Se le chiavi sono numeri a 64 bit, l'universo è enorme. Se dobbiamo memorizzare solo 2000 numeri, creare un array di dimensione $2^{64}$ è impossibile per mancanza di memoria e sarebbe un enorme spreco di spazio (quasi tutto vuoto).
Ecco una rielaborazione completa, corretta e ben strutturata del testo contenuto nelle immagini. Il contenuto è stato organizzato in una forma discorsiva e coerente, ideale per un manuale di studio o una dispensa universitaria.

***

## Le Tabelle Hash e la Gestione delle Collisioni

## Introduzione e Motivazioni
L'uso dell'indirizzamento diretto (array semplici) non è sempre applicabile, specialmente quando l'insieme universale delle chiavi $U$ è molto grande. In questi casi, una tabella di dimensione pari a $|U|$ sarebbe uno spreco di memoria inammissibile. La soluzione a questo problema è rappresentata dalle **tabelle hash**.

L'idea fondamentale è trasformare la chiave $k$ in un indice della tabella, non usandola direttamente, ma passandola attraverso una funzione specifica. Questa funzione, detta **funzione hash** $h$, mappa l'elemento $k$ in una posizione all'interno della tabella $T$. Se la nostra tabella $T$ ha cardinalità $m$ (dimensione della tabella) e vogliamo inserire $n$ elementi, sarà la funzione $h$ a decidere dove andrà a finire ogni chiave $k$, indirizzandola in una specifica posizione (indice).

### Il Problema delle Collisioni
Nella pratica, sorge immediatamente un problema: può accadere che due chiavi diverse, $k_i$ e $k_j$, vengano mappate dalla funzione hash nella stessa posizione della tabella. In termini matematici, si verifica che $k_i \neq k_j$ ma $h(k_i) = h(k_j)$. Questo fenomeno è chiamato **collisione**.

Poiché sappiamo che la tabella ha spazio limitato (solo $m$ posizioni per un numero potenzialmente infinito di chiavi), la collisione può avvenire tra due o più chiavi. È necessario, quindi, trovare un meccanismo che ci permetta di risolvere questi conflitti. Esistono diverse strategie, e la prima che analizzeremo è la **risoluzione per concatenazione**.

---

## Risoluzione delle Collisioni per Concatenazione

La soluzione più intuitiva per gestire le collisioni è immaginare che ogni cella della tabella hash non contenga il singolo elemento, ma sia la testa di una lista (o catena). Se due chiavi $k_i$ e $k_j$ finiscono nella stessa posizione, vengono fatte coesistere inserendo l'elemento in testa alla lista corrispondente a quell'indice.

### Operazioni sulle Tabelle Hash con Concatenazione

Possiamo risolvere il problema delle collisioni considerando le singole celle come delle liste. Le funzioni principali diventano:

1.  **Inserimento (`Insert`):**
    Chiamiamo la funzione di inserimento di $k$ nella lista $T[h(k)]$. Prima calcolo la posizione dove va a finire $k$ (ovvero $h(k)$) e poi chiamo una funzione `List-insert` che mette l'elemento in testa alla lista.
    *   **Costo:** L'inserimento in testa avviene in tempo costante $O(1)$.

2.  **Ricerca (`Search`):**
    Per dire se l'elemento c'è o no, chiamo la funzione `List-search`. Questa funzione scorre la lista presente nella posizione $T[h(k)]$. Immaginiamo che la funzione hash $h(k)$ possa essere calcolata in tempo costante; allora tutto dipende da come implemento la ricerca nella lista. Poiché la lista non è ordinata, la `List-search` deve scorrere la lista fino all'identificazione dell'elemento o fino alla fine.

3.  **Cancellazione (`Delete`):**
    Quando cancelliamo un elemento, si presuppone solitamente che sappiamo già dove si trovi (avendo una posizione o un puntatore all'elemento da cancellare). Generalmente, la ricerca ha una complessità superiore alla cancellazione vera e propria; quindi, supponendo di aver già trovato l'elemento, devo soltanto rimuoverlo. In una lista doppiamente linkata, questa operazione avviene in tempo costante $O(1)$.

### Analisi della Complessità: Caso Pessimo e Caso Medio

*   **Caso Pessimo:** Consideriamo l'inserimento di $n$ elementi. Sebbene l'inserimento sia sempre costante, durante la ricerca può succedere che tutti gli elementi vadano a finire all'interno della stessa cella della tabella hash (tutti indirizzati allo stesso indice), creando un'unica lunga lista concatenata con $n$ elementi, mentre tutte le altre posizioni sono vuote. In questo scenario, la ricerca diventa lineare: $O(n)$.
*   **Caso Medio:** Per analizzare il comportamento medio, ci chiediamo come si comporta la tabella se gli elementi sono presi a caso dall'insieme universale $U$.

Un parametro fondamentale è il **fattore di carico** $\alpha$ (alfa), definito come il rapporto tra il numero di elementi e il numero di posizioni:
$$ \alpha = \frac{n}{m} $$
Questo valore indica quanto è piena la tabella:
*   Se $\alpha = 0$, la tabella è vuota.
*   Se $\alpha = 0.5$, ho inserito un numero di elementi pari alla metà delle posizioni.
*   Se $\alpha = 1$, il numero di elementi è identico al numero di posizioni.
*   Se $\alpha > 1$, il numero di elementi supera quello delle posizioni (ci saranno sicuramente collisioni).

#### Ipotesi di Hashing Uniforme Semplice
Per un'analisi realistica del caso medio, ci basiamo sull'**ipotesi di hashing uniforme semplice**. Questa assume che la probabilità che una chiave $k$ venga mandata in una specifica cella $i$ sia uguale per tutte le celle ($1/m$). Inoltre, la probabilità che una chiave venga mandata in una cella è indipendente dalla posizione delle altre chiavi.

Ragioniamo su due casi di ricerca:

1.  **Ricerca senza successo:** Cerco un elemento che non è presente nella tabella. Prolungo la ricerca fino alla fine della lista. La lunghezza media della lista che sta in $T[i]$ è pari a $n/m = \alpha$. L'algoritmo scandisce la lista e si ferma quando trova `null`.
    *   Complessità: $O(1 + \alpha)$.

2.  **Ricerca con successo:** Cerco un elemento che è sicuramente presente. La complessità si basa sul numero di elementi inseriti prima di $k_i$ nella stessa cella. Attraverso calcoli probabilistici (utilizzando variabili indicatrici $X_{ij}$ che valgono 1 se due chiavi collidono), si dimostra che anche in questo caso il numero medio di elementi esaminati è proporzionale al fattore di carico.
    *   Complessità: $O(1 + \alpha)$.

In conclusione, se il fattore di carico è mantenuto ragionevole, le operazioni sulla tabella hash con concatenazione sono molto efficienti.

---

## Le Funzioni Hash

La scelta di una buona funzione hash è critica. Deve distribuire le chiavi in modo uniforme. Vediamo due metodi principali.

### 1. Metodo della Divisione
Prendo la chiave $k$, la divido per $m$ e prendo il resto.
$$ h(k) = k \mod m $$
La funzione restituisce un valore tra $0$ e $m-1$. È un metodo molto veloce.
*   **Esempio:** Se $m=10$ e voglio calcolare la posizione di 53, faccio $53/10$ e prendo il resto, quindi andrà in posizione 3.
*   **Attenzione ai valori di $m$:** Bisogna evitare di scegliere $m$ come una potenza di 2 ($2^p$), perché in quel caso $h(k)$ sarebbe costituita semplicemente dai $p$ bit meno significativi di $k$, ignorando il resto della chiave. Solitamente, con questo metodo, si usano **numeri primi** per $m$, distanti da potenze di 2.

### 2. Metodo della Moltiplicazione
Questo metodo opera in 4 passi:
1.  Prendo una costante $A$ tale che $0 < A < 1$ (Knuth suggerisce $A \approx 0.618$, basato sulla sezione aurea).
2.  Moltiplico $k \cdot A$, ottenendo un numero con parte intera e parte decimale.
3.  Prendo solo la parte decimale (ovvero $k \cdot A \mod 1$).
4.  Moltiplico questo risultato per $m$ e ne prendo la parte intera (funzione floor).

Formula:
$$ h(k) = \lfloor m (kA \mod 1) \rfloor $$

Questo metodo ha il vantaggio che il valore di $m$ non è critico (spesso si sceglie una potenza di 2 per facilitare i calcoli bitwise), ma è leggermente più "pesante" da calcolare rispetto alla divisione.

---

## Indirizzamento Aperto

Un approccio alternativo alla concatenazione è l'**indirizzamento aperto**. In questo modello, gli elementi finiscono nella tabella senza memoria aggiuntiva (niente puntatori o liste esterne). Ogni elemento occupa una cella.

Se si verifica una collisione, la soluzione è dotare la funzione hash di una nuova funzionalità: oltre a fornire un primo suggerimento su dove andare, se la cella è occupata, deve designare un'altra cella, e così via, finché non se ne trova una vuota.

La funzione hash diventa della forma:
$$ h(k, i) $$
dove $k$ è la chiave e $i$ è il numero del tentativo (o ispezione), con $0 \le i < m$.
Questa sequenza di tentativi deve essere una **permutazione** degli indici da $0$ a $m-1$. Se non trovo nessuna cella vuota dopo $m$ tentativi, significa che la tabella è piena. Di conseguenza, il fattore di carico $\alpha$ non può mai superare 1.

### Operazioni nell'Indirizzamento Aperto

1.  **Inserimento (`Insert`):**
    Si effettuano vari tentativi. Uso un ciclo `while` che continua finché il numero di tentativi è $< m$ e la cella esaminata $T[j]$ è diversa da `null`. Se trovo una cella `null`, inserisco $k$. Se il ciclo termina perché ho raggiunto $m$ tentativi, la tabella è piena (overflow).
    *   Complessità: $O(m)$ nel caso peggiore (tutte le celle occupate).

2.  **Ricerca (`Search`):**
    Simile all'inserimento. Si scorre la sequenza di ispezione generata dalla funzione hash. Se trovo la chiave $k$, restituisco `true`. Se trovo `null`, mi fermo e restituisco `false` (l'elemento non c'è). Se esaurisco i tentativi senza trovare né $k$ né `null`, l'elemento non è presente.

3.  **Cancellazione:**
    La cancellazione è problematica. Non possiamo semplicemente impostare la cella a `null`, perché questo interromperebbe la catena di ispezione per eventuali elementi inseriti successivamente che "passavano" per quella cella.
    *   **Soluzione:** Usiamo un simbolo speciale, ad esempio "D" (Deleted). Quando l'inserimento trova "D", può sovrascriverlo. Quando la ricerca trova "D", deve ignorarlo e proseguire l'ispezione.
    *   *Nota:* Questo comporta che, col tempo, le prestazioni possono degradare poiché la tabella si riempie di celle "D", aumentando i tempi di ricerca anche se logicamente ci sono pochi elementi.

### Analisi delle Prestazioni (Indirizzamento Aperto)

Interessa sapere il valore atteso del numero di ispezioni $X$.
Assumiamo l'ipotesi di **hashing uniforme**: ogni permutazione delle celle è ugualmente probabile.

1.  **Ricerca senza successo:**
    Dobbiamo trovare una cella vuota. La probabilità che la prima cella sia occupata è $p_1 = n/m = \alpha$. La probabilità che anche la seconda sia occupata (dato che la prima lo era) è $(n-1)/(m-1)$, e così via.
    Il numero medio di ispezioni è dato da una serie geometrica che si approssima a:
    $$ E[X] \approx \frac{1}{1-\alpha} $$
    *   *Esempio:* Se $\alpha = 0.5$ (tabella piena a metà), in media si fanno $1 / (1 - 0.5) = 2$ tentativi per trovare una cella vuota.

2.  **Ricerca con successo:**
    Si suppone che l'elemento sia già presente. Il costo per trovare un elemento è pari al costo sostenuto per inserirlo. Quando abbiamo inserito l'elemento $i$-esimo, il fattore di carico era inferiore.
    Facendo la media su tutti gli elementi inseriti, e approssimando la sommatoria con un integrale (interpretazione grafica dell'area sotto la curva $1/(1-x)$), otteniamo:
    $$ E[X] \approx \frac{1}{\alpha} \ln \left( \frac{1}{1-\alpha} \right) $$

In sintesi, l'indirizzamento aperto è efficiente per fattori di carico bassi (es. $\alpha < 0.7$), ma le prestazioni degradano molto più rapidamente della concatenazione quando $\alpha$ si avvicina a 1.

Ecco il testo rielaborato, corretto e strutturato come un capitolo di un libro di testo universitario.

***

# Lezione 9: Funzioni Hash e Alberi Binari di Ricerca Bilanciati

In questa lezione approfondiremo le tecniche di gestione delle collisioni nelle tabelle hash tramite indirizzamento aperto e introdurremo le strutture dati ad albero avanzate, specificamente gli alberi Rosso-Neri, per garantire efficienza nelle operazioni di ricerca e inserimento.

## 1. Indirizzamento Aperto: Tecniche di Scansione

Quando si verificano collisioni in una tabella hash ad indirizzamento aperto, è necessario determinare una sequenza di posizioni alternative da sondare. Esistono diverse possibili funzioni hash che possiamo definire per questo scopo: scansione lineare, scansione quadratica e hashing doppio.

### Scansione Lineare
La scansione lineare è la tecnica più semplice e intuitiva. Ci appoggiamo a una funzione hash standard ausiliaria $h'(k)$. La funzione di scansione è definita come:

$$h(k, i) = (h'(k) + i) \mod m$$

Dove $i$ rappresenta il numero del tentativo (da $0$ a $m-1$) e $m$ è la dimensione della tabella.

*   **Primo tentativo ($i=0$):** La funzione calcola $h'(k) \mod m$. Se la posizione è libera, inseriamo la chiave e terminiamo.
*   **Tentativi successivi:** Se la posizione è occupata, incrementiamo $i$. Per $i=1$, controlliamo la cella successiva $(h'(k) + 1) \mod m$. L'operazione di modulo ci garantisce un comportamento circolare: se arriviamo alla fine della tabella (posizione $n-1$), ripartiamo dall'inizio (posizione $0$).

In sostanza, scandiamo le posizioni della tabella in sequenza lineare a partire da $h'(k)$ fino a trovare una cella vuota o scandire l'intera tabella ($m$ tentativi). Sebbene funzionale, questo metodo soffre di un problema noto come **agglomerazione primaria**.

#### Il Fenomeno dell'Agglomerazione Primaria
Questo fenomeno può essere spiegato con un'analogia fisica: il "principio di attrazione dei corpi", secondo cui un corpo con massa maggiore esercita una forza di attrazione più forte sugli altri.

Nelle tabelle hash, le porzioni di celle contigue occupate agiscono come "corpi". Quando una nuova chiave viene mappata in una di queste celle o in una cella adiacente, la scansione lineare la costringerà ad essere inserita alla fine del blocco occupato, estendendolo ulteriormente. Più grande è il blocco, maggiore è la probabilità che una nuova chiave finisca al suo interno, facendolo crescere ancora di più.

Ad esempio, se abbiamo un blocco di 3 celle occupate, una di 1 e una di 2, e dobbiamo inserire una chiave che mappa nella cella precedente al blocco da 3, la probabilità che essa finisca per estendere quel blocco specifico è molto alta. Le chiavi tendono quindi ad accumularsi in pochi blocchi di grandi dimensioni anziché distribuirsi uniformemente, degradando le prestazioni verso $O(n)$.

### Scansione Quadratica
Per mitigare l'agglomerazione primaria, possiamo utilizzare la scansione quadratica. La funzione è definita come:

$$h(k, i) = (h'(k) + c_1 i + c_2 i^2) \mod m$$

Qui, l'offset dalla posizione iniziale dipende quadraticamente dal numero del tentativo $i$. Scegliendo opportunamente le costanti $c_1$ e $c_2$, possiamo garantire che la scansione copra tutte le posizioni della tabella.
Questa tecnica evita l'agglomerazione primaria, ma introduce un problema più lieve noto come **agglomerazione secondaria**: chiavi che hanno la stessa posizione iniziale seguiranno la stessa identica sequenza di scansione. Tuttavia, è decisamente più efficace della scansione lineare.

### Hashing Doppio
L'approccio più robusto è l'hashing doppio, che utilizza due funzioni hash indipendenti, $h'(k)$ e $h''(k)$. La funzione di scansione è:

$$h(k, i) = (h'(k) + i \cdot h''(k)) \mod m$$

In questo caso, non solo la posizione iniziale dipende dalla chiave, ma anche il "passo" di saltellamento (step) dipende dalla chiave (tramite $h''$).
*   Se $i=0$, la posizione è data solo da $h'$.
*   Nei passi successivi, l'incremento è determinato da $h''$.

Questo permette di generare fino a $m!$ (o comunque un numero quadratico $m^2$) sequenze di scansione diverse, diversificando notevolmente i percorsi anche per chiavi che collidono al primo tentativo. È importante scegliere $h''$ in modo che sia coprima con $m$ per garantire la scansione completa della tabella.

---

## 2. Dalle Tabelle Hash agli Alberi Binari di Ricerca

Concludiamo il discorso sulle tabelle hash ricordando che, sebbene molto efficienti in media, non garantiscono prestazioni ottimali nel caso pessimo e non mantengono l'ordine degli elementi.
Passiamo ora agli **Alberi Binari di Ricerca (BST)**. Un BST classico ha grandi potenzialità, garantendo operazioni in tempo logaritmico rispetto al numero dei nodi, ma solo se l'albero rimane bilanciato (altezza minima).

Nel caso pessimo (es. inserimento di chiavi già ordinate), un BST degenera in una lista collegata, portando l'altezza a essere proporzionale al numero di elementi ($O(n)$). Per garantire prestazioni sempre efficienti ($O(\log n)$), abbiamo bisogno di alberi **autobilancianti**.

### Il concetto di Rotazione
Per mantenere un albero bilanciato durante inserimenti e cancellazioni, utilizziamo un'operazione fondamentale chiamata **rotazione**. La rotazione modifica la struttura locale dell'albero spostando nodi e sottoalberi, ma preservando sempre la proprietà fondamentale dei BST (elementi a sinistra < radice < elementi a destra).

Esistono due tipi di rotazione, speculari tra loro:
1.  **Right Rotate (Rotazione a destra):** Si applica su un nodo $y$ che ha un figlio sinistro $x$. L'albero ruota in modo che $x$ diventi il nuovo padre e $y$ diventi il suo figlio destro. Il sottoalbero destro di $x$ (chiamiamolo $\beta$) viene spostato e diventa il figlio sinistro di $y$.
2.  **Left Rotate (Rotazione a sinistra):** Si applica su un nodo $x$ che ha un figlio destro $y$. $y$ diventa il nuovo padre, $x$ diventa il figlio sinistro e il sottoalbero sinistro di $y$ diventa il figlio destro di $x$.

Queste operazioni sono eseguibili in tempo costante $O(1)$ poiché coinvolgono solo la modifica di un numero limitato di puntatori. L'obiettivo è usare le rotazioni per ridurre l'altezza dell'albero o ripristinare le proprietà di bilanciamento.

---

## 3. Alberi Rosso-Neri (Red-Black Trees)

Tra le varie proposte di alberi autobilancianti (come gli alberi AVL), analizziamo gli **Alberi Rosso-Neri**. Questa struttura dati è un albero binario di ricerca che aggiunge un bit di informazione extra per ogni nodo: il colore (Rosso o Nero).

### Le 5 Proprietà (o Regole)
Un albero Rosso-Nero deve rispettare rigorosamente le seguenti 5 proprietà:
1.  **Colore:** Ogni nodo è o rosso o nero.
2.  **Radice:** La radice è sempre nera.
3.  **Foglie:** Tutte le foglie (NIL, nodi sentinella fittizi) sono nere.
4.  **Vincolo Rosso:** Un nodo rosso non può avere figli rossi (non possono esistere due nodi rossi consecutivi in un cammino).
5.  **Altezza Nera:** Per ogni nodo, ogni cammino che porta da quel nodo a una foglia discendente contiene lo stesso numero di nodi neri. Questo numero è chiamato *Black Height* ($bh(x)$).

### Perché queste proprietà funzionano?
La proprietà 5, combinata con la 4, è cruciale. Poiché non possono esserci due rossi di fila, il cammino più lungo dalla radice a una foglia (alternando rosso-nero) può essere al massimo lungo il doppio del cammino più breve (solo neri).
Matematicamente, si può dimostrare che l'altezza $h$ di un albero rosso-nero con $n$ nodi interni è limitata da:
$$h \le 2 \log_2(n+1)$$
Questo garantisce che le operazioni di ricerca, inserimento e cancellazione rimangano sempre $O(\log n)$.

La dimostrazione per induzione si basa sul fatto che un sottoalbero con radice $x$ ha almeno $2^{bh(x)} - 1$ nodi interni. Da qui deriva che l'altezza è logaritmica.

---

## 4. Inserimento in un Albero Rosso-Nero

L'inserimento è l'operazione critica in cui l'albero potrebbe sbilanciarsi. La procedura inizia come un normale inserimento in un BST:
1.  Si inserisce il nuovo nodo $z$ nella posizione corretta.
2.  Si colora il nuovo nodo $z$ di **Rosso**.

Perché rosso? Perché inserire un nodo nero violerebbe immediatamente la proprietà 5 (altezza nera) su quel cammino, che è difficile da correggere globalmente. Inserendo un nodo rosso, rischiamo "solo" di violare la proprietà 4 (due rossi consecutivi) o la 2 (se l'albero era vuoto), problemi che si risolvono localmente.

Se il padre del nuovo nodo $z$ è nero, non c'è violazione e abbiamo finito.
Se il padre è rosso, abbiamo una violazione (rosso su rosso). Dobbiamo intervenire distinguendo tre casi, basati sul colore dello **zio** (il fratello del padre).

Assumiamo che il padre di $z$ sia figlio sinistro del nonno (il caso speculare è simmetrico).

### Caso 1: Lo Zio è Rosso
Se sia il padre che lo zio di $z$ sono rossi:
*   **Azione:** Coloriamo il padre e lo zio di **Nero**. Coloriamo il nonno di **Rosso**.
*   **Effetto:** L'altezza nera non cambia. La violazione "rosso su rosso" è risolta localmente, ma il nonno (ora rosso) potrebbe violare la proprietà con il suo stesso padre.
*   **Procedura:** Spostiamo il problema verso l'alto (risaliamo l'albero di due livelli) e ripetiamo il controllo sul nonno.

### Caso 2: Lo Zio è Nero e $z$ è un figlio "interno"
Se lo zio è nero e $z$ è figlio destro del padre (mentre il padre è figlio sinistro del nonno), si forma una configurazione a "zig-zag" o triangolo.
*   **Azione:** Eseguiamo una **Left Rotate** sul padre.
*   **Effetto:** Questa rotazione trasforma la configurazione nel Caso 3 senza modificare l'altezza nera o risolvere definitivamente il problema dei colori, ma allineando i nodi. Ora $z$ e il padre sono scambiati di ruolo e formano una linea retta.

### Caso 3: Lo Zio è Nero e $z$ è un figlio "esterno"
Se lo zio è nero e il nodo (o il risultato del caso 2) è figlio sinistro del padre (configurazione lineare sinistra-sinistra).
*   **Azione:** Eseguiamo una **Right Rotate** sul nonno. Invertiamo i colori: il padre diventa **Nero** e il nonno diventa **Rosso**.
*   **Effetto:** Questa operazione risolve la violazione dei rossi consecutivi e ripristina le proprietà dell'albero. Non c'è bisogno di propagare ulteriormente la correzione; l'algoritmo termina.

### Esempio Pratico e Considerazioni
Immaginiamo di inserire sequenzialmente chiavi crescenti (es. 4, 11, 21, 14, 12, 17...). In un normale BST otterremmo una lista. Nell'albero Rosso-Nero:
1.  Inseriamo 4 (radice, diventa Nera).
2.  Inseriamo 11 (Rosso). Nessuna violazione.
3.  Inseriamo 21 (Rosso). Padre (11) Rosso, Zio (NIL) Nero. Siamo nel Caso 3 (linea destra-destra). Ruotiamo a sinistra su 4 e ricoloriamo.
4.  La struttura si bilancia automaticamente.

Un'osservazione importante riguarda la complessità: mentre il **Caso 1** può propagarsi ricorsivamente fino alla radice (richiedendo $O(\log n)$ ricolorazioni), i **Casi 2 e 3** eseguono al massimo due rotazioni in totale per terminare l'inserimento. Questo rende l'albero Rosso-Nero estremamente efficiente anche in fase di scrittura.

La capacità dell'albero di reagire a "situazioni di stress" (come l'inserimento ordinato) dimostra la potenza di questa struttura: le rotazioni e le ricolorazioni garantiscono che l'altezza rimanga sempre proporzionale al logaritmo del numero di elementi, assicurando tempi di risposta rapidi e deterministici.

Ecco una rielaborazione completa, corretta e formalizzata delle dispense fornite. Il testo è stato strutturato come un capitolo di un libro di testo o una dispensa universitaria, mantenendo un flusso logico continuo che collega tutti i concetti, dalla fase di ripasso dell'inserimento fino ai dettagli complessi della cancellazione e agli esercizi finali.

***

# Lezione 10: Inserimento e Cancellazione negli Alberi Rosso-Neri

## 1. Ripilogo dell'Inserimento

Riprendiamo il discorso sull'inserimento negli alberi rosso-neri esaminando un esempio pratico. Consideriamo una serie di chiavi da inserire in un albero inizialmente vuoto: **30, 11, 2, 1, 4, 7, 6, 20**, e successivamente aggiungiamo anche la chiave **5** (ipotizzando di averla inserita dopo il 3). L'obiettivo è osservare cosa accade alla struttura dell'albero e come vengono ristabilite le proprietà fondamentali, in particolare la proprietà 4 (i figli di un nodo rosso devono essere neri) e la proprietà 5 (l'altezza nera deve essere costante su tutti i cammini).

Quando inseriamo tutte queste chiavi partendo da un nodo radice, notiamo che l'aggiunta di nodi tende ad aumentare l'altezza nera dell'albero. La cosa fondamentale è che tutte le proprietà, specialmente quelle relative ai colori e al bilanciamento, vengano mantenute o ripristinate dopo ogni inserimento. La bellezza dell'inserimento, e come vedremo anche della cancellazione, risiede nel fatto che molto spesso non si verificano violazioni delle proprietà: in questi casi, possiamo semplicemente inserire il nodo senza dover compiere azioni correttive successive.

Quando invece si verificano delle violazioni, queste vengono risolte molto velocemente. Sebbene esistano operazioni che ristrutturano l'intero albero (che sono più complesse del normale), queste sono eventi rari. L'idea di base è che l'albero si mantiene bilanciato molto spesso, sbilanciandosi solo quando inseriamo chiavi prevalentemente da un lato, costringendoci a ribilanciare la struttura. Solitamente, la "vita" di un albero rosso-nero è costituita da una serie di tante piccole operazioni a costo costante e, solo occasionalmente, da un'operazione più grossa. Un eventuale esercizio d'esame rifletterà questa natura: ci sarà un'operazione un po' più complessa solo dopo alcune operazioni minime.

Esistono operazioni che da un lato riunificano il colore nero (da 2 a 1) e dall'altro lato condividono il colore sui due nodi del livello successivo.

## 2. La Cancellazione: Concetti Generali

Passiamo ora alla cancellazione di un nodo, un'operazione delicata. Prima di affrontare le specificità degli alberi rosso-neri, ricordiamo come si cancella un nodo in un generico **albero binario di ricerca (BST)**. Ci sono tre casi fondamentali:

1.  **Il nodo da cancellare $X$ è una foglia:** Se il nodo è una foglia, la cancellazione è banale: lo si taglia e l'operazione è conclusa.
2.  **Il nodo da cancellare non è una foglia, ma ha un solo figlio:** Anche questo caso è semplice, simile alla gestione di una lista concatenata. Si sostituisce il nodo $X$ con il suo unico figlio al posto del padre.
3.  **Il nodo ha due figli:** Questo è il caso più complesso, poiché la sostituzione diretta non è possibile (non si saprebbe se sostituire con il figlio sinistro o destro). La procedura standard prevede di andare nel sottoalbero di destra e individuare l'elemento più piccolo (che si trova nel ramo più a sinistra di quel sottoalbero). Questo elemento si chiama **successore** di $X$ (chiamiamolo $S$).

In pratica, nell'insieme degli elementi contenuti nell'albero, il successore $S$ è l'elemento che segue immediatamente $X$ in un eventuale ordinamento: è quello "più piccolo dei più grandi". Siamo sicuri che questo $S$ esista avendo il nodo $X$ un figlio destro. Il successore si trova al di sotto del ramo di $X$. La procedura prevede di trovare il successore (in tempo logaritmico rispetto a $n$) e sostituirlo al posto di $X$.

Il successore $S$ sta bene nella posizione di $X$ perché:
*   È più grande di tutti gli elementi che sono a sinistra (essendo il successore più grande di $X$, va bene per tutti quelli che sono a sinistra di $X$).
*   Tra tutti gli elementi che ci sono a destra, $S$ è il più piccolo, quindi rispetta la proprietà di ordinamento anche rispetto al sottoalbero destro.

Una volta sostituito il valore, bisogna cancellare il nodo $S$ originale dalla sua vecchia posizione. La caratteristica fondamentale è che $S$, essendo il minimo del sottoalbero destro, non può avere un sottoalbero di sinistra (altrimenti non sarebbe il minimo). Pertanto, la cancellazione di $S$ ricadrà sempre nel **Caso 1** (è una foglia) o nel **Caso 2** (ha solo un figlio destro).
Quindi, il problema di cancellare un nodo con due figli si riduce sempre a cancellare un nodo che è una foglia o che ha un unico figlio.

## 3. Cancellazione negli Alberi Rosso-Neri

Dopo aver ripassato la logica dei BST, introduciamo i colori.
Supponiamo di voler cancellare un nodo. Se il nodo che cancello è **rosso**, in pratica non succede nulla di grave. Eliminare un nodo rosso non altera il numero di nodi neri lungo i cammini, quindi l'altezza nera rimane invariata e le proprietà non vengono violate.

Il problema sorge quando si cancella un **nodo nero**. Eliminare un nodo nero significa togliere un'unità dal conteggio dei nodi neri di un cammino, mentre tutti gli altri cammini mantengono il loro conteggio originale. Questo crea uno squilibrio: se in un cammino tolgo il nodo nero, dovrei toglierlo anche dagli altri per mantenere l'equilibrio, ma non posso farlo arbitrariamente.
Dobbiamo renderci conto che il nodo nero (o meglio, il colore nero) è una risorsa fondamentale all'interno della struttura, che non si può togliere alla leggera. Quindi l'obiettivo è: cancello la chiave, ma devo fare in modo che quel "peso" nero rimanga lì dentro, nella posizione specifica.

### Casi preliminari di cancellazione del nodo nero

Supponiamo di trovarci in una condizione in cui il nodo nero da cancellare $X$ è una foglia o ha un solo figlio.

1.  **Figlio Rosso:** Se il nodo nero da cancellare ha un figlio rosso, siamo fortunati. Il padre (nodo nero) viene cancellato, e il figlio rosso prende il suo posto. Per mantenere l'altezza nera, basta colorare il figlio (ex rosso) di **nero**. In pratica, il figlio cede il suo colore rosso e acquisisce il nero del padre. Il conteggio dei nodi neri rimane invariato e abbiamo finito.
2.  **Figlio Nero (o nessun figlio):** Se invece il nodo nero ha un figlio nero (o è una foglia, che consideriamo avere figli NIL neri), le cose cambiano. Il nodo nero viene cancellato e il figlio nero subentra. Tuttavia, questo figlio nero non può assorbire il nero del padre semplicemente cambiandosi colore (è già nero!).

Qui nasce il concetto del **Doppio Nero**.

### Il Doppio Nero

La soluzione momentanea per gestire la perdita di un nodo nero senza un sostituto rosso è l'introduzione di un concetto astratto: il **Doppio Nero**.
Quando un nodo nero viene cancellato e sostituito da un figlio nero (o da un nodo NIL), quest'ultimo acquisisce il "nero" del padre in aggiunta al proprio. Lo chiamiamo "doppio nero".

Poiché la proprietà degli alberi rosso-neri dice che un nodo è o rosso o nero (non esiste il "doppio nero"), questa configurazione viola le regole. Immaginiamo questo "doppio nero" come un **gettone** in più che il nodo deve dare a qualcuno.
Disegneremo questo nodo con due cerchietti per indicare che è un doppio nero.
Tutta la procedura di risoluzione che vedremo da ora in poi consiste nel trovare un posto a cui dare questo gettone, o "patata bollente". Dobbiamo spostare questo doppio nero fino a quando qualcuno può assumersene il carico o fino a quando la struttura dell'albero si riequilibra.

La cancellazione avviene quasi sempre in maniera indolore, tranne in questi casi specifici dove dobbiamo eliminare il doppio nero.

## 4. Risoluzione del Doppio Nero: Analisi dei Casi

Per risolvere il doppio nero, dobbiamo guardare il **fratello** ($W$) del nodo con il doppio nero ($Z$). A differenza dell'inserimento, dove guardavamo lo zio, qui la discriminante è il fratello. Ci interessano il colore del fratello e dei suoi figli (i nipoti di $Z$).
Chiameremo $Z$ il nodo col doppio nero, $W$ il fratello, e $A$ e $B$ i figli di $W$.

### Caso 1: Il Fratello $W$ è Rosso
Il nodo $Z$ ha il doppio nero e il fratello $W$ è rosso. Poiché $W$ è rosso, il padre deve essere necessariamente nero.
La strategia è trasformare questo caso in uno degli altri casi (dove il fratello è nero), che sono più facili da gestire.

**Azione:** Eseguiamo una rotazione del fratello $W$ sul padre.
Durante la rotazione, i colori si scambiano: $W$ (rosso) diventa nero, e il padre (nero) diventa rosso.
Il padre scende e diventa il nuovo fratello di $Z$, ma ora è rosso. Tuttavia, $Z$ (che ha ancora il doppio nero) si ritrova con un nuovo fratello che è **nero** (uno dei figli originali di $W$).
Abbiamo quindi trasformato il Caso 1 in un caso dove il fratello è nero, riconducendoci alle situazioni successive.

### Analisi quando il Fratello $W$ è Nero
Se il fratello $W$ è nero, dobbiamo guardare i suoi figli (i nipoti di $Z$). Distinguiamo tre sottocasi principali basati sui figli di $W$.

#### Caso 2: Fratello Nero e entrambi i figli Neri
$W$ è nero e i suoi figli $A$ e $B$ sono entrambi neri.
Questa è una situazione di "stallo". $W$ non può aiutare $Z$ direttamente perché non ha nodi rossi da "spendere" o manipolare.

**Soluzione:** $W$ e $Z$ (doppio nero) cedono entrambi un'unità di nero al padre.
*   $W$ diventa rosso (ha ceduto il suo nero).
*   $Z$ perde il suo "doppio" nero e diventa un nodo nero semplice (ha ceduto il nero extra).
*   Il padre assorbe questo nero extra.

Qui si aprono due scenari per il padre (Caso 2A e 2B):
1.  **Caso 2A (Padre Rosso):** Se il padre era rosso, assorbe il nero extra e diventa **nero**. Abbiamo risolto il problema immediatamente. L'altezza nera è preservata e non ci sono più violazioni. È il caso più semplice e indolore.
2.  **Caso 2B (Padre Nero):** Se il padre era già nero, assorbendo un altro nero diventa **Doppio Nero**. Il problema non è risolto, ma è stato spostato verso l'alto. La procedura riparte ricorsivamente considerando il padre come il nuovo nodo $Z$.
    *   *Nota:* Se il doppio nero risale fino alla radice, il problema svanisce. La radice può semplicemente perdere un'unità di nero (l'intera altezza nera dell'albero diminuisce di 1), senza violare le proprietà interne.

#### Caso 3: Fratello Nero, figlio "vicino" Rosso, figlio "lontano" Nero
$W$ è nero. Il figlio di $W$ più vicino a $Z$ (chiamiamolo $A$) è rosso, mentre quello più lontano ($B$) è nero.
(Esempio: se $Z$ è figlio sinistro, $W$ è destro, $A$ è il figlio sinistro di $W$ e $B$ è il destro).

Questo caso serve come preparazione per il Caso 4.
**Azione:** Facciamo una rotazione su $W$ in modo che il figlio rosso $A$ prenda il posto di $W$. Scambiamo i colori: $A$ diventa nero e $W$ diventa rosso.
Ora ci ritroviamo in una situazione in cui il nuovo fratello di $Z$ è nero, ma ha il figlio **esterno** (lontano) rosso. Questo corrisponde esattamente al Caso 4.

#### Caso 4: Fratello Nero, figlio "lontano" Rosso
$W$ è nero e il suo figlio "lontano" (rispetto a $Z$) è rosso. Il colore dell'altro figlio non importa.
Questo è il caso risolutivo finale.

**Azione:**
1.  Facciamo una rotazione sul padre verso $Z$.
2.  Il fratello $W$ prende il posto del padre e ne eredita il colore (qualunque esso sia).
3.  Il padre (che ora scende) diventa **nero**.
4.  Il figlio rosso di $W$ diventa **nero**.
5.  Il doppio nero su $Z$ viene rimosso (diventa nero semplice).

**Risultato:** Analizzando i nodi, notiamo che da quella parte avevamo un deficit di nero e dall'altra un nodo rosso in più. Con la rotazione e i ricoloramenti, abbiamo ridistribuito il "peso" nero correttamente. Il doppio nero sparisce e la struttura è bilanciata. La procedura termina.

## 5. Riassunto e Complessità

Ricapitolando, i casi non sono cinque, ma fondamentalmente quattro logici:
1.  **Caso 1:** Fratello rosso $\to$ Rotazione $\to$ Diventa fratello nero.
2.  **Caso 2:** Fratello nero, figli neri $\to$ Spostiamo il nero al padre. (Ricorsivo se padre nero, terminale se padre rosso).
3.  **Caso 3:** Fratello nero, figlio interno rosso $\to$ Rotazione per spostare il rosso all'esterno $\to$ Diventa Caso 4.
4.  **Caso 4:** Fratello nero, figlio esterno rosso $\to$ Rotazione e scambio colori $\to$ Fine.

**Costo computazionale:**
Tutti i casi (1, 3, 4) richiedono un numero costante di operazioni (rotazioni e ricoloramenti) e terminano la procedura.
L'unico caso che può richiedere iterazioni è il **Caso 2B**, dove il doppio nero risale l'albero. Poiché l'altezza dell'albero è logaritmica ($O(\log n)$), nel caso peggiore la procedura risale fino alla radice.
Quindi, il costo della cancellazione, come per l'inserimento e la ricerca, rimane proporzionale all'altezza dell'albero: **$O(\log n)$**.

## 6. Esempi ed Esercizi

Esaminiamo alcuni scenari tipici di esercizi d'esame.

**Esercizio 1: Cancellazione in albero completo**
Immaginate un albero rosso-nero completo con 15 nodi (livelli 0, 1, 2, 3 pieni). Potrei colorare tutti i nodi di nero, tranne magari i livelli intermedi, a patto di rispettare le regole. L'esercizio potrebbe chiedere di cancellare nodi (es. le foglie) e verificare come l'albero si ribilancia.
Spesso si inizia cancellando il nodo più piccolo (il minimo). Se il minimo è rosso, la cancellazione è banale. Se è nero, si innescano i casi visti sopra. Ad esempio, cancellando il minimo in un albero dove il fratello è nero con due figli neri (Caso 2), entrambi cedono il nero al padre. Se il padre è rosso, diventa nero e abbiamo finito.

Se continuiamo a cancellare minimi, potremmo trovarci nella condizione in cui il nodo ha un fratello rosso, quindi ruotiamo e ci riconduciamo agli altri casi. Arriveremo alla fine, cancellando nodi fino alla radice, perdendo altezza nera. La memoria muscolare sugli esercizi è fondamentale: anche se la sequenza di operazioni sembra ripetitiva, ogni configurazione può portare a casi diversi (padre rosso vs nero, nipoti rossi vs neri).

**Esercizio 2: Riduzione dell'altezza nera**
Un esercizio particolare richiede di fornire un esempio di albero rosso-nero con 10 nodi tale che, cancellando un nodo specifico, l'albero perda un'unità di altezza nera complessiva.
L'unico modo affinché l'altezza nera diminuisca globalmente è chiamare ricorsivamente la procedura di "Doppio Nero" (Caso 2B) fino a raggiungere la radice.
Per costruire questo esempio, dobbiamo avere un nodo doppio nero il cui fratello è nero con due figli neri, e il padre è anch'esso nero. Questo deve ripetersi a catena fino alla cima dell'albero. Quando il doppio nero arriva alla radice, viene "buttato via", e l'albero diventa valido ma con altezza nera $h-1$.

**Consigli per l'esame:**
I casi sono sempre gli stessi e si ripetono. Le situazioni sono fluide. A volte l'esercizio chiede non solo di disegnare i passaggi, ma di scrivere la struttura finale dell'albero indicando colore e chiave (ad esempio tramite una visita *post-order* o *in-order*). È essenziale esercitarsi a disegnare il "doppio nero" e a spostarlo correttamente applicando rigorosamente le regole dei 4 casi.