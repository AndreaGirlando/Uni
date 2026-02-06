
int x = 0;
int y = 0;
int dir = 1;
float xK, yK;
void setup() {
  size(1000, 1000);
  y = height/2;
  background(0);
  println(y);
}

void draw() {
  background(0);
  stroke(0, 255, 0);
  fill(0, 0, 255);
  
  if(mousePressed){
    line(pmouseX,pmouseY,mouseX,mouseY);
  }

  //arc(100, 100, 100, 100, 0, 2*PI);
  //line(50,50,80,80);

  noFill();
  line(x,y,x,y-200);
  x = x+5*dir;
  if(x > width || x<0) dir = -dir;
}

void drawCuore() {
  //xy ancora1, xy controllo1, xy controllo2, xy ancora2
  stroke(255, 0, 0);
  strokeWeight(1);

  //xy ancora1, xy controllo1, xy controllo2, xy ancora2
  bezier(
    width/2, height/2+100,
    width/2-300, 200,
    width/2-150, height-100,
    width/2, height-100
    );

  bezier(
    width/2, height/2+100,
    width/2+300, 200,
    width/2+150, height-100,
    width/2, height-100
    );
}

void drawPoint(int x, int y) {
  stroke(0, 224, 216);
  strokeWeight(15);
  point(x, y);
  noStroke();
  strokeWeight(1);
}

void mousePressed(){
  drawPoint((int)random(500),(int)random(500));
  strokeWeight(1);
}

void keyPressed(){
  
  if(key == 'g'){
    fill(0,25);
    noStroke();
    rect(0,0,width,height);
    xK = lerp(xK,mouseX, 0.1);
    yK = lerp(yK,mouseY, 0.1);
    fill(255);
    ellipse(xK,yK, 50,50);
  }
}
