Questo file è la rielaborazione delle slide [[01_Parte1.pdf]]

# `Logica proposizionale`

La **logica** è un linguaggio formale usato per rappresentare informazioni. Ogni linguaggio è formato da:
- **Sintassi**: che definisce le frasi del linguaggio
- **Semantica**: che definisce il significato delle frasi
La logica più semplice di tutti è la logica proposizionale oggi basata sulla matematica booleana, quest'ultima viene detta proposizionale perché si occupa di proposizioni, più precisamente di variabili proposizionali, quest'ultime possono assumere solo 2 valori: 
- 1 = VERO
- 0 = FALSO
Ogni variabile proposizionale è già da se una "formula" proposizionale, ovviamente questa è una formula molto basilare. Per creare delle formule più complesse usiamo dei connettivi logici che sono i seguenti:

- ==¬ (negazione)==: si legge "non", e inverte il valore di verità di una proposizione. Se una proposizione è vera, la sua negazione è falsa, e viceversa. Questo connettivo logico rappresenta la porta logica NOT
- ==∨ (disgiunzione logica)==: si legge "o", ed è vera se **almeno una** delle due proposizioni è vera. Questo connettivo logico rappresenta la porta logica OR
- ==∧ (congiunzione logica)==: si legge "e", ed è vera se **entrambe** le proposizioni sono vere.  Questo connettivo logico rappresenta la porta logica AND
- ==⇒ (implicazione)==: si legge "se... allora…" o semplicemente "implica". È falsa solo se il primo termine è vero e il secondo è falso.
- ==⇔ (doppia implicazione o coimplicazione)==: si legge "se … e solo se …". È vera quando entrambi i termini sono veri o entrambi falsi.

**Esempi di formule** (usando le variabili P e Q che sono scelte casualmente):
- ¬P = "Non P"
- Q  
- P ∨ Q  = "P o Q"
- P ∧ Q = "P e Q"
- P ⇒ Q = "se P allora Q"
- P ⇔ Q = P se e solo se Q

Come per le operazioni normali (somma, moltiplicazione, ecc...) anche queste hanno delle precedenze,  la negazione (¬) ha la precedenza su tutto mentre congiunzione (∨) e disgiunzione (∧) hanno la stessa priorità infatti:
- ¬p ∨ q è la formula dove la negazione si applica solo a p 
- ¬(p ∨ q) è la formula dove la negazione si applica alla disgiunzione p ∨ q

Date 2 formule $P_1$ e $P_2$ che ovviamente posso assumere solo una valore (questa cosa la impone una funzione chiamata **interpretazione** che appunto assegna a $P_1$ e $P_2$  i valori 1 o 0) Di seguito si calcola il valore di verità delle seguenti formule: 
- I(¬$P_1$) è vera solo se $P_1$ è falsa
- I($P_1$ ∨ $P_2$) è vera se almeno una tra $P_1$ o $P_2$ è vera
- I($P_1$ ∧ $P_2$) è vera se entrambe sono vere
- I($P_1$ ⇒ $P_2$) è falsa solo quando $P_1$ è vera e $P_2$ è falsa, nei restanti casi è vera
- I($P_1$ ⇔ $P_2$) è vera se e solo se $P_1$ == $P_2$
Questa è la tabella della verità di tutte queste formule:

| $P_1$ | $P_2$ | ¬$P_1$ | $P_1$ ∨ $P_2$ | $P_1$ ∧ $P_2$ | $P_1$ ⇒ $P_2$ | $P_1$ ⇔ $P_2$ |
| ----- | ----- | ------ | ------------- | ------------- | ------------- | ------------- |
| 1     | 1     | 0      | 1             | 1             | 1             | 1             |
| 1     | 0     | 0      | 1             | 0             | 0             | 0             |
| 0     | 1     | 1      | 1             | 0             | 1             | 0             |
| 0     | 0     | 1      | 0             | 0             | 1             | 1             |

--- 
##### Nomenclature varie:
- Data una formula diremo che è **==soddisfacibile**== se esiste almeno un caso in cui sia vera, qualunque siano i valori delle variabili.
- Data una formula diremo che è **==insoddisfacibile==** se non esiste almeno una caso in cui sia vera, qualunque siano i valori delle variabili.
- Data una formula si dice **==tautologia==** se è sempre vera qualunque siano i valori delle variabili.
---
Di seguito degli esempi (usando le variabili della tabella di verità):
- $P_1$ ∧ $P_2$ è soddisfacibile
- $P_2$ ∨ ¬$P_2$ è tautologia (Questo viene chiamato ==**Principio del terzo escluso**==)
- $P_2$ ∧ ¬$P_2$ è insoddisfacibile (Questo viene chiamato ==**Principio di non contraddizione**==)

Due formule $P_1$ e $P_2$ si dicono equivalenti se hanno lo stesso valore, questo concetto in simboli lo esprimiamo così:  $P_1$ $\equiv$ $P_2$

Per la disgiunzione e la congiunzione vale la proprietà commutativa e associativa 
- p ∨ q ≡ q ∨ p (commutativa della disgiunzione)
- p ∨ (q ∨ r ) ≡ (p ∨ q) ∨ r (associatività della disgiunzione)

##### Giustificazione o conseguenza logica:
Sia $P$ un insieme di proposizioni e $p$ una proposizione generica, ci chiediamo quando $P$ giustifica $p$ questa domanda la denotiamo con: $P$  |= $p$
Di seguito un esempio:
$P$ = { p, p => q }  
$P$  |= $q$
Questa è la tavola di verità dell'esempio
![[Pasted image 20241008151855.png]]
==N.B:== Per essere vero che $P$ giustifica $q$ tutte le formule di $P$ devono essere vere e anche $q$ deve essere vera. Questa cosa si capisce ancora meglio in questo esempio

$P$ = { p ∨ r, q ∨ ¬r }  
$P$  |= p ∨ q

![[Pasted image 20241008232946.png]]

Come possiamo facilmente notare P giustifica quella disgiunzione (ovvero p ∨ q) solo quando tutte le formule di $P$ e la disgiunzione tra $p$ e $q$ sono vere (attenzione ai vari casi nella tabella). 

**TIPS**: [[Tips#Come creare tutte le combinazioni tra le variabili senza confondersi]] 

--- 
##### Altre equivalenze logiche
- $¬(¬p) ≡ p$
- $p ⇔ q ≡ (p ⇒ q) ∧ (q ⇒ p)$ (eliminazione della doppia implicazione)
- $p ⇒ q ≡ ¬p ∨ q$ (eliminazione dell'implicazione)
- $p ∧ (q ∨ r ) ≡ (p ∧ q) ∨ (p ∧ r )$ distributività della congiunzione sulla disgiunzione
- $p ∨ (q ∧ r ) ≡ (p ∨ q) ∧ (p ∨ r )$ distributività della disgiunzione sulla congiunzione

**TIPS:** [[Tips#Come distribuire le congiunzioni sulle disgiunzioni e viceversa]]

---
Molte volte formule complesse vengono standardizzate in 2 forme chiamate "normali":
- CNF (Forma Normale Congiuntiva) che si basa sul fare un AND di vari OR:
	- (p ∨ q) ∧ (¬p ∨ ¬r ∨ s)
- DNF (Forma Normale Disgiuntiva) che si basa sul fare un OR di vari AND:
	- (p ∧ q) ∨ (¬p ∧ ¬r ∧ s)

Una qualunque formala P si può trasformare in una delle 2 forme normali, questo si fa seguendo questi step:
1. Elimina le coimplicazioni p ⇔ q dalla formula sostituendole con (p ⇒ q) ∧ (q ⇒ p)
2. Elimina le implicazioni p ⇒ q dalla formula sostituendole con ¬p ∨ q
3. Sposta le negazioni a ridosso delle variabili proposizionali ed elimina le doppie negazioni.
	- ¬(¬p ∨ ¬r ∨ s) diventa (p ∧ r ∧ ¬s)
4. Di questo step abbiamo 2 casi:
	1. Per costruire una CNF distribuiamo le congiunzioni sulle disgiunzioni, di seguito un'esempio:
		1. $(p ∧ q) ∨ (¬p ∧ ¬r ∧ s)$
		2. $(p ∨ ...) ∧ (q ∨ ...)$ Scrivo entrambe le variabili separate con l'operatore logico che trovo tra le parentesi
		3. $(p ∨ (¬p ∧ ¬r ∧ s)) ∧ (q ∨ (¬p ∧ ¬r ∧ s))$ Sostituisco le parentesi ai puntini
		4. $(p ∨ ¬p) ∧ (p ∨ ¬r ) ∧ (p ∨ s) ∧ (q ∨ ¬p) ∧ (q ∨ ¬r ) ∧ (q ∨ s)$ distribuisco p e q sulla parentesi $(¬p ∧ ¬r ∧ s)$ 
		5. $(p ∨ ¬r ) ∧ (p ∨ s) ∧ (q ∨ ¬p) ∧ (q ∨ ¬r ) ∧ (q ∨ s)$ elimino la formula $(p ∨ ¬p)$ perché sarebbe sempre falsa
	2. Per costruire una DNF distribuiamo le disgiunzioni sulle congiunzioni, di seguito un'esempio
		1. $(p ∨ q) ∧ (¬p ∨ ¬r )$
		2. $(p ∧ ...) ∨ (p ∧ ...) ∨ (q ∧ ...) ∨ (q ∧ ...)$ Prendo una variabile della prima parentesi, gli metto vicino l'operatore logico fuori dalla parentesi, faccio questa cosa una volta per ogni variabile della della seconda parentesi. Il segno che c'è tra le nuove parentesi e quello dentro la parentesi iniziale. 
		3. $(p ∧ ¬p) ∨ (p ∧ ¬r ) ∨ (q ∧ ¬p) ∨ (q ∧ ¬r )$ Sostituisco ogni variabile della seconda parentesi iniziale ai puntini
		4. $(p ∧ ¬r ) ∨ (q ∧ ¬p) ∨ (q ∧ ¬r )$ elimino la formula $(p ∨ ¬p)$ perché sarebbe sempre falsa

Esempio:
![[Pasted image 20241012123046.png]]

---
--- 
# `Insiemi fino a slide 64` 
Gli insiemi vengono considerati una collezione ben definita di oggetti. 
1. Per esprimere l'**appartenenza** ad un insieme usiamo la seguente espressione: 
	- x ∈ T (x è un elemento generico e T è un'insieme generico)
2. Per esprimere la **non appartenenza** ad un'insieme usiamo la seguente espressione:
	- $x \notin T$
Dato che un'insieme è univocamente caratterizzato dal suo contenuto, 2 insiemi si dicono uguali se hanno gli stessi elementi, in simboli sarebbe:
- A = B ⇔ (∀x)(x ∈ A ⇔ x ∈ B) ==(A è uguale a B se e solo se qualsiasi x che appartiene ad A appartiene anche a B)==
	- A = {1, 2, 3} e B = {2, 3, 1, 2, 3} sono uguali perché contengono gli stessi elementi.
---
Per specificare un'insieme è sufficiente elencarne gli elementi, in questo modo:
- T = {1,2,3} ==(T è un'insieme contente i numeri 1,2,3)==
Più in generale possiamo specificare un'insieme esprimendo la proprietà che caratterizza i suoi elementi. Supponiamo che $P$ sia la proprietà di essere un divisore di 100 allora ${x: P(x)}$ (con questa nomenclatura indichiamo un'insieme di tutti gli elementi che rendono vera la proprietà $P$) è un insieme. Per poter esprimere un'insieme sotto questa forma la proprietà $P$ deve essere ben definita ovvero che per ogni valore di $x$, $P(x)$ può assumere solo 2 valori vero o falso, di seguito un esempio di non insieme: 
- Supponiamo $P$ sia la proprietà di essere "alti", allora ${x : P(x)}$ non è un insieme.
In questo caso parliamo di un non-insieme perché la proprietà di essere alti non è una proprietà ben definita in termini matematici infatti è una nozione che può variare in base al contesto.
--- 
Si dice **Cardinalità** il numero di elementi che costituisce un'insieme e si denota con il simbolo: $|A|$ questo potrebbe assumere anche il valore di $\infty$, ad esempio l'insieme dei numeri pari ha una cardinalità uguale ad $\infty$.

---
Nomenclature: 
- Per indicare un'insieme costituito da un solo elemento usiamola parola *singoletto*
- invece per indicare un'insieme vuoto usiamo il seguente simbolo: 
	- ∅ (la cardinalità del seguente insieme è uguale a 0)

---
Se abbiamo 2 insiemi A e B, e tutti gli elementi di A appartengono a B, diciamo che A è un ***sottoinsieme*** di B e lo denotiamo così:
- A ⊆ B ⇔ (∀x)(x ∈ A ⇒ x ∈ B) ==(A è un sottoinsieme di B se e solo se qualunque x che appartiene ad A, appartiene anche a B)==
facendo rifermento allo stesso caso potremmo dire che B è un ***sovrainsieme*** e lo denotiamo così:
- B ⊇ A ⇔ (∀x)(x ∈ A ⇒ x ∈ B) ==(A è un sovrainsieme di B se e solo se qualunque x che appartiene ad A, appartiene anche a B)==

<mark class="hltr-purple">Nota bene</mark> tra le due espressioni scritte qua sopra cambia la direzione del segno

Le relazioni A ⊆ B è verificata anche nel caso A = B, se volessimo esprimere il A ⊆ B ma specificando che A è diverso da B (quindi che in B ci sono elementi che in A non ci sono) scriviamo in questo modo A ⊂ B, in questo caso diciamo che A è un ***sottoinsieme proprio*** di B (tutta questa affermazione vale anche per il sovrainsieme).

Anche in questo caso possiamo definire un sottoinsieme definendo la proprietà che caratterizza ogni singolo elemento. Supponendo che $T$ sia un insieme, $Q$ è un sottoinsieme definito in questo modo:
- $Q$ = { $x :$ $x ∈ T$ e $P(x)$ } (==ogni elemento del sottoinsieme $Q$ deve appartenere sia a $T$ sia rispettare la proprietà $P(x)$==) 
	- $T$ è l'insieme dei numeri interi positivi da 1 a 100, la proprietà $P(x)$ per essere vera un numero deve essere multiplo di 10. Allora un sottoinsieme definito cosi: { $x :$ $x ∈ T$ e $P(x)$ } sarà uguale {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}.

---
Un'insieme di dice discreto se è possibile ordinare i suoi elementi in maniera tale che tra un qualunque elemento è il suo successivo non ci siano altri elementi. Ricordando:
- N = {0, 1, 2, 3, 4, . . .} è un insieme discreto
- Z = {. . . , −4, −3, −2, −1, 0, 1, 2, 3, 4, . . .} è un insieme discreto
- Q = {$\frac{n}{m}$ : n, m ∈ Z} non è un'insieme discreto
- R = {x : x razionale o irrazionale } non è un insieme discreto

---
##### Operazioni tra insiemi
Le operazioni principali tra insiemi sono:
1. ***Unione*** di 2 insiemi A e B, è l'insieme formato da quegli elementi che appartengono ad almeno uno dei due. La notazione che usiamo è la seguente:
	- $A$ ∪ $B$ = {$x$ : $x ∈ A$ oppure $x ∈ B$.} (==A unito B è formato da qualsiasi x che appartiene ad A oppure a B==)
		- Se $A$ = {1, 2, 3} e $B$ = {3, 4, 5} allora $A ∪ B$ = {1, 2, 3, 4, 5}. L’elemento 3, presente in entrambi gli insiemi, è presente nell’unione una sola volta.
2. ***Intersezione*** di 2 insiemi A e B, è l'insieme formato dagli elementi che appartengono ad entrambi gli insiemi. La notazione che usiamo è la seguente:
	- $A ∩ B$ = {$x$ : $x ∈ A$ e $x ∈ B$.} (==$A$ intersezione $B$ è formata dalle x che appartengono sia ad $A$ che a $B$==)
		- Se A = {1, 2, 3} e B = {3, 4, 5} allora A ∩ B = {3} notiamo che l’elemento 3, è l’unico presente in entrambi gli insiemi
	- A ∩ B = ∅. Se l'intersezione tra 2 insiemi è vuota si dicono disgiunti
3. ***Differenza*** di 2 insiemi, è l'insieme formato da quegli elementi del primo insieme che non appartengono al secondo insieme. La notazione che usiamo è la seguente:
	- $A \backslash B$ = {x : x ∈ A e $x \notin B$.} (A differenza B è formato dalle x che appartengono ad A ma non appartengono a B)
4. [[#Altre operazioni tra insiemi]]
Sia per l'unione che per l'intersezione valgono le proprietà commutativa e associativa

La cardinalità dell’unione di due insiemi è la somma delle cardinalità meno la cardinalità dell’intersezione. La notazione scritta sarebbe:
- $|A ∪ B|$ = $|A|$ + $|B|$ − $|A ∩ B|$
La cardinalità della differenza tra 2 insiemi è la differenza tra la cardinalità del primo insieme e la cardinalità dell'intersezione tra i 2 insiemi. La notazione scritta sarebbe:
- |$A \backslash B$| = $|A|$ − $|A ∩ B|$ 
---
Una rappresentazione classica delle relazioni tra insiemi è il diagramma di Venn
![[Pasted image 20241012110411.png]]
Come possiamo notare ci sono 8 regioni e sono le seguenti:
- A \ (B ∪ C)
- B \ (A ∪ C) 
- C \ (A ∪ B)
- (A ∩ B) \ C
- (A ∩ C) \ B
- (B ∩ C) \ A
- A ∩ B ∩ C
Un'altra regione è quella dove ci sono tutti gli elementi che non appartengono a nessuno dei 3 insiemi. Il numero di regioni nel diagramma di Venn è $2^n$ dove $n$ è il numero di insiemi presi in considerazione.

---
##### Altre operazioni tra insiemi
4. ***Complemento di un'insieme***, se assumiamo che tutti gli insiemi siano sottoinsiemi di un insieme ***"universo"*** detto $U$ allora $U \backslash A$ viene detto complemento di A (in notazione matematica si scrive così: $A^C$)
	- Se A = {1, 2, 3} e U = {1, 2, 3, · · · , 10}| allora AC = {4, 5, · · · , 10}
	Questo tipo di operazione ha delle proprietà:
	1. $(A^C)^C$  = $A$ ==(il complemento del complemento di un'insieme è l'insieme stesso)==
	2. $(A ∩ B)^C = A^C ∪ B^C$ ==(De Morgan: il complemento dell'intersezione è l'unione dei complementi)==
	3. $(A ∩ B)^C = A^C ∪ B^C$ (==De Morgan: il complemento dell'unione è l'intersezione dei complementi)==
	La cardinalità di un complemento di un insieme si basa sulla cardinalità di U se U è finito allora |$A^2$| = |U| - |A|. 
5. ***Differenza simmetrica*** di 2 insiemi, è l'unione tra la differenza tra gli insiemi e quindi tutti quegli elementi del primo o del secondo che non appartengono ad entrambi. La notazione che usiamo è la seguente:
	- $A∆B$ = (A \ B) ∪ (B \ A).
		- Se A = {1, 2, 3} e B = {3, 4, 5}| allora A∆B = {1, 2, 4, 5}
   Questo tipo di operazione ha delle proprietà:
	- Commutativa: $A∆B$ = $B∆A$
	- Associativa: $A∆(B∆C)$ = $(A∆B)∆C$
	- $A∆B$ = $(A \backslash B) ∪ (B \backslash A) = (A ∪ B) \backslash (A ∩ B).$ 
---
##### Dimostrazione diretta
Tutte le dimostrazioni di proprietà e le soluzioni di esercizi su insiemi includeranno dimostrazioni del tipo:
- dimostra che A ⊆ B o, equivalentemente, B ⊇ A,
	- Per dimostrare che A ⊆ B si considera un elemento generico x ∈ A e si dimostra che x ∈ B. 
- dimostra che A = B 
	- Per dimostrare che A = B, dobbiamo dimostrare che hanno gli stessi elementi. Quindi si dimostra che A ⊆ B e B ⊆ A. 
- dimostra che A = ∅ 
	- Per dimostrare che A = ∅ si fa vedere che la definizione di appartenenza ad A porta ad una contraddizione.

Supponiamo di avere l'insieme A definito come: A = {x ∈ N | x è pari e x è dispari}
Vogliamo dimostrare che A è vuoto.
1. **Assumiamo il contrario:** Supponiamo che esista un elemento x in A.
2. **Cerchiamo una contraddizione:** Se x è in A, allora x è sia pari che dispari. Ma un numero non può essere contemporaneamente pari e dispari. Questa è una contraddizione.
3. **Conclusione:** Poiché abbiamo trovato una contraddizione, l'assunzione iniziale (che esiste un elemento in A) deve essere falsa. Quindi, A è vuoto


