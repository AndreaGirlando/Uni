# Capitolo 1: Introduzione ai Sistemi Operativi
Un computer moderno è un sistema complesso costituito da processori, memoria centrale, dischi e dispositivi di input/output. Per gestire questa complessità, i computer dispongono di uno strato software fondamentale: il sistema operativo.

I computer operano principalmente in due modalità:
- **Modalità kernel** (o _supervisor_): Permette l'accesso completo a tutto l'hardware e l'esecuzione di qualsiasi istruzione la macchina sia in grado di svolgere. È qui che viene eseguito il sistema operativo.
- **Modalità utente:** È la modalità in cui "gira" il resto del software e dei programmi applicativi, con privilegi limitati.
A differenza delle normali applicazioni, i sistemi operativi sono software molto grandi, complessi e longevi (sistemi come Linux o Windows raggiungono dimensioni nell'ordine dei cinque milioni di righe di codice).
## 1.1 Che cos'è un sistema operativo
Il sistema operativo è il software che opera in modalità kernel e svolge due funzioni principali e distinte:
### 1.1.1 Il sistema operativo come macchina estesa
L'architettura hardware nativa di un computer è primitiva e complessa da programmare. Il sistema operativo ha il compito di nascondere questa complessità, offrendo ai programmatori un insieme di astrazioni chiare, eleganti e coerenti.
- **Driver:** Software che fornisce un'interfaccia semplificata per la gestione dell'hardware (ad esempio, per leggere o scrivere su un disco), sollevando il programmatore dall'occuparsi dei dettagli tecnici di basso livello.
### 1.1.2 Il sistema operativo come gestore delle risorse
Il sistema operativo fornisce un'allocazione ordinata e controllata delle risorse hardware tra i vari programmi. Questa gestione include la condivisione delle risorse, definita **multiplexing**, che avviene in due modalità:
- **Multiplexing nel tempo:** Più programmi o utenti utilizzano la stessa risorsa alternandosi (facendo a turno).
- **Multiplexing nello spazio:** I clienti non si alternano, ma ognuno ottiene una porzione specifica della risorsa.
## 1.2 Storia dei sistemi operativi
- **Prima generazione (1945-1955):** Valvole termoioniche. Assenza totale di sistemi operativi; la programmazione avveniva in linguaggio macchina tramite cavi e interruttori.    
- **Seconda generazione (1955-1965):** Transistor e sistemi batch (a lotti). Introduzione dei primi software di base per automatizzare il passaggio da un lavoro (job) all'altro senza l'intervento umano continuo.
- **Terza generazione (1965-1980):** Circuiti integrati (IC) e multiprogrammazione. Nascono il partizionamento della memoria e il _timesharing_ (condivisione del tempo) per permettere a più utenti di interagire contemporaneamente con la macchina.
- **Quarta generazione (1980-oggi):** Personal Computer. Grazie ai circuiti integrati su larga scala (LSI), i computer diventano personali. Nascono sistemi operativi come MS-DOS, UNIX e, successivamente, le interfacce grafiche (GUI) con Windows e macOS.
- **Quinta generazione (1990-oggi):** Dispositivi mobili e cloud computing. Sistemi operativi fortemente interconnessi per smartphone, tablet e infrastrutture di rete.
## 1.3 Analisi dell'hardware
Un sistema operativo è intimamente legato all'hardware del computer su cui gira: ne estende l'insieme di istruzioni e ne gestisce le risorse. 
### 1.3.1 Processori
La **CPU** (_Central Processing Unit_) è il "cervello" del computer. Il suo ciclo di base consiste nel prelevare un'istruzione dalla memoria (_fetch_), decodificarla per comprenderne tipo e operandi, eseguirla e passare alla successiva, fino al termine del programma.
Per migliorare le prestazioni, le moderne CPU adottano architetture avanzate:
- **Pipeline:** Organizzazione che permette di eseguire più istruzioni contemporaneamente (es. mentre si esegue l'istruzione $n$, si decodifica la $n+1$ e si preleva la $n+2$).
- **Multithreading** (o _hyperthreading_): Permette alla CPU di mantenere lo stato di due _thread_ diversi, i quali appaiono al sistema operativo come due CPU separate.
- **Multicore:** Chip CPU che contengono al loro interno più processori completi (core), richiedendo l'uso di un sistema operativo multiprocessore.
- **GPU** (_Graphics Processing Unit_): Processori dotati di migliaia di core microscopici, eccezionali per l'esecuzione parallela di piccoli calcoli (come il _rendering_ poligonale).
**I Registri della CPU**
Poiché l'accesso alla memoria è lento, la CPU utilizza memorie interne ad altissima velocità chiamate registri:
- **Program counter:** Contiene l'indirizzo di memoria della successiva istruzione da eseguire.
- **Stack pointer:** Puntatore allo _stack_.
- **PSW** (_Program Status Word_): Registro che contiene i bit di condizione, la priorità della CPU e il bit che controlla la modalità operativa (utente o kernel).
_Nota Operativa:_ Quando il sistema operativo ferma un programma per farne partire un altro (multiplexing temporale), deve salvare lo stato di tutti i registri per poterli ricaricare al riavvio del programma sospeso.
**Chiamate di Sistema e Interruzioni**
- **System Call** (Chiamata di sistema): Richiesta effettuata da un programma utente per ottenere servizi dal sistema operativo.
- **TRAP:** Istruzione che cambia la modalità operativa da utente a kernel e avvia il sistema operativo. Le _trap_ possono anche essere generate dall'hardware per segnalare situazioni eccezionali (es. divisione per zero).
### 1.3.2 Memoria
Poiché non esiste una memoria ideale (veloce, capiente e a basso costo contemporaneamente), il sistema è strutturato in strati gerarchici:
1. **Registri della CPU:** Strato alla sommità, velocissimi e a capacità ridotta.
2. **Memoria Cache:** Gestita dall'hardware. Si divide in **Cache L1** (interna alla CPU, fornisce istruzioni codificate) e **Cache L2**. Conserva le linee di memoria usate più di frequente.
3. **Memoria Principale (RAM):** La memoria di lavoro vera e propria ad accesso casuale. Gestisce tutte le richieste della CPU non soddisfatte dalla cache.
4. **Memoria non volatile:** Include la **ROM** (_Read Only Memory_, programmata dal costruttore e non modificabile), la **EEPROM** (cancellabile elettricamente) e le memorie _flash_.
### 1.3.3 Dischi
L'**Hard Disk** (disco magnetico) si trova sotto la RAM nella gerarchia. È lento perché è un'unità meccanica formata da piatti metallici rotanti e un braccio meccanico.
- **Traccia:** Regione anulare letta da una testina a una data posizione del braccio.
- **Cilindro:** L'insieme di tutte le tracce relative a una specifica posizione del braccio.
### 1.3.4 Dispositivi di I/O
I dispositivi di Input/Output sono composti dal dispositivo fisico e da un **controller** (il chip che lo governa fisicamente). Il sistema operativo vede solo l'interfaccia del controller.
- **Device Driver:** Software specifico necessario per controllare un determinato dispositivo di I/O. Gira in modalità kernel e può essere installato in tre modi:
    1. Ricollegando il kernel al driver e riavviando.        
    2. Creando una voce in un file di sistema e riavviando.
    3. Installazione "a caldo" mentre il sistema è in esecuzione (senza riavvio).
**Gestione dell'Input/Output:**
Avviene tramite tre metodi principali:
1. **Busy waiting:** Il driver avvia l'I/O e interroga continuamente il dispositivo per controllare se ha terminato. _Svantaggio:_ Impegna inutilmente la CPU.
2. **Interrupt:** Il driver avvia il dispositivo e si sospende. Al termine, il controller genera un **interrupt** (interruzione) per segnalare il completamento (il testo fa riferimento al **vettore degli interrupt**). La CPU può disabilitare temporaneamente gli interrupt per non essere interrotta in momenti inopportuni.
3. **DMA** (_Direct Memory Access_): Utilizza un hardware speciale che controlla il flusso di dati tra memoria e controller senza l'intervento costante della CPU. Al termine, il chip DMA genera un interrupt.
## 1.4 Panoramica dei sistemi operativi
- **Sistemi operativi per mainframe:** Orientati all'esecuzione simultanea di numerosi lavori con massicce richieste di I/O. Offrono servizi _batch_, elaborazione di transazioni e _timesharing_.
- **Sistemi operativi per server:** Servono molteplici utenti in rete, permettendo la condivisione di risorse hardware e software.
- **Sistemi operativi multiprocessore:** Varianti dei sistemi server ottimizzate per comunicazione e coerenza. Utilizzati sempre più spesso anche sui PC desktop dotati di chip multicore.
- **Sistemi operativi per personal computer:** Progettati per supportare in modo ottimale un singolo utente.
- **Sistemi operativi per computer palmari (PDA):** Sistemi sofisticati per dispositivi mobili, in grado di gestire CPU multicore, GPS, fotocamere e grandi memorie.
- **Sistemi operativi integrati (_embedded_):** Installati su dispositivi non considerati veri computer (es. forni a microonde). Il software è su ROM, non accetta app esterne, rendendo inutile la protezione tra applicazioni.
- **Sistemi operativi real-time:** Sistemi in cui il tempo è il parametro critico.
    - **Hard real-time:** Forniscono garanzie assolute che un'azione avvenga in un momento preciso.
    - **Soft real-time:** Tollerano il mancato rispetto occasionale di una scadenza.

## 1.5 Concetti fondamentali dei sistemi operativi
Per nascondere la complessità dell'hardware, i sistemi operativi creano alcune astrazioni chiave:
- **Processi:** È essenzialmente un programma in esecuzione. Comprende il codice eseguibile, i dati, lo stack e lo stato dei registri. Nei sistemi operativi, i processi possono crearne di nuovi, formando un "albero dei processi" (processi padre e figlio).
- **Spazio di indirizzamento:** L'intervallo di indirizzi di memoria (da 0 a un massimo) che un processo è autorizzato a utilizzare in modo esclusivo e protetto.
- **File e Directory:** Astrazioni per nascondere i dettagli tecnici dei dischi magnetici o a stato solido. I file sono organizzati in gerarchie strutturate chiamate directory (o cartelle).

## 1.6 Chiamate di sistema (System Call)
Le system call rappresentano l'interfaccia standard tra i programmi utente e il sistema operativo. Quando un programma ha bisogno di un servizio privilegiato (come leggere un file, allocare memoria o creare un processo), esegue una system call tramite un'istruzione TRAP, passando dalla modalità utente alla modalità kernel.
- Esempi di standard per le system call sono **POSIX** (usato da Unix e Linux) e **Win32 API** (usato da Windows).
## 1.7 Struttura di un sistema operativo

### 1.7.1 Sistemi monolitici
È l'organizzazione più comune. L'intero sistema operativo è un singolo programma eseguito in modalità kernel, formato da una raccolta di procedure collegate (linkate) tra loro. Poiché le procedure si richiamano liberamente senza restrizioni, il sistema risulta spesso pesante e difficile da capire.
### 1.7.2 Sistemi a livelli
Il sistema è organizzato gerarchicamente. Un esempio classico prevede sei livelli:
- **Livello 0:** Allocazione del processore (multiprogrammazione base).
- **Livello 1:** Gestione della memoria.
- **Livello 2:** Comunicazione tra processi e console operatore.
- **Livello 3:** Gestione dei dispositivi di I/O.
- **Livello 4:** Programmi utente.
- **Livello 5:** Operatore di sistema.
### 1.7.3 Microkernel
Nasce per garantire un'altissima stabilità. Il sistema è diviso in piccoli moduli ben definiti, ma **solo il microkernel viene eseguito in modalità kernel**. Driver, file system e server girano tutti in modalità utente. I programmi ottengono i servizi inviando brevi messaggi ai processi server.
### 1.7.4 Modello client-server
È una variazione del microkernel che distingue due classi di processi: i **server** (che forniscono i servizi) e i **client** (che li utilizzano). La comunicazione avviene tramite passaggio di messaggi (ottimizzabile se client e server risiedono sulla stessa macchina).
### 1.7.5 Macchine virtuali
Si basano su un **monitor di macchina virtuale** (oggi chiamato **hypervisor di tipo 1**) che gira direttamente sull'hardware e fornisce ai livelli superiori numerose **macchine virtuali**. Ogni macchina virtuale è identica all'hardware reale e può eseguire un proprio sistema operativo (_guest_).
- **Hypervisor di tipo 2:** Strategia ibrida utilizzata comunemente sui PC (es. VMware Workstation). Non gira direttamente sull'hardware, ma ha bisogno di un sistema operativo _host_ preesistente per installare e avviare il sistema operativo _guest_ su un disco virtuale.

# Capitolo 2: 