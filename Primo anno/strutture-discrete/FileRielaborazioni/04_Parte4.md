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
Un grafo semplice non orientato denotato con $G = (V,E)$ consiste:
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
Un grafo si dice connesso se ha una sola componente connessa, ovvero se per ogni coppia di vertici esiste un percorso che li collega.

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
1.  Dal momento che $\delta^+(i)$ > 0 esiste un vertice 