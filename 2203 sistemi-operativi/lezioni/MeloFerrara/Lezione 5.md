## Programmazione con Strutture Multicore

Programmare con strutture multicore ha la stessa logica di un core singolo: ogni thread ha una sua CPU virtuale. Per progettare programmi che usano strutture multicore bisogna tenere conto di:

- **Separare i task:** Identificare in modo preciso i task/compiti che la CPU deve eseguire. Non sempre conviene accoppiare un thread a ogni task; si potrebbero associare più task a un singolo thread.
    
- **Bilanciamento**
    
- **Suddivisione dei dati:** Ogni task ha bisogno di una struttura dati specifica, oppure potrei avere delle strutture dati usate da più thread.
    
- **Dipendenze dei dati:** Dato che i dati possono essere condivisi tra i thread, possono nascere delle dipendenze.
    
    > _Esempio: Merge Sort. Ho 3 task (ordinamento parte sx, ordinamento parte dx, fusione). Il task di fusione deve aspettare gli altri 2 task._
    
- **Test e Debugging:** È più complicato fare debugging poiché possono sorgere problemi legati alla programmazione concorrente (multicore).
    

---

## 1. Thread a Livello Utente (Modello 1-a-Molti)

In questo caso il Sistema Operativo (SO) non conosce i thread perché è costruito per gestire i processi. Per ovviare a questo:

- Si crea un **Run-time Environment**, ovvero una libreria esterna che serve a gestire i thread (creazione, distruzione, ecc.).

- Non richiede _trap_ nel kernel perché tutto avviene a livello utente.

- Serve una **tabella dei thread** (una sorta di PCB per i thread).

### Gestione e Scheduling

- Sfrutta il _time slicing_ della CPU. Il quanto di tempo assegnato a un processo viene diviso per ogni suo thread.

- Nella tabella dei thread vengono salvati i registri della CPU ogni volta che si cambia thread.

- La gestione avviene in modo diverso e senza interruzioni esterne. Non si può rilasciare la CPU per dispositivi di I/O in modo nativo.

- Il passaggio da un `Thread A` a un `Thread B` avviene tramite **Thread Yield**: il thread A rilascia volontariamente la CPU al thread B.

	- _Nota su Thread Yield:_ Prima salva tutti i dati della CPU (TPA) e dopo rilascia la CPU.

### Gestione dell'I/O e della Memoria

- Se un thread richiede l'uso di un I/O, può usare la `select` per vedere se è in uso un dispositivo I/O. Se lo è, il processo cede la CPU per evitare di bloccarsi interamente.

- **Page-Fault:** Serve a gestire la memoria. Se la memoria fisica necessaria finisce, non è un problema critico poiché ogni thread ha una memoria virtuale. Si spostano i thread non utili al momento sul disco e si riportano in RAM quelli utili. _Attenzione: questo causa dei rallentamenti per lo spostamento continuo tra RAM e disco._

---

## 2. Thread a Livello Kernel (Modello 1-a-1)

Il Kernel gestisce direttamente i thread. Il SO li conosce e sa che i processi sono composti da thread. A livello kernel si ha un'unica tabella per la gestione. _I nostri SO moderni usano principalmente i thread a livello kernel._

**Pro:**

- Se un thread effettua una chiamata bloccante o subisce un _page-fault_, il SO blocca **solo** il thread kernel associato, senza intralciare gli altri thread del processo.

- Il SO vede tutto come thread, persino un processo a singolo thread.

**Contro:**

- Cambio di contesto più lento, perché il kernel deve gestire tutti i thread del sistema, non solo quelli di un singolo processo.

- Creazione e distruzione sono operazioni più costose e il numero di thread kernel è limitato.

    - _Soluzione per mitigare il costo:_ Si possono riciclare dei thread (Thread Pool) per evitare di doverne creare e distruggere continuamente di nuovi.

### Modello Ibrido (Molti-a-Molti)

Prende il meglio dei due modelli precedenti. Si fa un'analisi preventiva dei task, dopodiché si crea un raggruppamento definendo un numero massimo di thread kernel. A ogni thread kernel posso poi associare e mappare più thread utente.

---

## 3. Comunicazione tra Processi (IPC)

Spesso i processi hanno bisogno di cooperare tra di loro. Questo fa emergere tre problemi principali:

1. Come scambiarsi i dati.

2. Accavallamento delle operazioni sui dati condivisi (sincronizzazione).

3. Coordinamento generale tra le operazioni.

### Le Pipe

È un collegamento diretto tra processi: un comando dà in output qualcosa che viene preso in input dal comando successivo (es. `cmd1 | cmd2` sul terminale).

- Il comando che aspetta l'input entra in stato di **Wait**.

- Se il `cmd2` è occupato a fare altro e il `cmd1` invia l'output, il `cmd1` non può consegnarlo immediatamente e quindi si blocca finché l'altro non è pronto.

### Inter-Process Communication (IPC)

Tecnica dove processi con il proprio spazio di indirizzamento separato riescono a comunicare in modo efficiente grazie a dei **segmenti di memoria condivisa**. Questo risolve il problema dello scambio dati permettendo la comunicazione diretta.

**Esempio:** Supponiamo di avere due processi P1 e P2 che aggiornano una variabile intera condivisa *x*. Entrambi eseguono un ciclo `for` che incrementa *x* di uno (`x = x + 1`) per 100 iterazioni ciascuno.

L'istruzione `x = x + 1` non è atomica: il processore la scompone in tre passi distinti:
1. **Leggi** il valore di *x* dalla memoria
2. **Incrementa** il valore nel registro
3. **Scrivi** il nuovo valore in memoria

Il problema nasce quando i due processi si interlacciano in mezzo a questi passi:
- *x* = 0
- P1 legge x → ottiene 0
- P2 legge x → ottiene 0 *(prima che P1 abbia scritto!)*
- P1 incrementa → 0+1 = 1, scrive x = 1
- P2 incrementa → 0+1 = 1, scrive x = 1

Risultato: *x* vale 1 invece di 2 — un incremento è andato perso. Questo può ripetersi in qualsiasi iterazione, quindi al termine delle 100 iterazioni di entrambi i processi, il valore finale di *x* potrebbe essere molto inferiore a 200. Questo fenomeno prende il nome di **race condition** (corsa critica).

**Sezioni critiche:** Per evitare le race condition, il programmatore deve garantire che i processi non accedano simultaneamente alla stessa risorsa condivisa. La porzione di codice in cui avviene questo accesso è detta *sezione critica*, e deve essere eseguita in mutua esclusione: un solo processo alla volta può trovarsi al suo interno.

Per avere una buona soluzione dobbiamo rispettare queste quattro condizioni:
1. mutua esclusione nell'accesso alle sezioni critiche
2. nessuna assunzione sulla velocità di esecuzione o sul numero di CPU
3. nessun processo fuori dalla propria sezione critica può bloccare un altro processo
4. nessun processo dovrebbe restare all'infinito in attesa di entrare nella propria sezione critica

Ci sono diverse soluzioni a questo problema, come:
- Disabilitare gli interrupt
- Variabili di lock
- Alternanza stretta