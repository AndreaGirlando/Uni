PImage im;
PImage sub; 

void setup(){
  size(600,600);
  im=loadImage("lena.png");
  println("Larghezza:"+im.width);
  println("Altezza:"+im.height);
  //sub=im.get(0,0,150,150);
}

void draw(){
  background(0);
  image(im,0,0);
  //image(sub,0,0);
  
}

void mousePressed()
{
  im.resize(im.width/2,im.height/2);
}

void keyTyped()
{
  if(key=='s' || key=='S')
  {
    println(savePath("lenaPiccola.png"));
    im.save(savePath("output/lenaPiccola.png"));
  }
  
  if(key=='c' || key=='C')
  {
    println("Salvo la Canvas");
    saveFrame("cavnvas.png");
  }
}
