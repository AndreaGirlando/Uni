-- CREAZIONE DATABASE
CREATE DATABASE AziendaTrasporti;
USE AziendaTrasporti;

-- CREAZIONE TABELLE

-- 1. ZONA
CREATE TABLE Zona (
    Id INT PRIMARY KEY AUTO_INCREMENT,
    Nome VARCHAR(255) NOT NULL
);

-- 2. UTENTE
CREATE TABLE Utente (
    Id INT PRIMARY KEY AUTO_INCREMENT,
    Nome VARCHAR(100) NOT NULL,
    Cognome VARCHAR(100) NOT NULL,
    CodiceFiscale CHAR(16) UNIQUE,
    DataNascita DATE,
    TipoUtente VARCHAR(20) NOT NULL CHECK (TipoUtente IN ('Studente', 'Pensionato', 'Standard')),
    MatricolaStudente VARCHAR(50),
    IdentificativoPensione VARCHAR(50)
);

-- 3. AUTISTA
CREATE TABLE Autista (
    Id INT PRIMARY KEY AUTO_INCREMENT,
    Nome VARCHAR(100) NOT NULL,
    Cognome VARCHAR(100) NOT NULL,
    DataAssunzione DATE NOT NULL,
    DataScadenzaPatente DATE NOT NULL
);

-- 4. MEZZO
CREATE TABLE Mezzo (
    Id INT PRIMARY KEY AUTO_INCREMENT,
    Targa VARCHAR(20) UNIQUE NOT NULL,
    Tipo VARCHAR(10) NOT NULL CHECK (Tipo IN ('Bus', 'Tram')),
    Capienza INT NOT NULL CHECK (Capienza > 0),
    KmTotali DECIMAL(10,2) NOT NULL,
    DataUltimaRevisione DATE
);

-- 5. LINEA
CREATE TABLE Linea (
    Id INT PRIMARY KEY AUTO_INCREMENT,
    NomeDescrittivo VARCHAR(255) NOT NULL
);

-- 6. TARIFFA TRATTA
CREATE TABLE TariffaTratta (
    Id INT PRIMARY KEY AUTO_INCREMENT,
    IdZonaPartenza INT NOT NULL,
    IdZonaArrivo INT NOT NULL,
    Prezzo DECIMAL(6,2) NOT NULL CHECK (Prezzo > 0),
    FOREIGN KEY (IdZonaPartenza) REFERENCES Zona(Id),
    FOREIGN KEY (IdZonaArrivo) REFERENCES Zona(Id)
);

-- 7. FERMATA
CREATE TABLE Fermata (
    Id INT PRIMARY KEY AUTO_INCREMENT,
    IdZona INT NOT NULL,
    Nome VARCHAR(255) NOT NULL,
    Latitudine DECIMAL(9,6),
    Longitudine DECIMAL(9,6),
    FOREIGN KEY (IdZona) REFERENCES Zona(Id)
);

-- 8. TITOLO VIAGGIO
CREATE TABLE TitoloViaggio (
    Id INT PRIMARY KEY AUTO_INCREMENT,
    IdUtente INT,
    IdTariffa INT NOT NULL,
    CodiceUnivoco VARCHAR(100) UNIQUE NOT NULL,
    Tipo VARCHAR(20) NOT NULL CHECK (Tipo IN ('Abbonamento', 'Biglietto')),
    DataEmissione DATE NOT NULL,
    DataScadenza DATE NOT NULL,
    FOREIGN KEY (IdUtente) REFERENCES Utente(Id),
    FOREIGN KEY (IdTariffa) REFERENCES TariffaTratta(Id)
);

-- 9. CORSA PIANIFICATA
CREATE TABLE CorsaPianificata (
    Id INT PRIMARY KEY AUTO_INCREMENT,
    IdLinea INT NOT NULL,
    OraPartenza TIME NOT NULL,
    KmTotali DECIMAL(8,2) NOT NULL,
    FOREIGN KEY (IdLinea) REFERENCES Linea(Id)
);

-- 10. MANUTENZIONE
CREATE TABLE Manutenzione (
    Id INT PRIMARY KEY AUTO_INCREMENT,
    IdMezzo INT NOT NULL,
    Costo DECIMAL(8,2) NOT NULL CHECK (Costo > 0),
    DataInizio DATE NOT NULL,
    DataFine DATE NOT NULL,
    Descrizione TEXT,
    Stato VARCHAR(20) NOT NULL CHECK (Stato IN ('Finita', 'Iniziata')),
    FOREIGN KEY (IdMezzo) REFERENCES Mezzo(Id),
    CHECK (DataFine >= DataInizio)
);

-- 11. RIFORNIMENTO
CREATE TABLE Rifornimento (
    Id INT PRIMARY KEY AUTO_INCREMENT,
    IdMezzo INT NOT NULL,
    Data DATE NOT NULL,
    Quantita DECIMAL(8,2) NOT NULL CHECK (Quantita > 0),
    CostoTotale DECIMAL(8,2) NOT NULL CHECK (CostoTotale > 0),
    KmAttuali DECIMAL(10,2) NOT NULL,
    FOREIGN KEY (IdMezzo) REFERENCES Mezzo(Id)
);

-- 12. TURNO
CREATE TABLE Turno (
    Id INT PRIMARY KEY AUTO_INCREMENT,
    IdAutista INT NOT NULL,
    DataInizio DATETIME NOT NULL,
    DataFine DATETIME NOT NULL,
    TipoTurno VARCHAR(20) NOT NULL CHECK (TipoTurno IN ('Lavoro', 'Riposo', 'Ferie', 'Malattia', 'Straordinario')),
    FOREIGN KEY (IdAutista) REFERENCES Autista(Id),
    CHECK (DataFine >= DataInizio)
);

-- 13. CORSA EFFETTIVA
CREATE TABLE CorsaEffettiva (
    Id INT PRIMARY KEY AUTO_INCREMENT,
    IdCorsaPianificata INT NOT NULL,
    IdAutista INT NOT NULL,
    NumeroPasseggeri INT DEFAULT 0,
    IdMezzo INT NOT NULL,
    Data DATE NOT NULL,
    OraPartenzaReale TIME NOT NULL,
    OraArrivoReale TIME NOT NULL,
    FOREIGN KEY (IdCorsaPianificata) REFERENCES CorsaPianificata(Id),
    FOREIGN KEY (IdAutista) REFERENCES Autista(Id),
    FOREIGN KEY (IdMezzo) REFERENCES Mezzo(Id),
    CHECK (OraArrivoReale > OraPartenzaReale)
);

-- 14. PERCORSO LINEA
CREATE TABLE PercorsoLinea (
    Id INT PRIMARY KEY AUTO_INCREMENT,
    IdLinea INT NOT NULL,
    IdFermata INT NOT NULL,
    Progressivo INT NOT NULL,
    FOREIGN KEY (IdLinea) REFERENCES Linea(Id),
    FOREIGN KEY (IdFermata) REFERENCES Fermata(Id)
);

-- 15. DEVIAZIONE
CREATE TABLE Deviazione (
    Id INT PRIMARY KEY AUTO_INCREMENT,
    IdLinea INT NOT NULL,
    Motivo TEXT,
    DataInizio DATE NOT NULL,
    DataFine DATE NOT NULL,
    FOREIGN KEY (IdLinea) REFERENCES Linea(Id),
    CHECK (DataFine >= DataInizio)
);

-- 16. PERCORSO DEVIAZIONE
CREATE TABLE PercorsoDeviazione (
    Id INT PRIMARY KEY AUTO_INCREMENT,
    IdDeviazione INT NOT NULL,
    IdFermata INT NOT NULL,
    Progressivo INT NOT NULL,
    FOREIGN KEY (IdDeviazione) REFERENCES Deviazione(Id),
    FOREIGN KEY (IdFermata) REFERENCES Fermata(Id)
);

-- 17. VALIDAZIONE
CREATE TABLE Validazione (
    Id INT PRIMARY KEY AUTO_INCREMENT,
    IdTitoloViaggio INT NOT NULL,
    IdCorsaEffettiva INT NOT NULL,
    Data DATETIME NOT NULL,
    FOREIGN KEY (IdTitoloViaggio) REFERENCES TitoloViaggio(Id),
    FOREIGN KEY (IdCorsaEffettiva) REFERENCES CorsaEffettiva(Id)
);

-- 18. RECLAMO
CREATE TABLE Reclamo (
    Id INT PRIMARY KEY AUTO_INCREMENT,
    IdCorsaEffettiva INT NOT NULL,
    IdUtente INT NOT NULL,
    Testo TEXT NOT NULL,
    Data DATE NOT NULL,
    FOREIGN KEY (IdCorsaEffettiva) REFERENCES CorsaEffettiva(Id),
    FOREIGN KEY (IdUtente) REFERENCES Utente(Id)
);


-- CREAZIONE INDICI
CREATE INDEX idx_validazione_corsaeffettiva ON Validazione(IdCorsaEffettiva);


-- Cambiamo il delimitatore standard da ; a $$
DELIMITER $$

-- Trigger 1: La data di validazione deve rientrare nella validità del Titolo di Viaggio
CREATE TRIGGER trg_check_data_validazione
BEFORE INSERT ON Validazione
FOR EACH ROW
BEGIN
    DECLARE v_data_emissione DATE;
    DECLARE v_data_scadenza DATE;

    SELECT DataEmissione, DataScadenza 
    INTO v_data_emissione, v_data_scadenza
    FROM TitoloViaggio
    WHERE Id = NEW.IdTitoloViaggio;

    IF DATE(NEW.Data) < v_data_emissione OR DATE(NEW.Data) > v_data_scadenza THEN
        SIGNAL SQLSTATE '45000' 
        SET MESSAGE_TEXT = 'Errore: Data validazione fuori dal periodo del Titolo di Viaggio.';
    END IF;
END $$

-- Trigger 2: Controllo validità patente per assegnazione Turno lavorativo
CREATE TRIGGER trg_check_patente_turno
BEFORE INSERT ON Turno
FOR EACH ROW
BEGIN
    DECLARE v_scadenza_patente DATE;

    IF NEW.TipoTurno = 'Lavoro' THEN
        SELECT DataScadenzaPatente INTO v_scadenza_patente
        FROM Autista
        WHERE Id = NEW.IdAutista;

        IF DATE(NEW.DataInizio) > v_scadenza_patente OR DATE(NEW.DataFine) > v_scadenza_patente THEN
            SIGNAL SQLSTATE '45000' 
            SET MESSAGE_TEXT = 'Errore: Impossibile assegnare turno. Patente scaduta.';
        END IF;
    END IF;
END $$

-- Trigger 3: Controllo validità patente per assegnazione Corsa Effettiva
CREATE TRIGGER trg_check_patente_corsa
BEFORE INSERT ON CorsaEffettiva
FOR EACH ROW
BEGIN
    DECLARE v_scadenza_patente DATE;

    SELECT DataScadenzaPatente INTO v_scadenza_patente
    FROM Autista
    WHERE Id = NEW.IdAutista;

    IF NEW.Data > v_scadenza_patente THEN
        SIGNAL SQLSTATE '45000' 
        SET MESSAGE_TEXT = 'Errore: Impossibile assegnare la corsa. Patente scaduta.';
    END IF;
END $$

-- Trigger 4: Coerenza chilometraggio durante il rifornimento
CREATE TRIGGER trg_check_km_rifornimento
BEFORE INSERT ON Rifornimento
FOR EACH ROW
BEGIN
    DECLARE v_km_totali DECIMAL(10,2);

    SELECT KmTotali INTO v_km_totali
    FROM Mezzo
    WHERE Id = NEW.IdMezzo;

    IF NEW.KmAttuali > v_km_totali THEN
        SIGNAL SQLSTATE '45000' 
        SET MESSAGE_TEXT = 'Errore: I KmAttuali nel rifornimento superano i KmTotali del Mezzo.';
    END IF;
END $$

-- Trigger 5: Incremento automatico del numero passeggeri ad ogni validazione
CREATE TRIGGER trg_incrementa_passeggeri
AFTER INSERT ON Validazione
FOR EACH ROW
BEGIN
    UPDATE CorsaEffettiva
    SET NumeroPasseggeri = NumeroPasseggeri + 1
    WHERE Id = NEW.IdCorsaEffettiva;
END $$

-- Ripristiniamo il delimitatore standard
DELIMITER ;



