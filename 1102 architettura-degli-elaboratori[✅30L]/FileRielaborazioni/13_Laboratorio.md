# 1. Sistemi di numerazione
Per contare noi usiamo un sistema posizionale in base 10, invece i nostri dispositivi elettronici usano un sistema posizionale in base 2. 

---
###### Conversione da decimale a binario
- Sia $N$ il numero (in base 10) da convertire e in questo caso $B = 2$
- Si calcola la divisione intera $N = N / B$ e si mette da parte il resto $R$ della divisione
- Se $N > 0$ si va al passo $2$
- Se $N = 0$ si riportano i vari RESTI da destra verso sinistra: essi rappresentano il numero convertito in base B.
  ![[Pasted image 20250118143404.png|500]]
Lo stesso sistema può essere utilizzato per convertire un numero in base ottale(B=8) e anche esadecimale (B=16).

---
###### Numeri binari
I concetti on/off alla base dei nostri dispositivi possono essere rappresentati tramite i numeri binari:
 - OFF = 0
 - ON  = 1
in generale un numero viene rappresentato tramite una stringa di bit, questi numeri binari possono essere rappresentati tramite 3 tecniche principali:
1. **Segno e valore assoluto**: si commuta il bit di segno da 0 a 1, mentre gli altri bit restano invariati.
2. **Complemento a uno**: si commuta qualsiasi bit da 0 a 1 e da 1 a 0
3. **Complemento a due**: si aggiunge 1 al complemento a uno
Queste 3 tecniche hanno in comune che il bit più a sinistra rappresenta il segno del numero:
- 0 se il numero è positivo
- 1 se il numero è negativo
---
###### Addizione e sottrazione di numeri in complemento a 2
**Addizione**: si applica il solito algoritmo di addizione
**Sottrazione**: si fa il complemento a 2 dei numeri che hanno il meno davanti e poi si calcola l'addizione algebrica
![[Pasted image 20250118144836.png]]

---
###### Estensione e riduzione
Accade spesso che i numeri vadano ridotti o estesi per adattarli a delle locazioni di memoria specifiche, per fare ciò seguiamo le seguenti regole:
- **Estendere**:
	- Se $n>0$ aggiungiamo altri 0 a sinistra
	- Se $n < 0$ aggiungiamo altri 1 bit a sinistra
- **Ridurre**:
	- Se $n>0$ togliere bit 0 da sinistra (smettere prima che emerge 1)
	- Se $n<0$ togliere bit 1 da sinistra (smettere prima che emerge 1)
![[Pasted image 20250118145253.png]]
---
###### Overflow
Il risultato di addizione e sottrazione in complemento a due è corretto se è COMPRESO nell’intervallo $[-2^{n-1}, 2^{n-1}]$ in caso contrario si ha Overflow. Il trabocco si verifica se e solo se i due addendi hanno lo stesso segno, ma il bit di segno della somma risulta diverso dal bit di segno degli addendi. Esempio: +7+4 con n = 4 si ottiene 1011 (-5)

---
###### Numeri in virgola mobile
Un numero in virgola mobile può essere rappresentato usando: 
- Un **segno** $s$
- La **mantissa** $m$ 
- Un **esponente** $e$ con segno in base 2
In base allo standard utilizzato abbiamo un numero di bit usati:
![[Pasted image 20250118150511.png]]
per rappresentare i numeri in questo modo faccio così:
![[Screenshot_20250118_150816_Samsung capture.jpg]]

---
###### Codice ASCII 
Per rappresentare le lettere, i numeri e i simboli in generela viene utilizzato un alfabeto definito su 7 bit chiamato alfabeto ascii
![[asciitable.gif]]

---
# 2. Istruzioni macchina
| **Istruzione** | **Sintassi**        | **Descrizione**                                                                                                                                       |
|-----------------|---------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Load**        | `R2, LOC`          | Legge i contenuti di una locazione di memoria il cui indirizzo è rappresentato simbolicamente dall’etichetta LOC e carica i contenuti nel registro R2. I contenuti originali della locazione LOC sono preservati mentre quelli del registro R2 sono sovrascritti. |
| **Add**         | `R4, R2, R3`       | Somma i contenuti dei registri R2 e R3 e inserisce la loro somma nel registro R4. Gli operandi in R2 e R3 non sono alterati, ma il precedente valore in R4 è sovrascritto dalla somma. |
| **Store**       | `R4, LOC`          | Copia l’operando del registro R4 nella locazione di memoria LOC. I contenuti originali della locazione LOC sono sovrascritti mentre quelli del registro R4 sono preservati. |
| **Move**        | `R4, R3`           | Carica il contenuto del registro R3 in R4.                                                                                                            |
| **Subtract**    | `R4, R2, R3`       | Sottrae i contenuti dei registri R2 e R3 e inserisce il risultato nel registro R4.                                                                     |

---
###### Modi di indirizzamento
- **Modo di registro**: L’operando o il risultato è contenuto in un registro di processore, il cui nome (che è indirizzo) è dato nell’istruzione. `ES: ADD R4,R2,R3`
- **Modo assoluto**: L’operando o il risultato è contenuto in una parola di memoria il cui indirizzo è dato nell’istruzione. `ES: LOAD R2,NUM1`
- **Modo immediato**: L’operando è dato esplicitamente nell’istruzione. `ES: R4,R6,#200`
- **Modo indiretto**: Il nome di un registro di processore contenente l’INDIRIZZO di memoria dell’operando o del risultato è dato nell’istruzione. `ES: Load R2, (R5)` Il registro R5 agisce come puntatore
- **Modo con indice e spiazzamento**: L’indirizzo effettivo di operando o risultato e ottenuto addizionando un valore costante (spiazzamento) al contenuto di un registro (indirizzo). `ES: LOAD R2,20(R5)`

---
###### Istruzioni da usare su visual
| Istruzione                     | Descrizione                                                                                      |
| ------------------------------ | ------------------------------------------------------------------------------------------------ |
| `LDR Ri, [Rj]`                 | Carica nel registro Ri il **contenuto della parola** di memoria puntata da Rj.                   |
| `ADD Rd, Ri, Rj`               | Somma il contenuto di Ri e Rj e lo carica nel registro Rd.                                       |
| `SUB Rd, Ri, Rj`               | Sottrae il contenuto di Rj da Ri e lo carica nel registro Rd.                                    |
| `STR Ri, [Rj]`                 | Salva nella parola di memoria puntata da Rj il contenuto di Ri.                                  |
| `MOV Ri, Rj / MOV Ri, #Valore` | Carica nel registro Ri il contenuto di Rj o il valore immediato.                                 |

---
###### Direttive di assemblatore
Le direttive di assemblatore servono per dare informazioni utili all'assemblatore.
- **EQU**: associa il valore numerico nome (in visual: EQU)
- **ORIGIN**: indica l'indirizzo di partenza dove inserire le istruzioni
- **RESERVE**: indica all'assemblatore di riservare uno spazio di memoria espresso in byte (in visual: FILL)
- **DATAWORD**: Inizializza una word di memoria con il contenuto passato (in visual: DCD)
- **END**:  indica all'assemblatore la fine del testo del programma sorgente (in visual: END)

---
###### Bit di esito
Il processore tiene traccia di alcune informazioni ausiliarie relative all’esito di svariate operazioni, che servono come condizioni per l’istruzione di salto. Tale informazioni sono espressi sotto forma di insiemi di bit detti bit di esito.
![[Pasted image 20250118153228.png]]
Le istruzioni sottostanti aggiornano i bit di stato

| Istruzione       | Descrizione                                                                                  |
|------------------|----------------------------------------------------------------------------------------------|
| `ADDS Rd, Ri, Rj` | Somma il contenuto di Ri e Rj e lo carica nel registro Rd (**aggiorna i bit di stato NZCV**). |
| `SUBS Rd, Ri, Rj` | Sottrae il contenuto di Rj da Ri e lo carica nel registro Rd (**aggiorna i bit di stato NZCV**). |
| `CMP Ri, Rj`      | Sottrae Rj da Ri e aggiorna i bit di stato. **Il risultato viene scartato**.                   |
| `CMN Ri, Rj`      | Somma Ri e Rj e aggiorna i bit di stato. **Il risultato viene scartato**.                      |


---
###### Istruzione di salto condizionato
`Branch_if_ condizione destinazione_salto`
nel caso la **condizione** sia vera il programma salta alla **destinazione_salto** espressa come locazione di memoria contenente l'istruzione da eseguire nel caso la condizione sia vera.
![[Pasted image 20250118154119.png]]
Le lettere usate sono le lettere dei corrispondenti bit di esito.

---
# 3. Algebra Booleana

###### Operatori logici
L'algebra booleana è un sistema algebrico in cui ogni variabile può assumere solo 2 valori ($0$ e $1$) le principali operazioni definite sono:
- **OR**: che si denota con "+" o "V" ed è una funzione che vale 1 se almeno uno dei suoi ingressi è 1
- **AND**: che si denota con "$*$" o "˄" ed è un funzione che vale 1 se entrambi i suoi ingressi valgono 1
- **NOT**: che si denota con  "ˉ" o "¬" ed è una funzione che inverte il valore del suo ingresso
- **XOR**: che si denota con "$\oplus$" è una funzione che vale 1 solo se il numero di uno nei suoi ingressi è dispari
 ![[Pasted image 20250119094414.png]]
 Abbiamo anche altre proprietà importanti che riguardano questi operatori logici:
 ![[Pasted image 20250119094741.png]]
 Ricordiamo anche il teorema di De Morgan che ci dice:
 - $¬(x+y) = ¬x * ¬y$
 - $¬(x*y) = ¬x+¬y$

---
###### Prima forma canonica (somma di prodotti)
Si crea la tabella di verità di un'espressione logica e poi si seguono i seguenti step:
1. Si individuano i casi in cui il risultato è pari a **1**
2. Per ogni caso si costruisce un prodotto delle $n$ variabili, ogni variabile è
	- se uguale a 1 la scriviamo direttamente
	- se uguale a 0 la scriviamo negata
3. Si sommano tra loro i prodotti ottenuti
![[Pasted image 20250119095719.png]]
###### Seconda forma canonica (prodotto di somme)
Si crea la tabella di verità di un'espressione logica e poi si seguono i seguenti step:
1. Si individuano tutti i casi in cui il risultato è pari a **0**
2. Per ogni caso, si costruisce una somma delle $n$ variabili, ogni variabile è:
	- se uguale a 0 la scriviamo direttamente
	- se uguale a 1 la scriviamo negata
3. Moltiplichiamo le somme ottenute.
![[Pasted image 20250119100003.png]]
---
###### Forma minima
Due espressioni logiche si dicono equivalenti se hanno la medesima tabella di verità, un'espressione di dice in **forma minima** quando non esiste un'altra espressione equivalente ma di costo inferiore, il costo di un'espressione si calcola contando il numero di volte in cui le variabili compaiono, per noi è molto importante ridurre un'espressione perché un'espressione minima produrrà un circuito logico più semplice.
 
> [!EXAMPLE] Esempio
> $(x_1 + x_2) · (x_1 + x_2) · (x_1 + x_2) \rightarrow$ costo 6
> $x_1 · x_2 \rightarrow$ costo 2

Di seguito un'esempio di minimizzazione
![[Pasted image 20250119103529.png]]

---
###### Mappe di Karnaugh
Le mappe di Karnaugh sono un metodo di tipo geometrico che permettono di ricavare l'espressione logica di costo minimo data una funzione
![[Pasted image 20250119104103.png]]
**Come si usano:**
1. Trasformare la tavola di verità in una mappa di Karnaugh
2. Raggruppare le caselle di valore 1 adiacenti orizzontalmente o verticalmente
3. Ogni gruppo rappresenta il prodotto delle sue variabili con lo stesso valore (forma diretta se 1 e negata se 0). Identificare quali variabili non contribuiscono ed eliminarle nella forma analitica.
4. Somma dei gruppi creati
![[Pasted image 20250123081550.png]]

**Condizione di indifferenza**: spesso accade che una funzione logica non sia definita su tutte le combinazioni di valori delle sue variabili, nella tabella di verità sono indicate con il simbolo "X" e quindi anche nella mappa di karnaugh corrispondente avranno un x, il loro valore va scelto in modo arbitrario cercando di creare una semplificazione a costo minimo.

---
###### Circuiti logici
Le operazioni logiche possono essere realizzate da semplici circuiti elettronici chiamati porte. Collegando varie porte tra di loro si possono rappresentare le espressioni logiche. Questi sono i simboli principali.
![[Pasted image 20250119104802.png|500]]
Altre porte molto importanti sono le porte NAND e NOR, si denota tramite gli operatori a due argomenti "↑" o "↓" rispettivamente
![[Pasted image 20250119105002.png|500]]
![[Pasted image 20250119105336.png]]
Queste 2 porte godono della proprietà commutativa ma non di quella associativa e appunto per questo non si possono creare degli alberi di porte. Grazie alle leggi di De Morgan e alla legge di involuzione possiamo passare da una SOP ad una rete di NAND

# 4. La pila
La pila consiste in una lista di elementi alla quale però si può lavorare solo agendo sulla cima della pila. É possibile eseguire solo 2 operazioni:
- **PUSH**:  aggiungiamo un elemento in cima
```
Subtract SP, SP,#4 ;diminuire l’indirizzo contenuto in SP di una parola per puntare alla nuova cima
Store Rj, (SP) ; scrivere il valore richiesto nella parola puntata da SP
```
- **POP**: togliere un elemento dalla cima
```
Load Rj, (SP) ;copiare il valore contenuto nella locazione di memoria puntata da SP in un registro del processore 
Add SP, SP,#4 ;aumentare l’indirizzo contenuto in SP di una parola per puntare alla nuova cima
```

###### La pila in Visual
![[Pasted image 20250119110510.png]]
Questi 2 comandi vanno a salvare nella pila la lista dei registri che inseriamo, l'ordine con la quale vengono inseriti si basa sul codice passato, i codici disponibili sono:
![[Pasted image 20250119110724.png]]


> [!EXAMPLE] Esempio
> I valori nei nostri registri sono:
> - R0 = 18
> - R1 = 20
> - R2 = 22
> - R3 = 24
> - R4 = 26
> - R5 = 28
> Questo succede se uso STM con i vari codici:
> ![[Pasted image 20250119111130.png]]
> Questo succede se uso LDM:
> ![[Pasted image 20250119111224.png]]

---
###### Area di attivazione in pila
Il blocco di programma riservato ai sottoprogrammi è anche essa una pila ed è chiamato **Stack Frame**, il **Frame Pointer** è un registro che punta allo stack frame del sottoprogramma in esecuzione.

---
###### Gestione dei sottoprogrammi
Un sottoprogramma è una lista di istruzioni che eseguono un compito specifico e che possono essere richiamate in un qualsiasi punto del programma.
- **Chiamata a sottoprogramma**: viene fatta attraverso l'istruzione `call INDIRIZZO`, l'operazione di chiamata esegue 2 step:
	1. Salva il contenuto del registro PC nel Link Register;
	2. Salta all'indirizzo di destinazione indicato nell'istruzione di chiamata
- **Rientro da sottoprogramma**: viene fatta attraverso l'istruzione `RETURN`, quello che fa questa istruzione è salvare il contenuto del link register nel registro PC
In Visual facciamo così:
![[Pasted image 20250119112656.png]]
Il passaggio di parametri ai sottoprogrammi può essere fatto attraverso i registri o usando la pila.
![[Pasted image 20250119113125.png]]

# 5. Shifting e comandi vari
![[Pasted image 20250119113759.png]]
![[Pasted image 20250119113806.png]]
![[Pasted image 20250119113814.png]]

---
# 6. Circuiti integrati
###### Transistor
Nei circuiti elettronici, per rappresentare i valori 0 e 1 delle variabili binarie si usano i valori di tensione elettrica, si stabilisce una **tensione di soglia** dove tutti i valori di tensione rappresentano un 1 mentre quelli inferiori rappresentano uno 0, i valori vicini alla soglia sono ambigui e quindi per evitare incertezze nasce la **banda vietata** dove i valori non vengono presi in considerazione. 
![[Pasted image 20250123082311.png]]
I transistor sono delle componenti elettroniche che svolgono il compito di interruttori, in specifico i transistor MOS (transistore a metallo-ossido semiconduttore) sono quelli più utilizzati nei nostri dispositivi, questo tipo di transistor hanno 3 collegamenti: **Base**, **Pozzo** e **Sorgente**, a seconda della tensione in ingresso nella Base il transistore collegherà o meno la sorgente al pozzo, se il transistor sta conducendo allora la tensione in entrata è uguale alla tensione in uscita, esistono 2 tipi di transistor MOS:
- **NMOS**: 
	- il transistor è in conduzione (vale 1) se $V_b = V_{cc}$
	- il transistor è in interdizione (vale 0) se $V_b$ = 0
- **PMOS**: 
	- il transistor è in conduzione (vale 1) se $V_b = 0$ 
	- il transistor è in interdizione (vale 0) se $V_b$ = $V_{cc}$
Attraverso questi 2 transistor possiamo costruire le seguenti porte logiche: 
- **NOT**: si ottiene una porta NOT con un transistor NMOS collegando la sorgente alla massa e il pozzo all'alimentazione tramite una resistenza, per una tensione di ingresso di "1" in uscita avremo una tensione di "0" e viceversa.
- **NOR**: si ottiene collegando due transistor NMOS in parallelo, solo se entrambi i transistori sono in interdizione la tensione in uscita sarà uno altrimenti sarà sempre 0
- **NAND**: collegando due transistor NMOS in serie si ottiene una porta NAND
- **AND**: collegando in serie una NAND e NOT
- **OR**: collegando in serie una NOR e NOT

L'unico problema dei transistor NMOS è che consumano tanta corrente, cosi nascono i transistor CMOS che hanno un consumo di potenza ridotto e soprattutto dimensioni ridotte infatti da quando sono nati abbiamo componenti con miliardi di transistor all'interno

---
###### Definizioni nelle porte logiche
- il **tempo di transizione** in un circuito è il tempo impiegato da un segnale per transitare di livello
- il **ritardo di propagazione** è il tempo che ci mette il nostro circuito ad adattarsi ai nuovi valor in input
- la **frequenza di lavoro** è il numero di volte che esso commuta in un determinato tempo.
- **Fan-in** è il numero di ingressi di una porta logica
- **Fan-out** è il numero di uscite di una porta logica

> [!TIP] 
> Tipicamente il fan-in e fan-out si limita a meno di 10 per porta perché un numero più elevato inciderebbe sul ritardo di propagazione

---
###### Circuiti integrati
**Decodificatore**: un blocco funzionale in grado di decodificare un codice binario in ingresso
**Multiplatore**: un blocco funzionale dotato di molteplici ingressi di selezione e altrettanti ingressi dato e di una sola uscita, quello che fa questo blocco funzionale è selezionare uno degli ingressi dato basandosi sui segnalo che arrivano negli ingressi selezione e inviarlo in uscita

---
###### Reti sequenziali
Le reti che riescono a memorizzare informazioni sono chiamate **reti sequenziali**, queste reti logiche sono basati su dei cicli, una rete sequenziale in grado di memorizzare dei bit viene anche detta **bistabile** ne esistono di 3 tipi:
- **Bistabile asincrono**: Sono privi di un segnale di sincronismo e modificano il loro stato in seguito al cambiamento degli ingressi.
- **Bistabile sincrono**: Sono sensibili ad un segnale di controllo e i cambiamenti di stato avvengono solo in corrispondenza di un impulso del segnale di controllo
- **Bistabile di tipo D**: Memorizza un bit unificando gli ingressi S e R in un unico ingresso D. Quando il segnale di clock $CLK$ è alto ($CLK=1$), l’uscita segue il valore di D; quando è basso ($CLK=0$), lo stato rimane invariato.