
# La progettazione di una base di dati (pt 2)

###### Identificazione esterna
In alcuni casi una entità può essere identificata da altre ad essa collegato, nell'esempio di seguito il corso di studio è identificato da un nome proprio e da quello del dipartimento che li eroga
![[Pasted image 20251208144712.png|500]]
le identificazioni esterne avvengono sempre tramite *associazioni binarie* in cui l'entità da identificare partecipa con cardinalità 1,1.

###### Gerarchie 
Spesso nelle analisi di un settore aziendale può risultare che più entità risultino simili o casi particolari l'una dell'altra, emerge quindi la necessità di evidenziare *sottoclassi* di alcune classi. Si definisce **gerarchia di specializzazione** il legame logico che esiste tra classi e sottoclassi

###### Gerarchia concettuale
La gerarchia concettuale è il legame logico tra un'entità padre $E$ ed alcune entità figlie $E_1,E_2, \dots, E_n$ dove:
- $E$ è la generalizzazione di $E_1,E_2, \dots, E_n$
- $E_1,E_2, \dots, E_n$ sono specializzazione di $E$
- $E_k$ è anche istanza di $E$
- $E$ può essere una istanza di $E_k$
![[Pasted image 20251208145335.png|500]]
Nella foto notiamo il tipo di gerarchia scritto in modo esplicito, di seguito tutte quelle studiate:
- **t**: che sta per *totale*, ogni istanza dell'entità padre deve far parte di una delle entità figlie
- **nt**: che sta per *non totale*: le istanze dell'entità padre possono far parte di una delle entità figlie
- **e**: che sta per *esclusiva*: ogni istanza dell'entità padre deve far parte di una sola delle entità figlie ![[Pasted image 20251208145729.png|500]]
- **ne**: che sta per *non esclusiva*: ogni istanza dell'entità padre può far parte di una o più entità figlie ![[Pasted image 20251208145744.png|500]]
###### Ereditarietà
Le proprietà dell'entità padre non devono essere replicate sull'entità figlia in quanto questa la eredità:
- il tipo di **personale** è: *(matricola, cognome, nome, indirizzo, data_nascita)*
- il tipo di **dipendente** è: (matricola, cognome, nome, indirizzo, data_nascita, *parametro*) 
- il tipo di **esterno** è: (matricola, cognome, nome, indirizzo, data_nascita, *ore*)

###### Strategie di progetto
Nei nostri progetti abbiamo 3 tipi diversi di approcci
- **Top-Down**
- **Bottom-Up**
- **Generale**
###### Bottom-Up
![[Pasted image 20251208150543.png|250]]
Le primitive di trasformazione top-down sono regole che partendo da uno schema semplice riescono ad aggiungere dettagli, e sono:
1. **T1:** si applica quando un'entità descrive due concetti diversi legati tra di loro
   ![[Pasted image 20251208151228.png|500]]
2. **T2**: Un'entità è composta da **sotto-entità distinte**
   ![[Pasted image 20251208151326.png|500]]
3. **T3**: Una relazione in realtà descrive due relazioni diverse tra le stesse entità
   ![[Pasted image 20251208151338.png|500]]
4. **T4**:  Una relazione descrive un concetto con esistenza autonoma, va sostituito con un entità
5. **T5**: Aggiungiamo attributi alle entità
6. **T6**: Aggiungiamo attributi alle relazioni

Usando questo approccio abbiamo questo vantaggio ovvero il progettista descrive inizialmente lo schema trascurando i dettagli precisando lo schema gradualmente, però abbiamo anche un problema ovvero: non va bene per applicazioni complesse perché è difficile avere una visione globale precisa di tutte le componenti del sistema

###### Bottom-up
Le specifiche nascono suddivise per sotto-progetti descriventi frammenti limitati della realtà da schematizzare, sviluppati i sottoshcemi separati si fondono per ottenere lo schema finale
![[Pasted image 20251208151917.png|500]]Anche in questo caso abbiamo degli step precisi da seguire:
1. **T1**: si individua nella specifica una classe di oggetti con proprietà comuni e si introduce un'entità corrispondente
2. **T2**: si individua nella specifica un legame logico fra entità e si introduce una associazione fra esse
3. **T3**: si individua una generalizzazione fra entità
4. **T4**: a partire da una serie di attributi si individua un'entità che li aggrega
5. **T5**: a partire da una serie di attributi si individua una relazione che li aggrega

L'uso di questo approccio si adatta bene ad una progettazione di gruppo in cui diversi progettisti possono sviluppare parti disgiunte che possono essere assemblate successivamente, però l'integrazione si sistemi concettualmente diversi comporta notevoli difficoltà

###### Metodologia generale
Per applicare la seguente metodologia dobbiamo definire:
- Glossario dei termini
- I requisiti senza ambiguità
Dopo aver fatto ciò applichiamo i seguenti step:
- **Passo base**: Individuare i concetti più rilevanti e rappresentarli in uno schema scheletro
- **Passo di decomposizione**: Effettuare una decomposizione dei requisiti facendo riferimento ai concetti definiti nello schema scheletro (questo step è opzionale)
- **Passo iterativo**: Raffinare i concetti presenti sulla base delle loro specifiche
- **Passo di integrazione**: Integrare i vari sottoschemi in uno schema generale facendo riferimento allo schema scheletro
- **Analisi di qualità**: bisogna fare un'analisi della qualità dello schema
###### Qualità di uno schema relazionale
La qualità di uno schema relazionale viene giudicata in base a delle proprietà che lo schema deve possedere:
- **Correttezza**: non ci devono essere errori:
	- *sintattici*: uso non ammesso dei costrutti
	- *semantici*: uso che non rispetta il loro significato
- **Completezza**: tutti i dati di interesse sono rappresentati e tutte le operazioni possono essere eseguite a partire dai concetti dello schema
- **Leggibilità**: quando rappresenta i requisiti in maniera naturale e facilmente comprensibile
- **Minimalità**: quando tutte le specifiche sono rappresentate una sola volta e non ci sono ridondanze7

# La progettazione di una base di dati (pt3)
###### Fasi della progettazione logica
**Ristrutturazione dello schema E-R**: è una fase di indipendente dal modello logico e consiste nell'ottimizzare lo schema ![[Pasted image 20251208161241.png]]
###### Analisi delle prestazioni su schemi E-R
Abbiamo due indici per la valutazione di schemi E-R:
- **Costo di un operazione**: in termini di numero occorrenze di entità ed associazioni che mediamente vanno visitate per rispondere a quella operazione sulla base di dati
- **Occupazione di memoria**: viene valutata in termini dello spazio di memoria necessario per memorizzare i dati del sistema
Per studiare questi due indici abbiamo bisogno di:
- *Volume dei dati*: ovvero il numero medio di occorrenze delle entità/associazioni, e la dimensione di ciascun attributo
- *Caratteristiche delle operazioni*: tipo di operazione, frequenza e i dati coinvolti

###### Esempio di analisi
Dato il seguente schema: ![[Pasted image 20251208161943.png|500]]
Definite le seguenti operazioni:
1. Assegna un impiegato ad un progetto
2. Trova i dati di un impiegato, del dipartimento nel quale lavora e dei progetti in cui è coinvolto
3. Trova i dati di tutti gli impiegati di un certo dipartimento
4. Per ogni sede, trova i dipartimenti con il cognome del direttore e l'elenco degli impiegati
   ![[Pasted image 20251208162214.png|500]]
Avendo a disposizione queste informazioni è possibile stimare il costo delle varie operazioni, prendiamo in esame l'**operazione 2**, quest'ultima prende in esame la seguente sezione di schema: ![[Pasted image 20251208162335.png|500]]
Per soddisfare la query dobbiamo accedere:
- Un occorrenza di Impiegato e di Afferenza e quindi di Dipartimento
- Poi per avere i dati dei progetti a cui lavora, dobbiamo accedere (in media) a tre occorrenze di Partecipazione e quindi a tre entità Progetto
tutto viene riassunto nella seguente tabella degli accessi
![[Pasted image 20251208162551.png|500]]
**L = lettura, S = Scrittura** essendo la scrittura più onerosa della lettura abbiamo una rapporto di $1S = 1L$


###### Come effettuare una ristrutturazione dello schema ER
- **Analisi delle ridondanze**: si decide se eliminare o no eventuali ridondanze
- **Eliminazione delle generalizzazioni**: tutte le generalizzazioni vengono analizzare e sostituire da altro
- **Partizionamento/Accorpamento**: si decide se partizionare concetti in più parti o viceversa
- **Scelta degli identificatori primari**: si sceglie un identificatore per quelle entità che ne hanno più di uno

###### Costi di un dato derivato
Quando si hanno dei dati derivata da altri dati (importoAnnuale = importoMensile $\times$ numeroMensilità) si deve fare particolare attenzione, perché questi riducono gli accessi perché non dobbiamo calcolare il dato derivato in fase di lettura, ma ovviamente occupano più spazio. Per capire se vanno mantenuti o no è necessario fare un'analisi dei costi:

**Esempio**: Consideriamo una relazione Città-Persona per l'anagrafica di una regione:
![[Pasted image 20251208163530.png|500]]Con le seguenti operazioni:
- *Operazione 1*: memorizza una persona nuova con la relativa città
- *Operazione 2*: stampa tutti i dati di una città (incluso il numero di abitanti)
Valutiamo gli indici di prestazioni per l'attributo NumeroAbitanti
![[Pasted image 20251208164046.png|500]]
**Con NumAbitanti**:
Assumendo che il numero di abitanti richieda 4 Byte il dato richiede $4 \times 200 = 800 \; byte$
- Operazione 1 richiede: 
	- un accesso in scrittura a Persona
	- un accesso in scrittura a Residenza
	- uno in lettura per cercare la città
	- uno in scrittura per incrementare il numero di abitanti nella città
  Si hanno *1500 accessi in scrittura e 500* in lettura
- Operazione 2 richiede:
	- un solo accesso in lettura a Città
		- 2 volte al giorno trascurabile
In totale avremo **3500 accessi** considerando il costo doppio degli accessi in scrittura

**Senza NumAbitanti**
- Operazione 1 richiede:
	- un accesso in scrittura a Persona
	- uno in scrittura a residenza
  Totale di *1000 accessi* in scrittura (che valgono doppio nel conteggio finale)
- Operazione 2 richiede:
	- 2 lettura in Città (trascurabili)
	- 5000 accessi in lettura a residenza (in media) per calcolare il numero di abitanti
  Totale di *10000 accessi* in lettura
Considerando doppi gli accessi in scrittura il totale è di *12000*

Quindi abbiamo 8500 accessi in più rispetto al caso di ridondanza contro meno di un solo Kilobyte di memoria in più

###### Gerarchie 
Il modello relazionale non rappresenta le gerarchie, queste sono sostituite da entità e associazioni, e questo viene fatto attraverso:
1. **Mantenimento delle entità** con associazioni
2. **Collasso verso l'alto**: riunisce tutte le entità figlie direttamente nell'entità padre, inserendo i campi dei figli come nullable
   ![[Pasted image 20251208165913.png|500]]
3. **Collasso verso il basso**: si elimina l'entità padre trasferendone gli attributi su tutte le entità figlie
   ![[Pasted image 20251208170011.png]]
L'importante è che tutte le entità vengono mantenute:
- le entità figlie sono in associazione con l'entità padre
- le entità figlie sono identificate esternamente tramite l'associazione

###### Partizionamento/Accorpamento
In questa fase cerchiamo di ridurre gli accessi ai dati:
- **Separando** attributi di uno stesso concetto che vengono acceduti da operazioni diverse
- **Raggruppando** attributi di concetti diversi che vengono acceduti dalle medesime operazioni
  ![[Pasted image 20251208170223.png|500]]![[Pasted image 20251208170300.png|500]]

###### Scelta della chiave primaria
Per poter scegliere la chiave primaria nel migliore dei modi seguiamo le seguenti regole:
1. Scegliere la chiave che è usata più frequentemente per accedere all'entità
2. Scegliere delle chiavi semplici ed evitare chiave composte

###### Traduzione
Per poter gestire meglio le entità e le relazioni nasce la traduzione standard dove:
- Ogni entità è tradotta con una relazione con gli stessi attributi
- Ogni associazione è tradotta con una relazione con gli stessi attributi più gli attributi di ogni entità ad essa associata
**Molti a molti**: ![[Pasted image 20251208173059.png|500]]
**1 ad N**: ![[Pasted image 20251208173129.png|500]]
**1 a 1**: ![[Pasted image 20251208173159.png|500]]
