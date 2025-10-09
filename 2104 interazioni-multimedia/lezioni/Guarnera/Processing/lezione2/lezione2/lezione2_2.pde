/*
size(1000, 700);
background(255);
noFill();

int raggio = 30;
int d = raggio * 2;

for (int center = raggio; center + d/2 <= width && d <= height; center += raggio) {
  ellipse(center, height / 2, d, d);
  d += raggio * 2;
  println(d);
}

*/
