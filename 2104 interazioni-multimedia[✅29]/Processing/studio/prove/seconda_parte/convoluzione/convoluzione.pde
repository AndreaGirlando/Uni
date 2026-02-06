PImage Im, In3, In5, Il, Is, IsX;
float n3=1/9.0, n5=1.0/25;
float[][] nbox3 = {{n3,n3,n3},{n3,n3,n3},{n3,n3,n3}};
float[][] lapl = {{-1,0,-1},{0,4,0},{-1,0,-1}};
float[][] sharp = {{-1,0,-1},{0,5,0},{-1,0,-1}};

void setup() {
  size(1536, 1024);
  Im = loadImage("lena.png");
  Im.filter(GRAY);
  In3 = converti(convoluzione(Im, nbox3));
  Il = converti(convoluzione(Im, lapl));
  Is = converti(convoluzione(Im, sharp));
  
  image(Im, 0, 0);
  image(In3, 512, 0);
  image(Il, 0, 512);
  image(Is, 512, 512);
}

float[][] convoluzione(PImage I, float[][] K) {
  float[][] R = new float[I.height][I.width];
  int N = K[0].length;
  int M = K.length;
  for (int x=0; x<I.width; x++) {
    for (int y=0; y<I.height; y++) {
      float res = 0;
      for (int p=0; p<N; p++) {
        for (int q=0; q<M; q++) {
          res += red(I.get(x-N/2+p, y-M/2+q)) * K[q][p];
        }
      }
      R[y][x] = res;
    }
  }
  return R;
}

PImage converti(float[][] F) {
  PImage R = createImage(F[0].length, F.length, RGB);
  for (int x=0; x<R.width; x++) {
    for (int y=0; y<R.height; y++) {
      R.set(x, y, color(constrain(F[y][x], 0, 255)));
    }
  }
  return R;
}
