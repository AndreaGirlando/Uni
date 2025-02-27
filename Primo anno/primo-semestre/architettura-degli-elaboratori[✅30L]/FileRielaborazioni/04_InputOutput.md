Questo file è la rielaborazione delle slide [[04_InputOutput.pdf]]

---

I dispositivi di input/output sono essenziali per acquisire dati dall’utente e per rappresentarli. Ogni dispositivo è associato a un proprio intervallo di indirizzi e utilizza linee di sincronizzazione, chiamate **interrupt**, per comunicare con il processore. Esistono due principali tipi di interrupt:

- **INTR**: segnala una richiesta di interruzione al processore.
- **INTA**: conferma l’avvenuta gestione dell’interruzione.

Quando il dispositivo invia un segnale **INTR**, richiede al processore di sospendere temporaneamente la sua esecuzione per gestire l’interrupt, eseguendo una specifica procedura chiamata **Interrupt Service Routine** (ISR). Esistono anche modalità che permettono agli interrupt di bypassare la CPU e accedere direttamente alla memoria, tramite una procedura chiamata **Direct Memory Access** (DMA). La circuiteria dedicata a collegare il dispositivo al bus e a sincronizzarlo con le altre periferiche è detta **controller della periferica**. Un tempo, questi dispositivi erano fisicamente visibili all'esterno del computer, mentre oggi si trovano integrati nei circuiti interni. In passato, indirizzi, canali e linee dovevano essere configurati manualmente dall'utente o da un tecnico. Tuttavia, grazie alla tecnologia **Plug&Play** il BIOS, il sistema operativo e il firmware cooperano per gestire automaticamente la configurazione delle periferiche, sia all’avvio del computer che durante l’installazione di nuovi dispositivi.

Tra gli standard di connessione più diffusi, troviamo: **USB** (Universal Serial Bus), **FireWire** (o IEEE 1394), e **Ethernet** (802.x).
