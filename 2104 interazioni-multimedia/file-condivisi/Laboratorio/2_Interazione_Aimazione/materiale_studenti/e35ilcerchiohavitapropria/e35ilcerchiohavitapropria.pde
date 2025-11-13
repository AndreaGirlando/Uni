//USIAMO RANDOM PER FAR MUOVERE UNA PALLINA
float vel=3;
int d=20;
float x;
float y;

void setup(){
  size(240,120);
  //la variabile inizializzata prima del setup se no non si vede. qui invece gli diamo un valore
  x=width/2;
  y=height/2;
}

void draw(){
  x=x+random(-vel,+vel);
  y=y+random(-vel,+vel);
  ellipse(x,y,d,d);
}
