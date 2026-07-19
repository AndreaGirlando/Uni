
ArrayList<Voto> list;
void setup() {
  list = new ArrayList<Voto>();
  size(500, 500);
}

void draw() {
  background(0);
  for (Voto v : list) {
    v.run();
  }
}

void mousePressed() {
  if (mouseButton == LEFT) {
    list.add(new Voto(
      30,
      int(random(18, 30)),
      int(random(0, width-60)),
      int(random(0, height-60)),
      int(random(2, 10)),
      1
      ));
  } else if (mouseButton == RIGHT) {
    list.add(new Votone(
      30,
      int(random(18, 30)),
      int(random(0, width-60)),
      int(random(0, height-60)),
      int(random(2, 10))
      ));
  }
}

void keyPressed() {
  if (key == 'r' || key == 'R')
    setup();
}
