class Ball{
  
  float posX,posY,size;//posizione e grandezza
  float sx,sy; //velocità
  
  Ball(float x, float y, float s, float sx, float sy)
  {
    this.posX=x;
    this.posY=y;
    this.size=s;
    this.sx=sx;
    this.sy=sy; 
  }
  
  Ball(float x, float y, float s)
  {
    this(x,y,s,0,0);
  }
  
  
  void display(){
    fill(255,255,0);
    noStroke();
    ellipse(posX,posY,size,size);
  }
  
  void move(){
    posX+=sx;
    posY+=sy;
  }
  
  void bounce(){
    if(posX<size/2 || posX>width-size/2)
    {
      sx=-sx;
    }
    
    if(posY<size/2 || posY>height-size/2)
    {
      sy=-sy;
      posY=height-size/2;
    }
  }
  
  void gravity()
  {
    sy+=0.2;
  }
  
  
 void run(){
   gravity();
   move();
   bounce();
   display();
 }
  
}
