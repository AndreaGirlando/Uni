
void setup(){
  size(300,300);
  frameRate(60);
}
int pos=0;

void draw(){ 
  background(200);
  line(pos,0,pos,height);
  if (pos>width){
    pos=0;
  }
  pos++;
}