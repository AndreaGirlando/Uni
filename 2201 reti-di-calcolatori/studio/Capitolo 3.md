### Introduzione al livello trasporto
###### Introduzione e Funzioni Principali
Posto tra il livello di applicazione e quello di rete, il livello di trasporto costituisce una parte centrale dell’architettura stratificata delle reti. La sua funzione critica è fornire servizi di comunicazione direttamente ai processi applicativi in esecuzione su host differenti.
- **Comunicazione logica** (_logical communication_): Dal punto di vista dell'applicazione, il livello di trasporto fa in modo che tutto proceda come se gli host comunicanti fossero direttamente connessi, anche se fisicamente si trovano agli antipodi del pianeta e sono separati da numerosi router.
- **Posizionamento:** I protocolli a livello di trasporto sono implementati esclusivamente nei sistemi periferici (host) e **non** nei router della rete.
- **Conversione e Incapsulamento:**
    - **Lato mittente:** Il livello di trasporto converte i messaggi ricevuti dal processo applicativo in **segmenti** (_transport-layer segment_). Questo avviene spezzando i messaggi (se necessario) e aggiungendo un'intestazione di trasporto. Il segmento viene poi passato al livello di rete, dove viene incapsulato in un **datagramma** (pacchetto a livello di rete) e inviato. I router intermedi esaminano solo i campi a livello di rete, ignorando il segmento incapsulato.
    - **Lato ricevente:** Il livello di rete estrae il segmento dal datagramma e lo passa al livello superiore (il trasporto).

###### L'Analogia del Servizio Postale
Per comprendere la differenza tra livello di trasporto e livello di rete, si può utilizzare l'analogia di due condomini (uno a Milano e uno a Roma) abitati da cugini che si scrivono lettere.
- **Processi:** I cugini.
- **Host (sistemi periferici):** I condomini.
- **Protocollo a livello di trasporto:** Anna (a Roma) e Andrea (a Milano), che raccolgono la posta dai fratelli e la distribuiscono a livello locale.
- **Protocollo a livello di rete:** Il servizio postale, che sposta le lettere da un condominio all'altro.
- **Messaggi dell'applicazione:** Le lettere nelle buste.
I protocolli di trasporto (Anna e Andrea) lavorano solo ai bordi della rete, trasferendo i messaggi dai processi al livello di rete, ma non sono coinvolti nello smistamento intermedio. Inoltre, i servizi che il livello di trasporto può offrire sono fortemente vincolati dal modello di servizio del protocollo sottostante (il livello di rete). Se il servizio postale non garantisce tempi massimi di consegna, Anna e Andrea non possono garantire ai cugini un limite di ritardo.

###### I Protocolli di Trasporto in Internet
A livello di rete usiamo **IP (Internet Protocol)** fornisce comunicazione logica tra host con un modello di servizio chiamato **best-effort delivery service** (massimo sforzo). IP fa del suo meglio per consegnare i segmenti, ma non offre garanzie: per questo è un servizio **non affidabile** (_unreliable service_). Ogni host possiede un indirizzo IP a livello di rete;
In una rete TCP/IP, il livello di trasporto offre due protocolli principali alle applicazioni:

- **UDP (User Datagram Protocol):** Fornisce un servizio non affidabile e **non orientato alla connessione**. UDP offre solo due servizi minimi: la consegna dei dati da processo a processo e un basilare controllo degli errori.
- **TCP (Transmission Control Protocol):** Offre un servizio affidabile e **orientato alla connessione**. questo è un protocollo complesso che fornisce servizi aggiuntivi fondamentali:
    - **Trasferimento dati affidabile:** Tramite controllo di flusso, numeri di sequenza, _acknowledgment_ e timer.
    - **Controllo di congestione** (_congestion control_): Evita che le connessioni TCP intasino i collegamenti e i router tra gli host con un traffico eccessivo.

###### Multiplexing e Demultiplexing
Questi due processi permettono di estendere il servizio di consegna da host-a-host (di IP) a un servizio di consegna processo-a-processo. Quello che ci permette di inviare i dati ai processi sono i **Socket**, quello che fai il livello di trasporto è trasferire i dati alla socket specifica piuttosto che semplicemente all'host ![[Pasted image 20260511095905.png|700]]
- **Multiplexing (Lato mittente):** Il compito di radunare frammenti di dati da diverse socket sull'host di origine, incapsulare ognuno con un'intestazione a livello di trasporto per creare segmenti, e passarli al livello di rete (come Anna che raccoglie e imbuca le lettere).
- **Demultiplexing (Lato ricevente):** Il compito di trasportare i dati dei segmenti in arrivo verso la giusta socket esaminando l'intestazione (come Andrea che legge il nome sulla busta e consegna la lettera al destinatario corretto).

Per far funzionare questo sistema, ogni socket deve avere un identificatore univoco e ogni segmento deve indicare la socket di destinazione. Questo si ottiene tramite i **numeri di porta** (campi da 16 bit, valori da 0 a 65535). ![[Pasted image 20260511095927.png|500]]
- **Numeri di porta noti:** I valori da 0 a 1023, riservati ad applicazioni standard.
- Ogni segmento contiene un **campo del numero di porta di origine** (_source port number field_) e un **campo del numero di porta di destinazione** (_destination port number field_).
###### Differenze di Demultiplexing: UDP vs TCP
- **Demultiplexing UDP:** Una socket UDP è identificata completamente da una coppia di parametri: **Indirizzo IP di destinazione** e **Numero di porta di destinazione**. Se due segmenti arrivano con indirizzi IP o porte di origine diversi, ma con identico IP e porta di destinazione, verranno diretti alla stessa socket UDP e quindi allo stesso processo.
- **Demultiplexing TCP:** Una socket TCP è identificata da quattro parametri: **Indirizzo IP di origine, Numero di porta di origine, Indirizzo IP di destinazione, Numero di porta di destinazione**. Due segmenti TCP in arrivo da origini diverse verranno diretti a due socket differenti (tranne per i segmenti di richiesta connessione).
    - _Esempio Web Server:_ Un web server Apache in ascolto sulla porta 80 genera processi/thread e socket di connessione diverse per ogni client, distinguendoli grazie agli IP e alle porte di origine. ![[Pasted image 20260511095955.png|700]]
    - _Impatto di HTTP:_ Con HTTP persistente, i messaggi viaggiano sulla stessa socket. Con HTTP non persistente, viene creata e chiusa una nuova connessione per ogni richiesta/risposta, impattando sulle prestazioni del server.
### UDP - User Datagram protocol
UDP è un protocollo ridotto all'osso che fa il minimo indispensabile. Aggiunge a IP solo il multiplexing/demultiplexing e un basilare controllo degli errori. Quando si usa UDP, l'applicazione dialoga quasi direttamente con IP. L'intestazione UDP è di soli **8 byte** (contro i 20 byte di TCP).

A primo impatto ci chiediamo che senso ha usare UDP piuttosto che TCP se ci offre pochissimi servizi? Di seguito vediamo diversi motivi:
1. **Controllo più preciso a livello applicativo:** UDP non avendo il controllo di congestione, invia immediatamente i dati trasferiti dal processo al livello di rete. È ideale per applicazioni in tempo reale che tollerano perdita di dati ma non ritardi.
2. **Nessuna connessione stabilita:** Non essendoci un _handshake_ iniziale (come in TCP), UDP non introduce ritardi di avvio. È il motivo per cui il protocollo DNS utilizza UDP.
3. **Nessuno stato di connessione:** UDP non memorizza parametri nei sistemi periferici (nessun buffer, parametri di congestione o numeri di sequenza/acknowledgment).
4. **Minor spazio usato per l'intestazione**
![[Pasted image 20260511100037.png|700]]
È possibile ottenere un trasferimento dati affidabile su UDP solo se l'affidabilità viene implementata al livello superiore (es. il protocollo **QUIC** usa UDP come trasporto ma garantisce l'affidabilità a livello applicativo).
###### Struttura del Segmento UDP
Oltre al campo "Dati" (che contiene il messaggio dell'applicazione), l'intestazione presenta 4 campi da 2 byte:
- Numero di porta di origine.
- Numero di porta di destinazione.
- **Lunghezza:** Specifica il numero totale di byte del segmento (necessario poiché il campo dati è variabile).
- **Checksum**: serve per determinare se i bit del segmento in arrivo sono stati alterati durante il trasferimento
Di seguito come viene gestito il checksum:
- **Calcolo Lato Mittente:** Si esegue il complemento a 1 della somma di tutte le parole da 16 bit nel segmento. L'eventuale riporto finale della somma viene sommato al primo bit. Il risultato viene inserito nel campo Checksum.
- **Verifica Lato Ricevente:** Si sommano tutte le parole originali più il checksum ricevuto. Se il pacchetto è privo di errori, il risultato sarà una stringa di soli 1. Se così non fosse i dati sono arrivati alterati, UDP scarta il segmento.

> [!EXAMPLE] Esempio matematico
> Supponendo che il segmento in arrivo sia formato solo da tre parole da 16 bit:
> - 0110011001100000
> - 0101010101010101
> - 1000111100001100
> 
>Procediamo in questo modo:
> - Somma delle prime due parole $0110011001100000 + 0101010101010101 = 1011101110110101$
> - Aggiunta della terza parola (e la somma supera i 16 bit devi sempre aggiungere quel bit "extra" in fondo al risultato) $1011101110110101 + 1000111100001100 = 0100101011000010$
> - Facciamo il complemento a 1:  $0100101011000010 \rightarrow 1011010100111101$
> - il valore calcolato nel punto precedente viene salvato nel checksum
> - il pacchetto arriva nel ricevente
> - fa la somma delle prime tre parole a 16 bit (seguendo le regole del bit extra): $0110011001100000 + 0101010101010101 +1000111100001100 = 0100101011000010$
> - Aggiunge il valore salvato nel checksum alla somma: $0100101011000010 + 1011010100111101 = 1111111111111111$
>  
> Visto che abbiamo ottenuto una sequenza di 1 non ci sono stati errori, se ci sono degli 0 allora i dati sono arrivati alterati

### RDT - Reliable data transfer protocol
Il problema del **trasferimento dati affidabile** (_reliable data transfer protocol_) è trasversale nel _networking_ (riguarda i livelli di trasporto, collegamento e applicazione).
- **Astrazione del servizio:** L'obiettivo è fornire ai livelli superiori un "canale affidabile" in cui nessun bit viene corrotto o perso, e in cui si assume che i pacchetti non vengano riordinati.
- **Difficoltà:** Implementare questa astrazione è complesso perché il livello sottostante (es. IP) può essere inaffidabile.
- **Modalità:** La complessità concettuale riguarda il **trasferimento dati unidirezionale** (_unidirectional data transfer_), ma nella pratica è necessario gestire il **trasferimento dati bidirezionale** (_bidirectional data transfer_ o _full-duplex_), permettendo ai punti terminali di trasmettere pacchetti in entrambe le direzioni.
Di seguito la costruzione di un protocollo di dati affidabile, da un modello semplice ad un modello complesso che prende i considerazione tutte le casistiche
###### rdt1.0: Trasferimento su canale completamente affidabile
Il caso più semplice è rappresentato da **rdt1.0**, che modella la trasmissione su un canale perfettamente affidabile, dove non avvengono mai né perdite né alterazioni di bit. Il comportamento del mittente e del destinatario è modellato attraverso macchine a stati finiti (note come **FSM**, dall'inglese _Finite-State Machine_).

![[Pasted image 20260511102721.png|700]]

Dato che le FSM in questo caso hanno un unico stato, le transizioni avvengono necessariamente tra quello stato e sé stesso.
- **Lato Mittente:** Accetta i dati dal livello superiore tramite l’evento `rdt_send(data)`, genera un pacchetto tramite l'azione `make_pkt(data)` e lo invia sul canale. In un'applicazione reale, questo evento è solitamente il risultato di una chiamata a procedura.
- **Lato Ricevente:** Raccoglie i pacchetti dal livello inferiore tramite l’evento `rdt_rcv(packet)`, estrae i dati con l'azione `extract(packet,data)` e li passa al livello superiore con l'azione `deliver_data(data)`.

In un canale perfettamente affidabile, tutti i dati fluiscono dal mittente al destinatario senza intoppi. Non c'è alcun bisogno che il destinatario fornisca un _feedback_ al mittente, poiché "nulla può andare storto". Si ipotizza, inoltre, che il destinatario riesca a processare i dati alla stessa velocità con cui questi vengono inviati.

###### rdt2.0: Canale con errori sui bit e Protocolli ARQ
Un modello più realistico del canale sottostante prevede che i singoli bit all'interno di un pacchetto possano subire corruzioni (errori). Per risolvere questo problema, si introducono protocolli basati sulla logica che usiamo durante una comunicazione telefonica difficile: chi ascolta conferma di aver capito ("OK") o chiede di ripetere ("Come scusa?"). Nelle reti di calcolatori, questo approccio basato sulle ritrasmissioni prende il nome di **Protocollo ARQ**.
- **Protocolli ARQ** (_Automatic Repeat reQuest_): Famiglia di protocolli che gestisce gli errori di trasmissione utilizzando notifiche di avvenuta o mancata ricezione per innescare eventuali ritrasmissioni.

I protocolli ARQ richiedono tre funzionalità fondamentali:
1. **Rilevamento dell’errore** (_error detection_): Un meccanismo che consenta al destinatario di accorgersi se i bit sono stati alterati (come ad esempio l'uso del campo _checksum_ nel protocollo UDP).
2. **Feedback del destinatario** (_receiver feedback_): Risposte esplicite inviate dal destinatario al mittente per confermare lo stato del pacchetto. Esistono due tipi di messaggi:
    - **ACK** (_positive acknowledgments_): Notifica positiva, il pacchetto è stato ricevuto intatto.
    - **NAK** (_negative acknowledgments_): Notifica negativa, il pacchetto presenta errori e deve essere scartato.
3. **Ritrasmissione** (_retransmission_): L'azione del mittente di rinviare un pacchetto se questo è stato ricevuto con errori.

![[Pasted image 20260511102747.png|700]]

Il protocollo **rdt2.0** opera secondo una logica nota come **stop-and-wait**:
- **Lato Mittente:** Ha due stati. Nel primo attende i dati dal livello superiore, vi aggiunge il _checksum_ e invia il pacchetto. Nel secondo stato si blocca in attesa di un ACK o di un NAK. Finché si trova in questo stato, **non può recepire nuovi dati** dal livello superiore. Se riceve un ACK, torna allo stato iniziale; se riceve un NAK, ritrasmette il pacchetto e continua ad attendere.
- **Lato Ricevente:** Ha un solo stato. All'arrivo di un pacchetto (evento `rdt_rcv(rcvpkt)`), controlla se ci sono errori (evento `corrupt(rcvpkt)`). Risponde inviando un ACK se è integro, oppure un NAK se è corrotto.

Questo protocollo presenta un problema critico: non prende in considerazione la possibilità che **gli stessi pacchetti ACK o NAK possano alterarsi** lungo il viaggio di ritorno verso il mittente. Se il mittente riceve una notifica illeggibile, non sa se il destinatario ha ricevuto i dati oppure no. L'approccio più semplice sarebbe quello di far ritrasmettere al mittente il pacchetto ogni volta che riceve un feedback illeggibile, ma questo introdurrebbe dei pacchetti duplicati (_duplicate packets_) nel canale. A quel punto, il ricevente non saprebbe distinguere se il pacchetto in arrivo contiene dati nuovi o è solo una ritrasmissione del pacchetto precedente.

###### rdt2.1 e rdt2.2: Gestione dei duplicati e rimozione dei NAK
La soluzione al problema dei pacchetti duplicati è elegante e semplice: aggiungere un **numero di sequenza** (_sequence number_) ai pacchetti dati.
- **Numero di sequenza:** Un campo aggiuntivo nel pacchetto. Per un protocollo _stop-and-wait_ è sufficiente 1 singolo bit (che si alterna tra 0 e 1), in quanto permette al destinatario di distinguere un pacchetto nuovo (numero di sequenza diverso dal precedente) da una ritrasmissione (stesso numero di sequenza del pacchetto appena ricevuto).

Nel protocollo **rdt2.1**, i pacchetti di ACK e NAK non necessitano di includere il numero di sequenza, perché non possono andare smarriti: il mittente sa sempre che il feedback ricevuto fa riferimento all'ultimo e unico pacchetto che ha trasmesso. L'introduzione dei numeri di sequenza costringe le FSM del mittente e del ricevente a raddoppiare i propri stati (devono tenere traccia se stanno processando un pacchetto con sequenza 0 oppure 1).

![[2.1.png]]

Il protocollo **rdt2.2** rappresenta un'evoluzione che elimina la necessità dei pacchetti NAK.

Anziché inviare un NAK per segnalare un errore, il ricevente invia semplicemente un ACK relativo al **pacchetto più recente ricevuto correttamente**, specificando all'interno dell'ACK il numero di sequenza. Se il mittente riceve due ACK identici per lo stesso pacchetto, deduce automaticamente che il ricevente non ha ricevuto correttamente il pacchetto successivo a quello appena confermato. Questo innesca la ritrasmissione senza il bisogno di un NAK esplicito.

![[2.2.png]]
###### rdt3.0: Gestione della perdita di pacchetti
Le reti reali (inclusa Internet) non si limitano a danneggiare i bit, ma possono smarrire interi pacchetti. Se il pacchetto dati o l'ACK vanno perduti, in un protocollo come rdt2.2 il mittente rimarrebbe bloccato per sempre in attesa di un feedback che non arriverà mai. Per risolvere il problema, il protocollo **rdt3.0** implementa un meccanismo di ritrasmissione basato sul tempo utilizzando un **contatore** (_countdown timer_). Il mittente attende un tempo prestabilito (sufficiente a coprire il ritardo di andata e ritorno più il tempo di elaborazione). Se il timer scade (_interrupt_) senza che sia arrivato un ACK, il mittente assume prudentemente che il pacchetto sia andato perso e **lo ritrasmette**. Se il pacchetto o l'ACK non erano persi ma solo in forte ritardo, questa azione genererà sul canale dei pacchetti duplicati, ma questi saranno gestiti agilmente grazie ai numeri di sequenza ereditati da rdt2.2. Dato che i numeri di sequenza si alternano costantemente tra 0 e 1, il protocollo rdt3.0 è noto anche come **protocollo ad alternanza di bit**.

![[Pasted image 20260511103713.png|700]]
###### Le performance e i Protocolli con Pipelining
Pur essendo funzionalmente ineccepibile, il protocollo rdt3.0 basato sulla logica _stop-and-wait_ risulta inaccettabile in termini di prestazioni, specialmente su reti ad alta velocità. Il collo di bottiglia è lo scarso **utilizzo del canale** (_utilization_).
- **Utilizzo:** Definito come la frazione di tempo in cui il mittente è attivamente impegnato a iniettare bit nel canale di trasmissione, rispetto al tempo totale impiegato ad attendere la risposta.


> [!EXAMPLE] Il calcolo delle prestazioni (Stop-and-wait)
> ![[Pasted image 20260511103604.png|700]]
> Per quantificare l'impatto di questo collo di bottiglia, consideriamo il caso ideale di due host connessi tra le due coste degli Stati Uniti. I parametri della rete sono i seguenti:
> *   **Velocità di trasmissione del canale ($R$):** 1 Gbps = $10^9$ bit/s
> *   **Dimensione del pacchetto ($L$):** 1000 byte = 8000 bit
> *   **Ritardo di andata e ritorno ($RTT$):** 30 ms = 0,03 s
> 
> **1. Tempo di trasmissione del pacchetto:**
> Il tempo fisicamente richiesto per immettere sul canale tutti i bit che compongono il pacchetto è:
> $$t = \frac{L}{R} = \frac{8000}{10^9} = 8 \text{ mu s} = 0,008 \text{ ms}$$
> 
> **2. Ciclo di invio e attesa:**
> Se il mittente inizia a trasmettere a $t = 0$, l'ultimo bit entra nel canale a $t = 0,008 \text{ ms}$. Il pacchetto impiega 15 ms ($RTT/2$) per attraversare il continente e giungere al destinatario. Assumendo che il pacchetto ACK sia minuscolo (tempo di trasmissione trascurabile) e che venga generato istantaneamente, l'ACK impiega altri 15 ms per compiere il viaggio di ritorno.
> Il tempo totale che intercorre prima che il mittente possa inviare il pacchetto successivo è quindi:
> $$t_{totale} = \frac{L}{R} + RTT = 0,008 \text{ ms} + 30 \text{ ms} = 30,008 \text{ ms}$$
> 
> **3. Utilizzo del mittente ($U_{mittente}$):**
> L'utilizzo è il rapporto tra il tempo in cui il mittente è stato effettivamente attivo e il tempo totale del ciclo:
> $$U_{mittente} = \frac{L/R}{RTT + L/R} = \frac{0,008}{30,008} \approx 0,00027$$
> 
> **Conclusione:**
> Il risultato di 0,00027 equivale allo **0,027%**. In altre parole, su una rete ultra-veloce da 1 Gbps, la logica stop-and-wait costringe il mittente a rimanere inattivo per oltre il 99,9% del tempo. Questo esempio pratico dimostra come *protocolli di rete inadeguati possano limitare o azzerare il rendimento dell'hardware di rete sottostante*.

Per abbattere questo limite prestazionale e sfruttare appieno l'hardware di rete, si utilizza una tecnica chiamata **Pipelining**. Una modalità operativa in cui si consente al mittente di iniettare nel canale **pacchetti multipli in successione**, senza doversi fermare ad attendere l'ACK per ogni singolo invio. In questo modo si riempie la "tubatura" che collega i due host, moltiplicando esponenzialmente l'utilizzo del canale. 

![[Pasted image 20260511103627.png|700]]
L'implementazione del pipelining ha un profondo impatto sull'architettura del protocollo:
1. **Espansione dei numeri di sequenza:** Dato che ci saranno contemporaneamente in transito più pacchetti non ancora confermati, lo spazio numerico dei numeri di sequenza deve essere incrementato (non bastano più solo 0 e 1).
2. **Necessità di Buffer:** I sistemi devono implementare delle code di memoria (Buffer). Il mittente deve obbligatoriamente memorizzare temporaneamente tutti i pacchetti inviati di cui non ha ancora ricevuto l'ACK (per le eventuali ritrasmissioni), e spesso il ricevente deve bufferizzare a sua volta per processare i dati fuori ordine.

Le due soluzioni principali per la gestione degli errori e la risoluzione dei pacchetti smarriti in regime di pipelining sono il protocollo **Go-Back-N** e la **Ripetizione Selettiva** (_selective repeat_).

### Gestione degli errori
###### Il Protocollo Go-Back-N (GBN)
In un protocollo **Go-Back-N (GBN)** il mittente può trasmettere più pacchetti consecutivamente senza dover attendere alcun riscontro, ma non può mantenere nella pipeline un numero di pacchetti non ancora riscontrati superiore a un valore massimo consentito, definito come $N$.
![[Pasted image 20260511163217.png|700]]
Analizzando l'intervallo dei numeri di sequenza dal punto di vista del mittente, possiamo definire due variabili fondamentali:
- **base:** Il numero di sequenza del pacchetto più vecchio che non ha ancora ricevuto un acknowledgment.
- **nextseqnum:** Il più piccolo numero di sequenza inutilizzato (ovvero il numero di sequenza del prossimo pacchetto da inviare).

Sulla base di queste variabili, è possibile suddividere lo spazio dei numeri di sequenza in quattro intervalli distinti:
- **$[0, base–1]$:** Corrisponde ai pacchetti già trasmessi per i quali è stato regolarmente ricevuto un acknowledgment.
- **$[base, nextseqnum–1]$:** Corrisponde ai pacchetti già inviati, ma che non hanno ancora ricevuto alcun acknowledgment.
- **$[nextseqnum, base+N–1]$:** Numeri di sequenza immediatamente disponibili per l'invio di nuovi pacchetti, qualora arrivassero dati dal livello superiore.
- **$\ge base+N$:** Numeri di sequenza non utilizzabili finché il mittente non riceve un acknowledgment per uno dei pacchetti attualmente nella pipeline.

**Ampiezza della finestra** (_window size_): È il valore $N$, che rappresenta l'intervallo di numeri di sequenza ammissibili per i pacchetti trasmessi ma non ancora riscontrati. Può essere visualizzato come una "finestra" che si sposta sull'intervallo complessivo dei numeri di sequenza.

**Protocollo a finestra scorrevole:** Denominazione alternativa e comune per indicare il protocollo GBN, derivante proprio dalla dinamica di scorrimento della finestra $N$.

A livello implementativo, il numero di sequenza di un pacchetto viene codificato in un campo a dimensione fissa della sua intestazione. Se questo campo ha una dimensione di $k$ bit, l'intervallo dei numeri di sequenza possibili sarà $[0, 2^k - 1]$. Essendo lo spazio limitato, tutte le operazioni aritmetiche sui numeri di sequenza avvengono in modulo $2^k$. Di conseguenza, lo spazio dei numeri di sequenza è un insieme ciclico in cui il valore $2^k - 1$ è immediatamente seguito dallo $0$. 


![[Schermata.png]]

Queste figure illustrano le FSM (Finite State Machine) estese per mittente e ricevente in un protocollo GBN basato esclusivamente su ACK (e privo di NAK).

Il **mittente GBN** deve gestire tre tipologie di eventi:
1. **Invocazione dall’alto:** Quando il livello superiore chiama la funzione `rdt_send()`, il mittente verifica innanzitutto se la finestra è piena (ovvero se ci sono già $N$ pacchetti in sospeso senza acknowledgment).
    - Se la finestra _non_ è piena: crea il pacchetto, lo invia e aggiorna le variabili.
    - Se la finestra _è_ piena: restituisce i dati al livello superiore, il quale riproverà la trasmissione in un secondo momento.
2. **Ricezione di un ACK:** Nel protocollo GBN, viene utilizzato un **Acknowledgment cumulativo** (_cumulative acknowledgment_). Questo significa che la ricezione di un ACK per il pacchetto con numero di sequenza $n$ conferma che _tutti_ i pacchetti con numero di sequenza minore o uguale a $n$ sono stati ricevuti correttamente dal destinatario.
3. **Evento di timeout:** È l'evento che dà il nome al protocollo ("Go-Back-N"). Per gestire la perdita di dati o di ACK, si utilizza un contatore temporale. Allo scadere del _timeout_, il mittente adotta un approccio drastico: ritrasmette in blocco tutti i pacchetti precedentemente inviati che non hanno ancora ricevuto un acknowledgment.

Le azioni del **destinatario GBN** seguono regole molto rigide:
- **Pacchetto in ordine:** Se un pacchetto $n$ viene ricevuto in modo corretto ed è esattamente il pacchetto atteso nella sequenza, il ricevente genera un ACK per $n$ e consegna i dati al livello superiore.
- **Pacchetto fuori sequenza:** In tutti gli altri casi, il destinatario scarta immediatamente il pacchetto e reinvia un ACK relativo all'ultimo pacchetto ricevuto correttamente in ordine.

**Perché scartare pacchetti corretti ma fuori sequenza?**
Sebbene eliminare un pacchetto corretto (es. $n+1$) possa sembrare inefficace, esiste una motivazione architettonica precisa. Il livello di trasporto deve consegnare i dati in ordine al livello superiore. Se si perdesse il pacchetto $n$, memorizzare in un buffer il pacchetto $n+1$ risulterebbe inutile: a causa della regola di gestione dei timeout del GBN, il mittente ritrasmetterebbe comunque sia $n$ che $n+1$.
- _Vantaggio:_ Estrema semplicità per il ricevente, che non deve gestire buffer per i pacchetti fuori sequenza. L'unica informazione che deve memorizzare è il numero di sequenza del pacchetto successivo atteso.
- _Svantaggio:_ Un pacchetto arrivato integro viene cestinato e la sua successiva ritrasmissione potrebbe essere soggetta a perdite o alterazioni, innescando ulteriori cicli di ritrasmissione.
![[Pasted image 20260511162630.png|700]]
In questo esempio, il protocollo opera con una finestra di ampiezza pari a 4. Il mittente invia i pacchetti da $0$ a $3$ e si ferma in attesa. All'arrivo di ACK0 e ACK1, la finestra scorre in avanti consentendo la trasmissione di pkt4 e pkt5. Lato ricevente, il pkt2 viene perso. Di conseguenza, i pacchetti $3$, $4$ e $5$ arrivano fuori sequenza e vengono inesorabilmente scartati.

Il protocollo GBN contiene molte delle tecniche impiegate dal TCP, permettendo al mittente di "riempire la tubatura" e risolvendo il problema dello scarso utilizzo del canale tipico dei protocolli _stop-and-wait_. Tuttavia, presenta un grave limite prestazionale: se l'ampiezza della finestra e il prodotto banda-ritardo sono molto elevati, la perdita di un singolo pacchetto genera una valanga di ritrasmissioni inutili.

###### Il Protocollo a Ripetizione Selettiva (SR)
Per ovviare alle inefficienze del GBN, nascono i **Protocolli a ripetizione selettiva** (_Selective-Repeat Protocol_, SR). Questi evitano le ritrasmissioni superflue obbligando il mittente a ritrasmettere esclusivamente i pacchetti che si sospetta siano andati persi o danneggiati. Questo approccio richiede che il destinatario confermi in modo specifico e individuale (non cumulativo) ogni pacchetto ricevuto correttamente.
- Il ricevente SR genera un acknowledgment per i pacchetti intatti, indipendentemente dal fatto che arrivino in ordine o fuori sequenza.
- I pacchetti fuori sequenza vengono memorizzati in un apposito buffer fino all'arrivo dei pacchetti mancanti (quelli con numeri di sequenza inferiori). Solo a quel punto, l'intero blocco di pacchetti riordinato viene consegnato al livello superiore.

![[Pasted image 20260511162505.png|700]]

Il protocollo a ripetizione selettiva gestisce l'invio e la ricezione tramite due finestre scorrevoli (sliding window) di ampiezza $N$, disaccoppiando lo stato del mittente da quello del ricevente.

**a. Visione del mittente sui numeri di sequenza**
Il mittente visualizza una finestra di ampiezza $N$ delimitata inferiormente dal puntatore `send_base` (il numero di sequenza del pacchetto non riscontrato più vecchio). Un secondo puntatore, `nextseqnum`, indica il limite fino al quale i pacchetti sono stati inviati. I pacchetti si dividono in quattro categorie:
1. **Già riscontrati:** Pacchetti inviati per i quali è stato regolarmente ricevuto l'ACK (possono trovarsi all'interno della finestra se pacchetti precedenti risultano ancora non riscontrati).
2. **Inviati, non ancora riscontrati:** Pacchetti trasmessi (compresi tra `send_base` e `nextseqnum`) per i quali è in corso il timer e si attende l'ACK.
3. **Utilizzabili, non ancora inviati:** Numeri di sequenza all'interno della finestra $N$ che il mittente è autorizzato a trasmettere non appena ci sono dati disponibili dal livello superiore.
4. **Non utilizzabili:** Numeri di sequenza al di fuori dell'attuale finestra di trasmissione. Non potranno essere usati finché la ricezione degli ACK non farà scorrere la base della finestra in avanti.

**b. Visione del ricevente sui numeri di sequenza**
Anche il ricevente mantiene una propria finestra di ampiezza $N$, basata sul puntatore `rcv_base` che identifica il pacchetto atteso con il numero di sequenza più basso. Gli stati dei pacchetti lato ricevente sono:
1. **Atteso, non ancora ricevuto:** Pacchetti mancanti all'interno della finestra (a partire da `rcv_base`), la cui assenza impedisce alla finestra di scorrere e la consegna dei dati ai livelli superiori.
2. **Non in ordine (nel buffer) ma già riscontrato:** Pacchetti ricevuti correttamente ma con un numero di sequenza superiore a pacchetti mancanti. Il ricevente li inserisce in un buffer e invia il relativo ACK al mittente.
3. **Accettabile (all'interno della finestra):** Spazio libero nella finestra di ricezione pronto per ospitare futuri pacchetti in arrivo.
4. **Non utilizzabile:** Pacchetti con numeri di sequenza fuori dalla finestra corrente, che verrebbero scartati perché non attesi in questa fase.

![[Pasted image 20260511162533.png|700]]

Come mostrato in Figura 3.26, se si perde il pacchetto $2$, i pacchetti $3$, $4$ e $5$ vengono temporaneamente isolati nel buffer del ricevente e consegnati in blocco al livello superiore solo quando il pacchetto $2$ viene finalmente ricevuto e processato.

**Eventi e azioni del Mittente SR:**
1. **Dati ricevuti dall’alto:** Controlla il numero di sequenza disponibile. Se rientra nella finestra di trasmissione, il pacchetto viene inviato; altrimenti, i dati vengono messi in un buffer o restituiti al livello superiore (esattamente come in GBN).
2. **Timeout:** Per monitorare le perdite, ogni pacchetto necessita di un proprio timer logico indipendente, poiché in caso di _timeout_ verrà ritrasmesso solo quello specifico pacchetto. A livello pratico, è possibile utilizzare un singolo contatore hardware per simulare le operazioni di molteplici timer logici
3. **ACK ricevuto:** Il mittente marca il pacchetto come "ricevuto". Se il numero di sequenza confermato coincide con `send_base` (la base attuale della finestra), la finestra avanza fino al successivo pacchetto in attesa di riscontro con il numero di sequenza più piccolo. Se questo slittamento fa rientrare nuovi pacchetti non ancora trasmessi all'interno della finestra utile, questi vengono immediatamente inviati.

**Eventi e azioni del Ricevente SR:**
1. **Ricezione corretta nell'intervallo** $\text{ [rcv\_base }, \text{ rcv\_base+N–1] }$ Il pacchetto cade all'interno della finestra di ricezione. Viene generato e inviato un ACK selettivo. Se il pacchetto è nuovo, viene messo nel buffer. Se il suo numero di sequenza equivale a `rcv_base`, esso e tutti i successivi pacchetti contigui già bufferizzati vengono consegnati al livello superiore, permettendo l'avanzamento della finestra di ricezione.
2. **Ricezione nell'intervallo** $\text{ [rcv\_base-N }, \text{ rcv\_base–1] }$ È cruciale notare che se arriva un pacchetto con numero di sequenza obsoleto, il ricevente **deve comunque generare un ACK**, anche se lo aveva già riscontrato in passato.
    - _Perché è necessario?_ Se l'ACK originario di un pacchetto è andato perso, la finestra del mittente non può avanzare. Il mittente continuerà a ritrasmettere il pacchetto credendolo perso. Se il ricevente ignorasse questa ritrasmissione, il protocollo andrebbe in stallo.
3. **Qualsiasi altro caso:** Il pacchetto viene ignorato.

Questa gestione asincrona degli ACK implica una conseguenza fondamentale: **Nei protocolli SR le finestre del mittente e del destinatario non sempre coincidono.**

![[Pasted image 20260511162425.png|700]]

L'utilizzo di un intervallo finito di numeri di sequenza genera potenziali ambiguità se la finestra è troppo grande. Immaginiamo uno spazio di 4 numeri di sequenza ($0, 1, 2, 3$) e una finestra di ampiezza $3$. Il mittente spedisce $0, 1, 2$.
- **Scenario A:** Gli ACK per $0, 1$ e $2$ vanno persi. Il mittente va in _timeout_ e ritrasmette il pacchetto $0$. Il destinatario riceve il pacchetto $0$, che in questo caso è una **copia** del primo pacchetto.
- **Scenario B:** Gli ACK per $0, 1$ e $2$ arrivano correttamente. La finestra del mittente avanza sui numeri $3, 0$ e $1$. Invia il $3$ (che va perso) e invia il nuovo pacchetto $0$. Il destinatario riceve il pacchetto $0$, che in questo caso contiene **nuovi dati**.
Dal punto di vista del ricevente (che non vede lo stato interno del mittente ma solo ciò che transita sul canale), le due situazioni sono indistinguibili. Non ha modo di capire se il pacchetto $0$ ricevuto sia la ritrasmissione del vecchio pacchetto o la trasmissione di uno nuovo. Chiaramente, un’ampiezza di finestra inferiore di uno rispetto a quella dello spazio dei numeri di sequenza non funziona. Ma quanto deve essere piccola la finestra? la finestra deve avere ampiezza inferiore o uguale alla metà dello spazio dei numeri di sequenza dei protocolli SR.

### TCP


