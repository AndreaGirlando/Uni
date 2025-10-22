# SQL: Amministrazione

###### Introduzione
Ad ogni utente tipicamente viene associata una base di dati, creata dall'amministratore del sistema, l'utente detto amministratore è quello che tipicamente crea il database e gestisce gli eventuali accessi di altri utenti alla sua base di dati


###### Creazione ed eliminazione del database
```SQL
CREATE SCHEMA Nome AUTHORIZATION Utente
```

Con questo comando creiamo il database chiamato *Nome* con *Utente* come suo amministratore, dopo questo comando scriviamo le definizioni delle tabelle, viste, ecc...

```SQL
DROP SCHEMA Nome RESTRICT
DROP SCHEMA Nome CASCADE
```

Questo comando va ad eliminare il database, può prendere come argomento:
- **RESTRICT**: il drop viene eseguito solo se il db è vuoto
- **CASCADE**: vengono rimossi automaticamente tutti i dati presente nel database


###### Creazione tabelle
Con il nostro database creato dobbiamo creare anche le nostre tabelle usando il comando **CREATE TABLE** dove andiamo a specificare i vari attributi, domini e vincoli
![[Pasted image 20251022095309.png|500]]
```SQL
CREATE TABLE Impiegato( 
	Matricola CHAR(6) PRIMARY KEY, 
	Nome CHAR(20) NOT NULL, 
	Cognome CHAR(20) NOT NULL, 
	Dipart CHAR(15), 
	Stipendio NUMERIC(9) DEFAULT 0, 
	FOREIGN KEY(Dipart) REFERENCES 
	Dipartimento(NomeDip), 
	UNIQUE (Cognome,Nome) 
)
```

###### Domini
Nel comando create table dopo il nome dell'attributo troviamo il tipo (anche detto dominio), esistono dei domini predefiniti da SQL, ma se necessario possiamo creare anche dei domini personalizzati
- **Domini elementari**:
  - *CHAR(n)* stringhe di lunghezza n
  - *VARCHAR(n)* stringhe di lunghezza variabile con al massimo n caratteri
  - *INTEGER* interi
  - *REAL* reali
  - *NUMERIC* (p,s) p cifre di cui s decimali
  - *FLOAT(p)* es. 0.17E16
  - *DATE,TIME* per date ed ore.
- **Domini personalizzati**: per definire un dominio utilizzabile in definizioni di tabelle usiamo il comando **CREATE DOMAIN** 
```SQL
CREATE DOMAIN Voto AS SMALLINT DEFAULT NULL CHECK ( value >= 18 AND value <= 30 )
```
questo comando va a creare un dominio personalizzato *Voto* che è un small-int che come default è null ma se prende valore questo deve essere compreso tra 18 e 30


###### Vincoli d'integrità
i vincoli di integrità riguardano i valori ammissibili negli attributi di una tupla e sono di due tipi:
- **Vincoli intrarelazionali**: nell'ambito della stessa relazione
	- *NOT NULL*
	- *UNIQUE*: i valori di questo tipo di colonne deve essere univoco per ogni riga
	- *PRIMARY KEY*: implica not null
	- *CHECK*: specifica i valori ammissibili
	- *DEFAULT*: specifica del valore default se nessun valore viene inserito
- **Vincoli Referenziali**: (o interrelazionali) tra diverse relazioni
	- *FOREIGN KEY*: ci permettono di definire delle relazioni tra la chiave primaria di un tabella e il campo dove inseriamo questo vincolo, praticamente ci permettono di garantire che i valori in una certa tabella facciano riferimento a valori reali di un'altra tabella. ![[Pasted image 20251022101343.png|500]]
	  In TabellaRef è stata definita una chiave primaria, questo ci impedisce di inserire delle tuple con il valore della chiave esterna diverso da uno dei valori della chiave primaria di TabellaRef

> [!DANGER] Nota bene
> ![[Pasted image 20251022100751.png|500]]
> queste due dichiarazioni non sono la stessa cosa

Questi vincoli vengono controllati durante possibili operazioni di modifica in SQL (Insert, Delete e Update), devono essere sempre soddisfatti altrimenti la transazione fallisce. Questi vincoli servono principalmente per:
- Migliorare la qualità dei dati
- Arricchire semanticamente la base di dati
- Maggiore ottimizzazione del sistema se usati direttamente nel db (piuttosto che in un sistema di interazione esterno)

###### Eliminazione dei record
Durante la specifica di una chiave esterna andiamo a definire come si deve comportare il nostro database quando andiamo ad eliminare una chiave primaria associata a quell'attributo, questo lo facciamo usando **ON DELETE** con le sue tre forme:
- **ON DELETE NO ACTION**: l'operazione viene rifiutata, si deve andare manualmente ad eliminare i record che hanno quello specifico valore nella chiave esterna
- **ON DELETE CASCADE**: cancella tutte le ennuple con valori della chiave esterna corrispondente alla chiave primaria delle ennuple cancellate
- **ON DELETE SET NULL**: mette a null la chiave esterna di tutte le ennuple con valori della chiave esterna corrispondente alla chiave primaria delle ennuple cancellate


###### Comando reale per la creazione di tabelle
``` SQL
CREATE TABLE Clienti ( 
	CodiceCliente CHAR(3) UNIQUE NOT NULL, 
	Nome CHAR(30) NOT NULL, 
	Citta’ CHAR(30) NOT NULL, 
	Sconto INTEGER NOT NULL CHECK(Sconto>=0 AND Sconto<100), 
	PRIMARY KEY pk_Clienti(CodiceCliente)
)
CREATE TABLE Agenti ( 
	CodiceAgente CHAR(3) UNIQUE NOT NULL, 
	Nome CHAR(30) NOT NULL, 
	Zona CHAR(8) NOT NULL, 
	Supervisore CHAR(3), 
	Commissione INTEGER, 
	PRIMARY KEY pk_Agenti(CodiceAgente), 
	FOREIGN KEY Supervisore REFERENCES Agenti(CodiceAgente)
)
```

###### Modifiche agli schemi
Esistono dei comandi per modificare sia le tabelle che i domini dopo averli creati:
```SQL
-- **************************************
-- ESEMPIO 1: ALTER DOMAIN
-- Modifica il dominio 'email_address' aggiungendo un vincolo CHECK
-- per assicurare che il valore contenga sempre il simbolo '@'.
-- **************************************
ALTER DOMAIN email_address
ADD CONSTRAINT check_at_sign CHECK (VALUE LIKE '%@%');


-- **************************************
-- ESEMPIO 2: ALTER TABLE
-- Modifica la tabella 'employees':
-- 1. Aggiunge la colonna 'hire_date' (data di assunzione).
-- 2. Imposta un valore predefinito 'Active' per la colonna 'status'.
-- **************************************
ALTER TABLE employees
ADD COLUMN hire_date DATE,
ALTER COLUMN status SET DEFAULT 'Active';


-- **************************************
-- ESEMPIO 3: DROP DOMAIN
-- Elimina il dominio chiamato 'zip_code'.
-- **************************************
DROP DOMAIN zip_code RESTRICT;

-- **************************************
-- ESEMPIO 4: DROP TABLE
-- Elimina completamente la tabella 'projects' dal database.
-- **************************************
DROP TABLE projects;
```

###### Inserimento, modifica ed eliminazione dei dati:
- **Inserimento**: facciamo uso del comando **INSERT** che ha la seguente sintassi:![[Pasted image 20251022102525.png|500]]
- **Modifica**: facciamo uso del comando **UPDATE** che ha la seguente sintassi: 
  ![[Pasted image 20251022102731.png|500]]
- **Eliminazione**: facciamo uso del comando **DELETE** che la seguente sintassi:![[Pasted image 20251022102816.png|500]]
```SQL
INSERT INTO Esami VALUES (‘DB1’, 123456, 27)
DELETE FROM Esami WHERE Matricola = 123456
UPDATE Aule SET Aula = 126 WHERE Aula = 3
```
