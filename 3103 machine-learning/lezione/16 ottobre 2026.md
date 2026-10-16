Ingredienti del machine learning
- Task
- Algoritmo di learning
- misure di performance
- misure di valutazione 
- Dataset

In genere le reti neurali sono un'aggregazione di neuroni (negli umani sono collegate ai cinque sensi molte volte), sono dei semplici propagatori di segnale, il segnale che arriva ad un neurone viene propagato se necessario. I primi modelli di ML puntavano simulare il funzionamento di un neurone. 

Di seguito l'evoluzione dei vari usi del machine learning
1. Essendo la rete neurale un propagatore di segnale riusciamo a costruire dei modelli di ML che sono in grado di funzionare come porte logiche, la limitazione principale è che nell'esempio fatto l'unico parametro disponibile è da impostare manualemente.
2. Percettrone: abbiamo n dati in input, attraverso una specifica funzione a gradini riusciamo a calssificare gli input in due classi, infatti il suo output è 0 o 1, basato sulla seguente funzione $$ hw(x_{i}\dots x_{n}) = \\ 1 \text{ se } [ \Sigma_{i = 1}^n w_{i}x_{i}\ge w_{0}] \\ 0 \text{ altrimenti }$$ graficamente la linea che divide le due classi viene chiamata *decision boundary*, attraverso il training vengono aggiornati i pesi del modello
3. XOR NETWORK: stiamo traformando un input binario in un'altro input 


**Task di regressione**

*Single regression*: abbiamo: $f: R \to R$ (dato il metraggio di una casa ti do il suo valore)
*Multiple regression*: $f: R^n \to R$
*Multivariate regression*: $f_{w}: R^n \to R^m$

funzione di loss

**Discesa del gradiente**