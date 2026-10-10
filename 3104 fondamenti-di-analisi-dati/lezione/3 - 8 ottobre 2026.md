---
color: ""
---
link: https://antoninofurnari.github.io/fad-2627/notes/02_describing_visualizing.html
#### Frequenze assoluto
Le frequenze assolute sono il numero di volte in un cui appare uno specifico valore (conto quante volte uno specifico valore è presente dentro il dataset) posso usare .value_counts()

#### Data visualization
Direttamente usando pandas possiamo creare dei veri e propri grafici interattivi, internamente userà mathplot.lib ma ci sono diverse metologie che ci fanno risparmiare tempo

![[Pasted image 20261008152319.png|500]]
Dato questo semplice grafico sono in grado di capire che alcune cose hanno più frequenza di altre

#### Frequenze relative
Frequenze che servono per mettere in relazione dei "conteggi" tra di loro, la formula è questa: 
![[Pasted image 20261008152900.png|350]]

### Continuo data visualization

#### Grafico a barre
![[Pasted image 20261008153704.png|500]]
in semplice grafico vediamo due plot, quello degli uomini in blu e quello delle donne in rosso, sempre nello stesso grafico, già da qui riusciamo a carpire diverse cose: 
- Mediamente le donne sono più basse degli uomini (le barre arancioni sono quelle più a sinistra)
- Ecc..

Ci sono altri modi di usare il grafico a barre:

![[Pasted image 20261008153937.png|500]]![[Pasted image 20261008153947.png|500]]Contiamo il numero di uomini e donne nel totale, nel secondo abbiamo più un evidenza percentuale (frequenza relativa) piuttosto che il conteggio del primo (frequenza assoluta)

#### Pie Charts
Usare dei grafici a torta non è ottimale sopratutto per questo tipo di cose, siamo abituati a capire meglio quale è la differenza tra due linee piuttosto che tra due angoli. Può essere utile solo quando abbiamo dei grafici di questo tipo:
![[Pasted image 20261008155256.png|500]]
#### Empirical Cumulative Distribution Function

Nel caso in cui il campione non fosse discreto le differenze tra i valori diventano piccole e sono soggette a rumore. Andando a creare grafici di questo tipo: 
![[Pasted image 20261008155418.png|500]]
ovvero dei grafici molto difficili da leggere. Ci sono diversi modi come per risolvere questi problemi come l'ECDF:
![[Pasted image 20261008155531.png|200]]

```
a = pd.Series([1, 5, 2, 6, 5, 4, 3, 5, 4, 2, 4, 5, 6, 4, 4, 3])
a.value_counts(normalize=True).sort_index()

Di seguito il risultato
1    0.0625
2    0.1250
3    0.1250
4    0.3125
5    0.2500
6    0.1250
Name: proportion, dtype: float64

a.value_counts(normalize=True).sort_index().cumsum()
Di seguito il risultato
1    0.0625
2    0.1875
3    0.3125
4    0.6250
5    0.8750
6    1.0000
Name: proportion, dtype: float64
```
In pratica mi dice in modo relativo la percentuale di elementi minore o uguale ad x
![[Pasted image 20261008160323.png|500]]
- il 65% circa degli uomini (linea blu) pesa al massimo 40kg
- le donne pesano mediamente meno degli uomini
Questo grafico è si utile ma non è facile da leggere, il confronto è complicato, per il peso usando il bar chart era più semplice. 
#### istogramma
Per risolvere questo problema possiamo semplicemente raggruppare il valori che sono più simili tra di loro "quantizziamo"
```
heights_quantized = pd.cut(heights, bins=10) #crea 10 gruppo usando tutte le altezze
heights_quantized.value_counts().sort_index().plot.bar(figsize=(18,6))
plt.grid()
plt.show()
```

Otteniamo questo grafico
![[Pasted image 20261008160944.png|500]]
Molti casi sono stati raggrupati è i grandi spike sono diventati degli spike medi, è importante scegliere un numero di bins sensato:
- **pochi bin**: ho una perdita di dettaglio
- **tanti bin**: ho troppo dettaglio, aumenta la confusione e soffro dello stesso problema iniziale
esitono delle erustiche per risolvere il problema
![[Pasted image 20261008161314.png|200]]
In generale queste formule hanno senso quando disegnare il grafico è difficile (come in passato) ora la creazione del graifico è istantanea quindi ci basta provare il numero giusto di bin fino a quando non otteniamo un risultato consono.
Inserendo entrambi dati sul peso nello stesso istogramma otteniamo una visualizzazione più intuitiva
![[Pasted image 20261008161653.png|500]]
la tendenza è sempre la stessa, sia per uomini che per donne ma gli uomini si trovano più "a sinistra" perché generalemnte sono più pensanti delle donne

#### Stima della densità
il problema degli istogrammi è creano dei grafici frastagliati quindi nasce l'esigenza di stimare la densità in modo da creare una linea quanto più continua possibile
![[Pasted image 20261008161936.png|500]]
 quello che ci serve sapere in questo momento è sapere che esiste una funzione "densità" che prende in input un parametro *bandwidth* che determina la "sensibilità al dettaglio", di seguito il grafico che ci fa vedere le differenze tra le varie scelte di bandwidth
 ![[Pasted image 20261008162156.png|500]]
 Possiamo ovviamente mixare diverse serie, come prima otteniamo un grafico dove mettiamo il peso delle donne e degli uomini a confronto
 ![[Pasted image 20261008162247.png|500]]
#### Mixes
Posso mixare sia istrogrammi che grafici di densità e creare un *density histogram*
![[Pasted image 20261008164532.png|500]]
#### Statistiche di base
sono dei numeri che ci danno una rappresentazione più quantitativa delle informazioni
- **Media**: somma di tutti gli elementi e divisione per il numero di elementi
- **Mediana**: quando gli elementi possono essere ordinati la mediana è l'elemento che divide a metà l'insieme
- **Percentile**: è una generalizzione della mediana, potrei decidere di dividere un insieme ordinato non in due parti uguali ma in 100 parti
	- se lo dividio in quattro parti ottengo un *quartile*
	- se lo divido in n parti avrò un *quantile* di ordine n
- **Moda**: elemento più frequente dell'insieme
#### Misure di dispersione
La distribuzione potrebbe essere motlo dispersa attorno ad un valore centrala quindi avere queste misure ci permette di avere delle informazioni sulla quale fare delle analisi
- **Minimo**
- **Massimo**
- **Range**: la differenza tra il massimo e il minimo
![[Pasted image 20261008170922.png|500]]Graficamente lo vediamo subito, quelli fuori dal quel range sono dei valori che "rompono" le medie perché troppo diversi dai valori reali, questo valori sono detti *outlier*, in generale il range non è ottimale come misura di dispersione una cosa più interessante è usare un range detto *interquartile range (IQR)* in specifico misura le differenze in termini di range tra il primo e il terzo quartile

Altre misure che resistono agli outlier sono: 
- **Varianza**: che osserva quanto i dati deviano dalla media, prendo la media e  calcolo lo scostamento da quest'ultima da ogni valore e poi divido questa sommatoria per n-1. L'unità di misura della varianza è il quadrato dell'unità di misura di $x$
![[Pasted image 20261008172011.png|500]]
- **Deviazione standard**: basta fare la radice quadrata della varianza


#### Normalizzazione dei dati
la normalizzazione dei dati consiste nell'usare delle tecniche che permette un confronto con dei dati che hanno diverse unità di misura
- **Normalizzazione tra 0 e 1**: i dati vengono scalati in modo che il massimo e il minimo siano 0 e 1
```
weights_norm = (weights-weights.min())/(weights.max()-weights.min())
weights_norm6 
```
- **Normalizzazione tra -1  e 1**: i dati vengono scalati in modo che il massimo e il minimo siano -1 e 1
```
weights_norm2 = (weights.max()+weights.min()-2*weights)/(weights.max()-weights.min())
weights_norm2
```
- **z-scoring**: è utile normalizzare i dati in modo che abbiamo 0 di media e 1 di deviazione standard

#### Indicatori di forma
Cerchiamo di descrivere un grafico rispetto al grafico gaussiano, ne abbiamo di diversi tipi
- **Skewness**: è un indicatore dello "sbilanciamento" rispetto al valore iniziale
	- *Negativa*: se la distribuzione è sbilanciata verso sinistra
	- *Positiva*: se la distribuzione è sbialnciata verso destra
	- *Close to zero*: nel caso di poco sbilanciamento
- **Kurtosis**: è un indicatore che ci indica se nel grafico avrò "una punta" nel punto centrale del grafico
	- *>0*: more peaked
	- *<0*: more flat
	- *=0*: vicina alla distribuzione guassiana

#### Sommario statistico
Tutti i dati visti fino ad adesso vengono descritte nel sommario statistico
![[Pasted image 20261008174344.png|500]]
#### Boxplots
un metodo di rappresentazione che descrive alcune caratteristiche di una specifica analisi dei dati, è fatto in qeusto modo:
![[Pasted image 20261008174551.png|500]]
Contengono diverse informazioni: 
- primo quartile
- terzo quartile
- le linee orizzontali rappresentano la mediana
- i "baffi" rappresentano i dati che vanno da A a B (A e B vengono definiti in base al boxplot)
- i punti sopra e sotto i "baffi" sono gli outlier, punti che cadono fuori dai range definiti dai "baffi"
anche attraverso i boxplot possiamo confrontare i pesi degli uomini e delle donne nei campioni analizzati anche precedemente

