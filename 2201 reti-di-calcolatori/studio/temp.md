### Principi del controllo di congestione
Il controllo di congestione è un aspetto critico in un contesto di rete generale. La congestione è un fenomeno negativo che si manifesta con scarse prestazioni per le applicazioni dei livelli superiori e con un basso utilizzo delle risorse. Per comprenderne cause e conseguenze, esaminiamo tre scenari via via più complessi.

###### Scenario 1: Due mittenti e un router con buffer illimitati
Consideriamo lo scenario di congestione più semplice possibile: due host (A e B) con una connessione che condivide un singolo router intermedio. 
![[Pasted image 20260514200424.png|700]]
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
- **Caso Realistico (_Timeout_ lungo):** Il mittente imposta un _timeout_ sufficientemente grande da ritrasmettere solo quando è certo che il pacchetto sia perduto.
    - _Esempio numerico:_ Se il carico offerto $\lambda'_{in}$ vale **$R/2$** (pari a $0,5 R$ unità di dati), il _throughput_ reale scende a **$R/3$**. Di questi $0,5 R$ trasmessi, in media **$0,333 R$ byte/s** sono dati originali e **$0,166 R$ byte/s** sono ritrasmissioni _(Riferimento Figura 3.46b)_.
    - _Costo della congestione:_ Il mittente deve sprecare capacità per effettuare ritrasmissioni necessarie a compensare i pacchetti caduti per l'_overflow_ dei _buffer_.
- **Caso Pessimistico (_Timeout_ prematuro):** Il mittente ritrasmette un pacchetto che ha subito solo un ritardo in coda, ma non è perduto. Al destinatario arrivano copie multiple (e ne basta una). Il router spreca lavoro per instradare copie inutili.
    - _Conseguenza:_ Se ogni pacchetto è instradato mediamente due volte, il _throughput_ assumerà asintoticamente il valore **$R/4$** quando il carico offerto tende a $R/2$ _(Riferimento Figura 3.46c)_.
![[Pasted image 20260514200550.png|600]]
###### Scenario 3: Quattro mittenti, router con buffer finiti e percorsi composti da più collegamenti
Ipotizziamo quattro host che trasmettono dati avvalendosi di meccanismi di _timeout_ e ritrasmissione (tutti con lo stesso valore di $\lambda_{in}$). I percorsi sono composti da due collegamenti sovrapposti (multi-hop). La capacità di tutti i collegamenti è $R$. 
![[Pasted image 20260514200611.png|700]]

Consideriamo la connessione dall'Host A all'Host C che passa per i router R1 e R2. Questa connessione condivide R1 con la connessione D-B e R2 con la connessione B-D.
- **Traffico scarso (Piccoli valori di $\lambda_{in}$):** Gli _overflow_ sono rari. Un incremento di $\lambda_{in}$ provoca un incremento proporzionale del _throughput_ ($\lambda_{out}$).
- **Traffico intenso (Grandi valori di $\lambda_{in}$ e $\lambda'_{in}$):** Analizziamo il router R2. Il traffico A-C arriva a R2 (già instradato da R1) al massimo con tasso $R$. Tuttavia, se il traffico concorrente B-D è enorme, il tasso di arrivo di B-D su R2 sarà molto più elevato. I pacchetti A-C e B-D competono per lo spazio limitato del _buffer_ in R2.
- **Collasso del _throughput_:** Al tendere del traffico B-D all'infinito, ogni spazio vuoto in R2 viene colmato dai pacchetti B-D. Il traffico A-C viene scartato per _overflow_ in R2 e il suo _throughput end-to-end_ **tende a 0**.
- **Costo estremo della congestione (Lavoro sprecato):** Ogni qualvolta un pacchetto viene scartato al secondo _hop_ (es. R2), tutto il lavoro effettuato dal router del primo _hop_ (R1) per instradarlo viene irrimediabilmente perso. La rete avrebbe funzionato meglio se il primo router lo avesse scartato subito.
![[Pasted image 20260514201455.png|600]]
###### Approcci al controllo di congestione
Nella pratica esistono due orientamenti principali per gestire la congestione, che si differenziano in base all'architettura di rete e ai protocolli:
- **Controllo di congestione end-to-end:** Il livello di rete non fornisce alcun supporto esplicito al livello di trasporto. La presenza di congestione deve essere dedotta esclusivamente dai sistemi periferici (mittente e destinatario) osservando il comportamento della rete. **TCP** adotta obbligatoriamente questo approccio, poiché il protocollo IP standard non offre _feedback_ sullo stato della rete.
- **Controllo di congestione assistito dalla rete:** I componenti a livello di rete (i router) forniscono un _feedback_ esplicito al mittente. Questo avviene solitamente in due modi:
    1. **Chokepacket (Pacchetto di strozzatura):** Un avviso diretto inviato dal router congestionato al mittente (messaggio: "Sono congestionato!").
    2. **Impostazione di un campo/bit:** Il router imposta un bit o un campo in un pacchetto dati che sta fluendo dal mittente al destinatario per segnalare il traffico. Questo approccio era adottato nelle prime architetture **SNA di IBM** e viene utilizzato nel controllo **ATM ABR** (_Available Bit Rate_), che consente al router di informare il mittente sulla frequenza trasmissiva esatta che può sopportare sul collegamento.        

###### Controllo di congestione in TCP (Classico)
TCP "classico" (la versione standardizzata) utilizza il controllo _end-to-end_. L'approccio consiste nell'imporre a ciascun mittente TCP un limite al tasso di invio in funzione della congestione percepita: si incrementa la trasmissione se c'è scarso traffico e la si riduce se c'è congestione.

Per farlo, il protocollo risponde a tre domande fondamentali:
- **Come TCP limita il tasso di invio?** TCP utilizza una variabile aggiuntiva mantenuta agli estremi della connessione: la **Finestra di Congestione (_cwnd_)**. **Regola fondamentale:** La quantità di dati inviata da un mittente che non ha ancora ricevuto _acknowledgment_ non può eccedere il minimo tra i valori della _cwnd_ e della finestra di ricezione (_rwnd_). Assumendo per semplicità un _buffer_ di ricezione enorme (ignorando il vincolo _rwnd_) e supponendo che il mittente abbia sempre dati da inviare, la velocità di invio viene regolata esclusivamente modificando il valore della _cwnd_.
- **Come TCP percepisce la congestione?** TCP rileva un **Evento di perdita** in due modi:
    1. Scadenza di un **_timeout_**.
    2. Ricezione di **tre ACK duplicati** dal destinatario.
Poiché l'_overflow_ dei _buffer_ causa l'eliminazione di un datagramma, il mittente considera questi eventi di perdita come il sintomo diretto della congestione, riducendo conseguentemente il tasso di invio.        
- **Come TCP capisce che la rete è libera?** L'arrivo di _acknowledgment_ (ACK) non duplicati è considerato un segnale che i segmenti sono stati consegnati con successo. All'arrivo di questi ACK, TCP espande la _cwnd_. **Auto-temporizzazione (Self-clocking):** Se gli ACK arrivano lentamente, la _cwnd_ cresce lentamente; se arrivano velocemente, cresce rapidamente. TCP utilizza gli ACK stessi per scandire gli incrementi della finestra.

**Rilevamento della larghezza di banda (Bandwidth Probing) e Princìpi Guida:**
Il problema critico è determinare la velocità esatta: se tutti i TCP trasmettessero troppo velocemente si avrebbe il collasso, se fossero troppo cauti la rete sarebbe sottoutilizzata.
Poiché non esiste coordinazione esplicita tra i mittenti, TCP utilizza una strategia distribuita di "sondaggio":
1. **Un segmento perso implica congestione:** Il tasso di trasmissione viene decrementato.
2. **Un ACK indica rete libera:** Il tasso di trasmissione viene incrementato.
3. **Il Ciclo di Rilevamento:** TCP aumenta progressivamente il tasso di invio per "tastare" la rete finché non si verifica una perdita (punto di inizio della congestione); a quel punto rallenta, per poi ricominciare la fase di rilevamento e testare se le condizioni sono cambiate.
Questo meccanismo è gestito dal celebrato algoritmo di controllo della congestione di TCP, che si articola in tre componenti/fasi principali:
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
    1. **Evento di timeout (Congestione grave):** TCP riporta _cwnd_ a 1 _MSS_ e ricomincia la _slow start_. Viene inoltre aggiornata la variabile di stato **ssthresh (Slow Start Threshold - Soglia di slow start)**, impostandola a metà del valore che _cwnd_ aveva al momento della perdita (ovvero _cwnd_/2).
    2. **Raggiungimento della soglia:** Quando _cwnd_ raggiunge o supera il valore di _ssthresh_ (considerato il limite di sicurezza basato sull'ultima congestione nota), raddoppiare diventa temerario. TCP termina la _slow start_ ed entra in _congestion avoidance_.
    3. **Tre ACK duplicati:** Il mittente effettua una **ritrasmissione rapida** ed entra direttamente nello stato di _fast recovery_.

###### La fase di _Congestion Avoidance_ (Prevenzione della Congestione)
Quando TCP entra in questo stato, il valore di _cwnd_ è circa la metà di quello che ha causato l'ultima congestione. L'approccio diventa conservativo.
- **Crescita Lineare:** Invece di raddoppiare, TCP incrementa _cwnd_ di **1 MSS ogni RTT**.
- **Implementazione pratica:** Il mittente aumenta _cwnd_ di una frazione per ogni singolo ACK ricevuto, usando la formula: `Incremento = MSS × (MSS/cwnd) byte`.
    - _Esempio:_ Se _MSS_ = 1460 byte e _cwnd_ = 14.600 byte (10 segmenti), ogni ACK incrementa la finestra di 1/10 di _MSS_. Ricevuti tutti e 10 gli ACK, la finestra sarà cresciuta esattamente di 1 _MSS_.
- **Termine della fase:** 
    1. **Evento di timeout:** Esattamente come in _slow start_, _cwnd_ torna a 1 _MSS_ e _ssthresh_ viene dimezzata (_cwnd_/2).
    2. **Tre ACK duplicati:** L'evento è considerato meno drastico del _timeout_. TCP dimezza il valore di _cwnd_ (aggiungendovi 3 _MSS_ per compensare i 3 duplicati ricevuti), imposta _ssthresh_ alla metà del valore di _cwnd_ precedente, ed entra in _fast recovery_
![[Pasted image 20260514200339.png|700]]
###### La fase di Fast Recovery (Recupero Rapido) e le Varianti TCP

Il _fast recovery_ è un componente raccomandato ma non obbligatorio (definito nella RFC 5681). Durante questa fase:
- _cwnd_ viene incrementato di 1 _MSS_ per ogni ACK duplicato ricevuto relativo al segmento perso.
- Quando arriva l'ACK per il segmento perso (quello ritrasmesso), TCP riduce _cwnd_ ed entra in _congestion avoidance_.
- Se si verifica un _timeout_ durante il _fast recovery_, TCP crolla in _slow start_ (_cwnd_ = 1 _MSS_, _ssthresh_ = _cwnd_/2).

Esistono differenze storiche nella gestione degli errori:
- **TCP Tahoe (Versione originaria):** Non possiede il _fast recovery_. In caso di _qualsiasi_ perdita (sia _timeout_ che 3 ACK duplicati), porta incondizionatamente _cwnd_ a 1 _MSS_ ed entra in _slow start_.
- **TCP Reno (Versione moderna):** Adotta regolarmente il _fast recovery_.
- **Evoluzione a confronto:**. Immaginando un _ssthresh_ iniziale di 8 _MSS_, per i primi 8 cicli Tahoe e Reno sono identici (crescita esponenziale fino a 8, poi lineare). All'ottavo ciclo (con _cwnd_ = 12 _MSS_) si verifica un triplo ACK duplicato. La nuova soglia _ssthresh_ diventa 6 _MSS_ ($12/2$).
	- **Reno:** Imposta _cwnd_ a 6 _MSS_ e riprende a crescere linearmente.
	- **Tahoe:** Crolla con _cwnd_ a 1 _MSS_, cresce esponenzialmente fino a 6 _MSS_, poi riprende linearmente.
![[Pasted image 20260514200238.png|700]]
###### Retrospettiva: AIMD e _Throughput_ Macroscopico
Ignorando le anomalie (_timeout_ e le _slow start_ iniziali), il controllo di TCP è guidato dalla ricezione dei 3 ACK duplicati e si basa su un principio matematico:
- **AIMD (Additive-Increase Multiplicative-Decrease):** TCP incrementa in modo additivo e lineare la finestra (+1 _MSS_ per _RTT_) e la decrementa in modo moltiplicativo (dimezzandola) in caso di perdita. Questo genera il caratteristico grafico a "**dente di sega**" (_saw tooth_). ![[Pasted image 20260514200300.png|600]]
- **Modello Macroscopico del Throughput:** Se $W$ è la dimensione della finestra quando si verifica la perdita, la velocità di trasmissione oscilla costantemente tra $\frac{W}{2 \cdot RTT}$ e $\frac{W}{RTT}$. Poiché la crescita tra i due estremi è lineare, si ottiene la formula: $$ \text{Throughput medio di una connessione} = \frac{0.75 \cdot W}{RTT} $$
###### Notifica Esplicita di Congestione (ECN)
Estensioni recenti di IP e TCP (RFC 3168) permettono un controllo assistito dalla rete:
- **ECN (Explicit Congestion Notification):** Utilizza due bit nel campo _Tipo di Servizio_ dell'intestazione IP. 
  ![[Pasted image 20260514200201.png|600]]
- **Funzionamento:** Se un router rileva una congestione persistente, imposta questi bit e inoltra il pacchetto. Il destinatario riceve il pacchetto e informa il mittente impostando il bit **ECE** (_Explicit Congestion Notification Echo_) all'interno di un segmento ACK.
- **Reazione:** Il mittente TCP reagisce dimezzando la _cwnd_ (come in una ritrasmissione rapida) e imposta il bit **CWR** (_Congestion Window Reduced_) nel successivo segmento inviato al ricevente per confermare la presa visione.

###### La Fairness (Equità) in TCP
Un meccanismo di controllo si dice _fair_ (equo) se $K$ connessioni che condividono un collo di bottiglia con capacità $R$ (assumendo assenza di traffico UDP) ottengono ciascuna una velocità media pari a **$R/K$**. Immaginiamo 2 connessioni TCP con identici _MSS_ e _RTT_, sempre in _congestion avoidance_.
![[Pasted image 20260514212511.png|600]]
All'aumentare della _cwnd_ (+1 _MSS_), il _throughput_ congiunto cresce lungo una semiretta a 45°. Quando la somma delle velocità supera $R$, i pacchetti vengono persi. Entrambe le connessioni dimezzano la loro _cwnd_ (il grafico decresce verso l'origine). Riprendendo a crescere a 45° e dimezzando ciclicamente, le connessioni convergono inevitabilmente verso la bisettrice del piano, ovvero la **linea di equa condivisione della banda**.
![[Pasted image 20260514212625.png|600]]
**Il peso dell'RTT:** Le ipotesi di base quasi mai si verificano nella realtà (le applicazioni _client/server_ ottengono porzioni assai diverse). Nello specifico, a parità di condizioni, le connessioni con un **RTT inferiore** riescono ad aprire le proprie finestre di congestione molto più rapidamente, accaparrandosi _throughput_ superiori a discapito di quelle con _RTT_ più alto.