//SCALE

/*
float scale=0.2;
float dir_scale=1;
void setup(){
  background(255);
  fill(0,255,0);
  stroke(255,0,0);
  strokeWeight(5);
  rectMode(CENTER);
  size(500,500);
  frameRate(10);
}

void draw(){
  background(255);
  translate(width/2,height/2);
  scale(scale);
  rect(0,0,width,height);
  scale+=dir_scale*0.1;
  
  if(scale>=1 || scale<=0)
  dir_scale=-dir_scale;
  
}
*/


//SHEAR

/*
float shX=0.1;
float shY=0.1;
void setup(){
  background(255);
  fill(0,255,0);
  stroke(255,0,0);
  strokeWeight(5);
  rectMode(CENTER);
  size(500,500);
  frameRate(10);
}

void draw(){
  background(255);
  translate(width/2,height/2);
  shearX(shX);
  shearY(shY);
  rect(0,0,150,150);
  
  shX+=0.1;
  shY+=0.1;
  //println(shX);
}
*/





//PALLINA EFFETTO SCOMPARSA

/*float rotAngle=10;


void setup(){ size(600,600);frameRate(10);}
void draw(){
  
  fill(255,50);
  rect(0,0,width,height);
  
  translate(width/2,height/2);
  rotate(radians(rotAngle));
  noStroke();
  fill(255,0,0);
  ellipse(250,0,20,20);
  rotAngle+=20;
}
*/





//QUADRATI A ROTAZIONE INDIPENDENTE

/*int a1=0;
int a2=0;

void setup(){
  size(500,500);
  rectMode(CENTER);
}

void draw(){
  
  background(0);
  pushMatrix();
  translate(width/2,height/2);
  rotate(radians(a1));
  fill(255);
  rect(0,0,50,50);
  popMatrix();
  
  pushMatrix();
  translate(width/2+80, height/2);
  rotate(radians(a2));
  fill(255,0,0);
  rect(0,0,50,50);
  popMatrix();
  
  a1++;
  a2+=4;

}*/
