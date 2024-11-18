L'operazione NOP è l'istruzione vuota o inattiva la quale non esegue nessuna operazione, la sua funzione principale è quella di occupare uno slot in modo da ordinare, questo permette alle operazioni sincrone di completare il loro ciclo senza creare problemi di dipendenza del dato. Viene usata per creare delle pause controllate.

Si preferisce il forwarding alle operazioni di NOP perché evita gli stalli. L'utilizzo del forwarding però può favorire i casi di dipendenze del dato

Usando istruzioni NOP
![[Pasted image 20241106174044.png]]
Usando il forwading RAM con latenza più bassa
![[Pasted image 20241106174133.png]]

Tecniche per evitare i ritardi dovuti all'accesso alla CPU
- **Gerarchia delle cache**: Una gestione ottimale dei vari livelli delle cache
- **Prefetching**: caricando i dati prima del loro utilizzo riduce i tempi di accesso
- **RAM con latenza più bassa**: in modo da ridurre il problema alla radice

I salti vengono chiamati **Branch**,  ritardi che accadono a causa dei salti vengono chiamati **Branch Delays** oppure **Branch Penalties** questi problemi vengono risolti attraverso le **Branch Prediction**, se la predizione non va ha buon fine abbiamo un **Branch Misprediction** quando avviene questa cosa viene avviato un **flush** ovvero la pulizia della pipeline, per evitare di mettere in esecuzione istruzioni errate, dopo aver fatto ciò la pipeline verrà riempita nel modo giusto.

Predizione statica usa regole semplici basate su informazioni statiche come la posizione dell'istruzione nel codice o il tipo di istruzione di salto, questo approccio statico è molto rapido e semplice ma può essere meno preciso in situazioni complesse. Per queste situazioni complesse si preferisce usare la predizione dinamica è basata sulla storia dei branch precedentemente eseguiti e quindi usa dei buffer di branch prediction (BPB) e come storico per fare una predizione più precisa, chiaramente più è grande il buffer più è precisa la predizione.