Questo file è la rielaborazione delle slide [[02_Parte2.pdf]] 


![[Pasted image 20241026111409.png]]

Sull'insieme N sono definite 2 operazione: 
- **Somma**: operazione che ad ogni coppia di numeri $(n, m)$ associa il numero $n+m ∈ N$ 
- **Prodotto**: operazione che ad ogni coppia di numeri $(n,m)$ associa il numero $n*m ∈ N$ 
Sull'insieme Z sono definite 3 operazioni:
- **Somma e prodotto** come definite per N
- **Differenza**: operazione che ad ogni coppia di numeri $(n,m)$ associa il numero $n-m$ ∈ Z
- In Z definiamo anche il valore assoluto in questo modo 
$|n| = \begin{cases} n & \text{se } n \geq 0 \\ -n & \text{se } n < 0 \end{cases}$
Giuseppe Peano dà una definizione dell'insieme dei numeri naturali in questo modo:
- Esiste un numero naturale 0
- Ogni numero naturale $a$ ha un numero naturale successore denotato come $S(a)$
- Non esiste il successo di 0
- Numeri naturali distinti hanno successori distinti

Introducendo la funzione successore (***S(a)***) è possibile definire una relazione di ordinamento sui numeri naturali, questo viene chiamato **assioma del buon ordinamento** infatti in un generico insieme S esiste un elemento minimo ovvero esiste un elemento s ∈ S tale che s ≤ t per ogni t ∈ S.

Ricordiamo:
- le proprietà fondamentali della somma sono Commutatività, Associatività e Elemento neutro
- le proprietà fondamentali del prodotto sono Commutatività, Associatività, Distributività, Elemento neutro e Elemento zero
- inoltre il calcolo avviene rispettando le priorità degli operatori

Peano introduce anche un altro concetto detto "***Principio di induzione***" che dice
- Se una proprietà $P$ è posseduta dal numero $0$ e la proprietà $P$ è posseduta anche dal successore di ogni numero naturale che possiede la proprietà P, allora la proprietà P è posseduta da tutti i numeri naturali.
![[Pasted image 20241026114516.png]]

[[Esempio principio di induzione.pdf]]

Sia x un numero reale, definiamo i 2 seguenti valori:
- "Floor": il più grande numero intero minore o uguale ad x
	- ![[Pasted image 20241026115046.png]]
- "Ceiling": il più piccolo numero intero maggiore o uguale ad x
	- ![[Pasted image 20241026115057.png]]
Esempi:
![[Pasted image 20241026115109.png]]

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
	- $a = 1$, $b = 10$:  $q = \frac{1}{10} = 0$ e $r = \frac{1}{10} \times 10 = 1$ quindi ==1 mod 10 = 1==
- Nel secondo caso assumiamo che il dividendo a sia negativo ma il divisore b positivo
	- Assumiamo allora che $a<0$ mentre $b>0$, chiameremo $q'$ e $r'$ i risultati del primo caso da cui otteniamo:
		- $a = (-q')b + (-r')$
		- $q = -q' - 1$ 
		- ***$r = b - r'$***
	- $a = -1$, $b = 10$: per $a = 1$ abbiamo $q' = 0$ e $r' = 1$ e quindi per a = -1 abbiamo $q' = -1$ e $r' = 10 - 1 = 9$ quindi ==-1 mod 10 = 9==
- Nel terzo caso assumiamo che il dividendo a sia positivo e il divisore b negativo
	- Assumiamo allora che $a > 0$  e $b < 0$, chiameremo $q'$ e $r'$ i risultati del primo caso da cui otteniamo:
		- $a = (-q')b + (-r')$
		- $q = -q'$ 
		- ***$r = r'$***
	- $a = 1$, $b = -10$: per $b = 10$ abbiamo $q' = 0$ e $r' = 1$ e quindi per b = -10 abbiamo $q' = 0$ e $r' = 1$ quindi ==1 mod -10 = 1==
- Nel quarto caso assumiamo che il dividendo a ed il divisore b siano entrambi negativi
	- Adesso assumiamo che $a < 0$ e $b < 0$, chiameremo $q'$ e $r'$ i risultati del primo caso da cui otteniamo:
		- $a = (q'+1)b -b -r'$
		- $q = -q'+1$ 
		- ***$r = -b -r'$***
	- $a = -1$, $b = -10$: per $a = 1$ e $b = 10$ abbiamo $q' = 0$ e $r' = 1$ e quindi per $a = -1$ e $b = -10$ abbiamo $q' = 1$ e $r' = 10 - 1 = 9$ quindi ==-1 mod -10 = 9== 

Riepilogando, dati due interi a, b ∈ Z con $\neq$  0, per trovare quoziente e resto r positivo della divisione a b agiamo così: 
- Troviamo il $q′$= $\frac{|a|}{|b|}$ ovvero il massimo intero $q′$ tale che $|a| − q|b| ≥ 0$ e fissiamo $r′ = |a| − q′|b|$. Se $a, b ≥ 0$ poniamo $q = q′$ e $r = r ′$. 
- Se $a < 0$ e $b > 0$ poniamo $q = −q′ − 1$ e $r = b − r ′$. 
- Se $a > 0$ e $b < 0$ poniamo $q = −q′$ e $r = r ′$. 
- Se $a < 0$ e $b < 0$ poniamo $q = q′ + 1$ e $r = −b − r ′$.

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
Esempio:
$n = 5$
$n^2 = 5^2 = 25$
$(5-1)^2 + 2(n-1) + 1 = 16 + 9 = 25$ 

---
###### Proprietà della divisibilità
- **Somma**: Se $a|b$ e $a|c$ allora $a | (b+c)$ 
- **Prodotto**: Se $a|b$ allora $a | bc$.
- **Transitività**: Se $a|b$ e $b|c$ allora $a|c$ 
![[Pasted image 20241101091611.png]]
- **Quadrato**: Se $a|b$ allora $a|b^2$ 
	- ***Dimostrazione***: Dato che $a|b$ esiste $x$ tale che $b = ax$, quindi $bc = axc$ questi dimostra che $a | b*b$ 
- **Combinazione lineare**: Se $a|b$ e $a|c$ allora $a | (hb + kc)$ per ogni $h,k \in Z$ 
	- **Dimostrazione**: Se $a | b$ allora $a | hb$, se $a | c$ allora $a | kc$ ovviamente valgono per ogni $h,k \in Z$ e quindi è vero che a | (hb + kc)
- **Proprietà del numero 0**: Ogni $a \in Z$ è divisore di 0
	- **Dimostrazione**: $a \in Z$ abbiamo che $a * 0 = 0$ quindi $a | 0$ 
- **Antisimmetrica**: Siano $a,b \in Z$ se $a | b$ e $b|a$ allora $|a| = |b|$ ossia $a = \pm b$  
	- Dalle ipotesi abbiamo che $b = ax$ e $a = by$. Quindi $a = axy$, raccogliendo a arriviamo ad $a(xy - 1)$ questo implica che $a$ sia $0$ oppure che $xy = 1$ da questo capiamo che:
		- Se $a = 0$ allora anche b = 0 (perché b = 0x)
		- Se $xy = 1$ allora a o b sono uguali a $\pm 1$ 
- **Divisori banali**: Siano a $\in$ Z allora $\pm a | a$  e $\pm 1 | a$ 
	- Avendo che $a=a⋅1$ oppure che $a=(−a)⋅(−1)$ possiamo affermare che $\pm a | a$ 
		- Seguendo la definizione capiamo che $a = b ⋅ k$ in questo caso $b = \pm a$ il k che soddisfa le nostre equazioni è k = 1
	- Avendo che $a = 1 * a$ possiamo dire che 1 è sempre un divisore di $a$
---
##### Minimo Comune Multiplo
Dati $a,b \in Z$ si chiama minimo comune multiplo fra a e b un terzo intero positivo m che è il più piccolo multiplo sia di $a$ che di $b$, quindi possiamo affermare che $a|m$ e $b|m$ 
###### Massimo Comune Divisore
Dati $a,b \in Z$ si chiama Massimo Comune Divisore un terzo intero $d \in Z$ tale che $d|a$ e $d|b$ cioè $d$ è il più grande divisore comune tra $a$ e $b$.

Il metodo migliore per calcolare il massimo comune divisore è l'algoritmo di euclide, che si basa su questa osservazione siano $a,b \in N$ e sia $b <= a$ (di seguito la dimostrazione per induzione):
- **Caso base** se b = 0 allora il $MCD(a,b) = a$ 
- **Passo induttivo**: visto che $a = qb + r$ con $0<r<b$ allora $MCD(a,b)$ = $MCD(b,r)$
Da questo notiamo che se $b|a$ allora $a = qb$ ($q$ sarebbe $\dfrac{a}{b}$) perché abbiamo resto 0 quindi la formula diventa $MCD(a,b)$ = $MCD(b,0)$ = $b$. In conclusione se $b|a$ otteniamo che $MCD(a,b) = b$  

Dimostriamo che $MCD(a,b)$ = $MCD(b,r)$ 
- Se $d$ è un divisore di $a$ e $b$ allora esistono $h$ e $k$ tali che $d$ sia un divisore di $r$ (la formula base per calcolare $r$ è $r = a - qb$ )
	- $a = hd$
	- $b = kd$ 
	- $r = hd - qkd = d(h - qk)$ (essendo che r può essere scritto come $d$ * un'intero allora è vero che $d$ è un divisore di $r$ [[#Definizione di divisibilità]]) 
- Se invece $d$ è un divisore di $b$ e di $r$ allora esistono $h$ e $k$ tali che $a$ è un divisore di $m$ (ricordiamo che la formula base per calcolare $a$ è $a = qb +r$):
	- $b = kd$
	- $r = hd$
	- $a = qkd + hd$ = $d(qk + h)$ (essendo che $a$ può essere scritto come d * un intero allora è vero che è un divisore di b [[#Definizione di divisibilità]])
Esempio
$x_1 = 330$ e $x_2 = 156$ 
$x_3 = 330\mod156 = 18$ 
$x_4 = 156\mod18=12$
$x_5 = 18 \mod 12 = 6$
$x_6 = 12 \mod 6 = 0$
Quindi $MCD(330, 156) = 6$. 
Da questo capiamo che il minimo comune divisore tra 2 numeri può essere calcolato trovando ripetutamente il modulo tra b ed il resto

Siano $a,b \in N$ allora esistono  $h, k \in Z$ tali che $MDC(a,b) = a * h + b*k$ 
Questo vuol dire che il MCD tra due numeri si può scrivere come una loro combinazione lineare
Esempio partendo dall'esempio precedente e andando a ritroso:
$6 = 18-12$
$= 18 - (156 - 8 * 18)$ 
$= -156 + 9 * 18$ 
$= -156 + 9 (330 - 2 * 156)$
$= -19 * 156 + 9 * 330$ 

---
###### Numeri primi e coprimi
Si definisce **numero primo** un intero che ha come divisori quelli banali ovvero 1 e se stesso. Due numeri $a,b \in Z$ si dicono **coprimi** se $MCD(a, b) = 1$ quindi esistono $h, k \in Z$ tali che (a · h + b · k) = 1

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
 
###### Teorema di euclide
I numeri primi sono infiniti.
Dimostrazione:
1. **Ipotesi di assurdo**: Supponiamo che ci sia un numero finito di numeri primi. Se così fosse, potremmo elencarli tutti. Chiamiamo questi numeri primi $p_1, p_2, \dots, p_n$, dove $p_1 = 2$, $p_2 = 3$, e così via fino a $p_n$, che rappresenterebbe l’ultimo numero primo.
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
- per n = 100 stimati $\frac{100}{\ln 100}\approx 22$ 
- per n = 1000 stimati $\frac{1000}{\ln 1000}\approx 145$ 

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

###### Criteri di divisibilità
Esistono delle regole molto semplici per verificare la divisibilità di un numero $a$ per un numero $b$ 
- **Divisibilità per 2**: un numero è divisibile per $2$ se è pari
	- 4 è divisibile per 2
- **Divisibilità per 3**: un numero è divisibile per $3$ se la somma delle sue cifre è un numero divisibile per $3$
	- 81 = 8 + 1 = 9 è divisibile per 3
- **Divisibilità per 5**: un numero è divisibile per $5$ se l''ultima cifra è $0$ o $5$
	- 105 è divisibile per 5
- **Divisibilità per 7**: un numero è divisibile per $7$ se $q - 2r$ è divisibile per $7$
	- $q =$ quoziente della divisione con 10
	- $r =$ resto della divisione con 10
	- $161: 16 - 2*1 = 14$ che è divisibile per 7  
- **Divisibilità per un generico n primo:** un numero è divisibile per $n$ se $q+xr$ è divisibile per $n$  
	- $q =$ quoziente della divisione con 10
	- $r =$ resto della divisione con 10
	- $x =$ resto della divisione di n con 10
	- Verifico la divisibilità per 13 del numero 130: 
		- $q =$  13
		- $r =$ 2
		- $x = 13 \mod 10 = 3$
		- $13 + 3*2$ = 19 non è divisibile per 130
- **Divisibilità per 11**:  un numero è divisibile per $11$ se $a - b$ è divisibile per 11
	- $a =$ somma dei numeri nelle posizioni dispari
	- $b =$ somma dei numeri nelle posizioni pari
		- 2805 quindi con
			- $a = 2+0$
			- $b = 8+5$
			- $a-b = -11$ che è divisibile per 11
- **Divisibilità per 9:** un numero $n$ è divisibile per $9$ se $n-m$ è divisibile per 9
	- $m$ è il numero delle sue cifre.
		- 333 è divisibile per 9 perché $m=9$ 