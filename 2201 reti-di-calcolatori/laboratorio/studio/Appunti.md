Tra un client e un serve possiamo ovviamente inviare anche delle struct 
![[Pasted image 20260908205203.png]]struct di questo tipo ci permetto di creare dei veri e propri protocolli: 
- il client invia questo tipo di messaggio e il server risponde in modo diverso in base al msg_type che sto usando

per consentire la connessione di più client mi basta salvare le seguenti informazioni![[Pasted image 20260908205426.png]]sockfd è il valore ritornato dalla accept alla quale passerò anche clientInfo->address, in modo che la struct con i parametri del client venga salvata. Inoltre userò ovviamente diversi thread (idealmente uno per ogni client che si collega). 

Anche nel client idealmente avrò un thread per inviare i dati e uno per riceverli - nel caso in cui sia necessario che queste due azioni siano asicrone

La comunicazione con più client diventa più semplice in udp - posso fare tutto usando una singola socket (per quanto riguardo il lato server)