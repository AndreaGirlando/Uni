size(800, 200);
strokeWeight(2);
//ciclo for 
//(inizializzazione contatore; condizione di permanenza nel ciclo; incremento contatore)
for (int i=20; i<400; i+=20){
  line(i, 0, i+i/2, height/2);
  line(i, height, i+i/2, height/2); //le seconde linee terminano dove terminano le prime (stesse coordinate)
}