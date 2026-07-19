PImage Im, Imax, Imin, Imed;

void setup() {
  size(1024, 1024);
  Im = loadImage("lena.png");
  Im.filter(GRAY);
  Imax = massimo(Im, 5);
  Imin = minimo(Im, 5);
  Imed = mediano(Im, 5);
  image(Im, 0, 0); image(Imax, 512, 0);
  image(Imin, 0, 512); image(Imed, 512, 512);
}

PImage mediano(PImage I, int N) {
  PImage R = createImage(I.width, I.height, RGB);
  int off = N/2;
  for (int x=0; x<I.width; x++) {
    for (int y=0; y<I.height; y++) {
      float[] v = new float[N*N];
      int count = 0;
      for (int i=-off; i<=off; i++) {
        for (int j=-off; j<=off; j++) {
          v[count++] = red(I.get(x+i, y+j));
        }
      }
      v = sort(v);
      R.set(x, y, color(v[v.length/2]));
    }
  }
  return R;
}

// Nota: massimo() e minimo() seguono la stessa logica cambiando solo il valore preso da v[]
PImage massimo(PImage I, int N) { /* ... simile a mediano, usa max(v) ... */ return I; }
PImage minimo(PImage I, int N) { /* ... simile a mediano, usa min(v) ... */ return I; }
