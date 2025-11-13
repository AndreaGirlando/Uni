
void setup(){
  size(300,300);
  frameRate(30);
}
//INIZIALIZZARE VARIABILE FUORI COSì è AL PARI PER SETUP E DRAW
int pos=0;
int pos2=0;
void draw(){ 
  //PER SPOSTARE LINEA DI VOLTA IN VOLTA AGGIORNIAMO LO SFONDO
  background(200);
  line(pos,20,pos2,height);
   
 
  pos++;
  pos2+=3;
}
