## Capitolo 1

### Generalità sui sistemi operativi
Un computer moderno è un sistema complesso costituito da processori, memoria centrale, dischi e dispositivi di input/output. Per gestire questa complessità, i computer dispongono di uno strato software fondamentale: il sistema operativo.

I computer operano principalmente in due modalità:
- **Modalità kernel (o supervisor):** Permette l'accesso completo a tutto l'hardware e l'esecuzione di qualsiasi istruzione la macchina sia in grado di svolgere. È qui che viene eseguito il sistema operativo.
- **Modalità utente:** È la modalità in cui "gira" il resto del software e dei programmi applicativi, con privilegi limitati.

A differenza delle normali applicazioni, i sistemi operativi sono software molto grandi, complessi e longevi (sistemi come Linux o Windows raggiungono dimensioni nell'ordine dei cinque milioni di righe di codice).
###### Che cos'è un sistema operativo
Il sistema operativo è il software che opera in modalità kernel e svolge due funzioni principali e distinte:
###### Il sistema operativo come macchina estesa

L'architettura hardware nativa di un computer è primitiva e complessa da programmare. Il sistema operativo ha il compito di nascondere questa complessità, offrendo ai programmatori un insieme di astrazioni chiare, eleganti e coerenti.
- **Driver:** Software che fornisce un'interfaccia semplificata per la gestione dell'hardware (ad esempio, per leggere o scrivere su un disco), sollevando il programmatore dall'occuparsi dei dettagli tecnici di basso livello.
###### Il sistema operativo come gestore delle risorse

Il sistema operativo fornisce un'allocazione ordinata e controllata delle risorse hardware tra i vari programmi. Questa gestione include la condivisione delle risorse, definita multiplexing, che avviene in due modalità:
- **Multiplexing nel tempo:** Più programmi o utenti utilizzano la stessa risorsa alternandosi (facendo a turno).
- **Multiplexing nello spazio:** I clienti non si alternano, ma ognuno ottiene una porzione specifica della risorsa.
###### Storia dei sistemi operativi
- **Prima generazione (1945-1955):** Valvole termoioniche. Assenza totale di sistemi operativi; la programmazione avveniva in linguaggio macchina tramite cavi e interruttori.
- **Seconda generazione (1955-1965):** Transistor e sistemi batch (a lotti). Introduzione dei primi software di base per automatizzare il passaggio da un lavoro (job) all'altro senza l'intervento umano continuo.
- **Terza generazione (1965-1980):** Circuiti integrati (IC) e multiprogrammazione. Nascono il partizionamento della memoria e il timesharing (condivisione del tempo) per permettere a più utenti di interagire contemporaneamente con la macchina.
- **Quarta generazione (1980-oggi):** Personal Computer. Grazie ai circuiti integrati su larga scala (LSI), i computer diventano personali. Nascono sistemi operativi come MS-DOS, UNIX e, successivamente, le interfacce grafiche (GUI) con Windows e macOS.
- **Quinta generazione (1990-oggi):** Dispositivi mobili e cloud computing. Sistemi operativi fortemente interconnessi per smartphone, tablet e infrastrutture di rete.
###### Analisi dell'hardware
Un sistema operativo è intimamente legato all'hardware del computer su cui gira: ne estende l'insieme di istruzioni e ne gestisce le risorse.

###### Processori
La CPU (Central Processing Unit) è il "cervello" del computer. Il suo ciclo di base consiste nel prelevare un'istruzione dalla memoria (fetch), decodificarla per comprenderne tipo e operandi, eseguirla e passare alla successiva, fino al termine del programma.

Per migliorare le prestazioni, le moderne CPU adottano architetture avanzate:
- **Pipeline:** Organizzazione che permette di eseguire più istruzioni contemporaneamente (es. mentre si esegue l'istruzione n, si decodifica la n+1 e si preleva la n+2).
- **Multithreading (o hyperthreading):** Permette alla CPU di mantenere lo stato di due thread diversi, i quali appaiono al sistema operativo come due CPU separate.
- **Multicore:** Chip CPU che contengono al loro interno più processori completi (core), richiedendo l'uso di un sistema operativo multiprocessore.
- **GPU (Graphics Processing Unit):** Processori dotati di migliaia di core microscopici, eccezionali per l'esecuzione parallela di piccoli calcoli (come il rendering poligonale).
###### I Registri della CPU
Poiché l'accesso alla memoria è lento, la CPU utilizza memorie interne ad altissima velocità chiamate registri:
- **Program counter:** Contiene l'indirizzo di memoria della successiva istruzione da eseguire.
- **Stack pointer:** Puntatore allo stack.
- **PSW (Program Status Word):** Registro che contiene i bit di condizione, la priorità della CPU e il bit che controlla la modalità operativa (utente o kernel).

**Nota Operativa:** Quando il sistema operativo ferma un programma per farne partire un altro (multiplexing temporale), deve salvare lo stato di tutti i registri per poterli ricaricare al riavvio del programma sospeso questo fenomeno si chiama context switching.
**Chiamate di Sistema e Interruzioni**
- **System Call (Chiamata di sistema):** Richiesta effettuata da un programma utente per ottenere servizi dal sistema operativo.
- **TRAP:** Istruzione che cambia la modalità operativa da utente a kernel e avvia il sistema operativo. Le trap possono anche essere generate dall'hardware per segnalare situazioni eccezionali (es. divisione per zero).

###### Memoria

Poiché non esiste una memoria ideale (veloce, capiente e a basso costo contemporaneamente), il sistema è strutturato in strati gerarchici:
- **Registri della CPU:** Strato alla sommità, velocissimi e a capacità ridotta.
- **Memoria Cache:** Gestita dall'hardware. Si divide in Cache L1 (interna alla CPU, fornisce istruzioni codificate) e Cache L2. Conserva le linee di memoria usate più di frequente.
- **Memoria Principale (RAM):** La memoria di lavoro vera e propria ad accesso casuale. Gestisce tutte le richieste della CPU non soddisfatte dalla cache.
- **Memoria non volatile:** Include la ROM (Read Only Memory, programmata dal costruttore e non modificabile), la EEPROM (cancellabile elettricamente) e le memorie flash.
###### Dischi
L'Hard Disk (disco magnetico) si trova sotto la RAM nella gerarchia. È lento perché è un'unità meccanica formata da piatti metallici rotanti e un braccio meccanico.
- **Traccia:** Regione anulare letta da una testina a una data posizione del braccio.
- **Cilindro:** L'insieme di tutte le tracce relative a una specifica posizione del braccio.
###### Dispositivi di I/O
I dispositivi di Input/Output sono composti dal dispositivo fisico e da un controller (il chip che lo governa fisicamente). Il sistema operativo vede solo l'interfaccia del controller.
- **Device Driver:** Software specifico necessario per controllare un determinato dispositivo di I/O. Gira in modalità kernel e può essere installato in tre modi:
    1. Ricollegando il kernel al driver e riavviando.
    2. Creando una voce in un file di sistema e riavviando.
    3. Installazione "a caldo" mentre il sistema è in esecuzione (senza riavvio).

**Gestione dell'Input/Output:**
Avviene tramite tre metodi principali:
- **Busy waiting:** Il driver avvia l'I/O e interroga continuamente il dispositivo per controllare se ha terminato. Svantaggio: Impegna inutilmente la CPU.
- **Interrupt:** Il driver avvia il dispositivo e si sospende. Al termine, il controller genera un interrupt (interruzione) per segnalare il completamento (il testo fa riferimento al vettore degli interrupt). La CPU può disabilitare temporaneamente gli interrupt per non essere interrotta in momenti inopportuni.
- **DMA (Direct Memory Access):** Utilizza un hardware speciale che controlla il flusso di dati tra memoria e controller senza l'intervento costante della CPU. Al termine, il chip DMA genera un interrupt.
###### Panoramica dei vari sistemi operativi
- **Sistemi operativi per mainframe**: Orientati all'esecuzione simultanea di numerosi lavori con massicce richieste di I/O. Offrono elaborazione di transazioni, timesharing e **servizi batch**, ossia l'esecuzione completamente automatica e sequenziale di grandi volumi di operazioni raggruppate in lotti (es. fatturazione o calcolo stipendi), senza necessità di interazione da parte dell'utente.
- **Sistemi operativi per server:** Servono molteplici utenti in rete, permettendo la condivisione di risorse hardware e software.
- **Sistemi operativi multiprocessore:** Varianti dei sistemi server ottimizzate per comunicazione e coerenza. Utilizzati sempre più spesso anche sui PC desktop dotati di chip multicore.
- **Sistemi operativi per personal computer:** Progettati per supportare in modo ottimale un singolo utente.
- **Sistemi operativi per computer palmari (PDA):** Sistemi sofisticati per dispositivi mobili, in grado di gestire CPU multicore, GPS, fotocamere e grandi memorie.
- **Sistemi operativi integrati (embedded):** Installati su dispositivi non considerati veri computer (es. forni a microonde). Il software è su ROM, non accetta app esterne, rendendo inutile la protezione tra applicazioni.
- **Sistemi operativi real-time:** Sistemi in cui il tempo è il parametro critico.
    - **Hard real-time:** Forniscono garanzie assolute che un'azione avvenga in un momento preciso.
    - **Soft real-time:** Tollerano il mancato rispetto occasionale di una scadenza.
###### Chiamate di sistema (System Call)

Le system call rappresentano l'interfaccia standard tra i programmi utente e il sistema operativo. Quando un programma ha bisogno di un servizio privilegiato (come leggere un file, allocare memoria o creare un processo), esegue una system call tramite un'istruzione TRAP, passando dalla modalità utente alla modalità kernel.

Esempi di standard per le system call sono POSIX (usato da Unix e Linux) e Win32 API (usato da Windows).

### Struttura di un sistema operativo
Di seguito le strutture dei vari tipi di sistema operativo:

###### Sistemi monolitici
È l'organizzazione più comune. L'intero sistema operativo è un singolo programma eseguito in modalità kernel, formato da una raccolta di procedure collegate (linkate) tra loro. Poiché le procedure si richiamano liberamente senza restrizioni, il sistema risulta spesso pesante e difficile da capire.

###### Sistemi a livelli
Il sistema è organizzato gerarchicamente. Un esempio classico prevede sei livelli:
- Livello 0: Allocazione del processore (multiprogrammazione base).
- Livello 1: Gestione della memoria.
- Livello 2: Comunicazione tra processi e console operatore.
- Livello 3: Gestione dei dispositivi di I/O.
- Livello 4: Programmi utente.
- Livello 5: Operatore di sistema.

###### Microkernel
Nasce per garantire un'altissima stabilità. Il sistema è diviso in piccoli moduli ben definiti, ma solo il microkernel viene eseguito in modalità kernel. Driver, file system e server girano tutti in modalità utente. I programmi ottengono i servizi inviando brevi messaggi ai processi server.

###### Modello client-server
È una variazione del microkernel che distingue due classi di processi: i server (che forniscono i servizi) e i client (che li utilizzano). La comunicazione avviene tramite passaggio di messaggi (ottimizzabile se client e server risiedono sulla stessa macchina).

###### Macchine virtuali
Si basano su un monitor di macchina virtuale (oggi chiamato **hypervisor di tipo 1**) che gira direttamente sull'hardware e fornisce ai livelli superiori numerose macchine virtuali. Ogni macchina virtuale è identica all'hardware reale e può eseguire un proprio sistema operativo (guest).

**Hypervisor di tipo 2:** Strategia ibrida utilizzata comunemente sui PC (es. VMware Workstation). Non gira direttamente sull'hardware, ma ha bisogno di un sistema operativo host preesistente per installare e avviare il sistema operativo guest su un disco virtuale.

## Capitolo 2
### Processi

Nei computer moderni è normale che vengano svolti molti compiti contemporaneamente, si consideri innanzitutto un Web server. Arrivano richieste per pagine web da ogni dove, quindi diventa necessario un qualche sistema per modellare e controllare tale concorrenza. Così nasce il modello dei processi. In questo modello, tutto il software eseguibile sul computer è organizzato in una serie di attività sequenziali detti *processi*.
- **Processo:** È un'istanza di un programma in esecuzione. Rappresenta un'attività in corso dotata di un proprio programma, di input, di output e di uno stato interno. Due istanze dello stesso programma costituiscono due processi distinti.
- **Programma:** È un oggetto passivo (codice) che può essere memorizzato su disco.

> [!QUOTE] Ricordiamo
> In questo capitolo daremo per assodato che vi sia una sola CPU. Sempre più spesso tuttavia questo assunto non è valido, dato che i nuovi chip sono spesso multicore, con due, quattro o più CPU.

###### L'anatomia di un processo in memoria
Quando un processo viene caricato in memoria, è strutturato nei seguenti segmenti:
- **Sezione Text:** Contiene il codice eseguibile vero e proprio.
- **Sezione Data:** Contiene le variabili globali e statiche.
- **Heap:** Memoria allocata dinamicamente a runtime.
- **Stack:** Memoria utilizzata per gestire le chiamate a funzione e le variabili locali.
![[Pasted image 20260317180000.png|550]]
###### CPU virtuale e cambio di contesto
Concettualmente, il modello garantisce a ogni processo l'illusione di avere una propria **CPU virtuale** esclusiva e uno spazio di memoria virtualmente infinito. Nella realtà, la CPU dedica un _quanto di tempo_ a ciascun processo, per poi passare al successivo.
- **Context Switch:** È l'operazione con cui la CPU smette di dedicarsi a un processo per passare al successivo. Vengono salvate le istruzioni e le risorse del processo uscente e caricate quelle del processo entrante.
- **Multiprogrammazione / Pseudoparallelismo:** È l'illusione di parallelismo creata dai continui e rapidissimi cambi di contesto in un sistema _single-core_.
###### Creazione dei processi
La creazione di un nuovo processo avviene principalmente in quattro circostanze:
1. **All'avvio del sistema (Boot):** Viene creato un processo radice (solitamente con Process ID = 1), che funge da capostipite per l'albero di tutti i processi successivi.
2. **Tramite chiamate di sistema (Syscall):** Un processo padre ne crea uno figlio per delegare compiti o distribuire il carico di lavoro (utile specie nei multiprocessori per evitare blocchi).
3. **Azione dell'utente:** Tipico dei sistemi interattivi (es. l'avvio di un'app).
4. **Inizio di un job batch:** Lo _Scheduler_, in base alle risorse libere, seleziona un lavoro dalla coda e crea un processo per eseguirlo.

All'avvio del sistema vengono avviati diversi processi, tra questi quelli eseguiti in _background_ vengono chiamati **demoni**
###### Chiamate di Sistema per la Creazione
- **Sistemi UNIX:** Usano una combinazione di due chiamate.
    - `fork`: Crea una copia esatta del processo padre (stesso spazio di indirizzamento, permessi e file aperti).
    - `execve` (o analoghe): Invocata solitamente dal processo figlio appena nato, sovrascrive la propria immagine di memoria per eseguire un nuovo programma
- **Sistemi Windows:** Utilizzano un'unica chiamata di sistema atomica chiamata `CreateProcess` (API Win32). Questa funzione richiede ben 10 parametri (tra cui nome del programma, attributi di sicurezza, priorità, ecc.) e crea direttamente un nuovo processo con la sua immagine di memoria dedicata.
###### Terminazione dei processi
La chiusura di un processo avviene per:
1. **Uscita normale (Volontaria):** Terminazione ordinaria. Avviene tramite la syscall `exit` in UNIX e `ExitProcess` in Windows (ritorna un _exit status_).
2. **Uscita su errore (Volontaria):** Terminazione anomala ma gestita e concepita dal programma stesso.
3. **Errore critico (Involontaria):** Scatta automaticamente per azioni illegali (divisione per zero, scrittura in zone _read-only_). L'hardware genera un'eccezione e il processo viene interrotto senza tentativi di ripristino.
4. **Terminato da un altro processo (Involontaria):** Un processo uccide un altro processo (se appartengono allo stesso utente, o se si è amministratori). Si usano le syscall `kill` in UNIX e `TerminateProcess` in Windows. Quando parliamo della chiamata di sistema kill dobbiamo fare la seguente distinzione:
	- **Soft Kill:** Viene inviato un segnale di chiusura al programma. Il programma può intercettarlo, eseguire una routine di pulizia e chiudersi, oppure persino rifiutare la chiusura.
	- **Hard Kill:** Chiusura forzata e istantanea a priori, senza possibilità di replica per il processo.
###### Stati di un processo e ciclo di vita
Il ciclo di vita può essere descritto da un automa a 5 stati (3 principali e 2 transitori):
- **New:** Fase transitoria di predisposizione delle risorse all'avvio.
- **Pronto (Ready):** Il processo è pronto a usare la CPU ed è in attesa in una speciale coda gestita dallo _Scheduler_.
- **In Esecuzione (Running):** Il processo detiene l'unica CPU disponibile in quel momento.
- **Bloccato (Blocked):** Il processo è parcheggiato in attesa di un evento esterno (spesso operazioni di Input/Output "lente").
- **Terminated:** Fase finale di chiusura.

![[Pasted image 20260426194444.png|700]]

Per passare da uno stato all'altro abbiamo dei meccanismi di transizione:
- **Running $\rightarrow$ Blocked (Attesa di I/O):** Quando un processo effettua una _syscall_ "lenta" (che richiede tempi lunghi di risposta dal SO), si blocca volontariamente per non sprecare cicli di CPU.
    - _Nota:_ **Blocking wait vs Busy wait:** Passare allo stato Bloccato (Blocking wait) è molto più efficiente del Busy wait, perché la CPU non deve sprecare tempo a controllare continuamente se il dato è arrivato; sarà il SO a risvegliare il processo a tempo debito.
- **Running $\rightarrow$ Ready (Prelazione / Interrupt):** Se un processo non effettua operazioni di I/O rischia di monopolizzare la CPU. Per evitare che questo accada esiste la **prelazione**: un'operazione tramite la quale il Sistema Operativo sposta il processo dallo stato di _running_ a quello di _ready_. Questo avviene quando il processo ha esaurito la quantità massima di tempo CPU che gli era stata assegnata, ed è innescato direttamente tramite un *interrupt*.

> [!TIP] La prelazione
> **Prelazione (_Preemption_):** È l'operazione tramite cui il sistema operativo interrompe temporaneamente un processo in esecuzione (togliendogli l'uso della CPU) senza alcuna cooperazione da parte del processo stesso, al fine di permettere l'esecuzione di un altro processo.
##### Gestione dei processi
Per riuscire a gestire il parallelismo e i processi il sistema operativo utilizza:
- **Tabella dei processi:** È una struttura dati dinamica (implementata come lista concatenata) che contiene tutte le informazioni dei processi del sistema.
- **Process Control Block (PCB):** È il record all'interno della Tabella dei Processi. Viene allocato alla creazione del processo e deallocato alla sua morte. Contiene tutto il necessario per permettere il _Context Switch_ senza perdita di dati:
    - Stato del processo e Process ID (PID).
    - Program Counter (PC) e contenuto dei registri della CPU.
    - Limiti di memoria e file aperti.
    - Processi imparentati (padre, figli).

> [!TIP]
> Il **PSW** (acronimo di **Program Status Word**, o a volte _Processor Status Word_) è un registro hardware fondamentale all'interno della CPU che descrive lo stato attuale del processore in un determinato istante.

###### Le Code
I processi non sono gettati alla rinfusa, ma incolonnati in specifiche code gestite dal sistema operativo.
- **Coda dei processi pronti:** Raccoglie tutti i processi in stato _Ready_. Non è una struttura in memoria separata, ma sfrutta i PCB della Tabella dei Processi uniti tra loro tramite speciali puntatori.
- **Code di I/O:** Raccoglie i processi in stato _Blocked_ in attesa di una specifica periferica o evento.
- **Coda di fork**: una coda che raccoglie tutti quei processi che stanno perdendo tempo per forkarsi
- **Coda time slice expired**: qua troviamo tutti i processi che hanno consumato tutto il loro tempo dentro la CPU
![[Pasted image 20260426194759.png|700]]
Vediamo che tutte queste code confluiscono dentro la coda dei processi pronti, infatti una volta usciti dalla coda specifica andranno in quella generica per aspettare la CPU.

### Thread
###### Introduzione al Modello a Thread Multipli
Il **modello a thread multipli** permette di gestire l'esecuzione di un singolo processo suddividendola su più flussi di esecuzione indipendenti. Mentre processi diversi non hanno risorse comuni e sono totalmente indipendenti, i thread appartenenti allo stesso processo condividono le risorse. Avere la possibilità di gestire più flussi è fondamentale per avere programmi complessi e responsivi.

> [!Example] 
> - **Esempio di un Text Editor:** Senza thread, il rendering del file a schermo si bloccherebbe a ogni salvataggio, e il controllo ortografico impedirebbe la scrittura simultanea.
> - **Esempio di un Web Server:** Senza thread, le richieste verrebbero gestite una ad una; una richiesta onerosa bloccherebbe le successive, creando code e abbattendo il _throughput_.
###### Thread con risorse esclusive o condivise
Tutti i thread generati all'interno di un medesimo processo condividono lo stesso PID (Process ID). Da qui distinguiamo due tipi di thread, classificati in base a come gestiscono le risorse:
- **Risorse esclusive (Dx):** Ogni thread possiede un proprio *program counter* (per sapere quale istruzione eseguire), propri *registri*, un proprio *stack* e un proprio stato (es. ready, running, blocked).
- **Risorse condivise (Sx):** Tutti i thread del processo condividono lo spazio di indirizzamento, l'*heap*, la memoria globale, il codice (o testo) e i file aperti.
![[Pasted image 20260317174247.png|500]]
###### Operazioni, Stati e Context Switch
Lo _scheduler_ del sistema operativo (nei sistemi moderni) tratta i thread come processi a sé stanti. I cambiamenti di stato sono identici a quelli dei processi: _Running_ (in esecuzione), _Ready_ (pronto) o _Blocked_ (bloccato).
**Le primitive fondamentali dei thread:**
- **thread_create:** Un thread genera un nuovo thread.
- **thread_exit:** Il thread chiamante ha finito il lavoro e termina.
- **thread_join:** Un thread si blocca per sincronizzarsi in attesa della fine di un altro thread.
- **thread_yield:** Il thread rilascia **volontariamente** la CPU per far eseguire qualcun altro.

**Context Switch sui thread:** Il _context switch_ tra thread dello stesso processo è drasticamente più veloce rispetto a quello tra processi distinti. Il motivo risiede nell'hardware: cambiando solo thread e mantenendo lo stesso spazio di memoria, si solleva l'**MMU** (_Memory Management Unit_) dal dover essere riprogrammata.

> [!TIP] MMU
> L'**MMU** è un componente **hardware** (solitamente integrato direttamente all'interno della CPU) che ha il compito fondamentale di gestire l'accesso alla memoria durante l'esecuzione dei programmi.
> 
Il suo scopo principale è la **traduzione degli indirizzi di memoria**: converte gli _indirizzi logici_ (o virtuali) generati dalla CPU in _indirizzi fisici_ (reali) all'interno della RAM.

###### Multicore Programming e Concorrenza
L'uso dei thread porta a benefici differenti in base all'hardware sottostante:
- **Sistemi Single-core:** Si ottiene un'esecuzione alternata, ovvero uno **pseudo-parallelismo** (lo scheduler decide quali thread eseguire alternandoli tra di loro).
- **Sistemi Multi-core:** Si ottiene un **parallelismo puro**, dove più thread vengono materialmente eseguiti nello stesso esatto istante su _core_ diversi.

La programmazione multi-core non è banale e richiede di gestire quattro criticità principali:
1. **Separazione dei task:** Suddividere logicamente il lavoro.
2. **Bilanciamento:** Distribuire equamente le responsabilità e la durata temporale dei task tra i thread.
3. **Dipendenze dei dati:** Individuare risorse condivise e dipendenze (es. il thread $A$ non può procedere finché non riceve un dato elaborato dal thread $B$).
4. **Test e debugging:** È estremamente complesso individuare tutti i casi limite e le circostanze anomale nell'esecuzione parallela.

###### Thread a livello utente (modello 1-a-molti)
Questo modello viene gestito interamente da librerie nello spazio utente, ed è utile per lavorare su _Kernel_ che non supportano nativamente i thread. Il sistema operativo vede solo un unico grande processo e un unico flusso di esecuzione. Lo scambio tra thread è gestito manualmente tramite la primitiva `thread_yield`, che salva i registri in una tabella locale nello spazio utente.
- **Punti di forza:**
    - **Scheduling personalizzato:** Permette priorità contestuali gestite dall'applicazione, molto più versatili rispetto a quelle generdell'OS.
    - **Dispatching senza trap:** Operando in modalità utente, si evitano le lentissime chiamate a sistema (_trap_), rendendo i thread estremamente veloci.
- **Criticità:**
    - **Chiamate bloccanti:** Se un thread fa una chiamata lenta (es. I/O su disco), l'OS blocca l'intero processo, fermando di conseguenza _tutti_ i thread utente. Anche i _page-fault_ causano l'interruzione totale.
	    - _Soluzione (select):_ Si utilizza la chiamata a sistema `select` per verificare preventivamente se un'istruzione (es. input da tastiera) è pronta. Se non lo è, per evitare di bloccare il processo, si fa un `thread_yield` per cedere la CPU e si riprova in seguito.
    - **Possibilità di non rilascio:** In assenza di _interrupt_ hardware (prelazione), se un thread non rilascia volontariamente la CPU, nessun altro thread utente può forzarlo a farlo.

> [!TIP] Page fault
> *Page fault:* Se un thread tenta di accedere a una variabile o a un'istruzione che si trova in un'area di memoria non attualmente caricata nella memoria RAM (ad esempio perché è stata spostata nell'area di swap su disco), si genera un'eccezione hardware chiamata _page fault_.

###### Thread a livello kernel (Modello 1-a-1)
È il modello nativamente supportato dai sistemi operativi moderni, associando a ogni thread utente un thread a livello _Kernel_. La tabella dei thread è mantenuta nel _Kernel_ ed è unica per tutti i processi.
- **Punti di forza:** Una chiamata bloccante effettuata da un thread blocca **esclusivamente** quel thread, risolvendo il problema principale del modello utente.
- **Svantaggi:**
    - **Context switch più lento:** Passare da un thread all'altro richiede l'uso di costose _trap_ di sistema (cambio di contesto simile a quello tra processi).
    - **Operazioni costose:** Creare e distruggere frequentemente thread _Kernel_ rallenta esponenzialmente l'intero sistema operativo.
###### Modello Ibrido (Molti-a-molti)
Questo modello mira a combinare i punti di forza dell'approccio a livello utente (efficienza e flessibilità) con quelli dell'approccio a livello kernel (vero parallelismo e tolleranza ai blocchi), mitigando i difetti di entrambi.

In pratica, il sistema effettua un **multiplexing** di numerosi thread a livello utente su un numero limitato (uguale o inferiore) di thread a livello kernel.
- **Livello Utente:** Il programmatore, tramite la libreria, può creare tutti i thread necessari per la logica dell'applicazione. Il _context switch_ tra questi thread rimane rapido perché avviene nello spazio utente.
- **Livello Kernel:** Il sistema operativo fornisce e gestisce un pool di thread a livello kernel, assegnandoli ai processori fisici disponibili. La libreria di runtime si occupa poi di mappare dinamicamente i thread utente sui thread kernel liberi.

**Il grande vantaggio:** In questo modo, se un thread utente effettua una chiamata di sistema bloccante o subisce un _page fault_, il sistema operativo blocca solo il thread kernel associato in quel preciso momento. Gli altri thread a livello utente possono continuare la loro esecuzione appoggiandosi ai restanti thread a livello kernel disponibili.
![[Pasted image 20260319163244.png|500]]
###### Librerie di Riferimento: pthreads
Quasi tutti i sistemi operativi moderni implementano nativamente i thread _Kernel_. Per gestire invece i thread a livello utente, lo standard di riferimento è la libreria **pthreads**. **pthreads:** Basata sullo standard POSIX, fornisce un'interfaccia univoca e funzioni semplificate per la gestione dei thread. Il suo grande pregio è la portabilità: il codice sorgente è compilabile e funzionante su molteplici OS; pur cambiando ciò che avviene "dietro le quinte" in base al sistema, i risultati rimangono analoghi.

### Comunicazione tra processi
###### Introduzione e complessità dell'IPC
La gestione della comunicazione tra processi (**IPC** - **InterProcess Comunication**) è fondamentale per ottenere sistemi reattivi e performanti. La complessità di un sistema aumenta drasticamente quando si passa da un'esecuzione puramente sequenziale (dove un processo $P_n$ segue l'altro in modo sincrono) a un sistema di **processi concorrenti** che comunicano tramite risorse condivise.

I tre problemi principali da affrontare sono:
1. **Passaggio di informazioni:** Come trasferire dati tra processi.
2. **Sincronizzazione:** Evitare che due o più processi si accavallino su dati comuni.
3. **Sequenzialità:** Gestire le dipendenze di ordine tra i processi.
Questi problemi valgono anche per i **thread**, sebbene per essi il passaggio di informazioni sia facilitato dalla condivisione dello spazio di indirizzamento. Esistono diversi approcci per permettere ai processi di scambiare dati, ognuno con criticità specifiche.

![[Pasted image 20260429175933.png|700]]
###### Il modello pipe
È il modello più semplice e lineare, basato sull'unidirezionalità.
- **Funzionamento:** Sfrutta i canali di input/output per concatenare i processi (es. `cmd1 | cmd2`).
- **Implicazioni:** Crea una **dipendenza di tempismo**, poiché `cmd2` deve attendere l'output di `cmd1`. Tra i processi è presente un **buffer** per conservare temporaneamente i dati.
- **Limiti:** Non permette la comunicazione bidirezionale e i dati non sono propriamente condivisi, rendendolo un modello limitato.
###### Segmento di memoria condiviso
Rappresenta l'approccio ideale. Sfrutta uno spazio di memoria comune dove i processi possono leggere e scrivere. Tuttavia, richiede un coordinamento rigoroso per evitare l'accavallamento delle operazioni, senno si ricade nel problema della race condition.
###### Il Problema delle race condition
La **race condition** è la situazione in cui il risultato finale dipende dall'ordine di esecuzione dei processi (ovvero da chi viene "scelto" per primo dallo _scheduler_).
- **Esempio pratico:** Se due processi eseguono simultaneamente un incremento $x = x+10$, il valore finale potrebbe essere inconsistente (es. 20 invece di 30) se entrambi leggono lo stesso valore iniziale prima che l'altro possa aggiornarlo.
La parte di programma in cui si accede alla memoria condivisa e quindi dove si creano le race condition si chiama **sezione critica** è importante ricordare che è compito del programmatore individuare e circoscrivere queste sezioni. È buona norma definire sezioni critiche differenti per strutture dati indipendenti, così da non bloccare processi che non competono per la stessa risorsa.

![[Pasted image 20260429180007.png|500]]

###### Condizioni per una soluzione efficace
Per risolvere le **race condition** devono essere soddisfatte quattro condizioni:
1. **Mutua esclusione:** Due processi non possono trovarsi contemporaneamente nelle loro sezioni critiche.
2. **Indipendenza Hardware:** Nessun presupposto su velocità o numero di CPU.
3. **Assenza di Blocchi Esterni:** Un processo fuori dalla sua sezione critica non deve bloccare altri processi.
4. **Attesa Finita:** Nessun processo deve attendere all'infinito l'ingresso nella sezione critica; deve essere garantito un tempo massimo finito.

Di seguito le varie soluzioni proposte:
###### Inibizione degli interrupt
L'approccio più radicale consiste nel permettere a un processo, una volta entrato nella sezione critica, di **disabilitare tutti gli interrupt**. Poiché lo scheduler del sistema operativo si appoggia sugli interrupt (come il timer del clock) per effettuare il _context switch_, disabilitarli significa dare al processo il controllo totale della CPU.
- **Perché non si usa oggi?** Sebbene funzioni perfettamente su sistemi mono-processore (garantendo l'atomicità per "forza bruta"), è estremamente pericoloso: un processo utente malizioso o buggato potrebbe bloccare l'intero sistema. Inoltre, nei moderni sistemi **multicore**, disabilitare gli interrupt su un core non impedisce agli altri core di accedere alla memoria condivisa, rendendo la soluzione del tutto inefficace.

###### Variabili di lock
Un'idea naturale è l'uso di una  **variabile di lock** (0 se libero, 1 se occupato). Il processo controlla il lock: se è 0, lo imposta a 1 ed entra.
- **Il paradosso:** Il problema è che l'azione di "controllare e poi impostare" non è atomica. Se il Processo A legge il lock e vede 0, ma viene interrotto _un istante prima_ di impostarlo a 1, il Processo B potrebbe essere schedulato, leggere anche lui 0 e impostare il lock. Al ritorno di A, entrambi si ritroveranno nella sezione critica, causando proprio la race condition che volevamo evitare.


> [!TIP] 
> L'azione di testare continuamente una variabile finché non è valorizzata si chiama **busy waiting**. Andrebbe generalmente evitato, dato che consuma tempo di CPU. Il busy waiting è da utilizzare quando c'è la ragionevole aspettativa che l'attesa sia breve. Un lock che utilizza il busy waiting è chiamato **spin lock**.

###### Alternanza Stretta
Questa soluzione software obbliga i processi a passarsi il turno tramite una variabile `turn`.
- **Il limite:** È una soluzione troppo rigida. Se il turno è del Processo 0, ma il Processo 0 è impegnato in una lunga operazione fuori dalla sezione critica (o termina), il Processo 1 rimarrà bloccato all'infinito anche se la risorsa è libera. Questo viola la regola fondamentale secondo cui **un processo fuori dalla sezione critica non deve bloccare altri processi**.
```
int N = 2 // numero di processi
int turn

function enter_region(int process):
    while(turn != process):
        do nothing // attende il proprio turno

function leave_region(int process):
    turn = 1 - process // passa il turno al prossimo
```
###### L'Algoritmo di Peterson
Sviluppato nel 1981, l'algoritmo di Peterson è una soluzione puramente software elegante che combina il concetto di "turno" con quello di "interesse". Un processo dichiara di voler entrare nella sezione critica (`interested[i] = true`) ma, per cortesia, cede il turno all'altro. Entra solo se l'altro non è interessato o se il turno è tornato a lui.
- **Problemi moderni:** Nonostante la sua correttezza logica, l'algoritmo di Peterson spesso fallisce sulle CPU moderne. I processori attuali eseguono il cosiddetto **out-of-order execution** (riordino delle istruzioni) per ottimizzare le prestazioni.

```C
int N = 2; // numero di processi
int turn;
bool interested[N]; // tutti a false di default

// in entrata alla sezione critica
void enter_region(int process) {
    int other;
    other = 1 - process;
    interested[process] = true; // il processo in questione si dichiara "interessato"
    turn = process;             // si imposta il turno al proprio numero di processo
    
    while (interested[other] == true && turn == process) {
        /* do nothing*/
    }
}

// in uscita dalla sezione critica
void leave_region(int process) {
    interested[process] = false;
}
```
###### Istruzione TSL e XCHG
Per superare i limiti delle soluzioni software, le architetture moderne offrono istruzioni speciali che eseguono più operazioni come un unico blocco indivisibile (**atomico**). L'istruzione `TSL` legge il contenuto di una parola di memoria in un registro e, contemporaneamente, scrive un valore diverso da zero (solitamente 1) in quella stessa locazione. La CPU garantisce che, durante l'esecuzione di `TSL`, nessun altro processore possa accedere a quella parola di memoria (bloccando il bus di memoria).

```assembly
enter_region:
    TSL REGISTER, LOCK   // registro = lock, lock = 1
    CMP REGISTER, #0     // se il registro è a 0, entra nella sezione critica
    JNE enter_region     // altrimenti aspetta
    RET

leave_region:
    MOVE LOCK, #0        // reimposta lock a 0
    RET
```

Molte architetture Intel x86 utilizzano l'istruzione `XCHG`, che scambia atomicamente il contenuto di un registro con quello di una locazione di memoria. La logica è identica a quella della `TSL`.
###### Conclusioni su queste soluzioni
Tutte le soluzioni basate su **busy waiting** sprecano cicli di _clock_ e possono causare il **problema dell'inversione della priorità**. 

> [!TIP] Inversione della priorità
> Si verifica quando un processo ad alta priorità ($P_H$) rimane bloccato in attesa di un _lock_ detenuto da un processo a bassa priorità ($P_L$). Se un processo a priorità media ($P_M$) viene eseguito, sottrae tempo di CPU a $P_L$, impedendogli di terminare la sezione critica e, di conseguenza, bloccando indirettamente anche $P_H$.

###### Primitive Sleep e Wakeup
Per evitare questi sprechi, l'OS offre chiamate di sistema che gestiscono lo stato dei processi:
- **Sleep:** Sospende il processo chiamante, portandolo nello stato **blocked**.
- **Wakeup:** Risveglia un processo specifico, riportandolo nello stato **ready**.
Queste primitive permettono ai processi di non consumare CPU mentre attendono l'accesso a una risorsa condivisa.

###### Prima soluzione al problema del Produttore-Consumatore
Il **problema del produttore-consumatore** (noto anche come problema del _bounded-buffer_) è un classico esempio per illustrare le criticità della sincronizzazione.
- **Scenario:** Due processi condividono un buffer di dimensioni fisse. Il **produttore** inserisce informazioni nel buffer, mentre il **consumatore** le preleva.
- **Criticità:** Se il buffer è pieno, il produttore deve entrare in stato di _sleep_ (sospensione) ed essere risvegliato solo quando il consumatore libera spazio. Viceversa, se il buffer è vuoto, il consumatore entra in _sleep_ finché il produttore non inserisce un nuovo elemento.

Per tenere traccia degli elementi, si usa una variabile `count`. Tuttavia, se l'accesso a questa variabile non è vincolato, si verificano gravi **race condition** (condizioni di competizione).

```
function producer():
	while (true):
		item = produce_item
		if (count = N):
			sleep()
		insert_item (item)
		count = count + 1
		if (count = 1):
			wakeup(consumer)

function consumer():
	while (true):
		if (count = 0):
			sleep()
		item = remove_item()
		count = count - 1
		if (count = N - 1):
			wakeup(consumer)
		consume_item(item)
```

Immaginiamo la seguente sequenza di eventi:
1. Il buffer è vuoto. Il consumatore legge `count = 0`, ma prima di entrare in _sleep_, lo scheduler interrompe la sua esecuzione e passa al produttore.
2. Il produttore inserisce un elemento, porta `count` a 1 e, sapendo che prima era a 0, invia un segnale di _wakeup_ al consumatore.
3. Il consumatore, non essendo ancora logicamente in _sleep_, perde il segnale. Quando riprenderà l'esecuzione, andrà in _sleep_ e ci rimarrà per sempre.

**Soluzione temporanea (inefficace):** Aggiungere un **bit di attesa wakeup** (un "salvadanaio" per salvare i segnali). Funziona per due processi, ma fallisce non appena il sistema scala a tre o più processi, rendendo il problema persistente.

###### Semafori
Per risolvere definitivamente la perdita dei _wakeup_,  Dijkstra introdusse una nuova primitiva di sincronizzazione, chiamata **Semaforo** ovvero una variabile intera utilizzata per contare il numero di _wakeup_ salvati per uso futuro. 
Può valere:
- 0 (nessun _wakeup_ salvato) 
- un numero positivo (uno o più _wakeup_ in attesa).

I semafori operano tramite due azioni atomiche (garantisce il sistema operativo che lo siano):
- **Down:** Generalizzazione dell'operazione di _sleep_. Verifica se il semaforo è $> 0$. Se sì, lo decrementa (consuma un _wakeup_) e prosegue. Se è 0, il processo viene messo in _sleep_ senza completare il _down_.
- **Up:** Generalizzazione dell'operazione di _wakeup_. Incrementa il semaforo. Se ci sono processi in _sleep_ su quel semaforo, il sistema ne sceglie uno (es. casualmente) e gli permette di completare il suo _down_.

I semafori inizializzati a 1 e usati da due o più processi, per assicurare che uno solo di loro possa entrare nella propria regione critica allo stesso tempo, sono chiamati **semafori binari**.
###### Soluzione al Produttore-Consumatore con i semafori
La soluzione richiede tre semafori implementati in maniera indivisibile (tramite chiamate di sistema che disabilitano brevemente gli interrupt):
1. **Full:** Conta i posti pieni (inizializzato a 0).
2. **Empty:** Conta i posti vuoti (inizializzato a N).
3. **Mutex:** Semaforo binario per la mutua esclusione (inizializzato a 1).

```
#define N 100                           /* numero di posti nel buffer */
typedef int semaphore;                  /* i semafori sono un tipo speciale di int */

semaphore mutex = 1;                    /* controlla l'accesso alla regione critica */
semaphore empty = N;                    /* conta i posti vuoti del buffer */
semaphore full = 0;                     /* conta i posti pieni del buffer */

void producer(void){
    int item;
    while (TRUE) {                      /* TRUE è la costante 1 */
        item = produce_item();          /* genera qualcosa da mettere nel buffer */
        down(&empty);                   /* decrementa il contatore empty */
        down(&mutex);                   /* entra nella regione critica */
        insert_item(item);              /* mette un nuovo elemento nel buffer */
        up(&mutex);                     /* lascia la regione critica */
        up(&full);                      /* incrementa il contatore dei posti pieni */
    }
}

void consumer(void){
    int item;
    while (TRUE) {                      /* ciclo infinito */
        down(&full);                    /* decrementa il contatore full */
        down(&mutex);                   /* entra nella regione critica */
        item = remove_item();           /* prende l'elemento dal buffer */
        up(&mutex);                     /* lascia la regione critica */
        up(&empty);                     /* incrementa il contatore dei posti vuoti */
        consume_item(item);             /* fa qualcosa con l'elemento */
    }
}
```

###### Mutex
I **Mutex** sono una versione semplificata dei semafori, utili unicamente per gestire la mutua esclusione di risorse o pezzi di codice.
- **Stati:** Possono essere solo _locked_ (bloccato, solitamente > 0) o _unlocked_ (sbloccato, 0).
- **Operazioni:**
    - `mutex_lock`: Se _unlocked_, il thread entra nella regione critica. Se _locked_, il thread si blocca.
    - `mutex_unlock`: Sblocca il mutex; se ci sono thread in attesa, ne viene scelto uno a caso per acquisire il lock.        

Essendo semplici, i mutex possono essere realizzati nello spazio utente usando istruzioni hardware come `TSL` o `XCHG`. La differenza cruciale tra  `enter_regione` e `mutex_lock` è l'uso di `thread_yield`: se il lock fallisce, il thread cede immediatamente la CPU allo scheduler, evitando sprechi di risorse dovuti al busy waiting.

###### Futex (Fast User Space Mutex)
I classici _spin lock_ (attesa attiva) sono veloci ma sprecano CPU se l'attesa è lunga. Il blocco tramite kernel, d'altra parte, è oneroso se ci sono poche contese. La soluzione di Linux è il **Futex**.
- **Funzionamento:** Opera interamente in spazio utente finché non ci sono contese. Condivide un intero a 32 bit come lock. Il thread tenta di prenderlo con un'istruzione atomica "decrement and test".
- **In caso di contesa:** Se il lock è già detenuto, il futex effettua una chiamata di sistema per mettere il thread in una coda d'attesa nel kernel (giustificando l'overhead del kernel system call solo quando strettamente necessario).
- **Rilascio:** Avviene con un'istruzione "increment and test". Se ci sono processi bloccati in coda, avvisa il kernel di sbloccarli.

###### Monitor
Poiché i mutex e i semafori sono difficili da usare correttamente, Brinch Hansen (1973) e Hoare (1974) hanno introdotto una primitiva di più alto livello ovvero i **Monitor:** una raccolta di procedure, variabili e strutture dati raggruppate in un modulo. I processi esterni possono chiamare le procedure, ma non possono accedere direttamente alle strutture dati interne. In un dato istante, **solo un processo può essere attivo all'interno di un monitor**, ed è il compilatore a gestire la mutua esclusione (di solito usando mutex o semafori binari dietro le quinte).

**Variabili condizione:** Per permettere ai processi di bloccarsi quando non possono procedere, si usano due operazioni:
- `wait`: Blocca il processo chiamante e consente l'ingresso nel monitor a un altro processo.
- `signal`: Risveglia un processo in attesa su quella condizione.

Per evitare di avere due processi attivi nel monitor contemporaneamente, abbiamo bisogno di una regola che indichi che cosa accade dopo una `signal`. Il libro propone di far sì che venga eseguito il processo appena svegliato, sospendendo l'altro.

Ad una prima occhiata si può pensare che le operazioni `wait` e `signal` siano simili a `sleep` e `wakeup`. Sono in effetti molto simili, ma con una differenza cruciale: `sleep` e `wakeup` fallivano perché mentre un processo stava tentando di entrare in sleep, l'altro stava provando a svegliarlo. Con i monitor questo non può accadere, grazie alla gestione automatica della mutua esclusione. In questo modo la programmazione parallela diventa molto meno incline agli errori rispetto all'uso manuale dei semafori. 

**Svantaggio**: problema principale di questa soluzione è che i monitor sono costrutti del linguaggio di programmazione, ma non tutti i compilatori li supportano (es. C e Pascal ne sono sprovvisti).

###### Soluzione Produttore-Consumatore con i monitor
```
monitor pc_monitor
  condition full, empty;
  integer count = 0;

  function insert(item)
    if count = N then wait(full);
    insert_item(item);
    count = count + 1;
    if count = 1 then signal(empty)

  function remove()
    if count = 0 then
      wait(empty);
    remove = remove_item()
    count = count - 1;
    if count = N-1 then signal(full)

function producer()
  while (true) do
    item = produce_item()
    pc_monitor.insert(item)

function consumer()
  while (true) do
    item = pc_monitor.remove()
    consume_item(item)
```

###### Scambio di messaggi
Sia mutex che semafori sono stati pensati per essere utilizzati in sistemi che hanno una singola memoria pubblica collegata alle CPU, ma quando ci troviamo in sistemi distribuiti con memoria privata per ogni CPU, queste primitive diventano inutili, quindi si utilizza lo scambio di messaggi. Questo metodo si basa su due chiamate di sistema principali:
- `send`: Invia un messaggio a una destinazione.
- `receive`: Riceve un messaggio da una fonte.
Questa soluzione ha delle criticità:
1. **Messaggi persi:** Si risolve costringendo il destinatario a inviare un messaggio di _acknowledgment_ (conferma di ricezione). Se l'ack viene perso, si crea un nuovo problema di gestione delle ritrasmissioni.
2. **Identificazione:** Come identificare il destinatario in modo non ambiguo.
3. **Autenticazione:** Garantire che il client stia comunicando con il vero server e non con un impostore.
Per indirizzare i messaggi si usano diverse tecniche:
- **Indirizzamento Diretto:** Assegnazione di un indirizzo univoco a ciascun processo, alla quale la `send` invierà un messaggio
- **Mailbox:** Una struttura dati usata come buffer che contiene un certo numero predefinito di messaggi. Se un processo tenta di inviare a una mailbox piena, viene sospeso finché non si libera spazio.
- **Rendezvous (Zero Buffer):** La comunicazione avviene senza buffer intermedi. Se la `send` viene eseguita prima della `receive`, il mittente si blocca finché il destinatario non è pronto (e viceversa). È una strategia più rigida ma di semplice implementazione.

###### Soluzione Produttore-Consumatore con i messaggi
Il consumatore invia _N_ messaggi vuoti al produttore. Il produttore li preleva, li riempie e li rimanda al consumatore.

```
#define N 100               /* numero di posti nel buffer */

void producer(void)
{
    int item;
    message m;              /* buffer del messaggio */

    while (TRUE) {
        item = produce_item();          /* genera qualcosa da mettere nel buffer */
        receive(consumer, &m);          /* aspetta che ne arrivi uno vuoto */
        build_message(&m, item);        /* costruisci un messaggio da spedire */
        send(consumer, &m);             /* manda l'elemento al consumatore */
    }
}

void consumer(void)
{
    int item, i;
    message m;

    for (i = 0; i < N; i++) send(producer, &m); /* manda N vuoti */
    while (TRUE) {
        receive(producer, &m);          /* prende un messaggio che contiene un elemento */
        item = extract_item(&m);        /* estrae l'elemento dal messaggio */
        send(producer, &m);             /* ne manda indietro uno vuoto */
        consume_item(item);             /* fa qualcosa con l'elemento */
    }
}
```

###### Problema dei filosofi a cena
Il problema modella le sfide della concorrenza nell'accesso a risorse limitate.
- **Lo Scenario:** Cinque filosofi sono seduti attorno a un tavolo circolare. Davanti a ciascuno c'è un piatto di spaghetti.
- **Le Risorse (Forchette):** Tra un piatto e l'altro c'è una singola forchetta (5 forchette in totale). Gli spaghetti sono così scivolosi che per mangiare servono due forchette.
- **L'Obiettivo:** Quando un filosofo ha fame, tenta di prendere la forchetta alla sua sinistra e quella alla sua destra (in qualsiasi ordine). Se ci riesce, mangia per un po', posa le forchette e torna a pensare. Dobbiamo scrivere un programma che assicuri che ogni filosofo riesca a mangiare senza che il sistema si blocchi mai.
![[Pasted image 20260430110713.png|500]]
###### Tentativi di soluzione al problema dei filosofi a cena
Nel cercare di risolvere il problema, si va incontro a diverse problematiche tipiche della programmazione concorrente.
 
**Tentativo 1: La Soluzione "Ovvia" (Errata)**
L'approccio più istintivo è far sì che ogni filosofo aspetti e prenda la forchetta sinistra, poi faccia lo stesso con la destra.

```
#define N 5

void philosopher(int i){
    while (TRUE) {
        think();
        take_fork(i);               /* Prende la sinistra */
        take_fork((i+1) % N);       /* Prende la destra */
        eat();
        put_fork(i);                /* Posa la sinistra */
        put_fork((i+1) % N);        /* Posa la destra */
    }
}
```

Questa soluzione è letale a causa del rischio di blocco totale. Supponiamo che tutti e cinque i filosofi prendano la loro forchetta sinistra contemporaneamente. Nessuno sarebbe in grado di prendere la sua forchetta destra e ci sarebbe un deadlock. 

**Tentativo 2: Rilascio e Attesa (Tempo Fisso)**

Per evitare il _deadlock_, il filosofo prende la sinistra, controlla la destra: se è occupata, posa la sinistra, aspetta un tempo predefinito e riprova. Anche questa proposta fallisce, sebbene per una diversa ragione. Con un poco di sfortuna, tutti i filosofi potrebbero iniziare il loro algoritmo contemporaneamente, prendendo la loro forchetta sinistra, verificando che la destra non è disponibile, riponendo la forchetta sinistra, aspettando, riprendendo di nuovo la sinistra e così via, per sempre. Una situazione di questo genere, in cui tutti i programmi continuano a essere eseguiti indefinitamente, ma senza alcun avanzamento, è detta **starvation**.

**Tentativo 3: Attesa Casuale**
Si potrebbe introdurre un tempo di attesa randomico anziché fisso. Sebbene riduca statisticamente il rischio di un blocco lungo, non offre una garanzia matematica. Nei sistemi critici, una soluzione deve funzionare sempre, non basarsi sulla fortuna.

**Tentativo 4: Mutex globale**
Un miglioramento alla Figura 2.46 che non ha deadlock e non ha starvation è quello di proteggere le cinque dichiarazioni che seguono la chiamata a _think_ da un semaforo binario. Prima di iniziare ad acquisire forchette un filosofo farebbe un down su _mutex_. Dopo aver riposto la forchetta, farebbe un up su _mutex_.  Dal punto di vista teorico è ideone. Dal punto di vista pratico ha un difetto di prestazione; ci sarebbe un solo filosofo per volta che potrebbe mangiare, ma con la disponibilità di 5 forchette dovrebberò essere in 2.

**Tentativo 5: macro LEFT e RIGHT**
Per evitare _deadlock_, eliminare la _starvation_ e al contempo **massimizzare il parallelismo** (permettendo a due filosofi di mangiare assieme), si utilizza una logica basata sul tracciamento degli stati. Si introduce un array `state` che tiene traccia della condizione di ogni filosofo (_THINKING_, _HUNGRY_, _EATING_). 

Quindi si definisce una regola d'oro: Un filosofo può passare allo stato _EATING_ solo ed esclusivamente se **nessuno dei suoi due vicini** lo sta facendo in quel momento.


```
#define N           5           /* numero di filosofi */
#define LEFT        (i+N-1)%N   /* numero del vicino alla sinistra di i */
#define RIGHT       (i+1)%N     /* numero del vicino alla destra di i */
#define THINKING    0           /* il filosofo sta pensando */
#define HUNGRY      1           /* il filosofo tenta di prendere le forchette */
#define EATING      2           /* il filosofo mangia */

typedef int semaphore;          /* i semafori sono uno speciale tipo di int */
int state[N];                   /* array per tener traccia dello stato di ciascuno */
semaphore mutex = 1;            /* mutua esclusione per le regioni critiche */
semaphore s[N];                 /* un semaforo per filosofo */

void philosopher(int i)         /* i: numero del filosofo, da 0 a N-1 */
{
    while (TRUE) {              /* ripeti sempre */
        think();                /* il filosofo sta pensando */
        take_forks(i);          /* prende due forchette o si blocca */
        eat();                  /* yum-yum, spaghetti */
        put_forks(i);           /* ripone entrambe le forchette sul tavolo */
    }
}

void take_forks(int i)          /* i: numero del filosofo da 0 a N-1 */
{
    down(&mutex);               /* entra nella regione critica */
    state[i] = HUNGRY;          /* registra il fatto che il filosofo i ha fame */
    test(i);                    /* prova a prendere due forchette */
    up(&mutex);                 /* esce dalla regione critica */
    down(&s[i]);                /* si blocca se non sono state prese le forchette */
}

void put_forks(int i)           /* i: numero del filosofo da 0 a N-1 */
{
    down(&mutex);               /* entra nella regione critica */
    state[i] = THINKING;        /* il filosofo ha finito di mangiare */
    test(LEFT);                 /* guarda se il vicino a sinistra adesso può mangiare */
    test(RIGHT);                /* guarda se il vicino a destra adesso può mangiare */
    up(&mutex);                 /* esce dalla regione critica */
}

void test(int i)                /* i: numero del filosofo da 0 a N-1 */
{
    /* Se ho fame e i miei vicini non stanno mangiando, inizio a mangiare */
    if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
        state[i] = EATING;
        up(&s[i]);              /* Sblocca il semaforo personale del filosofo */
    }
}
```

###### Problema dei lettori-scrittori
Un altro famoso problema è quello dei lettori e degli scrittori, che modella l'accesso a una base di dati. È accettabile avere molteplici processi che leggono il database contemporaneamente, ma se un processo sta aggiornando (scrivendo) il database, nessun altro processo può avere accesso al database, nemmeno i lettori. Come programmiamo i lettori e gli scrittori per seguire queste regole?

###### Tentativi di soluzione al problema dei lettori-scrittori

**Tentativo 1: Soluzione basata sui semafori (Priorità ai lettori)**
L'approccio iniziale utilizza i semafori per gestire l'accesso. Si usa un semaforo `mutex` per proteggere la variabile contatore dei lettori (`rc`) e un semaforo `db` per garantire l'accesso esclusivo al database da parte degli scrittori. Il primo lettore che arriva blocca il database agli scrittori, e l'ultimo lettore che esce lo sblocca.
```
semaphore mutex = 1
semaphore db = 1
int rc = 0

function reader()
    while true do
        down(mutex)
        rc = rc + 1
        if (rc == 1) down(db)   /* Il primo lettore blocca gli scrittori */
        up(mutex)
        
        read_database()
        
        down(mutex)
        rc = rc - 1
        if (rc == 0) up(db)     /* L'ultimo lettore sblocca gli scrittori */
        up(mutex)
        use_data_read()

function writer()
    while true do
        think_up_data()
        down(db)                /* Richiede l'accesso esclusivo */
        write_database()
        up(db)
```

**Problema:** Questa soluzione è fortemente sbilanciata a favore dei lettori. Come evidenziato nella slide, **lo scrittore potrebbe attendere per un tempo indefinito** (starvation). Finché continua ad arrivare almeno un nuovo lettore prima che l'ultimo se ne sia andato, `rc` non scenderà mai a 0, il semaforo `db` non verrà rilasciato, e lo scrittore rimarrà bloccato per sempre.

---

**Tentativo 2: Soluzione n.1 basata sui monitor (Incapsulamento senza risolvere la starvation)**
Per strutturare meglio il codice, si passa all'uso di un **monitor**. Si introducono le variabili di condizione (`read`, `write`), un contatore di lettori (`rc`) e un flag booleano (`busy_on_write`). In questa versione, un lettore aspetta solo se uno scrittore è attualmente in fase di scrittura (`busy_on_write == true`).
```
monitor rw_monitor
    int rc = 0; boolean busy_on_write = false
    condition read, write

    function start_read()
        if (busy_on_write) wait(read)
        rc = rc + 1
        signal(read)

    function end_read()
        rc = rc - 1
        if (rc == 0) signal(write)

    function start_write()
        if (rc > 0 OR busy_on_write) wait(write)
        busy_on_write = true

    function end_write()
        busy_on_write = false
        if (in_queue(read))
            signal(read)
        else
            signal(write)
```

**Problema:** Nonostante l'eleganza del monitor, la logica di base non cambia. I nuovi lettori continuano a entrare liberamente se non c'è uno scrittore _attivo_ (anche se c'è uno scrittore in _attesa_). Inoltre, quando uno scrittore finisce (`end_write`), controlla prima se ci sono lettori in coda e li risveglia, dando loro di nuovo la precedenza. La starvation per gli scrittori è ancora possibile.

---

**Tentativo 3: Soluzione n.2 basata sui monitor (Frenare i nuovi lettori)**
Per mitigare la starvation degli scrittori, si introduce una piccola ma cruciale modifica nella funzione `start_read()`
```
function start_read()
	/* Modifica: aspetta anche se c'è uno scrittore in coda */
	if (busy_on_write OR in_queue(write)) wait(read)
	rc = rc + 1
	signal(read)
```

**Miglioramento e limite:** Adesso, se uno scrittore si mette in attesa, i **nuovi** lettori che arrivano vengono bloccati. Questo evita che un flusso continuo di lettori tenga in ostaggio il database. Tuttavia, c'è un'incoerenza: quando lo scrittore finisce di scrivere (`end_write`), la logica precedente risveglia ancora prima i lettori in coda rispetto ad altri scrittori in coda. Questo porta a un'alternanza poco efficiente se ci sono molte scritture pendenti.

---

**Tentativo 4: Soluzione n.3 basata sui monitor (Priorità agli scrittori)**
Per risolvere definitivamente la latenza per gli scrittori, si inverte la logica di risveglio al termine di una scrittura.
```
monitor rw_monitor
    int rc = 0; boolean busy_on_write = false
    condition read, write

    function start_read()
        if (busy_on_write OR in_queue(write)) wait(read)
        rc = rc + 1
        signal(read)

    function end_read()
        rc = rc - 1
        if (rc == 0) signal(write)

    function start_write()
        if (rc > 0 OR busy_on_write) wait(write)
        busy_on_write = true

    function end_write()
        busy_on_write = false
        /* Logica invertita: precedenza agli scrittori */
        if (in_queue(write))
            signal(write)
        else
            signal(read)
```
In questa soluzione definitiva, si garantisce che:
1. I nuovi lettori si fermano se c'è uno scrittore in attesa.
2. Quando uno scrittore termina, cede il passo immediatamente al **prossimo scrittore in coda**.

### Scheduling

###### Introduzione allo scheduling
Quando un computer lavora in multiprogrammazione, si verifica spesso una competizione per l'utilizzo della CPU tra processi o _thread_ che si trovano contemporaneamente nello stato "pronto". Se il sistema dispone di una singola CPU, è necessario decidere a chi assegnarla.
- **Scheduler:** La componente del sistema operativo incaricata di decidere quale processo eseguire.
- **Algoritmo di scheduling:** La logica e le regole utilizzate dallo _scheduler_ per operare questa scelta.

Effettuare il cambio di processo (o **_context switch_**) è un'attività estremamente onerosa in termini di prestazioni. Richiede il passaggio in modalità _kernel_, il salvataggio dei registri e della mappa di memoria, l'aggiornamento della _Memory Management Unit_ (MMU) e l'invalidazione della memoria _cache_, che dovrà poi essere ricaricata. Un numero eccessivo di scambi penalizza l'efficienza globale.

Comprendere il comportamento dei processi è fondamentale per il design di un buon algoritmo:
- **Processi CPU-bound:** Spendono la maggior parte del loro tempo eseguendo calcoli complessi (lunghi burst di CPU) con rare attese di I/O.
- **Processi I/O-bound:** Spendono gran parte del loro tempo in attesa di terminare operazioni I/O (brevi burst di CPU). Si noti che la durata dell'I/O non c'entra: il punto è che non effettuano elaborazioni consistenti tra una richiesta e l'altra. Poiché le CPU evolvono più rapidamente dei dischi, la tendenza è che i processi diventino progressivamente sempre più _I/O-bound_.

###### Quando effettuare lo scheduling
Le decisioni di _scheduling_ si rendono necessarie in quattro momenti chiave:
1. Alla **creazione di un processo**, lo _scheduler_ sceglie se eseguire prima il genitore o il figlio.
2. Alla **terminazione di un processo**, per pescarne uno nuovo dalla coda dei pronti.
3. Al **blocco di un processo** (es. attesa I/O, attesa su un semaforo), per non lasciare la CPU inattiva.
4. Al verificarsi di un **interrupt di I/O** (un dispositivo ha terminato un'operazione, sbloccando potenzialmente un processo in attesa).

###### Categorie di Algoritmi e ambienti
Il modo in cui gli algoritmi reagiscono agli _interrupt_ del clock definisce la loro natura:
- **Algoritmo non preemptive:** Un processo selezionato mantiene il possesso della CPU ininterrottamente finché non si blocca volontariamente o termina. Non viene mai interrotto forzatamente per limiti di tempo.
- **Algoritmo preemptive:** Al processo è assegnato un tempo massimo di esecuzione. Scaduto tale intervallo, un _interrupt_ del clock permette allo _scheduler_ di riprendere forzatamente il controllo della CPU e assegnarla a un altro processo.

Gli obiettivi di uno _scheduler_ variano a seconda dell'ambiente operativo:
- **Obiettivi universali:** Equità (giusta condivisione delle risorse), corretta applicazione delle policy stabilite e bilanciamento del sistema.
- **Sistemi batch:** Massimizzare il _throughput_ (lavori/ora), ridurre il tempo di _turnaround_ (attesa dalla sottomissione al completamento) e mantenere la CPU sempre attiva.
- **Sistemi interattivi:** Offrire tempi di risposta immediati per soddisfare le aspettative umane.
- **Sistemi Real-Time**: Garantire il rispetto delle scadenze (_deadline_) ed evitare il degrado della qualità.

###### Algoritmi per sistemi batch
- **First-come first-served (FCFS):** Algoritmo _non preemptive_ basato su una singola coda. Assegna la CPU nell'ordine di arrivo delle richieste.
    - _Pro:_ Facilissimo da implementare e comprendere.
    - _Contro:_ Fortemente svantaggioso in ambienti misti. Un singolo processo _compute-bound_ può monopolizzare la CPU per un secondo intero, ritardando inutilmente centinaia di processi _I/O-bound_ che avrebbero impiegato pochi millisecondi.
- **Shortest job first (SJF):** Algoritmo _non preemptive_ che preleva sempre il processo con il tempo stimato di esecuzione più breve. È matematicamente ottimale per ridurre il tempo medio di _turnaround_, ma solo se tutti i processi sono disponibili simultaneamente.
- **Shortest remaining time next:** La variante _preemptive_ dell'SJF. Lo _scheduler_ subentra e cambia processo se ne arriva uno il cui tempo necessario alla conclusione è inferiore al tempo rimanente del processo attualmente in esecuzione.

###### Algoritmi per sistemi interattivi
- **Round-robin:** A ogni processo è assegnato un intervallo di tempo, chiamato **quanto**, durante il quale gli è consentito di essere eseguito. Se alla fine del quanto il processo è ancora in esecuzione, la CPU viene prelazionata e assegnata a un altro processo. Se il processo si blocca o termina prima che sia trascorso il quanto, viene fatto uno scambio di CPU, naturalmente, quando il processo si blocca. Il round-robin è facile da realizzare. Tutto quello che lo scheduler deve fare è mantenere una lista dei processi eseguibili
  
  *Come viene gestita la lunghezza di un quanto di tempo*
  L'unica questione interessante che riguarda il round-robin è la durata del quanto. La gestione del passaggio da un processo a un altro richiede una certa quantità di tempo. 
  
  Supponete che questo scambio di contesto richieda $1 ms$, supponete anche che il quanto sia impostato a $4 ms$. Con questi parametri, dopo $4 ms$ di lavoro utile, la CPU deve spendere (cioè sprecare) $1 ms$ per lo scambio di processo. È evidente che è troppo.
  
  Per migliorare l'efficienza della CPU, potremmo, diciamo, impostare il quanto a $100 ms$. Il tempo sprecato è ora solo l'1%. Ma si consideri che cosa accade su un sistema server se arrivano $50$ richieste in un intervallo di tempo molto breve e con richieste di CPU molto diverse. Cinquanta processi saranno messi nell'elenco dei processi eseguibili. Se la CPU è inattiva, il primo partirà immediatamente, il secondo non potrà partire prima di $100 ms$ e così via.
  
  La conclusione può essere formulata come segue: impostare un quanto come troppo breve causa troppi scambi di processo e riduce l'efficienza della CPU, ma impostarlo come troppo alto può causare una risposta scadente alle richieste rapide interattive. Un quanto di circa 20-50 ms è spesso un compromesso ragionevole.
  
- **Scheduling a priorità:** A ciascun processo viene assegnato un valore di priorità statico (es. ruoli aziendali) o dinamico. La CPU va al processo eseguibile con priorità massima. 
  
  Per impedire che i processi ad alta priorità siano eseguiti indefinitamente, lo scheduler può abbassare la priorità del processo attualmente in esecuzione a ogni scatto del clock (cioè a ogni interrupt). Se questa azione fa sì che la sua priorità vada al di sotto di quella del processo successivo, avviene uno scambio di processo. In alternativa a ciascun processo può essere assegnato un quanto di tempo massimo in cui può essere eseguito. 
  
  Al fine di ottenere determinati obiettivi le priorità possono essere anche assegnate dinamicamente dal sistema. Per esempio, alcuni processi sono molto I/O bound e spendono gran parte del loro tempo aspettando che l'I/O termini. In qualunque momento un processo di questo tipo richieda la CPU, dovrebbe essergli data immediatamente, per consentirgli di far avviare la sua richiesta successiva di I/O, che può poi procedere in parallelo con un altro processo effettivamente in elaborazione.
  
  È spesso conveniente raggruppare i processi in classi di priorità e usare lo scheduling a priorità fra le classi, ma all'interno di ciascuna classe usare lo scheduling round-robin. L'algoritmo di scheduling è il seguente: finché vi sono processi eseguibili a priorità 4, eseguire ciascuno per un quanto, in stile round-robin, senza perder tempo con le classi di priorità basse. Se la priorità 4 è vuota, allora eseguire i processi a priorità 3 in round-robin e così via.
  ![[Pasted image 20260430110220.png|500]]
- **Code multiple**: astrazione dello scheduling con priorità provvisto di **divisione in classi**, in pratica qui scegliamo un algoritmo di **scheduling verticale** (che decide quale classe avviare prima) e uno di **scheduling orizzontale** (che decide quale processo mettere in esecuzione in una specifica classe), si può avere un algoritmo di scheduling orizzontale diverso per ogni classe. 
  
  Il problema di questo modello puro a Code Multiple è il rischio di *Starvation* se le code "alte" si riempiono continuamente, le code più basse non otterranno mai la CPU. Per prevenire questo problema i Sistemi Operativi reali implementano una logica chiamata **code multiple con Retroazione**. In pratica, anziché ancorare un processo alla sua coda orizzontale in modo perpetuo, il sistema valuta il suo comportamento dinamico facendolo scivolare nelle code a priorità inferiore se questo consuma interamente il suo quanto di tempo senza mai bloccarsi per compiere operazioni di I/O. Questa discesa verso il basso isola i processi pesanti e puramente computazionali per favorire quelli interattivi. Di conseguenza, avremo le code a *priorità alta* popolate da processi I/O bound, *quelle a priorità bassa* da processi CPU bound e quelle a *priorità intermedia* da processi misti. Per assecondare questa struttura, si assegnano quanti di tempo più piccoli nelle priorità alte, che vengono utilizzati per i processi I/O bound che rendono il sistema molto più reattivo, mentre nelle code a priorità bassa si usano quanti di tempo progressivamente più grandi. 
  
  A tal proposito, la classe con la priorità più bassa in assoluto può avere *un quanto di tempo pari a più infinito*, il che significa adottare un algoritmo orizzontale First-Come, First-Served: essendo l'ultima ruota del carro, eseguita solo quando il resto del sistema è inattivo, conviene far girare i processi pesanti in modo ininterrotto per evitare gli sprechi di prestazioni causati dai continui cambi di contesto. 
  
  Un altro modo per gestire l'equità è cambiare lo scheduling verticale assegnando un tempo T a un ciclo. **Per ogni livello verrà assegnata una percentuale di T** a ogni coda di priorità. Se una coda è vuota la percentuale di T sarà minore (es. 50%, 25%, 15%, 10%).
  ![[Pasted image 20260430110643.png|500]]
- **Shortest process next** (Sui sistemi interattivi): Tenta di applicare la logica SJF stimando la durata del prossimo comando tramite l'esperienza passata, con una tecnica chiamata **_aging_**. Un approccio è quello di fare delle stime basate sull'esperienza maturata ed eseguire il processo con il tempo di esecuzione stimato più breve. Supponiamo che il tempo stimato per un comando per un certo terminale sia $T_0​$. Supponiamo che la sua esecuzione successiva sia misurata come $T_1$​. Potremmo aggiornare la nostra stima facendo una somma pesata dei numeri, ossia:  $$aT_0 + (1 - a)T_1$$Tramite la scelta di a possiamo decidere se avere il processo di stima che dimentica in breve tempo le ultime esecuzioni o le ricorda a lungo. La tecnica di stimare il valore successivo di una serie prendendo la media pesata del valore attuale misurato e la stima precedente è talvolta detta **aging**.
  ![[Pasted image 20260430105010.png|500]]
  
- **Scheduling garantito:** Il sistema fa una promessa all'utente (es. con $n$ processi, otterrai $1/n$ della potenza CPU). Per riuscire a mantenere questa promessa, il sistema deve tener traccia di quanta CPU ha ricevuto ogni processo dal momento della sua creazione. Poi calcola la quantità di CPU che ognuno ha diritto ad avere, cioè il tempo dalla creazione diviso n. Poiché è conosciuta la quantità di tempo di CPU ricevuto da ogni processo, è semplice calcolare il rapporto fra effettivo tempo di CPU consumato e tempo di CPU cui si ha diritto. Un rapporto di 0,5 significa che un processo ha avuto la metà di quanto avrebbe dovuto, un rapporto di 2,0 significa che il processo ha avuto il doppio di quanto aveva diritto. L'algoritmo **esegue poi il processo con il rapporto minore** finché il suo rapporto non supera quello del suo più vicino concorrente.
  
- **Scheduling a lotteria:** L'idea base è quella di dare ai processi un biglietto della lotteria per le diverse risorse del sistema, come il tempo di CPU. Ogni volta che deve essere presa una decisione di scheduling si pesca un biglietto della lotteria e il processo che ha quel biglietto si aggiudica la risorsa. 
  
  Ai processi più importanti possono essere assegnati dei biglietti extra, per aumentare le loro possibilità di vincere. Se ci sono 100 biglietti non estratti e un processo ne possiede 20, ha il 20% di possibilità di vincere ogni estrazione. A lungo termine si prenderà il 20% della CPU.
  
  Processi cooperanti possono, se lo desiderano, scambiarsi i biglietti. Per esempio, quando un processo client manda un messaggio a un processo server e poi si blocca, può elargire tutti i propri biglietti al server, per aumentare la possibilità che il server sia il prossimo a essere eseguito. Quando il server ha terminato, restituisce i biglietti al client, in modo che possa nuovamente essere eseguito. Di fatto, in assenza di client, ai server non serve alcun biglietto.

- **Scheduling fair-share:** Finora abbiamo ipotizzato che ogni processo fosse schedulato per proprio conto, senza considerare a chi appartenesse. Di conseguenza, se l'utente $1$ avvia $9$ processi e l'utente $2$ ne avvia $1$, con il round-robin o le priorità uguali, l'utente $1$ si prenderà il $90\%$ della CPU e l'utente $2$ ne prenderà solo il $10\%$. Per evitare questa situazione, prima di schedularlo, alcuni sistemi prendono in considerazione chi possiede un processo. In questo modello, a ogni utente viene assegnata una frazione di CPU e lo scheduler raccoglie i processi in modo tale da farla rispettare. Così se a due utenti è stato assegnato il $50\%$ della CPU, l'avranno, indipendentemente da quanti processi abbiano attivi.

###### Scheduling nei sistemi Real-Time
I sistemi real-time sono generalmente divisi in categorie come **hard real-time**, nel caso di scadenze assolute da assolvere, o **soft real-time** che implica un certo grado di tollerabilità. 

Gli eventi cui un sistema real-time può dover rispondere possono ulteriormente essere categorizzati come **periodici** (che avvengono a intervalli regolari) o **non periodici** (che avvengono imprevedibilmente). 

Gli algoritmi di scheduling real-time possono essere statici e dinamici. I primi intraprendono le loro decisioni di scheduling prima che il sistema inizi l'esecuzione, i secondi durante l'esecuzione. Lo scheduling statico funziona solo dove esiste in anticipo la disponibilità di un'informazione perfetta riguardo al lavoro da svolgere e le scadenze da raggiungere.
###### Scheduling a Thread
Quando molti processi hanno ognuno molteplici thread, abbiamo due livelli di parallelismo presenti: **processi e thread**. 

Lo scheduling in questi sistemi si differenzia sostanzialmente a seconda che siano supportati **thread utente o a livello kernel** (o entrambi). 

*Consideriamo per primi i thread utente*. Dato che il kernel non è a conoscenza dell'esistenza dei thread, opera come fa sempre, prendendo un processo, diciamo A, e assegnando ad A il controllo per il suo quanto. Lo scheduler di thread interno ad A decide quale thread eseguire, diciamo A1. Poiché per questi thread non vi sono interrupt del clock, questo può continuare l'esecuzione quanto vuole. Se utilizza l'intero quanto del processo, il kernel selezionerà un altro processo da eseguire. La sola restrizione è l'assenza di interrupt del clock che interrompano un thread eseguito troppo a lungo.

*Consideriamo adesso la situazione con i thread del kernel.* In questo caso il kernel preleva un particolare thread da eseguire. Non deve tener conto del processo cui appartiene il thread, ma può farlo, se vuole. Al thread è dato un quanto e se eccede quel quanto è sospeso forzatamente. Poiché il kernel sa che il passaggio da un thread nel processo A a un thread nel processo B è più costoso che eseguire un secondo thread nel processo A (dovuto al fatto di dover cambiare la mappa di memoria e dover svuotare la memoria cache), può tener conto di questa informazione quando deve prendere una decisione. Per esempio, dati due thread che sono ugualmente importanti, con uno di loro appartenente allo stesso processo del thread che si è bloccato, la preferenza potrebbe essere assegnata a questo.

Una differenza rilevante fra i thread utente e i thread del kernel sta nelle prestazioni. Fare uno scambio di thread utente richiede una manciata di istruzioni macchina. Con i thread del kernel richiede di fare uno scambio completo di contesto, il che è più lento di parecchi ordini di grandezza. D'altra parte, con i thread del kernel, un thread bloccato in attesa di I/O non sospende l'intero processo, come avviene con i thread utente.
###### Lo Scheduling su Sistemi Multiprocessore
1. **Multielaborazione asimmetrica:** Un processore assume il ruolo di **_master_** e concentra su di sé tutta la logica di scheduling, mentre gli altri fungono da **_slave_**.
    - _Pro:_ Nessun problema di accesso concorrente alle code dei processi.
    - _Contro:_ Scarsissima scalabilità. Il _master_ diventa presto un collo di bottiglia (_bottleneck_).
2. **Multielaborazione simmetrica (SMP):** Architettura standard attuale. Tutti i processori hanno lo stesso ruolo e i medesimi diritti. La gestione concorrente delle code può avvenire in due modi:
    - **Coda unificata:** Richiede meccanismi di sincronizzazione stretta (es. un **_lock_**). Quando uno _scheduler_ di un _core_ interroga la struttura dati, la blocca per tutti gli altri, che si metteranno in fila. Non c'è necessità di bilanciamento del carico.
    - **Code separate:** Ciascun _core_ dispone di un proprio _scheduler_ e di una coda personale. È la via più utilizzata. Sviluppa enormemente la **prelidezione**, ovvero l'alta probabilità che un _core_ riprenda a elaborare un processo di cui si era già occupato, massimizzando il numero di **_cache hit_**.

L'approccio a code separate necessita di gestire le discrepanze, affinché non ci sia un _core_ sovraccarico e uno inattivo. Esistono due metodologie:
- **Migrazione guidata:** Un _core_ supervisiona periodicamente il sistema. Se rileva uno sbilanciamento, interviene spalmandone il carico in eccesso sulle code vuote. (Ecco perché, anche con code separate, serve implementare un sistema di _lock_).
- **Migrazione spontanea:** È il _core_ inattivo a prendere l'iniziativa. Esplora le code dei _core_ intasati e "ruba" loro alcuni processi. Questo meccanismo abbatte il principio della prelidezione, ma è spesso affiancato da regole di **prelidezione forte**, che forzano certi _core_ a gestire specifici processi proprio per preservare e favorire i vantaggiosi **_cache hit_**.

###### Lo Scheduling nei principali sistemi operativi
- **Windows:** Utilizza uno scheduler basato su **code di priorità separate**. Fa largo uso di **euristiche** per favorire i processi interattivi in _foreground_ (tipici dei sistemi desktop) e per prevenire il problema dell'_inversione della priorità_.
- **MacOS:** Molto simile a Windows, impiega un _Mach scheduler_ anch'esso basato su code di priorità ed euristiche.
- **Linux:** Non distingue rigidamente processi e thread, ma gestisce una loro generalizzazione chiamata **task**. Utilizza il **Completely Fair Scheduler (CFS)**. Il CFS usa un albero rosso-nero per ordinare i task in base al loro **virtual run-time**. La CPU viene sempre assegnata al task con il tempo virtuale minore.

## Capitolo 3
### La memoria
###### Introduzione alla gerarchia della memoria
I moderni sistemi informatici adottano una **gerarchia della memoria** per bilanciare costi e prestazioni. Questa struttura si articola solitamente in tre livelli:
- **Memoria molto veloce:** Pochi megabyte, estremamente costosa e volatile.
- **Memoria di medio costo:** Qualche gigabyte, abbastanza veloce e volatile (RAM).
- **Memoria su disco:** Alcuni terabyte, non volatile, lenta ma a basso costo.
**Gestore della memoria:** È la componente del sistema operativo incaricata di gestire questa gerarchia.

Storicamente, dai primi _mainframe_ (prima del 1960) fino ai primi _personal computer_ (prima del 1980), non esisteva alcuna astrazione della memoria. Ogni programma interagiva direttamente con la **memoria fisica**. In questo scenario, il modello presentato al programmatore è un insieme di indirizzi che vanno da 0 a un limite massimo. In assenza di astrazione, non è possibile eseguire due programmi contemporaneamente: se un programma scrivesse in una posizione usata da un altro, ne cancellerebbe i dati. Esistono tre varianti principali per l'organizzazione del sistema operativo in questo modello:
1. **S.O. in RAM:** Il sistema operativo risiede nel fondo della memoria nella **RAM (Random Access Memory)**.
2. **S.O. in ROM:** Il sistema operativo si trova in cima alla memoria nella **ROM (Read Only Memory)**.
3. **Modello Ibrido:** I driver dei dispositivi risiedono nella ROM in cima alla memoria, mentre il resto del sistema è nella RAM sottostante. Questo modello è tipico dei primi PC con MS-DOS, dove la parte in ROM è nota come **BIOS (Basic Input Output System)**.
![[Pasted image 20260501104611.png|500]]
###### Esecuzione di molteplici programmi senza astrazione
È possibile ottenere un certo grado di parallelismo anche senza astrazione, seguendo diverse strategie:
- **Programmazione con thread**: Un metodo per avere parallelismo è utilizzare molteplici _thread_ all'interno dello stesso contesto di memoria. Essendo thread fanno parte dello stesso processo, quindi non è una vera esecuzione di più programmi.
- **Swapping (Versione primitiva)**: Un'altra possibilità è eseguire un programma alla volta, salvando l'intero contenuto della memoria su disco quando si passa al processo successivo. Finché risiede un solo programma in memoria, non si verificano conflitti.
- **Protezione tramite chiavi (IBM 360):** Con l'ausilio di hardware speciale, è possibile far risiedere più programmi contemporaneamente. L'IBM 360 utilizzava una **chiave di protezione** di 4 bit per ogni cella di memoria. La PSW di un processo conteneva conteneva una chiave di 4 bit che gli permetteva di interagire con la locazione di memoria a lui assegnata. L'hardware intercettava ogni tentativo di accesso alla memoria: se il codice di protezione del processo non coincideva con la chiave nella PSW, l'accesso veniva bloccato.

###### Il problema della rilocazione
Anche se i programmi sono protetti dalle chiavi, sorge il problema degli indirizzi assoluti. Se due programmi da 16 KB vengono caricati uno sopra l'altro, il secondo (caricato all'indirizzo 16.384) fallirà se tenta di eseguire un salto relativo al proprio inizio (es. `JMP 28`), poiché finirà per saltare a un indirizzo nel primo programma invece che nel proprio. In questo esempio vediamo esattamente questa cosa, dopo aver caricato il processo a e b in memoria (c) possiamo notare che:
- *processo A*: il jump 24 funzionerà bene e il processo finisce in modo corretto
- *processo B*: il jump 28 cercherà di saltare ma entra nella memoria del primo processo e andrà in errore
![[Pasted image 20260501105311.png|500]]

Una soluzione a questo problema è la **rilocazione statica:** consiste nel modificare il programma direttamente durante il caricamento in memoria, aggiungendo l'indirizzo di partenza (es. 16.384) a ogni indirizzo del programma. Funzionava in questo modo: quando un programma era caricato all'indirizzo 16.384, la costante 16.384 era aggiunta a ogni indirizzo del programma durante il processo di caricamento. Anche se questo meccanismo funziona bene se eseguito in modo corretto, ma non è una soluzione in generale e rallenta il caricamento.
### L'astrazione della memoria: lo spazio degli indirizzi
Esporre la memoria fisica presenta due gravi inconvenienti:
1. I programmi utente possono distruggere il sistema operativo.
2. È difficile gestire l'esecuzione contemporanea di più programmi.

Per risolvere i problemi di **protezione** e **riposizionamento**, è stata introdotta l'astrazione chiamata **spazio degli indirizzi**. Lo **spazio degli indirizzi:** è l'insieme degli indirizzi che un processo può utilizzare per indirizzare la memoria. Per rendere possibile questa astrazione virtuale in prima battuta facciamo uso della tecnica della rilocazione dinamica
###### Rilocazione dinamica: registri base e limite
La **rilocazione dinamica**, mappa lo spazio degli indirizzi di ogni processo su porzioni diverse di memoria fisica tramite hardware speciale, ovvero attraverso due registri della CPU:
- **Registro Base:** Contiene l'indirizzo fisico di partenza del programma in memoria.
- **Registro Limite:** Contiene la lunghezza del programma.
Quando un processo accede alla memoria, l'hardware esegue due passaggi automatici:
1. **Somma:** Aggiunge il valore del registro base all'indirizzo generato dal programma prima di inviarlo al bus.
2. **Controllo:** Verifica se l'indirizzo è uguale o maggiore del valore nel registro limite; in tal caso, genera un errore e interrompe l'accesso.
Su questa soluzione possiamo dire che:
- **Vantaggi:** Permette a ogni processo di avere uno spazio privato degli indirizzi in modo semplice.
- **Svantaggi:** Ogni riferimento alla memoria richiede una somma e un confronto, il che può rappresentare un onere computazionale.

![[Pasted image 20260501163345.png|700]]
###### Gestione del sovraccarico di memoria
Spesso la quantità totale di RAM richiesta dai processi in esecuzione supera la memoria fisica effettivamente disponibile. Per gestire questo scenario, i sistemi operativi hanno storicamente adottato due strategie principali:
1. **Swapping:** Consiste nello spostare interamente su disco i processi temporaneamente inattivi per fare spazio ad altri.
2. **Memoria virtuale:** Un'evoluzione successiva che consente l'esecuzione di programmi caricandone in RAM solo le parti strettamente necessarie.
###### Lo Swapping e la Frammentazione
Immaginiamo di avere due programmi, $P_1$ e $P_2$. Attualmente $P_1$ è in esecuzione, ma vogliamo eseguire anche $P_2$. Purtroppo, la memoria centrale (RAM) è piena. A questo punto interviene il componente del sistema operativo chiamato **swapper**: esso esegue uno _swap-out_ (sposta $P_1$ dalla RAM al disco) e uno _swap-in_ (carica $P_2$ dal disco alla RAM). Il disco viene quindi usato come "memoria secondaria" di appoggio. Il processo $P_1$, finché si trova su disco, è penalizzato poiché non riceve risorse dalla CPU. Sebbene sembri una soluzione perfetta, lo swapping continuo di programmi di dimensioni diverse crea un grave problema: la **frammentazione della memoria** . Ne esistono due tipi:
- **Frammentazione Interna:** Si verifica quando a un processo viene assegnata un'area di memoria leggermente più grande delle sue reali esigenze. Lo spazio extra all'interno di quell'area allocata rimane inutilizzato e sprecato.
- **Frammentazione Esterna:** Si verifica quando la memoria totale libera sarebbe sufficiente per ospitare un nuovo processo, ma è suddivisa in tanti piccoli blocchi non contigui (buchi). Poiché il processo necessita di memoria contigua, non può essere caricato. L'unica soluzione è la **Memory Compaction** (Compattazione della memoria): il S.O. sposta fisicamente tutti i processi attivi verso il fondo della memoria per unire tutti i "buchi" in un unico grande spazio libero in cima. È una procedura estremamente lenta e si cerca di evitarla il più possibile.
###### Il problema dell'Allocazione con Dimensione Dinamica
La gestione della frammentazione è ulteriormente complicata dal fatto che i processi non hanno sempre dimensioni fisse. Durante l'esecuzione, i dati di un programma possono crescere (ad esempio, allocando memoria dinamicamente). La struttura ottimale per gestire la crescita dinamica all'interno di un processo prevede due segmenti mobili:
- **Segmento Dati (Heap):** Posizionato subito dopo il codice statico del programma, cresce verso l'alto.
- **Segmento Stack (per variabili locali e ritorni):** Posizionato in cima all'area di memoria allocata per il processo, cresce verso il basso.
![[Pasted image 20260501112958.png|500]]
Se questi due segmenti crescono fino a scontrarsi, il processo ha finito lo spazio. Come interviene il S.O.?
- _Soluzione 1 (Sospensione):_ Se non c'è spazio adiacente in RAM per far crescere il processo e l'area di swap su disco è piena, il processo deve essere sospeso o terminato.
- _Soluzione 2 (Pre-allocazione):_ Una strategia preventiva. Quando il S.O. carica o sposta un processo, gli assegna preventivamente un "cuscinetto" di memoria extra, prevedendone la crescita. Tuttavia, se la crescita non avviene, questa memoria extra rimane sprecata (causando frammentazione interna).

###### Tenere traccia della memoria: Bitmaps e Liste
A causa dello swapping e delle dimensioni variabili dei processi, la memoria fisica diventa rapidamente un puzzle disordinato di "blocchi occupati" alternati a "buchi liberi". **Il Sistema Operativo ha quindi bisogno di strumenti per ricordarsi esattamente quali parti di RAM sono occupate e quali sono libere.** Utilizza principalmente due tecniche:

**A. Gestione con Bitmap**
La memoria viene idealmente divisa in "unità di allocazione" (che possono andare da pochi byte a vari kilobyte). La **Bitmap** è una lunga mappa in cui ogni bit rappresenta un'unità: `0` significa libera, `1` significa occupata (o viceversa).
- _Il parametro cruciale:_ La dimensione dell'unità di allocazione. Se scegliamo unità molto piccole (es. 4 byte), avremo una mappa enorme (per mappare 32 bit di memoria ci vorrà 1 bit di mappa).
- _Vantaggi:_ La dimensione della bitmap è fissa e dipende solo dalla quantità totale di RAM e dalla dimensione scelta per l'unità.
- _Svantaggi:_ Quando bisogna caricare un nuovo processo che richiede _k_ unità contigue, il S.O. deve scansionare la lunghissima sequenza di bit per cercare una stringa ininterrotta di _k_ zeri. Questa ricerca è estremamente lenta.
![[Pasted image 20260501170015.png|500]]
**B. Gestione con Liste Collegate**
Invece di mappare ogni singolo blocco, il S.O. mantiene una lista dinamica (Linked List) che mappa interi segmenti . Ogni nodo (voce) della lista descrive un blocco contiguo, e contiene:
1. Il tipo: Processo occupato (`P`) o Buco vuoto (`H` - _Hole_).
2. L'indirizzo fisico di partenza.
3. La lunghezza del blocco.
4. Il puntatore al segmento successivo.
La lista è ordinata in base all'indirizzo fisico crescente. 
![[Pasted image 20260501170052.png|500]]
Il momento più delicato in questo sistema è **quando un processo termina** o viene "swappato". Il suo segmento `P` diventa un segmento `H`. A questo punto, il S.O. deve guardare i segmenti vicini per evitare la frammentazione, potendo incontrare 4 casistiche:
- _(a) Nessun vicino vuoto:_ Si aggiorna semplicemente il nodo da `P` ad `H`.
- _(b) Vicino vuoto sopra:_ Il nuovo buco e quello precedente vengono fusi. La lista si accorcia di una voce.
- _(c) Vicino vuoto sotto:_ Il nuovo buco e quello successivo vengono fusi. La lista si accorcia di una voce.
- _(d) Entrambi i vicini vuoti:_ Si fondono tre buchi adiacenti in un unico grande spazio vuoto. Vengono eliminati due elementi dalla lista.
![[Pasted image 20260501170129.png|500]]

###### Algoritmi di allocazione: Come scegliere il "buco" giusto?
Quando arriva un nuovo processo, il gestore della memoria deve scorrere la lista collegata per trovargli un buco adeguato. Ma quale sceglie se ce n'è più di uno? Usa degli specifici algoritmi:
1. **First fit (Primo incastro):** È il più semplice e veloce. Scorre la lista dall'inizio e prende il _primo_ buco abbastanza grande. Se il buco è più grande del processo, viene diviso in due: una parte per il processo e una per il buco residuo.
2. **Next fit (Incastro successivo):** Identico al First fit, ma "si ricorda" dove aveva trovato l'ultimo spazio. La ricerca successiva riparte da quel punto invece che dall'inizio. Previene l'accumulo di piccoli buchi tutti all'inizio della memoria.
3. **Best fit (Miglior incastro):** Cerca in _tutta_ la lista e sceglie il buco più piccolo tra quelli in grado di contenere il processo.
    - _Svantaggio:_ È più lento (deve scorrere tutta la lista) e paradossalmente genera un enorme spreco di memoria: crea tantissimi microscopici "buchini" residui, inutilizzabili per qualsiasi altro processo.
4. **Worst fit (Peggior incastro):** Nasce per risolvere i difetti del Best fit. Cerca in tutta la lista e sceglie intenzionalmente il buco _più grande in assoluto_. L'idea è che il buco residuo che avanzerà sarà ancora abbastanza grande da poter ospitare altri processi in futuro.

> [!TIP]
> Per velocizzare queste ricerche, i progettisti hanno ideato tre strategie di ottimizzazione:
> - **Liste separate:** Invece di una lista mista, si usano due liste distinte: una solo per i processi e una solo per i buchi vuoti. Così gli algoritmi scansionano solo i buchi, risparmiando tempo.
> - **Ordinamento per dimensione:** La lista dei buchi viene ordinata dal più piccolo al più grande. Questo trasforma il _Best fit_ in un algoritmo velocissimo: il primo buco utile che incontra è per forza di cose il più piccolo adatto (quindi il migliore).
>     - _Svantaggio dell'ordinamento:_ Quando un processo termina, ritrovare i suoi vicini "fisici" per unire i buchi (le casistiche a,b,c,d viste prima) diventa un incubo computazionale, perché la lista non è più ordinata per posizione.

5. **Quick fit:** Usa array o tabelle che puntano a liste di buchi di dimensioni standardizzate e molto richieste (es. una lista solo per buchi da 4 KB, un'altra per buchi da 8 KB, ecc.).
    - _Vantaggio:_ Allocazione praticamente istantanea se il processo richiede una misura standard.
    - _Svantaggio:_ Come per l'ordinamento per dimensione, la deallocazione e la fusione dei buchi adiacenti restano operazioni molto dispendiose.
### La memoria virtuale
Come abbiamo visto, gestire "buchi" di memoria di dimensioni variabili (tramite liste e algoritmi di allocazione) è complesso e non risolve mai del tutto il problema della frammentazione. Per eliminare definitivamente questo ostacolo, l'informatica ha introdotto un'astrazione rivoluzionaria: la **memoria virtuale**.

L'obiettivo di questa astrazione è creare un'illusione perfetta: far credere a ogni programma in esecuzione di disporre di un'intera memoria centrale privata, continua e protetta. Con questa tecnica, lo spazio di memoria originario diventa uno **spazio di indirizzamento virtuale**, il quale viene suddiviso in piccoli blocchi di dimensione fissa chiamati **pagine**.

La caratteristica cruciale della memoria virtuale è che **non tutte le pagine di un programma devono risiedere contemporaneamente nella memoria fisica (RAM)** per poterne permettere l'esecuzione. Le pagine virtuali vengono mappate sulla memoria fisica in modo dinamico:
- **Accesso diretto:** Quando il programma fa riferimento a un indirizzo che fa parte di una pagina attualmente caricata nella memoria fisica, l'hardware esegue il mapping in modo diretto e istantaneo.
- **Recupero dal disco:** Quando, al contrario, il programma fa riferimento a uno spazio degli indirizzi che non è al momento presente nella memoria fisica, l'hardware genera un'interruzione. Il sistema operativo viene allertato per andare a recuperare il "pezzo" mancante dal disco (memoria secondaria), caricarlo in RAM, e infine rieseguire l'istruzione che era fallita.

###### La Paginazione (Paging) e la MMU
La paginazione ci permette quindi di suddividere la memoria fisica da quella virtuale associata ad ogni processo infatti quando un programma esegue un'istruzione come:
```
MOV REG,1000 // muove quello che c'è all'indirizzo 1000 dentro REG
```
 Per eseguirla deve accedere prima alla memoria e lo fa generando degli indirizzi detti **indirizzi virtuali** (l'insieme di questi indirizzi forma lo **spazio virtuale degli indirizzi** che sarebbero l'insieme degli indirizzi a disposizione di un processo). Gli indirizzi virtuali generati dalla CPU non vanno direttamente al bus di memoria ma passano prima attraverso un componente hardware dedicato chiamato **MMU (Memory Management Unit)** che consiste in un unità di gestione della memoria che ha il compito di mappare gli indirizzi virtuali sugli indirizzi di memoria fisica.
![[Pasted image 20260503161434.png|500]]
###### Pagine e frame
Le unità base della gestione della paginazione sono:
- **Pagine:** unità di dimensione fissa in cui è suddiviso lo spazio degli indirizzi virtuali.
- **Frame:** Unità di memoria della memoria fisica (RAM). 
![[Pasted image 20260503161516.png|400]]

> [!EXAMPLE]
> Prendendo ad esempio pagine da $4 KB$ (coma da img):
> - L'intervallo segnato come $0K-4K$ significa che gli indirizzi virtuali in quella pagina vanno dall'indirizzo $0$ all'indirizzo $4095$.
> - L'intervallo $4K-8K$ si riferisce agli indirizzi che vanno da $4096$ a $8191$, e così via.
> - Di conseguenza, ogni pagina contiene esattamente $4096$ indirizzi, che partono da un multiplo di $4096$ fino al multiplo di $4096$ successivo.

La maggior parte delle volte abbiamo **molte più pagine virtuali che pagine fisiche**, questo perché quella virtuali possono risiedere anche in disco. Per gestire questa cosa nella tabella degli indirizzi è presente un **bit presente/assente**, il quale tiene traccia di quali pagine sono fisicamente presenti in memoria. Quando cerchiamo di indirizzare un indirizzo non mappato nella memoria fisica viene sollevato dalla CPU un trap verso il sistema operativo detto **page fault**. Quando accade il sistema operativo interviene prelevando frame poco utilizzato e ne scrive il suo contenuto su disco (se il dirty bit è true), fatto ciò inserisce l'indirizzo del frame di memoria richiesto dentro la mappatura dell'MMU e riavvia l'istruzione che era andata in trap.

> [!EXAMPLE]
> Esempio con un istruzione reale prendendo in considerazione la tabella degli indirizzi dell'immagine precedente:
> 1. *Tentativo di accesso*: La CPU esegue `MOV REG, 32780`, chiedendo di accedere alla Pagina virtuale 8.
> 2. *Page Fault*: La MMU consulta la _Page Table_, vede che la Pagina 8 non è in RAM (bit assente) e genera un'interruzione (trap) verso il Sistema Operativo.
> 3. *Swap-Out*: Il Sistema Operativo libera spazio in RAM: prende un _frame_ usato poco e lo copia su disco.
> 4. *Swap-In*: Il Sistema Operativo preleva la Pagina 8 dal disco e la scrive nel _frame_ appena liberato in RAM, e aggiorna la usata dall'MMU.
> 5. *Riavvio*: La CPU ripete l'istruzione `MOV REG, 32780`. Questa volta la MMU trova la pagina e l'operazione va a buon fine.

###### Il processo di traduzione 
Per tradurre un indirizzo virtuale in indirizzo fisico la CPU esegue uno specifico processo, prendendo in esame l'istruzione:

```
MOV REG,0 //mette quello che c'è all'indirizzo 0 in REG
```

Viene eseguita in questo modo
1. L'indirizzo virtuale 0 viene inviato alla **MMU**.
2. La **MMU** vede che questo indirizzo virtuale cade nella pagina 0 (che copre gli indirizzi da 0 a 4095).
3. Secondo il mapping interno della MMU, la pagina 0 corrisponde al frame 2 (che copre gli indirizzi fisici da 8192 a 12287).
4. La **MMU** trasforma così l'indirizzo virtuale 0 nell'indirizzo fisico 8192 e lo invia esternamente sul bus.

*Risultato:* La MMU ha effettivamente mappato tutti gli indirizzi virtuali compresi fra 0 e 4095 sugli indirizzi fisici che vanno da 8192 a 12287.

###### Come si comporta la MMU

> [!attention] La tabella delle pagine
> Di seguito nomineremo spesso la tabella delle pagine, ci basta sapere che è una tabella che contiene informazioni riguardo ogni pagina come i bit presente/assente e l'indirizzo fisico del frame alla quale è mappata quella pagina

Gli indirizzi virtuali generati dalla CPU sono così formati:
- **numero di pagina**: questi sono gli $m$ bit più significativi dell'indirizzo virtuale e ci indicano quale pagina guardare per trovare il nostro indirizzo (il numero di pagine totali è $2^m$)
- **offset**: questi sono gli $n$ bit meno significativi che ci indicano quale indirizzo prendere tra quelli disponibili nella singola pagina. ($2^n$ sono gli indirizzi contenuti da una pagina)

> [!TIP] Esercizio di esame
> Dato un indirizzo virtuale dobbiamo fare la seguente cosa per tradurlo in indirizzo fisico:
> Supponiamo di avere una RAM a $32$ kilobyte, e di voler accedere all'indirizzo virtuale $v = 8196$. 
> Con $\text{dimensione dei frame} = 4096$, effettuiamo: $$\frac{8196}{4096} = \begin{cases} 2 \text{ (Numero di Pagina)} \\ 4 \text{ (Offset)} \end{cases}$$
> Supponiamo che nella nostra tabella delle pagine, la pagina $2$ è associata al frame $6$. 
> Moltiplichiamo adesso $6 \cdot \text{dimensione dei frame} = 6 \cdot 4096 = 24576$. 
> Otterremo quindi il primo indirizzo fisico appartenente al frame 6. Sommiamo l'offset ottenuto in precedenza, $24576 + 4 = 24580$. 
> 

Scendendo nel dettaglio di cosa fa l'MMU possiamo dire che: il processo di traduzione viene eseguito in  maniera più veloce e intuitiva. La divisione è sempre di potenze di 2, in quanto strettamente legata alla dimensione dei frame. Sarà quindi possibile implementarla con uno shift. Nello specifico segue questi step (input: *indirizzo virtuale*):
1. **Estrazione del numero di pagina (Quoziente):** Viene eseguito uno shift logico verso destra di $n$ bit sull'indirizzo virtuale.
    _Formula:_ `NumeroPagina = VA >> n`
2. **Estrazione dell'offset (Resto):** Viene eseguito un AND logico tra l'indirizzo virtuale e una maschera composta da $n$ bit a 1.
    _Formula:_ `Offset = VA AND ((1 << n) - 1)`
3. **Consultazione della tabella delle pagine:** L'hardware usa il `NumeroPagina` appena trovato come indice per cercare nella tabella delle pagine il `NumeroFrame` corrispondente (se la pagina è in RAM).
4. **Allineamento del frame:** Il `NumeroFrame` trovato viene shiftato verso sinistra di $n$ bit. Questo crea lo spazio per inserire l'offset e, matematicamente, equivale esattamente a calcolare $\text{numeroFrame} \times 2^n$.
    _Formula:_ `IndirizzoBaseFisico = NumeroFrame << n`
5. **Composizione dell'indirizzo fisico:** Si esegue un OR logico (che in questo caso equivale a una somma, dato che i bit inferiori dell'indirizzo base sono tutti zeri) tra l'indirizzo base fisico e l'offset.
    _Formula:_ `IndirizzoFisico = IndirizzoBaseFisico OR Offset`

> [!TIP] Esercizio di esame
> * Virtual memory = 4Mb
> * voci tabella pagine = $2^{13}$
> * Numero di frame a 8bit
> 
> Quanta RAM ho? Avendo 4Mb = $2^{22}$byte di virtual memory, con $\frac{2^{22}}{2^{13}}$ avrei la dimensione della singola pagina, ovvero $2^9$.
> 
> $$2^9byte \cdot 2^8 \text{ (numero di frame)} = 128kb$$

###### La tabella delle pagine
La tabella delle pagine è una tabella utilizzata dall'MMU insieme al sistema operativo per tradurre da indirizzi virtuali a fisici, l'esatto layout di una voce di una singola tabella della pagina dipende molto dalla macchina su cui si opera. Tuttavia, il tipo di informazioni presenti è più o meno lo stesso per tutte le architetture. Di seguito una rassegna dei campi contenuti in una voce:
- **Numero del frame (frame number):** È il campo più importante in assoluto, in quanto indica l'indirizzo fisico in cui si trova la pagina.
- **Bit Presente/Assente:** Se questo bit è 1, la voce è valida e può essere utilizzata normalmente. Se è 0, significa che la pagina virtuale cui appartiene la voce non è effettivamente in memoria in quel momento.
- **Protezione:** Specifica quali tipi di accesso sono consentiti per quella pagina. Nella sua forma più basilare, questo campo contiene 1 solo bit: il valore 0 significa lettura/scrittura consentita, mentre il valore 1 indica l'accesso in sola lettura.
- **Bit Modificato (Dirty bit):** Tiene traccia dell'uso della pagina. Se la pagina è stata modificata rispetto alla sua versione in disco (cioè è considerata "sporca"), questo bit è impostato. Se la pagina non è stata modificata (cioè è considerata "pulita"), in caso di sfratto il suo contenuto può essere semplicemente abbandonato senza sovrascriverlo, poiché la copia originaria presente sul disco è ancora perfettamente valida.
- **Bit Referenziato:** È impostato dall'hardware ogni qualvolta si faccia riferimento alla pagina, sia per un'operazione di lettura sia in scrittura. Serve ad aiutare il sistema operativo a scaricare (cioè a "sfrattare") una pagina quando si verifica un page fault. Le pagine inutilizzate (non referenziate) sono le candidate migliori per lo sfratto rispetto a quelle usate di recente.    
- **Disabilitazione della cache:** L'ultimo bit consente di disabilitare la cache per la specifica pagina. Questo è fondamentale per l'I/O: fa in modo che la macchina debba prelevare la parola direttamente da quel dispositivo hardware, senza rischiare di usare una vecchia parola non aggiornata messa precedentemente in cache.

###### Problemi principali della paginazione
Nei sistemi operativi, la gestione della memoria tramite paginazione impone due sfide architetturali critiche e diametralmente opposte:
- **Velocità di traduzione:** La mappatura dall'indirizzo virtuale a quello fisico deve essere quasi istantanea. Poiché questa operazione avviene per _ogni singolo_ riferimento alla memoria, un minimo ritardo genera un collo di bottiglia per l'intero sistema.
- **Dimensione delle tabelle:** Con i moderni spazi di indirizzamento a 64 bit, il numero di pagine virtuali è immenso, rendendo le relative Tabelle delle Pagine (Page Table) enormi e ingombranti.
La necessità di avere un meccanismo che sia **contemporaneamente gigantesco e ultra-veloce** rappresenta un ostacolo storico per i progettisti. Dal punto di vista concettuale, il problema si scontra con due approcci estremi, nessuno dei quali è praticabile da solo.
1. Nel **primo approccio (basato sull'hardware)**, l'intera tabella delle pagine viene memorizzata in un array di registri interni alla CPU. Durante l'esecuzione le prestazioni sono eccellenti, poiché il processore non deve mai accedere alla RAM per tradurre gli indirizzi. Tuttavia, i costi architetturali sono proibitivi: con le dimensioni delle tabelle moderne, i tempi e le risorse necessarie per aggiornare milioni di registri a ogni _context switch_ paralizzerebbero il sistema.
2. All'**estremo opposto (approccio in memoria)**, l'intera tabella viene mantenuta esclusivamente nella RAM. In questo scenario all'hardware basta un singolo registro dedicato, il **PTBR** (_Page Table Base Register_), che punta all'inizio della tabella del processo in esecuzione. Se da un lato il _context switch_ diventa istantaneo (è sufficiente aggiornare il valore del PTBR) e si risolvono i limiti di spazio, dall'altro la lentezza diventa inaccettabile: ogni singola istruzione richiederebbe un accesso extra alla RAM solo per consultare la tabella, dimezzando di fatto le prestazioni del computer.
### Translation Lookaside Buffer (TLB)
Per bilanciare velocità e dimensioni, la soluzione escogitata è stata quella di equipaggiare i computer di un piccolo dispositivo *hardware* dedicato esclusivamente a mappare gli indirizzi virtuali sugli indirizzi fisici senza dover passare ogni volta dalla tabella delle pagine in memoria, questo dispositivo si chiama **TLB** Acronimo di **Translation Lookaside Buffer**, talvolta chiamato anche **memoria associativa**.
- **Capacità e Struttura:** Contiene solitamente poche voci, ciascuna voce contiene informazioni cruciali riguardo una pagina, tra cui: 
	- *il numero di pagina virtuale*
	- *un dirty bit*: quando avviene una modifica ad un record questo viene macchiato come dirty, quando questo succede e quel record deve essere eliminato dalla TLB la modifica deve essere riportata alla tabella delle pagine.
	- *il codice di protezione* (i permessi di lettura, scrittura ed esecuzione) 
	- *il frame fisico*
- **Funzionamento:** Quando un indirizzo virtuale viene presentato alla MMU per la traduzione, l'hardware per prima cosa guarda se il suo numero di pagina virtuale è presente nel TLB, confrontandolo simultaneamente (cioè in parallelo) con tutte le voci.
    - **TLB hit (successo di TLB):** Il numero di pagina viene trovato e la traduzione avviene istantaneamente.
    - **TLB miss (fallimento di TLB):** Avviene quando il numero di pagina virtuale non è nel TLB. In questo caso, la MMU rileva il miss e fa una normale ricerca sulla tabella delle pagine in memoria. Quindi sfratta una delle voci dal TLB e la rimpiazza con la voce della tabella delle pagine appena cercata e recuperata. In questo modo, se quella stessa pagina è riusata a breve termine, la seconda volta si avrà un successo (TLB hit).
- **Caratteristiche**: è importante dire che questa memoria hardware è comparabile ad una cache e la ricerca viene fatta su tutte le sue celle in modo parallelo, quindi è molto veloce.

###### Effective Access Time (EAT)
L'**Effective Access Time (EAT)**, o tempo di accesso effettivo, è una metrica fondamentale per valutare le prestazioni di un sistema di memoria con paginazione che utilizza un **Translation Lookaside Buffer (TLB)**. L'EAT ci permette di calcolare il tempo _medio_ ponderato di accesso alla memoria, tenendo conto del **TLB Hit Ratio** ($\varepsilon$), ovvero la percentuale di volte in cui la traduzione viene trovata con successo all'interno della TLB.

> [!EXAMPLE] Facciamo un esempio
> - tempo di accesso alla memoria: $\alpha = 100 \text{ ns}$
> - Tempo di accesso alla TLB: $\beta = 20 \text{ ns}$
> 
> I tempi effettivi?
> - Con un TLB hit abbiamo $100 + 20 = 120 \text{ ns}$.
> - Con un TLB miss abbiamo $2 \cdot 100 + 20 = 220 \text{ ns}$.
> 
> Con un ratio TLB = $\varepsilon$, tempo di accesso alla TLB = $\beta$ e tempo di accesso alla memoria $\alpha$ abbiamo
> $$\text{EAT} = \varepsilon(\alpha + \beta) + (1 - \varepsilon)(2\alpha + \beta)$$

###### Osservazioni importanti sulla TLB
Di seguito alcune osservazioni importanti sulla TLB:
- Alcuni attributi dei record delle tabelle delle pagine non sono presenti, come il bit di referenzialmento o di validità di allocazione. Osserviamo che, se un record è presente nella TLB, dev'essere per forza valido e referenziato.
- La TLB conterrà sempre record relativi a pagine utili per il programma attuale. Inoltre, quando avviene una TLB miss, si andrà ad aggiornare il valore sulla TLB.
- Alcuni voci possono essere vincolate ad essere nella TLB, migliorando le tempistiche.

Le tabelle delle pagine sono una per processo: ne consegue che gli stessi indirizzi virtuali possono essere riutilizzati per rifarsi a indirizzi fisici differenti. Tuttavia, la TLB è unica per la CPU (o il core). Detto ciò, a causa del riutilizzo degli indirizzi virtuali, bisogna avere un modo per disambiguare i record riguardanti ogni processo. Di seguito vediamo due strategie:
- **Flush totale della TLB a ogni context-switch:** Non ideale, favorisce un alto numero di cache miss iniziali.
- **Address-space ID:** Aggiungendo un identificatore, chiamato ASID, è possibile disambiguare le voci delle TLB con lo stesso indirizzo virtuale, ma appartenenti a processi differenti, favorendo cache hit ad ogni context switch.

La strategia migliore è la seconda. Complica un po' la ricerca, aggiungendo gli ASID alla ricerca del record nella TLB, ma è molto efficiente in ambienti multithread. È un ottimo compromesso.

###### Gestione TLB via software nelle architetture RISC
Finora si è supposto che ogni macchina con memoria virtuale paginata abbia delle tabelle delle pagine riconosciute direttamente dall'hardware, più un TLB. Nel passato questo assunto era valido. Tuttavia, molte macchine ad architettura RISC moderne eseguono quasi tutta questa gestione delle pagine tramite software.

Nella gestione del TLB via software, è fondamentale capire la differenza fra due tipi di miss:
- **Soft miss:** Avviene quando la pagina di riferimento non è nel TLB, ma si trova comunque all'interno della memoria RAM. La risoluzione è rapida.
- **Hard miss:** All'opposto, avviene quando la pagina stessa non è in memoria (e ovviamente nemmeno nel TLB). Per prendere la pagina serve un accesso al disco, il che comporta tempistiche di parecchi millisecondi. Questa situazione può esitare in un errore di **segmentazione (segmentation fault)**.

I TLB possono essere usati per velocizzare la traduzione dell'indirizzo virtuale nell'indirizzo fisico rispetto allo schema originale della "tabella-delle-pagine-in-memoria". Rimane però un altro problema aperto: *quale comportamento assumere con spazi degli indirizzi virtuali molto grandi?*

###### Tabelle delle pagine multilivello
La paginazione multilivello è una struttura gerarchica utilizzata dai sistemi operativi per tradurre gli indirizzi di memoria virtuale in indirizzi fisici riducendo drasticamente il consumo di RAM. 

Invece di mantenere in memoria un'unica, gigantesca tabella che mappa l'intero spazio virtuale a disposizione di un processo (anche le enormi porzioni vuote), si utilizza una tabella principale e compatta, chiamata _Page Directory_. 

Questa directory contiene semplicemente dei puntatori a svariate tabelle secondarie più piccole. Il grande vantaggio di questo approccio è che le tabelle secondarie vengono create e mantenute in RAM esclusivamente per le porzioni di memoria effettivamente utilizzate dal programma; le aree non allocate non richiedono alcuna tabella. 

Inoltre, se il sistema ha bisogno di liberare spazio, le tabelle secondarie non consultate da tempo possono essere temporaneamente spostate sul disco fisso, lasciando in memoria solo la essenziale directory principale.
![[Pasted image 20260503161749.png|500]]
- **Meccanismo a due livelli:** Quando viene presentato un indirizzo virtuale alla MMU, l'hardware sa che è composto da due sotto-indirizzi quindi per prima cosa estrae il primo campo (chiamato _PT1_) e usa questo valore come indice nella tabella delle pagine di livello più alto. Il secondo campo, _PT2_, adesso è usato come un indice nella tabella delle pagine di secondo livello (selezionata dal passo precedente) per cercare il numero di frame della pagina stessa.
- **Espansione dei livelli:** Possiamo aumentare il numero di livelli per supportare indirizzi molto grandi; questo ci permette di risparmiare memoria (tenendo su disco i livelli non usati) a discapito però della velocità, poiché sarà richiesto un accesso in più alla memoria RAM per ogni livello aggiunto alla gerarchia.
###### Tabelle delle pagine invertite
Un'alternativa al continuo aumento dei livelli nella paginazione gerarchica è rappresentata dalle **tabelle delle pagine invertite**. In questa architettura, il paradigma classico viene ribaltato: anziché mantenere una voce per ogni pagina dello spazio virtuale, la tabella contiene **una singola voce per ogni frame fisico** effettivamente presente nella memoria RAM.
Questo approccio comporta due conseguenze contrapposte:
- **Enorme risparmio di spazio:** La dimensione della tabella dipende unicamente dalla quantità di memoria fisica installata e non da quella virtuale. Questo è un vantaggio cruciale nei sistemi moderni, dove lo spazio di indirizzamento virtuale è enormemente più vasto della RAM disponibile.
- **Traduzione complessa e lenta**: Nelle tabelle tradizionali, la pagina virtuale _p_ funziona esattamente come l'indice di un array, consentendo un accesso diretto e immediato alla riga corrispondente per leggere il frame fisico. Nella tabella invertita, invece, la struttura cambia: le righe rappresentano i frame fisici e al loro interno viene annotato quale processo (_n_) (tramite ASID) e quale pagina virtuale (_p_) vi sono ospitati in quel momento. Di conseguenza, quando l'hardware ha bisogno di tradurre l'indirizzo, si ritrova in mano la coppia _(n, p)_ ma non sa a priori in quale riga sia scritta. Non potendo usare l'accesso diretto, è costretto a effettuare una vera e propria **ricerca per contenuto**, scansionando la tabella finché non trova la riga con l'esatta corrispondenza (il cui indice indica finalmente il frame fisico). Senza strutture aggiuntive, questa ricerca si tradurrebbe in innumerevoli e lenti accessi sequenziali alla RAM, paralizzando le prestazioni.

Per aggirare questo ostacolo prestazionale, il sistema fa un **impiego massiccio del TLB** (_Translation Lookaside Buffer_). Finché le pagine utilizzate più di frequente si trovano in questa memoria cache ultra-veloce, la traduzione avviene in modo istantaneo, esattamente come nelle architetture tradizionali. 

Il problema si pone in caso di _TLB miss_ (quando la pagina cercata non è nella cache), evento che costringe l'hardware a interrogare la grande tabella invertita in RAM. Per evitare di doverla scandire linearmente dall'inizio alla fine, la ricerca viene ottimizzata strutturando la tabella come una **hash table** basata sull'indirizzo virtuale, riducendo così drasticamente i tempi necessari per localizzare il frame fisico.

###### Cache della memoria vs Memoria virtuale
La cache della memoria può essere basata sugli indirizzi fisici, o sugli indirizzi virtuali. Ciò dipenderà rispettivamente, se posizioniamo l’MMU prima o dopo la cache.
- *Indirizzi fisici*:
  **Pro**: non servirà invalidare la cache sul context-switch. Avendo indirizzi fisici già tradotti nella cache, non si avranno problemi di ambiguità.
  **Contro**: l’MMU diventa un collo di bottiglia per la cache.
- *Indirizzi virtuali*.
  **Pro**: più veloce ed efficace 
  **Contro**: servono gli ASID per non invalidare la cache
![[Pasted image 20260516091408.png|700]]
**Soluzione effettiva**:
approccio ibrido La cache $L1$ basata su indirizzi virtuali, si pone prima dell’MMU, basandosi sugli indirizzi virtuali. La cache $L2$ e successive dopo l’MMU, basate su indirizzi fisici.

### Gestione della memoria virtuale e algoritmi di sostituzione delle pagine
Quando si verifica un **page fault**, il sistema operativo deve fare spazio alla pagina entrante scegliendo una pagina residente da sfrattare. Se la pagina scelta è stata modificata durante la sua permanenza, deve essere prima riscritta sul disco per mantenerne la copia aggiornata. Le prestazioni del sistema risultano ottimali se si sceglie di rimuovere una pagina non particolarmente utilizzata.

###### Algoritmo di Sostituzione Ottimale
Il miglior algoritmo di sostituzione delle pagine è puramente teorico. L'idea è etichettare ciascuna pagina in memoria con il numero di istruzioni da eseguire prima che venga referenziata nuovamente. Al momento del **page fault**, l'algoritmo rimuove la pagina con l'etichetta più alta. Questo approccio è irrealizzabile, poiché il sistema operativo non ha modo di sapere in anticipo quando le pagine verranno referenziate la volta successiva.

###### Not Recently Used (NRU)
Per raccogliere statistiche sull'uso delle pagine, l'hardware mette a disposizione due bit di stato associati a ciascuna voce della tabella delle pagine:
- **Bit R (_Referenced_):** Impostato a 1 quando si fa riferimento alla pagina (in lettura o scrittura).
- **Bit M (_Modified_):** Impostato a 1 solo quando la pagina viene scritta (modificata).

All'avvio, questi bit sono azzerati. Periodicamente (es. a ogni interrupt del clock), il **Bit R** viene ripulito per distinguere le pagine usate di recente da quelle inattive. Al verificarsi di un **page fault**, l'algoritmo NRU divide le pagine in quattro categorie in base ai valori attuali dei bit:
- Classe 0: non referenziato, non modificato.
- Classe 1: non referenziato, modificato.
- Classe 2: referenziato, non modificato.
- Classe 3: referenziato, modificato.

L'algoritmo rimuove una pagina a caso dalla classe non vuota con il numero più basso. È infatti preferibile rimuovere una pagina modificata ma non usata di recente, piuttosto che una pagina pulita ma usata frequentemente.
###### First-in, First-out (FIFO) e Seconda Chance
L'algoritmo **FIFO** tiene una lista delle pagine in memoria ordinandole per tempo di arrivo. A un **page fault**, rimuove semplicemente la pagina più vecchia in testa. Questo approccio rigido rischia di eliminare pagine vecchie ma ancora usate intensamente.
Per evitare questo problema, l'algoritmo della **Seconda Chance** controlla il **Bit R** della pagina più vecchia prima di rimuoverla:
- Se **R = 0**: La pagina è vecchia e inutilizzata, quindi viene sostituita immediatamente.
- Se **R = 1**: Il bit viene azzerato, la pagina viene spostata in fondo alla lista (rinnovando il suo tempo di caricamento) e la ricerca continua. Se tutte le pagine sono state referenziate, degenera in un FIFO puro.

###### Algoritmo Clock
L'algoritmo della Seconda Chance è inefficiente perché sposta continuamente le pagine lungo la lista. L'algoritmo **Clock** migliora la struttura mantenendo i frame su una lista circolare a forma di orologio. Una lancetta indica la pagina vecchia. Quando avviene un **page fault**, si esamina la pagina indicata: se **R = 0**, la pagina viene sfrattata e la lancetta avanza; se **R = 1**, il bit viene azzerato e la lancetta passa alla pagina successiva finché non ne trova una sacrificabile. Se tutti i valori di R sono uguali a 1 nel momento in cui si verifica un page fault, la lancetta dell'algoritmo Clock farà un **giro completo dell'orologio (360 gradi)**. Al termine di questo giro, la pagina che era inizialmente indicata dalla lancetta verrà sfrattata. ![[Pasted image 20260519113550.png|700]]
###### Least Recently Used (LRU)
L'algoritmo **Least Recently Used (LRU)** rappresenta un'eccellente approssimazione dell'algoritmo ottimale teorico.  Per realizzare un **LRU hardware puro**, i progettisti dovrebbero dotare il sistema di un contatore a 64 bit capace di incrementarsi automaticamente a ogni singola istruzione eseguita dalla CPU. Parallelamente, ogni voce della tabella delle pagine dovrebbe possedere uno spazio dedicato per memorizzare questo valore. In questo scenario, ogni volta che la memoria viene referenziata, il valore attuale del contatore globale viene copiato istantaneamente nella voce della tabella corrispondente alla pagina appena utilizzata. Al verificarsi di un **page fault**, il sistema operativo è costretto a esaminare tutti i contatori presenti nella tabella delle pagine per individuare il valore assoluto più basso. Quella cifra identifica matematicamente la pagina usata meno recentemente, che diventa la candidata perfetta per la rimozione. Questa implementazione, per quanto teoricamente ineccepibile, si scontra duramente con la realtà ingegneristica. Aggiornare un contatore nella memoria a ogni singola istruzione, per poi dover scansionare l'intera tabella a ogni errore di pagina, richiederebbe un hardware dedicato estremamente complesso e costoso. Trovare una pagina, aggiornarla e riordinarla in tempo reale comporta un dispendio di tempo e risorse che rende l'LRU puro impraticabile per la quasi totalità dei computer commerciali.

###### Not Frequently Used (NFU)
Proprio per superare gli ostacoli fisici ed economici dell'LRU, i progettisti hanno ideato delle simulazioni implementabili via software. La prima e più intuitiva di queste è l'algoritmo **Not Frequently Used (NFU)**.

Il suo funzionamento si basa sull'associazione di un contatore software a ciascuna pagina residente in memoria, rigorosamente inizializzato a zero al momento del caricamento. Invece di agire a ogni singola istruzione, l'NFU sfrutta l'interrupt periodico del clock. A ogni "tic" del clock, il sistema operativo effettua una rapida scansione e somma il valore del **Bit R** (il bit di riferimento, che vale 1 se la pagina è stata usata in quel ciclo, 0 altrimenti) al contatore di ciascuna pagina. In questo modo, i contatori accumulano punteggio, tenendo una traccia sommaria di quante volte ogni singola pagina è stata utilizzata durante la sua permanenza in memoria. Al momento di un **page fault**, la scelta della "vittima" da sfrattare ricade semplicemente sulla pagina che possiede il contatore numericamente più basso.

Tuttavia, l'NFU nasconde un difetto strutturale critico che lo rende imperfetto rispetto all'LRU: è dotato di una memoria infallibile, ovvero **non dimentica mai il passato**. Per comprendere il problema, possiamo immaginare l'esecuzione di un compilatore strutturato a passaggi multipli. Durante il primo passaggio, il programma utilizzerà intensamente un gruppo specifico di pagine, facendo schizzare i loro contatori a valori altissimi. Quando il programma passa alla seconda fase, quelle pagine del primo passaggio non gli serviranno più; tuttavia, il loro punteggio storico le proteggerà ostinatamente dalla rimozione. Di conseguenza, il sistema operativo finirà paradossalmente per rimpiazzare le pagine nuove e realmente utili della fase in corso (che partono inevitabilmente da un contatore basso), salvando invece le pagine vecchie e inattive. L'NFU fallisce quindi nel cogliere il vero concetto di "recente", limitandosi a premiare un generico utilizzo totale.

Per risolvere questo limite si usa l'algoritmo di **Aging**, illustrato nella figura sottostante. A ogni ciclo, i contatori vengono spostati a sinistra di un bit e il **Bit R** viene inserito nella posizione più a sinistra. L'algoritmo rimuove la pagina con il contatore più basso. Rispetto all'LRU puro, l'Aging non distingue l'ordine esatto dei riferimenti nello stesso ciclo di clock e ha un orizzonte temporale limitato dai bit del contatore. ![[Pasted image 20260519113533.png|700]]

###### Il Modello Working Set
Il ciclo di vita della memoria di un processo inizia generalmente con la strategia del **Demand Paging** (paginazione su richiesta). Nella sua forma più pura, un processo viene avviato senza che nessuna delle sue pagine sia presente in memoria fisica. Appena la CPU tenta di prelevare la prima istruzione, genera inevitabilmente un **page fault**. Questo innesca il caricamento della pagina iniziale. Subito dopo, seguiranno a raffica altri page fault per caricare lo stack, le variabili globali e le istruzioni successive. Dopo questa fase di assestamento iniziale, il processo disporrà delle pagine fondamentali e inizierà a girare in modo fluido. Le pagine vengono quindi caricate letteralmente "su richiesta", senza alcun pre-caricamento.

Ma perché, dopo una raffica iniziale di errori, il processo si stabilizza? Questo accade grazie a una proprietà fondamentale del software nota come **Località di Riferimento**. I processi non accedono al loro spazio di indirizzamento in modo casuale o uniforme; al contrario, tendono a concentrare le loro letture e scritture su una frazione relativamente piccola e ristretta di pagine in ogni specifica fase della loro esecuzione. Ad esempio, un ciclo `for` continuerà a richiamare sempre le stesse istruzioni e le stesse variabili per migliaia di iterazioni prima di passare ad altro.

Questo specifico sottoinsieme di pagine attivamente referenziate in un dato istante prende il nome di **Working Set** (o insieme di lavoro). Finché l'intero working set del processo riesce a risiedere fisicamente in memoria, il programma verrà eseguito in modo efficiente. Ma cosa succede se la RAM è troppo piccola o troppo frammentata per contenerlo tutto? Il processo inizierà a scartare pagine che gli serviranno di nuovo pochissimi millisecondi dopo, generando un page fault ogni poche istruzioni. Questa condizione catastrofica di perenne blocco e caricamento prende il nome di **Thrashing**. Quando un sistema entra in thrashing, l'intero computer rallenta fino a bloccarsi, poiché la CPU spende più tempo a gestire i page fault che a eseguire calcoli utili.

Per scongiurare il thrashing, i sistemi operativi moderni adottano il "modello working set". L'obiettivo è tenere traccia attivamente del working set di ogni processo e assicurarsi che questo sia interamente pre-caricato in memoria _prima_ di consentirne l'esecuzione. Questa tecnica di caricamento anticipato prende il nome di **Prepaginazione** (_prepaging_) e abbatte drasticamente il numero di page fault a runtime.

###### L'Algoritmo di Sostituzione basato sul Working Set
Per tradurre questa teoria in un algoritmo pratico, il sistema operativo deve definire in modo misurabile cos'è il working set. Invece di contare gli ultimi "k" riferimenti alla memoria (metodo teorico impossibile da tracciare), si utilizza il **Tempo virtuale attuale**, ovvero la quantità di tempo di CPU _effettivamente_ consumata da quel processo dal momento del suo avvio. Si stabilisce poi una determinata soglia temporale massima, indicata con $\tau$.

> [!TIP] Tempo virtuale attuale 
> l **tempo virtuale attuale** (o _current virtual time_) di un processo rappresenta la quantità esatta di tempo di CPU che quello specifico processo ha _effettivamente_ consumato dal momento in cui è stato avviato.
> 
> A differenza del tempo reale (quello del mondo fisico scandito dall'orologio del computer), il tempo virtuale di un processo avanza solo ed esclusivamente quando il processo si trova in esecuzione attiva sulla CPU. Se il sistema operativo decide di sospendere il processo, ad esempio per metterlo in attesa del completamento di un'operazione di I/O o per dare spazio a un altro programma, il suo tempo virtuale si "congela" istantaneamente, per poi riprendere a scorrere non appena il processo torna in esecuzione.

Quando si verifica un page fault, l'algoritmo deve scansionare la tabella delle pagine alla ricerca di una vittima al di fuori del working set. Analizzando ogni pagina, il sistema controlla prima di tutto il **Bit R** (Referenziato):
- Se **R = 1**: La pagina è stata usata di recente, quindi fa indiscutibilmente parte del working set. Non può essere rimossa. Il sistema operativo si limita ad aggiornare il suo "tempo di ultimo utilizzo" scrivendovi il tempo virtuale attuale.
- Se **R = 0**: La pagina non è stata usata nell'ultimo ciclo. Per capire se sia davvero "vecchia", l'algoritmo calcola la sua età (sottraendo il tempo di ultimo utilizzo dal tempo virtuale attuale) e la confronta con la soglia $\tau$.
    - Se l'**età è maggiore di $\tau$**: La pagina è matematicamente uscita dal working set. Viene scelta come vittima e rimossa istantaneamente.
    - Se l'**età è minore o uguale a $\tau$**: La pagina si è "salvata" per un pelo; è temporaneamente inattiva ma appartiene ancora al working set. L'algoritmo non la rimuove, ma ne prende nota nel caso in cui non si trovi nient'altro di meglio.

Se, terminata l'ispezione di tutta la tabella, non viene trovata nessuna pagina con età maggiore di $\tau$, significa che tutto ciò che è in memoria fa parte del working set. A questo punto, costretto a liberare spazio, il sistema operativo rimuoverà la pagina con R = 0 che risulta avere l'età in assoluto maggiore tra quelle presenti. Se persino questo tentativo fallisce (perché tutte le pagine hanno miracolosamente R = 1), sceglierà a caso una pagina pulita da sacrificare.
![[Pasted image 20260519113508.png|700]]
###### WSClock
L'algoritmo base del working set è lento per via della scansione dell'intera tabella. Il **WSClock**, illustrato nella **Figura 3.20**, unisce la lista circolare del Clock alle informazioni del working set. ![[Pasted image 20260519113442.png|400]]
La lancetta analizza le pagine: se **R = 0** e l'età supera $\tau$, si valuta la pagina. Se è pulita, viene rimossa; se è sporca, si schedula la sua scrittura su disco e la lancetta avanza senza bloccare il processo. Se la lancetta fa un giro completo e torna al punto di partenza, si presentano due casi:
- È stata schedulata almeno una scrittura: la lancetta continua a scorrere cercando la prima pagina pulita disponibile.
- Non ci sono scritture schedulate: tutte le pagine sono nel working set, quindi si sceglie una pagina pulita qualunque, o in mancanza si sacrifica la pagina attuale.
###### Confronti prestazionali dei vari algoritmi di sostituzione delle pagine
Per valutare e confrontare oggettivamente l'efficienza dei vari algoritmi di sostituzione delle pagine, si utilizza come metrica fondamentale il numero di **page fault** generati. Le valutazioni standard vengono effettuate simulando una memoria RAM limitata, ad esempio con 3 frame disponibili , e sottoponendo il sistema a una specifica sequenza compatta di accessi in memoria (come la stringa 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1). In queste sequenze di test, le ripetizioni immediate dello stesso numero vengono omesse poiché non influenzano il verificarsi dei page fault.

###### Valutazione dei Modelli Base
Sottoponendo la sequenza di riferimento ai tre algoritmi principali, emergono chiare differenze prestazionali: Il modello **OPT (Ottimale)** funge da termine di paragone assoluto. Genera il minimo storico di soli 9 page fault. Resta tuttavia un algoritmo puramente teorico, poiché per prendere le sue decisioni necessita di informazioni impossibili da ottenere sui riferimenti futuri a breve termine.  ![[Pasted image 20260519160201.png|700]]*(ogni quadrato grigio indica un page fault, in alto troviamo le pagine richieste, e in basso dentro i quadratini quelle che ci sono in memoria)*
Passando alle implementazioni reali, l'algoritmo **FIFO** si dimostra molto meno efficiente, registrando ben 15 page fault
![[Pasted image 20260519160425.png|700]]
Questo algoritmo soffre del problema noto come *anomalia di Belady*. L'algoritmo **LRU (Least-Recently Used)** invece si posiziona nel mezzo registrando 12 page fault. Oltre alle buone prestazioni, inoltre quest'ultimo è immune a l'anomalia di Belady.
![[Pasted image 20260519160531.png|700]]
###### Anomalia di Belady e Proprietà di Inclusione
Testando determinati algoritmi, i progettisti si sono scontrati con un fenomeno matematico imprevisto.
**Anomalia di Belady:** È un'anomalia controintuitiva che associa un inaspettato aumento dei page fault a un aumento della memoria RAM fisica disponibile. Questa anomalia si verifica solo di fronte a specifiche sequenze di accesso. Ad esempio, sottoponendo a un sistema la sequenza $[1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5]$, si può osservare un peggioramento delle prestazioni passando da 3 a 4 frame di memoria.
![[Pasted image 20260519160909.png|500]]
L'algoritmo LRU non presenta questa anomalia perché il suo modello matematico soddisfa un requisito stringente.

**Proprietà di Inclusione:** È una proprietà matematica secondo cui, in ogni istante di tempo $t$ e con una memoria di $n$ frame, l'insieme dei frame caricati è sempre un sottoinsieme di quelli che verrebbero caricati avendo a disposizione $n+1$ frame. In formula: $B_{t}(n)\subseteq B_{t}(n+1)$. Qualsiasi algoritmo che rispetti questa proprietà è matematicamente immune all'anomalia di Belady.

###### Comportamento degli algoritmi derivati
Comprendere l'anomalia di Belady e la proprietà di inclusione permette di classificare anche l'efficienza e i difetti di tutti gli algoritmi derivati impiegati nei sistemi operativi reali: Tutti gli algoritmi che si basano sul principio temporale del FIFO, ovvero **Seconda Chance**, **Clock** e anche la rozza approssimazione **NRU**, soffrono dell'anomalia di Belady e possono peggiorare le loro prestazioni all'aumentare della memoria. Al contrario, gli algoritmi che nascono per approssimare l'LRU, ovvero **NFU** e **Aging**, ereditano e godono della proprietà di inclusione, risultando stabili e sicuri. In particolare, l'Aging si distingue come una buona approssimazione dell'LRU, vantando anche un'implementazione software altamente efficiente. ![[Pasted image 20260519161110.png|500]]
### Problemi di progettazione dei sistemi di paginazione

###### Politiche di Allocazione: Globali e Locali a Confronto
Nei paragrafi precedenti abbiamo analizzato gli algoritmi che scelgono _quale_ pagina sostituire al momento di un page fault. Tuttavia, in un sistema multiprogrammato, i progettisti devono affrontare un'altra questione fondamentale: come dovrebbe essere ripartita la memoria fisica totale fra tutti i processi concorrenti in esecuzione? Per comprendere il problema, possiamo fare riferimento alla **Figura 3.22** ![[Pasted image 20260519113418.png|600]]Immaginiamo una situazione in cui i processi A, B e C si trovano in memoria. A un certo punto, il processo A genera un **page fault**. L'algoritmo di sostituzione deve ora prendere una decisione cruciale: cercare la pagina da sfrattare considerando solo l'insieme di pagine attualmente allocate ad A, oppure valutare tutte le pagine presenti nell'intera memoria, a prescindere da chi le stia usando?

- **Algoritmi di Sostituzione Locale**: Se l'algoritmo decide di confinare la sua ricerca alle sole pagine del processo A (scegliendo, ad esempio, la sua pagina più vecchia per fare spazio a quella nuova), stiamo applicando un **Algoritmo di sostituzione locale**. Questo approccio assegna a ogni processo una frazione rigida e fissa di memoria. Tuttavia, presenta dei gravi difetti prestazionali legati all'imprevedibilità dei programmi. Se il **working set** di un processo si restringe durante l'esecuzione, l'algoritmo locale continuerà a tenergli assegnata la stessa quantità di memoria, sprecando preziosi frame che rimarranno inutilizzati. Al contrario, se il working set del processo aumenta improvvisamente, l'algoritmo lo costringerà a sostituire continuamente le proprie pagine in un circolo vizioso, portandolo al **thrashing** pur in presenza di frame liberi e disponibili nel resto della memoria.
- **Algoritmi di Sostituzione Globale**: Se invece l'algoritmo, al verificarsi dell'errore di A, valuta tutte le pagine del sistema e decide, ad esempio, di sottrarre la pagina meno utilizzata in assoluto (magari appartenente al processo B) per assegnarla ad A, in questo caso, il numero di frame assegnato a ciascun processo varia dinamicamente nel tempo. 

In generale, gli algoritmi globali funzionano nettamente meglio di quelli locali proprio perché riescono ad assecondare le naturali variazioni di dimensione dei working set. Scegliendo una politica globale, il sistema deve però stabilire quanti frame assegnare all'avvio. Dividere la memoria in parti uguali ha poco senso, perché tratterebbe allo stesso modo un piccolo processo da 10 KB e uno enorme da 300 KB. L'approccio più saggio è avviare ogni processo assegnandogli un numero di pagine strettamente proporzionale alla sua dimensione totale (garantendo comunque un limite minimo a tutti per poter funzionare), per poi aggiornare questa assegnazione dinamicamente mentre i programmi girano.

###### L'Algoritmo Page Fault Frequency (PFF)
Il metodo più efficace per gestire questa "assegnazione dinamica" dei frame è l'algoritmo **Page Fault Frequency (PFF)**, il cui grafico di funzionamento è illustrato nella **Figura 3.23** ![[Pasted image 20260519113406.png|500]]
È importante precisare che il PFF non sceglie _quale_ pagina sostituire (quello è compito di algoritmi come Clock o WSClock), ma indica solo _quando_ è il caso di aumentare o diminuire il numero totale di pagine allocate a un determinato processo. Il funzionamento si basa sulla misurazione costante della frequenza degli errori, calcolando i **page fault per secondo** di ogni processo (spesso calcolati facendo una media tra i page fault del secondo appena trascorso e la media attuale di esecuzione, divisa per due). Il sistema operativo stabilisce dei limiti di accettabilità per questa frequenza:
- **Limite Superiore (Linea tratteggiata A):** Se la frequenza di paginazione di un processo supera questa soglia, significa che il tasso di errore è troppo alto. Il processo è "in sofferenza" per mancanza di spazio, quindi il sistema interviene aumentandogli la quota di frame assegnati.
- **Limite Inferiore (Linea tratteggiata B):** Se la frequenza di paginazione scende al di sotto di questa soglia, significa che il processo sta girando con un numero di errori così basso da far supporre che abbia troppa memoria a disposizione rispetto al necessario. In questo caso, il sistema operativo può tranquillamente sottrargli dei frame per riassegnarli a processi più bisognosi.
In questo modo, il PFF lavora costantemente in background cercando di mantenere la frequenza di paginazione di tutti i processi all'interno di una fascia sicura e ottimale.

###### Politica di Pulitura e Gestione dei Frame Liberi
Il meccanismo di risoluzione dei **page fault** è davvero efficiente e rapido solo se ci sono **frame liberi** sempre disponibili in memoria. Quando i frame scarseggiano e si è costretti a rimuovere una pagina, la gestione diventa lenta, soprattutto se la pagina è "sporca" (modificata), poiché richiede una preventiva e pesante scrittura su disco. Per evitare questo collo di bottiglia, sistemi operativi come Linux e Windows utilizzano il **paging daemon**, un processo di servizio che monitora costantemente l'occupazione globale della RAM. Questo daemon agisce d'anticipo: individua le pagine che presume non saranno utili nel breve periodo, le seleziona e le rende disponibili, mantenendo così un **pool di frame liberi** sempre pronti all'uso. La caratteristica chiave di questo pool è che i dati non vengono cancellati subito, lasciando aperta la possibilità di un **ripescaggio** istantaneo: se un processo richiede quella pagina prima che il frame venga effettivamente sovrascritto, il sistema la recupera immediatamente senza dover scatenare un vero e proprio page fault, riducendo drasticamente l'overhead generale.

###### Controllo del Carico
Se i working set combinati superano la capacità di memoria, il PFF indicherà che tutti i processi necessitano di memoria, portando inesorabilmente al **thrashing**. L'unica soluzione è lo **Swapping**, scaricando quanti più processi sul disco. La scelta di chi scaricare dipende dal grado di multiprogrammazione e dalle caratteristiche del processo (I/O bound o CPU bound).

###### Dimensione delle Pagine
La scelta della dimensione della pagina di base è importante. Al crescere o decrescere della dimensione delle pagine, otteniamo effetti positivi e negativi.
**Pro delle pagine più grandi**
* *Tabella delle pagine più piccole.*
  Il numero di record della tabella delle pagine è pari al numero di pagine. Il numero di pagine, a parità di memoria, è inversamente proporzionale alla dimensione delle pagine.
* *Migliore efficienza nel trasferimento I/O.*
  Utilizzando pagine più grandi, un input/output potrà essere effettuato su pagine più grandi, e quindi un numero minore di pagine a cui accedere. Questi vantaggi si sentono di più all’interno di memorie di tipo elettromeccanico.
* *Minori page fault (e conseguente minor overhead).*
  Pagine più grosse $\Rightarrow$ meno pagine $\Rightarrow$ meno page fault. Non sempre ne vale la pena, ma è un fatto da tenere in considerazione.

**Pro delle pagine più piccole**
* *Minore frammentazione interna.*
  Pagine più grandi causano più spreco. Pagine
* *Migliore risoluzione nel definire il working set. Meno memoria sprecata!*
  Le approssimazioni saranno più precise. Le pagine sono di dimensione fissa: blocchi più piccoli permettono di rispondere alle nostre esigenze in maniera migliore.

I pro di uno, sono i contro dell’altro. Per bilanciare gli svantaggi, i sistemi operativi utilizzano a volte pagine di dimensioni diverse per le diverse parti del sistema: per esempio, pagine grandi per il kernel e più piccole per | processi utente.

###### Pagine Condivise e Gestione della Cache
Fino ad ora abbiamo immaginato che ogni processo avesse le sue pagine isolate. Ma cosa succede se abbiamo più istanze dello stesso programma in esecuzione? Entra in gioco un'ottimizzazione del sistema operativo mirata a risparmiare memoria: le **pagine condivise**. Invece di caricare copie identiche, il sistema porta in RAM una sola copia fisica del _codice eseguibile condiviso_ e fa puntare le tabelle delle pagine dei vari processi esattamente allo stesso frame. Questo funziona perfettamente perché il codice è mantenuto in modalità _sola lettura_. Le pagine condivise si possono usare anche come strumento di comunicazione inter-processo (IPC) in _lettura/scrittura_, a patto di utilizzare i classici meccanismi di sincronizzazione per buffer condivisi, come i _MUTEX_. L'uso di questa memoria condivisa crea però delle sfide architetturali:
- **Il problema dell'aliasing in Cache:** Nelle cache "pre-MMU" basate su indirizzi virtuali, i processi vedono la stessa risorsa fisica usando indirizzi (e chiavi) virtuali diversi. Questo genera falsi _cache miss_ e seri problemi di sincronizzazione, dato che la cache rischia di caricare la stessa pagina in due voci distinte.
- **La soluzione ibrida:** Si utilizzano cache che effettuano ricerche tramite indirizzi virtuali ma associate a _tag fisici_ (sfruttando l'offset). Questa ricerca "preliminare" avviene in parallelo alla traduzione effettuata dalla MMU, permettendo di scremare le voci rapidamente senza disabilitare la cache.
- **Tabelle Invertite:** Le pagine condivise rendono le tabelle delle pagine invertite un incubo da gestire. Avendo un solo record per ogni frame fisico, risulta impossibile associarvi due indirizzi virtuali diversi senza dover modificare continuamente il record a ogni _page fault_ o _context switch_.

###### Copy-on-Write (COW) e Zero-fill-on-demand

Condividere le pagine è una tecnica eccellente per risparmiare memoria RAM, ma sorge un problema quando un processo necessita di modificare i propri dati. Prendendo in esame una chiamata `fork()`, i processi figli vengono creati identici al padre e, per ottimizzare, le loro tabelle delle pagine punteranno inizialmente agli stessi frame. L'obiettivo è mantenere questa condivisione il più a lungo possibile, intervenendo unicamente in caso di scrittura per non corrompere la memoria altrui.

Il meccanismo del **Copy-on-write** gestisce questa criticità in modo elegante: il sistema operativo, di default, imposta tutte le pagine condivise come _read-only_ (portando il bit di scrittura a 0). Quando un processo tenta di effettuare una scrittura, la MMU intercetta l'operazione non consentita ma, invece di generare un errore fatale, invoca una specifica procedura del sistema operativo. A questo punto, l'OS crea una **copia fisica identica** della singola pagina interessata, assegnandola in esclusiva al processo che ha richiesto la modifica. Infine, il sistema aggiorna i puntatori nelle rispettive tabelle delle pagine e ripristina il bit di scrittura a 1 per entrambe le nuove copie, rendendole di fatto indipendenti.

Una logica simile è alla base dello **Zero-fill-on-demand**, utilizzato quando un processo richiede nuova memoria per l'heap tramite chiamate come `sbrk()`. Anziché allocare e pulire immediatamente dei frame reali, il sistema operativo illude il processo associando temporaneamente le nuove pagine a una _read-only static zero page_, ovvero un frame speciale pre-azzerato e privo di informazioni. Soltanto nel momento in cui il processo tenterà per la prima volta di utilizzare (e quindi scrivere su) queste pagine, si innescherà il meccanismo del _copy-on-write_: il sistema operativo pulirà dei frame reali _on-demand_, li assegnerà al processo e aggiornerà i puntatori nella tabella delle pagine.

###### Librerie Condivise, File Mappati e Layout della Memoria

Quando un programma ha bisogno di usare funzioni appartenenti a librerie esterne, può inglobarle in due modi molto diversi:
- **Linking statico (L'approccio pesante):** Tutto il codice binario della libreria precompilata viene inserito fisicamente dentro l'eseguibile nei posti in cui le funzioni vengono chiamate. Il programma ha tutto a disposizione subito, ma l'eseguibile finisce per occupare molto spazio.
- **Linking dinamico (L'approccio smart):** Nell'eseguibile risiede solo il sorgente. A run-time, alla prima chiamata, la libreria viene portata _tutta in RAM_ e messa a disposizione del processo. Se altri processi necessitano della stessa libreria, non ne viene creata una copia nuova, ma tutti si agganceranno a quell'unica copia condivisa.

Un'evoluzione ancora più prestante per la condivisione è l'utilizzo dei **file mappati**. La mappatura in memoria è un meccanismo che permette di associare un’area della memoria virtuale di un processo al contenuto di un file memorizzato sul disco, permettendo così di accedere a quest’ultimo come se fosse parte della memoria RAM. Questa tecnica consente un accesso rapido ed efficiente ai dati (successivamente a un page fault), migliorando le prestazioni di applicazioni che gestiscono file di grandi dimensioni e facilitando la comunicazione tra processi che condividono memoria.
###### Allocazione della Memoria per il Kernel
Il sistema operativo ha bisogno di spazio in RAM per ospitare le proprie strutture dati di supporto (come PCB, semafori, code, ecc.). A differenza della memoria utente che viene paginata, il Kernel sbatte contro un ostacolo fisico: moduli che dialogano direttamente con l'hardware o con il sistema DMA necessitano obbligatoriamente di indirizzi fisici e frame **fisicamente contigui**.

Per allocare questa memoria complessa mirando a una frammentazione interna nulla, Linux impiega lo **slab allocator**. Questo modello si basa su due elementi:
- **Slab:** È una sequenza di frame fisicamente adiacenti (un pezzo fisico di memoria contiguo).
- **Cache:** È un insieme di slab. Il grande vantaggio è che ogni cache è _fortemente specializzata_ per ospitare un singolo tipo di struttura dati: ad esempio, avremo una cache esclusivamente per oggetti da 3 KB e un'altra per quelli da 7 KB.

L'efficienza è massima perché l'OS sceglie sempre di allocare slab di dimensione perfettamente multipla allo spazio richiesto. Così facendo, la _frammentazione esterna_ si annulla totalmente (tutto lo spazio che non serve al kernel viene rimbalzato alla paginazione classica), e l'operare direttamente con indirizzi fisici garantisce un _overhead minimo_.
