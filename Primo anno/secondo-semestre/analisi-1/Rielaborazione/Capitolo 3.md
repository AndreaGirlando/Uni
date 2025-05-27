Questo è la rielaborazione del file [[AppuntiCap3.pdf]]

# Limiti e continuità delle funzioni reali di una variabile reale

Per una funzione reale si possono dare 9 definizioni di limite, precisamente studiare il limite di una funzione significa vedere qual è il comportamento della funzione stessa quando la variabile si avvicina ("tende") ad un certo punto. Le nove definizioni si differenziano l'una dall'altra solo per il diverso significato di "definitivamente".

### Definizioni di limite
###### Limite al tendere di x a c

> [!quote]
> **Punto di accumulazione**: un numero reale $c$ è detto punti di accumulazione per $X$ se, per ogni $r>0$ nell'intorno $]c-r,c++r[$ ci sono elementi diversi da $c$. L'insieme dei punti di accumulazione di accumulazione si denota con $D(X)$ 

Data una funzione reale definita in un insieme $X ⊆ R$, se $c \in D(x)$ si definisce il limite di $f$ al tendere di $x$ a $c$ nel seguente modo:
1. Si dice che $f$ **converge** al numero $l$ al tendere di $x$ a $c$ e si scrive: $$\lim_{x\to c}f(x) = l \in R$$ se $\forall \epsilon > 0$ $\exists δ > 0: x \in X, x \not=c,|x-c|<δ \Rightarrow |f(x)-l| < \epsilon$ ovvero $l-\epsilon < f(x) < l+\epsilon$  
   **Spiegazione intuitiva**: Dire che il limite di $f(x)$ per $x$ che tende a $c$ è $l$ significa che possiamo rendere $f(x)$ arbitrariamente vicino a $l$, scegliendo $x$ sufficientemente vicino a $c$ (ma senza che $x$ debba essere uguale a $c$). In altre parole, per ogni livello di precisione $\epsilon$ che vogliamo raggiungere, esiste un intervallo attorno a $c$ (di ampiezza $\delta$) tale che, se $x$ si trova all’interno di questo intervallo (escluso il punto $c$), allora $f(x)$ sarà compreso nell’intervallo $(l - \epsilon, l + \epsilon)$.
   
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