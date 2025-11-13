//Esercizio - Scrivere uno sketch che permetta di disegnare con un pennello di forma rotonda.
//Dare la possibilità di cambiare colore con i tasti r-rosso g-verde b-blu e c-casuale

void setup()
{
  size(512,512);
  stroke(255,0,0);
  strokeWeight(10);
  //fill(255,0,0);
  background(255);
  
}

void draw()
{
  if(mousePressed)
  {
    line(pmouseX,pmouseY,mouseX,mouseY);
    //ellipse(mouseX,mouseY,20,20);
  }
}

void keyPressed()
{
  if((key=='g')||(key=='G'))
    stroke(0,255,0);
   
  if((key=='b')||(key=='B'))
    stroke(0,0,255);
 
  if((key=='r')||(key=='R'))
    stroke(255,0,0);
    
  if((key=='c')||(key=='C'))
    stroke(random(0,255),random(0,255),random(0,255));
}