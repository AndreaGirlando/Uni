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
[[03_Parte3TeoriaSuperflua|La spiegazione teorica dell'immagine che vedi sotto]] la parte teorica qui è abbastanza inutile.
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