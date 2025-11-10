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
Siano $a,  f$ due funzioni reali definite nell'intervallo $(\alpha, \beta)$. L'equazione del primo ordine: $$y'(x)+a(x)y(x) = f(x) \quad (3.2)$$si dice *lineare*. Essa è il problema di determinare funzioni reali definite in un intervallo $I \subseteq (\alpha, \beta)$ derivabili e tali che si abbia: $$y'(x)+a(x)y(x) = f(x) \quad \forall x \in I$$
Si può provare che se le funzioni $a$ e $f$ sono continue in $(\alpha, \beta)$ l'equazione $3.2$ ammette soluzioni definite in $(\alpha, \beta)$. D'ora in avanti assumeremo che $a$ e $f$ siano funzioni continue con tutto quello che ne consegue.

Chiameremo **integrale generale** l'insieme di tutte le soluzioni, ogni soluzione $y$ potrà essere chiamata *integrale particolare*.

Se la funzione $f$ è identicamente nulla ($f(x) = 0 \quad \forall x \in R$), l'equazione è detta *omogenea*;

L'equazione omogenea associata alla $3.2$ è $$y' = -a(x)y$$
##### Risoluzione equazione omogena associata alla 3.2
> [!Check]
> la funzione identicamente nulla in $(\alpha, \beta)$ è soluzione.![[Screenshot_20251109_114108_Samsung capture.jpg|500]]

Sia $y$ una soluzione che non assume mai il valore $0$. Essendo una funzione continua essa ha sempre lo stesso segno. Si ha, per ogni $x \in$ $(\alpha, \beta)$. 
$$y' = -a(x)y \quad (3.3)$$
$$\frac{y'(x)}{y(x)} = -a(x)$$
notiamo subito che il primo membro di quest'eguaglianza è la derivata di $log |y(x)|$. 
Indichiamo ora con $A$ una primitiva della funzione $a(x)$ ($A$ è una qualsiasi funzione che derivata di da $a(x)$) possiamo osservare che le funzioni $log |y(x)|$ e $-A(x)$ hanno la stessa derivata quindi differiscono per una costante. Si ottiene: $$\log|y(x)| = -A(x)+c$$da cui facilmente $$y(x) = k e^{-A(x)} \quad (3.4)$$con $k \in R$. Per $k = 0$ si ottiene la funzione nulla che avevamo trovato prima, per $k>0$ si ottengono soluzioni positive e per $k<0$ soluzioni negative. La $3.4$ fornisce dunque tutte e sole le soluzioni dell'equazione omogenea.

![[Screenshot_20251109_123724_Samsung capture.jpg|500]]

Esaminiamo ora l'equazione completa. Applichiamo **il metodo di Lagrange della variazione della costante**: praticamente cerchiamo una soluzione del tipo: $$\overline y(x) = k(x)e^{-A(x)}, x \in (\alpha, \beta)$$cioè una funzione che abbia la stessa forma della $3.4$ ma in cui al posto della costante $k$ ci sia una funzione derivabile $k(x)$. 
Imponendo che:
- $\overline y$ sia soluzione della $3.2$
- $A'(x) = a(x) \quad \forall x \in (\alpha, \beta)$ 
si ottiene:
$$
\underbrace{k'(x)e^{-A(x)}-A'(x)k(x)e^{-A(x)}}_{\text{Derivata di } \overline y(x)}
\quad + \ 
\underbrace{a(x)}_{\text{Termine noto}}
\underbrace{k(x)e^{-A(x)}}_{\text{y(x)}}
= f(x)
$$da cui $$k'(x) = f(x)e^{(A(x))} \quad \forall x \in (\alpha, \beta)$$
quindi la funzione $k$ viene determinata in quanto primitiva della funzione $f(x)e^{A(x)}$. In questo modo abbiamo determinato un integrale particolare $\overline y$ della $3.2$. Di seguito i risultati che ci consentiranno di determinare tutte le soluzioni dell'equazione $3.2$. 

##### Teorema 1
Se $y$ una soluzione dell'equazione $3.2$ e $z$ una soluzione dell'equazione $3.3$ allora la funzione somma $y+z$ è soluzione dell'equazione $3.2$ 
**Dimostrazione**: Basta osservare che posto $w = y+z$, $w$ è derivabile in $(\alpha, \beta)$ e si ha:$$w'(x)+a(x)w(x) = (y'(x)+a(x)y(x)) + (z'(x)+a(x)z(x)) = f(x) + 0 = 0$$
##### Teorema 2
Se $y$ e $z$ sono due soluzioni dell'equazione $3.2$ allora la funzione differenza $y-z$ è soluzione dell'equazione $3.3$
**Dimostrazione**: anche in questo caso posto $w = y-z$, la funzione $w$ è derivabile in $(\alpha, \beta)$ e si ha:$$w'(x)+a(x)w(x) = (y'(x)+a(x)y(x)) - (z'(x)+a(x)z(x)) = f(x) - f(x) = 0$$
###### Conseguenze
Da queste due proposizione segue che tutte e sole le soluzioni dell'equazione $3.2$ si ottengono sommando una soluzione della $3.2$ alle soluzioni della $3.3$; tenendo conto della $3.4$ possiamo concludere che l'integrale generale della $3.2$ è dato da $$y(x) = \overline y(x)+k e^{-A(x)}, k \in R$$ 
### Equazioni lineari di ordine n

Sia $n \in N$ e siano date $n+1$ funzioni reali continue nel medesimo intervallo $(\alpha, \beta)$ siano esse $a_1, a_2, \dots, a_n f$. L'equazione differenziale lineare di ordine $n$ che ha la forma: $$y^{(n)}+a_1(x)y^{(n-1)}+ \dots + a_{n-1}(x)y' + a_n(x)y = f(x) \quad (3.5)$$è il problema della ricerca di funzioni reali $y$ definite in $(\alpha, \beta)$ derivabili $n$ volte e tali che $$y^{(n)}(x) + a_1(x)y^{(n-1)}(x) + \dots + a_{n-1}(x)y'(x) + a_n(x)y(x) = f(x) \quad \forall x \in (\alpha, \beta)$$Come nel caso precedente:
- Chiameremo *integrale generale dell'equazione differenziale* l'insieme delle sue soluzioni
- Un soluzione viene anche chiamata *integrale particolare*
- le funzioni $a_i$ sono dette *coefficienti dell'equazione* 
- funzione $f$ *termine noto*
- Se $f$ è identicamente nulla, l'equazione è detta *omogenea*
Di seguito l'omogenea associata alla $3.5$ avente i suoi stessi coefficienti e il termine noto nullo:
$$ y^{(n)} + a_1(x)y^{(n-1)} + \dots + a_{n-1}(x)y' + a_n(x)y = 0 \quad (3.6)$$
Nel paragrafo precedente abbiamo studiato il caso particolare $n=1$, i risultati ottenuti ci saranno utili per studiare il caso generale, si hanno intanto alcuni risultati preliminari:
##### Teorema 3 (teorema di esistenza e unicità)
Il problema di Cauchy associato all'equazione $3.5$ ammette una ed una sola soluzione definita in $(\alpha, \beta)$ 

##### Proposizioni 
###### Proposizione 1 
Se $y$ è una soluzione dell'equazione $3.5$ e $z$ soluzione della $3.6$ allora la funzione somma $y+z$ è soluzione dell'equazione $3.5$
###### Proposizione 2
Se $y$ e $z$ sono due soluzioni della $3.5$ allora la funzione differenza $y-z$ è soluzione dell'equazione $3.6$
###### Proposizione 3
Se $y$ e $z$ due soluzioni dell'equazione $3.6$ allora ogni loro combinazione lineare $hy(x)+kz(x) (h,k \in R)$ è soluzione della $3.6$
###### Proposizione 4 (principio di sovrapposizione)
dati:
- $y$ soluzione dell'equazione $y^{(n)} + a_1(x)y^{(n-1)}+ \dots a_n(x) y = f(x)$
- $z$ soluzione dell'equazione $y^{(n)}+a_1(x)y^{(n-1)}+\dots a_n(x) y = g(x)$ 
- $c_1, c_2$ sono due numeri reali
allora la funzione $c_1y+c_2z$ è una soluzione dell'equazione $$y^{(n)}+a_1(x)y^{(n-1)}+\dots a_n(x) y = c_1f(x)+c_2g(x)$$ Se il termine noto dell'equazione è una funzione a valori complessi nasce la proposizione di seguito
###### Proposizione 5
Supponiamo che il termine noto dell'equazione $3.5$ sia una funzione a valori complessi $f(x) = u(x)+iv(x)$. Allora la funzione complessa $y(x) = w(x)+iz(x)$ è soluzione dell'equazione $3.5$ se e solo se:
- $w$ soluzione di $y^{(n)} + a_1(x)y^{(n-1)} + \dots + a_{n-1}(x)y' + a_n(x)y = u(x)$
- $z$ soluzione di  $y^{(n)} + a_1(x)y^{(n-1)} + \dots + a_{n-1}(x)y' + a_n(x)y = v(x)$

> [!WARNING] Osservazione 1
> Dalla proposizione 4, e dal fatto evidente che la funzione identicamente nulla è soluzione della $3.6$ considerato con le usuali operazioni di somma fra funzioni e di prodotti di funzioni per un numero, è uno spazio vettoriale. 

###### Proposizione 6
ci proponiamo adesso di determinare l'integrale generale della $3.6$. A tale scopo siano $y_1, \dots y_n$ $n$soluzioni della $3.6$. Introduciamo il seguente determinante: $$W(x) = \begin{vmatrix}
y_1(x) & y_2(x) & \dots & y_n(x) \\
y'_1(x) & y'_2(x) & \dots & y'_n(x) \\
\dots & \dots & \dots & \dots \\
y_1^{(n-1)}(x) & y_2^{(n-1)}(x) & \dots & y_n^{(n-1)}(x)
\end{vmatrix}$$
detto *wronskiano delle soluzioni*. Si verifica una e una sola delle seguenti affermazioni:
- a) $W(x)$ è identicamente nulla (il determinante è zero per ogni valore di $x$)
- b) $W(x) \not = 0$ per ogni $x \in (\alpha, \beta)$

**Linea dimostrativa**: Si prova che $W(x)$ è soluzione dell'equazione differenziale $y'+a_1(x)y = 0$ le cui soluzioni sono del tipo $y(x) = ke^{-A(x)}$ con $A$ primitiva di $a_1$, quindi sono identicamente nulle ($k = 0$) o sempre diverse di da zero.

*Per brevità lo proviamo solo nel caso n = 2.* 
In tal caso si ha: $$
W(x) =
\begin{vmatrix}
y_1(x) & y_2(x) \\
y_1'(x) & y_2'(x)
\end{vmatrix}
= y_1(x)\,y_2'(x) - y_2(x)\,y_1'(x)
$$
quindi tenendo conto del fatto che $y_1$ e $y_2$ sono soluzioni della $3.6$:
$$ W'(x) = y'_1(x)y'_2(x) + y_1(x)y''_2(x) - y'_1(x)y'_2(x) - y''_1(x)y_2(x) = $$$$ = y_1(x) \left( -a_1(x)y'_2(x) - a_2(x)y_2(x) \right) - y_2(x) \left( -a_1(x)y'_1(x) - a_2(x)y_1(x) \right) = $$$$ = a_1(x) \left( -y_1(x)y'_2(x) + y_2(x)y'_1(x) \right) =$$ $$= -a_1(x)W(x) $$
Quindi possiamo scrivere che: $$W'(x) = -a_1 W(x) \rightarrow W'(x)+a_1W(x) = 0$$
visto che siamo riusciti a dimostrare che $W'(x)+a_1​(x)W(x)=0$ allora  $W(x)$ è soluzione di $y'+a_1​(x)y=0$
##### Definizione 1
le soluzioni $y_1, \dots y_n$ sono dette indipendenti se si ha $W(x) \not = 0 \quad \forall x \in (\alpha, \beta)$ 
###### Teorema 4
Un'equazione differenziale lineare di ordine $n$ omogenea ha sempre $n$ soluzioni indipendenti
**Dimostrazione**: Fissiamo ad arbitrio $x_0 \in (\alpha, \beta)$ e consideriamo $n$ problemi di Cauchy, l'i-mo dei quali è $$(P_i) \quad \begin{cases}
y^{(n)} + a_1(x)y^{(n-1)} + \dots + a_n(x)y = 0 \\
y^{(i)}(x_0) = 1 \\
y^{(j)}(x_0) = 0, \quad j \neq i
\end{cases}$$
Per il teorema di esistenza e unicità, $P_i$ ammette un'unica soluzione $y_i$. Consideriamo le $n$ soluzioni così ottenute, il loro wronskiano, calcolato in $x_0$ è:
$$W(x_0) = \begin{vmatrix}
1 & 0 & \dots & 0 \\
0 & 1 & \dots & 0 \\
\dots & \dots & \dots & \dots \\
0 & 0 & \dots & 1
\end{vmatrix} = 1$$
dalla definizione 1 e dalla proposizione 4 segue che $y_1, \dots y_n$ sono indipendenti

###### Teorema 5
Siano $y_1, \dots, y_n$ $n$ soluzioni indipendenti dell'equazione $3.6$, allora tutte e sole le soluzioni dell'equazione $3.6$ sono le funzioni del tipo: $$\sum_{i=1}^{n} k_i y_i(x), \quad k_i \in \mathbb{R}.$$
**Dimostrazione**: Che una combinazione lineare di soluzione sia una soluzione è già stato affermato dalla Proposizione 4. Proviamo il viceversa. Sia $y$ una soluzione della $3.6$ scelto ad arbitrio $x_0 \in (\alpha, \beta)$ consideriamo il problema di Cauchy
$$\begin{cases}
y^{(n)} + a_1(x)y^{(n-1)} + \dots + a_n(x)y = 0 \\
y(x_0) = \overline{y(x_0)} \\
\dots \\
y^{(n-1)}(x_0) = \overline{y(x_0)}
\end{cases}
\quad (3.7)$$
del quale la funzione $\overline y$ è evidentemente una soluzione. Dato inoltre che le soluzioni sono indipendenti, il sistema lineare di $n$ equazione nelle $n$ incognite $k_1, \dots, k_n$ 
$$\begin{cases}
k_1 y_1(x_0) + k_2 y_2(x_0) + \dots + k_n y_n(x_0) = \overline{y}(x_0) \\
k_1 y'_1(x_0) + k_2 y'_2(x_0) + \dots + k_n y'_n(x_0) = \overline{y}'(x_0) \\
\dots \\
k_1 y_1^{(n-1)}(x_0) + k_2 y_2^{(n-1)}(x_0) + \dots + k_n y_n^{(n-1)}(x_0) = \overline{y}^{(n-1)}(x_0)
\end{cases}$$
ha un'unica soluzione $(k_1, \dots, k_n)$ e la funzione $$w(x) = \sum_{i=1}^{n} k_i y_i(x)$$è soluzione del problema di Cauchy $3.7$. Per l'unicità della soluzione si ha $\overline y = w$. Abbiamo in tal modo provato che, data una n-pla di soluzioni indipendenti, ogni altra soluzione della $3.6$ è una loro combinazione lineare, come si voleva.
> [!WARNING] Osservazione 2
> Ricordiamo ora che $n$ elementi $v_1, \dots, v_n$ di uno spazio vettoriale si dicono linearmente indipendenti se l'unica loro combinazione lineare $\Sigma^n_{i=1}k_iv_i$ nulla è quella in cui $k_i = 0 \forall i = 1, \dots, n$. Si può provare che le soluzioni $y_1, \dots, y_n$ della $3.6$ sono indipendenti se e solo se sono linearmente indipendenti. Dal teorema 5 segue che lo spazio vettoriale delle soluzione ha dimensione $n$

###### Teorema 6
Siano $y_1, \dots, y_n$ $n$ integrali indipendenti dell'equazione omogenea $3.6$ e sia $\overline y$ un integrale particolare dell'equazione completa $3.5$. Allora l'integrale generale dell'equazione completa è dato da: $$y(x) = \overline{y} + \sum_{i=1}^{n} k_i y_i(x) : k_i \in \mathbb{R}$$**Dimostrazione**: La tesi segue dal teorema 5 e dalla proposizione 1.

### Equazioni lineari a coefficienti costanti
