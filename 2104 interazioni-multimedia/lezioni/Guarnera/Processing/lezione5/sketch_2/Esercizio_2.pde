// Questo esame cambia il disegno da fare ma la logica resta la stessa all'esame
ArrayList<Ball> ab;

void setup(){
  size(800,500);
  ab = new ArrayList<Ball>();
}

void draw(){
  background(0);
  for(Ball b:ab){ // Foreach dentro la lista di palline
    b.run(); // Invochiamo run dentro le palline
  }
}

void keyPressed(){
  if(key == 'n' || key == 'N'){ // Al click di n vado a creare una nuova pallina
    ab.add(
      new Ball(
        random(35,width-35), //x -> [35, width-35]
        random(35,height-35), //y -> [35, width-35]
        random(30,70), // size -> [30,70]
        random(1,10),  // speed -> [1,10]
        random(1,10) // speed -> [1,10]
        //parto da 35 in x e y in modo che anche la pallina da 70 si trovi nei bordi della canvas
      )
    );
  }
  if(key == 'g' || key == 'G'){ // Al click di n vado a creare una nuova pallina verde
    ab.add( 
      new GreenBall(
        // i commenti fatti sopra valgono anche qui
        random(35,width-35), 
        random(35,height-35), 
        random(30,70), 
        random(1,10), 
        random(1,10)
      )
    );
  }
}
