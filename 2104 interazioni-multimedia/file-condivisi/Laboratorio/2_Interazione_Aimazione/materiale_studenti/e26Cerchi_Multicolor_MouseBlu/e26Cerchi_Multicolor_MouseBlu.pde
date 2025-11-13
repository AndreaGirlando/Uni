int r=40;

void setup(){
  size(480, 480);
  background(0);
  noStroke();
  colorMode(RGB, width);
}

void draw(){
  for(int y=0; y<=height; y+=r){
    for (int x=0; x<=width; x+=r){
      if (dist(x,y,mouseX,mouseY)<r/2){
        fill(x,y,width);
      }
      else{
        fill(x, y, 0);
      }
      ellipse(x, y, r, r);
      
    }
  }
}
