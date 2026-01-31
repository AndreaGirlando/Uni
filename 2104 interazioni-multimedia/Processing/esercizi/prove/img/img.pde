
PImage I;
PImage I1;
PImage I2;
PImage I3;
PImage I4;
PImage I5;
color c = color(255, 255, 0);
int qK = 2;
int nbK = 5;
void setup() {
  I = loadImage("lena.png");
  size(512*3, 512*3);

  I1 = I.copy();
  I1.filter(GRAY);
  I3 = negative(I);
  I2 = gamma(I, 0.1);
  I4 = quantizza(I1, qK);
  I5 = bitplane(I1,nbK);

  //Modifico la prima lena
  for (int i = 0; i < I.width; i++) { // Coloriamo la diagonale principale di giallo
    I.pixels[pos(i, i, I.width)] = c; // si può fare anche I.set(i,i,c);
  }


}

PImage bitplane(PImage Img, int nb) {
  PImage R = Img.copy();
  R.loadPixels();
  for(int i  = 0; i < R.pixels.length; i++){
    int val = (int)red(R.pixels[i]);
    int bit = (val>>nb)&1; // shifto val di nb posizioni e prendo solo l'ultimo
    R.pixels[i] = color(bit*255);//*255 in modo che se è 1 lo vediamo nero
  }
  return R;
}

void mousePressed() {
  if(key == 'q'){
    qK = qK+1;
    I4 = quantizza(I1, qK);
  }
  if(key == 'b'){
    nbK = nbK+1;
    I5 = bitplane(I1, nbK);
  }
}

PImage quantizza(PImage Img, float k) {
  PImage R = Img.copy();
  R.loadPixels();
  for (int i = 0; i < R.pixels.length; i ++) {
    int q = floor((blue(R.pixels[i])*k)/256);
    q = int(float(q)/(k-1)*255);
    R.pixels[i] = color(q);
  }

  return R;
}

PImage gamma(PImage Img, float gamma) {
  PImage R = Img.copy();
  float r, g, b;
  float C = 1/pow(255, gamma-1);
  R.loadPixels();
  for (int i = 0; i < R.pixels.length; i++) {
    r = C*pow(red(R.pixels[i]), gamma);
    g = C*pow(green(R.pixels[i]), gamma);
    b = C*pow(blue(R.pixels[i]), gamma);
    R.pixels[i] = color(r, g, b);
  }

  return R;
}

PImage negative(PImage Img) {
  PImage R = Img.copy();
  float r, g, b;
  R.loadPixels();
  for (int i = 0; i <R.pixels.length; i++) {
    r = 255-red(R.pixels[i]);
    g = 255-green(R.pixels[i]);
    b = 255-blue(R.pixels[i]);
    R.pixels[i] = color(r, g, b);
  }
  R.updatePixels();
  return R;
}

int pos(int x, int y, int w) {
  return x+y*w;
}

void draw() {
  image(I, 0, 0);
  image(I1, 512, 0);
  image(I2, 512*2, 0);
  image(I3, 0, 512);
  image(I4, 512, 512);
  image(I5, 512*2, 512);
}
