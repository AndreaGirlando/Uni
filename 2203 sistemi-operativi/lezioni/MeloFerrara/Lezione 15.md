## 1. Anomalia di Belady e Page Fault

- Di norma, a parità di algoritmo, aumentando il numero di frame a disposizione diminuiscono i page fault.

- **Anomalia di Belady**: Si verifica quando, aumentando il numero di frame, aumentano anche i page fault.

- Questo accade perché rimuovere il frame presente da più tempo non è sempre un buon criterio (es. algoritmo FIFO).

- **Proprietà di inclusione**: Dato $B_{t}(n)$ come il set di pagine in memoria all'istante $t$ con un dato algoritmo e sequenza, la proprietà vale se l'insieme di pagine con $n$ frame è un sottoinsieme di quelle presenti nello stesso istante con $n+1$ frame.

- L'algoritmo **LRU** soddisfa questa proprietà, garantendo l'assenza dell'anomalia. L'algoritmo della _seconda chance_, essendo simile al FIFO, presenta invece l'anomalia.

## 2. Allocazione dei Frame e Paginazione su Richiesta

- **Paginazione su richiesta (Pure Demand Paging)**: All'avvio di un processo, tutte le sue pagine si trovano su disco e inizialmente non viene portato nulla in RAM.

- Questo approccio causa un picco di page fault nelle fasi primordiali di avvio (es. per richiedere il `main` o il Program Counter), per poi stabilizzarsi.

- **Numero minimo di frame**: Un'architettura richiede un numero minimo di frame affinché un processo sia eseguibile.

- Ad esempio, per un'istruzione `add` che gestisce operandi in memoria con livelli multipli di indirezione, potrebbero essere necessari 4 o più frame (per contenere l'istruzione stessa e i vari operandi), altrimenti si genererebbero infiniti page fault reiterando la richiesta.

- **Strategie di allocazione**:

    - **Equa**: I frame disponibili vengono ripartiti in modo uguale tra i processi, al netto di quelli usati dal Sistema Operativo.

    - **Proporzionale**: Assegnazione basata sulla taglia del processo (codice e dati). Il numero di frame per l'i-esimo processo è calcolato come $a_{i}$, in base alla sua taglia $s_{i}$ rispetto al totale.

## 3. Allocazione Locale vs Globale e Thrashing
### Thrashing e Allocazione dei Frame

Il **Thrashing** è una condizione di grave inefficienza in cui un sistema operativo spende più tempo a gestire il paging (operazioni di I/O su disco) rispetto all'effettiva esecuzione delle istruzioni dei processi. 

Sorge tipicamente quando la memoria fisica (RAM) allocata a un processo non è sufficiente a coprire il suo **Working Set** (l'insieme di pagine attivamente utilizzate in un dato intervallo di tempo).

---
### 📌 Allocazione Locale vs Globale nel Thrashing

La scelta della strategia di allocazione e sostituzione dei frame influisce drasticamente sulla modalità con cui il thrashing si propaga o viene contenuto all'interno del sistema.

#### 1. Sostituzione Globale (Effetto Domino)
* **Meccanismo:** Permette a un processo che subisce un *Page Fault* di selezionare un frame da rimpiazzare scegliendolo dall'intero pool della RAM, anche se quel frame appartiene a un altro processo (magari in esecuzione).
* **Impatto sul Thrashing:** Se un processo entra in affanno, inizierà a "rubare" frame ai processi sani. Questo riduce la memoria a disposizione degli altri programmi, che a loro volta inizieranno a soffrire di Page Fault e a rubare frame altrove.
* > [!DANGER] Conseguenza Critica
  > Si innesca una reazione a catena (effetto domino) che porta rapidamente al **collasso e al freeze totale del sistema operativo**.

#### 2. Sostituzione Locale (Effetto Quarantena)
* **Meccanismo:** Ciascun processo può selezionare un frame da rimpiazzare *esclusivamente* all'interno del set di frame che gli è stato originariamente allocato.
* **Impatto sul Thrashing:** Se il processo non ha abbastanza spazio, inizierà a sovrascrivere continuamente le proprie pagine, andando in stallo interno.
* > [!SUCCESS] L'Effetto "Quarantena"
  > Il thrashing viene isolato. Il processo malfunzionante rallenta drasticamente o si blocca, ma i processi sani mantengono i loro frame intatti e continuano a funzionare in modo fluido.

---
### ⚡ Il Collo di Bottiglia dell'I/O (Il Limite del Locale)

Sebbene l'allocazione locale protegga la RAM degli altri processi, **non è in grado di isolare il problema a livello hardware complessivo**.

> [!WARNING] Il Canale di I/O è una Risorsa Condivisa
> Un processo in thrashing locale bombarda il controllore del disco (SSD/HDD) con una coda infinita di richieste di lettura/scrittura. 
> Se un processo "sano" ha bisogno di caricare anche una sola pagina legittima dal disco, la sua richiesta rimarrà bloccata in coda dietro alle migliaia di richieste pendenti generate dal processo in stallo.

* **Risultato:** L'allocazione locale impedisce la corruzione della memoria altrui, ma le prestazioni generali del sistema subiscono comunque un netto degrado a causa della saturazione del sottosistema di I/O.

# Modello di Località e Working Set

## 1. Il Principio di Località
Rappresenta l'insieme di informazioni (codice e dati) utili per una determinata frazione di esecuzione di un processo in un dato momento. Garantire a un processo abbastanza frame per ospitare la sua località attuale gli permette di lavorare in modo efficiente, evitando il thrashing.
* **Località Temporale:** Se una risorsa è stata acceduta, è altamente probabile che venga riacceduta a breve (es. variabili contatore, cicli `for`).
* **Località Spaziale:** Se una risorsa è stata acceduta, è probabile che vengano accedute a breve risorse logicamente vicine (es. elementi di un vettore, esecuzione sequenziale di istruzioni).

---
## 2. Working Set Model (Modello proattivo)
L'insieme delle pagine referenziate negli ultimi accessi alla memoria, definiti da una finestra temporale parametrica $\Delta$ (finestra del Working Set) all'istante $t$. Le dimensioni e il contenuto del working set mutano dinamicamente nel tempo.

### 📐 Formulazione Matematica e Gestione
* **$WSS_i$ (Working Set Size):** Il numero di pagine uniche utilizzate dal processo $i$ all'interno dell'intervallo $\Delta$.
* **Domanda Totale di Frame ($D$):** Rappresenta la somma dei Working Set di tutti i processi attivi:
  $$D = \sum WSS_i$$
* **Politica di Controllo del Thrashing:**
  Se $m$ è il numero di frame fisici totali disponibili nella RAM:
  * Se $D \le m \implies$ Il sistema è stabile e i processi lavorano alla massima efficienza.
  * Se $D > m \implies$ Il sistema entra in **Thrashing** (non c'è abbastanza spazio per le località attuali).

> [!TIP] Soluzione del Sistema Operativo
> Quando $D > m$, il sistema operativo adotta una strategia drastica: **sospende un processo** (Medium-Term Scheduling / Swapping). Il processo scelto viene salvato su disco, i suoi frame vengono liberati e ridistribuiti immediatamente agli altri processi rimasti, abbassando $D$ sotto la soglia di pericolo.

### ⚙️ Approssimazione Software (Algoritmo di Aging)
Tracciare esattamente il working set ad ogni singolo accesso alla memoria è impossibile senza un hardware dedicato proibitivo. Il SO lo approssima combinando i **Bit di Riferimento** della Page Table e gli **Interrupt del Timer** stile algoritmo di aging.

---
## 3. Page Fault Frequency - PFF (Modello reattivo)
La PFF è un approccio alternativo e più diretto per capire se un processo è in sofferenza, misurando la frequenza reale dei page fault in rapporto ai frame fisici assegnati.

### 📈 Meccanismo di Controllo a Due Soglie
Il sistema operativo stabilisce due parametri di controllo: una **Soglia Superiore (Upper Threshold)** e una **Soglia Inferiore (Lower Threshold)**.

* **PFF > Soglia Superiore:** Il processo sta subendo troppi page fault. La sua località attuale è più grande dello spazio assegnato. 
  * *Azione del SO:* Alloca direttamente nuovi frame liberi a questo processo.
* **PFF < Soglia Inferiore:** Il processo ha una frequenza di page fault prossima allo zero. Si trova in una "zona comoda" (sovra-allocazione) e sta sprecando memoria utile.
  * *Azione del SO:* Rimuove frame da questo processo (sottrazione coatta) per rimetterli nel pool dei frame liberi.

> [!WARNING] Dinamica dei Picchi nei Cambi di Località
> Quando un processo cambia fase di esecuzione (cambio di località), la PFF subisce un **picco temporaneo verso l'alto**. Il processo richiede improvvisamente nuove pagine non presenti in RAM. Questo picco non indica necessariamente thrashing cronico, ma una transizione fisiologica: il SO risponde allocando frame finché il processo non stabilizza la sua nuova località, riportando la PFF all'interno delle due soglie.

---
## ⚖️ Confronto: Working Set vs PFF

| Caratteristica | Working Set Model | Page Fault Frequency (PFF) |
| :--- | :--- | :--- |
| **Approccio** | **Proattivo:** Previene il thrashing stimando il futuro in base al passato recente ($\Delta$). | **Reattivo:** Interviene solo quando il problema si manifesta misurando i guasti di pagina reali. |
| **Flusso di Lavoro** | Modifica l'allocazione dei frame *prima* che avvenga un page fault. | Modifica l'allocazione dei frame *in risposta* alla frequenza dei page fault. |
| **Overhead** | Più pesante (richiede il monitoraggio costante dei registri di bit a ogni tick del timer). | Più leggero (lavora e calcola le medie solo quando scatta un page fault). |

# Paging Daemon

- L'uso dell'algoritmo di sostituzione ha un costo, specialmente se la pagina da rimpiazzare è "sporca" (modificata) e necessita di essere salvata su disco.

- Il **Paging Daemon** è una routine che agisce periodicamente (quando il SO è poco carico) in modo proattivo per mantenere un _pool di frame liberi_.

- Seleziona una pagina vittima, la sincronizza su disco (se sporca) e azzera il bit di presenza/assenza, inserendo il frame nel pool dei liberi prima che si verifichi un effettivo page fault.

- **Ottimizzazione (Fast Page Fault)**: Se il processo proprietario reclama la pagina prima che il frame venga sovrascritto, la pagina è ancora fisicamente in RAM. Il SO la recupera istantaneamente dal pool dei liberi senza necessità di I/O su disco.

### Le Soglie di Memoria (Watermarks)

Il paging daemon non agisce alla cieca, ma regola la sua aggressività in base a tre soglie critiche di memoria libera (chiamate _watermarks_):

- **High Watermark (`lotsfree`):** La memoria libera è abbondante. Il paging daemon è in stato di _Sleep_. Il sistema alloca memoria istantaneamente.

- **Low Watermark (`desfree`):** La memoria libera sta scendendo. Il paging daemon viene svegliato in modalità **background**. Inizia a liberare frame lentamente per ristabilire la situazione prima che diventi critica, senza bloccare i processi utente.

- **Min Watermark (`minfree`):** Situazione di emergenza. La memoria libera è quasi esaurita. Il sistema passa alla **sostituzione sincrona (diretta)**: i processi che richiedono memoria vengono bloccati e costretti a liberare frame da soli prima di poter procedere. Se anche questo fallisce, interviene l'**OOM Killer** (Out Of Memory Killer libro pag 201-202) per terminare forzatamente i processi non vitali.

##  Dimensione della Pagina

- La dimensione (solitamente dai 4KB ai 32KB) è un limite imposto dall'hardware (MMU), ma il SO può fare _tuning_ in questo range.

- **Pagine più grandi (es. 16KB-32KB)**:

    - Meno voci nella tabella delle pagine (tabelle più piccole e meno ingombranti).
    
    - Ottimizzazione dell'I/O su disco, favorendo letture contigue e riducendo il tempo di posizionamento.
    
    - In teoria, riducono gli eventi di page fault raggruppando più informazioni.

- **Pagine più piccole**:

    - Riducono la frammentazione interna, evitando di sprecare spazio in RAM per caricare porzioni di dati non strettamente necessari.

##  Pagine Condivise e Cache

- Processi distinti che eseguono lo stesso programma (es. tre istanze del Blocco Note) possono condividere una singola copia del segmento del **codice** in RAM.

- Per evitare problemi di coerenza, la zona del codice condiviso deve essere rigorosamente contrassegnata in _sola lettura (Read-Only)_. Le zone dati restano separate e private per ogni processo.

- **Problema delle Tabelle Invertite**: Cercano la corrispondenza `[Processing_id : frame]`. Se un frame è condiviso da più processi, si crea overhead per cercare/aggiornare il `Processing_id` ad ogni accesso, rendendo questa struttura problematica sui sistemi multi-core.

- **Gestione Cache e Coerenza (Aliasing)**: Se due processi mappano lo stesso contenuto fisico su due indirizzi virtuali diversi (es. pagina virtuale 100 per P1 e 1000 per P2), si crea un problema di alias nelle cache basate su indirizzi virtuali. L'informazione si duplica in cache su linee diverse; se P1 modifica il dato, la cache di P2 non è sincronizzata, causando problemi di coerenza.