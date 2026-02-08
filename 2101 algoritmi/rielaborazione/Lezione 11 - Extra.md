
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

$endIndex - maxLenght : endIndex$ indica lo slicing della stringa da endIndex - maxLength a endIndex.
es: endIndex = 5  maxLength = 2 ---> da  3 a 5



