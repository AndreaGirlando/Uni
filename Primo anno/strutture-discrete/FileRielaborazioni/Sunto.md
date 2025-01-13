
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
Siano $U$ un insieme finito, $H ⊆ U$, e sia $A$ una famiglia di sottoinsiemi di $U$ tutti diversi dall’insieme vuoto. Diciamo che $H$ è un hitting set ($HS$) per $A$ se e solo se per ogni $A ∈ A$ si ha $A ∩ H$ $\neq$ ∅.
**Hitting set minimo e minimale**: Siano $U$ un insieme finito, $H ⊆ U$, e sia $A$ una famiglia di sottoinsiemi di $U$ tutti diversi dall’insieme vuoto. Se $H$ è un hitting set e per ogni $x ∈ H$ l’insieme $H \backslash \{x\}$ non è un hitting set, diciamo che $H$ è un hitting set minimale. Se $H$ è un hitting set tale che $|H| = min\{|K | : K$ è un hitting set $A\}$ allora $H$ è un hitting set minimo

# Parte 2
## Numeri Interi
---
L'insieme dei numeri naturali viene definito da:
- Esiste un numero naturale 0
- Ogni numero naturale ha un successore denotato come $S(a)$ 
- Non esiste numero naturale il cui successore è 0
- Numeri naturali distinti hanno successori distinti

---
**Assioma del buon ordinamento**: Introducendo la funzione successore $S(a)$ è possibile definire una relazione di buon ordinamento sui numeri naturali, questo viene chiamato **assioma del buon ordinamento** quindi dato un generico insieme $S$ esiste un elemento minimo $s \in S$

---
**Principio di induzione**: se una proprietà $P$ è valida per il numero $0$ e, ogni volta che è valida per $n$ è valida anche per $n+1$ allora $P$ è valida per tutti i numeri naturali

> [!WARNING] Dimostrazione
> **Teorema**: Sia $P$ una affermazione riguardante i numeri naturali. Se:
> 1. $P(0)$ è vera ed inoltre
> 2. per ogni numero naturale $n$ se $P(n)$ è vera allora è vera anche $P(n+1)$
> 
> **Dimostrazioni:** Ragioniamo per assurdo e sopponiamo falsa la tesi, ossia supponiamo che esiste almeno un numero naturale $n$ per cui $P(n)$ è falsa, e costruiamo così il seguente insieme:
> 
> $S = \{ n: n\in \mathbb{R}$ e $P(n)$ è falsa$\}$
> 
> Per la nostra ipotesi $S$ non è vuoto. Per l'assioma del buon ordinamento dentro $S$ abbiamo un elemento minimo $s$. Per definizione di $S$, $P(s)$ è falsa, dal teorema sappiamo che $P(0)$ è vera quindi $s\not=0$. Poiché $S ⊂ \mathbb{N}$ deve essere $s>0$, essendo $s$ maggiore di 0 ha un predecessore ovvero $s - 1$, dal momento che $s-1<s$ abbiamo che $s-1\notin S$ è vera ($s$ è il più piccolo elemento di $S$). Questo implica che per il caso 2 del teorema che se $P(s-1)$ è vera anche $P(s)$ è vera, siamo arrivati ad una contraddizione
>  
> [[Esempio principio di induzione.pdf]]

---
**Aritmetica modulare:** Dati due interi $a, b ∈ Z$, chiamati rispettivamente dividendo e divisore, esistono unici due interi relativi $q, r$, denominati rispettivamente quoziente e resto.
- $+n \mod +m$: dividi $n$ per $m$ e prendi il resto
- $-n \mod +m$: dividi $-n$ per $m$ prendi il resto, calcoli il resto reale cosi: $r = b - r'$
- $+n \mod -m$: dividi $n$ per $m$ e prendi il resto
- $-n \mod -m$: dividi $n$ per $m$, prendi il resto e calcoli il resto reale cosi: $r = -n - r'$ 
---
**Definizione di divisibilità:** Dati 2 interi relativi $n,m \in Z$ si dice che $m$ è un divisore di $n$ $(m|n)$ se esiste un intero relativo $k \in Z$ tale che $n = k \times m$. 

---
**Numero dispari:** un numero dispari ha questa forma: $n = 2k + 1$

> [!WARNING] Dimostrazioni
> **Teorema**: la somma dei primi $n$ numeri dispari è $n^2$ 
> **Dimostrazione**:
> - **Caso base**: $n = 1$ e la somma in questo caso è proprio $1 = 1^2$
> - **Caso induttivo**: Assumendo che la somma dei primi $n-1$ numeri dispari è uguale a $(n-1)^2$ e un generico numero dispari è definito con: $n = 2k+1$, quindi se aggiungiamo a  $(n-1)^2$ il numero dispari successivo quindi $2(n-1)+1$ otteniamo:
> - $(n-1)^2 + 2(n-1)+1 = n^2-2n+1+2n - 2 + 1 = n^2$

---

> [!WARNING] Dimostrazioni
> **Somma**
> **Teorema:** Se $a|b$ e $a|c$ allora $a | (b+c)$
> **Dimostrazione:** Dato che $a | b$ esiste $x$ tale che $b = ax$, e dato che $a | c$ esiste $y$ tale che $c = ay$. Quindi $b + c = ax + ay = a(x + y)$ e ponendo $z = x + y$ abbiamo trovato un intero tale che $b + c = az$ dimostrando che $a | (b + c)$.
> ---
> **Prodotto**
> **Teorema:** Se $a | b$ allora $a | bc$
> **Dimostrazione:** Dato che $a | b$ esiste $x$ tale che $b = ax$, quindi $bc = axc$ il che dimostra che $a | bc$
> ---
> **Transitività**
> **Teorema:** Se $a | b$ e $b | c$ allora $a | c$
> **Dimostrazione:** Dato che $a | b$ esiste $x$ tale che $b = ax$, e dato che $b | c$ esiste $y$ tale che $c = yb$. Quindi $by = axy$ ossia $c = axy$ e ponendo $z = xy$ abbiamo trovato un intero tale che $c = az$ dimostrando che $a | c$
> ---
> **Quadrato**
> **Teorema**: Se $a|b$ allora $a|b^2$
> **Dimostrazione**: Dato che $a|b$ esiste $x$ tale che $b = ax$, quindi $bc = axc$ questi dimostra che $a | b*b$
> ---
> **Combinazione lineare**
> **Teorema**: Se $a|b$ e $a|c$ allora $a | (hb + kc)$ per ogni $h,k \in Z$
> **Dimostrazione**: Se $a | b$ allora $a | hb$, se $a | c$ allora $a | kc$ ovviamente valgono per ogni $h,k \in Z$ e quindi è vero che $a | (hb + kc)$
> ---
> **Proprietà del numero 0** 
> **Teorema:** Ogni $a \in Z$ è divisore di $0$
> **Dimostrazione**: $a \in Z$ abbiamo che $a * 0 = 0$ quindi $a | 0$
> ---
> **Antisimmetrica**
> **Teorema:** Siano $a,b \in Z$ se $a | b$ e $b|a$ allora $|a| = |b|$ ossia $a = \pm b$
> **Dimostrazione**: Dalle ipotesi abbiamo che $b = ax$ e $a = by$. Quindi $a = axy$, raccogliendo a arriviamo ad $a(xy - 1)$ questo implica che $a$ sia $0$ oppure che $xy = 1$ da questo capiamo che: 
> - Se $a = 0$ allora anche $b = 0$ (perché b = 0x)
> - Se $xy = 1$ allora $a$ o $b$ sono uguali a $\pm 1$
> ---
> **Divisori banali**
> **Teorema**: Siano a $\in$ Z allora $\pm a | a$  e $\pm 1 | a$
> **Dimostrazione:** Avendo che $a=a⋅1$ oppure che $a=(−a)⋅(−1)$ possiamo affermare che $\pm a | a$
> - Seguendo la definizione capiamo che $a = b ⋅ k$ in questo caso $b = \pm a$ il k che soddisfa le nostre equazioni è k = 1
> Avendo che $a = 1 * a$ possiamo dire che 1 è sempre un divisore di $a$

---
- **Minimo comune multiplo:** Dati $a,b \in Z$ si chiama minimo comune multiplo fra $a$ e $b$ un terzo intero positivo $m$ che è il più piccolo multiplo in comune sia di $a$ che di $b$
- **Massimo comune divisore**: Dati $a,b \in Z$ si chiama Massimo Comune Divisore un terzo intero $d \in Z$ tale che $d|a$ e $d|b$ cioè $d$ è il più grande divisore comune tra $a$ e $b$.
---
**Algoritmo di Euclide:** questo è il metodo migliore per il calcolo del MCD e si basa sulla seguente osservazione siano $a,b\in \mathbb{N}$ e sia $b \le a$:
- **Caso base**: Se $b = 0$ allora il $MCD(a,b) = a$. Questo perché qualsiasi numero è divisibile per s
- **Passo induttivo**: Supponiamo che $a=qb+ra$ , dove $q$ è il quoziente intero della divisione di $a$ per $b$, e $r$ è il resto, con $0≤r<b$  allora $MCD(a,b)$ = $MCD(b,r)$

> [!WARNING] Dimostrazione
> **Teorema:** $MCD(a,b) = MCD(b,r)$
> **Dimostrazione:** 
> - Se $d$ è un divisore di $a$ e $b$ allora esistono $h$ e $k$ tali che $a = hd = qkd + r$. Quindi $r = d(h-qk)$ e quindi $d$ è anche un divisore di $r$.
> - Viceversa, se $d$ è un divisore di $b$ e di $r$ allora esistono $h$ e $k$ tali che $a = qb + r = qkd + hd$ e quindi $d$ è un divisore di $a$ visto che $a = d(qk + h)$

> [!EXAMPLE] Esempio
> 
> $x_1 = 330$ e $x_2 = 156$
> $x_3 = 330\mod156 = 18$
> $x_4 = 156\mod18=12$
> $x_5 = 18 \mod 12 = 6$
> $x_6 = 12 \mod 6 = 0$
> Quindi $MCD(330, 156) = 6$.
> Da questo capiamo che il minimo comune divisore tra 2 numeri può essere calcolato trovando ripetutamente il modulo tra b ed il resto

---
**Numero primo:** si definisce primo un numero che ha come divisori 1 e se stesso.
**Numeri coprimi**: Due numeri $a,b$ si dicono **comprimi** se MCD(a,b) = 1 e quindi esistono $h,z$ tali che $(a · h + b · k) = 1$

> [!WARNING] Dimostrazione
> **Teorema:** Due numeri interi consecutivi sono coprimi
> **Dimostrazione:** Siano $n$ e $n+1$ due numeri interi consecutivi, allora per $h=1$ e $k=-1$ abbiamo $1 = h \times (n+1) + k \times n$ 
> ---
> **Teorema**: Siano $a,b,c \in Z$ tali che $c| a * b$ con $c$ ed $a$ coprimi allora $c|b$
> **Dimostrazione:** Siano $a, b, c ∈ Z$ tali che $c | a · b$ con $c$ e $a$ coprimi. Quindi, esiste $h$ tale che $hc = ab$ ed esistono $k, k′$ tali che $1 = ka + k′c$. Moltiplicando per $b$ ambo i termini dell’ultima uguaglianza otteniamo $b = kab + k′cb$ da cui $b = khc + k′cb = c(kh + k′b)$ e quindi $c | b$
> ---
> **Teorema:** Siano $a, b, c ∈ Z$ tali che $a | c$ e $b | c$, se $a$ e $b$ sono coprimi allora $a \times b | c$
> **Dimostrazione:** Siano $a, b, c ∈ Z$ tali che $a | c$ e $b | c$, ed $a e b$ coprimi. Allora esistono $h, k, h′, k′$ tali che $c = ah$, $c = bk$, e $1 = ah′ + bk′$. Moltiplicando per $c$ ambo i termini dell’ultima uguaglianza otteniamo $c = ah′c + bk′c = ah′bk + bk′ah = ab(h′k + k′h)$ e quindi $ab | c$.

---
**Fattorizzazione degli interi:** ogni intero $n>1$ si può esprimere come prodotto di numeri primi positivi ed in modo unico.

> [!WARNING] Dimostrazione
> **Teorema:** preso un qualunque numero $n>1$ esiste una fattorizzazione di $n$
> **Dimostrazione:** Se per assurdo esistessero interi > 1 che non sono prodotto di numeri primi positivi potremmo costruire l'insieme 
> - $S = \{n: n \in N,$ non prodotto di numeri primi $\}$ 
> 
> Per l'assioma del buon ordinamento, dentro questo insieme abbiamo un minimo che chiameremo $s$, $s$ non è primo (perché senno sarebbe un prodotto di numeri primi positivi) quindi vuol dire che ha almeno un divisore non banale positivo chiamato $d$, avendo un divisore vuol dire che esiste un intero positivo $c$ che moltiplicato per $d$ ci da $s$, Poiché, $c$ ed d sono minori di $s$, che ricordiamo è il più piccolo elemento in $S$, allora $c$ e $d$ sono prodotti di primi positivi, e quindi anche $s$ lo è
> 
> ---
> **Teorema**: la fattorizzazione è unica
> **Dimostrazione:** Se $n = p_1 \cdot p_2 \cdots p_r = q_1 \cdot q_2 \cdots q_s$ dobbiamo dimostrare che $r = s$ e lo facciamo in questo modo:
> - **Caso base**: $r = 1$ Se $n = p_1$ allora $n$ è primo, da $p_1 = q_1 \cdot q_2 \cdots q_s$  otteniamo che $s = 1$ e $q_1 = p_1$
> - **Caso induttivo**: supponendo che sia vera questa tesi per r, dimostriamola per r+1, quindi: $n = p_1 \cdot p_2 \cdots p_{r+1} = q_1 \cdot q_2 \cdots q_s$ , dal caso base sappiamo che $q_1$ è divisore di $p_1$ e che quindi dividendo membro a membro per $p_1$ otteniamo $p_2 \cdots p_r \cdot p_{r+1} = q_2 \cdots q_s$ da questo capiamo che $r = s - 1$ e quindi che $s = r + 1$ quindi i fattori coincidono a meno dell'ordine e quindi che sono uguali.
> 

---
**Teorema di Euclide**: i numeri primi sono infiniti

> [!WARNING] Dimostrazione
> **Teorema:** i numeri primi sono infiniti
> **Dimostrazione:** Supponiamo che ci sia un numero finito di numeri primi. Se così fosse, potremmo elencarli tutti. Chiamiamo questi numeri primi $p_1, p_2, \dots, p_n$, dove $p_1 = 2$, $p_2 = 3$, e così via fino a $p_n$ , che rappresenterebbe l’ultimo numero primo. Ora definiamo $h = p_1 \cdot p_2 \cdots p_n + 1$, per costruzione, $h$ è maggiore di tutti i numeri primi $p_1, p_2, \dots, p_n$, inoltre sappiamo che non è divisibile da nessuno dei numeri primi. A questo punto, possiamo concludere che $h$ o è primo oppure è divisibile da un numero primo non presente nella lista $p_1, p_2, \dots, p_n$:
> - Se $h$ è primo, allora abbiamo trovato un nuovo numero primo che non era incluso nella lista originale, il che contraddice l’ipotesi che $p_1, p_2, \dots, p_n$ fossero tutti i numeri primi.
> - Se $h$ non è primo, allora deve avere un divisore primo che non è nessuno dei $p_1, p_2, \dots, p_n$, il che ancora una volta contraddice l’ipotesi che $p_1, p_2, \dots, p_n$ siano tutti i numeri primi.

---
**Crivello di Eratostene**: metodo migliore per calcolare tutti i numeri primi minori o uguali ad un numero $n$ [Esempio](https://youtu.be/0MDvEByNGic?t=83||)

---
**Radice numerica**: dato un numero $n$ la sua radice numerica di $n$, la denotiamo con $ρ(n)$ ed è la somma delle sue cifre reiterata sono ad ottenere una sola cifra

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


> [!WARNING] Dimostrazione
> **Teorema**: Sia $n$ un numero naturale e sia $m$ la somma delle sue cifre. Allora $n-m$ è divisibile per 9.
> **Dimostrazione: **Sia $n$ un numero, rappresentato come: $n = \sum_{i=0}^{k} a_i \cdot 10^i$ dove $a_0, a_1, \dots, a_k$ sono le cifre del numero $n$, con $a_0$ che rappresenta le unità, $a_1$ le decine, e così via. Ora consideriamo un altro numero $m$, che ha la forma:- $m = \sum_{i=0}^{k} a_i$
Questo numero $m$ è la somma delle cifre di $n$. La differenza tra $n$ e $m$ è:
$n - m = \sum_{i=0}^{k} a_i \cdot 10^i - \sum_{i=0}^{k} a_i = \sum_{i=0}^{k} a_i \cdot (10^i - 1) = \sum_{i=0}^{k} a_i \cdot 9 \cdot b_i = 9 \cdot \sum_{i=0}^{k} a_i \cdot b_i$

---

> [!WARNING] Dimostrazione
> **Teorema:** $\sqrt{2}$ non è razionale
> **Dimostrazione:** Assumendo che esistano 2 numeri naturali $a$ e $b$  tale che $\sqrt{2} = \frac{a}{b}$, assumendo anche che sia ridotta ai minimi termini almeno uno dei 2 è dispari. Elevando al quadrato otteniamo $a^2 = 2b^2$ essendo $a^2$ il doppio di un altro numero sarà per forza pari, detto ciò anche $a$ è pari è quindi esiste un numero $k$ tale che $a = 2k$ da questo avremo allora:
> - $2b^2 = a^2 = 4k^2$ e quindi che anche $b$ è pari visto che $b^2 = 2k^2$
> 
> questa affermazione contraddice la nostra ipotesi inziale

---
## Aritmetica modulare

**Congruenza modulo $m$**
Un intero $a \in Z$ è in relazione con $b \in Z$ se $m | (a-b)$ e quindi che $a-b$ è un multiplo di $m$. In modo equivalente potemmo dire che $a$ è in relazione con $b$ se $a \mod m$ = $b \mod m$. Denotiamo questa relazione così:
- $a \equiv b \pmod{m}$ se è vera
- $a \not\equiv b \pmod{m}$ se è falsa
La relazione di congruenza è una relazione di equivalenza:
- **Riflessiva**: Per ogni $a \in \mathbb{Z}$, è vero che $a \equiv a \pmod{m}$
- **Simmetrica:**  Se $a ≡ b(\mod m)$ allora $b ≡ a(\mod m)$
- **Transitiva:** Se $a ≡ b(\mod m)$ e b ≡ $c(\mod m)$ allora $a ≡ c(\mod m)$
---
**Classi di equivalenza definite dalla congruenza**: Le classi di equivalenza definite dalla congruenza modulo mmm raggruppano i numeri interi in base al loro resto quando divisi per mmm. Per $m=0$, ogni numero forma una classe distinta perché è uguale solo a sé stesso. Per $m=1$, tutti i numeri appartengono alla stessa classe, dato che ogni numero è multiplo di 1. Per $m=2$, i numeri si dividono in due classi: una con i numeri pari e una con i dispari. In generale, una classe di equivalenza modulo mmm contiene tutti i numeri che danno lo stesso resto quando divisi per m.

---

> [!WARNING] Definizioni
> **Teorema:** fissato un intero $m>1$ le sue classi di equivalenza sono: $[0]_m, [1]_m, [2]_m, \dots, [m-1]_m.$
> **Dimostrazione:** 
> Sia $a ∈ Z$ e sia $r$ il resto della divisione intera di $a$ per $m$, ovvero, applicando l’algoritmo di divisione
> - $a = qm + r$ con $0 ≤ r < m$. 
>
> Dal momento che $a − r = qm$ abbiamo che $a ≡ r (\mod m)$. Quindi, dal momento che $r$ può assumere solo i valori che vanno da $0$ a $m − 1$ le classi di equivalenza sono solo quelle dell’enunciato del teorema.
> 
> ---
> **Teorema:** Le classi definite dalla congruenza sono distinte
> **Dimostrazione**: Ragioniamo per assurdo e supponiamo che esistano $x, y ∈ Z$, $x \not= y$ e $0 ≤ x$, $y < m -1$ tali che $[x]_m$ = $[y]_m$ . Senza perdita di generalità supponiamo che $x > y$. Dall’ipotesi possiamo scrivere $x − y = km$ cioè $x − y$ è un multiplo di $m$. Da $0 ≤ x, y < m − 1$ e $x > y$ segue che $0 < x − y < m − 1$, che è una contraddizione visto che non esistono multipli di m in tra $0$ e $m − 1$.

---
**Invarianza rispetto a somma e prodotto**: Dato $m \in N$ e dati $a,b \in Z$ tali che $a \equiv b \pmod{m}$ allora prendendo $c,d \in Z$ tali che $c \equiv d \pmod{m}$ abbiamo che:
- $a + c \equiv b + d (\mod m)$
- $a * c \equiv b * d (\mod m)$

> [!WARNING] Dimostrazione
> **Teorema**: Definizione di invarianza rispetto a somma e prodotto
> **Dimostrazione:**
> 1. $(a+c) - (b+d) = (a-b) + (c-d) = (k_1$ + $k_2$)$m$ (da questo capiamo che qualsiasi sia l'ordine delle lettere avremo sempre dei multipli di $m$)
> 2. Abbiamo $a = b+k_1m$ e $c = d + k_2m$ quindi $ac-bd = (b + k_1m)(d + k_2m) - bd = bk_2m+dk_1m+k_1k_2m^2 = (bk_2 + dk_1 + k_1k_2m)m$

---
 
> [!WARNING] Dimostrazione
> **Teorema:** Per ogni $m \in N, m>1$ prendendo una qualunque sequenza di m interi questa contiene un intero divisibile per m
> **Dimostrazione**: Consideriamo allora $m$ interi consecutivi, dove il più piccolo è $n$, Come abbiamo già dimostrato, le classi di equivalenza della relazione di congruenza modulo $m$ sono $[0]_m , [1]_m , [2]_m , . . . [m − 1]_m$ , il nostro numero $n$ si trova in una di queste classi di equivalenza, supponiamo stia nella classe $[i]_m$ per $0 ≤ i ≤ m − 1$. Quindi $n ≡ i(\mod m)$ ed allora $n + 1 ≡ i + 1(\mod m)$ ovvero $n + 1 ∈ [i + 1]m$. Notiamo allora che se $i = 0$ ovvero $n ∈ [0]_m$ abbiamo dimostrato il teorema. Se invece $i > 0$, visto che $0 < i < m$ incrementando $i$ esattamente $m − i$ volte, con $m − i < m$ otteniamo che $n + (m − i) ≡ i + (m − i)(\mod m)$ ossia $n + (m − i) ≡ m(\mod m) ≡ 0(\mod m)$. In conclusione, $n + (m − i)$ è il numero multiplo di $m$ nella sequenza di $m$ numeri consecutivi.

---
**Esercizi importanti**
![[Pasted image 20241109153614.png]]

---
**Inverso modulare**: anche nell'aritmetica modulare esiste il concetto di inverso modulare. Siano $a, b ∈ N$ entrambi maggiori di zero. Allora, esiste un elemento $x ∈ N$ tale che $a · x ≡ 1(\mod b)$ se e solo se $a$ e $b$ sono coprimi. L'elemento $x$ viene chiamato "inverso di $a$ modulo $b$"

> [!WARNING] Dimostrazione
> **Teorema:** definizione di inverso modulare
> **Dimostrazione:** ![[Pasted image 20241116095002.png]] 
## Funzione di Eulero