class Ball {
  float posX, posY, size; //posizione e grandezza
  float speedX, speedY; // velocità

  Ball(float x, float y, float s, float sx, float sy) {
    this.posX = x;
    this.posY = y;
    this.size = s;
    this.speedX = sx;
    this.speedY = sy;
  }

  Ball(float x, float y, float s) { //costruttore di una pallina ferma, se mai servisse
    this(x, y, s, 0, 0); 
  }

  void display() { // disegniamo una pallina gialla usando le posizioni e le grandezza data
    fill(255, 255, 0);
    noStroke();
    ellipse(posX, posY, size, size); //size viene usata due volte in modo da avere un cerchio
  }

  void move() { // funzione che simula il movimento della pallina incrementando X e Y della velocità
    posX+=speedX;
    posY+=speedY;
  }

  void bounce() {
    // Ivertiamo il valore di velocità quando la pallina raggiunge i bordi
    // size/2 sarebbe il raggio del nostro cerchio  
    if (posX < size/2 || posX > width-size/2) {
      speedX=-speedX;
    }
    if (posY < size/2 || posY > height-size/2) {
      speedY=-speedY;
    }
  }

  void gravity() {
    speedY+=0.2; //Facciamo in modo che la pallina subisca la gravità, aumentando la velocità di 0.2
  }

  void run() {
    gravity();
    move();
    bounce();
    display();
  }
}
