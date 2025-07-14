Questo file è la rielaborazione delle slide [[12_Tecnologia-microelettronica.pdf]]

---
###### Rappresentazione delle variabili binarie
- Nei circuiti elettronici, i valori binari 0 e 1 sono rappresentati da livelli di tensione.
- La soglia separa gli 0 dagli 1. Ad esempio, in un sistema a 5V:
    - Tensioni sotto 1,5V = 0.
    - Tensioni sopra 3,5V = 1.
- Per evitare errori, esiste una "banda vietata" vicino alla soglia dove i valori non sono validi.
- La banda vietata riduce le incertezze causate da rumore e disturbi.

---
###### Cos'è un transistor?
- Un transistor è un semiconduttore usato per amplificare o commutare segnali elettronici.
- Materiali come il silicio sono drogati per creare zone positive e negative.
- Funziona come un interruttore che può essere in conduzione o in interdizione.
- Esistono due tipi principali di transistor:
    - **BJT (bipolare)**: La corrente è controllata da una corrente di base.
    - **FET (a effetto di campo)**: La corrente è controllata dalla tensione applicata al gate.

---
###### Tecnologia MOS (Metallo-Ossido-Semiconduttore)

- I transistor MOS sono i più comuni nei circuiti integrati.
- Valori tipici di tensione:
    - $V_{cc} = 5V$, $V_{soglia} = 2,5V$
    - $V_{cc} = 3,3V$, $V_{soglia} = 1,5V$
- Sopra la soglia = 1, sotto la soglia = 0.
- La tecnologia MOS consente di ridurre dimensioni e consumi, rendendo possibile l'integrazione di miliardi di transistor.

---
###### Tipi di transistor MOS
- **NMOS**:
    - Conduzione con tensione alta in ingresso.
    - Sorgente collegata a massa.
- **PMOS**:
    - Conduzione con tensione bassa in ingresso.
    - Sorgente collegata all'alimentazione.

---
###### Realizzazione di porte logiche con transistor

1. **NOT**:
    - Un singolo NMOS inverte il segnale.
    - Es.: ingresso = 1 → uscita = 0. 
      ![[Pasted image 20241229105432.png]]
2. **NOR**:
    - Due NMOS in parallelo.
    - Es.: uscita = 1 solo se entrambi gli ingressi = 0. 
      ![[Pasted image 20241229105450.png]]
3. **NAND**:
    - Due NMOS in serie.
    - Es.: uscita = 0 solo se entrambi gli ingressi = 1. 
      ![[Pasted image 20241229105507.png]]

---
###### Tecnologia CMOS
- Combina NMOS e PMOS per migliorare efficienza e ridurre i consumi.
- Consumo di potenza solo durante la commutazione.
- Permette l'integrazione di miliardi di transistor su un chip.
- Offre alte frequenze di commutazione (nell'ordine dei GHz).
- Esempi:
    - **NOT CMOS**:
        - Un NMOS e un PMOS in serie. ![[Pasted image 20241229105336.png]]
    - **NAND CMOS**:
        - Due NMOS in serie e due PMOS in parallelo. ![[Pasted image 20241229105325.png]]
    - **NOR CMOS**:
        - Due NMOS in parallelo e due PMOS in serie. ![[Pasted image 20241229105400.png]]

---
###### Concetti avanzati nei circuiti logici
- **Ritardi nei circuiti**:
    - **Tempo di transizione**: Cambio di stato del segnale.
    - **Ritardo di propagazione**: Tempo necessario per aggiornare l'uscita.
    - **Percorso critico**: Determina la frequenza massima di lavoro.
- **Fan-in e Fan-out**:
    - **Fan-in**: Numero massimo di ingressi per una porta logica.
    - **Fan-out**: Numero massimo di uscite che una porta può pilotare.
    - Collegare più uscite a uno stesso ingresso può causare cortocircuiti o interferenze.

---
###### Circuiti integrati
- I circuiti integrati sono dispositivi in silicio che combinano componenti elettronici.
- Tipi di circuiti integrati:
    - **SSI**: Poche porte logiche.
    - **MSI**: Moduli funzionali (es. addizionatori).
    - **LSI**: Piccoli processori come la ALU.
    - **VLSI**: Processori potenti e memorie avanzate.
- Circuiti integrati possono essere:
    - **Analogici**: Elaborano segnali continui.
    - **Digitali**: Elaborano segnali discreti.
    - **Mixed**: Combinano analogico e digitale.

---
###### Porta tri-state
Questo tipo di porta può assumere 3 stati:
- Acceso
- Spento 
- Alta impendenza
Quando la porta si trova in alta impedenza è come se fosse disconnessa, questa porta viene usata molto nei bus per permettere a più componenti di usare lo stesso bus ma senza influenzarsi tra di loro. [[08_Struttura-base-del-processore#^487a6e|Spiegazione correlata al bus]]

---
###### Decoder e Multiplexer
- **Decoder**: Converte un codice binario con $n$ ingressi in $2^n$ uscite. In pratica prende in input un segnale e lo decodifica in segnali di uscita leggibili anche da altre componenti.
  ![[Pasted image 20241229105243.png]]
- **Multiplexer**: è un circuito digitale che seleziona uno tra i diversi ingressi e lo invia in uscita, basandosi sui segnali di controllo che gli arrivano, ciò permette a più fonti di condividere la stessa linea di connessione.
  ![[Pasted image 20241229105220.png]]