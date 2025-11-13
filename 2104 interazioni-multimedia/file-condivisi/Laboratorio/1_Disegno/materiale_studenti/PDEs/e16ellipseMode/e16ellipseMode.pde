size(480,120);

//cambio il modo di interpretare la funzione ellipse

//figura1
rect(50, 60, 80, 80);
ellipse(50, 60, 80, 80);

//figura2
ellipseMode(CORNER); //le coordinate non sono più del centro ma il vertice in alto 
                     //a sx del quadrato/rettangolo in cui la circonferenza è inscritta
rect(150, 20, 80, 80);
ellipse(150, 20, 80, 80);

//figura3
ellipseMode(CENTER); //ritorno all'interpretazione di default, con coordinate che indicano il centro dell'ellisse/cerchio, uguale alla figura 1
rect(290, 20, 80, 80);
ellipse(290, 20, 80, 80);

/*
con la funzione "ellipseMode(RADIUS)" le coordinate sono del centro,
ma cambiano il terzo e quarto argomento che non indicano più la lunghezza del diametro/corda del cerchio/ellisse ma la lunghezza del suo raggio
*/

//figura4 - differenza tra RADIUS (in nero) e CENTER (in bianco)
fill(0);
ellipseMode(RADIUS);
ellipse(430, 60, 40, 40);
fill(255);
ellipseMode(CENTER);
ellipse(430, 60, 40, 40);

/*
con la funzione "ellipseMode(CORNERS)" viene definito il rettangolo che inscrive il cerchio.
le coordinate sono del vertice in alto a sx e del vertice in basso a dx.
processing non disegna il rettangolo ma solo il cerchio inscritto.
*/

/*
le stesse funzioni CENTER, CORNER, CORNERS e RADIUS valgono per il rettangolo.
la differenza sta nella funzione di default, che per il cerchio è CENTER e per il rettangolo è CORNER
*/