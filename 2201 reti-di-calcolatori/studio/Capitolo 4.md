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