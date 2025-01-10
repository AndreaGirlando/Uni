Questo file è la rielaborazione delle slide [[07_Pipelining.pdf]]

---

Per svolgere compiti sempre più complessi in tempi ridotti è stata introdotta nei processori la tecnologia del pipelining (idea presa dalle catene di montaggio delle fabbriche) l'obbiettivo di questa tecnica è quello di parallelizzare quante più istruzioni possibili, ricordando la suddivisione delle istruzioni in 5 fasi diverse (Prelievo – Decodifica – Elaborazione – Memoria - Scrittura) nel caso migliore avremo 5 istruzioni eseguite in parallelo. Per gestire l'esecuzione in pipeline di più istruzioni abbiamo bisogno di mantenere le istruzioni tra uno stadio e l'altro, queste istruzioni vengono conservate dai **buffer interstadi**. Di seguito una pipeline perfetta dove ad un certo punto vengono eseguite 5 istruzioni contemporaneamente.
![[Pasted image 20241118132107.png|500]]
Non è sempre possibile avere la situazione ideale infatti possono avvenire dei **conflitti** che rallentano l'esecuzione della pipeline. I possibili tipi di conflitto sono:
- **Dipendenze di dato**
  Questo tipo di conflitto avviene quando un'istruzione richiede un dato da un registro e quel dato non è stato ancora aggiornato dalle istruzioni precedenti.
  ![[Pasted image 20241118132529.png]]
  L'istruzione **Substract** dovrà aspettare che l'istruzione **Add** abbia finito, questo allunga inevitabilmente la durata della pipeline perché **Substract** resta in stallo aspettando l'aggiornamento del registro **R2**, per porre un'istruzione in stallo vengono generate delle istruzioni nulle **(NOP)** che sostanzialmente creano un ciclo di inattività da parte del processore, queste istruzioni vengono generate dal compilatore o via hardware, di seguito il le istruzioni di prima con l'introduzioni di istruzioni NOP 
  ![[Pasted image 20241118133216.png]]
  In questo modo l'istruzione Substract inizia solo quando Add ha finito. 
  Per evitare cicli della CPU a vuoto si fa uso della tecnica dell'**operand forwarding**, il risultato viene salvato nei registri interstadio sin dalla fase di execute in questo modo l'istruzione che ha bisogno di quel dato non deve aspettare che l'istruzione dalla quale dipende finisca tutte le fasi ma basta che arrivi alla fase di execute.
  ![[Pasted image 20241118134101.png]]

---
###### Dipendenza del dato
  Esistono 3 tipi di dipendenze del dato che abbiamo già discusso [[05_Processore#Esistono 3 tipi di dipendenza del dato|qui]]
- **Ritardi nell'accesso alla memoria**
  Gli accessi alla memoria alcune volte necessitano di diversi cicli di clock infatti nel caso un dato non si trovi nella **cache** si possono avere ritardi di 10 o più cicli di clock, questo crea dei ritardi nell'esecuzione delle istruzioni.
  ![[Pasted image 20241118150648.png]]
- **Ritardi nei salti**
  Durante un'istruzione di salto, l'indirizzo di destinazione viene caricato nel program counter durante il passo 3, quindi le successive istruzioni che entrano nella pipeline vengono scartate
  ![[Pasted image 20241118150626.png]]
  Per ridurre i cicli di clock inutili si può modificare il l'hardware in modo da effettuare il salto direttamente nello stadio di decodifica, un'altra tecnica è quella del **salto differito** dove le istruzioni successive al salto vengono eseguite in ogni caso, sarà il compilatore a modificare l'ordine di esecuzione delle istruzioni in modo da eseguire delle istruzioni che vanno eseguite a prescindere in quei slice di tempo, se non trova istruzioni valide inserisce delle NOP. 
  
  ---
  ###### Branch penalties
  I salti vengono chiamati **Branch**, i ritardi che accadono a causa dei salti vengono chiamati **Branch Delays** oppure **Branch Penalties** questi problemi vengono risolti attraverso le **Branch Prediction**, se la predizione non va a buon fine abbiamo un **Branch Misprediction** quando avviene questa cosa viene avviato un **flush** ovvero la pulizia della pipeline, dopo aver fatto ciò la pipeline verrà riempita nel modo giusto. Esistono 2 tipi di branch prediction, la **predizione statica** usa regole semplici basate su informazioni statiche come la posizione dell'istruzione nel codice o il tipo di istruzione di salto, questo approccio statico è molto rapido e semplice ma può essere meno preciso in situazioni complesse. In questi casi si utilizza la **predizione dinamica**, una tecnica che si basa sulla storia dei branch eseguiti in precedenza. Questo approccio sfrutta i **buffer di branch prediction** (BPB), che fungono da memoria storica per migliorare l’accuratezza della predizione. Più grande è il buffer, maggiore è la precisione della predizione. Ogni branch analizzato viene associato a uno stato, che varia a seconda dell’architettura della macchina:
	-  **In alcune macchine**, gli stati possibili sono due:
		  - **PS** (Probabilmente Salta)
		  - **PNS** (Probabilmente Non Salta)
	- **In altre macchine**, il modello può essere più complesso e utilizzare quattro stati:
		 - **MPS** (Molto Probabilmente Salta)
		 - **PS** (Probabilmente Salta)
		 - **PNS** (Probabilmente Non Salta)
		 - **MPNS** (Molto Probabilmente Non Salta)
  Questo sistema consente di migliorare significativamente la predizione, adattandosi dinamicamente al comportamento dei branch.
  
> [!Info]
>   Per poter eseguire la predizione nello stadio di Fetch si ha bisogno di una memoria piccola e veloce chiamata Buffer di destinazione di salto questo contiene una tabella con tutte le istruzioni di salto del programma. Per ogni istruzione saranno salvate le seguenti informazioni:
>   - Indirizzo dell’istruzione
>   - Uno o due bit di stato per l’algoritmo di predizione
>   - Indirizzo di destinazione del salto 
>   Una volta prelevata un’istruzione, il suo indirizzo verrà cercato nella tabella, se l’istruzione prelevata è un salto si useranno le informazioni in tabella per aggiornare il program counter. In grandi programmi la tabella non contiene tutte le istruzioni di salto, ma viene aggiornata man mano.

- **Limiti di risorse**
  La pipeline va in stallo quando una risorsa viene richiesta da più istruzioni, per evitare questo problema l'unica soluzione è quella di avere cache separate per istruzione e dati.
---
###### Valutazione delle prestazioni
La valutazione delle prestazioni di un processore viene fatta sia per i processori che usano la pipeline sia per quelli che non la usano, la formula chiaramente cambia. Di seguito la legenda per capire le formule successive:
- $N$: Numero di istruzioni macchina
- $S$: Numero di cicli di clock per istruzione (CPI - _Cycles Per Instruction_)
- $T_{clock}$​: Durata di un ciclo di clock ($T_{clock}=\frac{1}{R}​$)
- $R:$ frequenza di clock del processore 

> [!TIP]
> La formula per calcolare $T$ (tempo di esecuzione) di $N$ istruzioni in un processore con pipeline è la seguente: $T = \frac{N * S}{R}$  

> [!TIP]
> La formula per calcolare il throughput di un processore è la seguente:
> **Senza pipeline:** $P_{np} = \frac{R}{S*T_{clock}}$ 
> **Con pipeline:** $P_p = \frac{R}{S}$ 
> nel caso ottimale con pipeline il throughput è uguale ad R

Come già detto la pipeline soffre di conflitti, prendendo in considerazione questi conflitti la formula per il calcolo del throughput diventa:

> [!TIP] Formula calcolo del throughput
> $P_p = \frac{R}{S + \sigma_{dato} + \sigma_{salto} + \sigma_{miss}}$ 

Ogni tipologia di conflitto indipendente aumenta S di un delta δ dato dal numero di occorrenze del conflitto $p$ per il numero medio di cicli di stallo introdotti $c$ per evitarlo: 
- Conflitti di dipendenza di dato: $\sigma_{dato}$ = $p_{dato}$ · $c_{dato}$ 
- Conflitti di salto: $\sigma_{salto}$ = $p_{dato}$ · $c_{dato}$ 
- Conflitti di cache miss: $\sigma_{miss}$ = $p_{dato}$ · $c_{dato}$

---
###### Processori superscalari
I processori con più unita di elaborazione vengono chiamati **superscalari**, nel caso di un processore con 2 unità di elaborazione:
- **Unità aritmetica**: esegue le istruzione aritmetico-logiche
- **Unità Load/Store**: esegue le istruzioni di accesso alla memoria
Nel seguente caso la pipeline di questo tipo di processore è diversa da quella di un normale processore, in specifico cambia così:
![[Pasted image 20241118213021.png|500px]]
Le istruzioni aritmetiche e di accesso alla memoria possono essere eseguite in parallelo a coppie e quindi nei primi due cicli di clock si possono mandare in esecuzione le quattro istruzioni

All'entrata di ogni unità di esecuzione troviamo una **stazione di prenotazione** dove sono presenti:
- Tutte le istruzioni in attesa di esecuzione
- Informazioni e operandi rilevanti per ogni istruzione che troviamo
Un’istruzione viene mandata in esecuzione solo quando tutti i suoi operandi sono disponibili

---
###### Fase di smistamento
Nella **fase di smistamento** il processore deve assicurarsi che tutte le risorse necessarie ad un’istruzione siano disponibili, in specifico si occupa di verificare la disponibilità dei registri temporanei per contenere i risultati, che ci sia abbastanza spazio nella stazione di prenotazione dell'unità di esecuzione desiderata, e che ci sia una locazione disponibile nel buffer di riordino, inoltre si occupa di prevenire i **deadlock** (casi in cui due istruzioni rimangono bloccate a causa di dipendenze reciproche)

---
###### Esecuzione fuori ordine
**L'esecuzione fuori ordine** può verificarsi a causa di eventi come cache miss o eccezioni, e questo comporta il rischio che un'istruzione eseguita fuori dal suo ordine previsto possa alterare in modo errato il contenuto di registri o locazioni di memoria, generando così eccezioni imprecise. Per evitare tali problemi, i risultati prodotti dalle unità di esecuzione vengono temporaneamente memorizzati in registri provvisori (che all'occorrenza assumono il ruolo dei registri permanenti grazie al processo di **register renaming**). L'unità di **commitment** si occupa di trasferire i risultati nei registri permanenti rispettando rigorosamente l'ordine di esecuzione delle istruzioni. Per rendere possibile tutto ciò, si utilizza una struttura denominata buffer di riordino, che organizza le istruzioni nel corretto ordine di prelievo, garantendo la coerenza dell'esecuzione.

---
###### Pipeline con i processori CISC
I processori **CISC** hanno diverse difficoltà nell'utilizzare le pipeline a causa della complessità delle istruzioni, per risolvere questo problema quasi tutti i processori odierni sono si basati su CISC ma le istruzioni vengono dinamicamente convertite in micro-istruzioni RISC che posso essere eseguite nella pipeline in modo più agevole.