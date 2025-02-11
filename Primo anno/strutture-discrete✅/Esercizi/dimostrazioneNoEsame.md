Per dimostrare questo teorema dobbiamo enunciare e dimostrare 2 lemmi

###### Lemma 1: 
Sia $m>1$ e sia $C_m$ = $\{x: 0<x<m, MCD(x,m) = 1\}$ cioè l'insieme dei numeri interi positivi minori di $m$ e coprimi con $m$. Allora
- a) per ogni $x \in C_m$ esiste $y \in C_m$ tale $x*y ≡ 1(\mod m)$
- b) $C^{-1}_m$ = $\{x^{-1} \mod m: x \in C_m\} = C_m$

**Dimostrazione:**

**Punto (a):** Dimostrare che ogni elemento di $C_m$ ha un inverso moltiplicativo modulo $m$ che appartiene a $C_m$.
1. **Concetto chiave:**
   Grazie al **teorema di esistenza dell'inverso moltiplicativo** (l'inverso moltiplicativo di $2$ è $\frac{1}{2}$), sappiamo che ogni $x \in C_m$ ha un inverso $y$ tale che:  $x \cdot y \equiv 1 \pmod{m}.$
   Bisogna verificare che $y \in C_m$, cioè che $y$ sia coprimo con $m$.
2. **Proprietà utilizzate:**
   - Dalla definizione di $C_m$, $x$ è coprimo con $m$, quindi:
     $\text{MCD}(x, m) = 1.$
   - La proprietà fondamentale dell'inverso moltiplicativo ci garantisce che:
     $(x \cdot y) \mod m = 1.$
3. **Verifica che $y$ è coprimo con $m$:**
   - Per definizione, se $x \cdot y \equiv 1 \pmod{m}$, allora $y$ non può avere un divisore comune con $m$ diverso da 1 (altrimenti $x \cdot y$ non sarebbe congruo a 1 modulo $m$).
   - Quindi $\text{MCD}(y, m) = 1$, e quindi $y \in C_m$.

**Punto (b):** Dimostrare che $C^{-1}_m = C_m$.
1. **Definizione di $C^{-1}_m$:**
   $C^{-1}_m$ è l'insieme di tutti gli inversi moltiplicativi modulo $m$ degli elementi di $C_m$.

2. **Inclusione $C^{-1}_m \subseteq C_m$:**
   Dal punto (a), sappiamo che ogni elemento di $C_m$ ha un inverso modulo $m$ che appartiene a $C_m$. Questo implica che ogni elemento di $C^{-1}_m$ è un elemento di $C_m$.

3. **Inclusione $C_m \subseteq C^{-1}_m$:**
   Ogni $x \in C_m$ ha un inverso $y \in C_m$, ma possiamo considerare $y$ a sua volta come un elemento di $C_m^{-1}$. Siccome l'operazione di inversione è biunivoca (ovvero ogni elemento ha un singolo inverso), ogni elemento di $C_m$ corrisponde a un elemento di $C^{-1}_m$.

4. **Conclusione:**
   Poiché $C^{-1}_m \subseteq C_m$ e $C_m \subseteq C^{-1}_m$, possiamo affermare che: $C^{-1}_m = C_m.$

**Esempio:**
Per $m = 10$ abbiamo $C_{10} = \{1, 3, 7, 9\}$ e quindi che ( $ϕ(10)=ϕ(5)*ϕ(2)=4$ ):
- $1^{-1} \mod 10$ -> $1^{-1 \mod 4}\mod 10 = 1$ -> $1^3 \mod 10 = 1$,
- $3^{-1} \mod 10 = 7,$
- $7^{−1} \mod 10 = 3,$
- $9^{−1} \mod 10 = 9$.
Da questo concludiamo che $C^{−1}_{10}$ =$\{1, 7, 3, 9\}$

##### Lemma 2
Siano $n, m > 1$, tale che $MCD(n, m) = 1$. Sia $C_{n,m}$ = $\{(n · x) \mod m : x ∈ C_m \}$. Allora, $C_{n,m} = C_m$
###### Dimostrazione:

Per dimostrare che $C_{n,m} = C_m$, si procede in due passi:  
1. Dimostrare che $C_{n,m} \subseteq C_m$.  
2. Dimostrare che $C_m \subseteq C_{n,m}$.

---
###### 1. Primo passo: $C_{n,m} \subseteq C_m$  
Dimostriamo che ogni elemento di $C_{n,m}$ appartiene a $C_m$.
1. Prendiamo un $k \in C_{n,m}$. Per definizione di $C_{n,m}$, esiste un $x \in C_m$ tale che:  
   $k = (n \cdot x) \mod m$ con $0 \leq k < m$.
2. Supponiamo, per assurdo, che $k = 0$. Allora avremmo:  
   $n \cdot x = q \cdot m$
   cioè $m$ dividerebbe $n \cdot x$. Ma poiché $\text{MCD}(n, m) = 1$, $m$ non può dividere né $n$ né $x$, portando a una contraddizione.
3. Ne consegue che $k > 0$. Dato che $x \in C_m$, esiste l'inverso di $x$ modulo $m$, cioè un $x^{-1}$ tale che:  $x \cdot x^{-1} \equiv 1 \pmod{m}.$
4. Inoltre, poiché $\text{MCD}(n, m) = 1$, anche $n$ ha un inverso modulo $m$, chiamiamolo $n^{-1}$. Allora possiamo calcolare:  $k \cdot n^{-1} \equiv x \pmod{m}.$
5. Dato che $x \in C_m$, abbiamo che $x$ è coprimo con $m$. Questo implica che anche $k$, essendo congruente a $x$, è coprimo con $m$. Quindi:  $k \in C_m.$

---

###### 2. Secondo passo: $C_m \subseteq C_{n,m}$  
Dimostriamo ora che ogni elemento di $C_m$ appartiene a $C_{n,m}$.
1. Sia $x \in C_m$. Questo implica che $x$ è coprimo con $m$.
2. Poiché $\text{MCD}(n, m) = 1$, l'intero $n^{-1} \cdot x$ modulo $m$ esiste. Chiamiamolo $k$, ovvero:  
   $k = (n^{-1} \cdot x) \mod m.$
3. Possiamo riscrivere $x$ in termini di $k$:  $x = (n \cdot k) \mod m.$
4. Da questa relazione, vediamo che $k \in C_{n,m}$, perché $k$ è costruito come $n \cdot x \mod m$, con $x \in C_m$.
5. Dunque $x \in C_m \implies x \in C_{n,m}$.
**Conclusione:**
Poiché abbiamo dimostrato sia $C_{n,m} \subseteq C_m$ sia $C_m \subseteq C_{n,m}$, possiamo concludere che:  
$C_{n,m} = C_m.$

**Esempio:**
Per $m = 5$ e $n = 13$ abbiamo che $MCD(13,5) = 1$, inoltre $C_5$ = $\{1,2,3,4\}$ applicando la regola otteniamo $C_{13,5} = \{1*13 \mod 5, 2*13 \mod 5, 3*13 \mod 5, 4*13 \mod 5\}$, risolviamo i moduli:
- $1 · 13 \mod 5$ = $13 \mod 5$ = $3$
- $2 · 13 \mod 5$ = $26 \mod 5$ = $1$
- $3 · 13 \mod 5$ = $39 \mod 5$ = $4$
- $4 · 13 \mod 5$ = $52 \mod 5$ = $2$
Quindi $C_{13,5} = {3,1,4,2}$ 