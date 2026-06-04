
### Semafori
il problema produttori-consumatori spesso viene risolto usando i semafori, e viene fatto in questo modo:

```
// Inizializzazione
int N = 100           // Dimensione massima del buffer
semaphore mutex = 1   // Lucchetto per il buffer (1 = libero)
semaphore empty = N   // All'inizio, tutti gli N slot sono vuoti
semaphore full = 0    // All'inizio, ci sono 0 elementi da consumare

// -----------------------------------------------------------------

function producer() {
    while (true) {
        item = produce_item()  // Crea un nuovo dato (fuori dalla sezione critica)
        
        down(empty)            // C'è spazio? Se no, mi blocco e aspetto. Se sì, occupo uno slot "vuoto" (-1)
        down(mutex)            // Prendo il lucchetto per accedere al buffer
        
        insert_item(item)      // SEZIONE CRITICA: Inserisco l'elemento in modo sicuro
        
        up(mutex)              // Rilascio il lucchetto del buffer
        up(full)               // Segnalo che c'è un nuovo slot "pieno" (+1), svegliando il consumer se dormiva
    }
}

// -----------------------------------------------------------------

function consumer() {
    while (true) {
        down(full)             // C'è roba da leggere? Se no, mi blocco e aspetto. Se sì, "consumo" uno slot pieno (-1)
        down(mutex)            // Prendo il lucchetto per accedere al buffer
        
        item = remove_item()   // SEZIONE CRITICA: Rimuovo l'elemento in modo sicuro
        
        up(mutex)              // Rilascio il lucchetto del buffer
        up(empty)              // Segnalo che si è liberato un nuovo slot "vuoto" (+1), svegliando il producer se dormiva
        
        consume_item(item)     // Faccio qualcosa con il dato (fuori dalla sezione critica)
    }
}
```

abbiamo principalmente solo due operazioni: *up* e *down*, che incrementano/decrementano il contatore passato come parametro, è importante che il contatore non sia mai negativo.

### Mutex e thread utente
Tra i thread utente che fanno riferimento ad un unico processo modello *1 a molti* i mutex si possono usare in modo efficiente facendo uso di TSL (o XCHG)

> [!CITE]
> **Ricordiamo**:
> - **TSL (Test and Set Lock):** È un'istruzione hardware che esegue due operazioni contemporaneamente e in modo indivisibile: **legge** il valore di una locazione di memoria (il "lock") copiandolo in un registro della CPU, e subito dopo **imposta** (scrive) quella stessa locazione di memoria a un valore non nullo (solitamente `1`, per indicare che la risorsa è "occupata").
>     - _A cosa serve:_ Se il valore letto era `0`, il processo capisce che il lucchetto era libero, lo ha appena chiuso a chiave (`1`) ed entra nella sua sezione critica. Se il valore letto era `1`, sa che qualcun altro è già dentro e continua a ciclare (Spinlock) finché non si libera.
> - **XCHG (Exchange)** _(nota: spesso la troverai scritta `XCHG` invece di `XHCG`, tipica delle CPU x86)_: È un'istruzione hardware alternativa al TSL che **scambia** (exchange) in modo atomico il contenuto di un registro della CPU con il contenuto di una locazione di memoria.
>     - _A cosa serve:_ Il meccanismo è simile al TSL. Un processo mette il valore `1` in un suo registro interno e poi esegue la `XCHG` con la variabile di lock in memoria. Dopo lo scambio, il processo controlla il suo registro: se c'è uno `0`, significa che ha "rubato" lo zero alla memoria lasciandoci un `1` (ha acquisito il lock). Se c'è un `1`, il lock era già preso e deve riprovare.
> 

L'implementazione di queste due istruzioni cambia e andremo ad usare delle primitive introdotte precedentemente (thread_yield) vedi slide

**FUTEX (Fast Userspace Mutex)** Garantiscono prestazioni eccellenti riducendo drasticamente le costose chiamate di sistema (_system call_). L'idea chiave è tentare di gestire il lock interamente in modalità utente. Si compongono di due elementi:
- **Libreria utente:** Tenta di acquisire il lock usando istruzioni hardware atomiche (come le TSL o XCHG viste prima). Se il lock è libero, lo prende e ritorna istantaneamente. Non essendoci chiamate al sistema operativo, l'operazione è velocissima.
- **Servizio kernel:** Interviene **solo** in caso di contesa. Se la libreria utente trova il lock già occupato, effettua una chiamata a sistema per chiedere al kernel di bloccare il processo (mettendolo in _sleep_) e accodarlo finché la risorsa non si libera.
### Monitor
Sono delle astrazioni di alto livello che offrono una gestione semplice della mutua esclusione, che sollevano il programmatore della responsabilità di usare bene i mutex.

> [!TIP]
> I semafori sono universali non essendo legate al linguaggio di programmazione, sono delle chiamate a sistema a differenza dei monitor che sono dei costrutti di più alto livello.

Quando i linguaggi di programmazione introducono i monitor molto spesso integrano anche una gestione autonoma dei thread, per garantire la sincronizzazione il monitor crea una variabile condizione sulla quale esercita i *wait* e *signal* 

## 1. Modello di Hoare (Signal and Wait)

Sviluppato dal teorico C.A.R. Hoare, ideatore dei monitor. Privilegia la rigorosità logica a discapito delle performance.

- **Comportamento:** Il thread segnalatore (**T1**) si blocca immediatamente e cede il controllo del monitor al thread svegliato (**T2**).

- **Ripresa:** Quando **T2** finisce il suo lavoro ed esce dal monitor, **T1** si risveglia e riprende l'esecuzione esattamente da dove aveva fatto la `signal`.

- **Implicazioni sul codice:** Quando **T2** si sveglia, ha la garanzia assoluta che lo stato del monitor sia identico a quello in cui si trovava al momento della `signal`. Si può quindi usare un semplice costrutto `if`.

- **Perché non si usa:** È troppo costoso. Richiede **almeno due context switch** forzati e immediati tra T1 e T2, appesantendo enormemente il lavoro dello scheduler del sistema operativo. Non è mai stato implementato nei sistemi moderni di produzione.

> [!example] Snippet concettuale (Hoare)
> 
> Java
> 
> ```
> if (condizione_non_soddisfatta) {
>     wait(); 
> }
> // Sicuro al 100%: appena mi sveglio la condizione è vera!
> ```

---
## 2. Modello Mesa (Signal and Continue) - _Lo Standard_

Sviluppato nei laboratori Xerox per l'OS Mesa. È l'approccio orientato alle performance e alla praticità. **È l'implementazione utilizzata da Java, Pthreads (C/C++) e C#.**

- **Comportamento:** Il thread segnalatore (**T1**) **non si ferma**. Esegue la `signal` e continua la sua esecuzione tenendo per sé il monitor.

- **Ripresa:** Il thread svegliato (**T2**) viene semplicemente spostato dalla coda della condizione alla **coda dei processi "Ready"** (pronti ad entrare nel monitor). Dovrà competere per l'accesso al monitor non appena **T1** uscirà.

- **Il problema del "Furto":** Tra il momento in cui **T1** fa `signal` e il momento in cui **T2** riesce effettivamente ad entrare, un terzo thread **T3** potrebbe prendere il controllo del monitor e alterare di nuovo la condizione.

- **Implicazioni sul codice:** La condizione **deve essere sempre ricontrollata** al risveglio. È obbligatorio l'uso del costrutto `while`.

> [!warning] La Regola d'Oro di Mesa (Domanda d'esame) Nel modello Mesa, la `signal` è solo un suggerimento ("hint"). Non garantisce la condizione, per questo si deve usare sempre il `while`.

> while (condizione_non_soddisfatta) {
>     wait(); 
> }
> // Mi sono svegliato, ma ho ricontrollato il while prima di proseguire!
> ```

---
## 3. Modello Concurrent Pascal (Signal and Return)
Proposto da Per Brinch Hansen per il linguaggio Concurrent Pascal. È una via di mezzo, pensata per evitare i problemi di Hoare ma mantenendo l'uso dell'`if`.

- **Comportamento:** Un thread **T1** può fare una `signal` **solo come ultimissima istruzione** prima di uscire dalla procedura del monitor.
- **Ripresa:** Svegliando **T2** e uscendo contemporaneamente dal monitor, **T1** risolve il conflitto alla radice. **T2** entra subito nel monitor e trova la condizione intatta.
- **Perché non si usa:** Impone restrizioni troppo severe alla scrittura del codice. Il programmatore non può eseguire calcoli o aggiornare lo stato del monitor dopo aver lanciato una `signal`. Il linguaggio Concurrent Pascal non è più utilizzato.

---
## 📊 Tabella Riassuntiva di Confronto

| Modello | Comportamento di chi fa la `Signal` | Costrutto Richiesto | Efficienza Context Switch | Diffusione Attuale |
| :--- | :--- | :--- | :--- | :--- |
| **Hoare** | Si sospende e cede il monitor al volo | `if` | Bassa (troppi switch) | Puramente Teorico |
| **Mesa** | Continua a eseguire e tiene il monitor | `while` | **Alta** | **Standard (Java, C, ecc.)** |
| **Concurrent Pascal** | Obbligato a uscire dal monitor all'istante | `if` | Media | Obsoleto / Inutilizzato |

Di seguito la soluzione dei produttori-consumatori ma usando i monitor
vedi slide

### Scambio messaggi tra processi
Questo approccio utilizza due primitive ad alto livello fornite dal sistema operativo: **`send`** e **`receive`**.
I concetti chiave da ricordare sono tre:
- **Sincronizzazione implicita (Blocchi):** La `receive` è tipicamente _bloccante_: se non ci sono messaggi da leggere, il processo si mette in attesa. Anche la `send` può esserlo: se assumiamo che ci sia un **buffer** di appoggio con capienza finita _N_, e questo buffer è pieno, chi spedisce si blocca finché non si libera spazio.
- **Indirizzamento:** Può essere **diretto** (il mittente specifica il PID esatto del destinatario) oppure indiretto tramite una **mailbox** (una "cassetta della posta" condivisa da cui i processi pescano i messaggi).
- **Scalabilità:** Il grande vantaggio di questo approccio è che non richiede memoria condivisa. Per questo motivo è facilmente estendibile a sistemi distribuiti, permettendo a processi su computer diversi di comunicare via rete (ad esempio usando le librerie **MPI**).


**Il Codice (Produttore-Consumatore):** risolvere il problema del Bounded-Buffer in questo modo è elegantissimo. Il _producer_ impacchetta il dato e fa una `send`; il _consumer_ fa una `receive` e lo estrae. Tutta la complessità dei semafori visti in precedenza qui è gestita "dietro le quinte" dal sistema di messaggistica del sistema operativo!