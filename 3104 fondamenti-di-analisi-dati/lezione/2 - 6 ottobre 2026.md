Materiale di riferimento: [[3104 fondamenti-di-analisi-dati/file-condivisi/sitoWeb/01_Modulo_1/01_key_concepts.pdf|01_key_concepts.pdf]].

#### Definizioni iniziali
I **dati** sono un insieme di valori raccolti per descrivere un fenomeno. Ad esempio, per studiare una classe possiamo registrare, per ogni studente, età, altezza e voti.

- **Osservazione (observation)**: l'unità che studiamo, ad esempio uno studente, un'automobile o un evento. Lo studente è l'osservazione; la sua altezza è uno dei valori che registriamo.
- **Popolazione (population)**: l'insieme completo delle unità che ci interessano, definito dalla domanda di ricerca.
  - Esempio: tutti gli studenti di informatica in Italia, se vogliamo studiare le loro età.
- **Campione (sample)**: la parte della popolazione sulla quale raccogliamo effettivamente i dati.
  - Esempio: 500 studenti selezionati da diverse università italiane.
  - Un campione **non è automaticamente rappresentativo**: per estendere le conclusioni alla popolazione dobbiamo considerare come è stato selezionato. Un campione grande, ma selezionato male, può comunque dare risultati distorti.

#### Variabile
Una **variabile**, detta anche *feature* o *caratteristica*, indica quale informazione registriamo per ogni osservazione: altezza, età, colore degli occhi, ecc.

Formalmente è una funzione che associa a ogni osservazione un valore:

$$X : \Omega \to S, \qquad \omega \mapsto X(\omega)=x.$$

- $\Omega$ è la **popolazione**.
- $\omega$ è una particolare osservazione, ad esempio uno studente.
- $S$ è l'insieme dei **valori possibili** della variabile.
- $X$ è la variabile, ad esempio «altezza in centimetri».
- $x$ è il valore registrato per quello studente, ad esempio 175.

In altre parole: **studente → misuriamo l'altezza → otteniamo 175 cm**. La variabile è la regola di misurazione; 175 è uno dei suoi valori.

![[Pasted image 20261006153721.png]]

Le variabili possono essere classificate secondo aspetti diversi. Queste classificazioni non si escludono: l'altezza, ad esempio, è quantitativa, continua e scalare.

- **Qualitativa**: descrive una categoria, non una quantità. Esempi: colore degli occhi, città di nascita.
- **Quantitativa**: esprime una quantità misurabile o un conteggio. Esempi: altezza, peso, numero di fratelli.
- **Discreta**: assume valori separati, in numero finito oppure infinito numerabile. Esempio: il numero di fratelli può essere 0, 1, 2, ecc., ma non 1,5. Anche una variabile qualitativa con poche categorie ha un insieme discreto di valori.
  - **Binaria**: caso particolare con due valori possibili, ad esempio sì/no, spesso codificati come 1/0.
- **Continua**: può assumere qualsiasi valore in un intervallo, almeno nel modello teorico. Esempio: un'altezza può essere 175 cm, 175,2 cm, 175,23 cm, ecc. Arrotondare la misura non rende discreta la grandezza fisica.
- **Scalare**: associa a ogni osservazione un solo valore, ad esempio il peso.
- **Multidimensionale**: associa più componenti, ad esempio latitudine e longitudine per una posizione, oppure i tre canali RGB per un colore.

**Attenzione:** usare numeri per rappresentare una categoria non la rende quantitativa. Un codice studente come 102 è un identificatore: non ha senso dire che lo studente 102 è «il doppio» dello studente 51.

Le **scale di misura** indicano quali confronti e operazioni hanno significato:

| Scala | Che cosa possiamo confrontare? | Esempio |
| --- | --- | --- |
| **Nominale** | Uguaglianza e differenza tra categorie; non esiste un ordine naturale. | Colore degli occhi: verde non è «maggiore» di marrone. |
| **Ordinale** | I valori sono ordinabili, ma le distanze tra livelli non sono definite come quantità uguali. | Principiante < intermedio < esperto: il salto tra livelli non è una distanza misurabile. |
| **A intervalli (interval)** | Ordine e differenze hanno significato, ma lo zero è convenzionale. | Temperatura in °C: tra 10 e 20 °C ci sono 10 gradi, ma 20 °C non significa «il doppio della temperatura» di 10 °C. |
| **A rapporti (ratio)** | Hanno significato anche i rapporti, perché lo zero indica assenza della quantità. | Lunghezza: 0 cm indica lunghezza nulla e 180 cm è il doppio di 90 cm. |

La differenza tra **intervalli** e **rapporti** è quindi il significato dello zero. Non basta che i dati siano numeri: un voto 8, ad esempio, non indica necessariamente una competenza doppia rispetto a un voto 4.

##### Dataset
Un **dataset** è una raccolta di dati. Nel formato tabellare più comune:
- Ogni **riga** rappresenta un'osservazione.
- Ogni **colonna** rappresenta una variabile.
- Ogni **cella** contiene il valore di quella variabile per quella osservazione.

Ad esempio, nella riga di uno studente possiamo leggere i suoi voti nelle diverse materie.

![[Pasted image 20261006155130.png]]

La tabella è detta anche **matrice dei dati**: con $n$ osservazioni e $p$ variabili ha $n$ righe e $p$ colonne. Nei modelli, la *design matrix* contiene le caratteristiche usate come input; un identificatore non è automaticamente una caratteristica utile.

Una cella vuota o un valore come **NaN** segnala un **dato mancante**, non uno zero. Un voto mancante può significare che lo studente non ha ancora sostenuto la prova. Codici speciali come -1 possono indicare dati mancanti, ma solo se la documentazione lo specifica.

Prima di combinare colonne bisogna verificarne le scale: se una materia ha voti su 30 e un'altra su 10, farne direttamente la media darebbe più peso alla prima.

#### Metodi principali per raccogliere i dati
- **Questionari (surveys)**: domande standardizzate per raccogliere opinioni, preferenze o caratteristiche. Esempio: soddisfazione degli studenti.
- **Esperimenti**: il ricercatore modifica una condizione e osserva gli effetti, cercando di controllare gli altri fattori. L'assegnazione casuale ai gruppi aiuta a renderli confrontabili.
- **Osservazione**: registriamo ciò che accade senza assegnare o modificare le condizioni studiate. Esempio: temperatura e precipitazioni.
- **Fonti online**: dataset già disponibili, archivi pubblici o API. Bisogna verificarne provenienza, significato delle colonne e modalità di raccolta.

**Selection bias (distorsione di selezione)**: il modo in cui raccogliamo le osservazioni può far sì che alcune categorie siano troppo presenti e altre poco presenti o assenti. Per studiare tutti gli studenti universitari, ad esempio, intervistare soltanto quelli presenti in biblioteca escluderebbe molti studenti con abitudini diverse. Il problema non è semplicemente «selezione non casuale»: anche un invito casuale può produrre un campione distorto se rispondono soprattutto certe persone. Un campionamento casuale ben progettato aiuta, ma vanno considerate anche copertura e mancate risposte.

**Campionamento casuale e assegnazione casuale non sono la stessa cosa:**
- Il **campionamento** riguarda chi entra nello studio e aiuta a rappresentare la popolazione.
- L'**assegnazione** riguarda a quale gruppo sperimentale vengono destinati i partecipanti e aiuta a confrontare gli effetti delle condizioni.

Nei **dati osservazionali**, due variabili possono essere associate senza che una causi l'altra: entrambe potrebbero dipendere da un terzo fattore. Confrontare gruppi con età molto diverse, ad esempio, può mescolare l'effetto dell'età con quello della condizione che vogliamo studiare: questo è un problema di **confondimento**, distinto dal selection bias.

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
