### La memoria
###### Introduzione alla gerarchia della memoria
I moderni sistemi informatici adottano una **gerarchia della memoria** per bilanciare costi e prestazioni. Questa struttura si articola solitamente in tre livelli:
- **Memoria molto veloce:** Pochi megabyte, estremamente costosa e volatile.
- **Memoria di medio costo:** Qualche gigabyte, abbastanza veloce e volatile (RAM).
- **Memoria su disco:** Alcuni terabyte, non volatile, lenta ma a basso costo.
**Gestore della memoria:** È la componente del sistema operativo incaricata di gestire questa gerarchia.
###### Assenza di astrazione della memoria
Storicamente, dai primi _mainframe_ (prima del 1960) fino ai primi _personal computer_ (prima del 1980), non esisteva alcuna astrazione della memoria. Ogni programma interagiva direttamente con la **memoria fisica**.
###### Il modello di memoria fisica
In questo scenario, il modello presentato al programmatore è un insieme di indirizzi che vanno da 0 a un limite massimo. Ogni indirizzo corrisponde a una cella (solitamente di 8 bit). Un'operazione tipica consisteva, ad esempio, nel muovere il contenuto della locazione fisica 1000 in un registro (_REGISTER1_).

###### Limitazioni e varianti strutturali
In assenza di astrazione, non è possibile eseguire due programmi contemporaneamente: se un programma scrivesse in una posizione usata da un altro, ne cancellerebbe i dati. Esistono tre varianti principali per l'organizzazione del sistema operativo in questo modello:
1. **S.O. in RAM:** Il sistema operativo risiede nel fondo della memoria nella **RAM (Random Access Memory)**.
2. **S.O. in ROM:** Il sistema operativo si trova in cima alla memoria nella **ROM (Read Only Memory)**.
3. **Modello Ibrido:** I driver dei dispositivi risiedono nella ROM in cima alla memoria, mentre il resto del sistema è nella RAM sottostante. Questo modello è tipico dei primi PC con MS-DOS, dove la parte in ROM è nota come **BIOS (Basic Input Output System)**.
![[Pasted image 20260501104611.png|500]]
###### Esecuzione di molteplici programmi senza astrazione

È possibile ottenere un certo grado di parallelismo anche senza astrazione, seguendo diverse strategie:

- **Programmazione con thread**: Un metodo per avere parallelismo è utilizzare molteplici _thread_ all'interno dello stesso contesto di memoria. Essendo thread fanno parte dello stesso processo, quindi non è una vera esecuzione di più programmi.
- **Swapping (Versione primitiva)**: Un'altra possibilità è eseguire un programma alla volta, salvando l'intero contenuto della memoria su disco quando si passa al processo successivo. Finché risiede un solo programma in memoria, non si verificano conflitti.
- **Protezione tramite chiavi (IBM 360):** Con l'ausilio di hardware speciale, è possibile far risiedere più programmi contemporaneamente. L'IBM 360 utilizzava una **chiave di protezione** di 4 bit per ogni cella di memoria. La PWS di un processo conteneva conteneva una chiave di 4 bit che gli permetteva di interagire con la locazione di memoria a lui assegnata. L'hardware intercettava ogni tentativo di accesso alla memoria: se il codice di protezione del processo non coincideva con la chiave nella PSW, l'accesso veniva bloccato.

###### Il problema della rilocazione
Anche se i programmi sono protetti dalle chiavi, sorge il problema degli indirizzi assoluti. Se due programmi da 16 KB vengono caricati uno sopra l'altro, il secondo (caricato all'indirizzo 16.384) fallirà se tenta di eseguire un salto relativo al proprio inizio (es. `JMP 28`), poiché finirà per saltare a un indirizzo nel primo programma invece che nel proprio. In questo esempio vediamo esattamente questa cosa, dopo aver caricato il processo a e b in memoria (c) possiamo notare che:
- *processo A*: il jump 24 funzionerà bene e il processo finisce in modo corretto
- *processo B*: il jump 28 cercherà di saltare ma entra nella memoria del primo processo e andrà in errore
![[Pasted image 20260501105311.png|500]]

Una soluzione a questo problema è la **rilocazione statica:** consiste nel modificare il programma direttamente durante il caricamento in memoria, aggiungendo l'indirizzo di partenza (es. 16.384) a ogni indirizzo del programma.
##### L'astrazione della memoria: lo spazio degli indirizzi
Esporre la memoria fisica presenta due gravi inconvenienti:
1. I programmi utente possono distruggere il sistema operativo.
2. È difficile gestire l'esecuzione contemporanea di più programmi.

Per risolvere i problemi di **protezione** e **riposizionamento**, è stata introdotta l'astrazione dello **spazio degli indirizzi**. Lo **spazio degli indirizzi:** è l'insieme degli indirizzi che un processo può utilizzare per indirizzare la memoria. Per rendere possibile questa astrazione virtuale in prima battuta facciamo uso della tecnica della rilocazione dinamica
###### Rilocazione dinamica: registri base e limite
La **rilocazione dinamica**, mappa lo spazio degli indirizzi di ogni processo su porzioni diverse di memoria fisica tramite hardware speciale ovvero attraverso due registri della CPU:
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
2. **Memoria virtuale:** Un'evoluzione successiva (che vedremo dopo) che consente l'esecuzione di programmi caricandone in RAM solo le parti strettamente necessarie.
Analizziamo prima l'approccio storico: lo Swapping.

###### Lo Swapping e la Frammentazione
Immaginiamo di avere due programmi, $P_1$ e $P_2$. Attualmente $P_1$ è in esecuzione, ma vogliamo eseguire anche $P_2$. Purtroppo, la memoria centrale (RAM) è piena. A questo punto interviene il componente del sistema operativo chiamato **swapper**: esso esegue uno _swap-out_ (sposta $P_1$ dalla RAM al disco) e uno _swap-in_ (carica $P_2$ dal disco alla RAM).

Il disco viene quindi usato come "memoria secondaria" di appoggio. Il processo $P_1$, finché si trova su disco, è penalizzato poiché non riceve risorse dalla CPU.

Sebbene sembri una soluzione perfetta, lo swapping continuo di programmi di dimensioni diverse crea un grave problema: la **frammentazione della memoria** . Ne esistono due tipi:
- **Frammentazione Interna:** Si verifica quando a un processo viene assegnata un'area di memoria leggermente più grande delle sue reali esigenze. Lo spazio extra all'interno di quell'area allocata rimane inutilizzato e sprecato.
- **Frammentazione Esterna:** Si verifica quando la memoria totale libera sarebbe sufficiente per ospitare un nuovo processo, ma è suddivisa in tanti piccoli blocchi non contigui (buchi). Poiché il processo necessita di memoria contigua, non può essere caricato. L'unica soluzione è la **Memory Compaction** (Compattazione della memoria): il S.O. sposta fisicamente tutti i processi attivi verso il fondo della memoria per unire tutti i "buchi" in un unico grande spazio libero in cima. È una procedura estremamente lenta e si cerca di evitarla il più possibile.
###### Il problema dell'Allocazione con Dimensione Dinamica
La gestione della frammentazione è ulteriormente complicata dal fatto che i processi non hanno sempre dimensioni fisse. Durante l'esecuzione, i dati di un programma possono crescere (ad esempio, allocando memoria dinamicamente).

La struttura ottimale per gestire la crescita dinamica all'interno di un processo prevede due segmenti mobili:
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
Invece di mappare ogni singolo blocco, il S.O. mantiene una lista dinamica (Linked List) che mappa interi segmenti . Ogni nodo (voce) della lista descrive un blocco contiguo, specificando:
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

###### Algoritmi di Allocazione: Come scegliere il "buco" giusto?
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
###### La Memoria Virtuale
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
 Per eseguirla deve accedere prima alla memoria e lo fa generando degli indirizzi detti **indirizzi virtuali** l'insieme di questi indirizzi forma lo **spazio virtuale degli indirizzi** (l'insieme degli indirizzi a disposizione di un processo). Gli indirizzi virtuali generati dalla CPU non vanno direttamente al bus di memoria. passano prima attraverso un componente hardware dedicato chiamato **MMU (Memory Management Unit)** che consiste in un unità di gestione della memoria che ha il compito di mappare gli indirizzi virtuali sugli indirizzi di memoria fisica.
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

###### La Tabella delle Pagine
La tabella delle pagine è una tabella utilizzata dall'MMU insieme al sistema operativo per tradurre da indirizzi virtuali a fisici, l'esatto layout di una voce di una singola tabella della pagina dipende molto dalla macchina su cui si opera. Tuttavia, il tipo di informazioni presenti è più o meno lo stesso per tutte le architetture. Di seguito una rassegna dei campi contenuti in una voce:
- **Numero del frame (frame number):** È il campo più importante in assoluto, in quanto indica l'indirizzo fisico in cui si trova la pagina.
- **Bit Presente/Assente:** Se questo bit è 1, la voce è valida e può essere utilizzata normalmente. Se è 0, significa che la pagina virtuale cui appartiene la voce non è effettivamente in memoria in quel momento.
- **Protezione:** Specifica quali tipi di accesso sono consentiti per quella pagina. Nella sua forma più basilare, questo campo contiene 1 solo bit: il valore 0 significa lettura/scrittura consentita, mentre il valore 1 indica l'accesso in sola lettura.
- **Bit Modificato (Dirty bit):** Tiene traccia dell'uso della pagina. Se la pagina è stata modificata rispetto alla sua versione in disco (cioè è considerata "sporca"), questo bit è impostato. Se la pagina non è stata modificata (cioè è considerata "pulita"), in caso di sfratto il suo contenuto può essere semplicemente abbandonato senza sovrascriverlo, poiché la copia originaria presente sul disco è ancora perfettamente valida.
- **Bit Referenziato:** È impostato dall'hardware ogni qualvolta si faccia riferimento alla pagina, sia per un'operazione di lettura sia in scrittura. Serve ad aiutare il sistema operativo a scaricare (cioè a "sfrattare") una pagina quando si verifica un page fault. Le pagine inutilizzate (non referenziate) sono le candidate migliori per lo sfratto rispetto a quelle usate di recente.    
- **Disabilitazione della cache:** L'ultimo bit consente di disabilitare la cache per la specifica pagina. Questo è fondamentale per l'I/O: fa in modo che la macchina debba prelevare la parola direttamente da quel dispositivo hardware, senza rischiare di usare una vecchia parola non aggiornata messa precedentemente in cache.

###### Problemi principali della paginazione
Dopo aver visto le basi, è il momento di analizzare in maggior dettaglio le implementazioni. In ogni sistema di paginazione devono essere affrontate due questioni principali e molto critiche:
1. **Il mapping dall'indirizzo virtuale all'indirizzo fisico deve essere veloce.** Questo punto deriva dal fatto che il mapping virtuale-fisico deve avvenire in modo sistematico per _ogni_ singolo riferimento alla memoria.
2. **Se lo spazio virtuale degli indirizzi è grande, la tabella delle pagine sarà grande.** Questo punto deriva dal fatto che tutti i computer moderni usano indirizzi virtuali di almeno 64bit.

La necessità di avere un mapping delle pagine che sia simultaneamente grande e veloce rappresenta un limite significativo, dovuto specificamente al modo in cui sono costruiti i computer. I progettisti hanno dovuto affrontare questo problema per anni.

###### Le 2 Soluzioni Base per la Tabella delle Pagine
Dal punto di vista concettuale, esistono due approcci estremi:
- **Soluzione 1 (Registri hardware):** Avere una sola tabella delle pagine che consiste di un array di registri hardware estremamente veloci, con una sola voce per ogni pagina virtuale. All'avvio di un processo, il sistema operativo carica i registri con la tabella delle pagine del processo, prendendola da una copia che tiene in memoria. Durante l'esecuzione del processo, non sono necessari altri riferimenti alla memoria per la tabella delle pagine, garantendo grande velocità (ma con costi di context switch immensi se la tabella è grande).
- **Soluzione 2 (Tabella in Memoria e PTBR):** Nella situazione opposta, la tabella delle pagine può essere interamente caricata nella memoria RAM. Tutto ciò di cui necessita l'hardware in questo caso è un singolo registro dedicato che punti all'inizio della tabella delle pagine in memoria, noto come **PTBR (Page Table Base Register)**.

###### Il Translation Lookaside Buffer (TLB)
Per bilanciare velocità e dimensioni, la soluzione escogitata è stata quella di equipaggiare i computer di un piccolo dispositivo *hardware* dedicato esclusivamente a mappare gli indirizzi virtuali sugli indirizzi fisici senza dover passare ogni volta dalla tabella delle pagine in memoria.
**TLB:** Acronimo di **Translation Lookaside Buffer**, talvolta chiamato anche **memoria associativa**.
- **Capacità e Struttura:** Contiene solitamente poche voci, ciascuna voce contiene informazioni cruciali riguardo una pagina, tra cui: 
	- *il numero di pagina virtuale*
	- *un dirty bit*: quando avviene una modifica ad un record questo viene macchiato come dirty, quando questo succede e quel record deve essere eliminato dalla TLB la modifica deve essere riportata alla tabella delle pagine.
	- *il codice di protezione* (i permessi di lettura, scrittura ed esecuzione) 
	- *il frame fisico*
- **Funzionamento:** Quando un indirizzo virtuale viene presentato alla MMU per la traduzione, l'hardware per prima cosa guarda se il suo numero di pagina virtuale è presente nel TLB, confrontandolo simultaneamente (cioè in parallelo) con tutte le voci.
    - **TLB hit (successo di TLB):** Il numero di pagina viene trovato e la traduzione avviene istantaneamente.
    - **TLB miss (fallimento di TLB):** Avviene quando il numero di pagina virtuale non è nel TLB. In questo caso, la MMU rileva il miss e fa una normale ricerca sulla tabella delle pagine in memoria. Quindi sfratta una delle voci dal TLB e la rimpiazza con la voce della tabella delle pagine appena cercata e recuperata. In questo modo, se quella stessa pagina è riusata a breve termine, la seconda volta si avrà un successo (TLB hit).

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

###### Gestione TLB via Software nelle architetture RISC
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
- **Meccanismo a due livelli:** Quando viene presentato un indirizzo virtuale alla MMU, l'hardware per prima cosa estrae il primo campo (chiamato _PT1_) e usa questo valore come indice nella tabella delle pagine di livello più alto. Il secondo campo, _PT2_, adesso è usato come un indice nella tabella delle pagine di secondo livello (selezionata dal passo precedente) per cercare il numero di frame della pagina stessa.
- **Espansione dei livelli:** Possiamo aumentare il numero di livelli per supportare indirizzi molto grandi; questo ci permette di risparmiare memoria (tenendo su disco i livelli non usati) a discapito però della velocità, poiché sarà richiesto un accesso in più alla memoria RAM per ogni livello aggiunto alla gerarchia.
###### Tabelle delle Pagine Invertite
Un'alternativa al continuo aumento della gerarchia della paginazione è nota con il termine di **tabelle delle pagine invertite**. In questa particolare progettazione c'è **una sola voce per frame** presente nella memoria reale, piuttosto che una voce per pagina dello spazio virtuale degli indirizzi (come avviene nei metodi classici).
- **Vantaggio:** Le tabelle delle pagine invertite risparmiano una gran quantità di spazio, in particolar modo quando lo spazio virtuale degli indirizzi è molto superiore rispetto alla memoria fisica disponibile.
- **Svantaggio:** Presentano un grosso problema: la traduzione da indirizzo virtuale a indirizzo fisico diventa molto difficile. Quando il processo _n_ referenzia la pagina virtuale _p_, l'hardware non può più trovare la pagina fisica usando semplicemente _p_ come indice diretto nella tabella delle pagine. Deve cercare invece l'esatta voce o coppia (_n, p_) esplorando l'intera tabella delle pagine invertite.

**Soluzione al problema della ricerca:** La lentezza della traduzione si risolve mediante l'impiego massiccio del TLB. Se il TLB può contenere tutte le pagine più usate dal sistema, la traduzione può avvenire velocemente esattamente come con le normali tabelle delle pagine. Nel caso sfortunato in cui si verifichi una _TLB miss_, deve essere comunque fatta una ricerca nella grande tabella invertita. Un modo possibile ed efficiente di realizzare questa ricerca è di avere una **hash table** sull'indirizzo virtuale.

###### Cache della memoria vs Memoria virtuale
La cache della memoria può essere basata sugli indirizzi fisici, o sugli indirizzi virtuali. Ciò dipenderà rispettivamente, se posizioniamo l’MMU prima o dopo la cache.
- *Indirizzi fisici*:
  Pro: non servirà invalidare la cache sul context-switch. Avendo indirizzi fisici già tradotti nella cache, non si avranno problemi di ambiguità.
  Contro: l’MMU diventa un collo di bottiglia per la cache.
- *Indirizzi virtuali*.
  Pro: più veloce ed efficace 
  Contro: servono gli ASID per non invalidare la cache
![[Pasted image 20260516091408.png|700]]
Soluzione effettiva:
approccio ibrido La cache $L1$ basata su indirizzi virtuali, si pone prima dell’MMU, basandosi sugli indirizzi virtuali. La cache $L2$ e successive dopo l’MMU, basate su indirizzi fisici.