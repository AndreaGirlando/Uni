### La memoria
###### Introduzione alla gerarchia della memoria
I moderni sistemi informatici adottano una **gerarchia della memoria** per bilanciare costi e prestazioni. Questa struttura si articola solitamente in tre livelli:
- **Memoria molto veloce:** Pochi megabyte, estremamente costosa e volatile.
- **Memoria di medio costo:** Qualche gigabyte, abbastanza veloce e volatile (RAM).
- **Memoria su disco:** Alcuni terabyte, non volatile, lenta ma a basso costo.
**Gestore della memoria:** È la componente del sistema operativo incaricata di gestire questa gerarchia.
###### Assenza di astrazione della memoria
Storicamente, dai primi _mainframe_ (prima del 1960) fino ai primi _personal computer_ (prima del 1980), non esisteva alcuna astrazione della memoria. Ogni programma interagiva direttamente con la **memoria fisica**.
###### Il modello di memoria fisica
In questo scenario, il modello presentato al programmatore è un insieme di indirizzi che vanno da 0 a un limite massimo. Ogni indirizzo corrisponde a una cella (solitamente di 8 bit). Un'operazione tipica consisteva, ad esempio, nel muovere il contenuto della locazione fisica 1000 in un registro (_REGISTER1_).

###### Limitazioni e varianti strutturali
In assenza di astrazione, non è possibile eseguire due programmi contemporaneamente: se un programma scrivesse in una posizione usata da un altro, ne cancellerebbe i dati. Esistono tre varianti principali per l'organizzazione del sistema operativo in questo modello:
1. **S.O. in RAM:** Il sistema operativo risiede nel fondo della memoria nella **RAM (Random Access Memory)**.
2. **S.O. in ROM:** Il sistema operativo si trova in cima alla memoria nella **ROM (Read Only Memory)**.
3. **Modello Ibrido:** I driver dei dispositivi risiedono nella ROM in cima alla memoria, mentre il resto del sistema è nella RAM sottostante. Questo modello è tipico dei primi PC con MS-DOS, dove la parte in ROM è nota come **BIOS (Basic Input Output System)**.
![[Pasted image 20260501104611.png|500]]
###### Esecuzione di molteplici programmi senza astrazione

È possibile ottenere un certo grado di parallelismo anche senza astrazione, seguendo diverse strategie:

- **Programmazione con thread**: Un metodo per avere parallelismo è utilizzare molteplici _thread_ all'interno dello stesso contesto di memoria. Essendo thread fanno parte dello stesso processo, quindi non è una vera esecuzione di più programmi.
- **Swapping (Versione primitiva)**: Un'altra possibilità è eseguire un programma alla volta, salvando l'intero contenuto della memoria su disco quando si passa al processo successivo. Finché risiede un solo programma in memoria, non si verificano conflitti.
- **Protezione tramite chiavi (IBM 360):** Con l'ausilio di hardware speciale, è possibile far risiedere più programmi contemporaneamente. L'IBM 360 utilizzava una **chiave di protezione** di 4 bit per ogni cella di memoria. La PWS di un processo conteneva conteneva una chiave di 4 bit che gli permetteva di interagire con la locazione di memoria a lui assegnata. L'hardware intercettava ogni tentativo di accesso alla memoria: se il codice di protezione del processo non coincideva con la chiave nella PSW, l'accesso veniva bloccato.

###### Il problema della rilocazione
Anche se i programmi sono protetti dalle chiavi, sorge il problema degli indirizzi assoluti. Se due programmi da 16 KB vengono caricati uno sopra l'altro, il secondo (caricato all'indirizzo 16.384) fallirà se tenta di eseguire un salto relativo al proprio inizio (es. `JMP 28`), poiché finirà per saltare a un indirizzo nel primo programma invece che nel proprio. In questo esempio vediamo esattamente questa cosa, dopo aver caricato il processo a e b in memoria (c) possiamo notare che:
- *processo A*: il jump 24 funzionerà bene e il processo finisce in modo corretto
- *processo B*: il jump 28 cercherà di saltare ma entra nella memoria del primo processo e andrà in errore
![[Pasted image 20260501105311.png|500]]

Una soluzione a questo problema è la **rilocazione statica:** consiste nel modificare il programma direttamente durante il caricamento in memoria, aggiungendo l'indirizzo di partenza (es. 16.384) a ogni indirizzo del programma.
##### L'astrazione della memoria: lo spazio degli indirizzi
Esporre la memoria fisica presenta due gravi inconvenienti:
1. I programmi utente possono distruggere il sistema operativo.
2. È difficile gestire l'esecuzione contemporanea di più programmi.

Per risolvere i problemi di **protezione** e **riposizionamento**, è stata introdotta l'astrazione dello **spazio degli indirizzi**. Lo **spazio degli indirizzi:** è l'insieme degli indirizzi che un processo può utilizzare per indirizzare la memoria. Questa è un astrazione virtuale e per essere effettuata vengono usate diverse tecniche.

###### Rilocazione dinamica: registri base e limite
Una di queste tecniche, definita come **rilocazione dinamica**, mappa lo spazio degli indirizzi di ogni processo su porzioni diverse di memoria fisica tramite hardware speciale. Questa cosa viene fatta usando due registri della CPU:
- **Registro Base:** Contiene l'indirizzo fisico di partenza del programma in memoria.
- **Registro Limite:** Contiene la lunghezza del programma.
Quando un processo accede alla memoria, l'hardware esegue due passaggi automatici:
1. **Somma:** Aggiunge il valore del registro base all'indirizzo generato dal programma prima di inviarlo al bus.
2. **Controllo:** Verifica se l'indirizzo è uguale o maggiore del valore nel registro limite; in tal caso, genera un errore e interrompe l'accesso.
Su questa soluzione possiamo dire che:
- **Vantaggi:** Permette a ogni processo di avere uno spazio privato degli indirizzi in modo semplice.
- **Svantaggi:** Ogni riferimento alla memoria richiede una somma e un confronto, il che può rappresentare un onere computazionale.

![[Pasted image 20260501163345.png|700]]


###### Gestione del sovraccarico di memoria
Spesso la RAM totale richiesta dai processi supera la memoria fisica disponibile. Per gestire questo scenario si utilizzano due strategie:
- **Swapping:** Consiste nel caricare ciascun processo nella sua interezza in memoria, eseguirlo per un certo tempo e poi riportarlo su disco per far posto ad altri. Questo processo si ripete nel tempo ("copiare" il processo tra disco e RAM).
- **Memoria virtuale:** Consente l'esecuzione di programmi anche quando sono presenti solo parzialmente nella memoria principale.
![[Pasted image 20260501112621.png|500]]

###### Allocazione e gestione dello spazio
Quando lo _swapping_ crea frammentazione (molteplici spazi vuoti sparsi), si utilizza la **Memory Compaction**: i processi vengono spostati il più in basso possibile per combinare tutti i buchi in un unico grande spazio libero. Si cerca di evitare quanto possibile questa procedura perché molto lenta.

L'allocazione è semplice se i processi hanno dimensioni fisse. Tuttavia, se i dati crescono (es. tramite lo _heap_), sorgono difficoltà, qui definiamo due soluzioni:
- **Soluzione 1:** Se un processo non ha spazio per crescere e l'area di _swap_ è piena, il processo deve essere sospeso.
- **Soluzione 2:** Una strategia preventiva consiste nell'allocare una quantità di memoria extra ogni volta che un processo viene creato o spostato, prevedendone la crescita futura. Ma è inefficiente.

Per processi con due segmenti dinamici (lo _heap_ per i dati e lo _stack_ per variabili locali e indirizzi di ritorno), la sistemazione ottimale prevede:
1. **Segmento Dati:** Posizionato subito dopo il testo del programma, cresce verso l'alto.
2. **Segmento Stack:** Posizionato in cima alla memoria allocata, cresce verso il basso.
![[Pasted image 20260501112958.png|500]]
Quando la memoria è assegnata dinamicamente, il sistema operativo deve gestirla. In termini generali, ci sono due modalità di tener traccia dell'utilizzo della memoria: bitmap e liste.

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
il gestore della memoria per decidere come allocare un certo processo in RAM può utilizzare diversi algoritmi:
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