### Algebra Lineare
##### Strutture Algebriche
- **Insieme**: collezione di un elementi che hanno tutti una stessa caratteristica
- **Funzione**: dati due insiemi $A$ e $B$, si dice $f$ (funzione) una legge che associa ad ogni elemento di $A$ uno di $B$. [[01_Parte1#Funzioni |Spiegazione approfondita delle funzioni]] $f:R \to R$ si legge "$f$ definita in $R$ a valori in $R$".
---
##### Matrici

**Matrice**: una matrice è una tabella di **m-righe e n-colonne**, ogni singola "cella" di questa matrice si chiama **entrata**.
Una matrice con lo stesso numeri di righe e di colonne si dice **quadrata**, queste tipo di matrici possono assumere varie forme:
- **Triangolare diagonale**: se sopra **e** sotto la diagonale principale ci sono tutti zero.
- **Triangolare superiore**: se sotto la diagonale principale ci sono tutti zero.
- **Triangolare inferiore**: se sopra la diagonale principale ci sono tutti zero.
Una qualsiasi matrice si può dire:
- **Simmetrica**: se la matrice è uguale alla sua trasposta.
- **Antisimmetrica**: se la matrice è uguale all'opposta della sua trasposta.

**Matrice trasposta**: Ipotizzando una matrice A dove ogni entrata è definita come $a_{ij}$ la matrice trasposta di A la matrice trasposta di A che denotiamo con $A^T$ con le entrate definite così: $a_{ji}$ 
![[Pasted image 20241116152010.png]]
Per trasporre una matrice basta scrivere le sue righe sotto forma di colonne. Il determinante di A è uguale a determinante di $A^T$

**Matrici equivalenti**: 2 matrici sono uguali se ogni singola entrate è uguale in entrambe le matrici

---
###### Operazioni tra matrici
**Somma tra matrici**: per sommare 2 matrici quest'ultime devono avere le stesse dimensioni
![[Pasted image 20241116152444.png]]
**Moltiplicazioni tra un numero e una matrice:** il numero per la quale moltiplichiamo la matrice viene detto scalare (nell'esempio sottostante lo scalare si chiama c)
![[Pasted image 20241116152547.png]]
**Sottrazione tra matrici:** per poter fare la differenza tra 2 matrici devo avere lo stesso numero di righe e di colonne in entrambe le matrici
**Moltiplicazioni tra matrici**: date 2 matrici A e B per poter fare la moltiplicazione tra queste deve essere vera **almeno una** delle 2 condizioni sottostanti: ^5de7b3
1. numero di colonne di A  = numero di righe di B
2. numero di colonne di B = numero di righe di A
![[Pasted image 20241116153231.png]]
Ogni entrata della matrice "Risultato" è il risultato di una moltiplicazione tra una riga della prima matrice e una colonna della seconda. Di seguito il calcolo dell'entrata in posizione 1,1 della matrice "Risultato":
![[Pasted image 20241116153434.png]]

---

**Matrice identità:** denotiamo la matrice identità come $Id_m$. Definiamo matrice identità la matrice che rende vera questa cosa:
- $Id_m * A = A$
- $A * Id_m = A$
La matrice identità è una matrice quadrata che segue questa forma:

$\begin{pmatrix} 1 & 0 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 1 \end{pmatrix}$

**Forma di echelon:** una matrice si dice in forma di echelon se:
1. Se tutte le righe nulle sono in fondo
2. Se in ogni riga il primo elemento (detto **pivot**) $\not= 0$ partendo da sinistra si trova alla destra di tutti i pivot delle righe superiori e ha tutti zero sotto 
![[Pasted image 20241116155132.png]]
**Forma di echelon ridotta:** una matrice si dice in forma di echelon ridotta se:
1. É in forma di echelon normale
2. tutti i pivot sono uguali ad 1
3. ogni pivot è l'unico elemento non zero della sua colonna
![[Pasted image 20241116155409.png]]

**😍Metodo di Gauss-Jordan:😍** Questo metodo viene usato per trasformare qualsiasi matrice in forma di echelon ridotta, [[Metodo di Gauss-Jordan.pdf|Spiegazione di come funziona]] (farò riferimento a questa tecnica con la notazione G-J).

---

**Rango**: il rango di una matrice è il numero di pivot nella sua forma di echelon ridotta, il rango della matrice A lo denotiamo con $rkA$, questo numero rispetta sempre questa condizione:
	- $0 \leq rkA \leq min(m,n)$
	  Il rango di una matrice è massimo $rkA = min(m,n)$

**Invertibilità delle matrici:** una matrice si dice invertibile se il suo rango è massimo, denotiamo l'inversa della matrice $A$ con $A^{-1}$ 
**Inversa di una matrice**: Data una matrice A per trovare la sua inversa seguo questi step:
1. Controllo se il suo rango è massimo
2. Creo una nuova matrice unendo la matrice A e la matrice identità
   ![[Pasted image 20241116161255.png]]
3. Faccio Gauss-Jordan su questa matrice e ottengo una matrice di questo tipo
   ![[Pasted image 20241116161611.png]]
4. Se $D = id_m$ allora $D' = A^{-1}$  
![[Pasted image 20241116161811.png]]
Essendo $D = id_m$ allora $D' = B^{-1}$ 

---

**Sottomatrici**: Sia $a_{ij}∈M_{n,n}(\mathbb{R})$ con $i,j∈{1,…,n}$. La sottomatrice $A_{ij}$ di A è una matrice ottenuta rimuovendo le i-esime e le j-esime colonne e righe.
![[Pasted image 20241116171341.png]]

---

**Minore**: Il termine "minore" in algebra lineare si riferisce a una sottomatrice di una matrice più grande. Più precisamente, il minore di una matrice è il determinante di una sottomatrice ottenuta rimuovendo una o più righe e colonne dalla matrice originale. 

---

**Determinante**: è numero associato ad ogni matrice che può dirci molto sulle proprietà della matrice stessa. 

**Metodo di Sarrus per il calcolo del determinante nelle matrici quadrate** che consiste nei seguenti passaggi:
1. Prendi la tua matrice normale
   ![[Pasted image 20241116165902.png | 200px]]
2. Riscrivi le prime 2 colonne e tracci le diagonali
   ![[Pasted image 20241116165941.png]]
3. Faccio le moltiplicazioni delle diagonali, moltiplicando tutto per + nelle diagonali principali e per - nelle diagonali secondarie 
   

**Metodo di Laplace per il calcolo del determinante** : questa metodologia si basa su questa formula: 
- $\det(A) = \sum_{j=1}^{n} a_{ij}(-1)^{i+j} \cdot M_{ij}$ 
- meno generalizzata diventa: $\det A = a_{1 1} (-1)^{1+1} \left| A_{1 1} \right| + a_{1 2} (-1)^{1+2} \left| A_{1 2} \right| + \ldots + a_{1 m} (-1)^{1+m} \left| A_{1 m} \right|$
Dove:
- A è la matrice $n \times n$.
- i è l'indice della riga scelta per lo sviluppo.
- $a_{ij}$ è l'elemento della matrice A alla posizione $(i,j)$.
- $M_{ij}$ è il minore ottenuto eliminando la riga i e la colonna j dalla matrice A.
![[Pasted image 20241116174944.png]]

**Teorema di Binet:** se abbiamo 2 matrici quadrate A,B $\in$ $M_{n,n}(R)$ il $det(A*B) = det(A) * det(B)$
==Dimostrazione???==

**Teorema degli orlati:** Data una matrice A $\in M_{m,n}$ e una sottomatrice quadrata di $A$ detta $B$, con dimensioni $p*p$ se tutte le sotto matrici di A di dimensione $(p+1)(p+1)$ ottenute orlando $B$ hanno $det = 0$ allora $rkA = p = rkB$ (orlare una matrice consiste nell'aggiungere una riga o una colonna scelte arbitrariamente dalla matrice padre). Di seguito un'esempio con la seguente matrice:
![[Pasted image 20241116202537.png]]
1. Scegliamo una matrice con det $\not=$ 0
   ![[Pasted image 20241116202628.png]]
2. Alla matrice scelta aggiungiamo una riga ed una colonna scelte in modo casuale e ci calcoliamo il det
   ![[Pasted image 20241116202732.png]]
3. Aggiungiamo la riga 5 e la colonna 1 e calcoliamo il det
   ![[Pasted image 20241116202852.png]]
4. Continuando e provando notiamo che tutti i determinanti vengono uguali a 0 quindi il $rk A = p = rk B = 2$
---
- **Teorema Matrici Invertibili** dice che:
    - a) una matrice A è invertibile $\iff \det A \neq 0$
    - b) se $\det A \neq 0$ allora la matrice inversa è: $A^{-1} = \frac{1}{\det A} \cdot A_{a} = \frac{1}{\det A} \cdot (A_{ij})^{T}$
    - c) se $A$ è invertibile allora $\det A^{-1} = \frac{1}{{\det A}}$
    - d) $A*A^{-1} = Id_m$
---
##### Sistemi Lineari

**Sistema Lineare**: è un sistema di equazioni a più incognite (sempre di grado 1) per risolvere un sistema lineare possiamo trasformarlo in una matrice, la matrice che ne esce avrà questa forma: $A*X = B$ (questa è la definizione della matrice associata al sistema lineare)
![[Pasted image 20241117100819.png]]
Per risolvere un generico sistema lineare possiamo applicare Gauss-Jordan alla matrice completa che ha questa forma:
![[Pasted image 20241117102740.png]]
i valori rimasti nella matrice A quando arriviamo in forma di echelon ridotta rappresentano i coefficienti delle incognite, i valori rimasti nella matrice B sono i valori delle incognite.
![[Pasted image 20241117094917.png]]
Come possiamo notare da questa immagine facciamo quanto detto prima, le soluzioni che troviamo nella forma finale sono ${x_1 = 0, x_2 = 0, x_3 = 2}$ usando questo metodo la risoluzione di un sistema lineare diventa banale. 
Ci sono dei casi speciali in cui si può incappare quando si risolvono i sistemi lineari come quelli di seguito:  
1. **Sistema impossibile**: in uno dei passaggi di G-J siamo arrivati a questo punto (vedi immagine sotto), come possiamo notare le soluzioni dell'ultima riga sarebbero $x_1*0 + x_2*0 +x_3*0 = 1$,  e quindi che $0 = 1$ questa è chiaramente un'affermazione falsa quindi la risultato del sistema è impossibile da calcolare
   ![[Pasted image 20241117095302.png]]
2. **Sistema con infinite soluzioni**: Arrivati al punto di prendere le soluzioni ci siamo resi conto che $x_1$ dipende dal valore di $x_4$ e proprio quest'ultima non ha un valore definito, in questo caso si dice che le soluzioni del sistema sono infinite perché dipendono da un parametro, in questo caso $x_4$ (nelle soluzioni $x_4$ viene posto = $t$)
   ![[Pasted image 20241117095805.png]]

**Teorema di Rouchè Capelli**: Il sistema $A*X = B$ con $n$ variabili e $m$ equazioni ha soluzione se $rkA == rk(A|B) = r$ da qui si sviluppano 2 casi: 
- se r == n allora il sistema lineare ammette una sola soluzione
- se r < n allora esistono infinite soluzione che dipendono da $n-r$ parametri 

**Sistemi lineari con parametro $\alpha$**: può succedere che in un'esercizio venga inserito un parametro $\alpha$ la risoluzione non cambia da un normale sistema lineare dobbiamo solo fare attenzione a questo valore, questo implica che dobbiamo fare di tutto per evitare che $\alpha$ sia un pivot, se $\alpha$ è un pivot dobbiamo discutere le varie soluzione della matrice al variare del suo valore
![[Pasted image 20241117112305.png]]

Il nostro obbiettivo per continuare con G-J è quello di far diventare il pivot 1, per fare ciò dobbiamo essere sicuro che il valore di $\alpha$ sia diverso da zero, quindi vediamo quando è zero in questo modo:
$2 - \alpha - \alpha^2 = 0$ $=>$ $(\alpha - 1)(\alpha + 2) = 0$ $=>$ $\alpha = 1,-2$ 
Da questo capiamo che i casi da discutere sono 3:
1. $\alpha = 1$
2. $\alpha = 2$
3. $\alpha \not= 1,2$ 
Di seguito il continuo dell'esercizio
![[Pasted image 20241117112339.png]]
![[Pasted image 20241117113033.png]]
![[Pasted image 20241117113154.png]]
Nell'ultimo caso si vede un'applicazione del teorema di Rouchè Capelli (si lascia al lettore il brivido della scoperta delle soluzioni di quest'ultima matrice 😉)

**Sistemi omogenei**: un sistema omogeneo è un sistema lineare che si basa su questo paradigma: $A * X = 0$  e che quindi la matrice B dei termini noti è una matrice nulla (con tutti 0), la risoluzione di questo tipo di sistema lineare non differisce con un sistema lineare normale.

**Teorema di Cramer**: Per trovare le soluzioni di un sistema lineare del tipo $AX = B$ con $\det A \neq 0$ ovvero un sistema detto **determinato** (ammette una e una sola ($\exists!$) soluzione). Calcoliamo l'unica soluzione delle incognite in questo modo: 
- $x_i = \frac{\det(B_i)}{\det(A)} \quad \forall i \in \{1, 2, ..., n\}$ dove $n$ è il numero di incognite
	- $B_{1}$ si calcola sostituendo la $1^a$ colonna di $A$ con $B$.
	- $B_{2}$ si calcola sostituendo la $2^a$ colonna di $A$ con $B$.
	- $\dots$
	- $B_{n}$ si calcola sostituendo la $n^a$ colonna di $A$ con $B$.
Esempio di come trovare le soluzioni di un sistema lineare usando Cramer
![[Pasted image 20241123121610.png]]
Dimostrazione: prendo $Ax = B \Leftrightarrow x = A^{-1}B$ quello che devo dimostrare è che A è uguale a B se e soltanto se moltiplicata per quella x quindi seguo i seguenti passi: 
- Sostituisco $A^{-1}B$ ad $x$ della prima formula e quindi diventa: $A*(A^{-1}B) = B$
- Sposto le parantesi: $(A*A^{-1})B = B$ 
- Per definizione di matrice inversa $A * A^{-1} = Id_m$ 
- Quindi l'espressione diventa $B = B$
 
---
##### Spazi Vettoriali
**Spazio Vettoriale**: si dice spazio vettoriale un [[01_Parte1#`Insiemi`|insieme]] su cui valgono le seguenti proprietà:
1. **$V$ è un insieme non vuoto** con un'operazione di somma $+$ tale che:
    - È chiuso rispetto alla somma: $u + v \in V , \forall u, v \in V$.
    - La somma è **associativa**: $(u + v) + w = u + (v + w) , \forall u, v, w \in V$.
    - La somma è **commutativa**: $u + v = v + u , \forall u, v \in V$.
    - Esiste un **elemento neutro** $0 \in V$ tale che $u + 0 = u , \forall u \in V$.
    - Ogni elemento $u \in V$ ha un **opposto** $-u \in V$ tale che $u + (-u) = 0$.
2. **$V$ ha un'operazione di prodotto scalare** con un campo (ad esempio, i numeri reali $\mathbb{R}$):
    - È chiuso rispetto al prodotto scalare: $\forall \lambda \in \mathbb{R}, u \in V, \lambda u \in V$.
    - Vale la **distributività** rispetto alla somma degli scalari: $(\lambda + \mu)u = \lambda u + \mu u , \forall \lambda, \mu \in \mathbb{R}, u \in V$.
    - Vale la **distributività** rispetto alla somma dei vettori: $\lambda(u + v) = \lambda u + \lambda v , \forall \lambda \in \mathbb{R}, u, v \in V$.
    - Vale la **compatibilità** tra prodotto scalare e moltiplicazione scalare: $(\lambda \mu)u = \lambda (\mu u) , \forall \lambda, \mu \in \mathbb{R}, u \in V$.
    - Il numero $1 \in \mathbb{R}$ (scalare unitario) agisce come identità: $1u = u , \forall u \in V$.
Ipotizzando un insieme $V$ sulla quale valgono tutte queste proprietà lo chiamiamo **spazio vettoriale**, gli elementi di $V$ si chiamano **vettori**.

$R^n$ = { ($x_1$, $x_2$,..., $x_n$)| $x_i \in R$}  
$R^n$ è uno spazio vettoriale formato dai vettori con al massimo $n$ volte $x$, ad esempio $R^5 = {x_1,x_2,x_3,x_4,x_5}$, possiamo affermare che questo è uno spazio vettoriale perché valgono tutte le proprietà prima descritte.   

**Combinazione lineare**: un vettore è combinazione lineare degli altri vettori dello spazio vettoriale se esistono dei $\lambda_{1}, \lambda_{2}, \dots, \lambda_{n}$ tale che $v=\lambda_{1}v_{1}+\lambda_{2} v_{2}+\dots+\lambda_{n}v_{n}$

**Sottospazio**: $W$ è sottospazio di $V$ se $W \subseteq V$ e se $W$ rispetta queste proprietà:
- $\forall v, w \in W, v + w \in W$
- $\forall w \in W, -w \in W$
- $0 \in W$ 
 - $\forall \lambda \in \mathbb{R}, \forall w \in W \implies \lambda \cdot w \in W$
Nei sottospazi vettoriali definiamo 2 operazioni:
- **Intersezione tra sottospazi**: è sempre un sottospazio
- **Unione tra sottospazi**: è sottospazio solo se uno dei due è sottoinsieme dell'altro (ovvio)
- **Somma diretta**: Definiamo somma diretta la somma tra 2 sottospazi se e solo se la loro intersezione è $\{0\}$ ovvero un'insieme con solo lo 0 dentro, questo ci indica che i 2 insiemi sono completamenti diversi.
  ![[Pasted image 20241205162115.png]]

**Insieme di Generatori**: dato uno spazio vettoriale $V$, un insieme $(v_{1}, v_{2}, \dots, v_{n})$ è detto insieme di generatori (indicato con $G \{ v_{1}, v_{2}, \dots, v_{n}\}$) se preso un qualunque vettore $v \in V$ esso si può scrivere come combinazione lineare (C.L.) dei vettori di $G$.

**Linearmente Indipendenti**: i vettori $v_{1}, v_{2}, \dots, v_{n}$ si dicono linearmente indipendenti se facendo la combinazione lineare di quest'ultimi l'unico modo per farla venire uguale a 0 è usando dei $\lambda = 0$ 

**Linearmente dipendente**: i vettori $v_{1}, v_{2}, \dots, v_{n}$ si dicono linearmente dipendenti se facendo la combinazione lineare di quest'ultimi per un generico $\lambda$ il risultato è uguale a $0$

> [!Nota bene] Come capire se uno spazio vettoriale è linearmente indipendente
> Per capire se i vettori di uno spazio vettoriale sono linearmente indipendenti creo una matrice con quest'ultimi e mi calcolo il rango:
> - Se il rango è massimo allora lo spazio vettoriale è linearmente indipendente
> - Se il rango non è massimo vuol dire che qualche vettore può essere scritto come combinazione lineare degli altri e quindi che è linearmente dipendente

**Base di uno spazio vettoriale**: un insieme  $(v_{1}, v_{2}, \dots, v_{n})$ è detto **Base** di $V$ se $B$ genera $V$ e soprattutto se $B$ è linearmente indipendente
- $B = \{ (0,1),(1,0) \}$  è una base di $R^2$  questo perché genera $R^2$ ed è linearmente indipendente  
Una base che useremo spesso è la base di $R^n$ anche detta **base standard** è si presenta in questa forma:
![[Pasted image 20241205170539.png]]
 
**Dimensione di uno spazio vettoriale**: la dimensione di uno spazio vettoriale ci indica il numero di vettori che compongono una sua base. V spazio vettoriale, W sottospazio vettoriale di V allora $dim W \le dim V$ sempre tranne quando $W = V$  

**Formula di Grossmann**: $V$ spazio vettoriale $U,W ⊆ V$ allora 
- $dim(U + W) = dim U + dim W - dim(U ∩ W)$

==**Lemma di Steinitz**: tutte le basi di uno spazio vettoriale hanno la stessa dimensione== 

Per rappresentare la base di sottospazio abbiamo 2 metodi:
- **Forma parametrica**: ovvero come spazio generato da un insieme di vettori:
  ![[Pasted image 20241205181133.png]]
  Di seguito un'esempio:
  ![[Pasted image 20241205181317.png]]
- **Forma cartesiana:** come soluzione di un sistema lineare omogeneo
  ![[Pasted image 20241205184340.png]]
  Di seguito un'esempio:
  ![[Pasted image 20241205184655.png]]

**Come passiamo da una rappresentazione ad un'altra?**
- **Forma cartesiana -> forma parametrica**
  ![[Pasted image 20241206173139.png]]
- **Forma parametrica -> forma cartesiana**
  ![[Pasted image 20241206173319.png]]
Passare da una forma all'altra è utile per le operazioni che dobbiamo andare a fare, se dobbiamo fare un'intersezione di sottospazi la forma cartesiana risulta più comoda, invece per la somma di sottospazi la parametrica è la più comoda.

**Teorema del rango**: Data una matrice con dimensioni $m*n$ possiamo definire il seguente teorema:
- $rk A + dim(ker (A)) = n$  
opzionalmente si fa riferimento alla dimensione del $ker(A)$ indicandolo con $null(A)$ di conseguenza la formula diventa:
- $rk A + null(A) = n$ 
---
##### Applicazioni Lineari
- **Applicazione Lineare**: corrispondenza (funzione) tra due K-spazi vettoriali.
- **Immagine** ($\text{im} f$): insieme del codominio formato dai vettori immagine dei vettori del dominio.
    - L'immagine è sottospazio del codominio, si **dimostra** (4\*. L13) provando che è chiusa rispetto alla somma e al prodotto esterno.
    - **[Studio](immagine)**
        - $\dim imf = \rho$
        - **Base**: vettori L.I. di V (gli stessi che formano il rango)
        - **Equazione Cartesiana**: metodo matrice Z (si mettono in riga i vettori base, nell'ultima riga le incognite, si calcola il determinante)
- **Nucleo** ($\ker f$): insieme del dominio formato dai vettori che hanno come immagine il vettore nullo.
    - Il nucleo è sottospazio del dominio, si **dimostra** (5\*, L14) provando che è chiusa rispetto alla somma e al prodotto esterno esterno.
    - **[Studio](nucleo)**
        - $\dim \ker f = \dim V - \dim imf$
        - **Base**: $A \cdot X=0$
        - **Equazioni Cartesiane**: ricavate dal sistema precedente (o metodo matrice Z)

- **Iniettività**: una funzione si dice iniettiva se presi due qualsiasi vettori del dominio diversi allora ne deve seguire che le loro immagini siano diverse.
- **Suriettività**: una funzione si dice suriettiva se ogni vettore del codominio è raggiunto da almeno un vettore del dominio.
- **Teorema sul Nucleo e Iniettività**: afferma che $f$ è iniettiva $\iff \ker f = \{ 0 \}$
    - **Dimostrazione** (6\*, L14)
- **Applicazione Identica**: applicazione lineare cui legge corrisponde a $i(\vec z) = \vec z$
- **Applicazione Inversa**: Date due applicazioni lineari $f: V \to W$ e $g: W \to V$ se $g \circ f = i_{v}$ e $f \circ g = i_{w}$ allora $f$ è invertibile e $g$ è detta applicazione inversa di $f \,\, (g=f^{-1})$.
    - $f$ e $g$ devono essere suriettive e iniettive.
 ---
##### Endomorfismi

- **Endomorfismo**: applicazione lineare dove dominio $=$ codominio.
- **Isomorfismo**: un'applicazione lineare biettiva (iniettiva e suriettiva), quindi necessariamente endomorfismo.
- **Autovalore**: dato un endomorfismo $f: V \to V$, $\lambda$ si dice **autovalore** se esiste un vettore $v \in V$ con $v \neq 0$ tale che $f(v)=\lambda v$. $\qquad\lambda \space\text{autovalore} \iff \exists v \in V, v \neq 0 \space|\space f(v) = \lambda v$
- **Autovettore**: dato un endomorfismo $f: V \to V$, $v \in V$, $v \neq 0$ si dice **autovettore** se esiste un $\lambda \in K$ tale che $f(v) = \lambda v$. $\qquad v \in V, v \neq 0 \space\text{autovettore} \iff \exists \lambda \in K \space|\space f(v)=\lambda v$
- **Autospazio**: dato un endomorfismo $f: V \to V$, si dice **autospazio** $V_{\lambda}$ il sottospazio di V definito nel modo seguente: $\quad V_{\lambda} = \{ v \in V \space|\space f(v)=\lambda v \} \subseteq V$
- **Polinomio Caratteristico**: data una matrice $A$ il $P.C. = \det{(A-T\cdot I)}$.
- **Molteplicità Algebrica**: per molteplicità algebrica di $\lambda$ si intende il numero di volte in cui $\lambda$ è soluzione del polinomio caratteristico.
- **Molteplicità Geometrica**: per molteplicità geometrica di $\lambda$ si intende la dimensione dell'autospazio $V_{\lambda}$.
- **Endomorfismo Associato all'Autovalore**: indichiamo con $f_{\lambda}$ l'endomorfismo associato all'autovalore $\lambda$. $f_{\lambda}(v)=f(v)-\lambda v$
- **Teorema sulle Molteplicità**: dato un endomorfismo $f: V \to W$ e un autovalore $\lambda \in K$ allora $0 < g_{\lambda} \leq m_{\lambda}$.
- **Endomorfismo Semplice**: un endomorfismo si dice semplice se esiste una base formata interamente da autovettori.
- **Matrici simili**: due matrici $A$ e $B$ si dicono simili se  $\exists \,P \in \mathbb{K}^{n,n} \,|\, P^{-1}AP=B$.
- **Teorema sulla diagonalizzazione**: una matrice $A \in \mathbb{K}^{n,n}$ è diagonalizzabile $\iff$ $f_{A} : \mathbb{K}^{n} \to \mathbb{K}^{n}$ è semplice oppure se è simile a una matrice diagonale.
    - **Matrice Diagonalizzata**: matrice che ha sulla diagonale principale le molteplicità algebriche degli autovalori.
    - **Matrice Diagonalizzante**: matrice che ha in colonna una base degli autovettori.
- **Teorema Autospazio**: sia $V$ un K-spazio vettoriale e $f: V \to W$ un endormofismo. Allora ne segue che $V_{\lambda} = \ker f_{\lambda}$.
    - **Dimostrazione** (7\*, L19): si usa la definizione dell'autospazio.
 ---
##### Geometria

---
