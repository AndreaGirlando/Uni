# Server concorrente

## Perché esiste questo esercizio

Non è una traccia d'esame: è un esercizio breve per imparare il meccanismo che ricompare negli esami. Il server deve parlare con più client **nello stesso momento** e deve proteggere i dati che tutti i thread usano in comune.

Pensa a una reception: il server principale accetta ogni persona che arriva e assegna un addetto diverso a ciascuna. Il registro della reception, però, è uno solo: due addetti non possono modificarlo contemporaneamente.

## Consegna precisa

Realizzare un server TCP che conserva al massimo 10 record:

```text
ID client | ultimo valore inviato
```

Ogni client, dopo essersi connesso, può inviare uno dei seguenti comandi testuali:

```text
REG <id>             registra il client se non è già presente
SET <id> <valore>    aggiorna l'ultimo valore del client registrato
LIST                 richiede tutti i record presenti
QUIT                 chiude la propria connessione
```

Per ogni comando il server invia una risposta chiara: successo, errore oppure elenco dei record.

## Come deve funzionare

1. Il thread principale del server esegue `accept` in un ciclo.
2. Per ogni socket restituita da `accept`, crea un nuovo thread e gli passa **quella socket**.
3. Il thread legge i comandi del proprio client e risponde.
4. Quando il thread deve leggere o modificare l'array dei 10 record, esegue prima `pthread_mutex_lock` e dopo `pthread_mutex_unlock`.
5. Quando il client invia `QUIT` o chiude la connessione, solo il suo thread termina e chiude la sua socket. Il server continua ad accettare altri client.

## Cosa è condiviso e cosa no

| Dato | È condiviso? | Mutex? |
| --- | --- | --- |
| Socket del singolo client | No, appartiene al suo thread | No |
| Buffer usato per leggere un comando | No, deve essere locale al thread | No |
| Array dei 10 record | Sì, tutti i thread lo leggono/modificano | Sì |
| Contatore dei record registrati | Sì | Sì |

## Test minimo

Avvia due client: entrambi fanno `REG`, poi aggiornano il proprio valore con `SET`; infine uno richiede `LIST`. L'elenco deve contenere entrambi i record corretti.

## File

Mettere le sorgenti in `src/`. L'obiettivo non è un protocollo sofisticato: è saper usare correttamente `accept`, thread, socket per client e mutex.
