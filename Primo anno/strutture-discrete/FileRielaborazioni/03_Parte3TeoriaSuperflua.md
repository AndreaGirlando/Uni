
#### Disposizioni e combinazioni
Proviamo adesso a rispondere alle seguenti 4 domande puramente matematiche:
1. Dati due insiemi $A$ e $B$, con $|A| = k, |B| = n$ quante sono le [[Uni/Primo anno/strutture-discrete/FileRielaborazioni/Tips#Differenza tra applicazione e funzione|applicazioni]] di $A$ in $B$?
	- Il numero delle ==disposizioni con ripetizione== di $n$ elementi di classe $k$: denotato con: 
		- **$D_{n,k}^r$** 
1. Dati due insiemi $A$ e $B$, con $|A| = k, |B| = n$ quante sono le applicazioni iniettive di $A$ in $B$?
	- Numero delle ==disposizioni semplici== di $n$ elementi di classe $k$ denotato con:
		- $D_{n,k}$ 
1. Dato un insieme $B$, con $|B| = n$, e preso un intero $k ≤ n$, quanti sono i sottoinsiemi di $B$ composti di $k$ elementi ?
	  - Numero delle combinazioni di $n$ elementi di classe $k$: denotato con 
		  - $C_{n,k}$
1. Dato un insieme di $n$ variabili, $\{x_1, x_2, . . . , x_n\}$ e preso un un intero $k ≤ n$, quanti sono i monomi, con coefficiente $1$, di grado $k$ definiti sulle $n$ variabili date?
   Esempio: $x^2_1 x_3 x^3_4$ monomio di grado $6$, $x_2^2 x_4 x_5$ monomio di grado $4$.
	- Numero delle combinazioni di $n$ elementi di classe $k$ con ripetizione: denotato con:
		- $C^r_{n,k}$ 
##### Disposizioni con ripetizione
Per calcolare $D_{n,k}^r$ utilizziamo la regola del prodotto, infatti per ognuno dei $k$ elementi di $A$ dobbiamo scegliere uno tra gli elementi di $B$, ogni scelta è indipendente dalle scelte fatte precedentemente, questo perché il primo elemento di $A$ ha $n$ scelte per la sua immagine in $B$ stessa cosa vale anche per l'n-esimo elemento di $A$. Quindi il numero di disposizioni con ripetizione è $n$ moltiplicato $k$ volte per se stesso ovvero 
- $n^k$ 
![[Pasted image 20241214111501.png]]
##### Disposizioni semplici
Come prima cosa, notiamo che affinché esista un’[[01_Parte1#Funzione iniettiva|applicazione iniettiva]] da $A$ in $B$, con $|A| = k$ e $|B| = n$ deve essere $n ≥ k$. Per calcolare $D_{n,k}$ utilizziamo la regola del prodotto. Dobbiamo fare $k$ operazioni di scelta, tali che:
- La prima operazione si può fare in $n$ modi
- La seconda in $n-1$ modi
- La k-esima operazione si può fare in $n-k + 1$ modi
l'intera operazione, ovvero il numero di scelte totali è:
- $D_{n,k} = n(n-1)*\dots*(n-k+1) = \frac{n!}{(n-k)!}$ 

**Risposta 5**: Quante squadre di calcio diverse posso formare da un gruppo di 50 studenti?
![[Pasted image 20241214133049.png]]

##### Permutazioni
Il numero di permutazioni semplici o sostituzioni è il numero di disposizioni semplici di classe $n$ cioè $D_{n,n} = \frac{n!}{(n-n)!}$ ovvero $n!$ 
Quindi il numero delle Permutazioni è il numero delle [[01_Parte1#Funzione iniettiva|applicazione iniettiva]] di un insieme in un altro di cardinalità uguale. Queste applicazioni sono ovviamente anche [[01_Parte1#^cc7f98|surgettive]] e quindi il numero delle permutazioni è il numero delle [[01_Parte1#Funzione biiettiva|biiezioni]] di un insieme in un altro della stessa cardinalità.
![[Pasted image 20241214150710.png]]

##### Combinazioni
Consideriamo l'insieme di tutte le $D_{n,k}$ applicazioni iniettive di un insieme $A$ di $k>0$ elementi in un insieme $B$ di $n$ elementi($k \le n$). Data una qualunque applicazione iniettiva $f$ la sua [[01_Parte1#^329b13|immagine]] è un sottoinsieme di $B$ che contiene $k$ elementi (ovvero tutti i valori che la funzione potrà assumere che saranno proprio $k$ visto che la funzione iniettiva associa ad ogni elemento di B solo elemento di A). Da questa premessa introduciamo la seguente [[01_Parte1#^927242|relazione di equivalenza]]:
- f ≈ g ⇔ f(A) = g(A)
Quindi due applicazioni si dicono equivalenti se hanno la stessa immagine. Le possibili classi di equivalenza sono tante quanti i sottoinsiemi di B costituiti da $k$ elementi, che denoteremo con $C_{n,k}$ quindi $D_{n,k}$ = $C_{n,k}$ · $k!$ da cui ricaviamo che $C_{n,k}$ = $\frac{n!}{k!(n-k)!}$. I valori $n,k$ sono anche detti coefficienti binomiali e sono indicati con il simbolo: $\binom{n}{k} = \frac{n!}{k!(n-k)!}$ 
##### Combinazione con ripetizione
Dato un insieme di $n > 1$ variabili, $\{x_0, x_1, . . . , x_{n−1}\}$ e preso un un intero k, i monomi di grado $k$ sono $C_{n,k}^r = \binom{n+k-1}{k}$ 