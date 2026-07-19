//ricapitolo.
//ARRAY serve a conservare dati della stessa natura. se dobbiamo disegn 100 cerchi identici si mettono dati essenziali (es posiz) e poi si usa il ciclo for
//rettangoli tra di loro random ma con posizione fissa e poi si muovono assieme
//si crea fuori dalle funzioni
//inizializz array con il for nel setup e nel draw facciamo un ciclo for per leggerli
//possono contenere solo un tipo di dati, o float, o colori etc
float[] y= new float [1000];//vuoto
//esplicito con par graffe e i valori

void setup(){
  size (500,500);
  noStroke();
  //random in ciclo per cambiare colore ad ogni esecuzione
  //il random prende sempre float
  fill(random(255), random(255), random(255), 200);
  //lo facciamo dipendere dalla lunghezza dell'array senza mettere 5000
  for (int i=0; i<y.length; i++){ //i++=increm di 1
     //se array è new int [5]; fa una var array di 5 caselle e lo riempie col valore neutro di int (abbiamo chiamato int, non float o boolean)
     //in questo caso abbiamo 5000 caselle piene di 0.0
     //per riempire una casella(ad es la 1) basta fare y[1], se cambiamo valore facciamo y[1]=20 
    
    //almeno qualche rett è visibile
    y[i]=random(-1000,200); 
  }
}

void draw(){
  //aggiorniamo backg
  background(0);
  //sono tanti rect quindi usiamo il for
   for (int i=0; i<y.length; i++){ //facciamo spost rect di 1 pixel al fotogramma
     y[i]+=1;
     //per le x possiamo usare possiamo usare il val della i 
     float moltiplicatore=width/float(y.length);
     float x= i*moltiplicatore;
     rect(x,y[i],20,30);
   } 
}
