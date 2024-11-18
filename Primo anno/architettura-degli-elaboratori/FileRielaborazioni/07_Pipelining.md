
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
- **Ritardi nei salti**
- **Limiti di risorse**
