
# Il problema dello zaino

La ricorsione è uno strumento naturale per affrontare problemi di ottimizzazione in cui una scelta locale induce problemi residui della stessa natura. Il **problema dello zaino** che consiste in:

*dato un insieme di oggetti, ciascuno con un valore e un peso, si vuole scegliere un sottoinsieme che massimizza il valore totale senza superare una capacità massima $K$*

in questa prospettiva il problema dello zaino diventa una sfida di equilibrio tra costo e beneficio: ogni decisione di includere un oggetto implica la rinuncia a un altro, quello che possiamo fare, a ogni passo due possibilità - prendere un oggetto oppure lasciarlo riducendo così il problema ad una versione più piccola di se stesso.


###### Versione 0.1: pesi unitari, valori diversi
In questo caso abbiamo oggetto tutti con lo stesso peso ma valori differenti, il suo zaino può contenere solo un numero limitato di pezzi, pari alla capacità $K$, inoltre gli oggetti sono già disposti in ordine crescente di valore, dal meno prezioso al più prezioso, questa rappresenta la forma più semplice di questo problema. Infatti la scelta ottimale e abbastanza logica consiste nel prendere i $K$ oggetti che hanno il valore più alto

**Formalizzazione**: 
- Abbiamo $n$ oggetti ordinati per valore crescente: $$v_1 \le v_2 \le \dots \le v_n$$ tutti di peso unitario. 
- Vogliamo massimizzare il valore complessivo: $$max\{\Sigma_{i \in S} v_i: S ⊆ \{1,\dots,n\}, |S| \le K\}$$ poiché i pesi sono unitari e i valori ordinati, la soluzione ottima è semplicemente: $$S^* = \{n-K+1, n-K+2, \dots, n\}, V^* = \Sigma_{i=n-K+1}v_i$$
- Il problema si risolve in maniera lineare in un tempo di esecuzione $O(K)$ 
 
