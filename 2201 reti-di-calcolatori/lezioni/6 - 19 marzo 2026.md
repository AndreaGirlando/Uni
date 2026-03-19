### Throughput
il throughput è un indice della capacità di trasmissione in un canale di comunicazione
![[Pasted image 20260319101419.png|500]]
Consideriamo un canale con *Bandwidth* di 10 Mbps ovvero: $$BW = 10 \text{ Mbps } = 10^7 \text{ bit per secondo }$$da questo ne traiamo che:
- in $1 s \rightarrow 10000000 \; bits$
- in $0.1  \micro s \rightarrow 1 \; bits$
Se volessimo inviare un Frame di $1500$ bytes ovvero $12000$ bits impieghiamo: 
$$T_{\mathrm{frame}} = \frac{\text{Dimensione del frame (in bit)}}{\text{Bandwidth (in bit/s)}}$$

il nostro segnale si deve propagare da $A$  a $B$, quindi dobbiamo mettere in considerazione anche il tempo di propagazione del segnale, di seguito in dettaglio:
$$T_{\mathrm{propagazione}} = \frac{\text{Spazio di trasmissione}}{\text{Velocità di trasmissione}}$$

Con questa informazione possiamo calcolare anche il numero di bit che possono stare contemporaneamente nel canale:
$$\text{Bandwidth (in bit/s)} \cdot T_{\mathrm{propagazione}}(\text{in s})$$

Date tutte queste informazioni possiamo calcolare il **throughput teorico** è:
$$T = T_{\text{frame}} + T_{\text{propagazione}}$$
Per calcolare il **throughput reale** dobbiamo considerare il tempo di $ACK$ e il tempo di $RTT$(Round-Trip Time) ovvero il tempo di andata e ritorno, la formula diventa:
$$T = T_{\text{frame}} + RTT + T_{\text{propagazione}} + T_{\text{ACK}}$$
$$T_{ACK} = \frac{\text{Dimensione dell'ACK (in bit)}}{\text{Bandwidth (in bit/s)}}$$
$RTT$ lo dà l'esercizio
![[Pasted image 20260319105431.png|500]]

La modalità pipeline ci consente di aumentare il throughput di una rete. Invece di inviare un singolo frame ne inviamo $n$ e aspettiamo $n$ $ACK$, capiamo subito che è molto importante gestire  i casi in cui il frame si rovina e l'ACK di risposta non arriva, usiamo principalmente questi due algoritmi:
- **Go-Back-N (GBN)**: *Se si perde un pacchetto, si rimanda tutto da quel punto in poi.*
	* **Finestra di invio:** Il mittente può inviare fino a $N$ pacchetti senza aspettare conferma (ACK).
	* **Ricezione:** Il destinatario accetta i pacchetti solo in ordine rigoroso. Se arriva un pacchetto fuori sequenza, lo scarta.
	* **Gestione degli errori:** Se il pacchetto $3$ va perso nel canale, il destinatario ignorerà i pacchetti $4$, $5$, ecc. Quando il timer del mittente scade per il pacchetto $3,$ il mittente ritrasmette il pacchetto $3$ e tutti i pacchetti successivi già inviati (torna indietro a N).
- **Selective repeat**:  *Se si perde un pacchetto, si rimanda SOLO quello perso.*
	* **Finestra di invio:** Simile al GBN, il mittente invia fino a $N$ pacchetti senza aspettare l'ACK.
	* **Ricezione:** Il destinatario accetta i pacchetti fuori ordine e li **salva in un buffer**, inviando un ACK individuale per ogni pacchetto ricevuto correttamente.
	* **Gestione degli errori:** Se il pacchetto $3$ va perso ma il $4$ e il $5$ arrivano, il destinatario memorizza $4$ e $5$. Quando scade il timer del mittente per il pacchetto $3$, il mittente ritrasmette solo e unicamente il pacchetto $3$.

**Rumore**: dobbiamo mettere in considerazione anche il rumore, ovvero il disturbo al nostro segnale durante la sua trasmissione. 

Con questa foto vediamo le differenze tra TCP e UDP
![[Pasted image 20260319110552.png|300]]

---
### TCP
Nella ricostruzione delle versioni di TCP si dice siano 4 versioni, ma non è vero è una sola quella del $1981$. Il TCP ha diverse feature:
* Addressing/Multiplexing
* Connection Establishment, Management and Termination
* Data Handling and Packaging
* Data Transfer
* Providing Reliability and Transmission Quality Services
* Providing Flow Control and Congestion Avoidance Features
L'ultima è quella sulla quale stanno lavorando i ricercatori, per migliorarla. Ci sono delle cose che TCP non provvede: 
- Non offre sicurezza
- Non garantisce una comunicazione
- Non mantiene i *message boundaries* ovvero i confini del messaggio, queste servono per riuscire ad interpretare e ricostruire messaggi.

Di seguito la struttura del pacchetto TCP:
![[Pasted image 20260319115102.png|500]]
Troviamo diverse informazioni:
- **Destinatione e Source Port**
- **Sequence Number:** Campo di 32 bit che indica il numero di sequenza del primo byte dei dati contenuti nel segmento TCP.
	- _Esempio pratico:_ Supponiamo che tu debba inviare 500 byte di dati. Il pacchetto parte con un Sequence Number impostato a `1000`. Questo significa che il pacchetto contiene i byte che vanno dal numero `1000` al `1499`.
- **Acknowledgment Number (ACK):** Campo di 32 bit che indica il numero di sequenza del prossimo byte che il ricevitore si aspetta di ricevere (conferma cumulativa).
	- _Esempio pratico:_ Il destinatario riceve il tuo pacchetto con i byte dal `1000` al `1499`. Per dirti che è andato tutto bene, ti manda indietro un messaggio con l'ACK impostato a `1500`. Ti sta letteralmente dicendo: "Perfetto, ho tutto fino al 1499. Ora sto aspettando che mi mandi il byte 1500".
- **ecc...**

Tutto questo rende TCP affidabile ma non molto veloce, tuttavia anche il througput è un fattore da tenere in considerazione, per analizzarlo dobbiamo analizzare una serie di parametri:
- **MSS(Maximum Segment Size)**: Indica la dimensione massima dei dati che possono essere inviati in un singolo segmento TCP
- **MTU(Maximum Tramission Unit)**: $MSS+$$Header TCP+$$HeaderIP$ 

Un'altro dato importante è RTT(Round Trip TIme), questo tempo viene continuamente stimato in questo modo:
- Per ogni comunicazione viene misurato il tempo che trascorre tra l'invio del pacchetto e il ritorno di un ipotetico ACK
- Viene fatta la media di tutti i tempi salvati
è importante che RTT siano stimato bene perché:
- RTT troppo lungo: si ha una reazione troppo lenta alla perdita di pacchetti
- RTT troppo corto: gli ACK potrebbero non arrivare in tempo
il calcolo del RTT viene fatto ad ogni invio di pacchetto, in modo che TCP sappia quanto aspettare. Il tipo di media che viene usata si chiama: **Exponential Weighted Moving Average**.  (Moving perché si muove un valore avanti ad ogni pacchetto)


> [!DANGER] Da integrare
> Deviazione standard media dei pacchetti e calcolo del timeout effettivo


A differenza dei modelli teorici RDT (che prevedono un timer per ogni singolo pacchetto), TCP riduce la complessità del sistema utilizzando **un solo timer di ritrasmissione globale**.

Funziona in questo modo: quando TCP riceve un ACK che conferma un pacchetto, resetta il timer. Se ci sono altri dati già inviati ma non ancora confermati, il timer viene immediatamente riavviato per monitorare il segmento "più vecchio" ancora in volo (ad esempio, il segmento successivo _n+1_ in attesa di ACK).


Per adattarsi alle condizioni della rete, TCP calcola dinamicamente il timer di ritrasmissione attraverso questi 4 passaggi:
1. **SampleRTT (Campione):** Misurazione del tempo effettivo trascorso tra l'invio di un singolo segmento e la ricezione del suo ACK.
2. **EstimatedRTT (Tempo stimato):** Media mobile ponderata dei campioni precedenti. Serve a "smussare" i picchi e le anomalie temporanee della rete.
3. **DevRTT (Deviazione):** Calcolo della variabilità del RTT. Funge da margine di sicurezza per evitare timeout prematuri.
4. **RTO (Retransmission Timeout):** Il timer effettivo da utilizzare, calcolato come la somma del tempo stimato più il margine di sicurezza $$EstimatedRTT + 4 * DevRTT$$
la formula dell'RTO è progettata per essere prudente, il timer finale calcolato risulta spesso **molto lungo**. Se un pacchetto viene perso, aspettare la scadenza di questo timer causa un lungo periodo di inattività e rallenta la trasmissione. Per mettere una pezza a questo problema di latenza, TCP utilizza un meccanismo chiamato **Fast Retransmit** (Ritrasmissione Rapida):
- Se il ricevitore rileva un "buco" nei pacchetti, continua a mandare ACK con il numero del pacchetto mancante.
- Se il mittente riceve **3 ACK duplicati** di fila, deduce con certezza che il pacchetto successivo è andato perso.
- A questo punto il mittente **ritrasmette immediatamente il pacchetto**, senza aspettare che il lungo timer RTO scada.