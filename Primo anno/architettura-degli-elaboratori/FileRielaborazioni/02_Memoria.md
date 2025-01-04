Questo file è la rielaborazione delle slide [[02_Memoria.pdf]]

La memoria dentro i nostri elaboratori ha una struttura piramidale, più si va in alto in questa piramide più la memoria diventa veloce ma si riduce di dimensione:
![[Pasted image 20241012142813.png|500]]

La **memoria principale** di un computer è costituita da un insieme di celle ordinate, ciascuna con una capacità di un byte e dotata di un indirizzo univoco. All'interno di queste celle vengono memorizzati sia le istruzioni dei software che i dati di input e output. Tuttavia, i contenuti delle celle vengono mantenuti solo finché la memoria è alimentata elettricamente, motivo per cui questa memoria viene definita **volatile**.

La maggior parte della memoria principale è realizzata con tecnologia **RAM** (_Random Access Memory_), e in particolare con una sua variante chiamata **DRAM** (_Dynamic RAM_). La DRAM è così denominata perché i dati in essa contenuti devono essere continuamente aggiornati. I tempi di lettura e scrittura della RAM, tuttavia, sono più lenti rispetto alle altre operazioni svolte da un elaboratore, creando quello che viene definito un **collo di bottiglia** (bottleneck).

Per mitigare questo problema, sono state sviluppate le **SRAM** (_Static RAM_), un tipo di RAM più veloce e stabile, ma anche più costoso. Per questo motivo, la SRAM viene utilizzata principalmente come memoria di transito tra la memoria principale e il processore, con il nome di **cache**.

Le memorie DRAM sono installate sulla scheda madre all’interno di slot chiamati **DIMM** (_Dual Inline Memory Module_), caratterizzati dalla presenza di circuiti su entrambe le facce del modulo.

Oltre alla RAM, la memoria principale include anche la **ROM** (_Read Only Memory_), una memoria di sola lettura utilizzata per conservare il **BIOS** (_Basic Input/Output System_). Il BIOS è fondamentale nella fase di avvio del computer, nota come **bootstrap**, durante la quale il dispositivo viene inizializzato correttamente. Successivamente, il BIOS esegue la fase di **POST** (_Power On Self Test_), che verifica il corretto funzionamento delle componenti hardware del sistema.

Anche se la ROM è progettata per essere di sola lettura, può essere riprogrammata in determinate circostanze, come durante le procedure di configurazione o aggiornamento del BIOS.
