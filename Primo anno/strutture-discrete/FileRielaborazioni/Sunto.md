
# Parte 1
## Logica
Operatori logici:
- ¬ = NOT
- ∨ = OR disgiunzione
- ∧ = AND congiunzione
- $⇒$ = implica
- ⇔  = doppia implicazione
---
Dati $P_1$ e $P_2$ proposizioni logiche:
- $P_2$ ∨ ¬$P_2$ è una tautologia
- $P_2$ ∧ ¬$P_2$ è insoddisfacibile
- $¬(¬P_1) ≡ P_1$
- $P_1 ⇔ P_2 ≡ (P_1 ⇒ P_2) ∧ (P_2 ⇒ P_1)$
- $P_1 ⇒ P_2 ≡ ¬P_1 ∨ P_2$
- $¬(P_1 ∨ P_2) ≡ ¬P_1 ∧ ¬P_2$
- $¬(P_1 ∧ P_2) ≡ ¬P_1 ∨ ¬P_1$
---
- CNF (Forma normale congiuntiva) = AND di vari OR
- DNF (Forma normale disgiuntiva) = OR di vari AND
- [[Tips#Come trasformare una qualsiasi formula in CNF e DNF|✨metodo Di Bella ✨]]
---
## Insiemi
Un insieme è una collezione ben definita di oggetti
- $x \in T$  = x appartiene all'insieme $T$
- $x \notin T$ = x non appartiene all'insieme $T$
---
- **Insiemi uguali**: $A = B ⇔ (∀x)(x ∈ A ⇔ x ∈ B)$ A è uguale a B se e solo se qualsiasi x che appartiene ad A appartiene anche a B
---
- Possiamo definire un'insieme specificando le proprietà dei suoi elementi. Supponiamo che $P$ sia la proprietà di essere un numero pari minore di 10 allora 
  $A=\{x∈N∣x$ eˋ pari e $x<10\}$ ovvero $A=\{0,2,4,6,8\}$ 
---
- **Cardinalità**: definiamo cardinalità il numero di elementi che costituisce un insieme e si dento con: $|A|$
---
- **Sottoinsieme**: A ⊆ B ⇔ (∀x)(x ∈ A ⇒ x ∈ B) A è un sottoinsieme di B se e solo se qualunque x che appartiene ad A, appartiene anche a B

- **Sovrainsieme:** B ⊇ A ⇔ (∀x)(x ∈ A ⇒ x ∈ B) A è un sovrainsieme di B se e solo se qualunque x che appartiene ad A, appartiene anche a B
---
1. **Unione:** $A$ ∪ $B$ = {$x$ : $x ∈ A$ oppure $x ∈ B$.} $A$ unito $B$ è formato da qualsiasi $x$ che appartiene ad $A$ oppure a $B$
2. **Intersezione**: $A ∩ B$ = {$x$ : $x ∈ A$ e $x ∈ B$.} $A$ intersezione $B$ è formata dalle x che appartengono sia ad $A$ che a $B$
3. **Differenza:** $A \backslash B$ = {x : x ∈ A e $x \notin B$.} $A$ differenza $B$ è formato dalle $x$ che appartengono ad $A$ ma non appartengono a B
4. **Complemento**: $U \backslash A$ dove $U$ è l'insieme universo
5. **Differenza simmetrica**: $A∆B = (A \backslash B) ∪ (B \backslash A)$ è l'unione tra la differenza fra gli insiemi
---
- $A ⊆ B$ o $B ⊆ A$: Per dimostrarlo si considera un elemento generico x ∈ A e si dimostra che x ∈ B
- $A = B$: Per dimostrarlo dobbiamo dimostrare che hanno gli stessi elementi. Quindi si dimostra che A ⊆ B e B ⊆ A. 
- $A = ∅$: Per dimostrarlo si fa vedere che la definizione di appartenenza ad A porta ad una contraddizione.
---
**Insieme delle parti**: Dato un'insieme $T$ consideriamo insieme delle parti di $T$ un'insieme che contiene tutti i sottoinsiemi di $T$ e lo denotiamo così: $pow(T)$, $|pow(T)| = 2^n$ è il numero di elementi di $T$, l'insieme delle parti ha le seguenti proprietà:
- $P(A ∩ B) = P(A) ∩ P(B)$
> [!WARNING] Dimostrazione
> Per dimostrare che è vera l'equivalenza dobbiamo dimostrare 2 casi:
> 1. Caso ⊂: supponendo che $X ∈ P(A ∩ B)$  e quindi che $X ⊂ A$ e $X ⊂ B$ da questo capiamo facilmente che  $X ∈ P(A)$ e $X ∈ P(B)$ e quindi che $X ∈ P(A) ∩ P(B)$
> 
 2. Caso ⊃: supponiamo che $X ∈ P(A) ∩ P(B)$ e quindi che $X ⊆ A$ e $X ⊆ B$ quindi $X ⊆ A ∩ B$ ciò implica che $X ∈ P(A ∩ B)$
- $P(A ∪ B) ⊃ P(A) ∪ P(B)$ 
> [!WARNING] Dimostrazione
> Per dimostrare questa formula dobbiamo dimostrare che $P(A ∪ B) ⊃ P(A) ∪ P(B)$ ma anche che un generico elemento di $P(A ∪ B)$ non appartenga a $P(A) ∪ P(B)$ 
> 1. Caso ⊃: Supponiamo che $X ∈ P(A) ∪ P(B)$, allora $X ∈ P(A)$ oppure $X ∈ P(B)$.Nel primo caso $X ⊆ A$ mentre nel secondo caso $X ⊆ B$. In entrambi i casi, quindi, $X ⊆ A ∪ B$ da cui $X ∈ P(A ∪ B)$.
 2. Caso $\neq$ : Sia A = {1, 2} e B = {1, 3}. L’insieme $A ∪ B$ = {1, 2, 3} appartiene a $P(A ∪ B)$ ma non appartiene a $P(A)$ ∪ $P(B)$ ( ricordiamo che P(A) = { ∅, {1}, {2}, {1,2} }  invece P(B) = { ∅, {1}, {3}, {1,3} } ) 
---
- **Famiglia di insiemi**: sarebbe un insieme di insiemi (ES: l'insieme delle parti)
---
- **Insiemi chiusi**: Sia dato un insieme $U$ ed un operazione, se quest'ultima può essere definita o completata in $U$ allora possiamo dire che $U$ e chiuso rispetto a quell'operazione
---
Sia $F$ una famiglia di insiemi (Tipica forma di $F$ = $\{\{1\}, \{2, 3\}, \{1, 2\}\}$): 
- **Chiusura rispetto all'unione:** diciamo che $F$  è chiusa rispetto all’unione se per ogni coppia di insiemi $X$ e $Y$ appartenenti a $F$ anche $X ∪ Y$ appartiene a $F$.
- **Chiusura rispetto all'intersezione:** diciamo che $F$ è chiusa rispetto all’intersezione se per ogni coppia di insiemi $X$ e $Y$ appartenenti a $F$ anche $X ∩ Y$ appartiene a $F$.
- $F^C$ = {$X^C$ : $X$ ∈ $F$ } ovvero come l'insieme di tutte le $X$ ∈ $F$ però complementate ($X$).
- La famiglia $F$ è chiusa rispetto all’unione se e solo se la famiglia $F^C$ è chiusa rispetto all’intersezione.
- La famiglia $F$ è chiusa rispetto all’intersezione se e solo se la famiglia $F^C$ è chiusa rispetto all’unione.
> [!WARNING] Dimostrazione
> ![[Pasted image 20241019115203.png]]

---
- **Partizioni**: Una famiglia di insiemi $F$ formata da sottoinsiemi dell'insieme universo $U$ può essere chiamata anche partizione di $U$ 
---
- **Insieme prodotto:** $A \times B$ = $\{(x, y) : x ∈ A$ e $y ∈ B\}$ $A×B$ è l'insieme di tutte le coppie $(x, y)$ con $x$ che appartiene ad $A$ e $y$ che appartiene a $B$

## Relazioni e funzioni

**Relazione**: $R ⊆ U × U$ ovvero un sottoinsieme dell'insieme prodotto $U \times U$ ovvero: $\{(x, y) \in U \times U : R(x, y)$ è vera$\}$ in altre parole un insieme formato da tutte le coppie ordinate che rendono vera la relazione. [[Sunto#^e57522|Proprietà qui]]

---
**Funzione:** Una relazione $f$ definita su $A × B$ si dice funzione da $A$ (dominio) in $B$ (codominio) se per ogni $x ∈ A$ esiste uno ed uno solo $y ∈ B$ tale che $(x, y) ∈ f$ e quindi che $f(x)=y$. 

---
**Definizioni:**
- $f : A → B$  per ogni $x$, $f(x) = x$ si dice **applicazione identica** di $A$
- $f : A \times B → A$ tale che per ogni $(x, y)$ $f(x, y)$ = $x$ si dice **proiezione canonica** su $A$.
- $f : A \times B → B$ tale che per ogni $(x, y)$ $f(x, y)$ = $y$ si dice **proiezione canonica** su $B$.
- $f(A) = \{ y \in B \;|\; \exists x \in A \; \text{tale che} \; f(x) = y \}.$ si dice **immagine dell'applicazione $f$** e rappresenta tutti i valori che la funzione può assumere
---
- **Funzione iniettiva**: $f$: $A$ → $B$ se porta punti distinti del dominio su su punti distinti del codominio, di solito viene chiamata funzione "uno a uno". La cardinalità deve essere così: $|A|\le|B|$
- **Funzione surgettiva:** $f$: $A$ → $B$ una funzione che associa ad ogni elemento di B (codominio) **almeno** un'elemento di A(dominio). La cardinalità deve essere così: $|A|\ge|B|$
- **Funzione biiettiva**:$f$: $A$ → $B$ se una funzione è sia iniettiva che surgettiva
> [!TIP] Nota bene
> 1. Una ***funzione iniettiva*** può avere elementi del codominio che non vengono raggiunti.
> 2. Una ***funzione suriettiva***, invece, raggiunge tutti gli elementi del codominio.
> 3. La **corrispondenza biunivoca** è una relazione tra due insiemi che stabilisce un legame univoco tra gli elementi di un insieme e quelli di un altro. In termini formali è una funzione **biiettiva**.

---
**Cardinalità di un insieme**: definita come il numero di elementi che appartengono all'insieme

> [!WARNING] Dimostrazione
> **Teorema**
> Se $A$ e $B$ sono due insiemi finiti ed esiste una funzione **iniettiva** $f:A→B$, allora la cardinalità di $A$ è minore o uguale alla cardinalità di $B$, cioè $|A| \le |B|$
> **Dimostrazione**
> Si considera l'immagine $f(A)$, cioè l'insieme di elementi di $B$ a cui $A$ viene mappato. Poiché $f$ è iniettiva, ogni elemento di $A$ corrisponde a un elemento unico di $f(A)$, quindi $∣A∣=∣f(A)∣$. Tuttavia, $f(A)$ è un sottoinsieme di $B$ (cioè tutti gli elementi di $f(A)$ appartengono a $B$), quindi $∣f(A)∣≤∣B∣$. Da qui segue che $|A| \le |B|$.

---
**Proprietà delle relazioni** ^e57522
Sia dato un insieme $U$ diremo che una relazione $R(x, y)$ definita in $U×U$ è:
- **Riflessiva**: se $∀x∈U$ risulta vero che $R(x, x)$.
- **Simmetrica**: se $∀x, y ∈ U$ risulta vero che $R(x, y)$ e anche $R(y, x)$ 
- **Transitiva**: se $∀x,y,z ∈ U$ risulta vero che $R(x, y)$ e $R(y, z)$ allora ci deve essere anche una $R(x, z)$ 
- **Antisimmetrica**: $∀x, ∀y ∈ U$ risulta vero che $R(x, y)$ e $R(y, x)$ $→ x = y$ 
Una relazione che è sia riflessiva, simmetrica e transitiva si dice relazione di **equivalenza** e si indica cosi: $x ≈ y$.
---
**Classe di equivalenza**: Dato un insieme $U$ e una relazione di equivalenza su $U$, la **classe di equivalenza** di un elemento $x \in U$, indicata con $[x]$, è il sottoinsieme di $U$ formato da tutti gli elementi equivalenti a $x$: $[x] = \{y \in U \;|\; y \sim x\}.$ 
> [!WARNING] Dimostrazione
> **Teorema** 
> Due classi di equivalenza o sono disgiunte o coincidono.
> **Dimostrazione**
> Siano $[x]$ e $[z]$ due classi di equivalenza e supponiamo che esse abbiano un elemento $w$ in comune: pertanto è $w ≈ x$ e $w ≈ z$. Allora, per la proprietà transitiva è $x ≈ z$. Sia ora $y ∈ [x]$, cioè $y ≈ x$. Per la proprietà transitiva è $y ≈ z$, cioè $y ∈ [z]$. Quindi, $[x] ⊆ [z]$. Analogamente si dimostra che $[z] ⊆ [x]$. Quindi possiamo dire che **se** due classi di equivalenza non sono disgiunte allora devono necessariamente coincidere.

---
**Vari ordinamenti delle relazioni**
- Si dice di **preordinamento** una relazione binaria assegnata in un insieme che goda della proprietà riflessiva e transitiva.
- Si dice ***ordinata*** una relazione binaria assegnata in un insieme che goda della proprietà riflessiva, transitiva e antisimmetrica.
---
**Massimi e minimi**
In un insieme, non sempre tutti gli elementi sono confrontabili. Il **massimo/minimo** è l’elemento più **grande/piccolo** di tutti, mentre il **massimale/minimale** è l’elemento più **grande/piccolo** tra tutti gli elementi confrontabili

---
**Problema dell'hitting set**
Siano $U$ un insieme finito, $H ⊆ U$, e sia $A$ una famiglia di sottoinsiemi di $U$ tutti diversi dall’insieme vuoto. Diciamo che $H$ è un hitting set ($HS$) per $A$ se e solo se per ogni $A ∈ A$ si ha $A ∩ H$ $\neq$ ∅. Possono esistere diversi hitting set dentro un'insieme, si definisce **hitting set minimo** l'hitting set con meno elementi. Per trovare l’HS di un insieme con 100 elementi, ci vorrebbero circa 40 miliardi di anni 

# Parte 2
##