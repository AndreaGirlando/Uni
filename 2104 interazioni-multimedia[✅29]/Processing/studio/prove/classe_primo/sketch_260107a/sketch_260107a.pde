
ArrayList<Square> SquareList = new ArrayList<Square>();
int size = 20;
void setup() {
  size(700, 500);
  for(int i = 0; i < size; i++){
    if(i%2 == 0){
      SquareList.add(new Square(random(0, width-size), random(0, height-size), size, 10, 10));
    }else{
      SquareList.add(new BlueSquare(random(0, width-size), random(0, height-size), size, 10, 10));
    }
  }
}

void draw() {
  background(0);
  
  for (Square sq : SquareList) {
    sq.run();
  }
}

void keyPressed() {
  float size = random(15,50);
  if (key == 'a' || key == 'A') {
    SquareList.add(new Square(random(0, width-size), random(0, height-size), size, 10, 10));
  }
  if (key == 'b' || key == 'B') {
    SquareList.add(new BlueSquare(random(0, width-size), random(0, height-size), size, 10, 10));
  }
}
