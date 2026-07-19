class GreenBall extends Ball {
  GreenBall(float x, float y, float s, float sx, float sy) {
    super(x, y, s, sx, sy); //Richiamo il costruttore padre
  }
  GreenBall(float x, float y, float s) {
    super(x, y, s);
  }

  void display() { // Faccio un ovveride della funzione display della pallina normale
    fill(0, 255, 0); // Disegniamo la pallina ma verde
    ellipse(posX, posY, size, size);
  }
}
