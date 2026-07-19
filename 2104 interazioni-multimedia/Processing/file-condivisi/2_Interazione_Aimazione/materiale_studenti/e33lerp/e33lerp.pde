int x1 = 15;
int y1 = 10;
int x2 = 80;
int y2 = 90;
line(x1, y1, x2, y2);
for (int i = 0; i <= 10; i++) {
  float x = lerp(x1, x2, i/10.0) + 10;
  float y = lerp(y1, y2, i/10.0);
  point(x, y);
}