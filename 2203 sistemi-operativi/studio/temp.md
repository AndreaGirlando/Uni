###### Il Problema del Software Bloat e la Nascita della Memoria Virtuale
Mentre da un lato l'utilizzo dei registri base e limite può essere sfruttato per creare l'astrazione degli spazi degli indirizzi, dall'altro lato nell'informatica moderna sorge un nuovo problema fondamentale: la gestione del **software bloat** (software di grosse dimensioni). Questo fenomeno si verifica perché, nonostante le dimensioni della memoria fisica aumentino rapidamente con lo sviluppo tecnologico, le dimensioni dei software aumentano a una velocità ancora maggiore. Il metodo che fu escogitato nel 1961 da Fotheringham per risolvere questa limitazione sarebbe diventato noto come **memoria virtuale**. Questa tecnica prevede che ogni programma abbia il proprio spazio degli indirizzi personale, suddiviso a sua volta in pezzi chiamati **pagine**.

Queste pagine sono mappate sulla memoria fisica, ma la caratteristica cruciale è che **non tutte le pagine devono stare contemporaneamente nella memoria fisica per poter eseguire il programma**.
- Quando il programma fa riferimento a una parte del proprio spazio degli indirizzi che è attualmente caricata nella memoria fisica, l'hardware esegue il mapping direttamente. 
- Quando, al contrario, il programma fa riferimento a una parte del proprio spazio degli indirizzi che _non_ è presente nella memoria fisica, il sistema operativo viene allertato per andare a prendere il pezzo mancante e rieseguire l'istruzione che era fallita.

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
3. Secondo il mappaggio interno della MMU, la pagina 0 corrisponde al frame 2 (che copre gli indirizzi fisici da 8192 a 12287).
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

# SISTEMATI FINO A QUI

###### La Tabella delle Pagine
La tabella delle pagine è una tabella utilizzata dall'MMU insieme al sistema operativo per tradurre da indirizzi virtuali a fisici, l'esatto layout di una voce di una singola tabella della pagina dipende molto dalla macchina su cui si opera. Tuttavia, il tipo di informazioni presenti è più o meno lo stesso per tutte le architetture.

Di seguito una rassegna dei campi contenuti in una voce:
- **Numero del frame (frame number):** È il campo più importante in assoluto, in quanto indica l'indirizzo fisico in cui si trova la pagina. _(Da integrare guardando l'esercizio traduzione MMU indirizzi e tabelle dei frame dagli appunti)_.
- **Bit Presente/Assente:** Se questo bit è 1, la voce è valida e può essere utilizzata normalmente. Se è 0, significa che la pagina virtuale cui appartiene la voce non è effettivamente in memoria in quel momento.
- **Protezione:** Specifica quali tipi di accesso sono consentiti per quella pagina. Nella sua forma più basilare, questo campo contiene 1 solo bit: il valore 0 significa lettura/scrittura consentita, mentre il valore 1 indica l'accesso in sola lettura.
- **Bit Modificato (Dirty bit):** Tiene traccia dell'uso della pagina. Se la pagina è stata modificata (cioè è considerata "sporca"), questo bit è impostato. Se la pagina non è stata modificata (cioè è considerata "pulita"), in caso di sfratto il suo contenuto può essere semplicemente abbandonato senza sovrascriverlo, poiché la copia originaria presente sul disco è ancora perfettamente valida.
- **Bit Referenziato:** È impostato dall'hardware ogni qualvolta si faccia riferimento alla pagina, sia per un'operazione di lettura sia in scrittura. Serve ad aiutare il sistema operativo a scaricare (cioè a "sfrattare") una pagina quando si verifica un page fault. Le pagine inutilizzate (non referenziate) sono le candidate migliori per lo sfratto rispetto a quelle usate di recente.    
- **Disabilitazione della cache:** L'ultimo bit consente di disabilitare la cache per la specifica pagina. Questo è fondamentale per l'I/O: fa in modo che la macchina debba prelevare la parola direttamente da quel dispositivo hardware, senza rischiare di usare una vecchia parola non aggiornata messa precedentemente in cache.

###### Ottimizzazione del Mappaggio: Prestazioni e TLB
Dopo aver visto le basi, è il momento di analizzare in maggior dettaglio le implementazioni. In ogni sistema di paginazione devono essere affrontate due questioni principali e molto critiche:
1. **Il mappaggio dall'indirizzo virtuale all'indirizzo fisico deve essere veloce.** Questo punto deriva dal fatto che il mappaggio virtuale-fisico deve avvenire in modo sistematico per _ogni_ singolo riferimento alla memoria.
2. **Se lo spazio virtuale degli indirizzi è grande, la tabella delle pagine sarà grande.** Questo punto deriva dal fatto che tutti i computer moderni usano indirizzi virtuali di almeno 32 bit, e i 64 bit stanno ormai diventando la norma.

La necessità di avere un mappaggio delle pagine che sia simultaneamente grande e veloce rappresenta un limite significativo, dovuto specificamente al modo in cui sono costruiti i computer. I progettisti hanno dovuto affrontare questo problema per anni. A queste condizioni, senza accorgimenti, nessuno userebbe la paginazione.

###### Le 2 Soluzioni Base per la Tabella delle Pagine
Dal punto di vista concettuale, esistono due approcci estremi:
- **Soluzione 1 (Registri hardware):** Avere una sola tabella delle pagine che consiste di un array di registri hardware estremamente veloci, con una sola voce per ogni pagina virtuale (indicizzata per numero di pagina virtuale, come illustrato nella Figura 3.10). All'avvio di un processo, il sistema operativo carica i registri con la tabella delle pagine del processo, prendendola da una copia che tiene in memoria. Durante l'esecuzione del processo, non sono necessari altri riferimenti alla memoria per la tabella delle pagine, garantendo grande velocità (ma con costi hardware immensi se la tabella è grande).
- **Soluzione 2 (Tabella in Memoria e PTBR):** Nella situazione opposta, la tabella delle pagine può essere interamente caricata nella memoria RAM. Tutto ciò di cui necessita l'hardware in questo caso è un singolo registro dedicato che punti all'inizio della tabella delle pagine in memoria, noto come **PTBR (Page Table Base Register)**.

###### Il Translation Lookaside Buffer (TLB)
Per bilanciare velocità e dimensioni, la soluzione escogitata è stata quella di equipaggiare i computer di un piccolo dispositivo hardware dedicato esclusivamente a mappare gli indirizzi virtuali sugli indirizzi fisici senza dover passare ogni volta dalla tabella delle pagine in memoria.
**TLB:** Acronimo di **Translation Lookaside Buffer**, talvolta chiamato anche **memoria associativa**.
- **Capacità e Struttura:** Contiene solitamente poche voci (otto in alcuni casi, ma raramente più di 256). Ciascuna voce contiene informazioni cruciali riguardo una pagina, tra cui: il numero di pagina virtuale, un bit impostato quando la pagina viene modificata, il codice di protezione (i permessi di lettura, scrittura ed esecuzione) e il frame fisico in cui si trova la pagina.
- **Funzionamento:** Quando un indirizzo virtuale viene presentato alla MMU per la traduzione, l'hardware per prima cosa guarda se il suo numero di pagina virtuale è presente nel TLB, confrontandolo simultaneamente (cioè in parallelo) con tutte le voci.
    - **TLB hit (successo di TLB):** Il numero di pagina viene trovato e la traduzione avviene istantaneamente.
    - **TLB miss (fallimento di TLB):** Avviene quando il numero di pagina virtuale non è nel TLB. In questo caso, la MMU rileva il miss e fa una normale ricerca sulla tabella delle pagine in memoria. Quindi sfratta una delle voci dal TLB e la rimpiazza con la voce della tabella delle pagine appena cercata e recuperata. In questo modo, se quella stessa pagina è riusata a breve termine, la seconda volta si avrà un successo (TLB hit).

###### Gestione TLB via Software nelle architetture RISC

Finora si è supposto che ogni macchina con memoria virtuale paginata abbia delle tabelle delle pagine riconosciute direttamente dall'hardware, più un TLB. Nel passato questo assunto era valido. Tuttavia, molte macchine ad architettura RISC moderne (tra cui SPARC, MIPS e l'oggi defunto HP PA) eseguono quasi tutta questa gestione delle pagine tramite software.

Nella gestione del TLB via software, è fondamentale capire la differenza fra due tipi di miss:
- **Soft miss:** Avviene quando la pagina di riferimento non è nel TLB, ma si trova comunque all'interno della memoria RAM. La risoluzione è rapida.
- **Hard miss:** All'opposto, avviene quando la pagina stessa non è in memoria (e ovviamente nemmeno nel TLB). Per prendere la pagina serve un accesso al disco, il che comporta tempistiche di parecchi millisecondi. Questa situazione può esitare in un errore di **segmentazione (segmentation fault)**.


I TLB possono essere usati per velocizzare la traduzione dell'indirizzo virtuale nell'indirizzo fisico rispetto allo schema originale della "tabella-delle-pagine-in-memoria". Rimane però un altro problema aperto: quale comportamento assumere con spazi degli indirizzi virtuali molto grandi?

###### Tabelle delle Pagine Multilivello
La prima soluzione consiste nel considerare le **tabelle delle pagine multilivello**. Il segreto del metodo della tabella delle pagine multilivello sta nell'evitare di mantenere tutte le tabelle delle pagine caricate in memoria per tutto il tempo. In particolare, le tabelle non strettamente necessarie in quel momento dovrebbero essere messe da parte sul disco.
![[Pasted image 20260503161749.png|500]]
- **Meccanismo a due livelli:** Quando viene presentato un indirizzo virtuale alla MMU, l'hardware per prima cosa estrae il primo campo (chiamato _PT1_) e usa questo valore come indice nella tabella delle pagine di livello più alto. Il secondo campo, _PT2_, adesso è usato come un indice nella tabella delle pagine di secondo livello (selezionata dal passo precedente) per cercare il numero di frame della pagina stessa.
- **Espansione dei livelli:** Possiamo aumentare il numero di livelli per supportare indirizzi molto grandi; questo ci permette di risparmiare memoria (tenendo su disco i livelli non usati) a discapito però della velocità, poiché sarà richiesto un accesso in più alla memoria RAM per ogni livello aggiunto alla gerarchia.
###### Tabelle delle Pagine Invertite
Un'alternativa al continuo aumento della gerarchia della paginazione è nota con il termine di **tabelle delle pagine invertite**. In questa particolare progettazione c'è **una sola voce per frame** presente nella memoria reale, piuttosto che una voce per pagina dello spazio virtuale degli indirizzi (come avviene nei metodi classici).
- **Vantaggio:** Le tabelle delle pagine invertite risparmiano una gran quantità di spazio, in particolar modo quando lo spazio virtuale degli indirizzi è molto superiore rispetto alla memoria fisica disponibile.
- **Svantaggio:** Presentano un grosso problema: la traduzione da indirizzo virtuale a indirizzo fisico diventa molto difficile. Quando il processo _n_ referenzia la pagina virtuale _p_, l'hardware non può più trovare la pagina fisica usando semplicemente _p_ come indice diretto nella tabella delle pagine. Deve cercare invece l'esatta voce o coppia (_n, p_) esplorando l'intera tabella delle pagine invertite.

**Soluzione al problema della ricerca:** La lentezza della traduzione si risolve mediante l'impiego massiccio del TLB. Se il TLB può contenere tutte le pagine più usate dal sistema, la traduzione può avvenire velocemente esattamente come con le normali tabelle delle pagine. Nel caso sfortunato in cui si verifichi una _TLB miss_, deve essere comunque fatta una ricerca nella grande tabella invertita. Un modo possibile ed efficiente di realizzare questa ricerca è di avere una **hash table** sull'indirizzo virtuale.
