# Esame giugno 2026 — Rete ad anello UDP

## Consegna

Sviluppare una soluzione che simuli una rete di host organizzati in un anello unidirezionale. Ogni nodo comunica direttamente soltanto con il nodo successivo; un messaggio diretto a un host non adiacente deve essere inoltrato dai nodi intermedi. Tutte le comunicazioni usano esclusivamente UDP.

## Requisiti

- Ogni host ha un identificativo univoco.
- Ogni nodo riceve dal nodo precedente e, quando necessario, inoltra al successivo.
- Deve essere possibile inviare messaggi unicast verso un host specifico.
- Deve essere possibile inviare messaggi broadcast a tutti gli host dell'anello.
- Ogni evento di comunicazione deve essere notificato a un Server di LOG via UDP.
- Il Server di LOG salva gli eventi ricevuti in un file.
- I nodi possono essere in C o C++; il Server di LOG può essere in C, C++ o Python.

## Prima di scrivere codice

1. Scegliere numero di nodi, porte e verso dell'anello.
2. Definire il datagramma: mittente, destinatario, tipo, contenuto e informazione necessaria per fermare un broadcast.
3. Disegnare un esempio di unicast e uno di broadcast fino al loro termine.
4. Stabilire quando ciascun nodo produce una notifica per il server di log.

