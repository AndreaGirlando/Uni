# Ripasso operativo delle socket

## Obiettivo

Ricostruire senza copiare un esempio minimo TCP e uno UDP. Ogni programma deve avere un proprio `client.c`, `server.c` e, se utile, un `config.h`.

## TCP

- Il server crea la socket, assegna indirizzo e porta, ascolta e accetta una connessione.
- Il client si connette, invia un messaggio e riceve una risposta.
- Gestire la chiusura ordinata delle socket e gli errori principali.

## UDP

- Il server riceve un datagramma e risponde al mittente.
- Il client invia un datagramma e riceve la risposta.
- Conservare correttamente l'indirizzo del mittente ricevuto con `recvfrom`.

## Completato quando

Entrambe le coppie di programmi si compilano e funzionano da terminali separati, senza usare codice copiato durante il tentativo finale.
