size(480, 480);
background(0);
noStroke();

/* CORNICE DI CERCHI SOPRA E A SX

int y=0;
int r=40;

for(int x=0; x<=width; x+=r){
  fill(125);
  ellipse(x, y, r, r);
}

int x=0;  //la variabile x precedentemente esisteva solo per il costrutto for e non per il resto del programma, quindi si ricrea

for(y=0; y<=height; y+=r){
  fill(125);
  ellipse(x, y, r, r);
}

*/


//FINESTRA RIEMPITA DI CERCHI

int r=40;
for (int y=0; y<=height; y+=r){
  for (int x=0; x<=width; x+=r){
    fill(125);
    ellipse(x, y, r, r);
  }
}