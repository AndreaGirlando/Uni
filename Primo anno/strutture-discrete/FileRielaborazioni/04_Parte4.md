Questo file è la rielaborazione delle slide [[04_Parte4]]

# `Teoria dei grafi`
La teoria dei grafi inizia per risolvere un problema reale, chiamato problema dei sette ponti, questi ponti sono situati in una città Russa attraversata da un fiume e presenta due isolette che sono collegate con le aree principali della città con 7 ponti. Il nostro caro Eulero era in città e venne a sapere di questo problema: “E’ possibile fare una passeggiata che
attraversi ogni ponte una sola volta?”
![[Pasted image 20250107153947.png|500]]
Eulero sintetizza il tutto in termini astratti, assegnando ad ogni area della città un nodo e ad ogni ponte un arco.

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
La definizione di grafo completo si estende anche ai grafi orientati, sia $G = (V, E)$ un grafo orientato diciamo che è completo se ogni coppia ordinata 