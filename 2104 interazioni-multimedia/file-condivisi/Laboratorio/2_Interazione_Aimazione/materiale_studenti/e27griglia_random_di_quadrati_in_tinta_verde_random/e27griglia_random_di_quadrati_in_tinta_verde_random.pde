size(500, 500);
background(0, 255, 0);
noStroke();

int l= 50;

for(int y=0; y<=height; y+=l){
  for(int x=0; x<=width; x+=l){
    fill(random(255), 130);
    rect(x+random(-5,5),y+random(-5,5), l, l);
  }
}