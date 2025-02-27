Questo file è la rielaborazione delle slide [[03_Bus.pdf]]

---

Il **bus** è l’unità di interconnessione che permette la comunicazione tra i vari componenti della macchina di Von Neumann. Si presenta come un fascio ordinato di linee, ciascuna delle quali può rappresentare un bit. Il bus funziona quindi come un mezzo di trasporto per le informazioni tra la CPU (definita **Master**), la memoria e i dispositivi di I/O (detti **Slave**).

##### Tipologie di collegamenti
![[Pasted image 20241013094756.png|500]]
Dalla figura possiamo individuare diversi tipi di collegamenti che si instaurano nel sistema:
- **Dal processore alla memoria**
- **Dalla memoria al processore**
- **Dal processore ai dispositivi di I/O**
- **Dai dispositivi di I/O al processore**
Quando il processore agisce come Master:
- Un’operazione che trasferisce un dato dal processore alla memoria si chiama **Write**.
- Un’operazione che trasferisce un dato dalla memoria al processore si chiama **Read**.
Il tempo che intercorre tra il segnale di invio dell’operazione e la sua effettiva esecuzione è chiamato **latenza**.

---
##### Suddivisione del bus
Per gestire correttamente il trasferimento dei dati, il bus è suddiviso in tre diverse tipologie di linee:
1. **Address Bus** (_ABus_): trasporta le informazioni sugli indirizzi da utilizzare per il trasferimento.
2. **Data Bus** (_DBus_): viene utilizzato per trasferire i dati.
3. **Control Bus** (_CBus_): comprende linee dedicate a controllare il tipo e la direzione del trasferimento.

---
##### Linee del Control Bus
Le linee del **Control Bus** hanno compiti specifici:
- **I/O-Mem**: indica la direzione del trasferimento:
    - **Dal processore alle periferiche I/O**: valore impostato a **1**.
    - **Dal processore alla memoria**: valore impostato a **0**.
- **R/W**: specifica il tipo di trasferimento:
    - **Read**: valore impostato a **1**.
    - **Write**: valore impostato a **0**.
- **WAIT**: segnala lo stato del trasferimento:
    - **Trasferimento completato**: valore impostato a **1**.
    - **Trasferimento in corso**: valore impostato a **0**.

---
##### Sincronizzazione e velocità
La velocità del bus è regolata da un “orologio” interno, chiamato **clock**, che scandisce il tempo in modo costante, sincronizzando tutte le operazioni sul bus. Le dimensioni dei bus variano e influiscono sulle prestazioni del sistema, contribuendo al **collo di bottiglia** (bottleneck):
- **Address Bus (ABus)**: determina la quantità di memoria indirizzabile dai programmi. La memoria raggiungibile si calcola elevando 2 al numero di linee dell’ABus (es. un ABus a 32 bit permette di indirizzare 2³² byte di memoria).
- **Data Bus (DBus)**: rappresenta il grado di parallelismo del processore, ovvero la quantità di dati che può elaborare simultaneamente.
**Nota Bene**: ogni singolo bus trasporta un solo bit, ma la combinazione di più linee consente il trasferimento parallelo di più bit.

---
##### Chipset e bus principali
Sulla scheda madre i bus di sistema sono difficili da identificare visivamente; il loro funzionamento è gestito da linee fisiche e chip dedicati, noti con il nome di **Chipset**. Tra i vari tipi di bus, il più importante è il **PCI** (_Peripheral Component Interconnect_), ormai largamente utilizzato. La sua variante più recente, **PCI Express**, è progettata per gestire elevate velocità di trasferimento ed è particolarmente diffusa per l’uso con schede video.
