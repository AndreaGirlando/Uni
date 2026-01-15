void setup(){
  size(500,500);
  noFill();
}
void draw(){
  background(255); 

  stroke(255,100,0);
  line(185,50,10,50);
  line(190,300,15,290);
  stroke(0);
  bezier(185,50,10,50,15,290,190,300);
  /*
  cambio l'ordine dei parametri nella funzione bezier.
  inverto per il segmento in alto il punto di ancoraggio
  e il punto di controllo...
  */
  stroke(255,100,0);
  line(385,50,210,50);
  line(390,300,215,290);
  stroke(0);
  bezier(210,50,385,50,215,290,390,300);
}
