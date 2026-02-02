
PImage I;
PImage I1;
void setup(){
  size(512,256);
  I = loadImage("lena.png");
  I.resize(256,256);
  I1 = wow(I);
}

PImage wow(PImage I){
  PImage R = createImage(I.width, I.height, RGB);
  R.copy(I,I.width/2,0,I.width/2,I.height,0,0,I.width/2,I.height);
  R.copy(I,I.width/2,0,I.width/2,I.height,I.width/2,0,I.width/2,I.height);
  
  float parteAlta = R.pixels.length*random(0,1);
  R.loadPixels();
  for(int i = 0; i < R.pixels.length; i++){
    if(i < parteAlta){
      int value = R.pixels[i];
      float r = 255-red(value);
      float g = 255-green(value);
      float b = 255-blue(value);
      R.pixels[i] = color(r,g,b);
    }
    if(i > parteAlta){
      int value = R.pixels[i];
      float r = 255-red(value);
      float g = 255-green(value);
      float b = 0;
      R.pixels[i] = color(r,g,b);
    }
  }
  
  
  return R;
}

void keyPressed(){
  if(key == 'r' || key == 'R') setup();
}

void draw(){
  image(I,0,0);
  image(I1,256,0);
}
