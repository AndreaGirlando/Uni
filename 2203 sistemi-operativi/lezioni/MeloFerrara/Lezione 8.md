# Problema dei 5 Filosofi

## Descrizione del Problema
È un classico problema di sincronizzazione in cui più entità hanno bisogno di risorse esclusive. 
Il problema si presenta quando ci sono più risorse contese: vi è un tavolo con **5 filosofi**. Il loro ciclo di vita è sempre diviso tra due processi principali: `think()` (pensare) ed `eat()` (mangiare).

Per mangiare, ogni filosofo ha bisogno di **due forchette** (una alla sua destra e una alla sua sinistra). Al tavolo ci sono in totale solo 5 forchette.
Se una forchetta è presa da un filosofo, manca all'altro. Questa è una potenziale situazione bloccante.

**Obiettivo:** Trovare una soluzione generale per far mangiare più filosofi possibile contemporaneamente (il numero massimo è 2 contemporaneamente, per massimizzare il *throughput*).

---
## Tentativi di Soluzione

### Soluzione 1: Approccio Base (Rischio Stallo)
Ogni filosofo prima pensa, poi prende la prima forchetta, poi prende l'altra, mangia, e infine smette di mangiare posando le forchette (in loop).
* **Problema:** Questa soluzione non funziona sempre (non sempre 2 filosofi riescono a mangiare contemporaneamente). Se tutti i filosofi chiamano `take_fork(i)` nello stesso momento, cercheranno di prendere la propria forchetta ma non potranno prendere la vicina. Ogni filosofo avrà in mano una sola forchetta. 
* **Risultato:** $\Rightarrow$ **STALLO** (Deadlock).

### Soluzione 2: Rilascio e Riprova (Attesa fissa)
In caso di stallo, il filosofo rilascia la forchetta, aspetta $X$ secondi, e riprova.
* **Problema:** Funziona? **NO**. Si ripresenta lo stesso caso di prima: tutti i filosofi prendono una forchetta, la posano e aspettano $X$ secondi tutti insieme, per poi riprovare e bloccarsi di nuovo (Livelock).

### Soluzione 3: Rilascio e Riprova (Pausa Randomica)
Uguale alla Soluzione 2, ma con una pausa randomica invece che fissa.
* **Problema:** Risolve lo stallo, ma non siamo al massimo del *throughput*. Essendo un *meccanismo di polling*, ci potrebbero essere pause non necessarie in cui un filosofo aspetta anche se le forchette sono libere.

### Soluzione 4: Semaforo Mutex Globale
Usare un semaforo Mutex: si mette un *lock* globale prima che vengano prese le 2 forchette.
* **Problema:** Questo funziona e previene lo stallo, ma non avrò MAI il throughput massimo (2 filosofi), perché solo un filosofo alla volta potrà eseguire l'azione di prendere le forchette e mangiare.

---
## Soluzione Ottima: Vettore di Stato e Semafori Multipli

Questa soluzione utilizza un array per tracciare lo stato di ogni filosofo e un array di semafori per bloccare/sbloccare i singoli filosofi in modo indipendente.

### Codice della Soluzione

`// Inizializzazione`
`int N = 5;` 
`int THINKING = 0;`
`int HUNGRY = 1;` 
`int EATING = 2;`

`int state[N]; // Vettore per gestire gli stati dei filosofi`
`semaphore mutex = 1; // Mutex per proteggere l'accesso all'array di stato`
`semaphore s[N] = {0, 0, 0, 0, 0}; // N semafori per gestire i singoli filosofi`

`// Funzioni di utilità per calcolare i vicini`
`function left(int i)  = (i - 1) mod N`
`function right(int i) = (i + 1) mod N`

`// Ciclo di vita del Filosofo`
`function philosopher(int i) {`
    `while (true) do {`
        `think();`
        `take_forks(i); // Bloccante`
        `eat();`
        `put_forks(i);  // Sbloccante`
    `}`
`}`
`function take_forks(int i) {`
    `down(mutex);`
    `state[i] = HUNGRY;`
    `test(i);`
    `up(mutex);`
    `down(s[i]); // <--- NOTA BENE: Fuori dal mutex`
`}`
`function put_forks(int i) {`
    `down(mutex);`
    `state[i] = THINKING;`
    `test(left(i));  // Controllo se il vicino sinistro può mangiare`
    `test(right(i)); // Controllo se il vicino destro può mangiare`
    `up(mutex);`
`}`
`function test(int i) {`
    `// Se sono affamato e i miei vicini NON stanno mangiando`
    `if (state[i] == HUNGRY and state[left(i)] != EATING and state[right(i)] != EATING) {`
        `state[i] = EATING;`
        `up(s[i]); // Risveglio il filosofo`
    `}`
`}`
### Spiegazione delle logiche e commenti al codice

La funzione del filosofo è la stessa, ma `take_forks()` agisce in modo bloccante, mentre `put_forks()` è sbloccante. Tra la `down` e la `up` del mutex, si cambia lo stato del filosofo (THINKING $\rightarrow$ HUNGRY $\rightarrow$ EATING).

- **Nella `take_forks`:** Imposto il mio stato su `HUNGRY` e chiamo la funzione `test(i)` per vedere se posso mangiare. Subito dopo chiudo il mutex e faccio una `down(s[i])` sul mio semaforo personale.

    > [!warning] Attenzione alla `down` personale
    > 
    > La `down` su se stesso **DEVE ESSERE MESSA FUORI DAL MUTEX**, perché altrimenti bloccherebbe tutti. Se il filosofo non può prendere le forchette, si bloccherà fuori dalla sezione critica, permettendo agli altri di continuare.

- **Nella `put_forks`:** In teoria basterebbe aggiornare il proprio stato a `THINKING`, ma in pratica non è così. Controllo con `test(left(i))` e `test(right(i))` se i miei vicini non potevano mangiare per colpa mia. In questo modo posso risvegliarli, altrimenti non faccio niente.

- **Nella funzione `test`:** È importante controllare **sia** se il filosofo è affamato, **sia** che i vicini non stiano mangiando. Questo serve per evitare di risvegliare un filosofo che magari è bloccato da un altro vicino e non da me che ho appena finito.

## Problema dei 5 Filosofi: Soluzione con i Monitor

A differenza della soluzione con i semafori, i Monitor semplificano notevolmente la gestione della mutua esclusione.

* **Nessun Mutex esplicito:** Non vi è un semaforo mutex nel codice poiché la mutua esclusione all'interno del monitor viene gestita **autonomamente** dal costrutto stesso (solo un processo alla volta può essere attivo all'interno del monitor).
* **Gestione del Risveglio:** Nella funzione `test` vi è una `signal` sullo stesso filosofo dopo che il suo stato cambia in `EATING`. Questo segnale è inutile se il filosofo è già sveglio, ma è fondamentale se era stato bloccato in precedenza da una `wait`.
* *Nota sugli appunti:* La soluzione qui riportata si può scrivere anche in modo leggermente diverso, ma questa stesura ricalca la struttura per mantenerla parallela agli altri esempi.

### Codice della Soluzione (Monitor)

```c
int N = 5; 
int THINKING = 0; 
int HUNGRY = 1; 
int EATING = 2;

monitor dp_monitor {
    int state[N];
    condition self[N]; // Variabili condition per bloccare/svegliare i filosofi

    function take_forks(int i) {
        state[i] = HUNGRY;
        test(i); // Controllo se posso mangiare
        // Se dopo il test non sto mangiando, mi blocco sulla mia condition
        if (state[i] != EATING) {
            wait(self[i]); 
        }
    }

    function put_forks(int i) {
        state[i] = THINKING;
        // Ho finito di mangiare, controllo se i miei vicini ora possono farlo
        test(left(i));
        test(right(i));
    }

    function test(int i) {
        // Se il vicino sx NON mangia, io sono AFFAMATO, e il vicino dx NON mangia
        if (state[left(i)] != EATING and state[i] == HUNGRY and state[right(i)] != EATING) {
            state[i] = EATING;
            signal(self[i]); // Sveglio il filosofo (se era in wait)
        }
    }
}

// Ciclo di vita del Filosofo
function philosopher(int i) {
    while (true) do {
        think();
        dp_monitor.take_forks(i); // Chiamata al metodo del monitor
        eat();
        dp_monitor.put_forks(i);  // Chiamata al metodo del monitor
    }
}
```
## Il Problema dei Lettori e Scrittori (Readers-Writers Problem)

> [!info] Descrizione del Problema: È un problema classico che modella l'accesso concorrente a una risorsa condivisa, tipicamente un **database**.
> 
> - **Lettori (Readers):** Processi che vogliono solo leggere i dati. Possono leggere contemporaneamente senza darsi fastidio (se nessuno sta scrivendo).
>     
> - **Scrittori (Writers):** Processi che vogliono modificare i dati. Devono avere un accesso **esclusivo**. Mentre uno scrittore agisce sul database, nessun altro (né lettori né altri scrittori) può accedervi.
>     

### Soluzione con i Semafori

> [!abstract] Spiegazione della soluzione: L'idea base è tenere il conto di quanti lettori sono attualmente attivi (`rc` = _reader count_). Il **primo lettore** che arriva blocca il database (per impedire agli scrittori di entrare). I lettori successivi entrano liberamente. L'**ultimo lettore** che esce sblocca il database (permettendo finalmente agli scrittori di accedere). Lo scrittore, invece, deve solo prendere e rilasciare il blocco totale sul database.
semaphore mutex = 1; // Protegge la variabile condivisa 'rc' (reader count)
semaphore db = 1;    // Regola l'accesso esclusivo al database
int rc = 0;          // Contatore dei lettori attivi

```c
function reader() {
    while (true) do {
        // --- SEZIONE DI INGRESSO ---
        down(mutex);       // Richiedo accesso esclusivo per modificare 'rc'
        rc = rc + 1;       // Un nuovo lettore entra
        if (rc == 1) {     // Se sono il PRIMO lettore in assoluto...
            down(db);      // ...blocco l'accesso agli scrittori
        }
        up(mutex);         // Rilascio l'accesso a 'rc'
        
        // --- LETTURA ---
        read_database();   // Più lettori possono eseguire questa istruzione contemporaneamente
        
        // --- SEZIONE DI USCITA ---
        down(mutex);       // Richiedo accesso esclusivo per modificare 'rc'
        rc = rc - 1;       // Un lettore esce
        if (rc == 0) {     // Se sono l'ULTIMO lettore rimasto...
            up(db);        // ...sblocco il database, ora gli scrittori possono entrare
        }
        up(mutex);         // Rilascio l'accesso a 'rc'
        
        use_data_read();
    }
}

function writer() {
    while (true) do {
        think_up_data();
        
        down(db);          // Richiedo l'accesso ESCLUSIVO al database
        write_database();  // Scrivo i dati
        up(db);            // Rilascio il database
    }
}
```
[!warning] Il problema di questa soluzione: Starvation dello Scrittore Come indicato nelle slide, questa implementazione favorisce i lettori. Se c'è un flusso continuo di lettori che continuano ad arrivare prima che `rc` diventi 0, il database non verrà mai sbloccato (`up(db)` non viene mai chiamata). Di conseguenza, **lo scrittore potrebbe attendere per un tempo indefinito** (Starvation).

## Il Problema Lettori/Scrittori: Soluzioni con i Monitor

L'utilizzo dei Monitor permette di gestire il problema in modo più pulito rispetto ai semafori. Le tre varianti mostrate a lezione illustrano come cambiare le **politiche di priorità** agendo semplicemente sulle condizioni di attesa e risveglio.
### 1. Soluzione Base (Priorità ai Lettori)

In questa prima versione, i lettori hanno la precedenza. Se un lettore è dentro, gli altri possono entrare.
* **Il problema:** Se i lettori continuano ad arrivare, lo scrittore non entrerà mai (Starvation dello scrittore). Questo accade perché `start_read()` blocca i lettori *solo* se uno scrittore sta materialmente scrivendo (`busy_on_write`), ignorando gli scrittori in coda.

```c
monitor rw_monitor
    int rc = 0; 
    boolean busy_on_write = false;
    condition read, write;

    function start_read() {
        if (busy_on_write) wait(read);
        rc = rc + 1;
        signal(read); // Risveglio a catena: un lettore fa entrare il successivo
    }

    function end_read() {
        rc = rc - 1;
        if (rc == 0) signal(write); // Sblocco gli scrittori solo se non ci sono più lettori
    }

    function start_write() {
        // Mi blocco se ci sono lettori o se un altro sta scrivendo
        if (rc > 0 OR busy_on_write) wait(write);
        busy_on_write = true;
    }

    function end_write() {
        busy_on_write = false;
        // Quando finisco di scrivere, do prima la precedenza ai lettori in coda
        if (in_queue(read))
            signal(read);
        else
            signal(write);
    }
```
### 2. Prevenzione della Starvation (Blocco dei nuovi lettori)

Per evitare che lo scrittore muoia di fame, modifichiamo **solo la funzione di ingresso dei lettori**.

> [!check] La Modifica Aggiungiamo `OR in_queue(write)` nell'`if` di `start_read`. Ora, se un nuovo lettore arriva e vede che c'è uno scrittore in coda d'attesa, **si ferma e aspetta**, anche se ci sono altri lettori che stanno leggendo in quel momento.

`function start_read() {`
        `// MODIFICA: Mi blocco anche se c'è uno scrittore in coda d'attesa!`
        `if (busy_on_write OR in_queue(write)) wait(read);` 
        `rc = rc + 1;`
        `signal(read);`
    `}`
### 3. Soluzione con Forte Priorità agli Scrittori

In quest'ultima variante, non solo impediamo ai nuovi lettori di scavalcare lo scrittore in attesa, ma **ribaltiamo la priorità al momento dell'uscita di uno scrittore**.

> [!check] La Modifica Modifichiamo **solo la funzione di uscita degli scrittori**. Nella versione base, quando uno scrittore finiva, svegliava per primi i lettori in coda (`if in_queue(read)`). Ora invertiamo l'`if`: a fine scrittura, se ci sono altri scrittori in coda, facciamo entrare subito loro, lasciando i lettori ad aspettare.

`function end_write() {`
        `busy_on_write = false;`
        `// MODIFICA (INVERSIONE): Do la precedenza assoluta agli altri scrittori in coda`
        `if (in_queue(write))`
            `signal(write);`
        `else`
            `signal(read);`
    `}`
## CPU Scheduling

Lo scheduling è la strategia che definisce la scelta di quali processi, tra quelli in stato _Ready_ (pronti), devono ottenere l'assegnazione della CPU. In sostanza, stabilisce l'ordine della coda di esecuzione.

Si distinguono 2 tipi principali di processi:

1. **Processi CPU BOUND (o Bounded):** Processi che passano la maggior parte del loro tempo ad eseguire calcoli (usano principalmente la CPU).

2. **Processi I/O BOUND (o Bounded):** Processi che passano la maggior parte del tempo ad attendere operazioni di Input/Output (es. letture da disco, richieste di rete).

> [!check] Strategia di ottimizzazione (Dai tuoi appunti) La cosa buona dei processi I/O bound è che, una volta che gli viene assegnata la CPU per avviare la loro operazione, **la rilasciano subito** per mettersi in attesa del dispositivo I/O, al contrario dei processi CPU bound che tendono a occuparla a lungo.
> 
> **Conclusione logica:** È conveniente favorire prima i processi I/O. In questo modo si avviano le loro operazioni hardware e, mentre i dispositivi I/O lavorano in background per fornire le risposte, si può assegnare la CPU ai processi CPU bound. Si massimizza così l'uso parallelo delle risorse.

### Dispatcher

Il **Dispatcher** è il modulo del sistema operativo che si occupa materialmente di applicare la scelta fatta dall'algoritmo di scheduling (effettua il _context switch_, cambia i registri, salta all'istruzione giusta).

- **Definizione - Latenza di Dispatch (Dispatch Latency):** È il tempo impiegato dal dispatcher per fermare un processo e avviarne un altro. Più è basso, più il sistema è reattivo.
