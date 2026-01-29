class BlueSquare extends Square{
  BlueSquare(float tempPosX, float tempPosY, float tempSize, float tempSpeedX, float tempSpeedY) {
    super(tempPosX, tempPosY, tempSize, tempSpeedX, tempSpeedY);
  }
  void display() {
    fill(0, 0, 255);
    noStroke();
    square(posX, posY, size);
  }
}
