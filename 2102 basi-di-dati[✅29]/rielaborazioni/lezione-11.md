# Controllo d'accesso e transazioni

###### Introduzione al controllo d'accesso
In SQL è possibile specificare chi (quale utente) e come (lettura, scrittura) può utilizzare la base di dati, oggetto dei *privilegi* sono di solito le tabelle, ma anche altri tipi di *risorse* quali singoli attributi, viste o domini. Un utente predefinito *_system* ha tutti i privilegi

###### Privilegi
Un privilegio è caratterizzato da:
- la risorsa cui si riferisce
- l'utente che concede il privilegio
- l'azione che viene permessa
- la trasmissibilità del privilegio
i privilegi offerti da SQL sono:
- *insert*: permette di inserire nuovi oggetti
- *update*: permette di modificare il contenuto
- *delete*: permette di eliminare oggetti
- *select*: permette di leggere la risorsa
- *references*: permette la definizione di vincoli di integrità referenziale verso la risorsa
- *usage*: permette l'utilizzo in una definizione 
per dare questi privilegi usiamo i comandi **grant** e **revoke** che hanno le seguenti sintassi:
![[Pasted image 20251101093518.png|500]]
![[Pasted image 20251101093525.png|500]]
###### Autorizzazioni
La gestione delle autorizzazioni deve nascondere gli elementi cui un utente non può accedere, senza sospetti. 
**Esempio**: 
- Facciamo una select sulla tabella "Impiegati" e ricevo "non esiste" (è vero la tabella non esiste)
- Facciamo una select sulla tabella "ImpiegatiSegreti" e ricevo "non esiste" (la tabella esiste ma l'utente che sta facendo la query non è autorizzato)

Per autorizzare un utente a vedere solo alcune ennuple di una relazione usiamo le viste.

Il concetto di ruolo da assegnare ad ogni utente dentro la nostra base di dati viene introdotto con SQL 1999

###### Introduzione alle transazioni
Insieme di operazioni da considerare indivisibile, corretto anche in presenza di concorrenza e con effetti definitivi. Le proprietà principali delle transazioni sono:
- *Atomicità*: la sequenza di operazioni sulla base di dati viene eseguita per intero o per niente
- *Consistenza*: al termine dell'esecuzione di una transazione, i vincoli di integrità devono essere soddisfatti
- *Isolamento*: l'effetto di transazioni concorrenti deve essere coerente 
- *Durabilità*: la conclusione positiva di una transazione corrisponde ad un impegno a mantenere traccia del risultato in modo definitivo

###### Transazioni in SQL
Una transazione inizia al primo comando SQL dopo la *connessione* alla base dati, esiste anche un comando *start transaction* non obbligatorio. Alla conclusione di una transazione potremmo avere due casi:
- *commit*: le operazioni specificate a partire dall'inizio della transazione vengono eseguite sulla base di dati
- *rollback*: si rinuncia all'esecuzione delle operazioni specificate dopo l'inizio della transazione
molti sistemi prevedono una modalità di *autocommit* 
```SQL
start transaction
update ContoCorrente 
	set Saldo = Saldo – 10 
	where NumeroConto = 12345 ; 
update ContoCorrente 
	set Saldo = Saldo + 10 
	where NumeroConto = 55555 ; 
commit work;
```

# Basi di dati attive

###### Introduzione ai trigger
Una base di dati può contenere delle regole attive dette *trigger*, questi strumenti si basano sul paradigma: **Evento-Condizione-Azione**, questo modello consente computazioni reattive.
- *Evento*: normalmente una modifica dello stato del database: insert, delete, update, in questa fase il trigger viene *attivato*
- *Condizione*: Un predicato che identifica se l'azione del trigger deve essere eseguita, quando la condizione viene valutata il trigger è *considerato*
- *Azione*: Una sequenza di update SQL o una procedura, quando l'azione è eseguita anche il trigger è *eseguito*

###### Sintassi
Ogni trigger è caratterizzato da:
- nome
- target
- modalità (*before* o *after*)
- evento (*insert, delete* o *update*)
- granularità
- alias dei valori
- azione
- timestamp di creazione
![[Pasted image 20251101095648.png|500]]

###### Tipi di eventi
**Before**: il trigger è considerato ed eseguito prima dell'evento, di solito questa modalità è usata quando si vuole verificare una modifica prima che essa avvenga e *"modificare la modifica"*
```SQL
create trigger LimitaAumenti 
before update of Salario on Impiegato 
for each row 
when (New.Salario > Old.Salario * 1.2) 
set New.Salario = Old.Salario * 1.2
```
**After**: il trigger è considerato e eseguito dopo l'evento, è la modalità più comune ed è adatta alla maggior parte delle applicazioni
```SQL
create trigger LimitaAumenti 
after update of Salario on Impiegato 
for each row 
when (New.Salario > Old.Salario * 1.2) 
UPDATE Impiegato SET Salario = Old.Salario * 1.2 WHERE Matricola = NEW.Matricola
```

###### Granularità degli eventi
**Modalità statement-level**: *for each statement* il trigger viene considerato e possibilmente eseguito solo una volta per ogni statement che lo ha attivato
- ci sono due *tabelle di transizione* alla quale possiamo fare riferimento usando:
	- *old table*: che contiene la tabella con tutti i valori precedenti allo statement
	- *new table*: che contiene la tabella con tutti i valori successivi allo statement
```SQL
create trigger AccountMonitor 
after update on Account 
for each row 
when new.Total > old.Total 
insert 
	into Payments 
	values 
	(new.AccNumber,new.Total-old.Total)
```

**Modalità row-level**: *for each row* il trigger viene considerato e possibilmente eseguito una volta per ogni tupla modificata
- ci sono due *variabili di transizione* alla quale possiamo fare riferimento usando:
	- *old*: che rappresenta il valore precedente della tupla
	- *new*: che rappresenta il valore successivo delle tupla
```SQL
create trigger FileDeletedInvoices 
after delete on Invoice 
referencing old_table as OldInvoiceSet 
insert into DeletedInvoices 
(select * 
	from OldInvoiceSet)
```


###### Esecuzione dei trigger in conflitto
Quando vi sono più trigger associati allo stesso evento vengono eseguiti come segue:
- Prima i *BEFORE*
- Viene eseguita la modifica e il controllo dei vincoli di integrità
- Infine gli *AFTER*

Quando i vari trigger appartengono alla stessa categoria, l'ordine di esecuzione è definito in base al loro timestamp di creazione


###### Modello di esecuzione dei trigger
I trigger sono associati ad un *Trigger Execution Context*, l'azione di un trigger può produrre eventi che attivano altri trigger che vengono valutati in un nuovo TEC interno, questa cosa può accadere in modo ricorsivo, l'esecuzione termina in due modi:
- *Correttamente*: si arriva correttamente in uno stato quiescente
- *Erroneamente*: l'esecuzione termina in errore quando si raggiunge una profondità di ricorsione troppo alta, quando succede viene fatto un rollback allo statement che ha fatto partire la catena di trigger

###### Trigger in Oracle
In oracle si usa una sintassi differente: 
- sono consentiti eventi multipli
- non sono previste variabili per le tabelle 
- la condizione è presente solo con trigger row-level
![[Pasted image 20251101102210.png|500]]
###### Conflitti tra trigger in Oracle
Per evitare i conflitti tra trigger questo è l'ordine di esecuzione dei trigger in oracle:
- I before statement-level trigger
- I before row-level trigger
- Viene eseguita la modifica dei vincoli di integrità
- gli after row-level trigger
- gli after statement-level trigger

quando i vari trigger appartengono alla stessa categoria, l'ordine di esecuzione è definito in base al loro timestamp di creazione

*Mutating table exception*: scatta se la catena di trigger attivati da un before trigger T cerca di modificare lo stato della tabella target di T

###### Proprietà formali dei trigger
Vi sono tre proprietà classiche:
- *Terminazione*: per un qualunque stato iniziale e una qualunque transazione, si produce uno stato finale
- *Confluenza*: l'esecuzione dei trigger termina e produce un unico stato finale, indipendente dall'ordine di esecuzione dei trigger
- *Univoca osservabilità*:  i trigger sono confluenti e producono verso l'esterno lo stesso effetto

###### Analisi della terminazione
Si usa una rappresentazione delle regole detta *grafo di triggering* dove abbiamo un nodo per ogni trigger, un arco dal nodo $t_i$ al nodo $t_j$ se l'esecuzione dell'azione di $t_i$ può attivare il trigger $t_j$ in questo modo se:
- *il grafo è aciclico*: l'esecuzione termina
- *il grafo ha cicli*: allora può avere problemi di terminazione

**Esempio**
```SQL
T1: 
	create trigger AdjustContributions 
	after update of Salary on Employee 
	referencing new table as NewEmp 
	update Employee set Contribution = Salary * 0.8 
	where RegNum in (select RegNum from NewEmp)

T2: 
	create trigger CheckBudgetThreshold 
	after update on Employee 
	referencing new_table as NewEmp1 
	when 50000 < ALL (select (Salary+Contribution) from NewEmp1) 
	update Employee 
	set Salary = 0.9*Salary
```
![[Pasted image 20251101103432.png|500]]in questo caso abbiamo dei cicli ma terminano.