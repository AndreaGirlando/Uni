Questo file è la rielaborazione delle slide [[03_Parte3.pdf]]
 
# `Calcolo combinatorio`
Una delle cose più importanti che un informatico deve imparare a fare è **contare** o **calcolare** nel modo giusto, in particolare vogliamo essere in grado di contare il numero di oggetti o casi che ci interessano, senza doverli esplicitare uno per uno. Di seguito delle domande di esempio alla quale risponderemo dopo aver introdotto il calcolo combinatorio:
- **Domanda 1:** Se sto scrivendo un programma che simula il poker, il mio programma deve fare in modo che la probabilità di un poker d'assi servito sia quella giusta. Ma qual è tale probabilità?
- **Domanda 2:** Quanti sono i codici PIN di una carta bancomat a 5 cifre e quante sono le probabilità che un ladro riesca ad indovinare entro 3 tentativi? [[#^fec4ef|Risposta 2]]
- **Domanda 3:** Quante sono le possibili password fatte di 8 simboli alfa-numerici (maiuscole e minuscole sono diverse) e quanto tempo ci mette un programma che genera 1000 password al secondo a trovare quella giusta? [[#^a39c5a|Risposta 3]]
- **Domanda 4:** Se dovessi scommettere che in un’aula con 20 persone, ce ne siano almeno 2 che fanno il compleanno lo stesso giorno, scommetterei di si oppure no? E se ce ne sono 30, 40, 50 o più di persone?
- **Domanda 5:** Quante squadre di calcio diverse posso formare da un gruppo di 50 studenti?
---
##### Regola della somma
Questa regola ci dice che se vogliamo contare il numero di elementi dell'unione tra due insiemi ci basta sommare la cardinalità dei due insiemi.
- Se denotiamo con $A$ tutte le lettere dell'alfabeto minuscole e con $B$ tutte le lettere dell'alfabeto maiuscole allora il numero di elementi di $A ∪ B$ sarà uguale a $|A|+|B|$ e quindi $26+26 = 52$  
##### Regola del prodotto
Questa regola ci dice che se vogliamo contare quanti sono le possibili coppie di elementi, il primo scelto da $A$ e il secondo da $B$ ci basta fare $|A|*|B|$.
- Se denotiamo con $A$ tutte le lettere dell'alfabeto minuscole e con $B$ tutte le lettere dell'alfabeto maiuscole allora il numero di coppie possibili sono $26 *26 = 676$  
Più in generale se dobbiamo fare $k$ operazioni di scelta, tali che la prima si può fare in $n_1$ modi, la seconda in $n_2$ modi indipendenti dalla scelta precedenti, la i-esima in $n_i$ modi e quindi la k-esima in $n_k$ modi diversi allora il numero di scelte totali è
- $n_1*n_2*\dots*n_k$ 
  
Avendo le definizioni di queste 2 regole possiamo rispondere parzialmente alle domande 2,3:
- **Risposta 2**: i codici PIN di una carta bancomat a 5 cifre sono: ^fec4ef
	- $10*10*10*10*10 = 10^5 = 100000$
- **Risposta 3**: Le lettere dell'alfabeto sono $26$ i numeri sono $10$ quindi le cifre alfanumeriche prese in esame sono: ^a39c5a
	- $|A|+|B| = 26 + 10 = 36$
	- le password fatte da 8 simboli alfanumerici quindi sono sono:
		- $36*36*36*36*36*36*36*36 = 36^8 = 2.821.109.907.456$
	- Un computer che genera 1000 password al secondo ci metterà circa 2,8 miliardi di secondi a generarle tutte
---
##### Disposizioni e combinazioni
[[03_Parte3Teoria|La spiegazione teorica dell'immagine che vedi sotto]] la parte teorica qui è abbastanza inutile.
![[Pasted image 20241214162649.png]]
- Se nell'esercizio che sto facendo l'ordine degli elementi è importante guardo le colonne dove "Ordine?" è SI.
- Se nell'esercizio che sto facendo gli elementi posso essere riinseriti guardo le colonne dove "Reinserimento" è NO.
**Esercizio 1**: Domino
![[Pasted image 20241214170145.png]]
**Esercizio 2**: gruppi di persone
![[Pasted image 20241214170224.png]]
**Esercizio 3**: parola di 4 lettere
![[Pasted image 20241214170259.png]]
**Esercizio 4**: Gelato per tutti
![[Pasted image 20241214170322.png]]
##### Teorema binomiale
Il teorema binomiale è una formula che consente di elevare a qualsiasi numero un binomio così:
![[Pasted image 20241214164028.png]]
Ovvero la sommatoria da $k=0$ fino a $n$ (l’esponente del binomio) della moltiplicazione tra $a^{n-k} * b^k$ 
##### Pigeonhole principle
Nella sua forma più semplice, il Principio afferma che se dobbiamo fare entrare $n + 1$ piccioni in una piccionaia che contiene $n$ cassette, allora almeno una cassetta dovrà contenere più di un piccione. Più in generale, se abbiamo $n = km + 1$ oggetti da sistemare in m contenitori, allora almeno un contenitore dovrà contenere $k + 1$ oggetti.
- se in un cassetto abbiamo solamente calzini bianchi e neri, se peschiamo casualmente 3 volte un calzino, potremo sicuramente formare una coppia abbinata.


# `Probabilità discrete`

##### Introduzione e formalizzazione matematica
Lo studio della probabilità nasce tra la fine del 16esimo e gli inizi del 17esimo secolo, da problemi legati al gioco d'azzardo. 
- Le probabilità sono definite su uno **spazio di campioni** $S$. 
- Gli elementi di $S$ sono detti **eventi elementari**. 
- Ogni evento elementare è un sottoinsieme dello spazio dei campioni, inoltre ogni evento è sconnesso dagli altri.
- $S$ è l'evento certo mentre l'insieme nullo è l'evento nullo.
Per il lancio di due monete (costituite da testa e croce) lo spazio dei campioni è costituito da tutte le coppie che possono uscire ($2^2$), ovvero $\{TT,TC,CC,CT\}$, l’evento “si ottiene una testa e una croce” è composto dal sottoinsieme $\{TC, CT\}$ quindi 2/4 → ½ di probabilità. Da qui traiamo la definizione classica ed intuitiva della probabilità di verificarsi di un evento $A$ ovvero il rapporto tra i casi favorevoli $f_A$ ed il numero di casi totali $n$ la formalizzazione matematica sarebbe: 
 
> [!TIP] Formula generale per la probabilità
> $P(A) = \frac{f_A}{n}$
> con la notazione $P(A)$ si intende la probabilità che l'evento $A$ accada

- Prendendo in esame l'esperimento del lancio del dado e l’evento **"Esce un numero inferiore a 3"** lo spazio dei campioni è costituito da tutte i possibili esiti del lancio, ovvero $S = \{1, 2, 3, 4, 5, 6\}$ e gli esiti favorevoli sono solo $2$ ovvero $\{1, 2\}$. Quindi la probabilità di tale evento è $\frac{2}{6}$ .

##### Definizione frequentista
La definizione classica non considerava la possibilità di eventi non equiprobabili (come un dato truccato ad esempio), fu Richard von Mises a definire la probabilità che accada un evento $A$ come il limite del rapporto tra il numero di volte in cui si è verificato l'esito $f_A$ (l'esito favorevole) e il numero degli esperimenti $n$ ovvero:

> [!TIP] Formula frequentista per la probabilità
> $P(A) = \lim_{n \to \infty} \frac{f_A}{n}$

La definizione frequentista ha un problema di fondo insuperabile: non tutti gli esperimenti sono ripetibili e quindi alcune probabilità non sarebbero calcolabili. Da qui nasce la teoria della probabilità

##### Teoria della probabilità
Siano $A$ e $B$ due eventi qualsiasi definiti su uno spazio dei campioni $S$. Di seguito gli assiomi della probabilità:

> [!TIP] Assiomi della probabilità
> 1. $0 \le P(A) \le 1$ 
> 2. $P(S) = 1$ e $P(∅) = 0$ 
> 3. $P(A∪B)=P(A)+P(B) - P(A ∩ B)$ 
> 

Il terzo assioma afferma che la probabilità che si verifichi o $A$ o $B$ è uguale alla probabilità di $A$ più la probabilità di $B$ meno la probabilità che si verifichino entrambe. Usando il formalismo logico questo assioma può essere riscritto così: $P(A ∨ B) = P(A) + P(B) − P(A ∧ B)$

La distribuzione di probabilità è detta **uniforme** se tutti gli eventi sono equiprobabili

##### Probabilità condizionata e indipendenza
Il verificarsi di alcuni eventi può cambiare le probabilità che si verifichi un altro evento. La probabilità di un evento A, condizionata al verificarsi di un evento B (non nullo) è definita come:
> [!TIP] Probabilità di A, dato B già verificato
> $P(A|B) = \frac{P(A \cap B)}{P(B)}$

Definendo questa cosa capiamo che due eventi si dicono indipendenti se:
- $P(A|B) = P(A)$
- $P(B|A) = P(B)$
Da questa definizione possiamo ricavarci la formula per calcolare la probabilità che $A$ e $B$ accadano in questo modo:
![[Pasted image 20241215160352.png]]

> [!TIP] Probabilità che sia l'evento $A$ che l'evento $B$ accadano
> $P(A ∧ B) = P(A)*P(B)$

É importante anche ricordare il concetto di **indipendenza** degli eventi, ovvero molti eventi anche se sembrano correlati sono completamente indipendenti

> [!EXAMPLE] Esempio di indipendenza
> **Domanda**: Lanciamo un dado 3 volte. La probabilità della sequenza $[2, 1, 6]$ è più alta della probabilità della sequenza $[3, 3, 3]$?
> **Risposta**: No, le due probabilità sono uguali. 
> Infatti $P([2,1,6])$ = $P([3,3,3]) = \frac{1}{6}*\frac{1}{6}*\frac{1}{6} = \frac{1}{216}$
 

