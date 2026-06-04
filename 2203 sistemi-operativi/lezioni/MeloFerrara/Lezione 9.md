# Obiettivi dello Scheduling (Algoritmi)

_Gestione e assegnazione (CPU e dispositivi di I/O)_
- Deve garantire **equità** della gestione della CPU.

- Devono anche garantire un bilanciamento dell'uso delle risorse come uso dell'I/O; bisogna evitare di far restare troppo a lungo delle risorse ferme (non fanno nulla).
### Introduzione ai Sistemi Batch (a lotti)

> I sistemi Batch sono tipici dei grandi centri di calcolo tradizionali o mainframe. In questi sistemi, i programmi (e i relativi dati) vengono raggruppati in "lotti" (batch) ed eseguiti in sequenza, l'uno dopo l'altro. La caratteristica principale è la totale assenza di interazione tra l'utente e il job durante l'esecuzione: l'utente invia i dati e attende la fine dell'elaborazione per ritirare i risultati. Lo scheduling qui mira a tenere le risorse hardware sempre occupate, massimizzando la quantità di lavoro svolto.

### Obiettivi dei Sistemi Batch

- **Massimizzare il Throughput**: Il sistema si comporta bene se ha un throughput alto (il throughput non è sufficiente per garantire una stima, si può barare scegliendo task piccoli).

- **Minimizzare il tempo di Turnaround (tempo di completamento)**: È una metrica che misura sul singolo job il tipo e la qualità del servizio all'utente (più è breve, maggiore sarà la qualità).
	- Il **tempo di attesa** si misura da quando il job viene messo in coda fino a quando il job viene pescato, eseguito e completato.
    - Per calcolare il tempo di turnaround mi riferisco a un sistema batch.
- Il tempo di esecuzione è una costante dato che ogni processo ci mette sempre $X$ tempo, lo scheduling non può fare nulla per velocizzarlo.
    - Per togliere questa costante posso cercare di **minimizzare il tempo di attesa**.
### Introduzione ai Sistemi Interattivi (Time-Sharing)

> I sistemi interattivi nascono per consentire l'interazione continua tra utente e macchina (sono i classici sistemi operativi che usiamo quotidianamente, come Windows, macOS o Linux). Utilizzano la tecnica del _time-sharing_ (divisione di tempo): il sistema operativo assegna la CPU a ciascun processo per un intervallo di tempo limitato (il cosiddetto "quanto di tempo"), saltando rapidamente da un'applicazione all'altra. Questo crea l'illusione (pseudo-parallelismo) che tutti i programmi stiano girando in contemporanea.
### Obiettivi dei Sistemi Interattivi

- **Minimizzare il tempo di risposta**: In questi sistemi non ci interessa il tempo di esecuzione o di attesa di un processo, ma solo il tempo di risposta.
### Introduzione ai Sistemi Real-Time (in tempo reale)

> I sistemi Real-Time sono progettati per applicazioni in cui le tempistiche sono critiche (come dispositivi medici, sistemi di controllo automobilistico, catene di montaggio industriali). In questi sistemi, la correttezza di un'operazione non dipende solo dall'avere un output esatto matematicamente, ma anche dal produrre tale output entro uno specifico e rigido limite di tempo (chiamato _deadline_). Si dividono tipicamente in _Hard Real-Time_ (una scadenza mancata provoca un disastro) e _Soft Real-Time_ (una scadenza mancata degrada le prestazioni ma è tollerabile).
### Obiettivi dei Sistemi Real-Time

- **Rispetto delle scadenze**: Hanno una natura critica e le scelte di scheduling sono più stringenti.
- **Prevedibilità**.

---

# Scheduling Sistemi Batch

Ho una coda di job che devono essere schedulati. Esiste il **tempo di arrivo** (indica quando sono arrivati in coda; potrebbero essere tutti uguali se i processi arrivano insieme).

## 1) FCFS (First Come First Served / FIFO)

Rispetta l'ordine di arrivo in coda.

- È un sistema **NON-PREEMPTIVE**: significa che il SO non toglie la CPU a un processo in corso.

> [!info] Diagramma di Gantt
> 
> Un diagramma temporale che indica i vari processi schedulati.
> 

**Esempio FCFS:**

Diagramma: `| P1 (24) | P2 (3) | P3 (3) |`

- $P_2$ ha dovuto aspettare 24 secondi.

- $P_3$ ha dovuto aspettare 27 secondi.


Calcolo dei tempi:

- **TMA (Tempo Medio di Attesa):** $\frac{0 + 24 + 27}{3} = 17$
- **TMC (Tempo Medio di Completamento):** $\frac{24 + 27 + 30}{3} = 27$

**Posso fare di meglio? SÌ.**

Se inverto l'ordine: `| P2 (3) | P3 (3) | P1 (24) |`

- **TMA:** $\frac{6 + 0 + 3}{3} = 3$
- **TMC:** $\frac{30 + 3 + 6}{3} = 13$

Invece di considerare tutti i processi uguali in coda, scelgo prima quelli che finiscono subito, oppure nella coda faccio andare avanti i processi con un tempo di esecuzione minore, conservando poi il sistema FCFS se ci sono processi con tempi uguali. Avviene tramite algoritmi di ordinamento ed è una **scelta Greedy**.

## 2) Algoritmo Shortest Job First (SJF)

- È un sistema **NON-PREEMPTIVE**.
- È ottimale SOLO se i lavori sono tutti subito disponibili.
    ![[Screenshot 2026-04-15 124718.png|238]]

## 3) Shortest Remaining Time Next (SRTN)

Aggiunge la **preemptive** (prelazione) al SJF.

Considera il tempo rimanente più piccolo. Se vi è in esecuzione $P_0$ con 4 secondi, significa che attualmente era il più piccolo. Se a tempo 1 arriva $P_1$ con tempo 1 secondo, allora la CPU verrà data a $P_1$ e $P_0$ avrà tempo 3 invece che 4.

- Il **Context Switch** è colui che permette questo cambio (è un'operazione pesante ma avviene raramente nei sistemi batch).

**Es. Diagramma di Gantt:**

`| P1 | P2 | P3 | P4 | P5 | P2 | ...`

Il tempo di attesa di $P_2$ sarà il tempo di $P_1$ + $P_3, P_4, P_5$ poiché non è contrattempo.

- **TMA:** $\frac{0 + 5 + 0 + 1 + 2}{5} = 1.6$

![[Screenshot 2026-04-15 124718 1.png|258]]
---
# Scheduling nei Sistemi Interattivi

## Round Robin (RR)

È la prelazione del FCFS. Il preemptive è basato su un **Quanto di tempo** (Time Slice) $\rightarrow$ Costante $q$ da decidere.

- Valori tipici di $q$ sono 20-50 ms.

- Con $n$ processi e quanto $q$, ogni processo avrà diritto a $\frac{1}{n}$ della CPU e attenderà max $(n-1)q$.

- Questa procedura viene eseguita tramite **Interrupt**.

**Gestione delle Chiamate di Sistema e I/O:**

Se un processo $B$ fa una chiamata di sistema per un I/O o fa un'attesa bloccante, allora la CPU sarà interrotta e $B$ non sarà più nello stato READY ma **BLOCKED**, anche se non ha usato tutto il suo quanto di tempo.

Quando tornerà READY:

- O viene messo davanti agli altri in coda (piccola limitazione per favorire processi _I/O bound_).

- O normalmente viene rimesso in coda dandogli un nuovo quanto di tempo $q$ (NON $q$ + tempo mancante del vecchio $q$ $\rightarrow$ _Risorse consumate_).

> **Nota importante:** Usare quanti di tempo più piccoli aumenta l'overhead (per i continui context switch) ma aumenta anche la reattività del sistema.

**Def reattività:** indica il tempo da quando il processo è entrato nella coda dei processi pronti a quando gli viene assegnata la CPU