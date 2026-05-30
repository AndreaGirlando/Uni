**Il Framework delle 4 Fasi**
- **Fase 1: Il "Pacchetto" di Ritorno (La progettazione) 📦**
    - È il passaggio più importante. Chiediti: _"Se io sono un nodo genitore, quali informazioni _separate_ mi servono dai miei figli per calcolare tutte le mie opzioni?"_
    - Quasi mai basta il record globale. Spesso serve lo stato di un cammino continuo (come in `Black-Run`) o gli scenari condizionali (come "preso/non_preso" nella `Somma Massima`).
- **Fase 2: Il Caso Base 🧱**
    - Cosa deve restituire un nodo inesistente (`NIL`)?
    - I valori del pacchetto per un nodo `NIL` (es. `0`, `1`, `-\infty`) devono essere scelti in modo da "non fare danni" e non sballare le formule matematiche dei genitori.
- **Fase 3: La Delega 🔄**
    - Questa è la parte meccanica. Il nodo corrente chiama la funzione sui figli per ottenere i pacchetti pronti:
    - `(dati_sx) = F(x.sinistro)`
    - `(dati_dx) = F(x.destro)`
- **Fase 4: La Sintesi (Il lavoro del nodo corrente) 🧠**
    - Ora il nodo corrente usa il pacchetto sinistro, il pacchetto destro e i propri dati (colore, moneta, valore) per calcolare il _suo_ pacchetto personale da passare al livello superiore.

### 1. Quando usare la logica del "Pacchetto" (Accumulo / Kadane)

Usi questa logica quando il problema ti obbliga a prendere **elementi rigorosamente contigui (consecutivi e senza interruzioni)**.
- **Parole chiave nel testo:** _Sottostringa (Substring)_, _Sottoarray (Subarray)_, _Segmento_, _Sequenza contigua_, _Taglio/Divisione netta_.
- **La regola:** Non puoi fare "salti". Se prendi l'elemento all'indice $i$ e quello all'indice $i+2$, devi _per forza_ prendere anche l'elemento $i+1$.
- **Perché funziona il pacchetto?** Poiché non puoi fare salti, appena una condizione fallisce (es. il numero diventa più piccolo, oppure la somma diventa negativa), **l'intera catena è morta e non potrà mai più essere recuperata**. Puoi permetterti di resettare il tuo "pacchetto locale" e ripartire dall'elemento corrente, mantenendo in memoria solo il "record storico" (il massimo globale).
### 2. Quando usare la logica "Scelgo / Non Scelgo" (Albero Ricorsivo)

Usi questa logica quando il problema ti permette di fare **salti** tra un elemento e l'altro, ignorando gli elementi che non ti piacciono o che non rispettano le regole.
- **Parole chiave nel testo:** _Sottosequenza (Subsequence)_, _Sottoinsieme (Subset)_, _Elementi non adiacenti_, _Combinazione_, _Zaino (Knapsack)_.
- **La regola:** Puoi saltare gli elementi. Puoi prendere l'indice $0$, saltare l'$1$ e il $2$, e prendere il $3$.
- **Perché DEVI usare l'albero decisionale?** Perché se un elemento non va bene o rovina la tua sequenza, **non significa che la catena sia morta**. Significa solo che _quell'elemento_ specifico va scartato. La sequenza costruita fino a quel momento è "in pausa", viva e vegeta, pronta ad agganciarsi a un elemento valido che potrebbe comparire molto più avanti nell'array. L'unico modo per gestire queste pause è sdoppiare l'universo: in un ramo lo prendi, nell'altro lo ignori e vai avanti.
  
  
Nel caso di problemi complessi che chiedono di ottimizzare qualcosa (max/min) rispettando una certa condizione bisogna seguire un pattern logico per evitare di perdersi:
	  
## Il Pattern Universale dell'Ottimizzazione Vincolata
**1. L'Obiettivo Globale (La Ricorsione)** La funzione principale non si preoccupa dei dettagli intermedi, ma punta dritta al problema grande: _"Qual è il minimo assoluto per questo input?"_. Restituisce sempre un numero (il costo, il numero di tagli, il valore massimo).
**2. L'Esplorazione (Il ciclo `for`)** Siccome non hai la palla di vetro e non sai a priori _dove_ convenga fare il taglio (o quale elemento scegliere), deleghi il dubbio a un ciclo `for`. Il `for` dice: _"Non so quale sia la scelta giusta, quindi le provo sistematicamente **tutte**"_.
**3. Il Filtro di Validità (L'`if` con la condizione)** Dentro il `for`, prima di fare qualsiasi calcolo, metti il "buttafuori". È qui che applichi la condizione del problema (es. `if is_palindromo()`).
- Rispetta la regola? Ottimo, calcoliamo il costo.
- Non la rispetta? Ignoriamo questa strada e passiamo alla prossima iterazione del `for`.
**4. L'Aggiornamento dell'Ottimo (Il `min` / `max`)** Se la strada era valida, sommi il costo dell'azione appena fatta (es. `1` taglio) al costo del problema rimanente calcolato magicamente dalla ricorsione. Poi lo confronti con il tuo "record" attuale e, se è migliore, lo aggiorni.
### Perché funziona così bene?
Questo schema mentale è potente perché **separa le responsabilità**:
- Non devi scrivere una ricorsione complicatissima che cerca di indovinare la mossa giusta.
- Scrivi una logica "stupida" ma esaustiva (il `for`) che esplora l'intero albero delle possibilità, e usi l'`if` per potare all'istante i rami secchi o illegali (tecnica del _Pruning_).
Problemi come il _Matrix Chain Multiplication_ (moltiplicazione di catene di matrici), la parentesizzazione ottima, o il taglio del tubo di metallo (_Rod Cutting_), si risolvono **esattamente** con questa tua stessa identica frase logica: un `for` che prova tutti i tagli, un controllo di validità, e un `min` o `max` che raccoglie il risultato migliore.

Un esempio:
## Il Problema: Decodifica del Messaggio (Word Break Minimization)

Hai una stringa $S$ lunga $n$ caratteri che rappresenta un messaggio inviato senza spazi (es. "ilmarebello"). Hai a disposizione anche un dizionario $D$ che contiene l'elenco di tutte le parole valide della lingua italiana.

**L'obiettivo:** Vuoi suddividere la stringa $S$ nel **minor numero possibile di parole**, in modo che _ogni singolo pezzo_ tagliato sia una parola valida presente nel dizionario $D$.

_Nota:_ Supponi di avere già a disposizione una funzione di supporto `is_valida(S, i, j)` che restituisce `true` se la sottostringa $S[i \dots j]$ è presente nel dizionario, e `false` altrimenti (esattamente come avevi `is_palindromo`).

```
dec(S, n)
    // 1. Obiettivo (Caso base)
    if n == 0 return 0
    
    mink = +inf
    
    // 2. Esplorazione: provo a tagliare in tutti i punti 'i' possibili
    for i = 1 to n do
        
        // 3. Filtro: la parte finale da 'i' a 'n' è una parola sensata?
        if is_valida(S, i, n) then 
            
            // Se S[i..n] è una parola (1 taglio), ora devo decodificare il pezzo S[1..i-1]
            corr = 1 + dec(S, i - 1)
            
            // 4. Aggiornamento dell'ottimo
            if corr < mink then
                mink = corr

    return mink

```