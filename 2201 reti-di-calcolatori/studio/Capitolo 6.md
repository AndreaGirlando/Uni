### Introduzione al livello di collegamento
**Nodo:** qualunque dispositivo che opera a livello di collegamento, cioè al livello 2.
**Collegamento - Link:** canale di comunicazione che collega nodi adiacenti lungo un cammino. Su ogni collegamento, il nodo trasmittente incapsula il datagramma in un **frame del livello di collegamento** (_link-layer frame_) e lo trasmette lungo il collegamento stesso.

Sebbene il servizio di base del livello di collegamento sia il trasporto di datagrammi da un nodo a quello adiacente lungo un singolo canale di comunicazione, i dettagli dei servizi forniti possono variare da un protocollo all’altro.

###### Servizi offerti dai protocolli del livello di collegamento
Di seguito la lista dei servizi offerti dal livello di collegamento:
- **Framing:** quasi tutti i protocolli incapsulano i datagrammi del livello di rete all’interno di un frame del livello di collegamento prima di trasmetterli. I frame sono costituiti da un campo dati, nel quale viene inserito il datagramma, e da vari campi di intestazione. La struttura del frame è specificata dal protocollo.
- **Accesso al collegamento:** un protocollo che controlla l’accesso al mezzo trasmissivo, detto **MAC - Medium Access Control**, specifica le regole con cui immettere i frame nel collegamento. Nei collegamenti punto a punto, con un solo mittente e un solo destinatario, il protocollo MAC è semplice o può non esistere; il mittente può inviare il frame quando il canale risulta libero. Un caso più interessante è quello in cui vari nodi condividono un singolo canale broadcast: in questo caso, il protocollo MAC aiuta a coordinare la trasmissione dei frame da parte dei nodi.
- **Consegna affidabile:** i protocolli del livello di collegamento che forniscono questo servizio garantiscono il trasporto senza errori di ciascun datagramma. Anche alcuni protocolli di trasporto, come TCP, forniscono un servizio di consegna affidabile. Analogamente a quanto avviene al livello di trasporto, la consegna affidabile al livello di collegamento può essere realizzata mediante acknowledgment e ritrasmissioni. Il servizio di consegna affidabile è spesso utilizzato nei collegamenti soggetti a elevati tassi di errore allo scopo di correggere l’errore localmente invece di costringere i protocolli di trasporto o di applicazione a ritrasmettere i dati dalla sorgente alla destinazione.
- **Rilevazione e correzione degli errori:** il nodo ricevente può interpretare erroneamente come 0 un bit trasmesso come 1, o viceversa. Gli errori sui bit sono causati dall’attenuazione del segnale e dai disturbi elettromagnetici. Poiché non è utile inoltrare datagrammi contenenti errori, molti protocolli del livello di collegamento forniscono un meccanismo per rilevarne la presenza. Il nodo trasmittente inserisce nel frame alcuni bit di controllo dell’errore, sui quali il nodo ricevente esegue un controllo. Il rilevamento degli errori al livello di collegamento è solitamente più sofisticato, poiché viene implementato in hardware. 

###### Dov’è implementato il livello di collegamento?
L’implementazione del livello di collegamento di un host coinvolge sia l’hardware sia il software e deve interfacciarsi con le altre componenti hardware dell’host e con il sistema operativo.

La Figura 6.2 mostra la tipica architettura di un host. Per un determinato collegamento, il protocollo del livello di collegamento è sostanzialmente realizzato da un **adattatore di rete** (_network adapter_), noto anche come **scheda di rete** o **NIC - Network Interface Controller**.

![[Pasted image 20260606111432.png|700]]
Il cuore della scheda di rete è il **controller del livello di collegamento** (_link-layer controller_), generalmente costituito da un chip dedicato che implementa molti dei servizi del livello di collegamento La maggior parte delle funzionalità del controller è quindi implementata in hardware.

- **Lato mittente**, il controller preleva un datagramma creato dai livelli superiori della pila di protocolli e memorizzato nella memoria dell’host. Successivamente lo incapsula in un frame del livello di collegamento, riempie i diversi campi dell’intestazione e lo trasmette sul canale di comunicazione seguendo il protocollo di accesso al canale.
- **Lato ricevente**, il controller riceve l’intero frame, ne estrae il datagramma e lo consegna al livello di rete. Se il protocollo del livello di collegamento fornisce un servizio di rilevazione degli errori, il controller trasmittente imposta i bit utilizzati per tale rilevazione, mentre il controller ricevente esegue il controllo.

Una parte delle funzionalità del livello di collegamento è realizzata in software ed eseguita dalla CPU dell’host. Le componenti software implementano tipicamente le funzionalità di livello più alto, come l’assemblaggio delle informazioni di indirizzamento e l’attivazione dell’hardware del controller.

Lato ricevente, il software del livello di collegamento risponde agli interrupt generati dal controller, per esempio in seguito alla ricezione di uno o più frame, gestisce le condizioni di errore e trasferisce il datagramma al livello di rete.

### Framing
Nella trasmissione dei dati è fondamentale utilizzare una **codifica** che permetta al ricevitore di interpretare in maniera univoca il segnale elettrico come una sequenza di bit $0$ e $1$. 

Una semplice codifica a due livelli, nella quale un livello rappresenta $0$ e l’altro rappresenta $1$, presenta però alcuni problemi. Una lunga sequenza di zeri può essere indistinguibile dall’assenza di comunicazione, dall’interruzione della connessione o da un malfunzionamento; analogamente, durante lunghe sequenze costanti di zeri o di uno il ricevitore può perdere il riferimento temporale e non riuscire più a determinare quanti bit siano stati trasmessi. Di conseguenza, distinguere una sequenza continua di $0$ o di $1$ da un’interruzione della trasmissione non è possibile utilizzando soltanto una codifica a due livelli.

![[Pasted image 20260606135238.png|700]]

###### Codifica a tre livelli
Il **three-level encoding** utilizza tre possibili livelli del segnale: **alto**, **zero** e **basso**. Il valore del livello successivo viene determinato applicando le seguenti regole:
- se il prossimo bit è $0$, non avviene alcuna transizione del segnale;
- se il prossimo bit è $1$ e il livello corrente è diverso da $0$, il segnale passa al livello $0$;
- se il prossimo bit è $1$ e il livello corrente è $0$, il segnale passa al livello opposto rispetto al più recente livello diverso da $0$.

Poiché ogni bit uguale a $1$ provoca una transizione, una sequenza di quattro $1$ consecutivi fa compiere al segnale un ciclo completo tra i tre livelli: da un livello diverso da zero passa a $0$, raggiunge il livello opposto, ritorna a $0$ e infine torna al livello iniziale. Queste transizioni periodiche forniscono al ricevitore un riferimento temporale per il **clock recovery**, permettendogli di mantenere una frequenza di lettura coerente con quella di trasmissione. I bit uguali a $0$, invece, non modificano il livello del segnale: il ricevitore ne determina il numero misurando per quanti intervalli di bit il segnale rimane invariato.

![[Pasted image 20260606135401.png|700]]

La codifica a tre livelli non elimina però completamente il problema della sincronizzazione. Una lunga sequenza di $0$ mantiene infatti il segnale costante e non produce transizioni dalle quali il ricevitore possa ricavare il riferimento temporale. Se questa situazione dura troppo a lungo, il clock del ricevitore può disallinearsi rispetto a quello del trasmettitore, rendendo incerto il numero di bit ricevuti. In alcuni protocolli la trasmissione viene quindi preceduta da un **preambolo**, cioè una sequenza nota che consente al ricevitore di sincronizzarsi prima dell’arrivo dei dati. Il preambolo fornisce una sincronizzazione iniziale, ma non impedisce che lunghe sequenze prive di transizioni possano causare successivamente una nuova perdita del sincronismo. Le slide richiamano inoltre la possibile presenza di **ridondanza** nella codifica a tre livelli, senza approfondirne ulteriormente il significato.

###### Esempi di codifica a tre e cinque livelli
La **Fast Ethernet 100BASE-TX** utilizza una codifica a tre livelli, indicati nominalmente con $+1,\mathrm{V}$, $0,\mathrm{V}$ e $-1,\mathrm{V}$. Questi valori non devono essere interpretati come valori perfettamente statici, perché ciascun livello è rappresentato attraverso un intervallo di tensioni tollerabili.

Aumentando il numero dei livelli di tensione diventa possibile trasferire più bit con un singolo simbolo. La **Gigabit Ethernet 1000BASE-T** utilizza cinque livelli: $+1,\mathrm{V}$, $+0{,}5,\mathrm{V}$, $0,\mathrm{V}$, $-0{,}5,\mathrm{V}$ e $-1,\mathrm{V}$. Quattro di questi livelli possono rappresentare le combinazioni binarie $00$, $01$, $10$ e $11$, permettendo di trasmettere due bit alla volta. 
![[Pasted image 20260606135753.png|700]]
###### Criticità della codifica a tre livelli
La codifica a tre livelli costituisce una base per la trasmissione dei dati, ma presenta due criticità principali:
- **non è DC-balanced:** il livello medio della tensione non viene necessariamente mantenuto vicino a $0$, con possibili complicazioni nella trasmissione;
- **può perdere la sincronizzazione:** lunghe sequenze di zeri non producono transizioni sufficienti a mantenere sincronizzato il ricevitore.

Per affrontare questi problemi viene utilizzata la **codifica a blocchi**, che sostituisce gruppi di bit di una determinata dimensione con gruppi leggermente più grandi, come nelle trasformazioni $4\rightarrow5$ e $8\rightarrow10$. Le sequenze vengono scelte in modo da garantire un numero minimo di transizioni e da riservare alcune configurazioni a funzioni di controllo.

###### Codifica 4B5B
La **codifica 4B5B** associa ogni blocco di $4$ bit a un blocco di $5$ bit. L’aggiunta di un bit ogni quattro bit di dati richiede una larghezza di banda superiore del $25$%. La codifica è utilizzata nella Fast Ethernet e consente di selezionare sequenze che limitano la presenza di lunghe successioni prive di transizioni.
![[Pasted image 20260606140058.png|700]]
In questa codifica, non tutte le sequenze di 5 bit rappresentano dati: alcune sono riservate come **simboli di controllo**.
- **Idle - I (`11111`):** viene trasmesso negli intervalli tra due frame, quando il collegamento è attivo ma non ci sono dati da inviare.
- **SSD - Start-of-Stream Delimiter:** indica l’inizio del flusso dati.
- **ESD - End-of-Stream Delimiter:** indica la fine del flusso o del frame.
- **Halt - H (`00100`):** è un simbolo di errore, utilizzato per segnalare una condizione anomala durante la trasmissione.4

###### Codifica 8B10B
La **codifica 8B10B** utilizza $10$ bit di segnale per trasmettere $8$ bit di dati. La sequenza di ingresso viene divisa in due sottosequenze: 
- una composta da $5$ bit
- una composta da $3$ bit. 
La prima viene codificata in $6$ bit attraverso una funzione 5B/6B, mentre la seconda viene codificata in $4$ bit attraverso una funzione 3B/4B. Concatenando le due parti si ottiene la sequenza finale di $10$ bit.

il processo di codifica tiene sotto controllo la **disparità**, cioè la differenza tra il numero di bit $1$ e il numero di bit $0$ trasmessi. Il blocco _Disparity Control_ utilizza questa informazione per guidare la scelta della parola codificata, in modo da compensare eventuali sbilanciamenti accumulati nel flusso. Il bilanciamento non deve necessariamente essere perfetto all’interno di ogni singola parola da $10$ bit, ma viene mantenuto nel corso della trasmissione, evitando una prevalenza prolungata di $1$ o di $0$. In questo modo il valore medio del segnale rimane vicino a zero e la codifica risulta **DC-balanced**.

![[Pasted image 20260606135817.png|700]]

Tra le sequenze a $10$ bit, dodici sono riservate come **sequenze di controllo**. Alcune di esse, chiamate **comma**, permettono al ricevitore di allineare correttamente il flusso di bit e di individuare i confini delle parole codificate.

###### Quantità di informazione trasportata da un simbolo
Il numero di livelli disponibili determina la quantità di informazione che può essere associata a ciascun simbolo. 

Considerando *tre livelli*, indicati con $H$, $M$ e $L$: 
- un singolo step può assumere tre valori. 
- Utilizzando due step consecutivi si ottengono $3^2=9$ combinazioni: $$HH, HM, HL, MH, MM, ML, LH, LM e LL$$
- Con tre step si ottengono $3^3=27$ combinazioni
- con quattro step si ottengono $3^4=81$ combinazioni. 

In generale, utilizzando $k$ step e $n$ livelli, il numero delle possibili combinazioni è $n^k$. Ogni simbolo trasporta una determinata quantità di informazione, misurabile in bit. 

> [!TIP] Che cosa intendiamo per step
> Uno **step** è un intervallo temporale elementare della trasmissione. Durante ogni step il segnale assume uno degli $n$ livelli disponibili.

- Il **numero teorico di bit trasportati da un simbolo** che può assumere $n$ valori distinti è: $x=\log_2 n$
- Il **numero pratico di bit trasportati da un simbolo** è $x=\lfloor\log_2 n\rfloor$ poiché nella applicazione pratica non è possibile usare una frazione del bit

| Livelli | Step | Combinazioni | Informazione teorica in bit | Bit interi utilizzabili | Combinazioni utilizzabili |
| ------- | :--- | :----------- | :-------------------------- | :---------------------- | :------------------------ |
| 3       | 1    | 3            | 1,584963                    | 1                       | 2                         |
| 3       | 2    | 9            | 3,169925                    | 3                       | 8                         |
| 3       | 3    | 27           | 4,754888                    | 4                       | 16                        |
| 3       | 4    | 81           | 6,33985                     | 6                       | 64                        |
| 3       | 5    | 243          | 7,924813                    | 7                       | 128                       |
| 3       | 6    | 729          | 9,509775                    | 9                       | 512                       |
| 3       | 7    | 2187         | 11,09474                    | 11                      | 2048                      |
| 3       | 8    | 6561         | 12,6797                     | 12                      | 4096                      |
| 3       | 9    | 19683        | 14,26466                    | 14                      | 16384                     |
| 3       | 10   | 59049        | 15,84963                    | 15                      | 32768                     |

Il valore teorico aumenta in modo continuo, ma le combinazioni binarie effettivamente utilizzabili devono essere una potenza intera di due.

###### Limite teorico del bit rate
> [!TIP] Che cosa è il bit rate
> **Bit rate:** quantità di bit trasmessi in un secondo attraverso un canale di comunicazione. Si misura in **bit per secondo (bps)** e indica la velocità effettiva con cui vengono trasferite le informazioni.

Moltiplicando la quantità di informazione associata a ogni simbolo per il numero di simboli trasmessi al secondo si ottiene il limite teorico del bit rate: $$R_{\text{teorico}}=S\cdot\log_2 n$$
dove $S$ rappresenta il numero di simboli o step trasmessi al secondo e $n$ il numero di livelli disponibili. Di seguito uno specchietto dove vediamo l'andamento all'aumentare degli step e dei livelli, con le seguenti ipotesi: 
- segnale a 3 livelli
- in un secondo abbiamo 12 step quindi ogni step dura $1/12$ di secondo.
![[Pasted image 20260606162259.png|700]]

| Step per simbolo | Combinazioni totali |         Bit per simbolo          | Combinazioni utilizzabili |                   bps                   |
| :--------------: | :-----------------: | :------------------------------: | :-----------------------: | :-------------------------------------: |
|        1         |       $3^1=3$       |    $\lfloor\log_2 3\rfloor=1$    |          $2^1=2$          |  $\frac{12}{1}\cdot1=12\ \mathrm{bps}$  |
|        2         |       $3^2=9$       |    $\lfloor\log_2 9\rfloor=3$    |          $2^3=8$          |  $\frac{12}{2}\cdot3=18\ \mathrm{bps}$  |
|        3         |      $3^3=27$       |   $\lfloor\log_2 27\rfloor=4$    |         $2^4=16$          |  $\frac{12}{3}\cdot4=16\ \mathrm{bps}$  |
|        4         |      $3^4=81$       |   $\lfloor\log_2 81\rfloor=6$    |         $2^6=64$          |  $\frac{12}{4}\cdot6=18\ \mathrm{bps}$  |
|        6         |      $3^6=729$      |   $\lfloor\log_2 729\rfloor=9$   |         $2^9=512$         |  $\frac{12}{6}\cdot9=18\ \mathrm{bps}$  |
|        12        |   $3^{12}=531441$   | $\lfloor\log_2 531441\rfloor=19$ |      $2^{19}=524288$      | $\frac{12}{12}\cdot19=19\ \mathrm{bps}$ |
Raggruppando un numero crescente di step in ciascun simbolo, si riescono a sfruttare in modo più efficiente le combinazioni offerte dai tre livelli del segnale. Il bit rate effettivo si avvicina quindi progressivamente al limite teorico, senza però superarlo, perché ogni simbolo deve rappresentare un numero intero di bit. Nel caso considerato, con 12 step al secondo e 3 livelli, il limite teorico è pari a 12 · log₂(3) ≈ 19,02 bps.

Questa relazione prende il nome di Misura di Hartley e indica la quantità massima di informazione trasportabile quando tutti i simboli disponibili sono equiprobabili. Essa rappresenta un caso semplificato del concetto di entropia informativa di Shannon.


### Tecniche di rilevazione e correzione degli errori
Il rilevamento e la correzione degli errori sui bit sono due servizi generalmente forniti dal livello di collegamento.
![[Pasted image 20260606111407.png|700]]

La Figura 6.3 schematizza lo scenario di riferimento. Al nodo trasmittente, ai dati $D$ che devono essere protetti dagli errori vengono aggiunti alcuni bit chiamati **EDC - Error-Detection and Correction**. I dati $D$ e i bit EDC vengono inviati all’interno di un frame. Il nodo ricevente legge una sequenza di bit $D'$ ed $EDC'$, che può essere diversa da quella originale a causa della modifica di alcuni bit durante il transito. Il ricevente deve determinare se $D'$ coincida con $D$, potendo utilizzare soltanto $D'$ ed $EDC'$.

Le tecniche disponibili non consentono sempre al nodo ricevente di rilevare tutti gli errori verificatisi nei bit. Anche utilizzando bit per la rilevazione degli errori, è possibile che si presentino **errori non rilevati**: il nodo ricevente potrebbe quindi non accorgersi che le informazioni ricevute contengono errori.

Le tre tecniche considerate per rilevare gli errori nei dati trasmessi sono:
- il **controllo di parità** (_parity check_);
- il **checksum**;
- il **controllo a ridondanza ciclica**, o **CRC**.

###### Controllo di parità
La forma più semplice di rilevamento degli errori utilizza un unico **bit di parità**. Si supponga che le informazioni da inviare, indicate con $D$ nella Figura 6.4, siano costituite da $d$ bit.
- In uno schema di **parità pari**, il mittente aggiunge un bit e ne sceglie il valore in modo che il numero complessivo di bit uguali a 1 nei $d+1$ bit trasmessi sia pari. I bit trasmessi comprendono quindi l’informazione originale e il bit di parità. 
- In uno schema di **parità dispari**, il valore del bit di parità viene scelto in modo che il numero complessivo di bit uguali a 1 sia dispari.
![[Pasted image 20260606111732.png|700]]Con un singolo bit di parità, il ricevente deve semplicemente contare il numero di bit uguali a 1 tra quelli ricevuti. In uno schema di parità pari, se rileva un numero dispari di bit uguali a 1, sa che si è verificato almeno un errore su un bit. Se, tuttavia, si verifica un numero pari di errori sui bit, l’errore non viene rilevato. Quando la probabilità di errore è bassa e si può assumere che gli errori siano indipendenti, la probabilità che si verifichino più errori nello stesso pacchetto è estremamente ridotta e un singolo bit di parità potrebbe risultare sufficiente. È stato però rilevato statisticamente che gli errori tendono generalmente a verificarsi in gruppi di bit consecutivi, detti _burst_, invece che in modo indipendente. Occorre quindi adottare una strategia più efficace per la rilevazione degli errori.

Una semplice generalizzazione del bit di parità fornisce anche un approccio alla correzione dell’errore. La Figura 6.5 illustra una versione bidimensionale dello schema di parità.

![[Pasted image 20260606111746.png|700]]

In questo caso, i $d$ bit dei dati $D$ sono suddivisi in $i$ righe e $j$ colonne, per ciascuna delle quali viene calcolato un valore di parità. Si ottengono complessivamente $i+j+1$ bit di parità, utilizzati per la rilevazione degli errori nei frame del livello di collegamento.

Si supponga che si verifichi un solo errore nei $d$ bit originali. Nello schema di parità bidimensionale, i bit di parità relativi alla colonna e alla riga che contengono il bit errato permettono di individuare l’errore. Il ricevente può quindi non soltanto rilevare che si è verificato un errore, ma anche utilizzare gli indici della riga e della colonna per identificare e correggere il bit alterato.

La Figura 6.5 mostra un esempio nel quale il bit uguale a 1 nella posizione $(2,2)$ viene corrotto e assume il valore 0. L’errore può essere sia rilevato sia corretto dal ricevente. Sebbene l’esposizione sia concentrata sui $d$ bit originali, anche un errore che interessa gli stessi bit di parità è rilevabile e correggibile.

La capacità del ricevente di rilevare e correggere gli errori viene chiamata **FEC - Forward Error Correction** . Le tecniche FEC sono utili perché possono diminuire il numero di ritrasmissioni e permettono al ricevente di correggere immediatamente gli errori. In questo modo si evitano NAK e ritrasmissioni 

###### Checksum
Nelle tecniche basate sul **checksum**, i $d$ bit dei dati della Figura 6.4 vengono trattati come una sequenza di numeri interi da $k$ bit. Un metodo semplice consiste nel sommare questi interi da $k$ bit e utilizzare i bit del risultato per la rilevazione degli errori (come abbiamo già visto nel capitolo 3).

I metodi basati sul checksum forniscono una protezione dagli errori piuttosto limitata rispetto alle tecniche di controllo a ridondanza ciclica. Ci si può quindi chiedere perché al livello di trasporto venga utilizzato il checksum, mentre al livello di collegamento venga impiegato il CRC.

Il livello di trasporto viene generalmente eseguito dal software del sistema operativo dell’host. Poiché la rilevazione degli errori al livello di trasporto è implementata in software, è fondamentale disporre di schemi di rilevazione semplici e veloci. La rilevazione degli errori al livello di collegamento viene invece implementata mediante hardware dedicato nelle schede di rete, che possono eseguire più rapidamente le operazioni più complesse richieste dal CRC.

###### Controllo a ridondanza ciclica

Una tecnica di rilevazione degli errori largamente utilizzata è basata sui **codici di controllo a ridondanza ciclica**, o **CRC**. I codici CRC sono chiamati anche **codici polinomiali**, poiché la stringa di bit da trasmettere può essere interpretata come un polinomio i cui coefficienti corrispondono ai bit della stringa. Le operazioni sulla stringa vengono quindi interpretate come operazioni di aritmetica polinomiale.

Si considerino $d$ bit che costituiscono i dati $D$ da trasmettere. Si supponga inoltre che sorgente e destinazione abbiano concordato una stringa di $r+1$ bit, chiamata **generatore** e indicata con $G$. È necessario che il bit più significativo di $G$ sia uguale a 1.

![[Pasted image 20260606112144.png|700]]

Dato un blocco di dati $D$, il mittente sceglie $r$ bit addizionali, indicati con $R$, e li unisce a $D$. In questo modo ottiene una stringa di $d+r$ bit che, interpretata come numero binario, deve essere esattamente divisibile per $G$.

> [!TIP] Generatori utilizzati
> Sono stati definiti generatori standard di 8, 12, 16 e 32 bit. Attualmente diversi protocolli a livello di collegamento utilizzano questo generatore fatto da 32 bit: $G_{CRC-32} = 100000100110000010001110110110111$

Il controllo eseguito dal ricevente è semplice: se la divisione della stringa ricevuta di $d+r$ bit per $G$ produce un resto diverso da 0, il ricevente sa che si è verificato un errore; in caso contrario, i dati vengono accettati come corretti.

Tutti i calcoli del CRC sono eseguiti mediante **aritmetica modulo 2**. L’addizione e la sottrazione sono operazioni identiche ed entrambe equivalgono all’operazione di OR esclusivo, o XOR, applicata ai bit degli operandi. Le moltiplicazioni e le divisioni vengono eseguite come in base 2, moltiplicare una stringa per $2^k$ equivale a farla scorrere verso sinistra di $k$ posizioni e viceversa per la divisione.

> [!EXAMPLE] Esempio dell'uso dello XOR al posto della sottrazione
> Per esempio, valgono:
> - $1011\operatorname{XOR}0101=1110$;
> - $1001\operatorname{XOR}1101=0100$;
> - $1011-0101=1110$;
> - $1001-1101=0100$.

Dati $D$ e $R$, la quantità $D\times 2^r\operatorname{XOR}R$ produce la stringa di $d+r$ bit mostrata nella Figura 6.6 (shiftiamo verso sinistra $D$ aggiungendo $r$ zeri). Per calcolare $R$, il trasmittente deve trovare un valore tale che esista un numero $n$ per il quale valga: $$D\times 2^r\operatorname{XOR}R=nG$$
In altri termini, $R$ deve essere scelto in modo che la stringa $D\times 2^r\operatorname{XOR}R$ sia divisibile per $G$ senza resto. Eseguendo l’operazione XOR con $R$ su entrambi i membri si ottiene: $$D\times 2^r=nG\operatorname{XOR}R$$
Questa ha la stessa forma della divisione con resto: $$[\text{dividendo = } \text{quoziente}\cdot\text{divisore}+\text{resto}] \rightarrow \underbrace{D\cdot 2^r}_{\text{dividendo}} \quad  \mathrel{\Huge =} \quad\underbrace{n}_{\text{quoziente}} \quad \underbrace{G}_{\text{divisore}} \quad \underbrace{\operatorname{XOR}}_{+} \quad \underbrace{R}_{\text{resto}}$$
Questa espressione mostra che, dividendo $D\times 2^r$ per $G$, il resto ottenuto è precisamente $R$. Pertanto: $$R=\operatorname{resto}(\frac{ D\times 2^r}{G})$$Il CRC può rilevare errori a burst di lunghezza inferiore a $r+1$ bit: tutti gli errori consecutivi che interessano non più di $r$ bit vengono quindi rilevati.


> [!EXAMPLE] Esempio calcolo del CRC
> Dati $D=101110$, $G=1001$ (concordato tra mittente e destinatario) e $r=3$.
> - Si aggiungono $r=3$ zeri a $D$: $$D\cdot 2^r=101110000$$
> - Ora si divide $101110000$ per $1001$, usando lo **XOR** al posto della sottrazione: $$1011\oplus1001=0010$$
> - Si abbassa il bit successivo e si continua nello stesso modo:$$0101\oplus0000=0101$$$$1010\oplus1001=0011$$$$0110\oplus0000=0110$$$$1100\oplus1001=0101$$$$1010\oplus1001=0011$$
> - Il resto è formato dagli ultimi $r=3$ bit: $$\boxed{R=011}$$
> - Il resto viene inserito al posto dei tre zeri aggiunti: $$101110000\oplus000000011=101110011$$
> - Quindi i nove bit trasmessi sono: $$\boxed{101110011}$$
> Dividendo $101110011$ per $1001$, il resto ottenuto è $000$,  se nel destinatario questa divisione non ritorna zero allora significa che ci sono stati degli errori durante la trasmissione.
> ![[Pasted image 20260606112206.png|700]]

###### Distanza di Hamming e rilevazione degli errori
Durante la trasmissione sul mezzo fisico, il rumore elettromagnetico può alterare uno o più bit, trasformandoli da `0` a `1` o viceversa. Poiché una sequenza binaria, a differenza del linguaggio naturale, non contiene informazioni semantiche che permettano di ricostruire il messaggio originale dal contesto, per rilevare e correggere gli errori è necessario introdurre della ridondanza e stabilire quali sequenze siano valide.

**Codeword:** sequenza completa trasmessa dal mittente, composta dai bit di dati e dagli eventuali bit di controllo.

**Vocabolario:** insieme delle codeword valide utilizzate dal sistema. Per parole lunghe $n$ bit esistono $2^n$ combinazioni possibili; tuttavia, nei codici per la rilevazione e la correzione degli errori soltanto alcune vengono considerate valide. Le combinazioni escluse permettono di riconoscere che una sequenza ricevuta è stata alterata.

**Distanza di Hamming:** numero di posizioni nelle quali due codeword della stessa lunghezza contengono bit differenti, cioè il numero di bit da modificare per trasformare una sequenza nell’altra. Si calcola eseguendo lo **XOR** tra le due sequenze e contando gli `1` presenti nel risultato, poiché ciascun `1` corrisponde a una posizione differente.

```text
10001100
11000100
--------
01001000
```

Il risultato contiene due `1`, quindi la distanza di Hamming tra `10001100` e `11000100` è $2$.

La distanza può essere interpretata geometricamente considerando le sequenze come punti di uno **spazio di Hamming**: cambiare un bit equivale a compiere un passo tra due punti. Se due codeword valide hanno distanza $3$, sono necessarie almeno tre modifiche per trasformare direttamente l’una nell’altra.

###### Distanza minima di un codice
La **distanza minima**, indicata con $d_{\min}$, è la più piccola distanza di Hamming tra due codeword valide e distinte appartenenti allo stesso vocabolario:
$$d_{\min}=\min{d_H(x,y)\mid x\neq y,\ x\text{ e }y\text{ sono codeword valide}}$$
Essa rappresenta la separazione minima garantita tra tutte le parole valide del codice e determina il numero di errori rilevabili o correggibili.

![[Pasted image 20260606133103.png|500]]

Nel vocabolario rappresentato, le codeword più vicine differiscono in tre posizioni, mentre alcune coppie differiscono in sei; pertanto, $d_{\min}=3$. Ridurre il vocabolario a poche codeword sufficientemente distanti diminuisce il numero di sequenze valide, ma lascia disponibili più combinazioni per riconoscere e, in alcuni casi, correggere gli errori.

**Rilevazione degli errori**
Per **rilevare** fino a $e$ errori è necessario che nessuna sequenza ottenuta modificando al massimo $e$ bit di una codeword valida coincida con un’altra codeword valida. La condizione richiesta è: $$d_{\min}\geq e+1$$
*Dimostrazione:*
1. Supponiamo di trasmettere la Parola Valida $A$.
2. Durante il tragitto, un'interferenza introduce $e$ errori, spostando il dato ricevuto di $e$ passi lontano da $A$.
3. Affinché il ricevitore si accorga dell'errore (e non lo scambi per un messaggio legittimo), il punto in cui atterra il messaggio corrotto **non deve mai** coincidere con una seconda Parola Valida $B$.
4. Pertanto, la distanza totale $d$ che separa l'isola $A$ dall'isola $B$ deve essere strettamente maggiore del numero di "passi falsi" $e$ causati dall'errore ($d > e$).
5. Lavorando nel dominio dei bit e dei numeri interi, dire $d > e$ equivale ad affermare che $d \ge e + 1$.

**Correzione degli errori**
Per **correggere** fino a $e$ errori non è sufficiente riconoscere che la sequenza ricevuta è invalida: il ricevente deve anche poter determinare senza ambiguità quale codeword sia stata trasmessa originariamente. La condizione necessaria è:

$$d_{\min}\geq 2e+1$$

*Dimostrazione*:
1. Immaginiamo di tracciare una "sfera di attrazione" attorno a ogni Parola Valida sulla nostra mappa. Il raggio di questa sfera è $e$ (il limite massimo di bit che il nostro hardware può correggere).
2. Se un dato in transito subisce $e$ errori, cadrà comunque all'interno della sfera della sua Parola Valida originale. Il ricevitore applicherà la correzione "riportandolo" al centro esatto di quella specifica sfera.
3. **Il problema dell'ambiguità:** Se le sfere di due Parole Valide $A$ e $B$ si toccassero o si sovrapponessero, un dato corrotto che dovesse cadere nella zona di intersezione risulterebbe illeggibile. Il ricevitore non avrebbe modo di stabilire se il messaggio originale fosse $A$ (spostatosi verso destra) o $B$ (spostatosi verso sinistra).
4. Per evitare categoricamente questa sovrapposizione fatale, la distanza lineare $d$ tra il centro di $A$ e il centro di $B$ deve superare la somma dei due raggi ($e + e = 2e$).
5. Se la distanza fosse esattamente $2e$ (ad esempio $d=2$ per correggere $e=1$ errore), il pareggio creerebbe un vicolo cieco: un errore di 1 passo porterebbe il dato esattamente a metà strada tra le due isole, a distanza 1 da entrambe, impedendo al ricevitore di prendere una decisione certa.
6. È quindi strutturalmente necessario almeno un passo "cuscinetto" in più per rompere l'equilibrio. Sommando questo margine di sicurezza ai due raggi, otteniamo il limite assoluto: $d \ge 2e + 1$.
![[Pasted image 20260606122514.png|800]]

###### Codici di Hamming
La **distanza di Hamming** fornisce quindi il criterio teorico per stabilire quanti errori un codice può rilevare o correggere. Su questo principio si basa il **codice di Hamming**, che introduce bit di controllo in posizioni specifiche per individuare la posizione di un eventuale bit errato e correggerlo.
- i **bit di controllo** $b_r$ occupano le posizioni corrispondenti alle potenze di $2$, cioè $1,2,4,8,16,\ldots$;
- i **bit di dati** $d_x$ occupano tutte le altre posizioni, come $3,5,6,7,9,10,11,\ldots$.
Per determinare quali bit di controllo supervisionano una posizione, si scompone il suo indice in potenze di $2$, oppure si osservano gli `1` della sua rappresentazione binaria

|Posizione decimale|Posizione binaria|Scomposizione|Bit di controllo di riferimento|Tipo|
|:-:|:-:|:-:|:--|:--|
|**1**|`0001`|$1$|$b_1$, che controlla anche sé stesso|Controllo|
|**2**|`0010`|$2$|$b_2$, che controlla anche sé stesso|Controllo|
|**3**|`0011`|$2+1$|$b_2$ e $b_1$|Dati|
|**4**|`0100`|$4$|$b_4$, che controlla anche sé stesso|Controllo|
|**5**|`0101`|$4+1$|$b_4$ e $b_1$|Dati|
|**6**|`0110`|$4+2$|$b_4$ e $b_2$|Dati|
|**7**|`0111`|$4+2+1$|$b_4$, $b_2$ e $b_1$|Dati|
|**8**|`1000`|$8$|$b_8$, che controlla anche sé stesso|Controllo|
|**ecc.**|||||

L’algoritmo esegue operazioni differenti presso il mittente e il destinatario.
**Mittente:** inizialmente inserisce dei simboli provvisori `x` nelle posizioni $1,2,4,8,\ldots$, riservate ai bit di controllo, e colloca ordinatamente i bit del messaggio nelle posizioni rimanenti. Il bit nella posizione $2^k$ controlla tutte le posizioni il cui indice binario contiene un `1` nella colonna corrispondente:
- $b_1$ controlla gli indici che terminano con `1`;
- $b_2$ controlla gli indici con il secondo bit da destra uguale a `1`;
- $b_4$ controlla gli indici con il terzo bit da destra uguale a `1`;
- $b_8$ controlla gli indici con il quarto bit da destra uguale a `1`.
Il valore di ciascun bit di controllo si calcola eseguendo lo XOR, indicato con $\oplus$, tra i bit del gruppo supervisionato. Con la **parità pari**, il bit di controllo viene scelto in modo che lo XOR complessivo del gruppo, includendo il controllo stesso, sia `0`.

> [!example] Esempio di codifica  
> Il messaggio da inviare è $1\ 0\ 0\ 1\ 0$. Inserendo i controlli nelle posizioni $1$, $2$, $4$ e $8$, si ottiene:
> 
> $$x\ x\ 1\ x\ 0\ 0\ 1\ x\ 0$$
> 
> Le posizioni sono numerate da $1$ a $9$:
> 
> - $b_1$ controlla $1,3,5,7,9$, quindi $b_1=b_3\oplus b_5\oplus b_7\oplus b_9=1\oplus0\oplus1\oplus0=0$;
>     
> - $b_2$ controlla $2,3,6,7$, quindi $b_2=b_3\oplus b_6\oplus b_7=1\oplus0\oplus1=0$;
>     
> - $b_4$ controlla $4,5,6,7$, quindi $b_4=b_5\oplus b_6\oplus b_7=0\oplus0\oplus1=1$;
>     
> - $b_8$ controlla $8,9$, quindi $b_8=b_9=0$.
>     
> 
> Sostituendo i valori calcolati, la codeword trasmessa è:
> 
> $$001100100$$

**Destinatario:** ricalcola lo XOR di ogni gruppo sulla stringa ricevuta, includendo anche il relativo bit di controllo. Un risultato `0` indica che la parità è rispettata, mentre `1` segnala un’anomalia. L’insieme dei risultati costituisce la **sindrome**: se tutti sono `0`, non viene rilevato alcun errore; altrimenti, la posizione errata si ottiene sommando gli indici dei bit di controllo appartenenti ai gruppi che hanno prodotto `1`.

> [!example] Esempio di correzione  
> Il destinatario riceve:
> 
> $$001101100$$
> 
> Rispetto alla codeword originale, il bit in posizione $6$ è passato da `0` a `1`. Il ricalcolo produce:
> 
> - gruppo di $b_1$: $0\oplus1\oplus0\oplus1\oplus0=0$, quindi nessun errore segnalato;
>     
> - gruppo di $b_2$: $0\oplus1\oplus1\oplus1=1$, quindi il gruppo segnala un errore;
>     
> - gruppo di $b_4$: $1\oplus0\oplus1\oplus1=1$, quindi il gruppo segnala un errore;
>     
> - gruppo di $b_8$: $0\oplus0=0$, quindi nessun errore segnalato.
>     
> 
> I gruppi che segnalano l’anomalia sono quelli di $b_2$ e $b_4$; la posizione errata è quindi $2+4=6$. La sindrome individua il sesto bit e il destinatario esegue un **bit flip**, riportandolo da `1` a `0`. 

> [!TIP] Curiosità
> Un’applicazione pratica dei codici di correzione è la **ECC RAM — Error Correction Code RAM**, che utilizza bit di controllo aggiuntivi per rilevare e correggere eventuali errori nei dati memorizzati, aumentando l’affidabilità della memoria.

### Protocolli di accesso multiplo nei canali broadcast

###### Collegamenti punto a punto e broadcast
I collegamenti di rete possono essere **punto a punto** o **broadcast**. Un collegamento punto a punto connette un trasmittente a un unico ricevente, mentre un **collegamento broadcast** è un canale condiviso al quale sono connessi più nodi in grado di trasmettere e ricevere. Quando un nodo invia un frame, tutti gli altri nodi collegati al canale ne ricevono una copia. **Ethernet** e le **Wireless LAN** utilizzano collegamenti di questo tipo.

I **protocolli di accesso multiplo** stabiliscono come i nodi devono coordinare le proprie trasmissioni sul canale condiviso.

![[Pasted image 20260606180909.png|700]]

###### Collisioni e classificazione dei protocolli
Quando due o più nodi trasmettono contemporaneamente, i frame interferiscono tra loro e si verifica una **collisione**. I riceventi non riescono a interpretarli correttamente, quindi i dati devono essere ritrasmessi.

I protocolli di accesso multiplo si dividono in tre categorie:
- **protocolli a suddivisione del canale**;
- **protocolli ad accesso casuale**;
- **protocolli a rotazione o senza collisioni**.

Un protocollo ideale per un canale broadcast con velocità $R$ bit al secondo dovrebbe garantire:
- throughput pari a $R$ bps quando trasmette un solo nodo;
- throughput medio pari a $R/M$ bps per ciascun nodo quando sono attivi $M$ nodi;
- funzionamento decentralizzato, senza un nodo principale il cui guasto blocchi il sistema;
- semplicità ed economicità di implementazione.
### Protocolli a suddivisione del canale
###### TDMA e FDMA

**TDMA - Time Division Multiple Access** e **FDMA - Frequency Division Multiple Access** suddividono il canale tra $N$ nodi, impedendo le collisioni.

Con **TDMA**, il tempo è organizzato in intervalli ripetitivi chiamati _time frame_, ciascuno suddiviso in $N$ slot temporali. Ogni nodo può trasmettere soltanto nel proprio slot, che generalmente permette l’invio di un frame. La velocità media assegnata a ogni nodo è $R/N$ bps. Se un nodo non ha dati da inviare, però, il suo slot rimane inutilizzato; inoltre, un nodo attivo deve attendere il proprio turno anche quando tutti gli altri sono inattivi.

Con **FDMA**, il canale viene diviso in $N$ bande di frequenza, una per nodo. Ciascun nodo dispone quindi di una velocità pari a $R/N$ bps. Anche in questo caso, la porzione di canale assegnata a un nodo inattivo non può essere utilizzata dagli altri.

###### CDMA: accesso multiplo a divisione di codice

**CDMA - Code Division Multiple Access** assegna a ciascun nodo un codice univoco, anziché uno slot temporale o una banda di frequenza. Il nodo usa il proprio codice per codificare i dati trasmessi.

Se i codici sono scelti correttamente, più nodi possono trasmettere contemporaneamente. Ogni ricevente può ricostruire i dati destinati a esso conoscendo il codice appropriato, nonostante le interferenze prodotte dalle altre trasmissioni.

CDMA è stato inizialmente utilizzato in ambito militare e successivamente nella telefonia cellulare.

### Protocolli ad accesso casuale
Nei **protocolli ad accesso casuale**, ogni nodo trasmette alla massima velocità del canale, pari a $R$ bps. Se avviene una collisione, i nodi coinvolti ritrasmettono i propri frame finché questi non vengono ricevuti correttamente.

La ritrasmissione non avviene immediatamente: ciascun nodo attende un intervallo casuale, scelto indipendentemente dagli altri. In questo modo diminuisce la probabilità che gli stessi nodi trasmettano nuovamente nello stesso istante.

###### Slotted ALOHA
**Slotted ALOHA** si basa sulle seguenti assunzioni:
- tutti i frame hanno lunghezza $L$ bit;
- il tempo è diviso in slot di durata $L/R$ secondi, corrispondente al tempo di trasmissione di un frame;
- un nodo può iniziare a trasmettere soltanto all’inizio di uno slot;
- gli slot sono sincronizzati tra tutti i nodi;
- una collisione viene rilevata da tutti i nodi prima della fine dello slot.

Quando un nodo riceve un nuovo frame, aspetta l’inizio dello slot successivo e lo trasmette interamente. Se non si verifica una collisione, l’invio termina con successo. In caso contrario, il nodo ritrasmette negli slot successivi con probabilità $p$, finché il frame non viene inviato correttamente.
In ogni slot successivo a una collisione, il nodo:
- ritrasmette con probabilità $p$;
- non trasmette con probabilità $1-p$ e ripete la scelta nello slot seguente.

Le decisioni dei nodi sono indipendenti. Slotted ALOHA è quindi decentralizzato, anche se richiede la sincronizzazione degli slot.

Quando è attivo un solo nodo, questo può utilizzare continuamente il canale alla velocità $R$. Con molti nodi attivi, invece, alcuni slot vengono sprecati a causa delle collisioni, mentre altri rimangono vuoti perché nessun nodo decide di trasmettere. Uno **slot riuscito**, o _successful slot_, è uno slot nel quale trasmette esattamente un nodo.

![[Pasted image 20260606181319.png|700]]

###### Efficienza di Slotted ALOHA
L’**efficienza** è la frazione di slot nei quali avviene una trasmissione riuscita. Supponiamo che siano presenti $N$ nodi sempre attivi e che ciascuno trasmetta, in ogni slot, con probabilità $p$.

Affinché un determinato nodo sia l’unico a trasmettere, esso deve trasmettere con probabilità $p$, mentre gli altri $N-1$ nodi devono rimanere inattivi con probabilità $(1-p)^{N-1}$. La probabilità relativa a un determinato nodo è quindi $p(1-p)^{N-1}$.

Poiché il nodo trasmittente può essere uno qualsiasi degli $N$ nodi, l’efficienza complessiva è: $$S=Np(1-p)^{N-1}$$
Il valore che massimizza l’efficienza è $p^\ast=1/N$. All’aumentare del numero di nodi, ciascuno deve quindi trasmettere con probabilità minore.

Sostituendo $p^\ast=1/N$ e facendo tendere $N$ all’infinito si ottiene:

$$\lim_{N\to\infty}\left(1-\frac{1}{N}\right)^{N-1}=\frac{1}{e}\approx 0{,}37$$

L’efficienza massima di Slotted ALOHA è quindi circa $0{,}37$: con molti nodi attivi, soltanto il $37$% degli slot contiene mediamente una trasmissione riuscita.

###### ALOHA puro
In **ALOHA puro** non esistono slot sincronizzati. Un nodo trasmette un frame immediatamente quando questo arriva.

Se si verifica una collisione, il nodo ritrasmette immediatamente con probabilità $p$. Con probabilità $1-p$, attende un intervallo pari al tempo di trasmissione di un frame e ripete la scelta.

ALOHA puro è completamente decentralizzato, ma l’assenza degli slot aumenta l’intervallo nel quale una trasmissione può subire interferenze.

###### Efficienza di ALOHA puro
Si considera come unità di tempo il tempo necessario per trasmettere un frame. Supponiamo che il nodo $i$ inizi a trasmettere al tempo $t_0$.

Affinché il frame venga ricevuto correttamente, nessun altro nodo deve iniziare a trasmettere:
- nell’intervallo $(t_0-1,t_0]$, perché il suo frame si sovrapporrebbe all’inizio della trasmissione di $i$;
- durante l’intero intervallo di trasmissione del frame di $i$.

La probabilità che gli altri $N-1$ nodi rimangano inattivi in ciascuno dei due intervalli è $(1-p)^{N-1}$.
![[Pasted image 20260606182656.png|700]]

La probabilità che un determinato nodo trasmetta con successo è: $$p(1-p)^{2(N-1)}$$
L’efficienza massima risultante è: $$\frac{1}{2e}$$
L’efficienza massima di ALOHA puro è quindi la metà di quella di Slotted ALOHA.
###### CSMA: rilevamento della portante
Nei protocolli ALOHA, i nodi trasmettono senza verificare preventivamente l’attività del canale. **CSMA - Carrier Sense Multiple Access** introduce il **rilevamento della portante**: prima di trasmettere, un nodo ascolta il canale. Se rileva una trasmissione in corso, aspetta che il canale diventi libero. Il **rilevamento della collisione** prevede invece che il nodo continui ad ascoltare il canale anche durante la trasmissione. Se rileva un’interferenza, interrompe l’invio, attende un intervallo casuale e riprova.
Questi meccanismi sono alla base di:
- **CSMA - Carrier Sense Multiple Access:** rilevamento della portante;
- **CSMA/CD - CSMA with Collision Detection:** rilevamento della portante e delle collisioni.

###### Ritardo di propagazione e collisioni in CSMA
Il rilevamento della portante non elimina completamente le collisioni a causa del **ritardo di propagazione**, cioè del tempo necessario affinché il segnale raggiunga gli altri nodi del canale.

La Figura 6.12 mostra quattro nodi, $A$, $B$, $C$ e $D$. L’asse orizzontale rappresenta la loro posizione sul canale, mentre quello verticale rappresenta il tempo.

![[Pasted image 20260606183139.png|700]]

Al tempo $t_0$, il nodo $B$ rileva il canale libero e inizia a trasmettere. I suoi bit si propagano nelle due direzioni lungo il mezzo trasmissivo.

Al tempo $t_1>t_0$, il nodo $D$ deve inviare un frame. I bit di $B$ non hanno ancora raggiunto $D$, che percepisce quindi il canale come libero e inizia a trasmettere. Poco dopo, le due trasmissioni interferiscono e si verifica una collisione.

Maggiore è il ritardo di propagazione, maggiore è la probabilità che un nodo inizi a trasmettere senza essersi ancora accorto di una trasmissione già in corso.

###### CSMA/CD: rilevamento delle collisioni
In CSMA semplice, i nodi possono continuare a trasmettere anche dopo una collisione. Con **CSMA/CD**, invece, interrompono la trasmissione non appena la rilevano.

![[Pasted image 20260606183320.png|700]]

L’interruzione anticipata evita di occupare il canale per trasmettere interamente un frame già danneggiato.

Una scheda di rete che utilizza CSMA/CD esegue le seguenti operazioni:
1. Riceve un datagramma dal livello di rete, costruisce il frame e lo memorizza nel proprio buffer.
2. Ascolta il canale. Se è libero, inizia a trasmettere; se è occupato, aspetta che termini la trasmissione in corso.
3. Durante l’invio, controlla la presenza di segnali provenienti dalle altre schede.
4. Se completa il frame senza rilevare interferenze, la trasmissione ha successo. Se rileva una collisione, interrompe immediatamente l’invio.
5. Dopo la collisione, aspetta un intervallo casuale e ripete il procedimento dal controllo del canale.

###### Binary exponential backoff
Dopo una collisione è necessario utilizzare un’attesa casuale. Se i nodi aspettassero tutti lo stesso intervallo fisso, potrebbero ritrasmettere contemporaneamente e collidere di nuovo.

Il **tempo di backoff** deve adattarsi al livello di congestione. Un intervallo troppo grande rallenta inutilmente la ritrasmissione quando sono coinvolti pochi nodi; un intervallo troppo piccolo aumenta la probabilità di nuove collisioni quando i nodi sono numerosi.

Con il **binary exponential backoff**, dopo l’$n$-esima collisione relativa allo stesso frame, il nodo sceglie casualmente:

$$K\in{0,1,2,\ldots,2^n-1}$$

In Ethernet, il tempo di attesa corrisponde al tempo necessario per trasmettere $K$ volte $512$ bit. Il valore massimo utilizzato per $n$ è $10$.

Dopo la prima collisione, $K$ è scelto tra $0$ e $1$. Se $K=0$, il nodo ricomincia subito ad ascoltare il canale; se $K=1$, aspetta il tempo di trasmissione di $512$ bit. Dopo la seconda collisione, $K$ è scelto tra $0$, $1$, $2$ e $3$; dopo la terza, tra i valori da $0$ a $7$. Dopo dieci o più collisioni viene scelto uniformemente tra $0$ e $1023$.

L’intervallo dei possibili valori raddoppia a ogni collisione, fino al limite massimo previsto, riducendo la probabilità che nodi già entrati in collisione scelgano nuovamente lo stesso istante di trasmissione.

###### Efficienza di CSMA/CD
Con un solo nodo attivo, CSMA/CD permette di utilizzare la velocità massima del canale, per esempio $10$ Mbps, $100$ Mbps o $1$ Gbps in Ethernet. Con molti nodi attivi, una parte del tempo viene invece persa nelle collisioni e nelle attese.

L’**efficienza di CSMA/CD** è la frazione media di tempo durante la quale vengono trasmessi frame senza collisioni, considerando molti nodi attivi con numerosi frame da inviare.

Indichiamo con $d_{\mathrm{prop}}$ il massimo ritardo di propagazione tra due schede e con $d_{\mathrm{trasm}}$ il tempo necessario per trasmettere un frame della massima dimensione. Per Ethernet a $10$ Mbps, $d_{\mathrm{trasm}}$ è circa $1{,}2$ ms. $$\mathrm{Efficienza}=\frac{1}{1+5d_{\mathrm{prop}}/d_{\mathrm{trasm}}}$$
Quando $d_{\mathrm{prop}}$ tende a $0$, l’efficienza tende a $1$, perché le collisioni vengono rilevate quasi immediatamente e la capacità sprecata si riduce.

### Protocolli senza collisioni
I **protocolli senza collisioni** stabiliscono in anticipo quale nodo può trasmettere, utilizzando meccanismi di prenotazione o rotazione.

###### Protocollo bit map
Con $N$ nodi, il tempo viene inizialmente diviso in $N$ mini-slot, ciascuno destinato alla trasmissione di un bit. Ogni nodo inserisce nel proprio mini-slot:
- $1$ se vuole trasmettere;
- $0$ se non ha frame da inviare.

Al termine della fase di prenotazione si ottiene una **mappa di bit** che indica quali nodi devono trasmettere. Le trasmissioni possono quindi avvenire in ordine, senza collisioni.

###### Binary Backward Counting

Nel **Binary Backward Counting**, ogni nodo possiede un identificatore binario. I nodi che vogliono trasmettere confrontano gli ID un bit alla volta, iniziando dal bit più significativo. Quando nella stessa posizione alcuni nodi trasmettono $0$ e altri $1$, quelli che hanno trasmesso $0$ abbandonano la competizione. Il confronto continua finché rimane un solo nodo.
Supponiamo che i nodi $A$, $B$, $C$ e $D$ abbiano rispettivamente gli ID $0010$, $1010$, $0100$ e $1100$:
1. Nel primo mini-slot vengono confrontati i bit più significativi: $A:0$, $B:1$, $C:0$ e $D:1$.
2. I nodi $A$ e $C$ vengono eliminati perché hanno trasmesso $0$.
3. Nel mini-slot successivo vengono confrontati i secondi bit di $B$ e $D$: $B:0$ e $D:1$.
4. Il nodo $D$ vince e può trasmettere.

Il meccanismo può risultare poco equo, perché i nodi con ID binari più elevati sono avvantaggiati. Gli ID possono inoltre essere ricavati dagli indirizzi MAC, rendendo il vantaggio dipendente dall’identità del dispositivo.

###### Taking Turns Protocol

Nel **Taking Turns Protocol**, i nodi che vogliono trasmettere segnalano la richiesta inviando $1$ sul canale e vengono inseriti in un anello logico.

Il primo nodo dell’anello trasmette e, dopo un intervallo $T$, passa un **token** al nodo successivo. Solo il nodo che possiede il token può utilizzare il canale, quindi non si verificano collisioni.

Il protocollo presenta però due problemi: il guasto di un nodo può interrompere il passaggio del token e tutti i nodi della sottorete devono essere inclusi correttamente nell’anello logico per poter trasmettere.

### Ethernet
