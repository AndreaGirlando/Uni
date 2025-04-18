Questo è la rielaborazione del file [[AppuntiCap1.pdf]]

# Numeri reali e complessi e generalità sulle funzioni reali di una variabile reale

### L'insieme dei numeri reali
###### Simbologia insiemi numerici e operazioni in N
Di seguito i simboli che denotano i vari insiemi numerici:
- $N =$ insieme dei numeri naturali (Es: 1,2,3,4,5...)
- $N_0 = N∪\{0\}$   (Es: 0,1,2,3,4,5...)
- $Z =$ insieme dei numeri interi relativi (-2,-1,0,+1,+2)
- $Q$ = insieme dei numeri razionali (Es. tutti i numeri che posso essere scritti come frazione)
Ricordiamo il percorso che porta da $N$ a $Q$, i numeri naturali sono concetti primitivi perché legati ad una capacità della nostra mente ovvero quella di "associare", un altro concetto primitivo è il concetto di **"successivo di un numero"**  che in questa fase indicheremo con $n'$. Nei numeri naturali vale il **concetto di induzione** (se una proprietà è vera per $n = 1$, si suppone che sia vera per $n$, e si dimostra vera per $n+1$ allora è vera per tutti gli $n$). Partendo dal principio di induzione si possono definire varie operazioni (somma, prodotto e derivati) in $N$ di seguito elencate:
$a,n ∈ N_0$ 
1. $a+0=a$
2. $a + n' = (a+n)'$
3. $a · 0 = 0$
4. $a · n' = a · n + a$
5. $a^0 = 1$
6. $a^{n'} = a^n · n$ 
7. $a + 1 = a + 0' = (a + 0)' = a'$
8. $a < b$ se esiste $n \in N$ tale che $a+n = b$

> [!TIP] proprietà delle potenze
> $a^n \cdot a^m = a^{n+m}$
> $(a^n)^m = a^{nm}$
> $(a \cdot b)^n = a^n \cdot b^n$

Inoltre abbiamo delle operazioni inverse (sottrazione e divisione) nate per risolvere dei problemi:
- **Sottrazione:** trovare $n$ tale che $b+n=a$ 
- **Divisione**: trovare $n$ tale che $a = bn$ 
Essi tuttavia non sono sempre risolubili, infatti il primo lo è solo se $a>b$ e il secondo solo se $a$ è multiplo di $b$, questi problemi hanno portato all'introduzione degli insiemi numerici successivi. 

###### Insiemi numerici successivi ad N
**l'insieme dei numeri relativi definito così:**
> [!TIP] definizione di Z (insieme numeri relativi)
> $Z = \{0\} ∪ \{+n : n ∈ N\} ∪ \{−n : n ∈ N\}$ 

Introducendo le operazioni e l'ordine nella maniera ben nota è subito evidente che il problema della sottrazione in $Z$ è sempre risolto. Associando ad ogni $n \in N$ il numero $+n \in Z$ si ottiene una corrispondenza biunivoca fra $N$ e l'insieme dei numeri interi positivi, quindi possiamo considerare $N$ un sottoinsieme di $Z$. 

**l'insieme dei numeri razionali definito così:**
> [!TIP] definizione di Q (insieme dei numeri razionali)
> $Q = \{ (m,n) |m \in Z, n \in N\}$
> questi numeri li rappresentiamo sempre nella forma: $\pm \frac{m}{n}$.

Introducendo le operazioni e l'ordine nella maniera ben nota è subito evidente che anche il problema della divisione in $Q$ è sempre risolto. Associando ad ogni $z \in Z$ il numero $\frac{z}{1} \in Q$ si ottiene una corrispondenza biunivoca fra $Z$ e l'insieme dei numeri razionali con denominatore 1, quindi possiamo considerare $Z$ un sottoinsieme di $Q$. Questo insieme lascia tuttavia irrisolto il problema dell'estrazione della radice ovvero: 

> [!EXAMPLE] Esempio
> $\sqrt{2} = ?$ questa operazione non ha nessuno soluzione in $Q$ 

è necessario quindi introdurre un insieme di numeri più ampio ovvero la rappresentazione decimale dei numeri razionali, infatti ogni numero razionale $r =  \pm \frac{m}{n}$ ammette una rappresentazione del tipo $a = \pm a_0, a_1 a_2 \dots$ costituita da un segno, un numero intero $a_0$ e una successione di cifre decimali che sono o un numero finito o periodici. **A questo punto possiamo introdurre l'insieme dei numeri reali definito così:**
$\mathbb{R} = \{0\} \cup \{\pm a_0, a_1 a_2 \cdots : a_0 \in \mathbb{N}_0; a_i \in \{0, \cdots, 9\} \forall i \in \mathbb{N}\}$
i suoi elementi sono detti **numeri reali**: 
- **Numeri reali razionali**: se hanno una successione periodica di cifre decimali
- **Numeri reali irrazionali**: se non hanno una successione periodica di cifre decimali
###### Introduciamo ordine e operazioni in R
- **Introduciamo un ordine in R**:
	Per farlo si procede così:
	1. Ogni numero negativo è minore di 0, e ogni numero positivo e maggiore di zero
	2. dati due numeri positivi $a = \pm a_0, a_1 \dots$ e $a = \pm b_0, b_1 \dots$ diremo maggiore quello in cui la prima cifra diversa è maggiore
	3. dati $a,b < 0$ diremo che $a<b$ se $-a>-b$ 
- **Introduciamo la somma in R**
	Per farlo si procede così:
	1. $a+0 = a$ per ogni $a \in R$ 
	2. se $a,b > 0$ per ogni $n \in N$ si considera il numero $s_n = \pm a_0, a_1 \cdots a_n$ + $\pm b_0, b_1 \cdots b_n$ è possibile vedere che da un certo valore di $n$ in poi i 2 numeri hanno la stessa parte intera, la stessa prima cifra. ($n$ è il numero di cifre dopo la virgola)![[Pasted image 20250417172551.png]]la parte intera si stabilizza per $n = 0$, la prima cifra decimale per $n = 1$, la seconda cifra decimale per $n = 2$, ecc... 
	3. se uno dei due numeri è negativo si procede come nel caso dei numeri razionali. Esempio: $-\pi + \sqrt{2} = -(\pi - \sqrt{2})$.
- **Rappresentazione dei numeri reali** 
  L'insieme dei numeri reali viene rappresentato su una retta dove si costruisce una corrispondenza biunivoca fra $R$ e l'insieme di punti di una retta, associando ad ogni $x ∈ R$ il punto della retta avente ascissa $x$.
###### Densità di Q e di R\Q in R
