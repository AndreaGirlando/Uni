# 1.Sistemi di numerazione
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
