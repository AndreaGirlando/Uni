
PImage I;
float r,g,b;
color c;
//Quando posso usare un singolo for per implementare il mio algoritmo uso la matrice linearizzata sennò la matrice normale
void setup(){
  I = createImage(500,500,RGB);
  size(500,500);
  I.loadPixels();
  int b = 0;
  for(int y = 0; y < I.height; y++){
    for(int x = 0; x<I.width; x++){
      r = lerp(0,255,float(x)/I.width);
      g = lerp(0,255,float(y)/I.height);
      c = color(r,g,b);
      //I.pixels[pos(x,y,I.width)] = c;
      // oppure quella sotto, se levo la l'istruzione sopra dovrei togliere loadPixels e updatePixels
      I.set(x,y,c);
    }
  }
  I.updatePixels();
  
}  

int pos(int x, int y, int w){
  return x+y*w;
}

void draw(){
  image(I,0,0);
}

/*
PImage I;
color c;

int pos(int x, int y, int w){
  return x+y*w;
}

void setup(){
  c = color(255,255,0);
  I = loadImage("lena.png");
  size(512,512);
  
  //for(int i = 0; i < I.width; i++){ // disegniamo una linea gialla lungo la diagonale
  //  I.set(i,i,c);
  //}
  // Come la facciamo usando la matrice linearizzata?
  // Usando la seguente formula: x+y * width // metti -x per avere la diagonale secondaria
  // Per farlo definiamo la funzione pos
  
  I.loadPixels();
  for(int i = 0; i < I.width; i++){
    I.pixels[pos(i,i,I.width)] = c;
  }
  I.updatePixels();
}



void draw(){
  image(I,0,0);
}
*/








// Argomento fondamentale della seconda parte del corso

//Come creiamo una matrice linearizzata in processing? 
// una matrice linearizzata sono tutti i pixel messi dentro un array

/*
PImage I;
// I.loadPixel();
// I.updatePixel();
float r,g,b;
color c,c1;
int ar;
void setup(){
  I = loadImage("lena.png");
  size(512,512);
  ar = 0;
}

void draw(){
  image(I,0,0);
}

void keyPressed(){
  if(key == '+') ar++;
  if(key == '-') ar--;
  
  I.loadPixels(); //I.pixels contiene tutti i pixel della nostra img (precisamente il colore di ogni pixel)
  
  for(int i = 0; i < I.pixels.length; i++){
    c1 = I.pixels[i];
    c = color(red(c1)+ar, green(c1), blue(c1));
    I.pixels[i] = c;
  }
  
  I.updatePixels();
  println(ar);
}
*/
/*
PImage H;
color c;
int x, y;

void setup() {
  size(500, 500);
  H = loadImage("lena.png");
  H.resize(200, 200);
  c = color(0);
  x = width/2 - H.width/2; // Punto x di inizio img
  y = height/2 - H.height/2; // Punto y di inizio img
  println(x);
  println(y);
}


void draw() {
  background(c);// metto il colore ugale al colore c
  c = H.get(mouseX-x, mouseY-y); // in base a dove si trova il mouse prendo il colore
  image(H,x,y);
}
*/
