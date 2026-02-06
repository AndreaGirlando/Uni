
//EQUALIZZAZIONE

PImage Im, Is, Ie;

void setup(){
  size(1536,812);
  background(0);
  
  Im=loadImage("lena.png");
  Im.filter(GRAY);
  Is=stretching(Im);
  Ie=equalizza(Im);
  
  image(Im,0,0);
  image(Is,512,0);
  image(Ie,1024,0);
  
  float [] H1,H2,H3;
  H1=istogramma(Im);
  H2=istogramma(Is);
  H3=istogramma(Ie);
  rectMode(CORNERS);
  noStroke();
  fill(255,255,0);
  for (int i=0;i<256;i++)
  {
  rect(i*2,height-(H1[i]*256*100),i*2+2,height);
  rect(Im.width+i*2,height-(H2[i]*256*100),Im.width+i*2+2,height);
  rect(Im.width*2+i*2,height-(H3[i]*256*100),Im.width*2+i*2+2,height);
  }

}
void draw(){}

PImage stretching(PImage I)
{
  PImage R=I.copy();
  
  float max,min;
  R.loadPixels();
  max=red(R.pixels[0]);
  min=red(R.pixels[0]);
  
  for(int i=0; i<R.pixels.length; i++)
  {
    if(red(R.pixels[i])<min)
    min=red(R.pixels[i]);
    
    if(red(R.pixels[i])>max)
    max=red(R.pixels[i]);
    
  }
  
  for(int i=0; i<R.pixels.length; i++)
  {
    R.pixels[i]=color(255*(red(R.pixels[i])-min)/(max-min));
  }
  
  R.updatePixels();
  
  
  return R;
}

PImage equalizza(PImage I)
{
  PImage R=I.copy();
  
  float [] H=istogramma(I);
  
  //Istrogramma cumulativo
  for(int i=1;i<256; i++)
  {
    H[i]=H[i-1]+H[i];
  }
  
  R.loadPixels();
  
  for(int i=0; i<R.pixels.length; i++)
  {
    R.pixels[i]=color(255*H[int(red(R.pixels[i]))]);
  }
  
  R.updatePixels();
  
  return R;
}


float [] istogramma(PImage I)
{
  float[] H=new float[256];
  
  for(int i=0; i<256; i++)
  {
    H[i]=0;
  }
  
  I.loadPixels();
  
  for(int i=0; i<I.pixels.length; i++)
  {
    H[int(red(I.pixels[i]))]++;
  }
  
  for(int i=0; i<256; i++)
  {
    H[i]=H[i]/I.pixels.length;
  }
  
  return H;
    
}








// CONVOLUZIONE
/*
PImage Im, In3, In5, Il, Is, IsX;
//creo i kernel
float n3=1/9.0;
                  
float[][] nbox3={{n3, n3, n3},
                {n3, n3, n3},
                {n3, n3, n3}};
float n5=1.0/25;
float[][] nbox5={{n5,n5,n5,n5,n5},
                {n5,n5,n5,n5,n5},
                {n5,n5,n5,n5,n5},
                {n5,n5,n5,n5,n5},
                {n5,n5,n5,n5,n5}};
                
float[][] lapl={ {-1,0,-1},
                  {0,4,0},
                  {-1,0,-1}};
                  
float[][] sobX={ {-1,-2,-1},
                  {0,0,0},
                  {1,2,1}};
                  
float[][] sharp={{-1,0,-1},
                  {0,5,0},
                  {-1,0,-1}};
                  
float[][] random={{2,-2,-3},
                  {2,-1,0.5},
                  {-1,4,2}};
                  
 
void setup(){
  
  size(1536,1024);
  Im=loadImage("lena.png");
  Im.filter(GRAY);
  //convoluzione su matrici e conversione in PImage
  In3=converti(convoluzione(Im,nbox3));
  In5=converti(convoluzione(Im,nbox5));
  Il=converti(convoluzione(Im,lapl));
  Is=converti(convoluzione(Im,sharp));
  IsX=converti(convoluzione(Im,sobX));
  
  //In3=converti(convoluzione(Im,random));
  
  image(Im,0,0);
  image(In3,512,0);
  image(In5,1024,0);
  image(Il,0,512);
  image(Is,512,512);
  image(IsX,1024,512);
}

void draw(){}

float[][] convoluzione(PImage I, float[][] K)
{
  float[][] R= new float[I.height][I.width];
  
  int N=K[0].length;
  int M=K.length;
  
  PImage tmp;
  float res;
  
  for(int x=0; x<I.width; x++)
  {
    for(int y=0; y<I.height; y++)
    {
      tmp=I.get(x-N/2, y-M/2,N,M);
      res =0;
      for(int p=0; p<N; p++)
      {
        for(int q=0; q<M; q++)
        {
          res=res+green(tmp.get(p,q))*K[q][p];
        }
      }
      
      
      R[y][x]=res;
    }
  }

   return R;
}

PImage converti(float[][] F)
{
  PImage R=createImage(F[0].length,F.length,RGB);
  int res=0;
  for(int x=0; x<R.width; x++)
  {
    for(int y=0; y<R.height; y++)
    {
      res=int(constrain(F[y][x],0,255));
      R.set(x,y,color(res));
    }
  }
  
  return R;

}

*/  

//zooming 2x
/*PImage Im, Ic, Ir;
float mseO, mseP, mseR, psnrO, psnrP, psnrR;

void setup(){
  Im=loadImage("lena.png");
  Im.filter(GRAY);
  size(1536,512);
  background(0);
  
  Ic=Im.copy();
  Ic.resize(256,256);
  Ic.resize(512,512);
  
  Ir=Im.copy();
  Ir.resize(256,256);
  Ir=replication2x(Ir);
  
  image(Im,0,0);
  image(Ic,512,0);
  image(Ir,1024,0);
  
  mseO=MSE(Im,Im);
  mseP=MSE(Im,Ic);
  mseR=MSE(Im,Ir);
  
  psnrO=PSNR(Im,Im);
  psnrP=PSNR(Im,Ic);
  psnrR=PSNR(Im,Ir);
  
  println("MSE Origin:"+mseO);
  println("MSE Processing:"+mseP);
  println("MSE Replication2x:"+mseR);
  
  println("PSNR Origin:"+psnrO);
  println("PSNR Processing:"+psnrP);
  println("PSNR Replication2x:"+psnrR);
  
}

void draw(){}

PImage replication2x(PImage I)
{
  PImage R=createImage(2*I.width,2*I.height,RGB);
  
  for(int x=0; x<I.width; x++)
  {
    for(int y=0; y<I.height; y++)
    {
      
      R.set(2*x,2*y,I.get(x,y));
      R.set(2*x+1,2*y,I.get(x,y));
      R.set(2*x,2*y+1,I.get(x,y));
      R.set(2*x+1,2*y+1,I.get(x,y));
      
    }
  }
 
  return R;
}

float MSE(PImage I1, PImage I2)
{
  float res=0;
  I1.loadPixels();
  I2.loadPixels();
  
  for(int i=0; i<I1.pixels.length; i++)
  {
    res+=pow(blue(I1.pixels[i])-blue(I2.pixels[i]),2);
  }
  
  res=res/I1.pixels.length;
  
  return res;
  
}


float PSNR(PImage I1, PImage I2)
{
  float res;
  
  float mse=MSE(I1,I2);
  
  res=10*log(255*255/mse)/log(10);
  
  return res;
}

*/

//RANGO MAX/MIN/MEDIANO
/*
PImage Im,Imax,Imin,Imed;

void setup()
{
  size(1024,1024);
  Im=loadImage("lena.png");
  Im.filter(GRAY);
  Imax=massimo(Im,11);
  Imin=minimo(Im,11);
  Imed=mediano(Im,11);
  image(Im,0,0);
  image(Imax,512,0);
  image(Imin,0,512);
  image(Imed,512,512);
}
void draw()
{
}


PImage massimo(PImage I, int N)
{
  PImage R=createImage(I.width, I.height, RGB);
  
  PImage tmp;
  int off=N/2;
  float [] tmpF;
  
  tmpF=new float[N*N];
  
  for(int x=0; x<I.width; x++)
  {
    for(int y=0;y<I.height; y++)
    {
      tmp=I.get(x-off,y-off,N,N);
      tmp.loadPixels();
      for(int i=0; i<tmp.pixels.length; i++)
      {
        tmpF[i]=red(tmp.pixels[i]);
      }
      
      R.set(x,y,color(max(tmpF)));
    }
  }
  
  return R;
}

PImage minimo(PImage I, int N)
{
  PImage R=createImage(I.width, I.height, RGB);
  
  PImage tmp;
  int off=N/2;
  float [] tmpF;
  
  //tmpF=new float[N*N];
  int xs, ys;
 
  
  for(int x=0; x<I.width; x++)
  {
    for(int y=0;y<I.height; y++)
    {
      
       xs=x-off;
       ys=y-off;
   
   
      //tmp=I.get(x-off,y-off,N,N);
      tmp=I.get(max(0,xs),max(0,ys),min(N,min(N+xs,I.width-xs)),min(N,min(N+ys,I.height-ys)));
      tmp.loadPixels();
      
      tmpF=new float[tmp.pixels.length];
      
      for(int i=0; i<tmp.pixels.length; i++)
      {
        tmpF[i]=red(tmp.pixels[i]);
      }
      
      R.set(x,y,color(min(tmpF)));
    }
  }
  
  return R;
}

PImage mediano(PImage I, int N)
{
  PImage R=createImage(I.width, I.height, RGB);
  
  PImage tmp;
  int off=N/2;
  float [] tmpF;
  
  //tmpF=new float[N*N];
  int xs, ys;
  float med;
 
  
  for(int x=0; x<I.width; x++)
  {
    for(int y=0;y<I.height; y++)
    {
      
       xs=x-off;
       ys=y-off;
   
   
      //tmp=I.get(x-off,y-off,N,N);
      tmp=I.get(max(0,xs),max(0,ys),min(N,min(N+xs,I.width-xs)),min(N,min(N+ys,I.height-ys)));
      tmp.loadPixels();
      
      tmpF=new float[tmp.pixels.length];
      
      int s=tmp.pixels.length;
      
      for(int i=0; i<tmp.pixels.length; i++)
      {
        tmpF[i]=red(tmp.pixels[i]);
      }
      
      tmpF=sort(tmpF);
      
      if(s%2==1)
      {
        med=tmpF[s/2];
      }
      else
      {
        med=(tmpF[s/2]+tmpF[s/2-1])/2;
      }
      
      
      
      R.set(x,y,color(med));
    }
  }
  
  return R;
}
*/


//BITPLANE

/*
PImage Im,Ib;
int K;
void setup()
{
  Im=loadImage("lena.png");
  Im.filter(GRAY);
  size(1024,512);
  image(Im,0,0);
  K=7;
  Ib=bitplane(Im,K);
  image(Ib,512,0);
}

void draw()
{
}

PImage bitplane(PImage I, int nb)
{
  PImage R=I.copy();
  R.loadPixels();
  
  int x;
  int r;
  
  for (int i=0; i<R.pixels.length; i++)
  {
    x=int(blue(R.pixels[i]));
    r=(x>>nb)&1;
    R.pixels[i]=color(r*255);
  }
  
  R.updatePixels();
  return R;
  
}

void keyPressed(){

  if((key=='+') && (K<7))
  {
    Ib=bitplane(Im,++K);
    image(Ib,512,0);
  }
  
  if((key=='-') && (K>0))
  {
    Ib=bitplane(Im,--K);
    image(Ib,512,0);
  }
}

*/




          
