# Appunti: Gestione della Memoria

## Tecnica Copy-On-Write (COW)
È un'ottimizzazione che permette di risparmiare memoria quando processi diversi hanno delle pagine in cui, in una determinata fase, è presente lo stesso contenuto (pagine in comune). 

- Questo avviene sfruttando la `fork`. I due processi (Padre e Figlio, es. `A` e `A'`) punteranno inizialmente alla stessa sezione di memoria appena "forkata" (che rimane in comune). In questo modo si risparmia un'enorme quantità di memoria.
- **Il problema delle modifiche:** Quando uno dei due processi modifica la parte condivisa sorge un problema, poiché ogni processo si aspetta di avere una propria copia privata. 
- **La soluzione:** Questa tecnica funziona solo se le pagine dei due processi sono mantenute in **sola lettura**. Se avviene una modifica, si fa una copia privata *solo* per la specifica pagina modificata per ogni processo.

### Come interviene il Sistema Operativo
Per risolvere i problemi, il SO modifica la maschera dei permessi in *sola lettura* per captare le possibili scritture (tramite un page fault).
1. Se avviene una scrittura, si fa la copia fisica della pagina.
2. Vengono aggiornate le tabelle delle pagine del processo affinché puntino alla nuova pagina corretta.
3. Vengono ripristinati i permessi di scrittura.

> [!example] Esempio con più processi
> Se ho 3 o più processi ($P_1, P_2, P_3$) che puntano alla pagina `A` e $P_3$ prova a scrivere:
> - $P_3$ genererà un'eccezione e punterà a una sua nuova copia `A'` con i permessi ripristinati (lettura/scrittura).
> - $P_1$ e $P_2$ continueranno a puntare alla pagina originale `A`, mantenendo i permessi ancora in sola lettura.

---
## Zero-Fill-On-Demand
Si applica quando si deve allocare della nuova memoria. 
Una nuova pagina allocata dovrebbe essere sempre vuota. Tuttavia, essendoci la possibilità di sovrascrivere blocchi di memoria precedentemente allocata, la pagina potrebbe risultare "sporca" esponendo vecchi dati (rischio di sicurezza).

- **L'idea di base:** Mantenere in RAM una pagina costantemente riempita di zeri (vuota). Quando vengono caricate *tot* pagine di un processo, inizialmente tutte puntano a questa singola pagina vuota in *sola lettura* (di fatto, applicando il *Copy-On-Write* su questa specifica pagina).
- **Pool di pagine:** Per applicare bene questa tecnica, il sistema dovrebbe avere a disposizione un *pool di pagine vuote*. Non è detto che un processo usi effettivamente tutte le pagine che carica in memoria; per questo conviene applicare il COW.
- **Manutenzione del pool:** Il pool va mantenuto. Se il SO è in una fase di inattività (poco attivo), un processo in background ("zeroing thread") procede a pulire/liberare pagine per garantire disponibilità immediata quando richiesta.

---
## Gestione di Librerie Condivise (Shared Libraries)

> [!info] Integrazione e correzione: Linking Statico vs Dinamico
> Nella gestione delle grandi librerie condivise, il Sistema Operativo si occupa di non appesantire il binario del programma. Non include tutto il codice della libreria direttamente all'interno dell'eseguibile, ma fa sì che i processi richiamino un'unica copia fisica in memoria. La copia della libreria, quindi, è **condivisa tra i processi**.

Esistono due approcci principali:
1. **Linking Statico:** Consiste nell'inclusione effettiva di tutto il codice della libreria direttamente all'interno del file eseguibile in fase di compilazione/linking. (Crea file molto pesanti).
2. **Linking Dinamico:** Il collegamento e il caricamento delle librerie condivise avvengono direttamente a *run-time* (durante l'esecuzione).
	- **Vantaggi:** - Notevole risparmio di spazio sia su disco che nella RAM.
		- Sviluppo indipendente: facilita l'aggiornamento delle librerie senza dover ricompilare tutti i programmi che le utilizzano.

---
## File Mappati in Memoria (Memory-Mapped Files)

> [!note] Integrazione Slide: File Mappati
> I file mappati offrono un **modello alternativo di I/O su file**. Invece di usare le classiche `read()` e `write()`, un blocco del file su disco viene mappato direttamente nei frame della memoria virtuale di uno o più processi.

- **Possibilità di condivisione:** Più processi possono mappare lo stesso file nelle loro memorie virtuali; a livello fisico, i frame in RAM saranno condivisi (come mostrato nei diagrammi con la RAM al centro e i processi ai lati).
- **Cosa gestiscono automaticamente:**
	- Le librerie condivise (vengono mappate in memoria tramite questo sistema).
	- Il caricamento del codice eseguibile.
	- Il caricamento dei dati statici.

---
## Memoria del Kernel e Slab Allocator

Mentre la **memoria dei processi utente** è paginata (il che comporta un grado inevitabile di *frammentazione interna*), **il kernel ha le sue esigenze di memoria specifiche**.

> [!warning] Le esigenze del Kernel
> - Il kernel mira ad avere una **frammentazione interna minima o nulla** (non può permettersi sprechi).
> - C'è l'**impossibilità di paginare** l'allocazione in alcuni casi critici. Le strutture dati del kernel devono spesso risiedere in memoria fisica contigua.

### Lo Slab Allocator su Linux
Per risolvere le problematiche di frammentazione nella gestione della memoria del kernel, Linux utilizza lo *Slab Allocator*.

- **Slab:** È una sequenza di frame (pagine) fisicamente contigui in memoria.
- **Cache:** Consiste in uno o più *slab*. Viene creata **una cache per ogni tipo di struttura dati interna omogenea** del kernel (ad esempio, una cache dedicata solo ai descrittori di processo, un'altra per i descrittori dei file, ecc.).
- **Gestione dinamica e Stato:** Uno slab può trovarsi in tre stati differenti:
	- *Pieno* (tutti gli oggetti all'interno sono allocati).
	- *Vuoto* (nessun oggetto allocato, pronto per essere restituito o riutilizzato).
	- *Parziale* (alcuni oggetti in uso, altri liberi).
- **Vantaggi:** Garantisce la totale assenza di sprechi e una grandissima efficienza, poiché il kernel pre-alloca le strutture dati della dimensione esatta di cui ha bisogno.

L'ordine di creazione e assegnazione della memoria al kernel è differente, prima il kernel definisce i gruppi (cache) che gli servono e che deve utilizzare dopo quando deve usare una cache vede che non ha spazio d'indirizzamento e richiede al **Buddy System** (magazzino centrale della RAM) e gli richiede un blocco di memoria contigua e questo blocco di memoria che sarà assegnato prende il nome di slab.

# I File System

Come il Sistema Operativo (SO) ottimizza l'accesso e la gestione dei file.
I File System sono delle strutture dove organizziamo un accumulo di informazioni. Essi sono un'astrazione per rappresentare queste informazioni (queste strutture sono costituite da un concetto logico).

**I File e le Directory sono astrazioni.**

Ogni File System può avere convenzioni diverse da SO a SO, come ad esempio:
- **Nomenclatura**: L'estensione finale e ciò che descrive potrebbe cambiare.
- **Tipi di file**: Potrebbero esserci file di dispositivo speciali che indirizzano una partizione o un canale audio.
	- *(Nota: I primi 2 byte di ogni file rappresentano il tipo di file).*
- **Tipi di accesso**: Come può essere aperto un file.
- **Metadati (Attributi)**: Come la maschera dei permessi, la copia di backup, e vari timestamp per l'ultima modifica o la data di creazione.

---
## Operazioni su File

Non esistono solo le operazioni di `read` e `write`. Le directory hanno operazioni varie, e i link di codice hanno operazioni a parte.

> [!warning] Attenzione alla Concorrenza
> Se più processi aprono lo stesso file contemporaneamente, si possono presentare problemi simili alle **Race Condition**.

---
## Lock sui File

I lock sui file sono gestiti in maniera diversa per prevenire problemi di concorrenza:
- **Lock di tipo Shared (Condiviso)**: Sono lock potenzialmente condivisi, come avviene ad esempio per le operazioni di sola lettura.
- **Lock di tipo Exclusive (Esclusivo)**: Sono lock esclusivi, utilizzati per operazioni come la scrittura.

> [!info] Convenzioni dei SO
> SO diversi hanno convenzioni diverse anche sui lock (alcuni possono non supportare i lock *shared*, ma solo quelli *exclusive*).

### Modalità di applicazione del Lock
Il lock può essere applicato in modi differenti:

1. **Mandatory Lock (Obbligatorio)**: È il SO ad applicare il lock al processo (blocca le operazioni sui lock esclusivi).
2. **Advisory Lock (Consultivo)**: Il lock viene acquisito o rilasciato dai processi stessi. Un altro processo potrebbe non preoccuparsi di verificare se vi è un lock o meno; potrebbe quindi operare sul file senza sapere se il lock è stato acquisito o meno.