Copiare img pagina 168, 169

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

Per risolvere i problemi di **protezione** e **riposizionamento**, è stata introdotta l'astrazione dello **spazio degli indirizzi**. Lo **spazio degli indirizzi:** è l'insieme degli indirizzi che un processo può utilizzare per indirizzare la memoria. Questa è un astrazione virtuale e per essere effettuata vengono usate diverse tecniche.

###### Rilocazione dinamica: registri base e limite
Una di queste tecniche, definita come **rilocazione dinamica**, mappa lo spazio degli indirizzi di ogni processo su porzioni diverse di memoria fisica tramite hardware speciale. Questa cosa viene fatta usando due registri della CPU:
- **Registro Base:** Contiene l'indirizzo fisico di partenza del programma in memoria.
- **Registro Limite:** Contiene la lunghezza del programma.
Quando un processo accede alla memoria, l'hardware esegue due passaggi automatici:
1. **Somma:** Aggiunge il valore del registro base all'indirizzo generato dal programma prima di inviarlo al bus.
2. **Controllo:** Verifica se l'indirizzo è uguale o maggiore del valore nel registro limite; in tal caso, genera un errore e interrompe l'accesso.
Su questa soluzione possiamo dire che:
- **Vantaggi:** Permette a ogni processo di avere uno spazio privato degli indirizzi in modo semplice.
- **Svantaggi:** Ogni riferimento alla memoria richiede una somma e un confronto, il che può rappresentare un onere computazionale.
![[Pasted image 20260501112600.png|500]]
###### Gestione del sovraccarico di memoria
Spesso la RAM totale richiesta dai processi supera la memoria fisica disponibile. Per gestire questo scenario si utilizzano due strategie:
- **Swapping:** Consiste nel caricare ciascun processo nella sua interezza in memoria, eseguirlo per un certo tempo e poi riportarlo su disco per far posto ad altri. Questo processo si ripete nel tempo ("copiare" il processo tra disco e RAM).
- **Memoria virtuale:** Consente l'esecuzione di programmi anche quando sono presenti solo parzialmente nella memoria principale.
![[Pasted image 20260501112621.png|500]]

###### Allocazione e gestione dello spazio
Quando lo _swapping_ crea frammentazione (molteplici spazi vuoti sparsi), si utilizza la **Memory Compaction**: i processi vengono spostati il più in basso possibile per combinare tutti i buchi in un unico grande spazio libero. Si cerca di evitare quanto possibile questa procedura perché molto lenta.

L'allocazione è semplice se i processi hanno dimensioni fisse. Tuttavia, se i dati crescono (es. tramite lo _heap_), sorgono difficoltà, qui definiamo due soluzioni:
- **Soluzione 1:** Se un processo non ha spazio per crescere e l'area di _swap_ è piena, il processo deve essere sospeso.
- **Soluzione 2:** Una strategia preventiva consiste nell'allocare una quantità di memoria extra ogni volta che un processo viene creato o spostato, prevedendone la crescita futura. Ma è inefficiente.

Per processi con due segmenti dinamici (lo _heap_ per i dati e lo _stack_ per variabili locali e indirizzi di ritorno), la sistemazione ottimale prevede:
1. **Segmento Dati:** Posizionato subito dopo il testo del programma, cresce verso l'alto.
2. **Segmento Stack:** Posizionato in cima alla memoria allocata, cresce verso il basso.
![[Pasted image 20260501112958.png|500]]