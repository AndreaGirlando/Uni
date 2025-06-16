### Capitolo 1
**Teorema Densità di Q e di R\Q in R**: Siano $a,b$ due numeri reali con $a<b$. Allora, esistono infiniti numeri razionali $r$ e infiniti numeri irrazionali $s$ tali che $a<r<b$, $a<s<b$. 
Da questo teorema segue che tra $a$ e $b$ esistono infiniti numeri reali.

---

**Teorema inf e sup**:
1. Sia $X$ un insieme limitato inferiormente, allora possiamo dire che $\underline{M_x}$ è dotato di massimo
2. Sia $X$ un insieme limitato superiormente, allora possiamo dire che $\overline{M_x}$ è dotato di minimo
Quindi possiamo dire che:
- **Estremo inferiore**: che denotiamo con $inf X$ è uguale al $max \underline{M_x}$, se $X$ non è limitato inferiormente si pone $inf X = - \infty$. Dato un numero $l$ questo è l'estremo inferiore di $X$ se e solo se verifica queste proprietà:
	- $L \le x$ $∀x \in X$
	- $∀\epsilon \gt 0 ∃x \in X: x<l-\epsilon$
- **Estremo superiore**: che denotiamo con $supX$ è uguale al $min\underline{M_x}$, se $X$ non è limitato superiormente si pone $supX = +\infty$. Dato un numero $l$ questo è l'estremo superiore di $X$ se e solo se verifica queste proprietà:
	- $L \ge x$ $∀x \in X$
	- $∀\epsilon \gt 0 ∃x \in X: x>l-\epsilon$

---

**Teorema della radice n-ma aritmetica**: Siano $a$ un numero reale positivo ed $n$ un numero naturale maggiore o uguale a 2. Allora esiste uno ed uno solo numero positivo $b$ tale che $b^n = a$, il numero $b$ è detto radice n-ma aritmetica di $a$ e si indica con $\sqrt[n]{a}$. Grazie a questo teorema se $a>0$ e $n \in N$ si definisce:
- $a^{\frac{1}{n}}$ = $\sqrt[n]{a}$
- $a^{\frac{m}{n}} = (\sqrt[n]{a})^m$ 

---

**Teorema del rapporto incrementale**: La funzione $f$ è crescente (o decrescente) nel punto $c$ se e solo se esiste un intorno $I_s(c)$ tale che, per ogni $x \in I_s(c)\backslash\{c\}$ si abbia $r(x)>0$ (o $r(x)<0$)
**Dimostrazione**: Supponiamo che $r(x) > 0$ in $I_s(c) \ {c}$. In $]c − s, c[$ il denominatore di r e negativo, quindi lo e anche il numeratore: dunque, $f (x) < f (c)$. In $]c, c + s[$ il denominatore di $r$ e positivo, quindi lo e anche il numeratore: dunque, $f (x) > f (c)$. Ne segue che $f$ e crescente nel punto $c$. Il viceversa si prova allo stesso modo.

---
### Capitolo 2
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
---
**Teorema di confronto per successioni divergenti**: Se $a_n \le b_n$ per ogni $n \in N$ e $a_n \rightarrow +\infty$ allora $b_n \rightarrow +\infty$ oppure se $b_n \rightarrow -\infty$ allora $a_n \rightarrow -\infty$
**Teorema non in matematichese**: se la successione $a_n$ è sempre più piccola di $b_n$ allora se $a_n\rightarrow +\infty$ anche $b_n \rightarrow \infty$ (anche l'altro caso funziona allo stesso modo)
**Dimostrazione**: Se $a_n \rightarrow +\infty$ allora definitivamente si ha $a_n>k$ ne segue che $b_n \ge a_n >k$ (l'altro caso si prova in modo analogo)

---

**Teorema di regolarità (o sul limite) delle successioni monotone**:
- Una successione che verifica una delle condizioni $1)$ e $2)$ tende al suo estremo inferiore
- Una successione che verifica una delle condizioni $3)$ e $4)$ tende al proprio estremo superiore
**Dimostrazione**
Proviamo per semplicità solo il caso della divergenza:
1. Se $\inf a_n = -\infty$ fissato $k>0$ il numero $-k$ non è un minorante per la successione perché esiste sicuramente un numero nella successione più piccolo di $k$  ovvero $a_\alpha <-k$. Per $n> \alpha$ si ha $a_n \ge a_\alpha >k$ che è la tesi
2. Se $\sup a_n = +\infty$ fissato $k>0$ il numero $k$ non è un maggiorante per la successione perché esiste sicuramente un numero nella successione più grande di $k$ ovvero $a_\alpha > k$. Per $n>\alpha$  si ha $a_n>a_\alpha>k$ che è la tesi

---
**Teorema di regolarità delle successioni estratte**: Se $\{a_n\}$ è regolare, ogni sua estratta ha il suo stesso limite, il viceversa non vale.

---

### Capitolo 3
Per la funzione **regolare al tendere di x a c** abbiamo questo i seguenti teoremi:
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
---
**Teorema delle funzioni monotone**: Sia $f: (a,b)\to R$ una funzione strettamente crescente in $(a,b)$ allora possiamo dire che:
- per ogni $c \in ]a,b[$ esistono i limiti destro e sinistro di $f$ al tendere di $x$ a $c$ e si ha che $$l^- = \lim_{x\to c^-} f(x) = \sup_{(a,c[} \text{ } f(x) \le f(c) \le l^+ = \lim_{x\to c^+} f(x) = \inf_{]c,b)}f(x)$$
- esistono i limiti di $f$ al tendere di $x$ ad $a$ e a $b$ e si ha:
	- $l^+ = \lim_{x\to a}f(x)  = \inf_{]a,b)}f(x)$
	- $l^- = \lim_{x\to b}f(x)  = \inf_{(a,b[}f(x)$

---
**Teorema di Weierstrass**: Sia $f$ una funzione reale continua in un intervallo chiuso e limitato $[a,b]$, allora $f$ ammette minimo e massimo assoluti

---

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
---
**Teorema di esistenza dei valori intermedi (teorema di Darboux)**: Sia $f$ una funzione reale continua in un intervallo chiuso e limitato $[a,b]$ e si supponga che $f(a) \not = f(b)$ ad esempio $f(a)<f(b)$. Allora per ogni $\gamma \in ]f(a),f(b)[$ esiste $c \in [a,b]$ tale che $f(c) = \gamma$ 
 **Dimostrazione**: Consideriamo in $[a,b]$ la funzione $g(x) = f(x)-\gamma$ che è continua e agli estremi dell'intervallo assume valori di segno diverso, quindi per il teorema di esistenza degli zeri, si annulla in un punto $c$: si ha dunque  $f(c)-\gamma = 0$ e quindi che $f(c) = \gamma$ 

---
**Teorema di continuità delle funzioni monotone:** Sia $f: (a,b) \to R$ una funzione strettamente monotona e sia verificata la PVI allora $f$ è continua
**Dimostrazione**: Supponiamo che $f$ sia crescente e proviamo la continuità in un punto $c$ interno ad $(a,b)$. Dal teorema sui limiti delle funzioni monotone segue che $l^-\le f(x) \le l^+$ per provare la continuità basta provare che $l^- = f(x) = l^+$. Supponiamo per assurdo che non sia vero, ad esempio si abbia $l^- < f(c)$. Sia $\gamma \in ]l^-,f(c)[$ per la PVI esiste $\overline{x} \in (a,b)$ tale che $f(\overline{x}) = \gamma$. L'assurdo segue dal fatto che $\overline{x}$ non può esistere, infatti:
- se $\overline{x} = c$ si avrebbe $\gamma  = f(\overline{x}) = f(c)$ 
- se $\overline{x} < c$ si avrebbe $\gamma = f(\overline{x}) \le l^-$ 
- se $\overline{x} > c$ si avrebbe $\gamma = f(\overline{x}) > f(c)$
L'assurdo è dunque trovato. 

---
**Conseguenze di questi teoremi**
1. **Immagine di un intervallo mediante una funzione continua**: Sia $f:[a,b]\to R$ una funzione continua, dal teorema di Darboux segue che la sua immagine è un intervallo, e dal teorema di Weierstrass segue che $f$ possiede minimo $m$ e massimo $M$ quindi la sua immagine è l'intervallo chiuso e limitato $[m,M]$
	1. Se $f$ è crescente la sua immagine è l'intervallo $[f(a),f(b)]$ 
	2. Se $f$ è decrescente la sua immagine è l'intervallo $[f(b),f(a)]$
   In generale, se $f$ è una funzione continua in un intervallo generico $(a,b)$ la sua immagine è l'intervallo $(\inf_{(a,b)}f(x), sup_{(a,b)}f(x)$  
2. **Continuità della funzione inversa**: sia $f: [a,b] \to [f(a),f(b)]$ una funzione strettamente crescente e continua (può essere anche decrescente). Allora la sua inversa è continua.
3. **Continuità delle funzioni elementari**: tutte le funzioni elementari che abbiamo introdotto sono continue nei rispettivi insiemi di definizione. Sia infatti $c$ un punto dell'insieme di definizione di $f$. Se $c$ è contenuto in un intervallo in cui $f$ è monotona, la continuità in $c$ segue dal teorema di continuità delle funzioni monotone, in caso contrario il limite destro e sinistro coincidono

---

### Capitolo 4
**Teorema**: Se $f$ è derivabile in $c$ allora è continua
**Dimostrazione**: Si ha $$f(x) = f(x)-f(c)+f(c) = \frac{f(x)-f(c)}{x-c}(x-c) + f(c)$$e questa quantità al tendere di $x$ a $c$ converge a $f'(c) \cdot 0 + f(c) = f(c)$. Il viceversa non vale, consideriamo i due seguenti esempi:
1. $f(x) = \sqrt{x}, c = 0.$ Il rapporto incrementale $f(x) = \frac{1}{\sqrt{x}}$ diverge al tendere di $x$ a $0$
2. $f(x) = |x|, c = 0$. Il rapporto incrementale $r(x) = \frac{|x|}{x}$ vale $1$ per $x>0$ e $-1$ per $x<0$ quindi tende ad $1$ al tendere di $x$ a $0$ da destra e a $-1$ al tendere di $x$ a $0$ da sinistra. 
Le funzioni presentate nei precedenti esempi sono continue nel punto $c=0$ ma non sono derivabili in tale punto. Il seguente risultato prova che una funzione è derivabile nel punto $c$ solo se è possibile approssimarla in un intorno di $c$, con un polinomio di primo grado.

---

**Teorema**: $f$ è derivabile in $c$ se e solo se esiste un polinomio di primo grado $p$ tale che $p(c) = f(c)$ e che $\lim_{x\to c}\frac{f(x)-p(x)}{x-c} = 0$  
**Osservazione**: la condizione $\lim_{x\to c}\frac{f(x)-p(x)}{x-c} = 0$ significa che la differenza $f(x)-p(x)$ è un infinitesimo di ordine superiore rispetto a $x-c$ quindi al tendere di $x$ a $c$ è trascurabile: dunque $f$si può approssimare con il polinomio $p$
**Dimostrazione**: Se $f$ è derivabile in $c$, basta porre:
$$p(x) = f(c)+f'(c)(x-c)$$si ha infatti $$\frac{f(x)-p(x)}{x-c} = \frac{f(x)-f(x)}{x-c}-f'(c) \to 0$$
Viceversa, se esiste il polinomio $p = f(c)+a(x-c)$ si ha $$\frac{f(x)-f(c)}{x-c} = \frac{f(x)-p(x)+p(x)-f(c)}{x-c} = \frac{f(x)-p(x)}{x-c}+a\to 0+a \text{ quindi esiste } f'(c) = a$$ 

---

**Conseguenza della derivata**: Ricordando il teorema sul rapporto incrementale scritto nel capitolo 1 che ci diceva che la funzione $f$ è crescente (o decrescente) nel punto $c$ se e solo se $r(x)>0$(o $r(x)<0$) in un intorno di $c$. Quindi usando le derivate possiamo affermare che se $f'(c)>0$ (o $f'(c)<0$) allora per il teorema della permanenza del segno si avrà $r(x)>0$(o $r(x)<0$) in un intorno di $c$. 

---

**Teorema 1 (monotonia locale)**: Se $f'(c)>0$ $(\text{ oppure } f'(c)<0)$ allora $f$ è crescente (oppure decrescente) nel punto $c$, il viceversa non è vero. 
- Ad esempio $f(x) = x^3$ è crescente nel punto $c = 0$ ma $f'(0) = 0$.

---

**Teorema di Fermat**: Data una funzione $f(a,b) \to R$ sia $c \in ]a,b[$ un punto di minimo o di massimo relativo per $f$. Si supponga che $f$ sia derivabile nel punto $c$ allora si ha $f(c)' = 0$ 
**Dimostrazione**: Dato che il $c$ è interno, la derivata è il limite del rapporto incrementale sia da sinistra che da destra. il numeratore del rapporto incrementale in un intorno di $c$ ha sempre lo stesso segno sia a destra che a sinistra, mentre il denominatore è negativo a sinistra di $c$ e positivo a destra, quindi possiamo dire che:
- $f'(c) = f'_-(c) = \lim_{x\to c^-}r(x)\le 0$ 
- $f'(c) = f'_+(c) = \lim_{x\to c^+}r(x)\ge 0$ 
quindi necessariamente $f'(c) = 0$. Il viceversa di questo teorema non vale infatti prendendo la funzione $f(x) = x^3$ si ha $f'(0) = 0$ ma il punto $c = 0$ non è un estremo relativo, infatti $f$ è crescente in ogni punto di $R$. Quindi il fatto che $f'(c) = 0$ è una condizione necessaria, ma non sufficiente, per l'esistenza di un estremo relativo. Infine possiamo dire che i punti $c$ tale $f'(c) = 0$sono detti punti stazionari o critici per $f$.

---

**Teorema di Rolle**: Sia $f$ una funzione reale continua nell'intervallo chiuso $[a,b]$ e derivabile in $]a,b[$ tale che $f(a) = f(b)$. Allora esiste $c \in ]a,b[$ tale che $f'(c) = 0$ 
**Dimostrazione**: Per il teorema di Weierstrass $f$ è dotata di minimo e massimo assoluti:
- $x_1$ punto di minimo assoluto
- $x_2$ punto di massimo assoluto
Se $x_1 = a$ e $x_2 = b$ (o viceversa) allora il minimo e il massimo assoluti della funzione sono uguali quindi $f$ è costante e la sua derivata è ovunque nulla. In caso contrario uno dei due punti $x_1,x_2$ è interno, in esso allora la derivata è nulla per il teorema di Fermat

---

**Teorema di Lagrange**: Sia $f$ una funzione reale continua nell'intervallo $[a,b]$ e derivabile $]a,b[$. Allora esiste $c \in ]a,b[$ tale che $f(b)-f(a) = f'(c)(b-a)$ 
**Dimostrazione**: Consideriamo in $[a,b]$ la funzione $$g(x) = (f(b)-f(a))x+(a-b)f(x)$$Si vede facilmente che essa verifica le ipotesi del teorema di Rolle, quindi esiste $c \in ]a,b[$ tale $g'(c) = 0$. Dal fatto che $g'(x) = f(b)-f(a)+(a-b)f'(x)$ segue subito la tesi.

---
**Corollari del teorema di Lagrange**
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

---

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

---

**Continuo del teorema**: Ne segue che se esiste la derivata seconda in tutto l'intervallo $(a,b)$, gli eventuali punti di flesso vanno cercati fra i punti $c$ tali che $f''(c) = 0$ e in tal caso si ha un flesso proprio se:
- $f''(x)<0$ in un intorno sinistro di $c$
- $f''(x)>0$ in un intorno destri di $c$

---

**Teorema di de l'hopital**: Siano $f,g$ due funzioni reali derivabili in $(a,b)\backslash\{c\}$ tali che:
1. $\lim_{x\to c}f(x) = \lim_{x\to c}g(x) = 0$ oppure che $\lim_{x\to c}f(x) = \lim_{x\to c}g(x) = \infty$ 
2. $g'(x) \not = 0 \text{  } \forall x \in (a,b)\backslash\{c\}$ 
3. esiste il $\lim_{x\to c} \frac{f'(x)}{g'(x)} =l$ ($l \in R$ oppure $l = \pm\infty$)
Allora, si ha: 
- $g(x) \not = 0 \text{  } \forall x \in (a,b) \backslash \{c\}$
- $\lim_{x\to c}\frac{f(x)}{g(x)} = l$ 