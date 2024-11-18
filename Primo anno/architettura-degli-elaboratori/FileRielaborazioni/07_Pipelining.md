
Per svolgere compiti sempre più complessi in tempi ridotti è stata introdotta nei processori la tecnologia del pipelining (idea presa dalle catene di montaggio delle fabbriche) l'obbiettivo di questa tecnica è quello di parallelizzare quante più istruzioni possibili, ricordando la suddivisione delle istruzioni in 5 fasi diverse (Prelievo – Decodifica – Elaborazione – Memoria - Scrittura) nel caso migliore avremo 5 istruzioni eseguite in parallelo. Per gestire l'esecuzione in pipeline di più istruzioni abbiamo bisogno di mantenere le istruzioni tra uno stadio e l'altro, queste istruzioni vengono conservate dai **buffer interstadi**. Di seguito una pipeline perfetta dove ad un certo punto vengono eseguite 5 istruzioni contemporaneamente.
![[Pasted image 20241118132107.png]]
Non è sempre possibile avere la situazione ideale infatti possono avvenire dei **conflitti** che rallentano l'esecuzione della pipeline. I possibili tipi di conflitto sono:
- **Dipendenze di dato**
  Questo tipo di conflitto avviene quando un'istruzione richiede un dato da un registro e quel dato non è stato ancora aggiornato dalle istruzioni precedenti.
  ![[Pasted image 20241118132529.png]]
  L'istruzione **Substract** dovrà aspettare che l'istruzione **Add** abbia finito, questo allunga inevitabilmente la durata della pipeline perché **Substract** resta in stallo aspettando l'aggiornamento del registro **R2**, per porre un'istruzione in stallo vengono generate delle istruzioni nulle **(NOP)** che sostanzialmente creano un ciclo di inattività da parte del processore, queste istruzioni vengono generate dal compilatore o via hardware, di seguito il le istruzioni di prima con l'introduzioni di istruzioni NOP 
  ![[Pasted image 20241118133216.png]]
  In questo modo l'istruzione Substract inizia solo quando Add ha finito. 
  Per evitare cicli della CPU a vuoto si fa uso della tecnica dell'**operand forwarding**, il risultato viene salvato nei registri interstadio sin dalla fase di execute in questo modo l'istruzione che ha bisogno di quel dato non deve aspettare che l'istruzione dalla quale dipende finisca tutte le fasi ma basta che arrivi alla fase di execute.
  ![[Pasted image 20241118134101.png]]
- **Ritardi nell'accesso alla memoria**
  Gli accessi alla memoria alcune volte necessitano di diversi cicli di clock infatti nel caso un dato non si trovi nella **cache** si possono avere ritardi di 10 o più cicli di clock, questo crea dei ritardi nell'esecuzione delle istruzioni.
  ![[Pasted image 20241118150648.png]]
- **Ritardi nei salti**
  Durante un'istruzione di salto, l'indirizzo di destinazione viene caricato nel program counter durante il passo 3, quindi le successive istruzioni che entrano nella pipeline vengono scartate
  ![[Pasted image 20241118150626.png]]
  Per ridurre i cicli di clock inutili si può modificare il l'hardware in modo da effettuare il salto direttamente nello stadio di decodifica, un'altra tecnica è quella del **salto differito** dove le istruzioni successive al salto vengono eseguite in ogni caso, sarà il compilatore a modificare l'ordine di esecuzione delle istruzioni in modo da eseguire delle istruzioni che vanno eseguite a prescindere in quei slice di tempo, se non trova istruzioni valide inserisce delle NOP. I salti vengono chiamati **Branch**,i ritardi che accadono a causa dei salti vengono chiamati **Branch Delays** oppure **Branch Penalties** questi problemi vengono risolti attraverso le **Branch Prediction**, se la predizione non va a buon fine abbiamo un **Branch Misprediction** quando avviene questa cosa viene avviato un **flush** ovvero la pulizia della pipeline, dopo aver fatto ciò la pipeline verrà riempita nel modo giusto. Esistono 2 tipi di branch prediction, la **predizione statica** usa regole semplici basate su informazioni statiche come la posizione dell'istruzione nel codice o il tipo di istruzione di salto, questo approccio statico è molto rapido e semplice ma può essere meno preciso in situazioni complesse.
  
  Per affrontare situazioni complesse, si utilizza la **predizione dinamica**, una tecnica che si basa sulla storia dei branch eseguiti in precedenza. Questo approccio sfrutta i **buffer di branch prediction** (BPB), che fungono da memoria storica per migliorare l’accuratezza della predizione. Più grande è il buffer, maggiore è la precisione della predizione. Ogni branch analizzato viene associato a uno stato, che varia a seconda dell’architettura della macchina:
	-  **In alcune macchine**, gli stati possibili sono due:
		  - **PS** (Probabilmente Salta)
		  - **PNS** (Probabilmente Non Salta)
	- **In altre macchine**, il modello può essere più complesso e utilizzare quattro stati:
		 - **MPS** (Molto Probabilmente Salta)
		 - **PS** (Probabilmente Salta)
		 - **PNS** (Probabilmente Non Salta)
		 - **MPNS** (Molto Probabilmente Non Salta)
  Questo sistema consente di migliorare significativamente la predizione, adattandosi dinamicamente al comportamento dei branch.
  Per poter eseguire la predizione nello stadio di Fetch si ha bisogno di una memoria piccola e veloce chiamata Buffer di destinazione di salto questo contiene una tabella con tutte le istruzioni di salto del programma. Per ogni istruzione saranno salvate le seguenti informazioni:
  - Indirizzo dell’istruzione
  - Uno o due bit di stato per l’algoritmo di predizione
  - Indirizzo di destinazione del salto 
  Una volta prelevata un’istruzione, il suo indirizzo verrà cercato nella tabella se l’istruzione prelevata è un salto si useranno le informazioni in tabella per aggiornare il program counter per grandi programmi la tabella non contiene tutte le istruzioni di salto, ma viene aggiornata man mano.

- **Limiti di risorse**
  La pipeline va in stallo quando una risorsa viene richiesta da più istruzioni, per evitare questo problema l'unica soluzione è quella di avere cache separate per istruzione e dati.

==CONTINUARE DA SLIDE 19==