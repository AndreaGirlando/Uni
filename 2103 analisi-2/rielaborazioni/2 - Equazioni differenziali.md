# Equazioni differenziali lineari

### Generalità sulle equazioni differenziali
Siano $A$ un sottoinsieme di $R^{n+1}$ e $F: A \rightarrow R$ una funzione reale definita in $A$. Si dice equazione differenziale di ordine $n$ la funzione $$y^{(n)} = F(x, y, y', \dots, y^{(n-1)}) \quad (3.1)$$il problema di determinare le funzioni $y(x)$ che chiameremo soluzioni o integrali dell'equazione differenziale $$y: (a,b) \rightarrow R, (a,b) ⊆ R$$tali che:
 1. $y(x)$ è derivabile almeno $n$ volte in $(a,b)$ 
 2. $(x,y(x),y'(x), \dots, y^{(n)}(x) \in A)$ per ogni $x \in (a,b)$
 3. per ogni $x \in (a,b)$ si ha $$y^{(n)}(x) = F(x,y(x),y'(x), \dots , y^{(n-1)}(x))$$
Data l'equazione differenziale di ordine $n$ e dato un punto di $A$ di coordinate $(x_0,y_0,y'_0, \dots y_0^{(n-1)})$ si chiama **Problema di Cauchy** relativo all'equazione $3.1$ al punto $x_0$ e ai valori iniziali $y_0, \dots, y_0^{(n-1)}$
$$\begin{cases} y^{(n)} = F(x, y, y', \dots, y^{(n-1)}) \\ y(x_0) = y_0 \\ y'(x_0) = y'_0 \\ \quad \dots \\ y^{(n-1)}(x_0) = y_0^{(n-1)} \end{cases} $$
il problema di determinare una soluzione $y$ della $(1)$ tale che:
$$ y(x_0) = y_0 \quad y'(x_0) = y'_0 \quad \dots \quad y^{(n-1)}(x_0) = y_0^{(n-1)} $$
Ad esempio nel caso dell'equazione del primo ordine, il problema di Cauchy è quello di determinare una soluzione che in un punto dato assuma un valore determinato. Nel paragrafo successivo vedremo che sotto opportune ipotesi possiamo garantire l'esistenza, ed eventualmente l'unicità della soluzione per un problema di Cauchy

### Equazioni lineari del primo ordine
Siano $a,  f$ due funzioni reali definite nell'intervallo $(\alpha, \beta)$. L'equazione del primo ordine: $$y'+a(x)y = f(x) \quad (3.2)$$si dice *lineare*. Essa è il problema di determinare funzioni reali definite in un intervallo $I \subseteq (\alpha, \beta)$ derivabili e tali che si abbia: $$y'(x)+a(x)y(x) = f(x) \quad \forall x \in I$$
Si può provare che se le funzioni $a$ e $f$ sono continue in $(\alpha, \beta)$ l'equazione $3.2$ ammette soluzioni definite in $(\alpha, \beta)$. D'ora in avanti assumeremo che $a$ e $f$ siano funzioni continue con tutto quello che ne consegue.

Chiameremo **integrale generale** l'insieme di tutte le soluzioni, ogni soluzione $y$ potrà essere chiamata *integrale particolare*.

Se la funzione $f$ è identicamente nulla ($f(x) = 0 \quad \forall x \in R$), l'equazione è detta *omogenea*;

L'equazione omogenea associata alla $3.2$ è $$y' = -a(x)y$$
###### Risoluzione equazione omogena associata alla 3.2
> [!Check]
> la funzione identicamente nulla in $(\alpha, \beta)$ è soluzione.![[Screenshot_20251109_114108_Samsung capture.jpg|500]]

Sia $y$ una soluzione che non assume mai il valore $0$. Essendo una funzione continua essa ha sempre lo stesso segno. Si ha, per ogni $x \in$ $(\alpha, \beta)$. 
$$y' = -a(x)y$$
$$\frac{y'(x)}{y(x)} = -a(x)$$
notiamo subito che il primo membro di quest'eguaglianza è la derivata di $log |y(x)|$. 
Indichiamo ora con $A$ una primitiva della funzione $a(x)$ ($A$ è una qualsiasi funzione che derivata di da $a(x)$) possiamo osservare che le funzioni $log |y(x)|$ e $-A(x)$ hanno la stessa derivata quindi differiscono per una costante. Si ottiene: $$\log|y(x)| = -A(x)+c$$da cui facilmente $$y(x) = k e^{-A(x)} \quad (3.4)$$con $k \in R$. Per $k = 0$ si ottiene la funzione nulla che avevamo trovato prima, per $k>0$ si ottengono soluzioni positive e per $k<0$ soluzioni negative. La $3.4$ fornisce dunque tutte e sole le soluzioni dell'equazione omogenea.

![[Screenshot_20251109_123724_Samsung capture.jpg|500]]

Esaminiamo ora l'equazione completa. Applichiamo **il metodo di Lagrange della variazione della costante**: praticamente cerchiamo una soluzione del tipo: $$\overline y(x) = k(x)e^{-A(x)}, x \in (\alpha, \beta)$$cioè una funzione che abbia la stessa forma della $3.4$ ma in cui al posto della costante $k$ ci sia una funzione derivabile $k(x)$. 
Imponendo che:
- $\overline y$ sia soluzione della $3.2$
- $A'(x) = a(x) \quad \forall x \in (\alpha, \beta)$ 
si ottiene:
$$k'(x)e^{-A(x)}-A'(x)k(x)e^{-A(x)}+a(x)k(x)e^-A(x) = f(x) \quad \forall x \in (\alpha, \beta)$$da cui $k'(x) = f(x)e^{(A(x))} \quad \forall x \in (\alpha, \beta)$
quindi la funzione $k$ viene determinata in quanto primitiva della funzione $f(x)e^{A(x)}$. In questo modo abbiamo determinato un integrale particolare $\overline y$ della $3.2$. Di seguito i risultati che ci consentiranno di determinare tutte le soluzioni dell'equazione $3.2$. 