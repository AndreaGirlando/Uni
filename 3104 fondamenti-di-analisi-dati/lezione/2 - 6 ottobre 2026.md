
#### Definizione iniziali
"Data is a collection of values gathered with respect to certain variables that describe a given phenomenon"

- **Observations**: è l'unità fondamentale che usiamo per misurare i dati, ogni singola osservazione rappresenta un singolo "soggetto" o "evento", è unica e distinta dalle altre
	- ES: uno studente di una classe
- **Population**: l'insieme completo di tutte le osservazioni possibili. 
	- ES: Tutti gli studenti di informatica in italia
- **Sample**: sottoinsieme della population, il sottoinsieme dalla quale sto andando ad analizzare i dati (deve essere rappresentativo di tutta la population)

#### Variabile

Una variabile è una funzione che prende un'osservazione della popolazione e gli associa un valore$$X : Ω → S$$
$$ω → x$$
- $\Omega$ è la **popolazione**, cioè l’insieme di tutte le osservazioni possibili.
- $S$ è l’insieme dei **valori che la variabile può assumere**.
- $X$ è la variabile.
- $\omega$ indica una particolare osservazione/individuo.
- $x$ è il valore che $X$ assegna a quell’osservazione.
![[Pasted image 20261006153721.png]]
Le variabili possono essere di diverse nature:
- *Qualitative*: descrive quantità di caratteristiche che non possono essere misurate
- *Quantitative*: descrive quantità di caratteristiche realmente misurabili
- *Discreta*: variabili quantitative ma che possono assumere solo un set di valori
- *Continua*: variabili quantitative che assumono valori dentro un range
- *Scalare*: variabile che contiene un singolo valore ottenuto in una osservazione
- *Multidimensionale*: variabili composte da molteplici componenti (Coordinate, RGB, ecc...)

Queste variabili assegnano dei dati, ma ovviamente esistano anche diversi tipi di dati "assegnabili": 
- *Nominale*: valori non ordinabili, come "sposato" o "non sposato", sono dei valori che hanno un significato ma non si possono ordinare
- *Ordinale*: c'è un'ordine ma che non hanno significati diversi (ES: le stelline di recensione di un ristorante)
- *Interval*: Differenze significanti tra i vari dati ma non hanno un zero assoluto, lo zero significa qualcosa (ES: la temperatura, la differenza tra 10° e 20° esiste, ma 0° ha un significato non significa assenza di temperatura)
- *Ratio*: le differenze sono valide, e 0 indica assenza assoluta (ES: Altezza, se 0 indica assenza di altezza invece 180 cm ha un significato)

##### Dataset 
un dataset è una tabella organizzata dove le colonne rappresentano variabili e le righe le osservazioni (semplicemente nelle colonne trovo i parametri che devo catturare e nelle righe le varie misurazioni che faccio) 
![[Pasted image 20261006155130.png]]
#### Metodi principali per raccogliere i dati
- *Questionario*
- *Esperimenti*: raccolta dei dati in contesto controllato per cercare delle relazioni tra variabili
- *Osservazione*: raccolgo informazioni sugli eventi che succedono naturalmente senza l'intervento del ricercatore
- *Online sources*: usare delle informazioni che trovo online (dataset già creati, Kaggle, ecc...)

Certo. Puoi scriverlo in modo più chiaro così:

**Selection Bias**: si verifica quando il campione osservato non è rappresentativo della popolazione, perché gli individui vengono selezionati in modo non casuale. Per esempio, se testo un farmaco prima su persone anziane che stanno male e poi su persone giovani e sane, i risultati potrebbero essere distorti: potrei attribuire al farmaco differenze che in realtà dipendono dalle caratteristiche dei due gruppi.

Idealmente, il campione dovrebbe essere scelto **casualmente** e in modo da rappresentare il più possibile i diversi tipi di osservazioni presenti nella popolazione.

In molti casi, però, non è possibile controllare direttamente il processo di raccolta dei dati. Si parla quindi di **dati osservazionali**: i dati vengono raccolti “così come si presentano”, senza poter assegnare casualmente le condizioni. Un esempio è il meteo, che non può essere controllato sperimentalmente: possiamo soltanto osservare e registrare ciò che accade.

##### Laboratorio
[[01_key_concepts.ipynb]]
- *Data Wrangling*: serie di tecniche che usiamo per trasformare i dati in modo che siano pronte per le analisi che andiamo a fare
Esistono diversi modi per visualizzare i dati, abbiamo: 
- *Wide format*: ogni variabile ha la sua colonna
- *Long format*: vediamo più colonne "stacked" sulla stessa colonna
![[Pasted image 20261006172716.png|350]]
Ovviamente fare una analisi dei dati si basa molto spesso su questo workflow
![[Pasted image 20261006174216.png|500]]
Potrebbe essere importante ritornare indietro a degli step precedenti ogni volta che ci viene in mente un assunzione diversa sui dati che stiamo andando ad analizzare 