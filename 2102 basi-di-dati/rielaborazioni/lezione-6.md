# Algoritmo di Query Optimization

###### Equivalenza delle espressioni
Due espressioni sono **equivalenti** se producono lo stesso risultato qualunque sia l'istanza attuale della base di dati, questo è un concetto molto importante nei dbms in quanto questi strumenti cercano di eseguire continuamente delle query equivalenti ma meno "costose", un esempio potrebbe essere la query detta **push selection** ovvero: $$\sigma_{A=10}(R_1 \bowtie R_2) = R_1 \bowtie \sigma_{A = 10}(R_2)$$ queste 2 sono due query equivalenti ma quella a sinistra è molto più efficiente
![[Pasted image 20251011210250.png|650]]
###### Regole per la query optimization
La regola generale per le ottimizzare le query è: **Anticipare l'applicazione delle proiezioni e delle restrizioni rispetto al prodotto in modo da ridurre la dimensione delle tabelle a cui applicare il prodotto**. Andando in specifico le regole da seguire sono queste:
1. Raggruppamento di restrizioni
	- $\sigma_{C(X)}(\sigma_{C(Y)}(E)) = \sigma_{C(X) \land C(Y)}(E)$
2. Commutatività di $\sigma$ e $\pi$ 
	- a. $\quad \sigma_{C(X)}(\pi_Y(E)) = \pi_Y(\sigma_{C(X)}(E)) \quad \text{se } X \subseteq Y$
	- b. $\quad \pi_Y(\sigma_{C(X)}(\pi_{X \cup Y}(E))) = \pi_Y(\sigma_{C(X)}(E)) \quad \text{se } X \not\subseteq Y$
3. Anticipazioni di $\sigma$ rispetto a $\times$ 
	- a.  $\sigma_{C(X)}(E \times F) = \sigma_{C(X)}(E) \times F \quad \text{se } X \subseteq attr(E)$
	- b.  $\sigma_{C(X) \land C(Y)}(E \times F) = \sigma_{C(X)}(E) \times \sigma_{C(Y)}(F) \quad \text{se } X \subseteq attr(E) \text{ e } Y \subseteq attr(F)$
	- c.  $\sigma_{C(X) \land C(Y) \land C(Z)}(E \times F) = \sigma_{C(Z)}(\sigma_{C(X)}(E) \times \sigma_{C(Y)}(F)) \quad$ 
	  $\text{se } X \subseteq attr(E), Y \subseteq attr(F), Z \subseteq attr(E) \cup attr(F)$
4. Raggruppamento di proiezioni 
	- $\pi_{X}(\pi_{Y}(E)) = \pi_{X}(E) \quad \text{se } X \subseteq Y$
5. Eliminazione di proiezioni superflue
	- $\pi_{X}(E) = E \quad \text{se } X = attr(E)$
6. Anticipazione della $\pi$ rispetto a $\times$
	- $\pi_{X \cup Y}(E \times F) = \pi_{X}(E) \times \pi_{Y}(F) \quad \text{se } X \subseteq attr(E) \text{ e } Y \subseteq attr(F)$ 
###### Algoritmo
Per anticipare la selezione applicare le seguenti regole:
- Si anticipa $\sigma$ rispetto a $\pi$ usando la **2.a**
- Si raggruppano le restrizioni usando la 1
- Si anticipa l'esecuzione di $\sigma$ su $\times$ usando la 3
- Si eliminano le proiezioni superflue usando la 5
- Si raggruppano le proiezioni mediante la regola 4
- Si anticipa l'esecuzione delle proiezioni rispetto al prodotto usando ripetutamente la regola 2
   