//Manda lui il file, mi sono esercitato a fare i disegnini
int angolo = 0;
int shifting = 0;
float dimensionDelta = 0;
void setup() {
  size(500, 500);
  background(255);
  frameRate(5);
}

void draw() {
  background(255);
  translate(width/2, height/2);
  rotate(radians(angolo));
  
  Face face1 = new Face(angolo, dimensionDelta);
  face1.drawFace();
  Face face2 = new Face(angolo, dimensionDelta+0.20);
  face2.drawFace();

  angolo+=10;
  shifting+=10;
  dimensionDelta=random(0,0.50);
}
