Questo è la rielaborazione del file [[Appunticap2.pdf]]
# Successioni di numeri reali
### Successioni
###### Definizione
Una successione di numeri reali è una funzione reale definita in $N$ ([[Capitolo 1#Simbologia insiemi numerici e operazioni in N|definizione di N]]) di questo tipo: $f: N \rightarrow R$. 

> [!TIP]
> In parole semplici: per ogni numero naturale $n$, la funzione ti dà un numero reale $a_n$​, che è il termine della successione in posizione $n$.

Se $n \in N$ si usa la notazione $a_n = f(n)$, in questo modo la successione viene identificata con l'insieme dei suoi elementi: ${a_n}$ , l'elemento generico $a_n$ viene detto elemento di posto $n$.   
**Verifica definitivamente:** Si dice che la successione verifica *definitivamente* (nel seguito semplicemente **D**) una condizione $P$ se esiste una $\alpha \in N$ tale che per ogni $n>\alpha$ l'elemento $a_n$ verifica $P$.
> [!TIP]
> Verifica definitivamente vuol dire che **dopo un certo punto**(ovvero un certo $n$), tutti i termini della successione rispettano una certa proprietà.

> [!EXAMPLE]
> La successione: $a_n = n-4$ ovvero l'insieme: $\{-3,-2,-1,0,1,2,3,\dots\}$  
> come possiamo bene notare la successione dopo $n=5$ è sempre positiva e quindi possiamo affermare che la successione è *definitivamente positiva*
> 

Se due condizioni sono verificate definitivamente ad esempio una per $n>\alpha$ e una per $n>\beta$ allora per $n>max(\alpha,\beta)$ valgono entrambe.

###### Successione limitata
Una successione è detta limitata se lo è l'insieme dei suoi termini ovvero se esistono $h,k \in R$ tali che $h\le a_n \le k$ per ogni $n \in N$ si ha quindi che $\{a_n\} ⊆ [h,k]$, i concetti di minimo, massimo, estremo inferiore o superiore coincidono con quelli relativi all'insieme dei suoi termini.

> [!EXAMPLE]
> La successione: $a_n = n-1$ ovvero l'insieme: $\{0,1,2,3,\dots\}$  che ha come minimo 0

**Proposizione**: Una successione $D$ limitata è limitata.
**Dimostrazione**: Se si ha $h\le a_n \le k$ per ogni $n>\alpha$ ponendo:
- $h' = min\{h,a_1,\dots,a_\alpha\}$
- $k' = max\{k,a_1,\dots,a_\alpha\}$
 si ha $h' \le a_n \le k'$ per ogni $n \in N$ 

### Successioni regolari
###### Limite di una successione
Sia $l$ un numero reale. Si dice che la successione $\{a_n\}$ **converge o tende** ad $l$ o che $l$ è il **limite della successione** (che si denota con $a_n \rightarrow l$ o $a_n = l$) se è verificata la seguente condizione: $$\forall\epsilon>0 \ \exists\alpha \in N: n>\alpha \Rightarrow |a_n-l| < \epsilon$$ovvero se dato un qualunque intorno di $l$, definitivamente i termini delle successione (${a_n}$) appartengono a tale intorno, questo si traduce in termini matematici in questa cosa:
1. $|a_n-l|<\epsilon \Longleftrightarrow$ 
2. $-\epsilon < a_n-l < \epsilon \Longleftrightarrow$
3. $l-\epsilon < a_n < l+\epsilon$ 
> [!EXAMPLE]
> La successione: $a_n = k$ tende a $k$
> La successione $\frac{1}{n}$ tende a 0

###### Teoremi