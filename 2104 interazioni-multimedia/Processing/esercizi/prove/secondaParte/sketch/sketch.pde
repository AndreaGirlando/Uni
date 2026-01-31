
PImage I;
PImage I1;
PImage IMediano;
PImage IMassimo;
PImage IMinimo;
void setup() {
  size(512*3, 512*3);
  I = loadImage("lena.png");
  I1 = loadImage("lena.png");
  I1.resize(256, 256);
  I1 = replication2x(I1);

  println(MSE(I, I1));
  println(PSNR(I, I1));
  IMediano = mediano(I, 5);
  IMassimo = massimo(I, 5);
  IMinimo = minimo(I,5);
}

PImage mediano(PImage I, int N) {
  PImage R = createImage(I.width, I.height, RGB);
  int off = N/2;
  for (int x = 0; x < I.width; x++) {
    for (int y = 0; y < I.height; y++) {
      //i due for sopra scorrono la nostra img
      float[] v = new float[N*N]; // creo un array di float 
      int count = 0;
      for(int i = -off; i <= off; i++){ 
        for(int j = -off; j <= off; j++){
          v[count++] = red(I.get(x+i, y+j));
        }
      }
      v = sort(v);
      R.set(x,y,color(v[v.length/2]));
    }
  }
  return R;
}

PImage massimo(PImage I, int N) {
  PImage R = createImage(I.width, I.height, RGB);
  int off = N/2;
  for (int x = 0; x < I.width; x++) {
    for (int y = 0; y < I.height; y++) {
      //i due for sopra scorrono la nostra img
      float[] v = new float[N*N]; // creo un array di float 
      int count = 0;
      for(int i = -off; i <= off; i++){ 
        for(int j = -off; j <= off; j++){
          v[count++] = red(I.get(x+i, y+j));
        }
      }
      R.set(x,y,color(max(v)));
    }
  }
  return R;
}

PImage minimo(PImage I, int N) {
  PImage R = createImage(I.width, I.height, RGB);
  int off = N/2;
  for (int x = 0; x < I.width; x++) {
    for (int y = 0; y < I.height; y++) {
      //i due for sopra scorrono la nostra img
      float[] v = new float[N*N]; // creo un array di float 
      int count = 0;
      for(int i = -off; i <= off; i++){ 
        for(int j = -off; j <= off; j++){
          v[count++] = red(I.get(x+i, y+j));
        }
      }
      R.set(x,y,color(min(v)));
    }
  }
  return R;
}

float PSNR(PImage I1, PImage I2) {
  return 10 * log(pow(255, 2)/MSE(I1, I2))/log(10);
}

PImage replication2x(PImage I) {
  PImage R = createImage(I.width*2, I.height*2, RGB);
  for (int i = 0; i < I.width; i++) {
    for (int j = 0; j < I.height; j++) {
      color c = I.get(i, j);
      R.set(2*i, 2*j, c);
      R.set(2*i+1, 2*j, c);
      R.set(2*i, 2*j+1, c);
      R.set(2*i+1, 2*j+1, c);
    }
  }

  return R;
}

float MSE(PImage I1, PImage I2) {
  I1.loadPixels();
  I2.loadPixels();
  int res = 0;
  for (int i = 0; i < I1.pixels.length; i++) {
    res += pow(red(I1.pixels[i])-red(I2.pixels[i]), 2);
  }
  return res/I1.pixels.length;
}

void draw() {
  image(I, 0, 0);
  image(I1, 512, 0);
  image(IMediano, 512*2, 0);
  image(IMassimo, 0, 512);
  image(IMinimo, 512, 512);
}
