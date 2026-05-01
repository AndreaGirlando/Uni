###### Gestione della memoria con bitmap
La memoria viene divisa in unità di allocazione che possono essere piccole come qualche parola o grandi come molti _kilobyte_.
- **Bitmap:** Mappa in cui a ogni unità di allocazione corrisponde un bit. Questo bit assume il valore 0 se l'unità è libera e 1 se è utilizzata (o viceversa).
- **Dimensione dell'unità di allocazione:** È un importante parametro di progettazione. Un'unità di allocazione più piccola genera una bitmap più grande. Tuttavia, anche con un'unità di allocazione piccola di 4 _byte_, 32 _bit_ di memoria richiederanno un solo _bit_ della mappa.
- **Vantaggio:** Poiché la dimensione della bitmap dipende esclusivamente dalla dimensione totale della memoria e dalla dimensione dell'unità di allocazione, questo strumento fornisce un modo semplice per tener traccia della memoria impiegando una quantità fissa di spazio.
- **Svantaggio:** La ricerca dentro la bitmap per una locazione di memoria (quando allochiamo un nuovo processo) è estremamente lenta
![[Pasted image 20260501170015.png|500]]
###### Gestione della memoria con liste collegate
Un altro sistema consiste nel mantenere delle liste collegate di segmenti, dove ogni segmento indica se uno specifico range di indirizzi è occupato o meno:
- **Struttura della lista:** ogni segmento della lista specifica:
    1. Il tipo di occupazione (spazio vuoto H o processo P).
    2. L'indirizzo di partenza.
    3. La lunghezza.        
    4. Il puntatore alla voce successiva.
- In questo modello, la lista dei segmenti è **ordinata per indirizzo**. (La figura sottostante fa riferimento alla stessa situazione di indirizzamento dell'esempio della bitmap)
![[Pasted image 20260501170052.png|500]]

Quando un processo termina la sua esecuzione, ha normalmente due vicini di memoria (fatta eccezione per quando si trova esattamente in cima o in fondo alla memoria). Questi vicini possono essere sia altri processi sia spazi vuoti. Questo scenario porta a quattro possibili combinazioni, illustrate nella figura sottostante:
- **(a):** Aggiornare la lista porta semplicemente a rimpiazzare una voce P con una H.
- **(b) e (c):** Due voci adiacenti vengono fuse insieme e la lista si accorcia di una voce
- **(d):** Tre voci adiacenti vengono fuse in un unico grande spazio vuoto e due elementi vengono rimossi dalla lista.
![[Pasted image 20260501170129.png|500]]

###### Algoritmi di allocazione
il gestore della memoria per decidere come allocare un centro processo in RAM può utilizzare diversi algoritmi:
- **First fit**: È l'algoritmo più semplice. Il gestore della memoria scorre la lista dei segmenti finché non trova il primo spazio vuoto abbastanza grande. Lo spazio individuato viene poi suddiviso in due parti: una per il processo e l'altra per la memoria residua inutilizzata.
- **Next fit**: Variante minore del first fit. Lavora allo stesso modo, ma tiene traccia del posto esatto in cui ha trovato l'ultimo spazio adatto. Alla richiesta successiva, la ricerca riparte da quel punto anziché dall'inizio della lista.
- **Best fit**: Algoritmo molto conosciuto e largamente utilizzato. Cerca all'interno dell'intera lista, dall'inizio alla fine, selezionando lo spazio più piccolo che sia comunque adatto a contenere il processo.
    - **Svantaggi:** È più lento del **_first fit_** (dovendo cercare ogni volta in tutta la lista) e, in maniera sorprendente, genera un maggiore spreco di memoria perché tende a riempire il sistema di spazi minuscoli e inutili.        
- **Worst fit**: Creato per aggirare il problema del best fit, questo algoritmo prende sempre lo spazio disponibile più grande in assoluto, facendo in modo che la porzione di memoria residua sia grande abbastanza da risultare ancora utile per altri processi.

> [!TIP] Miglioramenti
> Tutti e quattro gli algoritmi descritti possono essere velocizzati separando le liste:
> - **Liste separate:** Mantenendo liste separate per i processi e per gli spazi vuoti, gli algoritmi possono dedicare le loro risorse esclusivamente alla ricerca degli spazi.
> - **Ordinamento per dimensione:** La lista degli spazi può essere ordinata dal più piccolo al più grande. In questo modo il **_best fit_** diventa estremamente veloce: appena trova uno spazio idoneo, sa già che è il più piccolo possibile per quel compito, risultando quindi la scelta migliore.
> 	- *Svantaggio*: Rallenta la fase di deallocazione per due motivi. Primo, il sistema perde tempo per reinserire lo spazio appena liberato nella giusta posizione per mantenere la lista ordinata per dimensione. Secondo, cercare i suoi vicini fisici per unire gli spazi liberi risulta molto più complesso.

**Quick fit:** Questo algoritmo mantiene liste separate in base ad alcune delle dimensioni di memoria richieste più comunemente. Ad esempio, utilizza una tabella in cui la prima voce è un puntatore a una lista di spazi di 4 KB, la seconda a una lista di 8 KB, la terza di 12 KB, e così via.
 - **Vantaggi e Svantaggi:** La ricerca di uno spazio della dimensione esatta è molto veloce. Tuttavia presenta lo stesso svantaggio di tutti gli schemi ordinati per dimensione: quando un processo finisce o ne viene fatto lo _swapping_ su disco, trovare i suoi vicini fisici per verificare se sia possibile unire gli spazi liberi risulta un'operazione complessa e dispendiosa.