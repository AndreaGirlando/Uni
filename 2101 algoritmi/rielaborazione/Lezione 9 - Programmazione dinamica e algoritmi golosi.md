# Programmazione dinamica 
### Introduzione
###### Definizione
la programmazione dinamica si applica ai *problemi di ottimizzazione*, questi problemi hanno molteplici soluzioni possibili, per capire quale soluzione è la migliore definiamo la funzione *bontà* che assegna ad ogni soluzione un grado di bontà. 

###### Sviluppare un algoritmo di programmazione dinamica
Lo sviluppo di un algoritmo di programmazione dinamica si può essere suddiviso in queste fasi:
1. Caratterizzazione di una sotto-struttura ottima
2. Definire in modo ricorsivo il valore di una soluzione ottima
3. Costruire una procedura bottom-up per il calcolo di una soluzione ottima
4. Costruire una soluzione ottima dalle informazioni calcolate

Le fasi dalla 1 alla 3 formano la base per risolvere un problema applicando la programmazione dinamica. La fase 4 può essere omessa se è richiesto soltanto il valore di una soluzione ottima. Infine ricordiamo che: 
- Approcciare un problema in maniera *top-down* vuol dire risolverlo in maniera *ricorsiva*
- Approcciare un problema in maniera *bottom-up* vuol dire risolverlo in maniera *iterativa*
### Fibonacci
###### Definizione
La sequenza di Fibonacci è definita dalla seguente equazione:
$$
F_n = 
\begin{cases} 
1 & \text{se } n \leq 2 \\
F_{n-1} + F_{n-2} & \text{se } n > 2 
\end{cases}
$$
L'implementazione diretta che ne facciamo è:
```
F(n):
    if n <= 2 then
        return 1
    else
        return F(n-2) + F(n-1)
```
![[Pasted image 20251224100247.png|500]]
Guardando l'albero di ricorsione si nota subito che alcuni sotto-problemi vengono risolti più volte, questo è ovviamente un problema che ci fa perdere tempo. Quello che facciamo è rendere un caso base ogni sotto-problema risolto
```
// Inizializzazione
M = new Array(n) // array che contiene la soluzione
M[1] = M[2] = 1
for i = 3 to n DO M[i] <- NULL // inizializzazione

F(n)
    if M[n] != null then
        return M[n]
    
    if M[n-1] == null then
        M[n-1] <- F(n-1)
    
    if M[n-2] == null then
        M[n-2] <- F(n-2)
        
    return M[n-1] + M[n-2]
```
Entrambe le soluzioni sono *top-down*, ma la seconda risulta più efficiente. Di seguito una soluzione *bottom-up*:
```
F(n):
    M[1] <- M[2] <- 1
    for i <- 3 to n do
        M[i] <- M[i-2] + M[i-1]
    return M[n]
```
###### Analisi
- L'approccio ricorsivo puro non ha senso se un sotto-problema deve essere risolto più volte per arrivare alla soluzione, in quel caso ha più senso fare uso della *memorizzazione*.
- Se lo spazio delle soluzioni viene esplorato tutto per trovare la soluzione allora ha più senso un approccio iterativo (*bottom-up*) come nel caso della sequenza di Fibonacci

### Rod-cutting
###### Definzione
*Il problema del taglio delle aste* può essere definito nel seguente modo:
- Data un'asta di lunghezza $n$ pollici
- Una tabella di prezzi $p_i$ con $i = 1,2,\dots,n$
- Bisogna determinare il ricavo massimo $r_n$ che si può ottenere tagliando l'asta e vendendone i pezzi. 
- Un'asta di lunghezza $n$ può essere tagliata in $2^{n-1}$ modi differenti

Denotiamo una decomposizione in pezzi utilizzando la normale *notazione additiva* ovvero $7 = 2+2+3$ indica che un asta di lunghezza $7$ viene tagliata in tre pezzi.

Se una soluzione ottima prevede il taglio dell'asta in $k$ pezzi, per $1\le k \le n$ allora la decomposizione: $$n = i_1+i_2+\dots+i_k$$dell'asta in pezzi di lunghezza $i_1,i_2,\dots, i_k$ fornisce il ricavo massimo ovvero: $$r_n = p_{i_1}+p_{i_2}+\dots+p_{i_k}$$

---

**Esempio**: di seguito mostriamo un esempio di ricavi massimi per ogni possibile lunghezza della rod ![[Pasted image 20251224103606.png|500]]

---
###### Generalizzando
Generalizzando possiamo esprimere i valori di $r_n$ in funzione dei ricavi delle aste più corte ovvero:$$r_n = max(p_n, r_1+r_{n-1},r_2+r_{n-2}, \dots, r_{n-1}+r_{1})$$dove:
- $p_n$ corrisponde alla vendita dell'asta di lunghezza $n$ senza tagli
- Gli altri $n-1$ argomenti corrispondono al ricavo massimo ottenuto facendo un taglio iniziale in due pezzi di dimensione $i$ e $n-i$ (con $i = 1,2, \dots, n-1$) e poi tagliando in modo ottimale gli ulteriori pezzi ottenendo i ricavi $r_i$ e $r_{n-i}$
Poiché non sappiamo a priori quale valore di $i$ ottimizza i ricavi *dobbiamo considerare tutti i possibili valori di $i$* e selezionare quello che massimizza i ricavi. Per risolvere il problema originale stiamo risolvendo i problemi più piccoli dello stesso tipo questo lo possiamo fare perché il problema del taglio delle aste presenta una *sottostruttura ottima* ovvero le soluzioni ottime di un problema incorporano le soluzioni ottime dei sotto-problemi correlati. 
Se vediamo ciascuna decomposizione di un'asta come un primo pezzo seguito da un'eventuale decomposizione del pezzo restante, possiamo *riformulare $r_n$ come*: $$r_n = \max_{1\le i \le n}(p_i+r_{n-i})$$quindi possiamo definire il nostro problema come: $$
r(i) = \begin{cases} 
0 & \text{se } i = 0 \\ 
\max_{1 \le k \le i} \{ p(k) + r(i - k) \} & \text{se } i \ge 1 
\end{cases}
$$
```
CUT-ROD(p, n)
    if n == 0
        return 0
    q = -infinity
    for i = 1 to n
        q = max(q, p[i] + CUT-ROD(p, n - i))
    return q
```
Di seguito l'albero di ricorsione con $i = 4$
![[Screenshot_20251224_110126_Samsung capture.jpg|500]]
Notiamo subito che ci sono dei sotto-problemi che si ripetono più volte, quindi dobbiamo fare uso della memorizzazione per rendere il tutto più efficiente.

###### Implementazione bottom-up del ROD-CUT con memorizzazione
Globalmente avremo definito:
- $P$ array con i valori rispetto alla lunghezza
- $R$ array con i valori dei casi già esaminati

```
ROD-CUT(n)
    if n = 0 then
        return 0
    
    for i <- 1 to n
        m <- P(i) // salviamo il valore senza aver tagliato
        for k <- 1 to i-1 DO // proviamo tutti i possibili tagli
            if R(k) + R(i-k) > m //vediamo con quale otteniamo il valore migliore
                then m <- R(k) + R(i-k) // salviamo il valore migliore ottenuto
        R[i] <- m // lo salviamo nei casi già esaminati
```
![[Screenshot_20251224_112902_Samsung capture.jpg|500]]
Oltre a memorizzare i casi già risolti ora vogliamo memorizzare il modo migliore per tagliare la rod di lunghezza $i$ e lo facciamo usando un array $K$

**Esempio**: con $K = [ \underset{1}{1}, \underset{2}{2}, \underset{3}{3}, \underset{4}{2} ]$ sappiamo che una rod di lunghezza $4$ deve essere tagliata nel punto $2$ per ottenere il taglio migliore
```
ROD-CUT(n)
    R <- new Array(n)
    K <- new Array(n)

    if n == 0 then
        return 0

    for i <- 1 to n
        m <- P(i)
        K[i] <- i
        for k <- 1 to i-1 DO
            if R[k] + R[i-k] > m then 
				m <- R[k] + R[i-k]
				K[i] <- k //Salviamo il taglio migliore
        
        R[i] <- m
        
    return K

PRINT-CUT(n, K) //Funzione che stampa il taglio migliore dato n
    if K[n] == n
        print(n)
    else
        PRINT-CUT(K[n], K)
        PRINT-CUT(n - K[n], K)
```

### Ottimizzazione della moltiplicazione tra matrici

Questo è un problema di ottimizzazione basato sul prodotto riga per colonna delle matrici, visto che questa operazione gode della proprietà associativa associando i prodotti in maniera diversa è possibile ottenere lo stesso risultato ma con un numero di operazioni scalari minori

###### Definizione della moltiplicazione tra matrici
Date due matrici $A$ e $B$ per poter effettuare il prodotto tra queste due dobbiamo rispettare la seguente condizione:
- Il numero delle colonne di $A$ deve essere uguale al numero di righe di $B$
L'implementazione della moltiplicazione è la seguente:
```
MATRIX-MULTIPLTY(A,B,p,q,w)
	C = NEW MATRIX[p,w]
	FOR i = 1 TO p DO
		FOR j = 1 TO w DO
		C[i,j] = 0
		FOR k = 1 TO q DO
			C[i,j] = C[i,j] + A[i,k]*B[k,j]
		RETURN c
```

###### Analizziamo la complessità
Supponendo di voler moltiplicare una sequenza di tre matrici $$A_1· A_2 · A_3$$con:
- $A_1 = p \times q$
- $A_2 = q \times w$
- $A_3 = w \times q$
Il numero di operazioni scalari di $A_1 · A_2$ sarà uguale a $p·q·w$ (ottenendo in output una matrice di dimensione $p \times w$). Quindi la complessità di $A_1· A_2 · A_3$ sarà uguale alla somma della complessità tra i vari prodotti riga per colonna, quindi la complessità cambia in base a quale operazione effettuiamo prima.
*Esempio*
Con
- $A_1 = 10 \times 100$
- $A_2 = 100 \times 5$
- $A_3 = 5 \times 50$
La complessità della parentesizzazione $(A_1 · A_2)·A_3$ sarà:
$$10·100·5+10·5·50 = 5000+2500 = 7500$$
La complessità della parentesizzazione $A_1 · (A_2·A_3)$ sarà:
$$100·5·50+10·100·50 = 25000 + 50000 = 75000$$
Associazioni differenti creano complessità molto differenti, la domande dalla quale nasce questo problema è:
*Come troviamo la parentesizzazione migliore per minimizzare il numero di operazioni scalari?*


###### Fasi della programmazione dinamica
**Premesse comuni a tutte le fasi**
- Abbiamo una sequenza di matrici $A_1, A_2, \dots A_n$ 
- abbiamo un vettore di interi $P = P_0, P_1, P_2, P_3, \dots P_n$
Le dimensioni della matrice $A_i$ sono $P_{i-1} \text{ e } P_i$

**1. Ricerca della sottostruttura ottima**
Presa la nostra sequenza di matrici $A_1, A_2, \dots A_n$ supponiamo che una parentesizzazione ottima di quest'ultima suddivida il prodotto in questo modo$$(A_1 \dots A_k)·(A_{k+1} \dots A_n)$$ovviamente anche entrambe le sotto sequenze devono essere parentesizzate in modo ottimo e quindi avremo che: $$S^*_{1,n} = S^*_{1,k}+S^*_{k+1,n} + P_0P_KP_n$$dove $P_0P_KP_n$ sono il numero di moltiplicazioni per $A_{1,k}·A_{k+1,n}$. 

**Dimostrazione**: 
Se ci fosse un modo meno costoso di parentesizzare $A_1 \dots A_k$ sostituendo questa parentesizzazione in quella ottima otterremo un'altra parentesizzazione di $A_1, A_2, \dots A_n$ il cui costo sarebbe minore di quella ottima: una contraddizione.
*Formalmente*:
Supponiamo che la sottostruttura non sia ottima. In particolare supponiamo che per la prima parte ($1$ a $k$) esista una soluzione migliore di quella usata, esiste un $S^{\text{migliore}}_{1,k}$ tale che:
$$S^{\text{migliore}}_{1,k}<S_{1,k}$$
se costruiamo la soluzione ottima con questa versione più economica otteniamo $$S^{\text{migliore}}_{1,n} = S^{\text{migliore}}_{1,k}+S^*_{k+1,n}+P_0P_KP_n$$Visto che abbiamo ipotizzato che $S^{\text{migliore}}_{1,k}<S_{1,k}$ allora necessariamente $$S^{\text{migliore}}_{1,n} < S^*_{1,n}$$Questo è un assurdo in quanto avevamo dichiarato che $S^*_{1,n}$ era già la soluzione ottimale

Usiamo la sottostruttura ottima per trovare una soluzione ricorsiva

**2. Definizione ricorsiva di una soluzione ottima**
Abbiamo la nostra sequenza di matrici: $A_i \dots A_j$ preso un $k$ generico avremo che $(A_i \dots A_k)(A_{k+1}\dots A_j)$ e su questo definiamo:
$$S_{i,j} = \begin{cases} 
0 & \text{se } i = j \\ 
\min_{i \le k < j} (S_{i,k} + S_{k+1,j} + p_{i-1} p_k p_j) & \text{se } i < j 
\end{cases}$$
Segue l'implementazione:
```
MATRIX-CHAIN-ORDER(p, i, j):
    if i == j:
        return 0
    
    sm = +infinity  // elemento più grande
    
    for k from i to j-1:
        // Chiamate ricorsive per calcolare i costi dei sottoproblemi
        res_sinistro = MATRIX-CHAIN-ORDER(p, i, k)
        res_destro = MATRIX-CHAIN-ORDER(p, k+1, j)
        
        // Calcolo del costo attuale: costo sx + costo dx + costo moltiplicazione finale
        costo_attuale = res_sinistro + res_destro + p[i-1] * p[k] * p[j]
        
        if sm > costo_attuale:
            sm = costo_attuale
            
    return sm
```
Se eseguiamo questa funzione con $i = 1$ e $j = 4$ cerchiamo il modo ottimale di moltiplicare $A_1, A_2, A_3, A_4$ e otteniamo il seguente albero di ricorsione:
![[Pasted image 20251226111919.png|500]]
dalla quale notiamo subito che ci sono dei sotto problemi che si ripetono quindi dobbiamo usare una approccio bottom-up per rendere più efficiente l'algoritmo

**3. Ricerca di una soluzione ottima usando un approccio bottom-up**
Per risolvere il problema dei sotto problemi che si ripetono dobbiamo fare uso della memorizzazione, in questo caso non attraverso un array ma attraverso una matrice, visto che abbiamo due indici. Data la matrice $S$ possiamo dire che:
- $S[i,j]$ è il costo minimo per moltiplicare le matrici da $A_i$ fino ad $A_j$
- la diagonale principale contiene sempre $0$ perché moltiplicare una matrice per stesse non richiede alcuna operazione
- Visto che l'algoritmo calcola il costo solo dove $i<j$ sarà sola il triangolo superiore alla diagonale ad essere riempito
- Il risultato finale ovvero il costo minimo per moltiplicare la sequenza di $n$ matrici si trova in posizione $S[1,n]$

```
MATRIX-CHAIN-ORDER(P, n)
    S = new matrix(n, n)
    
    // Inizializzazione diagonale: costo 0 per catene di lunghezza 1
    for i = 1 to n do
        S[i, i] = 0    // Dim 1
        
    // l è la lunghezza della catena
    for l = 2 to n do  // Dim l > 1
        for i = 1 to n - l + 1 do
            j = i + l - 1
            S[i, j] = +∞
            
            for k = i to j - 1 do
                // Calcolo del costo temporaneo
                costo = S[i, k] + S[k + 1, j] + P[i-1] * P[k] * P[j]
                
                // Se il nuovo costo è minore, aggiorna la matrice
                if S[i, j] > costo then
                    S[i, j] = costo
                    
    return S[1, n]
```

**ESEMPIO**
![[Screenshot_20251226_122108_Samsung capture.jpg|500]]

Questo algoritmo calcola il *costo minimo della soluzione* ma non abbiamo modo di sapere quale sia l'ordine effettivo delle matrici da moltiplicare. 

Molti algoritmi richiedono di trovare il valore della soluzione ottima, quindi ci potremmo fermare al terzo step, in questo caso però abbiamo bisogno anche ricostruire la parentesizzazione della soluzione ottima in modo da poter effettuare la vera e propria moltiplicazione, da questa esigenza nasce lo step successivo, solitamente opzionale.

**4. Costruzione della soluzione ottimale**
```
MATRIX-CHAIN-ORDER(p, n)
    S = new matrix(n, n)
    D = new matrix(n, n)
    
    for i = 1 to n do:
        S[i, i] = 0
        
    for l = 2 to n do:
        for i = 1 to n - l + 1 do:
            j = i + l - 1
            S[i, j] = +infinity
            
            for k = i to j - 1 do:  # k è il punto di scissione
                q = S[i, k] + S[k+1, j] + p[i-1] * p[k] * p[j]
                
                if S[i, j] > q:
                    S[i, j] = q
                    D[i, j] = k     # Memorizza il punto di scissione ottimale
                    
    return S[1, n]

PRINT-CHAIN(D, i, j)
    if i == j:
        print "A" + i
    else:
        k = D[i, j]
        print "("
        PRINT-CHAIN(D, i, k)
        PRINT-CHAIN(D, k+1, j)
        print ")"
```

Mentre l'algoritmo che è rimasto essenzialmente lo stesso si occupa di esplorare e trovare tutti i possibili modi di parentesizzare la catena $k$, la matrice $D[i,j]$ salva esattamente quale indice $k$ ha prodotto la parentesizzazione migliore. La funzione print-chain serve per stampare la parentesizzazione migliore in base ai parametri passati.  
###### Complessità
Avendo tre cicli annidati la complessità è $O(n^3)$, è una complessità molto alta, infatti questo algoritmo viene utilizzando quando si devono moltiplicare matrici molto grandi dove c'è un vero e proprio guadagno.
### Distanza di Editing e LCS
###### Introduzione al Problema

Il problema fondamentale analizzato riguarda il calcolo della distanza tra due stringhe, $X$ e $Y$. Esistono diverse metriche per valutare questa distanza, come la **Distanza di Hamming** (che considera solo sostituzioni su stringhe di uguale lunghezza) o la più generale **Distanza di Editing** (o distanza di Levenshtein).

La Distanza di Editing definisce il numero minimo di operazioni necessarie per trasformare la stringa $X$ nella stringa $Y$. Le operazioni consentite, ciascuna con un costo unitario, sono:
1. **Inserimento** di un carattere.
2. **Cancellazione** di un carattere.
3. **Sostituzione** di un carattere.

Consideriamo ad esempio la trasformazione dalla parola "CASA" alla parola "CHIESA".
- _CASA_ $\to$ _CHASA_ (Inserimento 'H')
- _CHASA_ $\to$ _CHESA_ (Sostituzione 'A' con 'E')
- _CHESA_ $\to$ _CHIESA_ (Inserimento 'I')
###### Definizione Formale e Ricorsiva
Date due stringhe:
- $X$ di lunghezza $n$, dove $x_i = X[1 \dots i]$ è il prefisso di lunghezza $i$.
- $Y$ di lunghezza $m$, dove $y_j = Y[1 \dots j]$ è il prefisso di lunghezza $j$.
Definiamo $ED(i, j)$ come la distanza di editing tra i prefissi $x_i$ e $y_j$. La soluzione può essere espressa ricorsivamente:

**Casi Base**
Se una delle due stringhe è vuota, la distanza è pari alla lunghezza dell'altra stringa (tutti inserimenti o cancellazioni):
- $ED(i, 0) = i$
- $ED(0, j) = j$

**Passo Ricorsivo**
Per calcolare $ED(i, j)$ con $i, j > 0$, consideriamo i caratteri $x_i$ e $y_j$:
1. Se $x_i = y_j$ (Match): Non è necessaria alcuna operazione sui caratteri correnti. Il costo è ereditato dai prefissi precedenti: $$ED(i, j) = ED(i-1, j-1)$$
2. Se $x_i \neq y_j$ (Mismatch): Dobbiamo scegliere l'operazione che minimizza il costo tra le tre possibili:
    - _Sostituzione:_ $ED(i-1, j-1) + 1$
    - _Cancellazione (da X):_ $ED(i-1, j) + 1$
    - _Inserimento (in Y):_ $ED(i, j-1) + 1$

La formula completa è:
$$ED(i, j) = \min(ED(i-1, j) + 1, ED(i, j-1) + 1,  ED(i-1, j-1) + \text{costo\_sostituzione})$$

(Nota: il costo di sostituzione è 1 se i caratteri sono diversi, 0 se uguali).

###### Programmazione Dinamica

L'approccio ricorsivo puro ("top-down") è inefficiente a causa della ricalcolazione dei sottoproblemi sovrapposti. La soluzione ottimale utilizza la **Programmazione Dinamica** ("bottom-up"), costruendo una tabella (matrice) di dimensione $(n+1) \times (m+1)$.

**Algoritmo per il calcolo della Distanza (EDT)**
*Input*: Stringhe $X, Y$ di lunghezza $n, m$.

*Complessità*: Tempo $O(n \times m)$, Spazio $O(n \times m)$ (ottimizzabile a $O(\min(n, m))$ se si memorizzano solo le ultime due righe).

**Pseudocodice:**
```
EDT(X, Y, n, m)
  Dichiara matrice ED[0..n, 0..m]

  // Inizializzazione
  FOR i = 0 TO n DO ED[i, 0] = i
  FOR j = 0 TO m DO ED[0, j] = j

  // Riempimento Matrice
  FOR i = 1 TO n DO
    FOR j = 1 TO m DO
      IF X[i] == Y[j] THEN
        ED[i, j] = ED[i-1, j-1]
      ELSE
        ED[i, j] = min(ED[i, j-1],    // Inserimento
                       ED[i-1, j],    // Cancellazione
                       ED[i-1, j-1])  // Sostituzione
                   + 1
```

###### Ricostruzione della Soluzione Ottima

Una volta compilata la matrice, il valore in $ED[n, m]$ rappresenta il costo minimo. Per trovare la sequenza di operazioni, si esegue un "backtracking" dalla cella $(n, m)$ alla cella $(0, 0)$.

**Pseudocodice Ricostruzione:**
```
PRINT-EDT(ED, X, Y, n, m)
  i = n, j = m
  WHILE (i > 0 OR j > 0)
    IF (i > 0 AND j > 0 AND X[i] == Y[j]) THEN
      // Match: nessun costo, ci spostiamo in diagonale
      i = i - 1
      j = j - 1
    ELSE
      // Determiniamo da quale cella proviene il minimo
      min_val = min(ED[i, j-1], ED[i-1, j], ED[i-1, j-1])

      IF (j > 0 AND min_val == ED[i, j-1]) THEN
        STAMPA("Inserimento di " + Y[j])
        j = j - 1
      ELSE IF (i > 0 AND min_val == ED[i-1, j]) THEN
        STAMPA("Cancellazione di " + X[i])
        i = i - 1
      ELSE
        STAMPA("Sostituzione di " + X[i] + " con " + Y[j])
        i = i - 1
        j = j - 1
```

---

###### Longest Common Substring

Un problema correlato è trovare la più lunga stringa di caratteri _consecutivi_ comune a entrambe le stringhe.

**Definizione Ricorsiva (Suffissi)**
Sia $LCS_{suffix}(i, j)$ la lunghezza del suffisso comune più lungo tra $X[1\dots i]$ e $Y[1\dots j]$.
- Se $X[i] = Y[j]$: $LCS_{suffix}(i, j) = LCS_{suffix}(i-1, j-1) + 1$
- Se $X[i] \neq Y[j]$: $LCS_{suffix}(i, j) = 0$ (la continuità si interrompe).

Durante il calcolo, è necessario mantenere una variabile globale `max_len` per tracciare il valore massimo trovato nella matrice, poiché la sottostringa più lunga può terminare in qualsiasi punto, non necessariamente alla fine delle stringhe.

*Ottimizzazione Spaziale:*
Poiché per calcolare la riga $i$ serve solo la riga $i-1$, è possibile utilizzare solo due array ("current" e "previous") invece di un'intera matrice, riducendo lo spazio.

###### Longest Common Subsequence
A differenza della sotto-stringa, una **sotto-sequenza** non richiede che i caratteri siano consecutivi, ma deve mantenere l'ordine relativo originale.

**Esempio**:
$X = \text{ACTAAA}$
$Y = \text{CCATAG}$
LCS = "ATA" (lunghezza 3).

**Relazione di Ricorrenza**
Sia $LCS(i, j)$ la lunghezza della più lunga sotto-sequenza comune tra $X[1\dots i]$ e $Y[1\dots j]$.
1. Se $X[i] = Y[j]$: Il carattere fa parte della LCS. $$LCS(i, j) = LCS(i-1, j-1) + 1$$
2. Se $X[i] \neq Y[j]$: Il carattere corrente non può estendere una corrispondenza comune. La soluzione è il massimo tra ignorare il carattere di $X$ o ignorare il carattere di $Y$. $$LCS(i, j) = \max(LCS(i-1, j), \quad LCS(i, j-1))$$

**Ricostruzione e Stampa della LCS**
Per stampare la sotto-sequenza, si utilizza una procedura ricorsiva partendo dalla fine della matrice calcolata ($L$).

```
PRINT-LCS(L, X, Y, i, j)
  IF (L[i, j] == 0) RETURN

  IF (X[i] == Y[j]) THEN
    // Trovato un carattere comune: stampa prima i precedenti (ordine inverso)
    PRINT-LCS(L, X, Y, i-1, j-1)
    STAMPA(X[i])
  ELSE
    // Segui la direzione del massimo valore
    IF (L[i-1, j] >= L[i, j-1]) THEN
      PRINT-LCS(L, X, Y, i-1, j)
    ELSE
      PRINT-LCS(L, X, Y, i, j-1)
```
# Algoritmi golosi
### Introduzione
###### Definizione
Un'altra strategia che possiamo sfruttare per risolvere problemi di ottimizzazione è la strategia greedy, in italiano golosa. Un algoritmo goloso fa sempre la scelta che sembra ottima in un determinato momento, ovvero fa una scelta *localmente ottima*, nella speranza che tale scelta porterà a una soluzione globalmente ottima. La scelta greedy che viene fatta cambia da problema a problema.

### Problema dello zaino
###### Definizione
Riprendendo il problema dello zaino presentato nella lezione 2, ricordiamo che:
- $k$ capienza dello zaino
- $A = \{a_1,a_2,\dots,a_n\}$
- $P(a_i) =$ peso dell'oggetto
- $V(a_i) =$ valore dell'oggetto
- *Obbiettivo*: massimizzare il guadagno
in questo caso però ogni oggetto ha lo stesso valore ovvero: $$v(a) = 1 \; \forall a \in A$$
Banalmente ciò che dobbiamo massimizzare è il numero di oggetti. Un ottima strategia (greedy) è quella di scegliere l'oggetto con il peso minore.
###### Dimostrazione scelta greedy
$$
a_w : P(a_w) = \min\{\text{Peso}(a_j) : a_j \in A\}
$$
Ovvero $a_w$ scelta greedy. $S \subseteq A$ è una soluzione ottima. Allora $a_w \in S$.
Ipotizziamo per assurdo che $a_w \notin S$.

$$
a_\phi \rightarrow P(a_\phi) = \min\{P(a_j) : a_j \in S\}
$$
Ovvero $a_\phi$ elemento meno pesante della soluzione ottima.
Allora consideriamo $S - \{a_\phi\}$ e considero

$$
S' = (S - \{a_\phi\}) \cup \{a_w\}
$$

Per ipotesi, $S$ è una soluzione ottima, per cui

$$
\sum_{a \in S} P(a) \leq k
$$

### Compressione di Huffman

###### Definizione
I codici di Huffman sono una tecnica molto diffusa ed efficace per comprimere i dati, risparmi dal 20% al 90% sono tipici, a seconda delle caratteristiche dei dai da comprimere. Consideriamo la compressione di un testo dove ogni carattere è rappresentato da una stringa binaria detta *parola in codice*, queste possono essere create in diversi modi. Spesso l'alfabeto (ovvero tutti i caratteri presenti nel testo) viene indicato con $\Sigma$ 

###### Come costruiamo le parole in codice
**Lunghezza fissa:** se utilizziamo un codice *a lunghezza fissa* occorrono 3 bit per rappresentare sei caratteri: $a = 000, b = 001, \dots f = 101$ (posso rappresentare $2^3$ caratteri)
**Lunghezza variabile**: questa codifica assegna ai caratteri più frequenti delle parole in codice corte e ai meno frequenti delle parole in codice lunghe
![[Pasted image 20251227102313.png|500]]

###### Codici prefissi
I codici considerati d'ora in avanti sono soltanto i codici in cui nessuna parola in codice è anche un prefisso di qualche altra parola in codice, questi codici sono detti *codici prefissi*.

> [!TIP] Perché usiamo i codici prefissi
> Data una tabella di codifica del tipo:
> $A = 0$ 
> $B = 01$ 
> $C = 1$
> 
> Notiamo subito che il codice di $A$ è un prefisso del codice $B$. 
> Questo comporta che quando al decodificatore arriva un codice del tipo $01$ non sa se questo equivale ad $AC$ o solo $B$

Per creare questo tipo di codici usiamo l'albero di Hoffman che funziona in questo modo:
- Ogni foglia è etichettata con un carattere e la sua frequenza
- Ogni nodo interno è etichettato con la somma delle frequenze delle foglie nel suo sottoalbero
Per creare i nodi interni prendiamo i nodi con la frequenza più bassa e li "uniamo" in un padre con la somma delle frequenza (alla quale assegniamo un'altra lettera), facendo questa cosa ricorsivamente otterremo un albero del tipo:
![[Pasted image 20251227102806.png|500]]![[Pasted image 20251227103754.png|500]]
Il cammino semplice che c'è tra la radice e quel carattere *definisce il suo codice prefisso*. **La profondità di una foglia corrisponde al numero di bit necessari per la codifica**

###### Costo di una codifica
Dato un albero $T$ che corrisponde a un codice prefisso, è semplice calcolare il numero di bit richiesti per codificare un file. Dato un nodo foglia $c$ definiamo:
- $f(c)$ la frequenza di quel nodo nel file
- $d_T(c)$ la profondità della foglia nell'albero
Il costo della codifica di un albero diventa:
$$B(T) = \sum_{c\in C} f(c) \times d_T(c)$$
quindi dobbiamo trovare una strategia che dato testo minimizza $B(T)$

###### Dimostrazione della sottostruttura ottima
**Definizioni iniziali:**
- $\Sigma$: Insieme dei caratteri (soluzione $T$)
- Consideriamo due nodi $a$ e $b$ (le foglie con frequenza minima) e il loro genitore $z$.
- $\Sigma' = \Sigma - \{a, b\} \cup \{z\}$ (soluzione $T'$)

**Relazioni tra frequenze e profondità:**
1. $f(z) = f(a) + f(b)$
    - La frequenza del nodo padre è la somma delle frequenze dei figli.
2. $d_T(a) = d_{T'}(z) + 1$ e $d_T(b) = d_{T'}(z) + 1$
	- La profondità di $a/b$ nell'albero originale è la profondità di $z$ nell'albero ridotto più 1.
**Costruzione di una relazione tra T e T'$:**
Il costo dell'albero $T$, denotato come $B(T)$, è dato dalla somma delle frequenze per le profondità:
$$B(T) = \sum_{c \in \Sigma} f(c) \cdot d_T(c)$$
3.  Espandendo la sommatoria per mettere in relazione $T$ con $T'$: $$B(T)= \left[ \sum_{c \in \Sigma'} f(c) d_{T'}(c) \right] - f(z) \cdot d_{T'}(z) + f(a) d_T(a) + f(b) d_T(b)$$*Nota*: Il termine tra parentesi quadre è $B(T')$. Sottraiamo il contributo di $z$ (che è in $T'$ ma non è foglia in $T$) e aggiungiamo i contributi di $a$ e $b$.
4. Sostituendo le relazioni di profondità e frequenza ($f(z) = f(a)+f(b)$): $$B(T) = B(T') - (f(a) + f(b)) d_{T'}(z) + f(a)(d_{T'}(z) + 1) + f(b)(d_{T'}(z) + 1)$$
5. Svolgendo i calcoli, i termini con $d_{T'}(z)$ si cancellano: $$= f(a) + f(b)$$
6. Quindi la relazione fondamentale è: $$B(T) = B(T') + f(a) + f(b)$$
**Suppongo che la sottostruttura ottima non esista**
- *Ipotesi per assurdo*: Supponiamo che $T$ **non** sia l'albero ottimo per $\Sigma$ (e quindi anche che $T'$ non sia l'albero ottimo per $\Sigma'$). Di conseguenza, deve esistere un albero $T_{opt}$ con costo strettamente inferiore a $T$: $$B(T_{opt}) < B(T)$$
- *Costruzione dell'albero ridotto*: Prendiamo $T_{opt}$ e uniamo le foglie $a$ e $b$ nel padre $z$. Otteniamo un nuovo albero $T'_{opt}$ valido per l'alfabeto ridotto $\Sigma'$. Il costo di questo albero ridotto è: $$B(T'_{opt}) = B(T_{opt}) - (f(a) + f(b))$$
- *Sviluppo algebrico*: Riprendiamo la disuguaglianza del punto 1: $$B(T_{opt}) < B(T)$$ Sottraiamo a entrambi i membri la quantità costante $(f(a) + f(b))$: $$B(T_{opt}) - (f(a) + f(b)) < B(T) - (f(a) + f(b))$$ Sostituiamo i termini con le definizioni dei costi ridotti ($B(T'_{opt})$ e $B(T')$): $$\underbrace{B(T_{opt}) - (f(a) + f(b))}_{B(T'_{opt})} < \underbrace{B(T) - (f(a) + f(b))}_{B(T')}$$ Otteniamo infine: $$B(T'_{opt}) < B(T')$$
Abbiamo dimostrato l'esistenza di un albero $T'_{opt}$ con costo inferiore a $T'$. Questo *contraddice l'ipotesi iniziale* che $T'$ fosse l'albero ottimo per $\Sigma'$.

###### Implementazione
```
HUFFMAN(Σ, f)
    Q <- new Priority Queue
    
    // Inizializzazione: crea un nodo foglia per ogni carattere
    foreach c in Σ do:
        x <- new Node(c)
        insert x in Q
        
    // Costruzione dell'albero dal basso verso l'alto
    for i <- 1 to |Σ| - 1 DO
        x <- extractMin(Q)      // Estrae il nodo con frequenza minima
        y <- extractMin(Q)      // Estrae il secondo nodo con frequenza minima
        
        z <- new Node           // Crea un nuovo nodo interno
        f(z) = f(x) + f(y)      // Somma le frequenze
        left(z) = x             // Assegna i figli
        right(z) = y
        
        insert z in Q           // Inserisce il nuovo nodo nella coda
        
    return extractMin(Q)        // Ritorna la radice dell'albero
```
Il processo inizia inserendo tutti i caratteri dell'alfabeto in una coda di priorità, dove vengono trattati come nodi foglia ordinati in base alla loro frequenza di apparizione. L'algoritmo procede estraendo iterativamente i due nodi con la frequenza minore assoluta e unendoli per creare un nuovo nodo intermedio, il cui valore è dato dalla somma delle frequenze dei due figli. Questo nuovo nodo viene reinserito nella coda, e l'operazione si ripete ciclicamente fino a quando rimane un unico nodo che diventa la radice dell'albero. Il risultato è una struttura in cui i caratteri più frequenti si trovano più vicini alla radice (ottenendo codici binari più corti), mentre quelli più rari sono posizionati in profondità (con codici più lunghi).