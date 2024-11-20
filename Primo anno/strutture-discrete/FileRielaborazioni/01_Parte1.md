
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

Una qualunque formala $P$ si può trasformare in una delle 2 forme normali sopracitate, questo si fa seguendo questi step:
1. Elimina le coimplicazioni p ⇔ q dalla formula sostituendole con (p ⇒ q) ∧ (q ⇒ p)
2. Elimina le implicazioni p ⇒ q dalla formula sostituendole con ¬p ∨ q
3. Sposta le negazioni a ridosso delle variabili proposizionali ed elimina le doppie negazioni.
	- ¬(¬p ∨ ¬r ∨ s) diventa (p ∧ r ∧ ¬s) ([[ExcelProof1.png |Veridicità di questa cosa]])
4. Di questo step abbiamo 2 casi:
	1. Per costruire una CNF distribuiamo le congiunzioni sulle disgiunzioni, di seguito un'esempio:
		1. $(p ∧ q) ∨ (¬p ∧ ¬r ∧ s)$
		2. $(p ∨ ...) ∧ (q ∨ ...)$ Scrivo entrambe le variabili separate con l'operatore logico che trovo tra le parentesi
		3. $(p ∨ (¬p ∧ ¬r ∧ s)) ∧ (q ∨ (¬p ∧ ¬r ∧ s))$ Sostituisco la seconda parentesi ai puntini
		4. $(p ∨ ¬p) ∧ (p ∨ ¬r ) ∧ (p ∨ s) ∧ (q ∨ ¬p) ∧ (q ∨ ¬r ) ∧ (q ∨ s)$ distribuisco p e q sulla parentesi $(¬p ∧ ¬r ∧ s)$ 
		5. $(p ∨ ¬r ) ∧ (p ∨ s) ∧ (q ∨ ¬p) ∧ (q ∨ ¬r ) ∧ (q ∨ s)$ elimino la formula $(p ∨ ¬p)$ perché sarebbe sempre falsa
	2. Per costruire una DNF distribuiamo le disgiunzioni sulle congiunzioni, di seguito un'esempio
		1. $(p ∨ q) ∧ (¬p ∨ ¬r )$
		2. $(p ∧ ...) ∨ (p ∧ ...) ∨ (q ∧ ...) ∨ (q ∧ ...)$ Prendo una variabile della prima parentesi, gli metto vicino l'operatore logico fuori dalla parentesi, faccio questa cosa una volta per ogni variabile della della seconda parentesi. Il segno che c'è tra le nuove parentesi e quello dentro la parentesi iniziale. 
		3. $(p ∧ ¬p) ∨ (p ∧ ¬r ) ∨ (q ∧ ¬p) ∨ (q ∧ ¬r )$ Sostituisco ogni variabile della seconda parentesi iniziale ai puntini
		4. $(p ∧ ¬r ) ∨ (q ∧ ¬p) ∨ (q ∧ ¬r )$ elimino la formula $(p ∨ ¬p)$ perché sarebbe sempre falsa
Per fare questa cosa in modo più veloce esiste [[Tips#Come trasformare una qualsiasi formula in CNF e DNF|✨metodo Di Bella ✨]]
Esempio:
![[Pasted image 20241012123046.png]]

---
# `Insiemi` 
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
##### Cardinalità
Si dice **Cardinalità** il numero di elementi che costituisce un'insieme e si denota con il simbolo: $|A|$ questo potrebbe assumere anche il valore di $\infty$, un'esempio potrebbe essere l'insieme dei numeri pari che ha una cardinalità uguale ad $\infty$.

---
Nomenclature: 
- Per indicare un'insieme costituito da un solo elemento usiamola parola *singoletto*
- invece per indicare un'insieme vuoto usiamo il seguente simbolo: 
	- ∅ (la cardinalità del seguente insieme è uguale a 0)

---
##### Sottoinsieme e sovrainsieme
Se abbiamo 2 insiemi A e B, e tutti gli elementi di A appartengono a B, diciamo che A è un ***sottoinsieme*** di B e lo denotiamo così:
- A ⊆ B ⇔ (∀x)(x ∈ A ⇒ x ∈ B) ==(A è un sottoinsieme di B se e solo se qualunque x che appartiene ad A, appartiene anche a B)==
facendo rifermento allo stesso caso potremmo dire che B è un ***sovrainsieme*** di A e lo denotiamo così:
- B ⊇ A ⇔ (∀x)(x ∈ A ⇒ x ∈ B) ==(A è un sovrainsieme di B se e solo se qualunque x che appartiene ad A, appartiene anche a B)==

<mark class="hltr-purple">Nota bene</mark> tra le due espressioni scritte qua sopra cambia la direzione del segno

Le relazioni A ⊆ B è verificata anche nel caso A = B, se volessimo esprimere il concetto A ⊆ B ma specificando che A è diverso da B (quindi che in B ci sono elementi che in A non ci sono) scriviamo in questo modo A ⊂ B, in questo caso diciamo che A è un ***sottoinsieme proprio*** di B (tutta questa affermazione vale anche per il sovrainsieme).

Anche in questo caso possiamo definire un sottoinsieme definendo la proprietà che caratterizza ogni singolo elemento. Supponendo che $T$ sia un insieme, $Q$ è un sottoinsieme definito in questo modo:
- $Q$ = { $x :$ $x ∈ T$ e $P(x)$ } (==ogni elemento del sottoinsieme $Q$ deve appartenere sia a $T$ sia rispettare la proprietà $P(x)$==) 
	- $T$ è l'insieme dei numeri interi positivi da 1 a 100, la proprietà $P(x)$ per essere vera un numero deve essere multiplo di 10. Allora un sottoinsieme definito cosi: { $x :$ $x ∈ T$ e $P(x)$ } sarà uguale {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}.

---
Un'insieme si dice **discreto** se è possibile ordinare i suoi elementi in maniera tale che tra un qualunque elemento è il suo successivo non ci siano altri elementi. Ricordando:
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
3. **Conclusione:** Poiché abbiamo trovato una contraddizione, l'assunzione iniziale (che esiste un elemento in A) deve essere falsa. Quindi, A è vuoto.

---
##### Insieme delle parti
Dato un'insieme T, consideriamo insieme delle parti di T un'insieme che contiene tutti i sottoinsiemi di T, lo indichiamo così:
- $P(T)$ oppure $pow(T)$
	- Sia $T$ = {1, 2, 3} allora $P(T)$ = {∅, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}
[[01_Parte1#Cardinalità|Cardinalità]] dell'insieme delle parti:
- Se $T$ = ∅  allora $P(T)$ = {∅}
- Se $|T|$ = 1  quindi $T$ = {a} allora $P(T)$ = { ∅ , {a} } = 2 elementi
- Se $|T|$ = 2  quindi $T$ = {a, b} allora $P(T)$ = { ∅ , {a}, {b}, {ab} } = 4 elementi
- Se $|T|$ = 3  quindi $T$ = {a, b, c} allora $P(T)$ = 8 elementi
Come possiamo ben notare la cardinalità di $P(T)$ = $2^n$ dove $n$ è il numero di elementi di T
Proprietà: (Per capire le proprietà di consiglia prima di vedere bene:[[#Sottoinsieme e sovrainsieme| spiegazione ⊂ e ⊃]])
- $P(A ∩ B) = P(A) ∩ P(B)$
	- Dimostrazione: Per dimostrare che è vera l'equivalenza dobbiamo dimostrare 2 casi
		1. Caso ⊂: supponendo che $X ∈ P(A ∩ B)$  e quindi che $X ⊂ A$ e $X ⊂ B$ da questo capiamo facilmente che  $X ∈ P(A)$ e $X ∈ P(B)$ e quindi che $X ∈ P(A) ∩ P(B)$
		2. Caso ⊃: supponiamo che $X ∈ P(A) ∩ P(B)$ e quindi che $X ⊆ A$ e $X ⊆ B$ quindi $X ⊆ A ∩ B$ ciò implica che $X ∈ P(A ∩ B)$
- $P(A ∪ B) ⊃ P(A) ∪ P(B)$ 
	- Dimostrazione: Per dimostrare questa formula dobbiamo dimostrare che $P(A ∪ B) ⊃ P(A) ∪ P(B)$ ma anche che un generico elemento di $P(A ∪ B)$ non appartenga a $P(A) ∪ P(B)$ 
		1. Caso ⊃: Supponiamo che $X ∈ P(A) ∪ P(B)$, allora $X ∈ P(A)$ oppure $X ∈ P(B)$.Nel primo caso $X ⊆ A$ mentre nel secondo caso $X ⊆ B$. In entrambi i casi, quindi, $X ⊆ A ∪ B$ da cui $X ∈ P(A ∪ B)$.
		2. Caso $\neq$ : Sia A = {1, 2} e B = {1, 3}. L’insieme $A ∪ B$ = {1, 2, 3} appartiene a $P(A ∪ B)$ ma non appartiene a $P(A)$ ∪ $P(B)$ ( ricordiamo che P(A) = { ∅, {1}, {2}, {1,2} }  invece P(B) = { ∅, {1}, {3}, {1,3} } ) 

> [!Famiglia di Insiemi]
> Un insieme di insiemi, come ad esempio l’insieme delle parti, è anche detto ***"famiglia di insiemi"***

---
##### Diagramma di Venn di famiglie di insiemi
Data una famiglia di n insiemi detta F, le regioni del diagramma di Venn sono $2^n$. Una famiglia di insiemi con un numero infinito di elementi è una ***famiglia infinita***. Se invece ha un numero finito di elementi allora è una ***famiglia infinita***.
- Sia $F$ = {P, D} dove P è l’insieme dei numeri pari (infinito) e D è l’insieme dei numeri dispari (infinito). La famiglia F è una famiglia finita di insiemi.
- Sia $F$ = {$P_1$, $P_2$, $P_3$, . . .} dove $P_i$ = {$2^1$, · · · , $2^i$ }. La famiglia è infinita, ma tutti i suoi elementi sono insiemi finiti.
Le operazioni di unione ed intersezione si possono estendere alle famiglie infinite. 

Sia $F$ una famiglia qualunque di insiemi si indica con: $\bigcup_{ X \in F} X$  l'insieme degli elementi di $X$ che appartengono ad F e viene detto insieme unione della famiglia $F$. Quindi:
- $\bigcup_{X \in \mathcal{F}} X = \{x : \exists X, X \in \mathcal{F}$ e $x \in X\}$ L'insieme unione della famiglia $F$ è uguale all'insieme di tutte le $x$ appartenenti a $X$ che rispettano la condizione che $X$ esista ed appartenga ad $F$. ==Tutto ciò si traduce nel dire che l'insieme unione della famiglia $F$ è uguale all'unione tra tutti gli insiemi appartenenti a $F$ stesso e quindi da tutti gli elementi degli insiemi (ripetuti una volta sola)==
- **Esempio:**
	- **La famiglia di insiemi $F$:** Rappresenta tutti gli studenti di una scuola, divisi per classe. Ogni classe è un insieme di studenti.
	- **L'insieme $X$ :** Rappresenta una singola classe.
	- **L'elemento $x$ :** Rappresenta un singolo studente.
	- **L'espressione:**
		In questo caso significherebbe "Se prendi tutti gli studenti da tutte le classi e li metti insieme, otterrai l'insieme di tutti gli studenti della scuola."
Sia $F$ una famiglia qualunque di insiemi si indica con $\bigcap_{X \in \mathcal{F}} X$ l'insieme degli elementi che appartengono a tutti gli insiemi $X$ che appartengono ad $F$ e viene detto insieme intersezione della famiglia $F$. Quindi:
- $\bigcap_{X \in \mathcal{F}} X = \{x : \forall X \in \mathcal{F}, x \in X\}$ L'insieme intersezione della famiglia $F$ è uguale all'insieme di tutti gli elementi $x$ tali che per ogni $X$ appartenente a F, x appartiene a X. ==Tutto ciò si traduce nel dire che l'insieme intersezione della famiglia F è uguale all'intersezione tra tutti gli insiemi appartenenti a F stesso e quindi avremo come risultato un insieme fatto dagli elementi comuni a tutti gli insiemi.==

---
##### Insiemi chiusi
Sia dato un insieme $U$ ed un operazione, se quest'ultima può essere definita o completata in $U$ allora possiamo dire che $U$ e chiuso rispetto a quell'operazione
- Sia $U = \mathbb{N}$ e l'operazione che consideriamo è la somma, allora possiamo dire che U è un'insieme chiuso rispetto alla somma (la somma di 2 qualsiasi valori ci da un valore positivo e quindi che appartiene a $\mathbb{N}$)
-  Sia $U = \mathbb{N}$ e l'operazione che consideriamo è la sottrazione, allora possiamo dire che U **non** è un'insieme chiuso rispetto alla sottrazione (la sottrazione di 2 qualsiasi valori ci potrebbe dare un valore negativo che non appartiene $\mathbb{N}$)
###### Chiusura rispetto all'unione ed intersezione
Sia $F$ una famiglia di insiemi
- diciamo che $F$  è chiusa rispetto all’unione se per ogni coppia di insiemi $X$ e $Y$ appartenenti a $F$ anche $X ∪ Y$ appartiene a $F$.
- diciamo che $F$ è chiusa rispetto all’intersezione se per ogni coppia di insiemi $X$ e $Y$ appartenenti a $F$ anche $X ∩ Y$ appartiene a $F$.
- Sia F = { {1, 2, 3}, {1, 2}, {1, 3} } abbiamo che $F$ è chiuso rispetto all’unione ma non è chiuso rispetto all’intersezione, perché {1, 2 } ∩ {1, 3} = {1} che non appartiene ad F.
Considerando $F$ una famiglia di insiemi composta da sotto insiemi di un insieme universo detto $U$, possiamo dire che per ogni X ∈ $F$ il complemento di X rispetto ad U ovvero $X^C = U \backslash X$ appartiene ad a $pow(U)$. Quindi possiamo dire che $F^C$ è una famiglia di insiemi dove ogni insieme viene complementato rispetto ad $U$ 
- $U$ = {1, 2, 3}
- pow($U$)= $\{\emptyset, \{1\}, \{2\}, \{3\}, \{1, 2\}, \{1, 3\}, \{2, 3\}, \{1, 2, 3\}\}$
- $F$ = {{1}, {2, 3}, {1, 2}}
- $F^C$ = { {2,3}, {1}, {3} }
la famiglia complemento viene definita cosi:
- $F^C$ = {$X^C$ : $X$ ∈ $F$ } 
ovvero come l'insieme di tutti le $X$ ∈ $F$ però complementate.

Teoremi:
- La famiglia $F$ è chiusa rispetto all’unione se e solo se la famiglia $F^C$ è chiusa rispetto all’intersezione.
- La famiglia $F$ è chiusa rispetto all’intersezione se e solo se la famiglia $F^C$ è chiusa rispetto all’unione.
![[Pasted image 20241019115203.png]]

Sia data:
- $F$ una famiglia finita di insiemi su un insieme $U$
- * una generica operazione sull'insieme

***Definiamo chiusura di $F$ rispetto ad * la più piccola famiglia $F^{*}$ che contiene $F$ ed è chiusa rispetto a * .***

- Esempio: sia data $F$ = {{1, 2, 3}, {1, 2}, {1, 3}, {2, 4}} ovvero famiglia non chiusa rispetto all'operazione di unione. La famiglia più piccola che contiene $F$ ed è chiusa rispetto all'operazione di unione è la famiglia $F^I$ = {{1, 2, 3}, {1, 2}, {1, 3}, {2, 4}, {1, 2, 3, 4}, {1, 2, 4}} [[Tips#Come calcolare la chiusura di una famiglia rispetto ad unione/intersezione]] 
---
##### Partizioni
Una famiglia di insiemi $F$ formata da sottoinsiemi dell'insieme universo $U$ può essere chiamata anche partizione di $U$ 
- Sia $U$ = {1,2,3,4,5,6,7,8,9,10,11,12} $F$ = { {1, 3, 5, 7, 8, 10, 12}, {2}, {4, 6, 9, 11} }, $F$ è una partizione di $U$
---
##### Coppie ordinate
Consideriamo 2 elementi x e y. Creiamo una coppia ordinata dove il primo elemento è x ed il secondo elemento è y. Denotiamo tale coppia con (x, y).
- la coppia (x, y) è diversa dalla coppia (y, x) (a meno che x = y).
- (x, y) = (x′, y′) se e solo se x = x′ e y = y′
> [!Nota bene]
> la coppia (x, y) è diversa dall’insieme {x, y} costituito dagli elementi x e y

----
##### Insieme prodotto
Dati 2 insiemi non vuoti $A$ e $B$, l'insieme prodotto da $A$ per $B$ (che indichiamo con $A × B$) è l'insieme di tutte le coppie ordinate $(x, y)$ con $x ∈ A$ e $y ∈ B$
- A × B = {(x, y) : x ∈ A e y ∈ B} A×B è l'insieme di tutte le coppie $(x, y)$ con $x$ che appartiene ad $A$ e $y$ che appartiene a $B$
	- Un'esempio di questo prodotto è il piano cartesiano che definiamo come $\mathfrak{R} \times \mathfrak{R}$ che è un insieme formato da tutte le coppie ordinate di numeri reali.
	 ![[Pasted image 20241019143758.png]]
	- Dati, in un certo ordine, tre insiemi A, B, C, si chiama loro prodotto, e si indica con A × B × C l’insieme di tutte le terne ordinate (x, y, z) con x ∈ A, y ∈ B, z ∈ C.
---
##### Paradosso di Russell
Partendo dal concetto di insieme, possiamo benissimo costruire un insieme formato da tutti quegli elementi che non appartengono a se stessi e lo definiamo in questo modo:
- $S = \{A {:} A \text{ è un insieme, e } A \notin A\}$  $S$ è l'insieme di tutti gli insiemi che non appartengono a se stessi. Per esempio, l'insieme di tutti i frutti non è un frutto, quindi potrebbe appartenere a $S$.
Usando questa definizione S ∈ S?
- **Se diciamo SI:** Se S appartiene a se stesso, allora per definizione di S, S non dovrebbe appartenere a se stesso (perché S contiene solo insiemi che non appartengono a se stessi). Questo è una contraddizione.
- **Se diciamo NO:** Se S non appartiene a se stesso, allora per definizione di S, S dovrebbe appartenere a se stesso (perché S contiene tutti gli insiemi che non appartengono a se stessi). Anche in questo caso abbiamo una contraddizione.
Evitiamo questa contraddizione imponendo nella definizione dell'insieme che quest'ultimo deve essere sottoinsieme di un'insieme conosciuto, la nuova definizione di $S$ diventa: $S = \{A \mid A \subseteq U, A \notin A\}$ 
Con questa nuova definizione, il paradosso svanisce. Se proviamo a chiedere se S appartiene a se stesso, ci rendiamo conto che S è un sottoinsieme di U, ma non possiamo dire con certezza se S appartiene o meno a U. In questo modo, evitiamo il circolo vizioso che portava alla contraddizione.

# `Relazioni e funzioni`
---
##### Relazioni
Sia $U$ un insieme non vuoto. Con il termine relazione indichiamo un insieme formato in questo modo: (per capire meglio questo insieme guarda: [[#Insieme prodotto]])
- $R ⊆ U × U$ ovvero $\{(x, y) \in U \times U : R(x, y)\}$ cioè un insieme formato da tutte le coppie che rendono vera la relazione, questo insieme viene chiamato ***grafico della relazione***
	- Considera l'insieme U = {1, 2, 3}. Una possibile relazione R su U potrebbe essere "è minore di". In questo caso, il grafico di R sarebbe {(1, 2), (1, 3), (2, 3)}, perché 1 è minore di 2 e 3, e 2 è minore di 3, questi sono gli unici 3 casi che rendono vera la relazione "è minore di".
[[#Proprietà delle relazioni]]
---
##### Funzioni
Una relazione f definita su $A × A$ si dice funzione di $A$ (dominio) in $B$ (codominio), se per ogni $x ∈ A$ esiste uno ed uno solo $y ∈ A$ tale che $(x, y) ∈ f$. La notazione classica per esprimere f è la seguente: $f : A → B$ per ogni x ∈ A l’unico elemento $y ∈ B$ tale che (x, y) ∈ $f$ si indica con $f(x)$

Casi particolari:
- $f : A → B$  per ogni x, f(x) = $x$ si dice ==**applicazione identica**== di $A$
- $f : A × B → A$ tale che per ogni $(x, y)$ $f(x, y)$ = $x$ si dice ==**proiezione canonica**== su $A$.
- $f : A × B → B$ tale che per ogni $(x, y)$ $f(x, y)$ = $y$ si dice ==**proiezione canonica**== su $B$.

Dato $f : A → B$ e anche un sottoinsieme di A chiamato X si dice ***immagine di X*** il sottoinsieme di B costituito dagli elementi che provengono da X. Questo insieme si indica con f(X) e anche con la seguente definizione:
- $f(X) = \{y: y \in B \land (\exists x \in X) (f(x) = y)\}$  ==L'immagine di X è l'insieme di tutti gli y appartenenti a B tali che esiste un x appartenente a X per cui f(x) è uguale a y==
$F(A)$ si dirà ***immagine dell'applicazione f***, ovvero tutti i possibili valori che la funzione può assumere.

###### Funzione iniettiva
Data un'applicazione $f$: $A$ → $B$ se porta punti distinti del dominio su su punti distinti del codominio la funzione si dice ==***iniettiva***== formalmente la definiamo così:
- $\forall x, y \in A, \text{ se } x \neq y, \text{ allora } f(x) \neq f(y).$ Per tutti x e y appartenenti ad A se x è diverso da y allora f(x) è diverso da f(y). Questo tipo di funzione viene definita funzione "uno a uno"
appunto perché associa ad ogni elemento di B(codominio) **soltanto** un elemento di A(dominio)
- Esempio: ![[Pasted image 20241020160345.png]]
- $X$ è l'insieme delle $x$ del piano cartesiano corrisponde a $A$ nella definizione precedente
- $Y$ è l'insieme delle $y$ del piano cartesiano corrisponde a $B$ nella definizione precedente
- ***nel primo grafico ad ogni valore di $Y$*** ***posso sempre associare un solo elemento di $X$*** ***e quindi è iniettiva, nel secondo invece ad ogni valore di $Y$ posso associare più elementi di $X$***
---
###### Funzione surgettiva
Data un'applicazione $f$: $A$ → $B$ se l'immagine $f(A)$ $=$ $B$ la funzione si dice ==***surgettiva***== ovvero un funzione che associa ad ogni elemento di B (codominio) **almeno** un'elemento di A(dominio).
- Esempio:![[Pasted image 20241020161146.png]]
- $X$ è l'insieme delle $x$ del piano cartesiano corrisponde al dominio
- $Y$ è l'insieme delle $y$ del piano cartesiano corrisponde al codominio
- ***nel primo grafico ad ogni valore di $Y$ posso associare almeno un elemento di $X$, nel secondo grafico invece ad ogni valore di $Y$ non posso associare un valore di $X$ (dove c'è la linea rossa non posso associare $Y$ a nessuna $X$)**.*

> [!Nota bene]
> 1. Una ***funzione iniettiva*** può avere elementi del codominio che non vengono raggiunti.
> 2. Una ***funzione suriettiva***, invece, raggiunge tutti gli elementi del codominio.

---
###### Funzione biiettiva
Data un'applicazione $f$: $A$ → $B$ si dice *==biiettiva==* se è sia iniettiva che surgettiva. Questo tipo di funzione associa sempre ogni elemento di A ad ogni elemento di B
Esempio: ![[Pasted image 20241020164744.png]] 
- $X$ è l'insieme delle $x$ del piano cartesiano corrisponde al dominio
- $Y$ è l'insieme delle $y$ del piano cartesiano corrisponde al codominio
- ad ogni elemento di $X$ posso associare soltanto un elemento di $Y$ questo posso farlo sempre

La cardinalità di un insieme è definita come il numero di elementi che appartengono all'insieme, per riuscire a contare questi elementi si cerca una corrispondenza biunivoca tra l'insieme e un insieme "campione" fatto da numeri naturali detto $l_n$ ovvero l'insieme dei numeri naturali interi che precedono $n$ ( es: {0, 1, 2, · · · , n − 1} ), infatti:
- ***Insieme finito***: si dice che un insieme $X$ è finito se esiste un $n ∈ N$ tale che $X$ si possa mettere in corrispondenza biunivoca con $I_n$ ; 
- ***Insieme infinito***: Se non esiste un numero naturale $n$ tale da costruire un insieme $l_n$ grande quanto $X$, l'insieme è infinito.

***Teorema***: Se $A$ e $B$ sono due insiemi finiti ed esiste una funzione **iniettiva** $f:A→B$, allora la cardinalità di $A$ è minore o uguale alla cardinalità di $B$, cioè $∣A∣≤∣B∣$ 

***Dimostrazione***:  Si considera l'immagine $f(A)$, cioè l'insieme di elementi di $B$ a cui $A$ viene mappato. Poiché $f$ è iniettiva, ogni elemento di $A$ corrisponde a un elemento unico di $f(A)$, quindi $∣A∣=∣f(A)∣$. Tuttavia, $f(A)$ è un sottoinsieme di $B$ (cioè tutti gli elementi di $f(A)$ appartengono a $B$), quindi $∣f(A)∣≤∣B∣$. Da qui segue che $∣A∣≤∣B∣$. (Ricordiamo che essendo iniettiva la funzione non tutti gli elementi di B(codominio) hanno un immagine in A(dominio))

---
##### Proprietà delle relazioni
Sia dato un insieme U diremo che una relazione $R(x, y)$ definita in $U×U$ è:
- ***Riflessiva***: se $∀x∈U$ risulta vero che $R(x, x)$.
	- R = { (1,1), (2,2) } è riflessivo
	- R = { (1,1), (2,2), (1,3) } non è riflessivo
- ***Simmetrica***: se $∀x, y ∈ U$ risulta vero che $R(x, y)$ e anche $R(y, x)$ 
	- R = {(1,2),(2,1)} è simmetrico
	- R = {(1,2),(2,1),(1,3)} non è simmetrico
- ***Transitiva***: se $∀x,y,z ∈ U$ risulta vero che $R(x, y)$ e $R(y, z)$ allora ci deve essere anche una $R(x, z)$ 
- ***Esempio fatto durante l'esercitazione:***![[Pasted image 20241023101548.png]]

> [!Nota bene]
> Una relazione che è sia riflessiva, simmetrica e transitiva si dice relazione di ***equivalenza***. Più in generale una **relazione di equivalenza** è una relazione tra elementi di un insieme che li "raggruppa" in base a certe proprietà comuni. si indica in questo modo:
> - $x ≈ y$ 


Se hai un insieme $U$ e una relazione di equivalenza su questo insieme, puoi prendere un elemento $x$ di $U$ e formare un sottoinsieme di $U$, che contiene tutti gli elementi che sono equivalenti a $x$. Questo sottoinsieme è chiamato ***classe di equivalenza*** di $x$, e si indica con  $[x]$. 

Per le classi di equivalenza vale il seguente teorema:
***Teorema***: Due classi di equivalenza o sono disgiunte o coincidono.
***Dimostrazione***: Siano $[x]$ e $[z]$ due classi di equivalenza e supponiamo che esse abbiano un elemento $w$ in comune: pertanto è $w ≈ x$ e $w ≈ z$. Allora, per la proprietà transitiva è $x ≈ z$. Sia ora $y ∈ [x]$, cioè $y ≈ x$. Per la proprietà transitiva è $y ≈ z$, cioè $y ∈ [z]$. Quindi, $[x] ⊆ [z]$. Analogamente si dimostra che $[z] ⊆ [x]$. 
**Spiegazione della dimostrazione**:
1. **Prima parte**: Supponiamo che le classi $[x]$ e $[z]$ abbiano un elemento $w$ in comune
    - Se $w$ è in comune, significa che $w ≈ x$ e $w ≈ z$
    - Per la proprietà transitiva della relazione di equivalenza, se $w ≈ x$ e $w ≈ z$, allora $x ≈ z$
2. **Seconda parte**: Dimostriamo che $[x]$ ⊆ $[z]$
    - Prendiamo un elemento qualsiasi $y ∈ [x]$
    - Per definizione di classe di equivalenza, $y ∈ [x]$ significa che $y ≈ x$
    - Sappiamo già che $x ≈ z$ (dalla prima parte)
    - Per la proprietà transitiva, se $y ≈ x$ e $x ≈ z$, allora $y ≈ z$
    - Quindi $y ∈ [z]$
    - Poiché questo vale per ogni $y ∈ [x]$, abbiamo dimostrato che $[x] ⊆ [z]$
3. **Terza parte**: Analogamente si dimostra che $[z] ⊆ [x]$
    - Il ragionamento è lo stesso ma invertendo x e z
4. **Conclusione**:
    - Se $[x] ⊆ [z]$ e $[z] ⊆ [x]$, allora $[x] = [z]$
    - Questo dimostra che **se** due classi di equivalenza non sono disgiunte (cioè hanno un elemento in comune), allora devono necessariamente coincidere. In altre parole, non possono "sovrapporsi parzialmente" o non hanno elementi in comune (sono disgiunte) o sono esattamente le stesse (coincidono).

Data una relazione $R$ su un insieme $U$, consideriamo ora la famiglia di insiemi $F$ formata da tutte le classi di equivalenza create dalla relazione $R$ su $U$. $F$ è un sottoinsieme di [[#Insieme delle parti|pow]](U) tale che:
- L'unione di tutte le classi di equivalenza che appartengono ad $F$ ci da $U$
- per ogni X , Y ∈ F, X $\neq$ Y si ha X ∩ Y = ∅ (vedi teorema precedente)
Quindi, una relazione di equivalenza $R$ individua una partizione $F$ su $U$ che viene detta ***Insieme Quoziente*** e lo denotiamo con $U/R$ 
***Esempio***: Immagina U come l'insieme dei numeri interi e R come la relazione "avere lo stesso resto nella divisione per 3" :
$[0]$ = {…, -3, 0, 3, 6, …}
$[1]$ = {…, -2, 1, 4, 7, …}
$[2]$ = {…, -1, 2, 5, 8, …} 
Queste tre classi formano una partizione di $U$ ovvero $F$, che si può anche chiamare ***Insieme quoziente di U***. Quindi capiamo subito che 
- $F = U/R$

Individuato l'insieme quoziente (che denotiamo con $U/R$), l'applicazione $U → U/R$, ovvero un'applicazione che associa ogni $x ∈ U$ alla sua classe di equivalenza. Questa è un'applicazione surgettiva perché ogni classe di equivalenza è effettivamente "raggiunta" da almeno un elemento di $U$. Questa applicazione viene anche chiamata ***applicazione canonica sul quoziente***. 

> [!Nota bene]
> [[Tips#Differenza tra applicazione e funzione]] 
> Nel contesto specifico dell'**applicazione canonica sul quoziente**, si parla di **applicazione** perché si vuole mettere in evidenza il fatto che stiamo "applicando" una trasformazione sugli elementi dell'insieme $U$. In particolare, stiamo usando una regola (la relazione di equivalenza) per trasformare ogni elemento x di $U$ nella sua **classe di equivalenza** $[x]$.

Di seguito delle definizioni:

1. Si dice che una relazione binaria si ***antisimmetrica*** se:
	- $∀x, ∀y ∈ U$ si ha che: $(R(x, y) e R(y, x)) → x = y$. il sussistere di entrambe le relazioni $R(x, y)$ e $R(y, x)$ è possibile solo quando $x$ e $y$ coincidono.

2. Si dice ***preordinamento*** una relazione binaria assegnata in un insieme che goda della proprietà riflessiva e transitiva

3. Si dice ***ordinata*** una relazione binaria assegnata in un insieme che goda della proprietà riflessiva, transitiva e antisimmetrica

Un insieme $U$ su cui è definita un relazione di pre-ordine si dice pre-ordinato. 
Un insieme $U$ su cui è definita un relazione d’ordine si dice ordinato.

Dato un pre-ordinamento oppure un ordinamento (rappresentato dal simbolo ≤) in un insieme U, si pone
- $x < y \quad \text{se} \quad x \leq y \quad \text{e} \quad x \neq y$  ovvero x è minore di y, se x è minore/uguale a y però con x diverso da y

Un ordinamento $≤$ definito in un insieme $U$ si dice totale o lineare se per ogni coppia $(x, y)$ di elementi di $U$ si ha $x ≤ y$ oppure $y ≤ x$. Altrimenti si dirà parziale.

---
###### Massimi e minimi
- Un elemento M di un insieme ordinato U si dice ***massimo*** se per ogni $x ∈ U$ si ha $x ≤ M$
- Si dice invece ***massimale*** se non vi è alcun elemento di U che lo supera.
- Un elemento m di un insieme ordinato U si dice ***minimo*** se per ogni $x ∈ U$ si ha $m ≤ x$. 
- Si dice invece ***minimale*** se non vi è alcun elemento di U ad esso inferiore

Il massimo (minimo) in un insieme è unico, il massimale (minimale) invece si può riscontrare più volte, questo accade perché potrebbe succedere che due elementi non siano confrontabili tra loro e quindi sono dei massimali.

Sia $A ⊆ N$ quindi $c(A) = n$ dal momento che A è finito, possiamo dire che A ⊆ $I_m$ per qualche intero $m$. con $I_m$ intendiamo un insieme fatto cosi {0,1,2, … , m-1}. Esistono diversi modi per rappresentare A ⊆ $I_m$
- ***Rappresentazione binaria***: la struttura dati più semplice che potremmo usare è un'array fatto da valori binari
	- $X[i]$ = 1 se $i ∈ A$
	- $X[i]$ = 0 se $i \notin A$
- ***Rappresentazione estesa***: si può anche usare un'array di interi Y con |A| = n elementi tale che se A = {$x_0$, $x_1$, . . . , $x_{n-1}$} allora per ogni $0 ≤ i ≤ n − 1$ $Y[i]$ = $x_i$ 

Se utilizziamo la rappresentazione binaria, verificare che un elemento i ∈ A prende tempo costante. Se utilizziamo la rappresentazione estesa, invece, ed A non è ordinato, dobbiamo scorrere tutta l’array e quindi tempo lineare. Se l’array è ordinata invece si può fare in tempo logaritmico. D’altro canto, se utilizziamo la rappresentazione binaria, per l’insieme A = {10, 3, 99} serve un’array di dimensione 100, mentre, se utilizziamo la rappresentazione estesa, serve un’array di dimensione 3.

Se prendiamo $U$ ovvero {0, 1, 2, . . . , n − 1}  gli elementi di $pow(U)$ sono i numeri binari esprimibili con $|U|$ bits. Quindi $2^{|U|}$.

---
Siano $U$ un insieme finito, $H ⊆ U$, e sia $A$ una famiglia di sottoinsiemi di U tutti diversi dall’insieme vuoto. Diciamo che $H$ è un hitting set ($HS$) per $A$ se e solo se per ogni $A ∈ A$ si ha $A ∩ H$ $\neq$ ∅

Sia $U$ = {a, b, c, d, e} e sia A = {{a, b, c, }, {a, d, e}, {b, c, d, }, {c, d, e}}. 
L’insieme {a, b, c} è un $HS$ per $A$ mentre {b, c} o {d, e} non lo sono.
- **{a, b, c} è un hitting set** perché:
    - Contiene 'a', che è presente anche in {a, d, e}.
    - Contiene 'b', che è presente anche in {b, c, d}.
    - Contiene 'c', che è presente anche in {c, d, e}.
    - In altre parole, questa scatola più piccola "colpisce" (interseca) tutte le altre scatole.
- **{b, c} e {d, e} non sono hitting set** perché:
	- **{b, c}** non contiene alcun elemento presente in {a, d, e}.
	- **{d, e}** non contiene alcun elemento presente in {a, b, c}.

Possono esistere diversi hitting set dentro un'insieme, si definisce **hitting set minimo** l'hitting set con meno elementi, nell'esempio sopra descritto un hitting set minimo sarebbe {a, c} visto che contiene almeno un elemento di ogni insieme contenuto in $A$

Il problema di trovare un $HS$ minimo per una famiglia di insiemi è facilmente risolvibile: basta provare per tutti i sottoinsiemi di $U$. Questo però vorrebbe dire che il numero di operazioni da fare è esponenziale visto che i sottoinsiemi non vuoti di $U$ sono esattamente $2|U| − 1$
- Per |U| = 100 il numero totale di operazioni sarebbe dell’ordine di 1, 26 · $10^{30}$ 
Esiste un modo migliore? ***non si sa!***
L'unico modo per cercare di risolvere questo tipo di problematiche è usare degli algoritmi detti greedy ciò vuol dire nello specifico, che potremmo prendere l’elemento $x_1$ di U che appartiene al maggior numero di elementi di $A$ Poi, per tutti gli elementi di $A$ a cui $x_1$ non appartiene, scegliamo l’elemento $x_2$ che appartiene alla maggior parte di essi, e così via.