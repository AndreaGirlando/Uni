Materiale di riferimento:
- [[3104 fondamenti-di-analisi-dati/file-condivisi/sitoWeb/appunti/Modulo-1/09_logistic_regression.pdf|09_logistic_regression.pdf]]
- [[3104 fondamenti-di-analisi-dati/file-condivisi/sitoWeb/slide/Modulo-1/09_logistic_regression.pdf|slide]]

### Regressione logistica
I modelli parametrici descrivono la relazione tra le variabili attraverso un insieme di coefficienti. Una volta stimati questi coefficienti, possiamo effettuare nuove previsioni senza conservare tutti i dati di addestramento: il modello è quindi *compatto* e la previsione è *veloce*.

Questo comportamento si distingue da quello di *K-NN*, che richiede di conservare il training set e cercare i vicini ogni volta che viene classificata una nuova osservazione. Tuttavia, per utilizzare un modello parametrico dobbiamo scegliere una forma adatta alla relazione da rappresentare.

La regressione lineare permette di prevedere una risposta quantitativa a partire da regressori quantitativi o qualitativi. Quando invece la risposta è qualitativa, come una diagnosi con due possibili esiti, dobbiamo costruire un modello adatto a un problema di *classificazione*. La *regressione logistica* affronta questo problema modellando la probabilità che un'osservazione appartenga a una delle due classi.

#### Risposta binaria e limiti della regressione lineare
Consideriamo il *Breast Cancer Wisconsin Dataset*, che contiene 569 osservazioni e 31 colonne: 30 misure ricavate da immagini di campioni di tessuto mammario e una variabile `Diagnosis`, che distingue i casi benigni da quelli maligni.

Codifichiamo la risposta attraverso una variabile binaria: $$Y=\begin{cases}0 & \text{se la diagnosi è benigna,}\\1 & \text{se la diagnosi è maligna.}\end{cases}$$
Inizialmente utilizziamo un solo regressore, `radius1`, che rappresenta una misura del raggio. Nei dati osserviamo una relazione tra questa variabile e la diagnosi:
- Per valori piccoli di `radius1` sono più frequenti i casi benigni.
- Per valori grandi di `radius1` sono più frequenti i casi maligni.

Un primo tentativo consiste nell'applicare una regressione lineare alla risposta codificata: $$\widehat Y=\widehat\beta_0+\widehat\beta_1\,radius1$$
![[10 - 3 novembre 2026-1.png]]
La retta segue la tendenza generale dei dati, ma non rappresenta adeguatamente una risposta binaria. Il modello lineare restituisce valori reali, mentre le classi possibili sono soltanto 0 e 1: $$f:\mathbb R\rightarrow\mathbb R\qquad\text{invece di}\qquad f:\mathbb R\rightarrow\{0,1\}$$
Inoltre, la retta può produrre valori inferiori a 0 o superiori a 1.

Nell'esempio la regressione lineare ha coefficienti statisticamente significativi e un valore di $R^2=0.533$, ma i residui mantengono una struttura legata al regressore. La significatività dei coefficienti non è quindi sufficiente a rendere adatta la forma del modello.

#### Probabilità condizionata
Per conservare un'uscita continua, invece di prevedere direttamente la classe modelliamo la *probabilità condizionata* che la risposta sia uguale a 1: $$p(x)=P(Y=1\mid X=x)$$
Nell'esempio questa quantità è la probabilità di una diagnosi maligna dato il valore osservato di `radius1`: $$P(Diagnosis=1\mid radius1)$$
La risposta osservata rimane binaria, mentre il modello restituisce un valore nell'intervallo $[0,1]$, che esprime la probabilità assegnata alla classe 1.

Non possiamo però utilizzare direttamente una combinazione lineare come probabilità: $$p(x)=\beta_0+\beta_1x$$
Il problema è che la combinazione lineare può ancora assumere valori esterni a $[0,1]$. Serve quindi una trasformazione che mantenga l'uscita nell'intervallo delle probabilità e che si avvicini a 0 o a 1 per valori estremi.

Nel caso considerato vogliamo una curva che assegni probabilità basse di malignità ai raggi piccoli e probabilità alte ai raggi grandi, con una transizione graduale tra le due situazioni.
![[10 - 3 novembre 2026-2.png]]

#### Funzione logistica
La *funzione logistica*, o *sigmoide*, è definita come: $$\sigma(z)=\frac{1}{1+e^{-z}}$$
Questa funzione ha le proprietà necessarie:
- Restituisce valori compresi tra 0 e 1.
- Si avvicina a 0 quando l'argomento diventa molto negativo.
- Si avvicina a 1 quando l'argomento diventa molto positivo.
- È differenziabile, proprietà utile per stimare i coefficienti mediante algoritmi di ottimizzazione.

Le due saturazioni sono descritte dai limiti: $$\lim_{z\to-\infty}\sigma(z)=0,\qquad \lim_{z\to+\infty}\sigma(z)=1$$
Quando l'argomento è nullo, le due classi hanno la stessa probabilità: $$\sigma(0)=\frac{1}{1+e^0}=\frac12$$
La sigmoide permette quindi di trasformare un valore reale in una probabilità, avvicinandosi gradualmente agli estremi 0 e 1.

#### Modello di regressione logistica semplice
Nella *regressione logistica semplice* applichiamo la sigmoide alla combinazione lineare di un solo regressore: $$p(x)=P(Y=1\mid X=x)=\sigma(\beta_0+\beta_1x)=\frac{1}{1+e^{-(\beta_0+\beta_1x)}}$$
La costruzione del modello avviene in due passaggi:
1. Calcoliamo il *predittore lineare* $z=\beta_0+\beta_1x$.
2. Trasformiamo $z$ nella probabilità $p(x)=\sigma(z)$.

Nell'esempio otteniamo: $$P(Diagnosis=1\mid radius1)=\frac{1}{1+e^{-(\beta_0+\beta_1\,radius1)}}$$
La parte $\beta_0+\beta_1x$ rimane lineare, ma la probabilità risultante non è una funzione lineare di $x$.

#### Modello di regressione logistica multipla
Con $n$ regressori estendiamo la combinazione lineare includendo il contributo di tutte le variabili: $$p(\mathbf x)=P(Y=1\mid\mathbf x)=\sigma(\beta_0+\beta_1x_1+\cdots+\beta_nx_n)=\frac{1}{1+e^{-(\beta_0+\beta_1x_1+\cdots+\beta_nx_n)}}$$
Per scrivere il modello in forma compatta includiamo l'intercetta nel vettore dei coefficienti e aggiungiamo una componente costante al vettore dei regressori: $$\boldsymbol\beta=\begin{pmatrix}\beta_0\\\beta_1\\\vdots\\\beta_n\end{pmatrix},\qquad \mathbf x=\begin{pmatrix}1\\x_1\\\vdots\\x_n\end{pmatrix}$$
Il prodotto scalare raccoglie tutti i termini del predittore lineare: $$\boldsymbol\beta^T\mathbf x=\beta_0+\beta_1x_1+\cdots+\beta_nx_n$$
Il modello diventa quindi: $$p(\mathbf x)=f_{\boldsymbol\beta}(\mathbf x)=\sigma(\boldsymbol\beta^T\mathbf x)$$

### Odds e logit
La forma logistica permette di collegare la probabilità a una quantità che dipende linearmente dai regressori. Per ricostruire questo collegamento introduciamo gli *odds*.

#### Odds di un evento
Dato un evento con probabilità $p$, gli *odds* sono il rapporto tra la probabilità che l'evento si verifichi e quella che non si verifichi: $$\operatorname{odds}(p)=\frac{p}{1-p}$$
Se un evento ha probabilità $p=0.3$, ci aspettiamo che si verifichi 3 volte su 10 e che non si verifichi nelle altre 7. I suoi odds sono quindi: $$\operatorname{odds}(0.3)=\frac{0.3}{0.7}=\frac37$$
Gli odds non coincidono con una probabilità: confrontano il verificarsi dell'evento con il suo non verificarsi.
- $\operatorname{odds}(p)<1$: l'evento è meno probabile del suo complemento.
- $\operatorname{odds}(p)=1$: evento e complemento hanno la stessa probabilità, quindi $p=0.5$.
- $\operatorname{odds}(p)>1$: l'evento è più probabile del suo complemento.

Per esempio, odds uguali a 3 indicano che l'evento è tre volte più probabile del suo complemento.

#### Collegamento tra sigmoide e odds
Partiamo dalla probabilità logistica e indichiamo con $z$ il predittore lineare: $$p=\frac{1}{1+e^{-z}}$$
Moltiplicando per il denominatore e isolando il termine esponenziale otteniamo: $$p(1+e^{-z})=1\;\Longrightarrow\;p+pe^{-z}=1\;\Longrightarrow\;pe^{-z}=1-p$$
Dividendo per $p$ e prendendo il reciproco ricaviamo: $$e^{-z}=\frac{1-p}{p}\;\Longrightarrow\;e^z=\frac{p}{1-p}$$
Gli odds della classe 1 sono quindi l'esponenziale del predittore lineare: $$\frac{P(Y=1\mid\mathbf x)}{1-P(Y=1\mid\mathbf x)}=e^{\beta_0+\beta_1x_1+\cdots+\beta_nx_n}$$
![[10 - 3 novembre 2026-3.png]]

#### Logit come funzione lineare dei regressori
Applicando il logaritmo naturale a entrambi i membri otteniamo: $$\log\left(\frac{P(Y=1\mid\mathbf x)}{1-P(Y=1\mid\mathbf x)}\right)=\beta_0+\beta_1x_1+\cdots+\beta_nx_n$$
Il logaritmo degli odds si chiama *log-odds* o *logit*: $$\operatorname{logit}(p)=\log\left(\frac{p}{1-p}\right)$$
La regressione logistica può quindi essere scritta come un modello lineare per il logit: $$\operatorname{logit}(p)=\boldsymbol\beta^T\mathbf x$$
Le tre quantità descrivono lo stesso modello su scale diverse:

| Quantità | Espressione | Relazione con i regressori |
| --- | --- | --- |
| Logit | $\log\left(\frac{p}{1-p}\right)=\boldsymbol\beta^T\mathbf x$ | Lineare |
| Odds | $\frac{p}{1-p}=e^{\boldsymbol\beta^T\mathbf x}$ | Esponenziale |
| Probabilità | $p=\sigma(\boldsymbol\beta^T\mathbf x)$ | Logistica |

La linearità riguarda quindi i *log-odds*, non la probabilità.

### Stima dei coefficienti
Per utilizzare il modello dobbiamo stimare i coefficienti $\boldsymbol\beta$ a partire dai dati.

Anche se il logit è lineare nei regressori, non possiamo applicare direttamente la regressione lineare ai logit delle probabilità osservate: nel campione non conosciamo le vere probabilità $p$. Per ogni osservazione conosciamo soltanto i regressori e la classe effettivamente osservata, cioè una coppia $(\mathbf x^{(i)},y^{(i)})$ con $y^{(i)}\in\{0,1\}$.

Serve quindi un criterio che valuti i coefficienti attraverso le probabilità assegnate alle classi osservate.

#### Probabilità della risposta osservata
Dato un vettore di coefficienti, il modello assegna alla classe 1 la probabilità: $$P(Y=1\mid\mathbf x;\boldsymbol\beta)=f_{\boldsymbol\beta}(\mathbf x)$$
Poiché esistono soltanto due classi, la probabilità della classe 0 è il complemento: $$P(Y=0\mid\mathbf x;\boldsymbol\beta)=1-f_{\boldsymbol\beta}(\mathbf x)$$
Le due espressioni si possono raccogliere in un'unica formula: $$P(Y=y\mid\mathbf x;\boldsymbol\beta)=\left[f_{\boldsymbol\beta}(\mathbf x)\right]^y\left[1-f_{\boldsymbol\beta}(\mathbf x)\right]^{1-y}$$
Gli esponenti selezionano la probabilità corrispondente alla risposta osservata:
- Se $y=1$, il secondo fattore vale 1 e rimane $f_{\boldsymbol\beta}(\mathbf x)$.
- Se $y=0$, il primo fattore vale 1 e rimane $1-f_{\boldsymbol\beta}(\mathbf x)$.

#### Massima verosimiglianza
Consideriamo un campione di $m$ osservazioni e assumiamo che gli esempi siano indipendenti. La *verosimiglianza* è il prodotto delle probabilità assegnate dal modello alle risposte osservate: $$L(\boldsymbol\beta)=\prod_{i=1}^{m}P\left(Y=y^{(i)}\mid\mathbf x^{(i)};\boldsymbol\beta\right)$$
Sostituendo la formula precedente otteniamo: $$L(\boldsymbol\beta)=\prod_{i=1}^{m}\left[f_{\boldsymbol\beta}(\mathbf x^{(i)})\right]^{y^{(i)}}\left[1-f_{\boldsymbol\beta}(\mathbf x^{(i)})\right]^{1-y^{(i)}}$$
Il metodo di *massima verosimiglianza*, o *Maximum Likelihood Estimation* (*MLE*), sceglie i coefficienti che rendono più probabili le risposte effettivamente osservate: $$\widehat{\boldsymbol\beta}=\operatorname*{arg\,max}_{\boldsymbol\beta}L(\boldsymbol\beta)$$
Un modello che assegna probabilità alte alle classi corrette produce una verosimiglianza maggiore di un modello che assegna loro probabilità basse.

#### Log-verosimiglianza e funzione di costo
Il logaritmo è una funzione crescente, quindi massimizzare la verosimiglianza equivale a massimizzarne il logaritmo. Inoltre, il logaritmo trasforma il prodotto in una somma: $$\ell(\boldsymbol\beta)=\log L(\boldsymbol\beta)=\sum_{i=1}^{m}\left[y^{(i)}\log f_{\boldsymbol\beta}(\mathbf x^{(i)})+(1-y^{(i)})\log\left(1-f_{\boldsymbol\beta}(\mathbf x^{(i)})\right)\right]$$
Per formulare un problema di minimizzazione cambiamo il segno e definiamo la *negative log-likelihood*: $$J(\boldsymbol\beta)=-\ell(\boldsymbol\beta)=-\sum_{i=1}^{m}\left[y^{(i)}\log f_{\boldsymbol\beta}(\mathbf x^{(i)})+(1-y^{(i)})\log\left(1-f_{\boldsymbol\beta}(\mathbf x^{(i)})\right)\right]$$
Questa funzione di costo è chiamata anche *log-loss* o *binary cross-entropy*. Esplicitando la dipendenza dai coefficienti attraverso la sigmoide otteniamo: $$J(\boldsymbol\beta)=-\sum_{i=1}^{m}\left[y^{(i)}\log\sigma(\boldsymbol\beta^T\mathbf x^{(i)})+(1-y^{(i)})\log\left(1-\sigma(\boldsymbol\beta^T\mathbf x^{(i)})\right)\right]$$
Il problema di stima diventa: $$\widehat{\boldsymbol\beta}=\operatorname*{arg\,min}_{\boldsymbol\beta}J(\boldsymbol\beta)$$
Per comprendere il significato della funzione di costo, indichiamo con $p_i=f_{\boldsymbol\beta}(\mathbf x^{(i)})$ la probabilità assegnata alla classe 1. Il contributo di una singola osservazione è: $$J_i=\begin{cases}-\log p_i & \text{se }y^{(i)}=1,\\-\log(1-p_i) & \text{se }y^{(i)}=0.\end{cases}$$
Se la classe osservata è 1, il costo diminuisce quando $p_i$ si avvicina a 1. Se la classe osservata è 0, il costo diminuisce quando $p_i$ si avvicina a 0. In entrambi i casi viene penalizzata l'assegnazione di una probabilità bassa alla risposta effettivamente osservata.

#### Ottimizzazione iterativa
A differenza della regressione lineare OLS, per la stima dei coefficienti logistici non disponiamo di una soluzione in forma chiusa. Utilizziamo quindi un *algoritmo iterativo*:
1. Partiamo da una stima iniziale dei coefficienti.
2. Calcoliamo il valore della funzione di costo.
3. Aggiorniamo i coefficienti per ridurre il costo.
4. Ripetiamo gli aggiornamenti fino alla convergenza.

La funzione di costo della regressione logistica è *convessa*: la ricerca del minimo non presenta minimi locali con un valore diverso da quello globale. Con un solo regressore possiamo rappresentare $J(\beta_0,\beta_1)$ come una superficie nello spazio dei due coefficienti; il minimo corrisponde al fondo della superficie.

Un metodo utilizzabile è la *discesa del gradiente*, o *gradient descent*, che sfrutta le derivate della funzione di costo per individuare la direzione in cui aggiornare i coefficienti.

### Interpretazione dei coefficienti
I coefficienti della regressione logistica descrivono variazioni nei *log-odds*. Per ottenere un'interpretazione in termini di odds dobbiamo esponenziarli.

#### Intercetta
Nel modello semplice il logit è: $$\log\left(\frac{p(x)}{1-p(x)}\right)=\beta_0+\beta_1x$$
Ponendo il regressore uguale a zero otteniamo: $$\log\left(\frac{p(0)}{1-p(0)}\right)=\beta_0$$
L'intercetta $\beta_0$ rappresenta quindi il valore dei log-odds quando $x=0$. Esponenziando entrambi i membri ricaviamo gli odds corrispondenti: $$\frac{p(0)}{1-p(0)}=e^{\beta_0}$$
Nel modello multiplo l'interpretazione è analoga: $e^{\beta_0}$ rappresenta gli odds della classe 1 quando *tutti i regressori sono nulli*.

La probabilità corrispondente si ottiene applicando la sigmoide all'intercetta: $$p(\mathbf 0)=\frac{1}{1+e^{-\beta_0}}$$

#### Coefficiente di un regressore
Per interpretare $\beta_1$, confrontiamo i log-odds in corrispondenza di $x$ e di $x+1$. Nel modello semplice la differenza è: $$\begin{aligned}\operatorname{logit}(p(x+1))-\operatorname{logit}(p(x))&=\beta_0+\beta_1(x+1)-(\beta_0+\beta_1x)\\&=\beta_1.\end{aligned}$$
Un incremento unitario di $x$ produce quindi un incremento di $\beta_1$ nei log-odds.

Utilizzando la proprietà della differenza tra logaritmi possiamo riscrivere il risultato come: $$\log\left(\frac{\operatorname{odds}(p(x+1))}{\operatorname{odds}(p(x))}\right)=\beta_1$$
Esponenziando otteniamo: $$\frac{\operatorname{odds}(p(x+1))}{\operatorname{odds}(p(x))}=e^{\beta_1}$$
Di conseguenza, gli odds dopo l'incremento sono: $$\operatorname{odds}(p(x+1))=e^{\beta_1}\operatorname{odds}(p(x))$$
La quantità $e^{\beta_1}$ è un *odds ratio*: indica il fattore per cui vengono moltiplicati gli odds quando il regressore aumenta di un'unità.

Nel modello multiplo, $e^{\beta_j}$ ha la stessa interpretazione per un incremento unitario di $x_j$, *mantenendo costanti tutti gli altri regressori*.

| Coefficiente | Odds ratio | Effetto di un incremento unitario del regressore |
| --- | --- | --- |
| $\beta_j>0$ | $e^{\beta_j}>1$ | Gli odds della classe 1 aumentano. |
| $\beta_j=0$ | $e^{\beta_j}=1$ | Gli odds non cambiano. |
| $\beta_j<0$ | $0<e^{\beta_j}<1$ | Gli odds della classe 1 diminuiscono. |

La variazione percentuale degli odds si calcola attraverso: $$\Delta_{\%}\operatorname{odds}=100\left(e^{\beta_j}-1\right)$$
L'effetto moltiplicativo riguarda gli *odds*, non direttamente la probabilità. La probabilità si ottiene trasformando il predittore lineare con la sigmoide.

### Valutazione del modello logistico
Anche nella regressione logistica distinguiamo la *goodness of fit*, che descrive l'adattamento ai dati utilizzati per la stima, dalla *valutazione predittiva*, che riguarda la capacità di classificare nuove osservazioni.

#### Log-verosimiglianza
La log-verosimiglianza misura quanto il modello rende probabili le risposte osservate. Poiché i logaritmi delle probabilità sono non positivi, valori più alti, cioè meno negativi, indicano un adattamento migliore.

Il modello viene stimato massimizzando la log-verosimiglianza, oppure, in modo equivalente, minimizzandone l'opposto.

#### Pseudo coefficiente di determinazione di McFadden
Nella regressione lineare il coefficiente di determinazione confronta la somma dei residui quadratici del modello con quella del modello che prevede sempre la media: $$R^2=1-\frac{RSS}{TSS}$$
Nella regressione logistica il criterio di stima è invece la verosimiglianza. Per valutare il miglioramento rispetto a un modello di riferimento utilizziamo uno *pseudo $R^2$*.

Lo *pseudo $R^2$ di McFadden*, riportato da `statsmodels`, confronta:
- $LL_{\mathrm{Model}}$: la log-verosimiglianza del modello con i regressori.
- $LL_{\mathrm{Null}}$: la log-verosimiglianza del modello con la sola intercetta, che assegna la stessa probabilità a tutte le osservazioni.

La definizione è: $$R^2_{\mathrm{McFadden}}=1-\frac{LL_{\mathrm{Model}}}{LL_{\mathrm{Null}}}$$
Se il modello con i regressori non migliora rispetto a quello con la sola intercetta, le due log-verosimiglianze coincidono e lo pseudo $R^2$ vale 0. Quando il modello migliora, la sua log-verosimiglianza diventa meno negativa e lo pseudo $R^2$ aumenta.

Per esempio, con $LL_{\mathrm{Model}}=-105.19$ e $LL_{\mathrm{Null}}=-452.39$ otteniamo: $$R^2_{\mathrm{McFadden}}=1-\frac{-105.19}{-452.39}\approx0.77$$
Questo valore quantifica il miglioramento rispetto al modello con la sola intercetta. Non coincide con il coefficiente di determinazione OLS e non va confrontato direttamente con esso. È utile nel confronto tra modelli logistici annidati, come quelli costruiti durante la backward elimination.

#### Valutazione predittiva
Per valutare il modello come classificatore possiamo utilizzare le misure della classificazione:
- *Accuracy*.
- *Precision*.
- *Recall*.
- *F1-score*.
- *Matrice di confusione*.

Queste misure valutano le classi assegnate dal modello, mentre la log-verosimiglianza valuta le probabilità attribuite alle risposte osservate.

### Regressione logistica in Python
Utilizziamo il dataset `biopsy`, disponibile nel pacchetto R `MASS` e caricabile attraverso `statsmodels`. Contiene 699 osservazioni e 11 colonne: un codice del campione, nove caratteristiche del tessuto e la diagnosi.

Le nove caratteristiche sono valutate su una scala da 1 a 10:

| Variabile | Caratteristica |
| --- | --- |
| `V1` | Spessore degli aggregati cellulari (*clump thickness*) |
| `V2` | Uniformità della dimensione delle cellule |
| `V3` | Uniformità della forma delle cellule |
| `V4` | Adesione marginale |
| `V5` | Dimensione delle singole cellule epiteliali |
| `V6` | Nuclei nudi (*bare nuclei*) |
| `V7` | Cromatina (*bland chromatin*) |
| `V8` | Nucleoli normali |
| `V9` | Mitosi |

La risposta `class` assume i valori `benign` e `malignant`. Il codice `ID` non viene utilizzato come regressore.

#### Caricamento e preparazione dei dati
```python
import numpy as np
from statsmodels.datasets import get_rdataset
from statsmodels.formula.api import logit

biopsy = get_rdataset('biopsy', package='MASS')
print(biopsy.__doc__)

data = biopsy.data.copy()
print(data['class'].unique())
```
I valori della risposta sono:
```text
['benign' 'malignant']
```
Per stimare il modello trasformiamo la diagnosi in una variabile numerica binaria. Creiamo una colonna `cl`, evitando di usare nella formula il nome `class`, che è una parola riservata:
```python
data['cl'] = data['class'].replace({'benign': 0, 'malignant': 1})
```
Il modello assegnerà quindi la probabilità alla classe `cl = 1`, cioè alla diagnosi maligna.

La variabile `V6` contiene 16 valori mancanti. Nella stima vengono escluse le osservazioni incomplete, per cui il modello utilizza *683 osservazioni*.

#### Modello completo
Includiamo inizialmente tutte le nove caratteristiche:
```python
model_full = logit(
    'cl ~ V1 + V2 + V3 + V4 + V5 + V6 + V7 + V8 + V9',
    data=data
).fit()

print(model_full.summary())
```
Nella formula:
- A sinistra di `~` troviamo la risposta.
- A destra troviamo i regressori, separati da `+`.
- L'intercetta viene inclusa automaticamente.

`logit()` definisce il modello, `.fit()` stima i coefficienti per massima verosimiglianza e `.summary()` restituisce il riepilogo dei risultati.

##### Informazioni generali del riepilogo
Le principali informazioni del modello completo sono:

| Voce | Significato e risultato |
| --- | --- |
| `Dep. Variable` | Risposta `cl` |
| `Model` | Modello `Logit` |
| `Method` | Stima per massima verosimiglianza, `MLE` |
| `No. Observations` | 683 osservazioni |
| `Df Model` | 9 coefficienti dei regressori |
| `Df Residuals` | $683-10=673$, considerando anche l'intercetta |
| `converged` | `True`: l'ottimizzazione è terminata con successo |
| `Log-Likelihood` | $-51.444$ |
| `LL-Null` | $-442.18$ |
| `Pseudo R-squ.` | $0.8837$ |
| `LLR p-value` | Circa $2.077\cdot10^{-162}$ |

Lo pseudo $R^2$ si ottiene confrontando le due log-verosimiglianze: $$R^2_{\mathrm{McFadden}}=1-\frac{-51.444}{-442.18}\approx0.8837$$
Il `LLR p-value` riguarda il confronto complessivo con il modello contenente soltanto l'intercetta. Il valore molto piccolo indica che i regressori, considerati nel loro insieme, migliorano il modello di riferimento.

##### Coefficienti e significatività individuale
La tabella dei coefficienti contiene:
- `coef`: la stima $\widehat\beta_j$.
- `std err`: l'errore standard della stima.
- `z`: la statistica utilizzata per il test sul coefficiente.
- `P>|z|`: il p-value del test bilaterale $H_0:\beta_j=0$.
- `[0.025, 0.975]`: gli estremi dell'intervallo di confidenza al 95%.

La statistica confronta la stima con il suo errore standard: $$z_{\mathrm{obs}}=\frac{\widehat\beta_j}{SE(\widehat\beta_j)}$$
Con un livello di significatività $\alpha=0.05$, consideriamo significativo un coefficiente quando il suo p-value è inferiore a $0.05$.

Nel modello completo otteniamo:

| Termine | Coefficiente | p-value |
| --- | --- | --- |
| `Intercept` | -10.1039 | $<0.001$ |
| `V1` | 0.5350 | $<0.001$ |
| `V2` | -0.0063 | 0.976 |
| `V3` | 0.3227 | 0.162 |
| `V4` | 0.3306 | 0.007 |
| `V5` | 0.0966 | 0.537 |
| `V6` | 0.3830 | $<0.001$ |
| `V7` | 0.4472 | 0.009 |
| `V8` | 0.2130 | 0.059 |
| `V9` | 0.5348 | 0.104 |

Il modello è complessivamente significativo, ma diversi coefficienti hanno p-value superiori a $0.05$. Per semplificarlo utilizziamo la *backward elimination*.

#### Backward elimination
La procedura parte dal modello completo e rimuove progressivamente i regressori non significativi:
1. Individuiamo il regressore con il p-value più alto tra quelli superiori a $0.05$.
2. Rimuoviamo quel regressore.
3. Stimiamo nuovamente il modello.
4. Ricalcoliamo tutti i coefficienti e i relativi p-value.
5. Ripetiamo finché tutti i regressori rimasti hanno p-value inferiori a $0.05$.

L'intercetta non viene usata come criterio di eliminazione. A ogni passaggio rimuoviamo una sola variabile, perché i risultati dei test dipendono dagli altri regressori presenti.

##### Eliminazione di V2
Nel modello completo il p-value più alto è quello di `V2`, pari a $0.976$. Rimuoviamo questa variabile:
```python
model_no_v2 = logit(
    'cl ~ V1 + V3 + V4 + V5 + V6 + V7 + V8 + V9',
    data=data
).fit()

print(model_no_v2.summary())
```
La log-verosimiglianza diventa $-51.445$ e lo pseudo $R^2$ rimane circa $0.8837$: l'adattamento cambia pochissimo.

Nel nuovo modello il p-value più alto è quello di `V5`, pari a $0.537$. Il p-value di `V3` passa invece da $0.162$ a $0.068$, mostrando che la significatività individuale cambia dopo la rimozione di un regressore.

##### Eliminazione di V5
Rimuoviamo `V5` e stimiamo nuovamente il modello:
```python
model_no_v5 = logit(
    'cl ~ V1 + V3 + V4 + V6 + V7 + V8 + V9',
    data=data
).fit()

print(model_no_v5.summary())
```
Otteniamo una log-verosimiglianza di $-51.633$ e uno pseudo $R^2$ di $0.8832$.

Ora:
- `V3` ha p-value $0.044$ e risulta significativo.
- `V8` ha p-value $0.042$ e risulta significativo.
- `V9` ha p-value $0.102$ ed è l'unico regressore rimasto sopra la soglia.

Non sarebbe quindi corretto eliminare contemporaneamente tutte le variabili non significative nel modello iniziale: `V3` e `V8`, inizialmente sopra soglia, diventano significative dopo le prime rimozioni.

##### Eliminazione di V9
Rimuoviamo `V9`:
```python
model_final = logit(
    'cl ~ V1 + V3 + V4 + V6 + V7 + V8',
    data=data
).fit()

print(model_final.summary())
```
Nel modello finale tutti i coefficienti dei regressori hanno p-value inferiori a $0.05$, quindi arrestiamo la procedura.

I passaggi della selezione sono:

| Modello | Decisione successiva | Log-verosimiglianza | Pseudo $R^2$ |
| --- | --- | --- | --- |
| Completo | Rimuovere `V2`, $p=0.976$ | -51.444 | 0.8837 |
| Senza `V2` | Rimuovere `V5`, $p=0.537$ | -51.445 | 0.8837 |
| Senza `V2` e `V5` | Rimuovere `V9`, $p=0.102$ | -51.633 | 0.8832 |
| Senza `V2`, `V5` e `V9` | Tutti i regressori rimasti sono significativi | -53.572 | 0.8788 |

Il modello finale utilizza sei regressori e mantiene un adattamento vicino a quello del modello completo. Il suo `LLR p-value` è circa $1.294\cdot10^{-164}$.

#### Modello finale
Le stime finali sono:

| Termine | Coefficiente | Errore standard | $z$ | p-value | IC al 95% |
| --- | --- | --- | --- | --- | --- |
| `Intercept` | -9.7671 | 1.085 | -9.001 | $<0.001$ | [-11.894, -7.640] |
| `V1` | 0.6225 | 0.137 | 4.540 | $<0.001$ | [0.354, 0.891] |
| `V3` | 0.3495 | 0.165 | 2.118 | 0.034 | [0.026, 0.673] |
| `V4` | 0.3375 | 0.116 | 2.920 | 0.004 | [0.111, 0.564] |
| `V6` | 0.3786 | 0.094 | 4.035 | $<0.001$ | [0.195, 0.562] |
| `V7` | 0.4713 | 0.166 | 2.837 | 0.005 | [0.146, 0.797] |
| `V8` | 0.2432 | 0.109 | 2.240 | 0.025 | [0.030, 0.456] |

Il predittore lineare stimato è: $$\widehat z=-9.7671+0.6225V_1+0.3495V_3+0.3375V_4+0.3786V_6+0.4713V_7+0.2432V_8$$
Questo valore rappresenta i log-odds previsti della diagnosi maligna. La probabilità prevista si ottiene applicando la sigmoide: $$\widehat p=\frac{1}{1+e^{-\widehat z}}$$

#### Interpretazione degli odds ratio
Per interpretare i coefficienti esponenziamo le stime:
```python
print(np.exp(model_final.params))
```
Otteniamo:
```text
Intercept    0.000057
V1           1.863641
V3           1.418374
V4           1.401487
V6           1.460166
V7           1.602133
V8           1.275287
```
L'esponenziale dell'intercetta rappresenta gli odds previsti della diagnosi maligna quando tutti i regressori sono nulli: $$\widehat{\operatorname{odds}}(Y=1\mid\mathbf x=\mathbf0)=e^{-9.7671}\approx0.000057$$
Gli odds molto piccoli corrispondono a una probabilità di malignità vicina a zero in questa configurazione.

Per ogni altro coefficiente, l'esponenziale indica il fattore moltiplicativo degli odds per un incremento unitario del regressore, *a parità di tutte le altre variabili*:

| Regressore | Odds ratio | Interpretazione di un incremento unitario |
| --- | --- | --- |
| `V1` | 1.863641 | Gli odds di malignità aumentano di circa l'86.4%. |
| `V3` | 1.418374 | Gli odds di malignità aumentano di circa il 41.8%. |
| `V4` | 1.401487 | Gli odds di malignità aumentano di circa il 40.1%. |
| `V6` | 1.460166 | Gli odds di malignità aumentano di circa il 46.0%. |
| `V7` | 1.602133 | Gli odds di malignità aumentano di circa il 60.2%. |
| `V8` | 1.275287 | Gli odds di malignità aumentano di circa il 27.5%. |

Per esempio, l'effetto di `V1` si ricostruisce dal coefficiente stimato: $$e^{0.6225}\approx1.8636\;\Longrightarrow\;100(1.8636-1)\approx86.4\%$$
Un aumento unitario di `V1` moltiplica quindi gli odds di malignità per circa $1.86$; non aumenta direttamente la probabilità di malignità dell'86.4%.

Tutti i coefficienti dei regressori rimasti sono positivi: a parità delle altre caratteristiche, valori più alti sono associati a odds maggiori di diagnosi maligna, mentre nei casi benigni ci aspettiamo valori più piccoli delle caratteristiche considerate.
