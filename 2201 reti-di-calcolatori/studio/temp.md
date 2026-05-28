Ci sono cose da vedere da riassunto:
- IPV4 header
- cose in più dopo questa linea
- ARP
### Funzioni fondamentali del livello di rete

Nel precedente capitolo abbiamo visto come il livello di trasporto garantisca la comunicazione tra processi, appoggiandosi ai servizi sottostanti senza preoccuparsi di come vengano realizzati. Ora ci addentriamo nel livello di rete per capire esattamente come venga fornito questo servizio di comunicazione _host-to-host_.

Data la sua complessità, la visione moderna del networking divide il livello di rete in due parti strettamente interagenti: il **piano dei dati** (_data plane_) e il **piano di controllo** (_control plane_).

###### Le Funzioni Fondamentali: Inoltro e Instradamento
Il ruolo principale del livello di rete è trasferire i pacchetti da un host a un altro. Per raggiungere questo obiettivo, il sistema fa affidamento su due funzioni ben distinte:
- **Inoltro (** _Forwarding_ **):** È l'azione locale e fulminea con cui un router, non appena riceve un pacchetto, lo trasferisce dalla sua interfaccia di ingresso a quella di uscita più appropriata. Poiché avviene su scale temporali minuscole (nell'ordine dei nanosecondi), questa funzione è tipicamente implementata direttamente in hardware e rappresenta il cuore del piano dei dati.
- **Instradamento (** _Routing_ **):** È il processo globale di rete che determina l'intero percorso che i pacchetti dovranno seguire nel loro viaggio dalla sorgente alla destinazione, avvalendosi di specifici algoritmi. Avvenendo su scale temporali più lunghe (nell'ordine dei secondi), l'instradamento è generalmente implementato in software nel piano di controllo.

Per collegare queste due funzioni, i router utilizzano un elemento chiave: la **tabella di inoltro** (_forwarding table_). Il router estrae i valori da uno o più campi dell'intestazione del pacchetto (come l'indirizzo di destinazione) e li utilizza come indice per consultare questa tabella, scoprendo così verso quale interfaccia di uscita dirigere il pacchetto. In sintesi, è proprio l'algoritmo di instradamento a determinare i valori che andranno a popolare le tabelle di inoltro.

![[Pasted image 20260527181325.png|700]]

In uno scenario ipotetico, potremmo persino immaginare una rete senza alcun protocollo di instradamento, in cui operatori fisicamente presenti configurano manualmente le tabelle affinché i pacchetti raggiungano le destinazioni. Questo ci porta a esplorare l'evoluzione del piano di controllo.

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

Quando si verificano corrispondenze multiple per un singolo indirizzo, il router adotta la **regola di corrispondenza a prefisso più lungo** (_longest prefix match_): cerca la riga con il prefisso corrispondente più specifico (più lungo) e instrada il pacchetto sull'interfaccia associata. Considerando che a tassi di trasmissione Gigabit questa ricerca va fatta in nanosecondi, si rende necessario l'uso di hardware dedicato (come le memorie TCAM) per andare oltre la semplice ricerca lineare. Oltre a questo, la porta di ingresso si occupa di gestire il checksum, il tempo di vita (TTL) del pacchetto e i contatori di rete.

###### La struttura di commutazione
Una volta stabilita l'interfaccia di uscita, il pacchetto attraversa la struttura di commutazione. Esistono tre architetture principali:
- **Commutazione in memoria:** Tipica dei primi router (che erano essenzialmente calcolatori tradizionali). Il pacchetto veniva copiato dalla porta di ingresso nella memoria di sistema, elaborato dalla CPU e copiato nella porta di uscita. Il throughput massimo è limitato dalla banda della memoria: se la memoria permette $B$ operazioni al secondo, il throughput è inferiore a $B/2$. Limite principale: si può inoltrare un solo pacchetto alla volta.
- **Commutazione tramite bus:** Le porte di ingresso inviano il pacchetto direttamente alle porte di uscita attraverso un bus condiviso, aggiungendo un'etichetta interna temporanea per indicare la porta di destinazione. Poiché il bus è unico, se arrivano più pacchetti contemporaneamente, tutti tranne uno dovranno attendere.
- **Commutazione attraverso rete di interconnessione (** _Crossbar_ **):** Per superare i limiti del singolo bus, si usa una matrice composta da $2n$ bus (intersecando i bus verticali di ingresso con quelli orizzontali di uscita). Questa struttura è definita _non-blocking_: un pacchetto viene bloccato solo se un altro pacchetto sta già viaggiando verso la sua _stessa_ porta di uscita. Permette l'inoltro di più pacchetti in parallelo. Strutture moderne scalano usando più reti di questo tipo in parallelo.
###### Accodamento (_Queuing_) e Gestione della Memoria
Le code di pacchetti si formano inevitabilmente quando il tasso di arrivo del traffico supera temporaneamente la velocità con cui il router riesce a smaltirlo. Se i buffer si riempiono completamente, i pacchetti in eccesso vengono persi. Questo fenomeno può verificarsi in due punti nevralgici:

![[Pasted image 20260527181450.png|700]]

1. **Accodamento alle porte di ingresso:** Avviene se la struttura di commutazione non è abbastanza veloce da trasferire senza ritardo tutti i pacchetti in arrivo.
    - In questo scenario può verificarsi il **blocco in testa alla coda** (_Head-of-Line blocking_, **HOL**): un pacchetto nella coda di ingresso deve attendere perché è bloccato da un pacchetto davanti a lui che sta aspettando che si liberi una porta di uscita contesa, anche se la destinazione del nostro pacchetto bloccato sarebbe in realtà libera.
![[Pasted image 20260527181507.png|700]]
2. **Accodamento alle porte di uscita:** Anche se la struttura di commutazione è velocissima, potrebbe trasferire simultaneamente molteplici pacchetti verso la medesima porta di uscita. Poiché la porta può trasmettere un solo pacchetto per volta sul cavo fisico, i pacchetti si accodano. ![[Pasted image 20260527181524.png|700]]
Quando la memoria del buffer in uscita si esaurisce, il router deve prendere delle decisioni. Può semplicemente scartare l'ultimo arrivato (politica **drop-tail**) o applicare algoritmi di **gestione attiva della coda (** _Active Queue Management_, **AQM**). Un celebre algoritmo AQM è il **RED** (_Random Early Detection_), che inizia a scartare o marcare pacchetti ancor prima che il buffer sia pieno, in modo da inviare precocemente un segnale di congestione al mittente.

**Ma quanta memoria di buffer è necessaria?**
Per anni, la regola empirica affermava che la dimensione del buffer ($B$) dovesse eguagliare il tempo medio di round-trip ($RTT$) moltiplicato per la capacità del link ($C$):
$$B = RTT \cdot C$$
Oggi, con la presenza di un vasto numero di flussi TCP indipendenti ($N$), gli studi suggeriscono che la quantità di buffer necessaria segua una proporzione differente $$B = RTT \times C/\sqrt{N}$$
Va inoltre considerato che buffer più grandi assorbono meglio le fluttuazioni, ma introducono ritardi di accodamento molto maggiori, penalizzando il traffico in tempo reale (come il gaming o le videoconferenze) e rendendo il protocollo TCP molto più lento a reagire alla congestione.

###### Schedulazione dei Pacchetti
Quando più pacchetti sono in attesa su una porta di uscita, uno **schedulatore di pacchetti** deve decidere in quale ordine trasmetterli. Generalmente si adotta una modalità _conservativa_: il collegamento non resta mai inattivo se c'è almeno un pacchetto in coda. Esistono diverse politiche di schedulazione:
- **First-In-First-Out (FIFO / FCFS):** Il modello più intuitivo. I pacchetti vengono trasmessi nell'esatto ordine in cui sono arrivati. Se la coda è piena, si applicano le politiche di scarto discusse precedentemente.
![[Pasted image 20260527181644.png|700]]
- **Code con priorità (** _Priority Queuing_ **):** I pacchetti vengono suddivisi in classi di priorità (ad esempio, il traffico VoIP o i dati di gestione di rete hanno priorità alta rispetto a una semplice email). Lo schedulatore trasmette sempre i pacchetti della classe a priorità maggiore; a parità di priorità, agisce come un FIFO. Se configurato _senza prelazione_, la trasmissione di un pacchetto (anche a bassa priorità) non viene mai interrotta a metà se ne arriva uno ad alta priorità. ![[Pasted image 20260527181718.png|700]]
- **Round Robin:** I pacchetti sono divisi in classi, ma senza una rigida priorità assoluta. Lo schedulatore si alterna ciclicamente tra le classi (es. invia un pacchetto della classe 1, poi uno della classe 2, e ricomincia). Se una coda è vuota, passa immediatamente alla successiva. ![[Pasted image 20260527181738.png|700]]
- **Accodamento equo ponderato (** _Weighted Fair Queuing_, **WFQ):** È una forma generalizzata e avanzata del Round Robin. I pacchetti sono classificati in code distinte e serviti in modo ciclico e conservativo, ma in modo differenziato. A ciascuna classe $i$ viene assegnato un peso $w_i$. Questo sistema garantisce matematicamente che ogni classe riceva una frazione di servizio pari a: $$\frac{w_i}{\sum w_j}$$Di conseguenza, su un collegamento con capacità trasmissiva totale $R$, alla classe $i$ sarà garantito un rendimento minimo di: $$R \cdot \frac{w_i}{\sum w_j}$$_(dove il denominatore somma i pesi di tutte le classi che hanno pacchetti pronti da trasmettere)._
![[Pasted image 20260527181816.png|700]]

### Protocollo Internet (IP)