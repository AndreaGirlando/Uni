

PImage I;
PImage I1;
PImage I2;
void setup() {
  size(256*4, 256);
  I = loadImage("lena.png");
  I.resize(256, 256);
  I1 = rev(I);
  I2 = revCopy(I);
}

PImage revCopy(PImage I) {
  PImage R = createImage(I.width, I.height, RGB);
  R.copy(I,
    256, 0, //Coordinate di input
    I.width/2, I.height, // dimensione img di input
    0, 0, // Coordinate di destinazione
    I.width/2, I.height // dimensione img di destinazione
    );
  return R;
}

PImage rev(PImage I) {
  color c = color(random(0, 255), random(0, 255), random(0, 255));
  PImage R = createImage(I.width, I.height, RGB);
  R.loadPixels();
  int len = max(I.width, I.height);
  for (int i = len/2; i < len; i++) {
    for (int j = 0; j < len; j++) {
      R.set((i-len/2), j, I.get(i, j));
    }
  }
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      R.set((i+len/2), j, I.get(i, j));
    }
  }
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      if (i == j) R.set(i, j, c);
    }
  }
  R.updatePixels();
  return R;
}

void keyPressed() {
  if (key == 'r' || key == 'R') {
    setup();
  }
}

void draw() {
  image(I, 0, 0);
  image(I1, 256, 0);
  image(I2, 256*3, 0);
}
