

PImage I;
PImage I1;
PImage I2;
void setup() {
  size(768, 256);
  I = loadImage("lena.png");
  I.resize(256, 256);
  I1 = sqr(I);
  I2 = colo(I);
}

PImage sqr(PImage I) {
  color c = color(255, 255, 0);
  PImage R = I.copy();
  R.loadPixels();
  int len = max(I.width, I.height);
  for (int i = len/2; i < len; i++) {
    for (int j = len/2; j < len; j++) {
      R.set(i, j, c);
    }
  }
  R.updatePixels();
  return R;
}

PImage colo(PImage I) {
  PImage R = I.copy();
  int len = max(I.width, I.height);
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      if(i>j){
        //Sopra la diagonale
        color c = R.get(i,j);
        float g = green(c);
        float b = blue(c);
        R.set(i,j,color(255,g,b));
      }
      else if(j>i){
        //Sotto la diagonale
        color c = R.get(i,j);
        float r = red(c);
        float g = green(c);
        R.set(i,j,color(r,g,255));
      }
    }
  }
  return R;
}

void draw() {
  image(I, 0, 0);
  image(I1, 256, 0);
  image(I2, 512, 0);
}
