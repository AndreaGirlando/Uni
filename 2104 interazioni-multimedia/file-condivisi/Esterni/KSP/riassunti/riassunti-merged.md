##### 1 - Prima parte

# [2] I FONDAMENTI
## 2.1 LEGGI
1. legge vicinanza
	- parti vicine di un insieme tendono ad essere percepite come raggruppate in unità
1. legge chiusura
	- le figure chiuse si vedono più facilmente e tendono a prevalere
2. legge uguaglianza
	- mettere insieme elementi che si assomigliano (colori)
3. legge continuità
	- ![]() un insieme di punti posto uno di seguito all'altro tendono a formare una strutture unitaria
4.  legge buona forma
	- forme regolari sono più gradevoli
5.  figure chiuse
	- il cervello tende a chiudere le forme
6. coerenza
	- si tende a fare continuare delle forme nascoste

## 2.2 intensità percepita e illusioni ottiche
l'occhio umano percepisce l'intensità luminosa in modo logaritmico rispetto all'intensità incidente nell'occhio. vale a dire che la luminosità percepita non è semplicemente in funzione dell'intensità emessa.

### bande di mach
![[Pasted image 20231005085502.png]]
data una serie di bande con luminosità costante. il nostro occhio tende a percepirle in maniera non uniforme al tendere dei bordi

### contrasto simultaneo
quello interno ha sempre lo stesso colore, percepiamo di colore diverso
![[Pasted image 20231130172953.png]]

## 2.3 rappresentazione immagine
rappresentata da funzione bidimensionale $f(x,y)$

- x,y coordinate spaziali
- f(x,y) : proporzionale allla luce incidente e riflessa
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
1. primo elemento matrice -> in alto sinistra
2. il piano sarebbe il 4° quadrante del piano cartesiano

##### tipi di immagini
1. bianco / nero
	1 bit per pixel => nella posizione i,j ci sarà 0 oppure 1
	![[Pasted image 20231005102748.png|300]]

2. scala grigi
	posizione (i,j) valore tra [0/255]
	![[Pasted image 20231005102918.png|300]]

3. a colori
	in base allo spazio di colore ogni pixel assumera un terna di valori
	$$(x,y,z)$$
	
	nel caso RGB una terna di valori rispetto all'intensità del rosso,verde e blu
	![[Pasted image 20231005103314.png|300]]
# [3] OPERAZIONI SU IMMAGINI E MATRICI 

un immagine raster può essere rappresentata come una matrice
- si potranno fare tutte le operazioni delle matrici (per modifiche varie)

## 3.1 neighborhood
vicinato rispetto ad un pixel (cella della matrice)

1. "4 connessi"
	![[Pasted image 20231005110547.png|100]]
2. "8 connessi"
	![[Pasted image 20231005110617.png|100]]

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
![[Pasted image 20231025152210.png]]
### scaling
- ingrandisce
![[Pasted image 20231025152226.png]]
### rotation
- ruota
![[Pasted image 20231025152242.png]]
### translation
- sposta un oggetto
![[Pasted image 20231025152251.png]]
### shear vertical
- si "streacha" l'immagine in verticale
![[Pasted image 20231025151723.png]]

### shear horizontal
- si "streacha" in orizzontale
![[Pasted image 20231025152324.png]]

#### modi di operare

1. forward mapping
"si moltiplica alle coordinate input (v,w) la matrice caratteristica e si ottengono le coordinate di output (x,y)"
![[Pasted image 20231025154442.png|250]]

2. inverse mapping
"si parte dalle coordinate di output per ricavarsi quelle di input iniziali"
![[Pasted image 20231025155139.png|250]]
#attensionplis 
> si possono combinare le operazioni affini, moltiplicando le matrici caratteristiche

## 3.3 ZOOMING IN - interpolazione
data un immagine $M \text{ x } N$, applicando uno zoom 2x avremo $2M \text{ x } 2N$ quadruplicando i pixel

#attensionplis 
nel corso delle trasformazioni si possono perdere delle informazioni

#ex 
> nello scaling alcuni punti saranno vuoti
> ![[Pasted image 20231025161252.png]]

l'interpolazione stima i dati non conosciuti

#### tipi di interpolazione
1. replication / nearest neighbor
prende i valori dei pixel e li replica nei "neighbor"
![[Pasted image 20231025161746.png|500]]
![[Pasted image 20231025162010.png]]
**svantaggi**: l'immagine si distorce lungo i lati degli oggetti
**vantaggi**: non introduce valori che prima non erano presenti

2. bilinear
tramite un equazione si definisce una funzione "intensità"
![[Pasted image 20231025171032.png]]
i coefficienti (a,b,c,d) sono dati dai quattro pixel più vicini
#ex 
vogliamo sapere cosa mettere nei pixel nell'intorno (0,0) - (2,2) ^7bcb12

| 1 | ***X*** | 2 | - | 3 |
| ---- | ---- | ---- | ---- | ---- |
| ***X*** | ***X*** | **X** | - | - |
| 4 | ***X*** | 5 | - | 6 |
| 7 | - | 8 | - | 9 |

dobbiamo partire da quello che sappiamo.
$V(0,0) = a * 0 + b * 0 + c * 0 * 0 + d = d \implies d=1 \text{ (valore all'interno della cella)}$
$V(2,0) = a * 2 + b * 0 + c * 2 * 0 + d = 2a + d \implies 2a+d=2$ 
$V(0,2) = a * 0 + b * 2 + c * 0 * 2 + d = 2b +d \implies 2b+d=4$ 
$V(2,2) = a * 2 + b * 2 + c * 2 * 2 + d = 2a + 2b + 4c + d \implies 2a+2b+4c+d=5$

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
$$V(1,1)=ax+by+cxy+d=\left( \frac{1}{2}*1 \right)+\left( \frac{3}{2}*1\right)+(0*1*1)+1=3$$

| 1 |***X*** | 2 | - | 3 |
|---|---|---|---|---|
| ***X***| ***3***| **X** | - | - | 
| 4 | ***X*** | 5 | - | 6 |
| - | - | - | - | - |
| 7 | - | 8 | - | 9 |

#attensionplis 
1. si prendono i 4 pixel più vicini dell'immagine originale
	#ex: nel punto (0,1) si prendono i pixel $(0,0) - (2,0) - (0,2) - (2,2)$
2. nel caso in cui ci sono più di 4 pixel vicini si prediligono i punti con $x,y$ maggiore
	#ex: nel punto (2,1) si prendono i pixel $(2,0) - (2,2) - (4,0) - (4,2)$

4. bicubica
si utilizzano i 16 pixel vicini al punto, la funzione si ottiene tramite la seguente equazione
![[Pasted image 20231025175257.png]]
#### interpolazione ai bordi
ai bordi non si hanno i valori sufficienti come negli altri punti

soluzioni
1. non fare nulla, si ricopiano i valori ottenuti
![[Pasted image 20231025175646.png|500]]
2. interpolare con valori minori, meno incognite


## 3.4 ZOOMING OUT - decimazione
data un immagine $M \text{ x } N$, applicando uno zooming out di 0,5 avremo $\frac{M}{2} \text{ x } \frac{N}{2}$

METODI
1. da 4 pixel se ne sceglie 1
![[Pasted image 20231025180335.png|400]]
2. da 4 pixel si calcola il valore medio
![[Pasted image 20231025180418.png|400]]

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
![[Pasted image 20231025181104.png|1000]]
#### PSNR
modi equivalenti:
![[Pasted image 20231025181118.png|500]]
better:
![[Pasted image 20231201153105.png]]
### come si usano in RGB?
2 modi:
1. media tre canali di colore
2. combinazione lineare che da un peso maggiore al verde

# [4] SENSORI E BAYERN PATTERN
## 4.1 acquisizione immagini digitali
quando la luce colpisce un oggetto, una parte viene assorbita ed una parte riflessa

quella riflessa da origine al colore percepito

per creare un immagine digitale è necessario catturare la luce riflessa **con un sensore** ed elaborarla

![[Pasted image 20231026001153.png|500]]

## 4.2 il sensore
l'energia che colpisce il sensore è trasformata in un impulso elettrico, il quale viene successivamente digitalizzato
![[Pasted image 20231026001322.png|400]]

### esempi sensori
1. singoli
EX: scanner
singolo sensore che viene spostato lungo la sorgente
![[Pasted image 20231026001457.png|400]]
2. in linea
EX: macchina per fare TAC
disposti in un unica linea
![[Pasted image 20231026002103.png|500]]
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
> 	![[Pasted image 20231026002648.png|200]]

## 4.3 Color filter array (CFA)
in quanto ogni cella memorizzerà un solo colore, occorre scegliere un modello di memorizzazione ottimale (CFA)
- scegliendo un filtro di colore apposito da posizionare davanti al sensore

tramite interpolazione verranno scelti i colori dei pixel vicini

### Bayern pattern
è il più usato
- dispone i pixel verdi nelle diagonali (più importante per la percezione umana) e poi si procede interpolando
![[Pasted image 20231026003327.png|400]]

senza un algoritmo sarebbero disposti a mosaico. Per avere una percezione reale del colore, per ogni cella sarà necessario la terna (RGB)

#attensionplis 
conservata nel formato raw
#### color interpolation
detto anche "demosaicking"
1. replication / nearest neighbor interpolation
> ![[Pasted image 20231125204528.png|400]]

2. bilinear
> per la cella che ha il rosso 
> ![[Pasted image 20231027140240.png |400]]
> per la cella con il blu
> ![[Pasted image 20231125205408.png|400]]
> 
> per la cella con il verde
> ![[Pasted image 20231125205446.png|400]]
# [5]  LA RISOLUZIONE

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

> ![[Pasted image 20231027134351.png|200]]
> 200pixel di larghezza
> 1dot per 1cm = 200pixel per rappresentazione reale
> 
> 200 x 200 x 24bit = 960 000bit per memorizzazione

#attensionplis 
> un immagine nata con una certa risoluzione dovrà essere visualizzata con la stessa

> STANDARD
> ![[Pasted image 20231027134720.png|500]]

# [6]  L'OCCHIO

a noi interessa la retina
## 6.1 la retina
membrana che ricopre la parte posteriore dell'occhio
![[Pasted image 20231030111710.png|400]]
formata da **coni** e **bastoncelli** (fotorecettori)

**CONI**
![[Pasted image 20231030112048.png|100]]
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
> ![[Pasted image 20231030121044.png]]

#attensionplis 
1. fovea parte centrale della retina (1,5mm x 1,5mm)
2. la fovea ha circa 150.000 coni per mm<sup>2</sup> =>circa 337.500 totali

## 6.2 formazione immagine
a noi arriva l'immagine capovolta ma poi viene elaborata
![[Pasted image 20231030122654.png|500]]

per comprendere questo principio esiste il **modello pinhole**
![[Pasted image 20231030123710.png|400]]
![[Pasted image 20231030123200.png|400]]

il pinhole ideale ha il seguente raggio $r=\sqrt{ \lambda d }$
- $\lambda$ [frequenza lunghezza d'onda] (nella realtà entra luce di tutti i tipi => lunghezze d'onda diverse. quindi non )
- d [distanza buco - sensore]

#attensionplis 
> nella realtà non possiamo rappresentare un punto ma un figura geometrica, ma produciamo un'area (POINT SPREAD FUNCTION)
> 
> ![[Pasted image 20231030123919.png|400]]


## 6.3 La lente sottile
oggetto fisico che permette di deviare la luce (onde elettromagnetiche)
- se costruite opportunamente possiamo decidere la direzione

definita da proprietà geometrica
![[Pasted image 20231030144533.png|500]]
1. i raggi paralleli alla lente vengono concentrati in un unico punto **fuoco** posto a distanza f dalla lente
![[Pasted image 20231030144500.png|400]]
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
\frac{h}{k} = \frac{v}{u}=\text{m}
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
![[Pasted image 20231026095718.png|200]]

1. campionamento: suddividiamo in intervalli di valori
> si analizza da sx -> dx
> più alto-> più bianco
![[Pasted image 20231026100346.png]]
2. suddivisione intervalli
![[Pasted image 20231026095909.png|400]]
4. quantizzazione
> per ogni intervallo si sceglie un valore (sono infiniti)
![[Pasted image 20231026095924.png|400]]

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
> nyquist rate: $2*N=2*400=800$
> 
> si divederà il segnale in 800 intervalli
> ![[Pasted image 20231026103039.png|500]]

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
![[Pasted image 20231031113457.png|400]]

### campionamento corretto

$$\text{campionamento}=\frac{\text{numero pixel}}{\text{tratto}}$$
#ex 
> immagine 720x720pixel
> tratti 4pixel
> 
> $N=\frac{720}{4}=180$
> per il nyquist rate è ottimale avere $2N$ =>$180*2=360$
> 
> allora campioneremo l'immagine in modo tale da avere 360 campioni su cui andremo ad applicare interpolazione lineare ([[#tipi di interpolazione]])

#attensionplis quando si parla di campionamento si intende la risoluzione dell'immagine

#ex
> immagini a diversi campioni/risoluzioni e poi ingrandite per notare le differenze
> 
> 240campioni non si rispetta nyquist -> si perdono dettagli
> 120campioni sotto nyquist -> bad Quality
> ![[Pasted image 20231026105144.png|400]]

### Aliasing
se si campiona sotto il nyquist rate possiamo imbatterci in perdite di dettagli ma anche all'**aggiunta di dettagli non presenti.** Questo fenomeno prende il nome di
"frequency aliasing o aliasing"

aliasing: le frequenze alte sono mascherate da basse frequenze

#ex 
> perdita di dettagli
> 
> nei momenti in cui le frequenze sono basse, campionando male le abbiamo perse
> ![[Pasted image 20231031120846.png|400]]

#ex 
> nuovi dettagli
> 
> i graffi non si notano più
> sono apparsi nuovi buchi sulle rocce
> ![[Pasted image 20231031120936.png|500]]

### effetto Moirè
effetto che si genera durante la digitalizzazione sovrapponendo 2 serie di linee o pattern creandone un ulteriore che sembra avere dei motivi distorti

#ex quando si fotografano tessuti a righe, recinzioni, griglie, ecc...

**CAUSA**
è causato dall'interferenza tra linee/pattern irregolari con la griglia di pixel su uno schermo o sul sensore di una fotocamera. Queste non si allieano creando l'illusione di one o cerchi

che si fa?
1. minimizzare disallinamento sensore - oggetto, modificando l'angolo di scatto
2. filtri anti-moirè
3. post elaborazione con software
![[Pasted image 20231031122108.png|500]]

### distorsione animazioni - wagon whell
presa un animazione (gif) in base al numero di campioni può essere cambiata totalmente

![[king.gif]]

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
$$t_{k}<=x<t_{k+1}$$
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

![[Pasted image 20231107160154.png|400]]
**COME SI RAPPRESENTANO IN MEMORIA?**
le etichette di ogni livello verrano rappresentate tramite bit
$$\text{numeroEtichette}=\log_{2}\text{numeroLivelli}$$

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
> ![[Pasted image 20231107160821.png|500]]

### tipi di quantizzazione
a seconda dell'uso possiamo definire 2 tipi di quantizzazione

1. uniforme
> uniforme: differenza tra $t_{k}\text{ e }t_{k+1}$ sempre uguale
> 
> $1<2<3<\dots<n$
> 
> ![[Pasted image 20231107165507.png]]

2. non uniforme
> alcuni range di livello sono più precisi di altri
> 
> #ex
> 	i primi intervalli sono molto precisi tra loro.
> 	gli ultimi 2 comprendono un range molto ampio, questo causerà una perdita importante di precisione.
> 	$10<20<30<420<10^8$
> 	
> 	![[Pasted image 20231107165522.png]]


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
> ![[Pasted image 20231107165726.png]]

### formule quantizzazione

**UNIFORME**
si fa la proporzione
$$
L'=\frac{L \cdot K}{N}
$$
$L$ = livello di ingresso (valore)
$L'$ = livello di uscita
$N$ = range ingresso
$K$ = range uscita

#attensionplis 
>si prende la parte intera arrotondando per difetto (floor)

#ex
> $$
 0 : 255 = 0 : 7
 $$
> se voglio inserire il valore 10:
> $$
 10:255=x:7\implies \frac{70}{255}=0
 $$

NON UNIFORME

$$
L'= f(L,N,K)
$$
$L'$ è in funzione dei 3 valori, l'implementazione definisce lo schema di riquantizzazione
( #ex logaritmica) 

LOGARITMICA 

$$
L' = \frac{\log_{2}L \cdot K}{N}
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
$$f(\text{valoreLvl}_{new}, k_{new,k_{old}})=\lfloor\frac{\text{valoreLivello}_{old}*k_{new}}{k_{old}}\rfloor$$

immagine_new: 

| 12 | 2  |
| --- | --- |
| 0  | 0   |

RIQUANTIZAZZIONE LOGARITMICA
$$f(\text{valoreLvl}_{new}, k_{new,k_{old}})=\lfloor\frac{\log_{2}{(\text{valoreLvl}_{new})}*k_{new}}{\log_{2}{(k_{old})}}\rfloor$$

# [8] COLORE

## 8.1 cos'è il colore?
il concetto di colore è legato alla lunghezza d'onda, ovvero lo spazio percorso dall'onda in un tempo pari al periodo (tempo tra un oscillazione e la successiva)
![[Pasted image 20231107173057.png|400]]
#ex 
> più lungo -> più verso rosso
> lento -> verso viola

#attensionplis spettro visibile tra violetto e rosso

la luce è formata dalle lunghezze d'onda percepite dall'occhio umano

lo spettro visibile oscilla tra violetto e blu
> diviso in 6 regioni: violetto, blu, verde, giallo, arancio e rosso
> 
> le bande di colore non sono tutte della stessa lunghezza, degradano nelle zone limitrofe
> ![[Pasted image 20231107173445.png]]

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
> ![[Pasted image 20231107175120.png]]

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
![[Pasted image 20231107180152.png]]

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
> $$X=\int^{780}_{{380}}{L_{e}(\lambda)}\bar{x}(\lambda)\, d\lambda $$

stessa cosa per il verde e blu
![[Pasted image 20231107180924.png]]
![[Pasted image 20231107180914.png]]

## 8.8 Dati colorimetrici
il colore che percepiamo è dato da diversi fattori
> ![[Pasted image 20231114150948.png]]
> 	1. distribuzione energetica della luce che lo illumina
> 	2. curva spettrale dell'oggetto illuminato
> 	3. percezione al colore dell'occhio umano

### misurazioni del colore
il colore può essere osservato in maniera differente a seconda del soggetto che effettua il campione

1. occhio umano
> ![[Pasted image 20231114151225.png|400]]
> la retina riceva la luce riflessa dall'oggetto e la invia al cervello, il quale identifica il colore in base alle informazioni che gli arrivano

2. colorimetro
> ![[Pasted image 20231114153059.png]]
> simil fotocamera
> 
> dotato di sensori con filtri che accettano solo alcune lunghezze d'onda (ex: RGB) i quali inviano le informazioni ad un microprocessore
> 
> il microprocessore (embedded) effettua un calcolo numerico e restituisce
> 
> **OUTPUT**
> valori finiti (in base alle informazioni inviate dai sensori)

3. spettrofotometro
>![[Pasted image 20231114153034.png]]
>1. oggetto viene illuminato da luce allo Xenon (luce che illumina in maniera uniforme).
>2. la luce riflessa viene raccolta da un insieme di lenti
>3. questa viene divisa in lunghezze d'onda (funzione)
>
>
> **OUTPUT**
> 2 tipi di output
> 
> 1. valori numerici
> 2. il sensore restituisce un intero spettro di valori (somma finite onde sinusoidali in cui ognuna da un contributo diverso)
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
X = K\int^{780}_{380} S(\lambda)\bar{x}(\lambda)R(\lambda) \, dx 
$$$$
Y = K\int^{780}_{380} \dots \, dx 
$$$$
Z = K\int^{780}_{380} \dots \, dx 
$$
> per normalizzare i valori otteunti dagli integrali si fa il rapporto tra 100 e l'integrale$$
 K=\frac{100}{\int^{780}_{380} S(\lambda)\bar{x}(\lambda)\, d\lambda}
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
 x=1-y-z
 $$
> $$
 y=1-x-z
 $$
> $$
 z=1-x-y
 
 $$ 

#attensionplis 
>$x,y,z$ sono in percentuale (valore compreso tra 0 e 1)


al variare di x e y si da origine al diagramma cromatico CIE
> valori lunghezza d'onda disposti lungo i bordi.
> 
> il punto in cui i colori hanno la stessa energia è bianco.
> ai bordi i colori non hanno bianco (puro).
> ![[Pasted image 20231114160553.png|400]]

#attensionplis 
1. unendo 2 colori con una linea => tutti i possibili colori ottenibili mischiandoli
2. unendo un colore al bianco => tutte le sfumutare

#attensionplis "COLOR GAMUT"
> vedendo questo grafico si dimostra che teoria tristimolo falsa, non esiste un triangolo che lo racchiude interamente
> 
> l'area dentro rappresenta i colori che può stampare una stampante
> ![[Pasted image 20231114094712.png|400]]

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
> $\Updelta=\text{someting}L_{1}- \text{someting}L_{2}$
> ![[Pasted image 20231114165658.png]]
> 
> $$
 C_{1}=(10,20,30)
 $$
> $$
 C_{2}=(11,21,31)
 $$
> 
> $$
 \Updelta E = \sqrt{ (10-11)^2 + (20-21)^2 +(30-31)^2}=\sqrt{ 1+1+1 } = \sqrt{ 3 }
 $$


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
>![[Pasted image 20231115161936.png]]

tinta / hue
> ![[Pasted image 20231115161943.png]]


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

![[Pasted image 20231115162909.png|500]]

### metameri
se due coppie di spettri diversi producono la stessa sensazione di colore si chiamano **metameri**
#ex
>i due spettri producono nel cervello lo stesso colore
>![[Pasted image 20231115163039.png]]

#### modello del pittore
ogni spettro è dotato di un metamero caratteristico
![[Pasted image 20231115163210.png]]
una funzione costante che ha un picco nel punto (lunghezza d'onda) in cui il colore è percepito

emedia: responsabiile del contenuto energetico della radiazione

#attensionplis 
>il rapporto tra $$\text{saturazione = }\frac{epicco-emedia}{(epicco+emedia})$$
>saturazione = quanto un colore è puro
##### modello del pittore
ogni colore può essere rappresentato tramite un triangolo
![[Pasted image 20231115163546.png|600]]

mettendo assieme i triangoli per ogni colore (HUE) si ottiene lo **"spazio HSV"**

### spazio HSV
![[Pasted image 20231114112042.png|600]]

### altri spazi
1. ruota dei colori
>    organizza spazio colorato in schema simmetrico

2. MUNSELL (HCV)
> colloca i colori in spazio tridimensionale
> ![[Pasted image 20231115163857.png]]
> ![[Pasted image 20231115163944.png]]
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
![[Pasted image 20231129152538.png]]
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
	$(200,255,15)\implies(55,0,240)=(255,255,255)$

### sintesi sottrattiva
dalla loro sovrapposizione, in quanto tutta la radiazione viene assorbita si produrrà il nero

sovrapponendo due filtri si ottiene la componente luminosa che non viene assorbita

si compongono 3 colori
$$
Y+M+C=K_{\text{nero}}
$$
![[Pasted image 20231129155221.png]]
#### quando viene usata?
su questo principio si basa la riproduzione delle immgini colorate nella fotografia a colori

![[Pasted image 20231129160132.png]]
## 8.11 colori primari e secondari

>i colori primari non sono definiti in maniera assoluta ma in base all'illuminante

### rgb
se ogni colore si ottiene mischiano altri 3 fondamentali si andrà a formare un cubo
ogni colore è un punto dentro il cubo
![[Pasted image 20231129160619.png]]

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
Y=0.299R+0.587+0.114B
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
\text{RGB}=8bit+8bit+8bit=24bit\implies \text{16 milioni}
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
n_{colori}=n!
$$

trovare quindi la disposizione ottima (ad entropia minima) è un problema NP-HARD
- però esistono algoritmi che riescono a trovare la soluzione ottimale

##### 2 - Seconda parte


# 9 Operazioni puntuali
## 9.1 istogramma
### intro
i pixel di un'immagine sono una popolazione sulla quale possiamo calcolare tutte le quantità statistiche descrittive
- media
- mediana
- varianza
- derivazione standard
- ecc...

particolare importanza è la conoscenza dei toni di grigio

### cos'è l'istogramma
strumento che riporta il numero di pixel per ogni livello di colore
- viene rappresentato tramite un grafico

data immagine $I[m,n]$ si ha:
$$
H(k)=\text{numero di pixel di valore k}
$$
la somma di tutti gli H equivale a $m \text{ x } n$

![[Pasted image 20231213163534.png]]

#attensionplis 
>restituisce un valore relativo, in modo tale da poter confrontare immagini con dimensioni diverse


#ex
> data immagine $I(m,n)$ con 3 bit
> 
> $$
 H= [5][17][82][0][0][25][7][8]
 $$
> $$\quad\quad\quad\quad\quad[0][\dots][\dots][\dots][\dots][\dots][\dots][7]
 $$
> 
> "5 pixel di valore 0"
> "17 di valore 1"
> ecc...
> 
> seguendo l'istogramma risulterà un immagine scura

#attensionplis 
>ci possono essere due immagini con lo stesso istogramma anche se diverse
>
>istogramma non tiene conto della position

immagine sovraesposta/sottoesposta
>si ha una prevalenza da una certa parte dell'istogramma


## 9.2 contrast stretching
> aumenta la dinamica di un'immagine il cui istogramma è concentrato su un intervallo limitato dei valori possibili
- punta ad aumentare il contrasto (allontana valori che prima erano concentrati tra loro)
- da un immagine che non usa tutti i toni ne vado a creare una che li usa

![[Pasted image 20231213164629.png|600]]


#attensionplis 
>nelle immagini a colori abbiamo una terna =>si divide l'immagine in 3 istogrammi
>
>le operazioni le effettuerò ai 3 canali singolarmente

### problemi aritmetica
operando aritmeticamente possiamo imbatterci in:
$$
\underbrace{ \text{valore negativo, valore maggiore del massimo} }_{ \text{problemi di range} }\text{ ,valore non intero}
$$

ai problemi di range vi sono due soluzioni principali
1. settare a 0 i valori negativi, 255 i valori maggiori del massimo
2. normalizzare
## 9.3 normalizzazione
usiamo la lineare

vogliamo che il minimo diventi 0 e il massimo 255
si avrà:
$$
[min,max]\to[0,255]
$$
usando la seguente formula:
$$
\huge
v_{new}=255 \cdot \frac{val_{old}-val_{min}}{val_{max}-val_{min}}
$$
- $val_{min}$ e $val_{max}$ sono rispettivamente i valori minimi e massimi della matrice di input

> [!example] Esempio normalizzazione
> data la seguente immagine (matrice):
> $$
> \begin{bmatrix}
> 45 & 100 & 150 \\
> 88 & 90 & 181 \\
> 110 & 111 & 112
> \end{bmatrix}
> $$
> non copre tutti i livelli. quindi mappo i valori del massimo e minimo rispetto a quelli presenti nella matrice  $min = 45$ e $max=181$ (si dimostra applicando la formula)
> 
> normalizzo per il valore 100:
> $$
> v_{new}=255*\frac{100-45}{181-45}=255* \frac{55}{136}=103,12\implies103
> $$
> 
> si procede così per tutti
## 9.4 Equalizzazione

si cerca di uniforma i contributi di tutti i colori dell'immagine, si punta ad avere una funizione costante nell'istogramma (impossibile nella realtà)

![[Pasted image 20231218165443.png]]
### algoritmo equalizzazione 
istogram matching = forzare un istogramma a diventare come un altro

> [!note] Numero di pixel in valori relativi
> $$p_{r}(r_{k})=\frac{n_{k}}{MN} \quad k = 0,1,2,\dots ,L-1$$
> - $r_{k}$ = un livello di grigio
> - $n_k$ = numero di pixel dell'immagine rispetto al livello $r_k$
> - $MN$ = dimensione matrice immagine

> [!important] Algoritmo equalizzazione
> $$
> \begin{align}
> s_{k}&=T(r_{k})\\
>  &=(L-1) \sum^{k}_{j=0}p_{r}(r_{j})\\
>  &=(L-1)\sum^{k}_{j=0} \frac{n_{j}}{MN} \quad k = 0,1,2,\dots,L-1
> \end{align}
> $$
> - $s_{k}$ = livello normalizzato
> - $L$ = numero di livelli disponibili nell'immagine
>   
>   per ogni livello calcolo il suo valore equalizzato tramite la formula

>[!example] Esempio equalizzazione
 Dato un immagine a 3 bit con dimensioni $MN = 64$, ed il seguente istogramma:
> 
> $$
> H=[0][4][16][8][4][32][16][16]
> $$
> equalizzare.
> 
> $$
> H_{\text{relativo}}=\left[ \frac{n_{k_{1}}}{MN} \right]\left[ \frac{n_{k_{2}}}{MN} \right] [\dots] \left[ \frac{n_{k_{n}}}{MN} \right]
> $$
> $$
> \begin{align}
> &&&&&&=\left[ \frac{0}{64} \right]\left[ \frac{4}{64} \right]\left[ \frac{16}{64} \right][\dots]\left[ \frac{16}{64} \right]
> \end{align}
> $$
> 
> $$
> \begin{align}
> &&&&&&&&&&&&=[0][0,06][0,25][0,125][0,06][0,5][0,25][0,25]
> \end{align}
> $$
> 
> applicare l'algoritmo:
> $$
> s_{k}=(L-1)\sum^{k}_{j=0} \frac{n_{j}}{MN}
> $$
> 
> - $s_{0}=(8-1) \sum^{0}_{j=0}0=0$
> - $s_{1}=(8-1) \sum^{1}_{j=0}\frac{n_{j}}{MN}=7 \cdot (0 + 0,06)=0,42$
> - $s_{2}=(8-1) \sum^{2}_{j=0}\frac{n_{j}}{MN}=7 \cdot (0 + 0,06+0,25)=7 \cdot 0,31=2,17$
> - $\dots$  
>
>si procede così per tutti i livelli dell'immagine e si avrà
> - $s_{0}=0$
> - $s_{1}=0,42$
> - $s_{2}=2,17$
> - $\dots$
> 
> si arrotondano i valori e si procede a modificare i valori dei pixel (immagine iniziale) rendendoli equalizzati
> - valore 0 = $s_{0}$
> - valore 1 = $s_{1}$
> - ecc...
## 9.5 Operatori puntuali
tratteremo solo immagini in scala di grigi

#attensionplis 
per le immagini a colori, si divide in 3 canali e si opera come se fossero immagini a scala di grigio

> [!info] Definizione di operazione:
> $$
> g(x,y)=T \cdot f(x,y)
> $$
> - $g$ = immagine output
> - $T$ = operatore di f definito in un intorno (x,y)
> - $f$ = immagine input
### TIPI DI OPERATORI
1. puntuale: si opera sui singoli pixel
2. locale: si opera sull'intorno del pixel
3. globale: si opera su tutta l'immagine

### operatori puntuali
un particolare operatore che prende in input un pixel e ne restituisce uno modificato che dipende dal valore di input

è rappresentato da una funzione $g(x,y)$. L'operatore può essere descritto da una tabella, in quanto l'ouput dipende solo dai valori in ingresso:
![[Pasted image 20231218165412.png]]

può essere rappresentata nel seguente grafico:
- asse $x$ input, $y$= output
![[Pasted image 20231218170520.png|400]]

grafico **look-up table** (LUT)
- grafico che si ottiene andando ad associare ad ognuno dei possibili input il corrispondende output, ottenuto applicando lo specifico operatore puntuale
![[Pasted image 20231218170722.png]]

#### operatore negativo
$$
g(x,y)=255-f(x,y)
$$
![[Pasted image 20231218171007.png]]

la curva cambia nel seguente modo:
![[Pasted image 20231218170953.png]]

#### incupimento / schiarimento
tramite modifica della curva:
![[Pasted image 20231218171117.png]]
![[Pasted image 20231218171137.png]]

#### trasformazione logaritmica
usato principalmente per avere maggiore dettaglio nelle aree scure dell'immagine.
- "comprime la gamma dinamica"

descritto dalla seguente legge:
$$
g(x,y)=c \cdot \log_{2}(1+f(x,y))
$$
- $c$ = costante positiva che normalizza il risultato in $[0,255]$

> [!attention] attensionplis
> $$
> f(x,y) \in [0,255]
> $$
> $$
> g(x,y)=\log(1+f(x,y)) \in [0,8]
> $$
>vogliamo che $g(x,y)$ sia nel range di $f(x,y)$, allora gli moltiplichiamo la $c$
>
>$$c=\frac{255}{\log_{2}(1 + (L-1))}=\frac{255}{\log_{2}(8)}=\frac{255}{3}$$
>
>$$g(x,y) \in [0,8] \quad\underset{ \text{moltiplico la c} }{ \implies }\quad  g(x,y) \cdot c \quad\implies \quad g(x,y) \in [0,255]$$

![[Pasted image 20231218173635.png]]

#### trasformazione potenza
lo stesso scopo dell'operatore logaritmico, qui invee eleva ad un certo $\gamma$
![[Pasted image 20231218175916.png]]

la legge:
$$
g(x,y)=c \cdot (f(x,y))^\gamma
$$
$$
f(x,y) \in [0,255^\gamma]
$$

per normalizzarlo si moltiplica per $c$
>$$c=\frac{255}{255^\gamma}=\frac{1}{255^{\gamma - 1}}$$

#attensionplis 
>aumentando $\gamma > 1$ si scurisce

>[!attention] trick
>dato un monitor con certe caratteristiche che applica una $\gamma = 2.5$
>
>per visualizzare l'immagine con colori non falsati, passiamo al monitor la seguente $f$
>
>$$\huge f(x,y)^{\frac{1}{2.5}}\implies \left( f(x,y)^{\frac{1}{2.5}} \right)^{2.5}\implies f(x,y)$$

#### binarizzazione
"sogliatura / trash holding"
produce immagine che ha solo 2 livelli (bianco nero)

$$
g(x,y)=\begin{cases}1 & f(x,y) \geq T \\
0 & f(x,y)<T
\end{cases}
$$

>[!example] esempio
> $$
> \begin{bmatrix}
> 25 & 150 \\
> 70 & 100
> \end{bmatrix}
> 
> \quad \underset{ T=90 }{ \implies } \quad
> 
> \begin{bmatrix}
> 0 & 1 \\
> 0 & 1
> \end{bmatrix}
> 
> $$

#attensionplis 
>l'istogramma cambia avendo due barre in corrispondenza di 1 e 0
#### variazioni di contrasto
rendere più evidenti le differenze di colore
- contrasto : quanto sono distanti nell'istrogramma i pixel chiari (più distanti -> più alto)

aumento contrasto:
![[Pasted image 20231218180533.png|400]]

diminuzione:
![[Pasted image 20231218181127.png]]

fino ad ora tutte le curve sono state di tipo monotone. una curva non monotona ad esempio può essere quella che descrive l'operatore "solarizzazione"
![[Pasted image 20231218181636.png]]
# 10  Convoluzioni
Le matrici che descrivono le immagini possono essere scomposte secondo il concetto di base canonica

> [!example] Esempio uso basi canoniche
> $$
> \begin{bmatrix}
> 10 & 20 & 30 \
> 40 & 50 & 60 \
> 70 & 80 & 90
> \end{bmatrix}
> $$
> $$
> 10 \cdot \begin{bmatrix}
> 1  & 0 & 0 \
> 0 & 0 & 0 \
> 0 & 0 & 0
> \end{bmatrix}
> +
> 
> 20 \cdot \begin{bmatrix}
> 0  & 1 & 0 \
> 0 & 0 & 0 \
> 0 & 0 & 0
> \end{bmatrix}
> 
> +
> 
> \dots
> 
> +
> 90 \cdot \begin{bmatrix}
> 0 & 0 & 0 \
> 0 & 0 & 0 \
> 0 & 0 & 1
> \end{bmatrix}
> $$

## 10.1 Operatori lineari
dato un operatore
$$
F:V\to W
$$
se $$
 a \cdot F(x_{1},y_{1})+b \cdot F(x_{2},y_{2})=F(ax_{1}+bx_{1},ay_{1}+by_{2})
$$l'operatore è lineare

> [!example] Esempio operatore lineare
> f(x,y)=(x2,y3) è lineare?
> 
> sostituiamo:
> $$
> a \cdot \left( \frac{x_{1}}{2},\frac{y_{1}}{3} \right)+b \cdot \left( \frac{x_{2}}{2},\frac{y_{2}}{3} \right)=(\frac{ax_{1}+bx_{2}}{2},\frac{ay_{1}+by_{2}}{3})
> $$
> 
> moltiplico per a e b rispettivamente
> 
> $$
> \left( \frac{ax_{1}}{2},\frac{ay_{1}}{3} \right)+\left( \frac{bx_{2}}{2},\frac{by_{2}}{2} \right)=\dots
> $$
> 
> li sommo
> $$
> (\frac{ax_{1}+bx_{2}}{2},\frac{ay_{1}+by_{2}}{3})=(\frac{ax_{1}+bx_{2}}{2},\frac{ay_{1}+by_{2}}{3})
> $$
> 
> sono uguali, quindi è lineare
## 10.2 Operatori invarianti per traslazione / Shift invariant
un operatore si dice "invariante per traslazione" se il suo comportamento sulla **immagini impulsive** è indipendente rispetto alle coordinate del pixel

>[!example] Esempio di Operatore invariante per traslazione
> dato un operatore $F$ lineare, invariante per traslazione
> $$
> F\left(\begin{bmatrix}
> 0 & 0 & 0 \\
> 0 & 1 & 0 \\
> 0 & 0 & 0
> \end{bmatrix}\right)
> 
> =
> 
> \begin{bmatrix}
> 0 & 0 & 0 \\
> \frac{1}{2} & 0 & \frac{1}{2} \\
> 0 & 0 & 0
> \end{bmatrix}
> $$
> 
> calcolare:
> $$
> F(\begin{bmatrix}
> 8 & 4 & 16 \\
> 32 & 8 & 8 \\
> 64 & 32 & 2
> \end{bmatrix})
> $$
> 
> la matrice la possiamo scrivere come somma di elementi della base canonica
> 
> $$
> F(8 \cdot \begin{bmatrix}
> 1 & 0 & 0 \\
> 0 & 0 & 0 \\
> 0 & 0 & 0
> \end{bmatrix}
> +4 \cdot \begin{bmatrix}
> 0 & 1 & 0 \\
> 0 & 0 & 0 \\
> 0 & 0 & 0
> \end{bmatrix}
> +\dots+
> 2 \cdot \begin{bmatrix}
> 0 & 0 & 0 \\
> 0 & 0 & 0 \\
> 0 & 0 & 1
> \end{bmatrix}
> )
> $$
> 
> sapendo che è lineare possiamo fare:
> $$
> 8 \cdot F(\begin{bmatrix}
> 1 & 0 & 0 \\
> 0 & 0 & 0 \\
> 0 & 0 & 0
> \end{bmatrix})
> 
> +4 \cdot F(\begin{bmatrix}
> 0 & 1 & 0 \\
> 0 & 0 & 0  \\
> 0 & 0 & 0
> \end{bmatrix})
> 
> +\dots+
> 2 \cdot F(\begin{bmatrix}
> 0 & 0 & 0 \\
> 0 & 0 & 0 \\
> 0 & 0 & 1
> \end{bmatrix})
> $$
> 
> essendo invariante per traslazione posso applicare la regola generale
> - dove abbiamo 1 mettiamo a sx e dx $\frac{1}{2}$
> - quando $\frac{1}{2}$ esce fuori dalla matrice non si conta
> 
> $$
> 8 \cdot \begin{bmatrix}
> 0 & \frac{1}{2} & 0 \\
> 0 & 0 & 0 \\
> 0 & 0 & 0
> \end{bmatrix}
> +
> 4 \cdot \begin{bmatrix}
> \frac{1}{2} & 0 & \frac{1}{2} \\
> 0 & 0 & 0 \\
> 0 & 0 & 0
> \end{bmatrix}
> +
> \dots
> +
> 2 \cdot \begin{bmatrix}
> 0 & 0 & 0 \\
> 0 & 0 & 0 \\
> 0 & \frac{1}{2} & 0
> \end{bmatrix}
> $$
> 
> si moltiplicano per i rispettivi valori
> $$
> \begin{bmatrix}
> 0 & 4 & 0 \\
> 0 & 0 & 0 \\
> 0 & 0 & 0
> \end{bmatrix}
> +
> \begin{bmatrix}
> 2 & 0 & 2 \\
> 0 & 0 & 0 \\
> 0 & 0 & 0
> \end{bmatrix}
> +
> \dots
> +
> \begin{bmatrix}
> 0 & 0 & 0 \\
> 0 & 0 & 0 \\
> 0 & 1 & 0
> \end{bmatrix}
> $$
> si sommano le matrici trovate (pesc a pesc) e si trova il risultato

![[Pasted image 20240102185627.png|500]]

#attensionplis 
1.  immagine impulsiva: immagine in cui tutti valori sono minimi tranne un punto in cui c'è il massimo
2. Tutti gli operatori puntuali sono invarianti per traslazione
3. i filtri lineari e invarianti per traslazione sono anche chiamati convolutivi

## 10.3 convoluzione
si indica con il simbolo:
$$
g=f \oplus h
$$

gode della proprietà associativa e commutativa

>[!example] Esempio di applicazione di un kernel
> Dato il seguente kernel:
> $$
> kernel = \begin{bmatrix}
> 2 & 1 & 2 \\
> 1 & 2 & 1 \\
> 2 & 1 & 2
> \end{bmatrix}
> $$
> applicarlo alla seguente immagine:
> $$
> input=\begin{bmatrix}
> 1 & 2 & 2 & \dots & \dots \\
> 3 & 2 & 2 & \dots & \dots \\
> 2 & 5 & 2 & \dots & \dots \\
> \dots & \dots & \dots & \dots & \dots
> \end{bmatrix}
> $$
> sovrapponiamo le due matrici rispetto al punto dove vogliamo fare il calcolo e moltiplichiamo i punti che si sovrappongono
> - in questo caso il due
> 
> $$
> (2*1)+(1*2)+(2*2)+(1*3)+(2*2)+(1*2)+(2*2)+(1*5)+(2*2)=30
> $$
> $$
> output=\begin{bmatrix}
> \dots & \dots & \dots & \dots & \dots \\
> \dots & 30 & \dots & \dots & \dots \\
> \dots & \dots & \dots & \dots & \dots \\
> \dots & \dots & \dots & \dots & \dots
> \end{bmatrix}
> $$
> 
> fare la stessa cosa per gli altri punti

### convoluzione ai bordi
ci sono diverse soluzioni in base all'esigenza:
>[!tip] non li calcolo
>
>tengo conto solo della matrice che posso calcolare
>
>input(5x5) => ouput(3x3)
>
>![[Pasted image 20240103125123.png]]

>[!hint] considero il valore 0 all'esterno
>
>va bene quando, allontanandosi dai bordi si trovano valori scuri
>
>![[Pasted image 20240103125252.png]]

>[!hint] aggiungo "toroidale"
>
>suppongo che l'immagine ricominci
 (punti alto -> basso) (destra -> sinistra)
>
>ha senso se l'img è una texture
>
>![[Pasted image 20240103125318.png]]

>[!hint] replico i valori vicini
>
>se immagine è fotorealistica può avere senso
>- non ci sono grandi variazioni tra pixel vicini

## 10.4 Esempi di operatori locali

#attensionplis 
>un filtro conserva l'energia se la somma dei suoi pesi equivale a 1
### mediano, minimo, massimo
filtro non lineare, fornisce il valore mediano dell'intorno del pixel

>[!example] mediano rispetto al valore 1
> $$
> \begin{bmatrix}
> 0 & 17 & 18 & 75 & 30 \\
> 25 & (1) & 30 & 4 & 22 \\
> 2 & 4 & 90 & 20 & 20
> \end{bmatrix}
> 
> \implies
> \begin{bmatrix}
> \dots & \dots & \dots & \dots & \dots \\
> \dots & 17 & \dots & \dots & \dots \\
> \dots & \dots & \dots & \dots & \dots
> \end{bmatrix}
> $$
> 
> faccio il mediano di (2,2)
> 1. prendo l'intorno di (2,2)
>    $$0,17,18,25,30,2,4,90$$
>  2. ordino i valori dell'intorno e sostiuisco a (2,2) il mediano
>$$0,2,4,17,18,25,30,90\implies 17$$
>  
>  in base al numero di elementi abbiamo due casi
>   1. dispari: prendo l'elemento al centro
>  2. pari: media tra i 2 elementi che stanno al centro

#attensionplis 
1. per gli operatori di minimo/massimo si usa lo stesso metodo del mediano, prendendo il minimo/massimo della sequenza (minimo =produce immagine scura, massimo =  chiara)

![[Pasted image 20240103130522.png]]
![[Pasted image 20240103130538.png]]
![[Pasted image 20240103130545.png]]

### n-box
si prende un box di dimensioni $n$ e si fa la media rispetto all'intorno della cella che vogliamo modificare

produce una sfocatura dell'immagine
- molto forte verticale e orizzontale, poco diagonale

$$
\frac{1}{NXN} \cdot \begin{bmatrix}
	\dots & \dots \\
	 \dots & \dots & 
\end{bmatrix}_{NxN}
$$

#attensionplis 
1. l'operatore è invariante
2. anche lineare (la media posso farla anche)
$$
\frac{k_{1}}{\text{n}}+\frac{k_{2}}{\text{n}}+\dots+\frac{k_{n}}{\text{n}}
$$

### n-binomiale
filtri di smussamento che creano kernel di dimensioni ricavati dalla distribuzione binomiale

smussa egualmente in tutte le direzioni, ma in maniera meno vigorosa rispetto a n-box

![[Pasted image 20240103133205.png]]


## 10.5 Noise cleaning e smoothing
i filtri possono essere usati anche per ridurre il rumore
### tipi di rumore

#### impulsivo "sale e pepe"
caratterizzato dalla probabilità che un pixel sia di valore massimo o minimo

#attensionplis 
>si presenta in genere con i pixel bruciati del sensore

![[Pasted image 20231219093935.png]]

>[!example] "probabilità pz che si trasformi in ... è"
> $$
> p(z)=\begin{cases}
> 0.1 & z=0 \\
> 0.3 & z=255 \\
> 0 & \text{altrimenti} 
> \end{cases}
> $$
> - 10% che pixel diventi nero
> - 30% bianco
> - 60% non succede niente (prob. che diventi)
> $$
> p(34)=0 \quad\quad p(200)=0 \quad\quad p(0)=0.1
> $$
> 
> devo scrivere solo probabilità che un pixel sia alto o basso, non i valori medi

>[!attention] possibile domanda: "data una matrice restituisci con rumore impulsivo con le seguenti caratteristiche"
>
>- si prende l'immagine, per ogni pixel si generano numeri casuali, in base al sistema delle probabilità sostiuisco il valore

#### rumore gaussiano

> [!info] Dato dalla seguente formula
> $$
> \huge
> p(z)=\frac{1}{\sqrt{ 2 \pi }\sigma}e^{-\frac{(z-\overset{\_}{z})^2}{2\sigma^2}}
> $$
> - $z$: l'intensità
> - $\overline{z}$: valore medio (massima probabilità di verificarsi, tendenzialmente è zero)
> - $\sigma^2$ = varianza (quanto è ampia la forma a campana della gaussiana)
> 
> "probabilità che un pixel abbia uno scostamento di intensità pari a $z$"

>[!attention] possibile domanda
>"Determinare il rumore gaussiano dato da una deviazione $\sigma=3$, valore medio $\overline{z}=x$ e un intensità $z=y$"
### considerations
> [!hint] tipo di kernel
> se il rumore è diffuso è meglio applicare un un kernel più grande rispetto ad iterarlo più volte. l'immagine risulterà meno sfocata
> ![[Pasted image 20240111165538.png|400]]

> [!hint] media vs mediano
> i filtri mediani danni risultati migliori rispetto a quelli di media. la media crea dei livelli prima non esistenti e attenua tutte le alte frequenze spaziali in maniera indiscriminata. inoltre il mediano non deteriora i lati ma elimina i picchi con base piccola rispetto al kernel

>[!hint] Altri filtri
> - filtro outlier: valore del pixel centrale confrontato con la media degli 8 pixel vicini. se:$$|\text{valore pixel} - \text{media}| > k$$ viene sostituito dal valore medio
> - filtro olimpico: dato un certo intorno si scartano max e min e si fa la media
## 10.6 Estrazione contorni
### intro
gli operatori locali sono utili ad estrarre i contorni da un immagine

I contorni sono definiti come delle discontinuità locali della luminanza.

Gli edge detector forniscono immagini in cui sono preservate le variazioni di luminanza ed eliminate tutte le altre informazioni.

>[!note] esempi di edge
>
>cambi intensità luminosa
>![[Pasted image 20240103152651.png]]
>- x: posizione x del pixel
>- y: luminosità


### tipi di filtri

#### basati sulla derivata prima
permettono di capire quando la funzione ha una variazione

> [!info] Sobel x/y
> $$
> \text{x-Sobel}=
> \begin{bmatrix}
> -1 & -2 & -1 \\
> 0 & 0 & 0 \\
> 1 & 2 & 1
> \end{bmatrix}
> $$
> $$
> \text{y-Sobel}=
> \begin{bmatrix}
> -1 & 0 & 1 \\
> -2 & 0 & 2 \\
> -1 & 0 & 1
> \end{bmatrix}
> $$

![[Pasted image 20240111171537.png]]
![[Pasted image 20240111171523.png]]

> [!info] Prewitt x/y
> $$
> \text{x-prewitt}=\begin{bmatrix}
> -1 & -1 & -1 \\
> 0 & 0 & 0 \\
> 1 & 1 & 1
> \end{bmatrix}
> $$
> $$
> \text{y-prewitt}=\begin{bmatrix}
> -1 & 0 & 1 \\
> -1 & 0 & 1 \\
> -1 & 0 & 1
> \end{bmatrix}
> $$

![[Pasted image 20240111171546.png]]
![[Pasted image 20240111171553.png]]

#attensionplis 
- i filtri "x" prediligono gli edge orizzontali, quelli "y" i verticali
- le matrici si possono combinare tramite la seguente formula
$$
\sqrt{ outputMatriceX^2+outputMatriceY^2 }
$$

#### basati sulla derivata seconda 
applicando la derivata seconda sulla funzione, in corrispondenza di un edge notiamo che passa per lo zero "zero crossing"

il kernel più diffuso è il laplaciano:
$$
\text{Laplaciano}= \begin{bmatrix}
-1 & 0 & -1 \\
0 & 4 & 0 \\
-1 & 0 & -1
\end{bmatrix}
$$
 >[!attention] attensionpls
 dopo aver applicato il laplaciano è necessario che si verifichi la condizione di "zero-crossing", ovvero deve accadere che nell'intorno di un pixel sia un valore positivo e uno negativo
>  ![[Pasted image 20240111174158.png]]

> [!example] determinare gli edge
> $$
> \text{output laplaciano = }\begin{bmatrix}
> 5 & 6 & 9 \\
> 7 & 8 & 9 \\
> -5 & -2 & -1
> \end{bmatrix}
> $$
> - le celle con 7,8,9 sono edge

![[Pasted image 20240111174715.png]]



## 10.7 filtri di sharpening 
filtri che incrementano la nitidezza di una immagine aumentando il contrasto locale
- evidenzia meglio i contorni
- aumenta anche il rumore

operazione opposta allo sfocamento

si usa un operatore derivato dal laplaciano

$$
\text{sharpening=}
\begin{bmatrix}
-1 & 0 & -1 \\
0 & 5 & 0 \\
-1 & 0 & -1
\end{bmatrix}
$$


# 11 Fourier 
## 11.1 intro 
Un’immagine può essere vista come una funzione discreta in due dimensioni i cui valori rappresentano il livello di grigio di un determinato pixel

può essere viste anche come somme di diverse onde sinusoidali semplici
![[Pasted image 20240112120000.png]]



il processo (fourier) si basa sul passaggio dalla base iniziale dell'immagine a quella di fourier, effettuando un cambio di dominio. sul dominio si fourier si effettuano delle operazioni per poi concludere applicando "l'antitrasformata" (operazione inversa trasformata) che permette di tornare al dominio iniziale dell'immagine
![[Pasted image 20240112120304.png]]
1. input immagine con eventuale pre processing
2. si applica la trasformazione di fourier ("processo di scomposizione in componenti elementari"
$$
f(x,y)=
\begin{bmatrix}
a_{1} & \dots  & \dots \\
	\dots  & \dots & \dots\ \\
	\dots & \dots & a_{n} \\
\end{bmatrix}
\overset{\text{trasformata}}{\implies}
F(x,y)=
\begin{bmatrix}
b_{1} & \dots  & \dots \\
	\dots  & \dots & \dots\ \\
	\dots & \dots & b_{n} \\
\end{bmatrix}
$$
$b_{1},\dots,b_{n}$: "coefficienti della trasformata", definiscono il contributo in frequenza del pixel.
si effettua un vero e proprio cambio di base (normal => base di fourier)
3. operazioni
4. inversa della trasformata
5. eventuale post processing

## 11.2 formula

> [!info] trasformata
> $$
> \huge
> F(u,v)=\frac{1}{MN}\sum^{M-1}_{x=0}\sum^{N-1}_{y=0}f(x,y)e^{-i2\pi(\frac{ux}{M}+\frac{vy}{N})}
> $$
> $\text{per } u=0,\dots,M-1 \quad v=0,\dots,N-1$
> - f(x,y): immagine
> - $MN$: dimensioni img
> - $u,v$: indici matrice di fourier (output)

> [!info] anti trasformata
> $$
> \Huge
> f(u,v)=\frac{1}{MN}\sum^{M-1}_{x=0}\sum^{N-1}_{y=0}F(x,y)e^{i2\pi(\frac{ux}{M}+\frac{vy}{N})}
> $$
> $\text{per } u=0,\dots,M-1 \quad v=0,\dots,N-1$

>[!attention] attensionpls
>per risolvere $\large e^{\pm i2\pi(\frac{ux}{M}+\frac{vy}{N})}$ bisogna usare la formula di eulero:
>$$e^{ix}=\cos x+i\sin x$$
>$$e^{-ix}=\cos x-i\sin x$$

ad esempio la matrice dopo il passaggio al dominio di fourier sarà della forma:
$$
F(u,v)=
\begin{bmatrix}
3+i{2} & 0 & 14 \\
1-i & 2 & 3 \\
15 & 2+i & 3+i5
\end{bmatrix}
$$
ogni componente rappresenta il contributo in frequenza, ma espressi in questo modo sono difficili da interpretare. Sarà necessario applicare delle operazioni.

### operazioni
> [!info] spettro trasformata
> $$
> |F(u,v)|=\sqrt{ Re^2(u,v)+Im^2(u,v) }
> $$
> - modulo del numero immaginario

> [!info] angolo di fase
> $$
> \phi(u,v)=\arctan(\frac{Im(u,v)}{Re(u,v)})
> $$
> - potrebbe capitare $\arctan\left( \frac{0}{0} \right)$ che non si potrebbe calcolare btw considerando che tende a 0 sarà uguale a $\frac{\pi}{2}$

> [!info] potrenza spettrale
> $$
> P(u,v)=|F(u,v)|^2
> $$
> - il modulo

![[Pasted image 20240112125335.png]]

> [!example] esempio a 1D
> sia $f:\{1,2,4,4\}$ calcolare la trasformata
> ![[Pasted image 20240112125002.png]]

#attensionplis 
- quando si visualizza lo spettro di fourier, esso manifesta una dinamica molto più grande di quella riproducibile dai display. in seguito ad una normalizzazione sarà necessario applicare l'operatore log per schiarirla
$$
D(u,v)=c\log(1+F(u,v))
$$

## 11.3 proprietà Trasformata a 2D
### separabilità
per avere una trasformazione a 2d posso applicare 2 volte quella a 1d
![[Pasted image 20240112125750.png]]

### traslazione
si sposta al centro il valore medio. i coefficenti relativi alle basse frequenze sono vicini al centro

la proprietà enuncia che anche se effettuo traslazioni lo spettro non cambia (lo spettro si concentra su quali sono le strutture, non dove sono)
![[Pasted image 20240112125911.png]]

> ![[Pasted image 20240109093329.png]]
> img=>trasformata+shift

### valore medio
la prima parte della formula generale (senza $e^{\dots}$) indica il valore medio della matrice in input
$$
F(u,v)=\frac{1}{MN}\sum^{M-1}_{x=0}\sum^{N-1}_{y=0}f(x,y)
$$
$$
f(u,v)=\frac{1}{MN}\sum^{M-1}_{x=0}\sum^{N-1}_{y=0}F(x,y)
$$
## 11.4 Teorema convoluzione
conviene lavorare sul dominio delle frequenze rispetto a quello spaziale per il teorema della convoluzione

> La trasformata della convoluzione di due segnali nel dominio spaziale equivale al prodotto delle trasformate dei due segnali

significa anche:
>La convoluzione di due segnali nel dominio spaziale equivale all’antitrasformata del prodotto delle trasformate dei due segnali.

ovvero, se volessi fare la convoluzione tra l'immagine $f$ ed un certo kernel $h$
$$
\begin{align}
& g(x,y)=f(x,y) \,\oplus \, h(x,y) & \text{(dominio spaziale)}
\end{align}
$$

se lo volessi fare nel dominio delle frequenze potrei fare la seguente
1. applicare la trasformata ad $F$ ed $H$ e fare il prodotto puntuale
$$
G(u,v)=F(u,v)H(u,v)
$$
	- F,H: trasformate di fourier delle funzioni
2. applicare l'antitrasformata su $G$
$$
g(x,y)=F^{-1}(G(u,v))
$$



## 11.5 Filtri nel dominio nelle frequenze
in generale è più efficiente lavorare con filtri che operano nel dominio delle frequenze
$$
\begin{align}
& \text{frequenze: }O(n\log n) \\
& \text{spaziale: }O(n^2)
\end{align}
$$

### low pass
"come la binarizzazio ne, solo che qua abbiamo un intorno"
$$
H(u,v)=
\begin{cases}
1 & D(u,v)\leq D_{0} \\
0 & \text{altrimenti}
\end{cases}
$$
- $D(u,v)=\sqrt{ \left( u-\frac{P}{2} \right)^2 +\left( v-\frac{Q}{2} \right)^2}$: frequenza candidata
- $D_{0}$: frequenza di taglio


![[Pasted image 20240113194259.png]]

### low pass di Butterworth
filtro low pass con passaggio graduale (non netto come quello normal)
$$
\huge
H(u,v)=\frac{1}{1+(\frac{D(u,v)}{D_{0}})^{2n}}
$$
![[Pasted image 20240113194733.png]]

### gaussiano
vantaggio di avere come trasformata sempre una gaussiana
$$
\huge
H(u,v)=e^{-D^2(u,v)/(2D_{0})^2}
$$
![[Pasted image 20240113194901.png]]

### passa alto
contrario passa basso.
ci sono sempre gli stessi tipo del lowpass
![[Pasted image 20240113195004.png]]
### band-reject
![[Pasted image 20240124095344.png]]

## 11.6 consideration
### Fast fourier transform
complessità fourier $O(n^2)$ => è stata creata la versione fast $O(n\log n)$
$$
\huge
F(u)=\frac{1}{N}\sum^{N-1}_{x=0}f(x)e^{\frac{-i2\pi ux}{N}}
$$
### a che serve
riempie i puntini lmao
![[Pasted image 20240113195051.png]]




# 12 Bit plane
## 12.1 intro
tecnica per la rappresentazione di immagini. Il bit plane di un'immagine digitale a $N$ bit, è un’insieme di $N$ immagini binarie (piani), in cui l’immagine i-esima contiene i valori dell’ i-esimo bit della codifica scelta.

>[!example] Esempio fasi rappresentazione bit-plane
> $$
> \begin{bmatrix}
> 2 & 10 \\
> 15 & 1
> \end{bmatrix}
> 
> \quad \overset{\text{conversione in binario puro}}{\implies} \quad
> 
> \begin{bmatrix}
> (0)\{0\}[1]0 & 1010 \\
> 1111 & 0001
> \end{bmatrix}
> $$
> si divide poi in $N$ matrici e si inseriscono i valori dal MSB (most significant bit) => LSB (least significant bit)
> 
> $$
> p_{0}=
> \begin{bmatrix}
> (0) & 1 \\
> 1 & 0
> \end{bmatrix}
> 
> \quad
> p_{1}=
> \begin{bmatrix}
> \{0\} & 0 \\
> 1 & 0
> \end{bmatrix}
> \quad
> p_{2}=
> \begin{bmatrix}
> [1] & 1 \\
> 1 & 0
> \end{bmatrix}
> \quad
> p_{3}=
> \begin{bmatrix}
> 0 & 0 \\
> 1 & 1
> \end{bmatrix}
> $$

>[!attention] attensionpls
>- utilizzando la codifica del binario puro i piani di bit più significativi cotengono info sulla struttura dell'immagine, mentre quelli meno significiativi forniscono piccoli dettagli.
>- la scomposizione in bit-planes tramite codifica in binario puro agevola la rimozione di certi livelli di grigio (per eliminare i grigi compresi tra 32 e 63 => pongo il 5° bit a zero).

>[!attention] Problema binario puro
>il binario puro ha il problema che anche se i numeri sono vicini possono cambiare tutti i bit
>$$0111111=127 \quad 1000000=128$$
>
>nelle immagini fotorealistiche è comune avere valori simili vicini.
>- soluzione: codice gray

## 12.2 Il codice gray
codifica che gode della proprietà per cui ogni codeword differisce dalla precedente per un solo bit (distanza di hamming = 1)

si effettua operazione di XOR (diversi 1, uguali 0)

![[Pasted image 20240115155554.png]]

>[!example] Conversione Binario => Gray
> 
> | decimale | binario puro | gray |
> | ---- | ---- | ---- |
> | 0 | 000 | 000 |
> | 1 | 001 | 001 |
> | 2 | 010 | 011 |
> | 3 | 011 | 010 |
> | 4 | 100 | 110 |
> | 5 | 101 | 111 |
> | 6 | 110 | 101 |
> | 7 | 111 | 100 |
> $$
> 
> \begin{align}
> 4_{gray}=&\,0 \oplus 0=0 &  & (a_{i} \oplus a_{i+1})\\
> =& 0 \oplus 1=1 \\
> =&1 & &  (\text{ricopio MSB})\\
> =& 110
> \end{align}
> $$

![[Pasted image 20240115160117.png]]

con il gray code i bit plane delle immagini risultano più coerenti. questo indica una minore entropia (sarà più semplice comprimere)

>[!attention] attensionplis
>non vale più la proprietà di eliminazione di range di colore
# 13 Compressione
## 13.1 intro
>[!note] compressione
si indica la tecnica di elaborazione dati che, tramite opportuni algoritmi, permette la riduzione della quantità di bit necessari alla rappresentazione in forma digitale di una informazione.
riduce le dimensioni di un file e l'occupazione di banda necessaria in una generica trasmissione dati digitale.

>[!note] dati ridondanti
>rappresentazioni che contengono informazioni irrilevanti o ripetute

>[!note] codice
>sistema di simboli usati per rappresentare una certà quantità di informazioni.
>- ad ogni pezzo di codice viene assegnata una sequenza di simboli "codeword"
>- il numero di simboli che costituisce ciascun codice è detto "lunghezza"

>[!attention] algortimo compressione
>tecnica che elimina la ridondanza di informazioni dai dati e consente un risparmio di memoria

![[Pasted image 20240115161259.png]]

in base al tipo di dato  (audio, video, generico) ci sono due tipi di compressione
- REVERSIBLE / LOSSLESS (senza perdita info): testo
- IRREVERSIBLE / LOSSY (eventuale perdita info): immagini

## 13.2 Compressione LOSSLESS
>[!note] definizione
>Si parla di compressione LOSSLESS quando i dati possono essere trasformati in modo da essere memorizzati con risparmio di memoria e successivamente ricostruiti perfettamente, senza errore e senza perdita di alcun bit di informazione.

si suppone che due pixel vicini possono essere simili (coerenza)

### Entropia dei dati

sia $f_{i}$ la frequenza di un carattere in un insieme di dati $S$:
$$
\huge
f_{i}=\frac{n_{\text{occorrenze}}}{N}
$$

- N: numero caratteri totali
"definiamo come Entropia della sequenza di dati, la quantità media di informazioni associata alla singola generazione di un simbolo nella sequenza $S$"
$$
\huge
E=-\sum f_{i}\log_{2}(f_{i}) \quad i \in S
$$
- $S$: sequenza di dati
> Più è grande l’incertezza della sequenza maggiore è l’entropia. Il massimo valore di entropia (e quindi di incertezza) lo si ha quando i simboli della sequenza sono equiprobabili.


>[!example] esempio lancio dadi
> $$
> \text{lancio dado: }\begin{cases}
> 	testa & \frac{1}{2} \\
> 		croce & \frac{1}{2}
> \end{cases}
> $$
> $$
> E=-\left( \underbrace{ \frac{1}{2}\log_{2}\left( \frac{1}{2} \right) }_{ \text{testa} } + \underbrace{ \frac{1}{2}\log_{2}\left( \frac{1}{2} \right) }_{ \text{croce} }\right)=-\left( -\frac{1}{2}-\frac{1}{2} \right)=1
> $$
> - ho bisogno di 1 bit per rappresentare un esito
> 
> 
> nel caso in cui il dado abbia le seguenti caratteristiche
> $$
> \text{lancio dado: }\begin{cases}
> 	testa & \frac{1}{8} \\
> 		croce & \frac{7}{8}
> \end{cases}
> $$
> 
> $$
> E=-\left( \underbrace{ \frac{1}{8}\log_{2}\left( \frac{1}{8} \right) }_{ \text{testa} } + \underbrace{ \frac{7}{8}\log_{2}\left( \frac{7}{8} \right) }_{ \text{croce} }\right)=-\left( -\frac{3}{8}-\frac{7}{8} \cdot 0.193 \right)=0,543
> $$
> - meno di un bit

>[!attention] attensionpls
1 bit: quantita d informazione necessaria in grado di distinguere due eventi equiprobabili
>

### Teorema di Shannon 
"per una sorgente discreta e a memoria zero, il bitrate minimo è pari all’entropia della sorgente"


>[!attention] attensionpls
> 1. discreto = numero di valori finiti
>
>
>2. memoria 0 = indipendenza eventi nel verificarsi tra succ. e prec.
>- img fotorealistica non è memoria 0 (coerenza stuff bro)
>

quindi per non avere perdita di informazioni devo usare un numero di bit pari a:
$$
N \cdot E
$$
- N: # caratteri
- E: entropia

shannon dice solo, serve un algoritmo per trovare quali bit usare => huffman
### Codice Huffman 
- codifica a lunghezza variabile che associa a simboli meno/più frequenti i codici più lunghi/corti (se gli eventi sono equiprobabili la lunghezza diventa fissa)
- nessun codice è prefisso di altri codici
- tende al limite di shannon

>[!example] Esempio Fasi algoritmo
> $$
> S=\text{AABABCAACAAADDDD}
> $$
> calcolo la frequenza di ogni lettera
> $$
> f_{a}=\frac{8}{16} \quad f_{b}=\frac{2}{16} \quad f_{c}=\frac{2}{16} \quad f_{d}=\frac{4}{16}
> $$
> 
> 1. creo i nodi
> ```mermaid
> graph TD;
> a((A:8/16))
> b((B:2/16))
> c((C:2/16))
> d((D:4/14))
> ```
> 2. prendo le freq più bassa e faccio questo nodo, sommando le freq
> ```mermaid
> 
> graph TD;
> a((a))
> x((4/16))-->b((B))
> x((4/16))-->c((C))
> d((d))
> ```
> 
> 3. itero fino ad avere le lettere come foglie
> ```mermaid
> 
> graph TD;
> a((a))
> y((8/16))-->x((4/16))
> y((8/16))-->d((D))
> x((4/16))-->b((B))
> x((4/16))-->c((C))
> d((d))
> ```
> 
> ```mermaid
> 
> graph TD;
> z((16/16))-->a((A))
> z((16/16))-->y((8/16))
> a((A))
> y((8/16))-->x((4/16))
> y((8/16))-->d((D))
> x((4/16))-->b((B))
> x((4/16))-->c((C))
> d((d))
> ```
> 4. si decide uno standard: dove mettere zero (se destra o sx), in questo caso a sx
>```mermaid
> 
> graph TD;
> z((16/16))-->|0|a((A))
> z((16/16))-->|1|y((8/16))
> a((A))
> y((8/16))-->|0|x((4/16))
> y((8/16))-->|1|d((D))
> x((4/16))-->|0|b((B))
> x((4/16))-->|1|c((C))
> d((d))
> ```
> si costruisce la seguente tabella:
> 
> | simbolo | codice |
> | ---- | ---- |
> | a | 0 |
> | b | 100 |
> | c | 101 |
> | d | 11 |

>[!example] Huffman con stringa gazzelle + VERIFICA SHANNON
> 
> $$
> S=\text{GAZZELLA}
> $$
> $$
> f_{a}=\frac{1}{8}
> $$
> $$
> f_{g}=\frac{2}{8}
> $$
> $$
> f_{z}=\frac{2}{8}
> $$
> $$
> f_{e}=\frac{1}{8}
> $$
> faccio grafo
>~meme~
> lo zero sta a destra
> 
> | sym | cod |
> | ---- | ---- |
> | g | 101 |
> | a | 01 |
> | z | 00 |
> | e | 100 |
> | l | 11 |
> 
> $gazzella_{\text{normal}} = 101010000100111101_{\text{huffman}} = 18bit$
> 
> bitrate minimo secondo shannon
> $$
> E=-\left( \frac{1}{8}\log_{2}\left( \frac{1}{8} \right) + \frac{2}{8}\log_{2}\left( \frac{2}{8} \right) + \frac{2}{8}\log_{2}\left( \frac{2}{8} \right) + \frac{1}{8}\log_{2}\left( \frac{1}{8} \right) + \frac{2}{8}\log_{2}\left( \frac{2}{8} \right) \right)
> $$
> $$
> E=2.25
> $$
> 
> $$
> \text{bitrateMIN}=N \cdot E = 8 \cdot 2.25=18\text{bit}
> $$
> - rispetta shannon

### Codifica Run-Length
le immagini che hanno delle ripetizioni di intensità lungo le righe/colonne possono essere compresse rappresentando tali sequenze (run) sottoforma di coppie di run-Length

>[!example] rappresentazione di 0000000111100
> 1. posso salvare singolarmente
> 2. oppure salvo (ricorrenza, tipo di dato)
> $$
> (7,0) \quad (4,1) \quad (3,0)
> $$

>[!attention] attensionpls
> 1. se ho solo 2 simboli, per ottimizzare posso salvare solo la ricorrenza
> $$
> (7,0) \quad (4,1) \quad (3,0) \implies (7)(4)(3)
> $$
> 2. certe volte peggiora (aumentando bit)

>[!hint] Uso run-length con bit-planes
![[Pasted image 20240115172033.png]]
> - ogni run length rappresenta una matrice

### Codifica differenziale
se la sequenza varia lentamente, basterà ricordarsi del valore iniziale e delle successive differenze
$$
\begin{align}
& 134, 137, 135, 128, 130, 134, 112, …  \\ \\

& \text{mi ricordo del valore 134 e calcolo le differenze} \\
 \\

& (134-137),(137-135),\dots \implies 3,2,\dots
\end{align}
$$

## 13.3 Compressione LOSSY
compressione che permette un maggiore risparmio di memoria ma ammette la perdita di informazioni

### requantization
algoritmo lossy basic.

per ogni canale di colore si prendono $n$ bit più significativi
data una rappresentazione a 24bit:
- RED: 8 bit => 4 
- GREEN: da 8 bit => 6
- BLUE: da 8 bit => 2

![[Pasted image 20240117154311.png]]

### jpeg
algoritmo diviso in fasi

#### 1. cambio spazio di colore
da RGB si passa a $YC_bC_r$

viene usato $YC_bC_r$ in quanto sfrutta maggiormente la luminanza ed è percettivamente uniforme


> [!note] RGB -> $YC_BC_R$
> $$
> \begin{align}
> & Y=0.300R+0.600G+0.100B \\
> & C_{b} = U +128= [600 \cdot (B-Y)]+128 \\
> & C_{r} = U +128= [700 \cdot (R-Y)]+128
> \end{align}
> $$

$$
\large
\text{Immagine}_{M x N}=
\begin{bmatrix}
R=\begin{bmatrix}
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
\end{bmatrix} \\
G=\begin{bmatrix}
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
\end{bmatrix} \\ 
B=\begin{bmatrix}
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
\end{bmatrix}
\end{bmatrix}

\implies

\begin{bmatrix}
Y=\begin{bmatrix}
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
\end{bmatrix} \\
C_{b}=\begin{bmatrix}
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
\end{bmatrix} \\ 
C_{r}=\begin{bmatrix}
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
\end{bmatrix}
\end{bmatrix}
$$
#attensionplis 
- questa operazione è ancora reversibile
- da ora in poi si lavora solo sulle matrici $Y,C_b,C_r$
#### 2. sottocampionamento matrici
La matrici Y rimane inalterata

per le matrici $C_b, C_r$ si sceglie un valore per ogni 4 pixel

$$
\large
\begin{bmatrix}
Y(\text{M x N})=\begin{bmatrix}
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
\end{bmatrix} \\
C_{b}(\text{M x N})=\begin{bmatrix}
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
\end{bmatrix} \\ 
C_{r}(\text{M x N})=\begin{bmatrix}
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
\end{bmatrix}
\end{bmatrix}

\implies

\begin{bmatrix}
Y(\text{M x N})=\begin{bmatrix}
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
\end{bmatrix} \\
C_{b}(\frac{M}{2}\text{ x }\frac{N}{2})=\begin{bmatrix}
		\dots & \dots \\
		\dots & \dots \\
\end{bmatrix} \\ 
C_{r}(\frac{M}{2}\text{ x }\frac{N}{2})=\begin{bmatrix}
		\dots & \dots \\
		\dots & \dots \\
\end{bmatrix}
\end{bmatrix}


$$

#### 3. amici quadrotti
partizione delle matrici in "quadrotti" di dimensione 8x8

a quadrotti diversi corrisponderanno differenti operazioni, da qui nasce il problema della "quadrettatura". se la compressione è elevata l'immagine cringia
![[Pasted image 20240117161241.png]]

$$
\begin{bmatrix}
Y(\text{M x N})=\begin{bmatrix}
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
\end{bmatrix} \\ \\

C_{b}(\frac{M}{2}\text{ x }\frac{N}{2})=\begin{bmatrix}
		\dots & \dots \\
		\dots & \dots \\
\end{bmatrix} \\  \\

C_{r}(\frac{M}{2}\text{ x }\frac{N}{2})=\begin{bmatrix}
		\dots & \dots \\
		\dots & \dots \\
\end{bmatrix}
\end{bmatrix}

\implies

\begin{bmatrix}
Y=\begin{bmatrix}
		\begin{bmatrix}\dots\end{bmatrix}_{\text{8 x 8}} & \dots & \begin{bmatrix}\dots\end{bmatrix}_{\text{8 x 8}} &  \\
 
	\dots & \dots & \dots \\
	\dots & \dots & \dots \\
		\begin{bmatrix}\dots\end{bmatrix}_{\text{8 x 8}} & \dots & \begin{bmatrix}\dots\end{bmatrix}_{\text{8 x 8}} &  \\

\end{bmatrix} \\ \\

C_{b}(\frac{M}{2}\text{ x }\frac{N}{2})=\begin{bmatrix}
		\begin{bmatrix}\dots\end{bmatrix}_{\text{8 x 8}} & \begin{bmatrix}\dots\end{bmatrix}_{\text{8 x 8}} &  \\
		\begin{bmatrix}\dots\end{bmatrix}_{\text{8 x 8}} & \begin{bmatrix}\dots\end{bmatrix}_{\text{8 x 8}} &  \\
\end{bmatrix} \\  \\

C_{r}(\frac{M}{2}\text{ x }\frac{N}{2})=\begin{bmatrix}
		\begin{bmatrix}\dots\end{bmatrix}_{\text{8 x 8}} & \begin{bmatrix}\dots\end{bmatrix}_{\text{8 x 8}} &  \\
		\begin{bmatrix}\dots\end{bmatrix}_{\text{8 x 8}} & \begin{bmatrix}\dots\end{bmatrix}_{\text{8 x 8}} &  \\
\end{bmatrix}
\end{bmatrix}


$$

#attensionplis 
- da ora in poi lavoro solo nei blocchetti. è anche un male perché potrebbe portare ad artefatti (lavorando ai singoli blocchi e non guardando nell'intorno, potrei fare operazioni che vanno in contrasto)

#### 4. shift di livelli di grigio
sottraggo 128 ad ogni 
$$
\begin{align}
& 128-Y \\
& 128-C_{b}\\
& 128-C_{r}
\end{align}
$$

#### 5. si applica la DCT
DCT: Discrete Cosine Transform

passo dal dominio spaziale a quello delle frequenze. si usa questa perché non lavora coi complessi.

>[!note] Formula
> $$
> F(u,v)=\frac{2}{N}\left[  \sum^{x=0}_{N-1}\sum^{y=0}_{N-1}  C(u)C(v)f(x,y) \cdot \cos \frac{(2x+1)u \pi}{2 } \cdot \cos \frac{(2y+1)v \pi}{2 } \right]
> $$
> $$
> C(u)=\begin{cases}
> \frac{1}{\sqrt{ 2 }} & u=0 \\
> 1  & \text{altrimenti}
> \end{cases}
> 
> \quad
> 
> C(v)=\begin{cases}
> \frac{1}{\sqrt{ 2 }} & v=0 \\
> 1  & \text{altrimenti}
> \end{cases}
> $$

#attensionplis 
- nel punto (0,0) si ha la media (applicando la formula si capisce mbare)
- i numeri della matrice ottenuta dalla DCT li considero come coefficienti che devono essere moltiplicati alle base della DCT (non canonica).

coefficiente in alto a sx prendono il nome di "DC"
- valore medio
gli altri "AC"


#### 6. Quantizzazione
per ogni cubo faccio divisione puntuale per una matrice Q
$$
\text{cubo 8x8= }
\begin{bmatrix}
	DC & \dots & \dots \\
\dots \\
\dots
\end{bmatrix}

\quad\underset{ \text{puntuale} }{ \divsymbol }\quad

Q=\begin{bmatrix}
	\dots & \dots & \dots \\
\dots \\
\dots
\end{bmatrix}
$$
- in base alla qualità di salvataggio si sceglie una Q apposita (standard)

#### 7. codifica zigzag
in ordine zig zag (metta in sequenza gli zeri ravvicinati) serve per applicare run lent
![[Pasted image 20240116104008.png]]

avro' array del tipo:$\begin{bmatrix}[DC],\quad \underbrace{ \dots \dots \dots }_{ [AC] }\end{bmatrix}$

#### 8. codifico gli AC/DC

> [!example] codifica DC
> prendo i DC di tutti gli array e faccio la codifica differenziale
> 
> assumendo che il primo DC sia -26
> $$
> DC_{1}=-26 \quad 
> DC_{2}=-17
> $$
> 
> calcolo $\Updelta=DC_{i}-DC_{i+1}$:
> $$
> \Updelta=-26-(-17)=-9
> $$
> 
> vado a confrontare il valore di $\Updelta$ nella tabella seguente, e prendo il codice SSSS (categoria) corrispondente
> ![[Pasted image 20240117163518.png]]
> SSSS ha due funzioni:
> 1. lo andremo a confrontare in un'altra tabella che lo associerà un codice di base
> ![[Pasted image 20240117163722.png]]
> 2. fornirà il numero di bit mancanti alla codifica
> 
> $$
> \begin{align}
> & \Updelta=-9 \\
> & SSSS=4 \\
> \end{align}
> 
> $$
> $$
> 4\text{ bit mancanti} \quad \text{codice base}=101
> $$
> i bit mancanti saranno riempiti in base al valore di $\Updelta$
> - $\Updelta>0$: aggiunta $n$ bit meno significativi del valore $\Updelta$ in binario
> - $\Updelta<0$: aggiunta $n$ bit complemento a 1 del $\Updelta$
> - $\Updelta=0$: non si aggiungono bit
> 
> $$
> -9_{10}=1001_{2}=\underbrace{ 0110_{c_{1}} }_{ \text{scambio bit} }
> $$
> $$
> DC_{1}=\underbrace{ 101 }_{ \text{cod base } }\underbrace{ 0110 }_{ \text{ codifica} }
> $$
> 


> [!example] codifica AC
> si usa la transformazione in skip value
> 
> "x zeri seguiti dal valore v"
> $$
> \begin{align}
> & 0,0,0,0,11,0,0,0,3,0,0,0,0,0,0,0,0,12,17… \\
> & (4,11),(3,3),(8,12),(0,17),…
> \end{align}
> $$
> 
> 
> avendo coppie del tipo $(x,AC)$, prendo il valore SSSS corrispondente:
> ![[Pasted image 20240117170447.png]]
> creo adesso la coppia $(x,SSSS)$ e gli associa il codice di base (uguale a DC)
> ![[Pasted image 20240117171057.png]]
> 
> ora si aggiungono AC=n bit da aggiungere:
> - $AC>0$: aggiunta $n$ bit meno significativi del valore $\Updelta$ in binario
> - $AC<0$: aggiunta $n$ bit complemento a 1 del $\Updelta$
> - $AC=0$: non si aggiungono bit
> 
> data la coppia (0,1):
> $$
> (0,1)\implies SSSS=1
> $$
> 
> vado a cercare nella seconda tabe la copppia $(0,SSSS)=(0,1)$
> $$
> (0,1)=[00]_{\text{codice base}}
> $$
> $$
> AC>0\implies 1_{10}=1_{2}
> $$
> 
> $$
> (0,1)=001
> $$
> 

#attensionplis 
- Le tabelle usate forniscono i codici di Huffmann ottenuti sulla base di calcoli statistici preventivi e sono fornite dallo standard.

#### 9. ricostruzione dati
si torna indietro ai dati originali.

come si fa? => non trattato dal corso kek

#attensionplis 
esiste una versione più recente di questo algoritmo: JPEG200
- effettua una wavelet decomposition (non divide in amici quadrotti)
- maggiore compressione


>[!question] domande
>1. dati due valori DC/AC codificarli.
>2. altri tipi di decomposizioni?



##### 3 - formule & stuff


# mse
![[Pasted image 20231025181104.png|1000]]
# psnr
![[Pasted image 20231201153105.png]]

# coni bastoncelli
coni: 6/7 milioni, vista policroma/fototica 
- parte centrale retina (fovea)
bastoncelli: 75/150 milioni vista scotopica
- parte laterale retina

# lente sottile
$$
\frac{1}{u}+\frac{1}{v}=\frac{1}{f}
$$

$$
\text{1 diottria} = \frac{1}{f}
$$

# magnificazione
fattore magnificazione
$$
\frac{h}{k} = \frac{v}{u}=\text{m}
$$

fuoco con un certo fattore di magnificazione
$$
f=\frac{u \cdot m}{m+1}
$$

# Campionamento
**campionamento**
> partendo da un segnale continuo ne formo uno discreto
> 
> bisogna scegliere un numero finito di campioni

# quantizzazione
> processo di mappatura dei valori in ingresso analogici da un insieme non limito ad uno limitato
> 
> #ex mappatura del segnale in 8bit

$$L'=\frac{L \cdot K}{N}$$
> $$
 0 : 255 = 0 : 7
 $$
> se voglio inserire il valore 10:
> $$
 10:255=x:7\implies \frac{70}{255}=0
 $$

#### logaritmica
$$
L' = \frac{\log_{2}L \cdot K}{N}
$$

## riquantizzazione
uniforme
$$
f(\text{valoreLvl}_{new}, k_{new,k_{old}})=\lfloor\frac{\text{valoreLivello}_{old}*k_{new}}{k_{old}}\rfloor
$$

log
$$
f(\text{valoreLvl}_{new}, k_{new,k_{old}})=\lfloor\frac{\log_{2}{(\text{valoreLvl}_{new})}*k_{new}}{\log_{2}{(k_{old})}}\rfloor
$$


# XYZ

> $L_{e}(\lambda)=\text{lunghezza d'onda da misurare}$
> $\bar{x}(\lambda)=\text{onda di riferimento del rosso}$
> 
> $780 - 380=\text{frequenza in cui si può trovare il rosso}$
> 
> con l'integrale si va a calcolare l'area di quella regione sottesa
> 
> $$X=\int^{780}_{{380}}{L_{e}(\lambda)}\bar{x}(\lambda)\, d\lambda $$

# xyz 1931

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
 x=1-y-z
 $$
> $$
 y=1-x-z
 $$
> $$
 z=1-x-y
 
 $$ 

al variare di x e y si da origine al diagramma cromatico CIE
> valori lunghezza d'onda disposti lungo i bordi.
> 
> il punto in cui i colori hanno la stessa energia è bianco.
> ai bordi i colori non hanno bianco (puro).
> ![[Pasted image 20231114160553.png|400]]

#attensionplis 
1. unendo 2 colori con una linea => tutti i possibili colori ottenibili mischiandoli
2. unendo un colore al bianco => tutte le sfumutare

# cie LAB

#ex:CIE $La^*b^*$
> $\Updelta=\text{someting}L_{1}- \text{someting}L_{2}$
> ![[Pasted image 20231114165658.png]]
> 
> $$
 C_{1}=(10,20,30)
 $$
> $$
 C_{2}=(11,21,31)
 $$
> 
> $$
 \Updelta E = \sqrt{ (10-11)^2 + (20-21)^2 +(30-31)^2}=\sqrt{ 1+1+1 } = \sqrt{ 3 }
 $$


# hSV
![[Pasted image 20231115163546.png|600]]


# colori sicuri
formati da 3 valori RGB composti da 2 numeri esadecimali
- 00 - 33 - 66 - 99 - CC - FF

# yuv
Y=0,300R + 0,600G+ 0,100B
$$
U = 0.564(B-Y)
$$
$$
V=0.713(R-Y)
$$

# ycbcbr
$$
Y=0.299R+0.587+0.114B
$$
$$
C_{b}=U+128
$$
$$
C_{r}=V+128
$$

# operatori puntuali
## normalizzazione 
$$\huge
v_{new}=255 \cdot \frac{val_{old}-val_{min}}{val_{max}-val_{min}}$$

## equalizzazione

> [!note] Numero di pixel in valori relativi
> $$p_{r}(r_{k})=\frac{n_{k}}{MN} \quad k = 0,1,2,\dots ,L-1$$
> - $r_{k}$ = un livello di grigio
> - $n_k$ = numero di pixel dell'immagine rispetto al livello $r_k$
> - $MN$ = dimensione matrice immagine

> [!important] Algoritmo equalizzazione
> $$
> \begin{align}
> s_{k}&=T(r_{k})\\
>  &=(L-1) \sum^{k}_{j=0}p_{r}(r_{j})\\
>  &=(L-1)\sum^{k}_{j=0} \frac{n_{j}}{MN} \quad k = 0,1,2,\dots,L-1
> \end{align}
> $$
> - $s_{k}$ = livello normalizzato
> - $L$ = numero di livelli disponibili nell'immagine
>   
>   per ogni livello calcolo il suo valore equalizzato tramite la formula

>[!example] Esempio equalizzazione
 Dato un immagine a 3 bit con dimensioni $MN = 64$, ed il seguente istogramma:
> 
> $$
> H=[0][4][16][8][4][32][16][16]
> $$
> equalizzare.
> 
> $$
> H_{\text{normalizzato}}=\left[ \frac{n_{k_{1}}}{MN} \right]\left[ \frac{n_{k_{2}}}{MN} \right] [\dots] \left[ \frac{n_{k_{n}}}{MN} \right]
> $$
> $$
> \begin{align}
> &&&&&&=\left[ \frac{0}{64} \right]\left[ \frac{4}{64} \right]\left[ \frac{16}{64} \right][\dots]\left[ \frac{16}{64} \right]
> \end{align}
> $$
> 
> $$
> \begin{align}
> &&&&&&&&&&&&=[0][0,06][0,25][0,125][0,06][0,5][0,25][0,25]
> \end{align}
> $$
> 
> applicare l'algoritmo:
> $$
> s_{k}=(L-1)\sum^{k}_{j=0} \frac{n_{j}}{MN}
> $$
> 
> - $s_{0}=(8-1) \sum^{0}_{j=0}0=0$
> - $s_{1}=(8-1) \sum^{1}_{j=0}\frac{n_{j}}{MN}=7 \cdot (0 + 0,06)=0,42$
> - $s_{2}=(8-1) \sum^{2}_{j=0}\frac{n_{j}}{MN}=7 \cdot (0 + 0,06+0,25)=7 \cdot 0,31=2,17$
> - $\dots$  
>
>si procede così per tutti i livelli dell'immagine e si avrà
> - $s_{0}=0$
> - $s_{1}=0,42$
> - $s_{2}=2,17$
> - $\dots$
> 
> si arrotondano i valori e si procede a modificare i valori dei pixel (immagine iniziale) rendendoli equalizzati
> - valore 0 = $s_{0}$
> - valore 1 = $s_{1}$
> - ecc...
## trasformazioni logaritmica
$$
g(x,y)=c \cdot \log_{2}(1+f(x,y))
$$
> [!attention] attensionplis
> $$
> f(x,y) \in [0,255]
> $$
> $$
> g(x,y)=\log(1+f(x,y)) \in [0,8]
> $$
>vogliamo che $g(x,y)$ sia nel range di $f(x,y)$, allora gli moltiplichiamo la $c$
>
>$$c=\frac{255}{\log_{2}(1 + (L-1))}=\frac{255}{\log_{2}(8)}=\frac{255}{3}$$
>
>$$g(x,y) \in [0,8] \quad\underset{ \text{moltiplico la c} }{ \implies }\quad  g(x,y) \cdot c \quad\implies \quad g(x,y) \in [0,255]$$

## trasformazione potenza
$$
g(x,y)=c \cdot (f(x,y))^\gamma
$$
$$
f(x,y) \in [0,255^\gamma]
$$

per normalizzarlo si moltiplica per $c$
>$$c=\frac{255}{255^\gamma}=\frac{1}{255^{\gamma - 1}}$$

## binarizzazione
$$
g(x,y)=\begin{cases}1 & f(x,y) \geq T \\
0 & f(x,y)<T
\end{cases}
$$

# Convoluzioni
## operatore lineare
$$
 a \cdot F(x_{1},y_{1})+b \cdot F(x_{2},y_{2})=F(ax_{1}+by_{1}+ay_{1}+by_{2})
$$
## convoluzione
![[Pasted image 20240122174821.png]]
![[Pasted image 20240122174826.png]]


## rumore

### sale pepe
>[!example] "probabilità pz che si trasformi in ... è"
> $$
> p(z)=\begin{cases}
> 0.1 & z=0 \\
> 0.3 & z=255 \\
> 0 & \text{altrimenti} 
> \end{cases}
> $$
> - 10% che pixel diventi nero
> - 30% bianco
> - 60% non succede niente (prob. che diventi)
> $$
> p(34)=0 \quad\quad p(200)=0 \quad\quad p(0)=0.1
> $$
> 
> devo scrivere solo probabilità che un pixel sia alto o basso, non i valori medi

### gaussiano
> [!info] Dato dalla seguente formula
> $$
> \huge
> p(z)=\frac{1}{\sqrt{ 2 \pi }\sigma}e^{-\frac{(z-\overset{\_}{z})}{2\sigma^2}}
> $$
> - $z$: l'intensità
> - $\overline{z}$: valore medio (massima probabilità di verificarsi, tendenzialmente è zero)
> - $\sigma$ = quanto è ampia la forma a campana della gaussiana
> 
> "probabilità che un pixel abbia uno scostamento di intensità pari a $z$"


### altri
![[Pasted image 20240122180331.png]]

### Estrazione contorni

#### derivata prima
> [!info] Sobel x/y
> $$
> \text{x-Sobel}=
> \begin{bmatrix}
> -1 & -2 & -1 \\
> 0 & 0 & 0 \\
> 1 & 2 & 1
> \end{bmatrix}
> $$
> $$
> \text{y-Sobel}=
> \begin{bmatrix}
> -1 & 0 & 1 \\
> -2 & 2 & 2 \\
> -1 & 0 & 1
> \end{bmatrix}
> $$

> [!info] Prewitt x/y
> $$
> \text{x-prewitt}=\begin{bmatrix}
> -1 & -1 & -1 \\
> 0 & 0 & 0 \\
> 1 & 1 & 1
> \end{bmatrix}
> $$
> $$
> \text{y-prewitt}=\begin{bmatrix}
> -1 & 0 & 1 \\
> -1 & 0 & 1 \\
> -1 & 0 & 1
> \end{bmatrix}
> $$

#attensionplis 
- i filtri "x" prediligono gli edge orizzontali, quelli "y" i verticali
- le matrici si possono combinare tramite la seguente formula
$$
\sqrt{ outputMatriceX^2+outputMatriceY^2 }
$$

#### derivata seconda
$$
\text{Laplaciano}= \begin{bmatrix}
-1 & 0 & -1 \\
0 & 4 & 0 \\
-1 & 0 & -1
\end{bmatrix}
$$
 >[!attention] attensionpls
 dopo aver applicato il laplaciano è necessario che si verifichi la condizione di "zero-crossing", ovvero deve accadere che nell'intorno di un pixel sia un valore positivo e uno negativo
>  ![[Pasted image 20240111174158.png]]

### sharpening
$$
\begin{bmatrix}
-1 & 0 & -1 \\
0 & 5 & 0 \\
-1 & 0 & -1
\end{bmatrix}
$$

# fourier
> [!info] trasformata
> $$
> \huge
> F(u,v)=\frac{1}{MN}\sum^{M-1}_{x=0}\sum^{N-1}_{y=0}f(x,y)e^{-i2\pi(\frac{ux}{M}+\frac{vy}{N})}
> $$
> $\text{per } u=0,\dots,M-1 \quad v=0,\dots,N-1$
> - f(x,y): immagine
> - $MN$: dimensioni img
> - $u,v$: indici matrice di fourier (output)

> [!info] anti trasformata
> $$
> \Huge
> f(u,v)=\frac{1}{MN}\sum^{M-1}_{x=0}\sum^{N-1}_{y=0}F(x,y)e^{i2\pi(\frac{ux}{M}+\frac{vy}{N})}
> $$
> $\text{per } u=0,\dots,M-1 \quad v=0,\dots,N-1$

>[!attention] attensionpls
>per risolvere $\large e^{\pm 2i\pi(\frac{ux}{M}+\frac{vy}{N})}$ bisogna usare la formula di eulero:
>$$e^{ix}=\cos x+i\sin x$$

### operazioni
> [!info] spettro trasformata
> $$
> |F(u,v)|=\sqrt{ Re^2(u,v)+Im^2(u,v) }
> $$
> - modulo del numero immaginario

> [!info] angolo di fase
> $$
> \phi(u,v)=\arctan(\frac{Im(u,v)}{Re(u,v)})
> $$
> - potrebbe capitare $\arctan\left( \frac{0}{0} \right)$ che non si potrebbe calcolare btw considerando che tende a 0 sarà uguale a $\frac{\pi}{2}$

> [!info] potrenza spettrale
> $$
> P(u,v)=|F(u,v)|^2
> $$

### convoluzione fourier
se lo volessi fare nel dominio delle frequenze potrei fare la seguente
1. applicare la trasformata ad $F$ ed $H$ e fare il prodotto puntuale
$$
G(u,v)=F(u,v)H(u,v)
$$
	- F,H: trasformate di fourier delle funzioni
2. applicare l'antitrasformata su $G$
$$
g(x,y)=F^{-1}(G(u,v))
$$


### low pass
"come la binarizzazione, solo che qua abbiamo un intorno"
$$
H(u,v)=
\begin{cases}
1 & D(u,v)\leq D_{0} \\
0 & \text{altrimenti}
\end{cases}
$$
- $D(u,v)=\sqrt{ \left( u-\frac{P}{2} \right)^2 +\left( v-\frac{Q}{2} \right)^2}$: frequenza candidata
- $D_{0}$: frequenza di taglio
#### low pass di Butterworth
filtro low pass con passaggio graduale (non netto come quello normal)
$$
\huge
\huge
H(u,v)=\frac{1}{1+(\frac{D(u,v)}{D_{0}})^{2n}}
$$

#### gaussiano
vantaggio di avere come trasformata sempre una gaussiana
$$
\huge
\huge
H(u,v)=e^{-D^2(u,v)/(2D_{0})^2}
$$

### passa alto
![[Pasted image 20240113195004.png]]

### band reject
![[Pasted image 20240124095344.png]]

### fft fast fourier trans
O(nlogn)
$$
\huge
F(u)=\frac{1}{N}\sum^{N-1}_{x=0}f(x)e^{\frac{-i2\pi ux}{N}}
$$



# bit plane
### whats
>[!example] Esempio fasi rappresentazione bit-plane
> $$
> \begin{bmatrix}
> 2 & 10 \\
> 15 & 1
> \end{bmatrix}
> 
> \quad \overset{\text{conversione in binario puro}}{\implies} \quad
> 
> \begin{bmatrix}
> (0)\{0\}[1]0 & 1010 \\
> 1111 & 0001
> \end{bmatrix}
> $$
> si divide poi in $N$ matrici e si inseriscono i valori dal MSB (most significant bit) => LSB (least significant bit)
> 
> $$
> p_{0}=
> \begin{bmatrix}
> (0) & 1 \\
> 1 & 0
> \end{bmatrix}
> 
> \quad
> p_{1}=
> \begin{bmatrix}
> \{0\} & 0 \\
> 1 & 0
> \end{bmatrix}
> \quad
> p_{2}=
> \begin{bmatrix}
> [1] & 1 \\
> 1 & 0
> \end{bmatrix}
> \quad
> p_{3}=
> \begin{bmatrix}
> 0 & 0 \\
> 1 & 1
> \end{bmatrix}
> $$

### codice gay
![[Pasted image 20240115155554.png]]


# compression
## Entropia dei dati

sia $f_{i}$ la frequenza di un carattere in un insieme di dati $S$:
$$
\huge
f_{i}=\frac{n_{\text{occorrenze}}}{N}
$$

- N: numero caratteri totali
"definiamo come Entropia della sequenza di dati, la quantità media di informazioni associata alla singola generazione di un simbolo nella sequenza $S$"
$$
\huge
E=-\sum f_{i}\log_{2}(f_{i}) \quad i \in S
$$
- $S$: sequenza di dati

## Teorema di Shannon 
quindi per non avere perdita di informazioni devo usare un numero di bit pari a:
$$
N \cdot E
$$
- N: # caratteri
- E: entropia

## huffman
>[!example] Esempio Fasi algoritmo
> $$
> S=\text{AABABCAACAAADDDD}
> $$
> calcolo la frequenza di ogni lettera
> $$
> f_{a}=\frac{8}{16} \quad f_{b}=\frac{2}{16} \quad f_{c}=\frac{2}{16} \quad f_{d}=\frac{4}{16}
> $$
> 
> 1. creo i nodi
> ```mermaid
> graph TD;
> a((A:8/16))
> b((B:2/16))
> c((C:2/16))
> d((D:4/14))
> ```
> 2. prendo le freq più bassa e faccio questo nodo, sommando le freq
> ```mermaid
> 
> graph TD;
> a((a))
> x((4/16))-->b((B))
> x((4/16))-->c((C))
> d((d))
> ```
> 
> 3. itero fino ad avere le lettere come foglie
> ```mermaid
> 
> graph TD;
> a((a))
> y((8/16))-->x((4/16))
> y((8/16))-->d((D))
> x((4/16))-->b((B))
> x((4/16))-->c((C))
> d((d))
> ```
> 
> ```mermaid
> 
> graph TD;
> z((16/16))-->a((A))
> z((16/16))-->y((8/16))
> a((A))
> y((8/16))-->x((4/16))
> y((8/16))-->d((D))
> x((4/16))-->b((B))
> x((4/16))-->c((C))
> d((d))
> ```
> 4. si decide uno standard: dove mettere zero (se destra o sx), in questo caso a sx
>```mermaid
> 
> graph TD;
> z((16/16))-->|0|a((A))
> z((16/16))-->|1|y((8/16))
> a((A))
> y((8/16))-->|0|x((4/16))
> y((8/16))-->|1|d((D))
> x((4/16))-->|0|b((B))
> x((4/16))-->|1|c((C))
> d((d))
> ```
> si costruisce la seguente tabella:
> 
> | simbolo | codice |
> | ---- | ---- |
> | a | 0 |
> | b | 100 |
> | c | 101 |
> | d | 11 |

## dCT
>[!note] Formula
> $$
> F(u,v)=\frac{2}{N}\left[  \sum^{x=0}_{N-1}\sum^{y=0}_{N-1}  C(u)C(v)f(x,y) \cdot \cos \frac{(2x+1)u \pi}{2 } \cdot \cos \frac{(2y+1)v \pi}{2 } \right]
> $$
> $$
> C(u)=\begin{cases}
> \frac{1}{\sqrt{ 2 }} & u=0 \\
> 1  & \text{altrimenti}
> \end{cases}
> 
> \quad
> 
> C(v)=\begin{cases}
> \frac{1}{\sqrt{ 2 }} & v=0 \\
> 1  & \text{altrimenti}
> \end{cases}
> $$

1. rgb -> ycbcr
2. sottocampionamento
	1. sottocampiona (dim/2: 1 ogni 4) (non di Y)
	2. amici quadrotti (8x8)
3. shift livelli grigi
	1. 128 - Y,Cb,Cr
4. DCT su tutte le matrici
5. quantizzazione
	1. divisione puntuale per matrici Q + DC, AC
6. codifica DC AC
	1. matrici -> array
	2. codifica DC
	3. codifica AC


> [!example] codifica DC
> prendo i DC di tutti gli array e faccio la codifica differenziale
> 
> assumendo che il primo DC sia -26
> $$
> DC_{1}=-26 \quad 
> DC_{2}=-17
> $$
> 
> calcolo $\Updelta=DC_{i}-DC_{i+1}$:
> $$
> \Updelta=-26-(-17)=-9
> $$
> 
> vado a confrontare il valore di $\Updelta$ nella tabella seguente, e prendo il codice SSSS (categoria) corrispondente
> ![[Pasted image 20240117163518.png]]
> SSSS ha due funzioni:
> 1. lo andremo a confrontare in un'altra tabella che lo associerà un codice di base
> ![[Pasted image 20240117163722.png]]
> 2. fornirà il numero di bit mancanti alla codifica
> 
> $$
> \begin{align}
> & \Updelta=-9 \\
> & SSSS=4 \\
> \end{align}
> 
> $$
> $$
> 4\text{ bit mancanti} \quad \text{codice base}=101
> $$
> i bit mancanti saranno riempiti in base al valore di $\Updelta$
> - $\Updelta>0$: aggiunta $n$ bit meno significativi del valore $\Updelta$ in binario
> - $\Updelta<0$: aggiunta $n$ bit complemento a 1 del $\Updelta$
> - $\Updelta=0$: non si aggiungono bit
> 
> $$
> -9_{10}=1001_{2}=\underbrace{ 0110_{c_{1}} }_{ \text{scambio bit} }
> $$
> $$
> DC_{1}=\underbrace{ 101 }_{ \text{cod base } }\underbrace{ 0110 }_{ \text{ codifica} }
> $$
> 


> [!example] codifica AC
> si usa la transformazione in skip value
> 
> "x zeri seguiti dal valore v"
> $$
> \begin{align}
> & 0,0,0,0,11,0,0,0,3,0,0,0,0,0,0,0,0,12,17… \\
> & (4,11),(3,3),(8,12),(0,17),…
> \end{align}
> $$
> 
> 
> avendo coppie del tipo $(x,AC)$, prendo il valore SSSS corrispondente:
> ![[Pasted image 20240117170447.png]]
> creo adesso la coppia $(x,SSSS)$ e gli associa il codice di base (uguale a DC)
> ![[Pasted image 20240117171057.png]]
> 
> ora si aggiungono AC=n bit da aggiungere:
> - $AC>0$: aggiunta $n$ bit meno significativi del valore $\Updelta$ in binario
> - $AC<0$: aggiunta $n$ bit complemento a 1 del $\Updelta$
> - $AC=0$: non si aggiungono bit
> 
> data la coppia (0,1):
> $$
> (0,1)\implies SSSS=1
> $$
> 
> vado a cercare nella seconda tabe la copppia $(0,SSSS)=(0,1)$
> $$
> (0,1)=[00]_{\text{codice base}}
> $$
> $$
> AC>0\implies 1_{10}=1_{2}
> $$
> 
> $$
> (0,1)=001
> $$
> 
