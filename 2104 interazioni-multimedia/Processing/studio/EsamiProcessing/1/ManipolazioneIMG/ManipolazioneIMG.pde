
PImage I;
PImage I1;
PImage I2;
PImage I3;
PImage I4;
void setup() {
  size(768, 512);
  I = loadImage("lena.png");
  I.filter(GRAY);
  I.resize(256, 256);
  I1 = wow(I);
  I2 = mas(I1, int(random(5, 15)));
  I3 = mini(I, int(random(5, 15)));
  I4 = mediano(I, int(random(5, 15)));
}


void draw() {
  image(I, 0, 0);
  image(I1, 256, 0);
  image(I2, 512, 0);
  image(I3, 0, 256);
  image(I4, 256, 256);
}

PImage mediano(PImage I, int N) {
  PImage R = createImage(I.width, I.height, RGB);
  int offset = N/2;

  float[] v = new float[N*N];

  for (int i = 0; i < I.width; i++) {
    for (int j = 0; j < I.height; j++) {
      int count = 0;
      for (int x = -offset; x < offset; x++) {
        for (int y = -offset; y < offset; y++) {
          v[count] = I.get(i+x, y+j);
          count++;
        }
      }
      sort(v);
      R.set(i, j, int(v[(v.length/2)-1]));
    }
  }
  return R;
}

PImage mini(PImage I, int N) {
  PImage R = createImage(I.width, I.height, RGB);
  int offset = N/2;

  float[] v = new float[N*N];

  for (int i = 0; i < I.width; i++) {
    for (int j = 0; j < I.height; j++) {
      int count = 0;
      for (int x = -offset; x < offset; x++) {
        for (int y = -offset; y < offset; y++) {
          v[count] = I.get(i+x, y+j);
          count++;
        }
      }
      R.set(i, j, int(min(v)));
    }
  }
  return R;
}

PImage wow(PImage I) {
  PImage R = createImage(I.width, I.height, RGB);
  I.loadPixels();
  R.loadPixels();
  int len = I.pixels.length;
  for (int i = len/2; i < len; i++) {
    R.pixels[i-(len/2)] = I.pixels[i];
  }
  for (int i = 0; i < len/2; i++) {
    R.pixels[(len/2)+i] = I.pixels[i];
  }
  R.updatePixels();
  return R;
}

PImage mas(PImage I, int N) {
  if (N%2 == 0) N++;
  PImage R = createImage(I.width, I.height, RGB);
  int offset = N/2;
  for (int i = 0; i < I.width; i++) {
    for (int j = 0; j < I.height; j++) {
      float[] v = new float[N*N];
      int count = 0;
      for (int q = -offset; q < offset; q++) {
        for (int p = -offset; p < offset; p++) {
          v[count] = red(I.get(i+q, j+p));
          count++;
        }
      }
      R.set(i, j, color(max(v)));
    }
  }

  return R;
}





void keyPressed() {
  if (key == 'r' || key == 'R') {
    setup();
  }
}
