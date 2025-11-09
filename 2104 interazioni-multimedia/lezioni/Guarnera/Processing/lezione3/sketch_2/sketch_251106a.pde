/*
// creazione di una canvas con i vari colori
void setup(){
   size(600,600);
   stroke(255,0,0);
   strokeWeight(10);
   background(255);
}  

void draw(){
  if(mousePressed){
    line(pmouseX,pmouseY,mouseX,mouseY);
  }
}

void keyPressed(){
  if((key == 'g') || (key == 'G')) stroke(0,255,0);
  if((key == 'b') || (key == 'B')) stroke(0,0,255);
  if((key == 'r') || (key == 'R')) stroke(255,0,0);
  if((key == 't') || (key == 'T')) stroke(random(0,255),random(0,255),random(0,255));
  
  if((key == 'p') || (key == 'p')) background(255);
}
*/
/*
//A COSA SERVE LA FUNZIONE LERP -> EFFETTO SCIA
float x,y;
void setup(){
  size(700,700);
  noStroke();
  //frameRate(6500);
}
void draw(){
  // background(0);
  // x = mouseX;
  // y = mouseY;
  fill(0,25);
  rect(0,0,width,height);
  x = lerp(x,mouseX, 0.1);
  y = lerp(y,mouseY, 0.1);
  fill(255);
  ellipse(x,y,60,60);
}
*/
/*
//USIAMO LA FUNZIONE LERP
size(700,700);
strokeWeight(5);
int x1 = 10;
int y1 = 10;
int x2 = 300;
int y2 = 300;
line(x1,y1,x2,y2);
for(int i = 1; i < 10; i++){
  strokeWeight(15);
  stroke(255,0,0);
  float perc = i/10.0;
  float x = lerp(x1,x2,perc);
  float y = lerp(y1,y2,perc);
  point(x,y);
}
*/
