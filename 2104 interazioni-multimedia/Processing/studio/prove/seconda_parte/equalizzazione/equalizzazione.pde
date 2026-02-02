PImage Im, Is, Ie;

void setup() {
  size(1536, 812);
  Im = loadImage("lena.png");
  if (Im == null) exit(); 
  Im.filter(GRAY);
  
  Is = stretching(Im);
  Ie = equalizza(Im);
  
  image(Im, 0, 0);
  image(Is, 512, 0);
  image(Ie, 1024, 0);
  
  visualizzaIstogrammi();
}

void visualizzaIstogrammi() {
  float[] H1 = istogramma(Im);
  float[] H2 = istogramma(Is);
  float[] H3 = istogramma(Ie);
  rectMode(CORNERS);
  noStroke();
  fill(255, 255, 0);
  for (int i=0; i<256; i++) {
    rect(i*2, height-(H1[i]*25600), i*2+2, height);
    rect(512+i*2, height-(H2[i]*25600), 512+i*2+2, height);
    rect(1024+i*2, height-(H3[i]*25600), 1024+i*2+2, height);
  }
}

PImage stretching(PImage I) {
  PImage R = I.copy();
  R.loadPixels();
  float max = 0, min = 255;
  for (int i=0; i<R.pixels.length; i++) {
    float v = red(R.pixels[i]);
    if (v < min) min = v;
    if (v > max) max = v;
  }
  for (int i=0; i<R.pixels.length; i++) {
    R.pixels[i] = color(255 * (red(R.pixels[i]) - min) / (max - min));
  }
  R.updatePixels();
  return R;
}

PImage equalizza(PImage I) {
  PImage R = I.copy();
  float[] H = istogramma(I);
  for (int i=1; i<256; i++) H[i] += H[i-1]; // Cumulativo
  R.loadPixels();
  for (int i=0; i<R.pixels.length; i++) {
    R.pixels[i] = color(255 * H[int(red(R.pixels[i]))]);
  }
  R.updatePixels();
  return R;
}

float[] istogramma(PImage I) {
  float[] H = new float[256];
  I.loadPixels();
  for (int i=0; i<I.pixels.length; i++) H[int(red(I.pixels[i]))]++;
  for (int i=0; i<256; i++) H[i] /= I.pixels.length;
  return H;
}
