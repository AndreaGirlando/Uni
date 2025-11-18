// Gestione testo

PFont f;
String typing = "";
String saved = "";
int indent = 25;

void setup(){
  size(500,300);
  f = createFont("Calibri", 16);
  textFont(f);
  fill(0);
}

void draw(){
  background(255);
  text("Clicca sulla canvas e scrivi;\nInvio per salvare", indent, 30);
  text("Input: " + typing, indent, 120);
  text("Testo salvato: "+saved, indent, 210);
}

void keyPressed(){
  if(key == '\n'){
    saved = typing;
    typing = "";
  }else if(key == BACKSPACE && typing.length()>0){
    typing = typing.substring(0, typing.length()-1);
  }
  else{
    typing = typing + key;
  }
}

/*
size(500, 500);
fill(0, 100, 150);
textSize(50);
String x = "Stringa più lunga di una semplice parola";
text(x,10,40,100,220);
*/
/*
void setup(){
   size(500,500);
   size(120,120);
   textAlign(CENTER);
   textSize(60);
}

void draw(){
  background(0);
  text(key, 60, 60);
}
*/
/*
textSize(70);
text("hello world", 10, 70);
text("word", 10, 140);
fill(0, 100, 150, 50);
text("hello world", 10, 210);
*/

/*
PFont c,a;
a = createFont("Arial",50);
c = createFont("Times New Roman",120);
textFont(a);
text("Font Arial", 10, 70);
textFont(c);
text("Font Times New Roman", 10, 180);
*/

// Se il font non è presente su tutti i sistemi processing ci dà l'opportunita di importare un file che descrive il font questo si fa usando:
// f = loadFont("nomeFile.vlw") // tutti i file esterni vanno inseriti dentro la cartella data, nei path non si deve mai inserire data 
