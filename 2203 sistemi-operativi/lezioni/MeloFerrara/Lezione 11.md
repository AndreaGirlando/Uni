# Scheduling dei Thread

Nella teoria non cambia molto: si sceglie un processo e poi si schedulano i suoi thread. In pratica, però, lo scheduling nei sistemi moderni avviene per **thread** invece che per processi.

- **Costo del context switch:** Nei thread kernel bisogna considerare il costo del passaggio da un thread all'altro.

- **Inefficienza:** Un context switch tra thread di processi diversi è oneroso.

    - _Esempio:_ Se ho $P_1(A, B, C)$ e $P_2(X, L)$, schedulare la sequenza $A - X - B - Z - C$ è inefficiente poiché avvengono troppi passaggi tra processi distinti.

- **Thread Utente:** Si possono usare algoritmi senza prelazione. Ogni thread ha la sua priorità, che dipende anche dalla priorità dell'intero processo a cui appartiene.

---
# Scheduling su Sistemi Multicore

In un sistema con più core (es. 4 core), si possono seguire due approcci principali:
## 1. Multielaborazione Asimmetrica

- Un core funge da **MASTER** e gli altri da **SLAVE**.

- Il **Master** coordina il Sistema Operativo (SO), gestisce le strutture dati e impartisce istruzioni agli slave. Si occupa anche interamente dello scheduling.

- I core **Slave** eseguono i thread utente assegnati dal Master.

> [!success] Vantaggi
> 
> - Riduzione dei problemi di concorrenza, poiché un unico core orchestra l'intero sistema.
>     

> [!danger] Svantaggi
> 
> - **Scalabilità:** L'approccio non è ottimale all'aumentare del numero di core, poiché il Master diventa un collo di bottiglia.
>     

## 2. Multielaborazione Simmetrica (SMP)

Ogni core può svolgere qualsiasi ruolo (thread utente, gestione strutture dati, ecc.). Esistono due modi per gestire le code:

### Coda Unica

- Tutti i processi/thread sono in un'unica coda.

- **Svantaggio:** Problemi di concorrenza. Se un core si libera e accede alla coda (ponendo un _lock_), un altro core che si libera contemporaneamente deve attendere che il primo finisca.

### Coda per Core (Scelta Migliore)

- Ogni core ha la sua coda dedicata.

- **Vantaggio Cache:** Quando un processo viene eseguito su un core, i registri e la cache di quel core si riempiono di dati relativi a quel processo. Mantenere il processo sullo stesso core favorisce il **cache hit** alla successiva esecuzione.

---
# Affinità del Processore

Nei sistemi multicore, spostare un processo $P_1$ dal core $C_1$ al core $C_2$ vanifica i benefici della cache. Idealmente, un processo dovrebbe essere associato a un unico core.

Si distinguono due tipi di affinità (o predilezione):

- **Predilezione Debole:** Il SO tenta di schedulare un processo sulla stessa coda/core, ma non vi è alcuna garanzia.

- **Predilezione Forte:** Il processo viene forzato su una determinata coda o core (solitamente su richiesta esplicita dell'utente/programmatore).


> [!info] Bilanciamento del Carico
> 
> La predilezione non deve contrastare il principio del **bilanciamento del carico** (_load balancing_), per cui ogni core deve avere una mole di lavoro simile.
### Meccanismi di Migrazione (per code separate)

Per correggere i disequilibri tra le code, si usano due tecniche:

1. **Migrazione Guidata (Push Migration):** Una routine del SO controlla periodicamente le code. Se individua un disequilibrio palese, "spinge" i processi da una coda all'altra (richiede _lock_ sulle code).

2. **Migrazione Spontanea (Pull Migration):** Un processore che si ritrova con la coda vuota "pesca" o "tira" un processo da una coda di un altro processore sovraccarico.

# Gestione della Memoria Centrale

La memoria viene gestita attraverso **indirizzi**. Esiste una gerarchia di memoria (dalla più veloce alla più lenta) che il Sistema Operativo deve coordinare per ottimizzare le prestazioni.

## 1. Evoluzione della Gestione degli Indirizzi

### A. Senza Astrazione

I programmi utilizzano direttamente gli **indirizzi fisici**.

- **Contesto:** Utilizzata in sistemi semplici (es. primi computer o sistemi embedded) dove non servivano strutture dati complicate.

- **Modelli:** Variano in base alla costruzione fisica dei dispositivi.

### B. Multiprogrammazione senza Astrazione

Più programmi risiedono contemporaneamente in RAM usando indirizzi fisici. Questo solleva due problemi critici:

1. **Rilocazione (Relocation):** Il programmatore non sa dove il programma verrà caricato. Se il codice punta all'indirizzo `100` ma viene caricato al `2000`, il programma crasha.

    - **Soluzione Statica:** Il **loader** modifica gli indirizzi nel codice al momento del caricamento, sommandovi l'indirizzo di base.

2. **Protezione (Protection):** Un processo potrebbe scrivere per errore nella memoria di un altro o del SO.

    - **Soluzione (Lock & Key):** La memoria è divisa in blocchi. Ogni blocco ha una "chiave" numerica. Il processo accede solo se la sua chiave nel registro di stato corrisponde a quella del blocco.  

---
## 2. Astrazione dello Spazio di Indirizzi

Viene creato uno **spazio di indirizzi logico** per ogni processo, permettendo a ciascuno di "credere" di partire dall'indirizzo `0`.
### Meccanismi Hardware (MMU)

La traduzione da indirizzo logico a fisico è gestita dalla **MMU** (_Memory Management Unit_) tramite:

- **Registro Base:** Contiene l'indirizzo fisico di partenza. $$Indirizzo_{Fisico} = Indirizzo_{Logico} + Registro_{Base}$$
  Sotto la condizione che:

$$0 \le Indirizzo_{Logico} < Registro_{Limite}$$
- **Registro Limite:** Definisce la dimensione massima del processo. Se il processo tenta di accedere a un indirizzo superiore al limite, il SO genera una **trap** e termina il processo.

---
## 3. Swapping

Quando la RAM è piena, interviene lo **swapper** (scheduler di medio termine).

- **Swap-out:** Un processo inattivo viene spostato temporaneamente sul disco (**Backing Store**).

- **Swap-in:** Un nuovo processo viene caricato dal disco nello spazio liberato.

> [!warning] Problema dell'I/O Pendente
> 
> Se un processo viene "swappato" mentre attende un'operazione di I/O, la periferica potrebbe scrivere dati in un'area di RAM che ora appartiene a un altro processo.
> 
> **Soluzione:** Il SO deve **ancorare** (pinning) i programmi impegnati in operazioni di I/O per evitarne lo spostamento.

---
## 4. Frammentazione della Memoria

La **frammentazione della memoria** è un fenomeno inefficiente che si verifica quando la memoria libera viene suddivisa in piccoli blocchi non contigui, rendendo difficile o impossibile allocare spazio per nuovi processi, anche se la quantità totale di memoria libera sarebbe teoricamente sufficiente.
In parole povere: è come avere un armadio con tanti piccoli spazi vuoti sparsi tra i vestiti; hai abbastanza spazio totale per una scatola grande, ma non hai un unico buco abbastanza grande dove infilarla.

L'allocazione dinamica della memoria porta a sprechi di spazio(frammentazione):

|**Tipo di Frammentazione**|**Descrizione**|
|---|---|
|**Interna**|Spreco _dentro_ la partizione assegnata al processo (causato dall'arrotondamento ai blocchi).|
|**Esterna**|Presenza di piccoli "buchi" tra i processi. La somma dei buchi basterebbe per un programma, ma lo spazio non è contiguo.|

> [!tip] Memory Compaction
> 
> Il SO riorganizza la RAM "schiacciando" i processi verso un'estremità per unire i buchi. È efficace ma **molto costosa** in termini di CPU.

---
## 5. Contabilità della Memoria

Il SO deve sapere quali zone sono libere (H - Hole) e quali occupate (P - Process).

### Metodo 1: Bitmap (Mappa di bit)

La memoria è divisa in unità di allocazione. Un bit indica se l'unità è libera (0) o occupata (1).

- **Trade-off:** Un'unità piccola riduce la frammentazione interna ma rende la bitmap enorme. Un'unità grande spreca spazio (frammentazione interna).
### Metodo 2: Liste Concatenate

Usa una lista (spesso doppiamente linkata) di nodi che indicano se il segmento è P o H, l'indirizzo di inizio e la lunghezza.

- **Coalescenza:** Quando un processo termina, il SO controlla i vicini: se sono buchi (H), li fonde in un unico grande buco in tempo $O(1)$.

---
## 6. Strategie di Allocazione (Algoritmi)

Per decidere dove inserire un processo in una lista di buchi:

- **First Fit:** Sceglie il _primo_ buco abbastanza grande. Veloce.

- **Next Fit:** Come il First Fit, ma parte dall'ultima posizione analizzata (per distribuire meglio l'uso della lista).

- **Best Fit:** Cerca il buco che si avvicina di più alla dimensione richiesta. Minimizza lo spreco immediato ma crea buchi piccolissimi e inutilizzabili.

- **Worst Fit:** Sceglie il buco _più grande_ disponibile, con l'idea di lasciare un "resto" abbastanza grande da essere utile. Richiede di scorrere tutta la lista ($O(n)$).