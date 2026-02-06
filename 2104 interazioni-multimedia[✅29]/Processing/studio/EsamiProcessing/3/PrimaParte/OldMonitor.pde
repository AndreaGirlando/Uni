class OldMonitor extends Monitor {
  color coloreMonitor, coloreBordo;
  OldMonitor(int tempPosX, int tempPosY, int tempSpeed, int tempH, int tempW, int tempDir) {
    super(tempPosX, tempPosY, tempSpeed, tempH, tempW, tempDir);
    coloreMonitor = color(0, 255, 0);
    coloreBordo = color(82, 75, 75);
  }
  void display() {
    fill(coloreMonitor);
    stroke(coloreBordo);
    strokeWeight(5);
    rect(posX, posY, 60, 60/4*3);
  }

  void muovi() {
    if (dist(posX,posY, mouseX, mouseY) > 30) {
      posX = posX + dir*speed;
      if (posX > width) {
        posX = 0;
      } else if (posX < -50) {
        posX = width;
      }
    }
  }
}
