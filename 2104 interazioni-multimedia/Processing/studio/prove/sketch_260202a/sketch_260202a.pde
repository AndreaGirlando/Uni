
PImage I;
PImage IBit;
PImage IConv;
float[][] filtro = {{-1, 0, -1}, {0, 5, 0}, {-1, 0, -1}};
void setup() {
  size(512, 512);
  background(0);
  I = loadImage("lena.png");
  I.resize(256, 256);
  IBit = bitplane(I, int(random(1, 7)));
  IConv = convertiToImg(convoluzione(I, filtro));
  println(MSE(I, IBit));
  println(PSNR(MSE(I, IBit)));
}

float[][] convoluzione(PImage I, float[][] k) {
  float[][] R = new float[I.width][I.height];

  int N = k.length;
  int M = k[0].length;

  for (int i = 0; i < I.width; i++) {
    for (int j = 0; j < I.height; j++) {
      float res = 0.0;
      for (int x = 0; x < N; x++) {
        for (int y = 0; y<M; y++) {
          int value = I.get(i-N/2+x, j-M/2+y);
          res += red(value)*k[x][y];
        }
      }
      R[i][j] = res;
    }
  }


  return R;
}

PImage convertiToImg(float[][] v) {
  PImage R = createImage(v[0].length, v.length, RGB);

  for (int i = 0; i<R.width; i++) {
    for (int j = 0; j< R.height; j++) {
      color c = color(constrain(v[i][j], 0, 255));
      R.set(i, j, c);
    }
  }

  return R;
}

PImage bitplane(PImage I, int nb) {
  PImage R = createImage(I.width, I.height, RGB);
  I.loadPixels();
  R.loadPixels();
  for (int i = 0; i < I.pixels.length; i++) {
    int value = (int(red(I.pixels[i])) >> nb)&1;
    R.pixels[i] = color(value*255);
  }
  R.updatePixels();
  return R;
}

float PSNR(float mse) {
  if (mse == 0) return 99; // Immagini identiche
  return 10 * log(pow(255, 2) / mse)/log(10);
}

float MSE(PImage I, PImage R) {

  R.loadPixels();
  I.loadPixels();
  float sum = 0.0;
  for (int i = 0; i < I.pixels.length; i++) {
    float val1 = red(I.pixels[i]);
    float val2 = red(R.pixels[i]);
    sum += pow(val1-val2, 2);
  }

  return sum/I.pixels.length;
}

void draw() {
  image(I, 0, 0);
  image(IBit, 256, 0);
  image(IConv, 0, 256);
}

void keyPressed() {
  if (key == 'r' || key == 'R') setup();
}
