//fare tanti piccoli cerchietti nello schermo. ci vogliono 2 for. 
//size(800,400); non cambia nulla perché abbiamo creato il ciclo
size(480,120);
background(0);
fill(255);
stroke(120);
int r=5;
for (int y=20; y<=height-20;y+=20){
  for(int x=20; x<=width-20; x+=20){
   ellipse(x,y,r,r);
//mettere poi delle linee che convergano al centro (width/2, height/2)
   line(x,y,width/2,height/2);
  }
}