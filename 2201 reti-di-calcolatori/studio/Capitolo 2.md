### Le applicazioni di rete

Le applicazioni di rete rappresentano la ragione di esistenza delle reti di calcolatori: senza la necessità di concepire applicazioni utili per gli utenti, non vi sarebbe alcun motivo di progettare protocolli di rete per supportarle.

Il cuore dello sviluppo in questo ambito è la creazione di programmi che vengono eseguiti sui sistemi periferici (host) e che comunicano tra loro via rete. Un classico esempio è quello delle applicazioni web, dove comunicano due programmi distinti:
- Il **browser** (eseguito sull'host dell'utente, come desktop, laptop o smartphone).
- Il **web server** (eseguito su un host dedicato, chiamato anch'esso web server).

Per lo sviluppatore di applicazioni, l'architettura di rete sottostante è fissa e fornisce uno specifico insieme di servizi. Il compito dello sviluppatore è progettare l'architettura dell'applicazione e stabilirne l'organizzazione sui vari sistemi periferici.

###### Le Architetture delle Applicazioni
Attualmente, le applicazioni di rete si basano principalmente su due architetture:
- **L'Architettura Client-Server**: In questa architettura, i ruoli sono nettamente separati:
	- **Server:** È un host sempre attivo che ha il compito di rispondere alle richieste di servizio inviate da molti altri host. Dispone di un indirizzo fisso e noto.
	- **Client:** È l'host dell'utente che contatta il server inviandogli un pacchetto per richiedere un oggetto o un servizio.
	in questo tipo di architettura i client non comunicano mai direttamente tra di loro (es. due browser non interagiscono tra loro in un'applicazione web). Inoltre il client può contattare il server in qualsiasi momento. Per evitare che un singolo host server soccomba sotto il peso di troppe richieste, si utilizzano spesso i **data center**: strutture che ospitano moltissimi host (fino a centinaia di migliaia, gestendone alimentazione e manutenzione) per creare un potente server virtuale.
- **L'Architettura P2P (Peer-to-Peer)**: In un'architettura P2P, l'infrastruttura basata su server centralizzati o data center è minima o del tutto assente.
	- **Peer:** Sono computer fissi e portatili controllati direttamente dagli utenti (situati in abitazioni, uffici o università) che comunicano direttamente tra loro formando delle coppie. I peer non appartengono a un fornitore di servizi.
  i punti di forza principali di questa architettura sono: 
	- **Scalabilità intrinseca:** Ogni peer genera carico di lavoro richiedendo file, ma allo stesso tempo aggiunge capacità di servizio al sistema rispondendo alle richieste degli altri peer.
	- **Convenienza economica:** Sfrutta risorse già esistenti e distribuite, senza richiedere costosi data center.

###### Processi e Interfacce di Comunicazione
Per costruire un'applicazione di rete è necessario capire come comunicano i programmi su host diversi. Nel gergo dei sistemi operativi, non si parla di semplici programmi, ma di **processi comunicanti**. Possiamo definire un **processo** come un programma in esecuzione su un sistema.
- Se i processi sono in esecuzione sullo **stesso sistema**, comunicano tramite un approccio chiamato _comunicazione interprocesso_.
- Se i processi sono su **host diversi**, comunicano scambiandosi messaggi attraverso la rete. Il processo mittente crea i messaggi e li invia; il processo destinatario li riceve e, se previsto, invia una risposta.

Le applicazioni di rete sono costituite da una coppia di processi che si scambiano messaggi. In una sessione di comunicazione, individuiamo due tipi di processo:
- **Processo Client:** Il processo che avvia la comunicazione (ovvero che contatta l'altro processo all'inizio della sessione).
- **Processo Server:** Il processo che attende di essere contattato per iniziare la sessione.

_Nota:_ Nelle applicazioni P2P, un processo può comportarsi sia da client che da server, poiché può inviare e ricevere file contemporaneamente. Tuttavia, all'interno di una singola sessione specifica, i ruoli di chi inizia e chi attende rimangono distinti.
###### Le Socket: L'interfaccia verso la rete
Un **Socket** è un'interfaccia software attraverso la quale un processo invia messaggi nella rete e riceve messaggi dalla rete. 

Per usare un'analogia: se il processo è una "casa", la socket è la sua "porta". Il processo mittente fa uscire il messaggio dalla propria socket, presupponendo l'esistenza di un'infrastruttura esterna di trasporto. Quando il messaggio arriva all'host di destinazione, attraversa la socket del processo ricevente, che infine opera sul dato.

La socket rappresenta anche le **API** (_Application Programming Interface_) tra l'applicazione e la rete. Il progettista dell'applicazione ha controllo totale sul livello applicativo della socket, ma un controllo minimo sul livello di trasporto sottostante. L'applicazione lato mittente "spinge" fuori i messaggi tramite la socket, e lato ricevente, il protocollo di trasporto ha la responsabilità di consegnarli alla socket di destinazione.
![[Pasted image 20260510103425.png|500]]
###### L'Indirizzamento dei processi
Affinché un messaggio venga consegnato correttamente come avviene nella posta tradizionale, il destinatario deve avere un indirizzo. Per identificare un processo ricevente sono necessarie due informazioni:
1. **Indirizzo IP:** Un numero di 32 bit che identifica univocamente l'host (il dispositivo hardware) all'interno di Internet. 
2. **Numero di porta di destinazione:** Un numero che identifica lo specifico processo (e la relativa socket) all'interno dell'host di destinazione. Questa distinzione è necessaria perché su un singolo host possono essere in esecuzione più applicazioni di rete contemporaneamente.
    - _Esempio:_ I web server usano la porta **80**. I server di posta che usano SMTP usano la porta **25**.

###### I servizi a livello di Trasporto
I protocolli a livello di trasporto forniscono il supporto alle applicazioni attraverso quattro categorie di servizi:
1. **Trasferimento Dati Affidabile**: In rete i pacchetti possono andare perduti (scartati da router/host o corrotti nei bit).
	- **Trasferimento dati affidabile:** Servizio che garantisce che i dati inviati siano consegnati al destinatario in modo corretto e completo. È un requisito fondamentale per applicazioni dove la perdita di dati causa danni gravi (es. posta elettronica, trasferimento file, finanza, web).
	- **Applicazioni che tollerano le perdite:** Se il protocollo non fornisce affidabilità totale, i dati possono non arrivare. Questo è accettabile per applicazioni multimediali audio/video, dove si tollera una certa perdita di dati senza compromettere troppo l'esperienza utente.
2. **Throughput**: il _throughput disponibile_ in una sessione di rete è la velocità alla quale il mittente può inviare i bit al ricevente. Dato che la rete è condivisa e le connessioni variano, il throughput oscilla nel tempo. Le applicazioni si dividono in:
	- **Applicazioni sensibili alla banda** (_Bandwidth-sensible applications_): Hanno requisiti specifici di throughput (es. flussi multimediali). Spesso usano tecniche di codifica adattativa per allineare la qualità al throughput del momento.
	- **Applicazioni elastiche** (_Elastic applications_): Sfruttano tutto il throughput disponibile, che sia tanto o poco (es. posta elettronica, web, trasferimento file).
3. **Temporizzazione (Timing)**: Garanzie sui limiti massimi di ritardo di consegna.
	- _Esempio:_ Il protocollo garantisce che un bit arrivi alla socket di destinazione entro massimo 100 millisecondi.
	- Questo servizio è cruciale per **applicazioni interattive in tempo reale** (telefonia Internet, teleconferenze, ambienti virtuali). Per le applicazioni non in tempo reale non si pongono vincoli così stretti sui ritardi _end-to-end_, ma un ritardo basso resta preferibile.
4. **Sicurezza**: Un protocollo può cifrare i dati trasmessi dal processo mittente e decifrarli al momento della consegna al processo ricevente. Questo garantisce la **riservatezza** tra le parti.

###### I Protocolli di trasporto in Internet: TCP vs UDP
Quando si progetta un'applicazione per Internet, lo sviluppatore deve scegliere tra due protocolli di trasporto che offrono modelli di servizio differenti: **TCP** e **UDP**.
- **I servizi del TCP**: Se un'applicazione usa il TCP, riceve due servizi principali, oltre a un meccanismo accessorio:
	1. **Servizio orientato alla connessione** (_Connection-oriented service_): Prima di inviare dati utili, client e server si scambiano informazioni di controllo (_handshaking_) per prepararsi al trasferimento. Viene istituita una connessione **full-duplex** (i processi si scambiano dati contemporaneamente in entrambe le direzioni) che andrà chiusa a fine comunicazione.
	2. **Servizio di trasferimento affidabile:** Garantisce il trasporto del flusso di dati (byte) senza errori, nel giusto ordine, senza perdite o duplicazioni.
	3. **Controllo della congestione:** Un servizio non diretto ai singoli processi, ma al benessere generale di Internet. "Strozza" la velocità di invio di client o server se la rete risulta eccessivamente congestionata dal traffico.
- **I servizi dell'UDP**: L'UDP è un protocollo leggero, senza fronzoli e dal modello minimalista.
	1. **Senza connessione:** Nessuna fase di _handshaking_ preliminare.
	2. **Trasferimento dati non affidabile:** Non garantisce che il messaggio arrivi a destinazione e i pacchetti possono giungere in disordine.
	3. **Nessun controllo della congestione:** Il mittente può pompare i dati sul livello di rete sottostante a qualsiasi velocità.

###### Limiti dei protocolli internet attuali
A differenza dei 4 parametri teorici visti nel paragrafo precedente, l'odierna infrastruttura Internet (TCP e UDP) **non fornisce garanzie esplicite su throughput e temporizzazione**. Tuttavia, applicazioni critiche per i ritardi (come la telefonia Internet) funzionano ugualmente da anni perché sono state progettate per operare e adattarsi nel miglior modo possibile all'assenza di tali garanzie assolute.
###### I protocolli a livello di applicazione
È fondamentale distinguere tra un'applicazione di rete nella sua interezza e il suo protocollo a livello di applicazione (che ne costituisce solo una parte, come accade ad esempio per un programma chiuso come Skype, in cui l'app contiene protocolli non pubblici).
- **Protocollo a livello di applicazione:** Definisce le regole con cui i processi di un'applicazione (su sistemi diversi) si scambiano i messaggi.

Nello specifico, questo protocollo definisce:
- I tipi di messaggi scambiati.
- La sintassi dei vari messaggi.
- La semantica dei campi (il significato delle informazioni contenute).
- Le regole per determinare quando e come inviare/rispondere a un messaggio.

###### Principali Applicazioni di Rete
Tra le innumerevoli applicazioni presenti, lo studio si concentra sulle più diffuse (Posta elettronica, Servizi di directory, Streaming video, P2P) il Web però è stata la prima applicazione a catturare l'attenzione del grande pubblico. La sua forza risiede nell'operare **su richiesta** (_on demand_).

### HTTP

###### Introduzione al Web
Il Web è stata la prima applicazione Internet a catturare l'attenzione del grande pubblico. La caratteristica principale che attira maggiormente gli utenti è la sua natura _on demand_: permette di ottenere ciò che si desidera, nel momento esatto in cui lo si desidera. Oltre a operare su richiesta, il Web presenta caratteristiche fondamentali:
- **Facilità di pubblicazione:** Chiunque può diventare editore rendendo disponibili informazioni a costi estremamente bassi.
- **Navigazione ipertestuale:** L'uso di collegamenti ipertestuali e motori di ricerca permette di orientarsi facilmente tra i siti.

###### Il Protocollo HTTP: Client, Server e Oggetti
> [!Quote] Che significa URL
> Un URL (Uniform Resource Locator), comunemente noto come indirizzo web, è una stringa unica utilizzata per individuare e raggiungere specifiche risorse online, come pagine web, immagini o file.

Il Web si basa su un protocollo specifico a livello di applicazione chiamato **HTTP** *(HyperText Transfer Protocol)* implementato in due programmi distinti, il **client** e il **server**, che sono in esecuzione su sistemi periferici diversi e comunicano tra loro scambiandosi **messaggi HTTP**. 
Il protocollo definisce sia la struttura di questi messaggi sia le regole con cui avviene lo scambio. Per comprendere il funzionamento di HTTP, è essenziale definire gli elementi che compongono il Web:
- **Oggetto (object):** È semplicemente un file che è indirizzabile tramite un **URL**.
- **Pagina web**: È costituita da un insieme di oggetti. La maggioranza delle pagine web consiste in un file HTML principale e da diversi oggetti referenziati al suo interno. Il file HTML referenzia gli altri oggetti tramite il loro URL, il quale è composto da due elementi principali: il **nome dell'host** del server e il **percorso dell'oggetto**.
_Esempio:_ Nell'URL `[http://www.someSchool.edu/someDepartment/picture.gif]`, il nome dell'host è `www.someSchool.edu` e il percorso è `/someDepartment/picture.gif`.

I due attori principali del protocollo HTTP sono:
- **Browser web:** Implementa il lato *client* di HTTP. Invia le richieste e riceve le risposte HTTP.
- **Web server:** Implementa il lato *server* di HTTP (es. Apache). Ospita gli oggetti web indirizzabili tramite URL e trasferisce le pagine richieste ai client.


###### L'Interazione con il Protocollo di Trasporto (TCP)
HTTP utilizza **TCP** come protocollo di trasporto sottostante. Il client HTTP inizia una connessione TCP con il server. Una volta stabilita, i processi client e server accedono a TCP attraverso le proprie **socket**, che fungono da "porta" tra il processo e la rete. Quando il client manda un messaggio alla sua interfaccia socket, questo passa "nelle mani" di TCP. HTTP non si deve preoccupare dello smarrimento dei dati, del loro recupero o del riordino dei pacchetti: questi sono compiti esclusivi di TCP e dei protocolli di livello inferiore. Dato che i server HTTP non mantengono alcuna informazione sui client che si connettono, HTTP è classificato come **protocollo senza memoria di stato** (_stateless protocol_).

###### Valutare l'efficienza delle connessioni
Per valutare l'efficienza delle connessioni, si utilizza la metrica **RTT (Round-Trip Time):** che rappresenta il tempo impiegato da un piccolo pacchetto per viaggiare dal client al server e tornare indietro. Include i ritardi di propagazione, di accodamento nei router e nei commutatori intermedi, e di elaborazione. ![[Pasted image 20260510111735.png|700]]
Come abbiamo visto HTTP usa TCP come protocollo di trasporto quindi prima della connessione vera e propria andrà ad eseguire un **three way handshake**
Per richiedere un file si esegue un _three-way handshake_ TCP:
1. Il client invia un piccolo segmento TCP (1/2 RTT).
2. Il server conferma con un altro segmento (1/2 RTT).
3. Il client invia la conferma finale accorpata alla richiesta HTTP (Inizio del 2° RTT).
4. Il server invia il file (Fine del 2° RTT + tempo di trasmissione).
Da questo capiamo che il ritardo totale per ogni oggetto è pari a **due RTT più il tempo di trasmissione del file**.

Detto questo durante una connessione HTTP gli sviluppatori devono decidere se instradare ogni coppia richiesta/risposta su una connessione TCP separata o mantenere attiva la stessa connessione. Da qui nasce la divisione tra connessioni non persistenti e persistenti.
###### Connessioni non persistenti
In questo approccio, ogni connessione TCP viene chiusa dopo l'invio di un singolo oggetto da parte del server (una connessione trasporta _soltanto_ un messaggio di richiesta e uno di risposta). Questo tipo di connessione viene gestita attraverso queste fasi:
1. Il client HTTP inizializza una connessione TCP con il server sulla **porta 80** (porta di default per HTTP). Vengono create le rispettive socket.
2. Il client invia un messaggio di richiesta HTTP includendo il percorso dell'oggetto (es. `/someDepartment/home.index`).
3. Il server riceve la richiesta, recupera l'oggetto, lo incapsula in un messaggio di risposta HTTP e lo invia al client.
4. Il server comunica a TCP di chiudere la connessione (TCP attenderà che il client riceva integro il messaggio prima di chiudere fisicamente).
5. Il client riceve la risposta, estrae il file HTML e trova i riferimenti ad altri oggetti (es. 10 immagini JPEG).
6. I primi quattro passi vengono **ripetuti per ciascuno degli oggetti** successivi. (es: con 10 immagini si generano in totale 11 connessioni TCP distinte).

> [!TIP] Prestazioni
> I moderni browser possono aprire connessioni TCP multiple in parallelo per abbreviare i tempi medi di risposta.

Questa tipologia di connessione si porta con se le seguenti *criticità*:
- Il server deve allocare buffer e mantenere variabili TCP per ogni singola connessione, creando un grave onere di calcolo quando ci sono centinaia di client simultanei.
- Ogni oggetto richiesto subisce l'overhead di latenza di 2 RTT.
###### Connessioni persistenti
È la modalità di default di HTTP 1.1. Il server lascia la connessione TCP aperta dopo l'invio di una risposta. Attraverso una tecnica chiamata **Pipelining** le richieste e le risposte successive per gli oggetti della stessa pagina possono essere trasmesse sulla stessa connessione una di seguito all'altra, senza aspettare le risposte delle richieste pendenti. Il server HTTP chiude la connessione solo quando questa rimane inattiva per un intervallo di tempo configurabile.
###### Formato dei Messaggi HTTP
Le specifiche HTTP definiscono rigorosamente la struttura dei messaggi in formato di testo ASCII, rendendoli leggibili dall'uomo. Esistono due tipi di messaggi:

**Il Messaggio di richiesta**: è formato dai seguenti campi
- una riga iniziale detta **riga di richiesta** (request line) che contiene a sua volta tre campi: il **metodo HTTP**, l'**URL** e la **versione di HTTP**. I principali **metodi HTTP** sono:
	- *GET*: Il metodo più comune, usato quando il browser richiede un oggetto identificato dall'URL. In questo caso il _corpo_ del messaggio è vuoto.
	- *POST*: Usato generalmente quando l'utente compila un form (es. una barra di ricerca). I dati immessi dall'utente vengono inseriti nel _corpo_ del messaggio. L'URL risultante spesso mostra i parametri della ricerca (es. `?scimmie&banane`).
	- *HEAD*: Simile al GET, ma il server risponde tralasciando l'oggetto richiesto. È usato dagli sviluppatori per test e debug (verificare il codice).
	- *PUT*: Usato per l'upload di oggetti o per la pubblicazione web verso un percorso specifico sul server.
	- *DELETE*: Consente di richiedere la cancellazione di un oggetto sul server.
- diverse **righe di intestazione** (_header lines_), tra cui le più importanti sono: 
	- `Host:` Specifica il nome del server su cui risiede l'oggetto.
	- `Connection:` Comunica al server come gestire la connessione (es. `close` per chiedere di chiuderla dopo la risposta).
	- `User-agent:` Identifica il tipo di browser che effettua la richiesta (es. Mozilla/Firefox).
	- `Accept-language:` Un'intestazione di negoziazione dei contenuti che indica la lingua preferita dall'utente.
- un **corpo** (_entity body_) contente i dati che si vogliono inviare al server (nel caso della get questa è sempre vuota)
![[Pasted image 20260510111521.png|700]]

**Il messaggio di risposta**: è formato dai seguenti campi:
- una **riga di stato** (_status line_) che contiene tre campi: **versione del protocollo, codice di stato e il messaggio di stato** associato. I codici di stato (con il messaggio di stato) più comuni sono:
	- *200 OK:* La richiesta ha avuto successo e l'oggetto è incluso nella risposta.
	- *301 Moved Permanently:* L'oggetto è stato trasferito. Il nuovo URL è specificato nell'intestazione `Location:` e il browser lo recupererà automaticamente.
	- *400 Bad Request:* Errore generico. Il server non ha compreso la richiesta.
	- *404 Not Found:* Il documento richiesto non esiste sul server.
	- *505 HTTP Version Not Supported:* Il server non supporta la versione HTTP richiesta.
- diverse  **righe di intestazione** (_header lines_) tra cui le più importanti sono:
	- `Server:` Indica il software del web server (es. Apache). È l'equivalente di _User-agent_ per il server.
	- `Date:` Data e ora di creazione e invio della risposta da parte del server.
	- `Last-Modified:` Data e ora dell'ultima modifica dell'oggetto (fondamentale per la gestione delle cache locali e dei proxy).
	- `Content-Length:` Numero di byte dell'oggetto inviato.
	- `Content-Type:` Identifica ufficialmente il tipo di oggetto contenuto nel corpo
- un **corpo** (_entity body_) contenente l'oggetto richiesto.

![[Pasted image 20260510111401.png|700]]

###### I Cookie: gestione dello stato dell'utente
Poiché HTTP è privo di stato, i server utilizzano i cookie per poter autenticare gli utenti, limitare gli accessi o fornire contenuti personalizzati (tenendo traccia degli utenti).

**Componenti della tecnologia dei cookie:**
1. Una riga di intestazione nel messaggio di **risposta** HTTP.
2. Una riga di intestazione nel messaggio di **richiesta** HTTP.
3. Un file mantenuto sul sistema dell'utente e gestito dal browser.
4. Un database lato server.
![[Pasted image 20260510111259.png|700]]

**Come funzionano i cookie (Esempio generale):**
Quando un utente visita un sito (es. un e-commerce) per la prima volta:
1. Il server riceve la richiesta e crea un **identificativo unico** (es. `1678`) registrandolo nel proprio database.
2. Il server invia la risposta HTTP includendo l'intestazione `Set-cookie: 1678`.
3. Il browser riceve la risposta, estrae l'intestazione e aggiunge una riga nel proprio file dei cookie locale (associando l'host al numero identificativo).
4. Nelle navigazioni successive sullo stesso sito, il browser includerà automaticamente in ogni richiesta HTTP l'intestazione `Cookie: 1678`.

**Utilizzi e Controversie**
Il server non conosce necessariamente il nome dell'utente, ma sa esattamente quali pagine visita, in quale ordine e a che ora.
- _Vantaggi:_ Permettono l'uso del carrello della spesa virtuale, i suggerimenti personalizzati e gli acquisti con un solo clic ("_one-click shopping_") incrociando l'ID del cookie con i dati di registrazione (indirizzo, carta di credito) conservati nel database del server.
- _Svantaggi (Privacy):_ I cookie sono fonte di controversie perché tracciano il comportamento dell'utente in rete. Le informazioni raccolte possono profilare l'utente ed essere vendute a terze parti.