
###### Definizioni iniziali
**A. Samuel nel 1959** definì il machine learning è l'abilità di un computer di imparare senza essere esplicitamente programmati

Vorremmo imparare da un set di *dati* a risolvere un *task*

Di solito abbiamo: dati->programma->output
con il machine learning abbiamo: dati->learning algorithm->programma che risolve uno specifico task. Durante la *fase di learning* insegniamo al nostro modello come comportarsi, poi durante la *fase di inferenza* con nuovi dati vediamo se questo ci da un ouput corretto

Quando parliamo di ML abbiamo sembra un certo grado di *incertezza*, questa incertezza deriva anche dal fatto che si tratta di *problemi stocastici*
**Esempi di problema**: 
- riconoscere una mail spam o non spam
	- input: testo della mail
	- output: etichetta "spam" (0) o "non spam" (1) (il set delle etichette è detto *set di classi*)
- colorazione di un immagine


**Mitchell nel (1997)** ha dato una nuova definizione di machine learning: 
Un computer impara dall'*esperienza E* rispetto ad un *task T* e ad una *misura di performance P* se le performance misurate sul task T mediante P migliorano con l'esperienza E

i dati (che sarebbe l'esperienza) possiamo indicarli con $$\{x^{(i)},y^{(i)}\}^{i = m}_{{i = 1}}$$
Durante il processo di apprendimento è importante poter misurare le performance sennò non potro capire se il "modello" sta veramente apprendendo. In generale quindi affermiamo che "imparo se le performance sul task aumentano tenendo conto dell'esperienza", *P misura l'apprendimento*. Avremo sia: 
- $P_t$ performance durante il training
- $P_{I}$ performance durante la fase di inferenza

il modello non è altro che una funzione matematica parametrizzata (i parametri si indicano con $\theta$)

$x^{(i)}$ è un campione, fisicamente sarà un vettore perché contiene diversi parametri e potremmo definirlo come: $$x^{(i)} = (x^{(i)}_{1}\cdots x^{(i)}_{n})$$quindi $x^{(i)}_{j}$ è uno specifico parametro del campione $x^{(i)}$, anche quest'ultimo è un vettore di dimensione $d$ -> quindi possiamo affermare che $x^{(i)}$ è una matrice $\in R^{n\times d}$

Di seguito la funzione che dato il dato $x^{(i)}$ mi permette di rappresentare i dati
$$\phi(x^{(i)}) = \overline{x^{(i)}}$$
$\overline{x^{(i)}}$ è detto *vettore di feature*

Per capire se una mail è spam o no, uno dei parametri da analizzare sono gli errori ortografici che indicheremo con $x^{(i)}_{j}$ (l'apice indica il numero della mail, il pedice la specifica caratteristica)

Con queste informazioni possiamo creare una matrice (*design matrix*) con la prima colonna il tipo di feature e nella seconda l'occorrenza

###### Supervised learning
il nostro algoritmo ha a disposizione sia i dati in input $x^{(i)} \in R^d$ che le etichette di output $x^{(i)} \in (1\dots k-1)$, le etichette possono essere formate da un set di *k classi*

Questi algoritmi possono essere di due tipi: 
- **Classificatori**
- **Regressione** 

###### Unsupervised learning
Abbiamo a disposizione solo i dati input, dagli algoritmi si pretende che scoprano in autonomia la struttura dei dati, questo approccio fa uso del *clustering* (raggruppiamo in gruppi valori vicini)

Questi metodi li vedremo poco

###### Feature
Le feature possono essere di due tipi:
- **Categoriche**: delle misurazioni che danno in output etichette che hanno un senso proprio 
	- *Ordinali*: abbiamo un ordine: bassa, media, alta
	- *Non ordinali*: non riusciamo a definire un ordine: colori
- **Continue**: numeri reali che hanno intrisicamente un senso

###### Reinforcement learning
Prendiamo l'esempio di un topo in un labirinto che può fare solo 4 tipi di movimenti: up, down, sx e dx. Questo può generare delle *sequenze* di movimenti possibili, ma solo alcuni porteranno ad un *positive reward* (uscire dal labirinto in questo) le altre daranno un *negative reward*. Imparando solo dai casi positivi l'apprendimento migliora

###### Altri definizioni
Nel caso di problemi di classificazione la misura di performance (quante volte l'algoritmo sbaglia o no) si chiama **accuracy**. 
Nei dati iniziali abbiamo delle etichette che indicano quale è il risultato che ci aspettiamo dal modello dette *etichette ground truth*, la funzione accuracy prende in input: 
 - le etichette GT
 - le etichette generate dal modello 
 in base a questo ci dice quale la percentuale di volte in cui il modello ci azzecca. La percentuale di errore è ovviamente: $1-accuracy$

i modelli oltre ai parametri hanno gli **iperparametri** (molto spesso sono dei parametri che modifichiamo manualmente)

Come dicevamo prima i dati vengono divisi in *X_train* e *X_test* (questa divisione è *randomica*). Uso i train per riuscire a settare nel modo corretto parametri e iperparametri, poi uso i test in modo che sto usando dati che il mio modello non ha mai visto.

é importante avere dei dataset bilanciati in termini di classi, se avro 80% dei campioni tutti relativi ad una specifica classe, allora il nostro modello diventerà molto bravo a riconoscere quella classe e fara molti errori nelle altre. Anche la randomness va controllata, devo comunque bilanciare nel modo coretto la partecipazione delle varie classi al dataset