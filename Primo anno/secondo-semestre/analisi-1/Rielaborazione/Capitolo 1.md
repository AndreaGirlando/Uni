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
**Teorema**: Siano $a,b$ due numeri reali con $a<b$. Allora, esistono infiniti numeri razionali $r$ e infiniti numeri irrazionali $s$ tali che $a<r<b$, $a<s<b$. 
Da questo teorema segue che tra $a$ e $b$ esistono infiniti numeri reali.
**Spiegazione**: Se prendi due numeri reali a e b con a<b, tra di loro non c'è mai un "vuoto": ci sono sempre infiniti numeri che stanno tra a e b.  
Non solo: tra a e b ci sono infiniti razionali (numeri come $\frac{3}{4}$, $−5$, $7.1$ , ecc.) e infiniti irrazionali (numeri come $\sqrt{2}$)[[#^c777f8|Conseguenza]]
###### Nomenclature sugli intervalli
**Intervalli limitati**:
- $]a, b[= \{x ∈ R : a < x < b\}$ (Intervallo aperto)
- $[a, b] = \{x ∈ R : a ≤ x ≤ b\}$ (Intervallo chiuso)
**Intervalli non limitati:**
- $]a, +∞[= \{x ∈ R : x > a\}$ (Intervallo non limitato superiormente)
- $] − ∞, b[= \{x ∈ R : x < b\}$ (Intervallo non limitato inferiormente)
**Intervalli notevoli:**
- $] − ∞, +∞[ = R$
- $(a,b)$ intervallo generico  
###### Intorno di un numero
Un'intervallo del tipo $]c − r, c + r[$ (con $c \in R$ ed $r > 0$) viene detto **Intorno di c di raggio r** e si denota con $B(c, r), I_r(c)$
###### Proprietà di Archimede
Dati $a,b > 0$ esiste un $n \in N$ tale che $na > b$
###### Insiemi finiti, infiniti, numerabili
**Definizione**: Siano $A$  e $B$ due insiemi non vuoti, diremo che hanno la stessa potenza se esiste una corrispondenza biunivoca $f: A \rightarrow B$ 
**Definizione**: Sia $X$ un insieme non vuoto. Diremo che $X$ è **finito** ed ha $n$ elementi se esiste una corrispondenza biunivoca fra $X$ e l'insieme $\{1,2, \cdots ,n\}$. In caso contrario $X$ è detto **infinito**. La caratteristica di un insieme infinito $X$ e che esso ha la stessa potenza di un suo sottoinsieme proprio (pur avendo più elementi!). Ad esempio, consideriamo l’insieme $N$ dei numeri naturali e l’insieme $P$ dei numeri naturali pari. Associando ad ogni $n ∈ N$ il numero $2n ∈ P$ si ottiene una corrispondenza biunivoca.
**Definizione** Un insieme $X$ si dice **numerabile** se ha la stessa potenza di $N$. $Z$ e $Q$ sono entrambi numerabili. Per invece $R$ possiamo dire le seguenti cose:
- Tutti gli intervalli hanno la medesima potenza
	- Questo significa che, ad esempio, l'intervallo $(0,1)$, $(2,5)$ o anche $(−∞,∞)$ hanno tutti la stessa cardinalità. Anche se sembrano “lunghi” in modo diverso, da un punto di vista insiemistico, contengono lo stesso numero di elementi.
- La potenza degli intervalli è maggiore della potenza del numerabile
	- un intervallo reale come $(0,1)$ non è numerabile: non esiste un modo per elencare tutti i numeri reali in quell'intervallo.
- $R$ ha la stessa potenza degli intervalli
	- L’insieme dei numeri reali $R$, anche tutto intero (non solo un intervallo), ha la stessa cardinalità di qualsiasi intervallo reale.
###### Valore assoluto
Se $x \in R$ si chiama valore assoluto di $x$ il numero reale $|x|$ definito ponendo: 
- $|x| = x$ se $x \ge 0$
- $|x| = -x$ se $x<0$  
Di seguito le proprietà del valore assoluto:
1. $|x| \geq 0;\quad |x| = 0 \iff x = 0$
2. $|-x| = |x|$
3. $-|x| \leq x \leq |x|$
4. $|xy| = |x|\,|y|$
5. $a < x < b,\ a < y < b \Rightarrow |x - y| < b - a$
6. $-a < x < a \Leftrightarrow |x| < a \quad \text{(essendo } a > 0\text{)}$
7. $|a + b| \leq |a| + |b|$
8. $|a - b| \leq |a| + |b|$
9. $|x| < \varepsilon \quad \forall \varepsilon > 0 \Rightarrow x = 0$
###### Estremo inferiore ed estremo superiore
Sia $X$ un insieme numerico, ossia un sottoinsieme non vuoto di $R$. 
- **Minimo**: è un elemento $m \in X$ tale che $m \le x$  per ogni $x \in X$ (è unico)
- **Massimo**: è un elemento $m \in X$ tale che $m \ge x$ per ogni $x \in X$ (è unico)
- **Minorante**: un numero $h \in R$ è detto *minorante* di $X$ se $h \le x$ per ogni $x \in X$, denoteremo con $\underline{M}_x$ l'insieme dei minoranti di $X$. Osserviamo che:
	- se $h \in \underline{M}_x$ e $h' < h$ allora $h' \in \underline{M}_x$, quindi i minoranti di $X$ se esistono sono infiniti
	- $h \not \in \underline{M}_x$ se esiste un $x \in X: x<h$ 
	- $\underline{M}_x = ∅$ se per ogni $h\in R$ esiste $x \in X: x < h$ 
- **Maggioranti**: un numero $k \in R$ è detto *maggiorante* di $X$ se $k \ge x$ per ogni $x \in X$. Denoteremo con $\overline{M_x}$ l'insieme dei maggioranti di $X$. Osserviamo che:
	- se $k \in \overline{M_x}$ e $k' > k,$ allora $k' \in \overline{M_x}$, quindi i maggioranti di $X$, se esistono sono infiniti
	- $k \not\in \overline{M_x}$ se esiste $x \in X: x>k$ 
	- $\overline{M_x} = ∅$ se, per ogni $k \in R$ esiste un $x \in X: x>k$

> [!EXAMPLE]
> Dato l'insieme $A = \{1,2,3\}$:
> - l'insieme dei maggioranti di $A$ è $M = \{ x \in R | x \ge 3\}$ 
> - l'insieme dei minoranti di $A$ è $M = \{ x \in R | x \le 1 \}$

- **Limitato inferiormente**: $X$ è limitato inferiormente se $\underline{M_x} \not= ∅$   
- **Limitato superiormente**: $X$ è limitato superiormente se $\overline{M_x} \not= ∅$ 
- **Limitato**: è detto limitato se è sia limitato superiormente che inferiormente

In definitiva, un insieme è limitato se e solo se esiste un intervallo che lo contiene, detto ciò possiamo definire il seguente teorema:
**Teorema**:
1. Sia $X$ un insieme limitato inferiormente, allora possiamo dire che $\underline{M_x}$ è dotato di massimo
2. Sia $X$ un insieme limitato superiormente, allora possiamo dire che $\overline{M_x}$ è dotato di minimo
Quindi possiamo dire che:
- **Estremo inferiore**: che denotiamo con $inf X$ è uguale al $max \underline{M_x}$, se $X$ non è limitato inferiormente si pone $inf X = - \infty$. Dato un numero $l$ questo è l'estremo inferiore di $X$ se e solo se verifica queste proprietà:
	- $L \le x$ $∀x \in X$
	- $∀\epsilon \gt 0 ∃x \in X: x<l-\epsilon$
- **Estremo superiore**: che denotiamo con $supX$ è uguale al $min\underline{M_x}$, se $X$ non è limitato superiormente si pone $supX = +\infty$. Dato un numero $l$ questo è l'estremo superiore di $X$ se e solo se verifica queste proprietà:
	- $L \ge x$ $∀x \in X$
	- $∀\epsilon \gt 0 ∃x \in X: x>l-\epsilon$

###### Nozioni di topologia
Sia $X$ un insieme numerico, di seguito varie nozioni di topologia:
- **Punto interno**: $c \in X$ è detto punto interno se esiste un $r>0$ tale che $]c-r,c++r[$ $⊆ X$, indichiamo con $int(X)$ l'insieme dei punti interni.
	- Osserviamo che se $X$ è un intervallo $(a,b)$, i punti interni sono i tutti e soli punti dell'intervallo aperto $]a,b[$ 
- **Punto di frontiera**: un numero reale $c$ è detto *punto di frontiera* per $X$ se per ogni $r>0$ nell'intorno $]c-r,c++r[$ ci sono elementi di $X$ che elementi di $R \textbackslash X$ 
- **Punto di accumulazione**: un numero reale $c$ è detto punti di accumulazione per $X$ se, per ogni $r>0$ nell'intorno $]c-r,c++r[$ ci sono elementi diversi da $c$. L'insieme dei punti di accumulazione di accumulazione si denota con $D(X)$ 
- **Insieme aperto**: $X$ si dice *aperto* se è vuoto oppure quando $X = int(X)$ 
- **Insieme chiuso**: L’insieme $X$ è detto *chiuso* se il suo complementare $R \backslash X$ è aperto. Si definisce chiusura di $X$ l'insieme $\overline{X} = X ∪ D(X)$ ovvero un insieme si dice chiuso se e solo se contiene tutti i suoi punti di frontiera  
**Osservazioni:** 
- se un punto è interno allora è di accumulazione
- se un punto è di frontiera potrebbe non essere di accumulazione
	- se $X = [0, 1] ∪ \{5\}$, il punto$c = 5$ è di frontiera ma non di accumulazione.
- $X$ si dice denso in $R$ se $\overline{X} = R$. Dal teorema di densità di $Q$ in $R$ segue che tutti i numeri reali sono punti di accumulazione per $Q$ quindi $\overline{Q} = R$, lo stesso vale per $R \backslash Q$. Si ha dunque, se $(a, b)$ è un intervallo limitato, posto $X = (a, b)∩Q$ oppure $X = (a, b) ∩ (R \ Q)$, si ha $X = [a, b]$. ^c777f8
###### Potenze e radici
Se $a \in R$ e $n \in N_0$ si definiscono i seguenti assiomi:
- $a^0$ = 1
- $a^{n+1}$ = $a^{n} \times a$ 
- Se $a \in R \backslash \{0\}$ e $n \in N$ si definisce $a^{-n} = \frac{1}{a^n}$ 
Per definire la potenza nel caso in cui l'esponente sia razionale o irrazionale dobbiamo premettere il seguente teorema

**Teorema della radice n-ma aritmetica**: Siano $a$ un numero reale positivo ed $n$ un numero naturale maggiore o uguale a 2. Allora esiste uno ed uno solo numero positivo $b$ tale che $b^n = a$, il numero $b$ è detto radice n-ma aritmetica di $a$ e si indica con $\sqrt[n]{a}$

grazie a questo teorema se $a>0$ e $n \in N$ si definisce:
- $a^{\frac{1}{n}}$ = $\sqrt[n]{a}$
- $a^{\frac{m}{n}} = (\sqrt[n]{a})^m$ 
Tutte le potenze definite fino ad adesso sono tutte **positive** infatti. Inoltre ricordiamo che:
- se $a>1$ sia ha $a^b>1$ se e solo se $b>0$
- se $0<a<1$ si ha $a^b > 1$ se e solo se $b<0$
Per poter estendere la definizione di radice (data sopra) dobbiamo discutere l'equazione binomia, come fatto di seguito:
**Discussione equazione binomia**
Siano $a \in R$ e $n \in N$ con $n \ge 2$ vogliamo trovare tutti i numeri reali $x$ tali che $x^n=a$, l'equazione $x^n = a$ è detta equazione binomia. Di seguito tutte le soluzioni al variare di $a$
1. $a = 0$ l'unica soluzione è $x=0$ 
2. $a>0$ ci sono 2 soluzioni:
	- $±\sqrt[n]{a}$ per $n$ pari
	- $\sqrt[n]{a}$ per $n$ dispari
3. $a<0$:
	- Non ci sono soluzioni per $n$ pari
	- $-\sqrt[n]{-a}$  per $n$ dispari
Grazie a quanto appena visto possiamo dire che per ogni $n \in N$ e $\sqrt[n]{x} = -\sqrt[n]{-x}$ per $x<0$ ed $n$ dispari 

###### Logaritmi
Siano $a,b$ due numeri positivi con $a \not= 1$. Si può dimostrare che l'equazione $a^x = b$ ha una e una sola soluzione detta logaritmo di $b$ in base $a$ e indicata con $\log_{a} b$ , da questo capiamo che il logaritmo verifica la seguente uguaglianza:
$$a^{\log_{a} b} = b$$
Di seguito un po' di proprietà dei logaritmi:
$\log_{a} a = 1$
$\log_{a} b = 0 \iff b = 1$
$\log_{a} bc = \log_{a} b + \log_{a} c$
$\log_{a} b^x = x \log_{a} b$
$\log_{a} \frac{b}{c} = \log_{a} b - \log_{a} c$
$\log_{a} b = (\log_{a} c) (\log_{c} b)$
Dalla prima e dall'ultima delle precedenti eguaglianze, si ottiene
$1 = \log_{a} a = (\log_{a} b) (\log_{b} a) \implies \log_{b} a = \frac{1}{\log_{a} b}$
Osserviamo inoltre che $\log_{a} b > 0$ se e solo se $a$ e $b$ sono entrambi maggiori di 1 o minori di 1.


---
### Cenni sui numeri complessi
###### Definizione
**Definizione**: Definiamo numero complesso una coppia ordinata di numeri reali: $z = (a,b)$ con $a,b\in R$. Indichiamo con $C$ l'insieme dei numeri complessi.
**Equivalenza:** se $z = (a,b)$ e $w = (c,d)$ sono due numeri complessi, diremo che $z = w$ se $a=c$ e $b = d$ se $z \not = w$  

---
Dalla definizione appare chiaro che si possa stabile una corrispondenza biunivoca fra $C$ e il piano cartesiano, facendo corrispondere ad $z = (a,b)$ il punto del piano avente coordinate $(a,b)$. 
###### Notazione:
Dato $z = (a,b) \in C$:
- se $b = 0$: $z$ è detto **numero complesso reale**
- se $b \not = 0$ è detto **numero complesso immaginario** 
- se $a=0$ e $b\not=0$ **numero immaginario puro**
**Convenzioni**:
- $0=(0,0)$ zero complesso
- $1=(1,0)$ unità reale
- $i = (0,1)$ unità immaginaria
- $-z = (-a,-b)$ opposto di $z$ 
- $\overline{z} = (a,-b)$ coniugato di $z$ 
- $|z| = \sqrt{a^2+b^2}$ modulo di $z$

> [!TIP]
> Presa un'unita reale $x = (x,0)$ il suo modulo è: $|x| = \sqrt{x^2+0^2} = x$  

###### Introduciamo le operazioni
- $(a,b)+ (c,d) = (a+b,c+d)$ somma
- $(a,b)*(c,d) = (ac-bd,ad+bc)$ prodotto
**Osservazioni**
- $z+(-z) = 0$ 
- $z * 1 = z$
- $z*\overline{z} = |z|^2$ 
- $i^2 = (0,1)*(0,-1) = (0-1,0+0) = (-1,0) = -1$ (un numero alla seconda che da risultato negativo)
È possibile indentificare ogni numero reale $a$ come il numero complesso reale $(a,0)$ si può dunque considerare $R$ come un sottoinsieme di $C$ (per questo possiamo affermare che $i^2=-1$ anche se siamo nel campo complesso)
![[Venn_Diagram_of_Numbers-it.svg.png|350]]
###### Forma algebrica e forma trigonometrica

**Forma algebrica:** Sia $z = (a,b)\in C$ alla luce delle definizione viste prima possiamo osservare che:$$z = (a,0)+(0,1)+(b,0) \rightarrow z = a+ib$$ dopo la freccia troviamo la forma algebrica di $z$, molto utile perché possiamo considerare $z$ come un polinomio in specifico come somma di una "parte reale" ($a$) e di una "parte immaginaria" ($ib$)
> [!EXAMPLE] Esempio
> ![[Screenshot_20250502_094916_Samsung capture.jpg]]
> ottenendo un quoziente dei due numeri, in forma algebrica.

**Forma trigonometrica**
Ricordiamo la costruzione del piano cartesiano:
![[im_03.png|250]]
![[Screenshot_20250502_101617_Samsung capture.jpg|250]]
Sia ora $z = a+ib$ un numero complesso non nullo, e sia $P = (a,b)$ il punto del piano che lo rappresenta. Indichiamo con $\alpha$ la misura in radianti del più piccolo angolo di cui deve ruotare il semiasse delle ascisse(x) positive per sovrapporsi in direzione e verso alla semiretta $OP$ orientata da $O$ verso $P$. Se $A$ è la proiezione di $P$ sull'asse delle ascisse, il triangolo $OPA$ è un triangolo rettangolo quindi si ha:
- $a = OA = |z| \cos \alpha$   
- $b = AP = |z| \sin \alpha$ 
Detto ciò possiamo scrivere il numero $z$ nella seguente forma:
$z = |z|(\cos \alpha + i \sin \alpha)$ 

> [!EXAMPLE] Da forma algebrica a trigonometrica
> 1. $i = 0+1i$ forma algebrica
> 2. $\alpha = 90° = \frac{π}{2}$ perché $i$ nel piano cartesiano si trova nell'asse y coord = (0,1)
> 3. $|i| = \sqrt{0^2+1^2} = 1$ calcolo modulo di $i$
> 4. $i = |i|(\cos \alpha + i\sin \alpha)$ 
> 5. $i = 1(\cos \frac{π}{2}+i\sin \frac{π}{2})$ forma trigonometrica

**Prodotto in forma trigonometrica**: il prodotto di due numeri in forma trigonometrica dopo varie deduzioni utilizzando la formula di addizione del coseno e seno si deduce facilmente la seguente formula detta **formula di Moivre** che fornisce la la potenza intera di un numero complesso:
$$z^n = |z|^n ( \cos(nα) + i \sin(nα))$$

> [!EXAMPLE]
> $i^2=1[cos(2π​)+isin(2π​)]^2=1^2(\cos(2*\frac{π}{2}) + i \sin(2*\frac{π}{2}))=cos(π)+isin(π)=−1$

###### Radici
Siano $z$ un numero complesso e $n$ un intero maggiore o uguale a 2. Un numero complesso $w$ tale che $w^n = z$ è detto radice *ennesima* di $z$. Di seguito ci proponiamo di trovare tutte le radici ennesime di $z$:
- $z = 0$: per la legge dell'annullamento del prodotto l'unica radice è $w = 0$. 
- $z \not = 0$:  in tal caso le eventuali radici saranno evidentemente non nulle. Sia $w$ una di esse
Scriviamo $z$ e $w$ in forma trigonometrica
- $z = |z| (\cos \alpha  + i\sin\alpha)$ 
- $w = |w| (\cos \alpha  + i\sin\alpha)$ 
Usando la formula di Moivre scriviamo l'uguaglianza $w^n = z$ in questo modo:
$$|w|^n (\cos \alpha  + i\sin\alpha) = |z| (\cos \alpha  + i\sin\alpha)$$
Da questo concludiamo le seguenti cose:
- $|w|^n = |z| \rightarrow |w| = \sqrt{n}{|z|}$
- esiste un $k \in Z: n\beta = \alpha+2k\pi \rightarrow \beta = \frac{\alpha + 2k\pi}{n}$ 
Quindi la radice $w$ sarà del tipo:
	$$w_k = \sqrt[n]{|z|} \left( \cos\left(\frac{\alpha + 2k\pi}{n}\right) + i \sin\left(\frac{\alpha + 2k\pi}{n}\right) \right) (*)$$
Al variare di $k$ nell'insieme $\{0,\dots,n-1\}$ otteniamo tutte le $n$ radici distinte di $z$ 

> [!EXAMPLE]
> Le radici quarte di $i$ sono: $\cos\frac{\frac{\pi }{2\:}\:+\:2k\pi }{4}+i\sin\frac{\frac{\pi }{2\:}\:+\:2k\pi }{4}$ per $k = 0,1,2,3,...$ ovvero le seguenti scritte in forma esponenziale:
> - $\cos\left(\frac{\pi}{8}\right) + i\sin\left(\frac{\pi}{8}\right)$
> - $\cos\left(\frac{5\pi}{8}\right) + i\sin\left(\frac{5\pi}{8}\right)$
> - $\cos\left(\frac{9\pi}{8}\right) + i\sin\left(\frac{9\pi}{8}\right)$
> - $\cos\left(\frac{13\pi}{8}\right) + i\sin\left(\frac{13\pi}{8}\right)$
> 
> Non scriviamo $\sqrt[n]{|z|}$ perché lavorando con $i$ il modulo è sempre 1

Se consideriamo il caso specifico delle radice quadrate avremo le due radici distinte scritte di seguito:
- $w_o = \sqrt{|z|}(\cos \frac{\alpha}{2} + i\sin \frac{\alpha}{2}))$
- $w_1 = \sqrt{|z|}(\cos (\frac{\alpha}{2}+\pi) + i\sin (\frac{\alpha}{2}+\pi)))$
allora possiamo dire che $w_1 = -w_0$ (grazie alle [[#Formule della trigonometria|formule]] 3 e 4). In particolare possiamo osservare che se $z \in R$:
- se $z>0$, $\alpha = 0$ e $|z| = z$ allora si ottengono le due radici $±\sqrt{z}$ 
- se $z < 0$, $\alpha = \pi$ e $|z| = -z$ si ottengono le due radici $±i\sqrt{-z}$ 

> [!example]
> ![[Pasted image 20250503103733.png]]
> ![[Pasted image 20250503104126.png]]
> by ChatGpt

Questa cosa ha delle implicazioni, ad esempio nella formula del $\Delta$ per la risoluzione delle equazioni di secondo grado, infatti in caso di $\Delta$ negativo la formula risolutiva diventa:
$$\frac{-b±\sqrt{\Delta}}{2a} \rightarrow \frac{-b±i\sqrt{-\Delta}}{2a}$$

> [!EXAMPLE] 
>Ad esempio, le soluzioni dell'equazione (a coefficienti reali, con discriminante negativo) $z^2 - 2z + 2 = 0$ sono $z = 1 \pm \sqrt{-1} = 1 \pm i$

---
### Funzioni reali di una variabile reale
###### Generalità
Sia $f$ una funzione reale definita in un sottoinsieme $X$ di $R$, ovvero $f:X\rightarrow R$. Si chiama grafico di $f$ il seguente sottoinsieme di $R^2$: 
$$gr(f) = \{(x,f(x)):x\in X\}$$
###### Definizioni:
- **Funzione pari**: $f$ si dice pari se e solo se il suo grafico è un insieme simmetrico rispetto all'asse delle ordinate(y) cioè se contiene il punto $(a,b)$ allora contiene anche il punto $(-a,b)$
- **Funzione dispari**: $f$ è una funzione dispari se e solo se il suo grafico è un insieme simmetrico rispetto all'origine cioè se contiene il punto $(a,b)$ allora contiene il punto $(-a,-b)$
- **Funzione periodica**: $f$ si dice periodica se esiste un numero positivo $T$ (detto periodo) tale che $\forall x \in R$ si ha $f(x+T) = f(x)$ inoltre $f$ è periodica se e solo se $f(x+hT) = f(x) \forall x\in R, h\in Z$
- **Immagine di f**: denotata con $f(X)$ l'immagine di $f$ è l'insieme dei valori che la funzione $f$ può assumere.
	- alcuni concetto insiemistici legati ad $f(X)$ vengono per definizione attribuiti ad $f$. 
		1. Diremo che $f$ è limitata se lo è l'insieme numerico $f(X)$. 
		2. Gli estremi inferiore e superiore e gli eventuali minimo e massimo di $f(X)$ verranno chiamati estremi inferiore e superiore, minimo e massimo di $f$. L'estremo inferiore si indica con $inf_X f$ 
		3. Se $f$ ha il minimo esso viene chiamato minimo assoluto di $f$ in $X$, sia esso $m = min_X$. Dato che $m$ è un valore della funzione allora esiste un punto $c$ tale che $f(c) = m$ e viene chiamato punto di minimo assoluto. In modo analogo si introducono il massimo assoluto e il punto di massimo assoluto. 
- **Oscillazione di f**: chiamiamo oscillazione di $f$ la quantità $sup\{|f(x)-f(y)| x,y \in X\}$ 

> [!Tip]
> Di seguito supporremo normalmente che l'insieme di definizione di $X$ di $f$ sia un intervallo $(a,b)$

###### Funzione composta
Siano date due funzioni:
- $f: (\alpha,\beta) \rightarrow R$ 
- $g: (a,b) \rightarrow (\alpha,\beta)$ 
allora per ogni $x \in (a,b)$ è possibile porre $F(x) = f(g(x))$. La funzione $F:(a,b)\rightarrow R$  definita in questo modo viene detta **funzione composta da f (funzione esterna) e g(funzione interna)**. 
###### Estremi relativi:
- Un punto $c\in(a,b)$ è detto punto di minimo relativo per $f$ se esiste un suo intorno $I = ]c-r,c+r[$ tal che $f(x) \ge f(c)$ per ogni $x\in I$ 
- Un punto $c\in(a,b)$ è detto punto di massimo relativo per $f$ se esiste un suo intorno $I = ]c-r,c+r[$ tal che $f(x) \le f(c)$ per ogni $x\in I$ 
Un punto di estremo assoluto e anche di estremo relativo, ma non il viceversa.
###### Monotonia

^2bb6d6

Sia data una funzione $f: (a,b) \rightarrow R$ si dice che questa è monotona se soddisfa una delle seguenti condizioni:
- **crescente**: se $x < y \Rightarrow f(x) \le f(y)$
- **strettamente crescente**: se $x < y \Rightarrow f(x) < f(y)$
- **decrescente**: se $x<y \Rightarrow f(x) \ge f(y)$
- **strettamente decrescente**: se $x<y \Rightarrow f(x) > f(y)$
Possiamo introdurre anche il concetto di monotonia locale, ovvero dato una punto $c \in (a,b)$ si dice che la funzione è crescente nel punto $c$ se esiste $s>0$ tale che:
- se $x \in ]c-s,c[$ si ha $f(x)<f(c)$
- se $x \in ]c,c+s[$ si ha $f(x)>f(c)$ 
in modo simmetrico si introduce il concetto di funzione decrescente. 
###### Rapporto incrementale
^a17adb

Sia $f: (a,b) \rightarrow R$ e sia $c\in(a,b)$. Per ogni $x \in (a,b) \backslash \{c\}$ poniamo:
$$r(x) = \frac{f(x)-f(c)}{x-c} \text{ oppure } R(h) = \frac{f(c+h)-f(c)}{h}$$
![[Pasted image 20250601130158.png]]
$r(x) \text{ oppure } R(h)$ viene chiamato rapporto incrementale di $f$ relativo al punto $c$, questo è utile per verificare la monotonia locale di $f$ grazie al seguente teorema:
**Teorema**
La funzione $f$ è crescente (o decrescente) nel punto $c$ se e solo se esiste un intorno $I_s(c)$ tale che, per ogni $x \in I_s(c)\backslash\{c\}$ si abbia $r(x)>0$ (o $r(x)<0$)
**Dimostrazione** 
Supponiamo che $r(x) > 0$ in $I_s(c) \ {c}$. In $]c − s, c[$ il denominatore di r e negativo, quindi lo e anche il numeratore: dunque, $f (x) < f (c)$. In $]c, c + s[$ il denominatore di $r$ e positivo, quindi lo e anche il numeratore: dunque, $f (x) > f (c)$. Ne segue che $f$ e crescente nel punto $c$. Il viceversa si prova allo stesso modo.
###### Funzione convessa
La funzione $f: (a,b) \rightarrow R$ è detta convessa se per ogni $x,y \in(a,b)$ e per ogni $t \in [0,1]$ si ha:
$$f(tx+(1-t)y) \le tf(x)+(1-t)f(y)$$in italiano significa che la porzione di grafico compresa tra le ascisse $x$ e $y$ è al di sotto di un segmento che congiunge questi due punti: $(x,f(x))$ e $(y,f(y))$. La nozione di convessità la possiamo esprimere anche così:
$$epi(f) = \{ (x,y) \in R^2 x(a,b), y \ge f(x) \}$$
 ovvero la porzione di grafico che sta al di sopra del grafico
![[Epigraph_convex.svg.png|500]]

Si prova che la funzione f è convessa se e solo se $epi(f )$ e un sottoinsieme convesso di $R^2$, cioè, se contiene due punti, contiene anche il segmento che li congiunge.


> [!TIP]
> Prendi due punti qualsiasi sul grafico della funzione, ad esempio $A = (x_1, f(x_1)$ e $B = (x_2, f(x_2)$. Ora disegna il segmento rettilineo che li collega. Se la funzione è convessa, allora tutti i punti su quel segmento si trovano al di sopra (o esattamente sul) grafico della funzione tra $x_1​$ e $x_2​$.

###### Funzioni elementari
Di seguito alcune funzioni che nascono dalle operazioni definite in $R$ dette funzioni elementari, la funzione inversa di una funzione elementare è anche essa elementare.
- **Funzione constante**: Se $k \in R$ la funzione $f(x) = k$ è definita in $]-\infty, +\infty[$  
- **Funzione identità**: funzione $f(x) = x$ è definita in $]-\infty,\infty[$
- **Funzione potenza con esponente intero positivo**: Se $n\in N$ la funzione $f(x) = x^n$ è definita in $]-\infty,\infty[$ 
- **Funzione potenza con esponente intero negativo**: Se $n\in N$ la funzione $f(x) = x^{-n}$ è definita in $]-\infty,\infty[$ 
- **Funzione con esponente razionale**: se $\frac{m}{n} \in Q$, la funzione $f(x) = x^\frac{m}{n} = (\sqrt[n]{x})^m$ ed è definita in:
	- in $[0,+\infty[$ se $\frac{m}{n}>0$
	- in $]0,+\infty[$ se $\frac{m}{n}<0$
- **Funzione con esponente irrazionale**: se $s \in R\backslash Q$, la funzione $f(x) = x^s$ è definita in: 
	- in $[0,+\infty[$ se $s\ge0$
	- in $]0,+\infty[$ se $s<0$
- **Radice n-ma**: Se $n\in N, n\ge2$  la funzione $f(x) = \sqrt[n]{x}$ è definita in 
	- $]-\infty,+\infty[$  se $n$ è dispari
	- $[0, +\infty[$ se $n$ è pari
- **Funzione esponenziale**: Se $a>0, a\not=1$ la funzione $f(x) = a^x$ è definita in $]-\infty,\infty[$
- **Funzione logaritmica**: Se $a>0, a\not=1$ la funzione $f(x) = log_a x$ è definita in $]0, +\infty[$
- **Funzione Coseno e seno**: Per ogni $x \in R$ si consideri il punto $P$, l'ascissa e l'ordinata di P sono dette rispettivamente $\cos x$ e $\sin x$, le funzioni $f(x) = \cos x$  e $g(x) = \cos x$ sono definite in $]-\infty,\infty[$ ![[Pasted image 20250509170053.png|250]]
- **Funzione tangente**: la funzione $\tan x = \frac{\sin x}{\cos x}$ è definita in $]-\infty,\infty[\backslash \{\frac{\pi}{2}+k\pi: k \in Z\}$  
- **Funzione arcocoseno e arcoseno**: Per ogni $y \in [-1,1]$ sia $x$ l'unico punto dell'intervallo $[0,\pi]$ tale che $\cos x = y$, si definisce così la funzione $\arccos y$ inversa di $\cos x$ nell'intervallo $[0,\pi]$. In modo analogo si introduce la funzione $\arcsin y$ inversa di $\sin x$ nell'intervallo $[-\frac{\pi}{2},\frac{\pi}{2}]$
- **Funzione arcotangente**:  come visto per il punto precedente si costruisce per ogni $y \in ]-\infty,\infty[$ la funzione $\arctan y$ inversa di $\tan x$
- **Funzione polinomi**: Se $n \in N_0$ e $a_0,a_1,\dots,a_n \in R$ la funzione $p(x) = a_0x^n+a_1x^{n-1}+\dots+a_n$  definito in  $]-\infty,\infty[$ 
- **Funzioni razionali fratte**: la funzione $f(x) = \frac{a_0x^n+a_1x^{n-1}+\dots+a_n}{b_0x^m+b_1x^{m-1}+\dots+b_m}$ ($a_i,b_j \in R, n \in N_0, m \in N, b_0 \not = 0$) è definita in $]-\infty,\infty[\backslash\{c \in R: b_0c^m + \dots +c_m = 0\}$  
###### Osservazioni sulle funzioni elementari
Di seguito un po' di osservazioni sulle funzioni elementari:
- Se $n$ è pari la funzione $f(x)=x^n$ è pari ed è strettamente crescente in $[0,+\infty[$ e la sua inversa (ovvero $\sqrt[n]{x}$) è strettamente decrescente in $]-\infty,0]$. 
- Se $n$ è dispari la funzione $f(x) = x^n$ è dispari ed è strettamente crescente in $]-\infty,\infty[$ 
- Se $n = 0$ il polinomio si dice costante si ha cioè $p(x) = a_0$ per ogni valore di $x$. Due polinomi $p(x) = a_0x^n+a_1x^{n-1}+\dots+a_n$ e $P(x) = b_0x^m+b_1x^{m-1}+\dots+b_m$ si dicono identici se $p(x) = P(x)$ per ogni $x \in R$, inoltre si può dimostrare che $p$ e $P$ sono identici se e solo se:
	- $m = n$
	- $b_i = a_i$ per ogni $i = 0,\dots,n$ 
- Dati due polinomi $p$ e $P$ esiste un polinomio $q$ (quoziente) ed un polinomio $r$ (resto) tale che:
  $$p(x) = P(x)q(x)+r(x)$$
- L'equazione $p(x) = 0$ detta equazione algebrica ha esattamente $n$ soluzioni distinte, se $k$ d tali soluzioni coincidono, detto $\alpha$ il loro comune valore, si dice che $\alpha$ è una soluzione di molteplicità $k$ (questi zeri possono essere anche numeri immaginari)
- Supponiamo che il numeratore e il denominatore di $f$ siano polinomi primi fra loro (privi di divisori comuni). Si può dimostrare che $f$ può essere espressa come somma di frazioni del tipo $\frac{A}{(x-a)^n}$ ($A,a \in R, n \in N$) e di frazioni del tipo $\frac{A_x+B}{(x^2+k^2)^n}$ $(A,B,k \in R, n \in N)$ dette fratti semplici. Per trovare i fratti semplici è necessario trovare gli zeri del polinomio al denominatore.
  


--- 


### Cose da ricordare

###### Formule della trigonometria

| Id  | Formula                                       | Nome / Spiegazione                     |
| --- | --------------------------------------------- | -------------------------------------- |
| 1   | $\sin(-\theta) = -\sin\theta$                 | Seno è una funzione dispari            |
| 2   | $\cos(-\theta) = \cos\theta$                  | Coseno è una funzione pari             |
| 3   | $\sin(\theta + \pi) = -\sin\theta$            | Traslazione di mezzo giro              |
| 4   | $\cos(\theta + \pi) = -\cos\theta$            | Come sopra                             |
| 5   | $\sin(a + b) = \sin a \cos b + \cos a \sin b$ | Formula della somma per il seno        |
| 6   | $\cos(a + b) = \cos a \cos b - \sin a \sin b$ | Formula della somma per il coseno      |
| 7   | $\sin(a - b) = \sin a \cos b - \cos a \sin b$ | Formula della differenza per il seno   |
| 8   | $\cos(a - b) = \cos a \cos b + \sin a \sin b$ | Formula della differenza per il coseno |

