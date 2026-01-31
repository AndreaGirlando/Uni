
void setup(){
  size(700,700);
}
void draw(){
  fill(255,25);
  rect(0,0,width,height);
  
  pushMatrix(); //Inizio blocco 1
  translate(width/2, height/2);
  fill(255,0,0);
  ellipse(0,0, 15, 15);
  rotate(random(255));
  drawRainbowRect();
  popMatrix(); //Fine blocco 1
  
  pushMatrix();//Inizio blocco 2
  translate(width/2+200,height/2+200);
  rotate(millis()*0.001*PI);
  ellipse(0,50,15,15);
  popMatrix(); //Fine blocco 2
}

void drawRainbowRect(){
  fill(random(255),random(255), random(255));
  rect(0,100,50,50);
  fill(0);
}
