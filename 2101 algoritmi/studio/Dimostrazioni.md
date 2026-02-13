### Sottostrutture ottime

###### Rodcut
Il problema del rodcut gode della proprietà della sottostruttura ottima di seguito la dimostrazione:
1. Prendiamo una soluzione ottima $S^*$ del problema 
2. Supponiamo che questa soluzione preveda il taglio dell'asta in due pezzi: uno di lunghezza $k$ e uno di lunghezza $n-k$, il valore di questa soluzione quindi è definito come $$p(S^*) = p(S_k) + p(S_{n-k})$$
3. Supponendo per assurdo che $S_{n-k}$ non sia ottima, abbiamo quindi un'altra decomposizione $S'_{n-k}$ con valore più alto
4. Quindi otteniamo una nuova soluzione ottima definita in questo modo: $$p(S^*_{migliore}) = p(S_k) + p(S'_{n-k})$$
5. Visto che $p(S'_{n-k}) > p(S_{n-k})$ allora $p(S^*_{migliore})>p(S^*)$, questo rappresenta una contraddizione in quanto $S$ era già ottima
###### Matrix
Presa la sequenza di matrici $A_1, A_2, \dots, A_n$ supponiamo che una parentesizzazione migliore di questa sequenza suddivida in questo modo il prodotto: $$(A_1\dots A_k)\times(A_k\dots A_n)$$ovviamente anche entrambe le sottosequenze devono essere prarentesizzate in modo ottimo e quindi avremo che:$$S^{*}_{1,n} = S^{*}_{1,k}+S^{*}_{k+1,n}+P_0P_kP_n$$
Di seguito la dimostrazione: 
1. Supponiamo per assurdo che per la prima parte (da $1$ a $k$) esiste una soluzione migliore di quella usata $S^{migliore}_{1,k}$ tale che $S^{migliore}_{1,k}<S^{*}_{1,k}$
2. Quindi riusciamo a costruire una soluzione migliore nella forma: $$S^{migliore}_{1,n} = S^{migliore}_{1,k}+S^{*}_{k+1,n}+P_0P_kP_n$$
3. Visto che $S^{migliore}_{1,k}<S^{*}_{1,k}$ allora sicuramente $S^{migliore}_{1,n}<S^{*}_{1,n}$ ma questa è una contraddizione in quanto la prima soluzione era già ottima
###### Longest common subsequence
Siano $X = \langle x_1, x_2, \dots, x_m \rangle$ e $Y = \langle y_1, y_2, \dots, y_n \rangle$ le sequenze; sia $Z = \langle z_1, z_2, \dots, z_k \rangle$ una qualsiasi LCS di $X$ e $Y$.
1. Se $x_m = y_n$, allora $z_k = x_m = y_n$ e $Z_{k-1}$ è una LCS di $X_{m-1}$ e $Y_{n-1}$. 
2. Se $x_m \neq y_n$, allora $z_k \neq x_m$ implica che $Z$ è una LCS di $X_{m-1}$ e $Y$.
3. Se $x_m \neq y_n$, allora $z_k \neq y_n$ implica che $Z$ è una LCS di $X$ e $Y_{n-1}$.
Di seguito la dimostrazione
4. Visto che deve essere $z_k = x_m = y_n$. Ora, il prefisso $Z_{k-1}$ è una sottosequenza comune di $X_{m-1}$ e $Y_{n-1}$ di lunghezza $k - 1$. Vogliamo dimostrare che questo prefisso è una LCS. Supponiamo per assurdo che ci sia una sottosequenza comune $W$ di $X_{m-1}$ e $Y_{n-1}$ di lunghezza maggiore di $k - 1$. Allora, accodando $x_m = y_n$ a $W$ si ottiene una sottosequenza comune di $X$ e $Y$ la cui lunghezza è maggiore di $k$, che è una contraddizione.
5. Se $z_k \neq x_m$, allora $Z$ è una sottosequenza comune di $X_{m-1}$ e $Y$. Se esistesse una sottosequenza comune $W$ di $X_{m-1}$ e $Y$ di lunghezza maggiore di $k$, allora $W$ sarebbe anche una sottosequenza comune di $X_m$ e $Y$, contraddicendo l’ipotesi che $Z$ sia una LCS di $X$ e $Y$.
6. La dimostrazione è simmetrica a quella del punto (2).

###### Longest common substring
Se i caratteri $X[i]$ e $Y[j]$ sono uguali, allora la lunghezza del suffisso comune che termina in $(i, j)$ dipende direttamente dalla lunghezza del suffisso comune che terminava in $(i-1, j-1)$. Di seguito la dimostrazione:

Supponiamo che $X[i] = Y[j]$. Poiché stiamo cercando una sottostringa, il carattere corrente estende semplicemente ciò che c'era immediatamente prima. Se la soluzione per $(i, j)$ è una stringa di lunghezza $K > 1$, significa che i caratteri $X[i]$ e $Y[j]$ sono l'ultimo carattere di questa stringa.  Se rimuoviamo questo ultimo carattere, rimaniamo con una sottostringa comune di lunghezza $K-1$ che termina agli indici $i-1$ e $j-1$.

Affinché la soluzione a $(i, j)$ sia ottima (massima), anche la soluzione a $(i-1, j-1)$ deve essere ottima. Se ci fosse un suffisso comune più lungo a $(i-1, j-1)$, potremmo aggiungerci $X[i]$ (che è uguale a $Y[j]$) ottenendo un risultato migliore per $(i, j)$, contraddicendo l'ipotesi iniziale.

###### Distanza di editing

**Tesi**: Sia $S$ una sequenza ottima di operazioni che trasforma il prefisso $X[1\dots i]$ nel prefisso $Y[1\dots j]$. Vogliamo dimostrare che la sottosequenza contenuta in $S$ che risolve i sottoproblemi deve essere a sua volta ottima. 

**Dimostrazione**: analizziamo l'ultima operazione effettuata nella sequenza $S$, da qui distinguiamo 3 casi possibili
1. L'utlima operazione è una sostituzione, allora $S$ è composta da una sottosequenza $S'$ e da un operazione di sostituzione, allora il suo costo totale è $$\text{costo(S) = Costo(S') + costo sostituzione}$$Se $S'$ per assurdo non è ottima allora esisterebbe $S''$ con un costo strettamente minore, questo significa che abbiamo trovato una soluzione $W$ con un costo minore di $S$, siamo arrivati ad una contraddizione
2. Analoga ma con la cancellazione come ultima operazione
3. Analoga ma con l'inserimento come ultima operazione
###### Huffman
**Definizioni iniziali:**
- $\Sigma$: Insieme dei caratteri (soluzione $T$)
- Consideriamo due nodi $a$ e $b$ (le foglie con frequenza minima) e il loro genitore $z$.
- $\Sigma' = \Sigma - \{a, b\} \cup \{z\}$ (soluzione $T'$)

**Relazioni tra frequenze e profondità:**
1. $f(z) = f(a) + f(b)$
2. $d_T(a) = d_{T'}(z) + 1$ e $d_T(b) = d_{T'}(z) + 1$
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
###### Activity selector
**Tesi**
Per dimostrare la sottostruttura ottima, definiamo l'insieme $S_{ij}$ come l'insieme delle attività che iniziano dopo la fine di $a_i$ e finiscono prima dell'inizio di $a_j$. Supponiamo che una soluzione ottima $A_{ij}$ contenga l'attività $a_k$. Se questa attività fa parte della soluzione, essa divide il problema in due sottoproblemi:
1. Trovare le attività compatibili in $S_{ik}$ (quelle che stanno tra $a_i$ e $a_k$).
2. Trovare le attività compatibili in $S_{kj}$ (quelle che stanno tra $a_k$ e $a_j$).
La soluzione totale sarà quindi: $A_{ij} = A_{ik} \cup \{a_k\} \cup A_{kj}$. E la sua dimensione sarà: $|A_{ij}| = |A_{ik}| + |A_{kj}| + 1$.

**Dimostrazione**
Per dimostrare che la soluzione è ottima, procediamo per assurdo. Supponiamo che la sottoparte $A_{kj}$ non sia ottima. Allora deve esistere un altro insieme $A'_{kj}$ più grande (cioè con più attività). Se fosse così, potremmo "tagliare" $A_{kj}$ dalla nostra soluzione originale e "incollarci" $A'_{kj}$. In questo modo otterremmo una soluzione totale più grande di $A_{ij}$. Ma questo è impossibile, perché avevamo ipotizzato che $A_{ij}$ fosse già la soluzione massima. Questa contraddizione ci conferma che una soluzione ottima deve per forza contenere le soluzioni ottime dei suoi sottoproblemi.
###### Cammini minimi
**Teorema**: Dati
- un grafo orientato $G = (V,E)$ 
- la funzione peso $w: E \rightarrow R$ 
- sia $p = (v_0,v_1, \dots, v_k)$ un cammino minimo dal vertice $v_0$ al $v_k$ 
per qualsiasi $i$ e $j$ tali che $0\le i \le j \le k$ sia $p_{ij}$ un sotto-cammino di $p$ dal vertice $v_i$ al vertice $v_j$ allora $P_{ij}$ è un cammino minimo da $v_i$ a $v_j$
**Dimostrazione**: Se scomponiamo il cammino $p$ in $$\nu_0 \overset{p_{0i}}{\leadsto} \nu_i \overset{p_{ij}}{\leadsto} \nu_j \overset{p_{jk}}{\leadsto} \nu_k $$abbiamo $w(p) = w(p_{0i})+w(p_{ij})+w(p_{jk})$. 
Supponiamo adesso che ci sia un cammino $p'_{ij}$ da $v_i$ a $v_j$ con peso $w(p'_{ij})<w(p_{ij})$. Allora $\nu_0 \overset{p_{0i}}{\leadsto} \nu_i \overset{p'_{ij}}{\leadsto} \nu_j \overset{p_{jk}}{\leadsto} \nu_k$ è un cammino da $v_0$ a $v_k$ il cui peso è minore di $w(p)$ che contraddice l'ipotesi che $p$ sia un cammino minimo da $v_0$ a $v_k$

### Scelta greedy

###### Huffman
**Teorema**: possiamo scegliere i due nodi con frequenza più bassa ad ogni passaggio e questa scelta localmente ottima è anche una scelta globalmente ottima
**Dimostrazione**:
1. Abbiamo $T$ che rappresenta una soluzione ottima, ma in cui la scelta greedy non è stat necessariamente rispettata, quindi $x$ e $y$ due nodi con la frequenza minima non sono fratelli e si trovano in una posizione qualsiasi
2. Prendiamo $a$ e $b$ due nodi fratelli alla massima profondità dell'albero, su questi nodi possiamo dire che:
	1. $f(x)\le f(a)$ e $f(x)\le f(b)$
	2. $d_t(a) \ge d_t(x)$ e $d_t(b) \ge d_t(y)$
3. Creaiamo un nuovo albero $T'$ uguale a $T$ ma con $x$ e $a$ scambiati (stessa cosa per $y$ e $b$). Ricordando che il costo di $T$ è deifnito come $$\sum f(c)*d_t(c)$$di seguito vediamo quanto ci è costato passare da $T$ a $T'$:
   $$B(T)-B(T') = f(x)d_T(x)+f(a)d_T(a)-[f(x)d_T(a)+f(a)d_T(x)]$$$$B(T)-B(T') = f(x)(d_T(x)-d_T(a))+f(a)(d_T(a)-d_T(x))$$$$B(T)-B(T') = (f(a)-f(x))*(d_T(a)-d_T(x))$$Analizzando i segni
   - le frequenze $f(a)-f(x) \ge 0$
   - la profondità $d_T(a)-d_T(x)\ge 0$
Poiché stiamo moltiplicando due numeri non negativi abbiamo che: $$B(T)-B(T') \ge 0 \Rightarrow B(T) \le B(T')$$ visto che $T$ e $T'$ sono uguali allora il loro costo sarà lo stesso. Questo dimostra che la scelta greedy è sicura.
###### Activity Selector
**Generalità**: Le attività in $S$ sono ordinate in modo crescente in base al tempo di fine
**Teorema:** Consideriamo un sottoproblema non vuoto $S_k$ e sia $a_m$ l’attività in $S_k$ che ha il primo tempo di fine; allora l’attività $a_m$ è inclusa in qualche sottoinsieme massimo di attività mutuamente compatibili di $S_k$ (prendiamo quella con il tempo di fine più basso).
**Dimostrazione:**
Supponiamo che $A_k$ sia un sottoinsieme massimo di attività mutuamente compatibili di $S_k$ e sia $a_j$ l’attività in $A_k$ con il più piccolo tempo di fine.
1. Se $a_j = a_m$, abbiamo finito (l'attività golosa è già nell'insieme ottimo).
2. Se $a_j \neq a_m$, costruiamo l'insieme $A'_k = (A_k - \{a_j\}) \cup \{a_m\}$ (sostituiamo $a_j$ con $a_m$).
    - Le attività in $A'_k$ sono disgiunte perché lo è anche $A_k$ e $f_m \le f_j$ (poiché $a_m$ è la scelta golosa).
    - Poiché $|A'_k| = |A_k|$, concludiamo che $A'_k$ è un sottoinsieme massimo che include $a_m$.

### Dimostrazioni generiche
###### Hashing con concatenazione
**Ricerca senza successo**: una ricerca senza successo richiede un tempo di $\Theta(1+\alpha)$ nel caso medio
  *Dimostrazione*: Il tempo atteso per ricercare senza successo una chiave $k$ è il tempo atteso per svolgere ricerche fino alla fine della lista $T[h(k)]$ che ha lunghezza attesa di $\alpha$ quindi il tempo totale richiesto (incluso quello per calcolare $h(k)$ che ipotizziamo sia $O(1)$) è $$\Theta(1+\alpha)$$
**Ricerca con successo**: una ricerca con successo richiede un tempo di $\Theta(1+\alpha)$ nel caso medio
  *Dimostrazione*: il numero di elementi esaminati durante una ricerca con successo di un elemento $x$ è uno in più del numero di elementi che si trovano prima di $x$ nella lista di $x$. Gli elementi prima di $x$ li troviamo facendo: $$1+\sum_{j=i+1}^{n}Pr(x_{ij})$$Ricordiamo che $Pr(x_{ij}) = \frac{1}{m}$. Dunque il numero atteso di elementi esaminati con successo è:$$\frac{1}{n} \sum^n_{i=1}(1+\sum^n_{j = n+1} Pr\{x_{ij}\})$$Di seguito la risoluzione:
	- Distribuiamo la sommatoria dentro la parentesi e sostituiamo $Pr\{x_{ij}\}$:$$\frac{1}{n}(\sum^n_{i=1}1+\sum^n_{i=1}\sum^n_{j = n+1}\frac{1}{m})$$
	- Riscrivo la prima sommatoria semplicemente come $n$ e sposto fuori la costante $\frac{1}{m}$: $$\frac{1}{n}(n+\frac{1}{m}\sum^n_{i=1}\sum^n_{j = n+1}1)$$
	- Riscrivo la sommatoria con $j$ come $n-i$: $$\frac{1}{n}(n+\frac{1}{m}\sum^n_{i=1}(n-i))$$
	- Riscrivo le sommatorie come differenza di sommatorie $$\frac{1}{n}\Big(n+\frac{1}{m}(\sum^n_{i=1} n \ -\sum^n_{j = n+1}i)\Big)$$
	- Risolvo le sommatorie $$\frac{1}{n}\Big(n+\frac{1}{m}(n^2-\frac{n(n+1)}{2})\Big)$$
	- Risolvo i calcoli rimanenti $$1+\frac{1}{mn}\Big(n^2-\frac{n(n+1)}{2}\Big) = 1 + \frac{n}{m} - \frac{n+1}{2m} \in O(1+\alpha)$$

###### Hashing con indirizzamento aperto
**Ricerca senza successo**: data una tavola hash con un fattore di carico $\alpha = n/m < 1$ il numero atteso di ispezioni in una ricerca senza successo è al massimo $\frac{1}{1-\alpha}$
*Dimostrazione*: ![[Pasted image 20251214181345.png|600]]

**Ricerca con successo**: data una tavola hash con un fattore di carico $\alpha = n/m < 1$ il numero atteso di ispezioni in una ricerca senza successo è al massimo $\frac{1}{\alpha}\ln\frac{1}{1-\alpha}$
*Dimostrazione*: ![[Pasted image 20251214181414.png|600]]

###### Altezza massima
**Definizione altezza massima**: l'altezza massima di un albero rosso-nero con $n$ nodi interni è $2 \log_2(n+1)$

***Dimostrazione:*** Iniziamo dimostrando che il sottoalbero con radice in un nodo $x$ qualsiasi contiene almeno $2^{bh(x)}-1$ nodi interni, lo faremo per induzione:
- *caso base*: Se l'altezza di $x$ è $0$ allora $x$ deve essere una foglia e il sottoalbero con radice in $x$ contiene: $2^0 - 1 = 1-1 = 0$
- *passo induttivo*: consideriamo un nodo $x$ che ha un altezza positiva ed è quindi un nodo interno con due figli. 
  Possiamo dire che ogni figlio ha un altezza nera pari a:
	- se rosso ha $bh(x)$
	- se nero ha $bh(x)-1$ (perché escludo il nodo stesso dal conteggio)
  Poiché l'altezza di un figlio di $x$ è minore dell'altezza di $x$ possiamo applicare l'ipotesi induttiva per concludere che ogni figlio ha almeno $$2^{bh(x)-1}-1 \text{ nodi interni }$$e quindi possiamo concludere che il sottoalbero con radice in $x$ contiene: $$
\underbrace{(2^{bh(x)-1}-1)}_{\text{nodi interni albero sx}} + \underbrace{(2^{bh(x)-1}-1)}_{\text{nodi interni albero dx}} + 1 = 2^{bh(x)} - 1 \;\text{nodi interni}
$$il che dimostra l'asserzione iniziale. 

Per completare la dimostrazione indichiamo con $h$ l'altezza dell'albero, sappiamo che almeno metà dei nodi in qualsiasi cammino semplice della radice ad una foglia deve essere nera, di conseguenza l'altezza nera della radice è $h/2$ (perché lungo il cammino i nodi si alternano rosso/nero) quindi abbiamo che: $$n \ge 2^{h/2}-1$$dove $n$ è il numero di nodi interni del nostro albero. Spostando $1$ nel lato sinistro e prendendo i logaritmi di entrambi i lati otteniamo: $$log_2(n+1) \ge h/2 \; \text{ ovvero } \; h \le 2\log_2(n+1)$$
