
class Cifra{
  char cifra;
  int posX;
  int posY;
  int speed;
  Cifra(int tempPosX, int tempPosY, int tempSpeed, char tempCifra){
    posX = tempPosX;
    posY = tempPosY;
    speed = tempSpeed;
    cifra = tempCifra;
  }
  
  
  void display(){
    fill(255,255,0);
    textSize(32);
    text(cifra, posX, posY);
  }
  
  void muovi(){
    posY = posY+(1*speed);
    if(posY > height){
       posY = 0;
       posX = int(random(0,width));
    }
  }
  
  void run(){
    display();
    muovi();
  }
  
}
  
  
