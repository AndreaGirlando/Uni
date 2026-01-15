void setup(){
  size(500,500);
  noFill();
}
void draw(){
 background(255); 

stroke(255,100,0);
line(185,50,mouseX,mouseY);
line(190,300,15,290);
stroke(0);
bezier(185,50,mouseX,mouseY,15,290,190,300);

}
