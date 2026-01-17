/*
la funzione setup(){} viene eseguite solo una volta.
la funzione draw(){} è un loop infinito (for(){} è finito) e viene richiamato
60 volte al secondo (60fps).
quando si definiscono queste funzioni, si devono creare promettendo il tipo di dato
che restituiscono (ad esempio random() restituisce un float, color() restituisce un colore),
nel caso di queste due funzioni, non restituiendo nessun dato, saranno accompagnate da "void"
*/

void setup(){
  println("sono nel setup");
  frameRate(2);                                           //la funzione frameRate() definisce gli fps. di defaulf è a 60.
}

void draw(){
  println("mi trovo nel draw al frame: "+frameCount);     //frameCount è una variabile che conta i frame in cui ci si trova per ogni ciclo
}