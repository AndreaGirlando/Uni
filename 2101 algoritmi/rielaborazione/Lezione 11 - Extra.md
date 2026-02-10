# Longest Common Substring
Date due stringhe X e Y devo cercare la più lunga stringa di caratteri **consecutivi** comune a entrambe le stringhe.
Vediamo se questo problema può essere risolto tramite la prog dinamica
Ricordiamo che dobbiamo dimostrare 2 cose:
1) la soluzione ottima di un problema contiene al suo interno le soluzioni ottime dei suoi sotto problemi
2) definire un approccio ricorsivo per risolvere il problema
### Sottostruttura ottima:

**Definizione del sotto problema:** Definiamo $L(i, j)$ come la lunghezza della più lunga sottostringa comune che **termina esattamente** agli indici $i$ di $X$ e $j$ di $Y$ (ovvero il "suffisso comune").

**La Tesi:** Se i caratteri $X[i]$ e $Y[j]$ sono uguali, allora la lunghezza del suffisso comune che termina in $(i, j)$ dipende direttamente dalla lunghezza del suffisso comune che terminava in $(i-1, j-1)$.

**La Dimostrazione (Logica):**
Supponiamo che $X[i] == Y[j]$.
Poiché stiamo cercando una **sottostringa** (caratteri _consecutivi_), il carattere corrente estende semplicemente ciò che c'era immediatamente prima.
- Se la soluzione per $(i, j)$ è una stringa di lunghezza $K > 1$, significa che i caratteri $X[i]$ e $Y[j]$ sono l'ultimo carattere di questa stringa.
- Se rimuoviamo questo ultimo carattere, rimaniamo con una sottostringa comune di lunghezza $K-1$ che termina agli indici $i-1$ e $j-1$.
- Affinché la soluzione a $(i, j)$ sia **ottima** (massima), anche la soluzione a $(i-1, j-1)$ deve essere **ottima**. Se ci fosse un suffisso comune più lungo a $(i-1, j-1)$, potremmo aggiungerci $X[i]$ (che è uguale a $Y[j]$) ottenendo un risultato migliore per $(i, j)$, contraddicendo l'ipotesi iniziale.

### Definizione funzione ricorsiva:
Dati due indici $i$ e $j$ (rispettivamente per le stringhe $X$ e $Y$) sfrutteremo una matrice per memorizzare i risultati e la soluzione sarà la casella con valore massimo della matrice:
**Caso Base:** Se uno degli indici è 0 (stringa vuota o prima dell'inizio), non c'è nessuna stringa comune.
$$L(i, 0) = 0, \quad L(0, j) = 0$$

**Caso 1: I caratteri corrispondono ($X[i] == Y[j]$)** Poiché i caratteri sono uguali, estendiamo la sottostringa comune trovata nel passo precedente (la "diagonale" precedente nella matrice).
$$L(i, j) = 1 + L(i-1, j-1)$$
_Perché $i-1, j-1$?_ Perché per mantenere la **consecutività**, dobbiamo guardare i caratteri immediatamente precedenti in entrambe le stringhe.

**Caso 2: I caratteri NON corrispondono ($X[i] \neq Y[j]$)** Poiché una sottostringa deve essere consecutiva, se i caratteri attuali sono diversi, la catena si **spezza**. Non possiamo "saltare" un carattere.
$$L(i, j) = 0$$
Il suffisso comune che _termina_ in questi indici ha lunghezza 0.

Se dopo che la catena si spezza il contatore di caratteri torna a 0 e si ripete la procedura fino a quando non si raggiungono i casi base.

### Soluzione con programmazione dinamica:

**Logica dell'algoritmo:**

1. Creiamo una matrice `dp` di dimensione $(m+1) \times (n+1)$.
2. Iteriamo sulle stringhe.
3. Se $X[i] == Y[j]$, incrementiamo il valore della diagonale precedente ($dp[i-1][j-1] + 1$).
4. Se $X[i] \neq Y[j]$, mettiamo $0$.
5. Teniamo traccia di una variabile `max_len` durante il processo.

```
dp[][]= new matrix(m+1,n+1)
maxLength = 0
endIndex = 0

for i from 1 to m+1 do:
	for j from 1 to n+1 do:
		if X[i] == Y[j]:
			dp[i][j] = dp[i-1][j-1] +1
			if dp[i][j] > maxLength:
				maxLength = dp[i][j]
				endIndex = i
		else:
			dp[i][j] = 0

LCS = X[endIndex - maxLenght : endIndex]

return LCS
```

> [!TIP]
> $$endIndex - maxLenght : endIndex$$ 
> indica lo slicing della stringa da endIndex - maxLength a endIndex.
> *Esempio*: endIndex = 5  maxLength = 2 ---> da  3 a 5
# Longest Common Subsequence (LCS)

Date due sequenze $X$ e $Y$, il problema consiste nel trovare la più lunga sottosequenza comune a entrambe. A differenza delle sottostringhe, una **sottosequenza** non richiede che gli elementi siano consecutivi nella sequenza originale, ma devono mantenere lo stesso ordine relativo. Ad esempio, data $X = \langle A, B, C, B, D, A, B \rangle$, la sequenza $\langle B, C, D, B \rangle$ è una sua sottosequenza. Vediamo come risolvere questo problema tramite la programmazione dinamica.
### Sottostruttura ottima
**Sottostruttura ottima di una LCS**
Siano $X = \langle x_1, x_2, \dots, x_m \rangle$ e $Y = \langle y_1, y_2, \dots, y_n \rangle$ le sequenze; sia $Z = \langle z_1, z_2, \dots, z_k \rangle$ una qualsiasi LCS di $X$ e $Y$.
1. Se $x_m = y_n$, allora $z_k = x_m = y_n$ e $Z_{k-1}$ è una LCS di $X_{m-1}$ e $Y_{n-1}$.
2. Se $x_m \neq y_n$, allora $z_k \neq x_m$ implica che $Z$ è una LCS di $X_{m-1}$ e $Y$.
3. Se $x_m \neq y_n$, allora $z_k \neq y_n$ implica che $Z$ è una LCS di $X$ e $Y_{n-1}$.
**Dimostrazione** 
- (1) Se $z_k \neq x_m$, allora potremmo accodare $x_m = y_n$ a $Z$ per ottenere una sottosequenza comune di $X$ e $Y$ di lunghezza $k + 1$, contraddicendo l’ipotesi che $Z$ sia una _più lunga_ sottosequenza comune di $X$ e $Y$. Quindi, deve essere $z_k = x_m = y_n$. Ora, il prefisso $Z_{k-1}$ è una sottosequenza comune di $X_{m-1}$ e $Y_{n-1}$ di lunghezza $k - 1$. Vogliamo dimostrare che questo prefisso è una LCS. Supponiamo per assurdo che ci sia una sottosequenza comune $W$ di $X_{m-1}$ e $Y_{n-1}$ di lunghezza maggiore di $k - 1$. Allora, accodando $x_m = y_n$ a $W$ si ottiene una sottosequenza comune di $X$ e $Y$ la cui lunghezza è maggiore di $k$, che è una contraddizione.
- (2) Se $z_k \neq x_m$, allora $Z$ è una sottosequenza comune di $X_{m-1}$ e $Y$. Se esistesse una sottosequenza comune $W$ di $X_{m-1}$ e $Y$ di lunghezza maggiore di $k$, allora $W$ sarebbe anche una sottosequenza comune di $X_m$ e $Y$, contraddicendo l’ipotesi che $Z$ sia una LCS di $X$ e $Y$.
- (3) La dimostrazione è simmetrica a quella del punto (2).

### Definizione funzione ricorsiva
Definiamo $c[i, j]$ come la lunghezza di una LCS delle sequenze $X_i$ e $Y_j$.
**Caso Base:** Se una delle sequenze ha lunghezza 0, la lunghezza della LCS è 0.
$$c[i, j] = 0 \quad \text{se } i=0 \text{ oppure } j=0$$

**Caso 1: I caratteri corrispondono ($x_i == y_j$):** Abbiamo trovato un elemento della LCS. Incrementiamo di 1 la lunghezza della LCS trovata nei prefissi precedenti ($i-1, j-1$).
$$c[i, j] = c[i-1, j-1] + 1$$
**Caso 2: I caratteri NON corrispondono ($x_i \neq y_j$):** Non possiamo estendere la sottosequenza con l'attuale coppia. Dobbiamo cercare la soluzione migliore risolvendo i due sottoproblemi possibili (ignorando l'ultimo carattere di $X$ o ignorando l'ultimo carattere di $Y$) e prendendo il massimo.
$$c[i, j] = \max(c[i, j-1], c[i-1, j])$$
### Soluzione con programmazione dinamica
**Logica dell'algoritmo:**
1. Creiamo una tabella $c$ di dimensione $(m+1) \times (n+1)$ per memorizzare le lunghezze.
2. Creiamo una tabella $b$ per memorizzare le "frecce" che indicano quale sottoproblema ha generato la soluzione ottima ($\nwarrow, \uparrow, \leftarrow$) .
3. Inizializziamo la prima riga e la prima colonna a 0 .
4. Iteriamo attraverso la tabella riga per riga (bottom-up).
5. Se $x_i == y_j$, il valore deriva dalla diagonale in alto a sinistra + 1 (freccia $\nwarrow$).
6. Se $x_i \neq y_j$, il valore è il massimo tra il vicino in alto (freccia $\uparrow$) e il vicino a sinistra (freccia $\leftarrow$) .
7. Il valore in $c[m, n]$ è la lunghezza della LCS. Per ricostruire la stringa, seguiamo le frecce a ritroso partendo da $b[m, n]$ .
```
LCS-LENGTH(X, Y)
	m = X.length
	n = Y.length
	Siano b[1..m, 1..n] e c[0..m, 0..n] nuove tabelle
	
	// Inizializzazione casi base
	for i = 1 to m: c[i, 0] = 0
	for j = 0 to n: c[0, j] = 0
	
	// Calcolo Bottom-up
	for i = 1 to m:
	    for j = 1 to n:
	        if X[i] == Y[j]:
	            c[i, j] = c[i-1, j-1] + 1
	            b[i, j] = "↖"           // Corrisponde a diagonale
	        elseif c[i-1, j] >= c[i, j-1]:
	            c[i, j] = c[i-1, j]
	            b[i, j] = "↑"           // Corrisponde a 'su'
	        else:
	            c[i, j] = c[i, j-1]
	            b[i, j] = "←"           // Corrisponde a 'sinistra'
	
	return c, b
```

Per stampare la sequenza effettiva, si usa una procedura ricorsiva che segue la tabella $b$ a ritroso:

```
PRINT-LCS(b, X, i, j)
	if i == 0 or j == 0:
	    return
	if b[i, j] == "↖":
	    PRINT-LCS(b, X, i-1, j-1)
	    print X[i]
	elseif b[i, j] == "↑":
	    PRINT-LCS(b, X, i-1, j)
	else:
	    PRINT-LCS(b, X, i, j-1)
```


# Activity selector

### 1. Definizione del Problema

Il nostro primo esempio è il problema della programmazione di più attività in competizione che richiedono l’uso esclusivo di una risorsa comune, con l’obiettivo di selezionare il più grande insieme di attività mutuamente compatibili. Supponiamo di avere un insieme $S = \{a_1, a_2, ..., a_n\}$ di $n$ attività che devono utilizzare la stessa risorsa, per esempio un’aula universitaria, che può essere utilizzata per svolgere una sola attività alla volta.
- Ogni attività $a_i$ ha un tempo di inizio $s_i$ e un tempo di fine $f_i$.
- Il problema della selezione di attività consiste nel selezionare il sottoinsieme che contiene il maggior numero di attività mutuamente compatibili.
- Supponiamo che le attività siano ordinate in modo monotonicamente crescente rispetto ai tempi di fine: $f_1 \le f_2 \le ... \le f_n$.
### 2. Sottostruttura Ottima
Possiamo facilmente verificare che il problema della selezione di attività presenta una sottostruttura ottima.
Indichiamo con $S_{ij}$ l’insieme delle attività che iniziano dopo la fine dell’attività $a_i$ e finiscono prima dell’inizio dell’attività $a_j$.
Supponiamo di voler trovare un insieme massimo di attività mutuamente compatibili in $S_{ij}$ e supponiamo che $A_{ij}$ sia un insieme massimo che include una certa attività $a_k$.
Includendo $a_k$ in una soluzione ottima, restano due sottoproblemi:
1. Trovare le attività mutuamente compatibili nell’insieme $S_{ik}$ (attività che iniziano dopo la fine di $a_i$ e finiscono prima dell’inizio di $a_k$).
2. Trovare le attività mutuamente compatibili nell’insieme $S_{kj}$ (attività che iniziano dopo la fine di $a_k$ e finiscono prima dell’inizio di $a_j$).
Siano $A_{ik} = A_{ij} \cap S_{ik}$ e $A_{kj} = A_{ij} \cap S_{kj}$.
Ne deriva che $A_{ij} = A_{ik} \cup \{a_k\} \cup A_{kj}$ e, quindi, la dimensione dell'insieme massimo è:
$$|A_{ij}| = |A_{ik}| + |A_{kj}| + 1$$
**Ragionamento "taglia e incolla":**
Se trovassimo un insieme $A'_{kj}$ di attività mutuamente compatibili in $S_{kj}$ tale che $|A'_{kj}| > |A_{kj}|$, allora potremmo utilizzare $A'_{kj}$ anziché $A_{kj}$ in una soluzione del sottoproblema per $S_{ij}$. Avremmo potuto costruire un insieme di $|A_{ik}| + |A'_{kj}| + 1 > |A_{ij}|$ attività, il che contraddice l’ipotesi che $A_{ij}$ sia una soluzione ottima. Un ragionamento simmetrico si applica a $S_{ik}$.
### 3. La Scelta Golosa (Greedy Choice)

Che cosa intendiamo con scelta golosa nel problema della selezione di attività? L’intuito ci dice di scegliere l’attività in $S$ che finisce per prima, perché così la risorsa resterebbe disponibile per il maggior numero possibile di attività successive. Poiché le attività sono ordinate per tempi di fine crescenti, la scelta golosa è l’attività $a_1$. Se facciamo la scelta golosa, resta un solo sottoproblema da risolvere: trovare le attività che iniziano dopo la fine di $a_1$. Sia $S_k = \{a_i \in S : s_i \ge f_k\}$ l’insieme delle attività che iniziano dopo la fine dell’attività $a_k$. Se scegliamo $a_1$, $S_1$ resta l’unico sottoproblema.
### 4. Teorema 16.1: Correttezza della scelta golosa
**Teorema:** Consideriamo un sottoproblema non vuoto $S_k$ e sia $a_m$ l’attività in $S_k$ che ha il primo tempo di fine; allora l’attività $a_m$ è inclusa in qualche sottoinsieme massimo di attività mutuamente compatibili di $S_k$.
**Dimostrazione:**
Supponiamo che $A_k$ sia un sottoinsieme massimo di attività mutuamente compatibili di $S_k$ e sia $a_j$ l’attività in $A_k$ con il più piccolo tempo di fine.
1. Se $a_j = a_m$, abbiamo finito (l'attività golosa è già nell'insieme ottimo).
2. Se $a_j \neq a_m$, costruiamo l'insieme $A'_k = (A_k - \{a_j\}) \cup \{a_m\}$ (sostituiamo $a_j$ con $a_m$).
    - Le attività in $A'_k$ sono disgiunte perché $a_j$ era la prima a finire in $A_k$ e $f_m \le f_j$ (poiché $a_m$ è la scelta golosa).
    - Poiché $|A'_k| = |A_k|$, concludiamo che $A'_k$ è un sottoinsieme massimo che include $a_m$.

---
### 5. Algoritmo Ricorsivo
La procedura cerca la prima attività in $S_k$ compatibile con $a_k$.

```
RECURSIVE-ACTIVITY-SELECTOR(s, f, k, n)
1  m = k + 1
2  while m <= n and s[m] < f[k]    // Trova la prima attività in Sk
3      m = m + 1
4  if m <= n
5      return {a_m} U RECURSIVE-ACTIVITY-SELECTOR(s, f, m, n)
6  else
       return Ø
```

**Analisi:**
Il ciclo `while` (righe 2-3) cerca la prima attività $a_m$ compatibile con $a_k$ (ovvero $s_m \ge f_k$). Il tempo di esecuzione è $\Theta(n)$, poiché ogni attività viene esaminata una sola volta nel test del ciclo `while` attraverso tutte le chiamate ricorsive.

---
### 6. Algoritmo Iterativo
Possiamo convertire la procedura ricorsiva in una iterativa. La procedura `GREEDY-ACTIVITY-SELECTOR` raccoglie le attività selezionate in un insieme $A$.
```
GREEDY-ACTIVITY-SELECTOR(s, f)
1  n = s.length
2  A = {a_1}
3  k = 1
4  for m = 2 to n
5      if s[m] >= f[k]
6          A = A U {a_m}
7          k = m
8  return A
```

**Funzionamento:**
- Le righe 2-3 selezionano $a_1$ e inizializzano $A$.
- La variabile $k$ indicizza l'ultima attività aggiunta ad $A$. Poiché le attività sono ordinate, $f_k$ è sempre il massimo tempo di fine in $A$.
- Il ciclo `for` (righe 4-7) esamina ogni attività $a_m$. Se $a_m$ è compatibile ($s_m \ge f_k$), viene aggiunta ad $A$ e $k$ viene aggiornato.
- Anche questo algoritmo impiega tempo $\Theta(n)$.