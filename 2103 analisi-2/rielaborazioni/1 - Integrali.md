# Integrali indefiniti e definiti

##### Integrali indefiniti

Sia data una funzione $f: (a,b) \rightarrow R$ 
###### Definizione 1: 
Sia $F: (a,b) \rightarrow R$ una funzione derivabile in $(a,b)$ e tale che $$F'(x) = f(x) \text{ } \forall x \in (a,b)$$ Si dice allora che $F$ è una primitiva di $f$ in $(a, b)$
###### Teorema 1 (caratterizzazione delle primitive): 
Sia $F$ una primitiva di $f$ in $(a,b)$. Allora tutte e sole le primitive di $f$ in $(a, b)$ sono le funzioni $F(x)+k$ al variare di $k$ in $R$
###### Dimostrazione 1: 
Se $F$ è una primitiva di $f$ in $(a, b)$ e $k \in R$, posto $$G(x) = F(x)+k$$ si ha subito $$G'(x) = f(x)+0 = f(x) \forall x \in (a, b)$$ Viceversa se $F$ e $G$ sono due primitive di $f$ in $(a, b)$ la funzione differenza: $$H(x) = G(x)-F(x) \forall x \in (a, b)$$ è derivabile in $(a, b)$ e si ha:
$$H'(x) = G'(x)-F'(x) = f(x)-f(x) = 0 \text{ } \forall x \in (a,b)$$
Per il teorema sulle funzione con derivata nulla $H$ è costante in $(a, b)$ e quindi esiste $k \in R$ tale che $$F(x)-G(x) = k \text{ } \forall x \in (a, b)$$
Da questo segue che se una funzione ha primitiva allora ne ha infinite, esistono casi in cui delle funzioni che non hanno alcuna primitiva

**Esempio 1**: Si consideri la funzione definita in $R$ ponendo
$$f(x) = \big\{^{1 \text{ se }x \ge0 }_{-1 \text{ se } x \le 0} $$Supponiamo per assurdo che $F$ sia una primitiva di $f$ in $] -\infty, +\infty [$  in particolare $F$ è una primitiva di $f$: 
- sia in $[0, +\infty[$ 
- sia in $]-\infty, 0[$  
Osserviamo che un altra primitiva di $f$ in $[0, +\infty[$ è la funzione $g(x) = x$ quindi per il teorema precedente esiste un numero reale $k$ tale che $$F(x) = x+k \text{  } \forall x \ge 0$$Analogamente si conclude che esiste un numero reale $c$ tale che $$F(x) = -x+c \text{  } \forall x < 0$$ Dato che $F$ è una funzione derivabile e quindi continua in $] -\infty, +\infty [$ si ha $$lim_{x\rightarrow 0^-} F(x) = lim_{x\rightarrow 0^+} F(x) \text{ cioè } c = k$$ e quindi in definitiva che $$F(x) = |x|+k \forall \text{  } x \in R$$ è ciò è assurdo perché implica che la funzione $|x|$ è derivabile in tutto $R$.

###### Definizione 2
Si chiama integrale indefinito di $f$ e si denota con il simbolo $$\int f(x)dx$$
*L'insieme formato dalle primitive di $f$, se $f$ è dotata di primitive, l'insieme vuoto se $f$ non è dotata di primitive*

 quindi se $F$ è una primitiva di $f$ di solito si scrive: $$\int f(x) dx = F(x)+k, k \in R$$L'integrale indefinito è dunque un **insieme di funzioni** vuoto o costituito da infiniti elementi

###### Integrali indefiniti notevoli
$$ \int e^x dx = e^x + k $$
$$ \int \cos x dx = \sin x + k $$
$$ \int \sin x dx = - \cos x + k $$
$$ \int \frac{1}{x^2 + 1} dx = \arctan x + k $$
$$ \int \frac{1}{\sqrt{1 - x^2}} dx = \arcsin x + k = - \arccos x + k $$
$$ \int x^\alpha dx = \frac{x^{\alpha+1}}{\alpha + 1} + k, (\alpha \neq -1) $$
$$ \int \frac{1}{x} dx = \log |x| + k $$
$$ \int e^{f(x)} f'(x) dx = e^{f(x)} + k $$
$$ \int \cos[f(x)] f'(x)dx = \sin[f(x)] + k $$
$$ \int \sin[f(x)] f'(x) dx = - \cos[f(x)] + k $$
$$ \int \frac{1}{[f(x)]^2 + 1} f'(x) dx = \arctan[f(x)] + k $$
$$ \int \frac{1}{\sqrt{1 - [f(x)]^2}} f'(x) dx = \arcsin[f(x)] + k = - \arccos[f(x)] + k $$
$$ \int [f(x)]^\alpha f'(x) dx = \frac{[f(x)]^{\alpha+1}}{\alpha + 1} + k, (\alpha \neq -1) $$
$$ \int \frac{1}{f(x)} f'(x) dx = \log |f(x)| + k $$
 

###### Teorema 2 (Proprietà di omogeneità)
Se $f$ è dotata di primitive in $(a, b)$ e $k$ è un numero reale diverso da zero allora:
1. **i)** $kf$ è dotata di primitive in $(a, b)$ 
2. **ii)** $\int kf(x) dx = k \int f(x) dx$ dove il secondo membro indica l'insieme delle funzioni ottenute moltiplicando per $k$ le primitive di $f$ 
**Dimostrazione**
Se $$F \in \int k\text{ }f(x) dx$$ allora $F'(x) = kf(x) \forall x \in (a, b)$. Posto
$$G(x) = \frac{F(x)}{k} \forall x \in (a, b)$$si ha che $$G'(x) = f(x) \forall x \in (a, b) \text{ ovvero $G$ è una primitiva di $f$ in $(a,b)$}$$Poiché $$F(x) = kG(x) \text{ , } \forall x \in (a, b)$$
la funzione $F$ appartiene al secondo membro della **ii)** in quanto è il prodotto di $k$ per una primitiva di $f$. Viceversa se $F \in k \int f(x) dx$ esiste $G$ primitiva di $f$ tale che:
$$F(x) = kG(x) \forall x \in (a, b)$$ da cui $F'(x) = kf(x) \forall x \in (a, b)$ e quindi che $$F \in \int kf(x) dx$$
**Osservazione**: se k = 0 la tesi non vale, infatti in questo caso il primo membro è l'integrale della funzione identicamente nulla, cioè l'insieme delle funzioni costanti, mentre il secondo membro è formato dalla sola funzione identicamente nulla
![[Pasted image 20251019113334.png|500]]

###### Teorema 3 (Proprietà distributiva)
Siano $f$ e $g$ due funzioni dotate di primitive in $(a, b)$ allora
- **i)** $f+g$ è dotata di primitive in $(a, b)$
- **ii)** $\int (f(x)+g(x)) dx = \int f(x) dx + \int g(x) dx$ 
dove il secondo membro indica l'insieme delle funzioni ottenute sommando una primitiva di $f$ ed una primitiva di $g$ da questo segue

###### Metodo di integrazione per decomposizione in somma
Se $f, g$ sono due funzioni dotate di primitive in $(a, b)$ e $h, k$ sono due numeri reali non entrambi nulli allora la funzione $hf+kg$ è dotata di primitive in $(a,b)$ e si ha
1. $$\int (h f(x) + k g(x)) dx = h \int f(x) dx + k \int g(x) dx$$
2. $$\int (h f(x) + k g(x)) dx = h F(x) + k \int g(x) dx$$ essendo $F$ una primitiva di $f$ in $(a,b)$, Il seguente risultato fornisce un utile metodo di integrazione quando la funzione integranda è il prodotto di una funzione per la derivata di un'altra funzione

###### Teorema 4 (Integrazione indefinita per parti)
Siano $f, g$ due funzioni derivabili in $(a,b)$. Se $fg'$ è dotata di primitive in $(a, b)$ allora:
- **i)** $f'g$ è dotata di primitive in $(a, b)$ 
- **ii)** $\int f(x)g'(x) dx = f(x)g(x) - \int f'(x)g(x) dx$ 
**Dimostrazione**: per la regola di derivazione del prodotto si ha:$$
f(x)g'(x) = (f(x)g'(x) + f'(x)g(x)) - f'(x)g(x) \\ = D[f(x)g(x)] - f'(x)g(x), \quad \forall x \in (a, b)$$
la **i)** è vera per la proprietà distributiva dell'integrale indefinito, applicando la formula di integrazione per decomposizione in somma si ottiene la  **ii)**. Questa formula si usta dunque quando è possibile individuare, nella funzione integranda un fattore di cui sia nota una primitiva. I fattori $f$ e $g'$ si chiamano rispettivamente *fattore finito* e *fattore differenziale*


**Esempio 3**
Sia $n \in N$ determiniamo $$\int e^x x^n dx$$ scegliendo $e^x$ come fattore differenziale e $x^n$ come fattore finito si ha:
e dopo $n$ integrazioni per parti il problema viene ricondotto alla determinazione dell'integrale indefinito di $e^x$  $$\int e^x x^n \,dx = e^x x^n - n \int e^x x^{n-1} \,dx = \\
= e^x x^n - n \left( e^x x^{n-1} - (n-1) \int e^x x^{n-2} \,dx \right) = \cdots.$$
> [!Danger] Errore
> Se avessimo scelto $e^x$ si arrivava alla determinazione dell'integrale $\int e^x x^{n+1} dx$ e quindi con il grado di x che aumenta cosa che inevitabilmente ci porta a calcoli enormi 

Con $n = 2$
$$ \int e^x x^2 dx = e^x x^2 - 2 \int e^x x dx = \\ $$$$ = e^x x^2 - 2 \left( e^x x - \int e^x \cdot 1 dx \right) = \\ $$$$ = e^x x^2 - 2 e^x x + 2 \int e^x dx = \\ $$ $$ = e^x x^2 - 2 e^x x + 2 e^x + k. $$
**Esempio 4**
Dato $$\int \log x \ dx$$
Considerando 1 come fattore differenziale si ha:
$$\int \log x \ dx = \int 1 \times \log x \ dx = x \log x - \int x \frac{1}{x} \ dx = x(\log x -1)+k$$
**Esempio 5**
![[Pasted image 20251019143533.png|500]]

**Osservazione 2**:
In alcuni casi integrando per parti si giunge ad un eguaglianza del tipo: $$\int f(x)\ dx = g(x)+c \int f(x)\ dx$$Se $c \not = 1$ si può dimostrare che: $$\int f(x) dx = \frac{1}{1-c}g(x)+k$$**Esempio 6**:
Applicando l'osservazione precedente per determinare $$\int e^x \sin x \ dx$$Che si risolve in: $$\int e^x \sin x \ dx = e^x \sin x - \int e^x \cos x \ dx = e^x \sin x -e^x \cos x - \int e^x \sin x \ dx$$e quindi: $$\int e^x \sin x \\ dx = \frac{1}{2}e^x(\sin x - \cos x) + k$$
Il seguente risultato fornisce un utile metodo di integrazione quando la funzione integranda è il prodotto di una funzione composta per la derivata della funzione interna


###### Teorema 5 (Primo teorema di integrazione indefinita per sostituzione)
Siano: $g:(a, b) \rightarrow (\alpha, \beta)$ una funzione derivabile, $f: (\alpha, \beta) \rightarrow R$ una funzione dotata di primitive in $(\alpha, \beta)$ allora si ha:
- **i)** $f(g(x))g'(x)$ è dotata di primitive in $(a, b)$ 
- **ii)** $$\int f(g(x))g'(x) \\ dx = \big [  \int f(t) \\ dt \big ]_{t=g(x)}$$
  dove il secondo membro è l'insieme delle funzioni ottenute componendo con $g$ le primitive di $f$ in $(\alpha, \beta)$ 

**Dimostrazione**: Sia $F$ una primitiva di $f$ consideriamo la funzione $G(x) = F(g(x))$ si ha $G'(x) = f(g(x))g'(x)$ quindi $G$ è una primitiva di $f(g(x))g'(x)$. Dunque il primo membro della tesi è uguale a $G(x)+k$ il secondo membro è uguale a $[F(t)+k]_{t = g(x)} = F(g(x))+k = G(x)+k$ 

**Esempio 7**: 
La proprietà appena dimostrata lo abbiamo applicato nell'esempio 2, infatti si ha:
$$\int e^{cx} dx = \frac{1}{c} \int c e^{cx} dx = \frac{1}{c} \left[ \int e^t dt \right]_{t=cx} = \frac{e^{cx}}{c} + k$$
Di seguito altri esempi:
1.  $$\text{Si ha } \int x \cos(x^2+5)dx = \frac{1}{2} \int (2x) \cos(x^2+5)dx = \frac{1}{2} \left[ \int \cos t dt \right]_{t=x^2+5} = \\
= \frac{1}{2} \sin(x^2+5) + k \\ $$ dato che la derivata di $x^2+5$ è 2x.
2. 
   $$\text{Si ha } \int \frac{e^x}{e^x+5} dx = \left[ \int \frac{1}{t+5} dt \right]_{t=e^x} = \log(e^x+5) + k$$
   Dato che la derivata di $e^x$ è $e^x$


###### Integrazione polinomi trigonometrici
Risolveremo solo integrali del tipo:
- $I_n = \int \cos^n x \, dx$
- $J_n = \int \sin^n x \, dx$
- $H = \int \cos^m x \sin^n x \, dx$
essendo $n, m \in N$ si ha:

$$I_1 = \sin x + k, \quad k \in \mathbb{R};$$

$$I_2 = \int \frac{1 + \cos(2x)}{2} \, dx = \frac{x}{2} + \frac{\sin(2x)}{4} + k, \quad k \in \mathbb{R};$$

$$I_3 = \int \cos x \cdot \cos^2 x \, dx = \int \cos x (1 - \sin^2 x) \, dx = \left[\int (1-t^2) \, dt\right]_{t=\sin x}$$
analogamente per $n>3$, in pratica possiamo dire che:
- **Per n pari**: si utilizzano le formule di bisezione
- **Per n dispari**: si ricorre all'integrazione per sostituzione
Analogamente:$$J_1 = -\cos x + k$$$$J_2 = \int \frac{1 - \cos(2x)}{2} \, dx$$$$J_3 = \int \sin x \cdot \sin^2 x \, dx = -\int (-\sin x)(1 - \cos^2 x) \, dx$$
e si procede allo stesso modo di $I_3$. Invece per determinare $H$ si distinguono due casi:
- **i)** se almeno uno fra $m,n$ è dispari, ad esempio $m = 2p+1, p\in N_0$ $$H = \int \cos x \cdot (\cos^2 x)^p \cdot \sin^n x \, dx = \int \cos x (1 - \sin^2 x)^p \sin^n x \, dx = \left[\int (1-t^2)^p t^n \, dt\right]_{t=\sin x}$$ praticamente arriviamo all'integrale di un polinomio
- **ii)** se $m,n$ sono entrambi pari ovvero $m = 2p, n = 2q$ con $p,q \in N$ si procede nel seguente modo


**Esempio 8**: di seguito alcuni integrali indefiniti di polinomi trigonometrici
1. $$\int \sin x \cos^3 x \, dx = -\int (-\sin x) \cos^3 x \, dx = -\left[\int t^3 \, dt\right]_{t=\cos x} = -\frac{\cos^4 x}{4} + k, \quad k \in \mathbb{R}.$$
2. $$\int \cos^3 x \sin^2 x \, dx = \int (\cos x) \cos^2 x \sin^2 x \, dx = \int (\cos x)(1-\sin^2 x) \sin^2 x \, dx = \left[\int (t^2 - t^4) \, dt\right]_{t=\sin x} = \frac{\sin^3 x}{3} - \frac{\sin^5 x}{5} + k, \quad k \in \mathbb{R}.$$
3. $$\int \cos^2 x \sin^2 x \, dx = \int \frac{1 + \cos(2x)}{2} \frac{1 - \cos(2x)}{2} \, dx = \int \frac{1 - \cos^2(2x)}{4} \, dx = \frac{1}{4} \int \left(1 - \frac{1 + \cos(4x)}{2}\right) \, dx = \frac{1}{4} \int \left(\frac{1}{2} - \frac{1}{2}\cos(4x)\right) \, dx = \frac{1}{8}x - \frac{1}{32}\sin(4x) + k, \quad k \in \mathbb{R}.$$

##### Integrazione delle funzioni razionali fratte
Sia $f$ una funzione razionale fratta: $$f(x) = \frac{a(x)}{b(x)} \text { funzione 1.1 } $$con $a, b$ polinomi primi fra loro, effettuando la divisione fra $a$ e $b$ si ottengono due polinomi $q$ e $r$ quest'ultimo avente grado minore di quello di $b$ tali che: $$f(x) = q(x)+\frac{r(x)}{b(x)}$$Quindi per integrare una qualsiasi funzione razionale fratta basta integrare un polinomio e una funzione razionale fratta propria, ossia una funzione razionale fratta in cui il grado del numeratore è minore di quello del denominatore.

Supponiamo che la funzione $1.1$ sia una funzione razionale fratta propria, e sia $m$ il grado del polinomio $b$, possiamo affermare che:
- $b(x) = 0$ ha $m$ soluzioni reali o complesse
	- Data $\alpha$ una soluzione reale con una sua molteplicità $n$ allora $b(x)$ è divisibile per $(x-\alpha)^n$ 
	- Dato $k+ic$ una soluzione complessa con molteplicità $n$ (anche il suo coniugato $k-ic$ lo sarà) allora $b(x)$ è divisibile per $$[x-(k+ic)]^n[x-(k-ic)]^n = [(x-k)^2+c^2]^n$$
Dunque il polinomio $b$ si decompone nel prodotto di fattori del tipo $(x-\alpha)^n$ e fattori del tipo $[(x-k)^2+c^2]^n$ cioè nel prodotto di potenze di polinomi di primo grado e di potenze di polinomi di secondo grado con discriminante negativo. A questo punto si dimostra che è possibile decomporre la funzione razionale $f$ nella somma di funzioni razionali (le **fratte semplici**) che sono del tipo:
- Ogni $b$ del tipo $(x-\alpha)^n$ dà luogo ad $n$ fratti semplici del tipo: $$\frac{A}{(x-\alpha)^n} \text{ funzione 1.2 }$$$$ \frac{A_1}{x-\alpha}, \frac{A_2}{(x-\alpha)^2}, \dots, \frac{A_n}{(x-\alpha)^n} $$
- Ogni fattore del tipo $[(x-k)^2+c^2]^n$ dà luogo ad $n$ fratti semplici del tipo: $$\frac{A_1x+B_1}{(x-k)^2+c^2} \text{ funzione 1.3 }$$
  $$ \frac{A_1 x + B_1}{(x-k)^2 + c^2}, \frac{A_2 x + B_2}{[(x-k)^2 + c^2]^2}, \dots, \frac{A_n x + B_n}{[(x-k)^2 + c^2]^n}. $$
**Esempio 9**
Presa una funzione razionale fratta con denominatore nella forma: $$x^3(x-2)(x^2+5)(x^2+1)^2$$i suoi fratti semplici saranno:
$$\frac{A_1}{x}, \frac{A_2}{x^2}, \frac{A_3}{x^3}, \frac{A_4}{x-2}$$e
$$ \frac{C_1 x + B_1}{x^2+5}, \frac{C_2 x + B_2}{x^2+1}, \frac{C_3 x + B_3}{(x^2+1)^2} $$
Praticamente l'integrazione di una funzione razionale fratta propria viene ricondotta all'integrazione dei suoi fratti semplici


###### Come integrare un fratto semplice

**Integrazione dei fratti semplici del primo tipo (1.2):**
Osserviamo che grazie alla proprietà di omogeneità possiamo supporre $A = 1$, il nostro fratto diventa:$$I_n = \int \frac{1}{(x-c)^n} dx$$
Se $n = 1$ si ha $$I_1 = \int \frac{1}{\underbrace{x-c}_{f(x)}} \cdot \underbrace{1}_{f'(x)} dx = \text{ e quindi per la regola di integrazione } = \log |x-c|+k$$Se $n>1$ si ha $$I_n = \int (x-c)^{-n} dx = \frac{(x-c)^{-n+1}}{-n+1} = \frac{1}{-n+1} \frac{1}{(x-c)^{n-1}}+k$$
**Integrazione dei fratti semplici del secondo tipo (1.3)**:
Tratteremo solo i casi con $n=1$ e $n=2$, poniamo quindi:
$$I_n = \int \frac{A_1x+B_1}{(x-k)^2+c^2}$$
*Primo caso:* $n=1$ 
Grazie al primo teorema di integrazione per sostituzione possiamo supporre $k=0$ quindi abbiamo che $$I_1 = \int \frac{A_1x+B_1}{x^2+c^2} dx \text{ decomponendo in somma: } A \int \frac{x}{x^2+c^2} dx + B \int \frac{1}{x^2+c^2} dx.$$
Supponendo $A = B = 1$, consideriamo i due in modo separato per semplicità:
1. $$ \int \frac{x}{x^2+c^2} dx = \frac{1}{2} \int \frac{2x}{x^2+c^2} dx = \frac{1}{2} \log(x^2+c^2) + k; $$
2. $$\int \frac{1}{x^2+c^2} dx = \int \frac{1}{c^2 \left[ \left(\frac{x}{c}\right)^2 + 1 \right]} dx = \frac{1}{c} \int \frac{1}{c \left[ \left(\frac{x}{c}\right)^2 + 1 \right]} dx = \\
= \frac{1}{c} \left[ \int \frac{1}{t^2+1} dt \right]_{t=\frac{x}{c}} = \frac{1}{c} \arctan \frac{x}{c} + k$$dato che la derivata di $\frac{x}{c} è {1}{c}$

*Secondo caso:* $n=2$
Anche questa volta possiamo supporre che $A=B=1$ e $k = 0$ quindi si ha che: $$\int \frac{x+1}{(x^2+c^2)^2} dx = I_1+I_2$$dove $I_1$ e $I_2$ sono: $$I_1 = \int \frac{x}{(x^2+c^2)^2} dx, \quad I_2 = \int \frac{1}{(x^2+c^2)^2} dx.$$
1. $$ I_1 = \frac{1}{2} \int \frac{2x}{(x^2+c^2)^2} dx = \frac{1}{2} \left[ \int \frac{1}{t^2} dt \right]_{t=x^2+c^2} = -\frac{1}{2} \frac{1}{x^2+c^2} + k $$
2. Per determinare $I_2$ procediamo come abbiamo visto nell'esempio $5$ relativo all'integrazione per parti: $$I_2 = \frac{1}{c^2} \int \frac{c^2}{(x^2+c^2)^2} dx = \frac{1}{c^2} \int \frac{x^2+c^2-x^2}{(x^2+c^2)^2} dx = \\ \frac{1}{c^2} \int \frac{1}{x^2+c^2} dx + \frac{1}{c^2} \int \frac{-x^2}{(x^2+c^2)^2} dx.$$il primo è stato già studiato nel caso $n=1$, per il secondo invece osserviamo che $\frac{1}{x^2+c^2}$ è $\frac{-2x}{(x^2+c^2)^2}$ quindi è possibile procedere per parti: $$\int \frac{-x^2}{(x^2+c^2)^2} dx = \frac{1}{2} \int x \cdot \frac{-2x}{(x^2+c^2)^2} dx = \frac{1}{2} \frac{x}{x^2+c^2} - \frac{1}{2} \int \frac{1}{x^2+c^2} dx.$$e anche in questo caso ci riconduciamo al caso di $n=1$

Con le considerazioni fatte finora, siamo in grado di integrare una funzione del tipo: $$f(x) = \frac{ax+b}{x^2+px+q}$$
Posto $\Delta = p^2 - 4q$ e da qui distinguiamo tre casi:
1. $\Delta > 0$: in questo caso il trinomio al denominatore ha due zeri reali e distinti $x_1$, $x_2$ e si ha $x^2+px+q = (x-x_1)(x-x_2)$ e quindi cerchiamo $A$ e $B$ tali che:
   $$\frac{ax+b}{x^2+px+q} = \frac{A}{x-x_1}+\frac{B}{x-x_2}$$
   Si deve risolvere il sistema $$\big \{^{A+B \ = \ a}_{-x_2A-x_1B \  = \ b} $$che ammette una sola soluzione in quanto il determinante dei coefficienti vale $x_2-x_1 \not = 0$ quindi ci si riconduce al caso $1.2$ 
2. $\Delta = 0$:  in questo caso il trinomio al denominatore ha un solo zero $x_0$ di molteplicità $2$ e si ha: $x^2+px+q = (x-x_0)^2$, procedendo come nel caso precedente si determinano due numeri $A$ e $B$ tali che: $$\frac{ax+b}{x^2+px+q} = \frac{A}{x-x_0} + \frac{B}{(x-x_0)^2}.$$in questo modo ci si riconduce nuovamente al caso $1.2$
3. $\Delta < 0$: in questo caso si utilizza il metodo del complemento dei quadrati: $$x^2 + px + q = x^2 + px + \frac{p^2}{4} - \frac{p^2}{4} + q = \left(x+\frac{p}{2}\right)^2 + \left(\frac{\sqrt{-\Delta}}{2}\right)^2$$quindi il trinomio al denominatore si scrive nella forma $(x-k)^2+c^2$ e si ha:
   $$ \int f(x) dx = a \int \frac{x}{x^2+px+q} dx + b \int \frac{1}{(x-k)^2+c^2} dx = $$$$ = \frac{a}{2} \int \frac{2x}{x^2+px+q} dx + b \int \frac{1}{(x-k)^2+c^2} dx = $$$$ = \frac{a}{2} \int \frac{2x+p-p}{x^2+px+q} dx + b \int \frac{1}{(x-k)^2+c^2} dx = $$$$ = \frac{a}{2} \int \frac{2x+p}{x^2+px+q} dx + \left( b - \frac{ap}{2} \right) \int \frac{1}{(x-k)^2+c^2} dx = $$$$ = \frac{a}{2} \log(x^2+px+q) + \left( b - \frac{ap}{2} \right) \left[ \int \frac{1}{t^2+c^2} dt \right]_{t=x-k}$$
Ci si riconduce quindi al caso $1.3$

###### Valanga di esempi:
**Esempio 10**: Determiniamo $$I = \int \frac{x+4}{x^2-x-6} dx$$si ha: $$x^2-x-6 = (x-3)(x+2)$$
quindi i fratti semplici saranno del tipo: $$\frac{A}{x-3} \ , \frac{B}{x+2}$$cerchiamo di determinare $A, B$: $$\frac{x+4}{x^2-x-6} = \frac{A}{x-3}+\frac{B}{x+2} = \frac{(A+B)x + 2A -3B}{x^2-x-6}$$quindi deve essere $A+B = 1$, $2A-3B = 4$ e quindi troviamo che $$A = \frac{7}{5}, \ B = -\frac{2}{5}$$sostituendo nei fratti semplici e integrando otteniamo che: $$I = \frac{7}{5}\log |x-3|- \frac{2}{5} \log |x+2| +k$$
**Esempio 11**: Determiniamo $$\int \frac{x+4}{x^2-2x+1} dx$$in questo caso i fratti semplici sono del tipo: $$\frac{A}{x-1}, \ \frac{B}{(x-1)^2}$$si trova $A = 1$ e $B = 5$ quindi l'integrale richiesto risulta essere: $$|x-1|-\frac{5}{x-1}+k$$
 **Esempio 12**: Determiniamo $$I = \int \frac{x+4}{x^2+x+4} dx$$il denominatore ha discriminante negativo, quindi si procede nel seguente modo: $$I = \frac{1}{2} \int \frac{2x+8}{x^2+x+4} dx = \frac{1}{2} \int \frac{2x+1}{x^2+x+4} dx + \frac{1}{2} \int \frac{7}{x^2+x+4} dx = $$$$
= \frac{1}{2} \log(x^2+x+4) + \frac{7}{2} \int \frac{dx}{\left(x+\frac{1}{2}\right)^2 + \frac{15}{4}} = $$$$
= \frac{1}{2} \log(x^2+x+4) + \frac{7}{\sqrt{15}} \arctan \frac{2}{\sqrt{15}} \left(x+\frac{1}{2}\right) + k$$
**Esempio 13**: Determiniamo
$$I = \int \frac{x+3}{(x^2+4)^2}dx$$ e quindi risulta che:
$$
I = \frac{1}{2} \int \frac{2x+6}{(x^2+4)^2} dx = \frac{1}{2} \left[ \int \frac{dt}{t^2} \right]_{t=x^2+4} + 3 \int \frac{dx}{(x^2+4)^2}
$$
$$
= -\frac{1}{2(x^2+4)} + \frac{3}{4} \int \frac{x^2+4-x^2}{(x^2+4)^2} dx
$$
$$
= -\frac{1}{2(x^2+4)} + \frac{3}{4} \int \frac{dx}{x^2+4} - \frac{3}{4} \int \frac{x^2}{(x^2+4)^2} dx
$$
$$
= -\frac{1}{2(x^2+4)} + \frac{3}{4} \int \frac{dx}{x^2+4} - \frac{3}{8} \int x \cdot \frac{2x}{(x^2+4)^2} dx
$$
$$
= -\frac{1}{2(x^2+4)} + \frac{3}{8} \arctan \frac{x}{2} - \frac{3}{8} \left[ x \cdot \left( -\frac{1}{x^2+4} \right) - \int 1 \cdot \left( -\frac{1}{x^2+4} \right) dx \right]
$$
$$
= -\frac{1}{2(x^2+4)} + \frac{3}{8} \arctan \frac{x}{2} - \frac{3}{8} \left[ -\frac{x}{x^2+4} + \int \frac{dx}{x^2+4} \right]
$$
$$
= -\frac{1}{2(x^2+4)} + \frac{3}{8} \arctan \frac{x}{2} + \frac{3x}{8(x^2+4)} - \frac{3}{8} \int \frac{dx}{x^2+4}
$$
$$
= -\frac{1}{2(x^2+4)} + \frac{3}{8} \arctan \frac{x}{2} + \frac{3x}{8(x^2+4)} - \frac{3}{8} \left( \frac{1}{2} \arctan \frac{x}{2} \right) + k
$$
$$
= -\frac{1}{2(x^2+4)} + \left( \frac{3}{8} - \frac{3}{16} \right) \arctan \frac{x}{2} + \frac{3x}{8(x^2+4)} + k
$$
$$
= -\frac{1}{2(x^2+4)} + \frac{3}{16} \arctan \frac{x}{2} + \frac{3x}{8(x^2+4)} + k.
$$

**Esempi 14**: questi sono esempi in cui la funzione razionale fratta non è propria, in questi casi la funzione deve essere decomposta nella somma di un polinomio e di una funzione razionale fratta propria: 
- *Casi con trasformazioni semplici*:
	1. $$\int \frac{x+1}{2x+3} dx = \frac{1}{2} \int \frac{2x+2}{2x+3} dx = \frac{1}{2} \int \frac{2x+3-1}{2x+3} dx = \\ \frac{1}{2} \int \left( 1-\frac{1}{2x+3} \right) dx.$$
	2. $$ \int \frac{x^4}{x^2+1} dx = \int \frac{x^4-1+1}{x^2+1} dx = \int \left( \frac{x^4-1}{x^2+1} + \frac{1}{x^2+1} \right) dx = \\ \int \left( x^2-1 + \frac{1}{x^2+1} \right) dx. $$
	3. $$ \int \frac{x^2 + 2}{x - 5}\,dx  = \int \frac{x^2 - 25 + 25 + 2}{x - 5}\,dx  = \int \left( x + 5 + \frac{27}{x - 5} \right)\,dx$$
- *Casi dove la trasformazione viene fatta effettuando la divisione fra il numeratore e il denominatore*
	1. $$ \int \frac{x^3}{x^2 + 2}\,dx  = \int \left( x + \frac{-2x}{x^2 + 2} \right)\,dx $$
	2. $$ \int \frac{x^4 + 1}{x^3 - 2}\,dx = \int \left( x + \frac{3x + 1}{x^3 - 2} \right)\,dx $$

###### Integrazione per razionalizzazione
Grazie al primo teorema di integrazione per sostituzione è possibile ricondurre alcuni integrali a quelli di funzioni razionali fratte. Di seguito degli esemp:
1. $$\int \frac{e^x}{e^x + 1} dx = \left[ \int \frac{1}{t+1} dt \right]_{t=e^x} = \log(e^x + 1) + k$$
2. $$\int \frac{e^{2x} + 4e^x}{e^{2x} + 1} dx = \int e^x \frac{e^x + 4}{e^{2x} + 1} dx = \left[ \int \frac{t+4}{t^2 + 1} dt \right]_{t=e^x}$$
   qui abbiamo osservato che è presente il fattore $D(e^x) = e^x$. Se esso non è presente basta moltiplicare il numeratore e il denominatore per $e^x$ come nell'esempio successivo
3. $$\int \frac{dx}{e^x + 3} = \int \frac{e^x}{e^{2x} + 3e^x} dx = \left[ \int \frac{dt}{t^2 + 3t} \right]_{t=e^x}$$
4. $$\int \frac{\tan x}{\tan x + 1} dx = \int \frac{\tan x (\tan^2 x + 1)}{(\tan x + 1)(\tan^2 x + 1)} dx = \left[ \int \frac{t}{(t+1)(t^2+1)} dt \right]_{t=\tan x}$$
   qui abbiamo moltiplicato numeratore e denominatore per $tan^2x+1$ che è la derivata di $\tan x$ 
###### Teorema 6 (secondo teorema di integrazione per sostituzione)
Siano $f: (a, b) \rightarrow R$ una *funzione dotata di primitive*, $g: (c, d) \rightarrow R$ una funzione  derivabile e tale che $Im(g) = (a,b)$. Se $g$ è *invertibile* si ha:
**Dimostrazione**: Dal primo teorema di integrazione per sostituzione segue che:
$$\int f(g(t))g'(t) dt = \big [ \int f(x) \  dx \big]$$componendo ambo i membri con $t = g^{-1}(x)$

**Esempio 15**: di seguito degli esempi di applicazione del teorema appena dimostrato
1. Determinare $$\int \sqrt{x+3} \ dx$$si ha che $(a,b) = [-3, +\infty[$ è ci poniamo come obbiettivo quello di porre $\sqrt{x+3} = t$. Si deve scegliere dunque $(c, d) = [0, +\infty[$ $g(t) = t^2-3$. Si prova subito che tutte le ipotesi del teorema sono soddisfatte e in particolare si ha: $$g'(t) = 2t, \\ g^{-1}(x) = \sqrt{x+3}$$quindi $$\int \sqrt{x+3} dx = \Big [ \int t \times 2t \ dt \Big ]_{t = \sqrt{x+3}} = \frac{2}{3}(\sqrt{x+3})^3 + k$$
2. Sia $$f(x) = \sqrt{\frac{px+q}{rx+s}}$$con $ps-qr \not = 0$ una funzione definita in un intervallo $(a, b)$ in cui il radicando è non negativo. La sostituzione da fare in questo caso è $$t = \sqrt{\frac{px+q}{rxs+s}}$$con $t \ge 0$ si ha allora
   $$g(t) = \frac{st^2-q}{p-rt^2}, \ g'(t) = \frac{2(ps-qr)t}{(p-rt^2)^2}$$
   Poiché $g'$ ha sempre segno costante, la funzione $g$ è invertibile. Applicando il secondo teorema di integrazione per sostituzione si ottiene: $$\int f(x) \ dx \Big[ \int \frac{2(ps-qr)t^2}{(p-rt^2)^2} \ dt \Big]_{t = \sqrt{\frac{px+q}{rx+s}}}$$che è l'integrale di una funzione razionale.
3. Di seguito un caso particolare: ![[Pasted image 20251026110341.png]]

##### Integrale definito secondo Riemann
Ricordiamo che dati due insiemi numerici $A$ e $B$ se: $$a \le b \ \forall \ a \in A, \forall b \in B$$si dice che $A$ e $B$ sono **separati** e in quel caso si può provare che $\sup A \le \inf B$ e tutti gli elementi $c \in [\sup A, \inf B]$ sono detti *elementi di separazione*. Se $\sup A = \inf B$ l'elemento di separazione è unico e gli insiemi $A$ e $B$ sono detti **contigui**.

Si può provare che $A$ e $B$ sono contigui se e solo se per ogni $\epsilon > 0$ esistono $a\in A$ e $b \in B$ tali che $b-a < \epsilon$ 

**Definizione 3**: Chiameremo **decomposizione** di $[a, b]$ ogni insieme di punti: $$D = \{x_0;x_1;\dots,x_{n-1}; x_n\}$$
tali che: $$a = x_0 < x_1 < \dots < x_{n-1}<x_n = b$$
- i punti $x_0,x_1,\dots,x_n$ sono detti *capisaldi della decomposizione*
- Il numero $$|D| = max\{(x_1-x_0), (x_2-x_1), \dots , (x_n-x_{n-1})\}$$si chiama *ampiezza di D*

> [!EXAMPLE] Esempio
> Se consideriamo l'intervallo $[0,10]$, una possibile decomposizione D potrebbe essere:
> $$D=\{0;2;5;10\}$$
> Qui i capisaldi sono $x_0​=0, x_1​=2, x_2​=5, x_3​=10$ con $|D| = 5$. 

Sia $D = \{x_0;x_1;\dots,x_{n-1}; x_n\}$ una delle decomposizioni di $[a,b]$. Poiché $f$ è continua in ognuno degli intervalli $[x_{i-1}, x_i]$ (con $i = 1,\dots,n$) è ivi dotata di massimo e minimo assoluto. Formalmente scriveremo che: per ogni $i = 1, \dots, n$ siano $y_i, z_i \in [x_{i-1}, x_i]$ tali che: $$f(y_i) = \min_{[x_{i-1}, x_i]}f, \ f(z_i) = \max_{[x_{i-1}, x_i]}f$$

**Definizione 4**: le quantità :
- *Somma inferiore* della funzione $f$ relativa a $D$ $$s(f, D) = \Sigma^{n}_{i=1}f(y_i)(x_i-x_{i-1})$$
- *Somma superiore* della funzione $f$ relativa a $D$ $$S(f, D) = \Sigma^{n}_{i=1}f(z_i)(x_i-x_{i-1})$$
Al variare della decomposizione $D$, queste somme descrivono due insiemi numeri $\underline{S}$ (insieme di tutte le possibili somme inferiori) e $\overline{S}$ (insieme di tutte le possibili somme superiori) su questi due insiemi possiamo dire che:
- Date due composizioni $D_1, D_2$ si ha che $$s(f,D_1) \le S(f, D_2)$$ cioè gli insiemi $\underline{S} \text{ e } \overline{S}$  sono separati
- Sapendo che sono separati sappiamo sicuramente che $\sup \underline{S} \le \inf \overline{S}$ 

**Teorema 7**: Gli insiemi $\underline{S}$ e $\overline{S}$ sono contigui
**Dimostrazione**: Dobbiamo dimostrare che $$\forall \epsilon > 0, \ \exists D \text{ decomposizione di } [a, b] \text{ tale che } S(D) - s(D) < \epsilon $$
Fissiamo $\epsilon > 0$ essendo $f$ una funzione continua in $[a, b]$ per il teorema di Cantor essa è uniformemente continua in $[a,b]$, scriviamo di seguito la definizione di *uniformemente continua* in $\frac{\epsilon}{b-a}$ e troviamo che: $$\exists \delta > 0 \text{ tale che } x,y \in [a,b], [x-y] < \epsilon \Rightarrow |f(x)-f(y)| < \frac{\epsilon}{b-a} \text{ (1.4) }$$Costruiamo una decomposizione $D$ di $[a, b]$ tale che $|D| < \delta$. 
- $x_0, x_1, \dots, x_{n-1}, x_n$ i capisaldi di questa decomposizione
- $y_i, z_i \in [x_{i-1}, x_i]$ i punti di minimo e massimo assoluto di $f$ in $[x_{i-1}, x_i]$ 
Dato che $|D| < \delta$ si ha $|z_i - y_i| < \delta$ quindi usando la $(1.4)$ per tale coppia di punti vale la disuguaglianza $$f(z_i)-f(y_i) = |f(z_i) - f(y_i)| < \frac{\epsilon}{b-a}$$si ha allora che: $$S(D)-s(D) = \Sigma^{n}_{i = 1}(f(z_i)- f(y_i))(x_i-x_{i-1}) < \sum_{i=1}^{n} \frac{\varepsilon}{b-a} (x_i - x_{i-1}) = $$$$ \frac{\varepsilon}{b-a} \sum_{i=1}^{n} (x_i - x_{i-1}) =$$$$ \frac{\varepsilon}{b-a} (b-a) = \varepsilon.$$
In virtù del teorema precedente gli insiemi $\underline{S} \text{ e } \overline{S}$ sono contigui e $\sup \underline{S} = \inf \overline{S}$ è il loro unico elemento di separazione

**Definizione 5**: il numero $$\int_{a}^{b} f(x)\ dx = \sup \underline{S} = \inf \overline{S}$$e si chiama *integrale definito (secondo Riemann)* di $f$ in $[a,b]$

**Esempio 16**: consideriamo la funzione costante: $$f(x) = k \forall \in [a, b]$$qualunque sia la decomposizione $D$ scelta, si ha subito$$s(f, D) = S(f, D) = k(b-a)$$quindi$$\int^b_a k \ dx = k(b-a)$$
Osserviamo che se $k>0$ il valore dell'integrale risulta uguale all'area del rettangolo $$\{(x,y) \in R^2: a \le x \le b, 0 \le y \le f(x)\}$$
**Osservazione 3**: Il valore dell'integrale dipende da $f$, da $a$ e da $b$ non cambia cambiando il nome della variabile di integrazione $$\int^b_a f(x) \ dx = \int^b_a f(t) \ dt = \dots$$
Sia $f$ una funzione continua in un intervallo $(\alpha, \beta)$ e siano $a,b \in (\alpha, \beta)$ Se $a<b$ abbiamo già definito l'integrale definito $$\int^b_a f(x) dx$$che si generalizza nel caso in cui $a \ge b$ nel seguente modo:
$$\int^b_a f(x) dx = \Big \{^{0 \quad \quad \quad \quad \quad  \ \text{ se } a = b}_{- \int^a_b f(x) \ dx  \quad \quad \text{ se } a > b}$$
 
 
 
##### Proprietà dell'integrale definito
Di seguito le principali proprietà dell'integrale definito:
- *Proprietà additiva*: se $f$ è una funzione continua in $(\alpha, \beta)$ allora $$\int^b_a f(x) \ dx = \int^c_a f(x) \ dx + \int^b_c f(x) \ dx$$ qualunque siano i punti $a,b,c \in (\alpha, \beta)$
- *Proprietà distributiva*: se $f,g$ sono continue in $(\alpha, \beta), a,b \in (\alpha, \beta) \text{ e } c_1, c_2 \in R$ si ha: $$\int_a^b (c_1 f(x) + c_2 g(x)) dx = c_1 \int_a^b f(x) dx + c_2 \int_a^b g(x) dx.$$
- *Proprietà della media*: Sia $f$ continua in $[a,b]$. Posto $m = \min_{[a,b]}f$ e $M = \max_{[a,b]} f$ si ha $$m(b-a) \leq \int_a^b f(x) dx \leq M(b-a).$$
  inoltre esiste $c \in [a,b]$ tale che: $$\int^b_a f(x) dx = f(c)(b-a)$$
  la prima proprietà della media segue dalla definizione di integrale usando la decomposizione $D = \{a;b\}$. Per ottenere la seconda basta osservare che: $$m \leq \frac{\int_a^b f(x) dx}{b - a} \leq M$$ e applicare la proprietà dei valori intermedi alla funzione $f$ 
- *Prima proprietà di monotonia*: Sia $f$ continua in $[a,b]$ e tale che $f(x)\ge 0$ per ogni $x \in [a,b]$, allora si ha: $$\int^b_a f(x) \ dx \ge 0$$
  l'eguaglianza si ha se e solo se $f$ è identicamente nulla. Questa proprietà si può provare usando quella della media e osservando che $m \ge 0$, da questo risultato applicando la proprietà distributiva segue subito la seconda proprietà 
- *Seconda proprietà di monotonia*: Siano $f, g$ continue in $[a, b]$ e tali che $f(x)\le g(x)$ per ogni $x \in [a,b]$. Allora si ha $$\int^b_a f(x) \ dx \le \int^b_a g(x) \ dx$$
- *Proprietà con il valore assoluto*: Siano $f$ continua in $[a,b]$ allora: $$|\int^b_a f(x) \ dx| \le \int^b_a |f(x)| \ dx$$
##### Funzione integrale
Sia $f: (\alpha, \beta) \rightarrow R$ una funzione continua e sia $x_0 \in (\alpha, \beta)$. Per ogni $x \in (\alpha, \beta)$ l'integrale definito $$\int^{x_0}_x f(t) \ dt$$è un numero (che dipende da $x$) possiamo quindi considerare la funzione $F: (\alpha, \beta) \rightarrow R$ definita mediante la legge: $$F(x) = \int^{x_0}_x f(t) \ dt, \ \forall x \in (\alpha, \beta)$$La funzione $F$ si chiama *funzione integrale di f di punto iniziale $x_0$*, ovviamente $F(x_0) = 0$ 
**Teorema 8**: Siano $f(\alpha, \beta) \rightarrow R$ una funzione continua e $x_0, x_1 \in (\alpha, \beta)$. Se $F$ e $G$ sono due funzioni integrali di punti iniziale $x_0$ e $x_1$ rispettivamente, allora esiste $c \in R$ tale che: $$F(x) = G(x)+c \ \forall x \in (\alpha, \beta)$$
**Dimostrazione**: Per definizione di funzione integrale si ha: $$F(x) = \int_{x_0}^x f(t) dt, \quad G(x) = \int_{x_1}^x f(t) dt, \quad \forall x \in (\alpha, \beta)$$Usando la proprietà additiva, dell'integrale definito otteniamo che:
$$F(x) = \int_{x_0}^x f(t) dt = \int_{x_0}^{x_1} f(t) dt + \int_{x_1}^x f(t) dt = G(x) + \int_{x_0}^{x_1} f(t) dt$$