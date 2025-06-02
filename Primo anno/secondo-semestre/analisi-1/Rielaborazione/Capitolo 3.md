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