int pos=0;
int dir=1;

void setup(){
  size(300,300);
  frameRate(120);
}


void draw(){ 
  background(200);
  line(pos,0,pos,height);
  if (pos>width){
    dir=-1;
  }
  if (pos<0){
    dir=1;
  }
  pos+=dir;
}