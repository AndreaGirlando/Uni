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
