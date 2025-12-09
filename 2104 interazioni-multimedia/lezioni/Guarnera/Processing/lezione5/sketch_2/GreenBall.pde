class GreenBall extends Ball{
  GreenBall(float x, float y, float s, float sx, float sy){
    super(x,y,s,sx,sy); //Richiamo il costruttore padre
  }
  GreenBall(float x, float y, float s){
    super(x,y,s);
  }
  
  void display(){
    fill(0,255,0);
    strokeWeight(5);
    stroke(255,0,255);
    ellipse(posX, posY, size, size);
  }
}
