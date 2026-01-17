int x;
int y;
int r=30;
int dir=1;

void setup(){
  size (480,480);
  x=width/2;
  y=height/2;
  //radius da la dist dal centro
  ellipseMode(RADIUS);
}
void draw(){
  background(200);
  float d= dist(mouseX,mouseY, x,y);
  //se si rimpicciolisce troppo o tocca i bordi cambia il senso
  if (r==20 || r==width/2){
    dir=-dir;
  }
  //se vado dentro il cerchio col mouse il cerchio si allarga o restringe
  if (d<r){
    r+=dir;
    fill(0);
  }
  else{
    fill(255);
  }
  
  ellipse(x,y,r,r);
}