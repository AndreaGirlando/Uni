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