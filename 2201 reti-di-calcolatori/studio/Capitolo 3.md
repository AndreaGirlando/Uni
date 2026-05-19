### Introduzione al livello trasporto
###### Introduzione e funzioni principali
Posto tra il livello di applicazione e quello di rete, il livello di trasporto costituisce una parte centrale dell’architettura stratificata delle reti. La sua funzione critica è fornire servizi di comunicazione direttamente ai processi applicativi in esecuzione su host differenti.
- **Comunicazione logica** (_logical communication_): Dal punto di vista dell'applicazione, il livello di trasporto fa in modo che tutto proceda come se gli host comunicanti fossero direttamente connessi, anche se fisicamente si trovano agli antipodi del pianeta e sono separati da numerosi router.
- **Posizionamento:** I protocolli a livello di trasporto sono implementati esclusivamente nei sistemi periferici (host) e **non** nei router della rete.
- **Conversione e Incapsulamento:**
    - **Lato mittente:** Il livello di trasporto converte i messaggi ricevuti dal processo applicativo in **segmenti** (_transport-layer segment_). Questo avviene spezzando i messaggi (se necessario) e aggiungendo un'intestazione di trasporto. Il segmento viene poi passato al livello di rete, dove viene incapsulato in un **datagramma** (pacchetto a livello di rete) e inviato. I router intermedi esaminano solo i campi a livello di rete, ignorando il segmento incapsulato.
    - **Lato ricevente:** Il livello di rete estrae il segmento dal datagramma e lo passa al livello superiore (il trasporto).

###### L'Analogia del servizio postale
Per comprendere la differenza tra livello di trasporto e livello di rete, si può utilizzare l'analogia di due condomini (uno a Milano e uno a Roma) abitati da cugini che si scrivono lettere.
- **Processi:** I cugini.
- **Host (sistemi periferici):** I condomini.
- **Protocollo a livello di trasporto:** Anna (a Roma) e Andrea (a Milano), che raccolgono la posta dai fratelli e la distribuiscono a livello locale.
- **Protocollo a livello di rete:** Il servizio postale, che sposta le lettere da un condominio all'altro.
- **Messaggi dell'applicazione:** Le lettere nelle buste.
I protocolli di trasporto (Anna e Andrea) lavorano solo ai bordi della rete, trasferendo i messaggi dai processi al livello di rete, ma non sono coinvolti nello smistamento intermedio. Inoltre, i servizi che il livello di trasporto può offrire sono fortemente vincolati dal modello di servizio del protocollo sottostante (il livello di rete). Se il servizio postale non garantisce tempi massimi di consegna, Anna e Andrea non possono garantire ai cugini un limite di ritardo.

###### I protocolli di trasporto in internet
A livello di rete usiamo **IP (Internet Protocol)** fornisce comunicazione logica tra host con un modello di servizio chiamato **best-effort delivery service** (massimo sforzo). IP fa del suo meglio per consegnare i segmenti, ma non offre garanzie: per questo è un servizio **non affidabile** (_unreliable service_). Ogni host possiede un indirizzo IP a livello di rete; In una rete TCP/IP, il livello di trasporto offre due protocolli principali alle applicazioni:
- **UDP (User Datagram Protocol):** Fornisce un servizio non affidabile e **non orientato alla connessione**. UDP offre solo due servizi minimi: la consegna dei dati da processo a processo e un basilare controllo degli errori.
- **TCP (Transmission Control Protocol):** Offre un servizio affidabile e **orientato alla connessione**. questo è un protocollo complesso che fornisce servizi aggiuntivi fondamentali:
    - **Trasferimento dati affidabile:** Tramite controllo di flusso, numeri di sequenza, _acknowledgment_ e timer.
    - **Controllo di congestione** (_congestion control_): Evita che le connessioni TCP intasino i collegamenti e i router tra gli host con un traffico eccessivo.

###### Multiplexing e demultiplexing
Questi due processi permettono di estendere il servizio di consegna da host-a-host (di IP) a un servizio di consegna processo-a-processo. Quello che ci permette di inviare i dati ai processi sono i **socket**. Praticamente quello che fai il livello di trasporto è trasferire i dati alla socket specifica piuttosto che semplicemente all'host ![[Pasted image 20260511095905.png|700]]
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

Nel protocollo **rdt2.1**, i pacchetti di ACK e NAK non necessitano di includere il numero di sequenza, perché non possono andare smarriti: il mittente sa sempre che il feedback ricevuto fa riferimento all'ultimo e unico pacchetto che ha trasmesso. L'introduzione dei numeri di sequenza costringe le FSM del mittente e del ricevente a raddoppiare i propri stati (devono tenere traccia se stanno processando un pacchetto con sequenza 0 oppure 1). ![[2.1.png|800]]
Il protocollo **rdt2.2** rappresenta un'evoluzione che elimina la necessità dei pacchetti NAK. Anziché inviare un NAK per segnalare un errore, il ricevente invia semplicemente un ACK relativo al **pacchetto più recente ricevuto correttamente**, specificando all'interno dell'ACK il numero di sequenza. Se il mittente riceve due ACK identici per lo stesso pacchetto, deduce automaticamente che il ricevente non ha ricevuto correttamente il pacchetto successivo a quello appena confermato. Questo innesca la ritrasmissione senza il bisogno di un NAK esplicito. ![[2.2.png|800]]
###### rdt3.0: Gestione della perdita di pacchetti
Le reti reali (inclusa Internet) non si limitano a danneggiare i bit, ma possono smarrire interi pacchetti. Se il pacchetto dati o l'ACK vanno perduti, in un protocollo come rdt2.2 il mittente rimarrebbe bloccato per sempre in attesa di un feedback che non arriverà mai. Per risolvere il problema, il protocollo **rdt3.0** implementa un meccanismo di ritrasmissione basato sul tempo utilizzando un **contatore** (_countdown timer_). Il mittente attende un tempo prestabilito (sufficiente a coprire il ritardo di andata e ritorno più il tempo di elaborazione). Se il timer scade (_interrupt_) senza che sia arrivato un ACK, il mittente assume prudentemente che il pacchetto sia andato perso e **lo ritrasmette**. Se il pacchetto o l'ACK non erano persi ma solo in forte ritardo, questa azione genererà sul canale dei pacchetti duplicati, ma questi saranno gestiti agilmente grazie ai numeri di sequenza ereditati da rdt2.2. Dato che i numeri di sequenza si alternano costantemente tra 0 e 1, il protocollo rdt3.0 è noto anche come **protocollo ad alternanza di bit**.

![[Pasted image 20260511103713.png|700]]
###### Le performance e i Protocolli con Pipelining
Pur essendo funzionalmente ineccepibile, il protocollo rdt3.0 basato sulla logica _stop-and-wait_ risulta inaccettabile in termini di prestazioni, specialmente su reti ad alta velocità. Il collo di bottiglia è lo scarso **utilizzo del canale** (_utilization_).

**Utilizzo:** Definito come la frazione di tempo in cui il mittente è attivamente impegnato a iniettare bit nel canale di trasmissione, rispetto al tempo totale impiegato ad attendere la risposta.

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
###### Il protocollo Go-Back-N (GBN)
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

###### Il Protocollo a ripetizione selettiva (SR)
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
Ora che sono stati stabiliti i principi fondamentali alla base del trasferimento dati affidabile, l'attenzione si sposta sul **TCP**, ovvero il protocollo di Internet a livello di trasporto che garantisce un servizio **affidabile e orientato alla connessione**. Per offrire questo trasferimento senza errori, il TCP si basa su una combinazione complessa di meccanismi.

###### Principi e Caratteristiche Generali
- **Orientato alla connessione (connection-oriented):** Il TCP è definito in questo modo perché, prima di poter iniziare l'effettivo scambio dei dati, i due processi comunicanti devono obbligatoriamente effettuare una fase preliminare detta *handshake a tre vie*. Una volta instaurata la connessione, i due processi possono finalmente scambiarsi dati. Il processo client manda un flusso di dati attraverso la _socket_. Non appena i dati attraversano questo punto di uscita, passano nelle mani del TCP in esecuzione nel client. TCP dirige immediatamente i dati al **buffer di invio della connessione** (uno specifico buffer che è stato allocato e riservato proprio durante la fase di handshake a tre vie). Da questo buffer, il protocollo preleverà di tanto in tanto dei blocchi di dati e li passerà al sottostante livello di rete.
- **Stato residente nei sistemi periferici:** È fondamentale chiarire che la "connessione" TCP non è un circuito _end-to-end_ fisico. Lo stato della connessione risiede unicamente ed esclusivamente nei due host periferici (i sistemi finali). Dato che il protocollo TCP va in esecuzione solo sui sistemi periferici e non negli elementi di rete intermedi (come i router), la rete stessa "non sa" dell'esistenza della connessione.
- **Servizio Full-Duplex:** Una connessione TCP consente il traffico bidirezionale simultaneo. Se esiste una connessione tra un processo A (su un host) e un processo B (su un altro host), i dati applicativi possono fluire da A verso B nello stesso identico momento in cui fluiscono da B verso A.
- **Punto a punto (point-to-point):** La comunicazione ha luogo strettamente tra un singolo mittente e un singolo destinatario. L'invio di tipo _multicast_ (ovvero il trasferimento di dati da un mittente a molti destinatari simultaneamente in un'unica operazione) con il TCP non è in alcun modo possibile.
###### Gestione delle Dimensioni dei Dati: MSS e MTU
La massima quantità di dati prelevabili dal buffer e posizionabili in un singolo segmento è rigorosamente limitata da un parametro:
- **MSS (Maximum Segment Size - Dimensione massima di segmento):** Rappresenta la massima quantità di dati a livello di applicazione che può essere inserita nel segmento.
- **MTU (Maximum Transmission Unit - Unità trasmissiva massima):** È la lunghezza del frame più grande che può essere inviato a livello di collegamento dall'host locale.

**Come si calcola l'MSS?** Generalmente, il valore dell'MSS viene impostato scegliendo una dimensione tale che l'intero segmento TCP possa stare comodamente all'interno di un singolo frame a livello di collegamento (MTU), tenendo però conto anche dello spazio occupato dalle intestazioni. Normalmente, l'intestazione combinata TCP/IP è pari a 40 byte. Protocolli di collegamento molto diffusi, come Ethernet e PPP, hanno un MTU standard di 1500 byte. Quando TCP riceve un file di grandi dimensioni (ad esempio un'immagine che fa parte di una pagina web), lo frammenta in porzioni di dimensione pari all'MSS. A ogni blocco di dati accoppia un'intestazione TCP, formando così i veri e propri segmenti. Questi vengono passati al livello di rete (dove sono incapsulati nei datagrammi IP) e immessi in rete. All'altro capo, quando il TCP riceve il segmento, immagazzina i dati nel **buffer di ricezione** della connessione, da cui l'applicazione destinataria andrà a leggere. Entrambi i lati della connessione possiedono il proprio buffer di invio e di ricezione.

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

###### Acknowledgment Cumulativi e anomalie di ricezione
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
1. **SampleRTT:** È l'RTT effettivamente misurato su un singolo segmento trasmesso. Anziché misurare ogni singolo pacchetto, la maggior parte delle implementazioni TCP valuta un solo _SampleRTT_ alla volta, relativo ai segmenti per cui non si è ancora ricevuto riscontro.
2. **EstimatedRTT:** I valori del _SampleRTT_ fluttuano continuamente a causa del traffico di rete. TCP calcola quindi una media chiamata _EstimatedRTT_, aggiornata costantemente secondo una **Media Mobile Esponenziale Ponderata (EWMA, Exponential Weighted Moving Average)**. La formula (dove il peso $\alpha$ consigliato è 0,125) attribuisce maggiore importanza ai campioni recenti, in quanto riflettono meglio l'effettiva congestione attuale: $$EstimatedRTT = (1 - 0,125) \times EstimatedRTT + 0,125 \times SampleRTT$$
3. **DevRTT:** Oltre alla media, è fondamentale conoscere la variazione (variabilità) del tempo di risposta. _DevRTT_ è un EWMA che stima quanto il _SampleRTT_ si discosta dalla media _EstimatedRTT_. Se le fluttuazioni sono limitate, _DevRTT_ sarà piccolo; in caso di traffico irregolare, sarà grande. Il valore suggerito per il peso $\beta$ è 0,25:$$DevRTT = (1 - 0,25) \times DevRTT + 0,25 \times |SampleRTT - EstimatedRTT|$$

**Impostazione del Timeout di Ritrasmissione:**
Combinando media e variabilità, si ottiene finalmente l'intervallo di timeout ideale, sufficientemente ampio da coprire fluttuazioni della rete ma abbastanza stretto da non causare gravi ritardi: $$TimeoutInterval = EstimatedRTT + 4 \times DevRTT$$
###### Il Servizio di Trasferimento Dati Affidabile
Il livello di rete sottostante, basato sul protocollo IP, fornisce un servizio _inaffidabile_ e _best-effort_: non garantisce la consegna, non garantisce l'ordine dei datagrammi e non garantisce l'integrità dei dati. Il compito del TCP è creare un solido servizio di trasporto dati affidabile proprio al di sopra di questo caos.

Il comportamento essenziale del mittente TCP è guidato da tre eventi principali:
1. **Ricezione di dati provenienti dall'applicazione:** Il TCP incapsula i dati, assegna il corretto numero di sequenza (corrispondente al primo byte) e passa il segmento a IP. Contestualmente, se non è già in funzione per un altro segmento, **avvia il timer**. Questo timer è sempre associato al pacchetto più vecchio in attesa di conferma. L'intervallo di scadenza è pari al _TimeoutInterval_ precedentemente calcolato.
2. **Scadenza del Timeout:** Se il timer scade prima di aver ricevuto una conferma, TCP reagisce ritrasmettendo esclusivamente il segmento che ha causato il timeout, per poi **riavviare il timer**.
3. **Arrivo di un Acknowledgment (ACK):** Quando arriva un ACK con valore _y_, il mittente lo confronta con la propria variabile di stato fondamentale, chiamata **SendBase**.
    - _SendBase:_ rappresenta il numero di sequenza del byte più vecchio che non ha ancora ricevuto un acknowledgment (ne consegue che _SendBase - 1_ è l'ultimo byte arrivato sano e salvo e in ordine).
    - Poiché gli acknowledgment sono cumulativi, il valore _y_ conferma implicitamente che tutti i byte precedenti sono stati ricevuti. Se **$y > SendBase$**, significa che l'ACK si riferisce a uno o più segmenti che erano in attesa. Di conseguenza, il mittente aggiorna la variabile _SendBase_.
    - Se, dopo l'aggiornamento, ci sono ancora altri segmenti in volo che necessitano di acknowledgment, il mittente riavvia nuovamente il timer per coprirli.

###### Trasferimento Dati Affidabile in TCP: Scenari, Ritrasmissioni e Gestione della Connessione
Abbiamo precedentemente visto come il TCP fornisca un trasferimento dati affidabile avvalendosi di timer e acknowledgment. Nonostante la trattazione sia stata semplificata, i meccanismi alla base del protocollo presentano una notevole ingegnosità. Per comprendere a fondo come funziona TCP nella pratica prendiamo in considerazione tre semplici scenari che illustrano il comportamento del TCP di fronte a imprevisti nella rete.
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

La regola d'oro del TCP prevede che **se il mittente riceve tre ACK duplicati** per lo stesso dato, considera questo evento come l'indizio inequivocabile che il segmento successivo sia andato perduto. A quel punto, effettua una **ritrasmissione rapida (fast retransmit)**, rispedendo il segmento mancante immediatamente, senza aspettare che il suo timer scada.
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
Esiste una modifica proposta per il TCP chiamata _acknowledgment selettivo_, che consente al destinatario di confermare esplicitamente e singolarmente i segmenti non in ordine, senza limitarsi all'approccio cumulativo sull'ultimo segmento corretto. Se uniamo questa opzione alla ritrasmissione selettiva (che evita di ritrasmettere i pacchetti singolarmente confermati), il TCP diventa estremamente simile a un generico protocollo SR (_Selective Repeat_). Per questo motivo, il meccanismo di ripristino dagli errori di TCP è classificabile come un **ibrido tra i protocolli GBN e SR**.

###### Servizio di Controllo di Flusso
Oltre all'affidabilità, TCP offre un fondamentale **servizio di controllo di flusso**. Non va confuso con il _controllo di congestione_ (che serve a non sovraccaricare la rete IP); il controllo di flusso serve per non sovraccaricare l'host di destinazione. Gli host agli estremi della connessione riservano dei **buffer di ricezione**. Quando il TCP riceve byte corretti e in sequenza, li posiziona in questo buffer. Il processo applicativo legge i dati dal buffer, ma i tempi possono variare: se l'applicazione è impegnata in un altro compito, potrebbe leggere i dati molto tempo dopo il loro arrivo. Se il mittente inviasse dati troppo rapidamente, il buffer di ricezione andrebbe in _overflow_. Il controllo di flusso è quindi un servizio di **confronto sulla velocità**, che bilancia la frequenza di invio del mittente con la frequenza di lettura dell'applicazione ricevente. Per affrontare questo problema quello che fa TCP è far mantenere al mittente una variabile chiamata **finestra di ricezione (rwnd, receive window)**, che gli fornisce costantemente l'indicazione dello spazio libero rimasto nel buffer del destinatario. Essendo una comunicazione full-duplex, i due mittenti mantengono finestre di ricezione distinte.

Se l'Host A sta inviando un file all'Host B, B alloca un buffer di ricezione di dimensione $RcvBuffer$. Si definiscono due variabili su B:
- _LastByteRead:_ il numero dell'ultimo byte del flusso letto dal processo applicativo.
- _LastByteRcvd:_ il numero dell'ultimo byte arrivato dalla rete e copiato nel buffer.
Per non mandare in overflow il buffer, deve valere la relazione: $LastByteRcvd - LastByteRead \le RcvBuffer$
La finestra di ricezione $rwnd$ (che è dinamica) indica lo spazio residuo calcolato come: $$rwnd = RcvBuffer - [LastByteRcvd - LastByteRead]$$**La comunicazione della finestra:**
L'Host B inizializza $rwnd$ con il valore intero di $RcvBuffer$ e inserisce il valore aggiornato di $rwnd$ nell'apposito campo (Finestra di ricezione) dei segmenti che manda ad A, tenendo traccia di variabili specifiche per ogni connessione attiva.
Sull'altro fronte, l'Host A tiene traccia di altre due variabili:
- _LastByteSent:_ l'ultimo byte mandato.
- _LastByteAcked:_ l'ultimo byte per cui ha ricevuto conferma.
La differenza tra queste due variabili ($LastByteSent - LastByteAcked$) esprime la quantità esatta di dati "in volo" inviati da A per i quali non c'è ancora riscontro. Mantenendo rigorosamente questa quantità sotto il valore di $rwnd$ fornito da B, l'Host A si assicura matematicamente di non causare mai un overflow nel buffer di ricezione di B.

> [!TIP] Cosa succede in caso di buffer pieno?
> Cosa succede se il buffer di B si riempie completamente ($rwnd = 0$) e B non ha più dati da inviare ad A?  
> Quando il processo applicativo di B finalmente svuota il buffer, TCP _non genera_ un segmento spontaneo per inviare un nuovo valore di $rwnd$. Questo accade perché TCP fa inviare segmenti all'Host A solo in caso di ack urgenti o nuovi dati, di conseguenza, l'Host A rimarrebbe totalmente bloccato, non sapendo che in B si è liberato spazio. 
> 
> Per prevenire questo stallo, le specifiche impongono che **l'Host A continui a inviare segmenti "sonda" contenenti 1 solo byte di dati** anche quando la finestra di ricezione vale zero. L'Host B sarà costretto a inviare un acknowledgment in risposta a questo byte, e prima o poi quell'ACK conterrà un valore di $rwnd$ diverso da zero, permettendo la ripresa regolare della trasmissione.
> 

###### Algoritmo di Nagle
Tecnica utilizzata nei protocolli di trasporto, in particolar modo nel protocollo TCP, sviluppata per ridurre l'_overhead_ generato dall'invio di piccoli pacchetti. Alla base di questa necessità c'è l'**RTT** (_Round Trip Time_), ovvero il tempo di latenza che viene atteso a ogni trasmissione di dati sulla rete. L'algoritmo risulta essere particolarmente utile per quelle applicazioni che generano molteplici trasmissioni di dati di dimensioni ridotte. Un esempio emblematico è _Telnet_, un'applicazione che invia costantemente pacchetti di dimensioni minime (tipicamente di **1 byte**). L'obiettivo principale del meccanismo è **aggregare dati di piccole dimensioni** all'interno del _buffer_ di trasmissione. Questi frammenti vengono poi inseriti in pacchetti più grandi prima dell'invio effettivo, ottimizzando le prestazioni specialmente quando l'RTT della rete è alto.

**Le fasi dell'algoritmo**
Il processo decisionale su quando trasmettere o quando accodare i dati si articola nei seguenti step sequenziali:
- **Fase 1:** Verificare se ci sono dati da trasmettere. Se sì, si procede allo Step 2; altrimenti, si salta allo Step 3.
- **Fase 2:** Verificare le condizioni dimensionali, controllando se la finestra di ricezione (**rwnd**) è $\ge$ **MSS** (_Maximum Segment Size_) e, contemporaneamente, se i dati disponibili sono $\ge$ **MSS**. Se entrambe le verifiche sono positive, si salta all'invio diretto (Step 5); altrimenti si passa allo Step 3.
- **Fase 3:** Verificare se si sta aspettando la ricezione di un **ACK** (_Acknowledgment_). In caso affermativo, si passa alla fase di accodamento (Step 4); in caso negativo, si procede all'invio (Step 5).
- **Fase 4:** Accodare i dati da mandare nel _buffer_ e attendere fino all'effettiva ricezione dell'ACK. Una volta ricevuto, procedere allo Step 5.
- **Fase 5:** Mandare i dati e terminare l'esecuzione (_end_).
**Pseudocodice**: La logica procedurale appena descritta può essere sintetizzata fedelmente in questo blocco di pseudocodice:

```
if available_data > 0:
    if window_size >= MSS AND available_data >= MSS:
        send_a_MSS_segment
    else:
        if waiting_for_an_ack == true:
            enqueue_data_in_buffer    /* until an acknowledge is received */
        else:
            send_data
```

- In specifici programmi che richiedono rigorosamente **bassa latenza** e **alta reattività**, l'attesa forzata introdotta dall'algoritmo per aggregare i dati può risultare un effetto indesiderato.    
- Per far fronte a questa esigenza, alcuni sistemi operativi offrono la possibilità di **disabilitare** totalmente l'algoritmo di Nagle. Questa operazione viene effettuata impostando la specifica opzione **TCP_NODELAY** direttamente all'interno delle _socket API_.

###### Apertura della connessione attraverso il Three-way handshake
Supponiamo che un processo client voglia inizializzare una comunicazione con un processo server.
- **Passo 1 (SYN):** Il TCP lato client invia uno speciale segmento al TCP server. Questo segmento è privo di dati a livello applicativo, ma ha il **bit SYN impostato a 1** nell'intestazione (viene pertanto detto _segmento SYN_). Il client sceglie casualmente un proprio numero di sequenza iniziale (_client_isn_) e lo pone nel campo corrispondente. Il segmento è inviato all'interno di un datagramma IP.
- **Passo 2 (SYNACK):** Se il pacchetto arriva, il server estrae il segmento, alloca all'istante i buffer e le variabili TCP per la connessione, e invia in risposta un segmento di approvazione (detto _segmento SYNACK_). Anche questo non contiene dati, ma possiede tre informazioni vitali:
    1. Il bit SYN è ancora posto a 1.
    2. Il campo ACK assume il valore di $client\_isn + 1$ (significa: "Ho ricevuto il tuo pacchetto e accetto la connessione, mi aspetto il prossimo byte").
    3. Il server sceglie un proprio numero di sequenza iniziale (_server_isn_) e lo inserisce nell'intestazione.
- **Passo 3 (ACK e Dati):** Alla ricezione del SYNACK, anche il client alloca i propri buffer e variabili alla connessione. Risponde al server ponendo il valore $server\_isn + 1$ nel campo ACK. In questo momento la connessione è formalmente stabilita, quindi il **bit SYN viene posto a zero**. Una particolarità fondamentale di questo terzo passo è che il campo dati di questo segmento **può già contenere informazioni utili** inviate dall'applicazione client al server.
![[Pasted image 20260511212701.png|700]]

###### Chiusura della Connessione TCP
Ciascuno dei due processi può decidere di terminare la connessione (nella nostra ipotesi, il client). Le "risorse" (buffer e variabili) di entrambi gli host dovranno essere deallocate.
1. Il processo applicativo client invia un comando di chiusura, costringendo il proprio TCP a generare un segmento speciale con il **bit FIN impostato a 1**.
2. Il server riceve questo segmento FIN e risponde inviando un normale acknowledgment di conferma al client.
3. Immediatamente dopo, il server spedisce a sua volta il proprio segmento di shutdown, anch'esso con il **bit FIN uguale a 1**.
4. Il client risponde inviando l'acknowledgment definitivo al segmento FIN del server. A questo punto tutte le risorse sono deallocate.
![[Pasted image 20260511212636.png|700]]

###### Gli Stati della Connessione TCP
Nel suo ciclo di vita, i protocolli TCP attraversano diversi stati formali:
- **Stati visitati dal Client:** Si parte da `CLOSED`. L'inizializzazione spinge il client in `SYN_SENT`. Ricevuto il SYNACK, si entra in `ESTABLISHED` (in cui fluiscono i dati utili). Quando il client chiede la chiusura inviando il FIN, passa in `FIN_WAIT_1`. Ricevuto l'ACK dal server, entra in `FIN_WAIT_2` (in attesa del FIN del server). Ricevuto il FIN, invia il suo ultimo ACK ed entra in un particolare stato detto **`TIME_WAIT`**.
- **A cosa serve il TIME_WAIT?** Permette al TCP client di inviare nuovamente l'ultimo acknowledgment nel caso disgraziato in cui questo andasse perduto e il server rimandasse il suo FIN. Il tempo di permanenza in `TIME_WAIT` è definito dall'implementazione (tipicamente 30 secondi, 1 minuto o 2 minuti). Scaduto questo tempo, la connessione è totalmente chiusa e la porta viene rilasciata, tornando allo stato `CLOSED`.
![[Pasted image 20260511212619.png|700]]

**Cosa accade se le porte sono errate o chiuse?**
Se la fase di handshake fallisce perché il server riceve un segmento TCP destinato a una porta su cui non è in ascolto (es. riceve un SYN sulla porta 80 ma non ha processi web attivi), il server risponde immediatamente con un segmento speciale di reset, caratterizzato dal **bit RST impostato a 1**. Questo comunica alla sorgente: "Non ho una socket attiva per quel segmento, non tentare di rimandarlo".

###### Generalità sul controllo di congestione
Il controllo di congestione è un aspetto critico in un contesto di rete generale. La congestione è un fenomeno negativo che si manifesta con scarse prestazioni per le applicazioni dei livelli superiori e con un basso utilizzo delle risorse. Per comprenderne cause e conseguenze, esaminiamo tre scenari via via più complessi.

###### Scenario 1: Due mittenti e un router con buffer illimitati
Consideriamo lo scenario di congestione più semplice possibile: due host (A e B) con una connessione che condivide un singolo router intermedio. ![[Pasted image 20260514200424.png|700]]
- **Il protocollo di trasporto:** Ipotizziamo un protocollo sottostante molto semplice. I dati vengono incapsulati e inviati nella _socket_ una sola volta, senza porre rimedio a eventuali errori. Ignoriamo per semplicità l'overhead aggiuntivo delle intestazioni.
- **Tasso di invio ($\lambda_{in}$):** L'applicazione nell'Host A passa i dati al protocollo a una frequenza media di **$\lambda_{in}$ byte/s**. L'Host B opera in modo identico, trasmettendo anch'esso a $\lambda_{in}$ byte/s.
- I pacchetti convergono in un collegamento uscente condiviso che ha una capacità trasmissiva totale pari a **$R$**.

Analizzando le prestazioni, si evincono due conseguenze:
- **Limite sul throughput:** Finché il tasso di invio $\lambda_{in}$ non supera **$R/2$**, il _throughput_ per connessione (numero di byte per secondo al ricevente) equivale al tasso di invio del mittente. Se $\lambda_{in}$ supera $R/2$, il _throughput_ si blocca a $R/2$. Questo limite superiore è la conseguenza diretta della condivisione della capacità $R$ tra le due connessioni: il collegamento non può fisicamente consegnare a un tasso superiore.
- **Crescita del ritardo:** Quando il tasso di invio si avvicina a $R/2$, il ritardo medio cresce progressivamente. Quando supera $R/2$, i pacchetti si accumulano nel _buffer_ (ipotizzato illimitato) e il **ritardo medio tra origine e destinazione tende all'infinito**.
- **Conclusione:** Avere un _throughput_ aggregato vicino alla capacità $R$ sembra ideale, ma dal punto di vista del ritardo è disastroso.
![[Pasted image 20260514200456.png|600]]

###### Scenario 2: Due mittenti e un router con buffer limitati
In questo scenario il router possiede _buffer_ di dimensione limitata: i pacchetti che giungono in un _buffer_ già pieno vengono scartati. Supponiamo inoltre che le connessioni siano affidabili: se un pacchetto viene scartato, il mittente prima o poi lo ritrasmetterà.  ![[Pasted image 20260514200520.png|600]]

Per via delle ritrasmissioni, dobbiamo distinguere due grandezze:
- **$\lambda_{in}$ (Tasso di trasmissione):** La frequenza in byte/s dei soli dati originali.
- **$\lambda'_{in}$ (Carico offerto):** Il tasso al quale il livello di trasporto invia l'insieme totale dei segmenti (dati originali + dati ritrasmessi).

Le prestazioni cambiano drasticamente in base a come e quando si effettua la ritrasmissione:
- **Caso Ideale (Conoscenza perfetta):** Se l'Host A potesse determinare (come per magia) se il _buffer_ del router è libero, trasmettendo solo in quel momento, non ci sarebbero smarrimenti. Avremmo **$\lambda'_{in} = \lambda_{in}$** e il _throughput_ della connessione sarebbe $\lambda_{in}$, con prestazioni ideali _(Riferimento Figura 3.46a)_.
- **Caso Realistico (Timeout lungo):** Il mittente imposta un _timeout_ sufficientemente grande da ritrasmettere solo quando è certo che il pacchetto sia perduto.
    - _Esempio numerico:_ Se il carico offerto $\lambda'_{in}$ vale **$R/2$** (pari a $0,5 R$ unità di dati), il _throughput_ reale scende a **$R/3$**. Di questi $0,5 R$ trasmessi, in media **$0,333 R$ byte/s** sono dati originali e **$0,166 R$ byte/s** sono ritrasmissioni _(Riferimento Figura 3.46b)_.
    - _Costo della congestione:_ Il mittente deve sprecare capacità per effettuare ritrasmissioni necessarie a compensare i pacchetti caduti per l'_overflow_ dei _buffer_.
- **Caso Pessimistico (Timeout prematuro):** Il mittente ritrasmette un pacchetto che ha subito solo un ritardo in coda, ma non è perduto. Al destinatario arrivano copie multiple (e ne basta una). Il router spreca lavoro per instradare copie inutili.
    - _Conseguenza:_ Se ogni pacchetto è instradato mediamente due volte, il _throughput_ assumerà asintoticamente il valore **$R/4$** quando il carico offerto tende a $R/2$ _(Riferimento Figura 3.46c)_.
![[Pasted image 20260514200550.png|600]]
###### Scenario 3: Quattro mittenti, router con buffer finiti e percorsi composti da più collegamenti
Ipotizziamo quattro host che trasmettono dati avvalendosi di meccanismi di _timeout_ e ritrasmissione (tutti con lo stesso valore di $\lambda_{in}$). I percorsi sono composti da due collegamenti sovrapposti (multi-hop). La capacità di tutti i collegamenti è $R$. 
![[Pasted image 20260514200611.png|700]]

Consideriamo la connessione dall'Host A all'Host C che passa per i router R1 e R2. Questa connessione condivide R1 con la connessione D-B e R2 con la connessione B-D.
- **Traffico scarso (Piccoli valori di $\lambda_{in}$):** Gli _overflow_ sono rari. Un incremento di $\lambda_{in}$ provoca un incremento proporzionale del _throughput_ ($\lambda_{out}$).
- **Traffico intenso (Grandi valori di $\lambda_{in}$ e $\lambda'_{in}$):** Analizziamo il router R2. Il traffico A-C arriva a R2 (già instradato da R1) al massimo con tasso $R$. Tuttavia, se il traffico concorrente B-D è enorme, il tasso di arrivo di B-D su R2 sarà molto più elevato. I pacchetti A-C e B-D competono per lo spazio limitato del _buffer_ in R2.
- **Collasso del throughput:** Al tendere del traffico B-D all'infinito, ogni spazio vuoto in R2 viene colmato dai pacchetti B-D. Il traffico A-C viene scartato per _overflow_ in R2 e il suo _throughput end-to-end_ **tende a 0**.
- **Costo estremo della congestione (Lavoro sprecato):** Ogni qualvolta un pacchetto viene scartato al secondo _hop_ (es. R2), tutto il lavoro effettuato dal router del primo _hop_ (R1) per instradarlo viene irrimediabilmente perso.
![[Pasted image 20260514201455.png|600]]
###### Approcci al controllo di congestione
Nella pratica esistono due orientamenti principali per gestire la congestione, che si differenziano in base all'architettura di rete e ai protocolli:
- **Controllo di congestione end-to-end:** Il livello di rete non fornisce alcun supporto esplicito al livello di trasporto. La presenza di congestione deve essere dedotta esclusivamente dai sistemi periferici (mittente e destinatario) osservando il comportamento della rete. **TCP** adotta obbligatoriamente questo approccio, poiché il protocollo IP standard non offre _feedback_ sullo stato della rete.
- **Controllo di congestione assistito dalla rete:** I componenti a livello di rete (i router) forniscono un _feedback_ esplicito al mittente. Questo avviene solitamente in due modi:
    1. **Chokepacket (Pacchetto di strozzatura):** Un avviso diretto inviato dal router congestionato al mittente (messaggio: "Sono congestionato!").
    2. **Impostazione di un campo/bit:** Il router imposta un bit o un campo in un pacchetto dati che sta fluendo dal mittente al destinatario per segnalare il traffico. Questo approccio consente al router di informare il mittente sulla frequenza trasmissiva esatta che può sopportare sul collegamento.        

###### Controllo di congestione in TCP (Classico)
TCP "classico" (la versione standardizzata) utilizza il controllo _end-to-end_. L'approccio consiste nell'imporre a ciascun mittente TCP un limite al tasso di invio in funzione della congestione percepita: si incrementa la trasmissione se c'è scarso traffico e la si riduce se c'è congestione. Per farlo TCP utilizza una variabile aggiuntiva mantenuta agli estremi della connessione: la **finestra di congestione (cwnd)**. Ovviamente la quantità di dati inviata da un mittente che non ha ancora ricevuto _acknowledgment_ non può superare la dimensione di questa finestra (ci sarebbe da mettere in mezzo il vincolo di rwnd, ma in questa fase non lo facciamo). Visto che TCP utilizza il controllo *end-to-end* per poter capire se la rete e congestionata fa attenzione ai seguenti eventi che possono accadere nella rete:
1. **Un segmento perso:** Se la rete perde un segmento implica che c'è congestione quindi il tasso di trasmissione viene decrementato.
2. **Un ACK**: arrivo di un ack indica che la rete non è congestionata quindi il tasso di trasmissione viene incrementato.

TCP aumenta progressivamente il tasso di invio per "tastare" la rete finché non si verifica una perdita (punto di inizio della congestione); a quel punto rallenta, per poi ricominciare la fase di rilevamento e testare se le condizioni sono cambiate. Questo meccanismo viene attuato combinando tra di loro questi algoritmi: 
- **(1) Slow Start** (Partenza Lenta - obbligatoria)
- **(2) Congestion Avoidance** (Prevenzione della Congestione - obbligatoria)
- **(3) Fast Recovery** (Recupero Rapido)
Le prime due differiscono tra loro per il modo (la curva matematica) con cui aumentano la grandezza della _cwnd_ in risposta agli ACK ricevuti.
###### La fase di Slow Start (Partenza Lenta)
All'apertura di una connessione, la rete potrebbe avere un'ampia banda disponibile, quindi il mittente ha l'obiettivo di scoprirla rapidamente.
- **Inizializzazione:** Il valore di _cwnd_ viene inizializzato a **1 MSS** (_Maximum Segment Size_).
    - _Esempio numerico:_ Se _MSS_ = 500 byte e _RTT_ (_Round Trip Time_) = 200 ms, la velocità iniziale (_MSS/RTT_) è di soli 20 kbps circa.
- **Crescita Esponenziale:** Per ogni segmento che riceve un _acknowledgment_ (ACK), _cwnd_ viene incrementata di 1 _MSS_. Di conseguenza, la velocità di trasmissione raddoppia a ogni _RTT_ (es. da 1 _MSS_ passa a 2, poi a 4, e così via).
- **Termine della fase:** La _slow start_ si interrompe in tre scenari:
    1. Si ha un **evento di timeout** TCP riporta _cwnd_ a 1 _MSS_ e ricomincia la _slow start_. Viene inoltre aggiornata la variabile di stato **ssthresh (Slow Start Threshold)**, impostandola a metà del valore che _cwnd_ aveva al momento della perdita (ovvero _cwnd_/2).
    2. **Raggiungimento della soglia:** Quando _cwnd_ raggiunge o supera il valore di _ssthresh_ (considerato il limite di sicurezza basato sull'ultima congestione nota), raddoppiare diventa temerario. TCP termina la _slow start_ ed entra in _congestion avoidance_.
    3. **Tre ACK duplicati:** Il mittente effettua una **ritrasmissione rapida** ed entra direttamente nello stato di _fast recovery_.
###### La fase di Congestion Avoidance (Prevenzione della Congestione)
Quando TCP entra in questo stato, il valore di _cwnd_ è circa la metà di quello che ha causato l'ultima congestione. L'approccio diventa conservativo.
- **Crescita Lineare:** Invece di raddoppiare, TCP incrementa _cwnd_ di **1 MSS ogni RTT**.
- **Implementazione pratica:** Il mittente aumenta _cwnd_ di una frazione per ogni singolo ACK ricevuto, usando la formula: $$Incremento = MSS × (MSS/cwnd) byte$$
    - _Esempio:_ Se _MSS_ = 1460 byte e _cwnd_ = 14.600 byte (10 segmenti), ogni ACK incrementa la finestra di 1/10 di _MSS_. Ricevuti tutti e 10 gli ACK, la finestra sarà cresciuta esattamente di 1 _MSS_.
- **Termine della fase:** 
    1. si ha **evento di timeout:** Esattamente come in _slow start_, _cwnd_ torna a 1 _MSS_ e _ssthresh_ viene dimezzata (_cwnd_/2).
    2. **tre ACK duplicati:** L'evento è considerato meno drastico del _timeout_. TCP dimezza il valore di _cwnd_ (aggiungendovi 3 _MSS_ per compensare i 3 duplicati ricevuti), imposta _ssthresh_ alla metà del valore di _cwnd_ precedente, ed entra in _fast recovery_
![[Pasted image 20260514200339.png|700]]
###### La fase di Fast Recovery (Recupero Rapido) e le Varianti TCP
Il _fast recovery_ è un componente raccomandato ma non obbligatorio. Durante questa fase:
- _cwnd_ viene incrementato di 1 _MSS_ per ogni ACK duplicato ricevuto relativo al segmento perso (Se ricevo un ACK duplicato, vuol dire che il destinatario ha ricevuto un altro pacchetto che avevo inviato dopo quello perso, quindi posso aumentare la finestra).
- Quando arriva l'ACK per il segmento perso (quello ritrasmesso), TCP riduce _cwnd_ ed entra in _congestion avoidance_(Visto che l'emergenza è finita la finestra può iniziare a crescere linearmente e non troppo bruscamente).
- Se si verifica un _timeout_ durante il _fast recovery_, TCP crolla in _slow start_ (_cwnd_ = 1 _MSS_, _ssthresh_ = _cwnd_/2) (se si verifica il timeout vuol dire che la rete è completamente bloccata quindi TCP riparte da capo).

Esistono differenze storiche nella gestione degli errori:
- **TCP Tahoe (Versione originaria):** Non possiede il _fast recovery_. In caso di _qualsiasi_ perdita (sia _timeout_ che 3 ACK duplicati), porta incondizionatamente _cwnd_ a 1 _MSS_ ed entra in _slow start_.
- **TCP Reno (Versione moderna):** Adotta regolarmente il _fast recovery_.
- **Evoluzione a confronto:**. Immaginando un _ssthresh_ iniziale di 8 _MSS_, per i primi 8 cicli Tahoe e Reno sono identici (crescita esponenziale fino a 8, poi lineare). All'ottavo ciclo (con _cwnd_ = 12 _MSS_) si verifica un triplo ACK duplicato. La nuova soglia _ssthresh_ diventa 6 _MSS_ ($12/2$).
	- **Reno:** Imposta _cwnd_ a 6 _MSS_ e riprende a crescere linearmente.
	- **Tahoe:** Crolla con _cwnd_ a 1 _MSS_, cresce esponenzialmente fino a 6 _MSS_, poi riprende linearmente.
![[Pasted image 20260514200238.png|700]]
###### Retrospettiva: AIMD e Throughput Macroscopico
Ignorando le anomalie (_timeout_ e le _slow start_ iniziali), il controllo di TCP è guidato dalla ricezione dei 3 ACK duplicati e si basa su un principio matematico:
- **AIMD (Additive-Increase Multiplicative-Decrease):** TCP incrementa in modo additivo e lineare la finestra (+1 _MSS_ per _RTT_) e la decrementa in modo moltiplicativo (dimezzandola) in caso di perdita. Questo genera il caratteristico grafico a "**dente di sega**" (_saw tooth_). ![[Pasted image 20260514200300.png|600]]
- **Modello Macroscopico del Throughput:** Se $W$ è la dimensione della finestra quando si verifica la perdita, la velocità di trasmissione oscilla costantemente tra $\frac{W}{2 \cdot RTT}$ e $\frac{W}{RTT}$. Poiché la crescita tra i due estremi è lineare, si ottiene la formula: $$ \text{Throughput medio di una connessione} = \frac{0.75 \cdot W}{RTT} $$
###### Notifica Esplicita di Congestione (ECN)
Estensioni recenti di IP e TCP (RFC 3168) permettono un controllo assistito dalla rete:
- **ECN (Explicit Congestion Notification):** Utilizza due bit nel campo _Tipo di Servizio_ dell'intestazione IP. 
  ![[Pasted image 20260514200201.png|600]]
- **Funzionamento:** Se un router rileva una congestione persistente, imposta questi bit e inoltra il pacchetto. Il destinatario riceve il pacchetto e informa il mittente impostando il bit **ECE** (_Explicit Congestion Notification Echo_) all'interno di un segmento ACK.
- **Reazione:** Il mittente TCP reagisce dimezzando la _cwnd_ (come in una ritrasmissione rapida) e imposta il bit **CWR** (_Congestion Window Reduced_) nel successivo segmento inviato al ricevente per confermare la presa visione.

###### La Fairness in TCP
In una rete, un meccanismo di controllo della congestione soddisfa il criterio di **equità** (_fairness_) se $K$ connessioni omogenee, che condividono un unico collegamento critico di capacità $R$ in assenza di traffico esogeno, convergono nel lungo periodo verso un throughput medio equamente ripartito e pari a $R/K$. Il protocollo **TCP** persegue questo obiettivo allocando la banda dinamicamente tramite l'algoritmo **AIMD** durante la fase di _Congestion Avoidance_. L'evoluzione dinamica del sistema può essere modellata geometricamente su un piano cartesiano i cui assi rappresentano i throughput delle singole connessioni, definendo lo spazio di stato tramite due rette fondamentali: la **linea di pieno utilizzo dell'ampiezza di banda** (Linea dell'Efficienza, $A + B = R$), che possiede pendenza negativa poiché il vincolo fisico impone che l'incremento di banda di un flusso corrisponda a una contrazione simmetrica del secondo, e la **linea di equa condivisione dell'ampiezza di banda** (Linea dell'Equità, $A = B$), coincidente con la bisettrice del quadrante. L'obiettivo del controllo di congestione è la convergenza asintotica verso il punto di intersezione tra queste due rette. ![[Pasted image 20260519105038.png|700]]
Per analizzare la dinamica microscopica, facendo riferimento alla figura, si parte da uno **stato iniziale arbitrario**, (punto **A**), in cui la connessione 2 gode di un throughput superiore. Poiché la rete non è satura, entrambe le connessioni aumentano linearmente la propria finestra di congestione della stessa quantità fissa per ogni RTT (+1 MSS); sul piano cartesiano, questo _incremento additivo_ genera uno spostamento lineare con una **pendenza geometrica di esattamente 45 gradi** (traiettoria da **A** a **B**), sviluppandosi in modo strettamente parallelo alla linea di equa condivisione e mantenendo così inalterato il divario assoluto tra le connessioni.

Intersecando e superando la linea di pieno utilizzo (punto **B**), i buffer dei router si saturano causando perdita di pacchetti l'algoritmo AIMD impone il **dimezzamento immediato** della finestra di entrambi i flussi, operazione che geometricamente equivale a far arretrare il sistema lungo una linea retta orientata verso l'origine degli assi (traiettoria da **B** a **C**). Essendo il taglio proporzionale (percentuale), la connessione 2 subisce una **riduzione quantitativa assoluta molto più severa** rispetto alla connessione 1, forzando il punto **C** a posizionarsi matematicamente più vicino alla linea della bisettrice rispetto alla traiettoria precedente.

Riprendendo la fase di crescita (traiettoria da **C** a **D**) e subendo ciclicamente questi dimezzamenti, si produce un caratteristico andamento geometrico a **dente di sega** che restringe progressivamente le oscillazioni attorno all'intersezione ottimale, garantendo l'equa ripartizione.

Tuttavia, è fondamentale precisare che questa equità perfetta si realizza _solo_ sotto la condizione di totale omogeneità dei flussi; nella realtà delle reti Internet, l'ipotesi di identità dei **tempi di andata e ritorno** (RTT) non si verifica quasi mai. Le connessioni caratterizzate da un **RTT inferiore**, infatti, riescono ad eseguire la fase di incremento additivo molto più rapidamente, deviando la traiettoria di crescita a proprio favore e introducendo un'**asimmetria intrinseca** che penalizza fortemente le connessioni a lungo raggio, comprimendone il throughput a vantaggio dei flussi locali.

> [!TIP] Formale
> **Definizione:** In una rete a commutazione di pacchetto, un meccanismo di controllo della congestione garantisce l'**equità** (_fairness_) se $K$ connessioni omogenee, che condividono un unico collo di bottiglia con capacità $R$ in assenza di traffico esogeno, convergono nel lungo periodo verso un throughput medio equamente ripartito e pari a $R/K$.
> 
> **Dimostrazione:** L'equità del protocollo **TCP** viene dimostrata geometricamente analizzando le dinamiche dell'algoritmo **AIMD** su un piano cartesiano. Tracciando la **linea dell'efficienza** ($A + B = R$) e la **linea dell'equità** ($A = B$), si osserva che l'_incremento additivo_ fa crescere i throughput in modo strettamente parallelo alla linea dell'equità (con pendenza a 45 gradi), mantenendo inalterato il divario assoluto tra i flussi. Al momento della congestione, il _decremento moltiplicativo_ dimezza le coordinate del punto, facendolo arretrare lungo una retta passante per l'origine; poiché il taglio è percentuale, il flusso che occupava più banda subisce una riduzione quantitativa assoluta molto più severa. La ripetizione ciclica di queste asimmetrie crea un andamento a **dente di sega** che dimostra visivamente e matematicamente come il sistema sia intrinsecamente costretto a convergere verso il punto di intersezione delle due rette, raggiungendo la perfetta ripartizione della risorsa.
