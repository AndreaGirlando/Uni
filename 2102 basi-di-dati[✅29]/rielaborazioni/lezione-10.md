# Viste

###### Generalità
Oltre alle tabelle di base che fanno parte dello schema si possono creare delle **tabelle ausiliarie** virtuali (*le viste*) in quando non sono fisicamente presenti sul nostro database ma vengono create "al volo". Queste sono molto utili per vari motivi:
- *Semplificazione*
- *Protezione dei dati*
- *Scomposizione di query complesse*

###### Sintassi ed esempi
![[Pasted image 20251022104103.png|500]]
Praticamente quello che facciamo è dare un nome ad una select, questa cosa nell'esempio di seguito è palese:
```SQL
CREATE VIEW MediaVoti (Matricola,Media) AS 
	SELECT Matricola, AVG(Voto) 
		FROM Esami 
	GROUP BY Matricola
```
Trattiamo la nostra view come se fosse una vera è propria tabella quindi per interrogarla facciamo semplicemente:
```SQL
SELECT * FROM MediaVoti
```

###### I vari usi delle VIEW

*Uso delle view per semplificare delle query complesse*
```SQL
CREATE VIEW AgPerZona (Zona,NumAg) 
AS 
SELECT Zona,COUNT(*) FROM AGENTI GROUP BY Zona 

SELECT AVG(NumAg) FROM AgPerZona

SELECT AVG(NumAg) 
	FROM (SELECT Zona,COUNT(*) as NumAg 
	FROM AGENTI 
	GROUP BY Zona
)
```

*Uso delle view per sicurezza*
Data la tabella ClientiBanca(Nome, Indirizzo, Saldo)
```SQL
CREATE VIEW ClientiInd AS SELECT Nome,Indirizzo FROM ClientiBanca
```
La creazione di questa view potrebbe salvaguardare un minimo la privacy delle persone impedendo ad utenti non autorizzati di sapere il loro saldo

*Uso delle view come tabelle*
Le view possono essere utilizzate come vere è proprie tabelle con quindi tutti i comandi che ne conseguono: INSERT, UPDATE, DROP, ecc
Ovviamente essendo trattate come tabelle possiamo fare delle viste di una vista.

###### Aggiornamento delle VIEW
> [!QUESTION]
> Le operazioni di *INSERT/UPDATE/DELETE* sulle view ovviamente sono permesse, ma che senso hanno?

Sono utili nel caso di accesso dati controllato. 
**Esempio**:
Data la tabella seguente tabella:
- Impiegato( Nome, Cognome, Dipart, Ufficio, Stipendio)
Il personale della segreteria non può accedere ai dati sullo stipendio ma può modificare gli altri campi della tabella, quindi si crea una view e dedicata al personale della segreteria senza lo stipendi, quando questi andranno ad inserire valori dentro la view ci sono due strade:
- Stipendio diventa null o qualsiasi altro valore default
- Operazione fallisce se lo stipendio non può avere null

###### Check option sulle View
```SQL
CREATE VIEW ImpiegatoRossi AS SELECT * FROM Impiegato WHERE Cognome=‘Rossi’
```
- INSERT INTO ImpiegatoRossi (…’Rossi’,…)
- INSERT INTO ImpiegatoRossi (…’Bianchi’,…)

Entrambe queste operazioni sono permesse, ma ovviamente quando la seconda verrà fatta non ci sarà nessuna modifica alla vista

Ovviamente logicamente non ha molto senso che anche la seconda venga effettuata, qui nasce il bisogno di utilizzare **WITH CHECK OPTION** che va a fare un vero è proprio controllo sui comandi di modifica della view per vedere se rispettano i vincoli del where
```SQL
CREATE VIEW ImpiegatoRossi AS SELECT * FROM Impiegato WHERE Cognome=‘Rossi’ WITH CHECK OPTION
```

###### Esempi
![[Pasted image 20251022110208.png|500]]
![[Pasted image 20251022110223.png|500]]
![[Pasted image 20251022110238.png|500]]

###### Algebra relazionale: limiti
Ci sono delle interrogazioni che non possono essere espresse usando l''algebra relazionale, come:
- *Calcolo di valori derivati*: possiamo solo estrarre valori non calcolarne di nuovi
- *Interrogazioni ricorsive*: le interrogazioni ricorsive come la chiusura transitiva non sono possibili

###### Chiusura transitiva
![[Pasted image 20251022111559.png|500]]
In algebra relazionale questa interrogazione non è risolvibile perché servirebbero un numero di join infinite, con ridenominazioni ogni volta diverse, in sql invece si può fare, di seguito un esempio del calcolo del fattoriale (tipico esempio di ricorsività) in SQL
```SQL
WITH RECURSIVE factorial (n, fact) AS ( 
	SELECT 0, 1 -- Initial Subquery 
		UNION ALL
	SELECT n+1, (n+1)*fact 
	FROM factorial -- Recursive Subquery 
	WHERE n < 9 
) 
SELECT * FROM factorial;
```

Di seguito un esempio con un applicazione reale:
- Per ogni persona, trovare tutti gli antenati avendo: Paternita(Padre, Figlio)
![[Pasted image 20251022112332.png|500]]

###### Funzioni scalari
Esistono delle funzioni che agiscono a livello di ennupla per estrarre delle informazioni dal dato, come:
- *current_date* 
- *extract(year from data)*
- *char_length*
- *lower*
- *CAST(X as Tipo)*
- *ecc..*

###### Funzioni condizionali
- *Case*: è una struttura simile a if-then-else (sarebbe uno switch case)
- *Coalesce*: modifica il valore null in qualcosa che passiamo
- *NULLIF:* Restituisce NULL se i due argomenti che riceve sono **uguali**; altrimenti restituisce il primo argomento. È spesso usata per prevenire errori di divisione per zero.

```SQL
SELECT Nome, Cognome, COALESCE(Dipart,'Ignoto') 
FROM Impiegato 

SELECT Targa, 
	CASE Tipo 
		WHEN 'Auto' THEN 2.58 * KWatt 
		WHEN 'Moto' THEN (22.00 + 1.00 * KWatt) 
		ELSE NULL 
	END AS Tassa 
FROM Veicolo 
WHERE Anno > 1975
```