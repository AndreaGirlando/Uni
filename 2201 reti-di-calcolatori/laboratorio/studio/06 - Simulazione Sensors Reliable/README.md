# Esercizio simulato — Sensors Reliable

## Consegna

Sviluppare tre programmi: **Sensor Node**, **Central Node** e **Control Node**.

### Sensor Node

- Invia dati ogni 3 secondi tramite una comunicazione affidabile.
- I dati possibili sono temperatura, umidità e qualità dell'aria.
- Ogni sensore ha un ID univoco.
- Se la temperatura supera 30 oppure la qualità dell'aria è scarsa, entra in modalità allarme.
- In modalità allarme non invia dati del sensore.
- Quando riceve il comando di arresto dell'allarme, torna alla modalità normale.

### Central Node

- Registra un nuovo sensore quando riceve un suo messaggio.
- Se riceve temperatura maggiore di 30 o qualità dell'aria scarsa, invia un messaggio al Control Node.
- Anche questa comunicazione deve essere affidabile.
- Se il Control Node richiede di fermare l'allarme di un nodo specifico, inoltra il comando al Sensor Node interessato.

### Control Node

- Stampa gli allarmi ricevuti.
- Salva tutti gli allarmi nel file `LOG`.
- Cinque secondi dopo l'ingresso in allarme di un sensore, richiede di arrestare il suo allarme.

## Prima di scrivere codice

1. Stabilire il protocollo imposto o più adatto alla comunicazione affidabile.
2. Disegnare chi ascolta su una porta e chi si connette.
3. Definire una struttura messaggio con tipo, ID sensore e dati necessari.
4. Decidere dove il Central Node conserva le associazioni tra ID e connessioni/indirizzi.
5. Elencare i test: dato normale, ingresso in allarme, log, comando di stop e ritorno alla normalità.

