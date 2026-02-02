class Cifrotta extends Cifra {
  Cifrotta(int tempPosX, int tempPosY, int tempSpeed, char tempCifra) {
    super(tempPosX, tempPosY, tempSpeed, tempCifra);
  }

  void display() {
    fill(255, 255, 255);
    textSize(32);
    textAlign(CENTER);
    text(cifra, posX, posY);
    ellipseMode(RADIUS);
    noFill();
    stroke(255, 255, 255);
    ellipse(posX, posY, 45, 45);
  }

  void muovi() {
    posY = posY+(-1*speed);
    if (posY < 0) {
      posY = height;
      posX = int(random(0, width));
    }
  }
}
