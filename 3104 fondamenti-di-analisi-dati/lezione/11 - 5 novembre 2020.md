Materiale di riferimento: 
- [[3104 fondamenti-di-analisi-dati/file-condivisi/sitoWeb/appunti/Modulo-1/10_extending_regression.pdf|10_extending_regression.pdf]]
- [[3104 fondamenti-di-analisi-dati/file-condivisi/sitoWeb/slide/Modulo-1/10_extending_regression.pdf|slide]]

*Interaction Terms*: un termine che media la relazione tra due parametri. Usiamo questo parametro nei modelli che chiamiamo *Interaction Model* 
![[11 - 5 novembre 2020-1.png]]
l'interaction model non è più considerabile un regressore lineare, aggiungere delle interpretazioni in questo senso spesso rende migliore il nostro modello. Di seguito il q-q plot
![[11 - 5 novembre 2020-2.png]]
Potremmo voler creare un modello non lineare, questa cosa la facciamo aggiungendo un termine al quadrato, come interpretiamo questo nuovo parametro? Che cosa indica?
$mpg = β_0 + β_1horsepower + β_2horsepower^2$
$\beta_{1}$ indica di quanto cambia horsepower all'aumentare di un unità di mpg, horsepower al quadrato cosa indica? aumentando anche a lui succederà qualcosa (*regressione quadratica*)

Dall'idea di aggiungere coefficenti di grado superiore nasce la *regressione polinomiale*. Il numero di gradi di una funzione indica i punti stazionari che questa può avere, teoricamente con un grado che va all'infinito riusciamo a rappresentare qualsiasi cosa, il problema è la varianza ad ogni minima condizione diversa del dataset la funzione cambia, quindi magari al campionamento successivo quel modello diventa inusabile (si fida troppo dei dati, si sta modellando in funzione dei dati di un campione della popolazione). L'obbiettivo è bilanciare il bias e la varianza 