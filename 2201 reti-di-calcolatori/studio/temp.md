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