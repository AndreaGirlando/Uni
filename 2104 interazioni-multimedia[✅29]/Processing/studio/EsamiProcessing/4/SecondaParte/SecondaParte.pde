
PImage I;
void setup() {
  size(500, 500);
  I = wow(loadImage("lena.png"));
}

PImage wow(PImage I) {
  PImage R = I.copy();
  int terzo = I.width/3;
  //SRC - RECT SORGENTE - RECT DESTINAZIONE
  R.copy(I, terzo*2, 0, terzo, I.height, 0, 0, terzo, I.height);
  R.copy(I, 0, 0, terzo, I.height, terzo*2, 0, terzo, I.height);
  
  float f = int(random(0,2));
  
  for(int i = 0; i < terzo; i++){
    for(int j = 0; j < I.height; j++){
      int value = R.get(i,j);
      float r = red(value);
      float g = green(value);
      float b = blue(value);
      R.set(i,j,color(r/f,g,b));
    }
  }
  for(int i = terzo*2; i < I.width; i++){
    for(int j = 0; j < I.height; j++){
      int value = R.get(i,j);
      float r = red(value);
      float g = green(value);
      float b = blue(value);
      R.set(i,j,color(r*f,g,b));
    }
  }
  return R;
}

void keyPressed(){
  if(key == 'r' || key == 'R') setup();
}

void draw() {
  image(I, 0, 0);
}
