// Costanti rappresentati radianti (angoli da usare in arc
// PI= pi greco (180)
// HALF_PI=Mezzo Pi greco (90)
// QUARTER_PI=Un quarto di Pi greco (45)
// TWO_PI=Due volte Pi greco (360)

//i primi 4 argomenti sono come in ellipse, gli ultimi due sono il punto
//di inizio e fine tra i quali viene tracciato l'arco (espressi in radianti)

size(480,120);
arc(90,60,80,80,0,HALF_PI);
arc(190,60,80,80,0,PI+HALF_PI);
arc(290,60,80,80,PI,TWO_PI+HALF_PI);
arc(390,60,80,80,QUARTER_PI,PI+QUARTER_PI);