---
color: ""
---
Materiale di riferimento: 
- [[3104 fondamenti-di-analisi-dati/file-condivisi/sitoWeb/appunti/Modulo-1/02_describing_visualizing.pdf|02_describing_visualizing.pdf]]
- [[3104 fondamenti-di-analisi-dati/file-condivisi/sitoWeb/slide/Modulo-1/02_describing_visualizing.pdf|slide]]

#### Le frequenze
##### Frequenze assolute
La **frequenza assoluta** $n_j$ è il numero di volte in cui uno specifico valore $a_j$ compare nel campione. La somma delle frequenze assolute è pari al numero totale di osservazioni $N$.

In pandas si usa `.value_counts()`, che ordina i valori per frequenza decrescente. Per ordinarli invece in base al valore si aggiunge `.sort_index()`:

```python
heights = hw['height']
weights = hw['weight']
heights.value_counts().sort_index()
# Direttamente usando pandas possiamo creare dei grafici
heights.value_counts().sort_index().plot.bar(figsize=(18, 6))
plt.grid()
plt.show()
```
![[Pasted image 20261008152319.png|center|500]]
Dal grafico riusciamo a capire subito quali valori sono più frequenti: sull'asse $x$ ci sono i valori osservati, sull'asse $y$ i rispettivi conteggi (64 in questo caso).

##### Frequenze relative
La *frequenza relativa* $f_{j}$ è il rapporto tra la frequenza assoluta di un valore e il numero totale di osservazioni: $$f_j = \frac{n_j}{N}$$
ovviamente la sommatoria di tutte le $f_{j}$ fa 1
```python
# ci basta mettere "normalize=True"
heights.value_counts(normalize=True).sort_index().plot.bar(figsize=(18, 6))
plt.grid()
plt.show()
```
![[3 - 8 ottobre 2026-1.png|center|500]]
### Data visualization
#### Grafico a barre
Nell'esempio di seguito vediamo un grafico a barre che rappresenta le frequenze relative delle altezze degli uomini (blu) e quelle delle donne (arancio), già da questo grafico riusciamo a fare delle analisi qualitative dei campioni

```python
pmf_height_m = hw[hw['sex']-='M']['height'].value_counts(normalize=True).sort_index() pmf_height_f = hw[hw['sex']-='F']['height'].value_counts(normalize=True).sort_index() plt.figure(figsize=(18,6)) 
# We add and subtract 0.2 from the indices to "shift" the bars and make them # visible when overlapping. We also set alpha=0.9 to make the bars 
# partially transparent. 
plt.bar(pmf_height_m.index+0.2, pmf_height_m.values, width=0.5, alpha=0.9) plt.bar(pmf_height_f.index-0.2, pmf_height_f.values, width=0.5, alpha=0.9) plt.xticks(hw['height'].unique(), rotation='vertical') plt.legend(['M','F']) # Display a legend 
plt.grid() plt.show()
```
![[3 - 8 ottobre 2026-3.png|center|500]]
Ci sono altri modi di usare il grafico a barre, ad esempio per rappresentare le proporzioni di una classe rispetto al dataset:
![[3 - 8 ottobre 2026-2.png|center|500]]
Qui contiamo gli uomini e le donne nel dataset: il primo grafico mostra le frequenze assolute, il secondo le frequenze relative, quest'ultime vengono rappresentate usando il *grafico a barre impilate* (*stacked barplot*): le proporzioni delle categorie formano un'unica barra di altezza 1, cioè il 100%.

#### Pie Charts
I *grafici a torta* rappresentano le proporzioni delle categorie rispetto al totale. Non sono ideali per confrontare molte categorie o proporzioni simili: è più facile confrontare le altezze delle barre che gli angoli e le aree dei settori. Possono essere utili quando le categorie sono poche, come nel confronto seguente:
![[Pasted image 20261008155256.png|center|500]]
#### Empirical Cumulative Distribution Function
Quando una variabile ha molti valori distinti, come accade spesso con dati continui registrati con precisione, le frequenze dei singoli valori sono piccole. Valori molto vicini vengono trattati come casi distinti e il grafico a barre diventa difficile da leggere:
![[Pasted image 20261008155418.png|center|500]]
Una soluzione a questo problema è la *ECDF (Empirical Cumulative Distribution Function)*: per ogni $x$, somma le frequenze relative dei valori minori o uguali a $x$.

$$F_N(x) = \sum_{a_{j}: a_j \leq x} f_j.$$

> [!EXAMPLE]
> Prendiamo in esame questa serie di numeri
> ```python
> a = pd.Series([1, 5, 2, 6, 5, 4, 3, 5, 4, 2, 4, 5, 6, 4, 4, 3])
> a.value_counts(normalize=True).sort_index()
> ```
> 
> ```text
> Risultato:
> 1    0.0625
> 2    0.1250
> 3    0.1250
> 4    0.3125
> 5    0.2500
> 6    0.1250
> Name: proportion, dtype: float64
> ```
> 
> ```python
> a.value_counts(normalize=True).sort_index().cumsum()
> ```
> 
> ```text
> Risultato:
> 1    0.0625
> 2    0.1875
> 3    0.3125
> 4    0.6250
> 5    0.8750
> 6    1.0000
> Name: proportion, dtype: float64
> ```
> 

Di seguito l'ECDF applicata alla caratteristica peso di uomini e donne:
```python
ecdf_weight_m = hw[hw['sex']-='M'] 
	['weight'].value_counts(normalize=True).sort_index().cumsum() 
ecdf_weight_f = hw[hw['sex']-='F'] 
	['weight'].value_counts(normalize=True).sort_index().cumsum() 
	
plt.figure(figsize=(12,8)) 
plt.plot(ecdf_weight_m.index, ecdf_weight_m.values) 
plt.plot(ecdf_weight_f.index, ecdf_weight_f.values) 
plt.legend(['M','F']) 
plt.grid() 
plt.show()
```
![[Pasted image 20261008160323.png|center|500]]
- In corrispondenza di $x=40$, la curva blu è circa a 0,60: circa il *60% degli uomini* ha un peso minore o uguale a 40 nelle unità riportate sull'asse.
- Le donne tendono ad avere pesi inferiori: a parità di soglia $x$, la curva arancione è generalmente più alta, cioè una quota maggiore di donne è sotto quella soglia.

L'ECDF è utile per leggere quote cumulative e confrontare distribuzioni

#### Istogramma
Possiamo raggruppare i valori vicini in intervalli detti **bin**: ogni osservazione viene assegnata al proprio intervallo (*discretizzazione* o *quantizzazione*).

```python
heights_quantized = pd.cut(heights, bins=10) # Crea 10 intervalli
heights_quantized.value_counts().sort_index().plot.bar(figsize=(18,6))
# oppure direttamente "plt.hist(heights, bins=10)"
plt.grid()
plt.show()
```

Otteniamo questo grafico:
![[Pasted image 20261008160944.png|center|500]]
Il grafico mostra i conteggi per intervallo, anziché per singolo valore, ovviamente diventa importante scegliere un numero di bin sensato:
- *Pochi bin*: perdita di dettaglio; possono nascondere caratteristiche importanti.
- *Tanti bin*: maggiore dettaglio, ma anche più rumore e difficoltà di lettura.

Esistono euristiche per scegliere un punto di partenza:
- Sturges: $k \approx 1 + \log_2 N$.
- Rice: $k \approx 2N^{1/3}$.
Sono criteri indicativi: conviene confrontare più scelte e verificare che le conclusioni non dipendano solo dai bin.

#### Stima della densità
Gli istogrammi producono una rappresentazione a blocchi, dipendente dalla scelta dei bin. La **stima della densità**, ad esempio tramite *Kernel Density Estimation* (KDE), fornisce invece una curva continua che descrive come si distribuiscono i dati.
![[Pasted image 20261008161936.png|center|499x339]]

In pandas si usa `.plot.density()` oppure `.plot.kde()`. Il parametro **bandwidth**, regolabile tramite `bw_method`, controlla il livello di smoothing:
- *Bandwidth piccola*: più dettagli, ma anche più oscillazioni e rumore.
- *Bandwidth grande*: curva più liscia, ma possibile perdita di caratteristiche importanti.

![[Pasted image 20261008162156.png|center|500]]
#### Istogramma di densità
Possiamo sovrapporre istogrammi e curve di densità per creare un *istogramma di densità*, questa grafico ha le seguenti caratteristiche: 
-  l’area totale delle barre è pari a 1
-  l’area totale sotto la curva è pari a 1

```python
weights.plot.density()
plt.hist(weights, bins=10, density=True, alpha=0.5)
plt.grid()
plt.show()
```
![[Pasted image 20261008164532.png|center|500]]
### Summary Statistics
Sono numeri che riassumono quantitativamente le caratteristiche del campione
- *Media*: somma dei valori divisa per il numero di osservazioni valide, $\bar{x}=\frac{1}{N}\sum_{i=1}^{N}x_i$. Si calcola con `.mean()` ed è sensibile ai valori estremi.
- *Mediana*: valore centrale del campione ordinato. Con un numero dispari di osservazioni si prende il valore centrale; con un numero pari di valori numerici si fa la media dei due centrali. Si calcola con `.median()`.
- *Quantile*: è un valore che permette di *dividere un insieme di dati ordinati in due parti*, in base a una proporzione scelta, i quantili generalizzano il concetto di mediana, permettendoci di scegliere proporzioni diverse, ad esempio il 25% e il 75%. Il parametro *α (alfa)* indica la proporzione scelta, con un valore compreso tra 0 e 1. 
	- Ad esempio, `age.quantile(0.25)` restituisce il primo quartile, cioè il valore di età al di sotto del quale si trova circa il 25% delle osservazioni. In altre parole, identifica la soglia che separa il 25% delle persone più giovani dal restante 75%.
- *Percentile*: è lo stesso concetto, ma la quota viene indicata su una scala da 0 a 100 invece che da 0 a 1.
- *Quartili*: sono i tre quantili che dividono i dati in quattro gruppi, ciascuno con circa il 25% dei dati:
    - **$Q_1$**: dopo il primo gruppo, cioè al 25% dei dati.
    - **$Q_2$**: dopo due gruppi, cioè al 50% dei dati, corrisponde esattamente alla mediana
    - **$Q_3$**: dopo tre gruppi, cioè al 75% dei dati.
- *Moda*: valore più frequente. Si calcola con `.mode()`, che può restituire più valori se ci sono frequenze massime uguali.
#### Misure di dispersione
Le misure di dispersione indicano quanto i valori sono distanti tra loro o dal centro della distribuzione.
- *Minimo*: `.min()`.
- *Massimo*: `.max()`.
- *Range*: differenza tra massimo e minimo, $x_{\max}-x_{\min}$.
- *Varianza*: misura gli scostamenti al quadrato dalla media: $$s^2 = \frac{\sum_{i=1}^{N}(x_i-\bar{x})^2}{N-1}.$$Si calcola con `.var()`, l'unità di misura della varianza è il quadrato dell'unità dei dati, prendendo sempre il dataset con le età delle persone la varianza avrà come unità di misura $anni^2$, dal bisogno di comparere il risultato ottenuto dalla varianza con i dati originali (che non hanno l'unità di misura al quadrato) nasce la deviazione standard
	- La formula base della varianza ha come denominatore semplicemente $N$ questa deve essere utilizzata quando si ha diposizione l'intera popolazione e non uno specifico campione come succederà a noi praticamente sempre, la formula con $N-1$ viene chiama Sample Variance
- *Deviazione standard*: radice quadrata della varianza, $s=\sqrt{s^2}$, espressa nella stessa unità dei dati. Si calcola con `.std()`

> [!DEFINITION] Outlier
> Sono osservazioni che si trovano insolitamente lontane dalla maggior parte dei dati di un insieme. Non sono necessariamente errori: possono rappresentare situazioni rare ma reali e devono essere interpretati nel loro contesto. Gli outlier possono *influenzare significativamente la media e il range*, perché valori particolarmente alti o bassi possono spostare la media e aumentare la distanza tra il minimo e il massimo. 

##### Interquartile range
Questa è una misura di dispersione che indica quanto sono distribuiti i valori nella parte centrale di un insieme di dati, considerando il 50% delle osservazioni centrali, si calcola nel seguente modo
$$IQR = Q_3-Q_1.$$
L'IQR è una misura robusta rispetto ai valori anomali (outlier) perché non dipende direttamente da quest'ultimi (come fa il range), base al risultato che otteniamo possiamo fare le seguenti condiserazioni:
- *IQR piccolo*: i valori centrali sono concentrati in un intervallo ristretto.
- *IQR grande*: i valori centrali sono più dispersi.

Graficamente viene rappresentate in questo modo:
![[3 - 8 ottobre 2026-4.png|center|500]]

> [!EXAMPLE]
> se il primo quartile (Q1) è 20 anni e il terzo quartile (Q3) è 41 anni, allora: $$IQR = 41 − 20 = 21 anni$$ Questo significa che il 50% centrale delle persone ha un'età compresa tra 20 (Q1) e 41 anni (Q1+IQR). L'IQR (21 anni) rappresenta quindi l'ampiezza dell'intervallo, non il suo valore iniziale. Per conoscere i limiti dell'intervallo dobbiamo guardare Q1 e Q3.

##### Statistical Summary
La funzione `.describe()` ritorna alcune statistiche riguardo un dataset viste in questa sezione, usando `age.describe()` otteniamo:
```text
Risultato:
count 714.000000 
mean 29.699118 
std 14.526497 
min 0.420000 
25% 20.125000 
50% 28.000000 
75% 38.000000 
ax 80.000000 
Name: Age, dtype: float64
```

#### Normalizzazione dei dati
La normalizzazione permette di confrontare variabili con scale o unità di misura diverse.
- *Normalizzazione tra 0 e 1*: il minimo diventa 0 e il massimo diventa 1:$$x_i^{\mathrm{norm}}=\frac{x_i-x_{\min}}{x_{\max}-x_{\min}}.$$
- *Normalizzazione tra -1 e 1*: porta i dati nell'intervallo $[-1,1]$: $$x_{i}^{{norm}} = \frac{x_{max}+x_{min}-2x_{i}}{x_{max}-x_{min}}$$
- *Standardizzazione (z-scoring)*: sottrae la media e divide per la deviazione standard: $$z_i=\frac{x_i-\bar{x}}{s}.$$I dati risultanti sono adimensionali, con media 0 e deviazione standard 1, usando la stessa convenzione per calcolare quest'ultima. Richiede una deviazione standard non nulla; **non** rende automaticamente gaussiana la distribuzione e non limita i valori a un intervallo fisso.

```python
weights_norm = (weights-weights.min())/(weights.max()-weights.min()) # tra 0 e 1
weights_norm2 = (weights.max()+weights.min()-2*weights)/(weights.max()-weights.min()) # tra -1 e 1
weights_z = (weights - weights.mean()) / weights.std()
```
#### Indicatori di forma
Descrivono alcuni aspetti della forma della distribuzione, usando la gaussiana come riferimento:
- *Skewness (asimmetria)*: misura l'asimmetria della distribuzione; si calcola con `.skew()`.
	- *Negativa*: coda più lunga verso sinistra.
	- *Positiva*: coda più lunga verso destra.
	- *Vicina a zero*: poca asimmetria secondo questo indicatore; non garantisce da sola una distribuzione simmetrica o gaussiana.
- *Kurtosis (curtosi)*: riguarda soprattutto il peso delle code e la presenza di valori estremi, non semplicemente l'altezza del picco centrale
	- **$>0$**: code più pesanti rispetto alla normale (*leptocurtica*).
	- **$<0$**: code più leggere rispetto alla normale (*platicurtica*).
	- **$=0$**: stessa curtosi della normale (*mesocurtica*)

![[3 - 8 ottobre 2026-5.png|center|500]]
#### Boxplots
Il *boxplot* è una rappresentazione compatta di posizione, dispersione e possibili outlier:
![[Pasted image 20261008174551.png|center|232]]
Nella versione standard di Tukey, usata normalmente da pandas/Matplotlib:
- Il bordo inferiore della scatola indica il **primo quartile** $Q_1$.
- Il bordo superiore indica il **terzo quartile** $Q_3$: la scatola è l'IQR.
- La linea interna rappresenta la **mediana** $Q_2$.
- Il **baffo inferiore** arriva al più piccolo valore osservato maggiore o uguale a $Q_1-1.5\,IQR$.
- Il **baffo superiore** arriva al più grande valore osservato minore o uguale a $Q_3+1.5\,IQR$.
- I punti oltre questi limiti sono **potenziali outlier** secondo questa regola, non necessariamente dati errati.
I baffi non coincidono necessariamente con minimo e massimo, né con le soglie teoriche: terminano su valori effettivamente osservati. Esistono altre versioni del boxplot con convenzioni diverse.
