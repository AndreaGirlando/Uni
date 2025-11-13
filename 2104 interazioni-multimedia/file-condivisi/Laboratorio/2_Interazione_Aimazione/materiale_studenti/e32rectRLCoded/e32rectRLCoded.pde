int x=200;

void setup(){
  size(480,120);
}

void draw(){
  background(200);
  if(keyPressed && (key==CODED)){//il codice associato a determinati tasti(non per le lettere)
    if (keyCode==LEFT){
      x--;
    }
    //è codificato non è in left ma in right se solo con else si attiverebbe con qualsiasi altro tasto
    else if(keyCode==RIGHT){
      x++;
    }
  }
      rect(x,45,50,50);
}