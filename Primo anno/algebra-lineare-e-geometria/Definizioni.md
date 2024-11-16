
##### Algebra Lineare
$f:R \to R$ si legge "$f$ definita in $R$ a valori in $R$".

---
##### Strutture Algebriche
- **Insieme**: collezione di un elementi che hanno tutti una stessa caratteristica
- **Funzione**: dati due insiemi $A$ e $B$, si dice $f$ (funzione) una legge che associa ad ogni elemento di $A$ uno di $B$. [[01_Parte1#Funzioni |Spiegazione approfondita delle funzioni]]
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
**Moltiplicazioni tra matrici**: date 2 matrici A e B per poter fare la moltiplicazione tra queste deve essere vera **almeno una** delle 2 condizioni sottostanti:
1. numero di colonne di A  = numero di righe di B
2. numero di colonne di B = numero di righe di A
![[Pasted image 20241116153231.png]]
Ogni entrata della matrice "Risultato" è il risultato di una moltiplicazione tra una riga della prima matrice e una colonna della seconda. Di seguito il calcolo dell'entrata in posizione 1,1 della matrice "Risultato":
![[Pasted image 20241116153434.png]]

---

**Matrice identità:** denotiamo la matrice identità come $Id_m$. Definiamo matrice identità la matrice che rende vera questa cosa:
- $Id_m * A = A$
- $A * Id_m = A$
La matrice identità è una matrice quadrata che segue questa forma
$$\begin{pmatrix}
1 & 0 & 0 \\
0 & 1 & 0 \\
0 & 0 & 1
\end{pmatrix}
$$

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
---
**==Continuare dalla lezione del 15 ottobre 2024 in specifico dai sistemi lineari==**
##### Spazi Vettoriali
- **Spazio Vettoriale**: si dice spazio vettoriale su un campo K (K-spazio vettoriale) un insieme su cui sono definite due operazioni + e * (G, + \*) e valgono le proprietà:
    - (G, +) è gruppo
    - Con \* vale associatività.
    - Con \* esiste elemento neutro.
    - Vale distributività della somma rispetto al prodotto esterno. $(a+b)\cdot \vec v=a \vec v + b \vec v$
    - Vale distributività del prodotto esterno rispetto alla somma. $a \cdot (\vec v + \vec w)=a \vec v +a \vec w$
- **Sottospazio**: $W$ è sottospazio di $V$ se $W \subseteq V$ e  $W$ è un $K$ spazio vettoriale rispetto alle operazioni di somma e prodotto definite su $V$.
- **Intersezione tra sottospazi**: è sempre un sottospazio
- **Unione tra sottospazi**: è sottospazio solo se uno dei due è sottoinsieme dell'altro (ovvio)
- **Combinazione Lineare**: un vettore è combinazione lineare di $\vec{v_{1}}, \vec{v_{2}}, \dots, \vec{v_{n}}$ se esistono $a_{1}, a_{2}, \dots, a_{n}$ tali che $v=a_{1}\vec{ v_{1}}+a_{2}\vec{ v_{2}}+\dots+a_{n}\vec{ v_{n}}$.
- **Insieme di Generatori**: dato un K-spazio vettoriale $V$, un insieme $(v_{1}, v_{2}, \dots, v_{n})$ è detto insieme di generatori (indicato con $G \{ v_{1}, v_{2}, \dots, v_{n}\}$) se preso un qualunque vettore $\vec z \in V$ esso si può scrivere come combinazione lineare (C.L.) dei vettori di $G$.
- **Base**: un insieme  $(v_{1}, v_{2}, \dots, v_{n})$ è detto **Base** di $V$ se ogni elemento di $V$ è combinazione lineare (C.L.) di  $v_{1}, v_{2}, \dots, v_{n}$ in modo **unico**.
    - $B$ è base $\iff$ i vettori di $B$ sono L.I. e generatori.
- **Linearmente Indipendenti**: i vettori $v_{1}, v_{2}, \dots, v_{n}$ si dicono linearmente indipendenti se quando $a_{1}\vec{ v_{1}}+a_{2}\vec{ v_{2}}+\dots+a_{n}\vec{ v_{n}}=0$ allora ne deve seguire che $a_1=a_2=\dots=a_n=0$
- **Lemma di Steinitz**: numero di vettori generatori $\geq$ numero di vettori linearmente indipendenti.
- **Teorema che caratterizza una base**: dato $B = \{ v_{1}, v_{2}, \dots, v_{n} \}$, $B$ è un insieme $\iff$ i vettori sono L.I. e generatori.
- **Teorema sulle Basi**: tutte le basi di un K-spazio vettoriale hanno lo stesso numero di elementi.
    - **Dimostrazione** (2\*, L10): Si usa il Lemma di Steinitz.
---
##### Sistemi Lineari
- **Sistema Lineare**: sistema di equazioni a più incognite di massimo 1° grado (c'è il termine noto)
- **Teorema di Rouchè Capelli N°1**: $\rho(A) =\rho(A,B) \iff$ Sistema possibile (ammette almeno una soluzione).
- **Teorema di Rouchè Capelli N° 2**: quando il sistema è possibile ($\rho(A) =\rho(A,B) = \rho$) allora esistono $\infty^{n-\rho}$ soluzioni. $n-\rho$ indica il numero di incognite libere.
- **Teorema di Cramer**: $\det A \neq 0 \iff$ Sistema determinato (ammette una e una sola ($\exists!$) soluzione).
    - L'unica soluzione si calcola con:
    - $$\begin{cases}

x_{1}=\frac{\det B_{1}}{\det A} \\

x_{2}=\frac{\det B_{2}}{\det A} \\

\dots \\

x_{n}=\frac{\det B_{n}}{\det A} \\

\end{cases}$$

        - $B_{1}$ si calcola sostituendo la $1^a$ colonna di $A$ con $B$.
        - $B_{2}$ si calcola sostituendo la $2^a$ colonna di $A$ con $B$.
        - $\dots$
        - $B_{n}$ si calcola sostituendo la $n^a$ colonna di $A$ con $B$.
    - **Dimostrazione** (3\*, L13):
        - Nell'andata si dimostrano unicità, esistenza e formula.
        - L'unicità e l'esistenza si dimostrano con il **Teorema delle matrici invertibili**.
        - La formula si dimostra svolgendo l'equazione dell'esistenza.
        - Il ritorno si dimostra con il teorema di **Rouchè Capelli N°2**.
- **Sistema lineare omogeneo**: sistema lineare con $B$ nullo (non esistono termini noti).
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
