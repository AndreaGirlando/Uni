Questa è una rielaborazione di [[04_InputOutput]]
La parte input/output di un calcolatore parte dall'acquisizione di dati e programmi, e alla rappresentazione di quest'ultimi in varie forme. Ogni dispositivo possiede un proprio range di indirizzi, inoltre hanno delle linee di sincronizzazione dette interrupt, ne esistono di 2 tipi:
- **INTR**: che segnala la richiesta di un'interruzione
- **INTA**: che segnala il suo completamento
Con il segnale INTR il dispositivo  chiede al processore di sospendere temporaneamente la sua esecuzione per eseguire un interrupt (sotto forma di una procedura **Interrupt Service Routine**), esistono anche delle routine che permettono agli interrupt di non passare dalla CPU, ed arrivare direttamente alla memoria, queste routine vengono chiamate **Direct Memory Access** (DMA), la circuiteria che è dedicata a collegarsi al bus e quindi di sincronizzarsi con altre periferiche si chiama scheda controller della periferica. Questi dispostivi prima erano fisicamente visibili ora si trovano all'interno dei circuiti interni del calcolatore 

==FINIRE CON IL RESTO DELLE SLIDE==
