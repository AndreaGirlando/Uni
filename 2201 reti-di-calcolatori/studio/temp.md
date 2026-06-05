### Routing in internet

Per facilitare il routing in Internet, quest’ultimo è organizzato in **sistemi autonomi** (AS). Ogni sistema autonomo è trattato come una singola entità amministrativa.
- All’interno di sistema autonomo, tutti i router eseguono lo stesso algoritmo di routing, chiamato **protocollo di instradamento intra-AS**.
- Per l’instradamento tra AS distinti si usano invece **protocolli di instradamento inter-AS**.

Questa organizzazione in sistemi autonomi, garantisce una maggiore **autonomia amministrativa** e migliore **scalabilità**. Ogni sistema autonomo è identificato da un **numero di sistema autonomo** (ASN).
###### RIP - Routing Information Protocol (intra-AS)
È un protocollo di routing basato sull’algoritmo **Distance Vector** (Bellman-Ford) per il routing interno ai sistemi autonomi. La sua metrica è il **numero di hop**, ovvero il numero di router da attraversare per raggiungere una determinata destinazione.
- Supporta al più 15 hop. Una destinazione $x$ con $d.x=16$ hop è irraggiungibile.
- I router scambiano informazioni relative alle tabelle di routing ogni 30 secondi.
- Un percorso non aggiornato per 180 secondi è marcato come irraggiungibile.
- Dopo altri 120 secondi viene rimosso dalla tabella (garbage collection).

Sfrutta inoltre due tipi di messaggi:
- `REQUEST` per richiedere informazioni di routing ai router vicini.
- `RESPONSE` per fornire aggiornamenti sulla propria tabella di routing.

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
- **Comunicare la raggiungibilità delle sotto reti.**  
    Permettendo a ciascun sistema di rendersi visibile rispetto i **prefissi di rete** che gestisce. È tramite BGP che tutti i router conoscono le sottoreti vicine.
- **Determinare i percorsi ottimali verso le sottoreti.**  
    Un router può apprendere più percorsi verso un **determinato prefisso** (ovvero una sottorete). La selezione del percorso migliore avviene in base alle politiche del sistema autonomo e alle informazioni di raggiungibilità fornite da BGP.

###### Funzionamento di BGP
Lo scambio di informazioni avviene tramite dei messaggi scambiati, per ogni coppia di router comunicante, in una sessione TCP. Tra router dello stesso sistema autonomo, sono dette sessioni **iBGP**. Altrimenti, si dice sessione **eBGP**. ![[Pasted image 20260605195557.png|700]]
Supponiamo si voglia **dichiarare la raggiungibilità del prefisso $x$**. L’annuncio di raggiungibilità verrà passato ai nodi adiacenti, che costruiranno una tabella BGP contenente alcuni attributi, tra cui:
- **AS-PATH:** indica i sistemi autonomi tramite cui è passato questo annuncio.
- **NEXT-HOP:** indica l’IP dell’interfaccia di rete tramite cui ”entrare” nel primo sistema autonomo dell’AS-PATH.
- Il prefisso $x$ da raggiungere.
L’insieme prefisso $x$ + attributi è detto _route_, **rotta**. Valutando ogni NEXT-HOP secondo una metrica stabilita, i router possono stabilire il percorso migliore. ![[Pasted image 20260605195625.png]]