float y = 0;
float x;
float speed = 2;
float gravity = 0.4;
float attrito = 0.10; // La velocità diminuisce del 10%

void setup(){
  size(800,500);
  x = width/2;
}

void draw(){
  background(255);
  fill(255,0,0);
  stroke(0,0,255);
  
  y+=speed;
  speed+=gravity; // la velocità aumenta perchè la pallina sta scedendo
  
  if(y>height-25){
    speed=speed*-(1-attrito);
  }
  
  ellipse(x,y,50,50);
  
}
