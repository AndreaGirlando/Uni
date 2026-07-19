class Monitor {
  int posX;
  int posY;
  int h;
  int speed;
  int dir;
  int w;
  color coloreMonitor, coloreBordo;
  Monitor(int tempPosX, int tempPosY, int tempSpeed, int tempH, int tempW, int tempDir) {
    posX = tempPosX;
    posY = tempPosY;
    speed = tempSpeed;
    h = tempH;
    w = tempW;
    dir = tempDir;
    coloreMonitor = color(int(random(0,255)),int(random(0,255)),int(random(0,255)));
    coloreBordo = color(int(random(0,255)),int(random(0,255)),int(random(0,255)));
  }

  void display() {
    fill(coloreMonitor);
    stroke(coloreBordo);
    rect(posX,posY,60,30);
    ellipseMode(CENTER);
    ellipse(posX+30,posY-50,70,70);
    line(posX-5,posY-50,posX,posY);
    line(posX+65,posY-50,posX+60,posY);
  }

  void muovi() {
    posX = posX + dir*speed;
    if (posX > width) {
      posX = 0;
    } else if (posX < -50) {
      posX = width;
    }
  }

  void run() {
    muovi();
    display();
  }
}
