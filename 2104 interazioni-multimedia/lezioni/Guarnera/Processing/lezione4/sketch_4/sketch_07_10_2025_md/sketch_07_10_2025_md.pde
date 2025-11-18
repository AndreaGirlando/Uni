
void setup(){
  size(500,500);
}
void draw(){
  background(0);
  translate(width/2, height/2);
  
  // Disegniamo una pallina con un linea rossa dentro
  fill(255);
  noStroke();
  rotate(millis()*0.001*TWO_PI/10); // routa la canvas una volta ogni 10 secondi rispetto al primo translate
  translate(80,0); // cambio il sistema di riferimento shiftando 80 pixel verso destra
  rotate(millis()*0.001*TWO_PI); // routa la canvas una volta al secondo rispetto al secondo translate
  ellipse(0,0,40,40);
  strokeWeight(5);
  stroke(255,0,0);
  line(0,0,20,0);
  
  
}

/*
// Rotate e translate
int a = 0;
void setup(){
  size(500, 500);
}

void draw(){
  background(0);
  translate(width/2, height/2); // cambia il sistema di riferimento il nuovo punto 0,0 -> 250,250
  rotate(radians(a));//routa la canvas rispetto al punto 0,0
  //rect(width/2, height/2 ,50, 50); // ruota rispetto al centro nel caso senza il translate
  fill(255);
  rect(-25, -25 ,50, 50);
  fill(255,0,0);
  rect(60, -25 ,50, 50);
  a++;
}
*/
