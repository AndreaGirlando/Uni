# Logging

## Consegna di allenamento

Aggiungere a un programma client-server un file di log degli eventi significativi: connessione, registrazione, richiesta, allarme/errore e chiusura.

## Requisiti

- Aprire il file una sola volta quando possibile.
- Scrivere righe leggibili e complete di identificativo ed evento.
- Rendere subito visibili le righe nel file quando il programma continua a girare.
- Se più thread scrivono nel log, proteggere anche il file con lo stesso mutex appropriato o con un mutex dedicato.

## Completato quando

Il file di log permette di ricostruire, nell'ordine, cosa è successo durante un test con più client.
