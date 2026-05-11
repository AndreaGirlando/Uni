
### Trasporto orientato alla connessione: TCP
Ora che sono stati stabiliti i principi fondamentali alla base del trasferimento dati affidabile, l'attenzione si sposta sul **TCP**, ovvero il protocollo di Internet a livello di trasporto che garantisce un servizio **affidabile e orientato alla connessione**. Per offrire questo trasferimento senza errori, il TCP si basa su una combinazione complessa di meccanismi: rilevazione degli errori, ritrasmissioni, acknowledgment cumulativi, contatori e l'utilizzo di campi specifici nell'intestazione per i numeri di sequenza e di acknowledgment.

###### Principi e Caratteristiche Generali
- **Orientato alla connessione (connection-oriented):** Il TCP è definito in questo modo perché, prima di poter iniziare l'effettivo scambio dei dati, i due processi comunicanti devono obbligatoriamente effettuare una fase preliminare detta _handshake_. Durante questo processo, si inviano reciprocamente alcuni segmenti per stabilire i parametri del successivo trasferimento dati e per inizializzare numerose variabili di stato associate alla connessione stessa.
- **Stato residente nei sistemi periferici:** È fondamentale chiarire che la "connessione" TCP non è un circuito _end-to-end_ fisico (come i circuiti TDM o FDM di una rete a commutazione di circuito). Lo stato della connessione risiede unicamente ed esclusivamente nei due host periferici (i sistemi finali). Dato che il protocollo TCP va in esecuzione solo sui sistemi periferici e non negli elementi di rete intermedi (come i router), la rete stessa "non sa" dell'esistenza della connessione.
- **Servizio Full-Duplex:** Una connessione TCP consente il traffico bidirezionale simultaneo. Se esiste una connessione tra un processo A (su un host) e un processo B (su un altro host), i dati applicativi possono fluire da A verso B nello stesso identico momento in cui fluiscono da B verso A.
- **Punto a punto (point-to-point):** La comunicazione ha luogo strettamente tra un singolo mittente e un singolo destinatario. L'invio di tipo _multicast_ (ovvero il trasferimento di dati da un mittente a molti destinatari simultaneamente in un'unica operazione) con il TCP non è in alcun modo possibile.

###### Instaurazione della Connessione e Flusso dei Dati
Supponiamo che un processo applicativo client voglia inizializzare una connessione con un server.
1. Il TCP in esecuzione sul client invia per primo uno **speciale segmento TCP**.
2. Il server riceve e risponde con un **secondo segmento speciale TCP**.
3. Infine, il client risponde con un **terzo segmento speciale**.

I primi due segmenti non trasportano alcun payload (non contengono dati a livello applicativo), mentre il terzo segmento può già iniziare a trasportare informazioni utili. Poiché i due host si scambiano esattamente tre segmenti, questa procedura iniziale viene universalmente definita **handshake a tre vie (three-way handshake)** .

Una volta instaurata la connessione, i due processi possono finalmente scambiarsi dati. Il processo client manda un flusso di dati attraverso la _socket_. Non appena i dati attraversano questo punto di uscita, passano nelle mani del TCP in esecuzione nel client. TCP dirige immediatamente i dati al **buffer di invio della connessione** (uno specifico buffer che è stato allocato e riservato proprio durante la fase di handshake a tre vie). Da questo buffer, il protocollo preleverà di tanto in tanto dei blocchi di dati e li passerà al sottostante livello di rete.

![[Pasted image 20260511213317.png|700]]

###### Gestione delle Dimensioni dei Dati: MSS e MTU

La massima quantità di dati prelevabili dal buffer e posizionabili in un singolo segmento è rigorosamente limitata da un parametro:
- **MSS (Maximum Segment Size - Dimensione massima di segmento):** Rappresenta la massima quantità di dati a livello di applicazione che può essere inserita nel segmento.
- **MTU (Maximum Transmission Unit - Unità trasmissiva massima):** È la lunghezza del frame più grande che può essere inviato a livello di collegamento dall'host locale.

**Come si calcola l'MSS?** Generalmente, il valore dell'MSS viene impostato scegliendo una dimensione tale che l'intero segmento TCP possa stare comodamente all'interno di un singolo frame a livello di collegamento (MTU), tenendo però conto anche dello spazio occupato dalle intestazioni. Normalmente, l'intestazione combinata TCP/IP è pari a 40 byte. Protocolli di collegamento molto diffusi, come Ethernet e PPP, hanno un MTU standard di 1500 byte.

_Attenzione alla terminologia:_ L'MSS rappresenta unicamente i _dati dell'applicazione_ nel segmento e **non** la dimensione massima del segmento TCP con intestazioni incluse. Sebbene possa confondere, è una convenzione con cui bisogna convivere.

Quando TCP riceve un file di grandi dimensioni (ad esempio un'immagine che fa parte di una pagina web), lo frammenta in porzioni di dimensione pari all'MSS. A ogni blocco di dati accoppia un'intestazione TCP, formando così i veri e propri segmenti. Questi vengono passati al livello di rete (dove sono incapsulati nei datagrammi IP) e immessi in rete. All'altro capo, quando il TCP riceve il segmento, immagazzina i dati nel **buffer di ricezione** della connessione, da cui l'applicazione destinataria andrà a leggere. Entrambi i lati della connessione possiedono il proprio buffer di invio e di ricezione.

###### Struttura dei Segmenti TCP

Un segmento TCP è costituito dai campi di Intestazione (_Header_) e da un campo contenente il blocco di dati dell'applicazione (la cui dimensione è limitata, come visto, dall'MSS). Generalmente, in assenza di opzioni aggiuntive, la lunghezza consueta dell'intestazione è di **20 byte**.

![[Pasted image 20260511213114.png|700]]
Esaminiamo nel dettaglio i campi dell'intestazione:
- **Numeri di porta di origine e di destinazione:** Utilizzati (come in UDP) per il multiplexing e demultiplexing dei dati verso le corrette applicazioni di livello superiore.
- **Checksum:** Utilizzato per il controllo dell'integrità e la rilevazione degli errori.
- **Numero di sequenza (32 bit)** e **Numero di acknowledgment (32 bit):** Utilizzati da mittente e destinatario per implementare il servizio di trasferimento dati affidabile (dettagliati nel paragrafo successivo).
- **Finestra di ricezione (receive window, 16 bit):** Campo cruciale per il controllo di flusso; indica esplicitamente il numero di byte che il destinatario è disposto e pronto ad accettare.
- **Lunghezza dell'intestazione (4 bit):** Specifica la lunghezza dell'intestazione TCP misurata in multipli di 32 bit. È necessaria perché la lunghezza è variabile a causa del campo Opzioni.
    
- **Opzioni (facoltativo, lunghezza variabile):** Usato durante le negoziazioni tra mittente e destinatario (es. per accordarsi sull'MSS) o come fattore di scala per la finestra in reti ad altissima velocità. Viene inoltre definita l'opzione di time-stamping; per dettagli aggiuntivi
- **Flag (6 bit):**
    - **ACK:** Indica che il valore trasportato nel campo "Numero di acknowledgment" è valido (ossia contiene l'ack per un segmento ricevuto con successo).
    - **RST, SYN, FIN:** Bit utilizzati per le fasi di impostazione e chiusura della connessione.
    - **CWR ed ECE:** Impiegati nel controllo di congestione esplicito.
    - **PSH:** Se vale 1, avverte il destinatario che dovrebbe inviare immediatamente i dati accumulati al livello superiore.
    - **URG:** Indica la presenza di dati che l'entità mittente ha marcato come "urgenti".
    - **Puntatore ai dati urgenti:** Campo usato insieme a URG, denota la posizione dell'ultimo byte dei dati urgenti, fornendo al livello superiore un puntatore alla fine di tali dati. Nella pratica, i flag PSH, URG e il relativo puntatore non vengono quasi mai usati, ma li citiamo per.

###### Numeri di Sequenza e Numeri di Acknowledgment

Il TCP vede i dati non come pacchetti isolati, ma come un **flusso di byte non strutturati, ma rigorosamente ordinati**. L'uso di questi due campi riflette proprio questa visione:
- **Numero di sequenza per un segmento:** Non indica il numero del segmento, bensì il numero nel flusso di byte corrispondente al **primo byte** di dati trasportato nel segmento stesso.
- **Numero di acknowledgment:** Poiché TCP è full-duplex (A può ricevere e inviare ad B contemporaneamente), il numero di acknowledgment che l'Host A scrive nei segmenti diretti a B rappresenta **il numero di sequenza del byte successivo** che l'Host A si attende di ricevere da B.

**Un esempio numerico chiarificatore:**
Supponiamo che l'Host A debba inviare all'Host B un flusso di dati pari a 500.000 byte, che l'MSS valga 1000 byte e che il primo byte del flusso sia numerato con 0.
Il TCP costruirà 500 segmenti:
- Al 1° segmento viene assegnato numero di sequenza 0.
- Al 2° segmento viene assegnato numero di sequenza 1000.
- Al 3° segmento viene assegnato numero di sequenza 2000, e così via.
Se l'Host A ha ricevuto dall'Host B tutti i byte numerati da 0 a 535, significa che A è in attesa del byte 536. Pertanto, l'Host A scriverà **536** nel campo del numero di acknowledgment del segmento che sta per spedire a B.

**Acknowledgment Cumulativi e anomalie di ricezione:**
Poiché TCP conferma la ricezione _solo_ fino al primo byte mancante nel flusso continuo, si dice che offre **acknowledgment cumulativi**.

Tuttavia, la rete è imperfetta. Un aspetto delicato è la gestione dei segmenti fuori sequenza. Se l'Host A riceve il terzo segmento (byte da 900 a 1000) prima del secondo (byte da 536 a 899), si trova di fronte a un "vuoto". Di fronte a segmenti non ordinati, l'host ha due scelte implementative:
1. Scartare immediatamente i segmenti non ordinati.
2. Mantenere i byte non ordinati in un buffer e attendere l'arrivo di quelli mancanti per colmare il vuoto (soluzione più efficiente e diffusa).

_Nota sulla sicurezza:_ I partecipanti alla connessione non partono quasi mai dal byte 0; scelgono invece a caso un **numero di sequenza iniziale**. Questo espediente minimizza drasticamente la possibilità che un vecchio segmento ritardato, ancora vagante nella rete da una connessione precedente, venga erroneamente interpretato come segmento valido in una connessione successiva.

###### Timeout e Stima del Tempo di Andata e Ritorno (RTT)
Per recuperare pacchetti persi, il TCP adotta un meccanismo di **timeout (tempo scaduto)** associato alla ritrasmissione.
Il problema principale è: _quanto deve durare il timeout?_
Deve essere maggiore del Tempo di Andata e Ritorno (**RTT, Round-Trip Time**), ovvero il tempo trascorso dall'invio del segmento alla ricezione del suo ACK, altrimenti si innescherebbero ritrasmissioni del tutto inutili.
Per stimare questo tempo, TCP calcola tre parametri fondamentali:
1. **SampleRTT:** È l'RTT effettivamente misurato su un singolo segmento trasmesso (tempo trascorso tra istante di invio e ricezione dell'ACK). Anziché misurare ogni singolo pacchetto, la maggior parte delle implementazioni TCP valuta un solo _SampleRTT_ alla volta, relativo ai segmenti per cui non si è ancora ricevuto riscontro.
2. **EstimatedRTT:** I valori del _SampleRTT_ fluttuano continuamente a causa del traffico di rete. TCP calcola quindi una media chiamata _EstimatedRTT_, aggiornata costantemente secondo una **Media Mobile Esponenziale Ponderata (EWMA, Exponential Weighted Moving Average)**. La formula (dove il peso $\alpha$ consigliato è 0,125) attribuisce maggiore importanza ai campioni recenti, in quanto riflettono meglio l'effettiva congestione attuale: $$EstimatedRTT = (1 - 0,125) \times EstimatedRTT + 0,125 \times SampleRTT$$
3. **DevRTT:** Oltre alla media, è fondamentale conoscere la variazione (variabilità) del tempo di risposta. _DevRTT_ è un EWMA che stima quanto il _SampleRTT_ si discosta dalla media _EstimatedRTT_. Se le fluttuazioni sono limitate, _DevRTT_ sarà piccolo; in caso di traffico irregolare, sarà grande. Il valore suggerito per il peso $\beta$ è 0,25:$$DevRTT = (1 - 0,25) \times DevRTT + 0,25 \times |SampleRTT - EstimatedRTT|$$

**Impostazione del Timeout di Ritrasmissione:**
Combinando media e variabilità, si ottiene finalmente l'intervallo di timeout ideale, sufficientemente ampio da coprire fluttuazioni della rete ma abbastanza stretto da non causare gravi ritardi: $$TimeoutInterval = EstimatedRTT + 4 \times DevRTT$$
###### Il Servizio di Trasferimento Dati Affidabile
Il livello di rete sottostante, basato sul protocollo IP, fornisce un servizio _inaffidabile_ e _best-effort_: non garantisce la consegna, non garantisce l'ordine dei datagrammi e non garantisce l'integrità dei dati (i datagrammi possono sovraffollare i buffer dei router ed essere scartati o subire alterazioni).
Il compito del TCP è creare un solido servizio di trasporto dati affidabile proprio al di sopra di questo caos.

![[Pasted image 20260511213018.png|700]]

Il comportamento essenziale del mittente TCP è guidato da tre eventi principali:

1. **Ricezione di dati provenienti dall'applicazione:** Il TCP incapsula i dati, assegna il corretto numero di sequenza (corrispondente al primo byte) e passa il segmento a IP. Contestualmente, se non è già in funzione per un altro segmento, **avvia il timer**. Questo timer è sempre associato al pacchetto più vecchio in attesa di conferma. L'intervallo di scadenza è pari al _TimeoutInterval_ precedentemente calcolato.
2. **Scadenza del Timeout:** Se il timer scade prima di aver ricevuto una conferma, TCP reagisce ritrasmettendo esclusivamente il segmento che ha causato il timeout, per poi **riavviare il timer**.
3. **Arrivo di un Acknowledgment (ACK):** Quando arriva un ACK con valore _y_, il mittente lo confronta con la propria variabile di stato fondamentale, chiamata **SendBase**.
    - _SendBase:_ rappresenta il numero di sequenza del byte più vecchio che non ha ancora ricevuto un acknowledgment (ne consegue che _SendBase - 1_ è l'ultimo byte arrivato sano e salvo e in ordine).
    - Poiché gli acknowledgment sono cumulativi, il valore _y_ conferma implicitamente che tutti i byte precedenti sono stati ricevuti. Se **$y > SendBase$**, significa che l'ACK si riferisce a uno o più segmenti che erano in attesa. Di conseguenza, il mittente aggiorna la variabile _SendBase_.
    - Se, dopo l'aggiornamento, ci sono ancora altri segmenti in volo che necessitano di acknowledgment, il mittente riavvia nuovamente il timer per coprirli.

###### Trasferimento Dati Affidabile in TCP: Scenari, Ritrasmissioni e Gestione della Connessione
Abbiamo precedentemente visto come il TCP fornisca un trasferimento dati affidabile avvalendosi di timer e acknowledgment. Nonostante la trattazione sia stata semplificata, i meccanismi alla base del protocollo presentano una notevole ingegnosità. Per comprendere a fondo come funziona TCP nella pratica, è utile analizzare alcuni scenari specifici di trasmissione e le dinamiche di gestione degli errori.

###### Scenari di Trasmissione e Gestione degli Errori
Consideriamo tre semplici scenari che illustrano il comportamento del TCP di fronte a imprevisti nella rete.
- **Primo scenario: Ritrasmissione dovuta alla perdita di un acknowledgment.** Supponiamo che l'Host A spedisca un singolo segmento all'Host B. Questo segmento ha numero di sequenza 92 e contiene 8 byte di dati. Dopo l'invio, A avvia il proprio timer e si mette in attesa di un segmento da B contenente il numero di acknowledgment 100 (ovvero il byte successivo che B si aspetta). Sebbene l'Host B riceva correttamente il segmento e invii l'acknowledgment, quest'ultimo viene smarrito sul percorso inverso. Di conseguenza, il timer dell'Host A scade (evento di timeout) e A ritrasmette esattamente lo stesso segmento. Quando l'Host B riceve questa ritrasmissione, controllando il numero di sequenza, rileva immediatamente che il segmento contiene dati già ricevuti in precedenza; pertanto, scarta i byte del segmento ritrasmesso.
![[Pasted image 20260511212957.png|700]]
- **Secondo scenario: Segmento salvato dall'arrivo ritardato dell'ACK.** In questo caso, l'Host A invia due segmenti consecutivi. Il primo ha numero di sequenza 92 e contiene 8 byte di dati; il secondo ha numero di sequenza 100 e contiene 20 byte di dati. Ipotizziamo che entrambi i segmenti arrivino intatti all'Host B. Di conseguenza, B invia due acknowledgment separati: il primo numerato 100 e il secondo numerato 120. Supponiamo ora che la rete subisca un rallentamento e nessuno dei due acknowledgment arrivi all'Host A prima dello scoccare del timeout relativo al primo segmento. Al verificarsi del timeout, l'Host A rispedisce il primo segmento (numero di sequenza 92) e riavvia il timer. A questo punto, prima che il nuovo timer scada, l'acknowledgment del secondo segmento (il numero 120) riesce ad arrivare ad A. Grazie a questo arrivo ritardato, il secondo segmento (quello con sequenza 100) non sarà ritrasmesso, poiché l'ACK ha confermato la corretta ricezione.
![[Pasted image 20260511212928.png|700]]
- **Terzo scenario: L'utilità dell'acknowledgment cumulativo.** Questo scenario è fondamentale per capire la potenza degli acknowledgment di TCP. L'Host A invia due segmenti, esattamente come nell'esempio precedente (seq 92 e seq 100). Questa volta, l'acknowledgment del primo segmento (100) viene effettivamente perso nella rete. Tuttavia, appena prima che scatti l'evento di timeout per il primo segmento, l'Host A riceve l'acknowledgment con numero 120 inviato da B in risposta al secondo pacchetto. Poiché gli acknowledgment TCP sono cumulativi, la ricezione del numero 120 certifica che l'Host B ha ricevuto con successo tutto il flusso di dati fino al byte 119. Essendone a conoscenza, l'Host A non rispedisce nessuno dei due segmenti, evitando del tutto ritrasmissioni inutili.
![[Pasted image 20260511212912.png|700]]
###### Raddoppio dell'Intervallo di Timeout

La maggior parte delle implementazioni TCP utilizza delle varianti rispetto al modello base, e la prima riguarda proprio la gestione della lunghezza dell'intervallo di timeout.

In tutti i casi in cui si verifica un timeout, TCP ritrasmette il segmento con il più basso numero di sequenza che non abbia ancora ricevuto acknowledgment. Tuttavia, a ogni ritrasmissione dello stesso segmento, TCP imposta il successivo intervallo di timeout **al doppio del valore precedente**, invece di calcolarlo derivandolo dagli ultimi valori di _EstimatedRTT_ e _DevRTT_.

_Esempio numerico:_ Supponiamo che il _TimeoutInterval_ associato al segmento più vecchio senza acknowledgment sia pari a 0,75 secondi. Quando il timer scade per la prima volta, TCP ritrasmette il segmento e imposta il nuovo tempo di scadenza a 1,5 secondi. Se anche questo timer dovesse scadere, TCP ritrasmetterà nuovamente il segmento stabilendo il tempo di scadenza a 3 secondi, e così via.

Questa modifica agisce come una forma limitata e rudimentale di controllo di congestione.

###### Ritrasmissione Rapida (Fast Retransmit)

Il meccanismo del timeout presenta un grave problema: il periodo di attesa prima della scadenza può rivelarsi relativamente lungo. Quando un segmento viene smarrito, questa lunga attesa impone al mittente di ritardare il nuovo invio, incrementando notevolmente il ritardo _end-to-end_ della comunicazione.

Fortunatamente, in molti casi il mittente può rilevare la perdita di pacchetti ben prima che si verifichi il timeout. Questo è possibile grazie all'arrivo di **ACK duplicati**, ovvero acknowledgment relativi a un segmento per cui il mittente ha già ricevuto conferma.

**Perché il destinatario invia un ACK duplicato?**

Quando il TCP ricevente riceve un segmento con un numero di sequenza superiore al successivo numero di sequenza atteso (cioè non lo riceve in ordine), rileva un "buco" nel flusso di dati, sintomo di un segmento mancante. Questo vuoto può essere causato da pacchetti persi o riordinati dalla rete.

Poiché il TCP non prevede la possibilità di inviare un _acknowledgment negativo esplicito (NACK)_ al mittente, il destinatario si limita a mandare nuovamente un acknowledgment relativo all'ultimo byte di dati che ha ricevuto regolarmente in ordine (generando di fatto un ACK duplicato).

Dato che i mittenti inviano spesso blocchi contenenti un gran numero di segmenti, se uno solo di questi viene smarrito, gli arriveranno probabilmente molti ACK duplicati dai segmenti successivi andati a buon fine.

La regola d'oro del TCP prevede che **se il mittente riceve tre ACK duplicati** per lo stesso dato, considera questo evento come l'indizio inequivocabile che il segmento successivo sia andato perduto. A quel punto, effettua una **ritrasmissione rapida (_fast retransmit_)**, rispedendo il segmento mancante immediatamente, senza aspettare che il suo timer scada.
![[Pasted image 20260511212847.png|700]]
###### Analisi dei Protocolli: TCP è Go-Back-N (GBN) o Ripetizione Selettiva (SR)?
Per capire l'architettura di TCP, è utile confrontarlo con i protocolli classici. Gli acknowledgment del TCP sono cumulativi e i segmenti ricevuti correttamente (ma disordinati) non vengono notificati singolarmente al mittente. Sotto questo aspetto, TCP assomiglia molto al GBN. Esistono tuttavia **differenze chiave**:
1. **Bufferizzazione dei pacchetti fuori ordine:** Molte implementazioni TCP non scartano i pacchetti giunti in disordine (come farebbe un GBN rigido), ma li memorizzano in un apposito buffer.
2. **Variabili di stato del mittente:** Il mittente TCP deve memorizzare solo due valori cruciali:
    - _SendBase:_ il numero di sequenza più basso tra i byte trasmessi senza acknowledgment.
    - _NextSeqNum:_ il numero di sequenza del successivo byte da inviare.
3. **Comportamento in caso di errore:** Consideriamo l'invio di una sequenza di segmenti numerati da _1, 2, ..., N_, e supponiamo che arrivino tutti al destinatario tranne il pacchetto _n_ ($n < N$). I restanti $N - 1$ pacchetti giungono prima dei rispettivi timeout.
    - Un protocollo GBN puro ritrasmetterebbe _non solo_ il pacchetto _n_, ma anche tutti i pacchetti da $n + 1$ fino a _N_.
    - TCP, al contrario, ritrasmetterebbe **al massimo il solo segmento n**.

**Acknowledgment Selettivo (Variante TCP):**
Esiste una modifica proposta per il TCP chiamata _acknowledgment selettivo_, che consente al destinatario di confermare esplicitamente e singolarmente i segmenti non in ordine, senza limitarsi all'approccio cumulativo sull'ultimo segmento corretto. Se uniamo questa opzione alla ritrasmissione selettiva (che evita di ritrasmettere i pacchetti singolarmente confermati), il TCP diventa estremamente simile a un generico protocollo SR (_Selective Repeat_).

Per questo motivo, il meccanismo di ripristino dagli errori di TCP è classificabile come un **ibrido tra i protocolli GBN e SR**.

###### Servizio di Controllo di Flusso

Oltre all'affidabilità, TCP offre un fondamentale **servizio di controllo di flusso**. Non va confuso con il _controllo di congestione_ (che serve a non sovraccaricare la rete IP); il controllo di flusso serve per non sovraccaricare l'host di destinazione.

Gli host agli estremi della connessione riservano dei **buffer di ricezione**. Quando il TCP riceve byte corretti e in sequenza, li posiziona in questo buffer. Il processo applicativo legge i dati dal buffer, ma i tempi possono variare: se l'applicazione è impegnata in un altro compito, potrebbe leggere i dati molto tempo dopo il loro arrivo. Se il mittente inviasse dati troppo rapidamente, il buffer di ricezione andrebbe in _overflow_. Il controllo di flusso è quindi un servizio di **confronto sulla velocità**, che bilancia la frequenza di invio del mittente con la frequenza di lettura dell'applicazione ricevente.

**Come funziona matematicamente il controllo di flusso:**

TCP fa mantenere al mittente una variabile chiamata **finestra di ricezione (_rwnd_, receive window)**, che gli fornisce costantemente l'indicazione dello spazio libero rimasto nel buffer del destinatario. Essendo una comunicazione full-duplex, i due mittenti mantengono finestre di ricezione distinte.

Se l'Host A sta inviando un file all'Host B, B alloca un buffer di ricezione di dimensione $RcvBuffer$. Si definiscono due variabili su B:
- _LastByteRead:_ il numero dell'ultimo byte del flusso letto dal processo applicativo.
- _LastByteRcvd:_ il numero dell'ultimo byte arrivato dalla rete e copiato nel buffer.
Per non mandare in overflow il buffer, deve valere la relazione: $LastByteRcvd - LastByteRead \le RcvBuffer$
La finestra di ricezione $rwnd$ (che è dinamica) indica lo spazio residuo calcolato come: $rwnd = RcvBuffer - [LastByteRcvd - LastByteRead]$

**La comunicazione della finestra:**
L'Host B inizializza $rwnd$ con il valore intero di $RcvBuffer$ e inserisce il valore aggiornato di $rwnd$ nell'apposito campo (Finestra di ricezione) dei segmenti che manda ad A, tenendo traccia di variabili specifiche per ogni connessione attiva.
Sull'altro fronte, l'Host A tiene traccia di altre due variabili:
- _LastByteSent:_ l'ultimo byte mandato.
- _LastByteAcked:_ l'ultimo byte per cui ha ricevuto conferma.
La differenza tra queste due variabili ($LastByteSent - LastByteAcked$) esprime la quantità esatta di dati "in volo" inviati da A per i quali non c'è ancora riscontro. Mantenendo rigorosamente questa quantità sotto il valore di $rwnd$ fornito da B, l'Host A si assicura matematicamente di non causare mai un overflow nel buffer di ricezione di B.

**Il problema della Finestra a Zero:**
Cosa succede se il buffer di B si riempie completamente ($rwnd = 0$) e B non ha più dati da inviare ad A? 

Quando il processo applicativo di B finalmente svuota il buffer, TCP _non genera_ un segmento spontaneo per inviare un nuovo valore di $rwnd$. Questo accade perché TCP fa pervenire segmenti all'Host A solo se ha nuovi dati o acknowledgment urgenti da inviare. Di conseguenza, l'Host A rimarrebbe totalmente bloccato, non sapendo che in B si è liberato spazio!

Per prevenire questo stallo, le specifiche impongono che **l'Host A continui a inviare segmenti "sonda" contenenti 1 solo byte di dati** anche quando la finestra di ricezione vale zero. L'Host B sarà costretto a inviare un acknowledgment in risposta a questo byte, e prima o poi quell'ACK conterrà un valore di $rwnd$ diverso da zero, permettendo la ripresa regolare della trasmissione.

###### Ciclo di Vita della Connessione: Handshake e Chiusura
Approfondiamo infine le procedure di apertura e chiusura del "circuito logico".
**Apertura della Connessione: L'Handshake a tre vie (Three-way handshake)**
Supponiamo che un processo client voglia inizializzare una comunicazione con un processo server.
- **Passo 1 (SYN):** Il TCP lato client invia uno speciale segmento al TCP server. Questo segmento è privo di dati a livello applicativo, ma ha il **bit SYN impostato a 1** nell'intestazione (viene pertanto detto _segmento SYN_). Il client sceglie casualmente un proprio numero di sequenza iniziale (_client_isn_) e lo pone nel campo corrispondente. Il segmento è inviato all'interno di un datagramma IP.
- **Passo 2 (SYNACK):** Se il pacchetto arriva, il server estrae il segmento, alloca all'istante i buffer e le variabili TCP per la connessione, e invia in risposta un segmento di approvazione (detto _segmento SYNACK_). Anche questo non contiene dati, ma possiede tre informazioni vitali:
    1. Il bit SYN è ancora posto a 1.
    2. Il campo ACK assume il valore di $client\_isn + 1$ (significa: "Ho ricevuto il tuo pacchetto e accetto la connessione, mi aspetto il prossimo byte").
    3. Il server sceglie un proprio numero di sequenza iniziale (_server_isn_) e lo inserisce nell'intestazione.
- **Passo 3 (ACK e Dati):** Alla ricezione del SYNACK, anche il client alloca i propri buffer e variabili alla connessione. Risponde al server ponendo il valore $server\_isn + 1$ nel campo ACK. In questo momento la connessione è formalmente stabilita, quindi il **bit SYN viene posto a zero**. Una particolarità fondamentale di questo terzo passo è che il campo dati di questo segmento **può già contenere informazioni utili** inviate dall'applicazione client al server.
![[Pasted image 20260511212701.png|700]]

**Chiusura della Connessione TCP**
Ciascuno dei due processi può decidere di terminare la connessione (nella nostra ipotesi, il client). Le "risorse" (buffer e variabili) di entrambi gli host dovranno essere deallocate.
1. Il processo applicativo client invia un comando di chiusura, costringendo il proprio TCP a generare un segmento speciale con il **bit FIN impostato a 1**.
2. Il server riceve questo segmento FIN e risponde inviando un normale acknowledgment di conferma al client.
3. Immediatamente dopo, il server spedisce a sua volta il proprio segmento di shutdown, anch'esso con il **bit FIN uguale a 1**.
4. Il client risponde inviando l'acknowledgment definitivo al segmento FIN del server. A questo punto tutte le risorse sono deallocate.
![[Pasted image 20260511212636.png|700]]

**Gli Stati della Connessione TCP:**
Nel suo ciclo di vita, i protocolli TCP attraversano diversi stati formali:
- **Stati visitati dal Client:** Si parte da `CLOSED`. L'inizializzazione spinge il client in `SYN_SENT`. Ricevuto il SYNACK, si entra in `ESTABLISHED` (in cui fluiscono i dati utili). Quando il client chiede la chiusura inviando il FIN, passa in `FIN_WAIT_1`. Ricevuto l'ACK dal server, entra in `FIN_WAIT_2` (in attesa del FIN del server). Ricevuto il FIN, invia il suo ultimo ACK ed entra in un particolare stato detto **`TIME_WAIT`**.
- **A cosa serve il TIME_WAIT?** Permette al TCP client di inviare nuovamente l'ultimo acknowledgment nel caso disgraziato in cui questo andasse perduto e il server rimandasse il suo FIN. Il tempo di permanenza in `TIME_WAIT` è definito dall'implementazione (tipicamente 30 secondi, 1 minuto o 2 minuti). Scaduto questo tempo, la connessione è totalmente chiusa e la porta viene rilasciata, tornando allo stato `CLOSED`.
![[Pasted image 20260511212619.png|700]]

**Cosa accade se le porte sono errate o chiuse?**
Se la fase di handshake fallisce perché il server riceve un segmento TCP destinato a una porta su cui non è in ascolto (es. riceve un SYN sulla porta 80 ma non ha processi web attivi), il server risponde immediatamente con un segmento speciale di reset, caratterizzato dal **bit RST impostato a 1**. Questo comunica alla sorgente: "Non ho una socket attiva per quel segmento, non tentare di rimandarlo".
_(Nota aggiuntiva sul testo: se una situazione identica accade con il protocollo UDP - porta di destinazione non corrispondente a una socket attiva - il sistema invia invece uno speciale datagramma di errore di tipo ICMP)._