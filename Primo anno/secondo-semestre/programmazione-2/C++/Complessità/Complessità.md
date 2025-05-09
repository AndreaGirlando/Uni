La complessità computazione serve per stabilire il **costo di un algoritmo** in termini di numero di operazioni fatte in RAM e dalla memoria occupata durante la sua esecuzione. Quando andiamo parliamo di costo computazionale prendiamo in esame 
- **il caso peggiore**: ovvero il costo massimo tra tutti i possibili input
- **il caso medio**: costo mediato tra tutte le istanze di input
è importante per definire un costo totale di un algoritmo definire il costo unitario di ogni singola operazione, in questo modo contando le operazioni si riesce a definire il costo totale, inoltre è necessario definire il comportamento dell'algoritmo in caso di dimensioni dell'input che tendono ad infinito e questo lo facciamo attraverso la notazione asintotica. Le notazioni principali sono:
- **Grande O**: denotiamo con O(g(n)) l'insieme delle funzioni
  $O(g(n)) = \{f(n:$ esistono delle constanti positive $c, n_0$ tale che $0 \le f(n) \le c \times g(n)$ per ogni $n > n_o$
  usando questa notazione facciamo riferimento ai casi peggiori ovvero ad un limite superiore per $f(n)$. Esistono diverse classe di equivalenza in cui i vari algoritmi in base alla loro complessità vengono raggruppate, le classi sono: 
	- **Costante**: 1
	- **Sotto-lineare**: $\log n, n^c$
	- **Lineare**: $n$
	- **Polinomiale**: $n \times \log n,n^2, ecc..$
	- **Esponenziale**: $c^n, \dots n^n,...$ (quello peggiore) 
- **Grande Beta**
- **Grande Theta**l