class Votone extends Voto {
  Votone(int tempLato, int tempNumero, int tempPosX, int tempPosY, int tempSpeed) {
    super(tempLato, tempNumero, tempPosX, tempPosY, tempSpeed, 0);
  }

  void display() {
    stroke(255, 255, 255);
    noFill();
    square(posX, posY, lato);
    textSize(28);
    text(numero, posX, posY+lato-5);
    if (numero > 24) {
      text("LODE", posX, posY+lato*2);
    }
  }
}
