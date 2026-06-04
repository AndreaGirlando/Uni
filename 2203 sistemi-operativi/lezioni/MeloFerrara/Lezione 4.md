### Processi

###### Definizione di processo
Il processo è un istanza di un programma in memoria, ogni processo ha il proprio spazio di indirizzamento, questo è composto dalle seguenti cose
- *codice*(text nell'img): Di default, due processi distinti hanno spazi di indirizzamento **completamente isolati**, non condividono nulla, nemmeno il codice. Il codice può essere condiviso in memoria centrale solo se due processi eseguono lo _stesso identico programma_ o se utilizzano **librerie condivise**
- *dati*: strutture statiche che hanno valore sempre (delle variabili valorizzate sin dall'avvio del programma) si trova vicino al codice perché anche questi dati vengono caricati in memoria insieme al codice
- *stack*: una struttura di supporto al processo, in pratica una memoria che gestisce le chiamate a funzione e la gestione delle variabili statiche
- *heap*: memoria dinamica in cui vengono allocate le variabili dinamiche (classi, oggetti, malloc, new)

> [!TIP]
> Usiamo lo heap perché quando si ha un ritorno di una funzione nello stack tutte le variabili allocate vengono eliminate questo non succede con le cose allocate nello heap, che restano fisse fino a quando il programmatore non le elimina

Per ogni processo abbiamo un **Process Control Block** dove sono contenuti diversi metadati, tutti i **PCB** si trovano dentro *una tabella dei processi* ognuno è identificato univocamente da un **PID**(Process ID). Tra i metadati troviamo diverse informazioni come lo stato del processo, i file aperti, la copia dei valori che deve usare nei registri(quando viene eseguito questi valori vengono caricati nei registri), processi imparentati, il suo PC e allarmi pendenti(interrupt/segnali)
I valori nei registri in un certo istante appartengono allo stato del processo.
I processi vengono eseguiti con uno pseudo-parallelismo associando a ogni istanza di tempo un determinato processo, questo viene chiamato **Time slicing**; inoltre quando si programma bisogna pensare in modo semplice come se ogni ad ogni processo fosse associata una CPU virtuale con la quale viene eseguito il processo.
###### Modelli dei processi
Cose


###### Creazione e terminazione dei processi
**Creazione processo**: viene creato in fase di init del sistema oppure viene creato un per azione dell'utente, questo viene fatto attraverso delle metodologie 
- **sdoppiamento del padre**: 
	- usando fork un comando UNIX che crea un nuovo processo clonando il padre
	- usando exec un comando UNIX che esegue un programma all'interno dello spazio di indirizzamento del processo chiamante, in pratica cancella tutte le informazioni del processo chiamante e inizializza al suo interno il nuovo processo (non crea un nuovo processo)
- **nuovo processo**: usando CreateProcess, un comando specifico per win che prende 10 argomenti e crea un nuova entità con PID diverso (Process ID), un dei tanti argomenti indica il path del percorso dell'eseguibile

fork e execve usate in un certo modo possono riprodurre il funzionamento di CreateProcess

#### Il Funzionamento della `fork()` e la Gestione dei Processi

La chiamata di sistema `fork()` è lo strumento fondamentale nei sistemi Unix-like per la creazione di nuovi processi. Quando un processo "padre" invoca una `fork()`, viene generato un processo "figlio" che è una copia quasi identica del genitore.

##### 1. Cosa eredita il processo figlio?

Il figlio non riparte dall'inizio del programma, ma riceve un'immagine speculare delle risorse del padre al momento della chiamata:

- **Codice eseguibile:** Il figlio condivide lo stesso codice binario.

- **Variabili e Dati:** Le variabili allocate e lo stato della memoria vengono copiati.

- **File Descriptor:** Se il padre aveva dei file aperti, il figlio eredita l'accesso a quegli stessi file.

- **Punto di esecuzione:** Il figlio riprende l'esecuzione esattamente dalla riga successiva alla `fork()`.

> **Nota Tecnica: Copy-on-Write (CoW)** Sebbene lo spazio di indirizzamento sia logicamente separato, il Sistema Operativo ottimizza le prestazioni non duplicando immediatamente la memoria fisica. Entrambi i processi puntano alle stesse pagine di memoria finché uno dei due non tenta di modificarle; solo in quel momento la pagina viene effettivamente copiata. Approfondimento a fine pagina

---
#### 2. Il Ciclo di Vita e la Terminazione

**Terminazione del processo**: esistono diverse modi per terminare un processo:
- uscita normale: exit o ExitProcess, è il processo stesso che chiede al sistema operativo di voler terminare
- uscita su errore
- kill(UNIX) o TerminateProcess(win) da parte di un altro processo (quando clicchiamo la x per chiudere un programma stiamo interagendo con la GUI quindi siamo in questo caso)

esiste soft-kill e hard-kill: il primo manda un segnale di terminazione hard kill invece uccide "senza pietà"

Il legame tra padre e figlio è regolato dal Sistema Operativo per garantire che le informazioni di terminazione non vadano perdute.

##### Il Processo Zombie

Quando un figlio termina la sua esecuzione tramite una `exit()`:

1. Il Sistema Operativo libera quasi tutte le sue risorse (RAM e CPU).

2. Il processo rimane però presente nella **tabella dei processi** in stato **"Zombie"**.

3. Questo stato permane finché il padre non esegue una `wait()`, leggendo il valore di ritorno del figlio e permettendo al kernel di eliminarlo definitivamente.

##### Il Processo Orfano

Se il padre termina il proprio ciclo di vita prima del figlio:

- Il figlio diventa un **"orfano"**.

- Il kernel riassegna il figlio a un nuovo genitore, solitamente il processo **`init`** (PID 1) o **`systemd`** nei sistemi moderni. Questi processi "adottano" i figli e si occupano di eseguire la `wait()` al posto del padre originale.

> [!TIP]
> Perchè si preferisce il modello fork-exec rispetto a create process:
#### 1. Il principio di "Ereditarietà Totale"

Quando fai una `fork()`, il figlio riceve una copia **esatta** dello spazio di indirizzamento del padre. Questo include:

- Variabili e dati calcolati fino a quel momento.

- **File descriptor aperti:** Se il padre stava leggendo un file o aveva una connessione socket aperta, il figlio può continuare a usarli immediatamente.

Con `CreateProcess`, invece, devi ripartire da zero. Se vuoi passare dei dati o dei file aperti al figlio, devi farlo esplicitamente tramite una lunga lista di parametri o tramite meccanismi di comunicazione inter-processo (IPC) molto più macchinosi.

#### 2. Configurazione "Pre-Esecuzione"

Questa è la vera potenza del modello UNIX. Tra la `fork()` (che crea il clone) e la `exec()` (che carica il nuovo programma), il processo figlio è "vivo" ed esegue ancora il codice del padre. In questo brevissimo lasso di tempo, il figlio può:

- Chiudere file che non gli servono.

- Cambiare i propri permessi (es. diventare un utente con meno privilegi).

- **Redirigere l'input/output:** Può collegare il proprio `stdout` a una pipe per parlare con un altro processo.

In Windows, tutto questo deve essere specificato all'interno dei parametri della `CreateProcess`. Se la funzione non prevede una specifica opzione, non puoi farlo facilmente. In UNIX, siccome il figlio è codice che puoi scrivere, hai un controllo totale prima che il nuovo programma parta.

###### Stato di un processo
1. **new**: il processo viene inizializzato
2. **ready**: il processo è pronto ad essere eseguito dalla CPU, viene messo in una *coda dei processi* è il sistema operativo a scegliere quale processo in fase di ready eseguire
3. **running**: Il processo che si trova nella code dei processi viene scelto dal sistema operativo e viene eseguito 
4. **blocked**: il processo in stato di running esegue una chiamata di input/output molto lenta, il processo è bloccato perché sta aspettando la risposta di questa chiamata,  quello che succede praticamente è che il sistema operativo lo tira fuori dalla coda dei processi a causa di questa cosa quest'ultimo entra nello stato di blocked, appena la chiamata di sistema rientra il processo diventa ready.
5. **terminated**: il processo ha finito, tutte le sue risorse sono state liberate.


Se un processo non effettua operazioni di I/O rischia di monopolizzare la CPU. Per evitare che questo accada esiste la **prelazione**: un'operazione tramite la quale il Sistema Operativo sposta il processo dallo stato di _running_ a quello di _ready_. Questo avviene quando il processo ha esaurito la quantità massima di tempo CPU che gli era stata assegnata, ed è innescato direttamente tramite un *interrupt*.

quando cambia il processo in esecuzione parliamo di cambio di contesto di esecuzione, questo viene fatto dall'operazione di **dispatch**(da approfondire)

###### Tabella dei processi
All'interno della tabella dei processi troviamo vari PCB, in un pcb come dicevamo prima troviamo le seguenti informazioni (vedi slide)
	Queste informazioni vengono usate in diversi modi, sopratutto nella gestione degli interrupt.  Di seguito la gestione degli interrupt per il passaggio da un processo ad un altro:
- salvataggio nello stack del PC e del PSW nello stack attuale;
- caricamento dal vettore degli interrupt l'indirizzo della procedura associata;
- salvataggio registri e impostazione di un nuovo stack;
- esecuzione procedura di servizio per l'interrupt;
- interrogazione dello scheduler per sapere con quale processo proseguire;
- ripristino dal PCB dello stato di tale processo (registri, mappa memoria);
- ripresa nel processo corrente.


> [!TIP]
> Il **PSW** (acronimo di **Program Status Word**, o a volte _Processor Status Word_) è un registro hardware fondamentale all'interno della CPU che descrive lo stato attuale del processore in un determinato istante.

###### Code e accodamento
Di seguito la gestione delle code all'interno della CPU durante l'esecuzione dei processi(vedi slide)

Vediamo che per ogni caso abbiamo abbiamo una coda:
- I/O queue/request: la coda di tutti i processi blocked a causa di operaizoni di input/output
- time slice expired: la coda di tutti quei processi che "consumano" tutta la time slice
- fork a child: qua troviamo tutti i processi che hanno bisogno di tempo per forkarsi 
vediamo che tutto converge nella coda dei processi ready, da qui il sistema operativo pesca il processo da eseguire

###### Thread
All'interno di un processo si possono avere più flussi di esecuzione, questi flussi sono i thread. Questo implica che la nostra CPU è formata da più CPU virtuali. Usare i thread ha dei benefici soprattutto durante lo stato "blocked" infatti al posto di bloccare tutto il processo si blocca solo lo specifico thread che fa l'operazione I/O.

Come possiamo notare un Thread è caratterizzato da:
- Program Counter, registri, stack, stato
e poi condivide tutto il resto con gli altri thread, nelle slide vediamo che sia il codice, i dati e il file vengono condivisi. La condivisione dei dati crea dei bug se il programmatore non è molto abile nella programmazione concorrente

> [!TIP] Vita del thread
> Possiamo dire che i thread vivono dentro lo stesso processo, in pratica condivido lo spazio di indirizzamento del processo.

**Tabella dei thread**: Ovviamente esiste una tabella dei thread che viene usata dalla CPU per quando ne esegue uno piuttosto che un'altro (questa tabella contiene una specie di PCB), quando passo da un thread ad un altro sto parlando cambio del contesto di esecuzione, questa operazione è più efficace nei thread piuttosto che nei processi, questo perché lo spazio di indirizzamento è in comune.
**Stati**: sono praticamente uguali a quelli dei processi (Running, Ready, Blocked)
**Operazioni**: sui thread possiamo fare diverse operazioni necessarie per gestirli
- *thread_create*: un thread ne crea un altro;
- *thread_exit*: il thread chiamante termina;
- *thread_join*: un thread si sincronizza con la fine di un altro thread, questa cosa è utile in alcuni casi, lo vedremo al lab.
- *thread_yield*: il thread chiamante rilascia volontariamente la CPU.


### Copy on write
Come accennavo, il kernel è pigro. Invece di duplicare subito gigabyte di RAM (che sarebbe lentissimo), usa il trucco del **Copy-on-Write (CoW)**.

- All'inizio, Padre e Figlio puntano alle **stesse pagine di memoria fisica**.

- Finché entrambi leggono soltanto i dati, non succede nulla.

- Nel momento esatto in cui uno dei due prova a modificare una variabile (scrivere in memoria), il SO interviene, crea una copia di quella specifica pagina di memoria e la assegna a chi ha tentato la modifica.

**In sintesi:** Hanno spazi di indirizzamento **logicamente identici** ma **fisicamente separati** non appena uno dei due prova a cambiare qualcosa.