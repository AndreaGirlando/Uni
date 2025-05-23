
Questo file è la rielaborazione delle slide [[01_Parte1.pdf]]

---
# `Logica proposizionale`

La **logica** è un linguaggio formale usato per rappresentare informazioni. Ogni linguaggio è formato da:
- **Sintassi**: che definisce le frasi del linguaggio
- **Semantica**: che definisce il significato delle frasi
La logica più semplice di tutti è la logica proposizionale oggi basata sulla matematica booleana, quest'ultima viene detta proposizionale perché si occupa di **proposizioni**, più precisamente di variabili proposizionali, quest'ultime possono assumere solo 2 valori: 
- 1 = VERO
- 0 = FALSO
Ogni variabile proposizionale è già da se una "formula" proposizionale, ovviamente una formula molto basilare. Per creare delle formule complesse usiamo dei connettivi logici:
- ==¬ (negazione)==: si legge "non", e inverte il valore di verità di una proposizione. Se una proposizione è vera, la sua negazione è falsa, e viceversa. Questo connettivo logico rappresenta la porta logica NOT
- ==∨ (disgiunzione logica)==: si legge "o", ed è vera se **almeno una** delle due proposizioni è vera. Questo connettivo logico rappresenta la porta logica OR
- ==∧ (congiunzione logica)==: si legge "e", ed è vera se **entrambe** le proposizioni sono vere.  Questo connettivo logico rappresenta la porta logica AND
- ==⇒ (implicazione)==: si legge "se... allora…" o semplicemente "implica". È falsa solo se il primo termine è vero e il secondo è falso.
- ==⇔ (doppia implicazione o coimplicazione)==: si legge "se … e solo se …". È vera quando entrambi i termini sono veri o entrambi falsi.
> [!EXAMPLE] Esempi di formule usando le variabili P e Q:
> - ¬P = "Non P"
> - Q  
> - P ∨ Q  = "P o Q"
> - P ∧ Q = "P e Q"
> - P ⇒ Q = "se P allora Q"
> - P ⇔ Q = P se e solo se Q

Come per le operazioni matematiche (somma, moltiplicazione, ecc...) anche le operazioni logiche hanno delle precedenze,  la negazione ($¬$) ha la precedenza su tutto mentre congiunzione ($∨$) e disgiunzione ($∧$) hanno la stessa priorità infatti:
- $¬p ∨ q$ è la formula dove la negazione si applica solo a $p$ 
- $¬(p ∨ q)$ è la formula dove la negazione si applica alla disgiunzione $p ∨ q$


> [!TIP] Funzione **Interpretazione**
> Una interpretazione $I$ su $P$ generica formula logica è una funzione $I$: $P \rightarrow \{0,1\}$ ovvero una funzione che assegna alla formula logica il valore 0 o 1. Con la nomenclatura $I(P)$ indichiamo quando la funzione $I$ assegna il valore di verità alla formula $P$

Date 2 formule $P_1$ e $P_2$ calcoliamo le loro interpretazioni: 
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
##### Nomenclature:
- Data una formula diremo che è **==soddisfacibile**== se esiste almeno un caso in cui sia vera, qualunque siano i valori delle variabili.
- Data una formula diremo che è **==insoddisfacibile==** se non esiste almeno una caso in cui sia vera, qualunque siano i valori delle variabili.
- Data una formula si dice **==tautologia==** se è sempre vera qualunque siano i valori delle variabili.
- Date 2 formule si dicono ==**equivalenti**== se hanno lo stesso valore, denotiamo questo concetto così: $P_1$ $\equiv$ $P_2$

> [!EXAMPLE]
> - $P_1$ ∧ $P_2$ è soddisfacibile
> - $P_2$ ∨ ¬$P_2$ è tautologia (Questo viene chiamato **Principio del terzo escluso**)
> - $P_2$ ∧ ¬$P_2$ è insoddisfacibile (Questo viene chiamato **Principio di non contraddizione**)
> - $P_1 ∨ P_2 ≡ P_2 ∨ P_1$ (commutativa della disgiunzione)
> - $P_1 ∨ (P_2 ∨ P_3 ) ≡ (P_1 ∨ P_2) ∨ P_3$ (associatività della disgiunzione)

---
##### Giustificazione o conseguenza logica:
Sia $P$ un insieme di proposizioni e $p$ una proposizione generica, ci chiediamo quando $P$ giustifica $p$ questa domanda la denotiamo con: $P$  |= $p$ diciamo che $P$ giustifica $p$ o viceversa se ogni interpretazione che soddisfa le formule di $P$ soddisfa anche $P$


> [!EXAMPLE]
> $P = \{ p, p \rightarrow q \}$  è un insieme fatto da 2 formule
> $P$  |= $q$
> ![[Pasted image 20241008151855.png | 500]]
> Per essere vero che $P$ giustifica $q$ tutte le formule di $P$ devono essere vere e anche $q$ deve essere vera. 
> 
> ---
> 
> $P = \{ p ∨ r, q ∨ ¬r \}$  
> $P$ |= $p ∨ q$
> 
> ![[Pasted image 20241008232946.png|500]]
> 
> Come possiamo facilmente notare P giustifica la disgiunzione $p ∨ q$ solo quando tutte le formule di $P$ e la disgiunzione stessa sono vere (attenzione ai vari casi nella tabella). 

---

**TIPS**: [[Tips#Come creare tutte le combinazioni tra le variabili senza confondersi]] 

--- 
##### Altre equivalenze logiche
- $¬(¬p) ≡ p$
- $p ⇔ q ≡ (p ⇒ q) ∧ (q ⇒ p)$ (eliminazione della doppia implicazione)
- $p ⇒ q ≡ ¬p ∨ q$ (eliminazione dell'implicazione)
- $p ∧ (q ∨ r ) ≡ (p ∧ q) ∨ (p ∧ r )$ distributività della congiunzione sulla disgiunzione
- $p ∨ (q ∧ r ) ≡ (p ∨ q) ∧ (p ∨ r )$ distributività della disgiunzione sulla congiunzione
- $¬(p ∨ q) ≡ ¬p ∧ ¬q$ ovvero, la negazione della disgiunzione è equivalente alla congiunzione delle negazioni (seconda legge di De Morgan)
- $¬(p ∧ q) ≡ ¬p ∨ ¬q$ ovvero, la negazione della congiunzione è equivalente alla disgiunzione delle negazioni (seconda legge di De Morgan)

**TIPS:** [[Tips#Come distribuire le congiunzioni sulle disgiunzioni e viceversa]]

---
##### CNF e DNF 
Molte volte formule complesse vengono standardizzate in 2 forme chiamate "normali": ^31c186
- **CNF (Forma Normale Congiuntiva)** che si basa sullo scrivere una qualsiasi formula come un AND di vari OR:
	- (p ∨ q) ∧ (¬p ∨ ¬r ∨ s)
- **DNF (Forma Normale Disgiuntiva)** che si basa sullo scrivere una qualsiasi formula come OR di vari AND:
	- (p ∧ q) ∨ (¬p ∧ ¬r ∧ s)

Una qualunque formala $P$ si può trasformare in una delle 2 forme normali sopracitate seguendo questi step:
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

> [!EXAMPLE]
> ![[Pasted image 20241012123046.png]]


---
# `Insiemi` 

Un insieme è una collezione ben definita di oggetti. 
1. Per esprimere l'**appartenenza** ad un insieme usiamo la seguente espressione: 
	- x ∈ T ($x$ è un generico elemento e $T$ è un generico insieme)
2. Per esprimere la **non appartenenza** ad un'insieme usiamo la seguente espressione:
	- $x \notin T$

Dato che un'insieme è univocamente caratterizzato dal suo contenuto, 2 insiemi si dicono **uguali** se hanno gli stessi elementi, in simboli sarebbe:
- A = B ⇔ (∀x)(x ∈ A ⇔ x ∈ B) (A è uguale a B se e solo se qualsiasi x che appartiene ad A appartiene anche a B)
  
> [!EXAMPLE] Esempio
> A = {1, 2, 3} e B = {2, 3, 1, 2, 3} sono uguali perché contengono gli stessi elementi.

---
##### Definizione di un insieme
Per specificare un'insieme è sufficiente elencarne gli elementi, in questo modo:
- T = {1,2,3} 
Più in generale possiamo specificare un'insieme esprimendo la proprietà che caratterizzano i suoi elementi. Supponiamo che $P$ sia la proprietà di essere un divisore di 100 allora: 

> [!TIP]
> $\{x: P(x)\}$ è un insieme (con questa nomenclatura indichiamo un'insieme da tutti gli elementi che rendono vera la proprietà $P$). 

Per poter esprimere un'insieme sotto questa forma la proprietà $P$ deve essere ben definita ovvero che per ogni valore di $x$, $P(x)$ può assumere solo 2 valori vero o falso 

> [!EXAMPLE] esempio con una proprietà non ben definita
> Supponiamo $P$ sia la proprietà di essere "alti", allora ${x : P(x)}$ non è un insieme.
> 
> In questo caso non parliamo di un'insieme perché la proprietà di essere alti non è una proprietà ben definita in termini matematici infatti è una nozione che può variare in base al contesto.

--- 
##### Cardinalità
Si dice **Cardinalità** il numero di elementi che costituisce un'insieme e si denota con il simbolo: $|A|$ questo potrebbe assumere anche il valore di $\infty$, ad esempio l'insieme dei numeri pari ha una cardinalità pari ad $\infty$.

---
##### Nomenclature: 
- Per indicare un'insieme costituito da un solo elemento usiamola parola **singoletto**
- Per indicare un'insieme vuoto usiamo il seguente simbolo: ∅
- Un'insieme si dice **discreto** se è possibile ordinare i suoi elementi in maniera tale che tra un qualunque elemento è il suo successivo non ci siano altri elementi.
	- N = {0, 1, 2, 3, 4, . . .} è un insieme discreto
	- Q = {$\frac{n}{m}$ : n, m ∈ Z} non è un'insieme discreto
---
##### Sottoinsieme e sovrainsieme
Se abbiamo 2 insiemi A e B, e tutti gli elementi di A appartengono a B, diciamo che A è un ***sottoinsieme*** di B e lo denotiamo così:
- A ⊆ B ⇔ (∀x)(x ∈ A ⇒ x ∈ B) A è un sottoinsieme di B se e solo se qualunque x che appartiene ad A, appartiene anche a B
facendo rifermento allo stesso caso potremmo dire che B è un ***sovrainsieme*** di A e lo denotiamo così:
- B ⊇ A ⇔ (∀x)(x ∈ A ⇒ x ∈ B) A è un sovrainsieme di B se e solo se qualunque x che appartiene ad A, appartiene anche a B

> [!DANGER]
> Attenzione alla direzione del segno

Le relazioni A ⊆ B è verificata anche nel caso A = B, se volessimo esprimere il concetto A ⊆ B ma specificando che A è diverso da B (quindi che in B ci sono elementi che in A non ci sono) scriviamo in questo modo A ⊂ B, in questo caso diciamo che A è un ***sottoinsieme proprio*** di B (tutta cosa vale anche per il sovrainsieme).

Possiamo definire un sottoinsieme definendo la proprietà che caratterizza ogni singolo elemento. Supponendo che $T$ sia un insieme, $Q$ è un sottoinsieme definito in questo modo:
- $Q$ = $\{ x : x ∈ T$ e $P(x) \}$ ogni elemento del sottoinsieme $Q$ deve appartenere sia a $T$ sia rispettare la proprietà $P(x)$
> [!EXAMPLE] Esempio di definizione di sottoinsieme 
> $T$ è l'insieme dei numeri interi positivi da 1 a 100, la proprietà $P(x)$ per essere vera un numero deve essere multiplo di 10. Allora un sottoinsieme definito cosi: { $x :$ $x ∈ T$ e $P(x)$ } sarà uguale {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}.

---
##### Operazioni tra insiemi
Le operazioni principali tra insiemi sono:
1. ***Unione*** di 2 insiemi A e B, è l'insieme formato da quegli elementi che appartengono ad almeno uno dei due. La notazione che usiamo è la seguente:
	- $A$ ∪ $B$ = {$x$ : $x ∈ A$ oppure $x ∈ B$.} $A$ unito $B$ è formato da qualsiasi $x$ che appartiene ad $A$ oppure a $B$
> [!EXAMPLE] Esempio di unione
> Se $A$ = {1, 2, 3} e $B$ = {3, 4, 5} allora $A ∪ B$ = {1, 2, 3, 4, 5}. L’elemento 3, presente in entrambi gli insiemi, è presente nell’unione una sola volta.
> 
2. ***Intersezione*** di 2 insiemi A e B, è l'insieme formato dagli elementi che appartengono ad entrambi gli insiemi. La notazione che usiamo è la seguente:
	- $A ∩ B$ = {$x$ : $x ∈ A$ e $x ∈ B$.} $A$ intersezione $B$ è formata dalle x che appartengono sia ad $A$ che a $B$
	- A ∩ B = ∅. Se l'intersezione tra 2 insiemi è vuota si dicono **disgiunti**
> [!EXAMPLE] Esempio di interesezione
> Se A = {1, 2, 3} e B = {3, 4, 5} allora A ∩ B = {3} notiamo che l’elemento 3, è l’unico presente in entrambi gli insiemi
3. ***Differenza*** di 2 insiemi, è l'insieme formato da quegli elementi del primo insieme che non appartengono al secondo insieme. La notazione che usiamo è la seguente:
	- $A \backslash B$ = {x : x ∈ A e $x \notin B$.} $A$ differenza $B$ è formato dalle $x$ che appartengono ad $A$ ma non appartengono a B
4. [[#Altre operazioni tra insiemi]]

Sia per l'unione che per l'intersezione valgono le proprietà commutativa e associativa

> [!TIP] Cardinalità delle operazioni
> La cardinalità dell’unione di due insiemi è la somma delle cardinalità meno la cardinalità dell’intersezione, ovvero: $|A ∪ B|$ = $|A|$ + $|B|$ − $|A ∩ B|$
> 
> La cardinalità della differenza tra 2 insiemi è la differenza tra la cardinalità del primo insieme e la cardinalità dell'intersezione tra i 2 insiemi, ovvero: |$A \backslash B$| = $|A|$ − $|A ∩ B|$ 

---
##### Diagramma di Venn

^2b9dff

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
	- Se $A = \{1, 2, 3\}$ e $U = \{1, 2, 3, · · · , 10\}$ allora $A^C$ = $\{4, 5, · · · , 10\}$ in $A^C$ troviamo tutti gli elementi di $A$ che non troviamo in $U$
	Questo tipo di operazione ha delle proprietà:
	1. $(A^C)^C$  = $A$ il complemento del complemento di un'insieme è l'insieme stesso
	2. $(A ∩ B)^C = A^C ∪ B^C$ De Morgan: il complemento dell'intersezione è l'unione dei complementi
	3. $(A ∩ B)^C = A^C ∪ B^C$ De Morgan: il complemento dell'unione è l'intersezione dei complementi
	La cardinalità di un complemento di un insieme si basa sulla cardinalità di U se U è finito allora |$A^2$| = |U| - |A|. 
5. ***Differenza simmetrica*** di 2 insiemi, è l'unione tra la differenza fra gli insiemi e quindi tutti quegli elementi del primo o del secondo che non appartengono ad entrambi. La notazione che usiamo è la seguente:
	- $A∆B$ = (A \ B) ∪ (B \ A).
> [!EXAMPLE] Esempio di differenza simmetrica 
> Se $A = \{1, 2, 3\}$ e $B = \{3, 4, 5\}$ allora $A∆B = \{1, 2, 4, 5\}$

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

> [!EXAMPLE] Esempio di insieme delle parti
> Sia $T$ = {1, 2, 3} allora $P(T)$ = {∅, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}

Cardinalità dell'insieme delle parti:
- Se $T$ = ∅  allora $P(T)$ = {∅}
- Se $|T|$ = 1  quindi $T$ = {a} allora $P(T)$ = { ∅ , {a} } = 2 elementi
- Se $|T|$ = 2  quindi $T$ = {a, b} allora $P(T)$ = { ∅ , {a}, {b}, {ab} } = 4 elementi
- Se $|T|$ = 3  quindi $T$ = {a, b, c} allora $P(T)$ = 8 elementi
Come possiamo ben notare la cardinalità di $P(T)$ = $2^n$ dove $n$ è il numero di elementi di T

Proprietà dell'insieme delle parti: 
- $P(A ∩ B) = P(A) ∩ P(B)$
	- Dimostrazione: Per dimostrare che è vera l'equivalenza dobbiamo dimostrare 2 casi
		1. Caso ⊂: supponendo che $X ∈ P(A ∩ B)$  e quindi che $X ⊂ A$ e $X ⊂ B$ da questo capiamo facilmente che  $X ∈ P(A)$ e $X ∈ P(B)$ e quindi che $X ∈ P(A) ∩ P(B)$
		2. Caso ⊃: supponiamo che $X ∈ P(A) ∩ P(B)$ e quindi che $X ⊆ A$ e $X ⊆ B$ quindi $X ⊆ A ∩ B$ ciò implica che $X ∈ P(A ∩ B)$
- $P(A ∪ B) ⊃ P(A) ∪ P(B)$ 
	- Dimostrazione: Per dimostrare questa formula dobbiamo dimostrare che $P(A ∪ B) ⊃ P(A) ∪ P(B)$ ma anche che un generico elemento di $P(A ∪ B)$ non appartenga a $P(A) ∪ P(B)$ 
		1. Caso ⊃: Supponiamo che $X ∈ P(A) ∪ P(B)$, allora $X ∈ P(A)$ oppure $X ∈ P(B)$.Nel primo caso $X ⊆ A$ mentre nel secondo caso $X ⊆ B$. In entrambi i casi, quindi, $X ⊆ A ∪ B$ da cui $X ∈ P(A ∪ B)$.
		2. Caso $\neq$ : Sia A = {1, 2} e B = {1, 3}. L’insieme $A ∪ B$ = {1, 2, 3} appartiene a $P(A ∪ B)$ ma non appartiene a $P(A)$ ∪ $P(B)$ ( ricordiamo che P(A) = { ∅, {1}, {2}, {1,2} }  invece P(B) = { ∅, {1}, {3}, {1,3} } ) 

> [!TIP] Famiglia di Insiemi
> Un insieme di insiemi, come ad esempio l’insieme delle parti, è anche detto ***"famiglia di insiemi"***

---
##### Diagramma di Venn di famiglie di insiemi
Data una famiglia di $n$ insiemi detta $F$, le regioni del diagramma di Venn sono $2^n$. Una famiglia di insiemi con un numero infinito di elementi è una ***famiglia infinita***. Se invece ha un numero finito di elementi allora è una ***famiglia infinita***.
- Sia $F$ = ${P, D}$ dove P è l’insieme dei numeri pari (infinito) e D è l’insieme dei numeri dispari (infinito). La famiglia F è una famiglia finita di insiemi.
- Sia $F$ = {$P_1$, $P_2$, $P_3$, . . .} dove $P_i$ = {$2^1$, · · · , $2^i$ }. La famiglia è infinita, ma tutti i suoi elementi sono insiemi finiti.
Le operazioni di unione ed intersezione si possono estendere alle famiglie infinite. 

Sia $F$ una famiglia qualunque di insiemi si indica con: $\bigcup_{ X \in F} X$  l'insieme degli elementi di $X$ che appartengono ad $F$ e viene detto insieme unione della famiglia $F$. Quindi:
- $\bigcup_{X \in \mathcal{F}} X = \{x : \exists X, X \in \mathcal{F}$ e $x \in X\}$ L'insieme unione della famiglia $F$ è uguale all'insieme di tutte le $x$ appartenenti a $X$ che rispettano la condizione che $X$ esista ed appartenga ad $F$. In pratica stiamo dicendo che l'insieme unione della famiglia $F$ è uguale all'unione tra tutti gli insiemi appartenenti a $F$ stesso e quindi da tutti gli elementi degli insiemi (ripetuti una volta sola)

> [!EXAMPLE] Esempio
> - **La famiglia di insiemi $F$:** Rappresenta tutti gli studenti di una scuola, divisi per classe. Ogni classe è un insieme di studenti.
> - **L'insieme $X$ :** Rappresenta una singola classe.
> - **L'elemento $x$ :** Rappresenta un singolo studente.
> - **L'espressione:**
> 	In questo caso significherebbe "Se prendi tutti gli studenti da tutte le classi e li metti insieme, otterrai l'insieme di tutti gli studenti della scuola."

Sia $F$ una famiglia qualunque di insiemi si indica con $\bigcap_{X \in \mathcal{F}} X$ l'insieme degli elementi che appartengono a tutti gli insiemi $X$ che appartengono ad $F$ e viene detto insieme intersezione della famiglia $F$. Quindi:
- $\bigcap_{X \in \mathcal{F}} X = \{x : \forall X \in \mathcal{F}, x \in X\}$ L'insieme intersezione della famiglia $F$ è uguale all'insieme di tutti gli elementi $x$ tali che per ogni $X$ appartenente a F, x appartiene a X. In pratica stiamo dicendo che l'insieme intersezione della famiglia F è uguale all'intersezione tra tutti gli insiemi appartenenti a F stesso e quindi avremo come risultato un insieme fatto dagli elementi comuni a tutti gli insiemi.

---
##### Insiemi chiusi
Sia dato un insieme $U$ ed un operazione, se quest'ultima può essere definita o completata in $U$ allora possiamo dire che $U$ e chiuso rispetto a quell'operazione
- Sia $U = \mathbb{N}$ e l'operazione che consideriamo è la somma, allora possiamo dire che U è un'insieme chiuso rispetto alla somma (la somma di 2 qualsiasi valori ci da un valore positivo e quindi che appartiene a $\mathbb{N}$)
-  Sia $U = \mathbb{N}$ e l'operazione che consideriamo è la sottrazione, allora possiamo dire che U **non** è un'insieme chiuso rispetto alla sottrazione (la sottrazione di 2 qualsiasi valori ci potrebbe dare un valore negativo che non appartiene $\mathbb{N}$)

---
###### Chiusura rispetto all'unione ed intersezione
Sia $F$ una famiglia di insiemi
- diciamo che $F$  è chiusa rispetto all’unione se per ogni coppia di insiemi $X$ e $Y$ appartenenti a $F$ anche $X ∪ Y$ appartiene a $F$.
- diciamo che $F$ è chiusa rispetto all’intersezione se per ogni coppia di insiemi $X$ e $Y$ appartenenti a $F$ anche $X ∩ Y$ appartiene a $F$.

> [!EXAMPLE] Esempio di chiusura rispetto all'unione 
> Sia $F = \{ \{1, 2, 3\}, \{1, 2\}, \{1, 3\} \}$ abbiamo che $F$ è chiuso rispetto all’unione ma non è chiuso rispetto all’intersezione, perché $\{1, 2\} ∩ \{1, 3\} = \{1\}$ che non appartiene ad F.

Considerando $F$ una famiglia di insiemi composta da sottoinsiemi di un insieme universo detto $U$, possiamo dire che per ogni X ∈ $F$ il complemento di $X$ rispetto ad $U$ ovvero $X^C = U \backslash X$ appartiene ad a $pow(U)$. Quindi possiamo dire che $F^C$ è una famiglia di insiemi dove ogni insieme viene complementato rispetto ad $U$ 

> [!EXAMPLE] Esempio di famiglia complemento
> - $U$ = {1, 2, 3}
> - $pow(U)$ = $\{\emptyset, \{1\}, \{2\}, \{3\}, \{1, 2\}, \{1, 3\}, \{2, 3\}, \{1, 2, 3\}\}$
> - $F$ = $\{\{1\}, \{2, 3\}, \{1, 2\}\}$
> - $F^C$ = $\{ \{2,3\}, \{1\}, \{3\} \}$

la famiglia complemento viene definita cosi:
- $F^C$ = {$X^C$ : $X$ ∈ $F$ } 
ovvero come l'insieme di tutti le $X$ ∈ $F$ però complementato.

**Teoremi**:
- La famiglia $F$ è chiusa rispetto all’unione se e solo se la famiglia $F^C$ è chiusa rispetto all’intersezione.
- La famiglia $F$ è chiusa rispetto all’intersezione se e solo se la famiglia $F^C$ è chiusa rispetto all’unione.
![[Pasted image 20241019115203.png]]

Sia data:
- $F$ una famiglia finita di insiemi su un insieme $U$
- * una generica operazione sull'insieme

***Definiamo chiusura di $F$ rispetto ad * la più piccola famiglia $F^{*}$ che contiene $F$ ed è chiusa rispetto a * .***

> [!EXAMPLE] Esempio
> sia data $F$ = $\{\{1, 2, 3\}, \{1, 2\}, \{1, 3\}, \{2, 4\}\}$ ovvero famiglia non chiusa rispetto all'operazione di unione. La famiglia più piccola che contiene $F$ ed è chiusa rispetto all'operazione di unione è la famiglia $F^I$ = $\{\{1, 2, 3\}, \{1, 2\}, \{1, 3\}, \{2, 4\}, \{1, 2, 3, 4\}, \{1, 2, 4\}\}$ 

[[Tips#Come calcolare la chiusura di una famiglia rispetto ad unione/intersezione]] 

---
##### Partizioni
Una famiglia di insiemi $F$ formata da sottoinsiemi dell'insieme universo $U$ può essere chiamata anche partizione di $U$ 


> [!EXAMPLE] Esempio di partizione
> Sia $U$ = $\{1,2,3,4,5,6,7,8,9,10,11,12\}$ 
> $F$ = $\{ \{1, 3, 5, 7, 8, 10, 12\}, \{2\}, \{4, 6, 9, 11\} \}$, 
> $F$ è una partizione di $U$


---
##### Coppie ordinate
Consideriamo 2 elementi $x$ e $y$. Creiamo una coppia ordinata dove il primo elemento è $x$ ed il secondo elemento è $y$. Denotiamo tale coppia con $(x, y)$.
- la coppia $(x, y)$ è diversa dalla coppia $(y, x)$ (a meno che $x = y$).
- $(x, y)$ = $(x′, y′)$ se e solo se $x = x′$ e $y = y′$
  
> [!DANGER]
> la coppia $(x, y)$ è diversa dall’insieme $\{x, y\}$ costituito dagli elementi $x$ e $y$

----
##### Insieme prodotto
Dati 2 insiemi non vuoti $A$ e $B$, l'insieme prodotto da $A$ per $B$ (che indichiamo con $A × B$) è l'insieme di tutte le coppie ordinate $(x, y)$ con $x ∈ A$ e $y ∈ B$
- A × B = $\{(x, y) : x ∈ A$ e $y ∈ B\}$ $A×B$ è l'insieme di tutte le coppie $(x, y)$ con $x$ che appartiene ad $A$ e $y$ che appartiene a $B$

> [!EXAMPLE] Esempio di insieme prodotto
> Un'esempio di questo prodotto è il piano cartesiano che definiamo come $\mathfrak{R} \times \mathfrak{R}$ che è un insieme formato da tutte le coppie ordinate di numeri reali.
>  ![[Pasted image 20241019143758.png]]
> Dati, in un certo ordine, tre insiemi $A$, $B$, $C$, si chiama loro prodotto, e si indica con $A × B × C$ l’insieme di tutte le terne ordinate $(x, y, z)$ con $x ∈ A$, $y ∈ B$, $z ∈ C$.

---
##### Paradosso di Russell
Partendo dal concetto di insieme, possiamo benissimo costruire un insieme formato da tutti quegli elementi che non appartengono a se stessi e lo definiamo in questo modo:
- $S = \{A {:} A \text{ è un insieme, e } A \notin A\}$  $S$ è l'insieme di tutti gli insiemi che non appartengono a se stessi. Per esempio, l'insieme di tutti i frutti non è un frutto, quindi potrebbe appartenere a $S$.
Usando questa definizione $S ∈ S$?
- **Se diciamo SI:** Se $S$ appartiene a se stesso, allora per definizione di S, S non dovrebbe appartenere a se stesso (perché S contiene solo insiemi che non appartengono a se stessi). Questo è una contraddizione.
- **Se diciamo NO:** Se $S$ non appartiene a se stesso, allora per definizione di $S$, $S$ dovrebbe appartenere a se stesso (perché $S$ contiene tutti gli insiemi che non appartengono a se stessi). Anche in questo caso abbiamo una contraddizione.
Evitiamo questa contraddizione imponendo nella definizione dell'insieme che quest'ultimo deve essere sottoinsieme di un'insieme conosciuto, la nuova definizione di $S$ diventa: $S = \{A \mid A \subseteq U, A \notin A\}$ 
Con questa nuova definizione, il paradosso svanisce. Se proviamo a chiedere se $S$ appartiene a se stesso, ci rendiamo conto che $S$ è un sottoinsieme di $U$, ma non possiamo dire con certezza se $S$ appartiene o meno a $U$. In questo modo, evitiamo il circolo vizioso che portava alla contraddizione.
 
---

# `Relazioni e funzioni`

##### Relazioni
Sia $U$ un insieme non vuoto. Con il termine relazione indichiamo un insieme formato in questo modo:
- $R ⊆ U × U$ ovvero $\{(x, y) \in U \times U : R(x, y)\}$ cioè un insieme formato da tutte le coppie che rendono vera la relazione, questo insieme viene chiamato ***grafico della relazione***

> [!EXAMPLE] Esempio
> Considera l'insieme U = {1, 2, 3}. Una possibile relazione R su U potrebbe essere "è minore di". In questo caso, il grafico di R sarebbe {(1, 2), (1, 3), (2, 3)}, perché 1 è minore di 2 e 3, e 2 è minore di 3, questi sono gli unici 3 casi che rendono vera la relazione "è minore di".

Qui le [[#Proprietà delle relazioni]]

---
##### Funzioni
Una relazione $f$ definita su $A × B$ si dice funzione da $A$ (dominio) in $B$ (codominio) se per ogni $x ∈ A$ esiste uno ed uno solo $y ∈ B$ tale che $(x, y) ∈ f$.  La notazione classica per esprimere la funzione $f$ è:  $f : A → B$ dove $f(x)$ rappresenta l'unico elemento $y \in B$ associato a $x \in A$ tale che $(x,y) \in f$ 
 
###### Casi particolari:
- $f : A → B$  per ogni $x$, $f(x) = x$ si dice **applicazione identica** di $A$ ^a112e2
- $f : A × B → A$ tale che per ogni $(x, y)$ $f(x, y)$ = $x$ si dice **proiezione canonica** su $A$.
- $f : A × B → B$ tale che per ogni $(x, y)$ $f(x, y)$ = $y$ si dice **proiezione canonica** su $B$.

Data una funzione $f: A \to B$ e un sottoinsieme $X \subseteq A$, si definisce **immagine di $X$** il sottoinsieme di $B$ formato da tutti gli elementi di $B$ che sono immagini di almeno un elemento di $X$ attraverso $f$. L'immagine di $X$ si indica con $f(X)$ ed è definita formalmente come:  $f(X) = \{ y \in B \;|\; \exists x \in X \; \text{tale che} \; f(x) = y \}.$ $f(X)$ è l'insieme di tutti gli $y \in B$ per cui esiste almeno un $x \in X$ tale che $f(x) = y$.

Inoltre, l'insieme $f(A)$, cioè l'immagine dell'intero dominio $A$, è chiamato **immagine dell'applicazione $f$**. Questo insieme rappresenta tutti i valori che la funzione può assumere e si scrive come:  $f(A) = \{ y \in B \;|\; \exists x \in A \; \text{tale che} \; f(x) = y \}.$


---
###### Funzione iniettiva:
Data un'applicazione $f$: $A$ → $B$ se porta punti distinti del dominio su su punti distinti del codominio la funzione si dice ***iniettiva*** formalmente la definiamo così: ^ccc2e0
- $\forall x, y \in A, \text{ se } x \neq y, \text{ allora } f(x) \neq f(y).$ Per tutti x e y appartenenti ad A se x è diverso da y allora f(x) è diverso da f(y). 
Questo tipo di funzione viene definita funzione "uno a uno", appunto perché associa ad ogni elemento di B(codominio) **soltanto** un elemento di A(dominio).  $|A|\le|B|$

> [!EXAMPLE] Esempio
> ![[Pasted image 20241020160345.png]]
> - $X$ è l'insieme delle $x$ del piano cartesiano e corrisponde al dominio 
> - $Y$ è l'insieme delle $y$ del piano cartesiano e corrisponde al codominio
> - ***nel primo grafico ad ogni valore di $Y$*** ***posso sempre associare un solo elemento di $X$*** ***e quindi è iniettiva, nel secondo invece ad ogni valore di $Y$ posso associare più elementi di $X$***

---
###### Funzione surgettiva
Data un'applicazione $f$: $A$ → $B$ se l'immagine $f(A)$ $=$ $B$ la funzione si dice ***surgettiva*** ovvero un funzione che associa ad ogni elemento di B (codominio) **almeno** un'elemento di A(dominio). $|A|\ge|B|$^cc7f98
> [!EXAMPLE] Esempio
> Esempio:![[Pasted image 20241020161146.png]]
> - $X$ è l'insieme delle $x$ del piano cartesiano e corrisponde al dominio
> - $Y$ è l'insieme delle $y$ del piano cartesiano e corrisponde al codominio
>  - ***nel primo grafico ad ogni valore di $Y$ posso associare almeno un elemento di $X$, nel secondo grafico invece ad ogni valore di $Y$ non posso associare un valore di $X$ (dove c'è la linea rossa non posso associare $Y$ a nessuna $X$)***.


> [!TIP] Nota bene
> 1. Una ***funzione iniettiva*** può avere elementi del codominio che non vengono raggiunti.
> 2. Una ***funzione suriettiva***, invece, raggiunge tutti gli elementi del codominio.

---
###### Funzione biiettiva
Data un'applicazione $f$: $A$ → $B$ si dice *==biiettiva==* se è sia iniettiva che surgettiva. Questo tipo di funzione associa sempre ogni elemento di A ad ogni elemento di B

> [!EXAMPLE] Esempio
>   
> ![[Pasted image 20241020164744.png]]
> - $X$ è l'insieme delle $x$ del piano cartesiano corrisponde al dominio
> - $Y$ è l'insieme delle $y$ del piano cartesiano corrisponde al codominio
> - ad ogni elemento di $X$ posso associare soltanto un elemento di $Y$ sempre
> 


> [!TIP] Corrispondenza biunivoca
> La **corrispondenza biunivoca** è una relazione tra due insiemi che stabilisce un legame univoco tra gli elementi di un insieme e quelli di un altro. In termini formali, una corrispondenza biunivoca è una funzione **biiettiva** (o biezione).

---
###### Cardinalità di un insieme

La cardinalità di un insieme è definita come il numero di elementi che appartengono all'insieme, per riuscire a contare questi elementi si cerca una corrispondenza biunivoca tra l'insieme e un insieme "campione" fatto da numeri naturali detto $l_n$ ovvero l'insieme dei numeri naturali interi che precedono $n$ ( es: $\{0, 1, 2, · · · , n − 1\}$ ), infatti:
- ***Insieme finito***: si dice che un insieme $X$ è finito se esiste un $n ∈ N$ tale che $X$ si possa mettere in corrispondenza biunivoca con $I_n$ ; 
- ***Insieme infinito***: Se non esiste un numero naturale $n$ tale da costruire un insieme $l_n$ grande quanto $X$, l'insieme è infinito.

***Teorema***: Se $A$ e $B$ sono due insiemi finiti ed esiste una funzione **iniettiva** $f:A→B$, allora la cardinalità di $A$ è minore o uguale alla cardinalità di $B$, cioè $∣A∣≤∣B∣$ 

***Dimostrazione***:  Si considera l'immagine $f(A)$, cioè l'insieme di elementi di $B$ a cui $A$ viene mappato. Poiché $f$ è iniettiva, ogni elemento di $A$ corrisponde a un elemento unico di $f(A)$, quindi $∣A∣=∣f(A)∣$. Tuttavia, $f(A)$ è un sottoinsieme di $B$ (cioè tutti gli elementi di $f(A)$ appartengono a $B$), quindi $∣f(A)∣≤∣B∣$. Da qui segue che $∣A∣≤∣B∣$. (Ricordiamo che essendo iniettiva la funzione non garantisce che tutti gli elementi di B(codominio) hanno un immagine in A(dominio))

---
##### Proprietà delle relazioni
Sia dato un insieme $U$ diremo che una relazione $R(x, y)$ definita in $U×U$ è:
- ***Riflessiva***: se $∀x∈U$ risulta vero che $R(x, x)$.
> [!EXAMPLE] Esempi
> R = { (1,1), (2,2) } è riflessivo
> R = { (1,1), (2,2), (1,3) } non è riflessivo
- ***Simmetrica***: se $∀x, y ∈ U$ risulta vero che $R(x, y)$ e anche $R(y, x)$ 
> [!EXAMPLE] Esempi
> R = {(1,2),(2,1)} è simmetrico
> R = {(1,2),(2,1),(1,3)} non è simmetrico
- ***Transitiva***: se $∀x,y,z ∈ U$ risulta vero che $R(x, y)$ e $R(y, z)$ allora ci deve essere anche una $R(x, z)$ 
> [!EXAMPLE] Esempio fatto durante l'esercitazione
> ![[Pasted image 20241023101548.png]]

> [!TIP] Relazione di equivalenza
> Una relazione che è sia riflessiva, simmetrica e transitiva si dice relazione di ***equivalenza***. Più in generale una **relazione di equivalenza** è una relazione tra elementi di un insieme che li "raggruppa" in base a certe proprietà comuni. Si indica in questo modo:
> - $x ≈ y$ 

^927242
###### Classe di equivalenza
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
    - Il ragionamento è lo stesso ma invertendo $x$ e $z$
4. **Conclusione**:
    - Se $[x] ⊆ [z]$ e $[z] ⊆ [x]$, allora $[x] = [z]$
    - Questo dimostra che **se** due classi di equivalenza non sono disgiunte (cioè hanno un elemento in comune), allora devono necessariamente coincidere. In altre parole, non possono "sovrapporsi parzialmente" o non hanno elementi in comune (sono disgiunte) o sono esattamente le stesse (coincidono).

Data una relazione $R$ su un insieme $U$, consideriamo ora la famiglia di insiemi $F$ formata da tutte le classi di equivalenza create dalla relazione $R$ su $U$. $F$ è un sottoinsieme di [[#Insieme delle parti|pow]](U) tale che:
- L'unione di tutte le classi di equivalenza che appartengono ad $F$ ci da $U$
- per ogni X , Y ∈ F, X $\neq$ Y si ha X ∩ Y = ∅ (vedi teorema precedente)
Quindi, una relazione di equivalenza $R$ individua una partizione $F$ su $U$ che viene detta ***Insieme Quoziente*** e lo denotiamo con $U/R$ 

> [!EXAMPLE] Esempio 
> Immagina U come l'insieme dei numeri interi e R come la relazione "avere lo stesso resto nella divisione per 3" :
> $[0]$ = $\{…, -3, 0, 3, 6, …\}$
> $[1]$ = $\{…, -2, 1, 4, 7, …\}$
> $[2]$ = $\{…, -1, 2, 5, 8, …\}$ 

Queste tre classi formano una partizione di $U$ ovvero $F$, che si può anche chiamare ***Insieme quoziente di U***. Quindi capiamo subito che 
- $F = U/R$

Individuato l'insieme quoziente (che denotiamo con $U/R$), l'applicazione $U → U/R$, ovvero un'applicazione che associa ogni $x ∈ U$ alla sua classe di equivalenza. Questa è un'applicazione surgettiva perché ogni classe di equivalenza è effettivamente "raggiunta" da almeno un elemento di $U$. Questa applicazione viene anche chiamata ***applicazione canonica sul quoziente***. 

> [!TIP] Nota bene
> [[Tips#Differenza tra applicazione e funzione]] 
> Nel contesto specifico dell'**applicazione canonica sul quoziente**, si parla di **applicazione** perché si vuole mettere in evidenza il fatto che stiamo "applicando" una trasformazione sugli elementi dell'insieme $U$. In particolare, stiamo usando una regola (la relazione di equivalenza) per trasformare ogni elemento x di $U$ nella sua **classe di equivalenza** $[x]$.

Di seguito delle definizioni:

1. Si dice che una relazione binaria sia ***antisimmetrica*** se:
	- $∀x, ∀y ∈ U$ si ha che: $(R(x, y)$ e $R(y, x)) → x = y$. il sussistere di entrambe le relazioni $R(x, y)$ e $R(y, x)$ è possibile solo quando $x$ e $y$ coincidono.
2. Si dice ***preordinamento*** una relazione binaria assegnata in un insieme che goda della proprietà riflessiva e transitiva. Un insieme $U$ su cui è definita un relazione di pre-ordine si dice pre-ordinato. 
3. Si dice ***ordinata*** una relazione binaria assegnata in un insieme che goda della proprietà riflessiva, transitiva e antisimmetrica. Un insieme $U$ su cui è definita un relazione d’ordine si dice ordinato.

Dato un pre-ordinamento oppure un ordinamento (rappresentato dal simbolo ≤) in un insieme U, si pone
- $x < y \quad \text{se} \quad x \leq y \quad \text{e} \quad x \neq y$  ovvero x è minore di y, se x è minore/uguale a y però con x diverso da y

Un ordinamento $≤$ definito in un insieme $U$ si dice **totale o lineare** se per ogni coppia $(x, y)$ di elementi di $U$ si ha $x ≤ y$ oppure $y ≤ x$. Altrimenti si dirà parziale.

---
###### Massimi e minimi
- Un elemento $M$ di un insieme ordinato $U$ si dice ***massimo*** se per ogni $x ∈ U$ si ha $x ≤ M$
- Si dice invece ***massimale*** se non vi è alcun elemento di U che lo supera.
- Un elemento m di un insieme ordinato U si dice ***minimo*** se per ogni $x ∈ U$ si ha $m ≤ x$. 
- Si dice invece ***minimale*** se non vi è alcun elemento di U ad esso inferiore

Il massimo (minimo) in un insieme è unico, il massimale (minimale) invece si può riscontrare più volte, questo accade perché potrebbe succedere che due elementi non siano confrontabili tra loro e quindi sono dei massimali.

Sia $A \subseteq \mathbb{N}$ quindi $c(A) = n$ dal momento che A è finito, possiamo dire che A ⊆ $I_m$ per qualche intero $m$. con $I_m$ intendiamo un insieme fatto cosi {0,1,2, … , m-1}. Esistono diversi modi per rappresentare A ⊆ $I_m$
- ***Rappresentazione binaria***: la struttura dati più semplice che potremmo usare è un'array fatto da valori binari
	- $X[i]$ = 1 se $i ∈ A$
	- $X[i]$ = 0 se $i \notin A$
  per ogni $i \in I_m$
- ***Rappresentazione estesa***: si può anche usare un'array di interi Y con $|A| = n$ elementi tale che se $A = \{x_0, x_1, . . . , x_{n-1}\}$ allora per ogni $0 ≤ i ≤ n − 1$ $Y[i]$ = $x_i$ 

Se utilizziamo la rappresentazione binaria, verificare che un elemento i ∈ A prende tempo costante. Se utilizziamo la rappresentazione estesa, invece, ed A non è ordinato, dobbiamo scorrere tutta l’array e quindi tempo lineare. Se l’array è ordinata invece si può fare in tempo logaritmico. D’altro canto, se utilizziamo la rappresentazione binaria, per l’insieme A = {10, 3, 99} serve un’array di dimensione 100, mentre, se utilizziamo la rappresentazione estesa, serve un’array di dimensione 3.

Se prendiamo $U$ ovvero {0, 1, 2, . . . , n − 1}  gli elementi di $pow(U)$ sono i numeri binari esprimibili con $|U|$ bits. Quindi $2^{|U|}$.

---
# `Il problema dell’Hitting Set`

Siano $U$ un insieme finito, $H ⊆ U$, e sia $A$ una famiglia di sottoinsiemi di U tutti diversi dall’insieme vuoto. Diciamo che $H$ è un hitting set ($HS$) per $A$ se e solo se per ogni $A ∈ A$ si ha $A ∩ H$ $\neq$ ∅

> [!EXAMPLE] Esempio
> Sia $U$ = {a, b, c, d, e} e sia A = {{a, b, c, }, {a, d, e}, {b, c, d, }, {c, d, e}}. 
> L’insieme {a, b, c} è un $HS$ per $A$ mentre {b, c} o {d, e} non lo sono.
> - **{a, b, c} è un hitting set** perché:
>     - Contiene 'a', che è presente anche in {a, d, e}.
>     - Contiene 'b', che è presente anche in {b, c, d}.
>     - Contiene 'c', che è presente anche in {c, d, e}.
>     - In altre parole, questa scatola più piccola "colpisce" (interseca) tutte le altre scatole.
> - **{b, c} e {d, e} non sono hitting set** perché:
> 	- **{b, c}** non contiene alcun elemento presente in {a, d, e}.
> 	- **{d, e}** non contiene alcun elemento presente in {a, b, c}.

Possono esistere diversi hitting set dentro un'insieme, si definisce **hitting set minimo** l'hitting set con meno elementi, nell'esempio un hitting set minimo sarebbe {a, c} visto che contiene almeno un elemento di ogni insieme contenuto in $A$

Il problema di trovare un $HS$ minimo per una famiglia di insiemi è facilmente risolvibile: basta provare per tutti i sottoinsiemi di $U$. Questo però vorrebbe dire che il numero di operazioni da fare è esponenziale visto che i sottoinsiemi non vuoti di $U$ sono esattamente $2|U| − 1$
- Per |U| = 100 il numero totale di operazioni sarebbe dell’ordine di 1, 26 · $10^{30}$ 
Esiste un modo migliore? ***non si sa!***
L'unico modo per cercare di risolvere questo tipo di problematiche è usare degli algoritmi detti greedy ciò vuol dire nello specifico, che potremmo prendere l’elemento $x_1$ di U che appartiene al maggior numero di elementi di $A$ Poi, per tutti gli elementi di $A$ a cui $x_1$ non appartiene, scegliamo l’elemento $x_2$ che appartiene alla maggior parte di essi, e così via.