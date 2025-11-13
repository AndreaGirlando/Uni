//Proviamo le trasparenze
size(640,240); //impostiamo la dimensione della tela (canvas)
background(0); //colore di sfondo a 0, ovvero rgb(0,0,0) ovvero NERO
noStroke(); //pennello senza tratto, nessuna linea di contorno

// se non inseriamo il 4o valore, di default l'opacità sarà al 100%
fill(0,0,255);
rect(0,0,320,200);

// 255 significa 100% di opacità.
fill(255,0,0,255);
rect(0,0,640,40);

// 75% di opacità.
fill(255,0,0,191);
rect(0,50,640,40);

// 55% di opacità.
fill(255,0,0,127);
rect(0,100,640,40);

// 25% di opacità.
fill(255,0,0,63);
rect(0,150,640,40);
