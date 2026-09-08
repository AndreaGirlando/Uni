# Esame vecchio — Gestione risorse UDP

## Consegna

Realizzare un servizio di gestione di risorse tra un solo server e più client usando UDP.

Sul server è presente il file iniziale [`server/risorse.txt`](server/risorse.txt), con campi separati dal carattere `#`:

```text
nome_risorsa#quantità#ID#ID...
```

Ogni client possiede un ID univoco a 32 bit. Quando una risorsa viene assegnata a un client, il suo ID viene aggiunto alla riga della risorsa.

Un client può:

1. chiedere l'elenco delle risorse disponibili, cioè con quantità maggiore di zero;
2. chiedere l'elenco delle risorse già riservate a se stesso;
3. bloccare una risorsa.

Il server risponde con un messaggio che indica il successo o il fallimento dell'operazione. L'operazione di blocco deve inoltre essere notificata a tutti i client registrati, per conoscenza.

Usare C o C++.

## Prima di scrivere codice

- Definire il formato dei datagrammi di richiesta, risposta e notifica.
- Decidere come registrare indirizzo e porta di ogni client UDP.
- Separare lettura/aggiornamento del file dalla logica di rete.
- Predisporre un file iniziale di risorse e testare il caso di quantità esaurita.

