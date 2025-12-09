// Questo esame cambia il disegno da fare ma la logica resta la stessa all'esame
ArrayList<Ball> ab;

void setup(){
  size(800,500);
  frameRate(250);
  ab = new ArrayList<Ball>();
}

void draw(){
  background(0);
  for(Ball b:ab){
    b.run();
  }
}

void keyPressed(){
  if(key == 'n' || key == 'N'){
    ab.add(
      new Ball(
        random(35,width-35), 
        random(35,height-35), 
        random(30,70), 
        random(1,10), 
        random(1,10)
      )
    );
  }
  if(key == 'g' || key == 'G'){
    ab.add(
      new GreenBall(
        random(35,width-35), 
        random(35,height-35), 
        random(30,70), 
        random(1,10), 
        random(1,10)
      )
    );
  }
}
