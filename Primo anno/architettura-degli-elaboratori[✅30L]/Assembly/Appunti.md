![[Pasted image 20241229113429.png]]
##### Somma di una lista di numeri
```
list dcd 2,3,4,1
mov r1,#numa
ldr r2,[r1]
ldr r3,[r1,#4]
ldr r4,[r1,#8]
ldr r5,[r1,#12]
```
con list **dcd 2,3,4,5** sto dichiarando in memoria una lista di numeri la keyword list (oppure un nome scelto a caso messo prima di dcd) punta al primo elemento della lista. Quello che faccio nelle istruzioni dopo è caricare tutti gli elementi della lista dentro i registri, questo lo faccio usando l'indirizzamento con indice e spiazzamento:
- Il primo elemento si trova nell'indirizzo puntato da R1
- Il secondo elemento si trova nell'indirizzo puntato da R1+4 (4 sono i byte che contengono un numero)
- ecc..
```
numa dcd 2
numb dcd 3
numc dcd 4
numd dcd 1

mov r1,#numa
ldr r1,[r1]

mov r2,#numb
ldr r2,[r2]

mov r3,#numc
ldr r3,[r3]

mov r4,#numd
ldr r4,[r4]
```
Avrei potuto fare la stessa cosa in questo modo, ma il codice scritto prima è più pulito.

---

##### Ciclo
```
lista dcd 1,2,3,4
dim dcd 4
risultato fill 4

mov r1,#dim
ldr r1,[r1] ; Inizzializzo l'indice del ciclo
mov r2,#lista
mov r4,#0

ciclo
	ldr r3,[r2]; Carico il valore puntanto da r2 in r3
	subs r1,r1,#1; indice ciclo - 1 e setto i bit di controllo
	add r4,r4,r3; somma parziale
	add r2,r2,#4; faccio puntare r2 all'elemento successivo
	bgt ciclo; controllo se il risultato del subs è > 0

mov r7,#risultato
str r4,[r7]; salvo il risultato in memoria

```
Inizialmente r1 vale 4, ad ogni ciclo  lo riduco di uno e setto i bit di controllo, in questo modo quando arrivo all'istruzione bgt, salto solo se il risultato della sottrazione non da un numero negativo, quindi salterò 4 volte 