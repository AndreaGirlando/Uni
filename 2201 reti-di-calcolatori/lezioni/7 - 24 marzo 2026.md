### Continuo TCP



###### Timer
è importante che il timer venga stimato nel modo corretto, perché:
- troppo piccolo: i pacchetti non arrivano in tempo
- troppo lungo: si ha una reazione lenta alla perdita di pacchetti

Come stimiamo RTT?
- *Sample RTT*: il tempo trascorso tra l'invio del pacchetto e la ricezione dell'ACK, basandoci su questo andiamo a calcolare *Estimated RTT* come di seguito: 
- *Estimated RTT*: $$\text{Estimated\_RTT}_n = (1-\alpha)*\text{Estimated\_RTT}_{n-1} + \alpha * \text{Sample\_RTT}_n$$
  il valore tipico di $\alpha$ è $0.125$

La natura variabile del RTT ci porta a voler tener conto anche della deviazione standard dei valori 
$$\text{DevRTT} = (1-\beta) \cdot \text{DevRTT} + \beta \cdot |\text{SampleRTT} - \text{EstimatedRTT}|$$
Usando questo valore andiamo a calcolare il tempo massimo di ritrasmissione **RTO(Retransmission TimeOut)** come di seguito: 
$$RTO = \text{EstimatedRTT} + 4 * DevRTT$$

Nonostante RDT stabilisca che ad un pacchetto venga associato un timer, TCP riduce la complessita di gestione gestendo esclusivamente un timer alla volta. Dopo la ricezione dell'ACK dell'n-esimo pacchetto, il timer per il segmento n + 1 non ancora acknowledged viene avviato. 

Per ridurre il tempo di attesa nasce la tecnica **Fast Retransmit**: se il sender manda tre ACK consecutivi per lo stesso pacchetto mancante (ovvero l’ACK dell’ultimo pacchetto consegnato con successo), viene attivata istantaneamente la ritrasmissione del pacchetto.

###### Controllo del flusso
 
Cosa succede se il ricevitore non è abbastanza veloce a riceve i pacchetti? 
Semplicemente viene usato un campo del pacchetto ACK chiamato *receive window* dove viene specificato dal mittente lo spazio massimo disponibile. ![[Pasted image 20260324103826.png|500]]
Per gestire in modo ottimale questa finestra usiamo un algoritmo detto *Nagle Algorithm* che sarebbe questo:

```
if available_data > 0 then
    if window_size ≥ MSS & available_data ≥ MSS then
        send_a_MSS_segment
    else
        if waiting_for_an_ack == true then
            enqueue_data /* until an acknowledge is received */
        else
            send_data
        end if
    end if
end if
```
Questo algoritmo si comporta in modo diverso in base alla rete in cui si trova:
- In reti con un basso RTT, questo algoritmo invia piccoli pacchetti con alta frequenza
- In reti con un alto RTT, i dati vengono bufferizzati e inviati in grandi pacchetti
Alcune volte per avere una forte reattività il sistema operativo disabilita questo algoritmo


###### Apertura della connessione

> [!DANGER] 
> Mi sono distratto, ha parlato di 2, 3, 4 way handshake


###### Chiusura della connessione
si usa un flag FIN dentro header TCP che viene impostato a 1 se quello è l'ultimo messaggio nella connessione.


###### Controllo di congestione
Il protocollo TCP gode di meccanismi per gestire la congestione, per ridurre la velocità di trasmissione e minimizzare i danni della congestione.

##### TCP Fairness
Ha fatto una dimostrazione