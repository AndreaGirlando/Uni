size(480,120);
//uso tre variabili per riutilizzarne i valori per i tre rettangoli
int x=25;
int h=20;
int y=30;

rect(x,y,300,h);
x=x+100;//aggiorno il valore della x, per far slittare in orizzontale i nuovi rettangoli
rect(x,y+h,300,h);
x=x-250;
rect(x,y+2*h,300,h);