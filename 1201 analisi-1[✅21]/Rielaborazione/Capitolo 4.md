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
> ![[Pasted image 20250615102458.png]]
