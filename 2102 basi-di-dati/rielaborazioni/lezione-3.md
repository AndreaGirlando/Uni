# Algebra relazionale

L'algebra relazionale è quella che ci permette di gestire i dati e si basa su degli operatori che:
- Sono definiti sulle relazioni
- Producono come risultato una relazione

Gli **operatori primitivi** sono:
- Ridenominazione
- Unione
- Differenza
- Proiezione
- Restrizione
- Prodotto

###### Ridenominazione
La ridenominazione è un operatore espresso dal simbolo $\delta_{name\rightarrow newName}$  che va a rinominare una colonna da $name$ a $newName$

> [!EXAMPLE]
> $\delta Matricola \leftarrow CodiceStudente (STUDENTE)$ 

###### Unione, differenza e intersezione
Dato che le relazioni sono degli insiemi (di ennuple) possiamo applicare gli operatori che di solito usiamo con gli insiemi, dati $R$ ed $S$ due relazioni dello stesso tipo allora abbiamo che:
- $R \cup S = \{t | t \in R \vee t \in S\}$
- $R - S = \{t | t \in R \wedge t \notin S\}$
- $R \cap S = \{t | t \in R \wedge t \in S\}$
![[Pasted image 20251003114505.png|500]]
![[Pasted image 20251003114518.png|500]]
![[Pasted image 20251003114533.png|500]]
###### Proiezione
La proiezione è un operatore che ci permette di selezionare solo specifici attributi della nostra tabella. Sia $R$ una relazione e siano $A_1, A_2, ... A_n$ alcuni suoi attributi allora una proiezione di $R$ sarebbe:
$$\pi_{A_1, A_2, ... A_n}(R) = \{t[A_1, A_2, ... A_n]t \in R\}$$
![[Pasted image 20251003115337.png|500]]
###### Selezione
La selezione è un operatore che produce un risultato con lo stesso schema dell'operando iniziale ma con un sottoinsieme di ennuple. Data $\lambda$ una formula proposizionale e dato $R$ una relazione allora la selezione di $R$ rispetto al formula $\lambda$ sarebbe:
$$\sigma_\lambda(R) = \{t|t\in R ∧ \lambda(t) = \text{TRUE}\}$$
 ![[Pasted image 20251003115657.png|500]]
###### Prodotto cartesiano
Date due relazione $R$ e $S$ con $R ∩ S = \text{insieme vuoto}$ l'operatore prodotto cartesiano ci permette di creare $$R \times S = \{tu| t \in R ∧ u \in S\}$$
![[Pasted image 20251003121235.png]]
###### JOIN
Questo operatore ci permette di combinare tuple da relazioni diverse basandosi sui valori degli attributi, ne abbiamo principalmente due tipi:
- **Natural JOIN**
  Sia $R$ con attributi $XY$ ed $S$ con attributi $YZ$ allora $R⋈S$ è una relazione $XYZ$ quindi: $$R⋈S = \{t|t[XY] \in R \text{ e } t[YZ] \in S\}$$
  cioè: le ennuple del risultato sono ottenute combinando le ennuple di $R$ e $S$ che hanno gli stessi valori negli attributi con lo stesso nome
  ![[Pasted image 20251003122038.png|500]]
- **Theta JOIN**
  viene specificato un predicato per la selezione delle ennuple, definito in questo modo: $$R⋈_F S = \sigma_F(R\times S)$$ quando la congiunzione $F$ è di uguaglianza allora si parla di **equi-JOIN**
  ![[Pasted image 20251004175818.png|500]]
  questa theta-join è anche una equi-join

###### Dimostrazione che equi-join è derivata
Siano $R(A_1:T_1, \dots, A_n:T_n)$ ed $S(A_{n+1}:T_{n+1}, \dots, A_{n+m}:T_{n+m})$ con $\{A_1,\dots,A_n\}∩\{A_{n+1}, \dots A_{n+m}\} = ∅$ 
Allora ponendo:
- $R \bowtie_{A_i = A_k} S = \{ tu \mid t \in R, u \in S, \; t.A_i = u.A_k \}$
- $\text{Con } 1 \leq i \leq n \; \text{e} \; n+1 \leq k \leq n+m.$
Arriviamo a capire che la equi-join è derivata perché $R \bowtie_{A_i = A_k} S = \sigma_{A_i = A_k}(R \times S)$ ovvero la equi-join è una theta join con una congiunzione di uguaglianza

###### Dimostrazione che natural-join è derivata
Siano $R$ con attributi $XY$ ed $S$ con attributi $YZ$, allora $R \bowtie S$ è una relazione di attributi $XYZ$ costituita da tutte le ennuple tali che: $t[XY]$ in $R$, $t[YZ]$ in $S$ ovvero che: $$R \bowtie S = \{t|t[XY] \in R \text{ \, e \, } t[YZ] \in S\}$$ Possiamo affermare che la congiunzione è derivata perché se rinominiamo gli attributi di $S$ come $Y'Z$ ottenendo $S'$ capiamo subito che usando una equi-join (con $Y = Y'$) e una proiezione rispetto $XYZ$ otteniamo la stessa cosa che facendo una natural join: $$R \bowtie S = \pi_{XYZ}(R\bowtie_{Y=Y'}S')$$
essendo la equi-join un operatore derivata allora anche la natural join lo è.


###### Dimostrazione che l'intersezione è derivata
Data due relazioni $R$ ed $S$ allora $$A\wedge R = R-(R-S)$$
###### Query
Una query è una funzione che da una istanza di una database (insiemi di relazioni) ci da una relazione come risultato