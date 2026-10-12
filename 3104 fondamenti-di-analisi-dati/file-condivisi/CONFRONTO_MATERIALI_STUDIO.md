# Confronto dei materiali di Fondamenti di Analisi Dati

Confronto del 10 ottobre 2026 tra `github/Fondamenti di Analisi Dati.pdf` e i 22 PDF presenti in `sitoWeb`: 19 documenti dei moduli teorici e 3 introduttivi di laboratorio. Ho confrontato l'indice e il contenuto degli appunti con gli argomenti, le spiegazioni, gli esempi e gli esercizi dei documenti del sito; questo non costituisce una verifica di ogni formula.

**Giudizio: gli appunti sono utili come base in italiano per gran parte della teoria, ma non sono sufficienti come unica fonte per studiare tutto il materiale fornito.** Mancano due nuclei del primo modulo — analisi causale e storytelling — e praticamente tutto il percorso operativo in Python. Inoltre, alcune parti richiedono correzioni.

Gli appunti hanno 206 pagine PDF e riportano l'anno accademico **2025/2026**, versione **16 gennaio 2026**. I documenti del sito riportano **2026/27**. La differenza di anno non dimostra da sola che ogni contenuto sia cambiato, ma rende necessario confrontarli con i materiali del proprio corso. L'autore stesso presenta il PDF, nella prefazione, come appunti personali sulla parte teorica e invita a consultare il materiale ufficiale.

## Cosa coprono gli appunti

Sono presenti i principali argomenti di statistica descrittiva, probabilità, associazione, distribuzioni, inferenza, regressione lineare e logistica, interazioni e regressione polinomiale, analisi predittiva, validazione, regolarizzazione Ridge/Lasso, classificazione e KNN, classificatori generativi, rappresentazione dei dati, K-means, stima della densità e PCA.

Non bisogna confondere una numerazione diversa con un'omissione: gli appunti riordinano il materiale. Ad esempio, l'analisi predittiva è nel capitolo 7, la logistica nel capitolo 11, e il capitolo 9 riunisce contenuti dei file `10_extending_regression.pdf` e `14_regression_for_prediction.pdf`. Diverse visualizzazioni sono raccolte nel capitolo 17.

## Confronto file per file

La colonna «Negli appunti» identifica i capitoli pertinenti, non certifica una corrispondenza completa. Le pagine dei file del sito indicate sotto sono quelle del relativo PDF, contate da 1.

| File in `sitoWeb` | Negli appunti | Contenuti aggiuntivi o differenze rilevanti |
| --- | --- | --- |
| `00_Modulo introduttivo/lab_01_setup.pdf` | Nessun capitolo corrispondente | Preparazione dell'ambiente, Anaconda, esecuzione di Python, Jupyter e Google Colab. |
| `00_Modulo introduttivo/lab_02_python_crash_course.pdf` | Nessun capitolo corrispondente | Sintassi e strutture di Python: tipi, liste, tuple, dizionari, insiemi, condizioni, cicli, funzioni, classi, eccezioni, moduli ed esercizi. |
| `00_Modulo introduttivo/lab_03_python_for_data_science.pdf` | Nessun capitolo operativo corrispondente | NumPy, indicizzazione e broadcasting; Matplotlib; Pandas, Series/DataFrame, selezione, valori mancanti, aggregazioni, groupby, crosstab, join e lettura/scrittura CSV. Percorso pratico di pulizia dei dati. |
| `01_Modulo_1/01_key_concepts.pdf` | Cap. 1 | Il nucleo concettuale è presente. Il sito aggiunge il lavoro concreto sul Titanic: caricamento, ispezione, gestione dei valori mancanti, conversioni, creazione di feature e trasformazioni di formato. |
| `01_Modulo_1/02_describing_visualizing.pdf` | Cap. 2 e 17 | Principali statistiche e grafici presenti. Il sito sviluppa il calcolo e l'interpretazione con esempi in Python ed esercizi; approfondisce anche la scelta e i limiti delle rappresentazioni grafiche. |
| `01_Modulo_1/03_probability.pdf` | Cap. 3; Bayes ripreso nel cap. 12 | Principali regole presenti, ma il sito offre una sequenza più estesa di esempi numerici e tabelle di probabilità congiunte, marginali e condizionate, anche calcolate con Pandas. |
| `01_Modulo_1/04_association.pdf` | Cap. 4 e 17 | Principali misure presenti. Il sito tratta esplicitamente anche la correlazione punto-biseriale per una variabile binaria e una continua, pp. 22–23, e contiene applicazioni ed esercizi. |
| `01_Modulo_1/05_distributions.pdf` | Cap. 5; stima gaussiana anche nel cap. 15 | Copertura ampia delle distribuzioni principali. Il sito aggiunge esempi di calcolo e stima in Python, confronto tra normalizzazioni degli istogrammi ed esercizi. |
| `01_Modulo_1/06_statistical_inference.pdf` | Cap. 6 | Negli appunti diversi test sono descritti brevemente: a p. 66 stampata sei test occupano complessivamente circa una pagina. Il sito ne mostra l'uso su dati reali. A p. 18 aggiunge intervalli di confidenza per **varianza e proporzioni**, che non trovano una trattazione corrispondente negli appunti. |
| `01_Modulo_1/08_linear_regression.pdf` | Cap. 8 | Teoria principale presente. Il sito sviluppa un'analisi completa con statsmodels: lettura dei risultati, diagnostica, confronto di modelli e rimozione delle variabili, oltre agli esercizi. |
| `01_Modulo_1/09_logistic_regression.pdf` | Cap. 11 | Modello, odds, loss e interpretazione dei coefficienti presenti. Il sito aggiunge analisi complete dei dataset, stima con statsmodels, lettura delle tabelle e selezione delle variabili. |
| `01_Modulo_1/10_extending_regression.pdf` | Cap. 9 e 11 | Interazioni, polinomi e logistica multiclasse sono presenti, ma distribuiti in capitoli diversi. Nel sito gli esempi applicativi e la lettura dei coefficienti sono più sviluppati. |
| `01_Modulo_1/11_causal_analysis.pdf` | **Manca una trattazione corrispondente** | Controfattuali, potential outcomes, ATE/ATT, bias, esperimenti randomizzati, grafi causali, catene, cause comuni, collider, d-separation, confondenti, mediatori, percorsi backdoor e uso della regressione per controllare i confondenti. Non basta il richiamo negli appunti al fatto che correlazione e causalità sono diverse. |
| `01_Modulo_1/12_storytelling.pdf` | **Manca una trattazione corrispondente** | Scelta della visualizzazione rispetto al pubblico, eliminazione del superfluo, attenzione, accessibilità, struttura narrativa, comunicazione dell'incertezza e dei limiti causali. Il capitolo 17 degli appunti spiega tipi di grafici, ma non sostituisce questi contenuti. |
| `02_Modulo_2/13_predictive_analysis.pdf` | Cap. 7 | Copertura ampia di learning, ERM, capacità, bias/varianza e validazione. Il sito esplicita anche la scomposizione dell'errore quadratico atteso in bias al quadrato, varianza e rumore irriducibile, p. 22; negli appunti il trade-off è spiegato soprattutto qualitativamente. |
| `02_Modulo_2/14_regression_for_prediction.pdf` | Cap. 9; validazione nel cap. 7 | MSE/RMSE/MAE, overfitting e Ridge/Lasso presenti. Manca il percorso operativo scikit-learn: split, fit/transform/predict, preprocessing, **Pipeline e GridSearchCV**, pp. 28–30. Il sito include anche un confronto con un regressore neurale, pp. 31–33. |
| `02_Modulo_2/15_classification.pdf` | Cap. 10 e 11 | Metriche, ROC/AUC, soglia e statistica di Youden, KNN, dimensionalità, medie macro/micro/weighted e strategie multiclasse sono presenti. Il sito aggiunge implementazioni complete, standardizzazione, tuning e valutazione finale su test. |
| `02_Modulo_2/16_generative_classifiers.pdf` | Cap. 12 | MAP, QDA/LDA, Naive Bayes gaussiano e multinomiale, smoothing e underflow sono presenti. Il sito aggiunge il confronto pratico tra modelli su testi: vectorizer, matrici sparse/dense, tempi, prestazioni ed esercizi sulle assunzioni e sul numero di parametri. |
| `02_Modulo_2/17_data_representation.pdf` | Cap. 13 | Spazio delle feature, norme, distanze e rappresentazioni estratte da modelli sono presenti. Mancano i laboratori comparativi su immagini e testi: pixel o conteggi grezzi contro feature apprese, CIFAR-10, spam e sentiment analysis, pp. 12–35. |
| `02_Modulo_2/18_clustering.pdf` | Cap. 14 | K-means, ottimizzazione, gomito e silhouette presenti. Il sito illustra più estesamente le iterazioni e aggiunge un percorso completo di segmentazione dei clienti, con scaling, scelta delle feature e interpretazione dei cluster, pp. 25–42. |
| `02_Modulo_2/19_density_estimation.pdf` | Cap. 15 | Istogrammi, KDE, kernel, bandwidth, gaussiana, GMM, soft clustering e richiamo a EM presenti. Il sito aggiunge l'applicazione della stima di densità alla **rilevazione di anomalie**, confrontando modelli tramite score e ROC/AUC, pp. 20–26. |
| `02_Modulo_2/20_pca.pdf` | Cap. 16 e 17.8 | Fondamenti geometrici e algebrici presenti. Il sito aggiunge applicazioni: visualizzazione di dati ad alta dimensione, **Principal Component Regression**, compressione e ricostruzione di immagini, eigenfaces e confronto di classificatori con/senza PCA, pp. 15–35. |

Gli esercizi del sito sono un'integrazione trasversale: gli appunti contengono esempi e figure, ma non offrono un percorso equivalente di esercitazione.

## Due errori concreti negli appunti

Qui uso i numeri **stampati sulle pagine** degli appunti; il visualizzatore PDF li trova aggiungendo 14.

1. **P. 64 stampata / p. 78 PDF, test sulla moneta.** Compare prima un valore di circa 1,6% per la probabilità di ottenere almeno 9 teste in 10 lanci di una moneta equa. Il valore corretto è `11/1024 ≈ 1,074%`. Poco dopo compare inoltre un fattore `(0,5)^10` duplicato in una formula. Il risultato bilaterale finale, circa 2,14%, è invece sostanzialmente corretto. La pagina contiene dunque passaggi incompatibili tra loro, pur arrivando alla decisione corretta.
2. **P. 179 stampata / p. 193 PDF, sezione 16.2.9.** Il testo identifica i pesi delle feature nelle componenti principali con gli **autovalori**. È una confusione: i coefficienti della combinazione lineare sono dati dalle componenti degli **autovettori**; gli autovalori indicano la varianza delle rispettive componenti. Per i loadings esistono convenzioni di scala diverse, ma non sono semplicemente gli autovalori. Il materiale del sito, `20_pca.pdf` p. 14, parla correttamente dei pesi attribuiti alle feature.

Questi esempi non sono un elenco completo degli errori. Anche i materiali del sito contengono passaggi da leggere criticamente: ad esempio, `11_causal_analysis.pdf` p. 33 descrive come non significativa una relazione la cui tabella riporta un p-value arrotondato a 0,000 e un intervallo del coefficiente che esclude lo zero.

## Come usarli per studiare

1. **Usa gli appunti per una prima lettura in italiano** e per costruire una mappa dei concetti.
2. **Integra interamente analisi causale e storytelling.** Per storytelling il PDF del sito è solo una sintesi: dice esplicitamente che le slide con le figure del libro vengono condivise direttamente dal docente e non sono riprodotte lì.
3. **Lavora sugli esempi e sugli esercizi del sito**, soprattutto inferenza, regressione, classificazione e validazione. Saper riconoscere una definizione non equivale a saper scegliere e applicare il metodo.
4. **Studia i tre laboratori iniziali secondo la tua preparazione**: se conosci già Python puoi scorrere setup e sintassi, ma NumPy/Pandas e il percorso scikit-learn restano necessari per riprodurre le analisi.
5. **Controlla sul materiale del tuo anno i dettagli dell'esame.** Il PDF locale di storytelling indica che la presentazione del progetto è la parte orale, con al massimo 15 slide, e richiama la comunicazione dell'incertezza e dei possibili confondenti. Non ho verificato una pagina esterna del programma o dell'esame: il giudizio qui riguarda esclusivamente i file locali forniti.

**Scelta consigliata:** appunti come base di lettura, materiali del sito come riferimento per copertura, applicazioni ed esercizi. Studiare soltanto il PDF GitHub lascerebbe lacune concrete.
