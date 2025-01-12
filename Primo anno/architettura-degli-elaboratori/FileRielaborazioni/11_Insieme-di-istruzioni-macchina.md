Questo file è la rielaborazione delle slide [[11_Insieme-di-istruzioni-macchina.pdf]]

---

Come ricordiamo dai capitoli passati l'architettura di base di un calcolatore è formata da:
- **CPU**: esegue istruzioni
- **Memoria**: contiene il programma che la CPU deve eseguire
- **Interfacce di I\O**: circuiti che connettono la CPU al mondo esterno
- **Bus di sistema**: insieme di collegamenti elettrici che interconnettono i vari componenti
  
Il calcolatore esegue le **istruzioni** in modo **sequenziale**, le istruzioni definiscono le operazioni da eseguire e sono raggruppate in **programmi**, le varie operazioni hanno bisogno di **dati** che vengono immagazzinati nella memoria, l'utente interagisce con il programma attraverso le periferiche di input/output.

###### Ciclo macchina
I passi elementari per eseguire un'istruzione sono:
- **Prelievo:** viene prelevata la prossima istruzione da eseguire dalla memoria
- **Decodifica:** decodifica dell'istruzione
- **Esecuzione:** esecuzione dell'istruzione

---

##### ISA
Le istruzioni elementari che un processore è in grado di eseguire sono definite nell'ISA (Istruction Set Architecture), queste istruzioni elementari vengono definite attraverso un alfabeto binario. Il linguaggio assemblativo (**assembly**) è una rappresentazione simbolica del linguaggio macchina. Esistono 2 grandi famiglie di ISA:
- **CISC** (Complex Istruction Set Architecture): Basata su istruzioni complesse, che possono anche occupare più di una word di memoria.
- **RISC**(Reduced Istruction Set Architecture): Basata su istruzioni semplici, con le istruzioni che al massimo occupano una word, di solito sono molto efficienti grazie all'utilizzo della [[07_Pipelining|pipeline]]

---
##### Memoria
Il calcolatore lavora su gruppi di bit detti **Parole**(word), ogni parola nella nostra memoria è associata ad un indirizzo binario univoco, parole consecutive sono associate ad indirizzi consecutivi. Un numero binario con $m$ bit potrà indirizzare al massimo $2^m$ indirizzi. L'unità minima di informazione indirizzabile in memoria è il byte, di solito i dati vengono immagazzinati in 2 modi diversi:
- **Big-endian(Crescente)**: memorizzazione/trasmissione che inizia dal byte più significativo (estremità più grande) per finire col meno significativo
- **Little-endian(Decrescente)**: memorizzazione/trasmissione che inizia dal byte meno significativo (estremità più piccola) per finire col più significativo.
![[Pasted image 20241228143343.png|500]]

---

##### Programmare in assembly
Il programmatore scrive i programmi in **linguaggio assemblativo** (assembly), che vengono tradotti in linguaggio macchina dall'**assemblatore**. Il codice risultante in linguaggio macchina viene poi eseguito direttamente dal processore.

---
##### Registri e locazioni di memoria
All'interno del nostro processore abbiamo diverse locazioni di memoria usate per immagazzinare dati di lavoro usati dalla CPU durante l'esecuzione delle istruzioni. Di solito i registri generici del processore vanno da: R0 ad Rn, abbiamo anche dei registri speciali come il [[08_Struttura-base-del-processore#^969586|PC]] (Program Counter) e [[08_Struttura-base-del-processore#^8e6647|IR]] (Istruction Register)

---
##### Istruzioni di base in assembly:
```
LOAD destinazione sorgente
STORE sorgente destinazione
ADD destinazione sorgente1 sorgente2
SUB destinazione sorgente1 sorgente2
```
Queste istruzioni fanno:
- **LOAD**: carica un dato dalla memoria in un registro del processore
- **STORE**: carica un dato presente in un registro di un processore in memoria
- **ADD**: somma il contenuto di 2 registri
- **SUB**: sottrae il contenuto di 2 registri

Nel linguaggio assemblativo, gli operandi e il risultato delle istruzioni possono essere espressi in modi diversi, i metodi con cui specificare operandi e risultato vengono chiamati modi di indirizzamento, i modi di indirizzamento base sono:
- **Modo immediato**: specificando direttamente l'operando
	- Add R4, R6, #200
- **Modo di registro**: indicando il nome del registro del processore
	- Load R2, R5
- **Modo assoluto**: indicando l'indirizzo di una word in memoria
	- Load R2, $\#0x5D$ 
- **Indiretto da registro**: indicando un registro con all'interno l'indirizzo della word in memoria
	- Load R2,(R5)
	  ![[Pasted image 20241228145830.png]]
- **Con indice e spiazzamento**: L'indirizzo effettivo di un operando è ottenuto prendendo l'indirizzo come nel caso "**indiretto da registro**" e sommandogli una costante
	- LOAD R2,20(R5)
	   ![[Pasted image 20241228150052.png]]
- **Con base e indice**: l'indirizzo effettivo è ottenuto sommando il contenuto di 2 registri.

##### Istruzione condizionale:
```
Branch_if condizione destinazione salto. 
Branch_if_[R2]>0 CICLO
```
  Istruzione usata per saltare all’esecuzione di un’istruzione specifica nel caso la condizione di salto sia vera

---
##### Direttive di assemblatore
Per aiutare l'assemblatore nella traduzione del nostro programma in codice binario esistono **le direttive all'assemblatore**, queste non vengono tradotte in vero e proprio codice binario ma servono per dare delle informazioni utili all'assemblatore. Ne esistono di vario tipo:

```
NOME EQU valore_numerico
ORIGIN indirizzo_memoria
RESERVE spazio_in_byte
DATAWORD contenuto_da_assegnare
```
- **EQU**: associa il valore numerico nome
- **ORIGIN**: indica l'indirizzo di partenza dove inserire le istruzioni
- **RESERVE**: indica all'assemblatore di riservare uno spazio di memoria espresso in byte
- **DATAWORD**: Inizializza una word di memoria con il contenuto passato

---
##### Generiche istruzioni assembly:
Di solito le istruzioni di assembly seguono la seguente struttura:
![[Pasted image 20241228151727.png]]
Inoltre l'assemblatore ci permette di denotare i numeri in diversi formati:
- **Binaria:** %
	- Add R2, R3, #%01011101
- **Decimale:** *nessun prefisso*
	- Add R2, R3, #93
- **Esadecimale:** 0x
	- Add R2, R3, $\#0x5D$

---
##### Pila(Stack)
Per gestire gli aspetti fondamentali di un programma (le chiamate a funzione, allocazione dinamica, ecc...)assembly usa lo stack, questa è una struttura dati basata sul paradigma **LIFO** (Last In First Out), abbiamo un registro speciale del processore chiamato **SP**(Stack pointer) che punta alla cima della lista, in questa struttura dati si possono fare solo 2 operazioni:
- **PUSH**: aggiunge un elemento in cima alla pila, di solito si implementa così:
```
Load Rj, (SP);prendo il valore dalla cima e lo salvo in Rj
Add SP, SP, #4;aumento l'indirizzo cosi da spostarmi alla nuova cima
```
- **POP**: preleva un elemento dalla cima, di solito si implementa così:
```
Load Rj, (SP) 
Add SP, SP, #4
```

---
##### Funzioni
Una funzione anche detto sottoprogramma è una lista di istruzioni che eseguono un compito specifico e che possono essere richiamate in un qualsiasi momento durante l'esecuzione di un programma, la chiamata alla funzione viene fatta usando una funzione di salto detta **Call Istruction**, nella funzione invece per ritornare alla routine chiamate viene usata l'istruzione **Return Istruction**, l'indirizzo di rientro di una funzione viene salvato nel **Link Register**.
```
CALL Indirizzo
RETURN
```
- **CALL**: chiama la funzione specificata seguendo questi 2 passi:
	1. Salva il contenuto del registro **PC** nel **Link register**
	2. Salta all'indirizzo di destinazione indicato nell'istruzione di chiamata
- **RETURN**: salta all'indirizzo di rientro e lo fa salvando nel **PC** il contenuto del **Link register**

Per passare i parametri a queste funzioni ci sono 2 modi:
- **Tramite registri:** il numero di dati è limitato al numero di registri
- **Tramite lo stack**: il numero di dati è virtualmente illimitato

il blocco dello stack riservato ai sottoprogrammi si chiama **Stack Frame**, il **Frame Pointer** è il puntatore a questa area della memoria, dentro questa area dello stack troviamo molte informazioni come le variabili locali e i loro valori. Quando abbiamo delle chiamate a funzione annidate dobbiamo ricorda di salvare l'indirizzo del link register dentro la pila, in modo da sapere sempre dove ritornare. In alcune architetture questa cosa viene fatta in automatico. 

---
##### Codifica delle istruzioni

> [!Info] Codice operativo
> Il codice operativo o OpCode corrisponde alla procedura da mettere in esecuzione quando si deve eseguire un'istruzione 

Le istruzioni in assembly possono cambiare in base all'architettura del processore, nel caso di una CPU a 32 bit possono essere usate le seguenti codifiche:
- **Formato con operandi in registri**: In questo caso parliamo di istruzioni di questo tipo: ADD R1,R2,R3 dove: 
	- I 15 bit più significativi vengono usati per gli indirizzi dei 3 registri (5 bit cadauno) 
	- I restanti 17 bit per il codice operativo
  ![[Pasted image 20241228160117.png]]
- **Formato con operando immediato**: in questo caso parliamo di istruzioni di questo tipo: ADD R1,R2,#5 dove:
	- 10 bit vengono usati per gli indirizzi dei registri, 
	- 6 bit vengono usati per il codice operativo
	- 16 bit vengono usati per operando immediato
	![[Pasted image 20241228160405.png]]
- **Formato per chiamata**: in questo caso parliamo di istruzioni di questo tipo: CALL 0x00400010 dove:
	- 6 bit vengono usati per il codice operativo
	- 26 bit per rappresentare l'indirizzo della funzione da chiamare

---
##### Register Transfer Notation (RTN)
La notazione a trasferimento di registro serve a descrivere formalmente il trasferimento di informazioni tra memoria e registri. Il simbolo utilizzato è $\leftarrow$ :
- A sinistra troviamo un indirizzo di memoria
- A destra troviamo un valore semplice o un'espressione
![[Pasted image 20241228162118.png]]

---
##### Istruzioni logiche
```
AND destinazione,sorgente1,sorgente2
OR destinazione,sorgente1,sorgente2
```
- **AND**:  fa un and tra le sorgenti
- **OR**: fa un or tra le sorgenti

---
##### Scorrimenti e rotazioni
**Scorrimento logico**:
Le operazioni di scorrimento logico fanno scorrere i bit di un registro a destra o a sinistra di n posizioni, i bit in uscita vengono persi, ad eccezione dell’ultimo bit che viene memorizzato nel bit di riporto c
![[Pasted image 20241228163117.png]]
**Scorrimento aritmetico:**
Lo scorrimento aritmetico verso destra funziona come quello logico, ma riempie le posizioni lasciate libere con il valore del bit più significativo
![[Pasted image 20241228163228.png]]
**Rotazione**
La rotazione è un’operazione di scorrimento dove i bit in uscita da un lato vengono fatti rientrare dall’altro. L’ultimo bit in uscita viene scritto nel bit di riporto c.
![[Pasted image 20241228163318.png]]
**Rotazione con riporto**
Nella rotazione con riporto il bit di riporto viene incluso nella sequenza di bit da ruotare. Nel caso di rotazione a sinistra il bit di riporto viene aggiunto alla sinistra dei bit del registro da ruotare. Nel caso di rotazione a destra il bit di riporto viene aggiunto alla destra dei bit del registro da ruotare
![[Pasted image 20241228163511.png]]

---
##### Altre istruzioni dell'assembly
```
LoadByte Rdst, LOCBYTE
StoreByte Rsrc, LOCBYTE
Multiply Rk, Ri, Rj
Divide Rk, Ri, Rj
```
- **LoadByte**: legge un singolo byte dalla memoria e lo registra negli 8 bit meno significativi del registro destinazione mettendo a 0 gli altri bit
- **StoreByte**: salva gli 8 bit meno significativi del registro sorgente nella locazione di memoria specificata
- **Multiply**: effettua la moltiplicazione tra i due numeri contenuti nei registri
- **Divide**: effettua la divisione tra due numeri in complemento a due contenuti in due registri

---
##### Istruzioni esclusive delle architteture CISC
![[Pasted image 20241228164434.png]]

> [!DANGER]
> **Le istruzioni scritte di seguito sono istruzioni esclusive di un architettura CISC**

**Istruzioni aritmetiche**
Questo tipo di istruzioni hanno un formato a 2 indirizzi, dove l'indirizzo di destinazione servirà sia da ingresso che anche da risultato.
```
Operazione destinazione, sorgente
ADD B,A
```

**MOVE**
```
Move destinazione, sorgente
```
L'istruzione Move permette il trasferimento di dati tra registri ed indirizzi di memoria

**Indirizzamento per autoincremento**
Nell’indirizzamento per autoincremento, l’indirizzo dell’operando è contenuto in un registro il cui nome viene specificato nell’istruzione. Alla fine dell’istruzione il contenuto del registro viene incrementato di un’unità. Può essere usata per eseguire l’operazione di Pop:
```
Move ELEMENTO, (SP)+
```
**Indirizzamento per autodecremento**
Nell’indirizzamento per autoincremento, l’indirizzo dell’operando è contenuto in un registro il cui nome viene specificato nell’istruzione. Prima di eseguire l’istruzione, il contenuto del registro viene decrementato di un’unità. Può essere usata per eseguire l’operazione di Push:
```
Move -(SP), NUOVOELEMENTO
```

**Bit di esito**
sono bit speciali immagazzinati a in un registro interno al processore, e vengono usati per tenere traccia dell'esito di svariate operazioni. Quelli più comuni sono:
![[Pasted image 20241228165236.png]]

