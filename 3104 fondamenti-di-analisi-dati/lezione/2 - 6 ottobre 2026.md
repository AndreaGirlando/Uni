Materiale di riferimento: 
- [[3104 fondamenti-di-analisi-dati/file-condivisi/sitoWeb/appunti/Modulo-1/01_key_concepts.pdf|01_key_concepts.pdf]]
- [[3104 fondamenti-di-analisi-dati/file-condivisi/sitoWeb/slide/Modulo-1/01_key_concepts.pdf |slide]]

### Concetti chiave
#### Definizioni iniziali
Di seguito delle definizioni:

- *Dati* sono un insieme di valori raccolti per descrivere un fenomeno
- *Osservazione (observation)*: unità elementare con la quale misuriamo i dati, ogni osservazione è unica (possiamo pensare ad un'osservazione come alla singola riga di uno spreedsheet)
- *Popolazione (population)*: l'insieme con tutte le possibili osservazioni (anche quelle che non useremo), in pratica l'insieme universo
- *Campione (sample)*: sottoinsieme della popolazione dalla quale prendiamo i dati, usiamo un sottoinsieme perché usare l'intera popolazione è molto spesso impossibile o troppo difficile

> [!EXAMPLE]
> Immaginiamo di voler studiare la salute degli alberi nella black forest, vediamo come i concetti di prima calzano in questa analisi:
> - *Osservazione*: un singolo albero della foresta con diverse caratteristiche (altezza, diametro, ecc...)
> - *Popolazione*: tutti gli alberi della foresta 
> - *Campione*: insieme di 500 alberi scelti casualmente tra le diverse aree della foresta

#### Variabile
Una **variabile**, detta anche *feature* o *caratteristica*, indica quale informazione registriamo per ogni osservazione. Formalmente è una funzione che associa a ogni osservazione un valore: $$X : \Omega \to S, \qquad \omega \mapsto X(\omega)=x.$$
- $\Omega$ è la popolazione.
- $S$ è l'insieme dei valori possibili della variabile
- $\omega$ è una particolare osservazione
- $x$ è il valore che la funzione $X$ ci ritorna con input la variabile $\omega$.

> [!EXAMPLE]
> Dato $\Omega = \text{ tutta la popolazione del mondo }$, possiamo definire la variabile $H$ come una funzione che data in input la persona $\omega$ ci ritorna la sua altezza in centimetri, in pratica $H(\omega) = 180 cm$ 

##### Classificazione delle variabili
Le variabili possono essere classificate secondo aspetti diversi:
- *Qualitativa*: descrive una categoria, non una quantità. 
	- Esempi: colore degli occhi, città di nascita.
- *Quantitativa*: esprime una quantità misurabile o un conteggio. 
	- Esempi: altezza, peso, numero di fratelli.
- *Discreta*: assume valori separati, in numero finito oppure infinito numerabile, un tipo di variabile discreta particolare è quello *binario* che ha due valori possibili spesso codificati come 1/0.
	- Esempi: il numero di fratelli può essere 0, 1, 2, ecc., ma non 1,5.
- *Continua*: può assumere qualsiasi valore in un intervallo, almeno nel modello teorico. 
	- Esempi: un'altezza può essere 175 cm, 175,2 cm, 175,23 cm, ecc.
- *Scalare*: associa a ogni osservazione un solo valore
	- Esempi: il peso di una persona
- *Multidimensionale*: associa più componenti ad ogni osservazione
	- Esempi: latitudine e longitudine per una posizione, oppure i tre canali RGB per un colore.

> [!WARNING]
> usare numeri per rappresentare una categoria non la rende quantitativa. Un codice studente come 102 è un identificatore: non ha senso dire che lo studente 102 è «il doppio» dello studente 51.

Un'altro modo per classificare le variabili è usando la **scala di misura**, che ci indica quali confronti o operazioni hanno significato: 

- *Nominale*: Uguaglianza e differenza tra categorie; non esiste un ordine naturale.
	- Esempio: colore degli occhi: verde non è "maggiore" di marrone.
- *Ordinale*: I valori sono ordinabili, ma le distanze tra livelli non sono definite come quantità uguali.
	- Esempio: Principiante < intermedio < esperto: il salto tra livelli non è una distanza misurabile.
- *Interval*: Ordine e differenze hanno significato, ma lo zero è convenzionale.
	- Esempio: tra 10 e 20 °C ci sono 10 gradi, ma 20 °C non significa "il doppio della temperatura" di 10 °C e 0°C non significa assenza di temperatura
- *Ratio*: i rapporti hanno significato e lo zero indica assenza della quantità.
	- Esempio: Lunghezza: 0 cm indica lunghezza nulla e 180 cm è il doppio di 90 cm.

##### Dataset
Un **dataset** è una raccolta di dati relativi ad uno specifico fenomeno, viene rappresentata in formato tabellare seguendo queste convenzioni:
- Ogni *riga* rappresenta un'osservazione.
- Ogni *colonna* rappresenta una variabile.
- Ogni *cella* contiene il valore di quella variabile per quella osservazione.
	- Una cella vuota o un valore come *NaN* segnala un dato mancante, non uno zero, nel caso di dati mancanti possiamo trovare codici speciali come -1, quando accade troviamo queste specifiche nella documentazione legata al dataset
- Questo tipo di tabella può anche essere chiamata *design matrix*
Prima di combinare le colonne (es: fare la media) è importante portare tutto alla stessa scala

> [!EXAMPLE]
> Ad esempio, nella riga di uno studente possiamo leggere i suoi voti nelle diverse materie.
> ![[Pasted image 20261006155130.png]]
> 


#### Metodi principali per raccogliere i dati
- *Questionari (surveys)*: domande standardizzate per raccogliere opinioni, preferenze o caratteristiche.
- *Esperimenti*: il ricercatore modifica una condizione e osserva gli effetti, cercando di controllare gli altri fattori. L'assegnazione casuale ai gruppi aiuta a renderli confrontabili.
- *Osservazione*: registriamo ciò che accade senza assegnare o modificare le condizioni studiate. Esempio: temperatura e precipitazioni.
- *Fonti online*: dataset già disponibili, archivi pubblici o API. Bisogna verificarne provenienza, significato delle colonne e modalità di raccolta.

il modo in cui raccogliamo le osservazioni può far sì che alcune categorie siano troppo presenti e altre poco presenti o assenti. Per studiare tutti gli studenti universitari, ad esempio, intervistare soltanto quelli presenti in biblioteca escluderebbe molti studenti con abitudini diverse. Il problema non è semplicemente "selezione non casuale": anche un invito casuale può produrre un campione distorto se rispondono soprattutto certe persone. Un campionamento casuale ben progettato aiuta, ma vanno considerate anche copertura e mancate risposte, questo problema è chiamato *selection bias*

##### Laboratorio
[[01_key_concepts.ipynb]]

**Caricamento e ispezione**

Nel PDF si usa il dataset del Titanic: ogni riga è un passeggero e le colonne descrivono età, classe del biglietto, sopravvivenza e altre caratteristiche.

Un **CSV** è una tabella salvata come testo, con i valori separati da un delimitatore, solitamente una virgola. In pandas la tabella viene caricata in un **DataFrame**:

```python
import pandas as pd

# DATA è il percorso o URL dei dati, definito nel notebook del corso.
titanic = pd.read_csv(DATA + "titanic.csv", index_col='PassengerId')

titanic.head()          # Prime 5 righe
titanic.shape           # (891, 11): righe e colonne
titanic.info()          # Tipi delle colonne e numero di valori non mancanti
titanic.isna().sum()    # Numero di valori mancanti per colonna
```

Con `index_col='PassengerId'` usiamo l'identificatore come **indice**: resta disponibile, ma non è più una delle 11 colonne di dati.

- `titanic['Age']`: seleziona la colonna delle età; restituisce una **Series**, cioè una sequenza di valori con un indice.
- `titanic.loc[101]`: seleziona la riga con **etichetta** PassengerId = 101.
- `titanic.iloc[101]`: seleziona la riga in **posizione** 101. Le posizioni partono da 0, quindi è la 102ª riga, non necessariamente quella con ID 101.
- `titanic.loc[101, 'Age']`: seleziona l'età del passeggero con ID 101.

Il **tipo informatico** non coincide necessariamente con il significato statistico: Pclass contiene gli interi 1, 2 e 3, ma indica le classi del biglietto, cioè categorie **ordinali**, non quantità da sommare.

**Data wrangling**

È l'insieme delle operazioni per rendere i dati adatti all'analisi: gestione dei valori mancanti, conversione dei tipi, rinomina delle colonne, nuove variabili, filtri e cambi di formato.

Per i **valori mancanti** possiamo:
- **Eliminare** le righe interessate: `titanic.dropna()` elimina ogni riga con almeno un valore mancante. Nel PDF restano solo 183 passeggeri su 891: possiamo perdere molti dati e alterare la composizione del campione.
- **Considerare soltanto una variabile**: `titanic['Age'].dropna()` conserva le 714 età disponibili.
- **Sostituire** il valore mancante (*imputazione*), ad esempio con la media per una variabile numerica.
- **Segnalare l'assenza**, con una categoria Unknown o una colonna che indica se il valore era mancante.

```python
titanic2 = titanic.copy()  # Non modifichiamo l'originale
titanic2['AgeMissing'] = titanic2['Age'].isna()
titanic2['Age'] = titanic2['Age'].fillna(titanic2['Age'].mean())
titanic2['Cabin'] = titanic2['Cabin'].fillna('Unknown')
```

Riempire le età con la media è un esempio, **non una soluzione sempre corretta**: non recupera le età reali e modifica la distribuzione. Riempire Age e Cabin non elimina inoltre i valori mancanti nelle altre colonne, come Embarked.

Altre operazioni viste nel PDF:

```python
# Classi del biglietto: categorie ordinate
titanic2['Pclass'] = pd.Categorical(
    titanic2['Pclass'], categories=[1, 2, 3], ordered=True
)

titanic2 = titanic2.rename(columns={'SibSp': 'SiblingsSpouses'})

# Familiari a bordo: fratelli/sorelle/coniugi + genitori/figli
titanic2['FamilySize'] = titanic2['SiblingsSpouses'] + titanic2['Parch']

adulti = titanic2[titanic2['Age'] >= 18]       # Selezione di righe
selezione = titanic2[['Age', 'Cabin', 'Fare']] # Selezione di colonne
```

Qui FamilySize conta i familiari **escluso il passeggero**: per includerlo bisogna aggiungere 1. Il filtro sugli adulti è applicato dopo l'imputazione: per le età mancanti, la selezione dipende quindi dal valore inserito, non da un'età conosciuta.

**Wide e long format**

Sono due modi di organizzare gli stessi dati, non due tipi di grafico:
- **Wide format**: una riga per studente e una colonna per materia. Il voto di Alice in matematica sta nella riga Alice, colonna Math.
- **Long format**: una riga per ogni coppia **studente–materia**, con colonne Student, Subject e Score. Alice compare più volte, una per ciascuna materia.

![[Pasted image 20261006172716.png|350]]

Nell'immagine ci sono 3 studenti e 3 materie: il wide ha **3 righe**, il long ne ha **9**. Non sono comparsi nuovi studenti: abbiamo soltanto distribuito i loro voti su più righe.

In pandas si passa dal wide al long con `melt` e si torna indietro con `pivot`:

```python
long_data = wide_data.melt(
    id_vars=['Student'], var_name='Subject', value_name='Score'
)
wide_again = long_data.pivot(
    index='Student', columns='Subject', values='Score'
)
```

Qui wide_data è la tabella di partenza. `pivot` richiede un solo valore per ogni coppia studente–materia. Il long è spesso utile per raggruppare e confrontare i voti per materia.

**Workflow dell'analisi dei dati**

![[Pasted image 20261006174216.png|500]]

1. **Definire la domanda**: che cosa vogliamo capire?
2. **Raccogliere i dati** necessari.
3. **Pulire e organizzare** i dati: valori mancanti, errori, formati e unità.
4. **Esplorare e descrivere** i dati con grafici e statistiche.
5. **Scegliere i modelli** adatti alla domanda.
6. **Adattare, regolare, valutare e confrontare** i modelli.
7. **Rivedere l'analisi** quando arrivano nuovi dati.

Il processo è **iterativo**, non una sequenza rigida. Se l'esplorazione rivela valori sospetti, torniamo alla pulizia; se mancano informazioni, raccogliamo altri dati; se la domanda iniziale non è adeguata, la riformuliamo. Le frecce tratteggiate del grafico rappresentano questi ritorni.
