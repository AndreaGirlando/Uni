Rielaborazione del file [[1-Ricorsione.pdf]]


# Concetto di ricorsione

###### La ricorsione
La **ricorsione** rappresenta uno dei concetti più eleganti e profondi della programmazione. Essa si fonda sull'idea che un problema complesso possa essere affrontato non direttamente nella sua interezza, ma scomponendolo in sotto-problemi più semplici, ciascuno dei quali conserva la stessa natura e struttura del problema originario, ma su scala ridotta.

> [!TIP] Definizione
> Un **programma ricorsivo** è una funzione o una procedura che durante la propria esecuzione richiama se stessa per risolvere versioni sempre più piccole dello stesso problema

Questo meccanismo sembra apparentemente circolare, ma è in realtà estremamente potente a condizione che esista un punto di arresto ben definito: ovvero **la condizione base**

L'idea alla base della ricorsione può essere illustrata con un semplice principio: per risolvere il problema complesso $P$ il programmatore non cerca di affrontarlo direttamente ma lo suddivide in $K$ problemi più piccoli  ($P_1,P_2,\dots,S_K$) che è in grado di risolvere (o si assume che sappia risolvere), ognuno di questi sotto problemi viene risolto, le soluzioni ottenute vengono combinate per ottenere la soluzione complessiva $S$

Un esempio classico di questo meccanismo è il calcolo del fattoriale di un numero intero non negativo $n$
![[Pasted image 20251012172214.png|500]]
in breve si afferma che per calcolare $n!$ non è necessario conoscere direttamente il risultato ma basta sapere come calcolare il fattoriale di un numero più piccolo $n-1$, questa definizione *auto-riferita* è perfettamente lecita e diventa computazionalmente potente perché il caso base (quello sopra) interrompe la catena di richiami e garantisce la terminazione (cosa molto importante in un programma)

###### Fasi della ricorsione
La chiave del pensiero ricorsivo risiede nella riduzione del problema invece di cercare una soluzione diretta e immediata, osservando questa prospettiva emergono due aspetti fondamentali:
- **Suddivisione**: del problema in sotto problemi di minore complessità
- **Ricombinazione**: dei risultati parziali nella soluzione complessiva
Questa duplice operazione è ciò che rende la ricorsione tanto elegante quanto potente infatti permette di passare da una visione monolitica del calcolo a una visione **gerarchica e modulare** 

###### La ricorsione come forma di arte
Nel mondo informatico e in particolare nella cultura degli hacker e dei programmatori più esperti si ha una senso di soddisfazione estetica quando si riesce a trovare una soluzione ricorsiva che pur essendo breve riesca a risolvere il problema

###### Definizioni ricorsive delle strutture dati
La ricorsione non riguarda solo gli algoritmi o le funzioni ma anche le **strutture dati**, di seguito degli esempi:
- **Lista**: non è altro che un *elemento iniziale* seguito da un'altra lista dello stesso tipo ![[Pasted image 20251012173553.png|500]]
-  **Array**: un array di lunghezza $n$ può essere definito come un elemento iniziale seguito da un array di lunghezza $n-1$: $$A_n = \{a_0\} \cup A_{n-1}$$
- **Alberi**: ogni nodo dell'albero può essere considerato come la radice di un nuovo albero, composto dai suoi sottoalberi![[Pasted image 20251012174314.png|500]]
Questo non è solo un dettaglio tecnico, ma un riflesso profondo della natura gerarchica di molte strutture logiche e computazionali, per queste ragioni la ricorsione non è soltanto un modo per **operare** sulle strutture dati, ma anche un modo per definirle, quando questo accade, la sua manipolazione di ricorsiva risulta non solo naturale, ma anche concettualmente più chiara e formalmente elegante.

###### Struttura generale di un programma ricorsivo
Ogni programma ricorsivo si fonda su una struttura concettuale ben precisa, che ne garantisce la correttezza logica e la terminazione formata da:
1. **Il caso base**: il caso base è una condizione che ne interrompe la prosecuzione infinita di una ricorsione, matematicamente corrisponde alla condizione di terminazione dell'equazione definita ricorsivamente
2. **Il passo ricorsivo**: In questo punto la funzione richiama sé stessa per risolvere uno o più sotto problemi di dimensione minore, se indichiamo con $P$ il problema principale e con $P_1,P_2, \dots, P_K$ i sotto problemi derivati, il passo ricorsivo può essere espresso formalmente come: $$S = \text{Combina}(F(P_1), F(P_2), \dots, F(P_K))$$
3. **La combinazione dei risultati**: Una volta risolti i sotto problemi occorre un meccanismo per ricomporre le soluzioni parziali e ottenere la soluzione complessiva del problema principale. Questo processo detto fase di combinazione è spesso ciò che distingue una ricorsione semplice da una più sofisticata

Una funzione ricorsiva $F(n)$ può essere definita in modo generale nel seguente modo: ![[Pasted image 20251012180931.png|500]]
Dal punto di vista operativo l'esecuzione di un programma ricorsivo può essere immaginata come una serie di scatole annidate ogni funzione apre un nuovo livello di esecuzione, questa dinamica viene gestita in modo automatico dallo **stack** che conserva lo stato di ciascuna chiamata, ogni nuova chiamata viene accodata in cima alla pila. 

In una funzione ricorsiva ben progettata la profondità della ricorsione deve sempre essere finita infatti in caso contrario si potrebbe incappare in problemi di **stack overflow** (troppe chiamate nello stack)

###### Dimensione del problema
