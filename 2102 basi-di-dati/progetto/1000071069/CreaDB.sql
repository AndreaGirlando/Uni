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


-- CREAZIONE TRIGGER

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

-- Ripristino il delimitatore standard
DELIMITER ;

-- INSERIMENTO DATI
-- 1. ZONA (3)
INSERT INTO Zona VALUES 
(1, 'Centro Storico'),
(2, 'Periferia Nord'),
(3, 'Area Industriale Sud');

-- 2. UTENTE (20)
INSERT INTO Utente VALUES 
(1, 'Mario', 'Rossi', 'RSSMRA80A01H501A', '1980-01-01', 'Standard', NULL, NULL),
(2, 'Laura', 'Bianchi', 'BNCLRA95B42H501B', '1995-02-12', 'Studente', 'MAT12345', NULL),
(3, 'Giuseppe', 'Verdi', 'VRDGPP50C15H501C', '1950-03-15', 'Pensionato', NULL, 'PEN98765'),
(4, 'Anna', 'Neri', 'NRANNA88D50H501D', '1988-04-20', 'Standard', NULL, NULL),
(5, 'Luigi', 'Gialli', 'GLLLGU02E05H501E', '2002-05-05', 'Studente', 'MAT67890', NULL),
(6, 'Maria', 'Blu', 'BLUMRA45F45H501F', '1945-06-10', 'Pensionato', NULL, 'PEN12345'),
(7, 'Francesco', 'Marroni', 'MRRFNC90G11H501G', '1990-07-11', 'Standard', NULL, NULL),
(8, 'Elena', 'Rosa', 'RSELNE99H55H501H', '1999-08-15', 'Studente', 'MAT54321', NULL),
(9, 'Paolo', 'Viola', 'VLAPLA60I20H501I', '1960-09-20', 'Pensionato', NULL, 'PEN11223'),
(10, 'Chiara', 'Grigi', 'GRGCHR85L60H501L', '1985-10-30', 'Standard', NULL, NULL),
(11, 'Roberto', 'Arancio', 'RNCRBR75M12H501M', '1975-11-12', 'Standard', NULL, NULL),
(12, 'Francesca', 'Azzurri', 'ZZRFNC01N45H501N', '2001-12-05', 'Studente', 'MAT99887', NULL),
(13, 'Antonio', 'Celesti', 'CLSNTN55O10H501O', '1955-01-10', 'Pensionato', NULL, 'PEN44556'),
(14, 'Silvia', 'Amaranto', 'MRNSLV92P52H501P', '1992-02-22', 'Standard', NULL, NULL),
(15, 'Marco', 'Cremisi', 'CRMMRC98Q03H501Q', '1998-03-03', 'Studente', 'MAT33445', NULL),
(16, 'Valeria', 'Indaco', 'NDCVLR48R48H501R', '1948-04-14', 'Pensionato', NULL, 'PEN77889'),
(17, 'Giovanni', 'Ocra', 'Crogvn82S07H501S', '1982-05-07', 'Standard', NULL, NULL),
(18, 'Martina', 'Prugna', 'PRGMRT03T63H501T', '2003-06-25', 'Studente', 'MAT55667', NULL),
(19, 'Stefano', 'Zaffiro', 'ZFFSFN68U18H501U', '1968-07-18', 'Pensionato', NULL, 'PEN99001'),
(20, 'Lucia', 'Corallo', 'CRLLCU89V59H501V', '1989-08-29', 'Standard', NULL, NULL);

-- 3. AUTISTA (5)
-- DataScadenzaPatente impostata nel futuro per evitare blocchi dai Trigger 2 e 3
INSERT INTO Autista VALUES 
(1, 'Claudio', 'Forte', '2015-05-10', '2030-12-31'),
(2, 'Simone', 'Lento', '2018-09-01', '2028-10-15'),
(3, 'Alessandro', 'Rapido', '2020-02-20', '2029-05-20'),
(4, 'Marta', 'Guida', '2021-07-15', '2031-08-10'),
(5, 'Giorgio', 'Strada', '2010-11-05', '2027-11-30');

-- 4. MEZZO (5)
-- KmTotali alti per rispettare il Trigger 4 sui rifornimenti
INSERT INTO Mezzo VALUES 
(1, 'AB123CD', 'Bus', 50, 150000.00, '2025-10-10'),
(2, 'EF456GH', 'Bus', 50, 120000.00, '2025-11-15'),
(3, 'IL789MN', 'Tram', 120, 80000.00, '2026-01-05'),
(4, 'OP012QR', 'Tram', 120, 95000.00, '2025-08-20'),
(5, 'ST345UV', 'Bus', 30, 200000.00, '2025-12-01');

-- 5. LINEA (2)
INSERT INTO Linea VALUES 
(1, 'Linea 1 - Circolare Centro-Nord'),
(2, 'Linea 2 - Direttissima Centro-Sud');

-- 6. TARIFFA TRATTA (6)
INSERT INTO TariffaTratta VALUES 
(1, 1, 1, 1.50),
(2, 1, 2, 2.00),
(3, 1, 3, 2.50),
(4, 2, 1, 2.00),
(5, 3, 1, 2.50),
(6, 2, 3, 3.00);

-- 7. FERMATA (15)
INSERT INTO Fermata VALUES 
(1, 1, 'Piazza Garibaldi', 45.123456, 9.123456),
(2, 1, 'Via Roma', 45.124456, 9.124456),
(3, 1, 'Duomo', 45.125456, 9.125456),
(4, 1, 'Stazione Centrale', 45.126456, 9.126456),
(5, 1, 'Via Cavour', 45.127456, 9.127456),
(6, 2, 'Ospedale Nord', 45.130456, 9.130456),
(7, 2, 'Stadio', 45.132456, 9.132456),
(8, 2, 'Via Milano', 45.134456, 9.134456),
(9, 2, 'Parco Nord', 45.136456, 9.136456),
(10, 2, 'Polo Universitario', 45.138456, 9.138456),
(11, 3, 'Fiera Sud', 45.110456, 9.110456),
(12, 3, 'Zona Industriale 1', 45.108456, 9.108456),
(13, 3, 'Zona Industriale 2', 45.106456, 9.106456),
(14, 3, 'Centro Commerciale', 45.104456, 9.104456),
(15, 3, 'Capolinea Sud', 45.102456, 9.102456);

-- 8. TITOLO VIAGGIO
-- Emissione/Scadenza ampie per non far scattare il Trigger 1 nelle validazioni del 2026
INSERT INTO TitoloViaggio VALUES 
(1, 1, 1, 'TKT001', 'Abbonamento', '2026-01-01', '2026-12-31'),
(2, 2, 2, 'TKT002', 'Abbonamento', '2026-01-01', '2026-12-31'),
(3, 3, 3, 'TKT003', 'Abbonamento', '2026-01-01', '2026-12-31'),
(4, 4, 4, 'TKT004', 'Abbonamento', '2026-01-01', '2026-12-31'),
(5, 5, 5, 'TKT005', 'Abbonamento', '2026-01-01', '2026-12-31'),
(6, 6, 6, 'TKT006', 'Abbonamento', '2026-01-01', '2026-12-31'),
(7, 7, 1, 'TKT007', 'Abbonamento', '2026-01-01', '2026-12-31'),
(8, 8, 2, 'TKT008', 'Abbonamento', '2026-01-01', '2026-12-31'),
(9, 9, 3, 'TKT009', 'Abbonamento', '2026-01-01', '2026-12-31'),
(10, 10, 4, 'TKT010', 'Abbonamento', '2026-01-01', '2026-12-31'),
(11, 11, 1, 'TKT011', 'Biglietto', '2026-02-01', '2026-12-31'),
(12, 12, 2, 'TKT012', 'Biglietto', '2026-02-01', '2026-12-31'),
(13, 13, 3, 'TKT013', 'Biglietto', '2026-02-01', '2026-12-31'),
(14, 14, 4, 'TKT014', 'Biglietto', '2026-02-01', '2026-12-31'),
(15, 15, 5, 'TKT015', 'Biglietto', '2026-02-01', '2026-12-31'),
(16, 16, 6, 'TKT016', 'Biglietto', '2026-02-01', '2026-12-31'),
(17, 17, 1, 'TKT017', 'Biglietto', '2026-02-01', '2026-12-31'),
(18, 18, 2, 'TKT018', 'Biglietto', '2026-02-01', '2026-12-31'),
(19, 19, 3, 'TKT019', 'Biglietto', '2026-02-01', '2026-12-31'),
(20, 20, 4, 'TKT020', 'Biglietto', '2026-02-01', '2026-12-31'),
(21, 1, 5, 'TKT021', 'Biglietto', '2026-02-01', '2026-12-31'),
(22, 2, 6, 'TKT022', 'Biglietto', '2026-02-01', '2026-12-31'),
(23, 3, 1, 'TKT023', 'Biglietto', '2026-02-01', '2026-12-31'),
(24, 4, 2, 'TKT024', 'Biglietto', '2026-02-01', '2026-12-31'),
(25, 5, 3, 'TKT025', 'Biglietto', '2026-02-01', '2026-12-31'),
(26, 6, 4, 'TKT026', 'Biglietto', '2026-02-01', '2026-12-31'),
(27, 7, 5, 'TKT027', 'Biglietto', '2026-02-01', '2026-12-31'),
(28, 8, 6, 'TKT028', 'Biglietto', '2026-02-01', '2026-12-31'),
(29, 9, 1, 'TKT029', 'Biglietto', '2026-02-01', '2026-12-31'),
(30, 10, 2, 'TKT030', 'Biglietto', '2026-02-01', '2026-12-31');

-- 9. CORSA PIANIFICATA (10)
INSERT INTO CorsaPianificata VALUES 
(1, 1, '06:00:00', 15.50),
(2, 1, '08:00:00', 15.50),
(3, 1, '10:00:00', 15.50),
(4, 1, '12:00:00', 15.50),
(5, 1, '14:00:00', 15.50),
(6, 2, '07:00:00', 20.00),
(7, 2, '09:00:00', 20.00),
(8, 2, '11:00:00', 20.00),
(9, 2, '13:00:00', 20.00),
(10, 2, '15:00:00', 20.00);

-- 10. MANUTENZIONE (2)
INSERT INTO Manutenzione VALUES 
(1, 1, 500.00, '2026-01-10', '2026-01-12', 'Cambio olio e filtri', 'Finita'),
(2, 3, 1200.00, '2026-02-01', '2026-02-05', 'Riparazione sistema elettrico tram', 'Finita');

-- 11. RIFORNIMENTO (4)
-- KmAttuali bassi per rispettare il Trigger 4 rispetto ai KmTotali dei Mezzi
INSERT INTO Rifornimento VALUES 
(1, 1, '2026-02-10', 100.50, 150.00, 140000.00),
(2, 2, '2026-02-11', 80.00, 120.00, 110000.00),
(3, 4, '2026-02-12', 50.00, 75.00, 90000.00),
(4, 5, '2026-02-13', 120.00, 180.00, 195000.00);

-- 12. TURNO (10)
INSERT INTO Turno VALUES 
(1, 1, '2026-02-15 05:00:00', '2026-02-15 13:00:00', 'Lavoro'),
(2, 2, '2026-02-15 06:00:00', '2026-02-15 14:00:00', 'Lavoro'),
(3, 3, '2026-02-15 13:00:00', '2026-02-15 21:00:00', 'Lavoro'),
(4, 4, '2026-02-15 14:00:00', '2026-02-15 22:00:00', 'Lavoro'),
(5, 5, '2026-02-15 00:00:00', '2026-02-15 23:59:59', 'Riposo'),
(6, 1, '2026-02-16 05:00:00', '2026-02-16 13:00:00', 'Lavoro'),
(7, 2, '2026-02-16 06:00:00', '2026-02-16 14:00:00', 'Lavoro'),
(8, 3, '2026-02-16 00:00:00', '2026-02-16 23:59:59', 'Riposo'),
(9, 4, '2026-02-16 14:00:00', '2026-02-16 22:00:00', 'Lavoro'),
(10, 5, '2026-02-16 13:00:00', '2026-02-16 21:00:00', 'Lavoro');

-- 13. CORSA EFFETTIVA (20)
-- Dati compatibili con le pianificate, trigger 3 rispettato
INSERT INTO CorsaEffettiva VALUES 
(1, 1, 1, 45, 1, '2026-02-15', '06:02:00', '06:55:00'),
(2, 2, 1, 50, 1, '2026-02-15', '08:05:00', '08:58:00'),
(3, 3, 1, 30, 1, '2026-02-15', '10:00:00', '10:50:00'),
(4, 4, 3, 40, 2, '2026-02-15', '12:01:00', '12:54:00'),
(5, 5, 3, 35, 2, '2026-02-15', '14:00:00', '14:52:00'),
(6, 6, 2, 80, 3, '2026-02-15', '07:03:00', '08:15:00'),
(7, 7, 2, 90, 3, '2026-02-15', '09:00:00', '10:10:00'),
(8, 8, 2, 70, 3, '2026-02-15', '11:05:00', '12:15:00'),
(9, 9, 4, 85, 4, '2026-02-15', '13:02:00', '14:12:00'),
(10, 10, 4, 60, 4, '2026-02-15', '15:00:00', '16:05:00'),
(11, 1, 1, 42, 1, '2026-02-16', '06:01:00', '06:52:00'),
(12, 2, 1, 48, 1, '2026-02-16', '08:00:00', '08:55:00'),
(13, 3, 5, 33, 2, '2026-02-16', '10:05:00', '10:55:00'),
(14, 4, 5, 38, 2, '2026-02-16', '12:00:00', '12:50:00'),
(15, 5, 4, 40, 5, '2026-02-16', '14:02:00', '14:55:00'),
(16, 6, 2, 75, 3, '2026-02-16', '07:00:00', '08:10:00'),
(17, 7, 2, 85, 3, '2026-02-16', '09:02:00', '10:12:00'),
(18, 8, 2, 65, 3, '2026-02-16', '11:00:00', '12:08:00'),
(19, 9, 4, 82, 4, '2026-02-16', '13:05:00', '14:15:00'),
(20, 10, 4, 55, 4, '2026-02-16', '15:02:00', '16:10:00');

-- 14. PERCORSO LINEA (25)
INSERT INTO PercorsoLinea VALUES 
(1, 1, 1, 1), (2, 1, 2, 2), (3, 1, 3, 3), (4, 1, 4, 4), 
(5, 1, 5, 5), (6, 1, 6, 6), (7, 1, 7, 7), (8, 1, 8, 8), 
(9, 1, 9, 9), (10, 1, 10, 10), (11, 1, 4, 11), (12, 1, 1, 12),
(13, 2, 4, 1), (14, 2, 3, 2), (15, 2, 2, 3), (16, 2, 1, 4), 
(17, 2, 11, 5), (18, 2, 12, 6), (19, 2, 13, 7), (20, 2, 14, 8), 
(21, 2, 15, 9), (22, 2, 14, 10), (23, 2, 11, 11), (24, 2, 1, 12), 
(25, 2, 4, 13);

-- 15. DEVIAZIONE (2)
INSERT INTO Deviazione VALUES 
(1, 1, 'Lavori in corso in Via Roma', '2026-02-10', '2026-02-20'),
(2, 2, 'Manifestazione in Piazza Garibaldi', '2026-03-01', '2026-03-01');

-- 16. PERCORSO DEVIAZIONE (5)
INSERT INTO PercorsoDeviazione VALUES 
(1, 1, 1, 1),
(2, 1, 5, 2),
(3, 1, 4, 3),
(4, 2, 4, 1),
(5, 2, 11, 2);

-- 17. VALIDAZIONE (60)
-- 2 validazioni per ciascuno dei 30 Titoli, Trigger 1 rispettato
INSERT INTO Validazione VALUES 
(1, 1, 1, '2026-02-15 06:10:00'), (2, 1, 6, '2026-02-15 07:15:00'),
(3, 2, 2, '2026-02-15 08:10:00'), (4, 2, 7, '2026-02-15 09:15:00'),
(5, 3, 3, '2026-02-15 10:10:00'), (6, 3, 8, '2026-02-15 11:15:00'),
(7, 4, 4, '2026-02-15 12:10:00'), (8, 4, 9, '2026-02-15 13:15:00'),
(9, 5, 5, '2026-02-15 14:10:00'), (10, 5, 10, '2026-02-15 15:15:00'),
(11, 6, 11, '2026-02-16 06:10:00'), (12, 6, 16, '2026-02-16 07:15:00'),
(13, 7, 12, '2026-02-16 08:10:00'), (14, 7, 17, '2026-02-16 09:15:00'),
(15, 8, 13, '2026-02-16 10:10:00'), (16, 8, 18, '2026-02-16 11:15:00'),
(17, 9, 14, '2026-02-16 12:10:00'), (18, 9, 19, '2026-02-16 13:15:00'),
(19, 10, 15, '2026-02-16 14:10:00'), (20, 10, 20, '2026-02-16 15:15:00'),
(21, 11, 1, '2026-02-15 06:20:00'), (22, 11, 6, '2026-02-15 07:25:00'),
(23, 12, 2, '2026-02-15 08:20:00'), (24, 12, 7, '2026-02-15 09:25:00'),
(25, 13, 3, '2026-02-15 10:20:00'), (26, 13, 8, '2026-02-15 11:25:00'),
(27, 14, 4, '2026-02-15 12:20:00'), (28, 14, 9, '2026-02-15 13:25:00'),
(29, 15, 5, '2026-02-15 14:20:00'), (30, 15, 10, '2026-02-15 15:25:00'),
(31, 16, 11, '2026-02-16 06:20:00'), (32, 16, 16, '2026-02-16 07:25:00'),
(33, 17, 12, '2026-02-16 08:20:00'), (34, 17, 17, '2026-02-16 09:25:00'),
(35, 18, 13, '2026-02-16 10:20:00'), (36, 18, 18, '2026-02-16 11:25:00'),
(37, 19, 14, '2026-02-16 12:20:00'), (38, 19, 19, '2026-02-16 13:25:00'),
(39, 20, 15, '2026-02-16 14:20:00'), (40, 20, 20, '2026-02-16 15:25:00'),
(41, 21, 1, '2026-02-15 06:30:00'), (42, 21, 6, '2026-02-15 07:35:00'),
(43, 22, 2, '2026-02-15 08:30:00'), (44, 22, 7, '2026-02-15 09:35:00'),
(45, 23, 3, '2026-02-15 10:30:00'), (46, 23, 8, '2026-02-15 11:35:00'),
(47, 24, 4, '2026-02-15 12:30:00'), (48, 24, 9, '2026-02-15 13:35:00'),
(49, 25, 5, '2026-02-15 14:30:00'), (50, 25, 10, '2026-02-15 15:35:00'),
(51, 26, 11, '2026-02-16 06:30:00'), (52, 26, 16, '2026-02-16 07:35:00'),
(53, 27, 12, '2026-02-16 08:30:00'), (54, 27, 17, '2026-02-16 09:35:00'),
(55, 28, 13, '2026-02-16 10:30:00'), (56, 28, 18, '2026-02-16 11:35:00'),
(57, 29, 14, '2026-02-16 12:30:00'), (58, 29, 19, '2026-02-16 13:35:00'),
(59, 30, 15, '2026-02-16 14:30:00'), (60, 30, 20, '2026-02-16 15:35:00');

-- 18. RECLAMO (2)
INSERT INTO Reclamo VALUES 
(1, 1, 1, 'Il pullman era in ritardo di 10 minuti.', '2026-02-15'),
(2, 6, 5, 'Mancava aria condizionata sul tram.', '2026-02-16');