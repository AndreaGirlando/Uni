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
                costo = S[i, k] + S[k + 1, j] + P[k] * P[j]
                
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
### La più lunga sotto-sequenza comune in una stringa
Lezione 14
# Algoritmi golosi
### Introduzione
### Selezione di attività
Lezione 13
### Compressione di Huffman
Lezione 15
