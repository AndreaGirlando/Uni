Questo file è la rielaborazione delle slide [[04_Parte4]]
# `Teoria dei grafi`
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

# `Problemi combinatori sui grafi`
Due problemi sui grafi che ricadono nella classe N P- hard sono:
1. Il problema della colorazione di un grafo utilizzando il numero minimo di colori;
2. il problema della eliminazione del numero minimo di vertici di un grafo, per renderlo aciclico.