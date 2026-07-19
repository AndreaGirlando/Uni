/*
int diametro = 50;
void setup(){
  size(500,500);
  background(#FFFF00);
  frameRate(60);
  colorMode(RGB , width); 
}

void draw(){
  for(int y = diametro/2; y<height; y+=diametro){
    for(int x = diametro/2; x<width; x+=diametro){
      if(dist(x,y,mouseX, mouseY)<diametro/2){
        fill(0,0,255);
      }else{
        fill(x,y,0);
      }
      ellipse(x,y,diametro,diametro);
    }
  }
}
*/
