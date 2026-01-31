- **strokeCap** sarebbe il rounded per le linee
- **strokeJoin** sarebbe il rounded per gli angoli dei quadrati (Default: MITER, BEVEL e ROUND)
- **stroke**(0,255,0); colore dei bordi a verde
- **fill**(0,0,255); colore del riempimento blu
- **noFill**(); reimposta il riempimento
- **dist**() ritorna la distanza tra due punti dati
- **arc**(x,y,dimX,dimY, PI_start, PI_end)
- **color** c = **color(255,255,0)**; variabile di tipi colore (il colore specificato è il giallo)

| **Angolo (Radianti)**   | **Posizione p5.js / Processing** |
| ----------------------- | -------------------------------- |
| $0$                     | Ore 3 (Destra)                   |
| **`HALF_PI`** ($\pi/2$) | Ore 6 (Basso)                    |
| **`PI`** ($\pi$)        | Ore 9 (Sinistra)                 |
| **`TWO_PI`** ($2\pi$)   | Ore 3 (Giro completo)            |
- **line**(xStart,yStart,yStart, yEnd)
- **text**("A1",185,50); scrive A1 nelle coordinate date
- **mouseX**,**mouseY** coordinate di dove si trova il mouse
- **bezier**(x1, y1, x2, y2, x3, y3, x4, y4);
  Per visualizzare come funziona, immagina che la curva sia un elastico teso tra il primo e l'ultimo punto, mentre i punti centrali agiscono come magneti.
	- **Punto 1 (x1, y1):** Punto di ancoraggio iniziale. La curva parte esattamente da qui.
	- **Punto 2 (x2, y2):** Primo punto di controllo. Determina la direzione e la "forza" della curvatura iniziale.
	- **Punto 3 (x3, y3):** Secondo punto di controllo. Determina come la curva si raccorda verso la fine.
	- **Punto 4 (x4, y4):** Punto di ancoraggio finale. La curva termina esattamente qui.
- void **mousePressed**(){} azione dopo un click
- **mousePressed** variabile d'ambiente che ci indica se il mouse è cliccato
- void **keyPressed**(){} azioni dopo un click di un tasto della tastiera
- key variabile d'ambiente che ci indica quale tasto è stato cliccato (case-sensitive)
- **ellipse** crea un ellisse
- **lerp**(50,100,0.1): funzione che calcola la distanza tra due punti con uno specifico incremento percentuale (terzo parametro):
	- 0.1: quasi vicino allo start
	- 0.5: a metà
- Per fare la scia di un qualcosa:
```pde
void draw(){
  fill(0,25);
  rect(0,0,width,height);
  x = lerp(x,mouseX, 0.1);
  y = lerp(y,mouseY, 0.1);
  fill(255);
  ellipse(x,y,60,60);
}
```
- Per far muovere verso una direzione piuttosto che un'altra usare: $x = x+1*dir$ con dir che diventa l'opposto quando si arriva ai bordi
- **translate**(width/2, height/2); questo comando trasla quello che vediamo della canvas, in pratica ishifta l'origine di width/2 e height/2 (in questo caso)
- **rotate**($millis()*0.001*$TWO_PI$/10$) ruota la canvas rispetto all'origine (in questo caso specifico lo fa ogni 10 secondi)
- **map**(10, 0, width, 20, 250); mappa il primo range in un range più grande
- **scale**(scale); scalta rispetto al parametro passato
- **PushMatrix** e **PopMatrix** quando vogliamo utilizzare translate/rotate in un punto rispetto a qualcosa e in altro punto ripetto a qualcos'altro dobbiamo usare questi due comandi
```
  pushMatrix(); //Inizio blocco 1
  translate(width/2, height/2);
  fill(255,0,0);
  ellipse(0,0, 15, 15);
  rotate(random(255));
  drawRainbowRect();
  popMatrix(); //Fine blocco 1
  
  pushMatrix();//Inizio blocco 2
  translate(width/2+200,height/2+200);
  rotate(millis()*0.001*PI);
  ellipse(0,50,15,15);
  popMatrix(); //Fine blocco 2
```
- **PImage**: tipo variabile img
- PImage I = **createImage**(dim,dim, spazio di colore): crea un imagine usando lo spazio di colore specificato (RGB sempre)
- PImage I = **loadImage("lena.png"):** carica l'immagine lena.png dalla cartella data che si trova insieme allo script
- I.**loadPixels()**: carica i pixel della nostra immagine dentro l'array **I.pixels** 
  per trovare un pixel data la sua posizione nella canvas facciamo in questo modo:
```
int pos(int x, int y, int w){
  return x+y*w;
}
```
- **I.set**(x,y,c): setta il colore c nelle coordinate date
- **I.get(x,y)**: prende il colore
- **red(), blue(), green()**: per dividere le componenti in modo da poter agire in modo diverso per ognuna di queste dobbiamo usare queste funzioni, che ritornano il valore di quella componente nel valore passato
- **image**(I,0,0); : inserisce l'img I dentro la canvas in posizione 0,0
- **Creazione classe**: 
```
class Square {
	float posX;
	Square(float tempPosX){
		posX = tempPosX;
	}
	void display(){...}
}
```
- **Estensione di una classe**
```
  class ColorSquare extends Square{
	  color c;
	  ColorSquare(float tempPosX, color tempColor){
		  super(tempPosX);
		  c = tempoColor;
	  }
	  void display(){
		  fill(color)
		  ...
	  }
  }
```
- **ArrayList Template**: molte volte ci verra chiesto di creare una lista di oggetti con classi padre e figlie, si fa in questo modo:
```
ArrayList<Square> SquareList = new ArrayList<Square>(); // lo tipizziamo con la classe padre
for (Square sq : SquareList) {
    sq.display();
}
```
### Vari filtri
Tutti i filtri presentati di seguito devono essere implementati rispetto ad ogni componente di colore
- **Negativo**: $s = 255 - r$
- **Logartimo**: $s = c \cdot \log(1 + r)$ con $c = \frac{255}{\log(255)}$
- **Gamma**: $s = c \cdot r^\gamma$ con $c = \frac{1}{255^{\gamma-1}}$
- **Quantizzazione** (su un singolo componente di colore se non riechiesto): 
	1. $L' = \lfloor \frac{L \cdot K}{N} \rfloor$
	2. $L_{out} = \frac{L'}{K-1} \cdot 255$
- **Mediano**: scorri l'img in input e per ogni pixel prendi il suo intorno chiami sort e prendi il valore in mezzo
- **Massimo**: scorri l'img in input e per ogni pixel prendi il suo intorno chiami max e prendi il massimo
- **Minimo**: scorri l'img in input e per ogni pixel prendi il suo intorno chiami min e prendi il minimo
### Possibili richieste
- **Bitplane**: un immagine composta dall'iesimo bit
```
...
int bit = (val>>nb)&1; // shifto val di nb posizioni e prendo solo l'ultimo
...
```
- **Replication**: crei un immagine 2 volte più grande e per ogni valore della prima ne crei 4 nella nuova
- **MSE**: $MSE = \frac{1}{n} \sum_{i=1}^{n} (y_i - \hat{y}_i)^2$
- **PSNR**: $PSNR = 10 \cdot \log_{10} \left( \frac{255^2}{MSE} \right)$
### Cose da vedere
- [x] Le implicaizoni delle classi
- [x] Altri filtri
- [ ] Fare gli esami vecchi
- [x] capire che cosa è la quantizzazzione e implementarla
- [ ] Convoluzione
- [ ] Equalizzazione