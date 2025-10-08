size(900, 500);
background(255);
fill(255, 0, 0);
stroke(14);
strokeWeight(2.1);
ellipse(75, 75, 150, 150);
fill(255, 255, 0, 127);
noStroke();
ellipse(75+75, 75, 150, 150);

stroke(14);
strokeWeight(2.1);
fill(255, 255, 255);
rect(200, 200, 150, 150);

ellipseMode(CORNER);
ellipse(350, 200, 150, 150); // i primi due per il punto in alto a sinistra e gli ultimi due come il raggio
ellipseMode(CENTER); //valore di defualt
//esiste anche rectMode che funziona in modo simile
