Questo file è la rielaborazione delle slide [[05_Processore.pdf]], approfondimento con codice assembly qui: [[08_Struttura-base-del-processore]]

Un processore è un singolo circuito integrato in grado di effettuare operazioni decisionali, di solito viene indicato con la sigla CPU (Central Processing Unit), il processore viene concettualmente diviso in 3 unità funzionali:
- **UC** (Control Unit): si affaccia sul [[03_Bus |bus]] e lo arbitra impostando i valori nelle linee ABus, DBus e CBus 
- **Registri**: sono delle memorie di lavoro dove vengono conservati i dati presi dall'UC sul bus per poi poterli far usare dalla ALU durante l'esecuzione
- **ALU** (Arithmetic logic unit): è l'unita di esecuzione effettiva del processore

Ogni processore viene progettato con un set di istruzioni specifico denominato ISA (**Instruction Set Architecture**) o IS (**Instruction Set**), ogni istruzione dell'ISA è contraddistinta da un numero specifico denominato **Operation Code(OP)** ad ogni OP si associa una breve descrizione in lingua naturale che ne ricorda la funzione. 

L'ALU, i registri e molti bus costituiscono il **data path**, che si presenta in questo modo:
![[Pasted image 20241109164814.png]]
Le istruzioni che devono essere usate dalla ALU, vengono caricate nei registri di input (che solitamente sono 2), la ALU fornisce il suo risultato nel registro di output (che solitamente è 1), infine il risultato verrà memorizzato nei registri, quello appena descritto è il ciclo del data path, ovvero la sequenza di passaggi che il computer esegue per eseguire un'operazione tramite la ALU (corrisponde alla fase di execute del ciclo macchina) ^73f111

In base al tipo di Instruction set vengono definiti vari tipi di processore
- **CISC (Complex Istruction Set Computer)**: basati su molte istruzioni complicate
- **RISC (Reduced Istruction Set Computer)**: basati su poche e semplici istruzioni
- **CRISC (Complex Reduced Instruction Set Code)**: quello più usato attualmente, è un architettura ibrida tra CISC e RISC

> [!Nota bene] 
> Il _Program Counter_ (PC) è un registro della CPU che contiene l'indirizzo della prossima istruzione da eseguire.

Un tipico processore opera seguendo una sequenza rigida di passi, che si ripetono fino all’arresto della macchina. Questi passi sono i seguenti:

- **Fetch**: L'Unità di Controllo (UC) carica nel bus degli indirizzi (ABus) il valore del Program Counter, attivando la lettura dalla memoria e caricando l'OpCode dell'istruzione corrente.
- **Decode**: L'UC, interpretando l'OpCode appena letto, determina la lunghezza dell'istruzione e quanti parametri sono necessari. Inizia quindi una fase intermedia, chiamata Operand Fetch, per caricare gli operandi, che si trovano in indirizzi consecutivi a quello dell'OpCode. Gli operandi vengono quindi memorizzati nei registri.
- **Execute**: L'UC avvia il microprogramma corrispondente all’OpCode, utilizzando i parametri precedentemente caricati nei registri. La frequenza con cui vengono eseguiti questi microprogrammi è regolata dal clock della CPU, cioè la frequenza del microprocessore.
- **Store**: Al termine dell’operazione di Execute, i risultati, ora memorizzati nei registri, vengono trasferiti sul bus dall'UC. Questi possono essere scritti in memoria o inviati a dispositivi di input/output (PIO).

Questa sequenza continua a ripetersi per ogni istruzione fino al completamento o arresto del programma.
![[Pasted image 20241109171144.png]]
Questo ciclo può interrompersi se arriva alla CPU un segnale di INTR (della quale abbiamo parlato qui [[04_InputOutput]])

Ogni singola istruzione dell'IS di un processore è contraddistinta da un proprio Op. Code, una determinata lunghezza e un preciso numero di cicli di bus per il suo completamento, il tempo effettivo di esecuzione dell'istruzione è poco influente sulla durata totale di un'istruzione, infatti il bus è un'ordine di grandezza più lento rispetto alla CPU (questo va a creare il già discusso [[01_Architettura#Bottleneck|collo di bottiglia]]) 

---
###### CISC vs RISC 

**CISC**
Le CPU CISC dispongono di un set di istruzioni ampio e complesso, progettato per eseguire operazioni di alto livello con un numero ridotto di istruzioni. Questo comporta però che ogni istruzione sia relativamente più lunga da eseguire, poiché richiede più cicli di clock e implica molteplici passaggi nel data path della CPU.

**RISC**
Le CPU RISC sono progettate con un set di istruzioni più semplice e costante, con comandi che richiedono un solo ciclo di clock per essere eseguiti. Questo approccio rende il data path della CPU molto più lineare e veloce, facilitando una rapida esecuzione delle istruzioni.

| Caratteristica | CISC                                                                                                                                                                                                                                                                                                                   | RISC                                                                                                                                                                                                                                                                                                 |
| -------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Pro**        | - **Flessibilità**: istruzioni complesse eseguono operazioni elaborate con poche istruzioni.  <br> - **Compatibilità**: architettura comune (es. x86), ampio supporto software. <br> - **Efficienza di memoria**: istruzioni più complesse possono ridurre il numero complessivo di istruzioni necessarie.             | - **Alta velocità**: istruzioni semplici eseguite in un singolo ciclo di clock, maggiore rapidità.<br> - **Efficienza energetica**: consumo energetico ridotto per via della semplicità delle istruzioni.<br> - **Facilità di ottimizzazione**: progettazione più semplice per prestazioni ottimali. |
| **Contro**     | - **Bassa efficienza**: esecuzione più lenta per il numero elevato di cicli di clock necessari per ogni istruzione.<br> - **Maggiore consumo energetico**: istruzioni complesse richiedono più energia.<br> - **Difficoltà di ottimizzazione**: architettura complessa, meno ottimizzabile per velocità e prestazioni. | - **Maggiore carico di programmazione**: servono più istruzioni per compiti complessi.<br> - **Maggiore consumo di memoria**: necessità di più istruzioni, che occupano più spazio.<br> - **Minor compatibilità software**: adattamenti necessari per software sviluppato su CISC.                   |
I processori moderni sono ibridi, ovvero usano un tipo di architettura chiamata **CRISC (Complex Reduced Instruction Set Computer)** cercando di ottenere i vantaggi di uno e dell'altro.

Come abbiamo capito il problema principale che causa un rallentamento della CPU è l'accesso alle risorse dal bus, per diminuire questi accessi e quindi aumentare il **throughput** si fa uso delle **cache**, una memoria "tampone" sulla quale vengono caricate le istruzioni più utilizzate dal processore, ad ogni operazione di lettura che fa il processore, controlla se l'informazione che gli serve è già nella cache in modo da poterci accedere in maniere più veloce, se non c'è il processore la richiede tramite il bus e sovrascrive l'istruzione meno usata che si trova nella cache con quella che ha appena richiesto. Esistono 3 tipi di cache:
- **L-1**:  che si trova all'interno del processore
- **L-2**: che è collegata al processore
- **L-3**: sulla motherboard
Si può dire che la cache sia genericamente più veloce del bus, ma più si alza il livello di cache più questa differenza diminuisce.
---
###### Prefetch
Per aumentare il parallelismo di esecuzione viene usata la tecnica del prefetching  che dice alla CPU che anziché limitarsi a caricare dalla memoria l’istruzione o il dato richiesto al momento, recuperi in anticipo anche le istruzioni o i dati immediatamente successivi. A questo scopo, i processori dispongono di una "coda di prefetch", un buffer interno che può contenere una certa quantità di dati consecutivi (ad esempio, i 6 o 8 byte successivi a quello appena caricato). In questo modo, il processore effettua un singolo accesso alla memoria per caricare una serie di valori che possono essere utilizzati subito dopo, sia come istruzioni che come operandi.

Esistono **4 tipi di prefetch**

1. **Prefetching hardware**: le CPU hanno un componente hardware al loro interno che rileva automaticamente i data pattern (dati che servono molte volte e seguono quindi una sorta di pattern nel loro utilizzo) nella memoria e li carica preventivamente nella cache.
2. **Prefetching software**: nel prefetching software si usano delle variabili per suggerire alla CPU che certi dati saranno utilizzati molto spesso, quindi cosi la CPU li caricherà nella cache senza passare ogni volta dal BUS.
3. **Tecnica di ottimizzazione in fase di compilazione** : è un metodo che in fase di compilazione identifica le linee di codice e i dati che vanno utilizzati di più. Questo è un modo per ottimizzare il codice. Funziona con compilatori moderni (C,C++ ecc...)
4. **Prefetching con accesso alla linee di cache**: utilizza le linee di cache per l'accesso alla memoria, quindi trasporta dei blocchi fissi, da 64 byte solitamente, direttamente alla cache.

---
###### L'elaborazione di un'istruzione
L'elaborazione di un'istruzione da parte di un processore con pipeline si articola in cinque fasi principali:

1. **IF (Instruction Fetch)**: Recupero dell'istruzione dalla memoria.
2. **ID (Instruction Decode)**: Decodifica dell'istruzione e lettura degli operandi dai registri.
3. **EX (Execution)**: Esecuzione dell'istruzione.
4. **MEM (Memory Access)**: Interazione con la memoria (valida solo per alcune istruzioni).
5. **WB (Write Back)**: Scrittura del risultato nel registro.

Queste fasi, sequenziali e talvolta sovrapposte, permettono al processore di eseguire le operazioni previste dalle istruzioni.

---
###### Pipeline
Alla coda di prefetch, è stato affiancato un sistema detto **pipeline** che ha lo scopo di sfruttare il concetto di catena di montaggio e quindi di parallelizzare più istruzioni possibili invece di eseguire un'istruzione completamente prima di eseguire la sua successiva. Basta che la prima istruzione sia in fase di decode che la seconda possa essere portata in fase di fetch.
- **Senza pipeline**
  ![[Pasted image 20241109183412.png]]
  
- **Con pipeline**
  ![[Pasted image 20241109183430.png]]
  
Come possiamo ben notare una pipeline a 5 stadi esegue 5 fasi contemporaneamente, questa tecnica sopperisce al problema dell'accesso alla memoria precedentemente discusso. 
L'uso della pipeline introduce anche delle problematiche:
- **Data hazards**: si verifica quando un istruzione richiede dei dati che vengono forniti da un altra istruzione che non ha ancora finito (ritardi di elaborazione o blocchi)
2. **Control hazards:** si verifica quando la pipeline deve gestire dei salti condizionali (tipo il go-to)
3. **Structural hazards:** si verifica quando più istruzioni cercano di accedere alla stessa risorsa (problemi dei filosofi a cena)

Dopo aver dotato i primi processori di pipeline si ci è resi conto che la fase più lenta diventava la fase di execute (quella implementata nella ALU) per sopperire a questo problema si montano più ALU dentro ad un singolo processore. Un processore con più ALU è detto **Superscalare**

---
###### I problemi del prefetching e della pipeline

Tutte queste tecniche vengono vanificate da 2 situazioni:
- Istruzioni di salto: la pipeline viene del tutto persa se il salto ci porta ad un'istruzione lontana da quella che si trova attualmente in pipeline
- Dipendenza dei dati tra le istruzioni: la pipeline viene interrotta
Esempio:
- Istruzione1: A = B + C.
- Istruzione2: D = A + 1. 
- La pipeline che sta servendo l'Istruzione 2 deve interrompersi allo stadio di operand fetch, dato che A non è disponibile se non quando l'Istruzione 1 non è del tutto terminata.

Per cercare di arginare il problema delle istruzioni di salto sono stati introdotti nel processore dei moduli chiamati **Dynamic Branch Prediction** che si occupano di implementare l'**esecuzione predicativa**, una tecnica che fa uso di tabelle simili a memorie cache, per cercare di capire se un'istruzione di salto avverrà o meno (questa tecnica non è deterministica infatti si basa solo su una statistica storica), il problema principale di questa tecnica si ha quando la previsione fatta è sbagliata, infatti in quel caso la pipeline va ripristinata. L'esecuzione predicativa è anche nota come **esecuzione speculativa** quando va a fare una predizione sul codice che potrebbe non essere mai utilizzato.  

Per cercare di arginare il problema delle dipendenze da dato si usa **l'esecuzione fuori ordine(out of order execution)** ovvero: quando il processore individua una dipendenza in un pipeline al posto di buttarla salta l'istruzione dipendente per eseguire istruzioni future, in questo modo la pipeline viene quasi del tutto conservata (un solo stadio rimane fermo fino all'arrivo del dato mancante), alla risoluzione della dipendenza saranno già state eseguite altre istruzioni (quelle che avevamo chiamato istruzioni «future»), con conseguente risalita delle prestazioni. Ci sono però delle condizioni critiche:
- Le istruzioni "future" possono essere eseguite solo se non sono dipendenti a loro volta
- Quando il processore si trova fuori ordine e arriva un interrupt, il processore deve ripristinare il suo stato e riordinare anche il giusto flusso di esecuzione 

**Per poter riordinare il giusto flusso di esecuzione dopo aver saltato e ricalcolato una istruzione con dipendenza, i processori utilizzano una serie di registri d'appoggio (interni e invisibili al programmatore)** su cui memorizzare i calcoli temporanei delle istruzioni fuori ordine. All'atto del riordinamento, per evitare di spostare i valori dai registri interni a quelli effettivamente usati nel data path, i processori sono in grado di rinominare i registri interni nei nomi dei registri effettivi, risparmiando il tempo del trasferimento (**register renaming**).

###### Esistono 3 tipi di dipendenza del dato:
- **RAW (Read After Write)**: Si verifica quando un'istruzione legge un dato che è stato scritto da una precedente istruzione. È chiamata anche dipendenza vera o _data dependency_, perché un dato deve essere prodotto prima di essere letto.
    - Esempio: `Istruzione 1: A = 5`, `Istruzione 2: B = A + 1`. L'istruzione 2 dipende dal valore di `A` prodotto dalla prima.

- **WAW (Write After Write)**: Si verifica quando due istruzioni scrivono nello stesso dato. La seconda scrittura deve avvenire dopo la prima per non sovrascrivere accidentalmente il valore prodotto dalla prima. Questa è una dipendenza anti o di output.
    - Esempio: `Istruzione 1: A = 5`, `Istruzione 2: A = 10`. Qui la seconda scrittura sovrascrive il valore di `A` della prima istruzione.

- **WAR (Write After Read)**: Si verifica quando una istruzione scrive su un dato che viene letto da una precedente istruzione. Questa dipendenza è detta anti-dipendenza, perché la scrittura deve avvenire solo dopo la lettura per evitare che il valore letto sia alterato.
    - Esempio: `Istruzione 1: B = A + 1`, `Istruzione 2: A = 3`. La seconda istruzione deve aspettare che la prima legga `A` prima di scrivere su di esso.

Anche se non esplicitamente, tutte queste innovazioni (pipeline, super-scalarità, predicazione, esecuzione fuori ordine) cercano di implementare un modello di esecuzione parallelo molto studiato nei centri di calcolo, e denominato VLIW (Very Long Instruction Word). In questo modello, oltre alla parallelizzazione dell'esecuzione ottenuta in hardware, si presuppone che lo stesso codice esecutivo generato dai compilatori sia «pre-cucinato» per essere parallelizzato ottimamente dalle CPU.
![[Pasted image 20241110122039.png]]

Questo file è la rielaborazione delle slide [[04_InputOutput.pdf]]
I dispositivi di input/output sono essenziali per acquisire dati dall’utente e per rappresentarli. Ogni dispositivo è associato a un proprio intervallo di indirizzi e utilizza linee di sincronizzazione, chiamate **interrupt**, per comunicare con il processore. Esistono due principali tipi di interrupt:

- **INTR**: segnala una richiesta di interruzione al processore.
- **INTA**: conferma l’avvenuta gestione dell’interruzione.

Quando il dispositivo invia un segnale **INTR**, richiede al processore di sospendere temporaneamente la sua esecuzione per gestire l’interrupt, eseguendo una specifica procedura chiamata **Interrupt Service Routine** (ISR). Esistono anche modalità che permettono agli interrupt di bypassare la CPU e accedere direttamente alla memoria, tramite una procedura chiamata **Direct Memory Access** (DMA). La circuiteria dedicata a collegare il dispositivo al bus e a sincronizzarlo con le altre periferiche è detta **controller della periferica**.

Un tempo, questi dispositivi erano fisicamente visibili all'esterno del computer, mentre oggi si trovano integrati nei circuiti interni. In passato, indirizzi, canali e linee dovevano essere configurati manualmente dall'utente o da un tecnico. Tuttavia, grazie alla tecnologia **Plug&Play**, BIOS, sistema operativo e firmware cooperano per gestire automaticamente la configurazione delle periferiche, sia all’avvio del computer che durante l’installazione di nuovi dispositivi.

Tra gli standard di connessione più diffusi, troviamo: **USB** (Universal Serial Bus), **FireWire** (o IEEE 1394), e **Ethernet** (802.x).
I dispositivi di input/output sono essenziali per acquisire dati dall’utente e per rappresentarli. Ogni dispositivo è associato a un proprio intervallo di indirizzi e utilizza linee di sincronizzazione, chiamate **interrupt**, per comunicare con il processore. Esistono due principali tipi di interrupt:

- **INTR**: segnala una richiesta di interruzione al processore.
- **INTA**: conferma l’avvenuta gestione dell’interruzione.

Quando il dispositivo invia un segnale **INTR**, richiede al processore di sospendere temporaneamente la sua esecuzione per gestire l’interrupt, eseguendo una specifica procedura chiamata **Interrupt Service Routine** (ISR). Esistono anche modalità che permettono agli interrupt di bypassare la CPU e accedere direttamente alla memoria, tramite una procedura chiamata **Direct Memory Access** (DMA). La circuiteria dedicata a collegare il dispositivo al bus e a sincronizzarlo con le altre periferiche è detta **controller della periferica**.

Un tempo, questi dispositivi erano fisicamente visibili all'esterno del computer, mentre oggi si trovano integrati nei circuiti interni. In passato, indirizzi, canali e linee dovevano essere configurati manualmente dall'utente o da un tecnico. Tuttavia, grazie alla tecnologia **Plug&Play**, BIOS, sistema operativo e firmware cooperano per gestire automaticamente la configurazione delle periferiche, sia all’avvio del computer che durante l’installazione di nuovi dispositivi.

Tra gli standard di connessione più diffusi, troviamo: **USB** (Universal Serial Bus), **FireWire** (o IEEE 1394), e **Ethernet** (802.x).

Questo file è la rielaborazione delle slide [[03_Bus.pdf]]

Il bus è l'unità di interconnessione tra i vari componenti della macchina di von Neumann. Esso si presenta come un fascio ordinato di linee, ognuna delle quali può assumere il significato di un bit. Il bus quindi è come un mezzo di trasporto delle informazioni tra la CPU (detta Master) la memoria e I/O (detti slave). 
![[Pasted image 20241013094756.png]]
Da questa immagine riusciamo ad indentificare vari tipi di collegamenti:
- da processore a memoria
- da memoria a processore
- da processore a I/0 
- da I/O a processore
Considerando il processore come master. un'operazione che trasporta un dato dal processore alla memoria è detta operazione di ***Write***, nel verso opposto viene chiamata operazione di ***Read*** il tempo che intercorre tra il segnale di invio dell'operazione e l'operazione stessa si chiama **Lantenza**. Per riuscire a gestire il trasferimento dei dati il bus è diviso in tre diversi tipi di linea:
- ***Address bus*** (ABus)
- ***Data bus*** (DBus)
- ***Control bus*** (CBus)

Per una corretto trasferimento dei dati vengono usati tutti e tre i tipi di bus:
- le linee DBus usate per il trasferimento dei dati
- le linee ABus contenenti le informazioni su gli indirizzi da utilizzare per il trasferimento
- e svariate linee CBus ognuna con uno dei seguenti compiti:
	-  ***I/0-Mem***: un tipo di linea che indica la direzione del trasferimento:
		- **Dal processore alle periferiche I/O**: il valore del bus viene impostato a 1
		- **Dal processore alla memoria**: il valore del bus viene impostato a 0
	- ***R/W***: un tipo di linea che indica il tipo di trasferimento:
		- **Read**: il valore del bus viene impostato a 1
		- **Write**: il valore del bus viene impostato a 0
	- ***WAIT***: un tipo di linea che indica se il trasferimento è stato completato o se il trasferimento è in corso:
		- **Trasferimento completato**: il valore del bus viene impostato su 1
		- **Trasferimento in corso** :  il valore del bus viene impostato su 0

la velocità del bus è determinata da un "orologio" interno, chiamato "clock" che scandisce il tempo in modo costante, come un metronomo, e sincronizza tutte le operazioni che avvengono sul bus. Le dimensioni dei bus possono variare e soprattutto influenzano [[Primo anno/architettura-degli-elaboratori/FileRielaborazioni/03_Bus#Bottleneck|il collo di bottiglia]]:
- **ABus**: la dimensione di questo tipo di Bus specifica la quantità di memoria raggiungibile dai programmi e si calcola e elevando a 2 il numero di ABus
- **DBus**: la dimensione di questo tipo di Bus rappresenta invece il grado di parallelismo del processore, ovvero la quantità di dati che è in grado di elaborare simultaneamente
***<mark class="hltr-green">NB: stiamo parlando della dimensione dei gruppi di bus, infatti un singolo bus porta solo un bit come giù scritto all'inizio</mark>***
All'interno di una scheda madre è difficile vedere i bus di sistema, quindi tutto quello che è dedicato ai bus che siano le linee fisiche o i chip vengono indicati con il nome ***Chipset***. Ovviamente esistono vari tipi di bus ma quello più importanti è il PCI ultimamente molto diffuso e soprattutto la sua variante express usato principalmente per le schede video.

Questo file è la rielaborazione delle slide [[02_Memoria.pdf]]

La memoria dentro i nostri elaboratori viene organizzata in questo modo:
![[Pasted image 20241012142813.png]]
Bisogna ricordare inoltre che più si va in alto nella piramide più la memoria sarà veloce.

La ***memoria principale*** è un contenitore di celle ordinate, ogni cella è ampia un byte e possiede un'indirizzo, dentro queste celle troviamo le istruzioni dei software e i dati di input e/o output, questi valori che troviamo dentro le celle vengono conservati fino a quando la memoria viene alimentata, appunto per questo viene chiamata memoria volatile. La maggior parte della memoria principale è realizzata in tecnologia ==RAM== (***Random Access Memory***), più precisamente usando una sotto-famiglia della RAM ovvero la ==DRAM== (***Dynamic RAM***), questo tipo di RAM viene chiamata cosi perché i dati al suo interno vengono modificati continuamente, i tempi di lettura e scrittura nella RAM sono più alti rispetto alle altre attività di un'elaboratore, questa situazione crea il [[Primo anno/architettura-degli-elaboratori/FileRielaborazioni/02_Memoria#Bottleneck|collo di bottiglia]]. Per riuscire a contrastare il collo di bottiglia sono state create le ==SRAM== (***Static RAM***) che però essendo più costose sono utilizzate solo come speciali memorie di transito tra memoria e processore, vengono chiamate memorie ==Cache==. Lo slot della scheda madre dove vengono inserite le memoria DRAM si chiama ==DIMM== (***Dual Inline Memory Module***) a due facce. All'interno della memoria principale troviamo anche la memoria ==ROM== (***Read Only Memory***) una memoria di sola lettura usata per conservare il ***BIOS*** (Basic Input/Output System). Il BIOS viene usato durante la fase di bootstrap per avviare il dispositivo nel modo corretto, dopo la quale troviamo la fase di ***POST*** (Power on Self Test) dove viene verificato il corretto funzionamento delle varie componenti dell'elaboratore. Questo tipo di memoria anche se è di sola lettura in realtà può essere riprogrammata attraverso delle procedure speciali, come le procedure di configurazione del BIOS.

Questo file è la rielaborazione delle slide [[01_Architettura.pdf]]
Un'**algoritmo** è un insieme finito di istruzioni usate per la risoluzione di un certo lavoro. Quest'ultimo molte volte viene definito come una particolare funzione parziale di una [[#macchina di Turing]] (Alan Turing, matematico britannico) oppure come un programma di una [[#macchina di Von Neumann]] (matematico statunitense).

Le funzioni di base di un'elaboratore possono essere riassunte in 4 macro aree:
- memorizzazione dei dati
- elaborazione dei dati
- trasferimento dei dati
- controllo

Un'esempio di elaboratore è il **computer**, il computer è una macchina che computa ovvero che esegue un certo algoritmo (ovviamente scritto in modo che la macchina stessa lo possa interpretare). Esistono vari tipi di computer: 
- Laptop
- Server
- Desktop
- Tablet/Smartphone

Un qualsiasi computer moderno segue la seguente architettura:
#### *macchina di Von Neumann*

![[Pasted image 20241004212308.png]]
Questo tipo di architettura viene chiamata Macchina di Von Neuman (questa è l'architettura alla quale fa riferimento la definizione di algoritmo sopracitata). Di seguito una descrizione di tutti i componenti:
- La ==**CPU**, o **Central Processing Unit**==, è l'unità centrale di elaborazione di un computer. È il componente principale che esegue le istruzioni dei programmi, gestisce le operazioni logiche e aritmetiche, e coordina il funzionamento delle altre parti del sistema. Come memoria di lavoro usa i registri e la cache. La sua velocita si misura in numero di cicli al secondo (MHz o GHz). La CPU è formata da 4 parti fondamentali:
	- il **program counter**: una locazione di memoria che contiene l'indirizzo dell'istruzione da eseguire
	- il **registro delle istruzioni**: una locazione di memoria contenente l'istruzione da eseguire
	- **ALU (Arithmetic logic unit)**: un sistema che esegue le operazioni aritmetiche e logiche
	- **CU (Control Unit)**: Il sistema di controllo gestisce il flusso di esecuzione delle istruzioni. Fa sì che ogni parte del processore faccia il suo lavoro nel momento giusto, attraverso una serie di cambiamenti di stato. 
- La ==**memoria**==, è un deposito di dati e di istruzioni da eseguire, ne esistono di 3 tipi:
	- **ROM**, o **Read Only Memory**, è una memoria di sola lettura non volatile dove si trovano tutte varie informazioni come le istruzioni usate per l'avvio del pc, o dei parametri necessari per il corretto funzionamento del dispositivo
	- **RAM**, o **Random Access Memory**, è una memoria volatile utilizzata per immagazzinare tutte quelle istruzioni che poi vengono eseguite dal processore
	- La **cache** è una memoria ad alta velocità che si trova all'interno o vicino alla CPU e viene utilizzata per immagazzinare temporaneamente i dati e le istruzioni più frequentemente utilizzate. La sua funzione principale è quella di ridurre i tempi di accesso alla RAM migliorando così le prestazioni del sistema e quindi riducendo il [[#Bottleneck]] tra CPU e RAM. [[02_Memoria |Approfondimento qui]]
- ==**Dispositivi di input**==: come un tastiera ed un mouse [[]]
- ==**Dispositivi di output**==: come un monitor o una stampante
- ==**Memoria di massa**==: un tipo di memoria non volatile che viene usata per immagazzinare grandi file, e ovviamente molto più lenta di qualsiasi altro tipo di memoria sopracitata. La memoria di massa è fondamentale per garantire l'archiviazione stabile di software, documenti, immagini e altri dati digitali, rendendoli accessibili nel tempo. Degli esempi sono: 
	- **Hard disk drive (HDD)**: basato su dischi magnetici rotanti.
	- **Solid State Drive (SSD)**: usa chip di memoria flash, più veloce e resistente rispetto agli HDD.
- ==**BUS**==, tutte queste componenti comunicano tra di loro attraverso i bus. I principali tipi di bus vengono usati per inviare dati o segnali di controllo. [[03_Bus|Approfondimento qui]]

La macchina di von Neumann viene definita logicamente come una terna, ovvero un'insieme di 3 elementi:
- **N** = {0,1,2,3} ovvero l'insieme dei numeri naturali (l'alfabeto della macchina)
- **IS** = {ZERO, INC, SOM, SOT, MOL, DIV, UGUALE, MINORE, SALCOND, ALT} è l’Instruction Set set ovvero un'insieme di istruzioni che la macchina può usare
- P =  {I0, I1, I2, I3, … , I|P| – 1} è una sequenza finita di istruzioni prese dall'insieme IS, questo insieme si chiama programma
Come possiamo ben notare un programma eseguibile dalla macchina von Neumann consiste in una lista di istruzioni che devono essere eseguite dal processore. Ogni istruzione viene sottoposta al ciclo macchina ovvero una serie di passaggi impiegati per l'esecuzione dell'istruzione stessa, di seguito i passaggi appena citati:
1. ==**Legge il contenuto del program counter**==: ovvero l'indirizzo della prossima istruzione da eseguire.
2. ==**Caricamento nel registro delle istruzioni (fetch)**==: Il processore va a recuperare l'istruzione dalla memoria, utilizzando l'indirizzo letto da program counter. Questa istruzione viene quindi inserita nel **registro delle istruzioni**.
3. ==**Decodifica dell'istruzione**==: Una volta che l'istruzione è stata caricata, il processore la decodifica, per capire di che tipo di istruzione si tratta
4. ==**Invio all'ALU**==: Se l'istruzione richiede un'operazione aritmetica o logica, la **unità logico-aritmetica** (ALU) riceve l'istruzione e i dati necessari per eseguire l'operazione.
5. ==**Accesso ai dati**==: Se l'istruzione da eseguire richiede dei dati la control unit li recupera dalla memoria. Se l'istruzione è del tipo SOM(M1, M2) ad esempio, significa che M1 e M2 sono indirizzi in memoria da cui vengono presi i dati. 
6. ==**Esecuzione**==: L'ALU effettua l'operazione richiesta (ad esempio, somma o confronto) utilizzando i dati forniti.
7. ==**Memorizzazione del risultato**==: Una volta ottenuto il risultato, viene registrato nella **locazione di memoria** specificata dall'istruzione.
8. ==**Aggiornamento del contatore**==: Il program counter viene incrementato per puntare all'istruzione successiva.
9. ==**Ripetizione del ciclo**==: Questo ciclo continua fino a quando non viene incontrata un'istruzione speciale che ferma o altera l'esecuzione, come un'istruzione ALT o un salto condizionato che modifica il flusso del programma. 

Un altro modello di elaboratore dalla quale Von Neumann prese spunto fu:
#### *macchina di Turing*

Una **macchina di Turing (o MdT)**  è stata inventata da Alan Turing nel 1936. Questo modello è fondamentale nella teoria della computabilità e fornisce una rappresentazione astratta di come funzionano i calcolatori. Formalmente viene definita in questo modo:
![[Pasted image 20241005110025.png  |  center]]
Di seguito una descrizione di tutti i componenti:
- ==**Nastro==:** Un'unità di memoria esterna infinita, suddivisa in celle, ogni cella contiene un simbolo oppure è vuota.
- ==**Testina di lettura/scrittura (TLS)== :** Un dispositivo che interagisce direttamente con il nastro.
- ==**Unità di memoria interna==:** Una struttura che memorizza lo stato interno della macchina.
- ==**Unità di calcolo==:** Un componente che esegue le operazioni di base.
- ==**Unità di controllo==:** Il "cervello" della macchina, che coordina le altre unità.
- ==**Unità di logica==:** Un componente che si occupa delle operazioni logiche.
Il comportamento di una MdT può essere programmata definendo un'insieme di regole, o quintuple di questo tipo: 
- ==(stato-interno-corrente, simbolo-letto, prossimo-stato-interno, simbolo-scritto, direzione)== 
di seguito degli esempi:
- (0, A, 1, B, -) se la macchina si trova nello stato 0 e legge il simbolo A passa allo stato 1 e scrive sul nastro B e sta ferma
- (1, B, 0, A, >) se si trova nello stato 1 e legge il simbolo B passa allo stato 0 e scrive sul nastro A e si muove di una posizione a destra

È importante sottolineare come l'attenzione di Turing sia rivolta al processo di calcolo, **indipendentemente da come esso avviene fisicamente**. Una M.d.T è un dispositivo ideale, cioè indipendente da ogni sua possibile realizzazione fisica. Una funzione si dice **Tuing-computabile** se almeno una MdT è in grado di computarla con un numero finito di passi. 
##### Condizioni di finitezza 
Una MdT per essere tale deve rispettare le condizioni di finitezza che sono:
- il numero di simboli che usa deve essere fissato e finito
- il numero di caselle del nastro osservabili in una volta è finito
- è possibile ricordare solo un numero finito di stadi precedenti
- le operazioni che può compiere sono:
	1. Cambiare il contenuto di alcune caselle osservate
	2. Cambiare le caselle osservate
	3. Cambiare il proprio stato
	4. Osservare nuove caselle che si trovano ad una distanza prefissata dalla casella osservata
##### Macchina di Turing universale
Se supponiamo di avere una macchina di Turing senza limiti di spazio, di tempo e che non possa commettere errori quest'ultima sarà in grado di calcolare tutte le funzioni calcolabili in ogni singola macchina di Turing, questa macchina la chiamiamo **==Macchina di Turing Universale (MdTU)==**, inoltre deve rispettare sia la condizione di finitezza sopracitata ma anche la condizione di determinatezza spiegata di seguito
##### Condizione di determinatezza 
le azioni di una MdTU devono dipendere solo dai simboli contenuti nella casella osservata in quell'instante e dallo "Stato mentale" corrente, cioè da quello che ricorda dei calcoli precedenti

Da tutto questo Turing formula la seguente Tesi: "*ogni funzione parziale calcolabile con un algoritmo è una funzione parziale calcolabile da una macchina di Turing.*" (appunto per questo all'inizio si parla dell'algoritmo come una funzione parziale della macchina di Turing). Questa tesi ci dice che **ogni [[#Funzione parziale]] calcolabile da un algoritmo può essere calcolata da una macchina di Turing**, poiché ogni algoritmo può essere descritto in termini di un insieme finito di regole.

---
Ulteriori informazioni:

##### Bottleneck
La CPU è progettata per operare a velocità estremamente elevate, elaborando milioni di istruzioni al secondo. Tuttavia, la RAM, sebbene veloce, ha tempi di accesso più lunghi quando la CPU richiede dati o istruzioni deve attendere che questi vengano recuperati dalla RAM. Questo processo di attesa genera un rallentamento, poiché la CPU rimane inattiva in attesa dei dati necessari per continuare l'elaborazione. Per mitigare questo problema, le CPU fanno uso della cache, una memoria più veloce e più vicina al processore, dove vengono conservati i dati e le istruzioni più frequentemente utilizzati. Tuttavia, anche con l'uso della cache, il bottleneck rimane una preoccupazione, specialmente in scenari di carico elevato o quando vengono eseguiti più processi contemporaneamente. In questi casi, se la RAM non è in grado di tenere il passo con le richieste della CPU, si crea un rallentamento significativo, influenzando negativamente l'efficienza complessiva del sistema. 

---
##### Il test di Turing
Turing cercò di rispondere alla domanda "can machines think?", per fare ciò formulo quello che viene chiamato test di Turing ovvero un giudice umano comunica con due interlocutori nascosti: uno è un essere umano, e l'altro è una macchina. Se il giudice non riesce a distinguere chi è la macchina e chi è l'umano basandosi solo sulle risposte fornite, allora si dice che la macchina ha **superato il test** e può essere considerata "intelligente". Fino a qualche mese fa nessuno era riuscito a superarlo tranne ChatGPT-4 di recente

---
##### Funzione parziale
Una funzione parziale è una funzione che non è necessariamente definita per ogni possibile input. Questo significa che per alcuni input, la funzione potrebbe non restituire alcun output. Quest'ultime vengono utilizzate nella definizione di una macchina di Turing universale perché riflettono la realtà infatti non tutte le computazioni terminano con successo. Questo rende il modello più realistico e potente perché è in grado di rappresentare qualsiasi tipo di computazione, sia quelle che vanno bene che quelle che vanno male

---
##### Processi sincroni/asincroni
- ***Processi sincroni***: sono processi che hanno bisogno di essere "sincronizzati" perché sono propedeutici tra di loro.
- ***Processi asincroni***: sono processi che non hanno bisogno di essere sincronizzati perché "lavorano da soli". La maggior parte dei processi asincroni vengono eseguiti dalle GPU quest'ultime hanno moltissimi core rispetto alle CPU proprio perché devono svolgere solo processi asincroni e quindi parallelizzabili, un'esempio dove questa proprietà è fondamentale è nella renderizzazione dello schermo, quest'ultimo è formato da matrici (la risoluzione ci indica quanto sono grandi Es: 720x480) dalla quale è possibile creare delle sottomatrici che vengono lavorate da processi indipendenti (e quindi asincroni), tutte queste sottomatrici vengono riunite nella matrice finale che sarà l'immagine che visualizzeremo a schermo (lo schermo a colori è formato da 3 matrici Red, Green, Blue che definiscono lo standard RGB).