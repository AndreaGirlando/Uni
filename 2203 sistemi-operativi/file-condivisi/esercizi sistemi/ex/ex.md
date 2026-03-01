# 1

## **domanda**
un sistema che fa uso di uno spazio di indirizzamento ad 1GB, con un numero di pagina a 22 bit ed un indirizzo fisico a 20 bit.
Calcolare quanti frame fisici ci sono in memoria.

## **soluzione**:
$$
1GB=2^{30}=\text{spazio di indirizzamento}
$$
$$
2^{22}=\text{numero di pagina}
$$

trovo la dimensione di ogni pagina:
$$
\frac{2^{30}}{2^{22}}=2^8
$$

trovo il numero di frame fisici per ogni pagina:
$$
\frac{2^{22}}{2^8}=2^{12}
$$

