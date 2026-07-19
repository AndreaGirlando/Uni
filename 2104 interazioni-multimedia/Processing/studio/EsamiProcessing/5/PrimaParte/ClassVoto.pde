class Voto {
  int lato;
  int numero;
  int posX, posY;
  int speed;
  int dir;
  Voto(int tempLato, int tempNumero, int tempPosX, int tempPosY, int tempSpeed, int tempDir) {
    lato = tempLato;
    numero = tempNumero;
    posX = tempPosX;
    posY = tempPosY;
    speed = tempSpeed;
    dir = tempDir;
  }

  void display() {
    stroke(255,255,0);
    noFill();
    square(posX, posY, lato);
    textSize(28);
    text(numero,posX,posY+lato-5);
  }

  void move() {
    posX = posX + dir * speed;
    if (posX > width-lato) dir = -dir;
    if (posX < 0) dir = -dir;
  }

  void run() {
    display();
    move();
  }
}
