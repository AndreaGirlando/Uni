Questo file è la rielaborazione delle slide [[12_Tecnologia-microelettronica.pdf]]
## Rappresentazione delle variabili binarie
- Nei circuiti elettronici, i valori binari 0 e 1 sono rappresentati da tensioni elettriche.
- La soglia di separazione discrimina tra i valori: tensioni superiori alla soglia rappresentano "1", mentre quelle inferiori rappresentano "0".
- Per evitare incertezze causate dal rumore, si definisce una **banda vietata** attorno alla soglia, i cui valori non vengono considerati.

---

## Transistori e tecnologia MOS
- I transistori funzionano come interruttori regolati dalla tensione di ingresso. I più comuni sono i transistori **MOS (metallo-ossido-semiconduttore)**.
- Valori tipici di tensione:
  - $V_{cc} = 5\,\text{V}$, $V_{\text{soglia}} = 2.5\,\text{V}$
  - $V_{cc} = 3.3\,\text{V}$, $V_{\text{soglia}} = 1.5\,\text{V}$

### Transistori NMOS e PMOS
- **NMOS**:
  - Conduzione con tensione alta in ingresso.
  - Sorgente collegata a massa.
- **PMOS**:
  - Conduzione con tensione bassa in ingresso.
  - Sorgente collegata all’alimentazione.

---

## Realizzazione di porte logiche
1. **NOT**: Realizzata con un transistore NMOS.
   - Se l’ingresso è "1", l’uscita sarà "0" e viceversa.  
   *[Inserire immagine del circuito NOT]*

2. **NOR**: Due NMOS in parallelo.
   - L’uscita è "1" solo se entrambi gli ingressi sono "0".  
   *[Inserire immagine del circuito NOR]*

3. **NAND**: Due NMOS in serie.
   - L’uscita è "0" solo se entrambi gli ingressi sono "1".  
   *[Inserire immagine del circuito NAND]*

---

## Tecnologia CMOS
- Combina transistori NMOS e PMOS, sfruttando il loro comportamento complementare:
  - Consumo di potenza ridotto (solo durante la commutazione).
  - Permette di integrare miliardi di transistori su un singolo chip.
- Esempi:
  - **NOT CMOS**: Un NMOS e un PMOS in serie.  
    *[Inserire immagine del circuito NOT CMOS]*

  - **NAND CMOS**: Due NMOS in serie e due PMOS in parallelo.  
    *[Inserire immagine del circuito NAND CMOS]*

  - **NOR CMOS**: Due NMOS in parallelo e due PMOS in serie.  
    *[Inserire immagine del circuito NOR CMOS]*

---

## Concetti avanzati
- **Ritardi nei circuiti**:
  - **Tempo di transizione**: Durata del cambio di stato di un segnale.
  - **Ritardo di propagazione**: Tempo richiesto per adattare l’uscita ai nuovi ingressi.
  - **Percorso critico**: Il percorso più lento determina la frequenza massima di lavoro.

- **Fan-in e fan-out**:
  - **Fan-in**: Numero di ingressi per porta logica.
  - **Fan-out**: Numero di uscite a cui può essere collegata una porta logica.
  - Limite tipico: 10 ingressi/uscite per porta.

---

## Circuiti integrati
- **Classificazione**:
  - **SSI**: Poche porte logiche.
  - **MSI**: Moduli funzionali come addizionatori o registri.
  - **LSI**: Processori semplici o ALU.
  - **VLSI**: Memorie avanzate e processori potenti.

---

## Decoder e multiplexer
1. **Decoder**:
   - Trasforma un codice binario in $n$ ingressi verso $2^n$ uscite.

2. **Multiplexer**:
   - Seleziona uno dei suoi ingressi in base a un codice di selezione $n$.  
   *[Inserire immagine del multiplexer]*
