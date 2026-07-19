
PImage I;
PImage I3;
PImage ILap;
PImage ISh;

float n3=1/9.0, n5=1.0/25;
float[][] nbox3 = {{n3, n3, n3}, {n3, n3, n3}, {n3, n3, n3}};
float[][] lapl = {{-1, 0, -1}, {0, 4, 0}, {-1, 0, -1}};
float[][] sharp = {{-1, 0, -1}, {0, 5, 0}, {-1, 0, -1}};
void setup() {
  size(512*3, 512*3);
  I = loadImage("lena.png");
  I3 = convertiToImg(convoluzione(I,nbox3));
  ILap = convertiToImg(convoluzione(I,lapl));
  ISh = convertiToImg(convoluzione(I,sharp));
}

void draw() {
  image(I, 0, 0);
  image(I3, 512, 0);
  image(ILap, 512*2, 0);
  image(ISh, 0, 512);
}

//Facciamo la convoluzione di un img con un kernel
float [][] convoluzione(PImage I, float[][] K) {
  float[][] R = new float[I.height][I.width];
  int N = K[0].length;
  int M = K.length;
  for (int i = 0; i < I.width; i++) {
    for (int j = 0; j < I.height; j++) {
      float res = 0;
      for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
          int value = I.get(i-N/2+x, j-M/2+y);
          res = res + red(value)*K[x][y];
        }
      }
      R[i][j] = res;
    }
  }
  return R;
}

PImage convertiToImg(float[][] req) {
  PImage R = createImage(req[0].length, req.length, RGB);
  for (int i = 0; i < R.width; i++) {
    for (int j = 0; j < R.height; j++) {
      color c = color(constrain(req[i][j], 0, 255));
      R.set(i, j, c);
    }
  }

  return R;
}
