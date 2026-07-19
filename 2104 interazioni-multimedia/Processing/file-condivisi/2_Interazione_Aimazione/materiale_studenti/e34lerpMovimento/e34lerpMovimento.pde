float x;
float y;

void setup() {
  size(640, 360); 
  noStroke();  
}

void draw() { 
  background(0);
  
   
  x = lerp(x, mouseX, 0.05);
  y = lerp(y, mouseY, 0.05);
  
  fill(255);
  stroke(255);
  ellipse(x, y, 66, 66);
}
