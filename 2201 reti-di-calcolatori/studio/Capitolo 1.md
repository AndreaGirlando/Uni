### Generalità su internet e le architetture che lo dirigono

###### Che cos’è Internet
Internet è oggi il più grande sistema ingegnerizzato mai creato dall’uomo, composto da centinaia di milioni di calcolatori, collegamenti e commutatori connessi tra loro.

Esistono due approcci principali per descrivere che cosa sia Internet:
1. **Approccio strutturale:** Descrive gli "ingranaggi" di Internet, ovvero i componenti di base hardware e software che la costituiscono (una rete pubblica di calcolatori che interconnette miliardi di dispositivi in tutto il mondo).
2. **Approccio orientato ai servizi:** Descrive Internet in termini di infrastruttura di rete che fornisce servizi ad applicazioni distribuite.    

###### Dispositivi e componenti di Rete
In passato, i dispositivi collegati alla rete erano fondamentalmente PC tradizionali, workstation Linux o server per l'immagazzinamento e la trasmissione di pagine web e posta elettronica. Oggi, il termine "rete di calcolatori" risulta quasi datato a causa dell'enorme quantità di dispositivi non tradizionali connessi.
- **Host (sistemi periferici):** Tutti i dispositivi collegati a Internet. Possono essere suddivisi in due categorie principali:
    - **Client:** Dispositivi che richiedono servizi.
    - **Server:** Macchine più potenti che memorizzano, distribuiscono ed erogano servizi.        
- **Collegamenti** Mezzi fisici che connettono i sistemi periferici tra loro. La loro velocità di trasmissione viene misurata in bit/secondo (bps).
- **Commutatori di pacchetto:** Dispositivi che ricevono un pacchetto da un collegamento in ingresso e lo inoltrano su un collegamento in uscita verso la destinazione. Uno di quelli più importanti è il router
- **Pacchetto:** L'insieme delle informazioni generate da un sistema periferico mittente, inviate attraverso la rete e riassemblate a destinazione per ottenere i dati originari.
- **Percorso:** La sequenza specifica di collegamenti e di commutatori di pacchetto attraversata dal singolo pacchetto dal sistema di invio a quello di ricezione.

###### Provider
I sistemi periferici accedono a Internet tramite gli **ISP** (_Internet Service Provider_). Un **ISP** è un insieme di commutatori di pacchetto e di collegamenti e può essere di varia natura: residenziale, aziendale, universitario o fornitore di accesso Wi-Fi/mobile in luoghi pubblici. Per garantire la connettività globale, gli stessi ISP devono interconnettersi tra loro, creando una vera e propria **rete di reti**. 

###### Protocolli e socket
Tutti i componenti di Internet fanno uso di protocolli per gestire la comunicazione. Un **Protocollo** è una regola che definisce il formato e l’ordine dei messaggi scambiati tra due o più entità in comunicazione, così come le azioni intraprese in fase di trasmissione e/o di ricezione di un messaggio o di un altro evento. Qualsiasi tipo di protocollo viene sviluppato da una **IETF** (_Internet Engineering Task Force_) è pubblicato attraverso una **RFC** (_Request For Comment_) ovvero una pubblicazione tecnica dettagliata di come funziona il protocollo. I due protocolli principali di Internet sono il **TCP** (_Transmission Control Protocol_) e l'**IP** (_Internet Protocol_). 

Affinché un software in esecuzione su un sistema periferico possa comunicare con un altro si ha bisogno (oltre al protocollo) anche di un'**interfaccia Socket**: ovvero un insieme di regole fornite dai sistemi periferici connessi a Internet che specifica come un programma mittente debba chiedere alla rete di recapitare dati a un programma di destinazione.

###### Le reti di accesso
La **rete di accesso** rappresenta l'infrastruttura che collega fisicamente un sistema terminale (host) al suo **edge router** (noto anche come _router di bordo_). Quest'ultimo costituisce il punto di ingresso verso il "core" della rete globale e si trova immediatamente all'esterno della rete di accesso stessa. A seconda dell'ambiente (residenziale, aziendale o mobile), le principali tecnologie utilizzate per stabilire questa connessione sono:
- **DSL (Digital Subscriber Line):** Utilizza le infrastrutture in doppino di rame già esistenti della compagnia telefonica fissa.
- **Rete via cavo:** Utilizza le infrastrutture preesistenti della televisione via cavo tramite _cable modem_ speciali. Il cavo coassiale funge da **mezzo condiviso**.
- **FTTH (Fiber To The Home):** Tecnologia che usa la fibra ottica per aumentare la velocità di trasmissione.
- **5G FWA (Fixed Wireless Access):** Fornisce un accesso residenziale ad alta velocità senza la necessità di installare cavi dalla centrale locale all'abitazione
- **Rete locale (LAN):** Utilizzata in aziende, università e abitazioni per collegare i sistemi periferici al _router_ di bordo (es. reti Ethernet cablate).
- **Wi-Fi:** Consente l'accesso senza fili scambiando pacchetti con un _Access Point_, il quale è a sua volta collegato fisicamente alla rete dell'operatore.
- **Reti cellulari:** Sfruttano stazioni radio base gestite dai provider di telefonia per garantire connettività a dispositivi mobili su aree geografiche estese.

###### I mezzi fisici
Il **mezzo fisico** è il supporto attraverso cui viaggiano i bit da un sistema all'altro, venendo ritrasmessi da ogni _router_ lungo il percorso. Non deve necessariamente essere dello stesso tipo per ogni tratta. Si dividono in due macro-categorie:
- **Mezzi vincolati** le onde vengono confinate in un mezzo fisico solido:
	- **Doppino di rame intrecciato:** Il meno costoso e più utilizzato (es. reti telefoniche e LAN). Più doppini formano un cavo. La variante non schermata è detta **UTP** (_Unshielded Twisted Pair_).
	- **Cavo coassiale:** Costituito da due conduttori di rame concentrici (non paralleli). Utilizzato per TV e Internet via cavo, trasla il segnale digitale su specifiche bande di frequenza ed opera come mezzo condiviso.
	- **Fibra ottica:** Mezzo sottile e flessibile che conduce impulsi di luce (ogni impulso è un bit). Supporta enormi velocità trasmissive (fino a centinaia di gigabit al secondo).
- **Mezzi non vincolati** le onde si propagano nell’atmosfera e nello spazio esterno:
	- **Canali radio terrestri:** Sfruttano lo spettro elettromagnetico. Non richiedono cavi, attraversano pareti e supportano mobilità e lunghe distanze. Le prestazioni dipendono dall'ambiente di propagazione.
	- **Canali radio satellitari:** Collegano due o più stazioni terrestri a microonde. Si dividono in:
	    - **Satelliti GEO** (_Geostationary Earth Orbit_): Fissi a 36.000 km di altezza. Introducono un notevole ritardo di propagazione (280 ms) ma operano a centinaia di Mbps, ideali per zone non coperte da reti via cavo.
	    - **Satelliti LEO** (_Low-Earth Orbiting_): Orbita a bassa quota.

###### Il Nucleo della rete
Il nucleo di Internet è una maglia di computer collegati tra di loro. Esistono due approcci fondamentali per spostare i dati al suo interno: la commutazione di pacchetto e la commutazione di circuito.
- **Commutazione di pacchetto (packet switching)**: La sorgente suddivide i messaggi lunghi in **pacchetti**. Le risorse di rete non vengono riservate a priori, ma utilizzate su richiesta (_on demand_). I pacchetti viaggiano attraverso _router_ e commutatori condividendo la capacità trasmissiva dei collegamenti. La tecnica principale che viene utilizza è il **Trasmissione Store-and-Forward:** dove il dispositivo deve ricevere l'intero pacchetto prima di poter cominciare a trasmettere il primo bit sul collegamento in uscita. Appunto per questo ogni dispositivo mantiene un _buffer_ di output (coda) per ogni collegamento. I pacchetti subiscono quindi **ritardi di accodamento** in attesa del proprio turno. Se il _buffer_ si riempie completamente, i nuovi pacchetti in arrivo vengono scartati, causando una **perdita di pacchetto** (_packet loss_). Ogni sistema periferico ha un **indirizzo IP** inserito nell'intestazione del pacchetto. Quando il pacchetto arriva a un _router_, questo consulta la propria **tabella di inoltro** (_forwarding table_) per determinare il collegamento uscente appropriato. Queste tabelle sono configurate automaticamente dai protocolli di instradamento (_routing protocol_).
  ![[Pasted image 20260509092448.png|500]]
  
- **Commutazione di Circuito (circuit switching)**: Le risorse richieste lungo il percorso per far comunicare due sistemi periferici vengono preallocate e riservate per l'intera durata della sessione, creando una **connessione end-to-end** (punto a punto) dedicata. Questo garantisce una larghezza di banda predefinita e una velocità costante. Un circuito viene implementato tramite due tecniche di _multiplexing_:
	- **FDM** (_Frequency-Division Multiplexing_): Lo spettro di frequenza del collegamento viene diviso (es. in bande da 4 kHz), assegnando una banda dedicata a ciascuna connessione.
	- **TDM** (_Time-Division Multiplexing_): Il tempo viene suddiviso in _frame_ (intervalli) fissi, a loro volta ripartiti in _slot_ temporali. Ogni connessione riceve uno _slot_ dedicato in ogni _frame_. (es. Con frame da 8000 slot/sec e slot da 8 bit, la velocità è di 64 kbps).
  ![[Pasted image 20260509092520.png|500]]
###### Confronto: circuito vs pacchetto
La tendenza delle odierne telecomunicazioni va nettamente verso la commutazione di pacchetto, sebbene coesistano entrambi i sistemi.
- **Commutazione di Circuito:**
    - _Svantaggi:_ Dispendiosa e inefficiente. Prealloca le risorse indipendentemente dalla reale richiesta; durante i "periodi di silenzio" (es. pause in una telefonata) le risorse dedicate rimangono inattive e non possono essere usate da altri. Stabilire circuiti dedicati è complesso.
    - _Vantaggi:_ migliore per servizi in tempo reale in quanto priva di ritardi imprevedibili.
- **Commutazione di Pacchetto:**
    - _Svantaggi:_ Non garantisce ritardi _end-to-end_ determinabili a priori a causa degli accodamenti.
    - _Vantaggi:_ Molto più efficiente, economica e flessibile.

> [!EXAMPLE] Esempio di efficienza
> In un'analogia con la ristorazione, la commutazione di circuito è un ristorante che richiede la prenotazione del tavolo (riservato anche se poi non mangi), quella di pacchetto è un ristorante senza prenotazione (ti siedi appena c'è posto). Tecnicamente, se su 10 utenti solo 1 trasmette dati, nella commutazione a circuito (TDM) l'utente sfrutterà solo il suo _slot_ (il 10% della banda) sprecando il resto del tempo; nella commutazione a pacchetto, l'unico utente attivo potrà sfruttare l'intera capacità massima del collegamento istantaneamente.

###### Prestazioni delle Reti: ritardi, perdite e throughput
Le reti di calcolatori sono soggette a limiti imposti dalle leggi fisiche che influenzano inevitabilmente la comunicazione tra due sistemi periferici. Nello specifico, le reti limitano il _throughput_ (la quantità di dati trasferita al secondo), introducono ritardi e possono causare la perdita dei pacchetti. Tuttavia, esistono numerose strategie ingegneristiche per affrontare e mitigare questi problemi.

###### I ritardi di rete
Un pacchetto dati inizia il suo viaggio da un _host_ sorgente, attraversa una serie di _router_ e termina il suo percorso nell'host di destinazione. Ad ogni tappa (nodo), il pacchetto subisce differenti tipologie di ritardo. Il **Ritardo totale di nodo** è la somma di tutti i ritardi subiti da un pacchetto all'interno di un singolo nodo (che sia un _host_ o un _router_). Matematicamente è espresso dalla formula:
$$d_{nodo} = d_{elab} + d_{acc} + d_{trasm} + d_{prop}$$
![[Pasted image 20260509092611.png|700]]

In specifico i vari tipi di ritardo:
- **Ritardo di elaborazione ($d_{elab}$):** Il tempo richiesto dal nodo per esaminare l'intestazione del pacchetto e determinare la direzione in cui inoltrarlo. Influenza pesantemente la velocità massima alla quale il _router_ può inoltrare i pacchetti.
- **Ritardo di accodamento ($d_{acc}$):** Il tempo che un pacchetto trascorre all'interno di una coda in attesa di essere trasmesso sul collegamento. La sua durata dipende dal numero di pacchetti arrivati precedentemente e non ancora trasmessi.
- **Ritardo di trasmissione ($d_{trasm}$):** Il tempo fisico richiesto al nodo per "spingere" tutti i bit che compongono il pacchetto sul collegamento in uscita. Nelle reti basate sulla politica _first-come-first-served_, un pacchetto viene trasmesso solo dopo quelli che lo hanno preceduto.
    - La formula per calcolarlo è $L/R$, dove $L$ è la lunghezza del pacchetto in bit e $R$ è la velocità di trasmissione del collegamento (in bps).
    - È trascurabile per connessioni veloci ($\ge 10$ Mbps), ma diventa impattante (centinaia di millisecondi) per pacchetti grandi su collegamenti lenti.
- **Ritardo di propagazione ($d_{prop}$):** Il tempo impiegato da un singolo bit, una volta immesso sul mezzo fisico, per viaggiare fino al _router_ successivo.
    - La formula per calcolarlo è $d/v$, dove $d$ è la distanza fisica tra i due nodi e $v$ è la velocità di propagazione del mezzo fisico (compresa tra $2 \cdot 10^8$ m/s e la velocità della luce, $3 \cdot 10^8$ m/s).
    - Può essere trascurabile in reti locali (es. campus universitario), ma diventa il termine dominante nei collegamenti satellitari.

> [!TIP] Praticamente
>  Il **ritardo di trasmissione** riguarda il tempo che il nodo impiega a _mettere_ il pacchetto sul cavo, mentre il **ritardo di propagazione** riguarda il tempo che il bit impiega a _viaggiare_ lungo il cavo fino alla destinazione.

###### Approfondimento sul ritardo di accodamento
La componente più complessa da prevedere è il ritardo di accodamento ($d_{acc}$), poiché dipende dalla natura casuale del traffico entrante, oltre che dalle velocità di arrivo e trasmissione. Per stimarla facciamo uso dell'**intensità di traffico** un dato molto importante definito dal rapporto $La/R$, dove $L$ è la dimensione del pacchetto in bit, $a$ è la velocità media di arrivo (pacchetti/secondo) e $R$ è la velocità di trasmissione (bps). Da qui possiamo definire diversi scenari:
- **$La/R > 1$:** La velocità di arrivo supera la capacità trasmissiva. La coda crescerà senza limiti e il ritardo tenderà all'infinito.
- **$La/R \le 1$:** Il ritardo dipende dal comportamento del traffico:
    - _Traffico periodico:_ Se i pacchetti arrivano a intervalli regolari (es. uno ogni $L/R$ secondi), la coda sarà sempre vuota e il ritardo nullo.
    - _Traffico a raffiche:_ Si verificano ritardi medi significativi a causa dell'arrivo simultaneo di più pacchetti.        
    - _Traffico casuale (Caso reale):_ Quanto più l'intensità di traffico si avvicina a $1$, tanto più la coda si allunga rapidamente e il ritardo cresce. Se l'intensità è vicina allo zero, i pacchetti sono distanziati e il ritardo è minimo.

Nel mondo reale, le code dei _router_ non hanno una capacità infinita. Quando arriva un nuovo pacchetto e la coda è piena il router è Impossibilitato a memorizzare il dato, il _router_ quindi lo elimina causando una **perdita di pacchetto**. Questo fenomeno è causato dallo straripamento della memoria associata alla coda (**buffer overflow**). Dal punto di vista dei sistemi periferici, il pacchetto andato perduto risulterà inviato ma mai giunto a destinazione. La probabilità di perdita aumenta proporzionalmente all'avvicinarsi dell'intensità di traffico a $1$ (caso in cui la grandezza della coda aumenta).

###### Ulteriori Fonti di Ritardo
- **Ritardo End-to-End:** Il tempo totale impiegato da un pacchetto per viaggiare dalla sorgente alla destinazione finale. Ipotizzando una rete non congestionata con $N-1$ _router_ (e quindi $N$ collegamenti), e assumendo ritardi omogenei, il calcolo è: $$d_{end-to-end} = N(d_{elab} + d_{trasm} + d_{prop})$$
- **Ritardo voluto** Nei sistemi periferici, un nodo può ritardare volontariamente la trasmissione per rispettare il protocollo di condivisione di un mezzo trasmissivo comune.
- **Ritardo di pacchettizzazione:** Il tempo necessario al mittente per riempire un pacchetto con i dati da trasmettere se il payload è particolarmente pesante.    

###### Il Throughput nelle Reti
Oltre ai ritardi e alle perdite, le prestazioni si misurano attraverso la capacità effettiva della rete.
- **Throughput istantaneo:** La velocità (espressa in bps) alla quale un sistema periferico sta ricevendo dei dati in un preciso istante di tempo.
- **Throughput medio:** La velocità complessiva del trasferimento di un dato, calcolata come $F/T$ (bps), dove $F$ sono i bit totali del file e $T$ è il tempo totale in secondi impiegato per la ricezione.

![[Pasted image 20260509092639.png|500]]

Per comprendere il _throughput_, si può immaginare la rete come un sistema di tubature idrauliche dove i bit sono un fluido e i collegamenti sono i tubi. In un semplice collegamento _Server_ $\rightarrow$ _Router_ $\rightarrow$ _Client_ (con velocità rispettivamente $R_s$ e $R_c$), il _throughput_ end-to-end è determinato dal tubo più stretto, ovvero $\min(R_s, R_c)$. Quindi il **Collo di bottiglia** è dietro l'angolo, infatti in un percorso di rete composto da $N$ collegamenti, è il collegamento con la velocità di trasmissione più bassa ($\min(R_1, R_2, ..., R_N)$), che detta il limite massimo di _throughput_ per l'intero trasferimento. ![[Pasted image 20260509092703.png|700]]
Nella rete Internet reale:
- I collegamenti nel nucleo (_core_) della rete hanno capacità estremamente elevate. Di conseguenza, il collo di bottiglia è quasi sempre localizzato nella **rete di accesso** (il collegamento periferico di utente o server).
- Tuttavia, il _throughput_ non dipende solo dalla larghezza di banda fisica, ma anche **dal traffico in essere**. Se un collegamento veloce nel nucleo della rete (es. $R = 5$ Mbps) deve essere diviso equamente tra $10$ _download_ simultanei, ogni flusso riceverà solo $500$ kbps. Se questa frazione è inferiore alle velocità delle reti di accesso, il nucleo diventa temporaneamente il collo di bottiglia.
###### Architettura di rete
L'odierna Internet è un sistema di immensa complessità, composto da mezzi trasmissivi, protocolli, _router_ e applicazioni. Per gestire intellettualmente e ingegneristicamente questa complessità, si ricorre a un'organizzazione strutturata. Per comprendere questo approccio organizzativo, si utilizza spesso l'analogia con le linee aeree: l'intero sistema del viaggio aereo è scomposto in azioni specifiche (biglietteria, bagagli, gate, volo, ritiro). Ogni fase ha compiti precisi ed è gestita da protocolli specifici, permettendo al sistema globale di funzionare in modo coordinato. ![[Pasted image 20260509092817.png|500]]
Esiste una forte analogia tra l'infrastruttura di una linea aerea e le reti di calcolatori: così come una compagnia aerea trasporta un passeggero da una località di partenza a una di destinazione, in Internet un pacchetto viene trasportato da un **host sorgente** a un **host di destinazione**.

###### L'Architettura a livelli (Stratificazione)
Per gestire sistemi grandi, articolati e complessi (costantemente soggetti ad aggiornamenti), i progettisti organizzano l'hardware, il software e i protocolli in **livelli** (o strati). Ciascun protocollo appartiene a uno specifico livello.

L'architettura a livelli offre dei vantaggi tra cui la **modularità** infatti rende molto più facile discutere una parte specifica del sistema e cambiarne l'implementazione senza coinvolgere o alterare le altre componenti. Fino a quando un livello fornisce lo stesso servizio allo strato superiore e utilizza gli stessi servizi dallo strato inferiore, il resto del sistema rimane invariato.

Tuttavia, alcuni ricercatori evidenziano dei potenziali svantaggi legati a questo approccio:
- **Duplicazione delle funzionalità:** Un livello potrebbe duplicare le operazioni di quello inferiore (es. meccanismi di correzione degli errori forniti su più livelli).
- **Violazione della separazione:** La funzionalità di un livello potrebbe richiedere informazioni presenti solo in un altro livello, vanificando lo scopo insito nella separazione stessa.

Il **Modello di servizio** (_service model_): È l'insieme dei servizi offerti da un livello a quello immediatamente superiore. Ogni livello fornisce il proprio servizio effettuando determinate azioni al suo interno e utilizzando, a sua volta, i servizi del livello inferiore. Un livello di protocolli può essere implementato via software, via hardware o tramite una combinazione di entrambi:
- **Implementazione Software:** Tipica dei livelli più alti. I protocolli a livello di applicazione (es. HTTP, SMTP) e a livello di trasporto sono quasi sempre implementati via software.
- **Implementazione Hardware:** Tipica dei livelli più bassi. I livelli fisico e di data link (che gestiscono collegamenti specifici come Ethernet o Wi-Fi) sono di regola implementati direttamente nella scheda di rete.    
- **Implementazione Mista:** Il livello di rete è spesso un'implementazione mista di hardware e software.
###### Architettura a livelli di internet
Dati i vantaggi offerti da un'architettura stratificata, Internet è strutturato a livelli. L'insieme dei suoi protocolli è definito **pila protocollare** (o stack), composta da cinque livelli che analizzeremo di seguito, procedendo dal basso verso l'alto:
![[Pasted image 20260509092841.png|700]]

**Livello di applicazione**
È la sede delle applicazioni di rete e dei relativi protocolli. Un protocollo a questo livello è distribuito su più sistemi periferici: l'applicazione su un sistema scambia pacchetti di informazioni con l'applicazione su un altro sistema.
- **Messaggio:** È il termine tecnico con cui si indica il pacchetto di informazione scambiato a livello applicativo.
- **Protocolli principali:** HTTP (richiesta e trasferimento di documenti web), SMTP (trasferimento di e-mail), FTP (trasferimento file tra sistemi remoti) e DNS (_Domain Name System_, che traduce i nomi degli host in indirizzi di rete a 32 bit).

**Livello di trasporto**
Trasferisce i **messaggi** del livello di applicazione tra punti periferici gestiti dalle applicazioni stesse.
- **Segmento:** È il pacchetto di dati gestito a livello di trasporto.
- **Protocollo TCP:** Fornisce un servizio orientato alla connessione. Include la consegna garantita dei messaggi, il controllo di flusso, il frazionamento dei messaggi lunghi in frammenti più piccoli e il controllo della congestione (la sorgente regola la velocità trasmissiva se la rete è congestionata).
- **Protocollo UDP:** Fornisce un servizio non orientato alla connessione. È un servizio "senza fronzoli", privo di garanzie di affidabilità, controllo di flusso o controllo della congestione.

**Livello di rete**
Si occupa di trasferire i pacchetti da un host all'altro instradandoli attraverso una serie di **router** lungo il percorso tra sorgente e destinazione. Il livello di trasporto gli consegna un segmento e un indirizzo di destinazione (come se consegnasse una lettera all'ufficio postale).
- **Datagramma:** È il pacchetto gestito a livello di rete.
- **Protocollo IP:** È il protocollo fondamentale di questo livello. Definisce i campi dei datagrammi e il modo in cui router e sistemi periferici vi agiscono. Tutti gli apparati Internet dotati di livello di rete devono supportare l'IP.

**Livello di collegamento**
Per trasferire un pacchetto da un nodo a quello adiacente sul percorso, il livello di rete si affida a questo livello. I servizi offerti dipendono dallo specifico protocollo utilizzato nella singola tratta (es. Ethernet, Wi-Fi).
- **Frame:** È l'unità di dati spostata dal livello di collegamento da un elemento della rete a quello adiacente.
- _Nota:_ Nel viaggio dalla sorgente alla destinazione, un datagramma potrebbe essere gestito da protocolli di collegamento differenti a seconda delle diverse tratte attraversate.

**Livello fisico**
Mentre il livello di collegamento sposta interi frame, il ruolo del livello fisico è trasferire i **singoli bit** che compongono il frame da un nodo a quello successivo. I protocolli dipendono strettamente dal tipo di collegamento e dall'effettivo mezzo trasmissivo utilizzato.

###### L'Incapsulamento dei dati
La pila protocollare è necessaria quando un dispositivo vuole inviare un messaggio nella rete, in questo caso infatti nasce il processo chiamato *incapsulamento* attraverso il quale un pacchetto dati, scendendo lungo la pila di protocolli del sistema mittente, viene progressivamente "avvolto" con nuove informazioni di controllo da parte di ogni livello attraversato, prima di essere trasmesso e fare il percorso inverso nel sistema ricevente.
![[Pasted image 20260509092902.png|500]]

In ogni livello, il pacchetto risulta composto da due parti:
1. **Intestazione** (_Header_): Le informazioni di controllo aggiunte dal livello corrente.
2. **Payload** (Carico utile): Il pacchetto dati vero e proprio proveniente dal livello superiore.

**Fasi dell'incapsulamento:**
1. Il **Messaggio** (livello applicazione) viene passato al livello di trasporto.
2. Il livello di trasporto concatena le proprie informazioni aggiuntive, creando un **Segmento**. _(Nota: un messaggio grande può essere diviso in più segmenti)_.
3. Il segmento passa al livello di rete, che aggiunge la propria intestazione (contenente, ad esempio, gli indirizzi dei sistemi periferici), creando un **Datagramma**. _(Nota: un segmento può a sua volta essere diviso in più datagrammi, che andranno poi ricostruiti in ricezione)_.
4. Il datagramma passa al livello di collegamento, che aggiunge un'ulteriore intestazione creando un **Frame**.
###### Reti Sotto Attacco (Sicurezza)
Il campo della sicurezza di rete analizza come i malintenzionati possono attaccare le reti e come difenderle. Insieme ai contenuti legittimi (web, email, ecc.), tramite Internet circolano minacce che infettano i dispositivi.
- **Malware:** Software malevolo (o "contenuto cattivo") che penetra nei dispositivi per comprometterli o cancellare file. Spesso i malware odierni sono **auto-replicanti**: una volta infettato un host, cercano automaticamente nuovi host da infettare, diffondendosi a velocità esponenziale.
- **Botnet:** Una rete composta da migliaia di dispositivi compromessi (controllati dal malintenzionato) utilizzata per compiere azioni coordinate, come l'invio di e-mail spazzatura (_spam_) o per lanciare attacchi informatici massicci.

###### Attacchi DoS e DDoS
**Attacco DoS** (_Denial of Service_ / Negazione del servizio): Tipologia di attacco che rende inutilizzabile un host, una rete o un'infrastruttura agli utenti legittimi. Esistono tre categorie principali:
1. **Attacchi alla vulnerabilità dei sistemi:** Invio di pochi messaggi specifici e ben costruiti verso un'applicazione vulnerabile o un sistema operativo. Se la sequenza è corretta, il servizio si ferma o l'host si spegne.
2. **Inondazione di banda** (_Bandwidth flooding_): L'attaccante invia un "diluvio" di pacchetti all'host bersaglio. La mole di dati ostruisce il collegamento di accesso, impedendo ai pacchetti legittimi di passare.
3. **Inondazione di connessioni** (_Connection flooding_): L'attaccante stabilisce un numero enorme di connessioni TCP (completamente o parzialmente aperte) verso l'host. Il bersaglio si "ingorga" gestendo queste richieste fasulle e non riesce più ad accettare connessioni valide.
**Attacco DDoS** (_Distributed Denial of Service_): È una variante del DoS in cui l'attaccante controlla **più sorgenti** (es. tramite una botnet) che attaccano simultaneamente il bersaglio. Questo rende la difesa molto più difficile, poiché, in un attacco a sorgente singola, un router a monte potrebbe facilmente bloccare il traffico isolando l'IP ostile.

###### Analisi del Traffico e Spoofing
L'uso massiccio di dispositivi wireless (Wi-Fi, cellulari) introduce gravi vulnerabilità dovute alla facilità di intercettazione passiva.
- **Packet sniffer:** È un ricevitore passivo posizionato in prossimità di un trasmettitore wireless (o in una rete cablata di tipo _broadcast_ come le LAN Ethernet) capace di ottenere e memorizzare una copia di ogni singolo pacchetto in transito, incluse le informazioni sensibili. Essendo totalmente passivo (non immette nulla nel canale), è estremamente difficile da individuare.
- **IP spoofing:** La pratica di creare un pacchetto "fatto a mano" alterandone le informazioni, inserendo in particolare un indirizzo IP sorgente **falso**, e immetterlo in Internet. La rete, ignara dell'inganno, inoltrerà doverosamente il pacchetto al destinatario.