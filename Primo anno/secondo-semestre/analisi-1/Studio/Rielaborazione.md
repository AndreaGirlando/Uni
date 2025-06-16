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



#### Capitolo 2


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

Se $l = 0$ la successione è detta infinitesima o semplicemente **un infinitesimo**

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
Generalizzando possiamo dire che: ^4215e5
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

^2ac9a5

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

^78c31d

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
###### Definizione
Consideriamo una successione del tipo: $a_n = (1+\frac{1}{n})^n$  si può dimostrate che è strettamente crescente per un numero $a_n<3$ $\forall n$ quindi converge ad un numero $<3$ chiamato $e$ che di solito viene definito cosi:
$$e = lim(1+\frac{1}{n})^n$$
Da questo possiamo dedurre i seguenti limiti:
1. Se $x_n \to \infty$ allora si ha: $$(1+\frac{1}{x_n})^{x_n} \to e$$
2.  Siano $a$ un numero positivo diverso da $1$ e $x_n \to 0$ allora si ha: $$\frac{\log_a(1+x_n)}{x_n} \to \log_ae$$
3. sia $\alpha \in R$ si ha $$\frac{(1+x_n)^n-1}{x_n} \to \alpha$$
4. sia $a_n \to 0$ allora la successione $\{\frac{\sin a_n}{a_n}\}$ allora definitivamente si ha che $|a_n|<\frac{\pi}{2}$

###### Altri limiti notevoli
In caso di funzioni trigonometriche abbiamo i seguenti limiti notevoli:
- $\frac{\sin a_n}{a_n} \to 1$ 
- $\frac{\tan a_n}{a_n} \to 1$ 
- $\frac{\arcsin a_n}{a_n} \to 1$ 
- $\frac{\arctan a_n}{a_n} \to 1$ 
- $\frac{1-\cos a_n}{(a_n)^2} \to \frac{1}{2}$ 
### Successioni estratte
###### Definizione
Date le successioni $\{a_n\}$ e $\{n_k\}$ (quest'ultima strettamente crescente). La funzione composta $\{a_{n_k}\}$ è detta **successione estratta** da $\{a_n\}$ mediate la legge $\{n_k\}$

> [!EXAMPLE]
> se $n_k = 2k$ si ottiene la successione dei termini di posto pari
> se $n_k = 2k-1$ si ottiene la successione dei termini di posto dispari

###### Teorema
**Teorema di regolarità delle successioni estratte**: Se $\{a_n\}$ è regolare, ogni sua estratta ha il suo stesso limite, il viceversa non vale.
> [!example]
> $a_n = (-1)^n$  la successione dei termini di posto pari è costante e quindi convergente 
> da questo esempio possiamo capire anche che il viceversa non vale perché $a_n$ oscilla 


> [!TIP]
> Se una successione ha due estratte aventi limiti diversi essa oscilla

Si hanno tuttavia i seguenti risultati:
1. se $\{a_{r+k}\}$ è regolare anche $\{a_n\}$ ha il suo stesso limite
2. se $\{a_{2k}\}$ e $\{a_{2k-1}\}$ hanno lo stesso limite, anche $\{a_n\}$ ha il loro stesso limite 

> [!EXAMPLE]
> sia $\{X_n\}$ una successione regolare di numeri tutti positivi e poniamo $a_x = (-1)^nX_n$, se $x_n \to 0$, si ha anche $a_n \to 0$. Se $x_n \to l > 0$
> - per n pari si ha $a_n = x_n \to l$ 
> - per n dispari si ha $a_n = -x_n \to -l$ 
> 
> avendo 2 estratte con limiti diversi possiamo dire che non è regolare e quindi oscilla 
 
### Confronto tra infiniti e infinitesimi

^2e5731
###### Infiniti
Siano $\{a_b\}$ e $\{b_n\}$ due successioni infinitamente grandi detti **infiniti**:
- Sono dello stesso ordine se il loro rapporto tende ad un limite diverso da zero
- Si dice che $\{a_n\}$ è di ordine superiore rispetto a $\{b_n\}$ se il loro rapporto diverge

> [!EXAMPLE]
> $a_n = n^n$
> $b_n = n!$ 
> Intuitivamente $a_n$ è di ordine superiore perché cresce più velocemente

###### Infinitesimi
Siano $\{a_b\}$ e $\{b_n\}$ due **infinitesimi**:
- Sono dello stesso ordine se il loro rapporto tende ad un limite diverso da zero
- Si dice che $\{a_n\}$ è di ordine superiore rispetto a $\{b_n\}$ se il loro rapporto tende a zero


> [!EXAMPLE]
> Dati $a_n​=\frac{1}{n},b_n​=\frac{2}{n}​$ il loro rapporto $\frac{a_n}{b_n} = \frac{\frac{1}{n}}{\frac{2}{n}} = \frac{1}{2}$ tende ad $\frac{1}{2}$ e quindi sono dello stesso ordine
> 
> Dati $a_n​=\frac{1}{n^2},b_n​=\frac{1}{n}​$ il loro rapporto $\frac{a_n}{b_n} = \frac{\frac{1}{n^2}}{\frac{1}{n}} = \frac{1}{n} \rightarrow 0$  e quindi $a_n$ è di ordine superiore
### Successione definite per ricorrenza
Una successione si dice definita per ricorrenza se viene dato il suo primo termine e viene fornita una legge che calcola ciascun termine in funzione del precedente cioè una funzione del tipo $a_{n+1} = f(a_n)$

> [!EXAMPLE] 
> $\begin{cases} a_1 = 4 \\ a_{n+1} = \sqrt{a_n}\end{cases}$
> $a_n = \{4,2,1.4,1.18, \cdots\}$

Quando si studia una successione di questo tipo si procede cosi:
- Studiare la monotonia
- Individuo quel numero $l$ che potrebbe essere l'estremo inferiore/superiore
- dal punto precedente segue che $l = \lim a_n$ (grazie a quanto detto sulle successioni estratte sappiamo che anche $l = \lim a_{n+1}$ )
- Per l'unicità del limite si deve avere $f(l) = l$ 
- Si risolve l'equazione $f(x) = x$ e si cerca tra le eventuali soluzione un numero $l$ che possa essere l'estremo inferiore/superiore della successione. Se non esiste la successione diverge

###  Cose da ricordare
- $\frac{1}{a_n} \rightarrow \infty$
- $\frac{1}{a_n} \rightarrow 0$

| **Categoria**     | **Proprietà/Formule**    | **Espressione**                                |
| ----------------- | ------------------------ | ---------------------------------------------- |
| **Logaritmi**     | Prodotto                 | $\\log_b(xy) = \\log_b(x) + \\log_b(y)$        |
|                   | Quoziente                | $\\log_b(x/y) = \\log_b(x) - \\log_b(y)$       |
|                   | Potenza                  | $\\log_b(x^n) = n \\cdot \\log_b(x)$           |
|                   | Radice                   | $\\log_b(\\sqrt{x}) = \\frac{1}{2} \\log_b(x)$ |
|                   | Cambio di base           | $\\log_b(x) = \\frac{\\log_k(x)}{\\log_k(b)}$  |
| **Potenze**       | Prodotto stessa base     | $a^m \\cdot a^n = a^{m+n}$                     |
|                   | Quoziente stessa base    | $\\frac{a^m}{a^n} = a^{m-n}$                   |
|                   | Potenza di potenza       | $(a^m)^n = a^{mn}$                             |
|                   | Potenza di prodotto      | $(ab)^n = a^n \\cdot b^n$                      |
|                   | Radice come potenza      | $\\sqrt[n]{a} = a^{1/n}$                       |
|                   | Radice di potenza        | $\\sqrt[n]{a^m} = a^{m/n}$                     |
| **Trigonometria** | Identità fondamentale    | $\\sin^2x + \\cos^2x = 1$                      |
|                   | Tangente e secante       | $1 + \\tan^2x = \\sec^2x$                      |
|                   | Cotangente e cosecante   | $1 + \\cot^2x = \\csc^2x$                      |
|                   | Doppio angolo (sin)      | $\\sin(2x) = 2\\sin(x)\\cos(x)$                |
|                   | Doppio angolo (cos)      | $\\cos(2x) = \\cos^2x − \\sin^2x$              |
|                   | Doppio angolo (cos) alt. | $\\cos(2x) = 2\\cos^2x − 1$                    |
|                   | Doppio angolo (cos) alt. | $\\cos(2x) = 1 − 2\\sin^2x$                    |
|                   | Doppio angolo (tan)      | $\\tan(2x) = \\frac{2\\tan(x)}{1 − \\tan^2x}$  |
|                   | Mezza angolo (sin²)      | $\\sin^2x = \\frac{1 − \\cos(2x)}{2}$          |
|                   | Mezza angolo (cos²)      | $\\cos^2x = \\frac{1 + \\cos(2x)}{2}$          |



#### Capitolo 3


Questo è la rielaborazione del file [[AppuntiCap3.pdf]]

# Limiti e continuità delle funzioni reali di una variabile reale

Per una funzione reale si possono dare 9 definizioni di limite, precisamente studiare il limite di una funzione significa vedere qual è il comportamento della funzione stessa quando la variabile si avvicina ("tende") ad un certo punto. Le nove definizioni si differenziano l'una dall'altra solo per il diverso significato di "definitivamente".
### Definizioni di limite
###### Limite al tendere di x a c

> [!quote]
> **Punto di accumulazione**: un numero reale $c$ è detto punti di accumulazione per $X$ se, per ogni $r>0$ nell'intorno $]c-r,c++r[$ ci sono elementi diversi da $c$. L'insieme dei punti di accumulazione di accumulazione si denota con $D(X)$ 

^818a5c

Data una funzione reale definita in un insieme $X ⊆ R$, se $c \in D(x)$ si definisce il limite di $f$ al tendere di $x$ a $c$ nel seguente modo:
1. Si dice che $f$ **converge** al numero $l$ al tendere di $x$ a $c$ e si scrive: $$\lim_{x\to c}f(x) = l \in R$$ se $\forall \epsilon > 0$ $\exists δ > 0: x \in X, x \not=c,|x-c|<δ \Rightarrow |f(x)-l| < \epsilon$ ovvero $l-\epsilon < f(x) < l+\epsilon$  
   **Spiegazione intuitiva**: Dire che il limite di $f(x)$ per $x$ che tende a $c$ è uguale ad $l$ significa che possiamo rendere $f(x)$ arbitrariamente vicino a $l$, scegliendo $x$ sufficientemente vicino a $c$ (ma senza che $x$ debba essere uguale a $c$). In altre parole, per ogni livello di precisione $\epsilon$ che vogliamo raggiungere, esiste un intervallo attorno a $c$ (di ampiezza $\delta$) tale che, se $x$ si trova all’interno di questo intervallo (escluso il punto $c$), allora $f(x)$ sarà compreso nell’intervallo $(l - \epsilon, l + \epsilon)$.
   
2. Si dice che $f$ **diverge** a $+\infty$ al tendere di $x$ a $c$ e si scrive $$lim_{x\to c} f(x) = +\infty$$ se $\forall k>0 \text{ } \exists δ>0 \text{ } x\in X, x\not=c, |x-c|<δ \Rightarrow f(x)>k$ 
   **Spiegazione intuitiva**: Dire che $f(x)$ tende a infinito quando $x$ si avvicina a $c$ significa che il valore di $f(x)$ può diventare arbitrariamente grande, cioè maggiore di qualunque soglia positiva. Per ogni $k > 0$, esiste un $\delta$ tale che, se $x \ne c$ e $|x - c| < \delta$, allora $f(x) > k$.

3. Si dice che $f$ **diverge** a $-\infty$ al tendere di $x$ a $c$ e si scrive $$lim_{x\to c} f(x) = -\infty$$ se $\forall k>0 \text{ } \exists δ>0 \text{ }: x\in X, x\not=c, |x-c|<δ \Rightarrow f(x)<-k$ 
   **Spiegazione intuitiva**: Quando $x$ si avvicina a $c$, il valore di $f(x)$ diventa arbitrariamente negativo, cioè più piccolo di qualunque soglia negativa (cioè inferiore a $-k$). Per ogni $k > 0$, esiste un $\delta$ tale che, se $x \ne c$ e $|x - c| < \delta$, allora $f(x) < -k$.
   
Come notiamo da queste definizione la condizione di limite deve essere verificata in un opportuno intorno di $c$, se questa cosa accade possiamo dire che la definizione di limite è verificata **definitivamente**. Se una delle tre condizioni descritte sopra è verificata allora la funzione è detta **regolare al tendere di x a c**, per questo tipo di limite abbiamo i seguenti teoremi:
- **Teorema dell'unicità del limite**: Se una funzione è regolare al tendere di $x$ a $c$ il suo limite è unico
- **Teorema della permanenza del segno**:
	- Se $\lim_{x\to c} f(x) = l>0$ esiste un intorno di $c$ in cui si ha $f(x)>0$  
	- Se $\lim_{x\to c} = l < 0$ esiste un intorno di $c$ in cui si ha $f(x)<0$	  
	generalizzando questo risultato, possiamo concludere che se $k>l(k<l)$ i valori della funzione saranno definitivamente minori (risp. maggiori) di $k$
- **Teorema di confronto per funzioni convergenti**: siano $f,g,h$ tre funzioni definite nello stesso insieme $X$ e sia $c \in D(x)$. Supponiamo che $f(x)\le g(x) \le h(x)$ per ogni $x \in X$ e che al tendere di $x$ a $c$ le due funzioni $f$ ed $h$ abbiano lo stesso limite $l$. Allora anche $g$ tende ad $l$ 
- **Teorema di confronto per funzioni divergenti**: siano $f,g$ due funzioni definite nello stesso insieme $X$ e sia $c \in D(x)$, supponiamo che $f(x)\le g(x)$ per ogni $x \in X$, allora:
	- se $\lim_{x \to c} f(x) = +\infty$ allora $\lim_{x \to c}g(x) = +\infty$ 
	- se $\lim_{x \to c} f(x) = +\infty$ allora $\lim_{x \to c}f(x) = -\infty$
- **Teorema sul limite di una funzione composta**: Siano date due funzioni $f: Y \to R, g: X \to Y$. Sia $c \in D(x)$ e si supponga che $\lim_{x\to c}g(x) = γ$ e che $γ \in D(y)$. Allora, se $\lim_{y\to γ}f(y) = l$ si ha posto $F(x) = f(g(x))$ che $\lim_{x\to c}F(x)=l$  
	- **Osservazione**: Dal teorema 5 segue che, per una funzione composta, occorre prima esaminare il limite della funzione interna (ovvero $γ$) e il limite di $F$ sarà quello a cui tende la funzione esterna quando la "sua" variabile tende a $γ$
- **Teorema ponte**: sia data una funzione $f: X \to R$ e sia $c \in D(x)$. Si ha $\lim_{x\to c}f(x) = l$ (rispettivamente  $+\infty,-\infty$)   se e solo se per ogni successione $\{x_n\}$ di elementi di $X$ convergente a $c$ si ha $f(x_n)\to l$ 

###### Limite sinistro e destro
Sia data una funzione $f: (a,b) \to R$, possiamo dire che:
- Per ogni $c \in ]a,b]$ il limite della restrizione di $f$ ovvero $(a,c[$ al tendere di $x$ a $c$ e si chiama **limite sinistro di f** (e si denota con $\lim_{x\to c^-}$)
- Per ogni $c \in ]a,b[$ il limite della restrizione di $f$ ovvero $]c,b)$ al tendere di $x$ a $c$ e si chiama **limite destro di f** (e si denota con $\lim_{x\to c^+}$) 
Allora possiamo dire che se $c \in ]a,b[$ ed esiste il $\lim_{x\to c} f(x)$ allora il limite destro e sinistro coincidono, vale anche il viceversa ovvero che se $\lim_{x\to c^-}f(x) = \lim_{x\to c^+}f(x) = l$ allora $\lim_{x\to c}f(x) = l$  

###### Limite al tendere di x all'infinito
Data una funzione $f: (a,+\infty[ \to R$ si definisce il limite di $f$ al tendere di $x$ a $+\infty$ nel seguente modo:
- $lim_{x \to +\infty} f(x) = l \in R \text { se } \forall\epsilon>0$ $\exists \bar{x}>a: x>\bar{x} \Rightarrow |f(x)-l|< \epsilon$
- $\lim_{x\to+\infty}f(x) = +\infty$ se $\forall k>0 \exists \bar x > a: x > \bar x \Rightarrow f(x)>k$ 
- $\lim_{x\to+\infty}f(x) = +\infty$ se $\forall k>0 \exists \bar x > a: x > \bar x \Rightarrow f(x)>k$ 
In modo simile si definisce per una funzione $f: ]-\infty,a) \to R$ il limite di $f$ in tal caso la convergenza si definisce così:
- $lim_{x \to +\infty} f(x) = l \in R \text { se } \forall\epsilon>0$ $\exists \bar{x}>a: x<\bar{x} \Rightarrow |f(x)-l|< \epsilon$ 
Anche in questo caso valgono i teoremi dell'unicità del limite, di confronto, della permanenza del segno e il teorema ponte
> [!TIP]
> usando il teorema ponte si riescono a costruire tutte le operazioni come fatto nelle [[Capitolo 2#^2ac9a5|successioni]]

###### Limiti di funzioni elementari
Vale la seguente **proposizione**: 
Se $f: X \to R$ è una funzione elementare, per ogni $c \in X$ si ha $\lim_{x \to c}f(x) = f(c)$.
di seguito alcuni casi in cui non è vera questa condizione:
1. **Funzione esponenziale**: Sia $\alpha$ un numero positivo e diverso da 1, consideriamo la funzione $a^x$, per studiare il suo limite dobbiamo considerare 2 casi:
	- $a>1$
		- $\lim_{x\to+\infty} a^x = +\infty$ 
		- $\lim_{x\to-\infty} a^x = 0$
	- $0<a<1$
		- $lim_{x\to +\infty} a^x = 0$
		- $lim_{x\to -\infty} a^x = +\infty$
2. **Funzione logaritmo**: Sia $\alpha$ un numero positivo e diverso da 1. Consideriamo la funzione $\log_a x$ per studiare il suo limite dobbiamo considerare 2 casi:
	- $a>1$ 
		- $\lim_{x\to+\infty} \log_a x = +\infty$ 
		- $\lim_{x\to0} \log_a x = -\infty$ 
	- $0<a<1$
		- $\lim_{x\to+\infty} \log_a x = -\infty$
		- $\lim_{x\to0} \log_a x = +\infty$ 
3. **Funzione potenza**: per questo tipo di funzione dobbiamo distinguere 2 casi $(n\in R)$  
	- *Funzione con esponente intero positivo\negativo*
		- $\lim_{x\to+\infty} x^n = +\infty$
		- $\lim_{x\to-\infty} x^n = +\infty$ se $n$ è pari
		- $\lim_{x\to-\infty} x^n = -\infty$ se $n$ è dispari
		- $\lim_{x\to\pm\infty} x^{-n} = 0$ se $n$ è pari
		- $\lim_{x\to0} x^{-n} = +\infty$ se $n$ è pari
		- $\lim_{x\to0^-} x^{-n} = +\infty$ se $n$ è dispari
		- $\lim_{x\to0^+} x^{-n} = +\infty$ se $n$ è dispari
		- $\lim_{x\to\pm\infty} x^{-n} = 0$ se $n$ è dispari
	- *Funzione con esponente non intero ($\alpha$)*
		- $\alpha>0$
			- $\lim_{x\to+\infty} x^\alpha = \infty$   
		- $\alpha < 0$
			- $\lim_{x \to +\infty}x^{\alpha} = 0$ 
			- $\lim_{x\to 0}x^\alpha = +\infty$ 
4. **Funzione polinomio**: consideriamo il polinomio $f(x) = a_0x^n+a_1x^{n-1}+\cdots+a_n$. con $x\to\pm\infty$ per determinare il suo limite riscriviamo il polinomio in questo modo: $f(x) = x^n(a_0+\frac{a_1}{x}+\cdots+\frac{a_n}{x^n})$ come dicevamo per le [[Capitolo 2#^78c31d|successioni]] la quantità tra partentesi tende a $a_0$ quindi ne segue che:
	- $\lim_{x \to +\infty} f(x) = +\infty$ se $a_0 > 0$;
	- $\lim_{x \to +\infty} f(x) = -\infty$ se $a_0 < 0$;
	- $\lim_{x \to -\infty} f(x) = +\infty$ se $a_0 > 0$, $n$ pari;
	- $\lim_{x \to -\infty} f(x) = -\infty$ se $a_0 < 0$, $n$ pari;
	- $\lim_{x \to -\infty} f(x) = -\infty$ se $a_0 > 0$, $n$ dispari;
	- $\lim_{x \to -\infty} f(x) = +\infty$ se $a_0 < 0$, $n$ dispari.

> [!TIP]
> In generale possiamo dire che al tendere di $x \to \infty$ i polinomi divergono sempre, per capire il segno basta fare questa cosa:
> - Se $n$ è pari, il segno della divergenza è il segno di $a_0$
> - Se $n$ è dispari, il segno della divergenza è il segno opposto a $a_0$

> [!EXAMPLE]
> - $\lim_{x \to +\infty} \left( x^4 - 2x^3 + 1 \right) = +\infty$
> - $\lim_{x \to +\infty} \left( x^5 - 2x^4 + 1 \right) = +\infty$
> - $\lim_{x \to +\infty} \left( x^4 - 2x^6 + 1 \right) = -\infty$
> - $\lim_{x \to +\infty} \left( x^2 - 2x^3 + 1 \right) = -\infty$
> - $\lim_{x \to -\infty} \left( x^4 - 2x^3 + 1 \right) = +\infty$
> - $\lim_{x \to -\infty} \left( x^5 - 2x^4 + 1 \right) = -\infty$
> - $\lim_{x \to -\infty} \left( x^4 - 2x^6 + 1 \right) = +\infty$
> - $\lim_{x \to -\infty} \left( x^4 - 2x^7 + 1 \right) = -\infty$

5. **Funzioni razionali fratte**: Consideriamo la funzione $f(x)$ definita così: $$f(x) = \frac{a_0x^n+a_1x^{n-1}+\cdots+a_n}{b_0x^m+b_1x^{m-1}+\cdots+b_m}$$ per poter analizzare il limite di questa funzione dobbiamo distinguere vari casi:
	- *se n>m*  al tendere di $x \to\pm\infty$ la funzione diverge e per capire il segno dobbiamo esaminare il segno del numeratore e denominatore
	- *se n = m* $\lim_{x\to+\infty}f(x) = \lim_{x\to+\infty}f(x) = \frac{a_0}{b_0}$    
	- se *n<m* $\lim_{x\to+\infty}f(x) = \lim_{x\to+\infty}f(x) = 0$ 

> [!EXAMPLE]
> - $\lim_{x\to+\infty}\frac{(2x-2)^3}{4-x^3} = -8$   caso $n = m$
> - $\lim_{x\to-\infty}\frac{2-x}{x^3+5} = \infty$ caso $n>m$
> - $\lim_{x\to-\infty}\frac{x^5+2}{x-1} = 0$ caso $n<m$

### Alcuni limiti notevoli
###### Limiti notevoli con funzioni trigonometriche
Utilizzando i limiti notevoli studiati per le successioni si ottiene che:
- $\lim_{x\to0}\frac{\sin x}{x} = 1$
- $\lim_{x\to0}\frac{\tan x}{x} = 1$ 
- $\lim_{x\to0}\frac{\arcsin x}{x} = 1$
- $\lim_{x\to0}\frac{\arctan x}{x} = 1$ 
- $\lim_{x\to0}\frac{1- \cos x}{x} = \frac{1}{2}$
- $\lim_{x\to0}\frac{\cos x - 1}{x} = 0$ 
###### Limiti notevoli di tipo esponenziale
- $\lim_{x \to \pm\infty} \left( 1 + \frac{1}{x} \right)^x = e$
- $\lim_{x \to 0} \left( 1 + x \right)^{\frac{1}{x}} = e$
- $\lim_{x \to 0} \frac{\log(1 + x)}{x} = 1$
- $\lim_{x \to 0} \frac{e^x - 1}{x} = 1$
- $\lim_{x \to 0} \frac{(1 + x)^{a} - 1}{x} = a \quad (a \in \mathbb{R})$
### Confronto fra infinitesimi e fra infiniti
- Una funzione che tende a zero è detta infinitesima (o "infinitesimo")
- Una funzione che diverge è detta infinitamente grande (o "un infinito")
il confronto è uguale a quello per le [[Capitolo 2#^2e5731|successioni]]

### Asintoti
###### Definizione
Un asintoto per $f$ è una **retta** $r$ tale che la distanza del generico punto del grafico di $f$ da $r$ tenda a zero. 
> [!TIP]
> La distanza che c'è tra la funzione e l'asintoto diventa sempre più piccola quando ci allontaniamo dall'origine (ovvero quando $x\to\pm\infty$), allora possiamo dire che la nostra distanza tende a $0$ (ovviamente questa cosa vale per ogni tipo di asintoto).
> 
> Inoltre una tra $x$ o $y$ deve tendere a $\pm\infty$ per avere un asintoto 

###### Diversi tipi di asintoto
Abbiamo diversi tipi di asintoto:
- **Asintoto verticale**: Se la funzione $f$ diverge al tendere di $x$ a $c$ allora la retta di equazione $x = c$ è detta asintoto verticale per $f$. 
  Infatti dato $P(x,f(x))$ un generico punto del grafico si ha: $$d(P,r) = |x-c|$$visto che $x\to c$ allora questa distanza tende a $0$. Inoltre visto che $x\to c$ allora deve essere vero che $y$ tende ad un'infinito ovvero che (almeno una):
	- $\lim_{x\to c^{+}} = \pm \infty$  asintoto verticale sinistro
	- $\lim_{x\to c^{-}} = \pm \infty$ asintoto verticale destro
![[Pasted image 20250531110936.png]]

> [!EXAMPLE]
> ![[Screenshot_20250531_111957_Samsung capture.jpg]]

- **Asintoto orizzontale**: Sia data una funzione $f: (a,+\infty[ \to R$ e si supponga che $\lim_{x\to+\infty} f(x) = l \in R$   allora la retta $r$  di equazione $y = l$ è detta asintoto orizzontale destro per $f$. 
  Infatti dato $P(x,f(x))$ un generico punto del grafico di $f$ si ha: $$d(P,r) = |f(x)-l|$$per il limite scritto prima $f(x)$ tende ad $l$ quando $x\to+\infty$, quindi la distanza tra la diminuisce e tende a $0$ ![[Pasted image 20250531110852.png]]Se abbiamo che $\lim_{x\to+\infty} f(x) = l$ e $\lim_{x\to-\infty} f(x) = h$ allora abbiamo 2 asintoti orizzontali: 
	- $y = l$ asintoto orizzontale destro
	- $y = h$ asintoto orizzontale sinistro

> [!EXAMPLE]
> ![[Screenshot_20250531_103631_Samsung capture.jpg]]

- **Asintoto obliquo**: Sia data una funzione $f: (a,+\infty[ \to R$ e si supponga che $\lim_{x\to+\infty}f(x)=\infty$ se $f$ ha un asintoto obliquo allora i due infiniti $f$ e $x$ devono avere lo stesso ordine di grandezza, in altre parole il rapporto $\frac{f(x)}{x}$ deve ammettere un limite finito (ovvero $m$) al tendere di $x$ a $+\infty$. 
  ![[Pasted image 20250531122500.png]]
  dunque se: 
  - $\lim_{x\to+\infty}\frac{f(x)}{x} = m \not= 0$
  - se $\lim_{x\to+\infty}f(x)-mx = p \in R$ 
  allora la retta $r$ di equazione $y = mx+p$ è asintoto obliquo destro per $f$ (in modo simmetrico si introduce quello sinistro). Infatti detto $P(x,f(x))$ il generico punto del grafico di $f$, si ha $d(P,r) = \frac{|mx-f(x)+p|}{\sqrt{1+m^2}}$ che tende a zero al tendere di $x$ a $+\infty$  
> [!EXAMPLE]
> ![[Screenshot_20250531_124822_Samsung capture.jpg]]

### Limiti delle funzioni monotone

> [!CITE] 
> Ricordiamo dal capitolo 1 che una funzione $f$ è detta [[Capitolo 1#^2bb6d6|monotona]] in un intervallo $(a,b)$ se in tale intervallo è crescente o decrescente (anche strettamente) 
###### Teorema
Sia $f: (a,b)\to R$ una funzione strettamente crescente in $(a,b)$ allora possiamo dire che:
- per ogni $c \in ]a,b[$ esistono i limiti destro e sinistro di $f$ al tendere di $x$ a $c$ e si ha che $$l^- = \lim_{x\to c^-} f(x) = \sup_{(a,c[} \text{ } f(x) \le f(c) \le l^+ = \lim_{x\to c^+} f(x) = \inf_{]c,b)}f(x)$$
- esistono i limiti di $f$ al tendere di $x$ ad $a$ e a $b$ e si ha:
	- $l^+ = \lim_{x\to a}f(x)  = \inf_{]a,b)}f(x)$
	- $l^- = \lim_{x\to b}f(x)  = \inf_{(a,b[}f(x)$
**Osservazioni**
1. Se $a, b$ appartengono all'insieme di definizione si ha:
	- $l^+ \ge f(a)$
	- $l^- \le f(b)$
2. Se $f$ è decrescente, si ha $$l^{-} = \lim_{x \to c^{-}} f(x) = \inf_{(a,c[} f(x) \geq f(c) \geq l^{+} = \lim_{x \to c^{+}} f(x) = \sup_{]c,b)} f(x)$$
### Funzioni continue

^14df84

###### Definizione
Sia data una funzione $f: X \to R$ e sia $c$ un punto non isolato di $X$, si dice che $f$ è continua in $c$ se $\lim_{x\to c}f(x) = f(c)$. Si dice che $f$ è continua se è continua $\forall x \in X$   
**In altre parole La funzione f è continua in un punto c se, quando x si avvicina a c, i valori di f(x) si avvicinano a f(c)**
###### Teorema di Weierstrass
Sia $f$ una funzione reale continua in un intervallo chiuso e limitato $[a,b]$, allora $f$ ammette minimo e massimo assoluti
###### Proprietà dei valori intermedi (PVI)
Si dice che una funzione $f: X \to R$ gode della proprietà dei valori intermedi (brevemente PVI) se: dati $\alpha,\beta \in f(X) \text{ con } \alpha < \beta$ per ogni $\gamma \in ]\alpha,\beta[$ esiste $x \in X$ tale che $f(x) = \gamma$, in altre parole se la funzione assume due valori allora questa assume anche i valori fra essi compresi.
###### Teorema di esistenza degli zeri
**Teorema**: sia $f$ una funzione reale continua in un intervallo chiuso e limitato $[a,b]$ e si supponga $f(a)<0$ e $f(b)>0$ (o viceversa). Allora esiste $c \in [a,b]$ tale che $f(c) = 0$
**Teorema non in matematichese**: la continuità di $f$ implica che la funzione non può “saltare” da negativo a positivo senza passare per lo zero. Vogliamo trovare il punto dove $f$ si annulla.
**Dimostrazione**: 
posto $x_0 = \frac{a+b}{2}$ 
- se $f(x_0) = 0$ la tesi è dimostrata
- se $f(x_0)<0$ poniamo $[a_1,b_1] = [x_0,b]$ 
  se $f(x_0)>0$ poniamo $[a_1,b_1] = [a, x_0]$
  in entrambi i casi si ha che:
	- $f(a_1)<0$ 
	- $f(b_1)>0$
	- $a \le a_1 < b_1 \le b$ 
	- $b_1 - a_1 = \frac{b-a}{2}$ 
Procedo analogamente a partire dall'intervallo $[a_1,b_1]$ e reiterando lo stesso ragionamento, se per un certo $n$ si trova $f(x)=0$ la tesi è dimostrata, in caso contrario si determinano due successioni $\{a_n\}$ e $\{b_n\}$ tali che per ogni $n \in N$ si ha che 
- $f(a_n)<0$
- $f(b_n)>0$
- $a \le a_1 \le \cdots \le a_n < b_n \le b_{n-1} \le \cdots \le b$
- $b_n - a_n = \frac{b-a}{2^n}$ 
La successione $\{a_n\}$ è crescente e limitata superiormente (da b) quindi converge al proprio estremo superiore $c\le b$. 
inoltre possiamo dire che $$b_n = b_n -a_n+a_n = \frac{b-a}{2^n}+a_n\to c$$ 
Si ha allora per la continuità di $f$: $$f(a_n) \to f(c) \text{ e } f(b_n)\to f(c)$$Poiché:
- da $f(a_n)<0$ si ha $f(c)\le 0$
- da $f(b_n)>0$ segue $f(c)\ge0$ 
quindi segue necessariamente che $$f(c)=0$$
###### Teorema di esistenza dei valori intermedi (teorema di Darboux)
**Teorema**: Sia $f$ una funzione reale continua in un intervallo chiuso e limitato $[a,b]$ e si supponga che $f(a) \not = f(b)$ ad esempio $f(a)<f(b)$. Allora per ogni $\gamma \in ]f(a),f(b)[$ esiste $c \in [a,b]$ tale che $f(c) = \gamma$ 
 **Dimostrazione**: Consideriamo in $[a,b]$ la funzione $g(x) = f(x)-\gamma$ che è continua e agli estremi dell'intervallo assume valori di segno diverso, quindi per il teorema di esistenza degli zeri, si annulla in un punto $c$: si ha dunque  $f(c)-\gamma = 0$ e quindi che $f(c) = \gamma$ 
 **Osservazioni**:
 1. Se l'intervallo non è chiuso e limitato la tesi vale egualmente: basta applicare il teorema ad una restrizione (ad un sotto intervallo)
 2. Se $f$ non è definita in un intervallo il teorema non vale: basti pensare ad esempio ad una funzione definita nell'unione di due intervalli disgiunti, costante in ciascuno di essi, con valori diversi delle costanti
 3. Il viceversa del teorema non vale: la funzione definita in $[0,1]$ ponendo $f(x) = x$ in $]0,1[$ $f(0)=1,f(1) = 0$ verifica la PVI ma non è continua
 4. Il teorema di esistenza degli zeri è un caso particolare del teorema di Darboux 
###### Teorema di continuità delle funzioni monotone
**Teorema:** Sia $f: (a,b) \to R$ una funzione strettamente monotona e sia verificata la PVI allora $f$ è continua
**Dimostrazione**: Supponiamo che $f$ sia crescente e proviamo la continuità in un punto $c$ interno ad $(a,b)$. Dal teorema sui limiti delle funzioni monotone segue che $l^-\le f(x) \le l^+$ per provare la continuità basta provare che $l^- = f(x) = l^+$. Supponiamo per assurdo che non sia vero, ad esempio si abbia $l^- < f(c)$. Sia $\gamma \in ]l^-,f(c)[$ per la PVI esiste $\overline{x} \in (a,b)$ tale che $f(\overline{x}) = \gamma$. L'assurdo segue dal fatto che $\overline{x}$ non può esistere, infatti:
- se $\overline{x} = c$ si avrebbe $\gamma  = f(\overline{x}) = f(c)$ 
- se $\overline{x} < c$ si avrebbe $\gamma = f(\overline{x}) \le l^-$ 
- se $\overline{x} > c$ si avrebbe $\gamma = f(\overline{x}) > f(c)$
L'assurdo è dunque trovato. 
###### Conseguenze di questi teoremi
1. **Immagine di un intervallo mediante una funzione continua**: Sia $f:[a,b]\to R$ una funzione continua, dal teorema di Darboux segue che la sua immagine è un intervallo, e dal teorema di Weierstrass segue che $f$ possiede minimo $m$ e massimo $M$ quindi la sua immagine è l'intervallo chiuso e limitato $[m,M]$
	1. Se $f$ è crescente la sua immagine è l'intervallo $[f(a),f(b)]$ 
	2. Se $f$ è decrescente la sua immagine è l'intervallo $[f(b),f(a)]$
   In generale, se $f$ è una funzione continua in un intervallo generico $(a,b)$ la sua immagine è l'intervallo $(\inf_{(a,b)}f(x), sup_{(a,b)}f(x)$  
2. **Continuità della funzione inversa**: sia $f: [a,b] \to [f(a),f(b)]$ una funzione strettamente crescente e continua (può essere anche descrescente). Allora la sua inversa è continua.
3. **Continuità delle funzioni elementari**: tutte le funzioni elementari che abbiamo introdotto sono continue nei rispettivi insiemi di definizione. Sia infatti $c$ un punto dell'insieme di definizione di $f$. Se $c$ è contenuto in un intervallo in cui $f$ è monotona, la continuità in $c$ segue dal teorema di continuità delle funzioni monotone, in caso contrario il limite destro e sinistro coincidono

### Punti di discontinuità
Data una funzione $f: X \to R$, un punto $c \in D(x)$([[#^818a5c|insieme dei punti di accumulazione]]) è detto punto di discontinuità per $f$ in uno dei seguenti casi: 
- se $f$ non è definita in $c$ 
	- $f(x) = \log x, c = 0$ 
- se $f$ non è dotata di limite al tendere di $x$ a $c$ 
	- $f(x) = \frac{|x|}{x}, c = 0$
- se $\lim_{x\to c} f(x) \not = f(c)$ 
	- $f(x) = x$ per $x \not = 0, f(0) = 5, c = 0$   
Dato $c$ punto di discontinuità possiamo dire che:
- $c$ è **eliminabile** se $lim_{x \to c} f(x) = l$ esiste ed è finito. In tal caso, definendo $$g(x) = \begin{cases} f(x) & \text{se } x \neq c, \\ l & \text{se } x = c, \end{cases}$$otteniamo una funzione continua in $c$.
- $c$ è di **prima specie** se i limiti:
	- $l^- = lim_{x\to c^-}f(x)$
	- $l^+ = lim_{x\to c^+}f(x)$ 
  esistono entrambi finiti ma sono distinti in tal caso il numero $|l^--l^+|$ è detto **salto** di $f$ in corrispondenza di $c$
- $c$ è un **punto di infinito** se $f$ diverge al tendere di $x$ a $c$, se $c$ è un punto di infinito per $f$ allora c'è un asintoto verticale di equazione $x = c$ 

#### Capitolo 4


Questo è la rielaborazione del file [[AppuntiCap4.pdf]]
# Calcolo differenziale per le funzioni reali di una variabile reale
### Derivabilità

###### Rapporto incrementale
^47484b
Dati una funzione $f: (a,b) \to R$ e un punto $c \in (a,b)$ abbiamo definito il [[Capitolo 1#^a17adb|rapporto incrementale]] di $f$ relativo al punto $c$ in queste 2 forme:
- $r(x) = \frac{f(x)-f(c)}{x-c}$ definito in $(a,b)\backslash\{c\}$
- $R(h) = \frac{f(c+h)-f(c)}{h}$ definito in $(a-c, b-c)\backslash\{0\}$  

e abbiamo visto che la funzione $f$ è crescente\decrescente nel punto $c$ se e solo se $r(x)>\backslash<0$ in un intorno di $c$. Ricordiamo che $r$ ed $R$ si ottengono per composizione l'uno dell'altro, e quindi: 
- Per il [[Capitolo 3#^14df84|teorema sui limiti delle funzioni composte]] è del tutto equivalente calcolare il limite di $r$ al tendere di $x$ a $c$ o il limite di $R$ al tendere di $h$ a $0$. 
- Se tale limite è positivo\negativo per il [[Capitolo 2#^4215e5|teorema della permanenza del segno]] la funzione risulterà crescente\decrescente nel punto $c$
###### Definizione
Si dice che $f$ è **derivabile** nel punto $c$ se il limite del rapporto incrementale ($\lim_{x\to c}r(x)$ oppure $\lim_{h\to 0}R(h)$) esiste ed è finito si dice che tale limite è detto derivata di $f$ in $c$ e si denota con $f'(c)$. Inoltre possiamo dire che: 
- $f$ è derivabile in $(a,b)$ se lo è in ogni punto, e in tal caso si definisce una funzione $f': (a,b) \to R$ che ad ogni punto $x \in (a,b)$ associa la derivata di $f$ in $x$ 
- se la funzione $f'$ è a sua volta derivabile in $c$, la sua derivata è detta derivata seconda di $f$ in $x$ e si denota con $f''$ se ciò accade in ogni punto di $(a,b)$ allora possiamo definire la funzione $f'':(a,b)\to R$, procedendo in modo iterativo si possono definire le derivate di ordine superiore

> [!tip]
> $f$ è derivabile in $c$ se:
> - $\lim_{x\to c}r(x)$ per valori di $x$ che si avvicinano a $c$ il rapporto incrementale esiste ed è finito
> - $\lim_{h\to 0}R(h)$ per valori di $h$ che si avvicinano a $0$ il rapporto incrementale esiste ed è finito

![[Screenshot_20250601_130105_Samsung capture.jpg]]
###### Derivata destra e sinistra
Se il punto $c$ è interno all'intervallo $(a,b)$ è possibile calcolare il limite sinistro e destro del rapporto incrementale, se esistono e sono finiti, essi vengono chiamati:
- $f'_-(c)$ derivata sinistra
- $f'_+(c)$ derivata destra
Ovviamente $f$ è derivabile in $c$ se e solo se $f'_-(c) = f'_+(c)$. Se l'intervallo è chiuso è possibile prendere in considerazione la derivata anche nei punti $a$ e $b$:
- la derivata nel punto $a$ è una derivata destra
- la derivata nel punto $b$ è una derivata sinistra
###### Teoremi
**Teorema**: Se $f$ è derivabile in $c$ allora è continua
**Dimostrazione**: Si ha $$f(x) = f(x)-f(c)+f(c) = \frac{f(x)-f(c)}{x-c}(x-c) + f(c)$$e questa quantità al tendere di $x$ a $c$ converge a $f'(c) \cdot 0 + f(c) = f(c)$. Il viceversa non vale, consideriamo i due seguenti esempi:
1. $f(x) = \sqrt{x}, c = 0.$ Il rapporto incrementale $f(x) = \frac{1}{\sqrt{x}}$ diverge al tendere di $x$ a $0$
2. $f(x) = |x|, c = 0$. Il rapporto incrementale $r(x) = \frac{|x|}{x}$ vale $1$ per $x>0$ e $-1$ per $x<0$ quindi tende ad $1$ al tendere di $x$ a $0$ da destra e a $-1$ al tendere di $x$ a $0$ da sinistra. 
Le funzioni presentate nei precedenti esempi sono continue nel punto $c=0$ ma non sono derivabili in tale punto. Il seguente risultato prova che una funzione è derivabile nel punto $c$ solo se è possibile approssimarla in un intorno di $c$, con un polinomio di primo grado.

**Teorema**: $f$ è derivabile in $c$ se e solo se esiste un polinomio di primo grado $p$ tale che $p(c) = f(c)$ e che $\lim_{x\to c}\frac{f(x)-p(x)}{x-c} = 0$  
**Osservazione**: la condizione $\lim_{x\to c}\frac{f(x)-p(x)}{x-c} = 0$ significa che la differenza $f(x)-p(x)$ è un infinitesimo di ordine superiore rispetto a $x-c$ quindi al tendere di $x$ a $c$ è trascurabile: dunque $f$si può approssimare con il polinomio $p$
**Dimostrazione**: Se $f$ è derivabile in $c$, basta porre:
$$p(x) = f(c)+f'(c)(x-c)$$si ha infatti $$\frac{f(x)-p(x)}{x-c} = \frac{f(x)-f(x)}{x-c}-f'(c) \to 0$$
Viceversa, se esiste il polinomio $p = f(c)+a(x-c)$ si ha $$\frac{f(x)-f(c)}{x-c} = \frac{f(x)-p(x)+p(x)-f(c)}{x-c} = \frac{f(x)-p(x)}{x-c}+a\to 0+a \text{ quindi esiste } f'(c) = a$$ 
###### Interpretazione geometrica
La derivata rappresenta il coefficiente angolare della retta tangente in un punto del grafico. La retta secante, che unisce due punti $(c, f(c))$ e $(c + h, f(c + h))$, ha coefficiente angolare dato dal rapporto incrementale $R(h)$. Se la funzione $f$ è derivabile in $c$, $\lim_{h \to 0} R(h) = f'(c)$. In questo caso, la retta secante tende alla tangente al grafico in $c$, con equazione $y = f(c) + f'(c)(x - c)$. La tangente rappresenta la posizione limite delle secanti e approssima il grafico localmente come un polinomio di primo grado. In situazioni particolari, come $f(x) = \sqrt{x}$ in $x = 0$, la tangente può essere verticale.

### Regole di derivazione
In questo paragrafo vengono presentate le regole per derivare funzioni ottenute mediante operazioni tra funzioni derivabili:
1. **Combinazione lineare**: Siano $f,g$ derivabili in un punto $c$ e $h,k \in R$. Indicata con $F$ la combinazione lineare $F(x) = hf(x)+kg(x)$ questa è derivabile nel punto $c$ e diventa: $F'(x) = hf'(c)+kg'(x)$. Il rapporto incrementale di $F$ è la combinazione lineare dei rapporti incrementali di $f$ e $g$ mediante le costanti $h$ e $k$ 
2. **Prodotto**: Siano $f,g$ derivabili in un punto $c$. Indicata con $p$ la funzione prodotto $p(x) = f(x)g(x)$, quest'ultima è derivabile nel punto $c$ e si ha $p'(c) = f(c)g'(c)+ f'(c)g(c)$ 
3. **Reciproco**: Sia $f$ derivabile in un punto $c$ e tale che $f(c) \not = 0$. Indichiamo con $F$ la funzione reciproca del tipo $F(x) = \frac{1}{f(x)}$, la funzione $F$ è derivabile nel punto $c$ e si ha $F'(c) = \frac{-f'(c)}{(f(c))^2}$ 
4. **Quoziente**: Siano $f,g$ derivabili in un punto $c$ e si abbia $g(c)\not = 0$. Indicata con $q$ la funzione quoziente del tipo $q(x) = \frac{f(x)}{g(x)}$, la funzione $q$ è derivabile nel punto $c$ e si ha $$q'(c) = \frac{f'(c)g(c)-f(c)g'(c)}{(g(c))^2}$$arriviamo a questa conclusione scrivendo $q$ nella forma $q(x) = f(x)\frac{1}{g(x)}$ e applicando le regole 2 e 3
5. **Funzione composta**: Siano date due funzioni
	- $f:(\alpha,\beta) \to R$ 
	- $g(a,b) \to (\alpha, \beta)$ 
   e supponiamo che $g$ sia derivabile nel punto $c$ e che $f$ sia derivabile nel punto $g(c)$ allora indichiamo con $F$ la funzione composta del tipo: $F(x) = f(g(x))$ questa è derivabile nel punto $c$ e diventa $F'(x) = f'(g(c))g'(c)$ 
6. **Funzione inversa**: Sia $f: [a,b] \to R$ una funzione strettamente crescente e continua, se essa è invertibile la sua inversa è $f^{-1}: [f(a),f(b)] \to [a,b]$, sia $\gamma \in [f(a),f(b)]$, dato $c\in[a,b]$ tale che $\gamma = f(c)$ allora si può dimostrare che $f^{-1}$ è derivabile in $\gamma$ e diventa $(f^{-1})(\gamma) = \frac{1}{f'(c)}$ 
### Derivate delle funzioni elementari
Di seguito le formule che permettono di derivare le funzioni elementari:
1. **Funzione costante**: Se $f(x) = k \text{ } \forall x \in R$ il suo rapporto incrementale è nullo quindi $$f(x) = k \text{ diventa } f'(x) = 0$$
2. **Funzione potenza con esponente intero**: $$f(x) = x^n \text{ diventa } f'(x) = nx^{n-1} \text{ (* n può essere negativo) }$$nel caso $n = 2$ il rapporto incrementale è: 
   ![[Screenshot_20250602_102709_Samsung capture.jpg|500]]
3. **Funzione con valore assoluto**: la funzione $f(x) = |x|$ non è derivabile nel punto $x = 0$ mentre:
	- se $x>0$ si ha $f'(x) = 1$
	- se $x < 0$ si ha $f'(x)=-1$ 
   la derivata di $f$ è la cosiddetta funzione segno, che può essere scritta mediante l'espressione $F'(c) = \frac{|x|}{x}$ $$f(x) = |x| \text{ diventa } f'(x) = \frac{|x|}{x}$$
4. **Funzione esponenziale**: Se $f(x) = a^x$ il rapporto incrementale è $r(x)=\frac{a^x-a^c}{x-c} = a^c\frac{a^{x-c}-1}{x-c}$ e si può provare che al tendere di $x$ a $c$ si ha il limite $a^c \log a$ e quindi si ha che:  $$f(x) = a^x \text{ diventa } f'(x) = a^x\log a$$inoltre se $a = e$ allora si ha che $$f(x) = e^x \text{ diventa } f'(x) = e^x$$
5. **Funzione logaritmo**: Per calcolare questa derivata useremo la regola per la derivata della funzione inversa. Preso $f(x) = e^x$ la cui inversa è $\log x$, se $\gamma > 0$, sia $c \in R$ tale che $e^c = \gamma$ ossia $c = \log \gamma$. Si ha $f'(c)=e^c \not = 0$ quindi $(f^{-1})'(\gamma) = \frac{1}{e^c} = \frac{1}{\gamma}$ quindi ne segue che: $$f(x) = \log x \text{ diventa } f'(x) = \frac{1}{x}$$o più in generale che: $$f(x) = \log_a x \text{ diventa } f'(x) = \frac{1}{x}\log_a e$$Inoltre grazie alla regola delle funzioni compose possiamo dire che: $$ F(x) = \log|f(x)| \text{ diventa } f'(x) = \frac{f'(x)}{f(x)}$$
6. **Funzione potenza con esponente qualunque**: Se $x>0$ consideriamo $f(x)=x^a = e^{log x^a} = e^{a \log x}$ da cui $f'(x) = e^{a \log x}a\frac{1}{x} = a\frac{x^a}{x} = ax^{a-1}$ quindi possiamo dire che $$f(x) = x^a \text{ diventa } f'(x) = ax^{a-1}$$  ![[Screenshot_20250602_114008_Samsung capture.jpg]]
7. **Funzioni trigonometriche**: usando la formula del rapporto incrementale si dimostra che
   $$f(x) = sin(x) \text{ diventa } f'(x) = cos(x)$$
   $$f(x) = cos(x) \text{ diventa } f'(x) = -sin(x)$$
   $$f(x) = tan(x) = \frac{\sin x}{\cos x} \text{ diventa } f'(x) = tan^2x+1 = \frac{1}{cos^2x}$$
![[Screenshot_20250602_110837_Samsung capture.jpg|500]]
8. **Funzioni inverse delle funzioni trigonometriche**: utilizzando le regole di derivazione delle funzioni inverse si può provare che: $$f(x) = \arcsin(x) \text{ diventa } f'(x) = \frac{1}{\sqrt{1-x^2}}$$$$f(x) = \arccos(x) \text{ diventa } f'(x) = \frac{1}{-\sqrt{1-x^2}}$$$$f(x) = \arctan(x) \text{ diventa } f'(x) = \frac{1}{1+x^2}$$
### Teoremi sul calcolo differenziale e loro applicazioni allo studio delle funzioni
Studiare una funzione significa individuare a partire dalla legge di definizione le sue principali proprietà analitiche:
- limitatezza
- continuità
- derivabilità
- monotonia
- convessità
- ecc...
Per individuare alcune di queste proprietà sarà molto utile lo studio delle derivate. 

###### Conseguenza della derivata
Ricordando il teorema sul rapporto incrementale scritto nel capitolo 1 che ci diceva che la funzione $f$ è crescente (o decrescente) nel punto $c$ se e solo se $r(x)>0$(o $r(x)<0$) in un intorno di $c$. Quindi usando le derivate possiamo affermare che se $f'(c)>0$ (o $f'(c)<0$) allora per il teorema della permanenza del segno si avrà $r(x)>0$(o $r(x)<0$) in un intorno di $c$. 

###### Teorema 1 (monotonia locale)
**Teorema**: Se $f'(c)>0$ $(\text{ oppure } f'(c)<0)$ allora $f$ è crescente (oppure decrescente) nel punto $c$, il viceversa non è vero. 
- Ad esempio $f(x) = x^3$ è crescente nel punto $c = 0$ ma $f'(0) = 0$.

###### Teorema di Fermat
**Teorema**: Data una funzione $f(a,b) \to R$ sia $c \in ]a,b[$ un punto di minimo o di massimo relativo per $f$. Si supponga che $f$ sia derivabile nel punto $c$ allora si ha $f(c)' = 0$ 
**Dimostrazione**: Dato che il $c$ è interno, la derivata è il limite del rapporto incrementale sia da sinistra che da destra. il numeratore del rapporto incrementale in un intorno di $c$ ha sempre lo stesso segno sia a destra che a sinistra, mentre il denominatore è negativo a sinistra di $c$ e positivo a destra, quindi possiamo dire che:
- $f'(c) = f'_-(c) = \lim_{x\to c^-}r(x)\le 0$ 
- $f'(c) = f'_+(c) = \lim_{x\to c^+}r(x)\ge 0$ 
quindi necessariamente $f'(c) = 0$. Il viceversa di questo teorema non vale infatti prendendo la funzione $f(x) = x^3$ si ha $f'(0) = 0$ ma il punto $c = 0$ non è un estremo relativo, infatti $f$ è crescente in ogni punto di $R$. Quindi il fatto che $f'(c) = 0$ è una condizione necessaria, ma non sufficiente, per l'esistenza di un estremo relativo. Infine possiamo dire che i punti $c$ tale $f'(c) = 0$sono detti punti stazionari o critici per $f$.

###### Teorema di Rolle
**Teorema**: Sia $f$ una funzione reale continua nell'intervallo chiuso $[a,b]$ e derivabile in $]a,b[$ tale che $f(a) = f(b)$. Allora esiste $c \in ]a,b[$ tale che $f'(c) = 0$ 
**Dimostrazione**: Per il teorema di Weierstrass $f$ è dotata di minimo e massimo assoluti:
- $x_1$ punto di minimo assoluto
- $x_2$ punto di massimo assoluto
Se $x_1 = a$ e $x_2 = b$ (o viceversa) allora il minimo e il massimo assoluti della funzione sono uguali quindi $f$ è costante e la sua derivata è ovunque nulla. In caso contrario uno dei due punti $x_1,x_2$ è interno, in esso allora la derivata è nulla per il teorema di Fermat

###### Teorema di Lagrange
**Teorema**: Sia $f$ una funzione reale continua nell'intervallo $[a,b]$ e derivabile $]a,b[$. Allora esiste $c \in ]a,b[$ tale che $f(b)-f(a) = f'(c)(b-a)$ 
**Dimostrazione**: Consideriamo in $[a,b]$ la funzione $$g(x) = (f(b)-f(a))x+(a-b)f(x)$$Si vede facilmente che essa verifica le ipotesi del teorema di Rolle, quindi esiste $c \in ]a,b[$ tale $g'(c) = 0$. Dal fatto che $g'(x) = f(b)-f(a)+(a-b)f'(x)$ segue subito la tesi.
	 
###### Corollari del teorema di Lagrange
1. **Teorema del prolungamento della derivata**: Sia data una funzione $f: (a,b)\to R$ e sia $c \in (a,b)$. Supponiamo che $f$ sia derivabile in $(a,b)\backslash\{c\}$ e che sia continua in $c$. Supponiamo inoltre che esista il $\lim_{x\to c}f'(x)$ e sia esso $l$ allora si ha $\lim_{x\to c}r(x) = l$ 
	- **Osservazione**: Dal teorema appena enunciato segue che le funzioni $\arcsin x$ e $\arccos x$ non sono derivabili in $-1$ e $1$, infatti sono continue ma le loro derivate divergono al tendere di $x$ a tali punti.
2. **Criterio di monotonia**: Sia data una funzione $f: (a,b) \to R$ derivabile, questa è un condizione sufficiente affinché $f$ sia crescente in $(a,b)$ è che $f'(x)\ge 0 \forall x \in (a,b)$ 
	- **Dimostrazione**: Siano $x,y \in (a,b)$ con $x<y$. Applicando il teorema di Lagrange ad $f$ nell'intervallo $[x,y]$ si ottiene che esiste $c \in ]x,y[$ tale che $f(y)-f(x) = (y-x)f'(c)\ge 0$ da cui la tesi.
3. **Criterio di stretta monotonia**: Sia data una funzione $f: (a,b) \to R$ derivabile. Condizione necessaria e sufficiente affinché $f$ sia strettamente crescente in $(a,b)$ è che:
	- $f'(x)\ge0 \text{  } \forall x \in (a,b)$ 
	- e che non esista nessun intervallo $(c,d) ⊆ (a,b)$ tale che $f'(x) = \forall x \in (c,d)$ 
4. **Teorema sulle funzioni con derivata nulla**: Sia data una funzione $f:(a,b) \to R$ derivabile, tale che $f'(x) = 0 \text{  } \forall x \in (a,b)$, allora $f$ è costante in $(a,b)$ 
	- **Dimostrazione**: Siano $x,y$ due punti generici di $(a,b)$ con $x<y$. Applicando il teorema di Lagrange ad $f$ nell'intervallo $[x,y]$ si ottiene l'esistenza di $c \in ]x,y[$ tale che $$f(y)-f(x) = f'(c)(y-x)$$ quindi $f(x) = f(y)$ e date che $x$ e $y$ sono arbitrari, ne segue la tesi.
	- **Osservazione**: è importante che $f$ sia definita in un intervallo, infatti se ad esempio prendiamo la funzione definita in $[0,1] ∪ [4,5]$ ponendo $f(x) = 2$ in $[0,1]$ e $f(x) = 6$ in $[4,5]$ ha derivata nulla in tutto il suo insieme di definizione ma non è costante.
### Metodo per lo studio dei punti stazionari
###### Metodo:
Sia $f$ una funzione derivabile in $(a,b)$ e sia $c\in (a,b)$ tale che $f'(c) = 0$. Dai risultati precedenti segue che $c$ può essere un punti di estremo relativo. Ricordando i criteri di monotonia segue che:
1. se $f'(x) < 0$ in un intorno sinistro di $c$ e $f'(x)>0$ in un intorno destro di $c$, allora $c$ è un punto di minimo relativo per $f$.
2. se $f'(x)>0$ in un intorno sinistro di $c$ e $f'(x)<0$ in un intorno destro di $c$, allora $c$ è un punto di massimo relativo per $f$.
In pratica un punto stazionario $c$ è un punto di estremo relativo per $f$ se in corrispondenza di $c$ la derivata cambia segno. Se esiste la derivata seconda in $c$, possiamo raffinare lo studio anche utilizzando il segno della derivata seconda, e precisamente si ha:
3. $f''(c)>0$, allora $c$ è un punto di minimo relativo per $f$
4. $f''(c)<0$, allora $c$ è un punto di massimo relativo per $f$ 
Infatti dato che $f''(c)$ è la derivata della funzione $f'$ nel punto $c$, se $f''(c)>0$  la funzione $f'$ è crescente nel punto $c$, in cui vale zero, quindi si avrà $f'(x)<0$ in un intorno sinistro di $c$ e $f'(x)>0$ in un intorno destro di $c$ e dal risultato "1." ne segue che $c$ è un punto di minimo relativo per $f$.   
###### In definitiva
se $f'(c) \not = 0$ la funzione $f$ è crescente o decrescente nel punto $c$ 
se $f'(c) = 0$ e $f''(c) \not = 0$, $c$ è un punto di estremo relativo per $f$

### Metodo per la ricerca degli estremi assoluti
###### Metodo:
Sia $f$ una funzione reale continua in $[a,b]$ il teorema di Weierstrass assicura l'esistenza degli estremi assoluti, per individuarli occorre determinare i seguenti insiemi:
- $A = \{c\in]a,b[:f'(c) = 0\}$
- $B = {c \in ]a,b[ \text{  }: \exists f'(c)}$ 
 - $C = \{a;b\}$
in quanto, se un punto di estremo assoluto appartiene all'interno di $[a,b]$ in tale punto la derivata, se esiste, è nulla per il teorema di Fermat: Pertanto, i punti di estremo assoluto andranno cercati o all’interno dell’intervallo, e in tal caso la derivata o non esiste oppure esiste e vale zero, oppure agli estremi dell’intervallo. Un volta determinati i tre insiemi $A, B, C$ basta calcolare i valori della funzione in tutti i punti di tali insiemi per trovare il minimo e il massimo.
![[Pasted image 20250606110912.png]]


### Funzioni localmente convesse
###### Definizione
Sia $f: (a,b) \to R$ una funzione derivabile e sia $c \in (a,b)$, ricordiamo che l'equazione della tangente al grafico di $f$ nel punto di ascissa $c$ è $y = f(c)+f'(c)(x-c)$ e questa divide il piano in due semipiani:
- Semipiano superiore definito come: $\overline{S} = \{(x,y)\in R^2: y \ge f(c)+f'(c)(x-c)\}$  
- Semipiano inferiore definito in modo analogo e lo indichiamo con $\underline{S}$ 
La funzione $f$ si dice **convessa** nel punto $c$ se esiste $r>0$ tale che, se $x \in ]c-r,c+r[$ si ha: $$f(x)\ge f(c)+f'(c)(x-c)$$ossia per tutti i punti di un opportuno intorno di $c$ il corrispondente punto del grafico appartiene a $\overline{S}$. La funzione si dice **concava** nel punto $c$ se per tutti i punti di un opportuno intorno di $c$ il corrispondente punto del grafico appartiene a $\underline{S}$. Se $f$ in $c$ non è né convessa né concava si dice che $c$ è un **punto di flesso**per $f$, hanno particolare interesse i punti di flesso detti **punti di flesso propri** che si hanno quando:
- se $x \in ]c-r,c[$ il corrispondente punto del grafico appartiene a $\overline{S}$ 
- se $x \in ]c,c+r[$ il corrispondente punto del grafico appartiene a $\underline{S}$ 
Si può dimostrare che $f$ è convessa in $(a,b)$ se lo è in ogni punto.

###### Teoremi
**Teorema**: sia $f$ una funzione derivabile in $(a,b)$ e sia $c\in(a,b)$ tale che esista $f''(c)>0$. Allora $f$ è convessa in $c$ (allo stesso modo si dice che se esiste $f''(c)<0$ allora $f$ è concava in $c$.)
**Dimostrazione**: Dobbiamo provare che in un opportuno intorno di $c$ si ha $f(x)\ge f(c)+f'(c)(x-c)$. 
Consideriamo allora in $(a,b)$ la funzione $F(x) = f(x)-f(c)-f'(c)(x-c)$, la funzione che ci indica la distanza verticale tra $f(x)$ e la tangente in $c$ quindi ci  basterà provare che $F(x)\ge 0$ (se questo valore è positivo la nostra funzione si trova sopra la tangente) in un intorno di $c$. 
Da questo capiamo che:
- Si ha $F(c) = f(c)-f(c)-f'(c)(c-c) = 0$  
- $F'(x) = f'(x)-f'(c)$ che è uguale a 0 nel punto $x = c$ 
	- la derivata di $f(c)$ è $0$ quindi non lo scrivo
	- la derivata di $f'(c)(x-c)$ è $f'(c)$
- e che esiste $F''(c) = f''(c)$. $F$ ha dunque in $c$ un minimo relativo (perché la derivata prima è 0 invece la seconda è positiva)
dunque esiste un intorno di $c$ in tutti i punti del quale si ha $F(x)\ge F(c) = 0$ come si voleva.

**Continuo del teorema**: Ne segue che se esiste la derivata seconda in tutto l'intervallo $(a,b)$, gli eventuali punti di flesso vanno cercati fra i punti $c$ tali che $f''(c) = 0$ e in tal caso si ha un flesso proprio se:
- $f''(x)<0$ in un intorno sinistro di $c$
- $f''(x)>0$ in un intorno destri di $c$

**Teorema di de l'hopital**: Siano $f,g$ due funzioni reali derivabili in $(a,b)\backslash\{c\}$ tali che:
1. $\lim_{x\to c}f(x) = \lim_{x\to c}g(x) = 0$ oppure che $\lim_{x\to c}f(x) = \lim_{x\to c}g(x) = \infty$ 
2. $g'(x) \not = 0 \text{  } \forall x \in (a,b)\backslash\{c\}$ 
3. esiste il $\lim_{x\to c} \frac{f'(x)}{g'(x)} =l$ ($l \in R$ oppure $l = \pm\infty$)
Allora, si ha: 
- $g(x) \not = 0 \text{  } \forall x \in (a,b) \backslash \{c\}$
- $\lim_{x\to c}\frac{f(x)}{g(x)} = l$ 

> [!EXAMPLE]
> Si voglia calcolare il $\lim_{x\to 0}x \log x$ allora si ha:
> $x\log x = \frac{\log x}{\frac{1}{x}}$  
> facendo la derivata otteniamo: 
> $$\frac{\frac{1}{x}}{-\frac{1}{x^2}} = \frac{1}{x} \times -x^2 = -x \to 0$$
> quindi possiamo concludere che il limite richiesto vale zero

Questo teorema può essere utile anche nella ricerca degli asintoti obliqui. Supponendo infatti che: 
- $\lim_{x\to +\infty}$ $f(x)  = \infty$ 
- $\lim_{x\to +\infty}$ $f'(x)  = m \in R$ 
allora si avrà $\lim_{x\to +\infty}\frac{f(x)}{x} = \lim_{x\to +\infty}\frac{f'(x)}{1} = m$ 
dove $m$ è il coefficiente angolare dell'eventuale asintoto obliquo

Ovviamente ci sono dei casi in cui questo teorema non va usato:
1. $\lim_{x\to 0} \frac{sinx}{x}$ il rapporto delle derivate tende ad 1 ma non è opportuno applicare questo teorema in quanto per calcolare la derivata di $\sin x$ era già necessario conoscere tale limite.  
   
> [!quote]
> Se non vi ricordate il risultato di qualche limite notevole potete usare de l'hopital basta che non lo vedo io (by Ornella Naselli)

2. $\lim_{x\to \infty} \frac{2^x}{3^x}$. il limite vale zero, come si vede subito riscrivendo la funzione nella forma $(\frac{2}{3})^x$. Il rapporto delle derivate non è di nessun aiuto in quanto vale $\frac{2^x}{3^x}\times\frac{\log 2}{\log 3}$.
Precisiamo infine che in alcuni casi il limite di $\frac{f(x)}{g(x)}$ esiste anche se non esiste il limite di $\frac{f'(x)}{g'(x)}$ il teorema fornisce dunque una condizione sufficiente ma non necessaria. 
Consideriamo ad esempio, per $x \to 0$ la coppia di funzioni $f(x) = x^2\sin\frac{1}{x}g(x) = x$. Il loro rapporto è $x\sin \frac{1}{x}$ che tende a zero. Il rapporto delle derivate è $2x\sin\frac{1}{x}-\cos\frac{1}{x}$ che al tendere di $x$ a $0$ non è regolare. 


> [!EXAMPLE]
> Esercizi di esempio
> ![[Pasted image 20250609144432.png]]
> ![[Pasted image 20250609144442.png]]
