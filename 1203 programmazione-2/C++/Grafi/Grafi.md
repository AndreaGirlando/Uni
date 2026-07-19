Dentro il nostro programma abbiamo 3 classi principali:
- Graph
- Node $\to$ Nodi del grafo
- Edge $\to$ Archi del grafo
![[Pasted image 20250606115051.png]]

Di seguito ogni classe viene discussa:
- **Graph**: è la classe che contiene il puntatore all'array di Node e il numero di nodi, nel costruttore inizializza l'array, ha un metodo addEdge che richiama il  metodo addEdge su un nodo specifico
- **Node**:  questa classe contiene l'indirizzo alla testa della lista di adiacenza ha un metodo addEdge che aggiunge un nuovo Edge in testa alla lista di adiacenza. L'indice dove si trova uno specifico nodo è il nodo che rappresenta 
	- Richiamando addEdge nel Node in posizione 2 sto aggiungendo degli archi da 2 al target specificato
- **Edge**: è la classe che rappresenta il singolo arco, contiene il valore target (ovvero il numero alla quale questo arco punta) e il puntatore a next usato per mantenere la struttura della lista

Di solito quando si implementa un graph si aggiunge un nodo in più, questo perché la numerazione delle liste parte da 0, ma per convenzione la numerazione dei nodi di un grafo parte da 1, per far coincidere queste 2 cose si aggiunge un nodo inutilizzato.