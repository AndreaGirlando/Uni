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

###### Teoremi
**Teorema 1 (monotonia locale):** Se $f'(c)>0$ $(\text{ oppure } f'(c)<0)$ allora $f$ è crescente (oppure decrescente) nel punto $c$, il viceversa non è vero. 
- Ad esempio $f(x) = x^3$ è crescente nel punto $c = 0$ ma $f'(0) = 0$.

**Teorema di Fermat**: Data una funzione $f(a,b) \to R$ sia $c \in ]a,b[$ un punto di minimo o di massimo relativo per $f$. Si supponga che $f$ sia derivabile nel punto $c$ allora si ha $f(c)' = 0$ 
**Dimostrazione**: Dato che il $c$ è interno, la derivata è il limite del rapporto incrementale sia da sinistra che da destra. il numeratore del rapporto incrementale in un intorno di $c$ ha sempre lo stesso segno sia a destra che a sinistra, mentre il denominatore è negativo a sinistra di $c$ e positivo a destra, quindi possiamo dire che:
- $f'(c) = f'_-(c) = \lim_{x\to c^-}r(x)\le 0$ 
- $f'(c) = f'_+(c) = \lim_{x\to c^+}r(x)\ge 0$ 
quindi necessariamente $f'(c) = 0$. Il viceversa di questo teorema non vale infatti prendendo la funzione $f(x) = x^3$ si ha $f'(0) = 0$ ma il punto $c = 0$ non è un estremo relativo, infatti $f$ è crescente in ogni punto di $R$. Quindi il fatto che $f'(c) = 0$ è una condizione necessaria, ma non sufficiente, per l'esistenza di un estremo relativo. Infine possiamo dire che i punti $c$ tale $f'(c) = 0$  sono detti punti stazionari o critici per $f$.

**Teorema di Rolle**: Sia $f$ una funzione reale continua nell'intervallo chiuso $[a,b]$ e derivabile in $]a,b[$ tale che $f(a) = f(b)$. Allora esiste $c \in ]a,b[$ tale che $f'(c) = 0$ 
**Dimostrazione**: Per il teorema di Weierstrass $f$ è dotata di minimo e massimo assoluti:
- $x_1$ punto di minimo assoluto
- $x_2$ punto di massimo assoluto
Se $x_1 = a$ e $x_2 = b$ (o viceversa) allora il minimo e il massimo assoluti della funzione sono uguali quindi $f$ è costante e la sua derivata è ovunque nulla. In caso contrario uno dei due punti $x_1,x_2$ è interno, in esso allora la derivata è nulla per il teorema di Fermat

**Teorema di Lagrange**: Sia $f$ una funzione reale continua nell'intervallo $[a,b]$ e derivabile $]a,b[$. Allora esiste $c \in ]a,b[$ tale che $f(b)-f(a) = f'(c)(b-a)$ 
**Dimostrazione**: Consideriamo in $[a,b]$ la funzione $$g(x) = (f(b)-f(a))x+(a-b)f(x)$$ Si vede facilmente che essa verifica le ipotesi del teorema di Rolle, quindi esiste $c \in ]a,b[$ tale $g'(c) = 0$. Dal fatto che $g'(x) = f(b)-f(a)+(a-b)f'(x)$ segue subito la tesi.
 