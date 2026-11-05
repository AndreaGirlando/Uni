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
Di conseguenza, un incremento unitario di `horsepower`, mantenendo costante il peso, è associato a una variazione media di `mpg` che dipende da `weight`.
L'interpretazione dei coefficienti diventa:
- $\beta_0$ è il valore medio previsto di `mpg` quando entrambi i regressori valgono zero.
- $\beta_1$ è l'effetto di un incremento unitario di `horsepower` quando `weight` vale zero; non rappresenta più una pendenza valida per qualsiasi peso.
- $\beta_2$ è l'effetto di un incremento unitario di `weight` quando `horsepower` vale zero.
- $\beta_3$ indica di quanto cambia la pendenza rispetto a `horsepower` quando `weight` aumenta di un'unità.

L'interazione è simmetrica: raccogliendo invece i termini che contengono `weight`, otteniamo: $$mpg=(\beta_0+\beta_1horsepower)+(\beta_2+\beta_3horsepower)weight+\epsilon$$
La variazione media di `mpg` associata a un incremento unitario del peso è quindi $\beta_2+\beta_3horsepower$.
Il modello non è più additivo nei regressori originali, ma *rimane lineare nei coefficienti*. Definendo una nuova variabile $Z=horsepower\cdot weight$, possiamo infatti scriverlo come: $$mpg=\beta_0+\beta_1horsepower+\beta_2weight+\beta_3Z+\epsilon$$
Possiamo quindi stimare i coefficienti con gli stessi minimi quadrati ordinari utilizzati nella regressione lineare multipla.

#### Stima del modello sull'Auto MPG Dataset
Prepariamo i dati e stimiamo sia il modello additivo sia quello con interazione:
```python
import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
import statsmodels.api as sm
import statsmodels.formula.api as smf

mpg = sns.load_dataset('mpg')
mpg = mpg.drop('name', axis=1)
mpg['horsepower'] = pd.to_numeric(
    mpg['horsepower'], errors='coerce'
)
mpg = mpg.dropna()

model_additive = smf.ols(
    'mpg ~ horsepower + weight',
    data=mpg
).fit()

model_interaction = smf.ols(
    'mpg ~ horsepower * weight',
    data=mpg
).fit()

print(f"Additivo: {model_additive.rsquared_adj:.4f}")
print(f"Con interazione: {model_interaction.rsquared_adj:.4f}")
print(model_interaction.summary().tables[1])
```
Nella sintassi delle formule, `horsepower * weight` include sia i due termini individuali sia il loro prodotto: equivale a `horsepower + weight + horsepower:weight`. Il simbolo `:` identifica il solo termine di interazione.
Il confronto mediante il *coefficiente di determinazione aggiustato* dà i seguenti risultati:

| Modello | $R^2_{\mathrm{adj}}$ |
| --- | --- |
| Additivo: `mpg ~ horsepower + weight` | 0.7049 |
| Con interazione: `mpg ~ horsepower * weight` | 0.7465 |

L'aumento di $R^2_{\mathrm{adj}}$ indica un miglioramento dell'adattamento anche tenendo conto del termine aggiuntivo. Inoltre, il coefficiente di `horsepower:weight` ha un p-value inferiore a $0.001$: il termine di interazione risulta statisticamente significativo.
Il modello stimato è: $$\widehat{mpg}=63.5579-0.2508\,horsepower-0.0108\,weight+5.355\cdot10^{-5}(horsepower\cdot weight)$$
La pendenza rispetto a `horsepower`, a peso fissato, diventa quindi: $$-0.2508+5.355\cdot10^{-5}\,weight$$
Poiché il coefficiente dell'interazione è positivo, aumentando il peso aumenta questa pendenza: *nelle automobili più pesanti, l'effetto della potenza su `mpg` diventa meno negativo*. Non significa che aumentando la potenza aumenti necessariamente l'efficienza, ma che la diminuzione prevista di `mpg` è meno marcata.
Nelle automobili molto pesanti, una maggiore potenza è necessaria anche per il movimento del veicolo; la penalizzazione dell'efficienza associata alla potenza risulta quindi inferiore rispetto a quella di un'automobile leggera.
![[11 - 5 novembre 2020-1.png]]

#### Diagnostica dei residui
Il miglioramento dell'adattamento deve essere esaminato anche attraverso i residui, definiti come la differenza tra risposta osservata e risposta prevista: $$e_i=y_i-\widehat y_i$$
Confrontiamo i grafici del modello additivo con quelli del modello con interazione:
![[11 - 5 novembre 2020-2.png]]
- Nel grafico *residuals vs. fitted* del modello additivo compare una curvatura: i residui non sono distribuiti attorno a zero senza un andamento sistematico. Con il termine di interazione, la linea che descrive l'andamento dei residui diventa molto più vicina a una linea orizzontale attorno a zero.
- Nel *Q-Q plot* confrontiamo i quantili dei residui con quelli di una distribuzione normale. Nel modello con interazione molti punti seguono la retta di riferimento, ma rimangono scostamenti, soprattutto nella coda inferiore.

L'interazione permette quindi di descrivere meglio la struttura della relazione, pur senza eliminare tutte le imperfezioni del modello.

### Regressione quadratica
Un altro modo per descrivere una relazione non lineare consiste nell'introdurre potenze di un regressore. Consideriamo nuovamente `horsepower` come unico regressore: all'aumentare della potenza, `mpg` tende a diminuire, ma l'andamento dei dati presenta una curvatura che una retta non riesce a seguire adeguatamente.
La *regressione quadratica* aggiunge al termine lineare il quadrato del regressore: $$mpg=\beta_0+\beta_1horsepower+\beta_2horsepower^2+\epsilon$$
Questo modello descrive una parabola anziché una retta. È *non lineare rispetto a `horsepower`*, ma rimane *lineare rispetto ai coefficienti* $\beta_0,\beta_1,\beta_2$.
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

#### Stima del modello quadratico
Con `statsmodels` introduciamo il quadrato attraverso `I(horsepower**2)`:
```python
model_quadratic = smf.ols(
    'mpg ~ horsepower + I(horsepower**2)',
    data=mpg
).fit()

print(model_quadratic.summary().tables[1])
```
La funzione `I()` permette di trattare `horsepower**2` come un'operazione aritmetica, aggiungendo al modello una colonna contenente i quadrati dei valori di `horsepower`.
I coefficienti stimati descrivono la seguente curva: $$\widehat{mpg}=56.9001-0.4662\,horsepower+0.0012\,horsepower^2$$
Il coefficiente del termine quadratico è positivo: la pendenza della curva aumenta al crescere della potenza. La diminuzione prevista di `mpg` è quindi più marcata per potenze basse e tende ad attenuarsi per potenze maggiori.
Il confronto con la regressione lineare semplice dà:

| Modello | $R^2$ |
| --- | --- |
| Lineare: `mpg ~ horsepower` | 0.606 |
| Quadratico: `mpg ~ horsepower + I(horsepower**2)` | 0.688 |

Il modello quadratico spiega una quota maggiore della variabilità osservata di `mpg`. Entrambi i modelli hanno una statistica F elevata; inoltre, il coefficiente del termine quadratico risulta significativo, con un p-value inferiore a $0.001$.
Possiamo rappresentare la curva stimata sopra lo scatterplot dei dati:
```python
b0, b1, b2 = model_quadratic.params.values

sns.scatterplot(x='horsepower', y='mpg', data=mpg)

x = np.linspace(40, 240, 200)
y = b0 + b1*x + b2*x**2

plt.plot(x, y, 'r')
plt.show()
```
`np.linspace(40, 240, 200)` costruisce una griglia di valori di potenza sulla quale valutiamo il polinomio stimato. La linea risultante permette di osservare come la parabola segua la curvatura della relazione tra potenza ed efficienza.

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
