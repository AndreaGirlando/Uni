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

^4aff97

Una successione è detta limitata se lo è l'insieme dei suoi termini ovvero se esistono $h,k \in R$ tali che $h\le a_n \le k$ per ogni $n \in N$ si ha quindi che $\{a_n\} ⊆ [h,k]$, i concetti di minimo, massimo, estremo inferiore o superiore coincidono con quelli relativi all'insieme dei suoi termini.

> [!EXAMPLE]
> La successione: $a_n = n-1$ ovvero l'insieme: $\{0,1,2,3,\dots\}$  che ha come minimo 0

**Proposizione**: Una successione $D$ limitata è limitata.
**Dimostrazione**: Se si ha $h\le a_n \le k$ per ogni $n>\alpha$ ponendo:
- $h' = min\{h,a_1,\dots,a_\alpha\}$
- $k' = max\{k,a_1,\dots,a_\alpha\}$
 si ha $h' \le a_n \le k'$ per ogni $n \in N$ 

### Successioni regolari
###### Limite di una successione (converge)
Sia $l$ un numero reale. Si dice che la successione $\{a_n\}$ **converge o tende** ad $l$ o che $l$ è il **limite della successione** (che si denota con $a_n \rightarrow l$ o $\lim a_n = l$) se è verificata la seguente condizione: $$\forall\epsilon>0 \ \exists\alpha \in N: n>\alpha \Rightarrow |a_n-l| < \epsilon$$ovvero se dato un qualunque intorno di $l$, definitivamente i termini delle successione (${a_n}$) appartengono a tale intorno, questo si traduce in termini matematici in questa cosa:
1. $|a_n-l|<\epsilon \Longleftrightarrow$ 
2. $-\epsilon < a_n-l < \epsilon \Longleftrightarrow$
3. $l-\epsilon < a_n < l+\epsilon$ 
Se questa condizione è vera, significa che la successione "si stabilizza" attorno al valore $l$. E quindi che man mano che $n$ diventa grande, i termini $a_n$​ rimangono vicini ad $l$ quanto vogliamo (scegliendo un $ε$ sufficientemente piccolo).
> [!warning]
> Con $\lim a_n = l$ intendiamo $\lim_{n \to \infty} a_n = l$ 
> ovvero quando il valore di $n$ va verso infinito il valore della del nostro generico $a_n$ si avvicina ad $l$ viene approfondito dopo i teoremi
 
> [!quote]
> ![[Screenshot_20250511_172815_Samsung capture.jpg]]
> Salvo Romeo

> [!EXAMPLE]
> La successione: $a_n = k$ tende a $k$
> La successione $\frac{1}{n}$ tende a 0

###### Teoremi
**Teorema dell'unicità del limite**: se una successione converge, il suo limite è unico
**Dimostrazione**: Supponiamo per assurdo che esistano 2 limiti: $a_n \rightarrow l$ e $a_n \rightarrow L$ con $l<L$. Scelto un $\epsilon$ tale che $0<\epsilon<\frac{L-l}{2}$, allora abbiamo la seguente disequazione: $$a_n<l+\epsilon < L-\epsilon < a_n$$ come possiamo notare abbiamo $a_n < a_n$ che è un assurdità.

---

**Teorema della permanenza del segno**: Se $a_n \rightarrow l>0$ (o $l<0$) allora si ha definitivamente $a_n >0$ (o $a_n<0$)
**Teorema non in matematichese**: questa cosa significa che se $l>0$ (o $l<0$) allora prima o poi nella successione anche $a_n$ sarà $> 0$ (o $<0$)
**Dimostrazione**: Supponiamo $l>0$. Scelto $\epsilon$ tale che $0<\epsilon<l$ allora definitivamente si ha $a_n>l-\epsilon>0$ (il caso $l<0$ si prova in modo simile)
Generalizzando possiamo dire che:
- preso un numero $h$ e $a_n \rightarrow l$ con $h<l$ allora definitivamente si ha che $a_n > h$
- preso un numero $k$ e $a_n \rightarrow l$ con $k>l$ allora definitivamente si ha che $a_n<k$  

---
**Teorema di confronto per successioni convergenti**: Se $a_n<b_n<c_n$ per ogni $n \in N$ e $a_n \rightarrow l$, $c_n \rightarrow l$ allora $b_n \rightarrow l$
**Teorema non in matematichese**: se le successioni $a_n$ e $c_n$ tendono ad $l$ e sappiamo che un terza successione $b_n$ è compresa tra $a_n$ e $c_n$ per ogni $n \in N$ allora anche queste tende a $l$ 
**Dimostrazione**: per la definizione di limite sappiamo che definitivamente si ha:
- $l-\epsilon < a_n < l+\epsilon$ 
- $l-\epsilon < c_n < l+\epsilon$ 
allora si ha sicuramente che: $$l-\epsilon < a_n<b_n<c_n < l+\epsilon$$
###### Limiti di una successione (diverge) 
Si dice che la successione $\{a_n\}$ **diverge o tende** a $+\infty$ (o $-\infty$) e si denota con $a_n \rightarrow +\infty$ o $\lim a_n = +\infty$(o $-\infty$) se e solo se è verificata la seguente condizione: $$\forall k > 0 \exists \alpha \in N: n>\alpha \Rightarrow a_n > k$$ vale ovviamente anche:
$$\forall k > 0 \exists \alpha \in N: n>\alpha \Rightarrow a_n < k$$ovvero $a_n\rightarrow +\infty\backslash\infty$ se e solo se definitivamente preso un qualsiasi numero trovo all'interno della successione un numero maggiore\minore. 
Anche per la divergenza vale l'unicità del limite, per quanto riguarda il teorema delle permanenza del segno possiamo dire che i termini di una successione divergente sono positivi/negativi.
> [!TIP] 
> Una successione di numeri positivi può tendere:
> - ad un limite positivo
> - a zero
> 	- $a_n = \frac{1}{n}$
> - a $\infty$
>
Una successione di numeri negativi può tendere:
> - ad un limite negativo
> - a zero
> 	- $a_n = -\frac{1}{n}$
> - a $-\infty$ 

###### Altri teoremi
**Teoremi di confronto per successioni divergenti**: Se $a_n \le b_n$ per ogni $n \in N$ e $a_n \rightarrow +\infty$ allora $b_n \rightarrow +\infty$ oppure se $b_n \rightarrow -\infty$ allora $a_n \rightarrow -\infty$  
**Teorema non in matematichese**: se la successione $a_n$ è sempre più piccola di $b_n$ allora se $a_n\rightarrow +\infty$ anche $b_n \rightarrow \infty$ (anche l'altro caso funziona allo stesso modo)  
**Dimostrazione**: Se $a_n \rightarrow +\infty$ allora definitivamente si ha $a_n>k$ ne segue che $b_n \ge a_n >k$ (l'altro caso si prova in modo analogo)

###### Successione regolare o oscillante
Una successione è detta **regolare** se converge o diverge, per una successione regolare il limite è unico, quando una successione non è regolare allora è detta oscillante

> [!EXAMPLE]
> Per capire bene questo esempio bisogna ricordarsi la [[#^4aff97|definizione di limite]]
> ![[Pasted image 20250514175914.png]]

###### Successioni e valore assoluto
