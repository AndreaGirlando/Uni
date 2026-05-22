### La memoria
###### Introduzione alla gerarchia della memoria
I moderni sistemi informatici adottano una **gerarchia della memoria** per bilanciare costi e prestazioni. Questa struttura si articola solitamente in tre livelli:
- **Memoria molto veloce:** Pochi megabyte, estremamente costosa e volatile.
- **Memoria di medio costo:** Qualche gigabyte, abbastanza veloce e volatile (RAM).
- **Memoria su disco:** Alcuni terabyte, non volatile, lenta ma a basso costo.
**Gestore della memoria:** È la componente del sistema operativo incaricata di gestire questa gerarchia.

Storicamente, dai primi _mainframe_ (prima del 1960) fino ai primi _personal computer_ (prima del 1980), non esisteva alcuna astrazione della memoria. Ogni programma interagiva direttamente con la **memoria fisica**. In questo scenario, il modello presentato al programmatore è un insieme di indirizzi che vanno da 0 a un limite massimo. In assenza di astrazione, non è possibile eseguire due programmi contemporaneamente: se un programma scrivesse in una posizione usata da un altro, ne cancellerebbe i dati. Esistono tre varianti principali per l'organizzazione del sistema operativo in questo modello:
1. **S.O. in RAM:** Il sistema operativo risiede nel fondo della memoria nella **RAM (Random Access Memory)**.
2. **S.O. in ROM:** Il sistema operativo si trova in cima alla memoria nella **ROM (Read Only Memory)**.
3. **Modello Ibrido:** I driver dei dispositivi risiedono nella ROM in cima alla memoria, mentre il resto del sistema è nella RAM sottostante. Questo modello è tipico dei primi PC con MS-DOS, dove la parte in ROM è nota come **BIOS (Basic Input Output System)**.
![[Pasted image 20260501104611.png|500]]
###### Esecuzione di molteplici programmi senza astrazione
È possibile ottenere un certo grado di parallelismo anche senza astrazione, seguendo diverse strategie:
- **Programmazione con thread**: Un metodo per avere parallelismo è utilizzare molteplici _thread_ all'interno dello stesso contesto di memoria. Essendo thread fanno parte dello stesso processo, quindi non è una vera esecuzione di più programmi.
- **Swapping (Versione primitiva)**: Un'altra possibilità è eseguire un programma alla volta, salvando l'intero contenuto della memoria su disco quando si passa al processo successivo. Finché risiede un solo programma in memoria, non si verificano conflitti.
- **Protezione tramite chiavi (IBM 360):** Con l'ausilio di hardware speciale, è possibile far risiedere più programmi contemporaneamente. L'IBM 360 utilizzava una **chiave di protezione** di 4 bit per ogni cella di memoria. La PSW di un processo conteneva conteneva una chiave di 4 bit che gli permetteva di interagire con la locazione di memoria a lui assegnata. L'hardware intercettava ogni tentativo di accesso alla memoria: se il codice di protezione del processo non coincideva con la chiave nella PSW, l'accesso veniva bloccato.

###### Il problema della rilocazione
Anche se i programmi sono protetti dalle chiavi, sorge il problema degli indirizzi assoluti. Se due programmi da 16 KB vengono caricati uno sopra l'altro, il secondo (caricato all'indirizzo 16.384) fallirà se tenta di eseguire un salto relativo al proprio inizio (es. `JMP 28`), poiché finirà per saltare a un indirizzo nel primo programma invece che nel proprio. In questo esempio vediamo esattamente questa cosa, dopo aver caricato il processo a e b in memoria (c) possiamo notare che:
- *processo A*: il jump 24 funzionerà bene e il processo finisce in modo corretto
- *processo B*: il jump 28 cercherà di saltare ma entra nella memoria del primo processo e andrà in errore
![[Pasted image 20260501105311.png|500]]

Una soluzione a questo problema è la **rilocazione statica:** consiste nel modificare il programma direttamente durante il caricamento in memoria, aggiungendo l'indirizzo di partenza (es. 16.384) a ogni indirizzo del programma. Funzionava in questo modo: quando un programma era caricato all'indirizzo 16.384, la costante 16.384 era aggiunta a ogni indirizzo del programma durante il processo di caricamento. Anche se questo meccanismo funziona bene se eseguito in modo corretto, ma non è una soluzione in generale e rallenta il caricamento.
### L'astrazione della memoria: lo spazio degli indirizzi
Esporre la memoria fisica presenta due gravi inconvenienti:
1. I programmi utente possono distruggere il sistema operativo.
2. È difficile gestire l'esecuzione contemporanea di più programmi.

Per risolvere i problemi di **protezione** e **riposizionamento**, è stata introdotta l'astrazione chiamata **spazio degli indirizzi**. Lo **spazio degli indirizzi:** è l'insieme degli indirizzi che un processo può utilizzare per indirizzare la memoria. Per rendere possibile questa astrazione virtuale in prima battuta facciamo uso della tecnica della rilocazione dinamica
###### Rilocazione dinamica: registri base e limite
La **rilocazione dinamica**, mappa lo spazio degli indirizzi di ogni processo su porzioni diverse di memoria fisica tramite hardware speciale, ovvero attraverso due registri della CPU:
- **Registro Base:** Contiene l'indirizzo fisico di partenza del programma in memoria.
- **Registro Limite:** Contiene la lunghezza del programma.
Quando un processo accede alla memoria, l'hardware esegue due passaggi automatici:
1. **Somma:** Aggiunge il valore del registro base all'indirizzo generato dal programma prima di inviarlo al bus.
2. **Controllo:** Verifica se l'indirizzo è uguale o maggiore del valore nel registro limite; in tal caso, genera un errore e interrompe l'accesso.
Su questa soluzione possiamo dire che:
- **Vantaggi:** Permette a ogni processo di avere uno spazio privato degli indirizzi in modo semplice.
- **Svantaggi:** Ogni riferimento alla memoria richiede una somma e un confronto, il che può rappresentare un onere computazionale.

![[Pasted image 20260501163345.png|700]]
###### Gestione del sovraccarico di memoria
Spesso la quantità totale di RAM richiesta dai processi in esecuzione supera la memoria fisica effettivamente disponibile. Per gestire questo scenario, i sistemi operativi hanno storicamente adottato due strategie principali:
1. **Swapping:** Consiste nello spostare interamente su disco i processi temporaneamente inattivi per fare spazio ad altri.
2. **Memoria virtuale:** Un'evoluzione successiva che consente l'esecuzione di programmi caricandone in RAM solo le parti strettamente necessarie.
###### Lo Swapping e la Frammentazione
Immaginiamo di avere due programmi, $P_1$ e $P_2$. Attualmente $P_1$ è in esecuzione, ma vogliamo eseguire anche $P_2$. Purtroppo, la memoria centrale (RAM) è piena. A questo punto interviene il componente del sistema operativo chiamato **swapper**: esso esegue uno _swap-out_ (sposta $P_1$ dalla RAM al disco) e uno _swap-in_ (carica $P_2$ dal disco alla RAM). Il disco viene quindi usato come "memoria secondaria" di appoggio. Il processo $P_1$, finché si trova su disco, è penalizzato poiché non riceve risorse dalla CPU. Sebbene sembri una soluzione perfetta, lo swapping continuo di programmi di dimensioni diverse crea un grave problema: la **frammentazione della memoria** . Ne esistono due tipi:
- **Frammentazione Interna:** Si verifica quando a un processo viene assegnata un'area di memoria leggermente più grande delle sue reali esigenze. Lo spazio extra all'interno di quell'area allocata rimane inutilizzato e sprecato.
- **Frammentazione Esterna:** Si verifica quando la memoria totale libera sarebbe sufficiente per ospitare un nuovo processo, ma è suddivisa in tanti piccoli blocchi non contigui (buchi). Poiché il processo necessita di memoria contigua, non può essere caricato. L'unica soluzione è la **Memory Compaction** (Compattazione della memoria): il S.O. sposta fisicamente tutti i processi attivi verso il fondo della memoria per unire tutti i "buchi" in un unico grande spazio libero in cima. È una procedura estremamente lenta e si cerca di evitarla il più possibile.
###### Il problema dell'Allocazione con Dimensione Dinamica
La gestione della frammentazione è ulteriormente complicata dal fatto che i processi non hanno sempre dimensioni fisse. Durante l'esecuzione, i dati di un programma possono crescere (ad esempio, allocando memoria dinamicamente). La struttura ottimale per gestire la crescita dinamica all'interno di un processo prevede due segmenti mobili:
- **Segmento Dati (Heap):** Posizionato subito dopo il codice statico del programma, cresce verso l'alto.
- **Segmento Stack (per variabili locali e ritorni):** Posizionato in cima all'area di memoria allocata per il processo, cresce verso il basso.
![[Pasted image 20260501112958.png|500]]
Se questi due segmenti crescono fino a scontrarsi, il processo ha finito lo spazio. Come interviene il S.O.?
- _Soluzione 1 (Sospensione):_ Se non c'è spazio adiacente in RAM per far crescere il processo e l'area di swap su disco è piena, il processo deve essere sospeso o terminato.
- _Soluzione 2 (Pre-allocazione):_ Una strategia preventiva. Quando il S.O. carica o sposta un processo, gli assegna preventivamente un "cuscinetto" di memoria extra, prevedendone la crescita. Tuttavia, se la crescita non avviene, questa memoria extra rimane sprecata (causando frammentazione interna).

###### Tenere traccia della memoria: Bitmaps e Liste
A causa dello swapping e delle dimensioni variabili dei processi, la memoria fisica diventa rapidamente un puzzle disordinato di "blocchi occupati" alternati a "buchi liberi". **Il Sistema Operativo ha quindi bisogno di strumenti per ricordarsi esattamente quali parti di RAM sono occupate e quali sono libere.** Utilizza principalmente due tecniche:

**A. Gestione con Bitmap**
La memoria viene idealmente divisa in "unità di allocazione" (che possono andare da pochi byte a vari kilobyte). La **Bitmap** è una lunga mappa in cui ogni bit rappresenta un'unità: `0` significa libera, `1` significa occupata (o viceversa).
- _Il parametro cruciale:_ La dimensione dell'unità di allocazione. Se scegliamo unità molto piccole (es. 4 byte), avremo una mappa enorme (per mappare 32 bit di memoria ci vorrà 1 bit di mappa).
- _Vantaggi:_ La dimensione della bitmap è fissa e dipende solo dalla quantità totale di RAM e dalla dimensione scelta per l'unità.
- _Svantaggi:_ Quando bisogna caricare un nuovo processo che richiede _k_ unità contigue, il S.O. deve scansionare la lunghissima sequenza di bit per cercare una stringa ininterrotta di _k_ zeri. Questa ricerca è estremamente lenta.
![[Pasted image 20260501170015.png|500]]
**B. Gestione con Liste Collegate**
Invece di mappare ogni singolo blocco, il S.O. mantiene una lista dinamica (Linked List) che mappa interi segmenti . Ogni nodo (voce) della lista descrive un blocco contiguo, e contiene:
1. Il tipo: Processo occupato (`P`) o Buco vuoto (`H` - _Hole_).
2. L'indirizzo fisico di partenza.
3. La lunghezza del blocco.
4. Il puntatore al segmento successivo.
La lista è ordinata in base all'indirizzo fisico crescente. 
![[Pasted image 20260501170052.png|500]]
Il momento più delicato in questo sistema è **quando un processo termina** o viene "swappato". Il suo segmento `P` diventa un segmento `H`. A questo punto, il S.O. deve guardare i segmenti vicini per evitare la frammentazione, potendo incontrare 4 casistiche:
- _(a) Nessun vicino vuoto:_ Si aggiorna semplicemente il nodo da `P` ad `H`.
- _(b) Vicino vuoto sopra:_ Il nuovo buco e quello precedente vengono fusi. La lista si accorcia di una voce.
- _(c) Vicino vuoto sotto:_ Il nuovo buco e quello successivo vengono fusi. La lista si accorcia di una voce.
- _(d) Entrambi i vicini vuoti:_ Si fondono tre buchi adiacenti in un unico grande spazio vuoto. Vengono eliminati due elementi dalla lista.
![[Pasted image 20260501170129.png|500]]

###### Algoritmi di allocazione: Come scegliere il "buco" giusto?
Quando arriva un nuovo processo, il gestore della memoria deve scorrere la lista collegata per trovargli un buco adeguato. Ma quale sceglie se ce n'è più di uno? Usa degli specifici algoritmi:
1. **First fit (Primo incastro):** È il più semplice e veloce. Scorre la lista dall'inizio e prende il _primo_ buco abbastanza grande. Se il buco è più grande del processo, viene diviso in due: una parte per il processo e una per il buco residuo.
2. **Next fit (Incastro successivo):** Identico al First fit, ma "si ricorda" dove aveva trovato l'ultimo spazio. La ricerca successiva riparte da quel punto invece che dall'inizio. Previene l'accumulo di piccoli buchi tutti all'inizio della memoria.
3. **Best fit (Miglior incastro):** Cerca in _tutta_ la lista e sceglie il buco più piccolo tra quelli in grado di contenere il processo.
    - _Svantaggio:_ È più lento (deve scorrere tutta la lista) e paradossalmente genera un enorme spreco di memoria: crea tantissimi microscopici "buchini" residui, inutilizzabili per qualsiasi altro processo.
4. **Worst fit (Peggior incastro):** Nasce per risolvere i difetti del Best fit. Cerca in tutta la lista e sceglie intenzionalmente il buco _più grande in assoluto_. L'idea è che il buco residuo che avanzerà sarà ancora abbastanza grande da poter ospitare altri processi in futuro.

> [!TIP]
> Per velocizzare queste ricerche, i progettisti hanno ideato tre strategie di ottimizzazione:
> - **Liste separate:** Invece di una lista mista, si usano due liste distinte: una solo per i processi e una solo per i buchi vuoti. Così gli algoritmi scansionano solo i buchi, risparmiando tempo.
> - **Ordinamento per dimensione:** La lista dei buchi viene ordinata dal più piccolo al più grande. Questo trasforma il _Best fit_ in un algoritmo velocissimo: il primo buco utile che incontra è per forza di cose il più piccolo adatto (quindi il migliore).
>     - _Svantaggio dell'ordinamento:_ Quando un processo termina, ritrovare i suoi vicini "fisici" per unire i buchi (le casistiche a,b,c,d viste prima) diventa un incubo computazionale, perché la lista non è più ordinata per posizione.

5. **Quick fit:** Usa array o tabelle che puntano a liste di buchi di dimensioni standardizzate e molto richieste (es. una lista solo per buchi da 4 KB, un'altra per buchi da 8 KB, ecc.).
    - _Vantaggio:_ Allocazione praticamente istantanea se il processo richiede una misura standard.
    - _Svantaggio:_ Come per l'ordinamento per dimensione, la deallocazione e la fusione dei buchi adiacenti restano operazioni molto dispendiose.
### La memoria virtuale
Come abbiamo visto, gestire "buchi" di memoria di dimensioni variabili (tramite liste e algoritmi di allocazione) è complesso e non risolve mai del tutto il problema della frammentazione. Per eliminare definitivamente questo ostacolo, l'informatica ha introdotto un'astrazione rivoluzionaria: la **memoria virtuale**.

L'obiettivo di questa astrazione è creare un'illusione perfetta: far credere a ogni programma in esecuzione di disporre di un'intera memoria centrale privata, continua e protetta. Con questa tecnica, lo spazio di memoria originario diventa uno **spazio di indirizzamento virtuale**, il quale viene suddiviso in piccoli blocchi di dimensione fissa chiamati **pagine**.

La caratteristica cruciale della memoria virtuale è che **non tutte le pagine di un programma devono risiedere contemporaneamente nella memoria fisica (RAM)** per poterne permettere l'esecuzione. Le pagine virtuali vengono mappate sulla memoria fisica in modo dinamico:
- **Accesso diretto:** Quando il programma fa riferimento a un indirizzo che fa parte di una pagina attualmente caricata nella memoria fisica, l'hardware esegue il mapping in modo diretto e istantaneo.
- **Recupero dal disco:** Quando, al contrario, il programma fa riferimento a uno spazio degli indirizzi che non è al momento presente nella memoria fisica, l'hardware genera un'interruzione. Il sistema operativo viene allertato per andare a recuperare il "pezzo" mancante dal disco (memoria secondaria), caricarlo in RAM, e infine rieseguire l'istruzione che era fallita.

###### La Paginazione (Paging) e la MMU
La paginazione ci permette quindi di suddividere la memoria fisica da quella virtuale associata ad ogni processo infatti quando un programma esegue un'istruzione come:
```
MOV REG,1000 // muove quello che c'è all'indirizzo 1000 dentro REG
```
 Per eseguirla deve accedere prima alla memoria e lo fa generando degli indirizzi detti **indirizzi virtuali** (l'insieme di questi indirizzi forma lo **spazio virtuale degli indirizzi** che sarebbero l'insieme degli indirizzi a disposizione di un processo). Gli indirizzi virtuali generati dalla CPU non vanno direttamente al bus di memoria ma passano prima attraverso un componente hardware dedicato chiamato **MMU (Memory Management Unit)** che consiste in un unità di gestione della memoria che ha il compito di mappare gli indirizzi virtuali sugli indirizzi di memoria fisica.
![[Pasted image 20260503161434.png|500]]
###### Pagine e frame
Le unità base della gestione della paginazione sono:
- **Pagine:** unità di dimensione fissa in cui è suddiviso lo spazio degli indirizzi virtuali.
- **Frame:** Unità di memoria della memoria fisica (RAM). 
![[Pasted image 20260503161516.png|400]]

> [!EXAMPLE]
> Prendendo ad esempio pagine da $4 KB$ (coma da img):
> - L'intervallo segnato come $0K-4K$ significa che gli indirizzi virtuali in quella pagina vanno dall'indirizzo $0$ all'indirizzo $4095$.
> - L'intervallo $4K-8K$ si riferisce agli indirizzi che vanno da $4096$ a $8191$, e così via.
> - Di conseguenza, ogni pagina contiene esattamente $4096$ indirizzi, che partono da un multiplo di $4096$ fino al multiplo di $4096$ successivo.

La maggior parte delle volte abbiamo **molte più pagine virtuali che pagine fisiche**, questo perché quella virtuali possono risiedere anche in disco. Per gestire questa cosa nella tabella degli indirizzi è presente un **bit presente/assente**, il quale tiene traccia di quali pagine sono fisicamente presenti in memoria. Quando cerchiamo di indirizzare un indirizzo non mappato nella memoria fisica viene sollevato dalla CPU un trap verso il sistema operativo detto **page fault**. Quando accade il sistema operativo interviene prelevando frame poco utilizzato e ne scrive il suo contenuto su disco (se il dirty bit è true), fatto ciò inserisce l'indirizzo del frame di memoria richiesto dentro la mappatura dell'MMU e riavvia l'istruzione che era andata in trap.

> [!EXAMPLE]
> Esempio con un istruzione reale prendendo in considerazione la tabella degli indirizzi dell'immagine precedente:
> 1. *Tentativo di accesso*: La CPU esegue `MOV REG, 32780`, chiedendo di accedere alla Pagina virtuale 8.
> 2. *Page Fault*: La MMU consulta la _Page Table_, vede che la Pagina 8 non è in RAM (bit assente) e genera un'interruzione (trap) verso il Sistema Operativo.
> 3. *Swap-Out*: Il Sistema Operativo libera spazio in RAM: prende un _frame_ usato poco e lo copia su disco.
> 4. *Swap-In*: Il Sistema Operativo preleva la Pagina 8 dal disco e la scrive nel _frame_ appena liberato in RAM, e aggiorna la usata dall'MMU.
> 5. *Riavvio*: La CPU ripete l'istruzione `MOV REG, 32780`. Questa volta la MMU trova la pagina e l'operazione va a buon fine.

###### Il processo di traduzione 
Per tradurre un indirizzo virtuale in indirizzo fisico la CPU esegue uno specifico processo, prendendo in esame l'istruzione:

```
MOV REG,0 //mette quello che c'è all'indirizzo 0 in REG
```

Viene eseguita in questo modo
1. L'indirizzo virtuale 0 viene inviato alla **MMU**.
2. La **MMU** vede che questo indirizzo virtuale cade nella pagina 0 (che copre gli indirizzi da 0 a 4095).
3. Secondo il mapping interno della MMU, la pagina 0 corrisponde al frame 2 (che copre gli indirizzi fisici da 8192 a 12287).
4. La **MMU** trasforma così l'indirizzo virtuale 0 nell'indirizzo fisico 8192 e lo invia esternamente sul bus.

*Risultato:* La MMU ha effettivamente mappato tutti gli indirizzi virtuali compresi fra 0 e 4095 sugli indirizzi fisici che vanno da 8192 a 12287.

###### Come si comporta la MMU

> [!attention] La tabella delle pagine
> Di seguito nomineremo spesso la tabella delle pagine, ci basta sapere che è una tabella che contiene informazioni riguardo ogni pagina come i bit presente/assente e l'indirizzo fisico del frame alla quale è mappata quella pagina

Gli indirizzi virtuali generati dalla CPU sono così formati:
- **numero di pagina**: questi sono gli $m$ bit più significativi dell'indirizzo virtuale e ci indicano quale pagina guardare per trovare il nostro indirizzo (il numero di pagine totali è $2^m$)
- **offset**: questi sono gli $n$ bit meno significativi che ci indicano quale indirizzo prendere tra quelli disponibili nella singola pagina. ($2^n$ sono gli indirizzi contenuti da una pagina)

> [!TIP] Esercizio di esame
> Dato un indirizzo virtuale dobbiamo fare la seguente cosa per tradurlo in indirizzo fisico:
> Supponiamo di avere una RAM a $32$ kilobyte, e di voler accedere all'indirizzo virtuale $v = 8196$. 
> Con $\text{dimensione dei frame} = 4096$, effettuiamo: $$\frac{8196}{4096} = \begin{cases} 2 \text{ (Numero di Pagina)} \\ 4 \text{ (Offset)} \end{cases}$$
> Supponiamo che nella nostra tabella delle pagine, la pagina $2$ è associata al frame $6$. 
> Moltiplichiamo adesso $6 \cdot \text{dimensione dei frame} = 6 \cdot 4096 = 24576$. 
> Otterremo quindi il primo indirizzo fisico appartenente al frame 6. Sommiamo l'offset ottenuto in precedenza, $24576 + 4 = 24580$. 
> 

Scendendo nel dettaglio di cosa fa l'MMU possiamo dire che: il processo di traduzione viene eseguito in  maniera più veloce e intuitiva. La divisione è sempre di potenze di 2, in quanto strettamente legata alla dimensione dei frame. Sarà quindi possibile implementarla con uno shift. Nello specifico segue questi step (input: *indirizzo virtuale*):
1. **Estrazione del numero di pagina (Quoziente):** Viene eseguito uno shift logico verso destra di $n$ bit sull'indirizzo virtuale.
    _Formula:_ `NumeroPagina = VA >> n`
2. **Estrazione dell'offset (Resto):** Viene eseguito un AND logico tra l'indirizzo virtuale e una maschera composta da $n$ bit a 1.
    _Formula:_ `Offset = VA AND ((1 << n) - 1)`
3. **Consultazione della tabella delle pagine:** L'hardware usa il `NumeroPagina` appena trovato come indice per cercare nella tabella delle pagine il `NumeroFrame` corrispondente (se la pagina è in RAM).
4. **Allineamento del frame:** Il `NumeroFrame` trovato viene shiftato verso sinistra di $n$ bit. Questo crea lo spazio per inserire l'offset e, matematicamente, equivale esattamente a calcolare $\text{numeroFrame} \times 2^n$.
    _Formula:_ `IndirizzoBaseFisico = NumeroFrame << n`
5. **Composizione dell'indirizzo fisico:** Si esegue un OR logico (che in questo caso equivale a una somma, dato che i bit inferiori dell'indirizzo base sono tutti zeri) tra l'indirizzo base fisico e l'offset.
    _Formula:_ `IndirizzoFisico = IndirizzoBaseFisico OR Offset`

> [!TIP] Esercizio di esame
> * Virtual memory = 4Mb
> * voci tabella pagine = $2^{13}$
> * Numero di frame a 8bit
> 
> Quanta RAM ho? Avendo 4Mb = $2^{22}$byte di virtual memory, con $\frac{2^{22}}{2^{13}}$ avrei la dimensione della singola pagina, ovvero $2^9$.
> 
> $$2^9byte \cdot 2^8 \text{ (numero di frame)} = 128kb$$

###### La tabella delle pagine
La tabella delle pagine è una tabella utilizzata dall'MMU insieme al sistema operativo per tradurre da indirizzi virtuali a fisici, l'esatto layout di una voce di una singola tabella della pagina dipende molto dalla macchina su cui si opera. Tuttavia, il tipo di informazioni presenti è più o meno lo stesso per tutte le architetture. Di seguito una rassegna dei campi contenuti in una voce:
- **Numero del frame (frame number):** È il campo più importante in assoluto, in quanto indica l'indirizzo fisico in cui si trova la pagina.
- **Bit Presente/Assente:** Se questo bit è 1, la voce è valida e può essere utilizzata normalmente. Se è 0, significa che la pagina virtuale cui appartiene la voce non è effettivamente in memoria in quel momento.
- **Protezione:** Specifica quali tipi di accesso sono consentiti per quella pagina. Nella sua forma più basilare, questo campo contiene 1 solo bit: il valore 0 significa lettura/scrittura consentita, mentre il valore 1 indica l'accesso in sola lettura.
- **Bit Modificato (Dirty bit):** Tiene traccia dell'uso della pagina. Se la pagina è stata modificata rispetto alla sua versione in disco (cioè è considerata "sporca"), questo bit è impostato. Se la pagina non è stata modificata (cioè è considerata "pulita"), in caso di sfratto il suo contenuto può essere semplicemente abbandonato senza sovrascriverlo, poiché la copia originaria presente sul disco è ancora perfettamente valida.
- **Bit Referenziato:** È impostato dall'hardware ogni qualvolta si faccia riferimento alla pagina, sia per un'operazione di lettura sia in scrittura. Serve ad aiutare il sistema operativo a scaricare (cioè a "sfrattare") una pagina quando si verifica un page fault. Le pagine inutilizzate (non referenziate) sono le candidate migliori per lo sfratto rispetto a quelle usate di recente.    
- **Disabilitazione della cache:** L'ultimo bit consente di disabilitare la cache per la specifica pagina. Questo è fondamentale per l'I/O: fa in modo che la macchina debba prelevare la parola direttamente da quel dispositivo hardware, senza rischiare di usare una vecchia parola non aggiornata messa precedentemente in cache.

###### Problemi principali della paginazione
Nei sistemi operativi, la gestione della memoria tramite paginazione impone due sfide architetturali critiche e diametralmente opposte:
- **Velocità di traduzione:** La mappatura dall'indirizzo virtuale a quello fisico deve essere quasi istantanea. Poiché questa operazione avviene per _ogni singolo_ riferimento alla memoria, un minimo ritardo genera un collo di bottiglia per l'intero sistema.
- **Dimensione delle tabelle:** Con i moderni spazi di indirizzamento a 64 bit, il numero di pagine virtuali è immenso, rendendo le relative Tabelle delle Pagine (Page Table) enormi e ingombranti.
La necessità di avere un meccanismo che sia **contemporaneamente gigantesco e ultra-veloce** rappresenta un ostacolo storico per i progettisti. Dal punto di vista concettuale, il problema si scontra con due approcci estremi, nessuno dei quali è praticabile da solo.
1. Nel **primo approccio (basato sull'hardware)**, l'intera tabella delle pagine viene memorizzata in un array di registri interni alla CPU. Durante l'esecuzione le prestazioni sono eccellenti, poiché il processore non deve mai accedere alla RAM per tradurre gli indirizzi. Tuttavia, i costi architetturali sono proibitivi: con le dimensioni delle tabelle moderne, i tempi e le risorse necessarie per aggiornare milioni di registri a ogni _context switch_ paralizzerebbero il sistema.
2. All'**estremo opposto (approccio in memoria)**, l'intera tabella viene mantenuta esclusivamente nella RAM. In questo scenario all'hardware basta un singolo registro dedicato, il **PTBR** (_Page Table Base Register_), che punta all'inizio della tabella del processo in esecuzione. Se da un lato il _context switch_ diventa istantaneo (è sufficiente aggiornare il valore del PTBR) e si risolvono i limiti di spazio, dall'altro la lentezza diventa inaccettabile: ogni singola istruzione richiederebbe un accesso extra alla RAM solo per consultare la tabella, dimezzando di fatto le prestazioni del computer.
### Translation Lookaside Buffer (TLB)
Per bilanciare velocità e dimensioni, la soluzione escogitata è stata quella di equipaggiare i computer di un piccolo dispositivo *hardware* dedicato esclusivamente a mappare gli indirizzi virtuali sugli indirizzi fisici senza dover passare ogni volta dalla tabella delle pagine in memoria, questo dispositivo si chiama **TLB** Acronimo di **Translation Lookaside Buffer**, talvolta chiamato anche **memoria associativa**.
- **Capacità e Struttura:** Contiene solitamente poche voci, ciascuna voce contiene informazioni cruciali riguardo una pagina, tra cui: 
	- *il numero di pagina virtuale*
	- *un dirty bit*: quando avviene una modifica ad un record questo viene macchiato come dirty, quando questo succede e quel record deve essere eliminato dalla TLB la modifica deve essere riportata alla tabella delle pagine.
	- *il codice di protezione* (i permessi di lettura, scrittura ed esecuzione) 
	- *il frame fisico*
- **Funzionamento:** Quando un indirizzo virtuale viene presentato alla MMU per la traduzione, l'hardware per prima cosa guarda se il suo numero di pagina virtuale è presente nel TLB, confrontandolo simultaneamente (cioè in parallelo) con tutte le voci.
    - **TLB hit (successo di TLB):** Il numero di pagina viene trovato e la traduzione avviene istantaneamente.
    - **TLB miss (fallimento di TLB):** Avviene quando il numero di pagina virtuale non è nel TLB. In questo caso, la MMU rileva il miss e fa una normale ricerca sulla tabella delle pagine in memoria. Quindi sfratta una delle voci dal TLB e la rimpiazza con la voce della tabella delle pagine appena cercata e recuperata. In questo modo, se quella stessa pagina è riusata a breve termine, la seconda volta si avrà un successo (TLB hit).
- **Caratteristiche**: è importante dire che questa memoria hardware è comparabile ad una cache e la ricerca viene fatta su tutte le sue celle in modo parallelo, quindi è molto veloce.

###### Effective Access Time (EAT)
L'**Effective Access Time (EAT)**, o tempo di accesso effettivo, è una metrica fondamentale per valutare le prestazioni di un sistema di memoria con paginazione che utilizza un **Translation Lookaside Buffer (TLB)**. L'EAT ci permette di calcolare il tempo _medio_ ponderato di accesso alla memoria, tenendo conto del **TLB Hit Ratio** ($\varepsilon$), ovvero la percentuale di volte in cui la traduzione viene trovata con successo all'interno della TLB.

> [!EXAMPLE] Facciamo un esempio
> - tempo di accesso alla memoria: $\alpha = 100 \text{ ns}$
> - Tempo di accesso alla TLB: $\beta = 20 \text{ ns}$
> 
> I tempi effettivi?
> - Con un TLB hit abbiamo $100 + 20 = 120 \text{ ns}$.
> - Con un TLB miss abbiamo $2 \cdot 100 + 20 = 220 \text{ ns}$.
> 
> Con un ratio TLB = $\varepsilon$, tempo di accesso alla TLB = $\beta$ e tempo di accesso alla memoria $\alpha$ abbiamo
> $$\text{EAT} = \varepsilon(\alpha + \beta) + (1 - \varepsilon)(2\alpha + \beta)$$

###### Osservazioni importanti sulla TLB
Di seguito alcune osservazioni importanti sulla TLB:
- Alcuni attributi dei record delle tabelle delle pagine non sono presenti, come il bit di referenzialmento o di validità di allocazione. Osserviamo che, se un record è presente nella TLB, dev'essere per forza valido e referenziato.
- La TLB conterrà sempre record relativi a pagine utili per il programma attuale. Inoltre, quando avviene una TLB miss, si andrà ad aggiornare il valore sulla TLB.
- Alcuni voci possono essere vincolate ad essere nella TLB, migliorando le tempistiche.

Le tabelle delle pagine sono una per processo: ne consegue che gli stessi indirizzi virtuali possono essere riutilizzati per rifarsi a indirizzi fisici differenti. Tuttavia, la TLB è unica per la CPU (o il core). Detto ciò, a causa del riutilizzo degli indirizzi virtuali, bisogna avere un modo per disambiguare i record riguardanti ogni processo. Di seguito vediamo due strategie:
- **Flush totale della TLB a ogni context-switch:** Non ideale, favorisce un alto numero di cache miss iniziali.
- **Address-space ID:** Aggiungendo un identificatore, chiamato ASID, è possibile disambiguare le voci delle TLB con lo stesso indirizzo virtuale, ma appartenenti a processi differenti, favorendo cache hit ad ogni context switch.

La strategia migliore è la seconda. Complica un po' la ricerca, aggiungendo gli ASID alla ricerca del record nella TLB, ma è molto efficiente in ambienti multithread. È un ottimo compromesso.

###### Gestione TLB via software nelle architetture RISC
Finora si è supposto che ogni macchina con memoria virtuale paginata abbia delle tabelle delle pagine riconosciute direttamente dall'hardware, più un TLB. Nel passato questo assunto era valido. Tuttavia, molte macchine ad architettura RISC moderne eseguono quasi tutta questa gestione delle pagine tramite software.

Nella gestione del TLB via software, è fondamentale capire la differenza fra due tipi di miss:
- **Soft miss:** Avviene quando la pagina di riferimento non è nel TLB, ma si trova comunque all'interno della memoria RAM. La risoluzione è rapida.
- **Hard miss:** All'opposto, avviene quando la pagina stessa non è in memoria (e ovviamente nemmeno nel TLB). Per prendere la pagina serve un accesso al disco, il che comporta tempistiche di parecchi millisecondi. Questa situazione può esitare in un errore di **segmentazione (segmentation fault)**.

I TLB possono essere usati per velocizzare la traduzione dell'indirizzo virtuale nell'indirizzo fisico rispetto allo schema originale della "tabella-delle-pagine-in-memoria". Rimane però un altro problema aperto: *quale comportamento assumere con spazi degli indirizzi virtuali molto grandi?*

###### Tabelle delle pagine multilivello
La paginazione multilivello è una struttura gerarchica utilizzata dai sistemi operativi per tradurre gli indirizzi di memoria virtuale in indirizzi fisici riducendo drasticamente il consumo di RAM. 

Invece di mantenere in memoria un'unica, gigantesca tabella che mappa l'intero spazio virtuale a disposizione di un processo (anche le enormi porzioni vuote), si utilizza una tabella principale e compatta, chiamata _Page Directory_. 

Questa directory contiene semplicemente dei puntatori a svariate tabelle secondarie più piccole. Il grande vantaggio di questo approccio è che le tabelle secondarie vengono create e mantenute in RAM esclusivamente per le porzioni di memoria effettivamente utilizzate dal programma; le aree non allocate non richiedono alcuna tabella. 

Inoltre, se il sistema ha bisogno di liberare spazio, le tabelle secondarie non consultate da tempo possono essere temporaneamente spostate sul disco fisso, lasciando in memoria solo la essenziale directory principale.
![[Pasted image 20260503161749.png|500]]
- **Meccanismo a due livelli:** Quando viene presentato un indirizzo virtuale alla MMU, l'hardware sa che è composto da due sotto-indirizzi quindi per prima cosa estrae il primo campo (chiamato _PT1_) e usa questo valore come indice nella tabella delle pagine di livello più alto. Il secondo campo, _PT2_, adesso è usato come un indice nella tabella delle pagine di secondo livello (selezionata dal passo precedente) per cercare il numero di frame della pagina stessa.
- **Espansione dei livelli:** Possiamo aumentare il numero di livelli per supportare indirizzi molto grandi; questo ci permette di risparmiare memoria (tenendo su disco i livelli non usati) a discapito però della velocità, poiché sarà richiesto un accesso in più alla memoria RAM per ogni livello aggiunto alla gerarchia.
###### Tabelle delle pagine invertite
Un'alternativa al continuo aumento dei livelli nella paginazione gerarchica è rappresentata dalle **tabelle delle pagine invertite**. In questa architettura, il paradigma classico viene ribaltato: anziché mantenere una voce per ogni pagina dello spazio virtuale, la tabella contiene **una singola voce per ogni frame fisico** effettivamente presente nella memoria RAM.
Questo approccio comporta due conseguenze contrapposte:
- **Enorme risparmio di spazio:** La dimensione della tabella dipende unicamente dalla quantità di memoria fisica installata e non da quella virtuale. Questo è un vantaggio cruciale nei sistemi moderni, dove lo spazio di indirizzamento virtuale è enormemente più vasto della RAM disponibile.
- **Traduzione complessa e lenta**: Nelle tabelle tradizionali, la pagina virtuale _p_ funziona esattamente come l'indice di un array, consentendo un accesso diretto e immediato alla riga corrispondente per leggere il frame fisico. Nella tabella invertita, invece, la struttura cambia: le righe rappresentano i frame fisici e al loro interno viene annotato quale processo (_n_) (tramite ASID) e quale pagina virtuale (_p_) vi sono ospitati in quel momento. Di conseguenza, quando l'hardware ha bisogno di tradurre l'indirizzo, si ritrova in mano la coppia _(n, p)_ ma non sa a priori in quale riga sia scritta. Non potendo usare l'accesso diretto, è costretto a effettuare una vera e propria **ricerca per contenuto**, scansionando la tabella finché non trova la riga con l'esatta corrispondenza (il cui indice indica finalmente il frame fisico). Senza strutture aggiuntive, questa ricerca si tradurrebbe in innumerevoli e lenti accessi sequenziali alla RAM, paralizzando le prestazioni.

Per aggirare questo ostacolo prestazionale, il sistema fa un **impiego massiccio del TLB** (_Translation Lookaside Buffer_). Finché le pagine utilizzate più di frequente si trovano in questa memoria cache ultra-veloce, la traduzione avviene in modo istantaneo, esattamente come nelle architetture tradizionali. 

Il problema si pone in caso di _TLB miss_ (quando la pagina cercata non è nella cache), evento che costringe l'hardware a interrogare la grande tabella invertita in RAM. Per evitare di doverla scandire linearmente dall'inizio alla fine, la ricerca viene ottimizzata strutturando la tabella come una **hash table** basata sull'indirizzo virtuale, riducendo così drasticamente i tempi necessari per localizzare il frame fisico.

###### Cache della memoria vs Memoria virtuale
La cache della memoria può essere basata sugli indirizzi fisici, o sugli indirizzi virtuali. Ciò dipenderà rispettivamente, se posizioniamo l’MMU prima o dopo la cache.
- *Indirizzi fisici*:
  **Pro**: non servirà invalidare la cache sul context-switch. Avendo indirizzi fisici già tradotti nella cache, non si avranno problemi di ambiguità.
  **Contro**: l’MMU diventa un collo di bottiglia per la cache.
- *Indirizzi virtuali*.
  **Pro**: più veloce ed efficace 
  **Contro**: servono gli ASID per non invalidare la cache
![[Pasted image 20260516091408.png|700]]
**Soluzione effettiva**:
approccio ibrido La cache $L1$ basata su indirizzi virtuali, si pone prima dell’MMU, basandosi sugli indirizzi virtuali. La cache $L2$ e successive dopo l’MMU, basate su indirizzi fisici.

### Gestione della memoria virtuale e algoritmi di sostituzione delle pagine
Quando si verifica un **page fault**, il sistema operativo deve fare spazio alla pagina entrante scegliendo una pagina residente da sfrattare. Se la pagina scelta è stata modificata durante la sua permanenza, deve essere prima riscritta sul disco per mantenerne la copia aggiornata. Le prestazioni del sistema risultano ottimali se si sceglie di rimuovere una pagina non particolarmente utilizzata.

###### Algoritmo di Sostituzione Ottimale
Il miglior algoritmo di sostituzione delle pagine è puramente teorico. L'idea è etichettare ciascuna pagina in memoria con il numero di istruzioni da eseguire prima che venga referenziata nuovamente. Al momento del **page fault**, l'algoritmo rimuove la pagina con l'etichetta più alta. Questo approccio è irrealizzabile, poiché il sistema operativo non ha modo di sapere in anticipo quando le pagine verranno referenziate la volta successiva.

###### Not Recently Used (NRU)
Per raccogliere statistiche sull'uso delle pagine, l'hardware mette a disposizione due bit di stato associati a ciascuna voce della tabella delle pagine:
- **Bit R (_Referenced_):** Impostato a 1 quando si fa riferimento alla pagina (in lettura o scrittura).
- **Bit M (_Modified_):** Impostato a 1 solo quando la pagina viene scritta (modificata).

All'avvio, questi bit sono azzerati. Periodicamente (es. a ogni interrupt del clock), il **Bit R** viene ripulito per distinguere le pagine usate di recente da quelle inattive. Al verificarsi di un **page fault**, l'algoritmo NRU divide le pagine in quattro categorie in base ai valori attuali dei bit:
- Classe 0: non referenziato, non modificato.
- Classe 1: non referenziato, modificato.
- Classe 2: referenziato, non modificato.
- Classe 3: referenziato, modificato.

L'algoritmo rimuove una pagina a caso dalla classe non vuota con il numero più basso. È infatti preferibile rimuovere una pagina modificata ma non usata di recente, piuttosto che una pagina pulita ma usata frequentemente.
###### First-in, First-out (FIFO) e Seconda Chance
L'algoritmo **FIFO** tiene una lista delle pagine in memoria ordinandole per tempo di arrivo. A un **page fault**, rimuove semplicemente la pagina più vecchia in testa. Questo approccio rigido rischia di eliminare pagine vecchie ma ancora usate intensamente.
Per evitare questo problema, l'algoritmo della **Seconda Chance** controlla il **Bit R** della pagina più vecchia prima di rimuoverla:
- Se **R = 0**: La pagina è vecchia e inutilizzata, quindi viene sostituita immediatamente.
- Se **R = 1**: Il bit viene azzerato, la pagina viene spostata in fondo alla lista (rinnovando il suo tempo di caricamento) e la ricerca continua. Se tutte le pagine sono state referenziate, degenera in un FIFO puro.

###### Algoritmo Clock
L'algoritmo della Seconda Chance è inefficiente perché sposta continuamente le pagine lungo la lista. L'algoritmo **Clock** migliora la struttura mantenendo i frame su una lista circolare a forma di orologio. Una lancetta indica la pagina vecchia. Quando avviene un **page fault**, si esamina la pagina indicata: se **R = 0**, la pagina viene sfrattata e la lancetta avanza; se **R = 1**, il bit viene azzerato e la lancetta passa alla pagina successiva finché non ne trova una sacrificabile. Se tutti i valori di R sono uguali a 1 nel momento in cui si verifica un page fault, la lancetta dell'algoritmo Clock farà un **giro completo dell'orologio (360 gradi)**. Al termine di questo giro, la pagina che era inizialmente indicata dalla lancetta verrà sfrattata. ![[Pasted image 20260519113550.png|700]]
###### Least Recently Used (LRU)
L'algoritmo **Least Recently Used (LRU)** rappresenta un'eccellente approssimazione dell'algoritmo ottimale teorico.  Per realizzare un **LRU hardware puro**, i progettisti dovrebbero dotare il sistema di un contatore a 64 bit capace di incrementarsi automaticamente a ogni singola istruzione eseguita dalla CPU. Parallelamente, ogni voce della tabella delle pagine dovrebbe possedere uno spazio dedicato per memorizzare questo valore. In questo scenario, ogni volta che la memoria viene referenziata, il valore attuale del contatore globale viene copiato istantaneamente nella voce della tabella corrispondente alla pagina appena utilizzata. Al verificarsi di un **page fault**, il sistema operativo è costretto a esaminare tutti i contatori presenti nella tabella delle pagine per individuare il valore assoluto più basso. Quella cifra identifica matematicamente la pagina usata meno recentemente, che diventa la candidata perfetta per la rimozione. Questa implementazione, per quanto teoricamente ineccepibile, si scontra duramente con la realtà ingegneristica. Aggiornare un contatore nella memoria a ogni singola istruzione, per poi dover scansionare l'intera tabella a ogni errore di pagina, richiederebbe un hardware dedicato estremamente complesso e costoso. Trovare una pagina, aggiornarla e riordinarla in tempo reale comporta un dispendio di tempo e risorse che rende l'LRU puro impraticabile per la quasi totalità dei computer commerciali.

###### Not Frequently Used (NFU)
Proprio per superare gli ostacoli fisici ed economici dell'LRU, i progettisti hanno ideato delle simulazioni implementabili via software. La prima e più intuitiva di queste è l'algoritmo **Not Frequently Used (NFU)**.

Il suo funzionamento si basa sull'associazione di un contatore software a ciascuna pagina residente in memoria, rigorosamente inizializzato a zero al momento del caricamento. Invece di agire a ogni singola istruzione, l'NFU sfrutta l'interrupt periodico del clock. A ogni "tic" del clock, il sistema operativo effettua una rapida scansione e somma il valore del **Bit R** (il bit di riferimento, che vale 1 se la pagina è stata usata in quel ciclo, 0 altrimenti) al contatore di ciascuna pagina. In questo modo, i contatori accumulano punteggio, tenendo una traccia sommaria di quante volte ogni singola pagina è stata utilizzata durante la sua permanenza in memoria. Al momento di un **page fault**, la scelta della "vittima" da sfrattare ricade semplicemente sulla pagina che possiede il contatore numericamente più basso.

Tuttavia, l'NFU nasconde un difetto strutturale critico che lo rende imperfetto rispetto all'LRU: è dotato di una memoria infallibile, ovvero **non dimentica mai il passato**. Per comprendere il problema, possiamo immaginare l'esecuzione di un compilatore strutturato a passaggi multipli. Durante il primo passaggio, il programma utilizzerà intensamente un gruppo specifico di pagine, facendo schizzare i loro contatori a valori altissimi. Quando il programma passa alla seconda fase, quelle pagine del primo passaggio non gli serviranno più; tuttavia, il loro punteggio storico le proteggerà ostinatamente dalla rimozione. Di conseguenza, il sistema operativo finirà paradossalmente per rimpiazzare le pagine nuove e realmente utili della fase in corso (che partono inevitabilmente da un contatore basso), salvando invece le pagine vecchie e inattive. L'NFU fallisce quindi nel cogliere il vero concetto di "recente", limitandosi a premiare un generico utilizzo totale.

Per risolvere questo limite si usa l'algoritmo di **Aging**, illustrato nella figura sottostante. A ogni ciclo, i contatori vengono spostati a sinistra di un bit e il **Bit R** viene inserito nella posizione più a sinistra. L'algoritmo rimuove la pagina con il contatore più basso. Rispetto all'LRU puro, l'Aging non distingue l'ordine esatto dei riferimenti nello stesso ciclo di clock e ha un orizzonte temporale limitato dai bit del contatore. ![[Pasted image 20260519113533.png|700]]

###### Il Modello Working Set
Il ciclo di vita della memoria di un processo inizia generalmente con la strategia del **Demand Paging** (paginazione su richiesta). Nella sua forma più pura, un processo viene avviato senza che nessuna delle sue pagine sia presente in memoria fisica. Appena la CPU tenta di prelevare la prima istruzione, genera inevitabilmente un **page fault**. Questo innesca il caricamento della pagina iniziale. Subito dopo, seguiranno a raffica altri page fault per caricare lo stack, le variabili globali e le istruzioni successive. Dopo questa fase di assestamento iniziale, il processo disporrà delle pagine fondamentali e inizierà a girare in modo fluido. Le pagine vengono quindi caricate letteralmente "su richiesta", senza alcun pre-caricamento.

Ma perché, dopo una raffica iniziale di errori, il processo si stabilizza? Questo accade grazie a una proprietà fondamentale del software nota come **Località di Riferimento**. I processi non accedono al loro spazio di indirizzamento in modo casuale o uniforme; al contrario, tendono a concentrare le loro letture e scritture su una frazione relativamente piccola e ristretta di pagine in ogni specifica fase della loro esecuzione. Ad esempio, un ciclo `for` continuerà a richiamare sempre le stesse istruzioni e le stesse variabili per migliaia di iterazioni prima di passare ad altro.

Questo specifico sottoinsieme di pagine attivamente referenziate in un dato istante prende il nome di **Working Set** (o insieme di lavoro). Finché l'intero working set del processo riesce a risiedere fisicamente in memoria, il programma verrà eseguito in modo efficiente. Ma cosa succede se la RAM è troppo piccola o troppo frammentata per contenerlo tutto? Il processo inizierà a scartare pagine che gli serviranno di nuovo pochissimi millisecondi dopo, generando un page fault ogni poche istruzioni. Questa condizione catastrofica di perenne blocco e caricamento prende il nome di **Thrashing**. Quando un sistema entra in thrashing, l'intero computer rallenta fino a bloccarsi, poiché la CPU spende più tempo a gestire i page fault che a eseguire calcoli utili.

Per scongiurare il thrashing, i sistemi operativi moderni adottano il "modello working set". L'obiettivo è tenere traccia attivamente del working set di ogni processo e assicurarsi che questo sia interamente pre-caricato in memoria _prima_ di consentirne l'esecuzione. Questa tecnica di caricamento anticipato prende il nome di **Prepaginazione** (_prepaging_) e abbatte drasticamente il numero di page fault a runtime.

###### L'Algoritmo di Sostituzione basato sul Working Set
Per tradurre questa teoria in un algoritmo pratico, il sistema operativo deve definire in modo misurabile cos'è il working set. Invece di contare gli ultimi "k" riferimenti alla memoria (metodo teorico impossibile da tracciare), si utilizza il **Tempo virtuale attuale**, ovvero la quantità di tempo di CPU _effettivamente_ consumata da quel processo dal momento del suo avvio. Si stabilisce poi una determinata soglia temporale massima, indicata con $\tau$.

> [!TIP] Tempo virtuale attuale 
> l **tempo virtuale attuale** (o _current virtual time_) di un processo rappresenta la quantità esatta di tempo di CPU che quello specifico processo ha _effettivamente_ consumato dal momento in cui è stato avviato.
> 
> A differenza del tempo reale (quello del mondo fisico scandito dall'orologio del computer), il tempo virtuale di un processo avanza solo ed esclusivamente quando il processo si trova in esecuzione attiva sulla CPU. Se il sistema operativo decide di sospendere il processo, ad esempio per metterlo in attesa del completamento di un'operazione di I/O o per dare spazio a un altro programma, il suo tempo virtuale si "congela" istantaneamente, per poi riprendere a scorrere non appena il processo torna in esecuzione.

Quando si verifica un page fault, l'algoritmo deve scansionare la tabella delle pagine alla ricerca di una vittima al di fuori del working set. Analizzando ogni pagina, il sistema controlla prima di tutto il **Bit R** (Referenziato):
- Se **R = 1**: La pagina è stata usata di recente, quindi fa indiscutibilmente parte del working set. Non può essere rimossa. Il sistema operativo si limita ad aggiornare il suo "tempo di ultimo utilizzo" scrivendovi il tempo virtuale attuale.
- Se **R = 0**: La pagina non è stata usata nell'ultimo ciclo. Per capire se sia davvero "vecchia", l'algoritmo calcola la sua età (sottraendo il tempo di ultimo utilizzo dal tempo virtuale attuale) e la confronta con la soglia $\tau$.
    - Se l'**età è maggiore di $\tau$**: La pagina è matematicamente uscita dal working set. Viene scelta come vittima e rimossa istantaneamente.
    - Se l'**età è minore o uguale a $\tau$**: La pagina si è "salvata" per un pelo; è temporaneamente inattiva ma appartiene ancora al working set. L'algoritmo non la rimuove, ma ne prende nota nel caso in cui non si trovi nient'altro di meglio.

Se, terminata l'ispezione di tutta la tabella, non viene trovata nessuna pagina con età maggiore di $\tau$, significa che tutto ciò che è in memoria fa parte del working set. A questo punto, costretto a liberare spazio, il sistema operativo rimuoverà la pagina con R = 0 che risulta avere l'età in assoluto maggiore tra quelle presenti. Se persino questo tentativo fallisce (perché tutte le pagine hanno miracolosamente R = 1), sceglierà a caso una pagina pulita da sacrificare.
![[Pasted image 20260519113508.png|700]]
###### WSClock
L'algoritmo base del working set è lento per via della scansione dell'intera tabella. Il **WSClock**, illustrato nella **Figura 3.20**, unisce la lista circolare del Clock alle informazioni del working set. ![[Pasted image 20260519113442.png|400]]
La lancetta analizza le pagine: se **R = 0** e l'età supera $\tau$, si valuta la pagina. Se è pulita, viene rimossa; se è sporca, si schedula la sua scrittura su disco e la lancetta avanza senza bloccare il processo. Se la lancetta fa un giro completo e torna al punto di partenza, si presentano due casi:
- È stata schedulata almeno una scrittura: la lancetta continua a scorrere cercando la prima pagina pulita disponibile.
- Non ci sono scritture schedulate: tutte le pagine sono nel working set, quindi si sceglie una pagina pulita qualunque, o in mancanza si sacrifica la pagina attuale.
###### Confronti prestazionali dei vari algoritmi di sostituzione delle pagine
Per valutare e confrontare oggettivamente l'efficienza dei vari algoritmi di sostituzione delle pagine, si utilizza come metrica fondamentale il numero di **page fault** generati. Le valutazioni standard vengono effettuate simulando una memoria RAM limitata, ad esempio con 3 frame disponibili , e sottoponendo il sistema a una specifica sequenza compatta di accessi in memoria (come la stringa 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1). In queste sequenze di test, le ripetizioni immediate dello stesso numero vengono omesse poiché non influenzano il verificarsi dei page fault.

###### Valutazione dei Modelli Base
Sottoponendo la sequenza di riferimento ai tre algoritmi principali, emergono chiare differenze prestazionali: Il modello **OPT (Ottimale)** funge da termine di paragone assoluto. Genera il minimo storico di soli 9 page fault. Resta tuttavia un algoritmo puramente teorico, poiché per prendere le sue decisioni necessita di informazioni impossibili da ottenere sui riferimenti futuri a breve termine.  ![[Pasted image 20260519160201.png|700]]*(ogni quadrato grigio indica un page fault, in alto troviamo le pagine richieste, e in basso dentro i quadratini quelle che ci sono in memoria)*
Passando alle implementazioni reali, l'algoritmo **FIFO** si dimostra molto meno efficiente, registrando ben 15 page fault
![[Pasted image 20260519160425.png|700]]
Questo algoritmo soffre del problema noto come *anomalia di Belady*. L'algoritmo **LRU (Least-Recently Used)** invece si posiziona nel mezzo registrando 12 page fault. Oltre alle buone prestazioni, inoltre quest'ultimo è immune a l'anomalia di Belady.
![[Pasted image 20260519160531.png|700]]
###### Anomalia di Belady e Proprietà di Inclusione
Testando determinati algoritmi, i progettisti si sono scontrati con un fenomeno matematico imprevisto.
**Anomalia di Belady:** È un'anomalia controintuitiva che associa un inaspettato aumento dei page fault a un aumento della memoria RAM fisica disponibile. Questa anomalia si verifica solo di fronte a specifiche sequenze di accesso. Ad esempio, sottoponendo a un sistema la sequenza $[1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5]$, si può osservare un peggioramento delle prestazioni passando da 3 a 4 frame di memoria.
![[Pasted image 20260519160909.png|500]]
L'algoritmo LRU non presenta questa anomalia perché il suo modello matematico soddisfa un requisito stringente.

**Proprietà di Inclusione:** È una proprietà matematica secondo cui, in ogni istante di tempo $t$ e con una memoria di $n$ frame, l'insieme dei frame caricati è sempre un sottoinsieme di quelli che verrebbero caricati avendo a disposizione $n+1$ frame. In formula: $B_{t}(n)\subseteq B_{t}(n+1)$. Qualsiasi algoritmo che rispetti questa proprietà è matematicamente immune all'anomalia di Belady.

###### Comportamento degli algoritmi derivati
Comprendere l'anomalia di Belady e la proprietà di inclusione permette di classificare anche l'efficienza e i difetti di tutti gli algoritmi derivati impiegati nei sistemi operativi reali: Tutti gli algoritmi che si basano sul principio temporale del FIFO, ovvero **Seconda Chance**, **Clock** e anche la rozza approssimazione **NRU**, soffrono dell'anomalia di Belady e possono peggiorare le loro prestazioni all'aumentare della memoria. Al contrario, gli algoritmi che nascono per approssimare l'LRU, ovvero **NFU** e **Aging**, ereditano e godono della proprietà di inclusione, risultando stabili e sicuri. In particolare, l'Aging si distingue come una buona approssimazione dell'LRU, vantando anche un'implementazione software altamente efficiente. ![[Pasted image 20260519161110.png|500]]
### Problemi di progettazione dei sistemi di paginazione

###### Politiche di Allocazione: Globali e Locali a Confronto
Nei paragrafi precedenti abbiamo analizzato gli algoritmi che scelgono _quale_ pagina sostituire al momento di un page fault. Tuttavia, in un sistema multiprogrammato, i progettisti devono affrontare un'altra questione fondamentale: come dovrebbe essere ripartita la memoria fisica totale fra tutti i processi concorrenti in esecuzione? Per comprendere il problema, possiamo fare riferimento alla **Figura 3.22** ![[Pasted image 20260519113418.png|600]]Immaginiamo una situazione in cui i processi A, B e C si trovano in memoria. A un certo punto, il processo A genera un **page fault**. L'algoritmo di sostituzione deve ora prendere una decisione cruciale: cercare la pagina da sfrattare considerando solo l'insieme di pagine attualmente allocate ad A, oppure valutare tutte le pagine presenti nell'intera memoria, a prescindere da chi le stia usando?

- **Algoritmi di Sostituzione Locale**: Se l'algoritmo decide di confinare la sua ricerca alle sole pagine del processo A (scegliendo, ad esempio, la sua pagina più vecchia per fare spazio a quella nuova), stiamo applicando un **Algoritmo di sostituzione locale**. Questo approccio assegna a ogni processo una frazione rigida e fissa di memoria. Tuttavia, presenta dei gravi difetti prestazionali legati all'imprevedibilità dei programmi. Se il **working set** di un processo si restringe durante l'esecuzione, l'algoritmo locale continuerà a tenergli assegnata la stessa quantità di memoria, sprecando preziosi frame che rimarranno inutilizzati. Al contrario, se il working set del processo aumenta improvvisamente, l'algoritmo lo costringerà a sostituire continuamente le proprie pagine in un circolo vizioso, portandolo al **thrashing** pur in presenza di frame liberi e disponibili nel resto della memoria.
- **Algoritmi di Sostituzione Globale**: Se invece l'algoritmo, al verificarsi dell'errore di A, valuta tutte le pagine del sistema e decide, ad esempio, di sottrarre la pagina meno utilizzata in assoluto (magari appartenente al processo B) per assegnarla ad A, in questo caso, il numero di frame assegnato a ciascun processo varia dinamicamente nel tempo. 

In generale, gli algoritmi globali funzionano nettamente meglio di quelli locali proprio perché riescono ad assecondare le naturali variazioni di dimensione dei working set. Scegliendo una politica globale, il sistema deve però stabilire quanti frame assegnare all'avvio. Dividere la memoria in parti uguali ha poco senso, perché tratterebbe allo stesso modo un piccolo processo da 10 KB e uno enorme da 300 KB. L'approccio più saggio è avviare ogni processo assegnandogli un numero di pagine strettamente proporzionale alla sua dimensione totale (garantendo comunque un limite minimo a tutti per poter funzionare), per poi aggiornare questa assegnazione dinamicamente mentre i programmi girano.

###### L'Algoritmo Page Fault Frequency (PFF)
Il metodo più efficace per gestire questa "assegnazione dinamica" dei frame è l'algoritmo **Page Fault Frequency (PFF)**, il cui grafico di funzionamento è illustrato nella **Figura 3.23** ![[Pasted image 20260519113406.png|500]]
È importante precisare che il PFF non sceglie _quale_ pagina sostituire (quello è compito di algoritmi come Clock o WSClock), ma indica solo _quando_ è il caso di aumentare o diminuire il numero totale di pagine allocate a un determinato processo. Il funzionamento si basa sulla misurazione costante della frequenza degli errori, calcolando i **page fault per secondo** di ogni processo (spesso calcolati facendo una media tra i page fault del secondo appena trascorso e la media attuale di esecuzione, divisa per due). Il sistema operativo stabilisce dei limiti di accettabilità per questa frequenza:
- **Limite Superiore (Linea tratteggiata A):** Se la frequenza di paginazione di un processo supera questa soglia, significa che il tasso di errore è troppo alto. Il processo è "in sofferenza" per mancanza di spazio, quindi il sistema interviene aumentandogli la quota di frame assegnati.
- **Limite Inferiore (Linea tratteggiata B):** Se la frequenza di paginazione scende al di sotto di questa soglia, significa che il processo sta girando con un numero di errori così basso da far supporre che abbia troppa memoria a disposizione rispetto al necessario. In questo caso, il sistema operativo può tranquillamente sottrargli dei frame per riassegnarli a processi più bisognosi.
In questo modo, il PFF lavora costantemente in background cercando di mantenere la frequenza di paginazione di tutti i processi all'interno di una fascia sicura e ottimale.

###### Politica di Pulitura e Gestione dei Frame Liberi
Il meccanismo di risoluzione dei **page fault** è davvero efficiente e rapido solo se ci sono **frame liberi** sempre disponibili in memoria. Quando i frame scarseggiano e si è costretti a rimuovere una pagina, la gestione diventa lenta, soprattutto se la pagina è "sporca" (modificata), poiché richiede una preventiva e pesante scrittura su disco. Per evitare questo collo di bottiglia, sistemi operativi come Linux e Windows utilizzano il **paging daemon**, un processo di servizio che monitora costantemente l'occupazione globale della RAM. Questo daemon agisce d'anticipo: individua le pagine che presume non saranno utili nel breve periodo, le seleziona e le rende disponibili, mantenendo così un **pool di frame liberi** sempre pronti all'uso. La caratteristica chiave di questo pool è che i dati non vengono cancellati subito, lasciando aperta la possibilità di un **ripescaggio** istantaneo: se un processo richiede quella pagina prima che il frame venga effettivamente sovrascritto, il sistema la recupera immediatamente senza dover scatenare un vero e proprio page fault, riducendo drasticamente l'overhead generale.

###### Controllo del Carico
Se i working set combinati superano la capacità di memoria, il PFF indicherà che tutti i processi necessitano di memoria, portando inesorabilmente al **thrashing**. L'unica soluzione è lo **Swapping**, scaricando quanti più processi sul disco. La scelta di chi scaricare dipende dal grado di multiprogrammazione e dalle caratteristiche del processo (I/O bound o CPU bound).

###### Dimensione delle Pagine
La scelta della dimensione della pagina di base è importante. Al crescere o decrescere della dimensione delle pagine, otteniamo effetti positivi e negativi.
**Pro delle pagine più grandi**
* *Tabella delle pagine più piccole.*
  Il numero di record della tabella delle pagine è pari al numero di pagine. Il numero di pagine, a parità di memoria, è inversamente proporzionale alla dimensione delle pagine.
* *Migliore efficienza nel trasferimento I/O.*
  Utilizzando pagine più grandi, un input/output potrà essere effettuato su pagine più grandi, e quindi un numero minore di pagine a cui accedere. Questi vantaggi si sentono di più all’interno di memorie di tipo elettromeccanico.
* *Minori page fault (e conseguente minor overhead).*
  Pagine più grosse $\Rightarrow$ meno pagine $\Rightarrow$ meno page fault. Non sempre ne vale la pena, ma è un fatto da tenere in considerazione.

**Pro delle pagine più piccole**
* *Minore frammentazione interna.*
  Pagine più grandi causano più spreco. Pagine
* *Migliore risoluzione nel definire il working set. Meno memoria sprecata!*
  Le approssimazioni saranno più precise. Le pagine sono di dimensione fissa: blocchi più piccoli permettono di rispondere alle nostre esigenze in maniera migliore.

I pro di uno, sono i contro dell’altro. Per bilanciare gli svantaggi, i sistemi operativi utilizzano a volte pagine di dimensioni diverse per le diverse parti del sistema: per esempio, pagine grandi per il kernel e più piccole per | processi utente.

###### Pagine Condivise e Gestione della Cache
Fino ad ora abbiamo immaginato che ogni processo avesse le sue pagine isolate. Ma cosa succede se abbiamo più istanze dello stesso programma in esecuzione? Entra in gioco un'ottimizzazione del sistema operativo mirata a risparmiare memoria: le **pagine condivise**. Invece di caricare copie identiche, il sistema porta in RAM una sola copia fisica del _codice eseguibile condiviso_ e fa puntare le tabelle delle pagine dei vari processi esattamente allo stesso frame. Questo funziona perfettamente perché il codice è mantenuto in modalità _sola lettura_. Le pagine condivise si possono usare anche come strumento di comunicazione inter-processo (IPC) in _lettura/scrittura_, a patto di utilizzare i classici meccanismi di sincronizzazione per buffer condivisi, come i _MUTEX_. L'uso di questa memoria condivisa crea però delle sfide architetturali:
- **Il problema dell'aliasing in Cache:** Nelle cache "pre-MMU" basate su indirizzi virtuali, i processi vedono la stessa risorsa fisica usando indirizzi (e chiavi) virtuali diversi. Questo genera falsi _cache miss_ e seri problemi di sincronizzazione, dato che la cache rischia di caricare la stessa pagina in due voci distinte.
- **La soluzione ibrida:** Si utilizzano cache che effettuano ricerche tramite indirizzi virtuali ma associate a _tag fisici_ (sfruttando l'offset). Questa ricerca "preliminare" avviene in parallelo alla traduzione effettuata dalla MMU, permettendo di scremare le voci rapidamente senza disabilitare la cache.
- **Tabelle Invertite:** Le pagine condivise rendono le tabelle delle pagine invertite un incubo da gestire. Avendo un solo record per ogni frame fisico, risulta impossibile associarvi due indirizzi virtuali diversi senza dover modificare continuamente il record a ogni _page fault_ o _context switch_.

###### Copy-on-Write (COW) e Zero-fill-on-demand

Condividere le pagine è una tecnica eccellente per risparmiare memoria RAM, ma sorge un problema quando un processo necessita di modificare i propri dati. Prendendo in esame una chiamata `fork()`, i processi figli vengono creati identici al padre e, per ottimizzare, le loro tabelle delle pagine punteranno inizialmente agli stessi frame. L'obiettivo è mantenere questa condivisione il più a lungo possibile, intervenendo unicamente in caso di scrittura per non corrompere la memoria altrui.

Il meccanismo del **Copy-on-write** gestisce questa criticità in modo elegante: il sistema operativo, di default, imposta tutte le pagine condivise come _read-only_ (portando il bit di scrittura a 0). Quando un processo tenta di effettuare una scrittura, la MMU intercetta l'operazione non consentita ma, invece di generare un errore fatale, invoca una specifica procedura del sistema operativo. A questo punto, l'OS crea una **copia fisica identica** della singola pagina interessata, assegnandola in esclusiva al processo che ha richiesto la modifica. Infine, il sistema aggiorna i puntatori nelle rispettive tabelle delle pagine e ripristina il bit di scrittura a 1 per entrambe le nuove copie, rendendole di fatto indipendenti.

Una logica simile è alla base dello **Zero-fill-on-demand**, utilizzato quando un processo richiede nuova memoria per l'heap tramite chiamate come `sbrk()`. Anziché allocare e pulire immediatamente dei frame reali, il sistema operativo illude il processo associando temporaneamente le nuove pagine a una _read-only static zero page_, ovvero un frame speciale pre-azzerato e privo di informazioni. Soltanto nel momento in cui il processo tenterà per la prima volta di utilizzare (e quindi scrivere su) queste pagine, si innescherà il meccanismo del _copy-on-write_: il sistema operativo pulirà dei frame reali _on-demand_, li assegnerà al processo e aggiornerà i puntatori nella tabella delle pagine.

###### Librerie Condivise, File Mappati e Layout della Memoria

Quando un programma ha bisogno di usare funzioni appartenenti a librerie esterne, può inglobarle in due modi molto diversi:
- **Linking statico (L'approccio pesante):** Tutto il codice binario della libreria precompilata viene inserito fisicamente dentro l'eseguibile nei posti in cui le funzioni vengono chiamate. Il programma ha tutto a disposizione subito, ma l'eseguibile finisce per occupare molto spazio.
- **Linking dinamico (L'approccio smart):** Nell'eseguibile risiede solo il sorgente. A run-time, alla prima chiamata, la libreria viene portata _tutta in RAM_ e messa a disposizione del processo. Se altri processi necessitano della stessa libreria, non ne viene creata una copia nuova, ma tutti si agganceranno a quell'unica copia condivisa.

Un'evoluzione ancora più prestante per la condivisione è l'utilizzo dei **file mappati**. La mappatura in memoria è un meccanismo che permette di associare un’area della memoria virtuale di un processo al contenuto di un file memorizzato sul disco, permettendo così di accedere a quest’ultimo come se fosse parte della memoria RAM. Questa tecnica consente un accesso rapido ed efficiente ai dati (successivamente a un page fault), migliorando le prestazioni di applicazioni che gestiscono file di grandi dimensioni e facilitando la comunicazione tra processi che condividono memoria.
###### Allocazione della Memoria per il Kernel
Il sistema operativo ha bisogno di spazio in RAM per ospitare le proprie strutture dati di supporto (come PCB, semafori, code, ecc.). A differenza della memoria utente che viene paginata, il Kernel sbatte contro un ostacolo fisico: moduli che dialogano direttamente con l'hardware o con il sistema DMA necessitano obbligatoriamente di indirizzi fisici e frame **fisicamente contigui**.

Per allocare questa memoria complessa mirando a una frammentazione interna nulla, Linux impiega lo **slab allocator**. Questo modello si basa su due elementi:
- **Slab:** È una sequenza di frame fisicamente adiacenti (un pezzo fisico di memoria contiguo).
- **Cache:** È un insieme di slab. Il grande vantaggio è che ogni cache è _fortemente specializzata_ per ospitare un singolo tipo di struttura dati: ad esempio, avremo una cache esclusivamente per oggetti da 3 KB e un'altra per quelli da 7 KB.

L'efficienza è massima perché l'OS sceglie sempre di allocare slab di dimensione perfettamente multipla allo spazio richiesto. Così facendo, la _frammentazione esterna_ si annulla totalmente (tutto lo spazio che non serve al kernel viene rimbalzato alla paginazione classica), e l'operare direttamente con indirizzi fisici garantisce un _overhead minimo_.