class Square {
  float posX, posY;
  float size;
  float speedX, speedY;

  Square(float tempPosX, float tempPosY, float tempSize, float tempSpeedX, float tempSpeedY) {
    posX = tempPosX;
    posY = tempPosY;
    size = tempSize;
    speedX = tempSpeedX;
    speedY = tempSpeedY;
  }
  Square(float tempPosX, float tempPosY, float tempSize) {
    this(tempPosX, tempPosY, tempSize, 0.0, 0.0);
  }

  void display() {
    fill(255, 0, 0);
    noStroke();
    square(posX, posY, size);
  }

  void move() {
    posX += speedX;
    posY += speedY;
  }

  void bounce() {
    if (posX > width-size) {
      speedX = -speedX;
      posX = width-size;
    } else if (posX < 0) {
      speedX = -speedX;
      posX = 0;
    }

    if (posY > height-size) {
      speedY = -speedY;
      posY = height-size;
    } else if (posY < 0) {
      speedY = -speedY;
      posY = 0;
    }
  }

  void gravity() {
    speedY += 0.15;
  }

  void run() {
    gravity();
    move();
    bounce();
    display();
  }
}
