Materiale di riferiemento:
- [[3104 fondamenti-di-analisi-dati/file-condivisi/sitoWeb/appunti/Modulo-1/09_logistic_regression.pdf|09_logistic_regression.pdf]]
- [[3104 fondamenti-di-analisi-dati/file-condivisi/sitoWeb/slide/Modulo-1/09_logistic_regression.pdf|slide]]


I vari tipi di regressione lineare hanno dei limiti, riusciamo a definire "solo" delle linee, ma se la nostra relazione non è lineare questa cosa non lo possiamo fare, in compenso sono molto veloci e compatti

in questa lezione usiamo il dataset sul cancro al seno, in questo caso il nostro risultato è binario (0 o 1)
![[10 - 3 novembre 2026-1.png]]
questa regressione intuitivamente non va bene, per riuscire a modellare il problema alla regressione lineare possiamo rendere il problema un problema di probilità, al posto di avere 0 o 1 ottengo un range di valori possibili tra $[0,1]$ se il valore va fuori questo range facciamo la seguente cosa: saturiamo a 0 per valori bassi e ad 1 per valori alti. Il valore risultante ci indica la probabilità che la diagnosi sia 1, in pratica creo una funzione di questo tipo:
![[10 - 3 novembre 2026-2.png]]
la funzione logistica che possiede esattamente le proprietà che ci interessano è il *sigmoide* ($f(x) = \frac{1}{1+e^{-x}}$)

Dato un evento binario gli *odds* di quel binario sono definiti in questo modo: $$Odds = \frac{P(event)}{1-P(event)}$$
definiamo il modello della regressione logistica in questo modo: 
![[10 - 3 novembre 2026-3.png]]
*Tanto yapping matematico e mi sono perso*

ha iniziato a fare laboratorio, sia quello a fine di questa leizone sia quello della scorsa volta