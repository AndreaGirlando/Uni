size(480, 480);

colorMode(RGB, 100);//il primo valore indica lo spazio colori sa usare, 
                    //il secondo l'estremo superiore dell'intervallo di valori
                    // che la funzione accetta. L'estremo inferiore è zero.
stroke(30, 50, 10); //30% di ROSSO, 50% di VERDE, 10% di BLU

/*
la stessa cosa si può scrivere con:

colorMode(RGB, 1.0);
stroke(0.3, 0.5, 0.1); //30% di ROSSO, 50% di VERDE, 10% di BLU

la funzione colorMode() definisce il range dei valori che si possono inserire.
di default il valore massimo è 255
*/

strokeWeight(50);
line(50, 50, 430, 430);