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

### HTTP - HyperText Transfer Protocol

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

Quando un utente visita un sito (es. un e-commerce) per la prima volta:
1. Il server riceve la richiesta e crea un **identificativo unico** (es. `1678`) registrandolo nel proprio database.
2. Il server invia la risposta HTTP includendo l'intestazione `Set-cookie: 1678`.
3. Il browser riceve la risposta, estrae l'intestazione e aggiunge una riga nel proprio file dei cookie locale (associando l'host al numero identificativo).
4. Nelle navigazioni successive sullo stesso sito, il browser includerà automaticamente in ogni richiesta HTTP l'intestazione `Cookie: 1678`.

Il server non conosce necessariamente il nome dell'utente, ma sa esattamente quali pagine visita, in quale ordine e a che ora.
- _Vantaggi:_ Permettono l'uso del carrello della spesa virtuale, i suggerimenti personalizzati e gli acquisti con un solo clic ("_one-click shopping_") incrociando l'ID del cookie con i dati di registrazione (indirizzo, carta di credito) conservati nel database del server.
- _Svantaggi (Privacy):_ I cookie sono fonte di controversie perché tracciano il comportamento dell'utente in rete. Le informazioni raccolte possono profilare l'utente ed essere vendute a terze parti.

###### Web Caching
Il **web caching** si avvale dell'uso di sistemi intermediari per ottimizzare l'accesso e il trasferimento degli oggetti sul Web. ![[Pasted image 20260510163351.png|500]]
**Proxy (o Web Cache):** Un elemento di rete che funge da intermediario. La sua caratteristica principale è quella di operare contemporaneamente sia da server che da client:
- Funziona da **server** quando riceve richieste da un browser e gli invia le relative risposte HTTP.
- Funziona da **client** quando invia richieste e riceve risposte da un server di origine.

**Funzionamento del Proxy:**
Se la cache non dispone dell'oggetto richiesto dal browser, la procedura è la seguente:
1. Il proxy apre una connessione **TCP** verso il server di origine (es. `www.someschool.edu`).
2. Il proxy invia al server una richiesta HTTP per l'oggetto desiderato.
3. Il server di origine riceve la richiesta e invia al proxy l'oggetto incapsulato all'interno di una risposta HTTP.
4. Quando il proxy riceve l'oggetto, ne salva una **copia nella propria memoria locale**.
5. Il proxy inoltra un'altra copia dell'oggetto al browser richiedente, sempre all'interno di un messaggio di risposta HTTP, sfruttando la connessione TCP già esistente tra browser e proxy.

Il **web caching** si è sviluppato ampiamente in Internet per due ragioni fondamentali:
- **Riduzione dei tempi di risposta:** Un proxy diminuisce in modo sostanziale l'attesa per i client. Questo è particolarmente vero se l'ampiezza di banda del "collo di bottiglia" (il tratto di rete più lento tra client e server di origine) è molto inferiore rispetto all'ampiezza di banda minima disponibile tra client e proxy.
- **Riduzione del traffico di rete:** I proxy riducono drasticamente il traffico sul collegamento di accesso a Internet di un'organizzazione (es. una rete LAN aziendale o universitaria). Ciò offre il grande vantaggio economico di non dover aumentare frequentemente l'ampiezza di banda del proprio abbonamento Internet.

Sebbene il _web caching_ riduca i tempi di risposta percepiti dall'utente, introduce un nuovo problema: la copia di un oggetto che risiede nella cache potrebbe essere **scaduta**. In altre parole, l'oggetto originale ospitato sul web server potrebbe essere stato modificato rispetto alla copia archiviata localmente nel client (sia esso un proxy o direttamente il browser). Per ovviare a questo problema, il protocollo HTTP offre un meccanismo che permette alla cache di verificare se i suoi oggetti sono ancora aggiornati.

**GET condizionale:** Un messaggio di richiesta HTTP viene classificato in questo modo se soddisfa contemporaneamente due condizioni:
1. Utilizza il metodo **GET**.
2. Include al suo interno una riga di intestazione **If-modified-since:**, che indica al server la data dell'ultima memorizzazione della pagina nel proxy, se ci sono stati aggiornamenti da allora il server risponde con la nuova pagina (e questa verrà ritornata al client) senno risponde con 304 not modified


###### HTTP/2: Introduzione e diffusione
L'**HTTP/2** rappresenta la prima vera nuova versione del protocollo HTTP dopo l'HTTP/1.1 (il quale fu standardizzato nel 1997). Standardizzato nel 2015, il protocollo HTTP/2 è rapidamente decollato: nel 2020 oltre il 40% dei 10 milioni di grandi siti _web_ lo supportava. 

###### Gli obiettivi principali di HTTP/2
Gli scopi primari che hanno guidato lo sviluppo di questa nuova versione sono:
- Ridurre la latenza percepita tramite il _multiplexing_ di richieste e risposte su una singola connessione TCP.
- Fornire supporto per la **priorità delle richieste**.
- Introdurre la funzionalità di _server push_.
- Garantire una compressione efficiente dei campi di intestazione (header) HTTP.

È fondamentale sottolineare che l'HTTP/2 garantisce la compatibilità con le basi del protocollo: non modifica i metodi, i codici di stato, gli URL e i campi di intestazione dell'HTTP tradizionale. Il cambiamento strutturale risiede esclusivamente nel **modo in cui i dati vengono formattati e trasportati** tra il _client_ e il _server_.

###### I limiti di HTTP/1.1
Per comprendere la necessità di passare ad HTTP/2, occorre analizzare il funzionamento del suo predecessore. L'HTTP/1.1 utilizza **connessioni TCP persistenti**, consentendo l'invio di tutti gli oggetti che compongono una pagina _web_ tramite un'unica connessione. Questo approccio genera un problema critico di prestazioni:

**Head of Line (HOL) blocking:** Definito anche "blocco della testa della linea", si verifica quando l'invio in sequenza di tutti gli oggetti su un'unica connessione porta al blocco o al rallentamento delle risorse più piccole, costrette ad attendere in coda dietro a risorse molto più pesanti.
- _Esempio:_ Si consideri una pagina _web_ costituita da una base HTML, un video _clip_ molto grande nella parte superiore e molti piccoli oggetti nella parte inferiore. Su un collegamento a collo di bottiglia, il file video impiegherà molto tempo per essere trasmesso; di conseguenza, i piccoli oggetti subiranno un grave ritardo poiché attendono in coda dietro di esso sulla singola connessione TCP.

###### Il Workaround in HTTP/1.1 e i problemi con il TCP
Per aggirare il blocco HOL, i _browser_ HTTP/1.1 aprono abitualmente **più connessioni TCP parallele** (spesso fino a sei). Questo comportamento genera un incentivo non voluto a causa delle dinamiche del controllo di congestione TCP.

Il controllo di congestione del TCP mira infatti ad assegnare a ogni connessione che condivide un collo di bottiglia una quota uguale di larghezza di banda. Di conseguenza, se ci sono _n_ connessioni attive, ognuna ottiene circa 1/n della banda disponibile. Aprendo connessioni parallele per una singola pagina, il _browser_ riesce di fatto a "imbrogliare" il sistema, accaparrandosi una porzione molto maggiore della larghezza di banda totale.

L'HTTP/2 risolve questo aspetto mirando a **eliminare o ridurre drasticamente** il numero di connessioni TCP parallele per pagina. Ciò non solo riduce i _socket_ che i _server_ devono mantenere aperti, ma permette anche al controllo di congestione TCP di operare correttamente e in modo equo.

###### Le Soluzioni Architetturali di HTTP/2
HTTP versione 2 mette sul piatto diverse soluzioni:
- **Framing HTTP/2 e Multiplexing**: La capacità di frammentare un messaggio è il principale miglioramento apportato dall'HTTP/2. Il Framing è la soluzione al blocco HOL e consiste nel suddividere ogni messaggio HTTP in piccoli _frame_ (trame) indipendenti. Questo permette di alternare e intervallare i messaggi di richiesta e risposta sulla stessa singola connessione TCP, per poi ricostruirli a destinazione.
- **La Priorità dei Messaggi**: il protocollo permette agli sviluppatori di personalizzare l'importanza relativa delle richieste per ottimizzare il caricamento e le prestazioni dell'applicazione. Quando un _client_ invia richieste simultanee, può assegnare a ciascun messaggio un **peso compreso tra 1 e 256**. Un numero più alto indica una **priorità più alta**. Il _server_, leggendo questi pesi, provvede a inviare per primi i _frame_ associati alle risposte ritenute prioritarie.
- **Server Push:** Funzionalità che permette a un _server_ di inviare proattivamente più risposte in seguito a una singola richiesta del _client_, trasmettendogli oggetti aggiuntivi senza che questi debbano essere esplicitamente richiesti.
	- _Funzionamento:_ Quando viene richiesta la pagina base HTML, il _server_ la analizza per identificare tutti gli oggetti secondari necessari al _rendering_ completo. Identificati questi file, il _server_ effettua l'invio (_push_) al _client_ in anticipo.
	- _Vantaggio:_ Elimina completamente la latenza aggiuntiva causata dall'attesa delle singole richieste esplicite per ogni oggetto della pagina.

###### Il Protocollo QUIC e HTTP/3
**QUIC:** È un nuovo protocollo di trasporto implementato a livello di applicazione. A differenza delle precedenti iterazioni di HTTP (che viaggiano su TCP), QUIC poggia sul protocollo UDP.

L'**HTTP/3** è il nuovo protocollo _web_ progettato nativamente per funzionare su QUIC. Stando al testo di riferimento, non è stato ancora completamente standardizzato.

### FTP - File Transfer Protocol
Il protocollo **FTP** (File Transfer Protocol) è uno standard utilizzato per lo **scambio di file tra due host**. Basato sul paradigma **client-server**, sfrutta il protocollo di trasporto **TCP** per garantire l'affidabilità della comunicazione. Inoltre, offre un meccanismo di **autenticazione** che deve avvenire preventivamente, prima di poter iniziare qualsiasi scambio di dati.
###### Architettura Client-Server
Nel modello operativo dell'FTP, le responsabilità sono suddivise tra i due attori principali:
- Il **client** si occupa di caricare (upload) o scaricare (download) i file verso o dal server remoto.
- Il **server** ospita fisicamente i file e gestisce le richieste in ingresso.
###### Gestione delle Porte e Connessioni
La comunicazione FTP è particolare poiché utilizza due canali distinti per il controllo e per i dati:
- **Porta 21 (Porta di controllo):** È la porta TCP su cui il server riceve le richieste e gestisce i comandi della sessione.
- **Porta 20 (Porta dati del server):** È la porta TCP dedicata dal server all'effettivo trasferimento fisico dei file.
- **Porta dati del client:** Viene generata in modo casuale dal client e comunicata al server tramite il comando specifico `PORT`.
![[Pasted image 20260510182341.png|500]]
###### Vulnerabilità e Sicurezza
Il protocollo FTP originale è oggi considerato sconsigliato e deprecato a causa di intrinseche debolezze architetturali:
- **Accesso al File System:** Abilitare l'accesso FTP all'intero file system è una mossa altamente rischiosa. È fondamentale regolare e restringere preventivamente quali porzioni di memoria rendere accessibili.
- **Trasmissione in chiaro:** Di default, sia le credenziali di accesso che i dati stessi vengono trasmessi sulla rete in chiaro. Questo rende il protocollo estremamente vulnerabile ad attacchi informatici come il _man-in-the-middle_ e lo _sniffing_.

**SFTP:** Acronimo di _SSH File Transfer Protocol_, è la soluzione moderna che risolve i problemi di sicurezza dell'FTP standard, implementando la crittografia nativa di SSH. Sfrutta la stessa porta di SSH, ovvero la **porta 22**.

### Telnet - Terminal Network
Il protocollo **Telnet** (acronimo di _TErminaL NETwork_) è un protocollo a livello applicativo che permette di controllare il terminale di un altro host **da remoto**.
###### Architettura e Sicurezza
Il protocollo si basa sul paradigma **client-server**, dove il dispositivo remoto a cui ci si connette funge da server. Per il trasferimento dei dati, Telnet si appoggia al protocollo **TCP**, utilizzando la **porta 23** come porta destinataria verso il server.
![[Pasted image 20260510182940.png|500]]

Telnet è oggi considerato un protocollo **sconsigliato e deprecato** a causa delle sue gravi mancanze in termini di sicurezza:
- L'autenticazione non è sempre obbligatoria.
- Tutti i dati, comprese le credenziali di autenticazione, vengono trasmessi **in chiaro**.
- Questo lo rende estremamente vulnerabile ad attacchi informatici come lo _sniffing_ e il _man-in-the-middle_.

**SSH (Secure Shell Protocol):** È il protocollo che ha sostituito Telnet. Offre funzionalità simili di controllo remoto, ma è sicuro poiché crittografa le comunicazioni, evitando di trasmettere i dati in chiaro. SSH sfrutta la **porta 22**.

###### Funzionamento di Telnet
Basandosi sul livello di trasporto TCP, la comunicazione tramite Telnet prevede prima di tutto la fase di instaurazione della connessione, che sfrutta il meccanismo del **three-way handshake**.
![[Pasted image 20260510182955.png|500]]
###### Utilizzo per il Debugging
Un fatto interessante riguarda la versatilità di questo protocollo: Telnet può essere impiegato come **strumento di debug** per testare altri servizi (come i Server HTTP o i Mail Server). Per effettuare il debugging, basta avviare Telnet inserendo come porta di destinazione quella specifica del servizio da diagnosticare, anziché la sua porta standard 23.
###### Remote Desktop Protocol
**RDP:** È un protocollo di rete che condivide presupposti logici simili a quelli di Telnet (controllo di un host a distanza), ma con una differenza fondamentale: RDP permette la trasmissione dell'**intera interfaccia grafica** del dispositivo remoto, e non solo dell'interfaccia a riga di comando (terminale).
### La posta elettronica
I componenti principali che permettono il corretto funzionamento della posta elettronica sono:
- **User Agent:** Software che permette agli utenti di leggere, rispondere, inoltrare, salvare e comporre messaggi. Esempi comuni sono Microsoft Outlook, Apple Mail e Google Gmail, i quali permettono di inserire o leggere messaggi direttamente sul _mail server_.
- **Mail Server:** È il server di posta da cui vengono recuperati, prelevati e inviati i messaggi. Se due _client_ comunicanti non sono connessi allo stesso _mail server_, avviene un trasferimento diretto tra i due server di posta. All'interno dei _mail server_, troviamo due elementi chiave per la gestione dei flussi:
	- **Mailbox** (casella di posta): Spazio collocato in un _mail server_ associato a ciascun destinatario, che gestisce e contiene i messaggi a lui inviati. Per accedervi, l'utente deve essere autenticato.
	- **Coda di messaggi** (_message queue_): Un'area di parcheggio in cui il server del mittente colloca i messaggi in uscita. Se il server del mittente non riesce a consegnare subito la ￼￼DNS
posta al server del destinatario, la trattiene in questa coda cercando di trasferirla in un secondo momento.

Perché il _mail server_ non viene eseguito localmente sulla macchina dell'utente? Erroneamente si potrebbe pensare che sia un'opzione valida, ma questo obbligherebbe ogni utente a tenere il proprio dispositivo sempre acceso e in ascolto sulla rete per assicurarsi di non perdere alcuna mail. Nel paradigma _client-server_, il server deve essere sempre attivo, motivo per cui si delega la gestione del _pull_ (ricezione) delle e-mail a specifici protocolli, riservando il _push_ (invio) al protocollo SMTP.

###### Il Protocollo SMTP (Simple Mail Transfer Protocol)
**SMTP:** È il protocollo di invio e-mail che offre al _client_ il modo di mandare (_push_) i messaggi al proprio _mail server_ e che si occupa del successivo trasferimento dal _mail server_ del mittente a quello del destinatario. Utilizza il protocollo **TCP** e opera sulla porta **25**.
- **Architettura:** Presenta un **lato client** (in esecuzione sul _mail server_ del mittente) e un **lato server** (in esecuzione sul _mail server_ del destinatario).
- **Restrizione all'ASCII a 7 bit:** Essendo un protocollo storicamente "arcaico" (antecedente ad HTTP), SMTP impone di trattare sia le intestazioni che il corpo del messaggio come semplice testo ASCII a 7 bit. Questa restrizione rende necessario l'uso del protocollo **MIME** per codificare i dati multimediali (binari) in ASCII prima dell'invio.
###### Le tre fasi di SMTP
Il processo di invio tramite SMTP si divide in tre fasi ben distinte:
1. **Handshaking** (Connessione iniziale): Avviene la connessione alla porta 25 del _mail server_. Il _client_ si identifica tramite il comando `HELO`, al quale il server risponde inviando un messaggio di benvenuto.
2. **Transfer of messages** (Trasferimento): Si utilizzano specifici comandi per la composizione.
    - `MAIL FROM: <indirizzo@email.com>` per specificare l'e-mail del mittente.
    - `RCPT TO: <destinatario@email.it>` per specificare i destinatari.
    - `DATA` per indicare l'inizio del corpo della mail. All'interno si può andare a capo liberamente; la scrittura si chiude inserendo una riga che contiene esclusivamente il carattere `.` (punto).
    - _Nota operativa:_ Questo passaggio può essere ripetuto per scrivere e inviare più mail contemporaneamente sfruttando la stessa sessione TCP persistente.
3. **Closure** (Chiusura): Si utilizza il comando `QUIT` per chiudere definitivamente la connessione.

###### Formati e Intestazioni dei Messaggi
Le e-mail contengono una serie di _header_ (intestazioni) fondamentali. Ecco il significato dei principali campi a disposizione:
- **To:** Indirizzi e-mail dei destinatari primari.
- **Cc:** Indirizzi e-mail dei destinatari secondari.
- **Bcc:** Come il campo _Cc_, ma gli indirizzi e-mail inseriti non sono visibili agli altri.
- **From:** Indirizzo e-mail di chi ha scritto materialmente il messaggio.
- **Sender:** Indirizzo e-mail dell'effettivo mittente.
- **Received:** Ogni server attraverso cui passa la mail lascia una traccia all'interno di questo campo.
- **Subject:** Breve riepilogo del contenuto del messaggio (oggetto).

###### Protocolli del Mail Server (POP3 e IMAP)
Per prelevare la posta in giacenza, vengono utilizzati due protocolli principali:
- **POP3** (_Post Office Protocol_): Permette al _client_ di scaricare (effettuare il _pull_) in locale le proprie e-mail.
    - **Memorizzazione:** Le e-mail vengono salvate fisicamente sul PC dell'utente e rimosse dal _mail server_ (non rimarrà traccia sul server delle mail prelevate).
    - **Accessibilità:** La posta viene letta _off-line_. Supporta l'accesso da un solo dispositivo alla volta (non supporta la sincronizzazione multi-dispositivo) ed è per questo considerato poco adatto agli utenti _mobile_.
    - **Risorse:** Semplice da implementare, utilizza risorse del server minime e non pone problemi di spazio (quote disco) lato server.
    - **Porte TCP:** Utilizza la porta **110** (versione non crittografata) e la porta **995** (versione crittografata).
- **IMAP** (_Internet Message Access Protocol_): Permette al _client_ di accedere alle e-mail mantenendole memorizzate all'interno della casella postale nel _mail server_.
    - **Memorizzazione:** Non grava sulla memoria locale del dispositivo, ma sfrutta lo spazio del server (sollevando possibili problemi di quote disco nel tempo). Il backup delle caselle è a carico dell'ISP (Internet Service Provider).
    - **Accessibilità:** La posta viene letta _on-line_. Permette l'accesso sincronizzato alle stesse e-mail da più dispositivi contemporaneamente (ottimo per utenti _mobile_).
    - **Risorse:** Più complesso da implementare, richiede un uso estensivo delle risorse del server ma garantisce all'utente un grande controllo sul download (permettendo anche il download parziale dei messaggi).
    - **Porte TCP:** Utilizza la porta **143** (versione non crittografata) e la porta **993** (versione crittografata).
Quindi possiamo dire che la connessione tra due utenti avviene in questo modo:
![[Pasted image 20260510174814.png|700]]






### DNS - Domain name server
Proprio come le persone, anche gli _host_ in Internet possono essere identificati in vari modi. Esistono due approcci principali per l'identificazione:
- **Hostname:** Nomi testuali (es. `[www.google.com](https://www.google.com)`) facili da ricordare per le persone, ma che non forniscono alcuna informazione utile sulla collocazione fisica dell'apparato all'interno della rete, rendendoli difficilmente elaborabili dai _router_.
- **Indirizzo IP:** Sequenza di quattro _byte_ che presenta una **rigida struttura gerarchica**.
    - **Definizione di Indirizzo IP:** Identificativo numerico (es. `121.7.106.83`) in cui ogni punto separa uno dei _byte_ espressi con un numero decimale compreso tra 0 e 255. Leggendolo da sinistra a destra, si ottengono informazioni sempre più specifiche sulla collocazione dell'_host_ in Internet.

Poiché le persone preferiscono gli _hostname_ e i _router_ prediligono gli indirizzi IP, è necessario un sistema che traduca gli uni negli altri.
###### Il Servizio DNS
Per conciliare i due metodi di identificazione nasce il **DNS**.
**DNS (Domain Name System):** È contemporaneamente:
1. Un **database distribuito** implementato in una gerarchia di server DNS.
2. Un **protocollo a livello di applicazione** che consente agli _host_ di interrogare il _database_.

Il DNS viene comunemente utilizzato da altri protocolli a livello di applicazione (come HTTP e SMTP) per tradurre i nomi forniti dall'utente in indirizzi IP. Dal punto di vista dell'applicazione sull'_host_ utente, il DNS agisce come una "scatola nera" che fornisce un servizio di traduzione semplice e diretto.

Quando un _browser_ richiede una pagina web, avvengono i seguenti passaggi:
1. Il _browser_ estrae l'_hostname_ dall'URL e lo passa al lato _client_ dell'applicazione DNS in esecuzione sulla macchina dell'utente.
2. Il _client_ DNS invia una **richiesta (_query_)** contenente l'_hostname_ a un _server_ DNS. Tutti i messaggi DNS (richieste e risposte) vengono inviati all'interno di **datagrammi UDP diretti alla porta 53**.
3. Dopo un breve ritardo, il _client_ DNS riceve un **messaggio di risposta** con l'indirizzo IP corrispondente.
4. Ricevuto l'indirizzo IP, il _browser_ inizia una **connessione TCP** verso il processo _server_ HTTP collegato alla **porta 80** di quell'indirizzo IP.

###### Servizi aggiuntivi forniti dal DNS
Oltre alla traduzione da _hostname_ a indirizzo IP, il DNS offre altri servizi fondamentali:
- **Host aliasing:** Un _host_ dal nome molto complesso (chiamato **hostname canonico**) può possedere uno o più sinonimi più semplici da ricordare (es. `[www.enterprise.com](https://www.enterprise.com)` per `relay1.west-coast.enterprise.com`). Il DNS traduce il sinonimo nel nome canonico e nel relativo indirizzo IP.
- **Mail server aliasing:** Permette agli indirizzi email di essere brevi e facili da ricordare (es. `bob@yahoo.com`), nascondendo l'_hostname_ reale del _server_ di posta, che spesso è molto più complesso.
- **Distribuzione del carico di rete:** Il DNS distribuisce il carico di traffico tra _server_ replicati (come i _web server_). A un _hostname_ canonico viene associato un **insieme di indirizzi IP**. Quando il _client_ effettua una _query_, il _server_ DNS risponde con l'intera lista di indirizzi, ma ne **varia l'ordinamento** a ogni risposta, smistando così il traffico.

###### Architettura fisica del DNS

A primo impatto l'idea di usare un unico _server_ DNS centrale contenente tutte le corrispondenze può sembrare valida ma non è praticabile (non è scalabile) a causa dei continui aumenti degli _host_ in Internet. I problemi principali di questo approccio sono:
- **Single point of failure (Punto di vulnerabilità):** Se il _server_ si guasta, internet si ferma.
- **Volume di traffico:** Un singolo _server_ non potrebbe gestire tutte le richieste HTTP e mail del mondo.
- **Distanza del database:** Le interrogazioni da continenti lontani causerebbero ritardi inaccettabili a causa di collegamenti lenti o congestionati.
- **Manutenzione:** Il _database_ dovrebbe contenere i _record_ di ogni singolo _host_ mondiale.

Per risolvere questi problemi dovuti principalmente alla scalabilità il DNS è progettato in maniera distribuita e utilizza tre classi di _server_ organizzate gerarchicamente:
![[Pasted image 20260510183742.png|700]]

1. **Root server:** Ne esistono più di 1000 dislocati nel mondo (sono copie di 13 _server_ principali gestiti da 12 organizzazioni, coordinate dalla _Internet Assigned Numbers Authority_).    
2. **Top-level domain (TLD) server:** Gestiscono i domini di primo livello generici (`com`, `org`, `net`, `edu`, `gov`) e quelli relativi alle nazioni (`it`, `uk`, `fr`).
3. **DNS server autoritativi:** Ospitano i _record_ DNS accessibili pubblicamente di specifiche organizzazioni (aziende, università), associando i nomi dei loro _host_ (es. _web_ e _mail server_) ai rispettivi indirizzi IP.
###### DNS Server Locale e tipologie di query
Esiste un'altra figura centrale nell'architettura che non fa strettamente parte della gerarchia e viene chiamato **DNS server locale (o default name server)** in pratica è il _server_ fornito dall'ISP ed è solitamente "vicino" all'_host_. Funge da _proxy_: riceve le richieste dall'_host_ utente e le inoltra nella gerarchia dei _server_ DNS.

Le _query_ inviate per risolvere un indirizzo (es. per passare dal _server_ locale al _Root_, poi al _TLD_, poi all'_Autoritativo_) possono essere di due tipi:
- **Query Ricorsiva (L'approccio "Pensaci tu"):** Il _server_ che riceve la richiesta si fa **totale carico** di trovare la risposta finale per conto del richiedente. Se non conosce l'indirizzo, andrà lui stesso a interrogarne altri finché non lo trova, per poi restituire il risultato "pronto all'uso" al _client_.
- **Query Iterativa (L'approccio "Chiedi a lui"):** Il _server_ interrogato non cerca la risposta per conto del richiedente. Risponde invece con la **migliore informazione parziale** di cui dispone (ovvero: _"Non conosco l'IP esatto, ma ti fornisco l'indirizzo del server successivo a cui devi chiederlo"_). Spetterà poi a chi ha fatto la domanda eseguire il passaggio successivo.

> [!EXAMPLE] Esempio di come funziona praticamente la risoluzione di un hostname
> ![[Pasted image 20260510183824.png|500]]
> Supponiamo che l'**Host richiedente** (`cse.nyu.edu`) abbia necessità di tradurre l'_hostname_ di destinazione `gaia.cs.umass.edu` nel corrispondente indirizzo IP. Come si evince dallo schema, per ottenere questa singola mappatura vengono generati in totale **otto messaggi DNS** (quattro _query_ e quattro risposte). Il processo si sviluppa attraverso i seguenti passaggi:
> - **Passaggio 1 (Query Ricorsiva):** L'Host richiedente (`cse.nyu.edu`) invia un messaggio di richiesta DNS al proprio **DNS server locale** (`dns.nyu.edu`). Questa richiesta è di tipo **ricorsivo**, poiché l'host sta delegando al _server_ locale l'intero compito di trovare la traduzione.
> - **Passaggio 2 (Prima Query Iterativa):** Il DNS _server_ locale, non conoscendo l'indirizzo IP finale, agisce da _proxy_ e inoltra un messaggio di richiesta a un **Root DNS server**. Da questo momento in poi, le richieste lanciate dal _server_ locale sono **iterative**.
> - **Passaggio 3 (Risposta del Root):** Il Root DNS _server_ analizza il suffisso del dominio richiesto (`.edu`). Non conoscendo l'IP esatto, restituisce al DNS _server_ locale l'indirizzo IP di un **TLD DNS server** responsabile per i domini di primo livello `.edu`.
> - **Passaggio 4 (Seconda Query Iterativa):** Ricevuta l'indicazione, il DNS _server_ locale invia un nuovo messaggio di richiesta al **TLD DNS server** indicato al passaggio precedente.
> - **Passaggio 5 (Risposta del TLD):** Il TLD DNS _server_ analizza la porzione `umass.edu` e risponde fornendo al _server_ locale l'indirizzo IP del **DNS server autoritativo** di competenza per l'Università del Massachusetts (`dns.umass.edu`).
> - **Passaggio 6 (Terza Query Iterativa):** Il DNS _server_ locale effettua l'ultimo balzo, inviando il messaggio di richiesta direttamente al **DNS server autoritativo** appena ottenuto.
> - **Passaggio 7 (Risposta dell'Autoritativo):** Il DNS _server_ autoritativo possiede nel proprio _database_ il record esatto. Risponde quindi al DNS _server_ locale fornendo finalmente l'indirizzo IP di `gaia.cs.umass.edu`.
> - **Passaggio 8 (Risposta Finale al Client):** Il DNS _server_ locale, avendo risolto con successo la catena, inoltra l'indirizzo IP definitivo all'**Host richiedente**, chiudendo la richiesta ricorsiva rimasta in sospeso dal Passaggio 1.

###### DNS Caching
Il **DNS caching** è una funzione fondamentale per migliorare le prestazioni, ridurre i ritardi e abbattere il volume dei messaggi scambiati in rete. Ogni volta che un _server_ DNS riceve una risposta, memorizza (mette in _cache_) le informazioni in essa contenute. Se riceve una nuova richiesta per una coppia host-indirizzo IP già presente in _cache_, fornisce direttamente la risposta senza interrogare altri _server_. Può memorizzare anche gli indirizzi IP dei _TLD server_, permettendo al _server_ locale di aggirare i _Root server_ nelle successive catene di richieste.

###### I Record di Risorsa (RR)
I _server_ che compongono il _database_ DNS memorizzano informazioni strutturate chiamate **Record di Risorsa (RR - Resource Records)**.
Un _record_ contiene i seguenti campi fondamentali: **(Name, Value, Type, TTL)**.
- **TTL (Time To Live):** Tempo residuo di vita di un _record_; determina quando una risorsa deve essere rimossa dalla _cache_.
Il significato dei campi **Name** e **Value** cambia in base al **Type**:
- **Type=A:** `Name` è l'_hostname_ standard, `Value` è il suo indirizzo IP (corrispondenza base).
- **Type=NS:** `Name` è un dominio (es. _foo.com_), `Value` è l'_hostname_ del _server_ autoritativo per quel dominio. Serve per instradare le richieste successive nella catena.
- **Type=CNAME:** `Name` è un sinonimo, `Value` è il relativo **hostname canonico**.
- **Type=MX:** `Name` è un sinonimo di un _server_ di posta elettronica, `Value` è il suo nome canonico. Permette di avere sinonimi semplici per le email.

###### Messaggi DNS
Sia i messaggi di richiesta (_query_) che quelli di risposta presentano esattamente lo stesso formato.
![[Pasted image 20260510183858.png|700]]
Struttura del messaggio:
- **Sezione di Intestazione (_header section_):** Sono i primi 12 _byte_. Contiene:
    - **Identificatore (16 bit):** Identifica univocamente la richiesta e viene copiato nella risposta per permettere al _client_ di associarla alla _query_ inviata.
    - **Campo Flag:** Contiene vari _bit_ di controllo:
        - **Query/Reply flag:** 0 per una richiesta, 1 per una risposta.
        - **Flag Autoritativo:** Impostato nella risposta se il _server_ interrogato è quello autoritativo
        - **Recursion-desired flag (Richiesta di ricorsione):** Impostato dal _client_ se desidera che il _server_ effettui una ricerca ricorsiva nel caso in cui non disponga del _record_.
    - **Numeri di occorrenze:** Quattro campi che indicano il numero di elementi presenti nelle quattro sezioni sottostanti.
- **Sezione delle Domande:** Contiene le info sulle richieste (il `Name` richiesto e il `Type` della domanda, es. A o MX).
- **Sezione delle Risposte:** (Solo nei messaggi di risposta) Contiene i **Record di Risorsa** richiesti. Può contenere più RR se un _hostname_ ha più indirizzi IP.
- **Sezione Autoritativa:** Contiene i _record_ di altri _server_ autoritativi.
- **Sezione Aggiuntiva:** Contiene _record_ utili a corredo. (Es. se la risposta contiene un _record_ MX, in questa sezione viene aggiunto automaticamente il _record_ A con l'IP del _server_ di posta).
###### Inserimento di record nel database DNS
Per registrare un nuovo nome a dominio, ci si rivolge a un **Registrar**. Il **Registrar** È un'azienda che verifica l'unicità del nome di dominio scelto e lo inserisce nel _database_ DNS (a pagamento).
Durante la registrazione, è necessario fornire al _registrar_ i nomi e gli indirizzi IP dei propri _server_ DNS autoritativi **primario** e **secondario**. Il _registrar_ si assicurerà di inserire nei _TLD server_ (relativi al suffisso scelto, es. `.com`) due _record_ fondamentali per ciascun _server_ autoritativo:
1. Un _record_ **NS** (che associa il dominio al nome del _server_ DNS).
2. Un _record_ **A** (che associa il nome del _server_ DNS al suo indirizzo IP).    

Storicamente i _server_ DNS venivano configurati in modo statico tramite _file_. Più recentemente, al protocollo DNS è stata aggiunta l'**opzione UPDATE**, che consente l'aggiunta o la cancellazione dinamica di dati dal _database_ attraverso messaggi DNS.

### SNMP - Simple Network Management Protocol
Il protocollo **SNMP** (Simple Network Management Protocol) è un protocollo di rete **connectionless** (senza connessione, basato su comunicazioni asincrone). Il suo scopo principale è la **gestione di una rete** e il **monitoraggio dei dispositivi** ad essa collegati, permettendo agli amministratori di raccogliere informazioni dettagliate sulle prestazioni e sullo stato operativo dell'infrastruttura.
###### Attori del SNMP
L'architettura si basa sul paradigma **client-server**, composto dai seguenti elementi:
- **Manager SNMP:** L'applicazione centrale (che funge da _client_) che comunica con i dispositivi della rete per raccogliere informazioni. Ha la facoltà di inviare richieste agli agenti.
- **Agente SNMP:** Un software (che funge da _server_) presente in ogni dispositivo di rete da monitorare. Ha il compito di raccogliere le informazioni locali (come stato, configurazione e prestazioni) e rispondere alle richieste del manager.
- **MIB (Management Information Base):** Un database di oggetti residente all'interno di ogni Agente SNMP. Definisce la struttura delle informazioni e degli attributi che possono essere raccolti o modificati tramite SNMP.
- **Protocollo SNMP:** È il protocollo vero e proprio utilizzato per far comunicare agenti e manager.
###### Trasporto e Porte di Comunicazione
A differenza di FTP, SNMP si affida al protocollo di trasporto **UDP**, utilizzando le seguenti porte:
- **Porta 161:** Utilizzata dagli **Agenti SNMP** per ricevere i messaggi e le direttive dal Manager.
- **Porta 162:** Utilizzata dal **Manager SNMP** per ricevere le notifiche di allarme (le cosiddette _traps_).

**Traps:** Notifiche generate in modo asincrono dai dispositivi di rete per segnalare al manager la presenza di malfunzionamenti, eventi significativi o anomalie.
###### Messaggi SNMP
La comunicazione avviene attraverso specifiche direttive, suddivise in base al mittente:
- **Da Manager ad Agente**
	- `GetRequest`: Richiesta per recuperare il valore di una singola variabile.
	- `SetRequest`: Richiesta per applicare un cambiamento al valore di una variabile.
	- `GetNextRequest`: Richiesta per recuperare una serie di possibili variabili e i loro rispettivi valori.
- **Da Agente a Manager**
	- `GetResponse`: Messaggio che restituisce al manager il valore di una o più variabili precedentemente richieste.
	- `Trap`: Notifica inviata in maniera asincrona, senza bisogno di una richiesta preventiva del manager, per segnalare situazioni anomale o eventi di rete rilevanti.
###### Versioni di SNMP
Nel corso del tempo, il protocollo ha subìto importanti evoluzioni per colmare le sue lacune iniziali:
- **Versione 1:** Presentava numerose criticità, sia in termini di sicurezza sia per performance che risultavano migliorabili.
- **Versione 2 e Versione 3:** Migliorano notevolmente le performance e la sicurezza generale del protocollo.
- **Miglioramenti della Versione 3:** Con questa iterazione viene introdotta formalmente la **crittografia per i dati** e un **sistema di autenticazione** robusto.