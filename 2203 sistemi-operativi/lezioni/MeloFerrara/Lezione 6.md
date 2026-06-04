Qualsiasi soluzione per gestire la mutua esclusione (che sia software o hardware) non deve solo "funzionare", ma deve obbligatoriamente garantire tre proprietà. 

- **Mutua Esclusione (Mutual Exclusion):** Se il processo $P_1$ sta eseguendo la sua sezione critica, nessun altro processo può trovarsi nella propria sezione critica.

- **Progresso (Progress):** Se nessun processo è nella sezione critica e alcuni processi vogliono entrarvi, solo i processi che non stanno eseguendo la loro sezione non critica possono partecipare alla decisione su chi entrerà. Questa decisione non può essere rimandata all'infinito. (In parole povere: un processo che si fa i fatti suoi fuori dalla sezione critica non deve bloccare chi vuole entrarci).

- **Attesa Limitata (Bounded Waiting):** Deve esistere un limite (un "tetto massimo") al numero di volte che gli altri processi possono entrare nelle rispettive sezioni critiche dopo che un processo ha fatto richiesta di entrarvi, e prima che questa richiesta venga accolta. Evita la _starvation_ (inedia).
## Come realizzare la Mutua Esclusione

Ci sono diversi modi per farlo:
- **Disabilitare gli interrupt:** Non è una soluzione ottima poiché non risolve il problema della mutua esclusione nei sistemi multicore. Inoltre, può portare l'utente a disabilitare gli interrupt per poi incappare in un bug, ecc.

- **Variabili di Lock:** Funzionano bene solo se gestite a livello kernel (un programmatore potrebbe sbagliare).

- **Alternanza stretta:** È una soluzione software che usa una variabile globale per determinare quale processo ha il diritto di entrare in sezione (non è ideale per le prestazioni viola la condizione di progresso).

## Algoritmo di Peterson

Un altro algoritmo molto usato è quello di Peterson. Funziona dichiarando le variabili di interesse per la sezione critica:

- Ha un array `flag` di tipo bool (indica l'interesse a entrare).

- `turn`: variabile `int` che indica a chi spetta il turno.

**Funzionamento:**

1. **Dichiara l'intenzione:** `flag[i] = true`

2. **Cede il turno:** `turn = j`

3. **Attesa attiva:** Ciclo `while` fino a quando `flag[j] == true` E `turn == j`

4. **Sezione critica:** (Se il ciclo `while` fallisce, il processo Pi entra)

5. **Uscita:** `flag[i] = false`

Nel punto due stiamo considerando la situazione in cui Pj arriva prima di Pi ed è qui che agisce il fattore **cortesia** dell'algoritmo dove il primo che arriva entra nella sezione critica (in parole povere dato che Pi vuole entrare ma vede che è arrivato prima Pj lo fa passare perchè è arrivato prima di lui "cortesia")
L'algoritmo di Peterson è geniale perché unisce i due tentativi precedenti (variabili di lock e alternanza stretta) compensandone i difetti:
- L'array `flag` garantisce la **mutua esclusione** (entrambi dichiarano l'intenzione, ma non si sovrappongono).
- La variabile `turn` rompe gli stalli e garantisce il **progresso** e l'**attesa limitata** (agisce come atto di cortesia: "dopo di te").

> **Nota:** Questo algoritmo si può generalizzare per N processi.

---
## Soluzioni Hardware: Istruzioni TSL e XCHG

### TSL (Test and Set Lock)

L'istruzione `TSL (REGISTER, LOCK)` compie due azioni allo stesso tempo:

1. Legge il valore attuale della variabile `LOCK` e lo copia nel registro.

2. Scrive un valore `!= 0` nella variabile `LOCK`.

**Come si usa:**

- Il processo chiama `TSL`.

- Se il registro riceve `1`, significa che qualcuno è dentro la sezione critica; il processo esegue quindi il ciclo di _wait_ finché `LOCK` non diventa `0`.

- All'uscita, il processo imposta `LOCK = 0`.

### XCHG (Exchange o Scambio)

Questa istruzione scambia il valore di un registro con quello di una specifica locazione di memoria.

## Sleep e Wakeup

L'attesa attiva (_busy waiting_) spreca preziosi cicli di CPU e, come visto, può portare al problema dell'inversione di priorità. Per risolvere questo problema, è fondamentale per un processo avere la possibilità di bloccarsi spontaneamente. I sistemi operativi offrono due primitive per questo scopo:

- **`sleep`**: Sospende l'esecuzione del processo chiamante. Il processo rilascia la CPU e passa nello stato di **Blocked** (bloccato). Potrà tornare in esecuzione solo quando un altro processo lo risveglierà.

- **`wakeup(processo)`**: Risveglia uno specifico processo dormiente, facendolo passare dallo stato di _Blocked_ a quello di **Ready** (pronto), rimettendolo a disposizione dello scheduler.

### Il problema del Produttore-Consumatore

Consideriamo il classico problema del produttore-consumatore con un **buffer limitato** (di dimensione $N$).

- Il **produttore** inserisce continuamente dati nel buffer.

- Il **consumatore** consuma continuamente dati dal buffer.

- _Vincoli:_ Il consumatore non può consumare ciò che non esiste (buffer vuoto) e il produttore non può inserire dati se non c'è spazio (buffer pieno).

Di seguito una prima (e problematica) soluzione a questo problema:


```
int count = 0; // Tiene traccia degli elementi nel buffer

// Definizione del Produttore
function producer() {
    while (true) {
        item = produce_item();
        if (count == N) sleep(); // Se il buffer è pieno, dorme
        insert_item(item);
        count = count + 1;
        if (count == 1) 
            wakeup(consumer);    // Se ha inserito il primo elemento, sveglia il consumatore
    }
}

// Definizione del Consumatore
function consumer() {
    while (true) {
        if (count == 0) sleep(); // Se il buffer è vuoto, dorme
        item = remove_item();
        count = count - 1;
        if (count == N - 1) 
            wakeup(producer);    // Se ha liberato uno spazio, sveglia il produttore
        consume_item(item);
    }
}
```

**Problema del Risveglio Perso (Lost Wakeup):** Questa soluzione ci porta fatalmente a un **deadlock**. Se il consumatore legge `count == 0` ma lo scheduler toglie la CPU _prima_ che esegua la `sleep()`, il produttore prenderà il controllo, inserirà un elemento, farà una `wakeup` (che andrà a vuoto, dato che il consumatore non sta ancora dormendo) e poi riempirà il buffer fino a mettersi in `sleep`. Quando il consumatore riprenderà l'esecuzione, eseguirà la sua `sleep()` (poiché aveva già letto `count == 0`). Entrambi i processi dormiranno per sempre.

Per aggirare questo problema, si era teorizzato l'uso di un **wakeup waiting bit** (un flag che "salva" un segnale di wakeup inviato quando il processo è sveglio), ma la vera soluzione robusta è arrivata con i Semafori.

---
## Semafori

Generalizzando e rendendo sicure le operazioni di `sleep` e `wakeup`, Edsger Dijkstra ha introdotto il **semaforo**. Un semaforo è una struttura dati composta da:

1. Una variabile intera $S$ che **non può mai diventare negativa** ($S \ge 0$).

2. Le primitive **`wait`** (chiamata anche `down` o `P`) e **`signal`** (chiamata anche `up` o `V`).

Queste due operazioni decrementano o incrementano la variabile $S$. Se un processo prova a effettuare una `wait` su un semaforo che vale $0$, l'operazione diventa **bloccante** (il processo viene messo in stato di _sleep_).

_Nota bene:_ Per garantire il corretto funzionamento ed evitare _race condition_ sul semaforo stesso, le operazioni `wait` e `signal` devono essere rigorosamente **atomiche**.

### Tipi di Semaforo

- **Numerico (Counting Semaphore):** $S$ assume valori da $0$ a $N$. Si presta ai problemi di conteggio delle risorse, bloccando il thread quando le risorse disponibili si esauriscono.

- **Mutex (Binary Semaphore):** $S$ assume solo valori $S \in \{0, 1\}$. Viene usato come "lucchetto" per garantire la mutua esclusione in una singola sezione critica.

### Soluzione del problema Produttore-Consumatore con i Semafori

Per risolvere il problema senza risvegli persi, usiamo tre semafori: un mutex per proteggere il buffer, uno per contare gli slot vuoti e uno per contare gli slot pieni.

```
semaphore mutex = 1; // Controlla l'accesso esclusivo al buffer
semaphore empty = N; // Conta gli slot vuoti nel buffer (inizialmente tutti)
semaphore full = 0;  // Conta gli slot pieni nel buffer (inizialmente nessuno)

function producer() {
    while (true) {
        item = produce_item();
        
        wait(empty);   // Decrementa gli slot vuoti (si blocca se è 0)
        wait(mutex);   // Entra nella sezione critica
        
        insert_item(item);
        
        signal(mutex); // Esce dalla sezione critica
        signal(full);  // Incrementa gli slot pieni
    }
}

function consumer() {
    while (true) {
        wait(full);    // Decrementa gli slot pieni (si blocca se è 0)
        wait(mutex);   // Entra nella sezione critica
        
        item = remove_item();
        
        signal(mutex); // Esce dalla sezione critica
        signal(empty); // Incrementa gli slot vuoti
        
        consume_item(item);
    }
}
```

**L'ordine di queste due istruzioni è vitale!** Se un programmatore invertisse le due operazioni (facendo prima `wait(mutex)` e poi `wait(empty)`), e il buffer fosse pieno, il produttore acquisirebbe il mutex bloccando l'intero buffer per poi addormentarsi aspettando uno slot vuoto. Il consumatore non potrebbe mai svuotare il buffer perché il mutex è bloccato dal produttore: **Deadlock istantaneo**.