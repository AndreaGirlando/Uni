int lato = 50;


void setup(){
  size(500,500);
  noStroke();
  background(0,255,0);
  for(int y = 0; y < height; y += lato){
      for(int x = 0; x < height; x += lato){
        fill(random(255),130);
        rect(x+random(-5,5), y+random(-5,5),lato,lato);
      }
  }
}

void mousePressed(){
  setup();
}

void draw(){
  
}
