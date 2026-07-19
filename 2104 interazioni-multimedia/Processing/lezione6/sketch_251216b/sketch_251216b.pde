// Prendendo la nostra immagine 512x512, la dividiamo in 4 img da 256*256
// E mettiamo tipo piano cartesiano Originale, Negativo, Gamma, Logaritmo


//Questo è un esercizio standard, ci sarà quasi sicuramente una richiesta con img in 4 quadranti, o in riga
PImage Im, ImN, ImG,ImL;

void setup(){
  Im = loadImage("lena.png");
  Im.resize(256,256);
  //Im.filter(GRAY) // inserisce un filtro che prende solo i valori grigi
  size(512,512);
  image(Im,0,0);
  
  
  ImN = negative(Im);
  image(ImN,256,0);
  
  ImG = gamma(Im,2);
  image(ImG,0, 256);
  
  ImL = logaritmo(Im);
  image(ImL,256,256);
}  

void draw(){

}


PImage logaritmo(PImage I){
  PImage R = I.copy();
  float r,g,b;
  float C = 255/log(256);
  for(int i = 0; i<R.pixels.length; i++){
    r = C*log(1+red(R.pixels[i]));
    g = C*log(1+green(R.pixels[i]));
    b = C*log(1+blue(R.pixels[i]));
    R.pixels[i] = color(r,g,b);
  }
  return R;
}

PImage gamma(PImage I, float gm){
  PImage R = I.copy();
  R.loadPixels();
  float r,g,b;
  float C = 1/pow(255,gm-1);
  for(int i = 0; i<R.pixels.length; i++){
    r = C*pow(red(R.pixels[i]), gm);
    g = C*pow(green(R.pixels[i]), gm);
    b = C*pow(blue(R.pixels[i]), gm);
    R.pixels[i] = color(r,g,b);
  }
  R.updatePixels();
  return R;
}

PImage negative(PImage I){
  PImage R = I.copy();
  float r,g,b;
  R.loadPixels();
  for(int i = 0; i <R.pixels.length; i++){
    r = 255-red(R.pixels[i]);
    g = 255-green(R.pixels[i]);
    b = 255-blue(R.pixels[i]);
    R.pixels[i] = color(r,g,b);
  }
  R.updatePixels();
  return R;
}
