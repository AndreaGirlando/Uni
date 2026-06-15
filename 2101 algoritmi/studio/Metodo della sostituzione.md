

# Guida
Come vuoi tu arrivi alla soluzione di seguito: 
$$
T(n)=\Theta(n)
$$

per poi verificarla formalmente come di seguito
# Verifica formale con sostituzione

## Limite superiore

Ipotesi:

$$
T(n/2)\le c\frac n2
$$

Sostituisco:

$$
T(n)=T(n/2)+n
$$

$$
T(n)\le c\frac n2+n
$$

Voglio dimostrare:

$$
c\frac n2+n\le cn
$$

Divido per $n$:

$$
\frac c2+1\le c
$$

Da cui:

$$
c\ge 2
$$

Quindi:

$$
T(n)=O(n)
$$

---

## Limite inferiore

Ipotesi:

$$
T(n/2)\ge c\frac n2
$$

Sostituisco:

$$
T(n)\ge c\frac n2+n
$$

Voglio dimostrare:

$$
c\frac n2+n\ge cn
$$

Dividendo per $n$:

$$
\frac c2+1\ge c
$$

Da cui:

$$
c\le 2
$$

Quindi:

$$
T(n)=\Omega(n)
$$

---

## Conclusione

Se:

$$
T(n)=O(g(n))
$$

e

$$
T(n)=\Omega(g(n))
$$

allora:

$$
T(n)=\Theta(g(n))
$$

---

# Schema rapido per l'esame

1. Scrivo la ricorrenza.
2. Espando 2-3 volte.
3. Individuo il pattern.
4. Trovo $k$ risolvendo:

$$
\frac{n}{b^k}=1
$$

5. Sostituisco $k$.
6. Ottengo una soluzione candidata.
7. Scrivo l'ipotesi per $O$.
8. Verifico la disuguaglianza.
9. Scrivo l'ipotesi per $\Omega$.
10. Verifico la disuguaglianza.
11. Concludo con $\Theta$.

---

# Risultati da ricordare

$$
T(n)=T(n/2)+1
\Rightarrow
\Theta(\log n)
$$

$$
T(n)=T(n/2)+\log n
\Rightarrow
\Theta(\log^2 n)
$$

$$
T(n)=T(n/2)+n
\Rightarrow
\Theta(n)
$$

$$
T(n)=2T(n/2)+n
\Rightarrow
\Theta(n\log n)
$$

$$
T(n)=4T(n/2)+n
\Rightarrow
\Theta(n^2)
$$