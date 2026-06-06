### Protocolli di accesso multiplo nei canali broadcast

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

Nel **Taking Turns Protocol**, i nodi che vogliono trasmettere segnalano la richiesta inviando $1$ sul canale e vengono inseriti in un anello logico.

Il primo nodo dell’anello trasmette e, dopo un intervallo $T$, passa un **token** al nodo successivo. Solo il nodo che possiede il token può utilizzare il canale, quindi non si verificano collisioni.

Il protocollo presenta però due problemi: il guasto di un nodo può interrompere il passaggio del token e tutti i nodi della sottorete devono essere inclusi correttamente nell’anello logico per poter trasmettere.