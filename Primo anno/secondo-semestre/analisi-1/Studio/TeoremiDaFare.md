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

###### Corollari del teorema di Lagrange
1. **Teorema del prolungamento della derivata**: Sia data una funzione $f: (a,b)\to R$ e sia $c \in (a,b)$. Supponiamo che $f$ sia derivabile in $(a,b)\backslash\{c\}$ e che sia continua in $c$. Supponiamo inoltre che esista il $\lim_{x\to c}f'(x)$ e sia esso $l$ allora si ha $\lim_{x\to c}r(x) = l$ 
	- **Osservazione**: Dal teorema appena enunciato segue che le funzioni $\arcsin x$ e $\arccos x$ non sono derivabili in $-1$ e $1$, infatti sono continue ma le loro derivate divergono al tendere di $x$ a tali punti.
2. **Criterio di monotonia**: Sia data una funzione $f: (a,b) \to R$ derivabile, questa è un condizione sufficiente affinché $f$ sia crescente in $(a,b)$ è che $f'(x)\ge 0 \forall x \in (a,b)$ 
	- **Dimostrazione**: Siano $x,y \in (a,b)$ con $x<y$. Applicando il teorema di Lagrange ad $f$ nell'intervallo $[x,y]$ si ottiene che esiste $c \in ]x,y[$ tale che $f(y)-f(x) = (y-x)f'(c)\ge 0$ da cui la tesi.
3. **Criterio di stretta monotonia**: Sia data una funzione $f: (a,b) \to R$ derivabile. Condizione necessaria e sufficiente affinché $f$ sia strettamente crescente in $(a,b)$ è che:
	- $f'(x)\ge0 \text{  } \forall x \in (a,b)$ 
	- e che non esista nessun intervallo $(c,d) ⊆ (a,b)$ tale che $f'(x) = \forall x \in (c,d)$ 
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