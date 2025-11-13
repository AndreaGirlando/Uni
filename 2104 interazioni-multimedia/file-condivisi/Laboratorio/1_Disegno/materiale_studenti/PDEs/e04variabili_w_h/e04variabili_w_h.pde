size (800,240);//dimensione della canvas
/*Uso le variabili che mi mette a disposizione Processing per 
conoscere lunghezza e altezza della finestra e disegnare le figure 
al centro senza fare calcoli.
Inoltre, cambiando i valori dati alla funzione size(), il disegno si
aggiorna mantenendo le proporzioni.*/
line(0,0,width,height);
line(width,0,0,height);
ellipse(width/2,height/2,20,20);