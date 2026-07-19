
//ROTOTRALAZIONE
/*void setup(){size(500,500);}
void draw(){
  background(0);
  translate(width/2,height/2);
  fill(255);
  noStroke();
  rotate(millis()*0.001*TWO_PI/10);
  translate(80,0);
  rotate(millis()*0.001*TWO_PI);
  ellipse(0,0,40,40);
  strokeWeight(5);
  stroke(255,0,0);
  line(0,0,20,0);
}
*/


//ROTATE / TRANSLATE
/*int a=0;
void setup(){
  size(500,500);
}

void draw(){
  background(0);
  translate(width/2,height/2);
  rotate(radians(a));
  fill(255);
  rect(-25,-25,50,50);
  fill(2550,0,0);
  rect(60,-25,50,50);
  a++;
}
*/


// Forza gravitazionale
/*float y=0;
float x;
float speed=2;
float gravity=0.4;
float attrito=0.05;

void setup(){
  size(800,500);
  x=width/2;
}
void draw(){
  background(255);
  fill(255,0,0);
  stroke(0,0,255);
  y+=speed;
  speed=speed+gravity;
  
  if(y>height-25)
  {
    speed=speed*-(1-attrito);
  }
  
  ellipse(x,y,50,50);
}
*/




// GESTIONE TESTO
/*
PFont f;
String typing="";
String saved="";
int indent=25;

void setup(){ 
  size(500,300); 
  f= createFont("Calibri",16);
  textFont(f);
  fill(0);
}

void draw(){
  background(255);
  text("CLicca sulla canvas e scrivi; \nInvio per salvare",indent, 40);
  text("Input:"+typing, indent, 190);
  text("Testo salvato:"+saved,indent,230);
}

void keyPressed(){
  if(key=='\n')
  {
    saved=typing;
    typing="";
  }
  else if(key==BACKSPACE && typing.length()>0)
  {
    typing=typing.substring(0,typing.length()-1);
  }
  else
  {
    typing=typing+key;
  }
  
}

*/


/*void setup(){
  size(120,120);
  textAlign(CENTER);
  textSize(60);
}
void draw(){
  background(0);
  text(key,60,60);
}*/




/*
size(1000,500);
fill(0,100,150);
textSize(50);
String x="Stringa più lunga di una semplice parola";
text(x,10,40,100,220);
textSize(70);
text("hello world",10,70);
fill(0,100,150);
text("word",10,140);
fill(0,100,150,50);
text("hello world",10,210);
PFont c,a,f;
a=createFont("Arial",50);
c=createFont("Times New Roman",120);
f=loadFont("Freestyler-48.vlw");
textFont(a);
text("Font Arial",10,70);
textFont(c);
text("Font Times Nee ROman",10,180);
textFont(f);
text("FONT IMPORTATO",10,300);*/



//RUMORE
/*
void setup(){ size(500,400);}
void draw()
{
  background(200);
  for(int x=40; x<width; x+=40)
  {
    //float rum=mouseX/10;
    println(mouseX);
    float rum=map(mouseX,0,width,0,width/10);
    float rumi=random(-rum,rum);
    float rumf=random(-rum,rum);
    line(x+rumi,100,x+rumf, height-100);
  }
}
*/



//Esercizio PUPULLA
/*
int raggio=50;
float lato=raggio*sqrt(2);
float move=lato/2;

void setup(){ size(500,500); ellipseMode(RADIUS); println(lato);}
void draw(){
  background(100);
  fill(255);
  ellipse(width/2,height/2,raggio,raggio);
  float x=map(mouseX,0,width,-move,move);
  float y=map(mouseY,0,height,-move,move);
  fill(0);
  ellipse(x+width/2,y+height/2,5,5);
  
}
*/



// MAP X e Y
/*
void setup(){ size(700,700);}
void draw(){
  float x=map(mouseX,0,width,250,450);
  float y=map(mouseY,0,height,250,450);
  ellipse(x,y,40,40);
}*/



//SLIDER MAP RAGGIO
/*
void setup(){
  size(700,700);
  background(100);
}
void draw(){
  background(0);
  float r=map(mouseX,0,width,20,255);
  fill(255,r,0);
  ellipse(width/2,height/2,r,r);
  println(mouseX);
  println(r);
  println("----------------");
}
*/


//cerchio crescente/decrescente
/*
int x; int y; int r=30; int dir=1;

void setup(){
  size(500,500);
  x=width/2;
  y=height/2;
  ellipseMode(RADIUS);
}
void draw(){
  background(200);
  float d=dist(mouseX,mouseY,x,y);
  
  if(r==20 || r==width/2)
  dir=-dir;
  
  
  if(d<r)
  {
    r+=dir;
    fill(0);
  }
  else
  {
    fill(255);
  }
  ellipse(x,y,r,r);
}*/
