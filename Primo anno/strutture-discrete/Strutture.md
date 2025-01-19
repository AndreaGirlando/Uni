## `Logica proposizionale`

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
## `Insiemi` 

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

## `Relazioni e funzioni`

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
## `Il problema dell’Hitting Set`

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

### 02_Parte2


Questo file è la rielaborazione delle slide [[02_Parte2.pdf]]
## `Numeri interi`
![[Pasted image 20241026111409.png]]

Sull'insieme N sono definite 2 operazione:
- **Somma**: operazione che ad ogni coppia di numeri $(n, m)$ associa il numero $n+m ∈ N$
- **Prodotto**: operazione che ad ogni coppia di numeri $(n,m)$ associa il numero $n*m ∈ N$
Sull'insieme Z sono definite 3 operazioni:
- **Somma e prodotto** come definite per N
- **Differenza**: operazione che ad ogni coppia di numeri $(n,m)$ associa il numero $n-m$ ∈ Z
- In Z definiamo anche il **valore assoluto** in questo modo
$|n| = \begin{cases} n & \text{se } n \geq 0 \\ -n & \text{se } n < 0 \end{cases}$
Giuseppe Peano dà una definizione dell'insieme dei numeri naturali in questo modo:
- Esiste un numero naturale 0
- Ogni numero naturale $a$ ha un numero naturale successore denotato come $S(a)$
- Non esiste un numero naturale il cui successore è 0
- Numeri naturali distinti hanno successori distinti

Introducendo la funzione successore (***S(a)***) è possibile definire una relazione di ordinamento sui numeri naturali, questo viene chiamato **assioma del buon ordinamento** infatti in un generico insieme S esiste un elemento minimo ovvero esiste un elemento s ∈ S tale che s ≤ t per ogni t ∈ S.

Ricordiamo:
- le proprietà fondamentali della somma sono Commutatività, Associatività e Elemento neutro
- le proprietà fondamentali del prodotto sono Commutatività, Associatività, Distributività, Elemento neutro e Elemento zero
- inoltre il calcolo avviene rispettando le priorità degli operatori

---
###### Principio di induzione

Peano introduce anche il _**Principio di Induzione**_, che afferma: se una proprietà $P$ è valida per il numero $0$ e, ogni volta che è valida per un numero naturale, lo è anche per il suo successore, allora $P$ è valida per tutti i numeri naturali.
![[Pasted image 20241026114516.png]]

[[Esempio principio di induzione.pdf]]

---
###### Floor e Ceiling

Sia x un numero reale, definiamo i 2 seguenti valori:
- "Floor": il più grande numero intero minore o uguale ad x
	- ![[Pasted image 20241026115046.png]]
- "Ceiling": il più piccolo numero intero maggiore o uguale ad x
	- ![[Pasted image 20241026115057.png]]

> [!EXAMPLE] Esempi
> ![[Pasted image 20241026115109.png]]

---
##### Divisione tra interi
Dati due interi $a, b ∈ Z$, chiamati rispettivamente dividendo e divisore, esistono unici due interi relativi $q, r$, denominati rispettivamente quoziente e resto, tali che $a = q · b + r$ con $0 ≤ r < |b|$.

> [!Legenda]
> a = dividendo
> b = divisore
> q = quoziente
> r = resto

In questo tipo di divisione noi abbiamo 4 casi:
- Nel primo caso assumiamo che il dividendo a ed il divisore b siano entrambi non negativi
	- É sempre possibile trovare un unico quoziente $q$ e un unico resto $r$ tali che:
		- $a = qb + r$
		- $q = \frac{a}{b}$ come risultato prendo solo la parte intera
		- ***$r = a + qb$***
		- $0 <= r < b$
> [!EXAMPLE] Esempio
> $a = 1$, $b = 10$:  $q = \frac{1}{10} = 0$ e $r = \frac{1}{10} \times 10 = 1$ quindi 1 mod 10 = 1
- Nel secondo caso assumiamo che il dividendo a sia negativo ma il divisore b positivo
	- Assumiamo allora che $a<0$ mentre $b>0$, chiameremo $q'$ e $r'$ i risultati del primo caso da cui otteniamo:
		- $a = (-q')b + (-r')$
		- $q = -q' - 1$
		- ***$r = b - r'$***
> [!EXAMPLE] Esempio
> $a = -1$, $b = 10$: per $a = 1$ abbiamo $q' = 0$ e $r' = 1$ e quindi per a = -1 abbiamo $q' = -1$ e $r' = 10 - 1 = 9$ quindi -1 mod 10 = 9
- Nel terzo caso assumiamo che il dividendo a sia positivo e il divisore b negativo
	- Assumiamo allora che $a > 0$  e $b < 0$, chiameremo $q'$ e $r'$ i risultati del primo caso da cui otteniamo:
		- $a = (-q')b + (-r')$
		- $q = -q'$
		- ***$r = r'$***
> [!EXAMPLE] Esempio
> $a = 1$, $b = -10$: per $b = 10$ abbiamo $q' = 0$ e $r' = 1$ e quindi per b = -10 abbiamo $q' = 0$ e $r' = 1$ quindi 1 mod -10 = 1
- Nel quarto caso assumiamo che il dividendo a ed il divisore b siano entrambi negativi
	- Adesso assumiamo che $a < 0$ e $b < 0$, chiameremo $q'$ e $r'$ i risultati del primo caso da cui otteniamo:
		- $a = (q'+1)b -b -r'$
		- $q = -q'+1$
		- ***$r = -b -r'$***
> [!EXAMPLE] Esempio
> $a = -1$, $b = -10$: per $a = 1$ e $b = 10$ abbiamo $q' = 0$ e $r' = 1$ e quindi per $a = -1$ e $b = -10$ abbiamo $q' = 1$ e $r' = 10 - 1 = 9$ quindi -1 mod -10 = 9


> [!SUMMARY] Sommario
> Riepilogando, dati due interi $a, b ∈ Z$ con $b \neq 0$, per trovare quoziente e resto positivo della divisione $\frac{|a|}{|b|}$ agiamo così:
> - Troviamo il $q′$= $\frac{|a|}{|b|}$ ovvero il massimo intero $q′$ tale che $|a| − q′|b| ≥ 0$ e fissiamo $r′ = |a| − q′|b|$
> - Se sia $a$ che $b$ sono **positivi** poniamo $q = q′$ e $r = r ′$.
> - Se $a$ è **negativo** e $b$ **positivo** poniamo $q = −q′ − 1$ e $r = b − r ′$.
> - Se $a$ è **positivo**  e $b$ **negativo** poniamo $q = −q′$ e $r = r ′$.
> - Se sia $a$ che $b$ sono **negativi** poniamo $q = q′ + 1$ e $r = −b − r ′$.

---
###### Definizione di divisibilità
Dati 2 interi relativi $n,m \in Z$ si dice che m è un divisore di n se esiste un intero relativo $k \in Z$ tale che n = $k*m.$ In altre parole m è un divisore di n se $n$ mod $m$ è uguale a 0, in tal caso useremo la notazione $m|n$. Se m non è un divisore di n quindi $n$ mod $m$ è diverso da 0 usiamo la notazione $m \nmid n$
- un numero $m | 2$ si dice **pari**
- un numero $m \nmid 2$ si dice **dispari**
visto che il resto della sua divisione per 2 è uguale ad 1 esiste un intero k tale che
- $n = 2k+1$
---
###### Dimostrazione per induzione che la somma dei primi n numeri dispari è $n^2$
- **Caso base**: n = 1 e la somma in questo caso è proprio $1 = 1^2$
- **Caso induttivo**: Assumendo che la somma dei primi n-1 numeri dispari è uguale a $(n-1)^2$ e un generico numero dispari è definito con: $n = 2k+1$, quindi se aggiungiamo a  $(n-1)^2$ il numero dispari successivo quindi $2(n-1)+1$ otteniamo:
- $(n-1)^2 + 2(n-1)+1 = n^2-2n+1+2n - 2 + 1 = n^2$

> [!EXAMPLE] Esempio
>
> $n = 5$
> $n^2 = 5^2 = 25$
> $(5-1)^2 + 2(n-1) + 1 = 16 + 9 = 25$

---
###### Proprietà della divisibilità
- **Somma**: Se $a|b$ e $a|c$ allora $a | (b+c)$
- **Prodotto**: Se $a|b$ allora $a | bc$.
- **Transitività**: Se $a|b$ e $b|c$ allora $a|c$
![[Pasted image 20241101091611.png]]
- **Quadrato**: Se $a|b$ allora $a|b^2$
	- ***Dimostrazione***: Dato che $a|b$ esiste $x$ tale che $b = ax$, quindi $bc = axc$ questi dimostra che $a | b*b$
- **Combinazione lineare**: Se $a|b$ e $a|c$ allora $a | (hb + kc)$ per ogni $h,k \in Z$
	- **Dimostrazione**: Se $a | b$ allora $a | hb$, se $a | c$ allora $a | kc$ ovviamente valgono per ogni $h,k \in Z$ e quindi è vero che $a | (hb + kc)$
- **Proprietà del numero 0**: Ogni $a \in Z$ è divisore di $0$
	- **Dimostrazione**: $a \in Z$ abbiamo che $a * 0 = 0$ quindi $a | 0$
- **Antisimmetrica**: Siano $a,b \in Z$ se $a | b$ e $b|a$ allora $|a| = |b|$ ossia $a = \pm b$
	- Dalle ipotesi abbiamo che $b = ax$ e $a = by$. Quindi $a = axy$, raccogliendo a arriviamo ad $a(xy - 1)$ questo implica che $a$ sia $0$ oppure che $xy = 1$ da questo capiamo che:
		- Se $a = 0$ allora anche $b = 0$ (perché b = 0x)
		- Se $xy = 1$ allora $a$ o $b$ sono uguali a $\pm 1$
- **Divisori banali**: Siano a $\in$ Z allora $\pm a | a$  e $\pm 1 | a$
	- Avendo che $a=a⋅1$ oppure che $a=(−a)⋅(−1)$ possiamo affermare che $\pm a | a$
		- Seguendo la definizione capiamo che $a = b ⋅ k$ in questo caso $b = \pm a$ il k che soddisfa le nostre equazioni è k = 1
	- Avendo che $a = 1 * a$ possiamo dire che 1 è sempre un divisore di $a$
---
##### Minimo Comune Multiplo (MCM)
Dati $a,b \in Z$ si chiama minimo comune multiplo fra a e b un terzo intero positivo m che è il più piccolo multiplo sia di $a$ che di $b$, quindi possiamo affermare che $a|m$ e $b|m$

---
##### Massimo Comune Divisore (MCD)
Dati $a,b \in Z$ si chiama Massimo Comune Divisore un terzo intero $d \in Z$ tale che $d|a$ e $d|b$ cioè $d$ è il più grande divisore comune tra $a$ e $b$.

---
###### Algoritmo di Euclide
Il metodo migliore per calcolare il massimo comune divisore è l'algoritmo di Euclide, che si basa su questa osservazione siano $a,b \in N$ e sia $b \le a$. Si basa sulla seguente osservazione matematica, che dimostriamo per induzione:
- **Caso base**:
  se b = 0 allora il $MCD(a,b) = a$. Questo perché qualsiasi numero è divisibile per sé stesso.
- **Passo induttivo**: 
  Supponiamo che $a=qb+ra$ , dove $q$ è il quoziente intero della divisione di $a$ per $b$, e $r$ è il resto, con $0≤r<b$  allora $MCD(a,b)$ = $MCD(b,r)$
  
Se $b|a$ allora la formula si riduce ad $a = qb$ ($q$ sarebbe $\dfrac{a}{b}$) avendo resto $0$ il calcolo del $MCD$ diventa $MCD(a,b)$ = $MCD(b,0)$ = $b$.

**Dimostrazione:**
Di seguito la dimostrazione che $MCD(a,b)$ = $MCD(b,r)$
- Se $d$ è un divisore di $a$ e $b$ allora esistono $h$ e $k$ tali che $d$ sia un divisore di $r$ (la formula base per calcolare $r$ è $r = a - qb$ )
	- $a = hd$
	- $b = kd$
	- $r = hd - qkd = d(h - qk)$ (essendo che r può essere scritto come $d$ moltiplicato per un intero allora è vero che $d$ è un divisore di $r$ [[#Definizione di divisibilità]])
- Se invece $d$ è un divisore di $b$ e di $r$ allora esistono $h$ e $k$ tali che $a$ è un divisore di $m$ (ricordiamo che la formula base per calcolare $a$ è $a = qb +r$):
	- $b = kd$
	- $r = hd$
	- $a = qkd + hd$ = $d(qk + h)$ (essendo che $a$ può essere scritto come $d$ moltiplicato per un intero allora è vero che è un divisore di b [[#Definizione di divisibilità]])


> [!TIP]
> L'algoritmo di Euclide sfrutta il fatto che il MCD di due numeri non cambia sostituendo il numero maggiore con il resto della loro divisione. Ripetendo questo processo iterativamente, si arriva al caso base, in cui uno dei due numeri è 0, e il MCD è dato dal numero rimanente.


> [!EXAMPLE] Esempio
> 
> $x_1 = 330$ e $x_2 = 156$
> $x_3 = 330\mod156 = 18$
> $x_4 = 156\mod18=12$
> $x_5 = 18 \mod 12 = 6$
> $x_6 = 12 \mod 6 = 0$
> Quindi $MCD(330, 156) = 6$.
> Da questo capiamo che il minimo comune divisore tra 2 numeri può essere calcolato trovando ripetutamente il modulo tra b ed il resto

Siano $a,b \in N$ allora esistono  $h, k \in Z$ tali che $MDC(a,b) = a * h + b*k$
Questo vuol dire che il MCD tra due numeri si può scrivere come una loro combinazione lineare

> [!EXAMPLE] Esempio partendo da risultato dell'esempio precedente
> 
> $6 = 18-12$
> $= 18 - (156 - 8 * 18)$
> $= -156 + 9 * 18$
> $= -156 + 9 (330 - 2 * 156)$
> $= -19 * 156 + 9 * 330$

---
###### Numeri primi e coprimi
Si definisce **numero primo** un intero che ha come divisori quelli banali ovvero 1 e se stesso. Due numeri $a,b \in Z$ si dicono **coprimi** se $MCD(a, b) = 1$ quindi esistono $h, k \in Z$ tali che $(a · h + b · k) = 1$

Come conseguenza del seguente teorema abbiamo le seguenti proprietà
1. Due numeri interi consecutivi sono coprimi
2. Siano $a,b,c \in Z$ tali che $c| a * b$ con $c$ ed $a$ coprimi allora $c|b$
	1. Abbiamo che $9|3 * 6$ però notiamo che $9 \nmid 3$ infatti $c$ ed $a$ non sono coprimi
3. Siano $a,b,c \in Z$ tali che $a|c$ e $b|c$  se $a$ e $b$ sono coprimi allora $a*b | c$
	1. Abbiamo che $4|12$ e $6|12$ ma $24 \nmid 12$ infatti $a$ e $b$ non sono coprimi

![[Pasted image 20241102092847.png]]

---
###### Fattorizzazione degli interi
Ogni intero n > 1 si può esprimere come prodotto di numeri primi positivi ed in modo unico
**Dimostrazione**: la dimostrazione di questo teorema deve essere fatta in 2 passi distinti
1. Prima dimostriamo che preso un qualunque n > 1 esiste una fattorizzazione di n;
	- Se per assurdo esistessero interi > 1 che non sono prodotto di numeri primi positivi potremmo costruire l'insieme $S = {n: n \in N }$ con n che è un numero non prodotto di numeri primi. Per l'assioma del buon ordinamento, dentro questo insieme abbiamo un minimo che chiameremo $s$, $s$ non è primo (perché senno sarebbe un prodotto di numeri primi positivi) quindi vuol dire che ha almeno un divisore non banale positivo chiamato $d$, avendo un divisore vuol dire che esiste un intero positivo che $c$ che moltiplicato per $d$ ci da $s$, $c$ e $d$ sono prodotti di primi positivi, e quindi anche $s$ lo è
2. successivamente dimostriamo che quella fattorizzazione è unica
	- Se $n = p_1 \cdot p_2 \cdots p_r = q_1 \cdot q_2 \cdots q_s$ ovvero $n$ è la somma dei primi $r$ o $s$ numeri interi ($p_i$ e $q_i$ sono gli i-esimi numeri primi ). La dimostrazione che va fatta è che $r$ = $s$, di seguito la dimostrazione per induzione.
		- **Caso base**: $r = 1$ Se $n = p_1$ allora $n$ è primo, da $p_1 = q_1 \cdot q_2 \cdots q_s$  otteniamo che $s = 1$ e $q_1 = p_1$
		- **Caso induttivo**: supponendo che sia vera questa tesi per r, dimostriamola per r+1, quindi: $n = p_1 \cdot p_2 \cdots p_{r+1} = q_1 \cdot q_2 \cdots q_s$ , dal caso base sappiamo che $q_1$ è divisore di $p_1$ e che quindi dividendo membro a membro per $p_1$ otteniamo $p_2 \cdots p_r \cdot p_{r+1} = q_2 \cdots q_s$ da questo capiamo che $r = s - 1$ e quindi che $s = r + 1$ quindi i fattori coincidono a meno dell'ordine e quindi che sono uguali.

---
###### Teorema di Euclide
Il teorema di Euclide ci dice che i numeri primi sono infiniti.
**Dimostrazione**:
1. **Ipotesi per assurdo**: Supponiamo che ci sia un numero finito di numeri primi. Se così fosse, potremmo elencarli tutti. Chiamiamo questi numeri primi $p_1, p_2, \dots, p_n$, dove $p_1 = 2$, $p_2 = 3$, e così via fino a $p_n$, che rappresenterebbe l’ultimo numero primo.
2. **Costruzione di un nuovo numero**: Consideriamo il numero $h$ definito come il prodotto di tutti questi numeri primi più uno:
   $h = p_1 \cdot p_2 \cdots p_n + 1$
3. **Proprietà di $h$**:
   - Per costruzione, $h$ è maggiore di tutti i numeri primi $p_1, p_2, \dots, p_n$.
   - Inoltre, $h$ non è divisibile da nessuno dei numeri primi $p_1, p_2, \dots, p_n$. Infatti, se dividiamo $h$ per uno qualsiasi di questi numeri primi $p_i$, otteniamo un resto di 1. In altre parole, $h \mod p_i = 1$, per ogni $i = 1, 2, \dots, n$.
4. **Contraddizione**:
   - A questo punto, possiamo concludere che $h$ o è primo oppure è divisibile da un numero primo non presente nella lista $p_1, p_2, \dots, p_n$.
   - Se $h$ è primo, allora abbiamo trovato un nuovo numero primo che non era incluso nella lista originale, il che contraddice l’ipotesi che $p_1, p_2, \dots, p_n$ fossero tutti i numeri primi.
   - Se $h$ non è primo, allora deve avere un divisore primo che non è nessuno dei $p_1, p_2, \dots, p_n$, il che ancora una volta contraddice l’ipotesi che $p_1, p_2, \dots, p_n$ siano tutti i numeri primi.

I numeri primi non solo sono infiniti, ma sono anche distribuiti in maniera tale da essere molto frequenti
Sia $n \in N$ sia $\pi(n)$ il numero di numeri primi minori o uguali ad n. Allora
$\lim_{n \to \infty} \frac{\pi(n)}{\frac{n}{\ln n}} = 1$ da questo estraiamo la seguente formula: $\frac{n}{\ln n}$ che ci va ad indicare il numero di numeri primi < di n
- per $n = 100$ stimati $\frac{100}{\ln 100}\approx 22$
- per $n = 1000$ stimati $\frac{1000}{\ln 1000}\approx 145$

---
###### Come verificare se un numero n è primo?
Verificando che non abbia divisore diversi da quelli banali. Ciò può essere fatto in maniera più efficiente se durante la verifica consideriamo i numeri compresi tra 2 e $\sqrt{\smash[b]{n}}$

---
###### Crivello di Eratostene
Se abbiamo la necessità di calcolare tutti i numeri primi minori o uguali ad un numero n, possiamo usare il crivello di Eratostene, questi sono i passaggi da seguire:
1. Scriviamo in sequenza tutti i numeri naturali compresi tra 2 e n.
2. Partiamo dal numero 2 e cancelliamo tutti i suoi multipli
3. Ad ogni passo prendiamo il primo numero tra i numeri che seguono e cancelliamo i suoi multipli
4. Quando abbiamo cancellato tutti i multipli del numero più grande che sia minore o uguale $a\sqrt{\smash[b]{n}}$ ci fermiamo.
[Esempio](https://youtu.be/0MDvEByNGic?t=83||)

---
###### Radice numerica
Dato un numero $n$ la sua radice numerica di $n$, la denotiamo con $ρ(n)$ ed è la somma delle sue cifre reiterata sono ad ottenere una sola cifra

> [!EXAMPLE] Esempio
> $198 : 1 + 9 + 8 = 18 → 1 + 8 = 9$ e quindi $ρ(198) = 9$.

---
###### Criteri di divisibilità
Esistono delle regole molto semplici per verificare la divisibilità di un numero $a$ per un numero $b$
- **Divisibilità per 2**: un numero è divisibile per $2$ se è pari
- **Divisibilità per 3**: un numero è divisibile per $3$ se la somma delle sue cifre è un numero divisibile per $3$
- **Divisibilità per 5**: un numero è divisibile per $5$ se l'ultima cifra è $0$ o $5$
- **Divisibilità per 7**: un numero è divisibile per $7$ se $q - 2r$ è divisibile per $7$
- **Divisibilità per 11**:  un numero è divisibile per $11$ se $a - b$ è divisibile per 11
- **Divisibilità per 9:** un numero $n$ è divisibile per $9$ se la sua radice numerica è divisibile per 9, oppure se $n-ρ(n)$ è divisibile per 9.
- **Divisibilità per altri numeri primi:**
	- $13$ divide n se $q + 4r$ è divisibile per $13$
	- $17$ divide n se $q − 5r$ è divisibile per $17$
	- $19$ divide n se $q + 2r$ è divisibile per $19$
	- $23$ divide n se $q + 7r$ è divisibile per $23$
		- $q =$ quoziente della divisione con $10$
		- $r =$ resto della divisione con $10$

> [!EXAMPLE] Esempio
> - **Divisibilità per 7**:
> 	- $q =$ quoziente della divisione con 10
> 	- $r =$ resto della divisione con 10
> 	- $161: 16 - 2*1 = 14$ che è divisibile per 7
> - **Divisibilità per 11**:
>   - $a =$ somma dei numeri nelle posizioni dispari
>   - $b =$ somma dei numeri nelle posizioni pari
>   - 2805 quindi con
> 	  - $a = 2+0$
> 	  - $b = 8+5$
> 	  - $a-b = -11$ che è divisibile per 11
> - **Divisibilità per 9:**
> 	- $198 : 1 + 9 + 8 = 18 → 1 + 8 = 9$ e quindi 198 è divisibile per 9
> - **Divisibilità per altri numeri**: [[6 novembre 2024.pdf | Esempi qui]]

---

**Teorema della divisibilità per 9**
Sia $n$ un numero naturale e sia $m$ la somma delle sue cifre. Allora $n − m$ è divisibile per 9.
**Dimostrazione:**
Sia $n$ un numero, rappresentato come:
- $n = \sum_{i=0}^{k} a_i \cdot 10^i$
dove $a_0, a_1, \dots, a_k$ sono le cifre del numero $n$, con $a_0$ che rappresenta le unità, $a_1$ le decine, e così via. Ora consideriamo un altro numero $m$, che ha la forma:
- $m = \sum_{i=0}^{k} a_i$
Questo numero $m$ è la somma delle cifre di $n$. La differenza tra $n$ e $m$ è:
$n - m = \sum_{i=0}^{k} a_i \cdot 10^i - \sum_{i=0}^{k} a_i = \sum_{i=0}^{k} a_i \cdot (10^i - 1) = \sum_{i=0}^{k} a_i \cdot 9 \cdot b_i = 9 \cdot \sum_{i=0}^{k} a_i \cdot b_i$

> [!EXAMPLE] Esempi
> 1. Consideriamo $n = 199$. La somma delle cifre di $n$ è $m = 1 + 9 + 9 = 19$. La differenza è: $199−19=180$ che è divisibile per 9.
> 2. Consideriamo $n = 640$. La somma delle cifre di $n$ è $m = 6 + 4 + 0 = 10$. La differenza è: $640−10=630$ che è divisibile per 9.
> 3. Consideriamo $n = 1129$. La somma delle cifre di $n$ è $m = 1 + 1 + 2 + 9 = 13$. La differenza è: $1129−13=1116$ che è divisibile per 9.

---
###### Dimostrazione per assurdo che $\sqrt{2}$ non è razionale
Assumendo che esistano 2 numeri naturali $a$ e $b$  tale che $\sqrt{2} = \frac{a}{b}$, assumendo anche che sia ridotta ai minimi termini almeno uno dei 2 è dispari. Elevando al quadrato otteniamo $a^2 = 2b^2$ essendo $a^2$ il doppio di un altro numero sarà per forza pari, detto ciò anche $a$ è pari è quindi esiste un numero $k$ tale che $a = 2k$ da questo avremo allora:
- $2b^2 = a^2 = 4k^2$ e quindi che anche $b$ è pari visto che $b^2 = 2k^2$
questa affermazione contraddice la nostra ipotesi inziale

---
## `Aritmetica modulare`
L'aritmetica modulare riguarda il calcolo sui resti delle divisioni tra interi rispetto ad un divisore fissato. Ricordiamo la [[#Divisione tra interi]] e diciamo che con la dicitura $n \mod m$, indichiamo con $n$ la base e con $m$ il modulo. Fissando un intero relativo $m$, possiamo definire la congruenza modulo $m$ in questo modo:
- un intero $a \in Z$ è in relazione con $b \in Z$ se $m | (a-b)$ e quindi che $a-b$ è un multiplo di $m$. In modo equivalente potemmo dire che $a$ è in relazione con $b$ se $a$ mod $b$ = $b$ mod $m$
- Se si verificano queste condizioni, la relazione tra a e b si scrive così:
	- $a \equiv b \pmod{m}$
- Se non si verificano queste condizioni, la relazione tra a e b si scrive così:
	- $a \not\equiv b \pmod{m}$

> [!TIP] Formula generale per la congruenza 
> Diciamo che 2 numeri sono congruenti se è vero che $m | (a-b)$

> [!EXAMPLE] Esempio
> - **12 ≡ 9(mod 3)** : $12$ mod $3$ = $9$ mod $3$ = $0$ entrambi per il primo caso del teorema della divisione
> - $7 \not\equiv 1\pmod{4}$ infatti $7$ mod $4$ = $3$ mentre $1$ mod $4$ = $1$

> [!TIP] 
> Da tutto ciò notiamo che per ogni $a \in Z$ ed ogni $m \in N$ abbiamo che: $a\equiv a\mod{m} \pmod{m}$
> **Esempio**: $5\equiv 5\mod{10}\pmod{10}$  se risolvi $5\mod10$ si capisce in modo intuitivo la proprietà

La relazione di congruenza è una **relazione di equivalenza**, il che implica che esistono un'infinità di classi di equivalenza, di seguito la dimostrazione:
- **Riflessiva**: Per ogni $a \in \mathbb{Z}$, è vero che $a \equiv a \pmod{m}$. Infatti, la differenza $a−a=0$ è sempre divisibile per qualsiasi numero, incluso $m$, poiché $0$ è divisibile per ogni intero. Quindi, $a \equiv a \pmod{m}$ per ogni $a \in \mathbb{Z}$.
- **Simmetrica:**  Se $a ≡ b(\mod m)$ allora $a − b = km$ per qualche $k ∈ Z$ e quindi, moltiplicando per $−1$ otteniamo $−a + b  = (−k)m$ ossia $b ≡ a(\mod m)$
- **Transitiva:** Se $a ≡ b(\mod m)$ e b ≡ $c(\mod m)$ abbiamo che esistono $h, k ∈ Z$ tali che $a − b$ = $hm$ e $b − c = km$. Sommando membro a membro le ultime due uguaglianze otteniamo: $a − c = (h + k)m$ e quindi $a ≡ c(\mod m)$.

---
###### Classi di equivalenza definite dalla congruenza
- **Congruenza modulo 0**: $a ≡ b(\mod 0)$ se e solo se $a − b = k · 0$ ovvero $a − b = 0$ quindi se $a = b$
	- Tutte le classi di equivalenza create dalla congruenza modulo 0 sono delle classi contenenti un solo elemento (ovvero quello preso in esame)
		- In questo caso la classe di equivalenza di $a$ è {$a$}
- **Congruenza modulo 1**: $a ≡ b(\mod 1)$ se e solo se $a − b = k · 1$ ovvero $a − b$ è multiplo di 1
	- Essendo che ogni numero è multiplo di 1 la classe di equivalenza creata dalla congruenza modulo 1 contiene tutti gli interi $\in Z$
- **Congruenza modulo 2**: $a ≡ b(\mod 2)$ se e solo se $a − b = k · 2$ ovvero $a − b$ è un numero pari
	- Se $a$ è pari abbiamo che $a = 2 * h$ e quindi che $b = 2h - k*2 = 2(h - k)$ e quindi anche $b$ è pari
	- Se $a$ è dispari abbiamo che $a = 2*h+1$ e quindi che $b = 2h + 1 - k*2 = 2(h-k)+1$ e quindi anche $b$ è dispari
	- Le classi di equivalenza create sono 2 una con tutti i numeri dispari e una con tutti i numeri pari
Dato un intero m >= 0 indicheremo con $[a]_m$ la classe di rappresentata dall'intero $a$ nella relazione di congruenza modulo $m$ ovvero:
- $[a]_m = \{b \in \mathbb{Z} : a \equiv b \pmod{m}\}$

**Teorema**
Fissato un intero m > 1 le sue classi di equivalenza sono: $[0]_m, [1]_m, [2]_m, \dots, [m-1]_m.$
**Dimostrazione**
Sia $a ∈ Z$ e sia $r$ il resto della divisione intera di $a$ per $m$, ovvero, applicando l’algoritmo di divisione
- $a = qm + r$ con $0 ≤ r < m$.
Dal momento che $a − r = qm$ abbiamo che $a ≡ r (\mod m)$. Quindi, dal momento che $r$ può assumere solo i valori che vanno da $0$ a $m − 1$ le classi di equivalenza sono solo quelle dell’enunciato del teorema.

**Dimostrazione che le classi sono distinte**
Ragioniamo per assurdo e supponiamo che esistano $x, y ∈ Z$, $x \not= y$ e $0 ≤ x$, $y < m -1$ tali che $[x]_m$ = $[y]_m$ . Senza perdita di generalità supponiamo che $x > y$. Dall’ipotesi possiamo scrivere $x − y = km$ cioè $x − y$ è un multiplo di $m$. Da $0 ≤ x, y < m − 1$ e $x > y$ segue che $0 < x − y < m − 1$, che è una contraddizione visto che non esistono multipli di $m$ in tra $0$ e $m − 1$.

Sia $m = 5$ (congruenza modulo $5$). Le classi resto modulo $5$ sono $[0]_5, [1]_5, [2]_5, [3]_5, [4]_5.$

> [!Info] 
> - $[2]_5$ Sono tutti quei numeri che divisi per 5 ci danno resto 2
> - $[5]_10$ Sono tutti quei numeri che divisi per 10 ci danno resto 5

> [!EXAMPLE] Esercizio
> Dato a ∈ Z come facciamo a stabilire in quale classe resto sta?
> - La risposta ci viene fornita dal teorema appena dimostrato: $[a]_m$ = $[r ]_m$ dove r è il resto della divisione di a per m.
> - Quindi se m = 5 e a = 22 allora eseguendo la divisione abbiamo 22 : 5 = 4 con resto di 2, ottenendo che $[22]_5$ = $[2]_5$.
> - Ricordiamo che la notazione $[a]_m$ indica la classe di equivalenza modulo $n$, cioè l'insieme di tutti i numeri interi che, divisi per $n$, lasciano lo stesso resto di $a$.
> 	Nel nostro caso:
> 	- $[22]_5$: Questa classe contiene tutti i numeri che, divisi per 5, lasciano resto 2. Alcuni esempi sono: 2, 7, 12, 17, 22, ...
> 	- $[2]_5$​: Questa classe contiene tutti i numeri che, divisi per 5, lasciano resto 2. Alcuni esempi sono: 2, 7, 12, 17, ...
> 	- le due classi contengono esattamente gli stessi elementi
> - In altre parole potremmo dire che $22 ≡ 2 (\mod 5)$
> 
> Notiamo che in classe $[0]_5$ ci sono tutti i multipli di 5 ed in generale in $[0]_m$ ci sono tutti i multipli di m.
> 

---
##### Invarianza rispetto a somma e prodotto
Dato $m \in N$ e dati $a,b \in Z$ tali che $a \equiv b \pmod{m}$ allora prendendo $c,d \in Z$ tali che $c \equiv d \pmod{m}$ abbiamo che:
- $a + c \equiv b + d (\mod m)$
- $a * c \equiv b * d (\mod m)$

###### Dimostrazione:
Ipotizziamo che per ipotesi esistono $k_1$,$k_2$ tale che $a-b = k_1m$ e $c-d =k_2m$, da questo possiamo dimostrare che:
1. $(a+c) - (b+d) = (a-b) + (c-d) = (k_1$ + $k_2$)m (da questo capiamo che qualsiasi sia l'ordine delle lettere avremo sempre dei multipli di m)
2. Abbiamo $a = b+k_1m$ e $c = d + k_2m$ quindi $ac-bd = (b + k_1m)(d + k_2m) - bd = bk_2m+dk_1m+k_1k_2m^2 = (bk_2 + dk_1 + k_1k_2m)m$
- **Come si arriva a questa conclusione?**
		1. **Sfruttiamo le ipotesi:** Ricordiamo che per ipotesi abbiamo:
		    - $a ≡ b (\mod m),$ quindi $a = b + k₁m$
		    - $c ≡ d (\mod m),$ quindi $c = d + k₂m$
		2. **Sostituiamo nella moltiplicazione:** Moltiplichiamo membro a membro le due equazioni ottenute al punto precedente:
		    - $ac = (b + k₁m)(d + k₂m)$
		3. **Sviluppiamo il prodotto:** Svolgendo i calcoli otteniamo:
		    - $ac = bd + bk₂m + dk₁m + k₁k₂m²$
		    - $ac - bd = bk₂m + dk₁m + k₁k₂m²$
		4. **Evidenziamo m:** Mettiamo in evidenza `m` a secondo membro:
			-  $ac - bd = m(bk₂ + dk₁ + k₁k₂m)$
		5.  **Cosa significa questo risultato?**
			-  Abbiamo dimostrato che la differenza tra $ac$ e $bd$ è un multiplo di $m$. Quindi, per definizione di congruenza modulo $m$, si ha: $ac ≡ bd (\mod m)$

---
###### Casi particolari:
- **Invarianza rispetto alla somma 1**: Se ==sommiamo== ad entrambi i membri di una congruenza uno stesso numero intero, la congruenza non cambia
	- $a ≡ b(\mod m)$ allora $a + c ≡ b + c(\mod m)$
- **Invarianza rispetto al prodotto 1**: Se ==moltiplichiamo== ambo i membri di una congruenza per uno stesso numero intero, la congruenza non cambia.
	- $a ≡ b(\mod m)$ allora $ac ≡ bc(\mod m)$
- **Invarianza rispetto alla somma 2**: Se ==sottraiamo== ad entrambi i membri di una congruenza uno stesso numero intero, la congruenza non cambia
	- $a ≡ b(\mod m)$ allora $a − c ≡ b − c(\mod m)$
- **Invarianza rispetto al prodotto 2**: Se ==dividiamo== ambo i membri di una congruenza per uno stesso numero intero, la congruenza potrebbe non valere più.
	- $6 ≡ 0 (\mod 3)$ è vera se dividiamo tutto per 2 diventa $2 \not≡ 0 (\mod 3)$ che è falsa

---
###### Conseguenza dei casi particolari:
Come conseguenza dei primi 2 casi particolari, dati $a,b,m \in N$ e visto che $a ≡ a \mod m (\mod m)$ e $b ≡ b \mod m(\mod m)$
valgono le seguenti proprietà:
1. $(a+b)$ ≡ $(a \mod m + b \mod m)(\mod m)$
   ossia $(a+b) \mod m$ = $(a \mod m + b \mod m)(\mod m$)
2. $(a \times b)$ ≡ $(a \mod m \times b \mod m)(\mod m)$
   ossia $(a \times b) \mod m = ((a \mod m)(b \mod m))(\mod m)$
Come conseguenze del punto 2 abbiamo:
3. Dati $a,n,m \in N, a^2 ≡ (a \mod m)^2(\mod m)$
4. Dati $a,b,h,k,m \in N$ allora $a^h \times b^k ≡ (a^h \mod m) \times (b^k \mod m)(\mod m)$
   ossia $a^h \times b^k \mod m = (a \mod m)^h \times (b \mod m)^k \mod m$

---
###### Diretta conseguenza dell'invarianza rispetto alla somma 
**Teorema**:
- Per ogni $m \in N, m>1$ , prendendo una qualunque sequenza di m interi questa contiene un intero divisibile per m
**Dimostrazione:**
Consideriamo allora $m$ interi consecutivi, dove il più piccolo è $n$, Come abbiamo già dimostrato, le classi di equivalenza della relazione di congruenza modulo $m$ sono $[0]_m , [1]_m , [2]_m , . . . [m − 1]_m$ , il nostro numero $n$ si trova in una di queste classi di equivalenza, supponiamo stia nella classe $[i]_m$ per $0 ≤ i ≤ m − 1$. Quindi $n ≡ i(\mod m)$ ed allora $n + 1 ≡ i + 1(\mod m)$ ovvero $n + 1 ∈ [i + 1]m$. Notiamo allora che se $i = 0$ ovvero $n ∈ [0]_m$ abbiamo dimostrato il teorema. Se invece $i > 0$, visto che $0 < i < m$ incrementando $i$ esattamente $m − i$ volte, con $m − i < m$ otteniamo che $n + (m − i) ≡ i + (m − i)(\mod m)$ ossia $n + (m − i) ≡ m(\mod m) ≡ 0(\mod m)$. In conclusione, $n + (m − i)$ è il numero multiplo di $m$ nella sequenza di $m$ numeri consecutivi.

---
**Esercizi**:
![[Pasted image 20241109153607.png|500]]
![[Pasted image 20241109153614.png|500]]

---
###### Inverso modulare
Nei numeri razionali esiste il concetto di "inverso" ovvero preso $a \in Q$ e $a \not=$ 0 esiste un $x \in Q$ tale che $a * x = 1$, $x$ viene anche denotato con la dicitura $a^{-1}$.
- se $a = 2$ allora $a^{-1} = \frac{1}{2}$
Il seguente teorema introduce una nozione simile per l'aritmetica modulare.

**Teorema**
Siano $a, b ∈ N$ entrambi maggiori di zero. Allora, esiste un elemento $x ∈ N$ tale che $a · x ≡ 1(\mod b)$ se e solo se $a$ e $b$ sono [[#Numeri primi e coprimi|coprimi]]. Anche in questo caso l'elemento x viene detto "inverso di a modulo b" e si denota con $a^{-1}$
> [!EXAMPLE] Esempi
> - con $a = 5$, $b = 3$ abbiamo che $a^{−1}$ = $2$,
> 	- infatti $2 · 5$ mod $3$ = $10$ mod $3$ = $1$ che è congruo con $1$ mod $3$
> -  con $a = 9$, $b = 7$ abbiamo che $a^{−1}$ = $4$,
> 	- infatti $4 · 9$ mod $7$ = $36$ mod $7$ = $1$ che è congruo con $1$ mod $7$

**Dimostrazione**
![[Pasted image 20241116095002.png]]

---
## `Funzione di Eulero`
Sia $n$ un intero positivo per definire quanti sono i numeri che precedono $n$ e che sono anche coprimi con $n$ dobbiamo usare la funzione di Eulero definita così:
- **$\phi(n) = |\{x: x \in \mathbb{N}, 0 < x \leq n, MCD(n,x) = 1\}|$** La funzione phi di Eulero di n è uguale al numero di numeri naturali x, compresi tra 0 e n (estremi inclusi), tali che il massimo comune divisore tra n e x sia uguale a 1.
> [!EXAMPLE] Esempi
> $n = 5$ : φ(5) = 4 poiché MCD(5, x) = 1, per x = 1, 2, 3, 4.
> $n = 7$: φ(7) = 6 poiché MCD(7, x) = 1, per x = 1, 2, 3, 4, 5, 6.
> $n = 10$: φ(10) = 4 poiché MCD(10, x) = 1, per x = 1, 3, 7, 9.
> $n = 12$: φ(12) = 4 poiché MCD(12, x) = 1, per x = 1, 5, 7, 11.

---
###### Formule generali per il calcolo del $\phi(n)$ usata negli esercizi
Ci sono delle formule generali per il calcolo del phi di un numero:
1. Se $n$ è un numero primo tutti i predecessori di n sono ad esso coprimi quindi $\phi(n) = n - 1$
2. Il caso $n$ potenza di numero primo, ovvero $n = p^k$ dove $k ≥ 2$ e $p$ è primo, tutti i divisori di $n$ vanno da $p^1, p^2, \ldots, p^k$ e i multipli di $p$ sono $p, 2p, 3p, \ldots, p^{k-1}$ i multipli di $p$ sono i numeri non coprimi con $n$, quindi facendo la differenza tra $p^k$ e $p^{k-1}$ otteniamo tutti i numeri coprimi con n ovvero $φ(n) = φ(p^k) = n − p^{k−1} = p^k − p^{k−1}$
3. Analizziamo il caso $n$ prodotto di due numeri distinti, ovvero n = $p_1 * p_2$ con $p_1, p_2$ entrambi primi. Tra gli interi $1, 2, 3, . . . p_1 · p_2$ = $n$ ci sono $p_2$ multipli di $p_1$, ossia $p_1$, $2p_1$, $3p_1$, . . . , $p_2$ · $p_1$ e, analogamente $p_1$ multipli di $p_2$. Tolti i multipli di $p_1$ e di $p_2$ tutti gli altri interi sono ovviamente coprimi con $n$ e quindi φ(n) = n − $p_1$ − $p_2$ + 1 = $p_1p_2$ − $p_1$ − $p_2$ + 1 = ($p_1$ − 1) · ($p_2$ − 1)

> [!EXAMPLE] Esempi
> $φ(5) = 4$
> $φ(8) = φ(2^3) = 2^3 − 2^2 = 8 − 4 = 4$
> $φ(6) = φ(2 · 3) = (2-1) · (3-1) = 2$

Il caso numero 3 può essere generalizzato nel seguente modo:
Sia $n = h · k$ dove $h$ e $k$ sono interi maggiori di zero e coprimi tra di loro. Allora $φ(n) = φ(h) · φ(k)$
- φ(4 · 9) = φ($2^2$) · φ($3^2$) = 2 · 6 = 12
- φ(5 · 8) = φ($5$) · φ($2^3$) = 4 · 4 = 16

> [!SUMMARY] Formulario
> - Per n numero primo allora $φ(n) = n -1$
> - **Con n multiplo di un numero primo** φ(n) = $n^{k_1}$ - $n^{k_2-1}$
>  - **Con n prodotto di numeri primi** $φ(n) = φ(k)\timesφ(q)...$ 

---
###### Formula generale per il calcolo della funzione di Eulero
Utilizzando il [[#Fattorizzazione degli interi |teorema di fattorizzazione degli interi]] possiamo ricavare la formula generale per il calcolo della funzione φ di Eulero.
Sia n > 1, consideriamo la sua fattorizzazione $n = p_1^{k_1} · p_2^{k_2} · . . . · p_m^{k_m}$ Allora
- $\phi(n) = (p_1^{k_1} - p_1^{k_1 - 1}) \cdot (p_2^{k_2} - p_2^{k_2 - 1}) \cdot \ldots \cdot (p_m^{k_m} - p_m^{k_m - 1})$

**Dimostrazione:** dimostriamo il teorema per induzione sul numero dei fattori primi presenti nella fattorizzazione di n.
**Caso base:**  se $m = 1$ allora $p_1^{k_1}$ sappiamo che è vera per il [[#Formule generali per il calcolo del $ phi(n)$ usata negli esercizi|caso 2]]
**Passo induttivo:** Supponiamo il teorema sia vero per ogni intero $n'$ la cui fattorizzazione presenta $m-1$ primi diversi campiamo che $n' = p_1^{k_1} · p_2^{k_2} · . . . · p_{m-1}^{k_{m-1}}$ a questo punto la fattorizzazione per $m$ sarà uguale a:
- $n = n′ · p^{k_m}_m$
dal teorema abbiamo che: $\phi(n') = (p_1^{k_1} - p_1^{k_1 - 1}) \cdot (p_2^{k_2} - p_2^{k_2 - 1}) \cdot \ldots \cdot (p_{m-1}^{k_{m-1}} - p_{m-1}^{k_{m-1} - 1})$  e quindi $\phi(n) = \phi(n') * (p_{m}^{k_{m}} - p_{m}^{k_{m} - 1})$.

Come possiamo notare il teorema vale sia nel caso base, sia nel passo induttivo e quindi il teorema è dimostrato.

> [!EXAMPLE] Esempio
> $φ(42) = (2^1 - 2^{1-1}) · (3^1 - 3^{1-1}) · (7^1 - 7^{1-1}) =$ 
>  $=(2^1 - 2^0) · (3^1 - 3^0) · (7^1 - 7^0)$ Quindi $φ(42) = 1 · 2 · 6 = 12$. 
> In questo esempio ho preferito specificare ogni singolo esponente per renderlo più semplice da capire)
> 

---
##### Teorema di Eulero
Il seguente teorema, detto Teorema di Eulero, dimostra come la funzione φ di Eulero si possa applicare alla esponenziazione modulare. Siano $n, m$ > $0$, se $MCD(n, m) = 1$ allora $n^{φ(m)} ≡ 1(\mod m)$

> [!EXAMPLE] Esempio
> $n = 12, m = 5 : 12^4 ≡ 1(\mod 5)$ infatti $12^4 = 20736$ e $20736\mod 5 = 1$

[[dimostrazioneNoEsame | Dimostrazione da non studiare per l'esame]]

---
##### Piccolo teorema di Fermat
conosciuto come "Ultimo Teorema di Fermat" afferma che non esistono soluzione intere positive all’equazione $a^n + b^n = c^n$ per $n > 2$

**Teorema** 
Se $p$ è primo e $MCD(a, p) = 1$, ovvero a non è un multiplo di $p$, allora $a^{p−1} ≡ 1(\mod p)$

> [!EXAMPLE] Esempio
> ![[Pasted image 20241208202530.png]]

---
##### Altra conseguenza del teorema di Eulero
Se $MCD(a, n) = 1$, allora per ogni $x > 0$ vale la seguente cosa:
- $a^x ≡ a^{x \mod φ(n)}(\mod n)$
![[Pasted image 20241208202924.png]]

---
##### Calcolo dell'inverso modulare
Abbiamo visto che se n ed m sono comprimi, allora esiste l'inverso di n modulo m ossia esiste k tale che $n * k ≡ 1(\mod m)$, per calcolare l'inverso di $n$ modulo $m$ è:
- $(n \mod m)^{φ(m) - 1} \mod m$ 
> [!EXAMPLE] Esempio
> ![[Pasted image 20241208204802.png]]

[[eserciziInversoModulare.pdf|Esercizi qui]]

---
## `Applicazioni dell'aritmetica modulare`

##### La prova del 9
La prova del nove è una verifica di correttezza del risultato di una operazione aritmetica tra numeri interi, ricordando la definizione di [[#Radice numerica|radice numerica]] questo è il teorema che definisce la prova del 9:
**Teorema:** dati $n,m \in N$ abbiamo che:
- $ρ(n*m) = ρ(ρ(n)*p(m))$
- $ρ(n+m) = ρ(ρ(n)+p(m))$

> [!EXAMPLE] Esempio
> Verificare che $123 * 347$ Faccia $42671?$ per verificare che è giusto facciamo così:
> - $ρ(123) = 6$
> - $ρ(347) = 5$ 
> - $ρ( ρ(123) * ρ(347) ) = ρ(30) = 3$
> - $ρ(42671) = ρ(20) = 2$ 
> 
> Gli ultimi 2 risultati sono sbagliati quindi la moltiplicazione è stata fatta nel modo errato (il vero risultato di $123*347$ è $42681$)

**Teorema:** dato $n \in N$ abbiamo che $n ≡ ρ(n)(\mod 9)$ in pratica stiamo dicendo che la radice numerica di un qualsiasi numero è congrua modulo $9$. 

**Dimostrazione**: per il Teorema di divisibilità del $9$ sappiamo che dato $n ∈ N$, se $m$ è la somma delle sue cifre allora $n − m$ è divisibile per $9$, ossia esiste un $k$ tale che $n − m = 9k$. 
Quindi, ottengo che $n ≡ m(\mod 9)$. 
Reiterando, se $m′$ è la somma delle cifre di $m$ otteniamo $m ≡ m′(\mod 9)$ quindi $n ≡ m(\mod 9) ≡ m′(\mod 9)$. 
Fermiamo il processo di somma delle cifre quando otteniamo un numero con una sola cifra (ovvero la radice numeri di $n$) quindi concludiamo che $n ≡ ρ(n)(\mod 9)$

> [!EXAMPLE] Esempio
> - $250 ≡ 7 \mod 9$ infatti
> 	- $250 \mod 9 = 7$
> 	- $7 \mod 9 = 7$

---
###### Codice ISBN
Il codice ISBN è un codice identificativo standard per i libri , oggi è composto da 13 cifre mentre prima del 2007 era composto da 10 cifre. Per controllare la validità del codice si fa in questo modo:

- **ISBN-10**: Se le cifre sono da $a_{10}$ fino ad $a_{1}$ il codice è formalmente corretto se:
	- $a_1 + 2a_2 + 3a_3 + \cdots + 9a_9 + 10a_{10} \equiv 0 \pmod{11}$ 
> [!EXAMPLE] Esempio
> Il codice 2468864212 è corretto?
> - Abbiamo $10 · 2 + 9 · 4 + 8 · 6 + 7 · 8 + 6 · 8 + 5 · 6 + 4 · 4 + 3 · 2 + 2 · 1 + 2 = 264$
> - il numero è divisibile per 11 quindi è un codice ISBN-10 corretto.

- **ISBN-13**: se le cifre sono da $a_1$ fino ad $a_{13}$ il codice è formalmente corretto se:
	- $a_1 + 3a_2 + a_3 + 3a_4 + \cdots + a_9 + 3a_{10} + a_{11} + 3a_{12} + a_{13} \equiv 0 \pmod{10}$ 
> [!EXAMPLE] Esempio
> - Il codice 2468864211129 è corretto?
> - Abbiamo $2 + 12 + 6 + 24 + 8 + 18 + 4 + 6 + 1 + 3 + 1 + 6 + 9 = 100$
> - il numero è divisibile per 10 quindi è un codice ISBN-13 corretto

---
###### Codice carta di credito
Anche il codice numerico a 16 cifre si basa sull'aritmetica modulare, assumendo che le cifre siano le seguenti (raggruppate in 4 gruppi):
- $a_1b_1a_2b_2$
- $a_3b_3a_3b_3$
- $a_5b_5a_6b_6$
- $a_7b_7a_8b_8$
Il codice numerico della carta di credito è formalmente corretto se $S$ è divisibile per 10 con $S = \sum_{i=1}^8 \rho(2a_i) + \sum_{i=1}^8 b_i$ 

> [!EXAMPLE] Esempio
> - 1234-5678-8765-4321
> 	- Le cifre di posto dispari, quelle che abbiamo denotato con $a_i$ sono allora 1, 3, 5, 7, 8, 6, 4, 2 moltiplicando per 2 e sommando le cifre dei risultati a più di una cifra otteniamo i numeri: 2, 6, 1, 5, 7, 3, 8, 4 la cui somma è 36
> 	- Le cifre di posto pari, quelle che abbiamo denotato con $b_i$ sono allora 2, 4, 6, 8, 7, 5, 3, 1 e la somma da come risultato di nuovo 36.
> - Quindi, non è un numero di carta di credito corretto, visto che il risultato finale 36 + 36 = 72 non è un multiplo di 10.

---
###### Cifrari a trasposizione
![[Pasted image 20241203164718.png]]
## `Teoria dei numeri e problemi aperti`

Ci sono molti problemi della teoria dei numeri che sono ancora irrisolti di seguito i problemi aperti più famosi, la maggior parte dei problemi aperti saranno del tipo "questa sequenza numeri è infinità?". Quasi tutte le sequenze più famose le trovi su questo sito: [OEIS](https://oeis.org) 

##### Numeri primi di Mersenne
I numeri primi di Mersenne sono numeri primi della forma:
- $M_p = 2^p - 1$ 
	- $M_2 = 2^2 - 1 = 3$
	- $M_3 = 2^3 - 1 = 7$
Ad oggi conosciamo solo 52 numeri di Mersenne, l'ultimo scoperto ad ottobre 2024 grazie al progetto GIMPS [lista numeri di Mersenne](https://www.mersenne.org/primes/) , il problema aperto è se questa sequenza sia infinita.

##### Numeri perfetti: funzione "Sigma"
Dato un numero $n \in N$ definiamo la seguente funzione
- $\sigma(n) = \sum_{0 < d, d|n} d$ ovvero la somma di tutti i divisori positivi di un numero.
un numero si dice **perfetto** se $\sigma(n) = 2n$ il primo numero perfetto è il 6 infatti:
- $σ(6) = 1 + 2 + 3 + 6 = 12$ 
I primi a studiare questi numeri furono i pitagorici. Pitagora si accorse di una proprietà che fu poi dimostrata da Euclide, ossia che se $2^n-1$ è un numero primo allora $2^{n-1}*(2^n - 1)$ è perfetto
Infatti i numeri perfetti sono strettamente correlati ai numeri di Mersenne, cosi quest'ultimi si ci chiede se i numeri perfetti siano infiniti.

##### Numeri primi gemelli
I numeri primi gemelli sono coppie di numeri primi che hanno una differenza di $2$, come $(3,5),(5,7)$, ecc. Entrambi i numeri sono dispari, perché la loro differenza è $2$, un numero pari.

La domanda riguarda se esistono infinite coppie di numeri primi la cui differenza è pari a $2k$ per ogni $k≥1$. Questo è legato alla congettura delle coppie di numeri primi, che suggerisce che esistano infinite coppie di numeri primi con differenze fisse, ma non è ancora stata dimostrata. In altre parole, pur essendo noti molti esempi, la dimostrazione formale che esistano infiniti numeri primi gemelli o con differenze maggiori è ancora un mistero aperto.

##### Congettura di Goldbach

La **congettura di Goldbach**, proposta dal matematico prussiano nel 1742 e formulata da Eulero, afferma che **ogni numero pari maggiore di 4 può essere scritto come la somma di due numeri primi**. Ad esempio:

- $6 = 3 + 3$
- $8 = 3 + 5$
- $10 = 3 + 7 = 5 + 5$
- $12 = 5 + 7$
- $14 = 3 + 11 = 7 + 7$

La congettura non è ancora stata dimostrata, ma non è stato trovato nemmeno un numero pari che non soddisfi questa proprietà.

Esistono **due definizioni equivalenti** della congettura:

1. **G1**: Per ogni numero intero $x \geq 2$, esiste un intero $d \geq 0$ tale che $x - d$ e $x + d$ siano entrambi numeri primi.
2. **G2**: Per ogni numero intero $x \geq 2$, esistono due numeri primi $p_1$ e $p_2$ tali che $x = \frac{p_1 + p_2}{2}$.

In altre parole, la congettura suggerisce che ogni numero pari può essere rappresentato come la media di due numeri primi.

Un concetto importante nella discussione della congettura di Goldbach è il **concetto di separatori dei numeri primi gemelli**, ovvero gli interi che si trovano a metà tra due numeri primi consecutivi. Per esempio, la sequenza di "interprimi" contiene numeri come $4$, $6$, $9$, $12$, $15$, $18$, $21$, ecc. Questi numeri, che si trovano a metà tra due numeri primi consecutivi, verificano la congettura di Goldbach. Ad esempio, $9$ è la media di $7$ e $11$, che sono numeri primi consecutivi.

Inoltre, grazie ai moderni strumenti di calcolo, la congettura è stata verificata fino a numeri pari molto grandi, fino a circa $10^{17}$, ma non è stata ancora dimostrata in modo generale.

Un'altra parte interessante della congettura riguarda la **distanza di Goldbach**, definita come la distanza minima $d(n)$ per ogni numero $n$, tale che $n - d(n)$ e $n + d(n)$ siano entrambi numeri primi. Per esempio:

- $d(2) = 0$ (poiché $2$ è primo),
- $d(4) = 1$ (poiché $3$ e $5$ sono primi),
- $d(6) = 1$ (poiché $5$ e $7$ sono primi),
- $d(8) = 3$ (poiché $5$ e $11$ sono primi).

Le sequenze di numeri con distanze di Goldbach uguali a un certo valore $k$ formano diverse **classi di numeri**, come la sequenza $G1$ (separatori dei primi gemelli), $G2$, $G3$, ecc. La congettura di Goldbach sarebbe vera se queste sequenze coprissero tutti i numeri naturali (eccetto $0$ e $1$).

Tuttavia, ci sono molte incognite, come la domanda se esistano sequenze infinite (ad esempio, se esistano infiniti separatori di primi gemelli) o sequenze vuote (se esistano valori di $d$ tali che non ci siano numeri $n$ per cui $n - d$ e $n + d$ sono entrambi primi).

In sintesi, la congettura di Goldbach suggerisce che ogni numero pari maggiore di $4$ è la somma di due numeri primi, ma non è ancora stata provata in modo rigoroso.

## `Congettura di Collatz`

La **congettura di Collatz** conosciuta anche come congettura $3x + 1$ questa congettura lega la teoria dei numeri ad un problema di terminazione di un algoritmo iterativo.
L'algoritmo si basa sulla seguente funzione:
![[Pasted image 20241207151025.png]]
Che diventa in pseudocodice:
```
Algoritmo di Collatz 
Leggi un intero x ≥ 1 
while (x > 1) do 
	if x mod 2 == 0 x = x/2; 
	else x = 3 ∗ x + 1; 
end_while
```

Il **problema irrisolto**: l'algoritmo si ferma sempre oppure esiste un $x$ partendo dal quale non si raggiunge mai il valore $1$?

L'algoritmo produce una sequenza di interi detta **traiettoria di n** dove n è il numero in input. Di seguito l'output di un'implementazione in C della seguente congettura con la traiettoria dei primi 10 numeri: 
![[Pasted image 20241207152343.png]]
Notiamo che per alcuni interi la lunghezza della traiettoria è maggiore del numero stesso ($n = 3$ ad esempio). Con il tempo è stato ideato un algoritmo di collatz semplificato
```
Algoritmo di Collatz semplificato 
Leggi un intero x ≥ 1 
while (x > 1) do 
	if x mod 2 == 0 x = x/2; 
	else x = (3 ∗ x + 1)/2; 
end_while
```
Visto che x è dispari, sicuramente 3x + 1 è pari, e quindi possiamo direttamente assegnare come nuovo valore ad x il valore (3x + 1)/2. In questo modo le traiettorie di accorciano. Sebbene la congettura sia stata formulata nel 1937, gran parte del lavoro "sperimentale" per provare a risolverla è incominciato nel 1970. Ad oggi, la congettura è stata verificata per tutti gli $n < 10^{18}$ 

### 03_Parte3


Questo file è la rielaborazione delle slide [[03_Parte3.pdf]]
## `Calcolo combinatorio`
Una delle cose più importanti che un informatico deve imparare a fare è **contare** o **calcolare** nel modo giusto, in particolare vogliamo essere in grado di contare il numero di oggetti o casi che ci interessano, senza doverli esplicitare uno per uno. Di seguito delle domande di esempio alla quale risponderemo dopo aver introdotto il calcolo combinatorio:
- **Domanda 1:** Se sto scrivendo un programma che simula il poker, il mio programma deve fare in modo che la probabilità di un poker d'assi servito sia quella giusta. Ma qual è tale probabilità?
- **Domanda 2:** Quanti sono i codici PIN di una carta bancomat a 5 cifre e quante sono le probabilità che un ladro riesca ad indovinare entro 3 tentativi? [[#^fec4ef|Risposta 2]] [[#^b95d26|Continuo]]
- **Domanda 3:** Quante sono le possibili password fatte di 8 simboli alfa-numerici (maiuscole e minuscole sono diverse) e quanto tempo ci mette un programma che genera 1000 password al secondo a trovare quella giusta? [[#^a39c5a|Risposta 3]]
- **Domanda 4:** Se dovessi scommettere che in un’aula con 20 persone, ce ne siano almeno 2 che fanno il compleanno lo stesso giorno, scommetterei di si oppure no? E se ce ne sono 30, 40, 50 o più di persone? [[#^dabca4|Risposta 4]]
- **Domanda 5:** Quante squadre di calcio diverse posso formare da un gruppo di 50 studenti?
---
##### Regola della somma
Questa regola ci dice che se vogliamo contare il numero di elementi dell'unione tra due insiemi ci basta sommare la cardinalità dei due insiemi.
- Se denotiamo con $A$ tutte le lettere dell'alfabeto minuscole e con $B$ tutte le lettere dell'alfabeto maiuscole allora il numero di elementi di $A ∪ B$ sarà uguale a $|A|+|B|$ e quindi $26+26 = 52$  

---
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
![[Pasted image 20250115190854.png]]
[[03_Parte3Teoria|La spiegazione teorica dell'immagine che vedi sotto]] la parte teorica qui è abbastanza inutile.

- Se nell'esercizio che sto facendo l'ordine degli elementi è importante guardo le colonne dove "Ordine?" è SI.
- Se nell'esercizio che sto facendo gli elementi possono essere reinseriti guardo le colonne dove "Reinserimento" è NO.
**Esercizio 1**: Domino
![[Pasted image 20241214170145.png]]
**Esercizio 2**: gruppi di persone
![[Pasted image 20241214170224.png]]
**Esercizio 3**: parola di 4 lettere
![[Pasted image 20241214170259.png]]
**Esercizio 4**: Gelato per tutti
![[Pasted image 20241214170322.png]]

---
##### Teorema binomiale
Il teorema binomiale è una formula che consente di elevare a qualsiasi numero un binomio così:
![[Pasted image 20241214164028.png]]
Ovvero la sommatoria da $k=0$ fino a $n$ (l’esponente del binomio) della moltiplicazione tra $a^{n-k} * b^k$ 

---
##### Pigeonhole principle
Nella sua forma più semplice, il Principio afferma che se dobbiamo fare entrare $n + 1$ piccioni in una piccionaia che contiene $n$ cassette, allora almeno una cassetta dovrà contenere più di un piccione. Più in generale, se abbiamo $n = km + 1$ oggetti da sistemare in m contenitori, allora almeno un contenitore dovrà contenere $k + 1$ oggetti.
- se in un cassetto abbiamo solamente calzini bianchi e neri, se peschiamo casualmente 3 volte un calzino, potremo sicuramente formare una coppia abbinata.

---
## `Probabilità discrete`

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

> [!TIP] Mutualmente esclusivi
> Se due eventi A e B non hanno elementi in comune essi sono detti eventi disgiunti o mutualmente esclusivi perché l'occorrenza dell'uno esclude l'altro.

^81d10b
---
##### Definizione frequentista
La definizione classica non considerava la possibilità di eventi non equiprobabili (come un dato truccato ad esempio), fu Richard von Mises a definire la probabilità che accada un evento $A$ come il limite del rapporto tra il numero di volte in cui si è verificato l'esito $f_A$ (l'esito favorevole) e il numero degli esperimenti $n$ ovvero:

> [!TIP] Formula frequentista per la probabilità
> $P(A) = \lim_{n \to \infty} \frac{f_A}{n}$

La definizione frequentista ha un problema di fondo insuperabile: non tutti gli esperimenti sono ripetibili e quindi alcune probabilità non sarebbero calcolabili. Da qui nasce la teoria della probabilità

---
##### Teoria della probabilità
Siano $A$ e $B$ due eventi qualsiasi definiti su uno spazio dei campioni $S$. Di seguito gli assiomi della probabilità:

> [!TIP] Assiomi della probabilità
> 1. $0 \le P(A) \le 1$ 
> 2. $P(S) = 1$ e $P(∅) = 0$ 
> 3. $P(A∪B)=P(A)+P(B) - P(A ∩ B)$ 
> 

Il terzo assioma afferma che la probabilità che si verifichi o $A$ o $B$ è uguale alla probabilità di $A$ più la probabilità di $B$ meno la probabilità che si verifichino entrambe. Usando il formalismo logico questo assioma può essere riscritto così: $P(A ∨ B) = P(A) + P(B) − P(A ∧ B)$

La distribuzione di probabilità è detta **uniforme** se tutti gli eventi sono equiprobabili

---
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
 
---
##### Regola di Bayes
Dalla definizione di probabilità condizionata, si ricava la regola di Bayes, importante in molti campi come quello dell'intelligenza artificiale. 
![[Pasted image 20241221153715.png]]
Come possiamo notare in questa immagine la probabilità di un evento A condizionata dal verificarsi di un evento B è uguale alla probabilità di un evento B condizionata da un evento A ovvero $P(A ∧ B) = P(B ∧ A)$, da qui nasce la **regola di Bayes** ovvero:

> [!TIP] Regola di Bayes
> $P(B|A) = \frac{ P(A|B) * P(B) }{ P(A) }$ 

Arriviamo a questa formula in questo modo:
![[Pasted image 20241221155532.png]]

La regola di Bayes ci permette quindi di calcolare $P(B|A)$ usando solo:
- $P(A)$
- $P(B)$
- $P(A|B)$
**Esempio**: 
- $P(E) = \frac{1}{10}$ ; $P(S) = \frac{4}{10}$ ;  $P(S|E) = \frac{7}{10}$ 
Quindi $P(E|S) = \frac{P(S|E) \cdot P(E)}{P(S)} = \frac{\frac{7}{10} \cdot \frac{1}{10}}{\frac{4}{10}} = \frac{7}{40}$ 

---
##### Teorema della probabilità totale
Qualche volta il calcolo della probabilità di un evento deve mettere in conto più processi casuali. 

**Teorema:**
Sia A un evento e siano $B_1,B_2,...,B_n$ eventi mutuamente esclusivi tali che $P(B_i) \not=  0$ per ogni i ed inoltre $P(B_1 || B_2 ||...|| B_n) = 1$

> [!TIP] Formula della probabilità totale
> $P(A) = P(A|B_1)P(B_1) + P(A|B_2)P(B_2) + \cdots + P(A|B_n)P(B_n) = \sum_{i=1}^{n} P(A|B_i)P(B_i)$ ovvero la sommatoria di tutte le probabilità che A accada se $B_i$ accade 

**Dimostrazione**
Dal momento che gli eventi $B_1,B_2,...,B_n$ sono esaustivi ovvero almeno una di loro si deve verificare. Siccome sono anche [[#^81d10b|mutualmente esclusivi]] la probabilità che $A$ si verifichi è la somma che sia $A$ che $B_i$ si verifichi ovvero:
- $P(A) = P(A \cap B_1) + \cdots + P(A \cap B_n)$
Dalla definizione di probabilità condizionata sappiamo che per ogni i:
- $P(A \land B_i) = P(A|B_i) \cdot P(B_i)$ 
  ![[Pasted image 20241221173203.png]]
  La formula che usiamo la ricaviamo in questo modo.
A questo punto il teorema è dimostrato

> [!EXAMPLE] Esempio:
>Supponiamo di divedere un mazzo di carte (52 carte) in due mazzi:
> - $M_1$ con $30$ carte
> - $M_2$ con $22$ carte
> Supponiamo che in $M_1$ ci siano 3 dei 4 assi.  Mentre in $M_2$ c'è il quarto asso. Scegliendo un mazzo a caso quale è la probabilità di pescare un asso? (definiamo questa probabilità con $P(A)$:
> - $P(M_1) = \frac{1}{2}$ probabilità di scegliere $M_1$ tra i due mazzi.
> - $P(M_2) = \frac{1}{2}$ probabilità di scegliere $M_2$ tra i due mazzi.
> - $P(A|M_1) = \frac{3}{30} = \frac{1}{10}$ probabilità di prendere un asso scegliendo il mazzo $M_1$ 
> - $P(A|M_2) = \frac{1}{22}$ probabilità di prendere un asso scegliendo il mazzo $M_1$
> per il teorema della probabilità totale:
> $P(A) = P(M_1) * P(M_2) * P(A|M_1) * P(A|M_2) = \frac{3}{30} \cdot \frac{1}{2} + \frac{1}{22} \cdot \frac{1}{2} = \frac{4}{55}$

---
##### Problemi d'urna
Tutti gli eventi che si possono formalizzare come "Estraiamo una o più palline numerate, da una o più urna" vengono detti **Problemi d'urna**. É importante che le estrazioni siano non truccate e che ogni estrazione sia indipendente dalla precedente. Le estrazioni da un'urna si possono classificare in 4 modi:
![[Pasted image 20250115190826.png]]
Attraverso i problemi dell'urna possiamo rispondere alla seconda domanda iniziale:
**Risposta 2**:  ^b95d26
- La probabilità di sbagliare il primo tentativo è $\frac{10^5-1}{10^5}$ 
- La probabilità di sbagliare il secondo  tentativo è $\frac{10^5-2}{10^5-1}$
- La probabilità di sbagliare il terzo tentativo è $\frac{10^5-3}{10^5-2}$ 
la probabilità totale diventa:
![[Pasted image 20241224143645.png]]

---
##### Paradosso del compleanno
Di seguito risponderemo alla domanda 4 posta all'inizio, ovvero "Se dovessi scommettere che in un’aula con 20 persone, ce ne siano almeno 2 che fanno il compleanno lo stesso giorno, scommetterei di si oppure no? E se ce ne sono 30, 40, 50 o più di persone?". In pratica ci stiamo chiedendo se dato un certo numero di persone la probabilità che 2 di esse facciano il compleanno lo stesso giorno sia maggiore di $\frac{1}{2}$. Questo problema è noto con il nome di **paradosso del compleanno** non perché genera un paradosso ma perché la risposta è apparentemente controintuitiva.

> [!TIP]
> Per il **pigeonhole principle** potremo dire che in un'aula con 366 persone di sicuro almeno 2 fanno il compleanno lo stesso giorno 

**Rispondiamo prima a** "Qual è il numero minimo di persone presenti in un aula tale che la probabilità che due di esse siano nate lo stesso mese è maggiore di $\frac{1}{2}$"
> [!TIP]
> Per il **pigeonhole principle** potremo dire che in un'aula con 13 persone di sicuro almeno 2 fanno il compleanno lo stesso mese

Assumiamo che $n$ sia uguale a $3$. Quindi abbiamo tre persone $p_1$,$p_2$ e $p_3$ ed ognuna di esse può essere nata in uno dei $12$ mesi. Il numero di terne ( {mese di nascita di $p_1$, mese di nascita di $p_2$, mese di nascita di $p_3$} ) possibili è dato dal numero di disposizioni semplici ovvero $12^3 = 1728$ (numero casi totali). Il numero di casi dove tutti e 3 i mesi sono diversi è:
- $3! \cdot \binom{12}{3} = 3! \cdot \frac{12!}{3!9!} = 12 \cdot 11 \cdot 10 = 1320$ 
  Moltiplichiamo tutto per $3!$ perché sono 6 le combinazioni che possiamo fare dati 3 mesi.
La probabilità che tre persone siano nate in un mese diverso con $n = 3$ è $\frac{1320}{1728} = 0,76$  

Ritornando alla domanda inziale, dobbiamo prendere in esame i casi in cui in aula ci siano meno di 366 persone. Calcoliamo la probabilità che facciano tutti il compleanno in giorno diverso e partiamo dal caso peggiore ovvero un anno bisestile:
- Se $n = 2$ abbiamo $365$ su $366$ giorni possibili per la seconda, se devono essere giorni diversi. Quindi, la probabilità che siano nati in giorni diversi è $\frac{365}{366} = 0, 997$.
- Se $n = 3$ abbiamo $365$ su $366$ giorni possibili per la seconda, e $364$ su $366$ per la terza, se devono essere giorni diversi. Quindi, la probabilità che siano nati in giorni diversi è $\frac{365·364}{366^2} = 0,991$ 
> [!TIP] Formula paradosso del compleanno
> Se abbiamo $p$ persone la formula che usiamo per calcolare la probabilità che siano nate in giorni diversi è:
> - $P_d(p) = \frac{p! \cdot \binom{366}{p}}{366^p}$
> Quindi la formula per calcolare la probabilità che almeno 2 persone facciano il compleanno lo stesso giorno è:
> - $P(p) = 1 - P_d(p) = 1 - \frac{365 \cdot 364 \cdot \ldots \cdot (366 - p + 1)}{366^{p-1}}$ 

> [!Example] Esempio
> Per $p$ = 23
> $P_d(23) = \frac{365 \cdot 364 \cdot \ldots \cdot 344}{366^{22}} \approx 0.48$
> $P(23) = 1 - 0.48 = 0.52$

**Risposta 4**: Dall'esempio qua sopra capiamo che basterebbero 23 persone scelte a caso per avere più del 50% di probabilità che 2 persone facciano il compleanno lo stesso giorno. ^dabca4

---
##### Variabile casuale o valore atteso

**Variabile Casuale**
Una **variabile casuale** è una funzione che associa ad ogni risultato possibile di un esperimento casuale un numero reale. In altre parole, ogni volta che si verifica un evento nel contesto di un esperimento (per esempio, lanciando un dado), la variabile casuale restituisce un valore numerico. Un esempio classico è il lancio di un dado. In questo caso, la variabile casuale **X** può rappresentare il numero che appare sulla faccia del dado. Quindi, quando lanci il dado, **X** prenderà uno dei seguenti valori: 1, 2, 3, 4, 5 o 6.

**Valore Atteso**
Il **valore atteso** (o **media ponderata**) di una variabile casuale è il valore medio che ti aspetti di ottenere se ripeti l'esperimento un numero molto grande di volte. È un concetto che descrive la "tendenza centrale" della variabile casuale. 

Per calcolare il valore atteso $E[X]$ di una variabile casuale **X**, moltiplichi ogni valore possibile che **X** può assumere per la probabilità che quel valore si verifichi e poi sommi tutti i risultati. La formula è la seguente:

> [!TIP] Formula per il calcolo del valore atteso
> $E[X]= \sum_{x} x \cdot P[X = x]$
> 
> Dove:
> - $x$ è un possibile valore che la variabile casuale **$X$** può assumere.
> - $P[X=x]$ è la probabilità che $**X**$ assuma il valore $x$.

> [!EXAMPLE] Lancio di un Dado
>Nel caso del lancio di un dado, la variabile casuale $X$ rappresenta il numero che appare sulla faccia del dado. I possibili valori di $X$ sono 1, 2, 3, 4, 5, e 6, e ognuno ha una probabilità di $\frac{1}{6}$ di verificarsi, perché il dado è equilibrato. Per calcolare il valore atteso $E[X]$: 
> $E[X] = 1 \cdot P[X = 1] + 2 \cdot P[X = 2] + 3 \cdot P[X = 3] + 4 \cdot P[X = 4] + 5 \cdot P[X = 5] + 6 \cdot P[X = 6]$
> Poiché la probabilità di ciascun numero è $\frac{1}{6}$, otteniamo: 
> - $E[X] = 1 \cdot \frac{1}{6} + 2 \cdot \frac{1}{6} + 3 \cdot \frac{1}{6} + 4 \cdot \frac{1}{6} + 5 \cdot \frac{1}{6} + 6 \cdot \frac{1}{6}$ 
> Semplificando, otteniamo: 
> - $E[X] = \frac{1 + 2 + 3 + 4 + 5 + 6}{6} = \frac{21}{6} = 3.5$ 
> Quindi, il valore atteso del lancio di un dado è **3.5**. Questo significa che, in media, se lanci un dado un numero molto grande di volte, il valore medio dei risultati sarà **3.5**.

---
 
**Linearità del Valore Atteso**
Una delle proprietà importanti del valore atteso è che è **lineare**, cioè: 
- $E[X + Y] = E[X] + E[Y]$ 
Questo significa che se hai due variabili casuali **X** e **Y**, e le sommi, il valore atteso della somma sarà la somma dei valori attesi delle singole variabili. Per esempio, supponiamo di avere due variabili casuali: **X**, che rappresenta il lancio di un dado, e **Y**, che rappresenta un altro lancio di dado. Se calcoliamo il valore atteso della somma $X + Y$, avremo: $E[X + Y] = E[X] + E[Y]$ Poiché ciascun dado ha valore atteso **3.5**, allora: $E[X + Y] = 3.5 + 3.5 = 7$.
Quindi, se sommiamo i risultati di due lanci di dado, ci aspettiamo che la media dei risultati sia **7**.

> [!Example] Esempio
> **Domanda:** Se lanciamo 2 dadi, qual è il valore atteso del massimo dei 2 valori.
> 
> In questo caso abbiamo quindi 36 casi possibili $\{(1,1),(1,2),...,(6,5),(6,6)\}$:
> - Di coppie con "6" ne abbiamo 11 
> - Di coppie con "5" ma senza "6" ne abbiamo 9 
> - Di coppie con "4" ma senza "5" o "6" be abbiamo 7 
> - Di coppie con "3" ma senza "4", "5", o "6" ne abbiamo 5 
> - Di coppie con "2" ma senza "3", "4", "5" o "6" ne abbiamo 3 
> - Di coppie con solo "1" ne abbiamo solo 1.
> 
> Quindi:
> ![[Pasted image 20241224154745.png]]
> 

---
##### Prova di Bernoulli
La prova di Bernoulli è un esperimento probabilistico che ha esattamente due risultati: **successo(p)** o **fallimento(q = 1 - p)**.
Il numero atteso dei numeri di tentativi da fare per ottenere “successo” è dato da 1/p.
**Esempi:**
![[Pasted image 20241226143158.png]]

Dunque **la legge dei grandi numeri** detta anche **teorema di Bernoulli** ci garantisce che la media dei risultati ottenuti dopo un grande numero di tentativi si avvicina al valore atteso, quindi se lanciamo all’infinito un dado, la media ottenuta
sarà esattamente $3,5$. 

---

## `Giochi e paradossi probabilistici`

Questo parte esplora quattro famosi paradossi probabilistici: il paradosso dei due bambini, il paradosso delle tre carte (o scatole), il paradosso dei tre prigionieri e il paradosso di Monty Hall.

###### 1. Paradosso dei Due Bambini

*   **Problema:** Un professore di probabilità ha due figli. Uno di loro è un maschio. Qual è la probabilità che anche l'altro figlio sia maschio?
*   **Soluzione:** Ci sono quattro possibili combinazioni di genere per due figli: FF, FM, MF, MM. Sapendo che almeno uno è maschio, escludiamo FF. Rimangono tre possibilità: FM, MF, MM. Solo una di queste (MM) vede entrambi maschi. Quindi la probabilità è 1/3.

---
###### 2. Paradosso delle Tre Carte (o Scatole)

*   **Problema (Versione Carte):** Ci sono tre carte: una rossa su entrambi i lati (R), una bianca su entrambi i lati (B) e una rossa da un lato e bianca dall'altro (M). Si sceglie una carta a caso e si mostra un lato. Se il lato visibile è rosso, qual è la probabilità che anche l'altro lato sia rosso?
*   **Problema (Versione Scatole):** Ci sono tre scatole: una con due monete d'oro (G2), una con due monete d'argento (A2) e una con una moneta d'oro e una d'argento (AG). Si sceglie una scatola a caso e si estrae una moneta. Se la moneta estratta è d'oro, qual è la probabilità che anche l'altra moneta nella scatola sia d'oro?
*   **Soluzione:** Concentrandoci sulla versione delle carte, ci sono sei possibili scenari considerando entrambi i lati di ogni carta (Ra, Rb, Ma, Mb, Ba, Bb). Se il lato visibile è rosso, le possibilità sono Ra, Rb, Ma. Di queste, due (Ra, Rb) hanno anche l'altro lato rosso. Quindi la probabilità è 2/3.

---
###### 3. Paradosso dei Tre Prigionieri

*   **Problema:** Tre prigionieri (A, B, C) sono condannati a morte. Il re ne grazierà uno a caso. Il carceriere sa chi sarà graziato. A chiede al carceriere di dirgli quale tra B e C sarà giustiziato. Il carceriere dice che sarà giustiziato B. A pensa che ora la sua probabilità di essere graziato sia aumentata da 1/3 a 1/2.
*   **Soluzione:** Prima della risposta del carceriere, la probabilità di A di essere graziato è 1/3. Ci sono due scenari in cui il carceriere dice che B sarà giustiziato:
    *   C è graziato (probabilità 1/3).
    *   A è graziato e il carceriere sceglie B a caso (probabilità 1/3 * 1/2 = 1/6).
La probabilità totale che il carceriere dica che B sarà giustiziato è 1/3 + 1/6 = 1/2.
Dato che il carceriere ha detto che B sarà giustiziato, la probabilità che C sia graziato è (1/3) / (1/2) = 2/3, mentre la probabilità che A sia graziato è (1/6) / (1/2) = 1/3. Quindi A si sbaglia.

---
###### 4. Paradosso di Monty Hall

*   **Problema:** Ci sono tre porte. Dietro una c'è un'auto, dietro le altre due ci sono delle capre. Il concorrente sceglie una porta. Il conduttore (che sa dove si trova l'auto) apre una delle altre due porte, rivelando una capra. Il conduttore offre al concorrente la possibilità di cambiare la sua scelta con la porta rimanente. Conviene cambiare?
*   **Soluzione:** Sì, conviene cambiare. Inizialmente, la probabilità di scegliere la porta con l'auto è 1/3. Quindi, la probabilità che l'auto sia dietro una delle altre due porte è 2/3. Quando il conduttore apre una porta con una capra, quella probabilità (2/3) si concentra sulla porta rimanente.

--- 
###### Domanda Finale
*   **Problema:** Ci sono 10 buste, una contiene un milione di euro, le altre sono vuote. Si sceglie la busta numero 1. Conviene scambiarla con le altre 9? E se qualcuno apre 8 delle altre 9 buste, rivelando che sono vuote, conviene scambiare la busta 1 con l'unica rimasta?
*   **Risposta:** Inizialmente, la probabilità di avere il milione è 1/10. Scambiare con le altre 9 aumenta la probabilità a 9/10. Dopo che 8 buste vuote sono state aperte, la probabilità che il milione sia nella busta rimanente è diventata 9/10, mentre la probabilità che sia nella busta 1 è ancora 1/10. Quindi, conviene decisamente scambiare.

Questo riassunto fornisce una panoramica dei concetti chiave discussi nel documento, evidenziando i problemi, le soluzioni e le logiche alla base di ciascun paradosso.

### 03_Parte3Teoria



#### Disposizioni e combinazioni
Proviamo adesso a rispondere alle seguenti 4 domande puramente matematiche:
1. Dati due insiemi $A$ e $B$, con $|A| = k, |B| = n$ quante sono le [[Uni/Primo anno/strutture-discrete/FileRielaborazioni/Tips#Differenza tra applicazione e funzione|applicazioni]] di $A$ in $B$?
	- Il numero delle ==disposizioni con ripetizione== di $n$ elementi di classe $k$: denotato con: 
		- **$D_{n,k}^r$** 
1. Dati due insiemi $A$ e $B$, con $|A| = k, |B| = n$ quante sono le applicazioni iniettive di $A$ in $B$?
	- Numero delle ==disposizioni semplici== di $n$ elementi di classe $k$ denotato con:
		- $D_{n,k}$ 
1. Dato un insieme $B$, con $|B| = n$, e preso un intero $k ≤ n$, quanti sono i sottoinsiemi di $B$ composti di $k$ elementi ?
	  - Numero delle combinazioni di $n$ elementi di classe $k$: denotato con 
		  - $C_{n,k}$
1. Dato un insieme di $n$ variabili, $\{x_1, x_2, . . . , x_n\}$ e preso un un intero $k ≤ n$, quanti sono i monomi, con coefficiente $1$, di grado $k$ definiti sulle $n$ variabili date?
   Esempio: $x^2_1 x_3 x^3_4$ monomio di grado $6$, $x_2^2 x_4 x_5$ monomio di grado $4$.
	- Numero delle combinazioni di $n$ elementi di classe $k$ con ripetizione: denotato con:
		- $C^r_{n,k}$ 
##### Disposizioni con ripetizione
Per calcolare $D_{n,k}^r$ utilizziamo la regola del prodotto, infatti per ognuno dei $k$ elementi di $A$ dobbiamo scegliere uno tra gli elementi di $B$, ogni scelta è indipendente dalle scelte fatte precedentemente, questo perché il primo elemento di $A$ ha $n$ scelte per la sua immagine in $B$ stessa cosa vale anche per l'n-esimo elemento di $A$. Quindi il numero di disposizioni con ripetizione è $n$ moltiplicato $k$ volte per se stesso ovvero 
- $n^k$ 
![[Pasted image 20241214111501.png]]
##### Disposizioni semplici
Come prima cosa, notiamo che affinché esista un’[[01_Parte1#Funzione iniettiva|applicazione iniettiva]] da $A$ in $B$, con $|A| = k$ e $|B| = n$ deve essere $n ≥ k$. Per calcolare $D_{n,k}$ utilizziamo la regola del prodotto. Dobbiamo fare $k$ operazioni di scelta, tali che:
- La prima operazione si può fare in $n$ modi
- La seconda in $n-1$ modi
- La k-esima operazione si può fare in $n-k + 1$ modi
l'intera operazione, ovvero il numero di scelte totali è:
- $D_{n,k} = n(n-1)*\dots*(n-k+1) = \frac{n!}{(n-k)!}$ 

**Risposta 5**: Quante squadre di calcio diverse posso formare da un gruppo di 50 studenti?
![[Pasted image 20241214133049.png]]

##### Permutazioni
Il numero di permutazioni semplici o sostituzioni è il numero di disposizioni semplici di classe $n$ cioè $D_{n,n} = \frac{n!}{(n-n)!}$ ovvero $n!$ 
Quindi il numero delle Permutazioni è il numero delle [[01_Parte1#Funzione iniettiva|applicazione iniettiva]] di un insieme in un altro di cardinalità uguale. Queste applicazioni sono ovviamente anche [[01_Parte1#^cc7f98|surgettive]] e quindi il numero delle permutazioni è il numero delle [[01_Parte1#Funzione biiettiva|biiezioni]] di un insieme in un altro della stessa cardinalità.
![[Pasted image 20241214150710.png]]

##### Combinazioni
Consideriamo l'insieme di tutte le $D_{n,k}$ applicazioni iniettive di un insieme $A$ di $k>0$ elementi in un insieme $B$ di $n$ elementi($k \le n$). Data una qualunque applicazione iniettiva $f$ la sua [[01_Parte1#^329b13|immagine]] è un sottoinsieme di $B$ che contiene $k$ elementi (ovvero tutti i valori che la funzione potrà assumere che saranno proprio $k$ visto che la funzione iniettiva associa ad ogni elemento di B solo elemento di A). Da questa premessa introduciamo la seguente [[01_Parte1#^927242|relazione di equivalenza]]:
- f ≈ g ⇔ f(A) = g(A)
Quindi due applicazioni si dicono equivalenti se hanno la stessa immagine. Le possibili classi di equivalenza sono tante quanti i sottoinsiemi di B costituiti da $k$ elementi, che denoteremo con $C_{n,k}$ quindi $D_{n,k}$ = $C_{n,k}$ · $k!$ da cui ricaviamo che $C_{n,k}$ = $\frac{n!}{k!(n-k)!}$. I valori $n,k$ sono anche detti coefficienti binomiali e sono indicati con il simbolo: $\binom{n}{k} = \frac{n!}{k!(n-k)!}$ 
##### Combinazione con ripetizione
Dato un insieme di $n > 1$ variabili, $\{x_0, x_1, . . . , x_{n−1}\}$ e preso un un intero k, i monomi di grado $k$ sono $C_{n,k}^r = \binom{n+k-1}{k}$ 

### 04_Parte4


Questo file è la rielaborazione delle slide [[04_Parte4]]
## `Teoria dei grafi`
La teoria dei grafi inizia per risolvere un problema reale, chiamato problema dei sette ponti, questi ponti sono situati in una città Russa attraversata da un fiume e presenta due isolette che sono collegate con le aree principali della città con 7 ponti. Il nostro caro Eulero era in città e venne a sapere di questo problema: “E’ possibile fare una passeggiata che
attraversi ogni ponte una sola volta?”
![[Pasted image 20250107153947.png|500]]
Eulero sintetizza il tutto in termini astratti, assegnando ad ogni area della città un nodo e ad ogni ponte un arco.

---
###### Definizione di grafo non orientato
Un grafo semplice non orientato denotato con $G = (V,E)$ è formato da:
- un insieme finito di **nodi/vertici** ($V$) 
- un insieme finito di **archi** ($E$) 
dove ogni elemento di $E$ è un sottoinsieme di cardinalità 2 di $V$ fatto in questo modo $e_k = \{i,j\}$ con $i,j \in V$
- Due nodi che caratterizzano l’arco sono detti "**estremi dell’arco**" e si dicono adiacenti
- Un arco che ha come estremo il nodo $i$ si dice "**incidente**" ad $i$.
- Un vertice che non è l’estremo di alcun arco si dice "**isolato**".

---
###### Definizione di grafo orientato
Un grafo semplice orientato denotato con $G = (V,E)$ consiste:
- un insieme finito di **nodi/vertici** $(V)$
- un insieme finito di **archi** $(E)$
in questo caso però gli elementi che appartengono ad $E$ sono delle coppie ordinate. Di conseguenza gli archi avranno un verso.
Gli archi del tipo $(i,i)$ ovvero degli archi orientati da un nodo verso se stesso vengono detti **cappi**.

---
###### Rappresentazione dei grafi
Rappresentiamo i grafi nel piano in questo modo
![[Pasted image 20250107160321.png| 500]]
Come possiamo notare da questa rappresentazione gli archi dei grafi orientati hanno una direzione.

---

**Multigrafi**
I grafi dove troviamo più di un arco che collega coppie di nodi sono detti "multigrafi".
![[Pasted image 20250107160523.png|500]]

---
###### Grado di un nodo
Dato un grafo $G = (V,E)$ il grado di un nodo $v$ denotato con $\delta(v)$ è il numero di archi ad esso incidenti ovvero: 
- $\delta(v) = |\{e \in E : v \in e\}|$ il grado del vertice $v$ è uguale al numero di archi $e$ nell'insieme $E$ (insieme di tutti gli archi del grafo) tali che il vertice $v$ è uno degli estremi dell'arco $e$ 

Dato un grafo orientato $G = (V,E)$ abbiamo 2 definizione differenti di grado di un nodo:
- **Grado di ingresso $δ^−(v )$**: ovvero il numero di archi orientati che "entrano" in $v$
	- $\delta^-(v) = |\{e \in E : e = (w, v) \text{ per qualche } w \in V\}|$  il grado di ingresso del nodo $v$ è pari alla cardinalità dell'insieme formato da tutti gli archi del tipo $(w,v)$
- **Grado di uscita $δ^+(v )$**: ovvero il numeri di archi orientati che "escono" da $v$
	- $\delta^+(v) = \{e \in E : e = (v, w) \text{ per qualche } w \in V\}$ il grado di uscita del nodo $v$ è pari alla cardinalità dell'insieme formato da tutti gli archi del tipo $(v,w)$ 


> [!EXAMPLE] Esempio con grafo non orientato
> ![[Pasted image 20250107162313.png]]
> Di seguito i gradi dei vari nodi di questo grafo non orientato:
> - $\delta(1) = 2$
> - $\delta(2) = 3$
> - $\delta(3) = 2$
> - $\delta(4) = 3$
> - $\delta(5) = 3$
> - $\delta(6) = 1$
> - δ(1) + δ(2) + δ(3) + δ(4) + δ(5) + δ(6) = 2 + 3 + 2 + 3 + 3 + 1 = 14

> [!EXAMPLE] Esempio con grafo orientato
>  ![[Pasted image 20250107162647.png]]
>  Di seguito i gradi dei vari nodi di questo grafo non orientato:
> *   $\delta^-(1) = 0$
> *   $\delta^-(2) = 2$
> *   $\delta^-(3) = 3$
> *   $\delta^-(4) = 2$
> *   $\delta^-(5) = 0$
> $δ^−(1) + δ^−(2) + δ^−(3) + δ^−(4) + δ^−(5) = 0 + 2 + 3 + 2 + 0 = 7$
> *   $\delta^+(1) = 2$
> *   $\delta^+(2) = 2$
> *   $\delta^+(3) = 0$
> *   $\delta^+(4) = 1$
> *   $\delta^+(5) = 2$
> $δ^+(1) + δ^+(2) + δ^+(3) + δ^+(4) + δ^+(5) = 2 + 2 + 0 + 1 + 2 = 7$

Da questi esempi notiamo che:
- **Grafo non orientato:** la somma di tutti i gradi è il doppio del numero degli archi
- **Grafo orientato:** la somma dei gradi in ingresso è uguale alla somma dei gradi in uscita, e la somma totale è il doppio del numero degli archi del grafo.

---
###### Handshaking Theorem
Sia $G = (V, E)$ un grafo non orientato allora la somma dei gradi di ogni vertice è uguale al doppio del numero degli archi.

---
###### Grafi regolari
Dato un grafo non orientato $G = (V,E)$ si dice regolare se tutti i suoi nodi hanno lo stesso grado $r$, la cardinalità di $V$ ovvero il numero di vertici del grafo è uguale a:
- $|V| = \frac{2|E|}{r}$

> [!EXAMPLE] Esempio
Consideriamo un grafo regolare con 4 vertici $(V = {A, B, C, D})$ e grado 2 (r = 2). Ciò significa che ogni vertice è connesso a esattamente altri due vertici. Un esempio potrebbe essere un quadrato, dove ogni vertice è connesso ai due vertici adiacenti. In questo caso ci sono 4 spigoli $(E = {(A,B), (B,C), (C,D), (D,A)})$, quindi |E| = 4.
Applicando la formula:
$|V| = (2 * 4) / 2 = 8 / 2 = 4$

---
###### Grafi completi
Diciamo che $G = (V,E)$ è completo se ogni coppia di vertici è connessa da un arco. Se $|V| = n$  allora il numeri di archi del grafo completo è $\binom{n}{2}$ ovvero il numero di tutte le possibili coppie di vertici.
![[Pasted image 20250107165841.png]]

---
###### Torneo
Sia $G = (V,E)$ un grafo completo. Il grafo orientato ottenuto assegnando uno dei due possibili versi ad ogni arco di $G$, si dice **torneo**, l'arco tra ogni coppia è orientato dal vincitore al perdente
![[Pasted image 20250107184745.png]]

---
###### Grafi orientati completi
La definizione di grafo completo si estende anche ai grafi orientati, sia $G = (V, E)$ un grafo orientato diciamo che è completo se ogni coppia ordinata è connessa da un arco, ovvero per ogni coppia di vertici $i,j \in V$ abbiamo $(i,j) \in E$ e $(j,i) \in E$ 
![[Pasted image 20250108091716.png]]

---
###### Grafi bipartiti
Sia $G = (V,E)$ un grafo non orientato. Diciamo che $G$ è bipartito se possiamo partizionare $V$ (l'insieme dei vertici) in 2 insiemi solitamente denotati con $V_1$ e $V_2$ in maniera tali che tutti gli archi abbiano un estremo in entrambi gli insiemi $V_1$ e $V_2$
![[Pasted image 20250108093247.png|500]]

---
###### Grafi bipartiti completi
Il grafo bipartito si dice completo se definita la partizione dei vertici $V_1$ e $V_2$ esiste un arco per ogni coppia di vertici $v \in V_1$ e $u \in V_2$. Un grafo bipartito completo si indica con $K_{n,m}$ dove $n = |V_1|$ e $m = |V_2|$ 
![[Pasted image 20250108093838.png|500]]

---
###### Sottografo
Sia $G = (V,E)$ un grafo non orientato. Diciamo che $G' = (V',E')$ è un sottografo di $G$ se:
- $V' ⊆ V$
- $E' ⊆ E$
- Ogni arco $(u,v) \in E'$ ha i suoi estremi entrambi in $V'$
![[Pasted image 20250108094710.png|500]]
Questa stessa regola vale anche per i grafi orientati, ovviamente i sottografi che possiamo creare saranno anche essi orientati.
![[Pasted image 20250108095044.png|500]]
**Sottografo indotto**
Sia $G = (V,E)$, dato $V'⊆ V$. Il sottografo indotto da $V'$ è il sottografo $G = (V',E')$ ottenuto eliminando da $G$ tutti i vertici non appartenenti a $V'$ e tutti gli archi incidenti ad almeno uno dei vertici eliminati
![[Pasted image 20250108095847.png |500px]]

---
###### Grafi isomorfi
Di seguito cercheremo di rispondere alla domanda: "In che modo 2 grafi possono essere considerati uguali?"

**Definizione di Isomorfismo tra grafi**:
Due grafi $G_1 = (V_1,E_1)$ e $G_2 = (V_2, E_2)$ si dicono isomorfi se esiste una applicazione biunivoca $f$ dall'insieme dei vertici $V_1$ all'insieme dei vertici $V_2$ tale che ($f(u), f(v)$) è un arco di $E_2$ se e solo se $(u,v)$ è un arco di $E_1$

> [!EXAMPLE] Esempio
> ![[Pasted image 20250108101029.png|500]]

Come immediata conseguenza sappiamo che:
- $|V_1| = |V_2|$ e $|E_1| = |E_2|$ 
- essendo $f(u) = v$ allora $\delta(u)=\delta(v)$ nel caso di grafi non orientati, e $\delta^+(u) = \delta^+(v)$ e $\delta^-(u) = \delta^-(v)$ nel caso di grafi orientati
- dato un sottografo del primo grafo esiste un sottografo del secondo a cui è isomorfo

> [!EXAMPLE] Esempio
> ![[Pasted image 20250108101921.png]]
> Questi 2 grafi hanno lo stesso numero di vertici e archi, però notiamo subito che **non sono isomorfi** perché nel grafo $G_1$ il vertice 2 ha gradi uscita pari a 2 mentre nessun vertice in $G_1$ ha questo grado di uscita. 

---
###### Omeomorfismi
Di seguito cercheremo di rispondere alla seguente domanda: "in che modo 2 grafi possono essere interpretati come aventi la stessa forma?"


**Definizione di suddivisione di un arco non orientato**
Sia $G = (V,E)$ un grafo non orientato e sia $e = (u,v)$ un arco di G. Una suddivisione dell'arco $e = (u,v)$ è ottenuta introducendo un nuovo vertice w e sostituendo in $G$ l'arco $(u, v)$ con gli archi $e_1 = (u, w)$ e $e_2 = (w, v)$   
![[Pasted image 20250108104746.png]]


**Definizione di suddivisione di un arco orientato**
Sia $G = (V,E)$ un grafo orientato e sia $e = (u,v)$ un arco di G. Una suddivisione dell'arco $e = (u,v)$ è ottenuta introducendo un nuovo vertice w e sostituendo in $G$ l'arco orientato $(u, v)$ con gli archi orientati $e_1 = (u, w)$ e $e_2 = (w, v)$
![[Pasted image 20250108104957.png]]

**Omeomorfismo tra grafi**
Due grafi non orientati $G_1 = (V_1,E_1)$ e $G_2 = (V_2,E_2)$ si dicono omeomorfi se attraverso una serie di suddivisioni di archi $G_1$ e $G_2$ si possono ottenere due grafi $G^{'}_1$ e $G^{'}_2$ che sono isomorfi
![[Pasted image 20250108112648.png]]
Questa stessa definizione si estende ai grafi orientati tenendo però presente la suddivisione di un arco orientato in 2 archi orientati.

---
###### Percorso
Un percorso in un grafo $G = (V,E)$ è una sequenza di nodi $v_1,...,v_k$ adiacenti ossia tali che per ogni $1 \leq i < k$ avrò una coppia $(v_i, v_{i+1})$ che è un arco del grafo.
- il nodo $v_1$ è detto **nodo origine**
- il nodo $v_k$ è detto **nodo destinazione**
- i nodi $v_i$ con $1 \leq i < k$ sono detti **nodi intermedi**
La lunghezza di un percorso è il numero di archi che lo compongono, ovvero $k - 1$
![[Pasted image 20250108113605.png]]
Il percorso cambia leggermente nel caso di un grafo orientato, infatti in questo caso ogni arco si può percorrere seguendo il suo verso.
![[Pasted image 20250108113720.png]]

---
###### Cammino
Un percorso si dice cammino quando tutti i nodi che attraversa sono differenti.
![[Pasted image 20250108114619.png]]

---
###### Circuito
Un percorso si dice circuito quando è un percorso chiuso ovvero un percorso $v_1,...,v_k$ tale che $v_1 = v_k$ 
![[Pasted image 20250108115144.png]]

---
###### Ciclo
Un ciclo in un grafo $G = (V,E)$ è un circuito chiuso, ovvero un circuito dove tutti i vertici sono diversi e $v_1 = v_k$.
![[Pasted image 20250108143854.png]]

---
###### Riepilogo

> [!SUMMARY] 
> ![[Pasted image 20250108143955.png]]

---
###### Cammini e cicli
Dalle spiegazioni date ne traiamo che:
- Dato un percorso da un nodo $v$ ad un nodo $w$ possiamo costruire un cammino da $v$ a $w$ 
- Dato un circuito possiamo costruire un ciclo
![[Pasted image 20250108145040.png]]

---
###### Grafi aciclici
Un grafo si dice aciclico se non possiede cicli
![[Pasted image 20250108145609.png]]
Partendo da questi due grafi è impossibile creare un ciclo

---
###### Componenti connesse

Dato un grafo $G = (V, E)$ diciamo che due vertici $u, v$ sono connessi se esiste un cammino da $u$ a $v$

**Definizione di componenti connesse**^4e37c4
Sia $G = (V,E)$ un grafo. Consideriamo una partizione indotta dalla relazione di connessione tra i vertici $V$ che crea dei sottoinsiemi $V_1, V_2,...,V_k$ dove ciascun $V_i​$ rappresenta un insieme di vertici connessi tra loro tramite percorsi all'interno del grafo $G$. Per ogni sottoinsieme $V_i$, definiamo il sottografo $G_i = (V_i, E_i)$, dove $E_i$ è l'insieme degli archi di $E$ che collegano i vertici di $V_i$. Ciascun sottografo $G_i$​ viene detto **componente connessa** di $G$.
![[Pasted image 20250108152956.png|500]] ^116511

---
###### Grafo connesso
Un **grafo** (non orientato) si dice **connesso** se, per ogni coppia di vertici del grafo, esiste un percorso che li collega. In altre parole, il grafo ha una sola componente connessa, ovvero tutti i vertici appartengono alla stessa componente.

---
###### Grafo orientato debolmente connesso
Un grafo orientato $G = (V,E)$ di dice debolmente connesso se il grafo non orientato ottenuto eliminando da $G$ l'orientamento degli archi è connesso

> [!TIP] Grafo sottostante
> Il grafo ottenuto eliminando da un grafo orientato l'orientamento degli archi si chiama **grafo sottostante**

> [!EXAMPLE] Esempio
> ![[Pasted image 20250108153907.png]]

---
###### Componenti fortemente connesse
Dato un grafo orientato $G = (V , E)$, diciamo che due vertici $u, v$ sono fortemente connessi se esiste sia un cammino da $u$ a $v$ che un cammino da $v$ ad $u$.

**Definizione di Componenti fortemente connesse**
La definizione è molto simile a [[04_Parte4#^116511|questa]] cambia solo che la relazione viene indotta dalla relazione di connessione forte e che i sottografi finali si chiamano componenti fortemente connesse di G.
![[Pasted image 20250108155731.png]]

---
###### Grafo orientato fortemente connesso
Sia $G = (V,E)$ un grafo orientato. $G$ si dice fortemente connesso se ha una sola componente fortemente connessa.
![[Pasted image 20250108160028.png]]

---
###### Grafi k-connessi
Dato un grafo $G = (V,E)$:
- Il grafo $G$ si dice k-connesso rispetto agli archi se dati comunque due vertici $u, v ∈ V$ esistono $k$ cammini ad archi disgiunti tra $u, v$. 
- Il grafo $G$ si dice k-connesso rispetto ai vertici se dati comunque due vertici $u, v ∈ V$ esistono k cammini a nodi disgiunti tra $u, v$.
Dalla definizione di k-connessione rispetto agli archi si deduce che per disconnettere il grafo è necessario rimuovere almeno k archi. Dalla definizione di k-connessione rispetto ai vertici si deduce che per disconnettere il grafo è necessario rimuovere almeno k vertici.
---
###### Rappresentazione di un grafo come matrice
Dato un grafo $G = (V,E)$ con $|V| = n$. La matrice $M$ detta matrice di adiacenza del grafo ha dimensione $n \times n$ dove $n$ è il numero di vertici, ed è formata in questo modo:
- $M[i, j] = 1$ se i vertici $i$ e $j$ sono connessi da un arco
- $M[i, j] = 0$ se i vertici $i$ e  $j$ non sono connessi da un arco

![[Pasted image 20250108163003.png|500]]
- La somma dei valori di ogni riga è il grado del vertice $i$
- Se ci sono degli uno nella diagonale principale vuol dire che nel grafo ci sono dei cappi
- La matrice è simmetrica ovvero per ogni $i$ e $j$: $M[i, j] = M[j, i]$.
![[Pasted image 20250108163009.png|500]]
- La somma degli 1 in ogni riga è il grado in uscita del nodo corrispondente
- La somma degli 1 in ogni colonna indica il grado in entrata del nodo corrispondente
- La matrice non è simmetrica

---
###### Matrice associata alle componenti connesse
![[Pasted image 20250108165309.png]]
Come possiamo notare ogni componente connessa crea un blocco $k \times k$ dove $k$ è il numero di vertici della componente. 

---
###### Cicli in un digrafo
Sia $G = (V,E)$ un grafo orientato per ogni vertice $i \in V$ siano $\delta^+(i)$ e $\delta^-(i)$ rispettivamente il grado in uscita ed in entrata di i. Se per ogni $i \in V$ siano $\delta^+(i)$ > 0 e $\delta^-(i)$ > 0 allora il grafo G contiene un ciclo
**Dimostrazione**
Dal momento che $\delta^+(i)$ > 0 esiste un vertice $i_0$ tale che esiste un arco da $i_0$ a $i_1$, stessa cosa vale per $i_1$ infatti siamo sicuri che esiste un arco da $i_1$ a $i_2$, se iteriamo questo processo sino a quando non abbiamo una sequenza di vertici $i_0,i_1,i_2,...i_n$ tali che ognuno è connesso da un arco al successivo. Se $|V| = n$ per il Pigeonhole Principle almeno 2 di questi n+1 vertici devono coincidere. Questo dimostra il teorema.

> [!EXAMPLE] Esempio
> ![[Pasted image 20250110131540.png]]
> Il grafo in figura possiede diversi cicli e, in particolare, un ciclo che coinvolge tutti i vertici: $1−5−4−6−3−7−2−1$. Come si può facilmente calcolare dalla matrice di adiacenza, il grado di ogni vertice è maggiore di zero.

Inoltre possiamo dire che un grafo orientato possiede un ciclo se un suo sottoinsieme lo possiede e quindi riscrivere il teorema così.
**Rivisitazione del teorema per il sottografo**
Sia $G = (V,E)$ un grafo orientato. Allora $G$ possiede un ciclo se e solo se esiste un sottoinsieme $V'⊆ V$, tale che il sottografo indotto $G = (V', E')$ verifica la seguente proprietà: per ogni vertice $i \in V'$ siano $\delta^+(i)$ > 0 e $\delta^-(i)$ > 0 allora ha un ciclo

---
###### Algoritmo per trovare un ciclo in un grafo
Sia $M$ la matrice del grafo, ed $M'$ la matrice ottenuta da $M$ eliminando la i-esima riga e colonna, sia inoltre $dim(M)$ la dimensione della matrice (il suo numero di righe o colonne)
1. Se controllando la matrice $M$ tutti i vertici del grafo hanno grado in uscita > 0 e grado in entrata > 0 **terminiamo e diciamo che il grafo possiede un ciclo**
2. Altrimenti, prendiamo un vertice $i$ con grado di uscita/entrata = 0 e lo eliminiamo sia dalla matrice associata al grafo creando la matrice $M'$
3. Ripeti passo 2-3
4. Se la $dim(M)$ = 1  ci fermiamo e diciamo che il grafo è aciclico

> [!EXAMPLE] Esempio
> ![[Pasted image 20250110133516.png]]
> I successivi due passi dell’algoritmi ci fanno prima eliminare il vertice 7 che ha grado in uscita ed in ingresso entrambi uguali a 0 e poi eliminare il vertice 5 che ha grado in entrata uguale a 0. Otteniamo così il sottografo in figura che verifica la condizione del teorema e quindi possiede un ciclo.
> ![[Pasted image 20250110133548.png]]
> 

---
###### Percorsi tra nodi
Dalle matrici matrice associata ad un grafo possiamo notare che la matrice ci dice se esiste un arco tra 2 vertici. Se volessimo cercare dei percorsi più lunghi?

> [!EXAMPLE] Esempio
> ![[Pasted image 20250110133835.png]]
> Non esiste un percorso di lunghezza 1 tra il 6 ed il 5 però ne esiste uno di lunghezza 2

> [!TIP] 
> Come facciamo a trovare questi percorsi più lunghi?
> Ci basta moltiplicare la matrice per se stessa tante volte quanto è la lunghezza del percorso che devo analizzare:
> - Se voglio trovare i percorsi di lunghezza 2, mi basta moltiplicare la matrice per se stessa ($M^2$)
> - Se voglio trovare i percorsi di lunghezza 3, mi basta fare la matrice cubica ($M^3$)
> - Se voglio trovare i percorsi di lunghezza $k$, basta fare $M^k$
> In questo modo siamo in grado di trovare il numero di percorsi di lunghezza arbitraria per ogni coppia di nodi


> [!EXAMPLE] Esempio
> ![[Pasted image 20250110134536.png]]
> Tra i nodi 1 e 4 non esiste un percorso di lunghezza 1, però ne esiste uno di lunghezza 2

---
###### Rappresentazione di un grafo con liste di adiacenza
Un grafo può essere rappresentato pure con le liste di adiacenza, ovvero un array i cui elementi sono i nodi e per ogni nodo viene associato un altro array con la lista dei nodi collegati ad esso. Lo spazio di cui abbiamo bisogno per rappresentare un grafo con una lista di adiacenza lo calcoliamo cosi:
- Grafo non orientato: $|V| + 2|E|$
![[Pasted image 20250110135330.png|500]]
- Grafo orientato: $|V| + |E|$
![[Pasted image 20250110135341.png|500]]

---
###### Circuito Euleriano
Un circuito euleriano è un circuito chiuso che passa per ogni ==arco== del grafo esattamente una volta. Un grafo si dice euleriano, se possiede un circuito euleriano.
> [!EXAMPLE] Esempio
> ![[Pasted image 20250110140732.png|500]]
> In questo grafo troviamo un circuito euleriano ovvero: $1-2-3-5-4-3-6-4-1$ 

> [!TIP] 
> Un qualsiasi grafo $G$ è euleriano se e solo se è connesso ed i suoi vertici hanno tutti grado pari

---
###### Cammino Euleriano
Un grafo ammette un cammino euleriano se e solo se è connesso e al massimo due dei suoi vertici hanno grado dispari. In tal caso, i vertici di grado dispari rappresenteranno il punto di inizio e il punto di fine del cammino euleriano.
> [!EXAMPLE] Esempio
> ![[Pasted image 20250110141354.png]]
> Il grafo in figura ha 2 vertici di grado dispari A e C ma possiede un cammino che passa per tutti gli archi una ed una sola volta: A − B − C − D − E − A − C

---
###### Cammino Hamiltoniano
Sia $G = (V , E)$ un grafo (digrafo) connesso. 
Un cammino hamiltoniano di $G$ è un circuito che passa una ed una sola volta per tutti i vertici di $G$. 
Se il cammino è chiuso, ovvero se è un ciclo, tale ciclo si dice **ciclo Hamiltoniano**. Un grafo si dice hamiltoniano, se possiede un ciclo hamiltoniano.
![[Pasted image 20250110143230.png]]
> [!EXAMPLE] Esempio
> ![[Pasted image 20250110142612.png]]
> Il grafo A è hamiltoniano, perché possiede il ciclo hamiltoniano $1-5-4-6-3-7-2-1$

---
###### Grafi pesati
Per poter usare i grafi come strutture dati abbiamo la necessità di associargli un peso (costo, valore), questi possono essere associati agli archi, ai nodi o ad entrambi
![[Pasted image 20250110143432.png]]
Dato un grafo pesato, il costo di un cammino può essere:
- La somma dei costi associati ai suoi archi, ovvero la somma dei costi di ogni singolo arco che attraversa.
- La somma dei costi associati ai suoi vertici, ovvero la somma dei costi di ogni singolo vertice che attraversa.
Da questo ne deduciamo che ci sono cammini che più costosi di altri.


> [!EXAMPLE]
> ![[Pasted image 20250110143659.png]]
> Nei grafi dell'esempio: il costo del cammino $5 − 4 − 2 − 1$ è:
> - per il grafo non orientato con peso sugli archi $4 + 1 + 2 = 7$
> - per il grafo orientato con peso sui vertici: $3 + 1 + 3 + 2 = 9$

> [!TIP]
> Il cammino con il costo minimo si chiama **shortest path**
> Il cammino con il costo massimo si chiama **longest path**
> 
> Parliamo di cammini perché non abbiamo ripetizioni

---
###### Rappresentazione dei grafi pesati
- **Funzione peso sugli archi**: la rappresentazione più semplice per un grafo o digrafo pesato è quella di una matrice, dove però invece di mettere 1 mettiamo il peso dell'arco, e 0 nel caso di un arco mancante.
  ![[Pasted image 20250110144758.png]]
- **Funzione peso sui vertici:** La soluzione più semplice è creare una matrice di adiacenza $M$ e ad associargli un vettore $C$ di lunghezza $|V|$ con il peso di ogni vertice
  ![[Pasted image 20250110145015.png]]
---
###### Esercizio completo sui grafi 

**Sapendo che:** Le seguenti coppie di città sono collegate da una linea aerea, che fornisce un servizio di A/R:
- Parigi-New York
- Parigi-Roma
- New York-Rio de Janeiro
- Roma-Londra
- Parigi-Londra
- Rio de Janeiro-Madrid
- Madrid-Parigi
- Madrid-Londra
**Rispondi alle seguenti domande:**
1. Qual è la strada più breve (numero di scali) da NY a Roma?
2. Quella più lunga?
3. Trovare (se esiste) un cammino che tocchi tutte le città, ossia un cammino hamiltoniano.
4. Trovare (se esiste) un ciclo che tocchi tutte le città, ossia un ciclo hamiltoniano.
5. Trovare (se esiste) un ciclo euleriano, ossia che percorre tutte le tratte una sola volta.
6. Il grafo è k-connesso? Se si, qual è il valore massimo di k?

**Rappresentazione del grafo:**
![[Pasted image 20250111112952.png]]

**Risposte alle domande:**
1. NY-PG-RM
2. NY-RJ-MD-LN-PG-RM
3. Si questo: NY-RJ-MD-LN-PG-RM
4. RM-PG-NY-RJ-MD-LN-RM
5. La trovi sotto
6. Il grado minimo di ogni vertice è 2 e quindi il grafo è 2-connesso

**Risposta alla domanda 5**: Il Teorema di Eulero ci dice che un grafo ha un ciclo euleriano se e solo se tutti i vertici hanno grado pari. I vertici LN e MD hanno grado dispari quindi la risposta è no. Però sono solo 2 i vertici di grado dispari e quindi possiamo utilizzare l’altro teorema di Eulero che ci dice che possiamo trovare un cammino euleriano che comincia da uno dei due vertici e finisce nell’altro. Ecco il cammino: LN-PG-NY-RJ-MD-PG-RM-LN-MD ^81d618

---
###### Il problema del commesso viaggiatore
Il problema del commesso viaggiatore anche conosciuto con la sigla TSP è il problema di trovare un circuito hamiltoniano che minimizza il costo totale per un grafo pesato.
![[Pasted image 20250110145941.png|500]]
Se un commesso viaggiatore deve attraversare tutti e 4 i nodi, partendo da A e tornando ad A, qual è il percorso che minimizza il costo totale, che supponiamo, per esempio, siano distanze in KM? Possiamo risolvere il problema analizzando tutti i circuiti hamiltoniani
![[Pasted image 20250110150242.png]]
Da qui capiamo che ci sono 2 circuiti che il viaggiatore potrebbe usare. All’aumentare dei nodi da attraversare aumenta esponenzialmente il tempo di risoluzione perché si devono banalmente provare più combinazioni. Nessuno ha avuto un idea per risolvere in modo migliore, quindi resta un problema aperto.

---
###### Grafi planari
Sia $G = (V,E)$ un grafo non orientato diciamo che è planare se può essere raffigurato in modo che non si abbiano archi che si intersecano.
![[Pasted image 20250110150820.png]]
**Teorema di Kuratowski**
Un grafo è planare se e solo se non contiene alcun sottografo che sia [[04_Parte4#Omeomorfismi|omeomorfo]] a $K_5$ o a $K_{3,3}$ (ricordiamo [[04_Parte4#Grafi bipartiti completi|i grafi bipartiti completi]])
![[Pasted image 20250110151742.png]]
**Criteri più semplici**
Se $G = (V,E)$ è un grafo connesso e planare se $|V| \ge 3$ allora $|E| \le 3 |V|-6$ 
**oppure**
Se $G = (V,E)$ è un grafo connesso e planare se $|V| \ge 3$ e non ci sono cicli di lunghezza 3 allora  $|E| \le 3 |V|-4$ 

---
###### Formula di Eulero
Se prendiamo un grafo planare e lo disegniamo sul piano possiamo individuare le **facce** ovvero il numero di regioni chiuse delimitate da archi del grafo (dobbiamo contrare anche la regione esterna, quella infinita).
![[Pasted image 20250111093757.png]]

> [!TIP] Formula di Eulero
> Se indichiamo con:
> - $v$ il numero di vertici
> - $e$ il numero di archi
> - $f$ è il numero di facce
> 
>vale la seguente formula: $v-e+f = 2$ dalla quale possiamo ricavare le formule inverse:
> $v = e-f+2$
> $f = e-v+2$
> $e = v+f-2$

---
###### Dimostrazioni vari teoremi
**Teorema**
Sia $G = (V , E)$ un grafo connesso con $|V | ≥ 3$. Supponiamo che $δ(v ) ≥ 2$ per ogni $v$. Allora $G$ possiede un ciclo.
**Dimostrazione**
Ordiniamo i vertici e chiamiamoli $v_1, v_2, . . . , v_n$ con $n = |V| ≥ 3$. Partiamo da v_1 e costruiamo il cammino più lungo possibile senza ripetizioni di vertici, supponiamo che il cammino più lungo senza ripetizioni sia $v_1, v_2, . . . , v_k$, dal vertice $v_k$ possiamo ancora raggiungere un altro vertice, dato il grado di almeno 2, dato che ci siamo fermati vuol dire che possiamo raggiungere solo un vertice già visto il che dimostra l'esistenza di un ciclo

---
**Teorema**
Sia $G = (V , E)$ un grafo connesso e aciclico. Allora $|E| = |V | − 1$
**Dimostrazione**
Il teorema è banalmente vero se $|V|\le2$. Supponiamo allora $|V| \ge 3$, essendo il grafo connesso ed aciclico deve esiste un vertice di grado $1$ altrimenti il grafo avrebbe un ciclo, prendiamo questo vertice $v$ e l'arco ad esso incidente il grafo e li rimuoviamo, il grafo indotto $V \backslash \{ v\}$ è connesso ed aciclico altrimenti dovremmo avere 2 vertici, $u, w$ che sono connessi solo da un cammino passante per $v$ ma ciò implicherebbe che $v$ ha grado maggiore di $1$ e quindi per induzione ha $|E| = |V| - 2$. Aggiungendo $v$ e l'arco ad esso incidente, abbiamo quindi che $|E| = |V|-1$

---
**Teorema**
Sia $G = (V , E)$ un grafo planare connesso, con $v$ vertici, $e$ archi e $f$ facce. Allora $v − e + f = 2$
**Dimostrazione**
Se il grafo possiede un ciclo, allora togliamo uno degli archi che completa tale ciclo, il numero di archi e di facce si abbassa allora di una unità e quindi la quantità $v − e + f$ rimane invariata. Ripetiamo tali sottrazioni di archi, sino a quando non eliminiamo tutti i cicli dall’albero, a questo punto avremo un grafo connesso ed aciclico con $e = v-1$ con $f=1$ visto che non ci sono cicli. Quindi $v-e+f = 2$

---
###### Grafi planari massimali o triangolare
Un grafo planare si dice massimale (o triangolare), se è planare e se aggiungendo un nuovo arco ad una qualunque coppia di vertici il grafo non è più planare. Ogni sua faccia è racchiusa da 3 archi. Dunque un grafo planare massimale ha $3v – 6$ archi e $2v – 4$ facce.
![[Pasted image 20250111101935.png]]

---
###### Colorazione di un grafo
Colorare un grafo vuol dire assegnare un colore ad ogni vertice in maniera tale che due vertici collegati da un arco abbiano colori distinti, un grafo è k-colorabile se è possibile colorare i suoi vertici rispettando il vincolo appena descritto usando al più $k$ colori. Il numero cromato di un grafo è denotato con $χ(G)$
![[Pasted image 20250111102250.png|500]]
Per un grafo completo con $n$ vertici, in cui ogni nodo è collegato ad ogni altro nodo, avremo bisogno di $n$ colori distinti, in figura possiamo vedere una colorazione di $K_5$
![[Pasted image 20250111102608.png|500]]
Per un grafo bipartito basterà usare 2 colori diversi, uno per $V_1$ e uno per $V_2$ come di seguito
![[Pasted image 20250111102741.png]]
Per un grafo con un semplice ciclo con $n$ vertici ci basterà usare:
- **n pari**: Possiamo usare sempre 2 colori diversi
  ![[Pasted image 20250111102843.png]]
- **n dispari**: Possiamo usare $2 + n \mod 2$ colori diversi
  ![[Pasted image 20250111103123.png]]

---
###### Teorema di Brooks
Una colorazione ottimale di un grafo $G$ è una colorazione dei vertici di $G$ che usa il numero minimo possibile di colori, ossia $χ(G)$. 
**Teorema**
Sia $G = (V,E)$ un grafo connesso con $n$ vertici $\delta_1 \ge \delta_2 \ge ... \ge \delta_n$ i gradi dei vertici del grafo in ordine crescente. Allora $χ(G) ≤ δ_1 + 1$ 
**Dimostrazione**
Il Teorema si può facilmente dimostrare per induzione. Se togliamo infatti il vertice di grado maggiore $v_1$, rimaniamo con un grafo con un vertice in meno e colorabile, per ipotesi induttiva, con al più $δ_2 + 1 ≤ δ_1 + 1$ colori. Quando aggiungiamo il vertice tolto, il caso peggiore è che i $δ_1$ vertici a lui connessi, siano tutti di colore diverso e quindi gli dobbiamo dare il colore rimasto dei $δ_1 + 1$.

---
###### Teorema di Brooks (versione forte)
Sia $G = (V , E)$ un grafo connesso con n vertici, e siano $δ_1 ≥ δ_2 ≥ · · · ≥ δ_n$ i gradi dei vertici del grafo in ordine decrescente. Se $G$ non è un grafo completo e $G$ non è un ciclo semplice con numero dispari di vertici, allora $χ(G) ≤ δ_1$

---
###### Teorema dei 4 colori
Sia $G = (V , E)$ un grafo planare, allora $χ(G) ≤ 4$.

---
###### Albero libero
Un albero libero (che di solito indichiamo con $T$) è un grafo $G = (V,E)$ connesso e aciclico, questo ha esattamente $|V| - 1$ archi, inoltre essendo connesso ogni vertice ha grado almeno $1$ e deve esistere almeno un vertice di grado $1$ altrimenti avrebbe un ciclo.
![[Pasted image 20250111111522.png]]
- Se $T$ ha un vertice allora questi si chiamano **vertici terminali**
- Se $T$ ha più di 2 vertici, i vertici di grado 1 sono detti **terminali o foglie**, mentre i vertici di grado maggiore di 1 sono detti **vertici interni** (il grafo sopra ha 6 foglie e 3 vertici interni)
---
###### Foresta
Una foresta è un insieme di uno o più alberi quindi un grafo $G = (V,E)$ aciclico ma non necessariamente connesso. Ogni componente connessa del grafo è un albero della foresta.
- Se $T$ ha solo 1 o 2 vertici allora tutti i vertici sono detti **Terminali**
- Se $T$ ha più di 2 vertici, i vertici di grado 1 sono detti foglie, mentre i vertici di grado maggiore sono detti vertici interni
Di seguito un grafo con 6 foglie e 3 nodi interni:
![[Pasted image 20250111112219.png]]

---
###### Alberi radicati
Dato un albero $T$ se scegliamo un nodo come radice e immaginiamo di impiantarlo con un chiodo, per gravità tutti gli altri nodi cadranno, così otteniamo un albero radicato
![[Pasted image 20250111112405.png]]
Dato un albero radicato:
- l'altezza è la lunghezza del cammino più lungo
- Il fattore di ramificazione dell’albero è il numero massimo di figli che ognuno dei nodi ha
- In un albero radicato, i **nodi figli** di un nodo sono quelli immediatamente sottostanti a esso e direttamente collegati tramite un arco. Il nodo che li collega dall'alto è chiamato **nodo padre**.
![[Pasted image 20250111112642.png]]
---

## `Problemi combinatori sui grafi`
Due problemi sui grafi che ricadono nella classe N P- hard sono:
1. Il problema della colorazione di un grafo utilizzando il numero minimo di colori;
2. il problema della eliminazione del numero minimo di vertici di un grafo, per renderlo aciclico.
## `Tips`
###### Come creare tutte le combinazioni tra le variabili senza confondersi
![[Pasted image 20241009133640.png]]
Numero variabili da rappresentare: 4 (P,Q,R,S)
Numero casi possibili: nCasi = $2^4$ = $16$
Per la prima variabile:
- scrivi 8 volte V e 8 volte F
Per la seconda variabile scrivi: 
- 4 volte V -  4 volte F - 4 volte V - 4 volte F
Per la terza variabile scrivi: 
- 2 volte V -  2 volte F - 2volte V - 2 volte F - 2 volte V -  2 volte F - 2 volte V - 2 volte F
Per la quarta variabile scrivi: 
- VERO - FALSO - VERO - FALSO … fino a quando non arrivi a nCasi 

Se hai una tabella con 6 variabili sono 64 casi e la prima variabile sarà 32 volte vero e 32 volte falso, ogni volta che cambi variabile dividi per 2 i casi veri e quelli falsi



##### Come distribuire le congiunzioni sulle disgiunzioni e viceversa
Formula iniziale: $p ∧ (q ∨ r )$

1. Riscrivo la variabile e l'operatore logico che sono fuori dalla parentesi e tra le 2 (2 sono il numero di variabili dentro la parentesi) parantesi che avrò metto l'operatore logico che c'è dentro la parentesi.
	- ($p ∧ ...$) ∨ ($p∧...$)
2. Metto al posto dei puntini le variabili che ho dentro la parentesi, non è importante l'ordine
	-  ($p ∧ q$) ∨ ($p∧r$)

Formula finale: ($p ∧ q$) ∨ ($p∧r$)

##### Come calcolare la chiusura di una famiglia rispetto ad unione/intersezione
$F$  = {1, 2, … , m}
$\mathcal{F}_U$ = ??? famiglia più piccola che contiene $F$ ed è chiusa rispetto all'unione
1. Costruiamo la famiglia $F^1$ mettendoci tutti gli elementi di $F$.
2. Per ogni i (partendo da 2) sino a m calcoliamo $F_i$ utilizzando tutte le coppie di elementi $X$ , $Y$ con $X ∈ F$ e $Y ∈ \mathcal{F}_{i-1}$ e mettendo $X ∪ Y$ in $F_i$ .
3. Poniamo infine $\mathcal{F}_U = \bigcup_{i=1}^{m} \mathcal{F}_i$ 



##### Come trasformare una qualsiasi formula in CNF e DNF
1. Elimina le coimplicazioni p ⇔ q dalla formula sostituendole con (p ⇒ q) ∧ (q ⇒ p)
2. Elimina le implicazioni p ⇒ q dalla formula sostituendole con ¬p ∨ q
3. Sposta le negazioni a ridosso delle variabili proposizionali ed elimina le doppie negazioni.
4. Di Bella move: ![[Pasted image 20241020173502.png]]Questo passaggio consiste nel trasformare il tutto in moltiplicazione e somme per rendere tutto più intuitivo.
##### Differenza tra applicazione e funzione
In matematica, i termini **"applicazione"** e **"funzione"** sono praticamente sinonimi, ma ci sono alcune sottili differenze di uso e di contesto che spiegano perché in certi casi si preferisce usare uno rispetto all'altro.

1. **Funzione**: La parola "funzione" è il termine più generico e formale per descrivere una corrispondenza tra due insiemi, dove ad ogni elemento del primo insieme (detto **dominio**) corrisponde **uno e un solo** elemento del secondo insieme (detto **codominio**). Quindi, una funzione è una regola che associa elementi del dominio al codominio. Formalmente, una funzione $f ⁣:A→B$ è una relazione che associa ad ogni elemento di $A$ un unico elemento di $B$.

2. **Applicazione**: Il termine "applicazione" è usato in contesti più specifici o pratici. Spesso viene utilizzato quando si vuole enfatizzare il **processo** o **l'atto** di associare un elemento del dominio al suo corrispondente nel codominio, piuttosto che la funzione come oggetto matematico in astratto. "Applicazione" sottolinea l'idea di "applicare" una regola o un'operazione a un elemento per ottenere un risultato.

