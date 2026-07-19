/* incrementi/decremento
"x=x+10" si può scrivere anche "x+=10"
nel caso in cui si deve incrementare/decrementare di una sola unità,
si può scrivere anche "x++;" o "x--;" invece di scrivere "x=x+1" o "x+=1"
*/

size(480, 240);

//linee orizzonali sottili
for (int i=0; i<200; i+=5){    //finché le condizioni tra le parentesi di "for" sono soddisfatte, il ciclo viene eseguito e inizia e finisce con le { }
                               //for (inizializzazione della variabile contatore; condizione della variabile; incremento del contatore)
 line(30, i, 80, i); 
}

/*quando si crea una variabile all'interno di { } essa esiste solo all'interno di { }
per questo in questo caso, per stampare prima, creo la variabile fuori, così da esistere all'interno di tutto il file da qui in poi
*/

//linee oblique grosse
int i=0;
println("valore di i: ");
strokeWeight(8);
for (i=20; i<320; i+=60){
 line(i, 40, i+60, 80);
 print(i+", ");
}
println();
println("valore finale di i: "+i);