# Polinomial Regression
Un regressore può tracciare solo delle linee nel grafico, ma potremmo avere la necessità di gestire lo spazio delle feature in modo non lineare. Ovvero usare la *polinomial regression*, che definiamo in questo modo:
$$
 \phi: x \to \text{ nuovo spazio polinomiale } \\
 x_{1} \to [x_{1},x_{1}^2] \\
 x_{1} \to [x_{1},x_{2}, x_{1}^2, x_{2}^2, x_2x_{2}]
$$
non trasformiamo il modello in maniera non lineare, ma le nostre feature diventano non lineari, in pratica creo nuove feature ma di grado più alto (grado del polinomio)

se non ho abbstanza parametri allora avrò problemi di *underfitting* (non riesco ad ottenere neanche in training delle buone performance), se ne ho troppi allora avrò il problem dell'*overfitting* (performance ottime in training ma basse in validation, sto praticamente memorizzando a memoria i dati)

come faccio a regolarizzare il mio polinomio in modo che abbia il numero giusto di parametri? modifico la loss function in questo modo
$$
J(\theta) = \frac{1}{2N}\sum_{i=1}^{N}\bigl(f_\theta(x^{(i)}) - y^{(i)}\bigr)^2 + \lambda\sum_{j=1}^{d} \theta^2
$$
il parametro aggiunto alla fine riduce l'errore dovuto all'overfitting (*fattore di regolarizzazione*)

**come? non l'ho capito**

posso comunque usare la discesa del gradiente anche con il regressore polinomiale, cambia solo che la derivata di $J(\theta)$ è diverso

Per capire se il modello funziona nel modo giusto faccio MSE sul test set, lo fa sempre bene? No, abbiamo altri modi:
- MAE (Mean absolute error): fa la media degli errori, ma con il valore assoluto
- RMSE (Root MSE): è praticamente una deviazione standard, quanto cambiano i miei valori rispetto alla media di errore (MSE normale)
- Rec curve: 
	- prendo tutti gli errori $e^1 \dots e^n$
	- li ordino
	- e poi faccio praticamente una Cumulative Distribution Function
	- ???

*Chiusa la questione della regressione*

# Classificazione
Inseriamo i valori dentro delle classi, ne abbiamo diversi tipi

- *Classificazione binari* $h_{\theta}: R^d \to {0,1}$
- *Classificazione multiclass* $h_{\theta}: R^d \to {\{0,1 \dots k-1\}}$  k = numero classi

Come sempre dobbiamo definire diverse cose:
- Modello
- Loss
- learning algo
- valutazione

Di seguito viene approfondita la classificazione binaria, fatta quella possiamo usarne diversi per creare un classificatore multiclass

Per definire il modello possiamo usare un regressore? Si, prendiamo il valore continuo del regressore e mettiamo una soglia sotto la quale il nostro valore è nella prima classe piuttosto che nella seconda, ma questa cosa non va bene perché la regressione lineare non ha limite potrebbe ritornando valore in $R$

si preferisce usare un *sigmoide*: 
$$\theta(z) = \frac{1}{1+e^{-z}} \text{ questa funzione ha un grafico che tende ad 1 }$$

la funzione del nostro modello diventa: 
$$h_{\theta}(x) = \frac{1}{1+e^{\theta_{0}+\theta_{1}x_{1}+\theta_{2}x_{2}}}$$
in questo modo riusciamo ad avere un upperbound e lowerbound (cosa che con il regressore non era fattibile)

possiamo vedere: $h_{\theta}(x) = P(y = 1|x,\theta) \implies P(y = 0|x,\theta) = 1-h_{\theta}(x)$. 
con $h_{\theta}(x) = 0.7$ allora la probabilità di essere di classe 1 è 70%

Stiamo comunque tracciando una linea (una decision boundary) ma lo facciamo usando un'altra funzione

non ho capito in modo ben preciso come questa cosa diventa una combinazione lineare: ha detto che posso fare il training nel mio pc e poi usare una combinazione lineare in un dispositivo più debole e rendere la classificazione (operazione pesante) portabile e low resources

*Abbiamo trovato il modello, dobbiamo cercare una funzione di loss*, per la loss non possiamo più usare MSE, cerchiamo di definirla di seguito:

Ci serve una funzione che resti nei limiti di 0, 1 (essendo classificazione binaria)

$$loss(h_{\theta}(x)) = - \log(h_{\theta}(x)) \text{ se } y = 1 \\ loss(h_{\theta}(x)) = - \log(1 - h_{\theta}(x)) \text{ se } y = 1$$

cercando di unirle possiamo dire: $$-y\log(h_{\theta}(x))-(1-y)\log(1-h_{\theta}(x))$$
Da qui arriviamo alla *cross-entropy loss (classificazione binaria)*: 
$$
J(\theta) = \frac{1}{m} \sum_{i = 1}^m (-y^i\log(h_{\theta}(x^i))-(1-y^i)\log(1-h_{\theta}(x^i)))
$$
potremmo aggiungere il fattore di regolarizzazione per evitare problemi di overfitting $\Sigma\frac{\lambda}{m}v_{j}^2$

con questa formula stiamo facendo la distanza tra due distribuzioni di probabilità, la probabilità di essere di classe 0 e quella di essere di classe 1

*Abbiamo trovato la funzione di loss, come learning algo usiamo sempre la discesa del gradiente, cambia semplicemente la funzione di loss da derivare*

Vedremo come costruire classificatori multiclasse usando classificatori binari, e poi come costruirli direttamente
