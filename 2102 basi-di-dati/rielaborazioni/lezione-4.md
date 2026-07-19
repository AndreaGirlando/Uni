# Operatori derivati dell’algebra relazionale


###### Join incompleti
Quando facciamo dei join ci possono essere dei casi limite che sono quelli che di seguito prendiamo in esame:
- **Dangling ennuple**: nel caso in cui alcuni valori tra gli attributi comuni non coincidono si hanno questo tipo di ennuple (come nel caso di seguito che mancano alcune ennuple)
  ![[Pasted image 20251011095944.png|500]]
- Potrebbe anche essere che nessuna ennupla trovi il suo corrispettivo e in quel caso si ha una join vuota
  ![[Pasted image 20251011100243.png|500]]
###### Join troppo completi
Ogni ennupla di $R_1$ si combina con ogni ennupla di $R_2$ e in quel caso si ha un prodotto delle cardinalità
![[Pasted image 20251011100601.png|500]]

###### Outer join
Per mantenere nel risultato le ennuple che non partecipano al JOIN si usa una variante del JOIN detta OUTER JOIN (giunzione esterna), si hanno tre varianti:

Le definizioni verranno date seguendo questa premessa: *Date $R$ ed $S$ definite sugli insiemi di attributi $XY$ e $YZ$*
- **Left**: solo dangling ennuple del primo operando
	- **Definizione**: la giunzione esterna destra è una giunzione naturale estesa con le ennuple della parte sinistra della giunzione, completate con valori NULL: $$R \;\Join^{ \leftarrow }\; S = (R \Join S) \;\cup\; \Big( (R - \pi_{XY}(R \Join S)) \times \{ Z = \text{NULL} \} \Big)$$![[Pasted image 20251011103041.png]]
- **Right**: solo dangling ennuple del secondo operando
	- **Definizione**:  la giunzione esterna destra è una giunzione naturale estesa con le ennuple della parte destra della giunzione, completate con valori NULL: $$R \;\Join^{ \rightarrow }\; S = (R \Join S) \;\cup\;\Big( \{ X = \text{NULL} \} \times  \Big( (S - \pi_{YZ}(R \Join S))\Big)$$
	  ![[Pasted image 20251011103316.png]]
- **Full**: ennuple da entrambi gli operandi
	- **Definizione:** La giunzione esterna è una giunzione naturale estesa con tutte le ennuple che non appartengono alla giunzione naturale, completate con valori NULL per gli attributi mancanti. $$ R \;\Join^{ \leftrightarrow }\; S = (R \Join S) \;\cup\; \Big( (R - \pi_{XY}(R \Join S)) \times \{ Z = \text{NULL} \} \Big)\;\cup\;\Big( \{ X = \text{NULL} \} \times (S - \pi_{YZ}(R \Join S)) \Big)$$![[Pasted image 20251011103548.png]]
![[Pasted image 20251011103613.png|500]]
---

###### Proprietà del JOIN
Per il JOIN valgono le proprietà: 
- **Commutativa**: $R \bowtie S = S \bowtie R$ 
- **Associativa**: $(R \bowtie S) \bowtie T = R \bowtie (S \bowtie T)$ 
quindi possiamo avere benissimo sequenze di JOIN senza rischio ambiguità: $R\bowtie S \bowtie T$ 
![[Pasted image 20251011104120.png|500]]

###### Prodotto cartesiano e intersezione a partire dal JOIN
**Prodotto cartesiano** :Il JOIN è definito anche se non ci sono attributi comuni fra le relazioni, quando succede questa cosa si ha un vero e proprio prodotto cartesiano tra le relazioni, questa è un'operazione molto dispendiosa in termini di risorse ![[Pasted image 20251011193401.png|500]]
**Intersezione**: Date due relazioni definite sulla stessa lista di attributi allora il natural join coincide con l'intersezione delle due relazioni 
###### Semi-giunzione
Siano $R$ ed $S$ due relazioni con attributi $XY$ e $YZ$ rispettivamente, $R \rtimes S$ è una relazione di attributi $XY$ costituita da tute le ennuple di $R$ che partecipano a $R \bowtie S$  ![[Pasted image 20251011194712.png|500]]
La semi-giunzione è derivata perché: $R \rtimes S = \pi_{XY}(R \bowtie S)$ 

###### Unione esterna
Siano $R$ ed $S$ due relazioni con attributi $XY$ e $YZ$ rispettivamente, l'unione esterna è $$
R \overset{\leftrightarrow}{\cup} S =
R \times \{Z = NULL\} \cup \{X = NULL\} \times S
$$
Si ottiene estendendo ognuna delle relazioni con gli attributi dell'altra (mettendo NULL come valore) e poi si fa l'unione ![[Pasted image 20251011195523.png|500]]
###### Selezione con valori nulli
Quando facciamo una selezione in un attributo dove si hanno dei valori NULL questi vengono ignorati ![[Pasted image 20251011200434.png|500]] infatti se prendiamo in considerazione condizioni come questa:
$$\sigma_{Eta>30 } (Persone) ∪ \sigma_{Eta \le 30}(Persone) \not = \text{Persone}$$
possiamo dire che questo non è vera, perché se in età abbiamo dei valori NULL questi verranno esclusi dal risultato. Per valutare i valori NULL si usano delle apposite condizioni che sono:
- **IS NULL**
- **IS NOT NULL**
Quindi la condizione di prima diventa: $$\sigma_{Eta>30}(Persone) \cup \sigma_{Eta\le30}(Persone) \cup \sigma_{Eta\,\text{IS NULL}}(Persone) = \text{Persone}
$$
###### Divisione
Siano $XY$ gli attributi di $R$ ed $Y$ quelli di $S$, allora si ha che: $$R \div S = \{w| {w} \times S ⊆ R\}$$
Data la tabella **Esami** formata dalla matricola e dalla materia passata, per rispondere alla domanda:
- Quali matricole hanno passato PROG e DB?
abbiamo bisogno della divisione e va impostata in questo modo: $Esami \div \{'DB','PROG'\}$. Quello che viene logicamente fatto è:
1. Prendiamo una matricola e facciamo un prodotto cartesiano con $\{'DB','PROG'\}$
2. Se il risultato del punto precedente è un sottoinsieme della tabella $Esami$ allora deve essere ritornato
3. Continuiamo i primi due passaggi su tutte le matricole
4. Tutti i valori ritornati saranno le matricole degli studenti che hanno superato entrambe le materie

###### Viste
Le viste fanno parte dello **schema esterno** del nostro dbms, e non sono altro che delle espressioni alla quale viene assegnato un nome, le espressioni possono essere:
- **Relazioni derivate**: relazione il cui contenuto è funzione del contenuto di altre relazioni
- **Relazioni di base**: semplici relazioni
Date queste tabelle: ![[Pasted image 20251011203917.png|500]]
una vista potrebbe essere $$\text{SUPERVISIONE} = \pi_{\text{Impiegato, Capo}}(\text {Afferenza} \bowtie \text{Direzione})$$
Abbiamo 2 tipi principali di viste:
- **Viste materializzate**: sono delle viste che vengono immagazzinate direttamente nel nostro database, sono sempre immediatamente disponibili ma portano alcune volte eccessiva ridondanza e appesantiscono il database
- **Viste (o relazioni virtuali)**: Sono supportate da quasi tutti i DBMS e non appesantiscono il db, un interrogazione su questo tipo di vista è più lento in quanto la vista viene ricalcolata ogni volta

Le viste vengono interpretate dal nostro dbms e sostituite con il valore ad esso collegato![[Pasted image 20251011205029.png|500]]
Le viste sono sicuramente un ottimo strumento per diversi motitivi:
- **Presentazione dei dati**: alcune volte si creano delle viste per creare delle autorizzazioni e far vedere agli utenti solo quello che sono autorizzati a vedere 
- **Programmazione**: Possono aiutare i programmatori a ridurre il codice scritto per fare una query, creando anche la possibilità di riutilizzare delle query scritte in precedenza
