
Un'**algoritmo** è un insieme finito di istruzioni usate per la risoluzione di un certo lavoro. Quest'ultimo molte volte viene definito come una particolare macchina di Turing (Alan Turing, matematico britannico) oppure come una macchina di [[#Macchina di Von Neumann]] (matematico statunitense).

Le funzioni di base di un'elaboratore possono essere riassunte in 4 macro aree:
- memorizzazione dei dati
- elaborazione dei dati
- trasferimento dei dati
- controllo.

Uno esempio di elaboratore è il **computer**, il computer è una macchina che computa ovvero che esegue un certo algoritmo (ovviamente scritto in modo che la macchina stessa lo possa interpretare). Esistono vari tipi di computer: 
- Laptop
- Server
- Desktop
- Tablet/Smartphone

Un qualsiasi computer moderno segue la seguente architettura:
###### <mark style="background: #FF5582A6;">La macchina di Von Neumann</mark>

![[Pasted image 20241004212308.png]]
Questo tipo di architettura viene chiamata [[#Macchina di Von Neumann]] (questa è l'architettura alla quale fa riferimento la definizione di algoritmo sopracitata). Di seguito una descrizione di tutti i componenti.
- La **CPU**, o **Central Processing Unit**, è l'unità centrale di elaborazione di un computer. È il componente principale che esegue le istruzioni dei programmi, gestisce le operazioni logiche e aritmetiche, e coordina il funzionamento delle altre parti del sistema. Come memoria di lavoro usa i registri e la cache. La sua velocita si misura in numero di cicli al secondo (MHz o GHz)
- La **memoria**, è un deposito di dati e di istruzioni da eseguire, ne esistono di 3:
	- **ROM**, o **Read Only Memory**, è una memoria di sola lettura non volatile dove si trovano tutte varie informazioni come le istruzioni usate per l'avvio del pc, o dei parametri necessari per il coretto funzionamento del dispositivo
	- **RAM**, o **Random Access Memory**, è una memoria volative utilizzato per immagazzinare tutte quelle istruzioni che poi vengono eseguite dal processore
	- La **cache** è una memoria ad alta velocità che si trova all'interno o vicino alla CPU e viene utilizzata per immagazzinare temporaneamente i dati e le istruzioni più frequentemente utilizzati. La sua funzione principale è quella di ridurre i tempi di accesso alla RAM migliorando così le prestazioni del sistema e quindi riducendo [[#Bottleneck]] tra CPU e RAM.
- ==**Dispositivi di input**==: come un tastiera ed un mouse
- ==**Dispositivi di output**==: come un monitor o una stampante
- ==**Memoria di massa**==: un tipo di memoria non volatile che viene usata per immagazzinare grandi file, e ovviamente molto più lenta di qualsiasi altro tipo di memoria sopracitata. La memoria di massa è fondamentale per garantire l'archiviazione stabile di software, documenti, immagini e altri dati digitali, rendendoli accessibili nel tempo. Degli esempi sono: 
	- **Hard disk drive (HDD)**: basato su dischi magnetici rotanti.
	- **Solid State Drive (SSD)**: usa chip di memoria flash, più veloce e resistente rispetto agli HDD.
- ==**BUS**==, tutte queste componenti comunicano tra di loro attraverso i bus. I principali tipi di bus vengono usati per inviare dati o segnali di controllo

La macchina di von Neumann viene definita logicamente come una terna, ovvero un'insieme di 3 elementi:
- **N** = {0,1,2,3} ovvero l'insieme dei numeri naturali (l'alfabeto della macchina)
- **IS** = {ZERO, INC, SOM, SOT, MOL, DIV, UGUALE, MINORE, SALCOND, ALT} è l’Instruction Set set ovvero un'insieme di istruzioni che la macchina può usare
- P =  {I0, I1, I2, I3, … , I|P| – 1} è una sequenza finita di istruzioni prese dall'insieme IS
Come possiamo ben notare un programma eseguibile dalla macchina von Neumann consiste in una lista di istruzioni che devono essere eseguite dal processore. Ogni istruzione viene sottoposta al ciclo macchina ovvero una serie di passaggi impiegati per l'esecuzione dell'istruzione stessa, di seguito i passaggi appena citati:
1. ==**Legge il contenuto del program counter**==: ovvero l'indirizzo della prossima istruzione da eseguire.
2. ==**Caricamento nel registro delle istruzioni (fetch)**==: Il processore va a recuperare l'istruzione dalla memoria, utilizzando l'indirizzo letto da program counter. Questa istruzione viene quindi inserita nel **registro delle istruzioni**.
3. ==**Decodifica dell'istruzione**==: Una volta che l'istruzione è stata caricata, il processore la decodifica, per capire di che tipo di istruzione si tratta
4. ==**Invio all'ALU**==: Se l'istruzione richiede un'operazione aritmetica o logica, la **unità logico-aritmetica** (ALU) riceve l'istruzione e i dati necessari per eseguire l'operazione.
5. ==**Accesso ai dati**==: Se l'istruzione da eseguire richiede dei dati la control unit li recupera dalla memoria. Se l'istruzione è del tipo SOM(M1, M2), significa che M1 e M2 sono indirizzi in memoria da cui vengono presi i dati. 
6. ==**Esecuzione**==: L'ALU effettua l'operazione richiesta (ad esempio, somma o confronto) utilizzando i dati forniti.
7. ==**Memorizzazione del risultato**==: Una volta ottenuto il risultato, viene registrato nella **locazione di memoria** specificata dall'istruzione.
8. ==**Aggiornamento del contatore**==: Il program counter viene incrementato per puntare all'istruzione successiva.
9. ==**Ripetizione del ciclo**==: Questo ciclo continua fino a quando non viene incontrata un'istruzione speciale che ferma o altera l'esecuzione, come un'istruzione ALT o un salto condizionato che modifica il flusso del programma. 


Un altro modello di elaboratore dalla quale Von Neumann prese spunto fu:
###### <mark style="background: #FF5582A6;">La macchina di Turing</mark>
Una **macchina di Turing** è stata inventata da Alan Turing nel 1936. Questo modello è fondamentale nella teoria della computabilità e fornisce una rappresentazione astratta di come funzionano i calcolatori. Formalmente viene definita in questo modo:
![[Pasted image 20241005110025.png]]
Di seguito una descrizione di tutti i componenti:
- Un nastro
- TSL (Testina di lettura/scrittura)
- Memoria di controllo
- Unità logica
- Memoria interna

---
###### <mark style="background: #D2B3FFA6;">Bottleneck</mark>
La CPU è progettata per operare a velocità estremamente elevate, elaborando milioni di istruzioni al secondo. Tuttavia, la RAM, sebbene veloce, ha tempi di accesso più lunghi quando la CPU richiede dati o istruzioni deve attendere che questi vengano recuperati dalla RAM. Questo processo di attesa genera un rallentamento, poiché la CPU rimane inattiva in attesa dei dati necessari per continuare l'elaborazione. Per mitigare questo problema, le CPU fanno uso della cache, una memoria più veloce e più vicina al processore, dove vengono conservati i dati e le istruzioni più frequentemente utilizzati. Tuttavia, anche con l'uso della cache, il bottleneck rimane una preoccupazione, specialmente in scenari di carico elevato o quando vengono eseguiti più processi contemporaneamente. In questi casi, se la RAM non è in grado di tenere il passo con le richieste della CPU, si crea un rallentamento significativo, influenzando negativamente l'efficienza complessiva del sistema. 
