###### RODCUT
```
RODCUT(n):
	R = new Array(n)
	if(n>m) return 0;
	
	for i = 0 to n:
		m = P[i]
		for k = 1 to i-1 do
			if(R[k]+R[k-i]>m)
				m = R[k]+R[k-i]
		R[i] = m;
	return R;
```

```
RODCUT(n):
	R = new Array(n)
	K = new Array(n)
	
	if n == 0 return
	
	for i = 1 to n
		m = P[i]
		K[i] = i
		for k = 1 to i-1 do
			if(R[k]+R[k-i]>m)
				m = R[k]+R[k-i]
		R[i] = m;
	return K;
	
```

```
PRINT-CUT(n,k):
	if(k[n] == n) 
		print(n)
	else 
		PRINT-CUT(k[n], k)
		PRINT-CUT(n-k[n], k)
```
###### MATRIX
```
MATRIX-CHAIN-ORDER(p, i, j)
	if i == j:
		return 0
	sm = +infinito
	
	for k from i to j-1
		sx = MATRIX-CHAIN-ORDER(p, i, k)
		dx = MATRIX-CHAIN-ORDER(p, k+1, j)
		
		tot = sx + dx + P[0]*P[k]*P[j]
		
		if sm > tot:
		 sm = tot;
		 
	return sm
```

```
MATRIX-CHAIN-ORDER(p, i, j)
	S = new Matrix(n,n)
	
	for i = 1 to n:
		S[i,i] = 0;
	
	for l = 2 to n do
		for i = 1 to n-l+1 do
			j = i+l-1
			S[i,j] = inf
			
			for k = i to j-1 do
				costo = S[i,k] + S[k+1, j] + P[i-1]*P[k]*P[j]
				
				if S[i,j] > costo
					S[i,j] = costo
	return S[1,n]
```

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

###### HEAP
```
DECREASE-KEY(H, i, k)
	H[i] = k
	p = parent(i)
	while i > 0 and H[p] > H[i] do
		swap(H[i], H[p])
		i = p
		p = parent(i)
		
INSERT(H, k)
	i = |H| - 1
	H[i] = k
	p = parent(i)
	while i > 0 and H[p] > H[i] do
		swap(H[i], H[p])
		i = p
		p = parent(i)
		
void min_heapify(int i){
    int l = left(i);
    int r = right(i);
    int min = i;

    if(l < size && array[l] < array[min]) min = l;
    if(r < size && array[r] < array[min]) min = r;

    if(min != i){
        int scambio = array[i];
        array[i] = array[min];
        array[min] = scambio;
        min_heapify(min);
    }
} 

int extractMax(){
	int max = array[0];
	
	int scambio = array[0];
	array[0] = array[size-1];
	array[size-1] = scambio;
	
	size--;
	max_heapify(0);
	
	return max;
}
```

###### HEAPSORT
```
void HeapSort(array){
	buildMaxHeap(array);
	int len = size;
	for(int i = len-1; i > 2; i--){
		int scambio = array[i];
		array[i] = array[0];
		array[0] = scambio;
		max_heapify(0, i); //il paramentro indica la lunghezza massima
	}

```

###### HUFFMAN
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
###### Longest commono substring
```
LCS(X,Y, n, m)
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

###### Longest common subsequence
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
###### Activity selector
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
###### Distanza di editing

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
###### Relax
```
RELAX(u,v,w):
	if(d[v]>d[u]+w(u,v))
		d[v] = d[u]+w(u,v)
```
###### BFS
```
BFS(V, s)
	Foreach v in V //for di inizializzazione
		color[v] = White
		d[v] = +infinito
		
	d[s] = 0; // la distanza della sorgente da stessa è 0
	Q = { } // inizializzazione della coda come vuota
	Q.enqueue(s)
	While Q != {} DO
		v = Q.dequeue(Q)
		foreach u in ADJ(v) //scorriamo tutti i nodi adiacenti a v
			if(color[u] == W) 
				d[u] = d[v]+1
				color[u] = Gray
				Q.enqueue(u)
		color[v] = Black
```
###### DFS

```
DFS-visit(v):
	d[v] = T //tempo di inizio visita
	T = T+1 //variabile che scandisce il tempo
	color[v] = gray;
	foreach u in adj(v)
		if color[u] = white
			π[u] = v
			DFS-visit(u)
		color[v] = black
	F[v] = T //tempo di fine visita
	T = T+1 //variabile che scandisce il tempo

DFS(G,s):
	foreach v in V DO:
		color[v] = white
		π[] = null
		
		
	foreach v in V DO:
		if color[v] = white:
			DFS-visit(s);
```

###### Bellam-Ford
```text
Bellman-Ford(G, s, w)
    // 1. Inizializzazione
    d = new Array(len(V))
    for each v ∈ V do
        d[v] = +∞
        π[v] = NIL
    d[s] = 0

    // 2. Rilassamento iterativo degli archi
    for i ← 1 to |V|-1 do
        for each (u, v) ∈ E do
            relax(u, v, w)

    // 3. Controllo dei cicli di peso negativo
    for each (u, v) ∈ E do
        if (d[v] > d[u] + w(u, v)) then
            return false

    return d
```
###### Dijkstra

```
Dijkstra(G, s, w)
    d = new Array(len(V))
    for each v ∈ V do
        d[v] = +∞
        π[v] = NIL
    d[s] = 0

    Q ← build-min-heap(V)
    
    while Q ≠ ∅ do
        v ← extract-min(Q)
        foreach u ∈ ADJ(v)
            if d[u] > d[v] + w(v, u) then
                decrease-key(Q, u, d[v] + w(v, u))
```

###### Floyd Warshall
```
FLOYD-WARSHALL(W)
    n = m  // numero di vertici
    D^0 = W
    for k = 1 to n do
        D^k = new Matrix(n, n)
        for i = 1 to n do
            for j = 1 to n do
                // Se il cammino attraverso k è più breve, aggiorna
                if (D^{k-1}[i, j] > D^{k-1}[i, k] + D^{k-1}[k, j])
                    D^k[i, j] = D^{k-1}[i, k] + D^{k-1}[k, j]
                else
                    D^k[i, j] = D^{k-1}[i, j]
    return D^n
```
###### APSP
```
Fast-APSP(W)
    n = m  // numero di vertici
    L^1 = W
    d = 1
    while d < n - 1 do
        L^{2d} = EXTEND-APSP(L^d, L^d)
        d = 2d
    return L^d

APSP(W) 
	n = m L_1 = W 
	for d = 2 to n - 1 do 
		L_d = EXTEND-APSP(L_{d-1}, W) 
	return L_{n-1}
```

###### SSSP DAG
```
DAG-SHORTEST-PATHS(G, w, s)
	U = getTopologicalOrder(G);
	foreach v in U:
	  foreach v in G.Adj[u]
		  RELAX(u, v, w)
```

###### Counting Sort
```
Counting-Sort(A, B, n):
    k = max(A)                     // valore massimo in A
    C = new Array(k+1)

    // inizializza C a 0
    for i = 0 to k:
        C[i] = 0

    // conta le occorrenze
    for i = 0 to n-1:
        C[A[i]] = C[A[i]] + 1

    // calcola le posizioni cumulative
    for i = 1 to k:
        C[i] = C[i] + C[i-1]
        
    // costruisci l'array ordinato B in maniera stabile
    for i = n-1 downto 0:
        B[C[A[i]] - 1] = A[i]     // -1 perché B è 0-indexed
        C[A[i]] = C[A[i]] - 1

```