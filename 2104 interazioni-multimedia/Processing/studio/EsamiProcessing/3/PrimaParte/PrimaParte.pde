
Monitor monitor;
OldMonitor OldMonitor;
void setup() {
  size(512, 512);
  int w = 60;
  int aspect169 = w/16*9;
  int aspect43 = w/4*3;
  int speed = int(random(1, 6)) * (random(1) > 0.5 ? 1 : -1);
  monitor = new Monitor(100, 100, speed, aspect169, w, 1);
}

void draw() {
  background(255);
  monitor.run();
}

void keyPressed() {
  if (key == 'r' || key == 'R')
    setup();
}
