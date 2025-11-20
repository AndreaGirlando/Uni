# [2] I FONDAMENTI
## 2.1 LEGGI
1. legge vicinanza
	- parti vicine di un insieme tendono ad essere percepite come raggruppate in unità
1. legge chiusura
	- le figure chiuse si vedono più facilmente e tendono a prevalere
2. legge uguaglianza
	- mettere insieme elementi che si assomigliano (colori)
3. legge continuità
	- un insieme di punti posto uno di seguito all'altro tendono a formare una strutture unitaria
4.  legge buona forma
	- forme regolari sono più gradevoli
5.  figure chiuse
	- il cervello tende a chiudere le forme
6. coerenza
	- si tende a fare continuare delle forme nascoste

## 2.2 intensità percepita e illusioni ottiche
l'occhio umano percepisce l'intensità luminosa in modo logaritmico rispetto all'intensità incidente nell'occhio. vale a dire che la luminosità percepita non è semplicemente in funzione dell'intensità emessa.

### Bande di mach
![](Pasted%20image%2020231005085502.png)
data una serie di bande con luminosità costante. il nostro occhio tende a percepirle in maniera non uniforme al tendere dei bordi

### contrasto simultaneo
quello interno ha sempre lo stesso colore, percepiamo di colore diverso
![](Pasted%20image%2020231130172953.png)

## 2.3 rappresentazione immagine
rappresentata da funzione bidimensionale $f(x,y)$

- $x,y$ coordinate spaziali
- $f(x,y)$ : proporzionale alla luce incidente e riflessa
>$$f(x,y)=i(x,y)r(x,y)$$
- i : luce incidente
- r : luce riflessa

#attensionplis  
> f(x,y) è numero reale, ma per rappresentare abbiamo bisogno di valori discreti
> 
> si opera tramite operazioni di **campionamento** e **quantizzazione**

**dominio spaziale**: piano XY in cui si trovano le coordinate dell'immagine
**coordinate spaziali**: le variabili x e y
### 2.3.1 immagini vettorial e raster

#### 2.3.1.1 vettoriali
immagine descritte da un insieme di funzioni **primitive geometriche** (cerchi, quadrati...)

per visualizzarle, il software riceve le informazioni rispetto ai parametri degli oggetti da disegnare

PRO: le trasformazioni sul piano si basano sul cambiamento dei parametri degli oggetti
CONTRO: non fotorealistico ed i formati sono proprietari

#ex"formati"
- pdf (adobe)
- ps (adobesystems) photoshop
#### 2.3.1.2 raster
il valore quantizzato dai sensori viene rappresentato tramite una matrice di pixel (picture element)

##### convenzioni
1. primo elemento matrice in alto sinistra
2. il piano sarebbe il 4° quadrante del piano cartesiano

##### tipi di immagini
1. bianco / nero
	1 bit per pixel => nella posizione i,j ci sarà 0 oppure 1
	![](Pasted%20image%2020231005102748.png)

2. scala grigi
	posizione (i,j) valore tra [0/255]
	![](Pasted%20image%2020231005102918.png)

3. a colori
	in base allo spazio di colore ogni pixel assumera un terna di valori
	$$(x,y,z)$$
	
	nel caso RGB una terna di valori rispetto all'intensità del rosso,verde e blu
	![](Pasted%20image%2020231005103314.png)
# [3] OPERAZIONI SU IMMAGINI E MATRICI 

un immagine raster può essere rappresentata come una matrice
- si potranno fare tutte le operazioni delle matrici (per modifiche varie)

## 3.1 neighborhood
vicinato rispetto ad un pixel (cella della matrice)

1. "4 connessi"
	![](Pasted%20image%2020231005110547.png)
2. "8 connessi"
	![](Pasted%20image%2020231005110617.png)

## 3.2 operazioni affini

operazioni per modificare immagini

2 modi
1. associando matrice caratteristica ed effettuando prodotto riga per colonna
la matrice delle coordinate sarà della forma
$$
(x,y,1)
$$
2. tramite un equazione
### identità
- non fa nulla
![](Pasted%20image%2020231025152210.png)
### scaling
- ingrandisce
![](Pasted%20image%2020231025152226.png)
### rotation
- ruota
![](Pasted%20image%2020231025152242.png)
### translation
- sposta un oggetto
![](Pasted%20image%2020231025152251.png)
### shear vertical
- si "streacha" l'immagine in verticale
![](Pasted%20image%2020231025151723.png)

### shear horizontal
- si "streacha" in orizzontale
![](Pasted%20image%2020231025152324.png)

#### modi di operare

1. forward mapping
"si moltiplica alle coordinate input (v,w) la matrice caratteristica e si ottengono le coordinate di output (x,y)"
![](Pasted%20image%2020231025154442.png)

2. inverse mapping
"si parte dalle coordinate di output per ricavarsi quelle di input iniziali"
![](Pasted%20image%2020231025155139.png)
#attensionplis 
> si possono combinare le operazioni affini, moltiplicando le matrici caratteristiche

## 3.3 ZOOMING IN - interpolazione
data un immagine $M \times N$, applicando uno zoom 2x avremo $2M \times 2N$ quadruplicando i pixel

#attensionplis 
nel corso delle trasformazioni si possono perdere delle informazioni

#ex 
> nello scaling alcuni punti saranno vuoti
> ![](Pasted%20image%2020231025161252.png)

l'interpolazione stima i dati non conosciuti

#### tipi di interpolazione
1. replication / nearest neighbor
prende i valori dei pixel e li replica nei "neighbor"
![](Pasted%20image%2020231025161746.png)
![](Pasted%20image%2020231025162010.png)
**svantaggi**: l'immagine si distorce lungo i lati degli oggetti
**vantaggi**: non introduce valori che prima non erano presenti

2. bilinear
tramite un equazione si definisce una funzione "intensità"
![](Pasted%20image%2020231025171032.png)
i coefficienti (a,b,c,d) sono dati dai quattro pixel più vicini
#ex 
vogliamo sapere cosa mettere nei pixel nell'intorno (0,0) - (2,2)

| 1 | X | 2 | - | 3 |
|---|---|---|---|---|
| X | X | X | - | - |
| 4 | X | 5 | - | 6 |
| 7 | - | 8 | - | 9 |

dobbiamo partire da quello che sappiamo.
$V(0,0) = a \cdot 0 + b \cdot 0 + c \cdot 0 \cdot 0 + d = d \implies d=1 \text{ (valore all'interno della cella)}$
$V(2,0) = a \cdot 2 + b \cdot 0 + c \cdot 2 \cdot 0 + d = 2a + d \implies 2a+d=2$ 
$V(0,2) = a \cdot 0 + b \cdot 2 + c \cdot 0 \cdot 2 + d = 2b +d \implies 2b+d=4$ 
$V(2,2) = a \cdot 2 + b \cdot 2 + c \cdot 2 \cdot 2 + d = 2a + 2b + 4c + d \implies 2a+2b+4c+d=5$

mettiamo tutto a sistema
$$
\begin{cases}
  d = 1 \\
       2a+d=2 \\
  2b+d=4 \\
2a+2b+4c+d=5 
\end{cases}
$$
risolviamo
$$
\begin{cases}
  d = 1 \\
       a=\frac{1}{2} \\
  b=\frac{3}{2} \\
c=0 
\end{cases}
$$
se voglio calcolare ad esempio V(1,1)
$$V(1,1)=a\cdot 1+b\cdot 1+c\cdot 1\cdot 1+d=\left( \frac{1}{2}\cdot 1 \right)+\left( \frac{3}{2}\cdot 1\right)+(0\cdot 1\cdot 1)+1=3$$

| 1 | X | 2 | - | 3 |
|---|---|---|---|---|
| X | 3 | X | - | - | 
| 4 | X | 5 | - | 6 |
| - | - | - | - | - |
| 7 | - | 8 | - | 9 |

#attensionplis 
1. si prendono i 4 pixel più vicini dell'immagine originale
	#ex: nel punto (0,1) si prendono i pixel $(0,0) - (2,0) - (0,2) - (2,2)$
2. nel caso in cui ci sono più di 4 pixel vicini si prediligono i punti con $x,y$ maggiore
	#ex: nel punto (2,1) si prendono i pixel $(2,0) - (2,2) - (4,0) - (4,2)$

3. bicubica
si utilizzano i 16 pixel vicini al punto, la funzione si ottiene tramite la seguente equazione
![](Pasted%20image%2020231025175257.png)
#### interpolazione ai bordi
ai bordi non si hanno i valori sufficienti come negli altri punti

soluzioni
1. non fare nulla, si ricopiano i valori ottenuti
![](Pasted%20image%2020231025175646.png)
2. interpolare con valori minori, meno incognite


## 3.4 ZOOMING OUT - decimazione
data un immagine $M \times N$, applicando uno zooming out di 0,5 avremo $\frac{M}{2} \times \frac{N}{2}$

METODI
1. da 4 pixel se ne sceglie 1
![](Pasted%20image%2020231025180335.png)
2. da 4 pixel si calcola il valore medio
![](Pasted%20image%2020231025180418.png)

## 3.5 stima qualità algoritmo
parametri caratteristici
#ex 
> prendo un immagine faccio varie trasformazioni con diversi algoritmi e poi li stimo tramite questi parametri. in base al risultato capisco qual è il migliore

**Mean square error** (MSE)
> stima errore quadratico medio tra due immagini.
> ***dimmenpo**
> più è BASSO -> minore differenza tra due immagini

**Peak signal to NoiseRatio** (PSNR)
> misura qualità immagine compressa rispetto a quella originale
> ***dimmenpo***
> più è ALTO -> maggiore la somiglianza con originale
> 
> #attensionplis 
> occore sia l'immagine da valutare che la sua versione ottimale
> non è il migliore ma il più diffuso

### come si calcolano?
$I'$ (immagine da valutare)
$I$ (versione ottimale)
$S$ (valore massimo di intensità del pixel)
#### MSE
$$
MSE=\frac{1}{M \cdot N}\sum_{i=1}^{M}\sum_{j=1}^{N}(I(i,j)-I'(i,j))^2
$$
#### PSNR
modi equivalenti:
![](Pasted%20image%2020231025181118.png)
better:
$$
PSNR = 10 \cdot \log_{10}\left( \frac{S^2}{MSE} \right)
$$
### come si usano in RGB?
2 modi:
1. media tre canali di colore
2. combinazione lineare che da un peso maggiore al verde

# [4] SENSORI E BAYERN PATTERN
## 4.1 acquisizione immagini digitali
quando la luce colpisce un oggetto, una parte viene assorbita ed una parte riflessa

quella riflessa da origine al colore percepito

per creare un immagine digitale è necessario catturare la luce riflessa **con un sensore** ed elaborarla

![](Pasted%20image%2020231026001153.png)

## 4.2 il sensore
l'energia che colpisce il sensore è trasformata in un impulso elettrico, il quale viene successivamente digitalizzato
![](Pasted%20image%2020231026001322.png)

### esempi sensori
1. singoli
EX: scanner
singolo sensore che viene spostato lungo la sorgente
![](Pasted%20image%2020231026001457.png)
2. in linea
EX: macchina per fare TAC
disposti in un unica linea
![](Pasted%20image%2020231026002103.png)
3. 2D array
EX: macchine fotografiche
sensori disposti in una matrice, non è necessario spostare il sensore


i più diffusi sono i **CCD** (charged couples device)
> se colpiti da fotoni assumono carica positiva
> non possono caricarsi oltre un certo limite
> il numero di celle identifica la qualità del sensore (misurata in MEGAPIXEL)
> 
> dopo che le cariche sono acquisite vengono digitalizzate in $n$ (numero colonne) fasi 
> 	
> durante ogni fase
> 	![](Pasted%20image%2020231026002648.png)

## 4.3 Color filter array (CFA)
in quanto ogni cella memorizzerà un solo colore, occorre scegliere un modello di memorizzazione ottimale (CFA)
- scegliendo un filtro di colore apposito da posizionare davanti al sensore

tramite interpolazione verranno scelti i colori dei pixel vicini

### Bayern pattern
è il più usato
- dispone i pixel verdi nelle diagonali (più importante per la percezione umana) e poi si procede interpolando
![](Pasted%20image%2020231026003327.png)

senza un algoritmo sarebbero disposti a mosaico. Per avere una percezione reale del colore, per ogni cella sarà necessario la terna (RGB)

#attensionplis 
conservata nel formato raw
#### color interpolation
detto anche "demosaicking"
1. replication / nearest neighbor interpolation
> ![](Pasted%20image%2020231125204528.png)

2. bilinear
> per la cella che ha il rosso 
> ![](Pasted%20image%2020231027140240.png)
> per la cella con il blu
> ![](Pasted%20image%2020231125205408.png)
> 
> per la cella con il verde
> ![](Pasted%20image%2020231125205446.png)
# [5] LA RISOLUZIONE

## 5.1 definizione
numero di pixel per unità di misura

indica il grado di qualità di un immagine

#attensionplis 
> il computer non può rappresentare linee ma solo punti. Se sono sufficientemente piccoli l'utente avrà la percezione di star vedendo linee

diverse unità di misura
1. pixel al centimetro
2. dots per inch (dpi)
3. numero di pixel su tutta l'immagine ( #ex 16MEGAPIXEL )

## 5.2 apparecchiatura di resa e ripresa

il concetto di risoluzione è relativo, varia a seconda dell'apparecchiatura (ripresa o resa)

si contano quanti sensori ci sono per unità lineare di misura

**RIPRESA**
- SCANNER [6000dpi e oltre]
- FOTOCAMERE []

**RESA**
- STAMPANTI [3000dpi e oltre]
- SCHERMI [72dpi]

**RISOLUZIONE STANARD STAMPE**
- quotidiano 75dpi
- riviste 133dpi
- brochure 175dpi
- libri fotografici 2400dpi

#ex 
immagine originale ha 2m diametro

> ![](Pasted%20image%2020231027134351.png)
> 200pixel di larghezza
> 1dot per 1cm = 200pixel per rappresentazione reale
> 
> $200 \times 200 \times 24\text{bit} = 960\,000\text{bit}$ per memorizzazione

#attensionplis 
> un immagine nata con una certa risoluzione dovrà essere visualizzata con la stessa

> STANDARD
> ![](Pasted%20image%2020231027134720.png)

# [6] L'OCCHIO

a noi interessa la retina
## 6.1 la retina
membrana che ricopre la parte posteriore dell'occhio
![](Pasted%20image%2020231030111710.png)
formata da **coni** e **bastoncelli** (fotorecettori)

**CONI**
![](Pasted%20image%2020231030112048.png)
> 6/7 milioni
> concentrati in una zona centrale della retina (fovea)
> 
>**molto** sensibili al colore
> ogni cono è collegato ad un nervo ottico specifico
> 
> ***cheffanno?***
> responsabili della vista fototica o policroma (visione a colori)

**BASTONCELLI**
> 75/150 milioni (sono di più -> più importanti)
> distribuiti su tutta la retina
> 
> **poco** sensibili al colore
> collegati ad UN nervo ottico a gruppi
> 
> ***cheffanno?***
> sensibili alla luce
> responsabili della vista **scotopica**/monocroma: vedi luminosità / macchie /aloni

quantità di fotorettori nella retina
> coni sono prevalentemente nella parte centrale (fovea: regione di 1,5 x 1,5 mm)
> 
> bastoncelli si distribuiscono nelle aree laterali
> ![](Pasted%20image%2020231030121044.png)

#attensionplis 
1. fovea parte centrale della retina (1,5mm x 1,5mm)
2. la fovea ha circa $150.000$ coni per $\text{mm}^2$ =>circa $337.500$ totali

## 6.2 formazione immagine
a noi arriva l'immagine capovolta ma poi viene elaborata
![](Pasted%20image%2020231030122654.png)

per comprendere questo principio esiste il **modello pinhole**
![](Pasted%20image%2020231030123710.png)
![](Pasted%20image%2020231030123200.png)

il pinhole ideale ha il seguente raggio $r=\sqrt{ \lambda d }$
- $\lambda$ [frequenza lunghezza d'onda] (nella realtà entra luce di tutti i tipi => lunghezze d'onda diverse. quindi non )
- d [distanza buco - sensore]

#attensionplis 
> nella realtà non possiamo rappresentare un punto ma un figura geometrica, ma produciamo un'area (POINT SPREAD FUNCTION)
> 
> ![](Pasted%20image%2020231030123919.png)


## 6.3 La lente sottile
oggetto fisico che permette di deviare la luce (onde elettromagnetiche)
- se costruite opportunamente possiamo decidere la direzione

definita da proprietà geometrica
![](Pasted%20image%2020231030144533.png)
1. i raggi paralleli alla lente vengono concentrati in un unico punto **fuoco** posto a distanza f dalla lente
![](Pasted%20image%2020231030144500.png)
2. i raggi che partono dal fuoco vengono ri-trasmessi in parallelo
3. una lente sottile ha 2 fuochi equidistanti

#attensionplis 
> il punto in cui si reincontrano i raggi si forma l'immagine
> 
> in base a dove si mette la lente alcuni oggetti saranno sfocati rispetto ad altri

#attensionplis nell'occhio come funziona
> alcuni muscoli deformano il cristallino, facendo cambiare la posizione dei fuochi

## 6.4 equazione lente sottile
elementi equazione
- "u": distanza tra punto che emette il raggio di luce e la lente
- "f" (distanza focale): distanza fuoco lente
- "v": distanza tra piano dei sensori / pellicola dove si forma l'oggetto e la lente
- "k": distanza tra raggio parallelo e centro
- "h"

equasion:
$$
\frac{1}{u}+\frac{1}{v}=\frac{1}{f}
$$

nell'occhio cambia la variabile "u" ed "f"
- f cambia deformando il cristallino

nelle macchine fotografiche cambia "u" e "v"
- la lente viene prodotta con un fuoco preciso che non può essere cambiato, quindi si opera muovendone la posizione "v"

#attensionplis 
$$
\text{1 diottria} = \frac{1}{f}
$$

## 6.5 magnificazione
fattore magnificazione
$$
\frac{h}{k} = \frac{v}{u}=m
$$

fuoco con un certo fattore di magnificazione
$$
f=\frac{u \cdot m}{m+1}
$$
# [7] CAMPIONAMENTO E QUANTIZZAZIONE
## 7.1 intro
segnale continuo: la variabile indipendente può assumere infinita di valori 
segnale discreto: segnale che assume valori finiti in intervalli di tempo

#attensionplis occore scegliere valori discreti per rappresentare un immagine

#ex digitalizzare i colori della seguente immagine
![](Pasted%20image%2020231026095718.png)

1. campionamento: suddividiamo in intervalli di valori
> si analizza da sx -> dx
> più alto-> più bianco
![](Pasted%20image%2020231026100346.png)
2. suddivisione intervalli
![](Pasted%20image%2020231026095909.png)
3. quantizzazione
> per ogni intervallo si sceglie un valore (sono infiniti)
![](Pasted%20image%2020231026095924.png)

## 7.2 Errori di campionamento
con un campionamento troppo basso (si prendono intervalli larghi) si va in contro alle seguenti problematiche
1. perdita dettagli
> certe volte necessario per esigenze di spazio nel database
> 
> #ex fotografo una persona distante (5pixel) pochi dettagliata

2. riproduce elenti non presenti
> il segnale viene alterato e cambiato in altro "**aliasing**"
> 
> #ex formazione pattern

## 7.3 Come si sceglie il giusto campionamento
"come faccio a capire con quanti valori posso rappresentare fedelmente l'intero segnale"

METODI
1. si prende l'intervallo più piccolo e si campiona l'intero sengnale in intervallo di tale dimensione
2. ***teorema di Shannon***

Il teorema di Shannon si basa sulla misura del **Nyquist Rate**
### nyquist rate
si definisce il ***doppio della più alta frequenza*** ($2N$) di un segnale continuo e limitato

#attensionplis 
> bisogna prendere ALMENO il doppio dei campioni. maggiori saranno più sarà fedele il segnale

#attensionplis 
> segnale limitato: somma di un numero finito di sinusoidi

#attensionplis 
> la "**frequenza del segnale**" nelle immagini è la variazione di intensità luminosa tra pixel successivi

#### come si calcola la frequenza
si prende il segnale e si vede se è costante

se non lo è si divide ancora

si procede a dividere fino a quando non si ha la funzione costante

il numero di divisioni sarà uguale alla frequenza

#ex 
> frequenza più alta: 400
> 
> nyquist rate: $2\cdot N=2\cdot 400=800$
> 
> si divederà il segnale in 800 intervalli
> ![](Pasted%20image%2020231026103039.png)

#ex 
> con quanti colori si può rappresentare un immagine grigia?
> 
> se ne scelgo uno sarà solo grigia.
> 
> man mano aumento più sarà accentuato il dettaglio
## 7.4 Campionamento
**campionamento**
> partendo da un segnale continuo ne formo uno discreto
> 
> bisogna scegliere un numero finito di campioni

#ex "campionamento di un immagine"
si vanno a vedere i tratti che la compongono
![](Pasted%20image%2020231031113457.png)

### campionamento corretto

$$\text{campionamento}=\frac{\text{numero pixel}}{\text{tratto}}$$
#ex 
> immagine 720x720pixel
> tratti 4pixel
> 
> $N=\frac{720}{4}=180$
> per il nyquist rate è ottimale avere $2N$ =>$180\cdot 2=360$
> 
> allora campioneremo l'immagine in modo tale da avere 360 campioni su cui andremo ad applicare interpolazione lineare ([[#tipi di interpolazione]])

#attensionplis quando si parla di campionamento si intende la risoluzione dell'immagine

#ex
> immagini a diversi campioni/risoluzioni e poi ingrandite per notare le differenze
> 
> 240campioni non si rispetta nyquist -> si perdono dettagli
> 120campioni sotto nyquist -> bad Quality
> ![](Pasted%20image%2020231026105144.png)

### Aliasing
se si campiona sotto il nyquist rate possiamo imbatterci in perdite di dettagli ma anche all'**aggiunta di dettagli non presenti.** Questo fenomeno prende il nome di
"frequency aliasing o aliasing"

aliasing: le frequenze alte sono mascherate da basse frequenze

#ex 
> perdita di dettagli
> 
> nei momenti in cui le frequenze sono basse, campionando male le abbiamo perse
> ![](Pasted%20image%2020231031120846.png)

#ex 
> nuovi dettagli
> 
> i graffi non si notano più
> sono apparsi nuovi buchi sulle rocce
> ![](Pasted%20image%2020231031120936.png)

### effetto Moirè
effetto che si genera durante la digitalizzazione sovrapponendo 2 serie di linee o pattern creandone un ulteriore che sembra avere dei motivi distorti

#ex quando si fotografano tessuti a righe, recinzioni, griglie, ecc...

**CAUSA**
è causato dall'interferenza tra linee/pattern irregolari con la griglia di pixel su uno schermo o sul sensore di una fotocamera. Queste non si allieano creando l'illusione di one o cerchi

che si fa?
1. minimizzare disallinamento sensore - oggetto, modificando l'angolo di scatto
2. filtri anti-moirè
3. post elaborazione con software
![](Pasted%20image%2020231031122108.png)

### distorsione animazioni - wagon whell
presa un animazione (gif) in base al numero di campioni può essere cambiata totalmente

![](king.gif)

la ruota gira così tanto che non riusciamo a vedere il giro completo ma lo vediamo a tratti sembrando che vada indietro

## 7.5 Quantizzazione

i sensori sono apparecchiature analogiche. Forniscono misure di luminosità sottoforma come numeri reali.
- è necessario mappare certi valori per mantenerli in un certo range

**DEF CRINGIATA**
> processo di mappatura dei valori in ingresso analogici da un insieme non limito ad uno limitato
> 
> #ex mappatura del segnale in 8bit
### rumore
durante il passaggio da continuo a discreto avviene una perdita di precisione.
i motivi principali si possono ricondurre a:
1. difetti sensore
2. perturbazioni termiche
> il sensore durante l'uso si surriscalda producendo uno sbalzo termico, facendo avvertire una maggiore intensità luminosa nell'immagine (che però non c'è)

#attensionplis 
> anche quando l'obiettivo di un CCD (Charge coupled device => fotocamera) è chiuso potrebbero verificarsi delle correnti che inducono rumore "**dark current**"

#attensionplis ogni fotocamera produce un pattern di rumore termico, tramite questo si potrebbe identificare il dispositivo di scatto

### procedura di quantizzazione
Sia $]a,b[$ il range in cui si vuola quantizzare il segnale su $n$ livelli

si fissano $n+1$ numeri $(t_{0}, t_{1}, t_{2}, \dots, t_{n})$ in $]a,b[$ tali che rispettino la seguente relazione
$$a=t_{0}<t_{1}<t_{2}<\dots<t_{n}=b$$
il numero ***x*** da in $]a,b[$ verrà assegnato al livello di quantizzazione ***k*** se risulta
$$t_{k} \leq x < t_{k+1}$$
#ex
> img scala grigi
> 
> $a=0<1<2<\dots<255$
> 
> cerco di trovare il valore in cui inserire "127,32"
> 
> $127<127,32<128$
> 
> lo vado ad inserire nel livello $t_{127}$

![](Pasted%20image%2020231107160154.png)
**COME SI RAPPRESENTANO IN MEMORIA?**
le etichette di ogni livello verrano rappresentate tramite bit
$$\text{numeroEtichette}=\log_{2}(\text{numeroLivelli})$$

#attensionplis 
> qui stiamo parlando solo di ripartire i valori in un insieme limitato. l'uso che ne faremo in seguito sarà indifferente
> 
> #ex
> audio: variazioni energia pressione
> img: variazione colori

#ex"segnale quantizzato"
> se il segnale si mantiene all'interno del livello verrà riprodotto come costante.
> 
> nel momento in cui entra in un altro livello varia
> ![](Pasted%20image%2020231107160821.png)

### tipi di quantizzazione
a seconda dell'uso possiamo definire 2 tipi di quantizzazione

1. uniforme
> uniforme: differenza tra $t_{k}\text{ e }t_{k+1}$ sempre uguale
> 
> $1<2<3<\dots<n$
> 
> ![](Pasted%20image%2020231107165507.png)

2. non uniforme
> alcuni range di livello sono più precisi di altri
> 
> #ex
> 	i primi intervalli sono molto precisi tra loro.
> 	gli ultimi 2 comprendono un range molto ampio, questo causerà una perdita importante di precisione.
> 	$10<20<30<420<10^8$
> 	
> 	![](Pasted%20image%2020231107165522.png)


**QUANDO SI USANO?**
nelle macchine digitali o negli scanner moderni è usata principalmente la quantizzazione **non uniforme e logaritmica**

> uniforme
> 	tutti i segnali hanno lo stesso range
> 	non tutti i dettagli vengono percepiti
> 	le parti più scure non si vedono
> 
> logaritmica
> 	le parti più scure vengono rese più visibili grazie ad un maggior numero di livelli a quella frequenza
> 	
> 	nelle frequenza alte notiamo un appiatimento che causa perdita di precisione (non vediamo la fiamma)
> 
> ![](Pasted%20image%2020231107165726.png)

### formule quantizzazione

**UNIFORME**
si fa la proporzione
$$
L'=\lfloor\frac{L \cdot K}{N}\rfloor
$$
$L$ = livello di ingresso (valore)
$L'$ = livello di uscita
$N$ = range ingresso
$K$ = range uscita

#attensionplis 
>si prende la parte intera arrotondando per difetto (floor)

#ex
> $$
> 0 : 255 = x : 7
> $$
> se voglio inserire il valore 10:
> $$
> 10:255=x:7\implies x=\frac{70}{255}\implies \lfloor x \rfloor=0
> $$

NON UNIFORME

$$
L'= f(L,N,K)
$$
$L'$ è in funzione dei 3 valori, l'implementazione definisce lo schema di riquantizzazione
( #ex logaritmica) 

LOGARITMICA 

$$
L' = \lfloor\frac{\log_{2}(L) \cdot K}{N}\rfloor
$$
### riquantizzazione
se voglio passare da un certo numero di livelli ad un altro (inferiore di solito).

#attensionplis 
> nel caso di superiore non ha senso.
> ha senso solo se si vogliono fare operazioni dopo con massima precisione

#ex "riquantizzazione immagine 2x2"
immagine con 256 livelli di grigio
$$k_{old}=256$$
voglio passare a 16 livelli 
$$k_{new} = 16$$
immagine_old

| 200 | 34  |
| --- | --- |
| 15  | 1   |

per ogni livelli si applica la seguente formula
$$f(\text{valoreLvl}_{\text{new}}, k_{\text{new}},k_{\text{old}})=\lfloor\frac{\text{valoreLivello}_{\text{old}}\cdot k_{\text{new}}}{k_{\text{old}}}\rfloor$$

immagine_new: 

| 12 | 2  |
| --- | --- |
| 0  | 0   |

RIQUANTIZAZZIONE LOGARITMICA
$$f(\text{valoreLvl}_{\text{new}}, k_{\text{new}},k_{\text{old}})=\lfloor\frac{\log_{2}{(\text{valoreLvl}_{\text{new}})}\cdot k_{\text{new}}}{\log_{2}{(k_{\text{old}})}}\rfloor$$

# [8] COLORE

## 8.1 cos'è il colore?
il concetto di colore è legato alla lunghezza d'onda, ovvero lo spazio percorso dall'onda in un tempo pari al periodo (tempo tra un oscillazione e la successiva)
![](Pasted%20image%2020231107173057.png)
#ex 
> più lungo -> più verso rosso
> lento -> verso viola

#attensionplis spettro visibile tra violetto e rosso

la luce è formata dalle lunghezze d'onda percepite dall'occhio umano

lo spettro visibile oscilla tra violetto e blu
> diviso in 6 regioni: violetto, blu, verde, giallo, arancio e rosso
> 
> le bande di colore non sono tutte della stessa lunghezza, degradano nelle zone limitrofe
> ![](Pasted%20image%2020231107173445.png)

## 8.2 Come percepisce il colore l'occhio?
l'occhio umano percepisce solo una piccola porzione dello spettro elettromagnetico.

inoltre percepisce come colore di un oggetto la sua luce riflessa
- riflette lunghezze d'onda luminosa: oggetto percepito come bianco
- lunghezze d'onda 500 a 570: verde

## 8.3 fattori che descrivono la luce
sono dei valori

**radianza**: quantità luce emessa dalla sorgente luminosa

**luminanza**: energia percepita dall'utente

**brillantezza**: soggettivo, indica quanto è puro un colore (chiaro / scuro)

## 8.4 i coni
all'interno della retina ci sono 3 tipi di coni

1. TIPO S: Sensibili alle lunghezze d’onda corte (short, colori bluastri)
2. TIPO M: Sensibili alle lunghezze d’onda medie (middle, colori verdastri)
3. TIPO L: Sensibili alle lunghezze d’onda lunghe (long, colori rossastri)

#attensionplis tutti i primati hanno questi 3 tipi

> lunghezze d'onda di attivazione dei vari coni
> ![](Pasted%20image%2020231107175120.png)

## 8.5 come si misura il colore?
a differenza di lunghezza o peso, non esiste una scala fisica per misurare il colore. si basa tutto sulla percezione / interpretazione soggettiva

#attensionplis
> non esistono colori reali ma solo acquisiti

la percezione si basa su diversi fattori come: luce, oggetti, occhi e cervello osservatore

### differenze di colore
certe differenze tra colori sono date da particolari condizioni

1. differenti **sorgenti luminose**
> lampadine, luce solare, ...
2. differenti **osservatori**
> sensibilità, vista, ...
3. differenti **dimensioni**
> "effetto area": i colori che ricoprono vaste aree appaiono più luminosi e vivaci
4. differente **sfondo**
> "effetto contrasto": oggetti appaiono più scuri se lo sfondo è più scuro
5. differente **direzione**
> "oggetto cangiante": può riflettere colori diversi a seconda da dove lo guardi

## 8.6 sintesi ADDITIVA
qualunque colore può essere ottenuto come somma di tre **luci monocromatiche agenti simultaneamente** (colori)

#attensionplis 
> esiste la "TEORIA DEL TRISTIMOLO" secondo cui ogni colore può essere dato dalla somma di 3 colori.
> 
> si è scoperto che è falso, non si possono rappresentare tutti

la CIE (Commission Internationale de l'Éclairage) è l'ente responsabile della ricerca nel campo dei colori e illuminazione.

la CIE ha scelto 3 radiazioni primarie
![](Pasted%20image%2020231107180152.png)

## 8.7 sensibilità spettrale occhio
la sensibilità spettrale (ai colori) dell'occhio umano è dato da 3 Variabili (X,Y,Z)

"per capire che intensità di colore ha un segnale, si fa il prodotto punto a punto tra il segnale da misurare e l'onda di riferimento di un certo colore"

#attensionplis 
>si capisce l'intensità in termini assoluti

> $L_{e}(\lambda)=\text{lunghezza d'onda da misurare}$
> $\bar{x}(\lambda)=\text{onda di riferimento del rosso}$
> 
> $780 - 380=\text{frequenza in cui si può trovare il rosso}$
> 
> con l'integrale si va a calcolare l'area di quella regione sottesa
> 
> $$X=\int^{780}_{380}{L_{e}(\lambda)\bar{x}(\lambda)\, d\lambda}$$

stessa cosa per il verde e blu
![](Pasted%20image%2020231107180924.png)
![](Pasted%20image%2020231107180914.png)

## 8.8 Dati colorimetrici
il colore che percepiamo è dato da diversi fattori
> ![](Pasted%20image%2020231114150948.png)
> 	1. distribuzione energetica della luce che lo illumina
> 	2. curva spettrale dell'oggetto illuminato
> 	3. percezione al colore dell'occhio umano

### misurazioni del colore
il colore può essere osservato in maniera differente a seconda del soggetto che effettua il campione

1. occhio umano
> ![](Pasted%20image%2020231114151225.png)
> la retina riceva la luce riflessa dall'oggetto e la invia al cervello, il quale identifica il colore in base alle informazioni che gli arrivano

2. colorimetro
> ![](Pasted%20image%2020231114153059.png)
> simil fotocamera
> 
> dotato di sensori con filtri che accettano solo alcune lunghezze d'onda (ex: RGB) i quali inviano le informazioni ad un microprocessore
> 
> il microprocessore (embedded) effettua un calcolo numerico e restituisce
> 
> **OUTPUT**
> valori finiti (in base alle informazioni inviate dai sensori)

3. spettrofotometro
>![](Pasted%20image%2020231114153034.png)
>1. oggetto viene illuminato da luce allo Xenon (luce che illumina in maniera uniforme).
>2. la luce riflessa viene raccolta da un insieme di lenti
>3. questa viene divisa in lunghezze d'onda (funzione)
>
>
> **OUTPUT**
> 2 tipi di output
> 
> 4. valori numerici
> 5. il sensore restituisce un intero spettro di valori (somma finite onde sinusoidali in cui ognuna da un contributo diverso)
> 	#ex funzione continua dell'integrale di prima


#attensionplis " l'illuminazione cambia il colore "
> - quando guardiamo un colore con occhio umano lo facciamo con la luce esterna che lo illumina
> - nello spettrofoto. si illumina l'oggetto con una particolare luce che lo illumina uniformemente


### illuminante
energia radiante, con distribuzione spettrale di energia relativa, definita nel campo di lunghezze d'onda capace di influenzare la visione del colore degli oggetti
- luci che permettono di misurare in maniera ottimale il colore

ILLUMINANTE CIE (standard)
illuminante D65
- D = daylight
- 65 = luce che emette il corpo nero quando esposto a 65k kelvin
- simula luce del sole (mezzogiorno equatore senza nuvole nel cielo)

#attensionplis D65 è l'illuminante di rgb

### angolo di visione
in base all'angolo da cui si guarda un oggetto cambia la percezione del colore

standard
> CIE 1931
> 	inferiore 4 gradi 
> 	oggetti vicini
> 	standard per beni culturali
> CIE 64
> 	superiore a 4 gradi
> 	oggetti lontani
> 	standard oggetti architettonici, affreschi da vedere da lontano

per calcolare il valore spettrale in base ad un certo illuminante si può usare la seguente formula
 
> variazione dell'integrale per misurazione spettrale (si aggiunge il parametro dell'illuminante) 
> $S$: illuminante
> $R$: lunghezza d'onda input
> $$
> X = K\int^{780}_{380} S(\lambda)\bar{x}(\lambda)R(\lambda) \, d\lambda 
> $$
> $$
> Y = K\int^{780}_{380} S(\lambda)\bar{y}(\lambda)R(\lambda) \, d\lambda 
> $$
> $$
> Z = K\int^{780}_{380} S(\lambda)\bar{z}(\lambda)R(\lambda) \, d\lambda 
> $$
> per normalizzare i valori otteunti dagli integrali si fa il rapporto tra 100 e l'integrale
$$
 K=\frac{100}{\int^{780}_{380} S(\lambda)\bar{y}(\lambda)\, d\lambda}
 $$

nel 1931 il CIE ha fissato le lunghezze d'onda standard per i colori primaria
> Blue = 435,8 nm
> Verde = 546,1 nm
> Rosso = 700 nm

anche se sperimentazioni hanno dimostrato che i dati effettivi sono questi
> Blue = 445 nm 
> Verde = 535 nm
> Rosso = 575 nm

### diagramma di cromaticità CIE 1931 "xyz"

siano
> x = quantita rosso
> 	$$x=\frac{X}{X+Y+Z}$$
>
>y = quantità verde
> 	$$y=\frac{Y}{X+Y+Z}$$
> 
>z = quantità blu
>	$$z=\frac{Z}{X+Y+Z}$$

#attensionplis 
>se hai già determinato due quantità di colore per ottenere la terza si possono utilizzare le seguenti formule:
> $$
> x=1-y-z
> $$
> $$
> y=1-x-z
> $$
> $$
> z=1-x-y
> $$ 

#attensionplis 
>$x,y,z$ sono in percentuale (valore compreso tra 0 e 1)


al variare di x e y si da origine al diagramma cromatico CIE
> valori lunghezza d'onda disposti lungo i bordi.
> 
> il punto in cui i colori hanno la stessa energia è bianco.
> ai bordi i colori non hanno bianco (puro).
> ![](Pasted%20image%2020231114160553.png)

#attensionplis 
1. unendo 2 colori con una linea => tutti i possibili colori ottenibili mischiandoli
2. unendo un colore al bianco => tutte le sfumutare

#attensionplis "COLOR GAMUT"
> vedendo questo grafico si dimostra che teoria tristimolo falsa, non esiste un triangolo che lo racchiude interamente
> 
> l'area dentro rappresenta i colori che può stampare una stampante
> ![](Pasted%20image%2020231114094712.png)

### modello di colore
lo scopo di un modello del colore è di consentire la specificazione dei colori con modalità standardizzate che fanno riferimento ad un sistema di coordinate 3D


#ex
1. RGB, CMY (orientati all'hardware di acquisizione e restituzione)
2. YUV, YIQ (trasmissione, compressione)
#### difetto sistema CIE
non è dotato di uniformità percettiva
- date due coppie di punti e la stessa distanza ($\Updelta$) tra loro, la differenza che percepiamo non sarà uguale

dopo diversi anni la CIE ha standardizzato 1976 due spazi di colore **percettivamente uniformi**
1. CIE $Luve$
2. CIE $LAB$

#### spazio CIE LAB
spazio di colore percettivamente uniforme

caratterizzato da 3 parametri
>1. "L": luminanza (contributo energetico generale)
>2. "a / b": coordinate di cromicità
>   
>   a = variazioni blu e giallo
>   b = variazioni verde rosso

le differenze di colore sono definite come distanza tra due punti dello spazio

#ex:CIE $La^*b^*$
> $\Updelta E = \sqrt{ (\Delta L)^2 + (\Delta a)^2 + (\Delta b)^2}$
> ![](Pasted%20image%2020231114165658.png)
> 
> $$
> C_{1}=(10,20,30)
> $$
> $$
> C_{2}=(11,21,31)
> $$
> 
> $$
> \Delta E = \sqrt{ (10-11)^2 + (20-21)^2 +(30-31)^2}=\sqrt{ 1+1+1 } = \sqrt{ 3 }
> $$


#attensionplis "a che serve"
> questi valori vengono usati nella realtà per avere degli standard da seguire nella relizzazione cromatica di certi prodotti, definendo un calcolo dell'errore
	 - #ex rosso ferrari = 0,01 valore errore MAX

#attensionplis "i grigi"
> i grigi si ottengono con $a=b$ e modificando il valore $L$

#attensionplis "geometria dello spazio LAB"
>rappresentabile tramite una serie di cerchi che si sviluppano in altezza.
>	l'altezza nella quale si trova ogni cerchio corrisponde alla luminanza
>	all'interno di ogni cerchio si individuano le coordinate $a,b$
#### spazio LCH
in quanto si sta lavorando all'interno di una sfera, al posto di usare coordinate cartesiane si utilizzare le coordinate polari (usando modulo e angolo)

$l$ = componente di luminanza
$c$ = componente cromatica (il colore puro effettivo)
$h$ = tinta (variazione del colore)

#ex 
>croma = rosso puro
>tinta rosso = colore che si ottiene aggiungendo sometin al rosso 

chroma
>![](Pasted%20image%2020231115161936.png)

tinta / hue
> ![](Pasted%20image%2020231115161943.png)


### bianco e nero

il bianco ed il nero sono valori che nella realtà non esistono

si dovrebbero avere dei valori
- $X,Y,Z=1$ nel caso del bianco
- $X,Y,Z = 0$ nel caso del nero
## 8.9 gli spazi di colore
in natura non vediamo colori puri ma miscele di radiazione luminosa

in quanto il nostro cervello non è uno spettrometro percepiamo le stesse sensazioni cromatiche anche con un cambio di illuminazione

#attensionplis 
>ogni lunghezza d'onda trasporta differenti quantità di energia
>
>l'energia totale è data dalla somma di tutti i contributi dalle diverse lunghezze d'onda

### spettro di un illuminante
diagramma dei contributi di energia che apporta per ciascuna lunghezza d'onda

![](Pasted%20image%2020231115162909.png)

### metameri
se due coppie di spettri diversi producono la stessa sensazione di colore si chiamano **metameri**
#ex
>i due spettri producono nel cervello lo stesso colore
>![](Pasted%20image%2020231115163039.png)

#### modello del pittore
ogni spettro è dotato di un metamero caratteristico
![](Pasted%20image%2020231115163210.png)
una funzione costante che ha un picco nel punto (lunghezza d'onda) in cui il colore è percepito

emedia: responsabiile del contenuto energetico della radiazione

#attensionplis 
>il rapporto tra $$\text{saturazione} = \frac{e_{\text{picco}}-e_{\text{media}}}{e_{\text{picco}}+e_{\text{media}}}$$
>saturazione = quanto un colore è puro
##### modello del pittore
ogni colore può essere rappresentato tramite un triangolo
![](Pasted%20image%2020231115163546.png)

mettendo assieme i triangoli per ogni colore (HUE) si ottiene lo **"spazio HSV"**

### spazio HSV
![](Pasted%20image%2020231114112042.png)

### altri spazi
1. ruota dei colori
>    organizza spazio colorato in schema simmetrico

2. MUNSELL (HCV)
> colloca i colori in spazio tridimensionale
> ![](Pasted%20image%2020231115163857.png)
> ![](Pasted%20image%2020231115163944.png)
### discussione sul modello del pittore
pro
- intuitivo
- rispetto alla nostra percezione assume un significato (RGB tutto cringiato)

contro
- modello non lineare
- ci sta una piramide esagonale


## 8.10 sintesi additiva vs sottrattiva
queste due sintesi si basano sulla sovrapposizione di filtri di colore che assumeranno il colore prodotto dalla radiazione complementare di quella che viene assorbita
### sintesi additiva
si parte dalla terna RGB come colori primari (RGB)
![](Pasted%20image%2020231129152538.png)
in questa sintesi i colori: giallo, magento, ciano si possono chiamara secondari

#### da chi viene usata?
su questo principio si basa il funzionamento di monitor e schermi televisivi

#### colori complementari
sia c1,c2 dei colori. c2 sarà complementare di c1 nel caso in cui $c1 + c2$ produce il bianco

$$
R + G + B = W
$$
$$
R+G=Y\implies Y+B=W \text{ (giallo complementare blu)}
$$
$$
R+B=M\implies M+G=W \text{ (magenta complementare verde)}
$$
$$
G+B=C\implies R+C=W \text{ (ciano complementare rosso)}
$$

#ex 
	qual è la terna che sommata a $(200,255,15)$ risulta bianco
	$(200,255,15) + (55,0,240)=(255,255,255)$

### sintesi sottrattiva
dalla loro sovrapposizione, in quanto tutta la radiazione viene assorbita si produrrà il nero

sovrapponendo due filtri si ottiene la componente luminosa che non viene assorbita

si compongono 3 colori
$$
Y+M+C=K_{\text{nero}}
$$
![](Pasted%20image%2020231129155221.png)
#### quando viene usata?
su questo principio si basa la riproduzione delle immgini colorate nella fotografia a colori

![](Pasted%20image%2020231129160132.png)
## 8.11 colori primari e secondari

>i colori primari non sono definiti in maniera assoluta ma in base all'illuminante

### rgb
se ogni colore si ottiene mischiano altri 3 fondamentali si andrà a formare un cubo
ogni colore è un punto dentro il cubo
![](Pasted%20image%2020231129160619.png)

PRO
- semplice da usare (standard)

CONTRO
- percettivamente non comodo, in natura non sappiamo i vari contributi di rgb

### colori sicuri per il web
a parita di hardware non tutti i sistemi oeprativi processano i colori allo stesso modo

> 40 su 256 processati in maniera differente

i restanti 216 si
- questi sono diventati standard "colori sicuri"

formati da 3 valori RGB composti da 2 numeri esadecimali
- 00 - 33 - 66 - 99 - CC - FF

## 8.12 rappresentazioni luminanza crominanza
gli spazi di colore, nei quali una componente è la luminisità e le altre due sono legate alla crominanza, vengono chiamati "rapressentazioni luminanza - crominanza"

1. importanti per la compressione delle immagini
2. l'occhio umano è più sensibile alla luminisità che ai colori (all'interno della retina abbiamo una quantità maggiore bastoncelli rispetto che ai coni che si occupano della vista policroma)

### spazio YUV
famiglia di spazi usati per la codifica di immagini o video **analogici** che tiene separata la componenti di luminanza e crominanza

spazio Yc<sub>b</sub>c<sub>r</sub> è una controparte digitale di YUV

## 8.13 da RGB a YUV
la luminanza può essere ottenuta con una combinazione lineare delle intensità luminose dei canali RGB

### calcolo Y

$$
Y=0,299R + 0,587G+ 0,114B
$$
#attensionplis 
1. per ricordare
$$
Y = 0,300R+0,590G+0,120B
$$
2. questa è una media pesata, il verde assume un peso maggiore in quanto il nostro occhio ne è più sensibile

### calcolo U e V
si associa un peso alla differenza tra (Blu e Y) e (Rosso e Y)ù
$$
U = 0.564(B-Y)
$$
$$
V=0.713(R-Y)
$$

#attensionplis 
>nel caso in cui R=G=B ovvero i grigi U e V saranno uguali a zero. i grigi hanno crominanza 0

## 8.14 YUV a YC<sub>b</sub>C<sub>r</sub>
YC<sub>b</sub>C<sub>r</sub> è una controparte digitale dello spazio YUV (lavora solo in analogico).
- largamente utilizzato per la compressione JPEG
- $C_{b}$ = crominanza blu
- $C_{r}$=crominanza rosso

gli spazi YC<sub>b</sub>C<sub>r</sub> si possono ottenere quantizzando i canali YUV

$$
Y=0.299R+0.587G+0.114B
$$
$$
C_{b}=U+128
$$
$$
C_{r}=V+128
$$

## 8.15 colori e memoria + Palette
assumendo di usare 8 bit per ogni colore si arriverebbe
$$
\text{RGB}=8\text{bit}+8\text{bit}+8\text{bit}=24\text{bit}\implies \text{16 milioni}
$$
anche se ho un immagine ad alta qualità sarà difficile usare tutti questi colori

#attensionplis 
>inoltre le immagini naturali dispongono della proprietà di coerenza interna per cui raramente si avrà un colore differente per ogni pixel


per questo si adotta la modalità a colori indicizzati / palette/ look-up-table

### palette
si fa uso di una tabella di etichette, in cui ogni cella rappresenterà un colore.

ad ogni pixel verrà assegnata un etichetta corrispondente al colore da rappresentare

### tipi di palette
in genere software commerciali / formati di compressione adottano palette di 256 colori

nel caso in cui si usa una palette adattata all'immagine si cerca di ridurla ad una palette basata su 256 colori

#attensionplis 
>esistono anche delle palette standard (mac, windows, ecc..)
>
>nel caso si usino alcune etichette potrebbero essere non usate

## 8.16 re-indexing
permette di trovare un migliore assegnamento degli indici ai colori in modo da minimizzare l'entropia. in modo tale da avere valori simili tra pixel adiacenti

se si abbassa l'entropia riesco a comprimere la mappa degli indice in maniera **lossless** (senza una perdita di informazioni) con un rapporto di compressione maggiore

### soluzione
avendo un numero elevato di colori, le combinazioni di palette saranno
$$
n_{\text{colori}}=n!
$$

trovare quindi la disposizione ottima (ad entropia minima) è un problema NP-HARD
- però esistono algoritmi che riescono a trovare la soluzione ottimale