// La quantizzazione
PImage Im, Iq;
int K;
void setup() {
  K = 2;
  Im = loadImage("lena.png");
  Im.filter(GRAY);
  size(1024, 512);
  image(Im, 0, 0);
  
  Iq = quantizza(Im, K);
  image(Iq, 512, 0);
}

PImage quantizza(PImage I, int k) {
  PImage R = I.copy();
  R.loadPixels();
  println(R.pixels);
  int q;
  for (int i = 0; i < R.pixels.length; i++) {
    q = floor(blue(R.pixels[i])*k/256);
    q = int(float(q)/(k-1)*255);
    R.pixels[i] = color(q);
  }
  R.updatePixels();
  return R;
}

void keyPressed() {
  if(key == '+') K++;
  if(key == '-') K--;
  
  Iq = quantizza(Im, K);
  image(Iq, 512, 0);
}

void draw() {
}
