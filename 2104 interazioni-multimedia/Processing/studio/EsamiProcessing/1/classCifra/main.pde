ArrayList<Cifra> list;

void setup() {
  list = new ArrayList<Cifra>();
  size(500, 500);
}

void draw() {
  background(0);
  for (Cifra cf : list) {
    cf.run();
  }
}

void keyPressed() {

  if (key >= '0' && key <= '4') {
    list.add(new Cifra(
      int(random(0, width-100)),
      int(random(0, height-100)),
      int(random(2, 10)),
      key
      ));
  } else if (key >= '5' && key <= '9') {
    list.add(new Cifrotta(
      int(random(0, width-100)),
      int(random(0, height-100)),
      int(random(2, 10)),
      key
      ));
  }
}

void mousePressed(){
  if(mouseButton == RIGHT){
    setup();
  }
}
