
PImage I;
PImage Is;
PImage Ie;
void setup() {
  size(512*3, 512*2);
  I = loadImage("lena.png");
  I.filter(GRAY);
  Is = stretching(I);
  Ie = equalizzazione(I);
  
  visualizzaIstogrammi();
}

void visualizzaIstogrammi() {
  float[] H1 = istogramma(I);
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

float[] istogramma(PImage I){
  float[] H = new float[256];
  I.loadPixels();
  for(int i = 0; i < I.pixels.length; i++) H[int(red(I.pixels[i]))]++;
  for(int i = 0; i < 256; i++) H[i] /= I.pixels.length;
  return H;
}

PImage equalizzazione(PImage I) {
   PImage R = I.copy();
   float[] H = istogramma(I);
   for(int i = 1; i < 256; i++) H[i] = H[i] + H[i-1];
   R.loadPixels();
   for(int i = 0; i < R.pixels.length; i++){
     R.pixels[i] = color(255*H[int(red(R.pixels[i]))]);
   }
   return R;
}

PImage stretching(PImage I) {
  PImage R = I.copy();
  float min = 255;
  float max = 0;
  
  R.loadPixels();
  
  // Trova il vero minimo e massimo presenti nell'immagine
  for(int i = 0; i < R.pixels.length; i++){
    float v = red(R.pixels[i]);
    if(v > max) max = v;
    if(v < min) min = v;
  }
  
  // Formula: R = 255 * (Im - min) / (max - min)
  for(int i = 0; i < R.pixels.length; i++){
    float v = red(R.pixels[i]);
    R.pixels[i] = color(255 * (v - min) / (max - min));
  }
  
  R.updatePixels();
  return R;
}

void draw() {
  image(I, 0, 0);
  image(Is, 512, 0);
  image(Ie, 512*2, 0);
}
