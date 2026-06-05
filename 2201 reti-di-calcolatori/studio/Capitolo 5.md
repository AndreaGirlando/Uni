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
