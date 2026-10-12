---
color: ""
---
link: https://antoninofurnari.github.io/fad-2627/notes/02_describing_visualizing.html

Materiale di riferimento: [[3104 fondamenti-di-analisi-dati/file-condivisi/sitoWeb/01_Modulo_1/02_describing_visualizing.pdf|02_describing_visualizing.pdf]].

#### Frequenze assolute
La **frequenza assoluta** $n_j$ è il numero di volte in cui uno specifico valore $a_j$ compare nel campione. La somma delle frequenze assolute è pari al numero totale di osservazioni $N$.

In pandas si usa `.value_counts()`, che ordina i valori per frequenza decrescente. Per ordinarli invece in base al valore si aggiunge `.sort_index()`:

```python
heights = hw['height']
weights = hw['weight']
heights.value_counts().sort_index()
```

#### Data visualization
Direttamente con pandas possiamo creare grafici tramite `.plot`: il backend predefinito è **Matplotlib**. Questo semplifica la scrittura del codice, ma non rende automaticamente interattivi i grafici.

```python
from matplotlib import pyplot as plt

heights.value_counts().sort_index().plot.bar(figsize=(18, 6))
plt.grid()
plt.show()
```

![[Pasted image 20261008152319.png|center|500]]
Dal grafico possiamo capire quali valori sono più frequenti: sull'asse $x$ ci sono i valori osservati, sull'asse $y$ i rispettivi conteggi.

#### Frequenze relative
La **frequenza relativa** è il rapporto tra la frequenza assoluta di un valore e il numero totale di osservazioni:

$$f_j = \frac{n_j}{N}, \qquad \sum_j f_j = 1.$$

Permette di confrontare campioni di dimensioni diverse. Moltiplicandola per 100 si ottiene la percentuale.

![[Pasted image 20261008152900.png|center|350]]

```python
heights.value_counts(normalize=True).sort_index()
```

### Data visualization (continuazione)

#### Grafico a barre
![[Pasted image 20261008153704.png|center|500]]
Nel grafico confrontiamo le frequenze relative delle altezze degli uomini (blu) e delle donne (arancione). Nel campione, le donne tendono a essere più basse: le barre arancioni si concentrano più a sinistra. Le distribuzioni si sovrappongono, quindi questo non significa che ogni uomo sia più alto di ogni donna.

Ci sono altri modi di usare il grafico a barre:

![[Pasted image 20261008153937.png|center|500]]

![[Pasted image 20261008153947.png|center|500]]

Qui contiamo gli uomini e le donne nel dataset: il primo grafico mostra le **frequenze assolute**, il secondo le **frequenze relative** che vengono rappresentate usando il *grafico a barre impilate* (*stacked barplot*): le proporzioni delle categorie formano un'unica barra di altezza 1, cioè il 100%.

#### Pie Charts
I **grafici a torta** rappresentano le proporzioni delle categorie rispetto al totale. Non sono ideali per confrontare molte categorie o proporzioni simili: è più facile confrontare le altezze delle barre che gli angoli e le aree dei settori. Possono essere utili quando le categorie sono poche, come nel confronto seguente:
![[Pasted image 20261008155256.png|center|500]]
#### Empirical Cumulative Distribution Function

Quando una variabile ha molti valori distinti, come accade spesso con dati continui registrati con precisione, le frequenze dei singoli valori sono piccole. Valori molto vicini vengono trattati come casi distinti e il grafico a barre diventa difficile da leggere:
![[Pasted image 20261008155418.png|center|687]]
Una soluzione è la **funzione di distribuzione cumulativa empirica (ECDF)**: per ogni $x$, somma le frequenze relative dei valori minori o uguali a $x$.

$$F_N(x) = \frac{\#\{i : x_i \leq x\}}{N} = \sum_{a_j \leq x} f_j.$$

![[Pasted image 20261008155531.png|center|200]]

```python
a = pd.Series([1, 5, 2, 6, 5, 4, 3, 5, 4, 2, 4, 5, 6, 4, 4, 3])
a.value_counts(normalize=True).sort_index()
```

Risultato:

```text
1    0.0625
2    0.1250
3    0.1250
4    0.3125
5    0.2500
6    0.1250
Name: proportion, dtype: float64
```

```python
a.value_counts(normalize=True).sort_index().cumsum()
```

Risultato:

```text
1    0.0625
2    0.1875
3    0.3125
4    0.6250
5    0.8750
6    1.0000
Name: proportion, dtype: float64
```
Ad esempio, $F_N(4)=0.625$: il **62,5%** degli elementi è minore o uguale a 4. È importante ordinare i valori prima di applicare `.cumsum()`. L'ECDF è una funzione a gradini, non decrescente, e raggiunge 1 al massimo osservato.

![[Pasted image 20261008160323.png|center|500]]
- In corrispondenza di $x=40$, la curva blu è circa a 0,60: circa il **60% degli uomini** ha un peso minore o uguale a 40 nelle unità riportate sull'asse.
- Le donne tendono ad avere pesi inferiori: a parità di soglia $x$, la curva arancione è generalmente più alta, cioè una quota maggiore di donne è sotto quella soglia.

L'ECDF è utile per leggere quote cumulative e confrontare distribuzioni; un istogramma può essere più intuitivo per individuarne picchi e concentrazioni.

#### Istogramma
Possiamo raggruppare i valori vicini in intervalli detti **bin**: ogni osservazione viene assegnata al proprio intervallo (*discretizzazione* o *quantizzazione*).

```python
heights_quantized = pd.cut(heights, bins=10) # Crea 10 intervalli
heights_quantized.value_counts().sort_index().plot.bar(figsize=(18,6))
plt.grid()
plt.show()
```

Otteniamo questo grafico:
![[Pasted image 20261008160944.png|center|500]]
Il grafico mostra i conteggi per intervallo, anziché per singolo valore. Un istogramma si può costruire anche direttamente con `plt.hist(heights, bins=10)`: l'asse $x$ è numerico e le barre occupano gli intervalli corrispondenti, a differenza di un grafico a barre per categorie.

È importante scegliere un numero di bin sensato:
- **Pochi bin**: perdita di dettaglio; possono nascondere caratteristiche importanti.
- **Tanti bin**: maggiore dettaglio, ma anche più rumore e difficoltà di lettura.

Esistono euristiche per scegliere un punto di partenza:
![[Pasted image 20261008161314.png|200]]
- **Sturges**: $k \approx 1 + \log_2 N$.
- **Rice**: $k \approx 2N^{1/3}$.

Sono criteri indicativi: conviene confrontare più scelte e verificare che le conclusioni non dipendano solo dai bin. Si possono anche specificare direttamente i bordi degli intervalli, ad esempio `bins=[20, 25, 30, 35, 40, 45, 50, 55, 60, 65]`.

Inserendo i pesi di uomini e donne nello stesso grafico otteniamo un confronto più intuitivo. Per un confronto corretto conviene usare gli stessi bordi dei bin e, se i gruppi hanno dimensioni diverse, normalizzare le distribuzioni.
![[Pasted image 20261008161653.png|center|500]]
La tendenza è la stessa vista prima: gli uomini si trovano più **a destra**, perché nel campione tendono ad avere pesi maggiori.

#### Stima della densità
Gli istogrammi producono una rappresentazione a blocchi, dipendente dalla scelta dei bin. La **stima della densità**, ad esempio tramite *Kernel Density Estimation* (KDE), fornisce invece una curva continua che descrive come si distribuiscono i dati.
![[Pasted image 20261008161936.png|center|499x339]]

In pandas si usa `.plot.density()` oppure `.plot.kde()`. Il parametro **bandwidth**, regolabile tramite `bw_method`, controlla il livello di smoothing:
- **Bandwidth piccola**: più dettagli, ma anche più oscillazioni e rumore.
- **Bandwidth grande**: curva più liscia, ma possibile perdita di caratteristiche importanti.

![[Pasted image 20261008162156.png|center|500]]

Possiamo confrontare diverse serie, ad esempio i pesi degli uomini e delle donne:

```python
hw.groupby('sex')['weight'].plot.density()
plt.legend()
plt.grid()
plt.show()
```

![[Pasted image 20261008162247.png|center|500]]
#### Mixes
Possiamo sovrapporre istogrammi e curve di densità. Per renderne confrontabile la scala verticale bisogna normalizzare l'istogramma con `density=True`:

```python
weights.plot.density()
plt.hist(weights, bins=10, density=True, alpha=0.5)
plt.grid()
plt.show()
```

In un **istogramma di densità** (density histogram), l’area totale delle barre è pari a 1. L’altezza di ciascuna barra si ottiene dividendo la frequenza relativa delle osservazioni nell’intervallo (bin) per l’ampiezza dell’intervallo stesso.

Di conseguenza, è l’area della barra, e non la sua altezza, a rappresentare la proporzione di osservazioni che ricade in quell’intervallo.

Lo stesso principio si applica a una curva di densità: l’area totale sotto la curva è pari a 1 e l’area compresa tra due valori rappresenta la probabilità che una variabile assuma un valore all’interno di quell’intervallo.

![[Pasted image 20261008164532.png|center|500]]
### Statistiche di base
Sono numeri che riassumono quantitativamente le caratteristiche del campione. In questa lezione il prof usa soprattutto le età dei passeggeri del Titanic (`age = titanic['Age']`).

Prima di calcolarli, distinguiamo il numero totale di righe (`len(age)`) dal numero di valori non mancanti (`age.count()`). Nell'esempio ci sono 891 righe, ma solo 714 età disponibili. I metodi pandas qui usati ignorano normalmente i valori mancanti.

- **Media**: somma dei valori divisa per il numero di osservazioni valide, $\bar{x}=\frac{1}{N}\sum_{i=1}^{N}x_i$. Si calcola con `.mean()` ed è sensibile ai valori estremi.
- **Mediana**: valore centrale del campione ordinato. Con un numero dispari di osservazioni si prende il valore centrale; con un numero pari di valori numerici si fa la media dei due centrali. Si calcola con `.median()` ed è più robusta della media rispetto agli outlier.
- **Quantile**: è un valore che permette di **dividere un insieme di dati ordinati in due parti**, in base a una proporzione scelta. Un esempio è la **mediana**, che divide i dati in due metà: il 50% dei valori si trova al di sotto e il restante 50% al di sopra. I quantili generalizzano questo concetto, permettendoci di scegliere proporzioni diverse, ad esempio il 25% e il 75%. Il parametro **α (alfa)** indica la proporzione scelta, con un valore compreso tra 0 e 1. Ad esempio, `age.quantile(0.25)` restituisce il **primo quartile (25° percentile)**, cioè il valore di età al di sotto del quale si trova circa il 25% delle osservazioni. In altre parole, identifica la soglia che separa il 25% delle persone più giovani dal restante 75%.
  - **Percentile**: è lo stesso concetto, ma la quota viene indicata su una scala da 0 a 100 invece che da 0 a 1. Il **25° percentile** e il **quantile 0,25** indicano quindi la stessa soglia.
  - **Quartili**: sono le tre soglie che dividono la fila ordinata in **quattro gruppi**, ciascuno con circa il 25% dei dati:
    - **$Q_1$**: dopo il primo gruppo, cioè al **25%** dei dati.
    - **$Q_2$**: dopo due gruppi, cioè al **50%** dei dati. Per questo **è la mediana**.
    - **$Q_3$**: dopo tre gruppi, cioè al **75%** dei dati.
- **Moda**: valore più frequente. Si calcola con `.mode()`, che può restituire più valori se ci sono frequenze massime uguali.
#### Misure di dispersione
Le misure di dispersione indicano quanto i valori sono distanti tra loro o dal centro della distribuzione.
- **Minimo**: `.min()`.
- **Massimo**: `.max()`.
- **Range**: differenza tra massimo e minimo, $x_{\max}-x_{\min}$.

**Outlier**: sono osservazioni che si trovano **insolitamente lontane dalla maggior parte dei dati** di un insieme. Non sono necessariamente errori: possono rappresentare situazioni rare ma reali e devono essere interpretati nel loro contesto. Gli outlier possono *influenzare significativamente la media e il range*, perché valori particolarmente alti o bassi possono spostare la media e aumentare la distanza tra il minimo e il massimo. 

**Interquartile Range (IQR)**: è una misura di dispersione che indica quanto sono distribuiti i valori nella parte centrale di un insieme di dati, considerando il 50% delle osservazioni centrali. Si calcola come differenza tra il **terzo quartile (Q3)**, che corrisponde al 75° percentile, e il **primo quartile (Q1)**, che corrisponde al 25° percentile.
$$IQR = Q_3-Q_1.$$
```python
iqr = age.quantile(0.75) - age.quantile(0.25)
```
L'IQR è una misura **robusta rispetto ai valori anomali (outlier)** perché, a differenza del range (massimo − minimo), non dipende direttamente dai valori estremi.
- **IQR piccolo**: i valori centrali sono concentrati in un intervallo ristretto.
- **IQR grande**: i valori centrali sono più dispersi.

> [!EXAMPLE]
> se il primo quartile (Q1) è 20 anni e il terzo quartile (Q3) è 41 anni, allora:
> $$
> IQR = 41 − 20 = 21 anni
> $$
> Questo significa che il 50% centrale delle persone ha un'età compresa tra 20 (Q1) e 41 anni (Q1+IQR).
> L'IQR (21 anni) rappresenta quindi l'ampiezza dell'intervallo, non il suo valore iniziale. Per conoscere i limiti dell'intervallo dobbiamo guardare Q1 e Q3.

Altre misure di dispersione, che **non sono robuste agli outlier**, sono:
- **Varianza**: misura gli scostamenti **al quadrato** dalla media. La varianza descrittiva usa il divisore $N$; la varianza campionaria corretta usa $N-1$: $$s^2 = \frac{\sum_{i=1}^{N}(x_i-\bar{x})^2}{N-1}.$$In pandas `.var()` usa per impostazione predefinita $N-1$; `.var(ddof=0)` usa $N$. L'unità di misura della varianza è il quadrato dell'unità dei dati.
- **Deviazione standard**: radice quadrata della varianza, $s=\sqrt{s^2}$, espressa nella stessa unità dei dati. Si calcola con `.std()` (divisore $N-1$) oppure `.std(ddof=0)` (divisore $N$).
#### Normalizzazione dei dati
La normalizzazione permette di confrontare variabili con scale o unità di misura diverse.
- **Normalizzazione tra 0 e 1**: il minimo diventa 0 e il massimo diventa 1:$$x_i^{\mathrm{norm}}=\frac{x_i-x_{\min}}{x_{\max}-x_{\min}}.$$
```python
weights_norm = (weights-weights.min())/(weights.max()-weights.min())
weights_norm
```
- **Normalizzazione tra -1 e 1**: la formula riportata nel PDF porta i dati nell'intervallo $[-1,1]$, ma **inverte l'ordine**: il minimo originale diventa 1 e il massimo originale diventa -1.
```python
weights_norm2 = (weights.max()+weights.min()-2*weights)/(weights.max()-weights.min())
weights_norm2
```
Per preservare l'ordine si può invece usare `2 * weights_norm - 1`. Entrambe le normalizzazioni min–max richiedono che massimo e minimo siano diversi e sono sensibili agli outlier.
- **Standardizzazione (z-scoring)**: sottrae la media e divide per la deviazione standard: $$z_i=\frac{x_i-\bar{x}}{s}.$$
```python
weights_z = (weights - weights.mean()) / weights.std()
```
I dati risultanti sono adimensionali, con media 0 e deviazione standard 1, usando la stessa convenzione per calcolare quest'ultima. Richiede una deviazione standard non nulla; **non** rende automaticamente gaussiana la distribuzione e non limita i valori a un intervallo fisso.
#### Indicatori di forma
Descrivono alcuni aspetti della forma della distribuzione, usando anche la gaussiana come riferimento.
- **Skewness (asimmetria)**: misura l'asimmetria della distribuzione; si calcola con `.skew()`.
  - **Negativa**: coda più lunga verso sinistra.
  - **Positiva**: coda più lunga verso destra.
  - **Vicina a zero**: poca asimmetria secondo questo indicatore; non garantisce da sola una distribuzione simmetrica o gaussiana.
- **Kurtosis (curtosi)**: riguarda soprattutto il peso delle code e la presenza di valori estremi, non semplicemente l'altezza del picco centrale. Il PDF e pandas (`.kurtosis()`) usano l'**eccesso di curtosi**, cioè la curtosi meno 3:
  - **$>0$**: code più pesanti rispetto alla normale (*leptocurtica*).
  - **$<0$**: code più leggere rispetto alla normale (*platicurtica*).
  - **$=0$**: stessa curtosi della normale (*mesocurtica*), ma non necessariamente distribuzione gaussiana.

#### Sommario statistico
Il **sommario statistico** raccoglie indicatori numerici della distribuzione. Per una variabile numerica, pandas `.describe()` restituisce molte delle misure viste:

```python
age.describe()
```

![[Pasted image 20261008174344.png|center|500]]
Include `count` (valori non mancanti), `mean`, `std`, `min`, `25%` ($Q_1$), `50%` (mediana), `75%` ($Q_3$) e `max`. **Non include automaticamente tutte le statistiche**: moda, varianza, range, IQR, skewness e kurtosis vanno calcolati a parte.

#### Boxplots
Il **boxplot** è una rappresentazione compatta di posizione, dispersione e possibili outlier:
![[Pasted image 20261008174551.png|center|232]]
Nella versione standard di Tukey, usata normalmente da pandas/Matplotlib:
- Il bordo inferiore della scatola indica il **primo quartile** $Q_1$.
- Il bordo superiore indica il **terzo quartile** $Q_3$: l'altezza della scatola è l'IQR.
- La linea interna rappresenta la **mediana** $Q_2$.
- Il **baffo inferiore** arriva al più piccolo valore osservato maggiore o uguale a $Q_1-1.5\,IQR$.
- Il **baffo superiore** arriva al più grande valore osservato minore o uguale a $Q_3+1.5\,IQR$.
- I punti oltre questi limiti sono **potenziali outlier** secondo questa regola, non necessariamente dati errati.

I baffi non coincidono necessariamente con minimo e massimo, né con le soglie teoriche: terminano su valori effettivamente osservati. Esistono altre versioni del boxplot con convenzioni diverse.

Anche tramite i boxplot possiamo confrontare i pesi di uomini e donne:

```python
hw.boxplot(column='weight', by='sex', figsize=(12, 8))
plt.show()
```

