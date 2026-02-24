USE AziendaTrasporti;

-- OP 1
INSERT INTO Validazione (IdTitoloViaggio, IdCorsaEffettiva, Data)
VALUES (20, 17, NOW());

-- OP 2
INSERT INTO TitoloViaggio (IdUtente, IdTariffa, CodiceUnivoco, Tipo, DataEmissione, DataScadenza)
VALUES (10, 3, 'TX-987654321', 'Biglietto', CURDATE(), DATE_ADD(CURDATE(), INTERVAL 1 DAY));

-- OP 4
INSERT INTO CorsaEffettiva (IdCorsaPianificata, IdAutista, NumeroPasseggeri, IdMezzo, Data, OraPartenzaReale, OraArrivoReale)
VALUES (5, 4, 0, 2, CURDATE(), '14:05:00', '15:00:00');

-- OP 7
INSERT INTO Reclamo (IdCorsaEffettiva, IdUtente, Testo, Data)
VALUES (1, 12, 'L''autobus ha saltato la mia fermata nonostante avessi prenotato la discesa.', CURDATE());

-- OP 3
SELECT 
    CP.Id AS IdCorsa, 
    L.NomeDescrittivo AS Linea, 
    CP.OraPartenza AS OrarioPartenzaCapolinea, 
    F.Nome AS FermataRichiesta
FROM CorsaPianificata CP
JOIN Linea L ON CP.IdLinea = L.Id
JOIN PercorsoLinea PL ON L.Id = PL.IdLinea
JOIN Fermata F ON PL.IdFermata = F.Id
WHERE L.Id = 1 AND F.Id = 5
ORDER BY CP.OraPartenza ASC;

-- OP 5
SELECT 
    PL.Progressivo, 
    F.Nome AS NomeFermata, 
    Z.Nome AS ZonaTariffaria
FROM PercorsoLinea PL
JOIN Fermata F ON PL.IdFermata = F.Id
JOIN Zona Z ON F.IdZona = Z.Id
WHERE PL.IdLinea = 2
ORDER BY PL.Progressivo ASC;

-- OP 6
SELECT 
    CE.Id AS IdCorsaEffettiva, 
    L.NomeDescrittivo AS Linea,
    CE.Data, 
    CE.OraPartenzaReale, 
    CE.NumeroPasseggeri AS AffollamentoTotale
FROM CorsaEffettiva CE
JOIN CorsaPianificata CP ON CE.IdCorsaPianificata = CP.Id
JOIN Linea L ON CP.IdLinea = L.Id
ORDER BY CE.Data DESC, CE.NumeroPasseggeri DESC;

-- OP 8
SELECT 
    L.NomeDescrittivo AS NomeLinea,
    COUNT(CE.Id) AS TotaleCorseEffettuate,
    ROUND(AVG(TIMESTAMPDIFF(MINUTE, CP.OraPartenza, CE.OraPartenzaReale)), 2) AS RitardoMedioMinuti
FROM CorsaEffettiva CE
JOIN CorsaPianificata CP ON CE.IdCorsaPianificata = CP.Id
JOIN Linea L ON CP.IdLinea = L.Id
WHERE MONTH(CE.Data) = 2 AND YEAR(CE.Data) = 2026
GROUP BY L.Id, L.NomeDescrittivo
ORDER BY RitardoMedioMinuti DESC;




