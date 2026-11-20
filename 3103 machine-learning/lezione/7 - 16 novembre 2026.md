# Support Vector Machine

Una **Support Vector Machine (SVM) lineare** è un classificatore binario supervisionato. Cerca un iperpiano che separi le classi con il margine più ampio possibile. Quando si ammettono violazioni del margine, il modello le penalizza tramite la **hinge loss**.

## Prodotto scalare e proiezione

Per due vettori non nulli $u,v\in\mathbb R^d$, con angolo $\theta$,

$$
\langle u,v\rangle=\sum_{j=1}^d u_jv_j=\lVert u\rVert\lVert v\rVert\cos\theta.
$$

I vettori sono ortogonali se $\langle u,v\rangle=0$. La **similarità coseno** è il prodotto scalare diviso per il prodotto delle norme. Coincide con il prodotto scalare quando entrambi i vettori hanno norma unitaria.

La proiezione ortogonale di $u$ lungo $v$ è

$$
\operatorname{proj}_v(u)
=\left(\lVert u\rVert\cos\theta\right)\frac{v}{\lVert v\rVert}
=\frac{\langle u,v\rangle}{\langle v,v\rangle}v.
$$

## Iperpiano e regola di classificazione

Il training set contiene coppie $(x_i,y_i)$, con $x_i\in\mathbb R^d$ e $y_i\in\{-1,+1\}$. La funzione $f(x)=\langle w,x\rangle+b$ assegna un **punteggio reale**. La predizione $\hat y(x)$ si ottiene dal suo segno, con una convenzione per il caso $f(x)=0$.

L'**iperpiano di decisione** è $H=\{x:f(x)=0\}$, dove $w\ne 0$ è il vettore normale e $b$ determina lo spostamento dell'iperpiano. Per due punti $x_a,x_b$ su $H$,

$$
0=f(x_a)-f(x_b)=\langle w,x_a-x_b\rangle.
$$

Quindi $w$ è ortogonale a tutte le direzioni dell'iperpiano. Il prodotto $t_i=y_i f(x_i)$ è il **margine funzionale** del punto. Se $t_i>0$, il punto sta dal lato della sua classe. Se $t_i<0$, sta dal lato opposto. Se $t_i=0$, è sulla frontiera.

## Distanza dall'iperpiano

Sia $\bar x$ la proiezione ortogonale di $x$ su $H$. Poiché lo spostamento è lungo la normale, scriviamo $x=\bar x+s\,w/\lVert w\rVert$, dove $s$ è la distanza con segno. Sostituendo in $f$ si ottiene

$$
f(x)=f(\bar x)+s\frac{\langle w,w\rangle}{\lVert w\rVert}
=s\lVert w\rVert.
$$

La distanza di un punto $x$ da $H$ è

$$
\operatorname{dist}(x,H)=\frac{|f(x)|}{\lVert w\rVert}.
$$

Il **margine geometrico rispetto alla classe** di un esempio $(x_i,y_i)$ è $y_i f(x_i)/\lVert w\rVert$.

Con separazione stretta il margine del classificatore è la distanza del punto più vicino,

$$
r=\min_i\frac{y_i f(x_i)}{\lVert w\rVert}.
$$

## Hard margin

Se i dati sono linearmente separabili, esistono $w,b$ per cui $y_i f(x_i)>0$ per tutti gli esempi. Moltiplicare $w$ e $b$ per lo stesso fattore positivo lascia invariati l'iperpiano, il segno delle predizioni e il margine geometrico. Questo consente due normalizzazioni.

| Normalizzazione | Vincolo sui punti | Margine |
| --- | --- | --- |
| Normale unitaria, $\lVert w\rVert=1$ | $y_i f(x_i)\ge r$ | $\min_i y_i f(x_i)$ |
| Margine funzionale minimo pari a $1$ | $y_i f(x_i)\ge 1$ | $1/\lVert w\rVert$ |

Per ottenere la seconda, si dividono sia $w$ sia $b$ per l'attuale minimo positivo $\min_i y_i f(x_i)$. Massimizzare $1/\lVert w\rVert$ equivale a minimizzare $\tfrac12\lVert w\rVert^2$, da cui il problema **hard margin**.

$$
\begin{aligned}
\min_{w,b}\quad &\frac12\lVert w\rVert^2\\
\text{con}\quad &y_i(\langle w,x_i\rangle+b)\ge 1 \qquad (i=1,\dots,N).
\end{aligned}
$$

Gli iperpiani $f(x)=+1$ e $f(x)=-1$ distano ciascuno $1/\lVert w\rVert$ dalla frontiera $f(x)=0$. L'intera fascia misura $2/\lVert w\rVert$. Nel caso hard margin, i **vettori di supporto** si trovano su questi iperpiani e soddisfano $y_i f(x_i)=1$.

## Soft margin

Le **variabili di scarto** (*slack variables*) $\xi_i\ge 0$ consentono di violare i vincoli di margine, per esempio quando le classi si sovrappongono. Il problema **soft margin** è

$$
\begin{aligned}
\min_{w,b,\xi}\quad &\frac12\lVert w\rVert^2+C\sum_{i=1}^N \xi_i\\
\text{con}\quad &y_i f(x_i)\ge 1-\xi_i,\qquad \xi_i\ge 0
\qquad (i=1,\dots,N).
\end{aligned}
$$

Il parametro $C>0$ pesa le violazioni. Un $C$ più grande aumenta il costo degli scarti. Con un $C$ più piccolo il modello accetta più facilmente scarti in cambio di una norma di $w$ minore. Ponendo tutte le $\xi_i=0$ si ritrova il problema hard margin, fattibile quando i dati sono separabili.

## Hinge loss

Per $w,b$ fissati, i vincoli richiedono $\xi_i\ge 0$ e $\xi_i\ge 1-y_i f(x_i)$. Dato che ogni $\xi_i$ ha costo positivo, il valore ottimo è il più piccolo consentito,

$$
\xi_i^\star=\max\{0,1-y_i f(x_i)\}=\ell\big(y_i f(x_i)\big).
$$

La **hinge loss** di un punto con margine funzionale $t=yf(x)$ è

$$
\ell(t)=\max\{0,1-t\}.
$$

La perdita scende con pendenza $-1$ fino a $t=1$ e resta zero da lì in poi.

| Margine funzionale $t=yf(x)$ | Posizione del punto | Perdita |
| --- | --- | --- |
| $t\ge 1$ | Corretto, sul margine o oltre | $0$ |
| $0<t<1$ | Corretto, dentro la fascia | $1-t\in(0,1)$ |
| $t=0$ | Sulla frontiera di decisione | $1$ |
| $t<0$ | Dal lato opposto alla sua classe | $1-t>1$ |

Sostituendo gli scarti ottimi si ottiene la formulazione equivalente senza vincoli espliciti.

$$
\min_{w,b}\left[\frac12\lVert w\rVert^2
+C\sum_{i=1}^N\max\{0,1-y_i(\langle w,x_i\rangle+b)\}\right].
$$

### Esempio

Con $w=(1,0)$ e $b=-1$, la frontiera è $x_1=1$ e gli iperpiani di margine sono $x_1=0$ e $x_1=2$. Per un punto di classe $+1$ in $(\tfrac32,0)$, si ha $t=\tfrac12$. La predizione è corretta e lo scarto minimo vale $\tfrac12$. Per un punto della stessa classe in $(\tfrac12,0)$, si ha $t=-\tfrac12$ e la hinge loss vale $\tfrac32$.

## Ripasso attivo

> [!question]- Perché la distanza contiene il divisore $\lVert w\rVert$?
> Spostarsi di una unità lungo $w/\lVert w\rVert$ cambia $f(x)$ di $\lVert w\rVert$. Dividere il punteggio per questa quantità lo converte in distanza con segno.

> [!question]- Come si passa dal margine massimo all'obiettivo hard margin?
> Si fissa il margine funzionale minimo a $1$. Il margine geometrico diventa $1/\lVert w\rVert$, quindi massimizzarlo equivale a minimizzare $\tfrac12\lVert w\rVert^2$.

> [!question]- Come può un punto classificato correttamente avere perdita positiva?
> Succede quando $0<y_i f(x_i)<1$. Il punto è dal lato giusto, dentro la fascia di margine.

> [!question]- Come si eliminano le variabili di scarto?
> Per ogni punto si sceglie il minimo scarto ammesso dai due vincoli, $\max\{0,1-y_i f(x_i)\}$. Lo si sostituisce nell'obiettivo, conservando il peso $C$.

## Trascrizione

La trascrizione segue l'ordine del quaderno. Ho uniformato gli indici e la tipografia delle formule, descritto gli schizzi e segnalato le letture incerte.

### PDF · Lezione 9 (16 novembre 2026)

**Support Vector Machine (SVM)**

Vogliamo costruire un classificatore del tipo $f:\mathbb R^d\to\{-1,1\}$. Si tratta di una funzione parametrizzata. SVM è un classificatore *supervised*. Crea un problema di ottimizzazione vincolata. Consideriamo un problema dove i dati sono linearmente separabili.

La figura 1 richiama ortogonalità e proiezione. Due vettori sono ortogonali se il loro prodotto scalare fa $0$. Per la proiezione si rimanda alla figura 2. Vogliamo trovare la linea con il più largo margine. Per margine si intende la distanza tra l'iperpiano e il punto più vicino all'iperpiano.

*Nota di notazione.* Il PDF usa $f$ per la predizione binaria. Il quaderno e gli appunti sopra usano $f$ per il punteggio reale da cui si ricava la predizione.

### Quaderno · Pagina 1 · Prodotto scalare e iperpiano

**Machine L. (16 Nov.)** Nel disegno le due classi sono rappresentate da crocette ($-1$) e cerchi ($+1$).

Si considerano $x^{(i)}$ e $x^{(s)}$. Misuriamo la loro similarità col prodotto scalare (o *cosine similarity*).

$$
\langle x^{(i)},x^{(s)}\rangle
=\lVert x^{(i)}\rVert\lVert x^{(s)}\rVert\cos\theta
=\sum_{j=1}^d x_j^{(i)}x_j^{(s)}.
$$

Proiezione di $x^{(i)}$ lungo $x^{(s)}$, nel verso indicato dalla formula.

$$
\lVert x^{(i)}\rVert\cos\theta\,\frac{x^{(s)}}{\lVert x^{(s)}\rVert}
=\frac{\langle x^{(i)},x^{(s)}\rangle}{\langle x^{(s)},x^{(s)}\rangle}x^{(s)}.
$$

$f:\mathbb R^d\to\mathbb R$, con $f(x)=\langle w,x\rangle+b$, $w\in\mathbb R^d$ e $b\in\mathbb R$. Lo schizzo mostra $w$ ortogonale all'iperpiano $\{x\in\mathbb R^d:f(x)=0\}$.

Supponiamo di avere $x_a$ e $x_b$ sull'iperpiano. Si ha $f(x_a)=f(x_b)=0$, quindi

$$
f(x_a)-f(x_b)
=(\langle w,x_a\rangle+b)-(\langle w,x_b\rangle+b)
=\langle w,x_a-x_b\rangle=0.
$$

Si vogliono le seguenti condizioni per le due classi.

$$
\begin{aligned}
\langle w,x^{(i)}\rangle+b &\ge 0 \qquad \text{se } y^{(i)}=1,\\
\langle w,x^{(i)}\rangle+b &< 0 \qquad \text{se } y^{(i)}=-1.
\end{aligned}
$$

### Quaderno · Pagina 2 · Margine e hard margin

Vogliamo quindi $y^{(i)}(\langle w,x^{(i)}\rangle+b)\ge 0$ per ogni $i$. Si introduce un margine $r>0$ lungo la direzione $w/\lVert w\rVert$. Per un punto $x^{(a)}$ dal lato positivo, di proiezione $\bar x^{(a)}$ e a distanza $r$ dall'iperpiano,

$$
x^{(a)}=\bar x^{(a)}+r\frac{w}{\lVert w\rVert}.
$$

Si sceglie $\lVert w\rVert=1$ e si vuole massimizzare $r$ sotto il vincolo $y^{(i)}(\langle w,x^{(i)}\rangle+b)\ge r$ per ogni $i$.

Sappiamo che $\langle w,\bar x^{(a)}\rangle+b=0$ e che $\bar x^{(a)}=x^{(a)}-r\,w/\lVert w\rVert$. Da cui

$$
\begin{aligned}
0&=\left\langle w,x^{(a)}-r\frac{w}{\lVert w\rVert}\right\rangle+b\\
 &=\langle w,x^{(a)}\rangle+b-r\frac{\langle w,w\rangle}{\lVert w\rVert}.
\end{aligned}
$$

Nella riga successiva il quaderno prende $\langle w,x^{(a)}\rangle+b=1$ («per costruzione») e ricava $1-r\lVert w\rVert=0$, dunque $r=1/\lVert w\rVert$. Qui si è passati alla normalizzazione con margine funzionale unitario.

Vogliamo massimizzare $r$, per cui vogliamo una norma di $w$ piccola. Il problema di ottimizzazione passa da $\max_{w,b}1/\lVert w\rVert$ a $\min_{w,b}\tfrac12\lVert w\rVert^2$ con i vincoli di separazione. È noto come **hard margin**.

### Quaderno · Pagina 3 · Scarti e hinge loss

«Da approfondire le *slack variable* per problemi non lineari.»

$$
\min_{w,b,\xi}\ \tfrac12\lVert w\rVert^2+C\sum_{i=1}^N\xi_i,
\qquad
y^{(i)}(\langle w,x^{(i)}\rangle+b)\ge 1-\xi_i,\qquad \xi_i\ge 0.
$$

$C$ è un fattore di rigidità. Se gli scarti tornano a $0$, ritorniamo al problema originale.

**Loss function.** Si riprende $f(x)=\langle w,x\rangle+b$, con $y\in\{-1,1\}$. La *hinge loss* è

$$
\ell(t)=\max\{0,1-t\},
\qquad
t=yf(x)=y(\langle w,x\rangle+b).
$$

> [!note] Schizzo e ultima formula
> Lo schizzo mostra due rami esterni, uno vicino a $-1$ e uno vicino a $1$. La formula scritta per $\ell(t)$ ha un solo cambio di pendenza, in $t=1$. Nell'ultima riga si legge la somma dei termini $\max\{0,1-y^{(i)}(\langle w,x^{(i)}\rangle+b)\}$. Il coefficiente della somma è poco leggibile. La derivazione in [[#Hinge loss]] ricava il fattore $C$ dal problema soft margin scritto sopra.

*Nota di lettura.* Le variabili di scarto si applicano al separatore lineare anche con dati non separabili. La frontiera della formulazione qui sopra è sempre $f(x)=0$.

### Fonti

- PDF introduttivo · Lezione_9_ML.pdf, p. 1.
- Quaderno · Foto del 20 novembre 2026, nell'ordine dei file con suffissi «10.00.15», «10.00.15 (1)» e «10.00.15 (2)».