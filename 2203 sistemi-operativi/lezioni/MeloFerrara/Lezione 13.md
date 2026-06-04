# Gestione della Memoria e Tabelle delle Pagine

## Tabella dei Frame

Per ogni frame ci dice lo stato di allocazione e se è allocato per quale processo.

Questo serve se devo occupare un frame: grazie alla tabella posso subito vedere dove prendere il frame.

## Come si implementa una Tabella delle Pagine

I fattori rilevanti sono:

- **Velocità di conversione:** serve avere una struttura veloce.

- **Dimensione:** siccome ho una tabella per processo dovrà avere dimensioni contenute.

### Velocità e ruolo del PTBR

Posso implementare la tabella in un numero di registri, ma c'è il limite in cui caricare tutta la tabella; questo però implica un costo in più per i vari context-switch. Una soluzione migliore è avere le tabelle in [[RAM]] e usarle direttamente dalla RAM.

La [[MMU]] deve capire che tabella usare tramite il registro **PTBR** (Page Table Base Register): è l'indirizzo da cui si sviluppa la tabella stessa.

> [!info] Approfondimento: Cos'è e come funziona il PTBR? Il **PTBR** è un registro hardware che contiene un singolo indirizzo fisico: l'indirizzo di partenza (o "base") della tabella delle pagine del processo attualmente in esecuzione. Poiché ogni processo ha la propria tabella isolata, ad ogni _context switch_ il Sistema Operativo aggiorna il PTBR con l'indirizzo della tabella del nuovo processo che sta per riprendere l'esecuzione. Quando la MMU deve tradurre un indirizzo virtuale, calcola dove trovare la riga giusta in RAM facendo un semplice calcolo hardware: `(Valore del PTBR) + (Numero di pagina)`.

**Il problema del doppio accesso alla RAM:** Avere la tabella in RAM e usare il PTBR significa che l'MMU farà **due fetch (accessi) alla RAM** per ogni operazione di memoria richiesta dal programma:

1. **Primo accesso:** Va all'indirizzo calcolato col PTBR per leggere la riga della Tabella delle Pagine e scoprire il numero del frame fisico.

2. **Secondo accesso:** Va all'indirizzo fisico appena scoperto nel frame per prendere o scrivere effettivamente il dato.

_(Nota: È proprio per risolvere la lentezza di questo "doppio accesso" alla RAM che viene introdotta la memoria cache TLB)._

---
## TLB (Translation Lookaside Buffer)

È una memoria veloce (cache) che si trova tra MMU e tabella delle pagine. Questo serve a tenere le pagine che sono usate da un processo in corso, un processo potrebbe concentrarsi su un'unica pagina a un certo punto della sua vita.

La TLB funziona proprio come la cache. Quello che accade più di frequente da qui definisce **TLB Hit/Miss** come cache hit/miss.

La TLB è molto critica, essa ha le voci speculari alla tabella delle pagine (bit protezione e numero di frame).

> [!tip] Velocità della TLB
> La **TLB** (*Translation Lookaside Buffer*) è una cache hardware costruita tramite **TCAM** (*Ternary Content-Addressable Memory*). 
> 
> Questo tipo di memoria consente di interrogare tutte le celle in parallelo in un singolo ciclo di clock, rendendo le query a complessità **$O(1)$**.
### Voci in TLB:

- **Numero di pagina virtuale** della voce (a cui si riferisce la voce)

- **Bit di validità** per la voce (vuota o con dati completi)

- **Numero di frame**

- **Bit di protezione:** è presente perché devo comunque controllare le autorizzazioni.

- **Dirty Bit:** serve poiché la CPU legge dalla TLB, quindi va segnato se viene usato o meno. Quando poi verrà scaricata, il dirty bit sarà trascritto in RAM.

- Il **Bit di referenziamento** non serve poiché se la pagina è in TLB sicuramente è stata usata di recente.

La TLB serve per privilegiare l'accesso ad alcune strutture dati (reiterate); in questo modo però non posso distinguere voci di un processo A da voci di un processo B. Ogni volta che un processo finisce avviene un **Flush della TLB**, così ogni nuovo processo troverà la TLB vuota e partirà con una TLB miss.

Un altro modo è aggiungere a questi campi un **ASID** (Address-Space Identifiers) che è equivalente al **PID** (identifica il processo). La ricerca adesso avviene con due chiavi (`PID`, `p`). I vari thread di un processo hanno lo stesso ASID così posso evitare i flush.

---
## Tabelle Multilivello

La tabella delle pagine va posta in modo contiguo. Per risolvere il problema della dimensione posso usare delle **Tabelle Multilivello**.

Avrò vari livelli di tabelle che costituiscono una **struttura ad albero**. Al primo livello ho la root, ovvero la tabella dei gruppi dove trovo le voci per ogni gruppo di pagine (livelli secondari). Di conseguenza avrò pagine più piccole poiché ogni pagina del livello finale avrà solo un gruppo ristretto di voci.

Per trovare l'indirizzo fisico, ora avendo in input il numero di pagina virtuale ($N$), faccio:

$$\frac{N}{DIM}$$

Ottengo $Q$, che mi dà il gruppo, e $R$ che è l'offset del gruppo specifico da $Q$.

Se le pagine non hanno valore (bit di validità a 0) non ha senso gestire queste pagine in una struttura multilivello.

---
## Tabella delle Pagine Inversa

Usata per la gestione di pagine grandi.

- Ha una voce per ogni frame fisico della [[RAM]] (stesso numero di frame = voci).

- Qui indico nelle voci a chi ho allocato e quale pagina (`PID`, pagina virtuale). È una mappatura della RAM.

La traduzione avviene tramite numero **PID**, numero di pagina virtuale e offset. Devo cercare una voce che contiene questa coppia.

- Se la ricerca in RAM ha successo, avrò un indice $n$ ($n$-esima voce) che sarà uguale al frame corrispondente (indice $n$ = frame $n$).

- Se accade una ricerca senza successo, avviene un **[[Page Fault]]**.

Posso affiancare la **TLB** e velocizzare la ricerca tramite l'uso di tabelle hash.