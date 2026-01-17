PImage Im, Iq;
int K;
void setup(){
  K=3;
  Im=loadImage("lena.png");
  Im.filter(GRAY);
  size(1024,512);
  image(Im,0,0);
  
  Iq=quantizza(Im,K);
  image(Iq,512,0);
}

void draw(){}

PImage quantizza(PImage I, int k)
{
  PImage R=I.copy();
  R.loadPixels();
  int q;
  for(int i=0; i<R.pixels.length; i++)
  {
    q=floor((blue(R.pixels[i])*k/256));
    q=int(float(q)/(k-1)*255);
    R.pixels[i]=color(q);
  }
  
  R.updatePixels();
  
  return R;
}


void keyPressed()
{
  if(key=='+')
  K++;
  
  if(key=='-')
  K--;
  
  Iq=quantizza(Im,K);
  image(Iq,512,0);
  
}


/*PImage Im, ImN, ImG, ImL;

void setup(){
  Im=loadImage("lena.png");
  Im.resize(256,256);
  Im.filter(GRAY);
  size(512,512);
  image(Im,0,0);
  
  ImN=negativo(Im);
  image(ImN,256,0);
  
  ImG=gamma(Im,2);
  image(ImG,0,256);
  
  ImL=logaritmo(Im);
  image(ImL,256,256);
 
}

PImage gamma(PImage I, float gm)
{
  PImage R=I.copy();
  R.loadPixels();
  float r,g,b;
  float C=1/pow(255,gm-1);
  
  for(int i=0; i<R.pixels.length; i++)
  {
    r=C*pow(red(I.pixels[i]),gm);
    g=C*pow(green(I.pixels[i]),gm);
    b=C*pow(blue(I.pixels[i]),gm);
    R.pixels[i]=color(r,g,b);
  }
  
  R.updatePixels();
  return R;
}

PImage logaritmo(PImage I)
{
  PImage R=createImage(I.width,I.height,RGB);
  float r,g,b;
  float C=255/log(256);
  
   R.loadPixels();
   I.loadPixels();
   
  for(int i=0; i<R.pixels.length; i++)
  {
    r=C*log(1+red(I.pixels[i]));
    g=C*log(1+green(I.pixels[i]));
    b=C*log(1+blue(I.pixels[i]));
    R.pixels[i]=color(r,g,b);
  }
  
  R.updatePixels();
  
  return R;
}

PImage negativo(PImage I)
{
  PImage R=I.copy();
  float r,g,b;
  R.loadPixels();
  for(int i=0; i<R.pixels.length; i++)
  {
    r=255-red(R.pixels[i]);
    g=255-green(R.pixels[i]);
    b=255-blue(R.pixels[i]);
    
    R.pixels[i]=color(r,g,b);
  }
  R.updatePixels();
  
  return R;
}

void draw(){}
*/

/*PImage I;
float r,g,b;
color c;

void setup(){
  I=createImage(500,500,RGB);
  size(500,500);
  b=0;
  //I.loadPixels();
  for(int y=0; y<I.height; y++)
  {
    for(int x=0; x<I.width; x++)
    {
      r=lerp(0,255,float(x)/I.width);
      g=lerp(0,255,float(y)/I.height);
      c=color(r,g,b);
      I.set(x,y,c);
      //I.pixels[pos(x,y,I.width)]=c;
    }  
  }
  
  //I.updatePixels();
  
}

void draw(){
  image(I,0,0);
}

int pos(int x, int y, int w)
{
  return x+y*w;
}*/


/*PImage I;
float r,g,b;
color c;

void setup(){
  c=color(255,255,0);
  I=loadImage("lena.png");
  size(512,512);
  I.loadPixels();
  for(int i=0; i<I.width; i++)
  {
    I.pixels[pos(i,i,I.width)]=c;
    //I.set(i,i,c);
  }
  I.updatePixels();
}

void draw()
{
  image(I,0,0);
}

int pos(int x, int y, int w)
{
  return x+y*w;
}*/







/*PImage I;
float r,g,b;
color c,c1;
int ar;

void setup(){
  I=loadImage("lena.png");
  size(512,512);
  ar=0;
}

void draw()
{
  image(I,0,0);
}

void keyPressed(){
  if(key=='+')
  ar++;
  
  if(key=='-')
  ar--;
  
  I.loadPixels();
  for(int i=0; i<I.pixels.length; i++)
  {
    c1=I.pixels[i];
    c=color(red(c1)+ar,green(c1),blue(c1));
    I.pixels[i]=c;
  }
  I.updatePixels();
  println(ar);
  
}*/

//I.loadPixels();
//I.updatePixels();



/*PImage H;
color c;
int x,y;

void setup(){
  size(500,500);
  H=loadImage("lena.png");
  H.resize(200,200);
  c=color(0);
  x=width/2-H.width/2;
  y=height/2-H.height/2;
  println(x);
  println(y);
}

void draw(){
  background(c);
  c=H.get(mouseX-x,mouseY-y);
  image(H,x,y);
}*/
