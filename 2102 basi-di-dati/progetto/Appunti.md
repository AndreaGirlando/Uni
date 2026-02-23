Utente(**Id**, Nome, Cognome, CodiceFiscale, DataNascita, TipoUtente, MatricolaStudente, IdentificativoPensione)
   TipoUtente = 'Studente, Pensionato, Standard'
   Fare un check sul campo:
   - se TipoUtente = Studente allora MatricolaStudente != NULL
   - se TipoUtente = Anziano allora IdentificativoPensione != NULL

---

TitoloViaggio(**Id**, *IdUtente*, *IdTariffa*, CodiceUnivoco, Tipo, DataEmissione, DataScadenza)
   Tipo = "Abbonamento" o "Biglietto"

---

Reclamo(**Id**, *IdCorsaEffettiva*, *IdUtente*, Testo, Data)

---

Validazione(**Id**, *IdTitoloViaggio*, *IdCorsaEffettiva*, Data)

---

CorsaEffettiva(**Id**, *IdCorsaPianificata*, *IdAutista*, *IdMezzo*, Data, OraPartenzaReale, OraArrivoReale)

---

Mezzo(**Id**, Targa, Tipo, Capienza, KmTotali, DataUltimaRevisione) 
Tipo = "Bus" o "Tram"

---

Manutenzione(**Id**, *IdMezzo*, Costo, DataInizio, DataFine, Descrizione, Stato)
Stato = "Fatta" o "Iniziata"

---

Rifornimento(**Id**, *IdMezzo*, Data, Quantità, CostoTotale, KmAttuali)
KmAttuali indica i chilometri del mezzo quando fa rifornimento, da questo ne possiamo tirare fuori i km al litro

---

Autista(**Id**, Nome, Cognome, DataAssunzione, DataScadenzaPatente)

---

Turno(**Id**, *IdAutista*, DataInizio, DataFine, TipoTurno)
**`TipoTurno`** (`VARCHAR` - es. "Lavoro", "Riposo", "Ferie", "Malattia")

---

Linea(**Id**, NomeDescrittivo)
PercorsoLinea(**Id**, *IdLinea*, *IdFermata*, progressivo)
Zona(**Id**, Nome)
TariffaTratta(**Id**, *IdZonaPartenza*, *IdZonaArrivo*, Prezzo)

Deviazione(**Id**, Motivo, DataFine, DataInizio)
PercorsoLinea(**Id**, *IdDeviazione*, *IdFermata*, progressivo)



### TODO
- [x] Deviazione
- [x] CorsaPianificata
- [x] Alcune cardinalità nelle relazioni
- [x] Controllare se va bene
- [x] Nello schema logico mancano le chiavi esterne
- [x] Cercare/Inserire un dato sulla quale fare le analisi delle ridondanze (modificare eventuale schema ER/logico)
- [x] Modificare almeno due query che che usino il dato dato ridondante
- [x] Modificare le operazioni, per fare le analisi sui dati ridondati serve che più operazioni lavorino sulle tabelle con i dati ridondanti in modo da fare i confronti
- [x] Capire se le stime sui volumi sono giusti
- [x] Analisi delle ridondanze
	- [x] Creazione delle stime e dei calcoli
	- [x] Sistemare la relazione
- [x] Analisi degli indici per il futuro
	- [x] Creazione delle stime e dai calcoli
	- [x] Sistemare la relazione
- [x] Scrivere le query per la creazione degli indici
- [x] Scrivere le query per la creazione del database
- [ ] Scrivere i trigger
	- [ ] Scrivere i trigger per i vincoli
	- [ ] Scrivere i trigger per il dato ridondante
- [ ] Scrivere le query per l'inserimento dei dati
- [ ] Scrivere le query per le varie operazioni definite
- [ ] Ultimare la relazione


---

