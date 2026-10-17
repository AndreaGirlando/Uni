###### Definizioni iniziali
**A. Samuel nel 1959** definì il machine learning come il campo di studi che permette ai computer di imparare senza essere esplicitamente programmati per risolvere un determinato problema.

Prendiamo un set di *dati* e li usiamo  per risolvere un *task*

- Di solito abbiamo: dati → programma che risolve un task → output.
- Con il machine learning abbiamo: dati → learning algorithm → modello che risolve uno specifico task. Nel caso supervisionato, durante l'apprendimento forniamo anche gli *output attesi*.

Durante la *fase di learning* il modello apprende dai dati, modificando i propri parametri. Durante la *fase di inferenza* usiamo il modello per produrre output su nuovi dati. Se conosciamo anche gli output corretti, possiamo confrontarli con le predizioni e valutare il modello: è quello che facciamo nel *testing*.

Molti problemi affrontati con il ML presentano un certo grado di *incertezza*: i dati possono essere variabili, incompleti o rumorosi e non conosciamo tutte le situazioni possibili. L'obiettivo non è solo risolvere i casi già visti, ma *generalizzare* a nuovi esempi.

**Esempi di problema**:
- riconoscere una mail spam o non spam
	- input: testo della mail
	- output: etichetta "spam" (0) o "non spam" (1); l'insieme delle etichette possibili è detto *insieme delle classi*
	- l'associazione tra numeri e classi è una convenzione, basta mantenerla coerente
- colorazione di un'immagine

**Mitchell** ha dato una definizione di machine learning basata su tre elementi:
"un computer impara dall'*esperienza E* rispetto a un *task T* e a una *misura di performance P* se le performance sul task T, misurate mediante P, migliorano con l'esperienza E"

Nel caso delle mail abbiamo:
- *T*: distinguere spam e non spam
- *E*: un insieme di mail già etichettate
- *P*: per esempio, la percentuale di classificazioni corrette

Durante il processo di apprendimento è importante poter misurare le performance, altrimenti non possiamo capire se il modello sta veramente apprendendo. Possiamo distinguere:
- $P_t$: performance sui dati di training
- $P_I$: performance su dati non visti, misurabile se abbiamo gli output corretti con cui confrontare le predizioni

Il modello è una funzione matematica parametrizzata, che indichiamo con $h_\theta$; i suoi parametri si indicano con $\theta$. Dato un input, produce una predizione:
$$\hat{y}^{(i)} = h_\theta(x^{(i)})$$
$y^{(i)}$ è l'output corretto, mentre $\hat{y}^{(i)}$ è quello *previsto* dal modello: non è detto che coincidano.

###### Dati e rappresentazione
Nel supervised learning i dati, che costituiscono l'esperienza, possiamo indicarli con:
$$D = \{(x^{(i)}, y^{(i)})\}_{i=1}^{m}$$
dove $m$ è il numero di esempi, $x^{(i)}$ è l'input dell'esempio i-esimo e $y^{(i)}$ è l'output associato.

Prima di usare un dato grezzo, come il testo di una mail, dobbiamo rappresentarlo in una forma adatta al modello. Una funzione di rappresentazione può trasformarlo in un *vettore di feature*:
$$\phi(x^{(i)}) = \overline{x^{(i)}} \in \mathbb{R}^d$$
Le rappresentazioni possono essere *costruite a mano* oppure *apprese*. Le feature devono mettere in evidenza caratteristiche utili per il task: non esiste una rappresentazione universale adatta a ogni problema.

Una volta effettuata la rappresentazione, per semplicità indichiamo direttamente con $x^{(i)}$ il vettore di feature:
$$x^{(i)} = (x^{(i)}_1, \dots, x^{(i)}_d) \in \mathbb{R}^d$$
- l'apice $(i)$ indica il campione, per esempio il numero della mail
- il pedice $j$ indica la specifica feature
- $x^{(i)}_j$ è il valore della feature j-esima nel campione i-esimo, quindi in questa rappresentazione è uno *scalare*

Le feature descrivono i dati e **non sono i parametri del modello**.

Con tutti i campioni possiamo creare una matrice, detta *design matrix*:
$$X =
\begin{pmatrix}
x^{(1)}_1 & \cdots & x^{(1)}_d \\
\vdots & \ddots & \vdots \\
x^{(m)}_1 & \cdots & x^{(m)}_d
\end{pmatrix}
\in \mathbb{R}^{m \times d}$$
- ogni **riga** rappresenta un campione
- ogni **colonna** rappresenta una feature

Per esempio, rappresentiamo ogni mail con due feature: numero di errori ortografici e numero di occorrenze di alcune parole chiave. Con 1000 mail avremo $X \in \mathbb{R}^{1000 \times 2}$, mentre le etichette saranno in un vettore separato $Y \in \{0,1\}^{1000}$.

##### Tipologie di task
Il *task* è il problema che vogliamo risolvere. Due task principali sono la **classificazione** e la **regressione**: in entrambi i casi partiamo da un input rappresentato mediante un vettore di feature, ma cambia il tipo di output che vogliamo ottenere.

###### Classificazione

Nella classificazione chiediamo al modello di stabilire **a quale categoria appartiene un input**, scegliendo tra un insieme di classi definito in anticipo.

Per esempio, vogliamo riconoscere se una mail è spam oppure no:
- *input*: il vettore di feature della mail, come il numero di errori ortografici e le occorrenze di parole chiave
- *output*: una delle due etichette possibili, "spam" o "non spam"

Durante il training forniamo al modello esempi $x^{(i)}$ insieme alle rispettive etichette corrette $y^{(i)}$. Se abbiamo *k classi*, possiamo rappresentare le etichette con:
$$y^{(i)} \in \{1, \dots, k\}$$
Il classificatore realizza quindi una funzione del tipo:
$$h_\theta : \mathbb{R}^d \to \{1, \dots, k\}$$
cioè prende un vettore di $d$ feature e restituisce la classe prevista $\hat{y}^{(i)} = h_\theta(x^{(i)})$.

Possiamo distinguere:
- *Classificazione binaria*: abbiamo due sole classi, spesso codificate con $\{0,1\}$. Nel nostro esempio manteniamo $0 =$ spam e $1 =$ non spam.
- *Classificazione multiclasse*: abbiamo più di due classi, per esempio riconoscere se un'immagine rappresenta un cane, un gatto o un cavallo.

Alcuni modelli producono una *probabilità per ciascuna classe*, invece di restituire direttamente un'etichetta. Per esempio, una mail potrebbe ricevere probabilità $0.9$ per spam e $0.1$ per non spam. Possiamo poi scegliere la classe con probabilità maggiore: l'obiettivo finale resta assegnare una categoria all'input.

###### Regressione

Nella regressione chiediamo al modello di **prevedere una quantità numerica**, non di scegliere una categoria.

Per esempio, vogliamo prevedere il prezzo di una casa:
- *input*: caratteristiche come metratura, età dell'immobile e zona
- *output*: il prezzo stimato della casa

Anche in questo caso, durante il training abbiamo esempi $x^{(i)}$ e output corretti $y^{(i)}$, ma questi ultimi sono valori numerici, per esempio i prezzi delle case osservate. Nel caso di un singolo valore da prevedere scriviamo:
$$y^{(i)} \in \mathbb{R}, \qquad h_\theta : \mathbb{R}^d \to \mathbb{R}$$
Il modello cerca di apprendere una relazione tra le feature e il valore da prevedere, così da stimarlo anche per nuovi input. Se usiamo solo la metratura, abbiamo una sola feature e quindi $d=1$; se aggiungiamo altre caratteristiche, il vettore di input avrà più componenti.

A differenza dei codici delle classi, qui le differenze tra i valori hanno un significato: prevedere un prezzo di 201.000 euro quando quello corretto è 200.000 euro è un errore più piccolo rispetto a prevedere 300.000 euro.

La distinzione dipende quindi da **cosa vogliamo prevedere**, non dall'oggetto che stiamo analizzando: per una casa, prevedere il prezzo è un task di *regressione*, mentre assegnarla a una delle categorie "economica", "media" o "di lusso" è un task di *classificazione*.

###### Feature
Le feature possono essere di due tipi principali:
- **Categoriche**: assumono valori appartenenti a un insieme finito di categorie
	- *Ordinali*: esiste un ordine significativo, per esempio bassa, media, alta
	- *Nominali* o *non ordinali*: non esiste un ordine naturale, per esempio i colori
- **Continue**: assumono valori numerici su un intervallo, per esempio altezza o temperatura

Un conteggio, come il numero di errori ortografici, è invece una quantità numerica *discreta*, anche se spesso viene trattato come una feature numerica insieme a quelle continue.

##### Tipologie di apprendimento
###### Supervised learning
Il nostro algoritmo ha a disposizione sia i dati in input $x^{(i)} \in \mathbb{R}^d$ sia gli output desiderati $y^{(i)}$. Il dataset deve quindi essere *etichettato*.

L'obiettivo è imparare la relazione tra input e output, in modo da fare predizioni anche su dati non visti. Ottenere le etichette può essere costoso, perché spesso richiede annotazioni manuali.

###### Unsupervised learning
Abbiamo a disposizione solo i dati in input, senza etichette:
$$D = \{x^{(i)}\}_{i=1}^{m}$$
Agli algoritmi chiediamo di scoprire in autonomia la struttura, i pattern e le associazioni presenti nei dati.

Un esempio è il *clustering*: raggruppiamo campioni simili senza conoscere in anticipo le loro etichette. Il clustering è un esempio di unsupervised learning, non l'unico approccio possibile.

Questi metodi li vedremo poco.

###### Reinforcement learning
Prendiamo l'esempio di un topo in un labirinto che può fare quattro tipi di movimenti: up, down, sx e dx. Il topo è l'*agente*, il labirinto è l'*ambiente*.

L'agente prova delle azioni e riceve delle ricompense (*reward*), per esempio:
- un *positive reward* se raggiunge l'uscita o il cibo
- un *negative reward* se incontra un pericolo

L'esperienza deriva dall'interazione con l'ambiente: stato attuale → azione → ricompensa → nuovo stato.

L'agente apprende per *trial and error*, sfruttando **sia le ricompense positive sia quelle negative**, non solo i casi positivi. L'obiettivo è apprendere una *policy* $\pi$, cioè una strategia per scegliere le azioni, che massimizzi la ricompensa cumulativa attesa. Conta quindi anche l'effetto delle sequenze di azioni, non solo il risultato immediato.

##### Altre definizioni
###### Misure di performance

Nei problemi di classificazione una misura di performance molto usata è l'**accuracy**, cioè la frazione di esempi classificati correttamente.

Le etichette che indicano il risultato corretto sono dette *etichette ground truth* (GT). Per calcolare l'accuracy confrontiamo:
- le etichette GT, $y^{(i)}$
- le etichette generate dal modello, $\hat{y}^{(i)}$

$$\operatorname{accuracy} = \frac{\text{numero di predizioni corrette}}{\text{numero totale di esempi}}$$
Per esempio, se il modello classifica correttamente 4 mail su 5, l'accuracy è $4/5 = 0.8$, cioè l'80%. Il *tasso di errore* è:
$$\operatorname{error\ rate} = 1 - \operatorname{accuracy}$$
Quindi, nell'esempio, è $0.2$, cioè il 20%. La formula $1-P$ **non vale per qualsiasi misura di performance**. Per altri task usiamo altre misure: nella regressione, per esempio, possiamo misurare l'errore quadratico medio (*mean squared error*), che vogliamo minimizzare.

###### Parametri e iperparametri
I modelli, oltre ai parametri $\theta$ appresi durante il training, hanno degli **iperparametri**: scelte che fissiamo al di fuori della procedura di training e che ne influenzano il comportamento. Possiamo sceglierli manualmente oppure tramite una ricerca automatica, valutandoli su dati di *validazione*.

###### Training e testing
Dividiamo il dataset in insiemi separati:
- *Training set*: usato per apprendere i parametri del modello
- *Validation set*: usato per scegliere gli iperparametri e confrontare le configurazioni
- *Test set*: usato per la valutazione finale su dati mai usati per addestrare o scegliere il modello

Il test set **non va usato per scegliere parametri o iperparametri**, altrimenti la valutazione non è più indipendente. In particolare:
$$D_{\text{train}} \cap D_{\text{test}} = \varnothing$$
La suddivisione è generalmente *casuale*. Nella classificazione possiamo usare una suddivisione *stratificata*, che mantiene approssimativamente le proporzioni delle classi nei diversi insiemi: per esempio, prendere l'80% per il training significa prendere circa l'80% dei campioni di ciascuna classe.

È importante controllare anche lo *sbilanciamento delle classi*. Se l'80% dei campioni appartiene a una classe, un modello che predice sempre quella classe ottiene già l'80% di accuracy, pur sbagliando tutti i casi dell'altra. Quindi un'accuracy alta non basta a dire che il modello funziona bene su tutte le classi.

Mantenere le proporzioni nello split non significa rendere le classi ugualmente numerose: dobbiamo distinguere tra *stratificazione* e *bilanciamento* e assicurarci che i dati di valutazione rappresentino il problema reale.

