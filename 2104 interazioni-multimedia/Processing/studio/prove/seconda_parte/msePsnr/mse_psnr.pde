PImage Im, Ic, Ir;

void setup() {
  size(1536, 512);
  Im = loadImage("lena.png");
  Im.filter(GRAY);
  
  Ic = Im.copy();
  Ic.resize(256, 256);
  Ic.resize(512, 512); // Bilineare di default
  
  Ir = Im.copy();
  Ir.resize(256, 256);
  Ir = replication2x(Ir);
  
  image(Im, 0, 0);
  image(Ic, 512, 0);
  image(Ir, 1024, 0);
  
  println("MSE Replication: " + MSE(Im, Ir));
  println("PSNR Replication: " + PSNR(Im, Ir));
}

PImage replication2x(PImage I) {
  PImage R = createImage(2*I.width, 2*I.height, RGB);
  for (int x=0; x<I.width; x++) {
    for (int y=0; y<I.height; y++) {
      color c = I.get(x, y);
      R.set(2*x, 2*y, c); R.set(2*x+1, 2*y, c);
      R.set(2*x, 2*y+1, c); R.set(2*x+1, 2*y+1, c);
    }
  }
  return R;
}

float MSE(PImage I1, PImage I2) {
  float res = 0;
  I1.loadPixels(); I2.loadPixels();
  for (int i=0; i<I1.pixels.length; i++) {
    res += pow(red(I1.pixels[i]) - red(I2.pixels[i]), 2);
  }
  return res / I1.pixels.length;
}

float PSNR(PImage I1, PImage I2) {
  return 10 * log(pow(255, 2) / MSE(I1, I2)) / log(10);
}
