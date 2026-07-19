# La progettazione di una base di dati

###### Introduzione
Come in ogni ciclo di vita di un sistema informativo, il progetto di una basi di dati consiste nei seguenti passi:
1. Raccolta ed analisi dei requisiti
2. Progettazione
	- Individua l'organizzazione e la struttura della base di dati
	- schematizza le operazioni sui dati
3. Implementazione 
4. Validazione e collaudo
5. Funzionamento e manutenzione
###### Metodologie di progettazione
Quando progettiamo una base di dati è importante avere una netta separazione delle decisioni relative a cosa rappresentare in una base di dati da quelle relative a come farlo, quindi distinguiamo:
- La progettazione concettuale
- La progettazione logica
- La progettazione fisica

###### Progettazione concettuale
Tradurre la *descrizione informale* della realtà risultato di una analisi approfondita, in uno *schema formale* e completo che dovrà essere indipendente dal tipo di DBMS usato
###### Progettazione logica
Consiste nella traduzione dello schema concettuale in termini di un determinato *modello logico* di dati usato dal DBMS che si intende usare, il risultato è lo *schema logico*, questo comprende anche l'ottimizzazione dello schema basandosi sulle operazioni che verranno effettuate
###### Progettazione Fisica
Si completa lo schema logico con la specifica dei parametri fisici di memorizzazione dei dati. Si produce lo *schema fisico* che dipende dal DBMS scelto


###### Analisi dei requisiti
Durante queste analisi bisogna:
- Individuare i requisiti hardware e software
- Produrre una descrizione dei *dati* in linguaggio naturale e come sono coinvolti nelle varie *operazioni*
Tutto ciò si fa attraverso uno *studio di fattibilità* e *piano di sviluppo* dove vengono anche specificati:
- i costi in termini di budget
- priorità e tempi di realizzazione
Di seguito come fare un analisi:
1. Si analizzano le descrizione dei dati per evitare le ambiguità (omonimie, conflitti di descrizione e similitudini)
2. Si controllano insieme ai responsabili dei vari settori da rappresentare se le operazioni che coinvolgono i dati hanno senso
3. Si costruisce un glossario dove per ogni termine (entità) troviamo la descrizione, i sinonimi e i termini collegati
4. Si verifica che tutti gli aspetti importanti sono stati considerati
5. Si verifica che il sistema sia consistente
**Esempio:** da queste frasi riusciamo a ricavare il glossario di seguito
![[Pasted image 20251208112921.png|500]]![[Pasted image 20251208113005.png|500]]
###### Modello Entità-Relazione
Questo è un modello concettuale di dati che contiene alcuni costrutti usati per descrivere la realtà in maniera semplice, questi costrutti sono:
- **Entità**
	- *Entità*: sono classi di oggetti che hanno delle proprietà
	- *Istanza di entità*: oggetto in memoria della quale si vogliono registrare fatti specifici, viene identificata univocamente.
	- Esempio: ![[Pasted image 20251208113603.png|500]]
- **Relazioni**
	- *Relazioni*: rappresentano legami logici fra due o più entità dell'applicazione
	- *Istanza di relazione*: fatto che descrive un'azione e quindi un legame tra istanze di entità
	- Esempio: ![[Pasted image 20251208113800.png]]
- **Proprietà(Attributi)**: sono fatti che descrivono le caratteristiche delle istanze di entità
  ![[Pasted image 20251208113932.png|500px]]
- **Cardinalità**
- **Identificatori**
- **Generalizzazioni**
- **Sottoinsiemi**

###### Notazione grafica modello E-R
Il modello ER usa simboli grafici per favorire l'immediatezza della comprensione
- **Entità**: viene rappresentato con una *quadrato* con al suo interno il nome di quella entità
  ![[Pasted image 20251208114406.png]]
- **Associazioni**: viene rappresentato con un *rombo* con al suo interno il nome della associazione
  ![[Pasted image 20251208114355.png|500]]
- **Attributi**: dalle entità/associazioni escono dei pallini che vanno a specificare i nomi degli attributi
  ![[Pasted image 20251208114419.png|500]]
prima dello schema ER vero e proprio si creano degli *schemi scheletro* che descrivono una prima struttura di massima dello schema, che scrivono in generale i collegamenti tra le entità di interesse e le associazioni che le legano ![[Pasted image 20251208114701.png|500]]
###### Identificazione delle proprietà
Le proprietà sono di diversi tipi: ![[Pasted image 20251208114950.png|500]]
Il simbolo **(n,m)** definisce se un valore è obbligatorio e quanti ne sono permessi:
- **(1,1):** Indica che l'attributo è obbligatorio (minimo 1) e singolo (massimo 1).
- **(1,n):** Indica che l'attributo è obbligatorio (minimo 1) e multiplo (massimo n valori, illimitati).
- **(0,1):** Indica che l'attributo è opzionale (minimo 0) e singolo   (massimo 1)
- **(0,n):** Indica che l'attributo è opzionale (minimo 0) e multiplo (massimo n valori).
![[Pasted image 20251208115803.png|500]]

###### Proprietà speciali
**Proprietà calcolate**: il valore di questo tipo di proprietà è calcolato con un algoritmo specifico, a differenza delle proprietà esplicite
![[Pasted image 20251208115906.png|500]]
**Proprietà di sintesi**: valori medi, massimi e minimi, sono anche queste delle proprietà calcolate ma che vanno a sintetizzare il contenuto della tabella
![[Pasted image 20251208120005.png|500]]
**Proprietà chiave**: identificano in modo univoco la singola istanza di un entità, è obbligatoria e può essere composto, come simbolo usa quello dell'attributo base ma con il pallino pieno
![[Pasted image 20251208120210.png|500]]
![[Pasted image 20251208120233.png|500]]
Si possono avere più chiavi in una tabella che vanno ad identificare univocamente lo stesso record
![[Pasted image 20251208120324.png|250]]
Le **associazioni hanno sempre della chiavi composte** definite come l'insieme delle chiavi primarie delle tabelle partecipanti alla relazione
![[Pasted image 20251208120452.png|500]]

###### Cardinalità
Per cardinalità si intende il numero di volte che un data istanza di entità deve o può partecipare alla associazione
- **(1,1)**: obbligatoria, una sola volta 
- **(1,n)**: obbligatoria, almeno una volta 
- **(0,1)**: opzionale, una sola volta 
- **(0,n)**: opzionale, n volte
In base al tipo di cardinalità abbiamo diversi tipi di associazioni:
- **M:N**:![[Pasted image 20251208121038.png]]Un dipendente deve partecipare ad almeno un progetto, ad un progetto possono partecipare $n$ dipendenti o anche $0$
- **1:1**: ![[Pasted image 20251208121345.png]]Un reparto deve avere un solo direttore, un direttore può dirigere un solo reparto
- **N:1**: ![[Pasted image 20251208121418.png]]Su un ripiano possono stare $n$ oggetti, un oggetto si può trovare in un solo ripiano
![[Pasted image 20251208121554.png|500]]
![[Pasted image 20251208121602.png|500]]

###### Auto-associazioni
Associazioni aventi come partecipanti istanze provenienti dalla stessa entità sono dette **auto-associazioni**
![[Pasted image 20251208121734.png|500]]
![[Pasted image 20251208121741.png|500]]
![[Pasted image 20251208121749.png|500]]