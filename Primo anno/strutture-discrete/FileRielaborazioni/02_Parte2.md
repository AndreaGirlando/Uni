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
![[Pasted image 20241031092542.png]]
- **Quadrato**: Se $a|b$ allora $a|b^2$ 
	- ***Dimostrazione***: Dato che $a|b$ esiste $x$ tale che $b = ax$, quindi $bc = axc$ questi dimostra che $a | b*b$ 
- **Combinazione lineare**: Se $a|b$ e $a|c$ allora $a | (hb + kc)$ per ogni $h,k \in Z$ 
	- **Dimostrazione**: Se $a | b$ allora $a | hb$, se $a | c$ allora $a | kc$ ovviamente valgono per ogni $h,k \in Z$ e quindi è vero che a | (hb + kc)
- **Proprietà del numero 0**: Ogni $a \in Z$ è divisore di 0
	- **Dimostrazione**: $a \in Z$ abbiamo che $a * 0 = 0$ quindi $a | 0$ 
- **Antisimmetrica**: Siano $a,b \in Z$ se $a | b$ e $b|a$ allora $|b| = |b|$ ossia $a = \pm b$  
	- 