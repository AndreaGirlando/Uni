Materiale di riferimento:
- [[3104 fondamenti-di-analisi-dati/file-condivisi/sitoWeb/appunti/Modulo-1/10_extending_regression.pdf|10_extending_regression.pdf]]
- [[3104 fondamenti-di-analisi-dati/file-condivisi/sitoWeb/slide/Modulo-1/10_extending_regression.pdf|slide]]

### Termini di interazione
#### Modello additivo
Nella regressione lineare multipla, il modello *additivo* descrive la risposta sommando i contributi dei singoli regressori. Consideriamo la relazione tra l'efficienza del carburante `mpg`, la potenza del motore `horsepower` e il peso dell'automobile `weight`: $$mpg=\beta_0+\beta_1horsepower+\beta_2weight+\epsilon$$
In questo modello, un incremento unitario di `horsepower` è associato a una variazione media di `mpg` pari a $\beta_1$, mantenendo costante `weight`. Questa variazione è la stessa per qualsiasi peso dell'automobile: *l'effetto della potenza non dipende dal peso*.
Analogamente, un incremento unitario di `weight` è associato a una variazione media di `mpg` pari a $\beta_2$, indipendentemente dal valore di `horsepower`.
L'additività impone quindi che ciascun regressore abbia un contributo separato, che non viene modificato dal valore degli altri regressori.

#### Modello con interazione
Un *termine di interazione* permette di rappresentare una situazione in cui l'effetto di un regressore sulla risposta dipende dal valore di un altro regressore. Nel caso di `horsepower` e `weight`, introduciamo il loro prodotto: $$mpg=\beta_0+\beta_1horsepower+\beta_2weight+\beta_3(horsepower\cdot weight)+\epsilon$$
Il termine aggiunto è il prodotto tra *due variabili*, non tra due coefficienti. Il coefficiente $\beta_3$ determina quanto cambia l'effetto di una variabile al variare dell'altra.
Raccogliendo i termini che contengono `horsepower`, possiamo riscrivere il modello come: $$mpg=(\beta_0+\beta_2weight)+(\beta_1+\beta_3weight)horsepower+\epsilon$$
A peso fissato, la relazione tra `horsepower` e `mpg` è ancora una retta, ma la sua pendenza è: $$\beta_1+\beta_3weight$$
A un dato peso, un incremento unitario di `horsepower` è associato a una variazione media di `mpg` pari a $\beta_1+\beta_3\,weight$. Questa variazione è diversa a seconda del peso considerato.
L'interpretazione dei coefficienti diventa:
- $\beta_0$ è il valore medio previsto di `mpg` quando entrambi i regressori valgono zero.
- $\beta_1$ è l'effetto di un incremento unitario di `horsepower` quando `weight` vale zero; non rappresenta più una pendenza valida per qualsiasi peso.
- $\beta_2$ è l'effetto di un incremento unitario di `weight` quando `horsepower` vale zero.
- $\beta_3$ indica di quanto cambia la pendenza rispetto a `horsepower` quando `weight` aumenta di un'unità.

Il modello non è più additivo nei regressori originali, ma *rimane lineare nei coefficienti*. Definendo una nuova variabile $Z=horsepower\cdot weight$, possiamo infatti scriverlo come: $$mpg=\beta_0+\beta_1horsepower+\beta_2weight+\beta_3Z+\epsilon$$
Possiamo quindi stimare i coefficienti con gli stessi minimi quadrati ordinari utilizzati nella regressione lineare multipla. Di seguito dei risultati sul dataset MPG usato due modelli diversi:
![[11 - 5 novembre 2020-1.png]]
$$
$$
Il miglioramento dell'adattamento deve essere esaminato anche attraverso i residui, definiti come la differenza tra risposta osservata e risposta prevista: $e_i=y_i-\widehat y_i$ Confrontiamo i grafici del modello additivo con quelli del modello con interazione:
![[11 - 5 novembre 2020-2.png|center|505]]
- Nel grafico *residuals vs. fitted* del modello additivo compare una curvatura: i residui non sono distribuiti attorno a zero senza un andamento sistematico. Con il termine di interazione, la linea che descrive l'andamento dei residui diventa molto più vicina a una linea orizzontale attorno a zero.
- Nel *Q-Q plot* confrontiamo i quantili dei residui con quelli di una distribuzione normale. Nel modello con interazione molti punti seguono la retta di riferimento, ma rimangono scostamenti, soprattutto nella coda inferiore.

L'interazione permette quindi di descrivere meglio la struttura della relazione, pur senza eliminare tutte le imperfezioni del modello.

### Regressione quadratica
Un altro modo per descrivere una relazione non lineare consiste nell'introdurre potenze di un regressore. Consideriamo nuovamente `horsepower` come unico regressore: all'aumentare della potenza, `mpg` tende a diminuire, ma l'andamento dei dati presenta una curvatura che una retta non riesce a seguire adeguatamente.
La *regressione quadratica* aggiunge al termine lineare il quadrato del regressore: $$mpg=\beta_0+\beta_1horsepower+\beta_2horsepower^2+\epsilon$$
Questo modello descrive una parabola anziché una retta. È *non lineare rispetto a `horsepower`*, ma rimane *lineare rispetto ai coefficienti* $\beta_0,\beta_1,\beta_2$ (sono tutti di grado uno).
Definendo $Z=horsepower^2$, possiamo infatti riscriverlo come: $$mpg=\beta_0+\beta_1horsepower+\beta_2Z+\epsilon$$
La stima si riconduce quindi a una regressione lineare multipla con due colonne di regressori: `horsepower` e `horsepower` al quadrato.

#### Interpretazione dei coefficienti
Poniamo $x=horsepower$ e indichiamo con $f(x)$ la componente deterministica del modello: $$f(x)=\beta_0+\beta_1x+\beta_2x^2$$
Nel modello lineare semplice, $\beta_1$ rappresenta una variazione costante della risposta per ogni incremento unitario del regressore. Nel modello quadratico questo non vale più, perché quando cambia $x$ cambia anche $x^2$.
Per ricavare la variazione associata al passaggio da $x$ a $x+1$, calcoliamo: $$\begin{aligned}f(x+1)-f(x)&=\left[\beta_0+\beta_1(x+1)+\beta_2(x+1)^2\right]-\left[\beta_0+\beta_1x+\beta_2x^2\right]\\&=\beta_1+\beta_2\left[(x+1)^2-x^2\right]\\&=\beta_1+\beta_2(2x+1)\end{aligned}$$
La variazione dipende quindi dal valore iniziale di $x$: un incremento unitario di potenza non produce la stessa variazione media di `mpg` per tutte le automobili.
La *pendenza locale* della curva si ottiene invece mediante la derivata: $$f'(x)=\beta_1+2\beta_2x$$
Possiamo quindi interpretare i coefficienti nel seguente modo:
- $\beta_0$ è il valore medio previsto della risposta quando $x=0$.
- $\beta_1$ è la pendenza della curva nel punto $x=0$, non una pendenza costante.
- $\beta_2$ determina la curvatura e il modo in cui la pendenza cambia al variare di $x$.

La derivata seconda rende esplicito il ruolo del termine quadratico: $$f''(x)=2\beta_2$$
Se $\beta_2>0$, la parabola ha concavità verso l'alto e la pendenza aumenta al crescere di $x$. Se $\beta_2<0$, ha concavità verso il basso e la pendenza diminuisce.
Non possiamo interpretare $\beta_2$ come l'effetto di una variazione di $x^2$ mantenendo costante $x$: *le due quantità derivano dalla stessa variabile e cambiano insieme*.


### Regressione polinomiale
La regressione quadratica è un caso particolare della *regressione polinomiale*. In generale, scegliendo un grado $d$, includiamo le potenze del regressore fino a quel grado: $$Y=\beta_0+\beta_1X+\beta_2X^2+\cdots+\beta_dX^d+\epsilon=\beta_0+\sum_{j=1}^{d}\beta_jX^j+\epsilon$$
Il grado stabilisce la potenza massima presente nel modello. Per un solo regressore, un polinomio di grado $d$ contiene $d+1$ coefficienti da stimare, contando anche l'intercetta.
Per stimarlo, costruiamo le variabili trasformate $Z_1=X$, $Z_2=X^2$, fino a $Z_d=X^d$. Il modello diventa: $$Y=\beta_0+\beta_1Z_1+\cdots+\beta_dZ_d+\epsilon$$
La curva può quindi essere non lineare rispetto a $X$, mentre la stima rimane un problema di regressione lineare nei coefficienti, risolvibile con i minimi quadrati ordinari.

#### Polinomio di grado quattro
Per descrivere la relazione tra `mpg` e `horsepower` con un polinomio di grado quattro, utilizziamo: $$mpg=\beta_0+\beta_1horsepower+\beta_2horsepower^2+\beta_3horsepower^3+\beta_4horsepower^4+\epsilon$$
La stima e la rappresentazione della curva si ottengono aggiungendo le nuove potenze alla formula:
```python
model_polynomial = smf.ols(
    'mpg ~ horsepower + I(horsepower**2) + '
    'I(horsepower**3) + I(horsepower**4)',
    data=mpg
).fit()

b0, b1, b2, b3, b4 = model_polynomial.params.values

sns.scatterplot(x='horsepower', y='mpg', data=mpg)

x = np.linspace(40, 240, 200)
y = b0 + b1*x + b2*x**2 + b3*x**3 + b4*x**4

plt.plot(x, y, 'r')
plt.show()
```
Rispetto alla parabola, il polinomio di grado quattro ha una maggiore flessibilità: i termini cubico e di quarto grado permettono di modificare ulteriormente l'andamento della curva.

#### Regressione polinomiale con più regressori
Quando abbiamo più regressori, un modello polinomiale comprende anche prodotti tra variabili diverse, cioè *termini di interazione*.
Partendo da un modello additivo con due regressori: $$Y=\beta_0+\beta_1X_1+\beta_2X_2+\epsilon$$
il modello polinomiale completo di grado due diventa: $$Y=\beta_0+\beta_1X_1+\beta_2X_2+\beta_3X_1^2+\beta_4X_2^2+\beta_5X_1X_2+\epsilon$$
I termini aggiunti hanno ruoli differenti:
- $X_1^2$ e $X_2^2$ permettono di rappresentare curvature rispetto ai singoli regressori.
- $X_1X_2$ permette all'effetto di un regressore di dipendere dal valore dell'altro.

Il termine $X_1X_2$ ha grado totale due, perché gli esponenti delle due variabili si sommano. Anche in questo caso basta aggiungere alla matrice dei regressori le colonne contenenti quadrati e prodotti, per poi stimare i coefficienti tramite OLS.
Aumentando il numero dei regressori, cresce anche il numero di termini necessari per costruire un modello polinomiale di un dato grado.

#### Grado del polinomio, bias e varianza
Aumentando il grado aumentiamo la flessibilità della curva. Un polinomio di grado $d\geq1$ ha una derivata di grado $d-1$, quindi può avere *al massimo $d-1$ punti stazionari*. Un grado maggiore consente di rappresentare andamenti più articolati, ma introduce anche più coefficienti da stimare.
Questa maggiore flessibilità deve essere bilanciata con la stabilità del modello:
- Un grado troppo basso può impedire di rappresentare la struttura della relazione. Il modello rimane troppo rigido e presenta un *bias elevato*.
- Un grado molto alto può portare il modello a seguire anche le particolarità del campione utilizzato per la stima. Piccole variazioni dei dati possono allora produrre curve molto diverse, aumentando la *varianza*.

Nel secondo caso, il modello si adatta molto ai dati osservati, ma la curva ottenuta può descrivere male un nuovo campione della stessa popolazione: questo comportamento è detto *overfitting*.
L'obiettivo non è quindi aumentare indefinitamente il grado, ma scegliere una flessibilità sufficiente a rappresentare la relazione senza rendere il modello eccessivamente dipendente dal campione. La scelta del grado esprime il *compromesso tra bias e varianza*.

### Regressione logistica multinomiale
La regressione logistica binaria descrive una risposta categoriale con due possibili valori. Quando la variabile dipendente presenta più di due categorie, utilizziamo la *regressione logistica multinomiale*: a partire dai regressori, continui o categoriali, il modello permette di calcolare la probabilità di appartenenza a ciascuna categoria.
Per costruire il modello scegliamo una *classe di riferimento*, detta anche *baseline*. Le altre classi vengono descritte attraverso il confronto con questa categoria.

#### Diabetes Dataset
Il *Diabetes Dataset* contiene misurazioni cliniche di 145 soggetti, utilizzate per studiare il metabolismo del glucosio e la resistenza all'insulina. Le variabili disponibili sono:

| Variabile | Significato |
| --- | --- |
| `relwt` | Peso relativo, cioè rapporto tra peso effettivo e peso atteso. |
| `glufast` | Livello di glucosio plasmatico a digiuno. |
| `glutest` | Intolleranza al glucosio, misurata attraverso l'area del test orale di tolleranza al glucosio. |
| `instest` | Risposta insulinica, misurata attraverso l'area del test dell'insulina. |
| `sspg` | Glucosio plasmatico allo stato stazionario, una misura della resistenza all'insulina. |
| `group` | Gruppo diagnostico: `Normal`, `Chemical_Diabetic` oppure `Overt_Diabetic`. |

La risposta `group` ha tre categorie. Scegliamo `Normal` come classe di riferimento, in modo da descrivere ciascuno dei due gruppi diabetici rispetto ai soggetti normali.
Carichiamo i dati e rappresentiamo le relazioni tra le variabili distinguendo i gruppi mediante il colore:
```python
import statsmodels.api as sm
import statsmodels.formula.api as smf
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

diabetes_data = sm.datasets.get_rdataset('Diabetes', 'heplots').data
print(diabetes_data.head())

sns.pairplot(diabetes_data, hue='group')
plt.show()
```
Il pairplot permette di osservare come si distribuiscono i tre gruppi rispetto alle misurazioni disponibili:
![[11 - 5 novembre 2020 - gruppi Diabetes.png]]

#### Modello di regressione logistica multinomiale
Nella regressione logistica binaria modelliamo il logaritmo degli *odds*, cioè del rapporto tra la probabilità della classe 1 e quella della classe 0: $$\log\left(\frac{P(Y=1\mid\mathbf x)}{1-P(Y=1\mid\mathbf x)}\right)=\beta_0+\beta_1x_1+\cdots+\beta_nx_n$$
Con più di due categorie, il *complemento* della probabilità di una classe comprende tutte le altre classi. Per confrontare separatamente ogni categoria con la baseline, modelliamo invece il logaritmo del rapporto tra le loro probabilità. Indichiamo con $K$ il numero di classi e, nella formulazione generale, scegliamo la classe $Y=1$ come riferimento. Per ogni classe $k=2,\ldots,K$ scriviamo: $$\log\left(\frac{P(Y=k\mid\mathbf x)}{P(Y=1\mid\mathbf x)}\right)=\beta_{k0}+\beta_{k1}x_1+\cdots+\beta_{kn}x_n$$
Ogni classe diversa dalla baseline ha quindi una propria combinazione lineare dei regressori e un proprio insieme di coefficienti. Non stimiamo una combinazione aggiuntiva per la baseline, perché il logaritmo del rapporto della sua probabilità con sé stessa è zero: $$\log\left(\frac{P(Y=1\mid\mathbf x)}{P(Y=1\mid\mathbf x)}\right)=\log(1)=0$$
Con $n$ regressori, ogni confronto richiede $n+1$ coefficienti, contando l'intercetta. Poiché i confronti sono $K-1$, il numero totale di parametri è: $$(n+1)(K-1)$$in pratica sono: $K-1$ regressioni logistiche con ognuna che ha $n+1$ parametri

#### Probabilità delle classi
Per passare dai rapporti di probabilità alle probabilità delle singole classi, indichiamo con $p_k(\mathbf x)=P(Y=k\mid\mathbf x)$ la probabilità della classe $k$ e con $\eta_k(\mathbf x)$ la sua combinazione lineare: $$\eta_k(\mathbf x)=\beta_{k0}+\beta_{k1}x_1+\cdots+\beta_{kn}x_n$$
Applicando l'esponenziale alla relazione del modello, otteniamo: $$\frac{p_k(\mathbf x)}{p_1(\mathbf x)}=e^{\eta_k(\mathbf x)}\quad\Longrightarrow\quad p_k(\mathbf x)=p_1(\mathbf x)e^{\eta_k(\mathbf x)}$$
Le probabilità di tutte le classi devono sommare a uno. Sostituendo l'espressione precedente nella somma, ricaviamo: $$1=p_1(\mathbf x)+\sum_{l=2}^{K}p_l(\mathbf x)=p_1(\mathbf x)\left(1+\sum_{l=2}^{K}e^{\eta_l(\mathbf x)}\right)$$
La probabilità della classe di riferimento è quindi: $$P(Y=1\mid\mathbf x)=\frac{1}{1+\sum_{l=2}^{K}e^{\eta_l(\mathbf x)}}$$
Per ogni altra classe, sostituendo questo risultato nel rapporto iniziale, otteniamo: $$P(Y=k\mid\mathbf x)=\frac{e^{\eta_k(\mathbf x)}}{1+\sum_{l=2}^{K}e^{\eta_l(\mathbf x)}},\qquad k=2,\ldots,K$$
Possiamo esprimere la combinazione lineare anche in forma vettoriale, includendo l'intercetta mediante una prima componente uguale a uno: $$\widetilde{\mathbf x}=(1,x_1,\ldots,x_n)^T,\qquad\boldsymbol\beta_k=(\beta_{k0},\beta_{k1},\ldots,\beta_{kn})^T,\qquad\eta_k(\mathbf x)=\boldsymbol\beta_k^T\widetilde{\mathbf x}$$
Una volta stimati i coefficienti, queste formule permettono di calcolare tutte le probabilità per una nuova osservazione.

#### Interpretazione dei coefficienti
Il coefficiente $\beta_{kj}$ descrive il confronto tra la classe $k$ e la baseline. Mantenendo costanti gli altri regressori, un incremento unitario di $x_j$ aumenta di $\beta_{kj}$ il logaritmo del rapporto tra le due probabilità. Sulla scala dei rapporti, questo corrisponde a una moltiplicazione per $e^{\beta_{kj}}$: $$\frac{p_k(\mathbf x')}{p_1(\mathbf x')}=e^{\beta_{kj}}\frac{p_k(\mathbf x)}{p_1(\mathbf x)},\qquad x'_j=x_j+1$$
Tutte le altre componenti di $\mathbf x'$ rimangono uguali a quelle di $\mathbf x$. Possiamo distinguere tre casi:
- Se $\beta_{kj}>0$, il rapporto tra la probabilità della classe $k$ e quella della baseline aumenta.
- Se $\beta_{kj}<0$, il rapporto diminuisce.
- Se $\beta_{kj}=0$, il rapporto non cambia.

L'intercetta $\beta_{k0}$ è il logaritmo del rapporto quando tutti i regressori valgono zero; il rapporto corrispondente è $e^{\beta_{k0}}$. L'interpretazione riguarda quindi un *confronto con la classe di riferimento*, non una variazione diretta della probabilità della singola classe.

### Interpretazione geometrica dei coefficienti di un regressore logistico
I coefficienti della regressione logistica possono essere interpretati anche dal punto di vista geometrico. Nella regressione lineare cerchiamo una curva che descriva i valori della risposta; nella classificazione logistica possiamo invece studiare la *decision boundary* che separa le regioni assegnate alle diverse classi.
Consideriamo il caso binario con osservazioni bidimensionali $\mathbf x=(x_1,x_2)\in\mathbb R^2$. Il modello assegna alla classe 1 la probabilità: $$P(Y=1\mid\mathbf x)=\frac{1}{1+e^{-(\beta_0+\beta_1x_1+\beta_2x_2)}}$$
Supponiamo che i coefficienti stimati siano $\widehat\beta_0=-3.47$, $\widehat\beta_1=1.17$ e $\widehat\beta_2=1.43$. La probabilità stimata è quindi: $$\widehat P(Y=1\mid\mathbf x)=\frac{1}{1+e^{-(-3.47+1.17x_1+1.43x_2)}}$$

#### Dalle probabilità alla classificazione
Per assegnare un'osservazione a una classe, utilizziamo la soglia $0.5$: $$\widehat y=\begin{cases}1&\text{se }\widehat P(Y=1\mid\mathbf x)\geq0.5,\\0&\text{altrimenti.}\end{cases}$$
Questa regola sceglie la classe con la probabilità stimata maggiore, perché nel caso binario $P(Y=0\mid\mathbf x)=1-P(Y=1\mid\mathbf x)$.
La frontiera decisionale è l'insieme dei punti per i quali le due classi hanno la stessa probabilità: $$P(Y=1\mid\mathbf x)=P(Y=0\mid\mathbf x)=0.5$$
Per ricavare la sua equazione, imponiamo questa condizione nella funzione logistica: $$\begin{aligned}\frac{1}{1+e^{-(\beta_0+\beta_1x_1+\beta_2x_2)}}=\frac12&\Longleftrightarrow1+e^{-(\beta_0+\beta_1x_1+\beta_2x_2)}=2\\&\Longleftrightarrow e^{-(\beta_0+\beta_1x_1+\beta_2x_2)}=1\\&\Longleftrightarrow\beta_0+\beta_1x_1+\beta_2x_2=0\end{aligned}$$
L'ultima espressione è l'equazione di una retta nel piano dei regressori (ovvero l'equazione della *decision boundary*). La frontiera dipende quindi dalla combinazione lineare interna alla funzione logistica.

#### Pendenza e intercetta della frontiera decisionale
Esplicitando $x_2$ nell'equazione della retta, con $\beta_2\neq0$, otteniamo: $$x_2=-\frac{\beta_1}{\beta_2}x_1-\frac{\beta_0}{\beta_2}$$
I coefficienti del modello determinano quindi due caratteristiche geometriche:
- Il *coefficiente angolare* della frontiera è $-\beta_1/\beta_2$.
- L'*intercetta* sull'asse $x_2$ è $-\beta_0/\beta_2$.

I singoli coefficienti della regressione logistica non coincidono quindi direttamente con la pendenza e l'intercetta della retta di separazione: queste dipendono dai loro rapporti.
Sostituendo le stime dell'esempio, la frontiera decisionale è: $$-3.47+1.17x_1+1.43x_2=0\quad\Longleftrightarrow\quad x_2=-\frac{1.17}{1.43}x_1+\frac{3.47}{1.43}\approx-0.82x_1+2.43$$
La retta ha pendenza negativa e intercetta circa uguale a $2.43$:
![[11 - 5 novembre 2020 - frontiera logistica.png|center|303]]

#### Regioni di classificazione e linearità
La funzione logistica è crescente e assume valore $0.5$ quando il suo argomento è zero. La regola di classificazione può quindi essere espressa direttamente mediante il segno della combinazione lineare: $$\widehat y=\begin{cases}1&\text{se }\widehat\beta_0+\widehat\beta_1x_1+\widehat\beta_2x_2\geq0,\\0&\text{se }\widehat\beta_0+\widehat\beta_1x_1+\widehat\beta_2x_2<0.\end{cases}$$
Nell'esempio, poiché $\widehat\beta_2=1.43>0$, i punti sopra la retta vengono assegnati alla classe 1 e quelli sotto alla classe 0. Sulla frontiera le probabilità sono uguali e la regola scelta assegna la classe 1.
Con $n$ regressori, la stessa condizione diventa: $$\beta_0+\beta_1x_1+\cdots+\beta_nx_n=0$$
Questa equazione descrive un *iperpiano* nello spazio dei regressori: una retta in due dimensioni, un piano in tre dimensioni e un iperpiano nelle dimensioni superiori.
Il regressore logistico è quindi un *classificatore lineare*, anche se la funzione logistica usata per calcolare le probabilità non è lineare. La non linearità della trasformazione delle probabilità non modifica il fatto che la frontiera decisionale del modello considerato sia definita da un'equazione lineare nei regressori.
