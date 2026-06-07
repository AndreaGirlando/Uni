## Capitolo 1

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

## Capitolo 2


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

## Capitolo 3


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
In una rete, un meccanismo di controllo della congestione soddisfa il criterio di **equità** (_fairness_) se $K$ connessioni omogenee, che condividono un unico collegamento critico di capacità $R$ in assenza di traffico esogeno, convergono nel lungo periodo verso un throughput medio equamente ripartito e pari a $R/K$. Il protocollo **TCP** persegue questo obiettivo allocando la banda dinamicamente tramite l'algoritmo **AIMD** durante la fase di _Congestion Avoidance_. L'evoluzione dinamica del sistema può essere modellata geometricamente su un piano cartesiano i cui assi rappresentano i throughput delle singole connessioni, definendo lo spazio di stato tramite due rette fondamentali: la **linea di pieno utilizzo dell'ampiezza di banda** (Linea dell'Efficienza, $conn1 + conn2 = R$ la somma dei due throughput può essere al massimo $R$), che possiede pendenza negativa poiché il vincolo fisico impone che l'incremento di banda di un flusso corrisponda a una contrazione simmetrica del secondo, e la **linea di equa condivisione dell'ampiezza di banda** (Linea dell'Equità, $conn1 = conn2$), coincidente con la bisettrice del quadrante. L'obiettivo del controllo di congestione è la convergenza asintotica verso il punto di intersezione tra queste due rette. ![[Pasted image 20260519105038.png|700]]
Per analizzare la dinamica microscopica, facendo riferimento alla figura, si parte da uno **stato iniziale arbitrario**, (punto **A**), in cui la connessione 2 gode di un throughput superiore. Poiché la rete non è satura, entrambe le connessioni aumentano linearmente la propria finestra di congestione della stessa quantità fissa per ogni RTT (+1 MSS); sul piano cartesiano, questo _incremento additivo_ genera uno spostamento lineare con una **pendenza geometrica di esattamente 45 gradi** (traiettoria da **A** a **B**), sviluppandosi in modo strettamente parallelo alla linea di equa condivisione e mantenendo così inalterato il divario assoluto tra le connessioni.

Intersecando e superando la linea di pieno utilizzo (punto **B**), i buffer dei router si saturano causando perdita di pacchetti l'algoritmo AIMD impone il **dimezzamento immediato** della finestra di entrambi i flussi, operazione che geometricamente equivale a far arretrare il sistema lungo una linea retta orientata verso l'origine degli assi (traiettoria da **B** a **C**). Essendo il taglio proporzionale (percentuale), la connessione 2 subisce una **riduzione quantitativa assoluta molto più severa** rispetto alla connessione 1, forzando il punto **C** a posizionarsi matematicamente più vicino alla linea della bisettrice rispetto alla traiettoria precedente.

Riprendendo la fase di crescita (traiettoria da **C** a **D**) e subendo ciclicamente questi dimezzamenti, si produce un caratteristico andamento geometrico a **dente di sega** che restringe progressivamente le oscillazioni attorno all'intersezione ottimale, garantendo l'equa ripartizione.

Tuttavia, è fondamentale precisare che questa equità perfetta si realizza _solo_ sotto la condizione di totale omogeneità dei flussi; nella realtà delle reti Internet, l'ipotesi di identità dei **tempi di andata e ritorno** (RTT) non si verifica quasi mai. Le connessioni caratterizzate da un **RTT inferiore**, infatti, riescono ad eseguire la fase di incremento additivo molto più rapidamente, deviando la traiettoria di crescita a proprio favore e introducendo un'**asimmetria intrinseca** che penalizza fortemente le connessioni a lungo raggio, comprimendone il throughput a vantaggio dei flussi locali.

> [!TIP] Formale
> **Definizione:** In una rete a commutazione di pacchetto, un meccanismo di controllo della congestione garantisce l'**equità** (_fairness_) se $K$ connessioni omogenee, che condividono un unico collo di bottiglia con capacità $R$ in assenza di traffico esogeno, convergono nel lungo periodo verso un throughput medio equamente ripartito e pari a $R/K$.
> 
> **Dimostrazione:** L'equità del protocollo **TCP** viene dimostrata geometricamente analizzando le dinamiche dell'algoritmo **AIMD** su un piano cartesiano. Tracciando la **linea dell'efficienza** ($A + B = R$) e la **linea dell'equità** ($A = B$), si osserva che l'_incremento additivo_ fa crescere i throughput in modo strettamente parallelo alla linea dell'equità (con pendenza a 45 gradi), mantenendo inalterato il divario assoluto tra i flussi. Al momento della congestione, il _decremento moltiplicativo_ dimezza le coordinate del punto, facendolo arretrare lungo una retta passante per l'origine; poiché il taglio è percentuale, il flusso che occupava più banda subisce una riduzione quantitativa assoluta molto più severa. La ripetizione ciclica di queste asimmetrie crea un andamento a **dente di sega** che dimostra visivamente e matematicamente come il sistema sia intrinsecamente costretto a convergere verso il punto di intersezione delle due rette, raggiungendo la perfetta ripartizione della risorsa.


## Capitolo 4


### Funzioni fondamentali del livello di rete
Nel precedente capitolo abbiamo visto come il livello di trasporto garantisca la comunicazione tra processi, appoggiandosi ai servizi sottostanti senza preoccuparsi di come vengano realizzati. Ora ci addentriamo nel livello di rete per capire esattamente come venga fornito questo servizio di comunicazione _host-to-host_.
###### Le Funzioni Fondamentali: Inoltro e Instradamento
Il ruolo principale del livello di rete è trasferire i pacchetti da un host a un altro. Per raggiungere questo obiettivo, il sistema fa affidamento su due funzioni ben distinte:
- **Inoltro (** _Forwarding_ **):** È l'azione locale e fulminea con cui un router, non appena riceve un pacchetto, lo trasferisce dalla sua interfaccia di ingresso a quella di uscita più appropriata. Poiché avviene su scale temporali minuscole (nell'ordine dei nanosecondi), questa funzione è tipicamente implementata direttamente in hardware e rappresenta il cuore del piano dei dati.
- **Instradamento (** _Routing_ **):** È il processo globale di rete che determina l'intero percorso che i pacchetti dovranno seguire nel loro viaggio dalla sorgente alla destinazione, avvalendosi di specifici algoritmi. Avvenendo su scale temporali più lunghe (nell'ordine dei secondi), l'instradamento è generalmente implementato in software nel piano di controllo.

Per collegare queste due funzioni, i router utilizzano un elemento chiave: la **tabella di inoltro** (_forwarding table_). Il router estrae i valori da uno o più campi dell'intestazione del pacchetto (come l'indirizzo di destinazione) e li utilizza come indice per consultare questa tabella, scoprendo così verso quale interfaccia di uscita dirigere il pacchetto, appena uscirà dal router attraverso i diversi algoritmi di instradamento questo arriverà a destinazione.

![[Pasted image 20260527181325.png|700]]

###### Data plane vs Control plane
La vastità degli argomenti che riguardano il Network Layer, ci spingono a suddividere la discussione tra data plane e control plane.
- **Data plane:** Il data plane é la parte del router o dello switch che si occupa del trasferimento effettivo dei pacchetti, inoltrandoli da un'interfaccia all'altra secondo i termini stabiliti del control plane. Opera in modo veloce e automatico, spesso in hardware. E quindi il responsabile del forwarding!
- **Control plane:** Il control plane è responsabile di prendere decisioni sul percorso dei pacchetti, costruendo e aggiornando le tabelle di routing seguendo dei protocolli dedicati. Gestisce la logica e la configurazione della rete. E chiaramente il responsabile del routing.

###### L'Approccio Software-Defined Networking (SDN)
Fino a poco tempo fa, le aziende implementavano l'algoritmo di instradamento internamente a ogni router: ogni dispositivo aveva una propria componente software che comunicava con gli altri router. Tuttavia, l'idea che le tabelle possano essere configurate dall'esterno ha aperto la strada a un approccio alternativo, noto come **Software-Defined Networking (SDN)**. In questo modello, la rete è "gestita da software": un controller remoto, fisicamente separato dai router (magari situato in un data center sicuro e ridondato), calcola e distribuisce le tabelle di inoltro a tutti i dispositivi. I router, a questo punto, si limitano a effettuare il mero inoltro fisico, scambiandosi messaggi con il controller remoto per ricevere le tabelle e inviare informazioni di instradamento.
![[Pasted image 20260527181347.png|700]]
###### I Servizi del Livello di Rete (Il modello Best-Effort)
Teoricamente, il livello di rete potrebbe offrire una vasta gamma di servizi: dalla consegna garantita (con o senza ritardo limitato), alla consegna ordinata, fino a una banda minima garantita (emulando un collegamento con un bit rate specifico senza perdita di pacchetti) o servizi di sicurezza (cifratura e decifratura dei datagrammi).

Nella realtà, il livello di rete di Internet mette a disposizione un solo servizio: il **servizio _best-effort_** ("col massimo impegno possibile"). Questo modello non offre alcuna garanzia. Non assicura che i pacchetti vengano consegnati, né che arrivino in ordine, né rispetta alcun limite di ritardo o di larghezza di banda. Paradossalmente, persino una rete che non consegna alcun pacchetto rispetterebbe la definizione di _best-effort_. Tuttavia, unito a un'adeguata larghezza di banda e a protocolli applicativi capaci di adattarsi, questo servizio essenziale si è dimostrato straordinariamente efficace per supportare le applicazioni moderne.

> **Nota Terminologica:** Nel networking, i termini _forwarding_ e _switching_ sono spesso usati come sinonimi. Un dispositivo generico che trasferisce pacchetti da un ingresso a un'uscita in base all'intestazione è detto **commutatore di pacchetto** (_packet switch_). Ne distinguiamo due tipi: i commutatori a livello di collegamento (livello 2), che si basano sui campi del frame, e i **router** (livello 3), che prendono decisioni basandosi sui campi a livello di rete.

### Router
###### Che cosa si trova all'interno di un router?
Esplorando l'architettura di un router, possiamo identificare quattro componenti principali. Le prime tre sono quasi sempre implementate in hardware specializzato, mentre l'ultima è tipicamente software:
![[Pasted image 20260527181402.png|700]]
1. **Porte di ingresso (**_Input port_**):** Gestiscono la terminazione elettrica del collegamento fisico e le funzioni a livello di collegamento. Svolgono inoltre la funzione cruciale di ricercare nella tabella di inoltro la porta di uscita corretta per il pacchetto. Se ricevono pacchetti di controllo (es. aggiornamenti di instradamento), li inoltrano al processore.
2. **Struttura di commutazione (**_Switching fabric_**):** È il cuore del router, una vera e propria rete interna che connette fisicamente le porte di ingresso a quelle di uscita.
3. **Porte di uscita (**_Output port_**):** Memorizzano i pacchetti in arrivo dalla struttura di commutazione e li trasmettono sul collegamento in uscita, applicando le funzioni dei livelli fisico e di collegamento.
4. **Processore di instradamento (**_Routing processor_**):** Esegue le funzioni del piano di controllo. In un router tradizionale gestisce i protocolli, le tabelle e i collegamenti; in un router SDN, dialoga con il controller remoto per ricevere le tabelle di inoltro e installarle sulle porte di ingresso.

###### L'Elaborazione alle Porte di Ingresso
L'elaborazione sulla porta di ingresso è vitale per le prestazioni del router. ![[Pasted image 20260527181419.png|700]]
Per evitare che il processore di instradamento diventi un collo di bottiglia, una copia della tabella di inoltro viene trasferita (tramite un bus separato) sulla memoria locale di ogni porta di ingresso. In questo modo, le decisioni di inoltro avvengono localmente. Poiché gli indirizzi IP sono a 32 bit (generando oltre 4 miliardi di combinazioni), i router non possono avere una riga per ogni singolo indirizzo. Piuttosto, raggruppano gli indirizzi in intervalli e usano una corrispondenza per prefisso.

Quando si verificano corrispondenze multiple per un singolo indirizzo, il router adotta la **regola di corrispondenza a prefisso più lungo** (_longest prefix match_): cerca la riga con il prefisso corrispondente migliore (più lungo) e instrada il pacchetto sull'interfaccia associata. Considerando che a tassi di trasmissione Gigabit questa ricerca va fatta in nanosecondi, si rende necessario l'uso di hardware dedicato per andare oltre la semplice ricerca lineare come la memoria chiamata *Ternary Content Addressing Memory* un tipo speciale di memoria ad alta velocità che può cercare all'interno del suo intero contenuto in un singolo ciclo di clock.

###### La struttura di commutazione
Una volta stabilita l'interfaccia di uscita, il pacchetto attraversa la struttura di commutazione. Esistono tre architetture principali:
- **Commutazione in memoria:** Tipica dei primi router (che erano essenzialmente calcolatori tradizionali). Il pacchetto veniva copiato dalla porta di ingresso nella memoria di sistema, elaborato dalla CPU e copiato nella porta di uscita. Il throughput massimo è limitato dalla banda della memoria: se la memoria permette $B$ operazioni al secondo, il throughput è inferiore a $B/2$. Limite principale: si può inoltrare un solo pacchetto alla volta.
- **Commutazione tramite bus:** Le porte di ingresso inviano il pacchetto direttamente alle porte di uscita attraverso un bus condiviso, aggiungendo un'etichetta interna temporanea per indicare la porta di destinazione. Poiché il bus è unico, se arrivano più pacchetti contemporaneamente, tutti tranne uno dovranno attendere.
- **Commutazione attraverso rete di interconnessione**: usa una rete di interconnessione pit sofisticata, con una matrice di commutazione (crossbar switch): consiste in $2n$ bus che collegano $n$ porte di ingresso a $n$ porte d'uscita. Ogni bus verticale interseca tutti i bus orizzontali a un punto d'incrocio che può essere aperto o chiuso dal controller della struttura di commutazione in qualsiasi momento. Quando un pacchetto che entra dalla porta A deve essere inoltrato alla porta d'uscita Y, viene chiuso l'incrocio tra i bus A—Y. Analogamente, questo avviene per l'entrata B e l'uscita X. Quando sono coinvolte porte d'uscita differenti, i pacchetti possono essere trasferiti in parallelo, altrimenti si accoderanno alla porta d'output. ![[Pasted image 20260529162931.png|700]]
###### Accodamento (_Queuing_) e Gestione della Memoria
Le code di pacchetti si formano inevitabilmente quando il tasso di arrivo del traffico supera temporaneamente la velocità con cui il router riesce a smaltirlo. Se i buffer si riempiono completamente, i pacchetti in eccesso vengono persi. Questo fenomeno può verificarsi in due punti nevralgici:

![[Pasted image 20260527181450.png|700]]

1. **Accodamento alle porte di ingresso:** Avviene se la struttura di commutazione non è abbastanza veloce da trasferire senza ritardo tutti i pacchetti in arrivo.
    - In questo scenario può verificarsi il **blocco in testa alla coda** (_Head-of-Line blocking_, **HOL**): un pacchetto nella coda di ingresso deve attendere perché è bloccato da un pacchetto davanti a lui che sta aspettando che si liberi una porta di uscita contesa, anche se la destinazione del nostro pacchetto bloccato sarebbe in realtà libera.![[Pasted image 20260527181507.png|500]]
2. **Accodamento alle porte di uscita:** Anche se la struttura di commutazione è velocissima, potrebbe trasferire simultaneamente molteplici pacchetti verso la medesima porta di uscita. Poiché la porta può trasmettere un solo pacchetto per volta sul cavo fisico, i pacchetti si accodano. ![[Pasted image 20260527181524.png|500]]
Quando la memoria del buffer in uscita si esaurisce, il router deve prendere delle decisioni. Può semplicemente scartare l'ultimo arrivato (politica **drop-tail**) o applicare algoritmi di **gestione attiva della coda (** _Active Queue Management_, **AQM**). Un celebre algoritmo AQM è il **RED** (_Random Early Detection_), che inizia a scartare o marcare pacchetti ancor prima che il buffer sia pieno, in modo da inviare precocemente un segnale di congestione al mittente.

**Ma quanta memoria di buffer è necessaria?**
Per anni, la regola empirica affermava che la dimensione del buffer ($B$) dovesse eguagliare il tempo medio di round-trip ($RTT$) moltiplicato per la capacità del link ($C$):
$$B = RTT \cdot C$$
Oggi, con la presenza di un vasto numero di flussi TCP indipendenti ($N$), gli studi suggeriscono che la quantità di buffer necessaria segua una proporzione differente $$B = RTT \times C/\sqrt{N}$$
Va inoltre considerato che buffer più grandi assorbono meglio le fluttuazioni, ma introducono ritardi di accodamento molto maggiori, penalizzando il traffico in tempo reale (come il gaming o le videoconferenze) e rendendo il protocollo TCP molto più lento a reagire alla congestione.

###### Packet Discarding policy
**Tail drop**: Quando la coda è piena, i pacchetti in arrivo vengono scartati a priori, senza considerare priorità o tipologia del traffico. Droppare pacchetti in questo modo potrebbe causare burst di drop.
**Priority queueing**: Il buffer è diviso in più code, ognuna con priorità diversa. I pacchetti vengono etichettati con un livello di priorità (o può essere stabilita dal router). In questo modo, i pacchetti ad alta priorità non saranno scartati, quando sono presenti in coda altri pacchetti a priorità più bassa.

###### Schedulazione dei Pacchetti
Quando più pacchetti sono in attesa su una porta di uscita, uno **schedulatore di pacchetti** deve decidere in quale ordine trasmetterli. Generalmente si adotta una modalità _conservativa_: il collegamento non resta mai inattivo se c'è almeno un pacchetto in coda. Esistono diverse politiche di schedulazione:
- **First-In-First-Out (FIFO / FCFS):** Il modello più intuitivo. I pacchetti vengono trasmessi nell'esatto ordine in cui sono arrivati. Se la coda è piena, si applicano le politiche di scarto discusse precedentemente.![[Pasted image 20260527181644.png|700]]
- **Code con priorità (** _Priority Queuing_ **):** I pacchetti vengono suddivisi in classi di priorità (ad esempio, il traffico VoIP o i dati di gestione di rete hanno priorità alta rispetto a una semplice email). Lo schedulatore trasmette sempre i pacchetti della classe a priorità maggiore; a parità di priorità, agisce come un FIFO. Se configurato _senza prelazione_, la trasmissione di un pacchetto (anche a bassa priorità) non viene mai interrotta a metà se ne arriva uno ad alta priorità. ![[Pasted image 20260527181718.png|700]]
- **Round Robin:** I pacchetti sono divisi in classi, ma senza una rigida priorità assoluta. Lo schedulatore si alterna ciclicamente tra le classi (es. invia un pacchetto della classe 1, poi uno della classe 2, e ricomincia). Se una coda è vuota, passa immediatamente alla successiva. ![[Pasted image 20260527181738.png|700]]
- **Accodamento equo ponderato (** _Weighted Fair Queuing_, **WFQ):** È una forma generalizzata e avanzata del Round Robin. I pacchetti sono classificati in code distinte e serviti in modo ciclico e conservativo, ma in modo differenziato. A ciascuna classe $i$ viene assegnato un peso $w_i$. Questo sistema garantisce matematicamente che ogni classe riceva una frazione di servizio pari a: $$\frac{w_i}{\sum w_j}$$Di conseguenza, su un collegamento con capacità trasmissiva totale $R$, alla classe $i$ sarà garantito un rendimento minimo di: $$R \cdot \frac{w_i}{\sum w_j}$$_(dove il denominatore somma i pesi di tutte le classi che hanno pacchetti pronti da trasmettere)._
![[Pasted image 20260527181816.png|700]]

### Il Protocollo Internet (IP): IPv4, IPv6 e Indirizzamento

La trattazione del livello di rete nell'Internet di oggi si concentra su aspetti chiave governati dal celebre **Protocollo Internet (IP, _Internet Protocol_)**. Attualmente, nell'architettura di rete, sono in uso due versioni principali di questo protocollo: la versione 4 (IPv4) e la versione 6 (IPv6).
###### Formato dei datagrammi IPv4
![[Pasted image 20260529122033.png|500]]
Il pacchetto a livello di rete è noto come **datagramma**. L'intestazione di un datagramma IPv4 standard (escludendo le opzioni) occupa 20 byte. Di conseguenza, un datagramma non frammentato che trasporta un segmento TCP avrà complessivamente 40 byte di intestazione (20 byte per l'IP e 20 byte per il TCP), a cui si aggiunge il messaggio di livello di applicazione.

L'intestazione è composta da diversi campi fondamentali:
- **Numero di versione** (_version number_): Utilizza quattro bit per specificare la versione del protocollo IP. Consente al router la corretta interpretazione del datagramma, poiché versioni diverse hanno formati strutturali differenti.
- **Lunghezza dell'intestazione** (_header length_): Poiché un datagramma può contenere opzioni di lunghezza variabile, questo campo indica esattamente dove termina l'intestazione e dove iniziano i dati veri e propri.
- **Tipo di servizio** (_TOS, type of service_): Incluso per distinguere i vari tipi di datagrammi in base a esigenze specifiche di rete (ad esempio, traffico che richiede un basso ritardo, un alto throughput o una particolare affidabilità).
- **Lunghezza del datagramma** (_datagram length_): Indica la dimensione totale del pacchetto (intestazione più dati) misurata in byte.
- **Tempo di vita** (_TTL, time-to-live_): Un meccanismo di sicurezza per evitare che i pacchetti restino in circolazione all'infinito nella rete a causa di errori di instradamento. Il suo valore viene decrementato di un'unità ogni volta che viene elaborato da un router; quando raggiunge lo zero, il pacchetto viene scartato.
- **Protocollo:** Rappresenta l'anello di congiunzione tra il livello di rete e quello di trasporto. Indica a quale specifico protocollo di livello superiore (es. 6 per TCP, 17 per UDP) devono essere consegnati i dati una volta raggiunta la destinazione.
- **Checksum dell'intestazione** (_header checksum_): Consente ai router di rilevare la corruzione dei dati sui bit ricevuti. È calcolato trattando ogni coppia di byte dell'intestazione come numeri, sommandoli e facendone il complemento a 1 (noto come **checksum Internet**). Riguarda _esclusivamente_ l'intestazione e non i dati, poiché i protocolli IP e TCP/UDP non appartengono necessariamente alla stessa pila e un doppio controllo totale sarebbe troppo oneroso per i router.
- **Indirizzi IP sorgente e destinazione:** Indicano rispettivamente l'host di partenza e quello di arrivo (quest'ultimo spesso ricavato tramite una risoluzione DNS).
- **Opzioni** (_options_): Campo concepito per un utilizzo sporadico ed eventuali estensioni future dell'intestazione.
- **Dati** (_payload_):** Il "carico utile" del pacchetto. Nella maggior parte dei casi contiene il segmento di trasporto da consegnare, ma può trasportare anche altri messaggi di gestione (come i pacchetti ICMP).

Alcuni campi che non abbiamo ancora affrontato, sono quelli relativi alla frammentazione. Quando un datagramma IP viene frammentato in più datagrammi IP più piccoli, queste informazioni permettono la ricostruzione del frammento originale a destinazione. 
- **ID:** 16 bit, identificano un insieme di pacchetti IP che (presumibilmente) ricostruiranno un pacchetto originale.
- **Flags:** 3 bit, 2 usati. I flags sono:
    - $\text{DF} = \text{Don't Fragment} = 1$: "Non frammentare mai. Al massimo, scarta."
    - $\text{MF} = \text{More Fragments} = 1$: "Questo non è l'ultimo frammento".
- **Offset:** 13 bit, indica dove inizia il frammento rispetto all'inizio del pacchetto originale, espresso in unità da 8 bit. Permette di ricostruire in maniera opportuna i pacchetti frammentati.

Questo compito non spetta solitamente ai router, i quali ricordiamo occuparsi principalmente di forwarding. Una corruzione dei dati di frammentazione può avere gravi conseguenze in fase di ricostruzione.
- **Offset alterato** - il ricongiungimento dei pezzi non può essere eseguito correttamente.
- **ID alterato** - un frammento potrebbe cambiare pacchetto di appartenenza
- **MF=1 $\rightarrow$ MF=0** - un frammento che non è l'ultimo potrebbe essere considerato l'ultimo.

> [!EXAMPLE] Esempio di frammentazione
> Dato un pacchetto con $4000\text{ byte}$ e un router con MTU di $1500\text{ byte}$ (come Ethernet).
> 
> - Se il frammento arriva con il flag $\text{DF} = 1$, viene scartato
>     
> - Con $\text{DF} = 0$ si procede alla frammentazione.
>     
> 
> Vediamo come procederebbe la frammentazione:
> 
> 1. Il primo frammento viene mandato con $\text{MF} = 1$ con offset a $0$. Il segmento mandato è di $1480\text{ byte}$, in quanto $20\text{ byte}$ saranno occupati dall'header IP. $4000 - 1480 = 2520\text{ byte}$ da mandare rimanenti.
>     
> 2. Il secondo frammento viene mandato con $\text{MF} = 1$ con offset a $\frac{1480}{8} = 185$. $2520 - 1480 = 1040\text{ byte}$ da mandare rimanenti.
>     
> 3. Il terzo frammento viene mandato con $\text{MF} = 0$ ($1040 - 1480 < 0$) con offset a $\frac{1480 + 1480}{8} = 370$.

###### Indirizzamento IPv4
Il punto di giunzione fisico tra un dispositivo (host o router) e il collegamento di rete viene definito **interfaccia**(interface).
- **Host:** dispongono generalmente di una sola interfaccia di rete.
- **Router:** devono connettersi a più collegamenti per poter inoltrare i datagrammi, pertanto possiedono necessariamente due o più interfacce.

> [!TIP] Regola chiave
> Poiché il protocollo IP richiede che ogni interfaccia abbia un identificativo univoco globale, **l'indirizzo IP è associato alla singola interfaccia** e non al dispositivo in sé.

L'indirizzo IPv4 ha le seguenti caratteristiche: 
- **Lunghezza:** 32 bit (4 byte), per un totale di circa 4 miliardi di indirizzi possibili.
- **Notazione:** **Decimale puntata**, in cui ciascun byte viene espresso in forma decimale (da 0 a 255) e separato da un punto (es. `193.32.216.9`).
- **Assegnazione:** Non avviene in modo casuale, ma è determinata dalla struttura della rete a cui il dispositivo è connesso.

Una **sottorete** (o rete IP) è una rete formata da interfacce di host e router interconnesse direttamente tra loro (ad esempio tramite uno switch Ethernet) senza l'interposizione di un router.
- **Identificazione topologica:** Per determinare il numero di sottoreti, si possono idealmente separare le interfacce dai nodi (host e router) creando delle "isole" isolate. Ognuna di queste rappresenta una sottorete.
- **Collegamenti punto-a-punto:** Anche i collegamenti diretti che uniscono due router costituiscono una sottorete a sé stante.
- **Maschera di sottorete (_subnet mask_):** È una notazione (come `/24`) che specifica quanti dei bit più a sinistra dell'indirizzo identificano la rete. Ad esempio, in `223.1.1.0/24`, i primi 24 bit definiscono la sottorete, lasciando i restanti 8 bit per gli host.

![[Pasted image 20260529122139.png|700]]

L'attuale strategia di allocazione globale degli indirizzi è il **CIDR**(*Classless Interdomain Routing*), che supera la rigida divisione in classi e definisce l'indirizzamento nella forma `a.b.c.d/x`. In questa notazione, l'indirizzo viene suddiviso in due parti:
- **Prefisso di rete (`x` bit più a sinistra):** È l'identificativo comune a tutti i dispositivi di una determinata organizzazione. I router esterni considerano solo questo prefisso per l'instradamento, consentendo l'aggregazione delle rotte e riducendo le dimensioni delle tabelle di routing globali.
- **Bit di Host (`32-x` bit rimanenti):** Sono utilizzati all'interno dell'organizzazione per distinguere e indirizzare le singole interfacce dei dispositivi locali.

###### Classificazione degli indirizzi IP
Prima del CIDR, si utilizzava il **classful addressing**, uno schema in cui la parte di rete veniva suddivisa in classi:

![[Pasted image 20260529164546.png|700]]

Questo approccio fu abbandonato per via del rapido esaurimento degli indirizzi, causato dallo scarso utilizzo dello spazio assegnato: una classe C poteva ospitare solo 254 host (troppo pochi per molte aziende), mentre la classe B ne offriva oltre 65.000, risultando enormemente sovradimensionata per organizzazioni di medie dimensioni (es. un'azienda con 2000 host sprecava migliaia di indirizzi assegnati).

###### Indirizzi IP speciali
Questi indirizzi sono riservati a delle funzioni specifiche.
- **`0.0.0.0`** - _This Host_, usato su un host il cui indirizzo non è ancora stato specificato (ma solo in IPv4, non in IPv6, che usa un indirizzo IP basato sul MAC Address. Guarda EUI-64, pagina 81).
- **`255.255.255.255`** - Broadcast relativo alla propria subnet.
- **`127.0.0.0` – `127.255.255.255`** - _Localhost_, riferimento a se stesso.
- **`10.0.0.0` – `10.255.255.255`** - Private IP.
- **`169.254.0.0` – `169.254.255.255`** - _Automatic Private IP Addressing_ (APIPA), usate per risolvere problemi relativi al DHCP.

###### Come vengono usate le maschere di rete
La maschera di rete, indicata in notazione CIDR con `/x`, indica che i primi $x$ bit a sinistra indicano la (sotto)rete. Nella maschera di rete, i primi $x$ bit a sinistra saranno 1, mentre gli altri $32 - x$ saranno 0.    
- **Esempi di maschere di rete:**
    - Con **/19** la maschera sarà: `255.255.224.0` — `11111111111111111110000000000000`
    - Con **/24** la maschera sarà: `255.255.255.0` — `11111111111111111111111100000000`
    - Con **/16** la maschera sarà: `255.255.0.0` — `11111111111111110000000000000000`
![[Pasted image 20260529165916.png|700]]
La maschera di rete può essere usata per estrapolare e confrontare l’indirizzo della sottorete di appartenenza di due host.

###### Elementi del livello collegamento e ARP
Studiando il livello di collegamento, scopriremo che gli host e i router hanno un indirizzo sia a livello di rete (IP) che a livello di collegamento (indirizzo MAC). Il protocollo ARP (_address resolution protocol_) permette ai nodi l’associazione:

$$\text{Indirizzo IP} \rightarrow \text{Indirizzo MAC}$$

**Cos’è un indirizzo MAC?**
Un indirizzo _Media Access Control_ è un codice a 6 byte che identifica univocamente una scheda di rete. Gli indirizzi MAC sono univoci: la IEEE si occupa di distribuire proprio questi indirizzi MAC alle varie aziende.
- I primi 3 byte sono stabiliti dall’IEEE (viene scelta quindi una combinazione di bit su $2^{24}$).
- Gli ultimi tre vengono dati univocamente ad ogni dispositivo prodotto dall’azienda stessa (sempre $2^{24} = 16.777.216$).

**Il protocollo ARP**
Sta per _Address Resolution Protocol_, e traduce gli indirizzi IP in MAC address. Traduce gli indirizzi IP di dispositivi situati nella stessa sottorete. Convenzionalmente, gli indirizzi IP sono scritti in decimale, gli indirizzi MAC in esadecimale. Di seguito in dettaglio come funziona questo protocollo, ogni nodo contiene una tabella ARP i cui record contengono tre valori: `Indirizzo IP` - `Indirizzo MAC` - `Time To Live` Il _time-to-live_ specifica tra quanto tempo quel determinato record dovrà essere eliminato dalla tabella. Un tempo tipico sono 20 minuti.

**Caso 1 - Invio sulla stessa (sotto)rete**
1. Se un datagramma deve essere mandato da un host $A$ a un host $B$ nella stessa sottorete, $A$ dovrà conoscere l’indirizzo MAC di quel dispositivo.
2. Se l’indirizzo MAC è già presente nella tabella ARP del nodo, questo manderà il datagramma senza ulteriori passaggi.
3. Altrimenti, manderà una cosiddetta "richiesta ARP" contenuta in un pacchetto ARP mandato all’indirizzo broadcast della rete `FF-FF-FF-FF-FF-FF`.
4. Il pacchetto conterrà sia l’indirizzo IP e MAC del mittente, che l’indirizzo IP del destinatario.
5. La richiesta broadcast verrà mandata a tutte le schede di rete della sottorete. La risposta ARP verrà mandata in modalità non-broadcast dal dispositivo con indirizzo IP uguale a quello della richiesta, verso il richiedente. La risposta ARP conterrà al suo interno l’indirizzo MAC del ricevente della richiesta, e la tabella ARP verrà aggiornata.

**Caso 2 - Invio su (sotto)rete diversa**
Alice desidera mandare un messaggio a Bob, collegato ad una sottorete diversa.
1. Alice manda il datagramma alla sua scheda di rete. Dovrà indicare l’indirizzo MAC dell’interfaccia del router a cui è collegato. Se l’indirizzo MAC è già presente nella tabella ARP di Alice, questo manderà il datagramma al router.
2. Altrimenti, userà il protocollo ARP per ottenere l’indirizzo MAC. Manderà una richiesta ARP all’indirizzo broadcast della rete `FF-FF-FF-FF-FF-FF`, contenente l’indirizzo IP del router. Il router, riconoscendo il proprio indirizzo, risponderà con una ARP reply condividendo ad Alice il proprio indirizzo MAC. Alice memorizzerà il nuovo indirizzo MAC appena scoperto nella propria tabella ARP, e manda il proprio frame. ![[Pasted image 20260529170807.png|700]]
3. Il router confronta l’IP del pacchetto con la propria tabella di inoltro. Sa che il pacchetto deve essere inoltrato all’interfaccia 2, ma non conosce l’indirizzo MAC del destinatario Bob. ![[Pasted image 20260529170827.png|700]]
4. Il router manda la richiesta ARP, lo switch la manda in broadcast a tutti i dispositivi connessi. Bob riconosce l’indirizzo IP della richiesta ARP, e manda una risposta ARP. Il router riceverà l’indirizzo MAC di Bob, lo conserverà nella propria ARP table assieme al suo IP. ![[Pasted image 20260529170841.png|700]]
5. Il router avrà tutto il necessario per inoltare il pacchetto a Bob, ed è ciò che farà.![[Pasted image 20260529170918.png|700]]
Notiamo che, dopo aver ottenuto tutti gli indirizzi necessari tramite il protocollo ARP, per tutta la durata delle _entries_ nella tabella ARP, l’inoltro sarà presumibilmente molto più veloce.

###### Come ottenere un indirizzo IP: ICANN e DHCP
![[Pasted image 20260529171207.png|700]]
Per ottenere un blocco di indirizzi da usare nella propria sottorete, un amministratore di solito contatta il proprio ISP. Quest'ultimo, a sua volta, attinge a blocchi di indirizzi gestiti dall'**ICANN** (_Internet Corporation for Assigned Names and Numbers_), l'autorità globale senza scopo di lucro responsabile della gestione ultima dello spazio IP e dei server root DNS.

All'interno della singola rete, gli indirizzi dei dispositivi possono essere configurati manualmente, ma più spesso si utilizza il **DHCP** (_Dynamic Host Configuration Protocol_). Noto anche come protocollo _plug-and-play_ o _zero-conf_, il DHCP automatizza la connessione degli host fornendo loro un indirizzo temporaneo (o persistente) e altre informazioni di configurazione. Se in una sottorete non è presente un server DHCP, viene utilizzato un **agente di relay DHCP** (solitamente un router) per inoltrare le richieste al server DHCP di un'altra rete.

Essendo un protocollo client-server, l'interazione per un host appena connesso si articola in quattro fasi ben distinte:
- **Individuazione** (_DHCP discover_): Il client DHCP, non conoscendo ancora la sua rete, invia in broadcast (verso l'indirizzo 255.255.255.255, identificandosi come 0.0.0.0) un pacchetto UDP sulla porta 67.
- **Offerta** (_DHCP offer_): I server DHCP presenti rispondono in broadcast proponendo un indirizzo IP, la maschera di sottorete e la durata della concessione (_lease time_).
- **Richiesta** (_DHCP request_): Il client sceglie una delle offerte disponibili (ci possono essere più server DHCP e quindi più proposte) e risponde riportando i parametri di configurazione scelti.
- **Conferma** (_DHCP ACK_): Il server conferma definitivamente i parametri richiesti, permettendo al client di utilizzare l'IP per tutta la durata della concessione (che può essere successivamente rinnovata).

Il DHCP presenta tuttavia un limite strutturale per i dispositivi mobili: spostandosi da una sottorete all'altra, il nodo riceve necessariamente un nuovo indirizzo IP, causando la caduta delle connessioni TCP in corso con le applicazioni remote.

###### NAT (Network Address Translation)
![[Pasted image 20260529122217.png|700]]
La proliferazione di smartphone, tablet e smart TV nelle reti domestiche e SOHO ha reso insostenibile l'assegnazione di un indirizzo IP pubblico per ciascun dispositivo. Per ottimizzare le risorse, si utilizzano gli **indirizzi IP privati** (come la classe 10.0.0.0/8), che hanno valore solo localmente e sono invisibili all'Internet globale. La comunicazione con l'esterno è resa possibile dal **NAT (Network Address Translation)**: il router nasconde i dettagli della rete interna presentandosi al mondo con un unico IP pubblico (fornito dall'ISP), mentre sul lato interno gestisce un proprio server DHCP per assegnare gli IP privati. Grazie all'uso dei numeri di porta a 16 bit, questo meccanismo è incredibilmente efficiente e permette di supportare **oltre 60.000 connessioni simultanee** verso l'esterno usando un solo IP pubblico. Di seguito come funziona in dettaglio:
- **Mappatura in uscita (Outbound):** Quando un host interno (es. IP 10.0.0.1 sulla porta 3345) invia una richiesta, il router NAT la intercetta, sostituisce l'IP privato con il proprio IP pubblico e genera una nuova porta di origine (es. 5001), salvando l'associazione esatta nella sua _tabella di traduzione_.
- **Instradamento in entrata (Inbound):** Il server remoto risponde all'indirizzo pubblico del router sulla porta 5001. Ricevuto il pacchetto, il router consulta la tabella, traduce nuovamente l'indirizzo pubblico e la porta nei valori privati originari e inoltra la risposta all'host corretto.

Questo protocollo anche se molto utile e ampiamente utilizzato ha le seguenti problematiche
- **Violazione del principio end-to-end:** Teoricamente, i router (dispositivi di livello 3) dovrebbero limitarsi a elaborare gli IP e non toccare i dati dei livelli superiori. Il NAT viola questo principio perché legge e modifica attivamente i numeri di porta (che appartengono al livello di Trasporto, livello 4).
- **Problemi con il P2P:** Il NAT rende molto difficili le connessioni Peer-to-Peer (e per le applicazioni che fungono da server) perché i dispositivi dietro un NAT non sono direttamente indirizzabili dall'esterno senza configurazioni specifiche (NAT traversal).
###### IPv6
![[Pasted image 20260529122235.png|700]]
Nei primi anni '90, a causa del rapido esaurimento dello spazio a 32 bit, l'IETF iniziò lo sviluppo di **IPv6**. Oltre all'esigenza primaria di disporre di uno spazio di indirizzi inesauribile (grazie a un **indirizzamento esteso a 128 bit**), il nuovo protocollo introduce una serie di innovazioni architettoniche.

L'**intestazione ottimizzata** di IPv6 è stata portata a una dimensione fissa di 40 byte. Un'altra novità cruciale è l'**etichettatura dei flussi**, che permette di marcare particolari pacchetti che richiedono una gestione speciale da parte del mittente.

Di seguito i campi dell'intestazione IPv6:
- **Versione (4 bit):** Identifica la versione del protocollo IP in uso (IPv6).
- **Classe di traffico (8 bit):** Gestisce la priorità dei pacchetti e la qualità del servizio (QoS), ereditando la funzione del vecchio campo _TOS (Type of Service)_ di IPv4.
- **Etichetta di flusso (20 bit):** Serve a etichettare i pacchetti che appartengono allo stesso flusso di comunicazione, aiutando i router a gestirli in modo uniforme e sequenziale.
- **Lunghezza del payload (16 bit):** Indica la dimensione espressa in byte di tutto ciò che segue l'intestazione fissa (inclusi i dati utili ed eventuali estensioni).
- **Indirizzi sorgente e destinazione (128 bit ciascuno):** Le coordinate complete del mittente e del destinatario del pacchetto, notevolmente ampliate rispetto a IPv4.
- **Intestazione successiva (Next Header):** Un campo cruciale che indica il protocollo del livello superiore a cui consegnare i dati (come TCP o UDP) oppure segnala la presenza di opzioni e intestazioni aggiuntive.
- **Limite di hop (Hop Limit):** Sostituisce il vecchio campo _TTL (Time to Live)_; viene ridotto di una unità da ogni router attraversato e, se raggiunge lo zero, determina lo scarto del pacchetto per evitare loop infiniti nella rete.

Mettendo a confronto IPv6 con IPv4, emergono alcune importanti eliminazioni:
- **Frammentazione e riassemblaggio intermedi:** Questa operazione non può più essere svolta dai router lungo il percorso, ma unicamente dall'host sorgente e destinazione. Se un router IPv6 riceve un pacchetto troppo grande, lo elimina semplicemente e invia al mittente un errore ICMP ("Pacchetto troppo grande").
- **Checksum dell'intestazione:** È stato rimosso per snellire l'elaborazione, considerandolo ridondante visto che il controllo viene già effettuato dai livelli di Trasporto (TCP/UDP) e di Collegamento (Ethernet).
- **Opzioni:** Non appesantiscono più l'intestazione standard, ma vengono richiamate tramite il campo "Intestazione successiva", permettendo di alleggerire il pacchetto base.
###### Vantaggi di IPv6
Sintetizziamo in breve gli aspetti _game changer_ del protocollo IPv6:
- **Indirizzamento esteso:** Aumenta la dimensione degli indirizzi. Con $2^{128}$ indirizzi possibili, lo spazio disponibile è praticamente inesauribile.
- **Unicast, Multicast e Anycast:** Supporta indirizzi unicast, multicast ed anycast. Gli indirizzi multicast e anycast identificano insiemi di interfacce. Mandando un pacchetto a un indirizzo multicast, questo verrà inviato a tutte le interfacce del gruppo. Mandando un pacchetto a un indirizzo anycast, questo verrà recapitato all'interfaccia più vicina (o a una qualunque).
- **Etichettatura dei flussi:** Etichettando in un determinato modo i pacchetti di un determinato flusso, diventa possibile dare priorità e offrire delle garanzie di servizio migliori rispetto a determinati protocolli dell'application layer.
- **Rimossa frammentazione ai router intermedi:** Solleva i router di transito dal carico di frammentare i pacchetti, ottimizzando la velocità di instradamento.
- **Sfoltiti gli header:** La struttura dell'intestazione è stata semplificata e resa fissa per velocizzare l'elaborazione da parte dell'hardware di rete.

###### EUI-64 - Extended Unique Identifier
L'assegnazione di un indirizzo IPv6 a un'interfaccia di rete avviene solitamente tramite DHCP. Tuttavia, in alternativa, l'identificativo dell'interfaccia può essere derivato automaticamente a partire dal proprio **MAC address a 48 bit** seguendo il metodo **EUI-64**. Questa procedura è particolarmente **utile nelle configurazioni senza DHCPv6**.
I passaggi per la generazione sono i seguenti:
1. **Lettura del MAC:** Si prende l'indirizzo MAC a 48 bit del dispositivo.
2. **Divisione:** Lo si divide esattamente in due metà (da 24 bit ciascuna).
3. **Inserimento centrale:** Viene inserito il valore esadecimale **`FF:FE`** in mezzo alle due metà per raggiungere i 64 bit richiesti. _(Nota: i sistemi Windows moderni inseriscono invece delle cifre casuali per motivi di privacy)._
4. **Modifica del settimo bit:** Si cambia il settimo bit (bit _Universal/Local_) del primo byte: viene impostato a `1` se l'indirizzo è amministrato localmente, oppure a `0` se è globalmente unico.

> **Nota:** Gli indirizzi generati con questa modalità (di tipo _link-local_) sono validi e funzionano esclusivamente all'interno della stessa rete locale (LAN).

###### Neighbour Discovery Protocol (Il nuovo ARP!)
Il **NDP (Neighbour Discovery Protocol)** è il protocollo che sostituisce e migliora le funzioni del vecchio ARP in IPv6. Rispetto ad ARP, non lavora direttamente sul livello data-link ma si appoggia a **ICMPv6**, sfruttando principalmente due tipi di messaggi:
- **Neighbour Solicitation (NS):** È l'equivalente della _ARP request_. Viene utilizzato per richiedere il MAC address di un dispositivo a partire dal suo indirizzo IPv6.
- **Neighbour Advertisement (NA):** È l'equivalente della _ARP reply_. Può essere inviato anche in modalità spontanea (senza una richiesta NS preventiva) per comunicare tempestivamente ai dispositivi della rete un eventuale cambio di MAC address.
Oltre alla risoluzione degli indirizzi, questo protocollo permette di **autoconfigurare gli host** e supporta i messaggi di **Router Advertisement**, fondamentali per consentire ai dispositivi di scoprire i router presenti nella rete.
###### Passaggio da IPv4 a IPv6 e Tunneling
L’argomento della transizione da IPv4 a IPv6 è estremamente **delicato**: l’intera infrastruttura globale di Internet è stata costruita su IPv4, e in pochi alle origini avrebbero potuto prevedere un tale successo e una simile scala.

Sebbene IPv6 sia il sostituto definitivo, il processo di transizione si sta rivelando lento e durerà ancora molti anni. Non potrà mai essere un passaggio rapido "a tavolino" come quello che avvenne agli albori di Internet per passare dal protocollo NCP (il protocollo di trasporto della rete ARPANET) al TCP. Questo perché i nuovi sistemi IPv6 sono retrocompatibili e capaci di elaborare datagrammi IPv4, ma **le macchine IPv4 non sanno gestire in alcun modo i datagrammi IPv6**.

Poiché è impraticabile spegnere simultaneamente l'intera infrastruttura mondiale per aggiornarla, si è resa necessaria una coesistenza graduale basata su due approcci principali: **Dual Stack** e **Tunneling**.

**Dual Stack**: I dispositivi (host e router) gestiscono **entrambi i protocolli simultaneamente**. Le applicazioni scelgono quale usare in base alla connessione, dando la precedenza a IPv6. Aumenta la complessità del nodo a causa del doppio IP, ma è la soluzione più stabile.

**Tunneling**: Si usa quando due nodi IPv6 sono separati da una rete intermedia che supporta solo IPv4.
- **Incapsulamento:** Il datagramma IPv6 viene nascosto all'interno del payload di un normale pacchetto IPv4.
- **Transito:** I router intermedi IPv4 instradano il pacchetto come traffico standard, ignorando il contenuto IPv6.
- **Estrazione:** All'uscita dal tunnel, il router ricevente riconosce il **protocollo 41** nell'header IPv4, estrae il datagramma IPv6 originale e lo consegna.

> **Nota Storica:** La penetrazione a macchia d'olio ma lenta di IPv6 lascia un'importante lezione ingegneristica: è enormemente difficile variare o aggiornare i protocolli fondamentali del livello di rete (network layer) una volta che l'infrastruttura globale si è consolidata. Questo spiega perché molti protocolli teoricamente rivoluzionari abbiano spesso ottenuto un successo commerciale modesto.

### ICMP
###### ICMP - Internet Control Message Protocol
È un protocollo utilizzato per la trasmissione di informazioni di controllo e di errore all'interno della rete. Viene incapsulato direttamente nei pacchetti IP ed è alla base di strumenti di diagnostica molto comuni come **ping** e **traceroute**.

ICMP esiste sia per IPv4 che per IPv6; in quest'ultimo trova un'importante applicazione nella gestione dei messaggi del _Neighbor Discovery Protocol_ (NDP).

L'header ICMP include i seguenti campi principali:
- **Tipo (8 bit):** Specifica la tipologia e il formato generale del messaggio.
- **Codice (8 bit):** Identifica nel dettaglio il sotto-tipo di messaggio all'interno di una determinata categoria.
- **Checksum (16 bit):** Utilizzato per il controllo dell'integrità del messaggio.
- **Dati:** Un campo a lunghezza variabile che cambia in base ai valori specificati nei campi "tipo" e "codice".

### Firewall e DMZ
###### Firewall
I firewall sono strutture software, hardware o ibride il cui compito principale è **bloccare e/o filtrare il traffico malevolo** o effettuare un reindirizzamento dei pacchetti per ulteriori elaborazioni di sicurezza.
Per gestire le minacce che attraversano la rete, i firewall applicano delle regole di filtraggio intelligenti basate su diversi criteri:
- Indirizzi IP e porte (sia di origine sia di destinazione).
- Protocolli di trasporto o di rete (TCP, UDP, ICMP, ecc.).
- Stato della connessione (per verificare se il traffico appartiene a una sessione già autorizzata).
- **Contenuto del pacchetto**, nel caso di firewall avanzati dotati di ispezione profonda (_Deep Packet Inspection_ o DPI).

> I firewall possono operare a livello di rete, di trasporto e/o a livello applicativo, a seconda delle specifiche esigenze di sicurezza e controllo.

###### DMZ - Demilitarized Zone
Tra la rete locale (LAN) e la rete esterna (WAN/Internet), solitamente si crea una terza sottorete isolata chiamata **Demilitarized Zone (DMZ)**. Questa zona ospita i sistemi che devono essere raggiungibili dall'esterno (come i server web o email), ma che rimangono separati e protetti rispetto alla rete interna sensibile, fungendo da vera e propria "facciata". È proprio in corrispondenza della DMZ e dei confini di rete che il firewall applica le sue azioni principali sui pacchetti:
- **Allow:** Permette al pacchetto di transitare e raggiungere la destinazione.
- **Deny:** Blocca il pacchetto e invia una notifica di rifiuto al mittente.
- **Drop:** Scarta il pacchetto istantaneamente senza inviare alcuna notifica al mittente, una tecnica utile per risparmiare banda e nascondere la presenza dell'host.
Infine, un firewall può anche implementare le funzionalità di **NAT**, mascherando gli indirizzi IP privati della rete interna quando questa comunica con l'esterno.

## Capitolo 5


### Piano di controllo e algoritmi di instradamento

###### Il piano di controllo del livello di rete
Lo studio del livello di rete viene completato analizzando il **piano di controllo**, responsabile del modo in cui le **tabelle di inoltro** e le **tabelle dei flussi** vengono calcolate, mantenute e installate nei router. Per realizzare queste funzioni sono possibili due approcci principali: il **controllo per router** e il **controllo logicamente centralizzato**.

###### Controllo per router 
l’algoritmo di instradamento viene eseguito separatamente su ogni router. All'interno di ciascun dispositivo vengono quindi svolte sia le funzioni di inoltro, appartenenti al **piano dei dati**, sia quelle di instradamento, appartenenti al **piano di controllo**.

![[Pasted image 20260605162434.png|700]]
###### Controllo logicamente centralizzato
un controller logicamente centralizzato calcola le tabelle di inoltro e le distribuisce ai router che devono utilizzarle. ![[Pasted image 20260605162514.png|700]]
Il controller interagisce con l’**agente di controllo**, indicato con **CA — Control Agent**, presente in ogni router. L’interazione avviene tramite un protocollo che consente di configurare e gestire la tabella dei flussi del router. Tipicamente il CA dispone di funzionalità minime: comunica con il controller ed esegue le operazioni che quest’ultimo gli ordina.

A differenza degli algoritmi di instradamento eseguiti direttamente nei router, gli agenti di controllo non interagiscono direttamente tra loro e non partecipano attivamente all'elaborazione delle tabelle di inoltro.

Con l’espressione **controllo logicamente centralizzato** si indica un servizio di controllo dell’instradamento al quale si accede come se fosse un singolo punto centrale. Il servizio può tuttavia essere implementato mediante più server, in modo da garantire una maggiore resistenza ai guasti e una migliore scalabilità delle prestazioni.

###### Scopo degli algoritmi di instradamento
Gli **algoritmi di instradamento** hanno lo scopo di determinare i percorsi, o cammini, che collegano le sorgenti alle destinazioni attraverso una rete di router. Tipicamente si ricerca il percorso avente il costo minimo, anche se nella pratica assumono importanza anche problemi concreti, come l’applicazione delle **policy** di instradamento.

Indipendentemente dal fatto che il piano di controllo utilizzi un approccio per router oppure un approccio logicamente centralizzato, deve sempre essere definita una sequenza precisa di router che il pacchetto attraversa durante il viaggio dall’host sorgente all’host destinatario.

###### Rappresentazione della rete mediante un grafo
I problemi di instradamento possono essere formulati utilizzando un grafo.

**Grafo:** un grafo $G=(N,E)$ è costituito da un insieme $N$ di nodi e da un insieme $E$ di archi, ciascuno dei quali collega una coppia di nodi appartenenti a $N$.

Nel contesto dell’instradamento a livello di rete, i nodi rappresentano i **router**, che prendono decisioni sull’inoltro dei pacchetti, mentre gli archi rappresentano i collegamenti fisici tra i router.

A ogni arco $(x,y)$ è associato un costo, indicato con $c(x,y)$. Per gli scopi dell’analisi, i costi degli archi vengono considerati come dati, senza esaminare il modo in cui sono stati determinati. Il termine **metrica** viene spesso utilizzato per indicare il valore associato a un collegamento.

Se la coppia $(x,y)$ non appartiene all’insieme degli archi $E$, si pone $c(x,y)=+\infty$.

Vengono considerati grafi non orientati, cioè dotati di archi bidirezionali. Di conseguenza, l’arco $(x,y)$ coincide con l’arco $(y,x)$ e vale $c(x,y)=c(y,x)$.

Un nodo $y$ è detto **adiacente**, o **vicino**, a un nodo $x$ se $(x,y)$ è un arco appartenente a $E$.

**Percorso:** un percorso in un grafo $G=(N,E)$ è una sequenza di nodi $(x_1,x_2,\ldots,x_p)$ tale che ciascuna coppia consecutiva
$$  
(x_1,x_2),(x_2,x_3),\ldots,(x_{p-1},x_p) \text{ sia un arco appartenente a $E$. }
$$
Il costo del percorso è uguale alla somma dei costi di tutti gli archi che lo compongono:
$$  
c(x_1,x_2)+c(x_2,x_3)+\cdots+c(x_{p-1},x_p)  
$$
![[Pasted image 20260605162831.png|700]]

Tra due nodi qualsiasi $x$ e $y$ possono esistere più percorsi, ciascuno caratterizzato da un proprio costo. Uno o più di questi percorsi possono costituire un **percorso a costo minimo**, cioè un percorso che collega l’origine alla destinazione sostenendo il costo complessivo più basso.

Se tutti gli archi del grafo hanno lo stesso costo, il percorso a costo minimo coincide anche con il **percorso più breve**, ossia con quello che attraversa il minor numero di collegamenti tra la sorgente e la destinazione.

###### Classificazione degli algoritmi di instradamento
Gli algoritmi di instradamento possono essere classificati secondo diversi criteri. 
1. Una prima distinzione riguarda la disponibilità delle informazioni sulla rete e separa gli algoritmi **centralizzati** da quelli **decentralizzati**.
	- **Algoritmo di instradamento centralizzato:** calcola il percorso a costo minimo tra una sorgente e una destinazione utilizzando una conoscenza globale e completa della rete. L’algoritmo riceve in ingresso tutti i collegamenti esistenti tra i nodi e i relativi costi. Prima di eseguire il calcolo deve quindi ottenere tutte queste informazioni. Gli algoritmi che utilizzano informazioni globali sullo stato della rete sono spesso chiamati **LS - Link-State**, o algoritmi con stato del collegamento, poiché devono conoscere il costo di ogni collegamento della rete.
	- **Algoritmo di instradamento decentralizzato:** calcola il percorso a costo minimo in maniera distribuita e iterativa. Nessun nodo possiede informazioni complete sul costo di tutti i collegamenti della rete. Inizialmente ciascun nodo conosce soltanto i costi dei collegamenti direttamente incidenti su di esso. Attraverso un processo iterativo e lo scambio di informazioni con i nodi adiacenti, ogni nodo calcola gradualmente il percorso a costo minimo verso una destinazione o verso un insieme di destinazioni. L’algoritmo decentralizzato considerato è chiamato **DV - Distance-Vector**, o algoritmo con vettore delle distanze, perché ogni nodo elabora un vettore contenente le stime dei costi, o distanze, verso tutti gli altri nodi della rete.
2. Una seconda classificazione distingue gli algoritmi **statici** da quelli **dinamici**.
	- **Statici**: negli algoritmi di instradamento statici, i percorsi cambiano molto raramente e le modifiche sono spesso il risultato di un intervento umano, come la modifica manuale della tabella di inoltro di un router.
	- **Dinamici**: Gli algoritmi dinamici modificano invece gli instradamenti in risposta alle variazioni del volume di traffico o della topologia della rete. Possono essere eseguiti periodicamente oppure come conseguenza diretta di una modifica della topologia o del costo di un collegamento. Gli algoritmi dinamici rispondono meglio ai cambiamenti della rete.
3. Una terza classificazione si basa sulla sensibilità dell’algoritmo al carico della rete.
	- **Algoritmo sensibile al carico:** utilizza costi dei collegamenti che variano dinamicamente per riflettere il livello corrente di congestione. Se a un collegamento congestionato viene associato un costo elevato, l’algoritmo tende a evitare di utilizzarlo.
	- **Algoritmo insensibile al carico**: gli algoritmi di instradamento impiegati attualmente in Internet, tra cui **RIP**, **OSPF** e **BGP**, sono invece insensibili al carico, poiché il costo di un collegamento non riflette esplicitamente il suo livello attuale o recente di congestione.

### Instradamento Link-State
Nell'instradamento **LS - Link-State**, la topologia della rete e tutti i costi dei collegamenti sono noti e disponibili in ingresso all'algoritmo. Questa conoscenza viene ottenuta facendo inviare a ogni nodo dei pacchetti relativi allo stato dei propri collegamenti. Tali pacchetti vengono distribuiti a tutti gli altri nodi della rete e contengono l’identità e il costo dei collegamenti connessi al nodo mittente. Nella pratica, come nel caso del protocollo OSPF, la distribuzione viene spesso realizzata mediante un algoritmo di **link-state broadcast**. In questo modo tutti i nodi dispongono di una vista identica e completa della rete, e ciascun nodo che esegue l’algoritmo LS ottiene gli stessi risultati. L’algoritmo utilizzato per calcolare i percorsi nell'instradamento link-state è l’**algoritmo di Dijkstra**.
###### Algoritmo di Dijkstra

L’algoritmo di Dijkstra calcola i percorsi a costo minimo da un nodo origine $u$ a tutti gli altri nodi del grafo. Utilizza: 
- $D(v)$, stima corrente del costo da $u$ a $v$; 
- $p(v)$, predecessore di $v$ nel percorso conosciuto; 
- $N'$, insieme dei nodi per i quali il percorso minimo è definitivo.

**Pseudocodice**
```text
Algoritmo Dijkstra dal nodo origine u

1   Inizializzazione:
2       N’ = {u}
3       per tutti i nodi v
4           se v è adiacente a u
5               allora D(v) = c(u,v)
6           altrimenti D(v) = ∞

8   Ciclo
9       determina un w non in N’ tale che D(w) sia minimo
10      aggiungi w a N’
11      aggiorna D(v) per ciascun nodo v adiacente a w e non in N’:
12          D(v) = min {D(v), D(w) + c(w,v)}
13          /* il nuovo costo verso v è il vecchio costo verso v
14             oppure il costo del percorso minimo noto verso w più il
               costo da w a v */
15      ripeti in ciclo finché non si verifica che N’ = N
```

Inizialmente $N'$ contiene soltanto $u$. Per ogni nodo adiacente a $u$ si pone $D(v)=c(u,v)$ e $p(v)=u$; per gli altri nodi si pone $D(v)=+\infty$ e il predecessore rimane non definito.

A ogni iterazione viene scelto il nodo $w\notin N'$ con distanza $D(w)$ minima. Il suo percorso viene considerato definitivo e $w$ viene aggiunto a $N'$. Successivamente si esaminano i vicini $v$ di $w$ non ancora risolti: se $D(w)+c(w,v)<D(v)$, il percorso attraverso $w$ è migliore, quindi si aggiornano $D(v)=D(w)+c(w,v)$ e $p(v)=w$. In forma compatta, l’aggiornamento è $D(v)=\min{D(v),D(w)+c(w,v)}$.

Il ciclo termina quando $N'=N$. A quel punto, $D(v)$ contiene il costo minimo da $u$ a ogni nodo $v$, mentre i predecessori $p(v)$ permettono di ricostruire i relativi percorsi.

> [!EXAMPLE] Esempio applicazione dell'algoritmo di Dijkstra
> ![[Pasted image 20260605162831.png|700]]
> Considerando la rete rappresentata nella Figura 5.3, si possono calcolare i percorsi a costo minimo dal nodo $u$ verso tutte le destinazioni.
> 
> Durante l’inizializzazione, i costi dei percorsi conosciuti da $u$ ai nodi adiacenti $v$, $w$ e $x$ vengono posti rispettivamente a $2$, $5$ e $1$. Il costo verso $w$ è inizialmente uguale a $5$ perché questo è il costo del collegamento diretto da $u$ a $w$, anche se successivamente verrà individuato un percorso di costo inferiore. I costi verso $y$ e $z$ sono posti a $+\infty$, poiché questi nodi non sono adiacenti a $u$.
> 
> Nella prima iterazione vengono esaminati i nodi che non appartengono ancora a $N'$. Il nodo avente il costo minimo è $x$, con costo $1$, e viene quindi aggiunto all’insieme. Successivamente vengono aggiornati i costi dei nodi adiacenti a $x$.
> 
> Il costo del percorso verso $v$ non cambia. Il costo verso $w$, che al termine dell’inizializzazione era uguale a $5$, diventa $4$ passando attraverso $x$. Viene pertanto selezionato il percorso di costo inferiore e il predecessore di $w$ lungo il percorso minimo da $u$ diventa $x$. Analogamente, il costo verso $y$ attraverso $x$ viene calcolato come $2$ e la tabella viene aggiornata di conseguenza.
> 
> ![[Pasted image 20260605164238.png|700]]
> 
> Nella seconda iterazione, i nodi $v$ e $y$ hanno entrambi un percorso di costo minimo pari a $2$. Se ne sceglie arbitrariamente uno, per esempio $y$, e lo si aggiunge a $N'$, che contiene ora $u$, $x$ e $y$. I costi verso i nodi rimanenti, cioè $v$, $w$ e $z$, vengono aggiornati applicando la regola dell’algoritmo. I risultati corrispondono alla terza riga della Tabella 5.1.
> 
> Il procedimento prosegue nello stesso modo fino a quando tutti i nodi appartengono a $N'$. Al termine dell’algoritmo, per ogni nodo è noto il predecessore lungo il percorso a costo minimo a partire dall’origine.
> 
> La tabella di inoltro di un nodo, per esempio $u$, può essere costruita utilizzando queste informazioni. Per ciascuna destinazione viene memorizzato il nodo corrispondente al **successivo hop** lungo il percorso a costo minimo da $u$ alla destinazione.
> 
> ![[Pasted image 20260605164300.png|700]]

###### Complessità dell’algoritmo di Dijkstra
Un’implementazione dell’algoritmo di Dijkstra che ricerca il valore minimo esaminando ogni volta tutti i nodi ha, nel caso peggiore, una complessità quadratica, pari a $O(N^2)$. Un’implementazione più sofisticata può utilizzare un **heap**, la complessità si riduce a 
$O(|N|+|E|log|N|)$
###### Oscillazioni nell’instradamento sensibile alla congestione
Un comportamento patologico può verificarsi quando il costo di un collegamento dipende dalla quantità di traffico che lo attraversa. In questo esempio, il costo di ciascuna direzione di un collegamento coincide con il carico trasportato in quella direzione.

I costi non sono quindi necessariamente simmetrici: può accadere che $c(u,v)\neq c(v,u)$, perché le due direzioni dello stesso collegamento possono trasportare quantità di traffico differenti.

I nodi generano il seguente traffico, tutto diretto verso $w$:
- $x$ genera una quantità di traffico pari a $1$;
- $z$ genera una quantità di traffico pari a $1$;
- $y$ genera una quantità di traffico pari a $\varepsilon$.

Per evitare ambiguità, l’ordine dei nodi in senso orario è:
$$  
w\rightarrow x\rightarrow y\rightarrow z\rightarrow w  
$$
Di conseguenza, da $y$ 
- il percorso in senso orario verso $w$ è $y\rightarrow z\rightarrow w$
- mentre quello in senso antiorario è $y\rightarrow x\rightarrow w$
![[Pasted image 20260605164639.png|700]]
**Configurazione iniziale**
Nella Figura 5.5(a), il traffico segue questi percorsi:
- $z$ raggiunge direttamente $w$ attraverso $z\rightarrow w$;
- $x$ raggiunge direttamente $w$ attraverso $x\rightarrow w$;
- $y$ raggiunge $w$ attraverso $y\rightarrow x\rightarrow w$.

Il collegamento $z\rightarrow w$ trasporta soltanto il traffico generato da $z$, quindi ha costo $1$.
Il collegamento $y\rightarrow x$ trasporta il traffico generato da $y$, quindi ha costo $\varepsilon$.
Il collegamento $x\rightarrow w$ trasporta sia il traffico generato da $x$ sia quello proveniente da $y$. Il suo costo è pertanto: $1+\varepsilon$

Le direzioni opposte dei collegamenti non trasportano traffico e hanno quindi costo $0$.
**Primo ricalcolo dei percorsi**
I router eseguono ora nuovamente l’algoritmo utilizzando i costi della configurazione iniziale. 
1. Per il nodo $x$:
	- il percorso diretto verso $w$ ha costo: $c(x,w)=1+\varepsilon$ 
	- Il percorso in senso orario $x\rightarrow y\rightarrow z\rightarrow w$ ha invece costo: $c(x,y)+c(y,z)+c(z,w)=0+0+1=1$
	Poiché $1<1+\varepsilon$, il nodo $x$ decide di spostare il proprio traffico sul percorso in senso orario. 
2. Anche il nodo $y$ confronta i due percorsi. 
	- Il percorso in senso orario $y\rightarrow z\rightarrow w$ ha costo: $c(y,z)+c(z,w)=0+1=1$
	- Il percorso in senso antiorario $y\rightarrow x\rightarrow w$, leggendo i costi riportati nella figura, ha invece costo: $\begin{aligned}c(y,x)+c(x,w)&=\varepsilon+(1+\varepsilon)\&=1+2\varepsilon\end{aligned}$
	Poiché $1<1+2\varepsilon$, anche $y$ sceglie il percorso in senso orario.
3. Il nodo $z$ continua invece a utilizzare il collegamento diretto $z\rightarrow w$.
Dopo queste decisioni, il traffico segue quindi i percorsi:
- $x\rightarrow y\rightarrow z\rightarrow w$;
- $y\rightarrow z\rightarrow w$;
- $z\rightarrow w$.
Si ottiene così la configurazione mostrata nella Figura 5.5(b).

Nella nuova configurazione, tutto il traffico procede in senso orario. 
- Il collegamento $x\rightarrow y$ trasporta il traffico di $x$, quindi ha costo: $1$ 
- Il collegamento $y\rightarrow z$ trasporta il traffico di $x$ e quello di $y$ quindi ha costo $1+\varepsilon$
- Il collegamento $z\rightarrow w$ trasporta il traffico generato da tutti e tre i nodi, quindi ha costo: $2+\varepsilon$

Le direzioni opposte non trasportano traffico e hanno costo $0$. Il problema nasce dal fatto che tutti i router hanno cambiato percorso contemporaneamente. La direzione che prima sembrava conveniente è ora diventata congestionata, mentre la direzione opposta appare completamente libera.

**Secondo ricalcolo dei percorsi**
Quando l’algoritmo viene eseguito di nuovo utilizzando i costi della Figura 5.5(b), ogni nodo osserva che i collegamenti in senso antiorario hanno costo nullo o comunque inferiore. Hanno tutti costo 0 quindi tutti e tre i nodi decidono quindi di spostare simultaneamente il proprio traffico in senso antiorario.
Si ottiene la configurazione della Figura 5.5(c), nella quale:
- $x$ utilizza direttamente $x\rightarrow w$
- $y$ utilizza $y\rightarrow x\rightarrow w$
- $z$ utilizza $z\rightarrow y\rightarrow x\rightarrow w$.

Dopo lo spostamento del traffico si ottiene che i percorsi in senso orario hanno un costo minore, quindi al prossimo ricalcolo i router cambieranno di nuovo direzione. Questa oscillazione nasce dalla combinazione di due fattori:
1. i costi dei collegamenti dipendono dal traffico corrente;
2. tutti i router ricalcolano e cambiano percorso nello stesso momento.

Una possibile soluzione sarebbe rendere i costi indipendenti dal traffico, ma ciò impedirebbe all’algoritmo di evitare i collegamenti congestionati. Una soluzione più ragionevole consiste nel fare in modo che i router non eseguano l’algoritmo esattamente nello stesso istante, evitando che tutti spostino contemporaneamente il traffico nella stessa direzione.

###### Flooding e Link-State Broadcaste problema del conteggio all’infinito
Un algoritmo di instradamento **centralizzato** calcola il percorso migliore utilizzando una conoscenza globale della rete. È quindi necessario che ogni router conosca:
- la **topologia** della rete;
- i collegamenti disponibili;
- il **costo** associato a ogni collegamento.
Il protocollo **Open Shortest Path First (OSPF)** ottiene queste informazioni attraverso il **link-state broadcast**. Ogni router genera dei messaggi chiamati **Link-State Advertisement (LSA)**, contenenti informazioni sui propri collegamenti e sui relativi costi, e li distribuisce agli altri router tramite il **flooding**. Il **flooding** è una tecnica di diffusione nella quale un dispositivo inoltra un messaggio su **tutte le linee disponibili, eccetto quella dalla quale il messaggio è stato ricevuto**. In questo modo il messaggio può raggiungere tutti i nodi della rete anche quando il mittente non conosce un percorso preciso verso ciascuno di essi. Nel caso di OSPF, il flooding non viene utilizzato per trasportare i normali dati degli utenti, ma per distribuire informazioni di controllo relative alla topologia e ai costi dei collegamenti.

![[Pasted image 20260605184820.png|700]]
Nelle reti con molti collegamenti e cicli, un messaggio può raggiungere più volte lo stesso dispositivo attraverso percorsi differenti. Senza opportuni controlli, ciò può causare:
- pacchetti duplicati;
- consumo inutile di banda;
- aumento del carico sui dispositivi;
- possibili loop;
- saturazione della rete.
Per questo motivo vengono utilizzati diversi meccanismi di controllo.
1. **Identificativo e numero di sequenza**: ogni messaggio viene associato a un identificativo, generalmente formato dall’ID del dispositivo che lo ha generato e da un **numero di sequenza progressivo**. Quando un router riceve il messaggio, verifica se lo ha già elaborato:
	- se il messaggio è nuovo, lo registra e lo inoltra;
	- se ha già visto lo stesso identificativo e numero di sequenza, lo scarta.
2. **Limite di hop** Un messaggio può contenere un valore che limita il numero massimo di dispositivi che può attraversare. Nel protocollo IP questo ruolo è svolto dal **TTL**. 
3. **Eliminazione logica dei cicli**: Guardando alla rete come ad un grafo, per evitare la circolazione indefinita dei messaggi, è possibile costruire una topologia logica priva di cicli, mantenendo eventualmente i collegamenti ridondanti inattivi o utilizzandoli soltanto come percorsi alternativi. 
4. **Utilizzo di uno Spanning Tree**: Uno **Spanning Tree**, o albero di copertura, è un sottoinsieme dei collegamenti della rete che:
	- collega tutti i dispositivi; 
	- non contiene cicli;
	- mantiene fisicamente disponibili eventuali collegamenti ridondanti.
  I messaggi vengono inoltrati soltanto lungo i rami attivi dell’albero, evitando che possano circolare in modo indefinito. Questa tecnica è utilizzata principalmente nelle reti Ethernet attraverso lo **Spanning Tree Protocol (STP)**.

### Instradamento Distance-Vector
###### Introduzione
A differenza dell’instradamento LS, che utilizza informazioni globali, l’instradamento **DV - Distance-Vector** è distribuito, iterativo e asincrono.
- È **distribuito** perché ogni nodo riceve una parte delle informazioni da uno o più vicini direttamente connessi e, dopo aver eseguito i propri calcoli, comunica loro i risultati.
- È **iterativo** perché il processo viene ripetuto fino a quando non avvengono ulteriori scambi informativi tra i vicini. L’algoritmo è anche auto-terminante: non esiste un segnale esplicito che ordini di interrompere il calcolo; il sistema entra semplicemente in uno stato nel quale non sono necessari nuovi aggiornamenti.
- È **asincrono** perché non richiede che tutti i nodi eseguano contemporaneamente le stesse operazioni o procedano allo stesso ritmo.
Per implementare questo algoritmo viene usato la formula di bellam-ford 
###### Formula di Bellman-Ford
Sia $d_x(y)$ il costo del percorso a costo minimo dal nodo $x$ al nodo $y$. I costi minimi sono legati dalla formula di **Bellman-Ford**: $$  
d_x(y)=\min_{v}{c(x,v)+d_v(y)}$$
Il minimo viene calcolato su tutti i nodi $v$ vicini di $x$. La relazione è intuitiva. Se il percorso da $x$ a $y$ inizia attraversando il collegamento da $x$ a un vicino $v$, e da $v$ prosegue lungo il percorso a costo minimo verso $y$, il suo costo complessivo è $c(x,v)+d_v(y)$.  Attraverso questa formula nasce l'algoritmo di bellman ford usato ampiamente nell'implementazione del distance vector
###### Vettori delle distanze e informazioni mantenute dai nodi
Ogni nodo $x$ deve stimare il costo necessario per raggiungere ciascuna destinazione $y\in N$. Questa stima viene indicata con: $D_x(y)$

Il pedice $x$ indica il nodo che sta effettuando il calcolo, mentre l’argomento $y$ indica la destinazione considerata. Di conseguenza, $D_x(y)$ rappresenta la stima, mantenuta dal nodo $x$, del costo del percorso a costo minimo da $x$ a $y$.

È importante distinguere tra $D_x(y)$ e $d_x(y)$:
- $D_x(y)$ è una stima che può cambiare durante l’esecuzione dell’algoritmo;
- $d_x(y)$ è il costo effettivo del percorso a costo minimo da $x$ a $y$.
Quando l’algoritmo converge, la stima diventa uguale al valore reale:
$$  
D_x(y)=d_x(y)  
$$
Il nodo $x$ raccoglie tutte le proprie stime all'interno di un unico vettore.
**Vettore delle distanze:** il vettore delle distanze del nodo $x$ è:
$$  
D_x=[D_x(y):y\in N] \text{ indica che il vettore $D_x$ contiene un valore $D_x(y)$ per ogni nodo $y$ appartenente all'insieme $N$. }
$$
Ogni nodo $x$ mantiene localmente tre tipi di informazioni.
- Per ciascun vicino $v$, conserva il costo del collegamento diretto $c(x,v)$.
- Conserva il proprio vettore delle distanze $D_x$, contenente le stime dei costi da $x$ verso tutte le destinazioni $y\in N$.
- Conserva l’ultima copia ricevuta del vettore delle distanze di ciascun vicino $v$. Il  vettore ricevuto dal vicino $v$ è indicato con:$$D_v=[D_v(y):y\in N]$$Il valore $D_v(y)$ rappresenta quindi la stima che il vicino $v$ possiede per raggiungere la destinazione $y$. Il nodo $x$ non conosce l’intera topologia della rete: conosce soltanto i costi dei propri collegamenti diretti e le stime comunicate dai suoi vicini.

Periodicamente, oppure quando il proprio vettore cambia, ogni nodo invia una copia del proprio vettore delle distanze a tutti i vicini direttamente collegati. Quando il nodo $x$ riceve un nuovo vettore da un vicino $v$, lo memorizza e ricalcola le proprie stime applicando la formula di Bellman-Ford: $$D_x(y)=\min_{v:(x,v)\in E}{c(x,v)+D_v(y)}$$
questa formula non viene quindi applicata una sola volta all’intero vettore. Il nodo $x$ la applica a ogni possibile destinazione $y\in N$
Dopo il ricalcolo possono verificarsi due casi.
- Se nessun valore del vettore è cambiato, il nodo $x$ non deve inviare alcun aggiornamento, perché i vicini possiedono già le sue stime più recenti.
- Se almeno un valore $D_x(y)$ è cambiato, il nodo $x$ invia il proprio vettore aggiornato a tutti i vicini

I vicini memorizzano il nuovo vettore ricevuto e utilizzano a loro volta queste informazioni per ricalcolare le proprie stime. Un cambiamento può quindi propagarsi progressivamente da un nodo ai suoi vicini e successivamente ai vicini dei vicini.

Lo scambio avviene in modo **asincrono**: non è necessario che tutti i nodi effettuino il calcolo o inviino i vettori nello stesso momento. Ciascun nodo reagisce quando riceve un aggiornamento oppure quando rileva una variazione nel costo di uno dei propri collegamenti diretti. l processo continua finché gli aggiornamenti non producono più cambiamenti. Quando tutti i vettori rimangono invariati, l’algoritmo entra in uno stato quiescente e le stime convergono ai costi effettivi dei percorsi minimi: $$D_x(y)\longrightarrow d_x(y)$$
###### Pseudocodice Distance-Vector
Nel grafo $G=(N,E)$, $N$ è l’insieme dei router e $adj(x)$ è l’insieme dei vicini diretti di $x$.

```
Algoritmo Bellman-Ford per Distance Vector

A ciascun nodo x:

1   Inizializzazione:
2       per tutte le destinazioni y in N:
3           Dₓ(y) = c(x,y)  /* se y non è adiacente, allora c(x,y) = ∞ */
4       per ciascun vicino w
5           Dᵥ(y) = ? per tutte le destinazioni y in N
6       per ciascun vicino w
7           invia il vettore delle distanze Dₓ = [Dₓ(y): y in N] a w

9   ciclo
10      attendi (finché vedi cambiare il costo di un collegamento verso
11              qualche vicino w o finché ricevi un vettore delle distanze
12              da qualche vicino w)
13      per ogni y in N:
14          Dₓ(y) = minᵥ {c(x,v) + Dᵥ(y)}

16      se Dₓ(y) è cambiato per qualche destinazione y
17          invia il vettore delle distanze Dₓ = [Dₓ(y): y in N]
            a tutti i vicini

19  ripeti il ciclo indefinitamente
```

Per ogni destinazione $y$, il nodo $x$ deve conoscere sia il costo stimato $D_x(y)$ sia il vicino da utilizzare come **successivo hop**. Il vicino scelto viene indicato con $v^\ast(y)$ ed è quello che produce il valore minimo nella formula di Bellman-Ford, se più vicini producono lo stesso valore minimo, $v^\ast(y)$ può essere scelto arbitrariamente tra essi. La tabella di inoltro associa quindi alla destinazione $y$ il vicino $v^\ast(y)$, che rappresenta il router successivo lungo il percorso a costo minimo.

A differenza del **Link-State**, che richiede una mappa completa della rete prima di eseguire l’algoritmo di Dijkstra, il **Distance-Vector** è decentralizzato: ogni nodo conosce soltanto i costi dei collegamenti diretti e i vettori delle distanze ricevuti dai propri vicini. Questo meccanismo è utilizzato da protocolli come **RIP** e **BGP**.

> [!EXAMPLE] Esempi di come DV calcola i vettori delle distance
> 
> ![[Pasted image 20260605181001.png|700]]
> 
> La figura mostra l’esecuzione in modo sincrono: i nodi ricevono contemporaneamente i vettori, ricalcolano le stime e comunicano gli eventuali cambiamenti. In ogni tabella, la prima riga contiene il vettore locale e le altre gli ultimi vettori ricevuti dai vicini.
> 
> Per $x$, il vettore iniziale è:
> $$  
> D_x=[D_x(x),D_x(y),D_x(z)]=[0,2,7]  
> $$
> 
> Prima di ricevere messaggi, le righe relative a $D_y$ e $D_z$ contengono $+\infty$. Dopo lo scambio iniziale, $x$ calcola:
> 
> $$  
> D_x(y)=\min{\{2+0,7+1\}}=2  
> $$
> 
> $$  
> D_x(z)=\min{\{2+1,7+0\}}=3  
> $$
> 
> La stima verso $z$ passa da $7$ a $3$, usando $y$ come successivo hop quindi $v^*{(y)}$ resta $y$ e invece $v^*(z)=y$.
> 
> La seconda colonna mostra i vettori aggiornati e quelli ricevuti. Solo $x$ e $z$ inviano un nuovo messaggio, perché il vettore di $y$ non cambia. Dopo un ulteriore ricalcolo, nessuna stima varia: l’algoritmo entra in **stato quiescente** e attende un nuovo vettore o una variazione del costo di un collegamento.

###### Diminuzione del costo di un arco
Quando un nodo che esegue l’algoritmo **Distance-Vector** rileva una variazione nel costo di un collegamento diretto, aggiorna il proprio vettore delle distanze applicando nuovamente la formula di Bellman-Ford. Se almeno una delle sue stime cambia, il nodo invia il vettore aggiornato ai propri vicini.

Un aumento o una diminuzione del costo di un collegamento non viene quindi comunicato direttamente a tutti i router della rete. L’informazione si propaga progressivamente: il nodo che rileva il cambiamento aggiorna le proprie stime e le comunica ai vicini; questi possono modificare i propri vettori e inviare a loro volta nuovi aggiornamenti.

![[Pasted image 20260605181845.png|700]]

Nella Figura 5.7(a), il costo del collegamento tra $x$ e $y$ diminuisce da $4$ a $1$. L’analisi si concentra sui nodi $y$ e $z$ e sulle loro stime relative alla destinazione $x$.

La propagazione dell’informazione avviene nel modo seguente.
1. All'istante $t_0$, il nodo $y$ rileva che il costo del collegamento diretto verso $x$ è diminuito da $4$ a $1$. Aggiorna quindi la propria stima ponendo $D_y(x)=1$ e invia il nuovo vettore delle distanze ai propri vicini.
2. All'istante $t_1$, il nodo $z$ riceve il vettore aggiornato di $y$. Poiché il collegamento tra $z$ e $y$ ha costo $1$, $z$ calcola il nuovo costo verso $x$ passando attraverso $y$: $$ \begin{aligned} D_z(x) &=c(z,y)+D_y(x)\ &=1+1\ &=2 \end{aligned}  $$La precedente stima di $z$ verso $x$ era pari a $5$. Poiché il nuovo percorso ha costo $2$, $z$ aggiorna il proprio vettore e comunica il cambiamento ai vicini.
3. All'istante $t_2$, il nodo $y$ riceve il nuovo vettore di $z$. Tuttavia, il percorso diretto da $y$ a $x$ continua ad avere costo $1$ ed è quindi migliore del percorso che passa attraverso $z$. Le stime di $y$ non cambiano e il nodo non invia ulteriori messaggi.

Dopo questi aggiornamenti, l’algoritmo entra nuovamente in uno **stato quiescente**. La diminuzione del costo si propaga rapidamente perché ogni nodo che riceve l’informazione individua immediatamente un percorso migliore. 
###### Aumento del costo di un arco
La situazione diventa più problematica quando il costo di un collegamento aumenta. In questo caso, un nodo può continuare temporaneamente a utilizzare informazioni non aggiornate ricevute dai vicini, provocando la formazione di un ciclo di instradamento.
![[Pasted image 20260605182349.png]]
Si supponga che il costo del collegamento tra $x$ e $y$ aumenti da $4$ a $60$. Prima della modifica valgono:
- $D_y(x)=4$ e $D_y(z)=1$
- $D_z(y)=1$ e $D_z(x)=5$ (deriva dal percorso $z\rightarrow y\rightarrow x$, il cui costo è $c(z,y)+D_y(x)=1+4=5$.)

1. All'istante $t_0$, il nodo $y$ rileva che il costo diretto verso $x$ è passato da $4$ a $60$. Per aggiornare la propria stima confronta il percorso diretto, di costo $60$, con quello che passa attraverso $z$, il cui costo apparente è $c(y,z)+D_z(x)=1+5=6$. Osservando globalmente la rete, questo risultato è errato: il nodo $z$ ritiene di poter raggiungere $x$ con costo $5$ proprio perché il suo percorso passa attraverso $y$. 
2. Poiché la stima di $y$ è cambiata, all'istante $t_1$ il nodo comunica a $z$ il nuovo valore $D_y(x)=6$. Quando riceve l’aggiornamento, $z$ confronta il collegamento diretto verso $x$, di costo $50$, con il percorso attraverso $y$: $$D_z(x)=\min{c(z,x)+D_x(x),c(z,y)+D_y(x)}\ =\min{50+0,1+6}\ =7$$l nodo $z$ aggiorna la propria stima da $5$ a $7$ e comunica il nuovo valore a $y$. Dopo aver ricevuto l’aggiornamento, $y$ calcola $D_y(x)=\min{60,1+7}=8$ e invia il valore a $z$, che a sua volta calcola $D_z(x)=\min{50,1+8}=9$.

Si forma così il ciclo $y\rightarrow z\rightarrow y\rightarrow z\rightarrow\cdots$. Un pacchetto destinato a $x$ che raggiunge uno dei due nodi viene inoltrato ripetutamente tra $y$ e $z$, finché le informazioni di instradamento non vengono corrette oppure il pacchetto non viene eliminato.

Il procedimento continua nello stesso modo: $D_y(x)=10$, $D_z(x)=11$, $D_y(x)=12$, $D_z(x)=13$ e così via. Le stime aumentano progressivamente, mentre i due nodi continuano a indicarsi reciprocamente come parte del percorso verso $x$. Il processo termina soltanto quando $z$ calcola che il percorso attraverso $y$ ha un costo superiore a $50$, cioè al costo del proprio collegamento diretto verso $x$. A quel punto $z$ sceglie il collegamento diretto e comunica la nuova informazione a $y$, che può finalmente raggiungere $x$ passando correttamente attraverso $z$ con costo $51$.

Nell'esempio sono necessarie $44$ iterazioni prima che venga individuato il percorso corretto. Se $c(y,x)$ passasse da $4$ a $10,000$ e $c(z,x)$ fosse pari a $9,999$, il numero di aggiornamenti richiesti sarebbe ancora maggiore.

**Problema del conteggio all’infinito:** fenomeno per cui, in seguito all'aumento del costo o al guasto di un collegamento, i nodi incrementano gradualmente le proprie stime prima di riconoscere che un percorso non è più conveniente o non è più disponibile. Le diminuzioni di costo si propagano rapidamente, mentre gli aumenti possono diffondersi molto lentamente
###### Inversione avvelenata
Lo specifico ciclo che può formarsi tra due nodi adiacenti può essere evitato mediante una tecnica chiamata **inversione avvelenata**.

**Inversione avvelenata:** se un nodo utilizza un vicino come successivo hop per raggiungere una determinata destinazione, comunica a quel vicino che la propria distanza verso tale destinazione è infinita.

Si supponga che il nodo $z$ raggiunga la destinazione $x$ passando attraverso $y$, seguendo quindi il percorso $z\rightarrow y\rightarrow x$. In questa situazione, $z$ non comunica a $y$ il proprio valore reale $D_z(x)=5$, ma dichiara invece $D_z(x)=+\infty$. Il nodo continua a fornire questa informazione finché utilizza $y$ come successivo hop verso $x$.

La motivazione è che il valore comunicato da $z$ non deve essere utilizzato da $y$ per costruire un nuovo percorso verso $x$. Il percorso di $z$, infatti, passa già attraverso $y$; se $y$ scegliesse a sua volta $z$ come successivo hop, i due nodi si indicherebbero reciprocamente e si formerebbe il ciclo $y\rightarrow z\rightarrow y\rightarrow\cdots$.

Applicando l’inversione avvelenata allo scenario precedente, prima dell’aumento del costo il nodo $z$ raggiunge $x$ attraverso $y$ e comunica quindi a quest’ultimo che $D_z(x)=+\infty$.
- All'istante $t_0$, il costo del collegamento diretto tra $y$ e $x$ aumenta da $4$ a $60$. Il nodo $y$ confronta il percorso diretto, di costo $60$, con quello attraverso $z$, che in base all'informazione avvelenata ha costo infinito: $$\begin{aligned}D_y(x)=\min{\{60,1+(+\infty)\}}=60 \end{aligned}$$Di conseguenza, $y$ non sceglie erroneamente $z$ e continua temporaneamente a utilizzare il collegamento diretto verso $x$. Comunica quindi a $z$ il nuovo valore $D_y(x)=60$.
- All'istante $t_1$, il nodo $z$ riceve l’aggiornamento e confronta il collegamento diretto verso $x$, di costo $50$, con il percorso attraverso $y$, di costo $1+60=61$: $$D_z(x) =\min{\{50,1+60\}}=50$$Il nodo $z$ sceglie quindi il collegamento diretto verso $x$. Poiché non utilizza più $y$ come successivo hop, non deve più avvelenare il percorso e può comunicare a $y$ il valore reale $D_z(x)=50$.
- All'istante $t_2$, il nodo $y$ riceve il nuovo valore e aggiorna la propria distanza: $$D_y(x) = \min{60,1+50} = 51$$
Il nuovo percorso minimo di $y$ verso $x$ diventa quindi $y\rightarrow z\rightarrow x$. A questo punto è $y$ a utilizzare $z$ come successivo hop; di conseguenza, applicando l’inversione avvelenata, $y$ comunica a $z$ che $D_y(x)=+\infty$, anche se la sua distanza reale verso $x$ è pari a $51$.

L’inversione avvelenata impedisce quindi la formazione di un ciclo tra due nodi che si indicano reciprocamente come successivo hop. Non risolve però completamente il problema del conteggio all'infinito: i cicli che coinvolgono tre o più nodi possono non essere rilevati, poiché ciascun nodo avvelena il percorso soltanto nei confronti del vicino utilizzato come successivo hop.

### Confronto tra instradamento LS e DV
Gli algoritmi LS e DV adottano approcci diversi per calcolare i percorsi.
- **Complessità dei messaggi**
    - LS richiede che ogni nodo conosca i costi di tutti i collegamenti, generando $O(|N|\cdot|E|)$ messaggi. Ogni variazione di costo deve essere comunicata a tutti i nodi.
    - DV scambia informazioni solo tra nodi adiacenti. Gli aggiornamenti vengono propagati quando modificano uno o più percorsi a costo minimo.
- **Velocità di convergenza:** LS ha complessità $O(|N|^2)$ e richiede $O(|N|\cdot|E|)$ messaggi. DV può convergere lentamente, creare cicli ed essere soggetto al conteggio all’infinito.
- **Robustezza:** in presenza di router guasti o malevoli:
    - Con LS, un router può dichiarare costi errati solo per i propri collegamenti o alterare i pacchetti ricevuti. Tuttavia, ogni nodo calcola autonomamente la propria tabella, limitando la propagazione degli errori.
    - Con DV, un nodo può comunicare percorsi errati verso tutte le destinazioni. Poiché le informazioni vengono propagate tra vicini, un errore può diffondersi nell’intera rete.
Nessuno dei due approcci è sempre migliore: sia LS sia DV sono utilizzati in Internet.

### Routing in internet

Per facilitare il routing in Internet, quest’ultimo è organizzato in **sistemi autonomi** (AS). Ogni sistema autonomo è trattato come una singola entità amministrativa.
- All’interno di sistema autonomo, tutti i router eseguono lo stesso algoritmo di routing, chiamato **protocollo di instradamento intra-AS**.
- Per l’instradamento tra AS distinti si usano invece **protocolli di instradamento inter-AS**.

Questa organizzazione in sistemi autonomi, garantisce una maggiore **autonomia amministrativa** e migliore **scalabilità**. Ogni sistema autonomo è identificato da un **numero di sistema autonomo** (ASN).
###### RIP - Routing Information Protocol (intra-AS)
È un protocollo di routing basato sull'algoritmo **Distance Vector** per il routing interno ai sistemi autonomi. La sua metrica è il **numero di hop**, ovvero il numero di router da attraversare per raggiungere una determinata destinazione.
- Supporta al più 15 hop. Una destinazione $x$ con $\text{ distanza }.x=16$ hop è irraggiungibile.
- I router scambiano informazioni relative alle tabelle di routing ogni 30 secondi.
- Un percorso non aggiornato per 180 secondi è marcato come irraggiungibile.
- Dopo altri 120 secondi viene rimosso dalla tabella (garbage collection).

Sfrutta inoltre due tipi di messaggi:
- `REQUEST` per richiedere informazioni di routing ai router vicini.
- `RESPONSE` per fornire aggiornamenti sulla propria tabella di routing.

Visto che è basato su distance vector soffre del problema del count to infinity
###### Tabelle di routing RIP
Contengono:
- Indirizzo $x$ di destinazione.
- Distanza minima (in hop) verso $x$.
- Prossimo hop per arrivare a $x$.
- Un timeout.
- Un timer per la garbage collection.

###### Versioni di RIP
- **RIP v1** supporta solo indirizzamento classful senza subnet. Il campo next hop non è esplicito, e non supporta autenticazione.
- **RIP v2** supporta CIDR, Poison Reverse, autenticazione e next hop esplicito nel messaggio.
- **RIPng** (next generation) per IPv6, basata su RIP v2. Non supporta l’autenticazione.

###### OSPF - Open Shortest Path First (intra-AS)
È un protocollo di routing intra-AS di tipo **Link State** usato soprattutto nei contesti di rete medio-grandi e nei **backbone degli ISP**. È molto scalabile e robusto. Ogni router OSPF:
- Costruisce una **mappa topologica completa** del sistema autonomo usando il flooding. Costruisce un grafo della rete.
- Esegue localmente l’algoritmo di Dijkstra e determina l’albero dei cammini minimi da se stesso.
- Mantiene un Link-State Database con informazioni sui collegamenti noti.
- Manda aggiornamenti periodici tramite dei Link-State Advertisements, rendendo il protocollo molto robusto.

> [!TIP]
> Il **backbone di un ISP** è la sua **rete dorsale principale**, cioè l’infrastruttura ad alta capacità che trasporta grandi quantità di traffico Internet tra città, regioni, data center e altre reti.
> In pratica:
> - tu ti colleghi alla rete di accesso dell’ISP tramite fibra, rame o rete mobile;
> - il traffico viene raccolto e inoltrato verso il **backbone**;
> - dal backbone passa poi verso altri ISP, servizi online o punti di interscambio Internet.

I messaggi sono del tipo:
- `HELLO`, trasmissione periodica per Neighbor Discovery.
- `Database Description`, per condividere le informazioni link-state tra i vari router
- `LS Request`, per richiedere parti specifiche del link-state database di un vicino.
- `LS Update`, per effettuare il flooding.
- `LS ACK`, dei segnali di ACK relativi al Link-State update.

E ogni nodo effettua questi passaggi:
1. **Scoperta dei vicini**, in cui i router scoprono i nodi adiacenti inviando messaggi `HELLO`.
2. **Sincronizzazione dei database**, `EXCHANGE`, con scambio e confronto delle informazioni Link-State.
3. **Aggiornamento dei database**, `FLOODING`, con messaggi tramite cui i cambiamenti dei cammini minimi sono propagati.

###### BGP - Border Gateway Protocol
È un protocollo di routing **inter-AS**, e quindi tra sistemi autonomi. È fondamentale per il funzionamento di Internet, tanto quanto IP, in quanto è il **collante tra tutti i vari AS**.
- **Comunicare la raggiungibilità delle sotto reti:** Permettendo a ciascun sistema di rendersi visibile rispetto i **prefissi di rete** che gestisce. È tramite BGP che tutti i router conoscono le sottoreti vicine.
- **Determinare i percorsi ottimali verso le sottoreti:** Un router può apprendere più percorsi verso un **determinato prefisso** (ovvero una sottorete). La selezione del percorso migliore avviene in base alle politiche del sistema autonomo e alle informazioni di raggiungibilità fornite da BGP.
###### Funzionamento di BGP
Un router che esegue il protocollo BGP è detto **BGP speaker**. Due BGP speaker configurati per scambiarsi informazioni di routing sono detti **BGP peer** o **BGP neighbors** e comunicano attraverso una sessione **TCP**, normalmente sulla porta 179. Le sessioni possono essere di due tipi:
- **eBGP - External BGP**, tra router appartenenti a sistemi autonomi differenti. Serve a scambiare informazioni sulla raggiungibilità dei prefissi tra AS diversi.
- **iBGP - Internal BGP**, tra router appartenenti allo stesso sistema autonomo. Serve a distribuire all’interno dell’AS le rotte esterne apprese tramite eBGP.

iBGP non sostituisce un protocollo intra-AS come OSPF o RIP: iBGP comunica quale prefisso esterno è raggiungibile e quale next hop utilizzare, mentre OSPF o RIP determinano il percorso interno necessario per raggiungere quel next hop.

![[Pasted image 20260605195557.png|700]]

Supponiamo che un AS voglia **dichiarare la raggiungibilità del prefisso (x)**. Un router BGP invia l’annuncio ai propri peer, che possono accettarlo, modificarne alcuni attributi e propagarlo ulteriormente secondo le politiche del proprio AS. L’insieme formato dal prefisso e dai relativi attributi è detto **route BGP**, cioè rotta BGP. Tra le informazioni principali di una rotta troviamo:
- il **prefisso (x)**, cioè la rete resa raggiungibile;
- **AS-PATH**, la sequenza degli AS attraversati dall’annuncio;
- **NEXT-HOP**, l’indirizzo IP del router verso cui inoltrare i pacchetti per utilizzare quella rotta.

Quando un annuncio viene propagato tramite eBGP, ogni AS aggiunge normalmente il proprio ASN all’AS-PATH. Questo attributo descrive quindi il percorso tra sistemi autonomi e permette anche di evitare i loop: se un AS riceve un annuncio nel cui AS-PATH compare già il proprio ASN, scarta la rotta. Nelle comunicazioni iBGP, invece, l’AS-PATH normalmente non viene modificato, perché l’annuncio resta all’interno dello stesso AS.

Il NEXT-HOP non rappresenta necessariamente l’intero percorso, ma il prossimo router da raggiungere per utilizzare la rotta. Affinché la rotta sia valida, il NEXT-HOP deve essere raggiungibile tramite il protocollo di routing interno dell’AS.

Un router può apprendere più rotte verso lo stesso prefisso. BGP non sceglie il percorso migliore mediante una sola metrica, ma attraverso un **processo decisionale** basato sulle politiche dell’AS e su diversi attributi, tra cui:
- **LOCAL_PREF**, che esprime la preferenza interna per una rotta;
- lunghezza dell’**AS-PATH**;
- **MED**, che può suggerire il punto di ingresso preferito in un AS;
- preferenza di una rotta eBGP rispetto a una iBGP;
- costo del percorso interno necessario per raggiungere il NEXT-HOP.


## Capitolo 6


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

### Accesso multiplo nei canali broadcast

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

Nel **Taking Turns Protocol**, i nodi accedono al canale a turno, evitando così le collisioni.

Una possibile implementazione è il **token passing**: i nodi sono organizzati in un anello logico e un **token** viene passato da un nodo al successivo. Solo il nodo che possiede il token può utilizzare il canale e, dopo aver terminato la trasmissione oppure dopo un intervallo massimo $T$, deve cederlo al nodo seguente.

Un’altra implementazione è il **polling**, nella quale un nodo centrale interroga a turno gli altri nodi e concede loro il permesso di trasmettere.

Il protocollo presenta però alcuni problemi: il guasto di un nodo può interrompere il passaggio del token, il token può andare perso e tutti i nodi devono essere inseriti correttamente nell’anello logico. Per questo motivo, le implementazioni reali prevedono meccanismi di controllo e recupero.

### Ethernet

###### Diffusione ed evoluzione di Ethernet
**Ethernet** ha pressoché conquistato il mercato delle reti cablate è diventata di gran lunga la tecnologia più diffusa per le **LAN cablate**, situazione che sembra destinata a perdurare anche nel prossimo futuro. Si potrebbe affermare che Ethernet è stata per le reti locali ciò che Internet è stata per la rete globale.

Alla fine degli anni ’90, la maggior parte delle aziende e delle università aveva sostituito le proprie LAN con installazioni Ethernet basate su una **topologia a stella con hub**. In queste installazioni, gli host e i router erano collegati direttamente a un hub.

**Hub:** dispositivo di livello fisico che agisce sui singoli bit anziché sui frame. Quando un bit, rappresentato da 0 o 1, arriva a una delle sue interfacce, l’hub lo rigenera, ne amplifica la potenza e lo trasmette attraverso tutte le altre interfacce.

Una rete Ethernet con topologia a stella basata su hub è quindi una **LAN broadcast**, poiché ogni volta che l’hub riceve un bit da una delle sue interfacce ne invia una copia a tutte le altre. Se l’hub riceve contemporaneamente frame provenienti da due interfacce differenti, si verifica una **collisione** e i nodi che hanno generato i frame devono ritrasmetterli.

Successivamente, le installazioni Ethernet continuarono a utilizzare una topologia a stella, ma l’hub centrale venne sostituito da uno **switch**. Lo switch non solo consente di realizzare una rete priva di collisioni, ma è anche un vero e proprio commutatore di pacchetti **store-and-forward**. A differenza dei router, che operano fino al livello 3, gli switch si limitano normalmente al livello 2.

###### Struttura del frame Ethernet
Sebbene il payload di un frame Ethernet sia normalmente un datagramma IP, Ethernet può trasportare anche altri tipi di pacchetti appartenenti al livello di rete.

Si supponga che la scheda di rete trasmittente $A$ abbia indirizzo MAC `AA-AA-AA-AA-AA-AA` e che la scheda ricevente $B$ abbia indirizzo MAC `BB-BB-BB-BB-BB-BB`. La scheda di rete $A$ incapsula il datagramma IP in un frame Ethernet e lo passa al livello fisico. La scheda di rete $B$ riceve il frame dal livello fisico, estrae il datagramma IP e lo trasferisce al livello di rete.

![[Pasted image 20260607103822.png|700]]
Il frame Ethernet comprende sei campi.

- **Campo dati, da 46 a 1500 byte:** contiene il datagramma IP. L’unità massima di trasmissione di Ethernet, indicata come **MTU — Maximum Transfer Unit**, è pari a 1500 byte. Se un datagramma IP supera tale valore, l’host deve frammentarlo. Se invece il datagramma IP è più piccolo della dimensione minima del campo dati, pari a 46 byte, il campo deve essere riempito fino a raggiungere tale dimensione. I dati trasferiti al livello di rete contengono quindi sia il datagramma IP sia gli eventuali byte di riempimento, che vengono rimossi utilizzando il campo Lunghezza dell’intestazione del datagramma IP.
- **Indirizzo di destinazione, 6 byte:** contiene l’indirizzo MAC della scheda di rete destinataria, nell'esempio `BB-BB-BB-BB-BB-BB`. Quando la scheda di rete $B$ riceve un frame Ethernet contenente il proprio indirizzo oppure l’indirizzo MAC broadcast, trasferisce il contenuto del campo dati al livello di rete.
- **Indirizzo sorgente, 6 byte:** contiene l’indirizzo MAC della scheda che trasmette il frame, nell'esempio `AA-AA-AA-AA-AA-AA`.
- **Tipo:** consente a Ethernet di supportare diversi protocolli di rete. Oltre a IP, gli host possono infatti supportare altri protocolli di rete e utilizzare protocolli differenti per applicazioni differenti. La scheda di rete ricevente deve quindi sapere a quale protocollo di rete consegnare il contenuto del campo dati di ogni frame ricevuto. IP e gli altri protocolli di rete dispongono ciascuno di un proprio numero di tipo standardizzato. Lo stesso principio si applica ad **ARP**: un frame ARP presenta nel campo Tipo il valore esadecimale `0806`.
- **CRC - Controllo a ridondanza ciclica, 4 byte:** consente alla scheda di rete ricevente di rilevare la presenza di errori nei bit del frame, secondo il meccanismo richiamato nel Paragrafo 6.2.3.
- **Preambolo, 8 byte:** i frame Ethernet iniziano con un campo formato da otto byte. I primi sette presentano la sequenza di bit `10101010`, mentre l’ultimo presenta la sequenza `10101011`. I primi sette byte servono a risvegliare le schede di rete riceventi e a sincronizzarne il clock con quello della scheda trasmittente.

La sincronizzazione è necessaria perché, a seconda del tipo di LAN Ethernet, la scheda di rete $A$ tenta di trasmettere il frame a 10 Mbps, 100 Mbps oppure 1 Gbps, ma il tasso effettivo presenta sempre una variazione rispetto al valore esatto previsto. Tale variazione non è nota a priori alle altre schede della LAN. Il ricevente utilizza quindi i primi sette byte del preambolo per sincronizzarsi con il clock della scheda di rete $A$. Gli ultimi due bit del preambolo, corrispondenti ai primi due 1 consecutivi, avvisano la scheda di rete $B$ che stanno per iniziare i campi significativi del frame.

###### Servizio senza connessione e non affidabile
Tutte le tecnologie Ethernet forniscono al livello di rete un **servizio senza connessione**. Quando una scheda di rete vuole inviare un datagramma a un host della rete, lo incapsula semplicemente in un frame Ethernet e lo immette nella LAN, senza effettuare alcun handshake preventivo con il destinatario. Tale servizio è analogo al servizio senza connessione offerto dai datagrammi IP al livello 3 e da UDP al livello 4.

Ethernet fornisce inoltre al livello di rete un **servizio non affidabile**. Quando la scheda di rete $B$ riceve un frame proveniente da $A$, esegue il controllo CRC, ma non invia alcun acknowledgement, né quando il frame supera il controllo né quando viene rilevato un errore. In quest’ultimo caso il frame viene semplicemente scartato. Di conseguenza, $A$ non sa se il frame trasmesso abbia superato il controllo CRC.

L’assenza di un servizio affidabile al livello di collegamento contribuisce a mantenere Ethernet semplice ed economica, ma comporta la possibilità che il flusso dei datagrammi consegnati al livello di rete presenti delle lacune.

Il modo in cui l’applicazione dell’host $B$ rileva tali lacune dipende dall’uso di **TCP** o **UDP**. Se l’applicazione utilizza UDP, vedrà direttamente le lacune nei dati. Se invece utilizza TCP, l’host $B$ non invia un acknowledgement per i dati contenuti nei frame scartati.

###### Cavi
La trasmissione attraverso un cavo è influenzata dal modo in cui questo è stato realizzato. Tra i principali fattori da considerare vi sono il passaggio della corrente e la lunghezza del cavo.

Il passaggio di corrente induce un **campo magnetico**, che genera a sua volta una **corrente indotta**. Questa scorre in verso opposto rispetto al flusso di corrente iniziale, esercitando quindi una vera e propria opposizione. Anche i cavi adiacenti possono generare campi magnetici e, di conseguenza, flussi opposti: questo fenomeno prende il nome di **diafonia**.

La **lunghezza del cavo** è direttamente proporzionale alla sua **resistenza**. Per coprire grandi distanze è quindi necessario utilizzare dei **ripetitori**.

I cavi di rame sono costituiti dalle seguenti parti:
- **Conduttore:** elemento attraverso il quale avviene la trasmissione.
- **Jacket:** materiale isolante esterno.
- **Shield:** schermatura complessiva applicata a tutti i cavi.
- **Foil:** schermatura applicata a una coppia di cavi.

In base alla schermatura utilizzata, si distinguono diverse tipologie di cavo:
- **UTP - Unshielded Twisted Pair**;
- **STP - Shielded Twisted Pair**;
- **FTP - Foiled Twisted Pair**;
- **SFTP - Shielded Foiled Twisted Pair**.

Si distinguono anche diversi tipologie di cavo di rame in base alla velocità e frequenza:
- **Cat5:** supporta una velocità massima di 100 Mbps e opera a una frequenza di 100 MHz.
- **Cat5e — Cat5 enhanced:** segue maggiormente gli standard IEE, supporta una velocità massima di 1 Gbps e opera a una frequenza di 100 MHz.
- **Cat6:** supporta una velocità massima di 10 Gbps e opera a una frequenza di 250 MHz.
- **Cat6a:** supporta una velocità massima di 10 Gbps, consente di coprire distanze maggiori rispetto alla Cat6 e opera a una frequenza di 500 MHz.

###### Connettore RJ-45
Il **connettore RJ-45** costituisce la terminazione dei cavi utilizzati nelle reti Ethernet. È un connettore di tipo **8P8C**, ossia formato da otto posizioni e otto contatti.

Esistono due schemi di cablaggio, **T568A** e **T568B**, che differiscono per l’inversione delle coppie 2 e 3. Il T568B è lo schema preferito nei sistemi più recenti, secondo lo standard **ANSI/TIA**, definito dall’American National Standards Institute e dalla Telecommunications Industry Association.

![[Pasted image 20260607110236.png|700]]

La disposizione dei pin nello schema T568B è la seguente:

|Pin|Colore|Polarità|Utilizzo|
|--:|---|:-:|---|
|1|bianco/arancione|$+$|Trasmissione (Tx)|
|2|arancione|$-$|Trasmissione (Tx)|
|3|bianco/verde|$+$|Ricezione dati (Rx)|
|4|blu|$-$|Dati bidirezionali (Bi3)|
|5|bianco/blu|$+$|Dati bidirezionali (Bi3)|
|6|verde|$-$|Ricezione dati (Rx)|
|7|bianco/marrone|$+$|Dati bidirezionali (Bi4)|
|8|marrone|$-$|Dati bidirezionali (Bi4)|
La polarità opposta dei segnali trasmessi nei cavi **twisted pair** permette di ridurre facilmente gli effetti del rumore. Si supponga che un bit venga trasmesso mediante due segnali con polarità opposta: sul primo cavo, indicato con $A$, viene trasmesso $+1,\mathrm{V}$, mentre sul secondo, indicato con $B$, viene trasmesso $-1,\mathrm{V}$.

Nei **sistemi differenziali**, l’informazione è rappresentata dalla differenza tra i due segnali. Il valore risultante è quindi:

$$1,\mathrm{V}-(-1,\mathrm{V})=1,\mathrm{V}+1,\mathrm{V}=2,\mathrm{V}$$

Si supponga ora di introdurre un rumore di $+0.5,\mathrm{V}$ sul cavo, e quindi su entrambi i conduttori della coppia. Il primo segnale assume il valore $1.5,\mathrm{V}$, mentre il secondo assume il valore $-0.5,\mathrm{V}$. Calcolando nuovamente la differenza si ottiene:

$$(1,\mathrm{V}+0.5,\mathrm{V})-(0.5,\mathrm{V}-1,\mathrm{V})=1.5,\mathrm{V}-(-0.5,\mathrm{V})=1.5,\mathrm{V}+0.5,\mathrm{V}=2,\mathrm{V}$$

Il rumore, essendo presente nello stesso modo su entrambi i segnali, viene eliminato dalla sottrazione. Il valore differenziale rimane quindi pari a $2,\mathrm{V}$.

![[Pasted image 20260607110258.png|700]]
###### Standard e mezzi fisici Ethernet
Ethernet non è un singolo standard di protocollo, ma comprende numerose tecnologie con denominazioni differenti, tra cui:
- **10BASE-T**;
- **10BASE-2**;
- **100BASE-T**;
- **1000BASE-LX**;
- **10GBASE-T**.
- ...

Queste e molte altre tecnologie Ethernet sono standardizzate dai gruppi di lavoro **IEEE 802.3 CSMA/CD** (CSMA/CD viene usato per gestire l'accesso al canale condiviso).

Le tecnologie standardizzate Ethernet presentano una denominazione fissa:
- *Velocità*: un numero che indica la velocità dello standard.
- *Tipologia di traffico*: BASE in quanto trasferisce solo traffico Ethernet.
- *Mezzo fisico*: un’etichetta che ne specifica il mezzo fisico

![[Pasted image 20260607105753.png|700]]
###### Codifica e decodifica di Manchester
La **codifica di Manchester** nasce per risolvere alcune criticità relative alla trasmissione dei dati:
- **Ambiguità delle lunghe sequenze:** la codifica di Manchester impone transizioni obbligatorie durante la trasmissione dei bit. In questo modo diventa più semplice riconoscere eventuali malfunzionamenti e interruzioni della trasmissione.
- **Sincronizzazione precaria:** ogni bit contiene al proprio interno una transizione, impedendo la perdita della sincronizzazione.

La codifica viene realizzata mediante un’operazione di **XOR** tra il segnale di clock e il segnale dati. Ogni bit viene codificato mediante un fronte di salita per il valore 1 oppure un fronte di discesa per il valore 0. In questo modo, il bitstream e il segnale di clock vengono, in un certo senso, trasmessi contemporaneamente.

![[Pasted image 20260607110915.png|700]]

La codifica di Manchester è tuttavia influenzata dalla polarità del segnale trasmesso. Se il segnale codificato viene invertito, anche la sua decodifica risulta invertita. Questo problema può essere risolto mediante la **codifica di Manchester differenziale**.

La **codifica di Manchester differenziale** rende la codifica insensibile alla polarità del segnale. Ogni bit presenta almeno una transizione a metà del periodo di clock. Il valore del bit dipende invece dalla presenza o dall’assenza di una transizione, in particolare di un fronte di salita, all’inizio del periodo di clock:
- **Bit 0:** presenza di una transizione.
- **Bit 1:** assenza di una transizione.

![[Pasted image 20260607110928.png|700]]

### Gigabit Ethernet

Il **Gigabit Ethernet** raggiunge una velocità di $1000\ \text{Mbit/s}$, cioè $1\ \text{Gbit/s}$. Lo standard **1000BASE-T** è progettato per utilizzare il cablaggio Ethernet in rame già presente negli edifici, costituito da quattro coppie di fili intrecciati, dette **doppini**. L’aumento di velocità non viene ottenuto semplicemente aumentando la frequenza, perché ciò renderebbe il collegamento più sensibile ad attenuazione, rumore e interferenze; vengono invece combinate trasmissione parallela, segnalazione multilivello, funzionamento full-duplex ed elaborazione digitale.

###### Varianti del Gigabit Ethernet

| Standard        | Mezzo trasmissivo  | Segmento massimo | Caratteristiche                                                                     |
| --------------- | ------------------ | ---------------: | ----------------------------------------------------------------------------------- |
| **1000BASE-SX** | Fibra ottica       |  $550\ \text{m}$ | Fibra multimodale da $50$ o $62{,}5\ \mu\text{m}$                                   |
| **1000BASE-LX** | Fibra ottica       | $5000\ \text{m}$ | Fibra monomodale da $10\ \mu\text{m}$ o multimodale da $50$ e $62{,}5\ \mu\text{m}$ |
| **1000BASE-CX** | Due coppie STP     |   $25\ \text{m}$ | Doppino intrecciato schermato                                                       |
| **1000BASE-T**  | Quattro coppie UTP |  $100\ \text{m}$ | Cablaggio Ethernet in rame                                                          |
###### Passaggio da 100 Mbit/s a 1 Gbit/s
Il percorso verso 1000BASE-T viene schematizzato attraverso cinque scelte principali:
1. **Rimozione della codifica 4B5B.** Eliminando questo overhead, la capacità simbolica considerata passa da $100$ a $125\ \text{Mbit/s}$.
2. **Utilizzo simultaneo dei quattro doppini.** I quattro canali portano la capacità complessiva da $125$ a $4\cdot125=500\ \text{Mbit/s}$ (possibile grazie alla cancellazione dell'eco).
3. **Trasmissione full-duplex.** Ogni coppia viene usata contemporaneamente per trasmettere e ricevere.
4. **Cinque livelli** Al posto dei tre livelli della codifica MLT-3 vengono impiegati cinque livelli di segnale usando PAM-5.
5. **Forward Error Correction.** La ridondanza introdotta attraverso permette di migliorare la resistenza agli errori (attraverso Trellis Coded Modulation)

###### Intervalli simbolici e velocità
1000BASE-T divide la trasmissione in **125 milioni di intervalli al secondo**. Ogni intervallo dura quindi:

$$  
T=\frac{1}{125\cdot10^6}=8\ \text{ns}  
$$

Durante ciascun intervallo vengono inviati contemporaneamente quattro livelli elettrici, uno su ogni doppino. Questi quattro livelli non rappresentano quattro dati separati, ma vengono interpretati insieme come un’unica combinazione.

Ogni combinazione permette di rappresentare un byte, cioè otto bit. Di conseguenza, il sistema trasferisce un byte ogni 8 nanosecondi: $$125\cdot10^6\ \text{intervalli/s}\cdot8\ \text{bit/intervallo} 10^9\ \text{bit/s}$$
La velocità complessiva è quindi pari a un miliardo di bit al secondo. Poiché ogni doppino può assumere cinque livelli differenti, le combinazioni teoricamente disponibili sono:$$5^4=625$$
Per rappresentare tutti i possibili valori di un byte ne sarebbero sufficienti 256, perché: $$2^8=256$$

Le combinazioni disponibili in più non corrispondono a un ulteriore bit di dati. Vengono invece utilizzate dal sistema di codifica per scegliere sequenze di segnali più facilmente riconoscibili e più resistenti agli errori causati dal rumore.

###### PAM-5 e rappresentazione a quattro dimensioni
tecnica di modulazione che consente a ogni doppino di assumere uno tra cinque livelli logici, rappresentabili come $-2$, $-1$, $0$, $+1$ e $+2$. Questi valori identificano livelli del segnale e non devono necessariamente essere interpretati come tensioni espresse in volt.

Poiché vengono usati quattro doppini, il simbolo trasmesso può essere rappresentato mediante una quadrupla:

$$(s_1,s_2,s_3,s_4)$$

Ogni componente identifica il livello presente su uno dei quattro canali. Una possibile combinazione è, per esempio, $(-1,+2,0,+1)$. Non si tratta di quattro messaggi separati, ma di un unico simbolo complessivo descritto da quattro coordinate; per questo si parla di segnalazione **a quattro dimensioni**.

Il numero teorico di combinazioni è: $$5^4=625$$

Lo spazio dei simboli corrisponde a una capacità teorica di $\log_2(625)\approx9$ bit. Non tutte le 625 combinazioni rappresentano dati: parte dello spazio viene utilizzata per controllo, ridondanza e protezione dagli errori.

###### Utilizzo dei quattro doppini e full-duplex
Nel Fast Ethernet vengono normalmente impiegate due coppie: una per la trasmissione e una per la ricezione. In 1000BASE-T vengono invece utilizzati contemporaneamente tutti e quattro i doppini.
Su ogni coppia viaggiano nello stesso momento:
- il segnale trasmesso dal dispositivo locale;
- il segnale proveniente dal dispositivo remoto;
- l’eco prodotta dal segnale locale;
- rumore e interferenze presenti sul collegamento.

**Cancellazione dell’eco:** procedimento con cui il ricevitore, conoscendo il segnale generato localmente, ne stima l’effetto sul cavo e lo sottrae dal segnale complessivamente osservato:
$$\text{segnale ricevuto}=\text{segnale remoto}+\text{eco locale}+\text{rumore}$$
L’eco stimata viene rimossa per ricostruire il segnale remoto. La stima deve essere aggiornata continuamente, perché le caratteristiche del collegamento dipendono dalla lunghezza del cavo, dai connettori, dalla temperatura e dalle interferenze ambientali.

###### Sincronizzazione del collegamento
Il ricevitore deve riconoscere con precisione gli intervalli simbolici, ciascuno della durata di: $8\ \text{ns}$

Per mantenere stabile il riferimento temporale, il collegamento non rimane completamente inattivo quando non vengono trasmessi frame. I dispositivi continuano infatti a scambiarsi simboli **Idle**, che permettono al ricevitore di mantenere il sincronismo, controllare la qualità del collegamento e riconoscere rapidamente l’arrivo di nuovi dati.

La sincronizzazione viene facilitata anche dallo **scrambling**. Prima della trasmissione, la sequenza dei dati viene rielaborata in modo da evitare successioni troppo regolari o lunghi periodi con poche variazioni del segnale. In questo modo il ricevitore dispone di un numero sufficiente di cambiamenti elettrici per ricostruire correttamente il ritmo della trasmissione. Lo scrambling non modifica l’informazione originale, perché il ricevitore applica il procedimento inverso per recuperare i dati.

Infine, uno dei due dispositivi assume il ruolo di riferimento temporale, detto **Master**, mentre l’altro, detto **Slave**, adatta il proprio clock al segnale ricevuto. Questa organizzazione evita che i due apparati utilizzino riferimenti temporali indipendenti e contribuisce a mantenere stabile la comunicazione.

###### Filtro DuoBinary
Il **filtro DuoBinary** interviene sulla codifica del segnale. Il bit $x_k$ viene distribuito su più percorsi; gli elementi indicati con $D$ introducono ritardi pari a un byte, cioè circa $8\ \text{ns}$, mentre i sommatori combinano il valore corrente con valori ritardati, producendo le due uscite $y_k^{(1)}$ e $y_k^{(2)}$.

Il procedimento:
1. sdoppia il segnale in ingresso;
2. introduce un ritardo su uno dei percorsi;
3. combina simboli correnti e precedenti;
4. rappresenta un simbolo mediante due simboli codificati;
5. restringe lo spettro occupato dal segnale.

![[Pasted image 20260607115527.png|700]]
Il prezzo della riduzione dello spettro è l’introduzione di memoria: il simbolo prodotto non dipende soltanto dal bit corrente, ma anche dai bit elaborati negli intervalli precedenti. Raddoppiando il numero di bit per rappresentare un bit d’informazione, gli errori peseranno meno sull'informazione complessiva

###### Trellis Coded Modulation
La **Trellis Coded Modulation** introduce ridondanza e limita le successioni di simboli ammesse. in questo esempio un bit informativo produce due bit codificati e il codificatore viene descritto mediante un automa a quattro stati: $0$, $1$, $2$ e $3$.

Le etichette delle transizioni hanno la forma **ingresso/uscita**: ![[Pasted image 20260607120354.png|700]]
Poiché da ogni stato sono possibili soltanto alcune transizioni, non tutte le sequenze di coppie di bit costituiscono una codifica valida. Il ricevitore può quindi sfruttare sia i simboli osservati sia la coerenza dell’intera sequenza per individuare eventuali errori. La distanza di Hamming tra le coppie ricevute e quelle associate ai diversi percorsi fornisce la metrica utilizzata nella decodifica.

###### Decodifica mediante algoritmo di Viterbi
L’**algoritmo di Viterbi** usa l'automa a stati finiti della Trellis per decodificare, per ogni ramo viene calcolata la **distanza di Hamming**, cioè il numero di bit differenti. Tale distanza viene sommata alla metrica del percorso precedente. Quando più percorsi raggiungono lo stesso stato, viene conservato soltanto quello con metrica cumulativa minore, detto **percorso superstite**. Al termine viene scelto il percorso complessivamente meno distante dalla sequenza ricevuta. ![[Pasted image 20260607125701.png|700]]
- la sequenza informativa è: $011001$
- Il codificatore produce: $00\ 11\ 01\ 01\ 11\ 11$
- Dopo la trasmissione viene ricevuta la sequenza: $01\ 11\ 01\ 11\ 11\ 11$
La prima e la quarta coppia differiscono dalla sequenza codificata. Partendo dallo stato $0$, le metriche superstiti evolvono nel seguente modo:
![[Pasted image 20260607131803.png|500]]
La metrica finale minima è $D=2$ nello stato $2$. Il percorso corrispondente ricostruisce la sequenza iniziale $011001$, nonostante le due alterazioni introdotte durante la trasmissione. 
![[Pasted image 20260607131843.png|500]]
Questa codifica migliora l’affidabilità, ma non garantisce la correzione di qualsiasi errore. Se il disturbo è troppo elevato, il frame può risultare comunque danneggiato; il controllo finale del frame permette di rilevarlo e l’eventuale ritrasmissione può essere gestita dai protocolli dei livelli superiori.


### Switch, Hub, Bridge, router e VLAN
###### Funzionamento del bridge
Il **bridge** riceve una trama su una delle proprie porte, ne esamina gli indirizzi **MAC sorgente** e **MAC destinazione** e consulta una tabella che associa ciascun indirizzo MAC alla porta attraverso cui il dispositivo corrispondente è raggiungibile. La tabella viene costruita dinamicamente mediante **autoapprendimento**: ogni volta che il bridge riceve una trama, registra l’indirizzo MAC sorgente e la porta di ingresso. In questo modo apprende progressivamente la posizione dei dispositivi senza richiedere una configurazione manuale.

Dopo aver appreso l’indirizzo sorgente, il bridge decide come trattare la trama in base all’indirizzo destinazione. Se la destinazione è presente nella tabella e si trova su una porta diversa da quella di ingresso, la trama viene inoltrata esclusivamente su quella porta. Se sorgente e destinazione appartengono allo stesso segmento, il bridge filtra la trama e non la inoltra sulle altre porte. Se, invece, l’indirizzo destinazione non è ancora conosciuto, la trama viene replicata su tutte le porte tranne quella da cui è arrivata. Lo stesso comportamento viene adottato per le trame broadcast.

Nell’esempio mostrato, quando il nodo $A$ invia inizialmente una trama al nodo $H$, i bridge apprendono progressivamente su quali porte è raggiungibile $A$; poiché la posizione di $H$ non è ancora nota, la trama viene inoltrata sui diversi segmenti della rete.

![[Pasted image 20260607132744.png|400]]
![[Pasted image 20260607132804.png|400]]
![[Pasted image 20260607132818.png|400]]
![[Pasted image 20260607132831.png|400]]
Quando $H$ risponde, i bridge apprendono anche la sua posizione e possono inoltrare la risposta soltanto lungo il percorso necessario per raggiungere $A$.

![[Pasted image 20260607132855.png|400]]
![[Pasted image 20260607132904.png|400]]
![[Pasted image 20260607132918.png|400]]
La presenza di collegamenti ridondanti può tuttavia provocare la duplicazione e la circolazione delle trame tra i bridge, poiché una rete Ethernet non impedisce autonomamente la formazione di percorsi ciclici.

![[Pasted image 20260607132953.png|400]]
![[Pasted image 20260607133002.png|400]]
![[Pasted image 20260607133014.png|400]]
###### Funzionamento degli switch
Il ruolo di uno **switch** è ricevere i frame in ingresso e inoltrarli sui collegamenti in uscita. Lo switch è trasparente ai nodi: un nodo indirizza il frame a un altro nodo e lo immette nella LAN senza sapere che uno switch riceverà il frame e provvederà a inoltrarlo.

La velocità con cui i frame raggiungono una determinata interfaccia di uscita può temporaneamente superare la capacità del collegamento associato a quell'interfaccia. Per questo motivo lo switch utilizza buffer nei quali conservare temporaneamente i frame.

**Filtraggio:** funzionalità mediante la quale lo switch determina se un frame debba essere inoltrato attraverso una determinata interfaccia oppure scartato.

**Inoltro:** operazione con cui lo switch individua l’interfaccia verso cui il frame deve essere diretto e lo invia attraverso tale interfaccia.

Le operazioni di filtraggio e inoltro vengono eseguite utilizzando una **tabella di commutazione**. La tabella contiene voci relative ad alcuni nodi della LAN, ma non necessariamente a tutti. Ogni voce comprende:
1. l’indirizzo MAC del nodo;
2. l’interfaccia dello switch che conduce al nodo;
3. il momento in cui la voce relativa al nodo è stata inserita nella tabella.

Si consideri un frame con indirizzo MAC di destinazione `DD-DD-DD-DD-DD-DD`, ricevuto dallo switch attraverso l’interfaccia $x$. Lo switch cerca tale indirizzo nella propria tabella di commutazione. Possono verificarsi tre casi.
1. **L’indirizzo non è presente nella tabella.** Lo switch invia una copia del frame ai buffer di uscita di tutte le interfacce, eccetto l’interfaccia $x$ dalla quale il frame è arrivato. In altre parole, se non esiste una voce per l’indirizzo di destinazione, lo switch trasmette il frame in broadcast.
2. **La tabella associa l’indirizzo `DD-DD-DD-DD-DD-DD` all’interfaccia $x$.** Il frame proviene dallo stesso segmento di rete nel quale si trova la scheda di destinazione. Non è quindi necessario inoltrarlo verso un’altra interfaccia e lo switch esegue il filtraggio scartando il frame.
3. **La tabella associa l’indirizzo `DD-DD-DD-DD-DD-DD` a un’interfaccia $y$, con $y \neq x$.** Il frame deve essere inoltrato al segmento di LAN collegato all’interfaccia $y$. Lo switch esegue quindi l’inoltro inserendo il frame nel buffer dell’interfaccia $y$.

###### Autoapprendimento e aging delle tabelle
Uno switch può costruire automaticamente, dinamicamente e autonomamente la propria tabella, senza l’intervento di un operatore o di un protocollo di configurazione. Per questo motivo si afferma che gli switch sono dispositivi ad **autoapprendimento**.
Il processo avviene nel modo seguente:
1. inizialmente la tabella di commutazione è vuota;
2. per ogni frame ricevuto, lo switch registra l’indirizzo MAC contenuto nel campo Indirizzo sorgente, l’interfaccia dalla quale il frame è arrivato e il momento dell’arrivo;
3. in questo modo lo switch individua il segmento LAN nel quale si trova il nodo trasmittente;
4. quando tutti i nodi della LAN hanno trasmesso almeno un frame, la tabella può contenere le relative associazioni.

Quando lo switch non riceve frame da un determinato indirizzo sorgente per un certo intervallo, chiamato **aging time** o tempo di invecchiamento, elimina la relativa voce dalla tabella. Se un computer viene sostituito con un altro dotato di una diversa scheda di rete, l’indirizzo MAC del computer precedente viene quindi rimosso automaticamente.

Gli switch sono dispositivi **plug-and-play**, perché non richiedono interventi da parte dell’amministratore di rete o dell’utente. È sufficiente collegare i segmenti di LAN alle interfacce dello switch, senza configurare manualmente le tabelle al momento dell’installazione o quando un host viene rimosso da un segmento.

###### Vantaggi delle LAN commutate
L’utilizzo degli switch presenta diversi vantaggi rispetto ai collegamenti broadcast, come i bus o le topologie a stella basate su hub.
- **Eliminazione delle collisioni:** in una LAN composta da switch e priva di hub non si verifica uno spreco di banda dovuto alle collisioni. Gli switch inseriscono i frame nei buffer e non trasmettono più di un frame alla volta su ciascun segmento di LAN.
- **Collegamenti eterogenei:** poiché lo switch isola un collegamento dagli altri, i vari collegamenti della LAN possono operare a velocità differenti e utilizzare mezzi trasmissivi diversi.
- **Gestione:** oltre a fornire maggiore sicurezza, uno switch facilita la gestione della rete. Se una scheda di rete presenta un malfunzionamento e trasmette continuamente frame Ethernet, lo switch può individuare il problema e disconnettere internamente la scheda non funzionante.

###### Confronto tra switch e router
I **router** sono commutatori di pacchetti store-and-forward che inoltrano i pacchetti utilizzando indirizzi del livello di rete. Anche gli switch sono commutatori store-and-forward, ma si distinguono dai router perché inoltrano i frame utilizzando gli indirizzi MAC.

I router sono quindi commutatori di pacchetto di **livello 3**, mentre gli switch sono commutatori di pacchetto di **livello 2**. I moderni switch che operano secondo la modalità **match-action** possono tuttavia essere impiegati sia per inoltrare frame di livello 2 sulla base dell’indirizzo MAC di destinazione, sia per inoltrare datagrammi di livello 3 utilizzando l’indirizzo IP di destinazione.

Gli switch sono dispositivi plug-and-play e possono offrire capacità elevate di filtraggio e inoltro. Devono inoltre elaborare i pacchetti soltanto fino al livello 2, mentre i router devono elaborarli fino al livello 3.

![[Pasted image 20260607105202.png|700]]

Inoltre, gli switch non offrono protezione contro le **tempeste di broadcast**: se un host iniziasse a trasmettere un flusso ininterrotto di pacchetti broadcast, gli switch continuerebbero a inoltrarli, provocando il collasso della rete.

Gli indirizzi di rete utilizzati dai router sono spesso gerarchici, a differenza degli indirizzi MAC, descritti nel testo come lineari. Generalmente i pacchetti non percorrono cicli attraverso i router, anche quando la rete dispone di percorsi ridondanti. I cicli possono comunque verificarsi se le tabelle dei router sono configurate in modo errato. IP utilizza uno specifico campo dell’intestazione del datagramma per limitare la percorrenza di tali cicli.

Poiché i router non sono soggetti alle restrizioni imposte dalla topologia ad albero, Internet può utilizzare una topologia più ricca, comprendente, per esempio, collegamenti multipli tra Europa e Nord America. A differenza degli switch, i router proteggono dalle tempeste di broadcast di livello 2. Non sono però dispositivi plug-and-play: il loro indirizzo IP e quello degli host a essi collegati devono essere configurati.

Nelle reti composte al massimo da alcune centinaia di host e da pochi segmenti, gli switch sono generalmente sufficienti. Essi localizzano il traffico e incrementano il throughput aggregato senza richiedere la configurazione degli indirizzi IP.

Le reti più grandi, composte da migliaia di host, comprendono invece tipicamente sia switch sia router. I router forniscono un isolamento più efficace del traffico, evitano le tempeste di broadcast e utilizzano percorsi più funzionali tra gli host della rete.

###### Problemi delle LAN gerarchiche
![[Pasted image 20260607105240.png|700]]

Le LAN istituzionali moderne sono spesso configurate in modo gerarchico: ogni gruppo dispone di una propria LAN commutata, collegata alle LAN degli altri gruppi mediante una gerarchia di switch. Questa configurazione funziona bene in un ambiente ideale, ma presenta alcuni inconvenienti nelle reti reali.
- **Mancanza di isolamento del traffico:** sebbene la gerarchia localizzi il traffico interno di un gruppo su un singolo switch, il traffico broadcast, come i frame che trasportano messaggi ARP e DHCP, deve comunque attraversare l’intera rete istituzionale. Le prestazioni della LAN migliorerebbero se il campo di diffusione del traffico broadcast potesse essere limitato. Tale limitazione è importante anche per ragioni di sicurezza e riservatezza.
- **Uso inefficiente degli switch:** se l’istituzione fosse composta da 10 gruppi anziché da 3, sarebbero necessari 10 switch di primo livello, ossia gli switch che raccolgono i gruppi di host. Se ciascun gruppo comprendesse meno di 10 persone, un unico switch a 96 porte potrebbe essere sufficiente dal punto di vista della capacità, ma non fornirebbe isolamento del traffico.
- **Gestione degli utenti:** se un dipendente si spostasse da un gruppo a un altro, sarebbe necessario modificare la posa della rete per collegarlo a un diverso switch della Figura 6.15. La presenza di dipendenti appartenenti contemporaneamente a più gruppi renderebbe il problema ancora più complesso.

###### VLAN basate sulle porte
Le difficoltà delle LAN gerarchiche possono essere superate utilizzando uno switch che supporti una **VLAN - Virtual Local Area Network**, realizzata su una singola infrastruttura fisica di rete locale.

Gli host appartenenti a una VLAN comunicano tra loro come se fossero tutti collegati allo stesso switch. In una **VLAN basata sulle porte**, il gestore di rete divide le porte dello switch in gruppi. Ciascun gruppo costituisce una VLAN e le sue porte formano un dominio broadcast separato.

![[Pasted image 20260607111247.png|700]]

La Figura 6.25 mostra uno switch dotato di 16 porte. Le porte dalla 2 alla 8 appartengono alla VLAN del dipartimento di Ingegneria elettronica, mentre le porte dalla 9 alla 15 appartengono alla VLAN del dipartimento di Informatica.
Questa configurazione risolve i problemi precedentemente descritti:
- i frame delle due VLAN sono isolati;
- i due switch della Figura 6.15 vengono sostituiti da un singolo switch fisico;
- se l’utente collegato alla porta 8 entra a far parte del dipartimento di Informatica, il gestore di rete può riconfigurare il software della VLAN e associare la porta 8 alla VLAN di Informatica, senza modificare fisicamente il cablaggio.

###### Comunicazione tra VLAN

L’isolamento completo delle VLAN introduce un nuovo problema: permettere la trasmissione del traffico dal dipartimento di Ingegneria elettronica a quello di Informatica.

Una possibile soluzione consiste nel collegare una porta dello switch VLAN, per esempio la porta 1 della Figura 6.25, a un router esterno e configurarla in modo che appartenga a entrambe le VLAN. Anche se i due dipartimenti condividono lo stesso switch fisico, dal punto di vista logico la configurazione appare come due switch separati collegati tramite un router.

Un datagramma IP diretto dal dipartimento di Ingegneria elettronica a quello di Informatica attraversa prima la VLAN di Ingegneria per raggiungere il router. Il router inoltra quindi il datagramma all’host di destinazione appartenente alla VLAN di Informatica.

I produttori di switch semplificano questa configurazione offrendo dispositivi che comprendono sia le funzioni di uno switch sia quelle di un router, evitando così la necessità di installare un router esterno separato..

###### Interconnessione di switch VLAN e trunking
![[Pasted image 20260607105334.png|700]]
La Figura 6.26 mostra un secondo switch con 8 porte, ciascuna configurata come appartenente alla VLAN di Ingegneria elettronica oppure alla VLAN di Informatica.

Una soluzione semplice per collegare i due switch consiste nel configurare su ciascuno di essi una porta appartenente alla VLAN di Informatica e nel collegare direttamente le due porte, come mostrato nella Figura 6.26(a). Lo stesso procedimento dovrebbe essere ripetuto per ciascuna VLAN.

Questa soluzione non è scalabile: con $N$ VLAN sarebbero necessarie $N$ porte su ciascuno switch soltanto per realizzare l’interconnessione tra i due dispositivi.

Un approccio più scalabile è il **VLAN trunking**. Come mostrato nella Figura 6.26(b), su ogni switch viene configurata una porta speciale, detta **porta di trunking**, utilizzata per interconnettere gli switch VLAN. Una singola connessione di trunk può quindi trasportare frame appartenenti a VLAN differenti.

Il trunking introduce però la necessità di determinare a quale VLAN appartenga ciascun frame ricevuto sulla porta di trunk. A questo scopo IEEE ha definito nello standard **802.1Q** un formato Ethernet esteso per i frame che attraversano un trunk VLAN.

###### Formato Ethernet IEEE 802.1Q
Il frame 802.1Q è costituito dal frame Ethernet standard, al quale viene aggiunta nell'intestazione un’**etichetta VLAN**, o **VLAN tag**, lunga quattro byte. L’etichetta trasporta l’identità della VLAN alla quale appartiene il frame.

![[Pasted image 20260607105427.png|700]]

L’etichetta VLAN viene aggiunta al frame dallo switch sul lato trasmittente del trunk. Sul lato ricevente, lo switch esamina l’etichetta per determinare la VLAN del frame e successivamente la rimuove.

L’etichetta VLAN comprende:
- un campo **TPID - Tag Protocol Identifier** di due byte, con valore esadecimale fisso `81-00`;
- un campo **Tag Control Information** di due byte;
- all’interno del Tag Control Information, un campo di identificazione della VLAN lungo 12 bit;
- un campo di priorità lungo 3 bit, simile al campo TOS del datagramma IP.
