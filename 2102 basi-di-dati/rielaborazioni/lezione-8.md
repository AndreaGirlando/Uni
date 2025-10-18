# SQL - SELECT 2

###### Ricordiamo la sintassi della select
![[Pasted image 20251018151352.png]]

###### Limitazioni della Having
Date queste tabelle, dobbiamo fare una query che restituisca nome, matricola, voto minimo voto massimo, voto medio per gli studenti che hanno dato più di 8 materie
![[Pasted image 20251018151949.png]]
ovvero:
```SQL
SELECT Nome, Matricola, MIN(Voto), MAX(Voto),AVG(Voto) 
FROM Esami, Studenti 
WHERE Esami.Matricola = Studenti.Matricola 
GROUP BY Nome,Matricola 
HAVING COUNT(*) > 8
```

Ricordiamo che la clausola having ammette come argomento un espressione booleana su predicati semplici quindi $count(*)>8$ è valido ma $AVG(Voto)>Voto$ non lo è


###### Interrogazioni nidificate
Per alcuni tipi di query potremmo avere bisogno di fare delle select annidate, queste sono dette **sotto-select** queste danno come risultato una tabella con un solo elemento o una vuota, in questo modo posso essere usate come predicati dentro le condizioni where, di seguito la sintassi:
![[Pasted image 20251018154005.png|500]]
**Esempi:** date queste tabelle:
![[Pasted image 20251018154035.png|500]]
- Nome e reddito del padre di Franco
	- *Normale*: SELECT Nome, Reddito FROM Persone, Paternita WHERE Nome = Padre AND Figlio = 'Franco'
	- *Con sotto-select*: SELECT Nome, Reddito FROM Persone WHERE Nome = ( SELECT Padre FROM Paternita WHERE Figlio = 'Franco')
	questi sono due modi di fare la stessa cosa

###### Condizioni sulle sottoselect
Le condizioni in SQL permettono anche il confronto fra un attributo e il risultato di una sottoquery:
- **Attributo (ANY | ALL) (sottoselect)** 
	- *ANY*: il predicato è vero se almeno uno dei valori restituiti rispetta la condizione
	- *ALL*: il predicato è vero se tutti i valori restituiti rispetta la condizione
- **\[ NOT\] EXIST (sottoselect)**: il predicato è vero se la select restituisce almeno una tupla
- **Attributo \[ NOT \] in (sottoselect):** ritorna true se l'attributo non esiste tra quelli ritornati
Inoltre possiamo dire che:
- NOT IN è sinonimo di $<>ALL$
- IN è sinonimo di $=ANY$
###### Commenti sulle interrogazioni nidificate
- La forma nidificata è meno dichiarativa ma talvolta più leggibile
- La forma piana e quella nidificata possono essere combinate
- Le sotto interrogazioni non supportano gli operatori insiemistici
- Regole di visibilità:
	- non è possibile fare riferimenti a variabili definite in blocchi più interni
	- se un nome di variabile è omesso si assume riferimento alla variabile più vicina
- in un blocco si può fare riferimento a variabili definite in blocchi più esterni

###### Negazione con le query nidificate
Ci sono dei casi in cui andiamo a negare la nostra query nidificata per togliere elementi da quella principale

**Esempio**: trovare quei dipartimenti dove non c'è nessuno che si chiama "Brown":
```SQL
select DeptName
from Department
where DeptName <> all (
	select Dept 
	from Employee 
	where Surname = 'Brown'
)
```
ritorno i nomi del dipartimento diversi da quelli che vengono ritornati dalla sottoquery

###### MAX e MIN con le query nidificate
Nelle query nidificate si possono utilizzare anche max e min, di seguito degli esempi: 
- Il dipartimento dove lavora colui con lo stipendio più alto di tutta l'azienda
```SQL
select Dept
from Employee
where Salary in (select max(Salary) from Employee)
```
	oppure si potrebbe anche scrivere
```SQL
select Dept
from Employee
where Salary >= all (select Salary from Employee)
```

- i dipartimenti che hanno una somma di salari maggiore rispetto alla somma media dei salari dell'azienda per dipartimento
```SQL
SELECT Dept 
FROM Emp 
GROUP BY Dept 
HAVING SUM(Salary) > ( 
	SELECT AVG(Totale.SalTot) 
	FROM (SELECT SUM(Salary) ‘SalTot’ 
		FROM Emp 
		GROUP BY Dept) AS Totale
)
```

###### Exist
Prima abbiamo accennato ad exist come ad una condizione che ci permette di capire se un attributo è contenuto in una sottoselect, di seguito degli esempi:
- Le persone che hanno almeno un figlio
```SQL
SELECT * 
FROM Persone p 
WHERE EXISTS ( SELECT * 
	FROM Paternita 
	WHERE Padre = p.Nome
) 
OR 
EXISTS ( SELECT * 
	FROM Maternita 
	WHERE Madre = p.Nome
)
```

###### Semantica delle espressioni correlate
- La query più interna può usare variabili della query esterna
- L'interrogazione interna viene eseguita una volta per ciascuna ennupla dell'interrogazione esterna


###### Esempio con il quantificatore universale
Supponiamo di voler trovare i codici di quei clienti che hanno fatto ordini a tutti gli agenti di Catania, la query è:
```SQL
SELECT C.CodiceCliente 
FROM Clienti C 
WHERE NOT EXISTS 
	(SELECT * FROM Agenti A
	WHERE A.Zona = ‘Catania’ 
	AND NOT EXISTS 
	(SELECT * 
	FROM Ordini V 
	WHERE V.CodiceCliente = C.CodiceCliente 
	AND V.CodiceAgente = A.CodiceAgente) )
```


###### Commenti finali sulle query nidificate
Questo tipo di query possono essere meno dichiarative in un certo senso ma spesso sono più facilmente interpretabili, si deve fare attenzione alle regole di visibilità e infine si deve fare in modo di ridurre il numero di variabili in gioco (con un altro numero di variabili le query diventano complicate)