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
**Teorema di confronto per successioni divergenti**: Se $a_n \le b_n$ per ogni $n \in N$ e $a_n \rightarrow +\infty$ allora $b_n \rightarrow +\infty$ oppure se $b_n \rightarrow -\infty$ allora $a_n \rightarrow -\infty$  
**Teorema non in matematichese**: se la successione $a_n$ è sempre più piccola di $b_n$ allora se $a_n\rightarrow +\infty$ anche $b_n \rightarrow \infty$ (anche l'altro caso funziona allo stesso modo)  
**Dimostrazione**: Se $a_n \rightarrow +\infty$ allora definitivamente si ha $a_n>k$ ne segue che $b_n \ge a_n >k$ (l'altro caso si prova in modo analogo)

###### Successione regolare o oscillante
Una successione è detta **regolare** se converge o diverge, per una successione regolare il limite è unico, quando una successione non è regolare allora è detta oscillante

> [!EXAMPLE]
> Per capire bene questo esempio bisogna ricordarsi la [[#^4aff97|definizione di limite]]
> ![[Pasted image 20250514175914.png]]

###### Successioni e valore assoluto
Accanto alla successione $\{ a_n \}$ consideriamo la successione $\{ |a_n| \}$ allora possiamo affermare le seguenti cose:
1. Se $a_n \rightarrow l$ allora $|a_n| \rightarrow l$ 
  il viceversa non vale infatti posto $a_n = (-1)^n$ la successione dei valori assoluti è constante e converge ad $l$ (in questo caso $l=1$) ma $\{a_n\}$ oscilla
2. Se $a_n \rightarrow +\infty$ oppure $a_n \rightarrow -\infty$ si ha $|a_n| \rightarrow +\infty$ 
   il viceversa non vale infatti posto $a_n = (-1)^nn$ la successione dei valori assoluti vale $n$ e quindi diverge invece $\{a_n\}$ oscilla.
   Se $|a_n| \rightarrow +\infty$ allora la successione $\{a_n\}$ è detta **infinitamente grande**
###### Regolarità e limitatezza
Si hanno le seguenti affermazioni:
- Una successione convergente è **limitata**, infatti essa è **D** compresa ad esempio tra $l-1$ e $l+1$ quindi è **D** limitata, non vale il viceversa infatti $\{(-1)^n\}$ è limitata ma oscillante
- Una successione che diverge a $+\infty$ è limitata inferiormente
- Una successione che diverge a $-\infty$ è limitata superiormente

### Successioni monotone
Si dice che la successione $\{a_n\}$ è **monotona** se verifica una delle seguenti condizioni:
1. $a_n > a_{n+1}$ *successione strettamente decrescente*
	- Se $a_n$ è maggiore di $a_{n+1}$ allora la funzione sta decrescendo
2. $a_n \ge a_{n+1}$ *successione  decrescente*
	- Se $a_n$ è maggiore o uguale di $a_{n+1}$ allora la funzione sta decrescendo
3. $a_n < a_{n+1}$ *successione strettamente crescente*
	-  Se $a_n$ è minore di $a_{n+1}$ allora la funzione sta crescendo
4. $a_n \le a_{n+1}$ *successione crescente*
	-  Se $a_n$ è minore o uguale di $a_{n+1}$ allora la funzione sta crescendo

###### Altri teoremi
**Teorema di regolarità (o sul limite) delle successioni monotone**:
- Una successione che verifica una delle condizioni $1)$ e $2)$ tende al suo estremo inferiore
- Una successione che verifica una delle condizioni $3)$ e $4)$ tende al proprio estremo superiore
**Dimostrazione**
Proviamo per semplicità solo il caso della divergenza:
1. Se $\inf a_n = -\infty$ fissato $k>0$ il numero $-k$ non è un minorante per la successione perché esiste sicuramente un numero nella successione più piccolo di $k$  ovvero $a_\alpha <-k$. Per $n> \alpha$ si ha $a_n \ge a_\alpha >k$ che è la tesi
2. Se $\sup a_n = +\infty$ fissato $k>0$ il numero $k$ non è un maggiorante per la successione perché esiste sicuramente un numero nella successione più grande di $k$ ovvero $a_\alpha > k$. Per $n>\alpha$  si ha $a_n>a_\alpha>k$ che è la tesi


### Operazioni con i limiti delle successioni
###### 1. Successione con uno scalare
Sia $\{a_n\}$ una successione regolare e sia $c$ un numero reale. Prendiamo in considerazione la successione $\{ca_n\}$ allora si ha:
	1. se $a_n \rightarrow l$ allora $ca_n \rightarrow cl$ 
	2. se $a_n \rightarrow +\infty$ e $c>0$ allora $ca_n \rightarrow +\infty$  
	3. se $a_n \rightarrow +\infty$ e $c<0$ allora $ca_n \rightarrow -\infty$ 
	4. se $a_n \rightarrow -\infty$ e $c>0$ allora $ca_n \rightarrow -\infty$  
	5. se $a_n \rightarrow -\infty$ e $c<0$ allora $ca_n \rightarrow +\infty$ 
	**Dimostrazione**:
	- 1) se $c = 0$, la tesi è ovvia, se $c\not=0$ per ottenere $|ca_n-cl|<\epsilon$  basta osservare che **D** si ha $|a_n - l|<\frac{\epsilon}{|c|}$  
	- 2) Per ottenere $ca_n>k$ basta osservare che **D** si ha $a_n > \frac{k}{c}$
	- 3) Per ottenere $ca_n <k$ basta osservare che **D** si ha $|a_n - l|<\frac{-k}{c}$ 
	- 4) e 5) si provano in modo simile
###### 2. Successione somma
Date due successioni $\{a_n\}$ e $\{b_n\}$ prendiamo in considerazione la **successione somma** $\{a_n+b_n\}$ allora si ha che:
	1. Se $a_n \rightarrow l$ e $b_n \rightarrow L$ allora $a_n+b_n \rightarrow l+L$ 
	2. Se $a_n \rightarrow +\infty$ ed esiste un numero $h \le b_n$ per ogni $n \in N$ allora $a_n + b_n \rightarrow +\infty$ 
   **Dimostrazione**:
	- 1) Fissato $\epsilon > 0$ esistono $\alpha, \beta \in N$ tali che per $n>\alpha$ si ha $|a_n - l|< \frac{\epsilon}{2}$ e per $n>\beta$ si ha $|b_n-L|<\frac{\epsilon}{2}$. Allora per $n>max(\alpha, \beta)$ si ha $$|(a_n+b_n) - (l+L)| \le |a_n -l| + |b_n - L| < \epsilon$$
	- 2) Si ha $a_n+b_n \ge a_n + h$ quindi dato che **D** si ha $a_n > k-h$ ne segue $a_n+b_n > k$ 
    **Osserviamo**: che la successione $\{b_n\}$ nel caso 2 può non essere regolare (e.g se $a_n = n$  e $b_n = (-1)^n$ si ha lo stesso che $a_n+b_n \rightarrow +\infty$) e quindi possiamo dedurre:
    1. Se $a_n \rightarrow +\infty$ e $b_n \rightarrow L$ allora $a_n+b_n \rightarrow +\infty$
    2. Se $a_n \rightarrow +\infty$ e $b_n \rightarrow +\infty$ allora $a_n+b_n \rightarrow +\infty$
    3. Se $a_n \rightarrow -\infty$ e $b_n \rightarrow  L$ allora $a_n+b_n \rightarrow -\infty$
    4. Se $a_n \rightarrow -\infty$ e $b_n \rightarrow  -\infty$ allora $a_n+b_n \rightarrow -\infty$
    se una delle due successioni diverge a $+\infty$ e l'altra a $-\infty$ (o viceversa) si ha una **forma indeterminata** questo significa che si posso avere molte situazioni diverse.    
> [!TIP]
> I risultati contenuti nei casi 1) e 2) sono utili per studiare le successioni del tipo $\{ca_n+c'b_n\}$
###### 3. Successione prodotto
Date due successioni $\{a_n\}$ e $\{b_n\}$ e prendiamo in considerazione la **successione prodotto** $\{a_n \cdot b_n\}$ si ha che:
	1. Se $a_n \rightarrow l$ e $b_n \rightarrow L$ allora $a_n \cdot b_n \rightarrow l \cdot L$  
	2. Se $a_n \rightarrow 0$ e $\{b_n\}$ è limitata allora $a_n \cdot b_n \rightarrow 0$ 
		- osserviamo che la successione $\{b_n\}$ può non essere regolare ($e.g.$ se $a_n = \frac{1}{n}$ e $b_n = (-1)^n$ si ha $a_n \cdot b_n \rightarrow 0$)
	3. Se $a_n \rightarrow +\infty$ ed esiste un numero positivo $h \le b_n$ per ogni $n \in N$ allora $a_n \cdot b_n \rightarrow +\infty$ 
	Dai risultati precedenti si deduce la seguente tabella sul comportamento della successione prodotto:
	- Se $a_n \rightarrow +\infty$ e $b_n \rightarrow L > 0$ allora $a_n \cdot b_n \rightarrow +\infty$ 
	- Se $a_n \rightarrow +\infty$ e $b_n \rightarrow +\infty$ allora $a_n \cdot b_n \rightarrow +\infty$ 
	- Se $a_n \rightarrow +\infty$ e $b_n \rightarrow L < 0$ allora $a_n \cdot b_n \rightarrow -\infty$ 
	- Se $a_n \rightarrow +\infty$ e $b_n \rightarrow -\infty$ allora $a_n \cdot b_n \rightarrow -\infty$ 
	- Se $a_n \rightarrow -\infty$ e $b_n \rightarrow L>0$ allora $a_n \cdot b_n \rightarrow -\infty$
	- Se $a_n \rightarrow -\infty$ e $b_n \rightarrow -\infty$ allora $a_n \cdot b_n \rightarrow +\infty$
	- Se $a_n \rightarrow - \infty$ e $b_n \rightarrow L < 0$ allora $a_n \cdot b_n \rightarrow +\infty$
   Infine se una delle due successione diverge e l'altra tende a $0$ si ha una **forma indeterminata**
###### 4. Successione reciproca
Sia $\{a_n\}$ una successione regolare e **D** non nulla, prendiamo in considerazione la **successione reciproca** $\{\frac{1}{a_n}\}$ allora possiamo dire che:
    1. Se $a_n \rightarrow l \not= 0$ allora $\frac{1}{a_n} \rightarrow \frac{1}{l}$
    2. Se $a_n \rightarrow 0$ allora $\frac{1}{a_n} \rightarrow \infty$ 
    3. Se $a_n \rightarrow \infty$ allora $\frac{1}{a_n} \rightarrow 0$
###### 5. Successione quoziente
Date due successioni $\{a_n\}$ e $\{b_n\}$ con $b_n \not= 0$ **D**, prendiamo in considerazione la **successione quoziente** $\{\frac{a_n}{b_n}\}$. Essa viene studiata utilizzando i risultati visti ai punti 3 e 4 scrivendola nella forma $a_n \cdot \frac{1}{b_n}$ 
### Limiti notevoli
Alcune successioni sono espresse mediante funzioni elementari, e qui vediamo le più comuni:
###### Successione potenza
ovvero $\{n^x\} \text{ con } x \in R$  
	- Se $x = 0$ la successione è costante
	- Se $x > 0$ si ha $n^x \rightarrow +\infty$ 
	- Se $x<0$ si ha $x^n = \frac{1}{n^{-x}} \rightarrow 0$ 
###### Successione in forma di polinomio 
ovvero $x_n = a_0n^p+a_1n^{p-1}+\cdots+a_p$  che per semplicità si trasforma in: $$x_n = n^p(a_0+\frac{a_1}{n}+\cdots+\frac{a_p}{n^p})$$ e si ha che $n^p \rightarrow +\infty$ mentre la quantità fra parentesi tende ad $a_0$ quindi:
	- $x_n \rightarrow +\infty$ se $a_0 >0$ 
	- $x_n \rightarrow -\infty$ se $a_0 < 0$ 	  
> [!TIP]
> I termini dentro la parentesi tendono a $0$ perché all'aumentare di $n$ verso $\infty$ questi numeri diventano sempre più piccoli e quindi tendono a $0$, l'unico valore importante per determinare la tendenza della successione è quello di grado più alto ovvero $a_0$ che se moltiplicato per $n^P$ tende a $+\infty/-\infty$ in base al segno 

###### Successione in forma di funzione razionale
ovvero $x_n = \frac{a_0n^p+a_1n^{p-1}+\cdots+a_p}{b_0n^p+b_1n^{p-1}+\cdots+b_p}$ che possiamo scrivere anche come: $$x_n = n^{p-q} \frac{a_0+\frac{a_1}{n}+\cdots+\frac{a_p}{n^p}}{b_0+\frac{b_1}{n}+\cdots+\frac{b_p}{n^p}}$$usando quello che abbiamo detto per le successioni in forma di polinomio possiamo affermare che: 
    1. se $p = q$ si ha $x_n \rightarrow \frac{a_0}{b_0}$
    2. se $p<q$ si ha $x_n \rightarrow 0$ 
    3. se $p>q$ si ha $x_n \rightarrow +\infty$ se $a_0$ e $b_0$ hanno lo stesso segno
    4. se $p>q$ si ha $x_n \rightarrow -\infty$ se $a_0$ e $b_0$ hanno lo segno diverso
> [!EXAMPLE]
> - $\frac{2n^2 + 5n + 3}{n^2 + 8} \to 2$ 
> 	- stesso grado quindi uso la prima regola
> - $\frac{2n^2 + 5n + 3}{n^5 + 8} \to 0$
> 	- $p < q$ uso la seconda regola
> - $\frac{2n^2 + 5n + 3}{3n^7} \to 0$
> 	- $p < q$ uso la seconda regola
> - $\frac{2n^2 + 5n + 3}{n + 8} \to +\infty$
> 	- $p > q$ e $a_0$ e $b_0$ hanno segno uguale quindi 3 regola
> - $\frac{2n^2 + 5n + 3}{8 - 3n} \to -\infty$
> 	- $p > q$ e $a_0$ e $b_0$ hanno segno diverso quindi 4 regola
> - $\frac{2n^2 + 8}{8 - n^2} \to -\infty$
> 	- $p > q$ e $a_0$ e $b_0$ hanno segno diverso quindi 4 regola
> - $\frac{2n^2 - 5n^3 + 3}{8 - n^2} \to +\infty$
> 	- $p > q$ e $a_0$ e $b_0$ hanno segno uguale quindi 3 regola
###### Successioni geometrica
ovvero ${a^n}$ con $a \in R$ ha il seguente comportamento al limite:
- $a>1 \Rightarrow a_n \rightarrow +\infty$
- $a = 1 \Rightarrow a^n \rightarrow 1$
- $0<a<1 \Rightarrow a^n \rightarrow0$ 
- $a = -1 \Rightarrow a^n$ è oscillante
- $a<-1 \Rightarrow a^n \to |\infty|$ ed è oscillante
###### Successioni composte mediante funzioni elementari
questo tipo di successioni si basano su questa
   **Proposizione 1**: Se $f: X \to R$ è una funzione se $a_n ⊆ X$, $a_n \to l$, $l \in X$ allora si ha $f(a_n) \to f(l)$ 
   **Esempio**: Se $a_n \to \pi$ si ha $\cos a_n \to \cos \pi$ 
   Di seguito alcuni casi di successioni composte mediante funzioni elementari:
	1. Sia $\{x_n\}$ una successione regolare e sia $\alpha$ un numero positivo e diverso da $1$ quindi studiamo la successione $\{a^{x_n}\}$, per la proposizione scritta prima se $x_n \to l$ allora si ha che $a^{x_n} \to a^l$. Se $\{x_n\}$ diverge dobbiamo distinguere se $a>1$ oppure $0<a<1$ e quindi si ha:
	  - $a>1,x_n \to +\infty \Rightarrow a^{x_n} \to +\infty$
		  - dimostrazione: $a^{x_n} > k$ equivale a $x_n>\log_ak$ che è **D** vera dato che $x_n \to +\infty$   
	  - $a>1,x_n \to -\infty \Rightarrow a^{x_n} \to +\infty$
		  - dimostrazione: $a^{x_n} = \frac{1}{a^{-x_n}}$ 
	  - $0<a<1,x_n \to +\infty \Rightarrow a^{x_n} \to 0$
		  - dimostrazione: basta osservare che $a = \frac{1}{\frac{1}{a}}$ e $\frac{1}{a}>1$ 
	  - $0<a<1,x_n \to -\infty \Rightarrow a^{x_n} \to +\infty$
		  - dimostrazione: basta osservare che $a = \frac{1}{\frac{1}{a}}$ e $\frac{1}{a}>1$ 
	2. Sia $\{x_n\}$ una successione regolare di numeri positivi e sia $a$ un numero positivo e diverso da $1$ quindi studiamo la successione $\{\log_a x_n\}$, per la proposizione scritta prima se $x_n \to l>0$ si ha allora che $\log_a x_n \to log_al$, però dobbiamo distinguere i vari casi:
	   - $a>1,x_n\to+\infty\Rightarrow \log_a x_n \to +\infty$ 
		   - dimostrazione: $\log_a x_n >k$ equivale a $x_n > a^k$ che è **D** vera dato che $x_n \to +\infty$ 
	   - $a>1,x_n\to0\Rightarrow \log_a x_n \to -\infty$
		   - dimostrazione: basta osservare che $\log_ax_n = \log_a \frac{1}{\frac{1}{x_n}} = -\log_a\frac{1}{x_n}$  
	   - $a<1,x_n\to+\infty\Rightarrow \log_a x_n \to -\infty$
		   - Basta osservare che $log_ax_n =(\log_a\frac{1}{a})(\log_{\frac{1}{a}}x_n) = -\log_{\frac{1}{a}} x_n$       
	   - $a<1,x_n\to+0\Rightarrow \log_a x_n \to +\infty$
		   - Basta osservare che $log_ax_n =(\log_a\frac{1}{a})(\log_{\frac{1}{a}}x_n) = -\log_{\frac{1}{a}} x_n$ 
	3. Successione del tipo $(a_n)^{b_n}$ essendo $a_n > 0$ per ogni $n$.  Questa successione si scrive nella forma $(a_n)^{b_n} = e^{\log((a_n)^{b_n})} = e^{b_n \log a_n}$ e in questa forma ci si può ricondurre ai casi $1$, $2$.  Si avranno forme indeterminate se il prodotto $b_n \log a_n$ si presenta nella forma $0 \cdot \infty$ .
### Il numero e


###  Cose da ricordare
- $\frac{1}{a_n} \rightarrow \infty$
- $\frac{1}{a_n} \rightarrow 0$