# Sistemi Operativi e Architettura degli Elaboratori

## 1. Introduzione ai Sistemi Operativi

All'inizio i S.O. erano molto ingombranti e inaffidabili. Le macchine all'inizio erano troppo elementari e ci fu l'esigenza di semplificare le cose con l'astrazione. Con la nascita del PC e del codice, bisognava creare qualcosa che semplificasse l'utilizzo: così nascono i Sistemi Operativi (UNIX, LINUX, ecc.).

### Architettura di un calcolatore

I componenti principali sono collegati tra loro (tramite bus):

- **CPU**
    
- **Memory (RAM)**
    
- **Disk Controller**
    
- **USB Controller** (Mouse, Keyboard, Printer)
    
- **Graphics Adapter** (Monitor)
    

---

## 2. Il Processore e i Registri

Il funzionamento base del processore si divide in tre fasi: **FETCH**, **DECODE**, **EXECUTE**.

I registri principali della CPU sono:

- **Program Counter (PC)**: Serve ad indicare l'indirizzo dell'istruzione successiva da eseguire.
    
- **Stack Pointer (SP)**: Serve per puntare alla testa di uno stack, nel quale sono inseriti gli indirizzi di dove bisogna fare un "salto" nel programma. In particolare, vengono passati anche i dati utili che servono all'esecuzione del programma. L'insieme di questi dati è detto **FRAME DI ATTIVAZIONE** (gestito dalle istruzioni `CALL` e `RETURN`). È un registro della CPU.
    
- **Program Status Word (PSW)**: Altro registro della CPU che indica l'insieme di bit che rappresenta lo stato della CPU. 1 bit all'interno della PSW rappresenta la modalità (Kernel o Utente); quest'ultimo controlla anche la "violazione" di un'istruzione e l'interruzione del programma.
    

---

## 3. Ottimizzazione della CPU: Pipeline e Multithreading

### Pipeline e CPU Superscalare

- **Pipeline**: Divide il flusso di esecuzione della CPU. Ad esempio, mentre l'istruzione $m$ è in fase di _Execute_, l'istruzione $m+1$ è in _Decode_ e la $m+2$ è in _Fetch_.
    
- **CPU Superscalare**: Divide Fetch, Decode ed Execute e li invia in un buffer che gestisce le esecuzioni multiple in parallelo.
    

### Processori Multithreading

- All'interno, la CPU tiene lo stato di 2 thread.
    
- Non c'è un'esecuzione parallela vera e propria, e il S.O. non ne tiene conto.
    
- Questo avviene sfruttando i **tempi morti** della CPU. La CPU può spostarsi rapidamente da un processo a un altro. Se abbiamo 2 processi, abbiamo 2 set di registri all'interno della singola CPU per mantenere questi 2 contesti.
    
- _Parallelismo Hardware_: Se ho 2 processi e 2 core (CPU 1 e CPU 2, ciascuna coi propri registri), conviene mettere un processo in una CPU e uno nell'altra per sfruttare l'hardware.
    
- Nelle CPU che permettono di fare multithread, non ha senso aggiungere troppe CPU logiche perché creerebbero molti tempi morti.
    
- **Vantaggi**: Throughput, affidabilità, multicore, utilizzo GPU.
    

---

## 4. Modalità di Esecuzione e Passaggio di Contesto

La CPU ha due modalità: user e kernel
**User mode:**
È la modalità "ristretta" o "non privilegiata".
- **Chi la usa:** Qui vengono eseguiti tutti i normali programmi e applicazioni (il browser web, i videogiochi, Word, e anche l'interfaccia grafica stessa del S.O.).

- **Limiti:** I processi in User Mode sono tenuti "in gabbia". **Non possono** accedere direttamente all'hardware (memoria RAM, disco fisso, scheda di rete) e **non possono** eseguire istruzioni critiche della CPU (come disabilitare gli interrupt o spegnere la macchina).

- **Sicurezza:** Se un programma in User Mode va in crash o tenta di fare un'operazione non consentita, la CPU lo blocca immediatamente (generando un'eccezione, detta _Trap_) e passa il controllo al Sistema Operativo, che solitamente chiude il programma in errore senza intaccare il resto del sistema.
**Kernel mode:**
È la modalità "privilegiata" o di "sistema".
- **Chi la usa:** Qui gira esclusivamente il nucleo (kernel) del Sistema Operativo e i driver essenziali dei dispositivi.

- **Potere assoluto:** La CPU in Kernel Mode non ha alcuna restrizione. Può eseguire _qualsiasi_ istruzione hardware, accedere a _qualsiasi_ indirizzo di memoria e comandare direttamente le periferiche.

- **Rischi:** Proprio perché non ci sono barriere di sicurezza, se una porzione di codice in Kernel Mode va in errore (ad esempio un driver della scheda video scritto male), crolla l'intero sistema. È quello che causa il famoso _Blue Screen of Death_ su Windows o il _Kernel Panic_ su Linux e Mac.

Come avviene il passaggio da modalità User a Kernel? Tramite le **Chiamate di Sistema (System Call)** (ad esempio l'operazione `open`).

- La **TRAP** permette di "saltare" all'interno del S.O. (viene inserita dal compilatore nel kernel). Il rientro da questa TRAP (in modo simile alla `call`) ritorna al programma chiamante. La TRAP è sincrona, l'interrupt è asincrono.

**Flusso della System Call:**

1. **User Mode**: Il processo utente fa una `call`.
    
2. **Kernel Mode**: Scatta la `TRAP` -> Viene eseguita la system call.
    
3. **Return**: Ritorno dalla call (`return`) e ripresa in User Mode.
    
### Gli Interrupt

La CPU si sposta da una modalità all'altra a un certo punto tramite un **Interrupt**, che serve a fermare ciò che sta avvenendo (si passa in modalità Kernel).

- Questo è un interrupt hardware.
    
- Ogni interrupt ha il suo posto specifico in memoria così da sapere quando avviene (è gestito tramite indirizzi IP).
    
- Un interrupt può avvenire anche mentre si è già in modalità Kernel (es. si passa a una sottomodalità kernel).
    

---

## 5. Gerarchia delle Memorie

- **Registri**: Velocissimi, implementati direttamente sul chip della CPU, capienza molto limitata.
    
- **Cache**: Viene organizzata in "linee" formate da blocchi (es. 64 byte). Una linea viene portata nella cache dalla RAM quando la CPU la usa. La CPU prima chiede alla cache se è presente la "word" (parola) di cui ha bisogno:
    
    - **Cache Hit**: Se è presente, la preleva con il tempo di lavoro della cache (molto veloce), guadagnando in efficienza.
        
    - **Cache Miss**: Se non è presente, la CPU dovrà prenderla dalla memoria centrale (RAM) per poi sovrascriverla nella cache (può succedere per caricare word vicine).
        
    - Lo spazio della cache è limitato. È più lenta dei registri ma molto più veloce della RAM.
        
    - _Livelli_: **Cache L1** (piccolissima, costosa, lavora a stretto contatto con la CPU) e **Cache L2** (più grande, dedicata o condivisa).
        
- **RAM**: Memoria volatile, lavora con la CPU, ha dimensioni superiori. Ha dei "tempi morti" (es. il tempo per prelevare un'informazione). Essendo volatile, ha bisogno di una memoria di appoggio (i dischi).
    

### I Dischi

- **Dischi Magnetici (HDD)**: Leggono e scrivono dati utilizzando il magnetismo.
    
- **Dischi Elettronici (SSD)**: Non hanno parti mobili, utilizzano memoria flash.
    
- **Dischi Ottici**: Dati scritti/letti sul disco con un laser che rileva i solchi o le zone piatte.
    

---

## 6. Gestione dell'I/O (Input/Output)

Quando il processore deve aspettare dati dal disco magnetico, si crea un **Bottle-neck** (collo di bottiglia).

- **Controller**: Fa da "ponte" tra la CPU e una periferica.
    
    - _Es. Dischi SATA_: Quando la CPU salva un file, il controller si occupa di trovare spazio sul disco, gestire gli errori e confermare l'operazione. L'interfaccia del controller è formata da una serie di richieste che il software può fare per leggere/scrivere blocchi.
        
- **Driver**: Componente software che fornisce un'interfaccia. Assolve alle operazioni del S.O., ma deve "parlare la stessa lingua" del controller per potervi dialogare.
    
- **Porte IN / OUT**: Permettono di leggere e scrivere per comunicare con il controller. Possono essere scritte tramite istruzioni privilegiate (modalità Kernel).
    
- **MMU (Memory Management Unit)**: Il S.O. può istruire un controller che riceve gli indirizzi da leggere/scrivere e li inoltra alla RAM (**Mappatura in memoria**). Qui entra in gioco la sicurezza: ogni processo ha la sua area di lavoro per evitare violazioni.
    

### Polling vs Interrupt vs DMA

Se il S.O. usa la CPU per leggere le porte aspettando la risposta (polling), la CPU si blocca e viene sprecata. Per evitare questo:

1. **Interrupt nel Controller**: La richiesta per un dispositivo viene accodata. La CPU istruisce il controller tramite il driver e poi passa ad altri processi. Quando il controller ha finito, genera un Interrupt per avvisare la CPU dell'esito. Il S.O. si riattiva, prende i blocchi e risveglia il processo che era in attesa.
    
    - _Regola d'oro_: Minore è il tempo che la CPU impiega per far funzionare il S.O. (overhead), migliore è il sistema.
        
2. **DMA (Direct Memory Access)**: Viene utilizzato per togliere ulteriore lavoro alla CPU. In fase di lettura/scrittura (prima dell'interrupt), il controller DMA si occupa di trasferire i dati direttamente tra il disco e la RAM, scavalcando la CPU.