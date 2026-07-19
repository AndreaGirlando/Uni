# Gestione delle Transazioni e Organizzazione Fisica

###### Definizione di transazione
Una transazione è una parte di programma caratterizzata da un inizio (*start transaction*) e una fine, al cui interno deve essere eseguita una e una sola volta una delle seguenti operazioni terminali:
- **Commit work**: per terminare correttamente e rendere permanenti le modifiche
- **Rollback work**: per abortire la transazione e annullare le modifiche

Un sistema transazionale (OLTP) gestisce l'esecuzione di transazioni per conto di applicazioni concorrenti.

###### Proprietà ACID
Le transazioni devono godere di quattro proprietà fondamentali:
- **Atomicità**: La transazione è un'unità indivisibile. Non può lasciare il database in uno stato intermedio. In caso di guasto prima del commit, si esegue l'**UNDO** (annullamento); dopo il commit, se necessario, si esegue il **REDO**.
- **Consistenza**: La transazione deve rispettare i vincoli di integrità. Se lo stato iniziale è corretto, anche quello finale deve esserlo.
- **Isolamento**: L'esecuzione concorrente deve produrre un risultato equivalente a un'esecuzione sequenziale. Una transazione non deve esporre i suoi stati intermedi.
- **Durabilità (Persistenza)**: Gli effetti di una transazione in *commit* non devono andare perduti, anche in presenza di guasti.

###### Gestore dell'affidabilità
Questo modulo assicura atomicità e durabilità gestendo il **Log** (giornale di bordo), un file sequenziale su memoria stabile che registra tutte le operazioni.

**Record del Log**:
- Operazioni: $B(T)$ (Begin), $I(T,O,AS)$ (Insert), $D(T,O,BS)$ (Delete), $U(T,O,BS,AS)$ (Update), $C(T)$ (Commit), $A(T)$ (Abort).
- $BS$ (Before State): valore prima della modifica (per Undo).
- $AS$ (After State): valore dopo la modifica (per Redo).

**Regole fondamentali (WAL)**:
1. **Write-Ahead-Log**: si scrive nel log la parte *before* prima di scrivere nel database (consente l'Undo).
2. **Commit-Precedenza**: si scrive nel log la parte *after* prima di effettuare il commit (consente il Redo).

###### Checkpoint e Ripristino
Il **Checkpoint (CK)** è un'operazione che serve a ridurre il tempo di ripristino, registrando quali transazioni sono attive in un dato istante e portando le pagine "sporche" su disco.

**Algoritmo di ripresa a caldo (Warm Restart)**:
1. Trovare l'ultimo checkpoint ripercorrendo il log a ritroso.
2. Costruire gli insiemi:
    - **UNDO**: transazioni attive al guasto o non committate.
    - **REDO**: transazioni committate ma le cui modifiche potrebbero non essere su disco.
3. Ripercorrere il log all'indietro disfacendo le azioni delle transazioni in UNDO.
4. Ripercorrere il log in avanti rifacendo le azioni delle transazioni in REDO.

###### Controllo di concorrenza
L'esecuzione concorrente non controllata può causare anomalie:
- **Perdita di aggiornamento**: $w_1(x)$ viene sovrascritta da $w_2(x)$ senza aver letto il valore aggiornato.
- **Lettura sporca**: leggere un dato scritto da una transazione poi abortita.
- **Lettura inconsistente**: leggere lo stesso dato due volte ottenendo valori diversi.
- **Aggiornamento fantasma**: modifiche che violano vincoli a causa di inserimenti concorrenti.

###### Serializzabilità
Uno schedule è una sequenza di operazioni di I/O di transazioni concorrenti. L'obiettivo è ottenere schedule **serializzabili**, ovvero che producano lo stesso risultato di uno schedule seriale (una transazione alla volta).

**Conflict-Serializzabilità (CSR)**:
Due schedule sono *conflict-equivalenti* se includono le stesse operazioni e ogni coppia di operazioni in conflitto (almeno una scrittura sullo stesso oggetto) compare nello stesso ordine.
Uno schedule appartiene a CSR se e solo se il **grafo dei conflitti** è aciclico.

###### Locking a due fasi (2PL)
Per garantire la serializzabilità in pratica si usano i **Lock**:
- *r_lock* (condiviso) per la lettura.
- *w_lock* (esclusivo) per la scrittura.

**Protocollo 2PL**:
1. Una transazione acquisisce lock (fase crescente).
2. Una volta rilasciato un lock, non può acquisirne altri (fase decrescente).
*Nota*: Il 2PL garantisce la conflict-serializzabilità ma può causare **Deadlock** (stallo), risolvibili tramite timeout o rilevamento di cicli nel grafo delle attese.

###### Organizzazione fisica dei dati
I DBMS gestiscono i dati in memoria secondaria (persistente ma lenta) usando un **Buffer Manager** in memoria centrale per ridurre gli accessi al disco.

**Gestione del Buffer**:
- **Fix**: richiede una pagina (se non c'è, la carica applicando politiche come LRU).
- **Force**: forza la scrittura su disco (sincrona).
- **Steal/No-Steal**: politiche di sostituzione delle pagine modificate prima del commit.

###### Strutture di memorizzazione
I record sono organizzati in file:
- **Heap file (seriale)**: i record sono inseriti in coda in modo non ordinato. Efficiente per inserimenti, inefficiente per ricerche.
- **File Hash**: accesso diretto basato su una funzione di hash. Ottimo per uguaglianze ($A=v$), pessimo per intervalli ($v_1 < A < v_2$).
- **File Ordinati (sequenziali)**: ordinati fisicamente secondo un campo. Buoni per ricerche, costosi per inserimenti.

###### Indici
Strutture ausiliarie per l'accesso efficiente ai dati.
- **Indice Primario**: basato sul campo di ordinamento fisico del file. Solitamente **sparso** (una entry per blocco). Costo ricerca: $\log_2 n$ blocchi.
- **Indice Secondario**: su campi non di ordinamento. Deve essere **denso** (una entry per record). Più costoso in spazio ma essenziale per ricerche su chiavi alternative.

**B-Tree (Indici multilivello)**:
Alberi di ricerca bilanciati pensati per la memoria secondaria. Ogni nodo corrisponde a una pagina. Riducono drasticamente l'altezza dell'albero e quindi gli accessi al disco ($t = \log_{fo} N$). Usati dalla maggior parte dei DBMS moderni (Oracle, SQL Server, MySQL InnoDB).

###### Ottimizzazione delle interrogazioni
Il *Query Optimizer* traduce la query SQL in un piano di esecuzione efficiente:
1. **Analisi**: lessicale, sintattica e semantica.
2. **Ottimizzazione algebrica**: trasformazioni logiche (es. anticipare le selezioni).
3. **Ottimizzazione basata sui costi**: scelta degli indici e algoritmi (es. *nested-loop* vs *hash-join*) basata su statistiche (cardinalità, distribuzione) mantenute nel catalogo.