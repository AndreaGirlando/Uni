# SQL - SELECT

###### Generalità
SQL (Structured Query Language) sviluppato dalla IBM nel 1973 è lo standard per tutti i sistemi commerciali ed open source, lo standard alla quale facciamo riferimento noi sarà fondamentalmente SQL-92. SQL viene usato principalmente per interrogare le nostre basi di dati, il comando che vedremo di seguito è il **SELECT**


###### SELECT - sintassi generale
![[Pasted image 20251018103656.png|500]]
Quello che fa la select è:
- Prodotto cartesiano tra le tabelle in *Tabelle*
	- In Tabelle si trovano tutti i nomi delle tabelle
- Seleziona le righe che soddisfano la condizione *Condizione*
- Valuta le espressioni specificare in *Attributi*
	- Assume il nome degli attributi, eventuali operazioni o $*$ nel caso volessimo tutti gli attributi disponibili

**Caratteristiche** generali:
- Implementa gli operatori ridenominazione, proiezione, selezione e join dell'algebra relazionale.
- Comandi case sensitive
- Le query possono essere distribuite in una o più righe (le keyword no) 

Di seguito un esempio:
![[Pasted image 20251018104344.png|500]]

###### Espressioni aritmetiche
All'interno dei nostri attributi possiamo specificare delle operazioni aritmetiche tra i campi di delle tabelle delle clausola FROM, i simboli utilizzabili sono: $+$ $-$ $*$ $/$ e valgono le regole della precedenze dell'aritmetica generale
![[Pasted image 20251018104818.png|500]]

###### Alias delle colonne
Possiamo rinominare ogni campo che selezioniamo dentro i nostri attributi usando la keyword **AS**, richiede un doppio apice se il nome da assegnare è una stringa con spazi
![[Pasted image 20251018105051.png|500]]

###### Alias nelle tabelle
Quando si hanno attributi uguali in più tabelle si deve fare uso della ridenominazione delle tabelle ![[Pasted image 20251018105158.png|500]]
###### Distinct
All'interno degli attributi è consentito usare la keyword **DISTINCT** per eliminare le righe duplicate (perché a differenza dell'algebra relazione qua posso esiste doppioni)
![[Pasted image 20251018105348.png|500]]

###### Uso delle clausola WHERE
Usando where possiamo limitare le righe ritornate dalla select a solo quelle che rispettano una certa condizione, la sintassi delle condizione è la solita di qualsiasi linguaggio però si hanno degli operatori in più:
- **BETWEEN...AND...** esprime il compreso tra due valori
  ![[Pasted image 20251018105953.png|500]]
- **IN(list)**: il valore a sinistra è dentro list
  ![[Pasted image 20251018110015.png|500]]
- **LIKE**: Operatore di pattern matching (espressioni regolari)
	- Le ricerche possono includere letterali, caratteri o numeri, inoltre ricordiamo che
		- $\%$ denota zero o più caratteri
		- $\_$ denota un carattere
![[Pasted image 20251018110153.png]]
- **IS NULL**: Controllo se il valore è null
  ![[Pasted image 20251018110228.png]]
- **Diverso**: è un operatore che conosciamo ma ha un simbolo diverso ovvero: $<>$
Ovviamente abbiamo anche gli operatori logici **AND**, **OR**, **NOT** (con le solite regole di precedenze) ![[Pasted image 20251018110417.png|500]]
###### ORDER BY
Le righe possono essere ordinate usando la clausola **ORDER BY** specificando:
- **ASC**: ordine crescente
- **DESC** ordine decrescente
deve essere inserita come ultima clausola nelle select ![[Pasted image 20251018111252.png]]
###### JOIN
La join viene usata per effettuare query su più tabelle, ha la seguente sintassi:
![[Pasted image 20251018111351.png]]
Come possiamo notare la clausola del join viene specificata dentro la clausola where
![[Pasted image 20251018112051.png|700]]
Per rendere queste query con molte tabelle più pulite si usano gli alias delle tabelle
```
SELECT p1.Professore 
FROM Corsi p1, Corsi p2, Esami e1, Esami e2 
WHERE p1.Corso = e1.Corso AND 
	p2.Corso = e2.Corso AND 
	p1.Professore = p2.Professore AND 
	e1.Matricola = e2.Matricola AND 
	NOT p1.Corso = p2.Corso
```

Se non si specificano delle clausole, viene generato un prodotto cartesiano (detto **cross join**) delle tabelle, questo è molto pesante da fare, quindi le clausole vanno messe la maggior parte delle volte
![[Pasted image 20251018120830.png|500]]
###### JOIN esplicito
Al posto di sfruttare le where per inserire le clausole di una JOIN esiste il comando esplicito che ci aiuta, di seguito la sintassi
![[Pasted image 20251018121640.png|500]]
**Esempi**: ![[Pasted image 20251018121022.png|500]]
- Padre e madre della stessa persona
	- Join: *SELECT paternita.figlio,padre, madre FROM maternita, paternita WHERE paternita.figlio = maternita.figlio*
	- Join On: *SELECT madre, paternita.figlio, padre FROM maternita JOIN paternita ON paternita.figlio = maternita.figlio*
- Padri di persone che guadagnano più di 20  
	- Join: *SELECT distinct padre FROM persone, paternita WHERE figlio = nome AND reddito > 20*
	- Join On: *SELECT distinct padre FROM persone JOIN paternita ON figlio = nome WHERE reddito > 20*
- Le persone che guadagnano di più dei rispettivi padri:
	- Join: *SELECT f.nome, f.reddito, p.reddito FROM persone p, paternita, persone f WHERE p.nome = padre AND figlio = f.nome AND f.reddito > p.reddito*
	- Join On: *SELECT f.nome, f.reddito, p.reddito FROM persone p JOIN paternita ON p.nome = padre JOIN persone f ON figlio = f.nome WHERE f.reddito > p.reddito*

###### Join esterno
Oltre al Join-On abbiamo anche i comandi per le varie join esterne
![[Pasted image 20251018122529.png || 500]]
###### Natural Join
Questa è una join che non ha bisogno di nessuna clausola, infatti controlla i campi delle tabelle che hanno lo stesso nome e fa una join basandosi su quelli: ![[Pasted image 20251018122831.png|500]]

###### Unione, intersezione e differenza
La select da sola non permette di fare unioni, per farlo serve un costrutto esplicito ovvero **UNION** questo ha delle implicazioni sulla posizione degli attributi:
![[Pasted image 20251018123158.png|500]]
Analogamente vale per **INTERSECT** e **EXCEPT**

---

###### Aggregazione dati

Negli attributi possiamo avere anche espressioni che calcolano valori a partire da insiemi di ennuple, questi sono gli operatori di aggregazione e sono (questi operatori non esistono in algebra relazionale):
- **Conteggio**(COUNT): ritorna il numero di valori non null della colonna specificata
	- count($*$) restituisce il numero di righe ![[Pasted image 20251018123739.png|500]]
- **Massimo**(MAX): ritorna il massimo della colonna specificata
- **Minimo**(MIN): ritorna il minimo della colonna specificata
- **Media**(AVG): ritorna la media della colonna specificata
- **Somma**(SUM): ritorna la somma della colonna specificata
![[Pasted image 20251018123720.png|500]]
se una colonna A contiene solo valori nulli, tutte queste ritornano null tranne count che ritorna $0$
**Esempi**: 
- Media dei redditi dei figli di Franco: *SELECT avg(reddito) FROM persone JOIN paternita ON nome=figlio WHERE padre=‘Franco’*

Questi aggregatori vengono usati spesso su dei gruppi di record, i gruppi di record li creiamo usando **GROUP BY**
![[Pasted image 20251018124330.png|500]]


###### Group By
Nelle select si va a posizionare in questo modo: ![[Pasted image 20251018124411.png]]
Insieme agli operatori di aggregazione viene usato in questo modo:![[Pasted image 20251018124518.png|500]]
è possibile raggruppare anche più di una colonna, semplicemente specificando più attributi dopo il Group by
![[Pasted image 20251018124633.png|500]]


###### Target list
La target list degli attributi deve essere omogena, non possiamo usare un operatore di aggregazione vicino ad una attributo normale
![[Pasted image 20251018124713.png|500]]
Gli operatori di aggregazione possono essere utilizzati anche in gruppi creati usando il group by, sempre facendo attenzione che la target list sia omogena ![[Pasted image 20251018124909.png|500]]
ogni colonna o espressione della Select che non è argomento di funzioni di gruppo deve essere nella group by ![[Pasted image 20251018125116.png|500]]

###### Having
I gruppi non possono essere ristretti usando la clausola WHERE
![[Pasted image 20251018125235.png|500]] in questo caso infatti abbiamo bisogno di having, che nella select si trova esattamente dopo il group by: ![[Pasted image 20251018125332.png|500]] di seguito un esempio di un suo tipo di utilizzo:
![[Pasted image 20251018125410.png|500]]

###### Sommario
Ricordiamo sempre che l'ordine di una query è:
![[Pasted image 20251018125509.png|500]]
- **FROM** – vengono prese le tabelle coinvolte e calcolati eventuali join o prodotti cartesiani.
- **WHERE** – si filtrano le righe secondo le condizioni specificate.
- **GROUP BY** – si raggruppano le righe secondo gli attributi indicati.
- **HAVING** – si filtrano i gruppi in base a condizioni sui risultati aggregati.
- **SELECT** – si scelgono le colonne (e si calcolano le funzioni di aggregazione).
- **DISTINCT** – (eventuale) eliminazione dei duplicati dal risultato.
- **ORDER BY** – si ordina il risultato finale.
