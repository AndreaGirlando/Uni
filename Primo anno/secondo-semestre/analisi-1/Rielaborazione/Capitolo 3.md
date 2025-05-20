Questo è la rielaborazione del file [[AppuntiCap3.pdf]]

# Limiti e continuità delle funzioni reali di una variabile reale

Per una funzione reale si possono dare 9 definizioni di limite, precisamente studiare il limite di una funzione significa vedere qual è il comportamento della funzione stessa quando la variabile si avvicina ("tende") ad un certo punto. Le nove definizioni si differenziano l'una dall'altra solo per il diverso significato di "definitivamente".

### Definizioni di limite
###### Limite al tendere di x a c

> [!quote]
> **Punto di accumulazione**: un numero reale $c$ è detto punti di accumulazione per $X$ se, per ogni $r>0$ nell'intorno $]c-r,c++r[$ ci sono elementi diversi da $c$. L'insieme dei punti di accumulazione di accumulazione si denota con $D(X)$ 

Data una funzione reale definita in un insieme $X ⊆ R$, se $c \in D(x)$ si definisce il limite di $f$ al tendere di $x$ a $c$ nel seguente modo:
1. Si dice che $f$ **converge** al numero $l$ al tendere di $x$ a $c$ e si scrive: $$\lim_{x\to c}f(x) = l \in R$$ se $\forall \epsilon > 0$ $\exists δ > 0: x \in X, x \not=c,|x-c|<δ \Rightarrow |f(x)-l| < \epsilon$ ovvero $l-\epsilon < f(x) < l+\epsilon$  
   **Spiegazione intuitiva**: Dire che il limite di $f(x)$ per $x$ che tende a $c$ è $l$ significa che possiamo rendere $f(x)$ arbitrariamente vicino a $l$, scegliendo $x$ sufficientemente vicino a $c$ (ma senza che $x$ debba essere uguale a $c$). In altre parole, per ogni livello di precisione $\epsilon$ che vogliamo raggiungere, esiste un intervallo attorno a $c$ (di ampiezza $\delta$) tale che, se $x$ si trova all’interno di questo intervallo (escluso il punto $c$), allora $f(x)$ sarà compreso nell’intervallo $(l - \epsilon, l + \epsilon)$.
   
2. Si dice che $f$ **diverge** a $+\infty$ al tendere di $x$ a $c$ e si scrive $$lim_{x\to c} f(x) = +\infty$$ se $\forall k>0 \text{ } \exists δ>0 \text{ } x\in X, x\not=c, |x-c|<δ \Rightarrow f(x)>k$ 
   **Spiegazione intuitiva**: Dire che $f(x)$ tende a infinito quando $x$ si avvicina a $c$ significa che il valore di $f(x)$ può diventare arbitrariamente grande, cioè maggiore di qualunque soglia positiva. Per ogni $k > 0$, esiste un $\delta$ tale che, se $x \ne c$ e $|x - c| < \delta$, allora $f(x) > k$.

3. Si dice che $f$ **diverge** a $-\infty$ al tendere di $x$ a $c$ e si scrive $$lim_{x\to c} f(x) = -\infty$$ se $\forall k>0 \text{ } \exists δ>0 \text{ }: x\in X, x\not=c, |x-c|<δ \Rightarrow f(x)<-k$ 
   **Spiegazione intuitiva**: Quando $x$ si avvicina a $c$, il valore di $f(x)$ diventa arbitrariamente negativo, cioè più piccolo di qualunque soglia negativa (cioè inferiore a $-k$). Per ogni $k > 0$, esiste un $\delta$ tale che, se $x \ne c$ e $|x - c| < \delta$, allora $f(x) < -k$.
   
Come notiamo da queste definizione la condizione di limite deve essere verificata in un opportuno intorno di $c$, se questa cosa accade possiamo dire che la definizione di limite è verificata **definitivamente**. Se una delle tre condizioni descritte sopra è verificata allora la funzione è detta **regolare al tendere di x a c**, per questo tipo di limite abbiamo i seguenti teoremi:
- **Teorema dell'unicità del limite**: Se una funzione è regolare al tendere di $x$ a $c$ il suo limite è unico
- **Teorema della permanenza del segno**:
	- Se $\lim_{x\to c} f(x) = l>0$ esiste un intorno di $c$ in cui si ha $f(x)>0$  
	- Se $\lim_{x\to c} = l < 0$ esiste un intorno di $c$ in cui si ha $f(x)<0$	  
	generalizzando questo risultato, possiamo concludere che se $k>l(k<l)$ i valori della funzione saranno definitivamente minori (risp. maggiori) di $k$
- **Teorema di confronto per funzioni convergenti**: siano $f,g,h$ tre funzioni definite nello stesso insieme $X$ e sia $c \in D(x)$. Supponiamo che $f(x)\le g(x) \le h(x)$ per ogni $x \in X$ e che al tendere di $x$ a $c$ le due funzioni $f$ ed $h$ abbiano lo stesso limite $l$. Allora anche $g$ tende ad $l$ 