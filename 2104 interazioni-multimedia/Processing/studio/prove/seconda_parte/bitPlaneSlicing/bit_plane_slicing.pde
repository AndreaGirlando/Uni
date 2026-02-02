PImage Im, Ib;
int K = 7;

void setup() {
  size(1024, 512);
  Im = loadImage("lena.png");
  Im.filter(GRAY);
  aggiorna();
}

void aggiorna() {
  Ib = bitplane(Im, K);
  image(Im, 0, 0);
  image(Ib, 512, 0);
  fill(255, 0, 0);
  text("Piano Bit: " + K, 520, 20);
}

PImage bitplane(PImage I, int nb) {
  PImage R = I.copy();
  R.loadPixels();
  for (int i=0; i<R.pixels.length; i++) {
    int val = int(red(R.pixels[i]));
    int bit = (val >> nb) & 1;
    R.pixels[i] = color(bit * 255);
  }
  R.updatePixels();
  return R;
}

void keyPressed() {
  if (key == '+' && K < 7) K++;
  if (key == '-' && K > 0) K--;
  aggiorna();
}
