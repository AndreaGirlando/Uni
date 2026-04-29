### I Processi

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
2. **Tramite chiamate di sistema (_Syscall_):** Un processo padre ne crea uno figlio per delegare compiti o distribuire il carico di lavoro (utile specie nei multiprocessori per evitare blocchi).
3. **Azione dell'utente:** Tipico dei sistemi interattivi (es. l'avvio di un'app).
4. **Inizio di un job _batch_:** Lo _Scheduler_, in base alle risorse libere, seleziona un lavoro dalla coda e crea un processo per eseguirlo.

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
- **Pronto (_Ready_):** Il processo è pronto a usare la CPU ed è in attesa in una speciale coda gestita dallo _Scheduler_.
- **In Esecuzione (_Running_):** Il processo detiene l'unica CPU disponibile in quel momento.
- **Bloccato (_Blocked_):** Il processo è parcheggiato in attesa di un evento esterno (spesso operazioni di Input/Output "lente").
- **Terminated:** Fase finale di chiusura.

![[Pasted image 20260426194444.png|00]]

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
Tutti i thread generati all'interno di un medesimo processo condividono lo stesso PID (Process ID). Per funzionare, ogni thread mantiene una divisione netta tra ciò che è strettamente personale e ciò che condivide con i "fratelli":
- **Risorse esclusive (Dx):** Ogni thread possiede un proprio *program counter* (per sapere quale istruzione eseguire), propri *registri*, un proprio *stack* e un proprio stato* (es. ready, running, blocked).
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
    - **Scheduling personalizzato:** Permette priorità contestuali gestite dall'applicazione, molto più versatili rispetto a quelle asettiche dell'OS.
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
    - **Context switch più lento:** Passare da un thread all'altro richiede l'uso di costose _trap_ di sistema.
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
Quando più processi operano su dati condivisi in modo non coordinato, si verificano anomalie critiche come la: **race condition** situazione in cui il risultato finale dipende dall'ordine di esecuzione dei processi (ovvero da chi viene "scelto" per primo dallo _scheduler_).
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