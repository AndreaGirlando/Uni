###### Ingredienti del machine learning
Per impostare un problema di machine learning abbiamo bisogno di:
- **Task**: il problema che vogliamo risolvere
- **Modello**: una funzione parametrizzata che associa un output a un input
- **Algoritmo di learning**: il metodo con cui impariamo i parametri del modello
- **Funzione di loss**: misura quanto le predizioni si discostano dai risultati attesi e guida l'apprendimento
- **Misure di valutazione**: ci permettono di misurare le performance del modello su dati di validation/test
- **Dataset**: i dati da cui imparare; nel supervised learning abbiamo coppie $(x^{(i)}, y^{(i)})$

##### I primi modelli di machine learning

Le reti neurali sono un insieme di neuroni artificiali collegati tra loro. L'idea dei primi modelli era simulare in modo semplificato il funzionamento di un neurone biologico: i *dendriti* ricevono i segnali, il *corpo cellulare* li elabora e l'*assone* trasmette il segnale ad altri neuroni.

###### Neurone di McCulloch e Pitts
Abbiamo degli input binari e una soglia $v$. Gli input possono essere *eccitatori* oppure *inibitori*, sommiamo gli input: se la somma è maggiore o uguale alla soglia, l'output è 1, altrimenti è 0.

Con $n$ input eccitatori riusciamo a costruire delle porte logiche:
- *AND*: impostiamo $v = n$, quindi tutti gli input devono valere 1
- *OR*: impostiamo $v = 1$, quindi basta che un input valga 1

Le limitazioni principali sono che gli input sono binari, hanno tutti lo stesso peso e la soglia va impostata manualmente: non abbiamo ancora una procedura automatica di training. Un singolo neurone di questo tipo non riesce a rappresentare lo XOR.
![[16 ottobre 2026-1.png]]
 
###### Percettrone di Rosenblatt
Abbiamo $n$ feature in input, ciascuna con un peso $w_j$. Attraverso una *funzione a gradino* classifichiamo gli input in due classi, infatti l'output è 0 oppure 1:
$$h_w(x) = \begin{cases}
1 & \text{se } \displaystyle\sum_{j=1}^{n} w_j x_j \ge v \\
0 & \text{altrimenti}
\end{cases}$$
![[16 ottobre 2026-2.png|center|360]]
Possiamo incorporare la soglia introducendo un *bias* $w_0 = -v$ e una feature costante $x_0 = 1$. La condizione diventa: $$w_0 + \sum_{j=1}^{n} w_j x_j \ge 0$$
Graficamente il confine che divide le due classi viene chiamato *decision boundary*. Con due feature è una retta: $$w_0 + w_1x_1 + w_2x_2 = 0$$
![[16 ottobre 2026-3.png|center|406]]
Un singolo percettrone può separare correttamente le classi solo se i dati sono *linearmente separabili*.
###### Training del percettrone
Durante il training:
- inizializziamo i pesi
- per ogni campione $x^{(i)}$ calcoliamo la predizione $\hat y^{(i)} = h_w(x^{(i)})$
- confrontiamo la predizione con l'etichetta corretta $y^{(i)}$
- se la predizione è sbagliata, aggiorniamo i pesi
La regola di aggiornamento, includendo il bias tramite $x_0^{(i)} = 1$, è:

$$w_j \leftarrow w_j + \alpha\bigl(y^{(i)} - \hat y^{(i)}\bigr)x_j^{(i)}, \qquad j = 0, \dots, n$$

$\alpha > 0$ è il *learning rate*; nella regola standard possiamo porlo uguale a 1. Se il risultato è corretto, la differenza è 0 e i pesi non cambiano. Modificando i pesi spostiamo anche la decision boundary.
###### XOR network
Lo XOR restituisce 1 se i due input binari sono diversi, 0 se sono uguali:
- $(0,0) \to 0$
- $(0,1) \to 1$
- $(1,0) \to 1$
- $(1,1) \to 0$

Non possiamo dividere queste due classi con una sola retta: il problema **non è linearmente separabile**, quindi un singolo percettrone non basta.

Se disegniamo i quattro input, otteniamo i vertici di un quadrato: i punti della classe 1 occupano una diagonale, quelli della classe 0 l'altra. Non esiste una retta che lasci entrambi i punti della classe 1 da un lato ed entrambi quelli della classe 0 dall'altro. Cambiare i pesi sposta la retta, ma non elimina questo limite.

![[16 ottobre 2026-4.png|center|158]]
La soluzione è usare una *rete di percettroni*: uno **strato nascosto** trasforma gli input in una nuova rappresentazione, poi un neurone di uscita combina i risultati. Ad esempio:
- un neurone riconosce il caso $(1,0)$ con la condizione $x_1 - x_2 \ge 0.5$
- un altro riconosce il caso $(0,1)$ con la condizione $x_2 - x_1 \ge 0.5$
- il neurone finale fa l'OR delle due uscite
![[16 ottobre 2026-5.png|center|259]]
Quindi non stiamo solo trasformando un input binario in un altro: stiamo cambiando la rappresentazione dei dati in modo da rendere le classi separabili nello spazio trasformato. La regola di training del singolo percettrone non si applica direttamente a tutta una rete multistrato.

##### Regressione

A differenza della classificazione, nella regressione vogliamo predire un valore reale, o un vettore di valori reali, invece di un'etichetta di classe.

###### Tipi di regressione
Possiamo distinguere:
- *Single regression*: $h_w: \mathbb{R} \to \mathbb{R}$, un input e un output (dato il metraggio di una casa ti do il suo valore)
- *Multiple regression*: $h_w: \mathbb{R}^n \to \mathbb{R}$, più feature in input e un solo output (metraggio, numero di stanze, ecc. per predire il valore della casa)
- *Multivariate regression*: $h_w: \mathbb{R}^n \to \mathbb{R}^m$, più feature in input e più valori in output

###### Regressione lineare semplice
Nella regressione lineare semplice cerchiamo una retta che approssimi la relazione tra input e output:

$$h_w(x) = w_0 + w_1x$$

$w_0$ è l'intercetta, $w_1$ è la pendenza. Imparare significa trovare i valori di questi parametri che rendono le predizioni vicine ai valori reali: non è necessario che la retta passi esattamente per tutti i punti.

###### Regressione lineare multipla
Nella regressione lineare multipla abbiamo un peso per ciascuna feature, più il bias:

$$h_w(x) = w_0 + w_1x_1 + \dots + w_nx_n$$

Ponendo $x_0 = 1$ possiamo scrivere $h_w(x) = \sum_{j=0}^{n} w_jx_j = w^\top x$. Rispetto al percettrone non applichiamo la funzione a gradino: l'output resta un valore continuo.

###### Funzione di loss

Per capire quanto il modello sbaglia confrontiamo le predizioni $h_w(x^{(i)})$ con i valori corretti $y^{(i)}$.

Con $N$ campioni di training usiamo l'errore quadratico medio (*MSE*), qui moltiplicato per $1/2$:

$$J(w) = \frac{1}{2N}\sum_{i=1}^{N}\bigl(h_w(x^{(i)}) - y^{(i)}\bigr)^2$$

- il quadrato evita che errori positivi e negativi si annullino e penalizza di più gli errori grandi
- dividiamo per $N$ per fare la media sui campioni
- il fattore $1/2$ serve a semplificare le derivate e non cambia il punto di minimo

L'obiettivo del training è **minimizzare $J(w)$**. Nella regressione lineare questa loss è convessa rispetto ai pesi, quindi ha una forma a tazza e non presenta minimi locali diversi dal minimo globale.

###### Feature scaling

Se le feature hanno scale molto diverse, la discesa del gradiente può essere lenta. Per questo le portiamo su scale simili, ad esempio con:

- *Standardizzazione (z-score)*: $x_j \leftarrow \frac{x_j - \mu_j}{\sigma_j}$
- *Min-max*: $x_j \leftarrow \frac{x_j - x_j^{\min}}{x_j^{\max} - x_j^{\min}}$

Media, deviazione standard, minimo e massimo si calcolano **solo sul training set** e si riusano su validation/test, senza ricalcolarli, per evitare *data leakage*.

##### Discesa del gradiente

È un algoritmo iterativo che modifica i pesi per diminuire la loss. Possiamo immaginare di partire da un punto sulla superficie di $J$ e muoverci verso il basso.

Se consideriamo un solo parametro:
- quando la derivata è positiva, diminuiamo il parametro
- quando la derivata è negativa, aumentiamo il parametro

Con più parametri usiamo il *gradiente*, cioè il vettore delle derivate parziali. Il gradiente indica la direzione di massima crescita: per diminuire la loss ci muoviamo nella direzione opposta.

###### Aggiornamento dei parametri
La regola di aggiornamento è:

$$w_j \leftarrow w_j - \alpha\frac{\partial J(w)}{\partial w_j}$$

Per la loss quadratica della regressione lineare abbiamo:

$$\frac{\partial J(w)}{\partial w_j} = \frac{1}{N}\sum_{i=1}^{N}\bigl(h_w(x^{(i)}) - y^{(i)}\bigr)x_j^{(i)}, \qquad j = 0, \dots, n$$

Quindi l'algoritmo consiste nel:
1. inizializzare i pesi
2. calcolare le predizioni e le derivate della loss sui dati di training
3. aggiornare **tutti i pesi contemporaneamente**, usando le derivate calcolate con i vecchi pesi
4. ripetere finché la loss cambia poco, il gradiente è vicino a 0 oppure raggiungiamo il numero massimo di iterazioni

###### Learning rate
Il *learning rate* $\alpha$ è un iperparametro che controlla l'ampiezza del passo:
- se è troppo piccolo, l'apprendimento è lento
- se è troppo grande, possiamo oltrepassare il minimo, oscillare o divergere

*La lezione si è fermata prima della regressione polinomiale.*
