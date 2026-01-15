int lato=50;
void setup(){
  size(500,500);
  background(0,255,0);
  noStroke();
  
  for(int y=0; y<height; y+=lato)
  {
    for(int x=0; x<width; x+=lato)
    {
      fill(random(255),130);
      rect(x+random(-5,5),y+random(-5,5),lato,lato);
    }
  }
}

void draw(){
  
}

void mousePressed(){
  setup();
}


/*int pos=0;
int vel= 3;
int dir=1;

void setup(){
  size(500,500);
}

void draw(){
  background(255);
  
  if(pos>width || pos<0)
    dir=-dir;
  //  pos=0;
  line(pos,20,pos, height-20);
  pos+=dir*vel;
}
*/


//bezièr
/*
void setup(){
  size(800,800);  noFill();textSize(40);
}

void draw(){
    background(125);
    text("A1",185,50);
    text("C1",mouseX,mouseY);
    text("C2",190,300);
    text("A2",15,300);
    stroke(255,0,0);
    line(185,50,mouseX,mouseY);
    line(15,300,190,300);
    stroke(0);
    bezier(185,50,mouseX,mouseY,190,300,15,300);
    
    
}
*/

//funzione arc
/*
void setup(){
  size(800,400);
  background(255);
  fill(255,255,0);
  //0-90
  arc(100,height/2,100,100,0,HALF_PI);
  //0-270
  arc(200,height/2,100,100,0,PI+HALF_PI);
  //errore
  arc(300,height/2,100,100,PI,0);
  //180-360
  arc(400,height/2,100,100,PI,TWO_PI);
  arc(500,height/2,100,100,PI,2*PI);
  //45-90
  arc(600,height/2,100,100,QUARTER_PI,HALF_PI);
  
  arc(700,height/2,100,100,radians(30),radians(330),PIE);//OPEN - CHORD

}

void draw(){}
*/

/*int diametro=50;
void setup(){  
size(500,500); background(#FFFF00); colorMode(RGB,width);
}

void draw(){
  for(int y=diametro/2; y<height; y+=diametro)
 {
    for(int x=diametro/2; x<width; x+=diametro)
    {
      if(dist(x,y,mouseX,mouseY)<diametro/2)
        fill(0,0,width);
      else
        fill(x,y,0);  
      ellipse(x,y,diametro,diametro);
    }
  }
}*/


//setup e draw
/*
void setup(){
  size(500,500);
  println("Sono nel setup");
  frameRate(10);
  background(0);
}

void draw(){
   //if(frameCount>150 && frameCount<200)
   if(millis()>3000 && millis()<4000)
   ellipse(width/2,height/2,50,50);
}
*/



//cerchi
/*
size(700,700);
background(255);
noFill();
int raggio=30;
int d=raggio*2;

for(int center=raggio; center<width; center+=raggio)
{
  if((d<width))
  ellipse(center, height/2,d,d);
  d+=raggio*2;
  println(d);
}
*/



//doppio ciclo for
/*
size(1000,500);
background(255,255,0);
int diametro=50;
ellipseMode(CORNER);
for(int y=0; y<height; y+=diametro)
{
  for(int x=0; x<width; x+=diametro)
  {
    ellipse(x,y,diametro,diametro);
  }
}
*/


// iterazione
/*
size(1000,500);
background(255);
int larghezza_freccia=150;
strokeWeight(25);
for(int x=50; x<width; x+=50)
{
  if((x+larghezza_freccia)<=width)
  {
    //stroke(x%256,(x+80)%256,(x+160)%256);
    stroke(x%256,x%256,x%256);
    line(x,0,x+larghezza_freccia,height/2);
    line(x,height,x+larghezza_freccia,height/2);
  }
}*/
