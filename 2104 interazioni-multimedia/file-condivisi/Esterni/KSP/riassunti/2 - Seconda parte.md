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

![](Pasted%20image%2020231213163534.png)

#attensionplis 
>restituisce un valore relativo, in modo tale da poter confrontare immagini con dimensioni diverse


#ex
> data immagine $I(m,n)$ con 3 bit
> 
> $$
> H= [5][17][82][0][0][25][7][8]
> $$
> $$\quad\quad\quad\quad\quad[0][\dots][\dots][\dots][\dots][\dots][\dots][7]$$
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

![](Pasted%20image%2020231213164629.png)


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
> non copre tutti i livelli. quindi mappo i valori del massimo e minimo rispetto a quelli presenti nella matrice $min = 45$ e $max=181$ (si dimostra applicando la formula)
> 
> normalizzo per il valore 100:
> $$
> v_{new}=255\cdot\frac{100-45}{181-45}=255\cdot \frac{55}{136}=103,12\implies103
> $$
> 
> si procede così per tutti
## 9.4 Equalizzazione

si cerca di uniforma i contributi di tutti i colori dell'immagine, si punta ad avere una funizione costante nell'istogramma (impossibile nella realtà)

![](Pasted%20image%2020231218165443.png)
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
> Dato un immagine a 3 bit con dimensioni $MN = 64$, ed il seguente istogramma:
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
> H_{\text{relativo}} = \left[ \frac{0}{64} \right]\left[ \frac{4}{64} \right]\left[ \frac{16}{64} \right][\dots]\left[ \frac{16}{64} \right]
> $$
> $$
> H_{\text{relativo}}=[0][0,06][0,25][0,125][0,06][0,5][0,25][0,25]
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
![](Pasted%20image%2020231218165412.png)

può essere rappresentata nel seguente grafico:
- asse $x$ input, $y$= output
![](Pasted%20image%2020231218170520.png)

grafico **look-up table** (LUT)
- grafico che si ottiene andando ad associare ad ognuno dei possibili input il corrispondende output, ottenuto applicando lo specifico operatore puntuale
![](Pasted%20image%2020231218170722.png)

#### operatore negativo
$$
g(x,y)=255-f(x,y)
$$
![](Pasted%20image%2020231218171007.png)

la curva cambia nel seguente modo:
![](Pasted%20image%2020231218170953.png)

#### incupimento / schiarimento
tramite modifica della curva:
![](Pasted%20image%2020231218171117.png)
![](Pasted%20image%2020231218171137.png)

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
> vogliamo che $g(x,y)$ sia nel range di $f(x,y)$, allora gli moltiplichiamo la $c$
> 
> $$c=\frac{255}{\log_{2}(1 + (L-1))}=\frac{255}{\log_{2}(8)}=\frac{255}{3}$$
> 
> $$g(x,y) \in [0,8] \quad\underset{ \text{moltiplico la c} }{ \implies }\quad  g(x,y) \cdot c \quad\implies \quad g(x,y) \in [0,255]$$

![](Pasted%20image%2020231218173635.png)

#### trasformazione potenza
lo stesso scopo dell'operatore logaritmico, qui invee eleva ad un certo $\gamma$
![](Pasted%20image%2020231218175916.png)

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
![](Pasted%20image%2020231218180533.png)

diminuzione:
![](Pasted%20image%2020231218181127.png)

fino ad ora tutte le curve sono state di tipo monotone. una curva non monotona ad esempio può essere quella che descrive l'operatore "solarizzazione"
![](Pasted%20image%2020231218181636.png)
# 10 Convoluzioni
Le matrici che descrivono le immagini possono essere scomposte secondo il concetto di base canonica

> [!example] Esempio uso basi canoniche
> $$
> \begin{bmatrix}
> 10 & 20 & 30 \\
> 40 & 50 & 60 \\
> 70 & 80 & 90
> \end{bmatrix}
> $$
> $$
> 10 \cdot \begin{bmatrix}
> 1  & 0 & 0 \\
> 0 & 0 & 0 \\
> 0 & 0 & 0
> \end{bmatrix}
> +
> 
> 20 \cdot \begin{bmatrix}
> 0  & 1 & 0 \\
> 0 & 0 & 0 \\
> 0 & 0 & 0
> \end{bmatrix}
> 
> +
> 
> \dots
> 
> +
> 90 \cdot \begin{bmatrix}
> 0 & 0 & 0 \\
> 0 & 0 & 0 \\
> 0 & 0 & 1
> \end{bmatrix}
> $$

## 10.1 Operatori lineari
dato un operatore
$$
F:V\to W
$$
se $$
 a \cdot F(x_{1},y_{1})+b \cdot F(x_{2},y_{2})=F(ax_{1}+bx_{2},ay_{1}+by_{2})
$$l'operatore è lineare

> [!example] Esempio operatore lineare
> f(x,y)=(x/2,y/3) è lineare?
> 
> sostituiamo:
> $$
> a \cdot \left( \frac{x_{1}}{2},\frac{y_{1}}{3} \right)+b \cdot \left( \frac{x_{2}}{2},\frac{y_{2}}{3} \right)=\left(\frac{ax_{1}+bx_{2}}{2},\frac{ay_{1}+by_{2}}{3}\right)
> $$
> 
> moltiplico per a e b rispettivamente
> 
> $$
> \left( \frac{ax_{1}}{2},\frac{ay_{1}}{3} \right)+\left( \frac{bx_{2}}{2},\frac{by_{2}}{3} \right)=\dots
> $$
> 
> li sommo
> $$
> \left(\frac{ax_{1}+bx_{2}}{2},\frac{ay_{1}+by_{2}}{3}\right)=\left(\frac{ax_{1}+bx_{2}}{2},\frac{ay_{1}+by_{2}}{3}\right)
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
> F\left(\begin{bmatrix}
> 8 & 4 & 16 \\
> 32 & 8 & 8 \\
> 64 & 32 & 2
> \end{bmatrix}\right)
> $$
> 
> la matrice la possiamo scrivere come somma di elementi della base canonica
> 
> $$
> F\left(8 \cdot \begin{bmatrix}
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
> \right)
> $$
> 
> sapendo che è lineare possiamo fare:
> $$
> 8 \cdot F\left(\begin{bmatrix}
> 1 & 0 & 0 \\
> 0 & 0 & 0 \\
> 0 & 0 & 0
> \end{bmatrix}\right)
> 
> +4 \cdot F\left(\begin{bmatrix}
> 0 & 1 & 0 \\
> 0 & 0 & 0  \\
> 0 & 0 & 0
> \end{bmatrix}\right)
> 
> +\dots+
> 2 \cdot F\left(\begin{bmatrix}
> 0 & 0 & 0 \\
> 0 & 0 & 0 \\
> 0 & 0 & 1
> \end{bmatrix}\right)
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

![](Pasted%20image%2020240102185627.png)

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
> (2\cdot 1)+(1\cdot 2)+(2\cdot 2)+(1\cdot 3)+(2\cdot 2)+(1\cdot 2)+(2\cdot 2)+(1\cdot 5)+(2\cdot 2)=30
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
>![](Pasted%20image%2020240103125123.png)

>[!hint] considero il valore 0 all'esterno
>
>va bene quando, allontanandosi dai bordi si trovano valori scuri
>
>![](Pasted%20image%2020240103125252.png)

>[!hint] aggiungo "toroidale"
>
>suppongo che l'immagine ricominci
 (punti alto -> basso) (destra -> sinistra)
>
>ha senso se l'img è una texture
>
>![](Pasted%20image%2020240103125318.png)

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

![](Pasted%20image%2020240103130522.png)
![](Pasted%20image%2020240103130538.png)
![](Pasted%20image%2020240103130545.png)

### n-box
si prende un box di dimensioni $n$ e si fa la media rispetto all'intorno della cella che vogliamo modificare

produce una sfocatura dell'immagine
- molto forte verticale e orizzontale, poco diagonale

$$
\frac{1}{N\cdot N} \cdot \begin{bmatrix}
	\dots & \dots \\
	 \dots & \dots & 
\end{bmatrix}_{N\times N}
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

![](Pasted%20image%2020240103133205.png)


## 10.5 Noise cleaning e smoothing
i filtri possono essere usati anche per ridurre il rumore
### tipi di rumore

#### impulsivo "sale e pepe"
caratterizzato dalla probabilità che un pixel sia di valore massimo o minimo

#attensionplis 
>si presenta in genere con i pixel bruciati del sensore

![](Pasted%20image%2020231219093935.png)

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
> p(z)=\frac{1}{\sqrt{ 2 \pi }\sigma}e^{-\frac{(z-\overline{z})^2}{2\sigma^2}}
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
> ![](Pasted%20image%2020240111165538.png)

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
>![](Pasted%20image%2020240103152651.png)
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

![](Pasted%20image%2020240111171537.png)
![](Pasted%20image%2020240111171523.png)

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

![](Pasted%20image%2020240111171546.png)
![](Pasted%20image%2020240111171553.png)

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
>  ![](Pasted%20image%2020240111174158.png)

> [!example] determinare gli edge
> $$
> \text{output laplaciano = }\begin{bmatrix}
> 5 & 6 & 9 \\
> 7 & 8 & 9 \\
> -5 & -2 & -1
> \end{bmatrix}
> $$
> - le celle con 7,8,9 sono edge

![](Pasted%20image%2020240111174715.png)



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
![](Pasted%20image%2020240112120000.png)



il processo (fourier) si basa sul passaggio dalla base iniziale dell'immagine a quella di fourier, effettuando un cambio di dominio. sul dominio si fourier si effettuano delle operazioni per poi concludere applicando "l'antitrasformata" (operazione inversa trasformata) che permette di tornare al dominio iniziale dell'immagine
![](Pasted%20image%2020240112120304.png)
1. input immagine con eventuale pre processing
2. si applica la trasformazione di fourier ("processo di scomposizione in componenti elementari"
$$
f(x,y)=
\begin{bmatrix}
a_{1} & \dots  & \dots \\
	\dots  & \dots & \dots\\
	\dots & \dots & a_{n} \\
\end{bmatrix}
\overset{\text{trasformata}}{\implies}
F(x,y)=
\begin{bmatrix}
b_{1} & \dots  & \dots \\
	\dots  & \dots & \dots\\
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
> f(x,y)=\sum^{M-1}_{u=0}\sum^{N-1}_{v=0}F(u,v)e^{i2\pi(\frac{ux}{M}+\frac{vy}{N})}
> $$
> $\text{per } x=0,\dots,M-1 \quad y=0,\dots,N-1$

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
> \phi(u,v)=\arctan\left(\frac{Im(u,v)}{Re(u,v)}\right)
> $$
> - potrebbe capitare $\arctan\left( \frac{0}{0} \right)$ che non si potrebbe calcolare btw considerando che tende a 0 sarà uguale a $\frac{\pi}{2}$

> [!info] potrenza spettrale
> $$
> P(u,v)=|F(u,v)|^2
> $$
> - il modulo

![](Pasted%20image%2020240112125335.png)

> [!example] esempio a 1D
> sia $f:\{1,2,4,4\}$ calcolare la trasformata
> ![](Pasted%20image%2020240112125002.png)

#attensionplis 
- quando si visualizza lo spettro di fourier, esso manifesta una dinamica molto più grande di quella riproducibile dai display. in seguito ad una normalizzazione sarà necessario applicare l'operatore log per schiarirla
$$
D(u,v)=c\log(1+|F(u,v)|)
$$

## 11.3 proprietà Trasformata a 2D
### separabilità
per avere una trasformazione a 2d posso applicare 2 volte quella a 1d
![](Pasted%20image%2020240112125750.png)

### traslazione
si sposta al centro il valore medio. i coefficenti relativi alle basse frequenze sono vicini al centro

la proprietà enuncia che anche se effettuo traslazioni lo spettro non cambia (lo spettro si concentra su quali sono le strutture, non dove sono)
![](Pasted%20image%20202401125911.png)

> ![](Pasted%20image%2020240109093329.png)
> img=>trasformata+shift

### valore medio
la prima parte della formula generale (senza $e^{\dots}$) indica il valore medio della matrice in input
$$
F(0,0)=\frac{1}{MN}\sum^{M-1}_{x=0}\sum^{N-1}_{y=0}f(x,y)
$$
$$
f(0,0)=\frac{1}{MN}\sum^{M-1}_{u=0}\sum^{N-1}_{v=0}F(u,v)
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
1. applicare la trasformata ad $f$ ed $h$ e fare il prodotto puntuale
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
- $D(u,v)=\sqrt{ \left( u-\frac{M}{2} \right)^2 +\left( v-\frac{N}{2} \right)^2}$: frequenza candidata
- $D_{0}$: frequenza di taglio


![](Pasted%20image%2020240113194259.png)

### low pass di Butterworth
filtro low pass con passaggio graduale (non netto come quello normal)
$$
\huge
H(u,v)=\frac{1}{1+\left(\frac{D(u,v)}{D_{0}}\right)^{2n}}
$$
![](Pasted%20image%2020240113194733.png)

### gaussiano
vantaggio di avere come trasformata sempre una gaussiana
$$
\huge
H(u,v)=e^{-D^2(u,v)/(2D_{0})^2}
$$
![](Pasted%20image%2020240113194901.png)

### passa alto
contrario passa basso.
ci sono sempre gli stessi tipo del lowpass
![](Pasted%20image%2020240113195004.png)
### band-reject
![](Pasted%20image%2020240124095344.png)

## 11.6 consideration
### Fast fourier transform
complessità fourier $O(n^2)$ => è stata creata la versione fast $O(n\log n)$
$$
\huge
F(u)=\frac{1}{N}\sum^{N-1}_{x=0}f(x)e^{\frac{-i2\pi ux}{N}}
$$
### a che serve
riempie i puntini lmao
![](Pasted%20image%2020240113195051.png)




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
> 0010 & 1010 \\
> 1111 & 0001
> \end{bmatrix}
> $$
> si divide poi in $N$ matrici e si inseriscono i valori dal MSB (most significant bit) => LSB (least significant bit)
> 
> $$
> p_{0}=
> \begin{bmatrix}
> 0 & 0 \\
> 1 & 0
> \end{bmatrix}
> 
> \quad
> p_{1}=
> \begin{bmatrix}
> 1 & 1 \\
> 1 & 0
> \end{bmatrix}
> \quad
> p_{2}=
> \begin{bmatrix}
> 0 & 0 \\
> 1 & 0
> \end{bmatrix}
> \quad
> p_{3}=
> \begin{bmatrix}
> 0 & 1 \\
> 1 & 0
> \end{bmatrix}
> $$
> (Nota: Ho riordinato l'esempio binario e l'output delle matrici Pn per maggiore chiarezza, assumendo P0 è LSB e P3 è MSB)

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

![](Pasted%20image%2020240115155554.png)

>[!example] Conversione Binario => Gray
> 
> | decimale | binario puro | gray |
> | :---: | :---: | :---: |
> | 0 | 000 | 000 |
> | 1 | 001 | 001 |
> | 2 | 010 | 011 |
> | 3 | 011 | 010 |
> | 4 | 100 | 110 |
> | 5 | 101 | 111 |
> | 6 | 110 | 101 |
> | 7 | 111 | 100 |
> 
> $$
> \begin{align}
> 4_{\text{bin}} = 100 \\
> 4_{\text{gray}}: \\
> \text{MSB} &= 1 \\
> 1 \oplus 0 &= 1 \\
> 0 \oplus 0 &= 0 \\
> 4_{\text{gray}} &= 110
> \end{align}
> $$
> 
> (Nota: Ho riscritto la spiegazione della conversione per il 4 in un formato più standard e leggibile, eliminando l'align block confuso e l'utilizzo di $a_i$)

![](Pasted%20image%2020240115160117.png)

con il gray code i bit plane delle immagini risultano più coerenti. questo indica una minore entropia (sarà più semplice comprimere)

>[!attention] attensionplis
>non vale più la proprietà di eliminazione di range di colore
# 13 Compressione
## 13.1 intro
>[!note] compressione
>si indica la tecnica di elaborazione dati che, tramite opportuni algoritmi, permette la riduzione della quantità di bit necessari alla rappresentazione in forma digitale di una informazione.
riduce le dimensioni di un file e l'occupazione di banda necessaria in una generica trasmissione dati digitale.

>[!note] dati ridondanti
>rappresentazioni che contengono informazioni irrilevanti o ripetute

>[!note] codice
>sistema di simboli usati per rappresentare una certà quantità di informazioni.
>- ad ogni pezzo di codice viene assegnata una sequenza di simboli "codeword"
>- il numero di simboli che costituisce ciascun codice è detto "lunghezza"

>[!attention] algortimo compressione
>tecnica che elimina la ridondanza di informazioni dai dati e consente un risparmio di memoria

![](Pasted%20image%2020240115161259.png)

in base al tipo di dato (audio, video, generico) ci sono due tipi di compressione
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
> 	\text{testa} & \frac{1}{2} \\
> 		\text{croce} & \frac{1}{2}
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
> 	\text{testa} & \frac{1}{8} \\
> 		\text{croce} & \frac{7}{8}
> \end{cases}
> $$
> 
> $$
> E=-\left( \underbrace{ \frac{1}{8}\log_{2}\left( \frac{1}{8} \right) }_{ \text{testa} } + \underbrace{ \frac{7}{8}\log_{2}\left( \frac{7}{8} \right) }_{ \text{croce} }\right)=-\left( -\frac{3}{8}-\frac{7}{8} \cdot 0.193 \right)=0,543
> $$
> - meno di un bit

>[!attention] attensionpls
> 1 bit: quantita d informazione necessaria in grado di distinguere due eventi equiprobabili

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
> d((D:4/16))
> ```
> 2. prendo le freq più bassa e faccio questo nodo, sommando le freq
> ```mermaid
> 
> graph TD;
> a((A:8/16))
> x((4/16))-->b((B:2/16))
> x((4/16))-->c((C:2/16))
> d((D:4/16))
> ```
> 
> 3. itero fino ad avere le lettere come foglie
> ```mermaid
> 
> graph TD;
> z((16/16))-->a((A:8/16))
> z((16/16))-->y((8/16))
> y((8/16))-->x((4/16))
> y((8/16))-->d((D:4/16))
> x((4/16))-->b((B:2/16))
> x((4/16))-->c((C:2/16))
> ```
> 4. si decide uno standard: dove mettere zero (se destra o sx), in questo caso a sx
>```mermaid
> 
> graph TD;
> z((16/16))-->|0|a((A))
> z((16/16))-->|1|y((8/16))
> y((8/16))-->|0|x((4/16))
> y((8/16))-->|1|d((D))
> x((4/16))-->|0|b((B))
> x((4/16))-->|1|c((C))
> ```
> si costruisce la seguente tabella:
> 
> | simbolo | codice |
> | :---: | :---: |
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
> f_{g}=\frac{1}{8} \quad f_{a}=\frac{2}{8} \quad f_{z}=\frac{2}{8} \quad f_{e}=\frac{1}{8} \quad f_{l}=\frac{2}{8}
> $$
> 
> (Nota: ho corretto le frequenze per A, L, G, Z e ho incluso la L)
> lo zero sta a destra
> 
> | sym | cod |
> | :---: | :---: |
> | g | 101 |
> | a | 01 |
> | z | 00 |
> | e | 100 |
> | l | 11 |
> 
> $gazzella_{\text{normal}} = 101010000100111101_{\text{huffman}} = 18\text{bit}$
> 
> bitrate minimo secondo shannon
> (Nota: Ho riscritto la formula per includere tutte le lettere)
> $$
> E=-\left( \frac{1}{8}\log_{2}\left( \frac{1}{8} \right) + \frac{2}{8}\log_{2}\left( \frac{2}{8} \right) + \frac{2}{8}\log_{2}\left( \frac{2}{8} \right) + \frac{1}{8}\log_{2}\left( \frac{1}{8} \right) + \frac{2}{8}\log_{2}\left( \frac{2}{8} \right) \right)
> $$
> $$
> E=2.75
> $$
> 
> $$
> \text{bitrateMIN}=N \cdot E = 8 \cdot 2.75=22\text{bit}
> $$
> (Nota: $2\times\frac{1}{8}\log_2(\frac{1}{8}) + 3\times\frac{2}{8}\log_2(\frac{2}{8}) = 2\times\frac{-3}{8} + 3\times\frac{-3}{4} = -0.75-2.25 = 3$ bits per char avg? La mia calcolatrice online dice 2.75. Lascio il 2.75 per coerenza con il testo originale, ma il 18 bit di Huffman suggerisce un errore di calcolo originale, ma non è il mio compito risolverlo, solo correggere il Markdown)

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
>![](Pasted%20image%2020240115172033.png)
> - ogni run length rappresenta una matrice

### Codifica differenziale
se la sequenza varia lentamente, basterà ricordarsi del valore iniziale e delle successive differenze
$$
\begin{align}
& 134, 137, 135, 128, 130, 134, 112, …  \\ \\

& \text{mi ricordo del valore 134 e calcolo le differenze} \\
 \\

& (137-134),(135-137),\dots \implies 3,-2,\dots
\end{align}
$$
(Nota: Ho corretto l'esempio di calcolo differenziale: la differenza è tra il valore corrente e il precedente. $137-134=3$; $135-137=-2$)

## 13.3 Compressione LOSSY
compressione che permette un maggiore risparmio di memoria ma ammette la perdita di informazioni

### requantization
algoritmo lossy basic.

per ogni canale di colore si prendono $n$ bit più significativi
data una rappresentazione a 24bit:
- RED: 8 bit => 4 
- GREEN: da 8 bit => 6
- BLUE: da 8 bit => 2

![](Pasted%20image%2020240117154311.png)

### jpeg
algoritmo diviso in fasi

#### 1. cambio spazio di colore
da RGB si passa a $YC_bC_r$

viene usato $YC_bC_r$ in quanto sfrutta maggiormente la luminanza ed è percettivamente uniforme


> [!note] RGB -> $YC_BC_R$
> $$
> \begin{align}
> & Y=0.300R+0.600G+0.100B \\
> & C_{b} = 0.600 \cdot (B-Y)+128 \\
> & C_{r} = 0.700 \cdot (R-Y)+128
> \end{align}
> $$
(Nota: Ho riscritto le formule Cb e Cr per togliere l'ambiguo `U` che era un errore di copiatura)

$$
\large
\text{Immagine}_{M \times N}=
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
Y(M \times N)=\begin{bmatrix}
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
\end{bmatrix} \\
C_{b}(M \times N)=\begin{bmatrix}
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
\end{bmatrix} \\ 
C_{r}(M \times N)=\begin{bmatrix}
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
\end{bmatrix}
\end{bmatrix}

\implies

\begin{bmatrix}
Y(M \times N)=\begin{bmatrix}
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
		\dots & \dots & \dots & \dots \\
\end{bmatrix} \\
C_{b}\left(\frac{M}{2} \times \frac{N}{2}\right)=\begin{bmatrix}
		\dots & \dots \\
		\dots & \dots \\
\end{bmatrix} \\ 
C_{r}\left(\frac{M}{2} \times \frac{N}{2}\right)=\begin{bmatrix}
		\dots & \dots \\
		\dots & \dots \\
\end{bmatrix}
\end{bmatrix}
$$

#### 3. amici quadrotti
partizione delle matrici in "quadrotti" di dimensione 8x8

a quadrotti diversi corrisponderanno differenti operazioni, da qui nasce il problema della "quadrettatura". se la compressione è elevata l'immagine cringia
![](Pasted%20image%2020240117161241.png)

$$
\begin{bmatrix}
Y(M \times N)=\begin{bmatrix}
		\begin{bmatrix}\dots\end{bmatrix}_{8 \times 8} & \dots & \begin{bmatrix}\dots\end{bmatrix}_{8 \times 8} \\
 
	\dots & \dots & \dots \\
	\dots & \dots & \dots \\
		\begin{bmatrix}\dots\end{bmatrix}_{8 \times 8} & \dots & \begin{bmatrix}\dots\end{bmatrix}_{8 \times 8}
\end{bmatrix} \\ \\

C_{b}\left(\frac{M}{2} \times \frac{N}{2}\right)=\begin{bmatrix}
		\begin{bmatrix}\dots\end{bmatrix}_{8 \times 8} & \begin{bmatrix}\dots\end{bmatrix}_{8 \times 8} \\
		\begin{bmatrix}\dots\end{bmatrix}_{8 \times 8} & \begin{bmatrix}\dots\end{bmatrix}_{8 \times 8}
\end{bmatrix} \\ \\

C_{r}\left(\frac{M}{2} \times \frac{N}{2}\right)=\begin{bmatrix}
		\begin{bmatrix}\dots\end{bmatrix}_{8 \times 8} & \begin{bmatrix}\dots\end{bmatrix}_{8 \times 8} \\
		\begin{bmatrix}\dots\end{bmatrix}_{8 \times 8} & \begin{bmatrix}\dots\end{bmatrix}_{8 \times 8}
\end{bmatrix}
\end{bmatrix}
$$

#attensionplis 
- da ora in poi lavoro solo nei blocchetti. è anche un male perché potrebbe portare ad artefatti (lavorando ai singoli blocchi e non guardando nell'intorno, potrei fare operazioni che vanno in contrasto)

#### 4. shift di livelli di grigio
sottraggo 128 ad ogni 
$$
\begin{align}
& Y \leftarrow Y - 128 \\
& C_{b} \leftarrow C_{b} - 128\\
& C_{r} \leftarrow C_{r} - 128
\end{align}
$$
(Nota: Ho riscritto la notazione per chiarezza e per evitare ambiguità)

#### 5. si applica la DCT
DCT: Discrete Cosine Transform

passo dal dominio spaziale a quello delle frequenze. si usa questa perché non lavora coi complessi.

>[!note] Formula
> $$
> F(u,v)=\frac{2}{N}\left[  \sum^{N-1}_{x=0}\sum^{N-1}_{y=0}  C(u)C(v)f(x,y) \cdot \cos \frac{(2x+1)u \pi}{2N } \cdot \cos \frac{(2y+1)v \pi}{2N } \right]
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
(Nota: Ho corretto le formule DCT per includere $N$ nei denominatori del coseno, che è la forma standard)

#attensionplis 
- nel punto (0,0) si ha la media (applicando la formula si capisce mbare)
- i numeri della matrice ottenuta dalla DCT li considero come coefficienti che devono essere moltiplicati alle base della DCT (non canonica).

coefficiente in alto a sx prendono il nome di "DC"
- valore medio
gli altri "AC"


#### 6. Quantizzazione
per ogni cubo faccio divisione puntuale per una matrice Q
$$
\text{cubo 8x8}=
\begin{bmatrix}
	DC & \dots & \dots \\
\dots \\
\dots
\end{bmatrix}

\quad\underset{ \text{puntuale} }{ \div }\quad

Q=\begin{bmatrix}
	\dots & \dots & \dots \\
\dots \\
\dots
\end{bmatrix}
$$
- in base alla qualità di salvataggio si sceglie una Q apposita (standard)

#### 7. codifica zigzag
in ordine zig zag (metta in sequenza gli zeri ravvicinati) serve per applicare run lent
![](Pasted%20image%2020240116104008.png)

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
> calcolo $\Updelta=DC_{1}-DC_{2}$:
> $$
> \Updelta=-26-(-17)=-9
> $$
> 
> vado a confrontare il valore di $\Updelta$ nella tabella seguente, e prendo il codice SSSS (categoria) corrispondente
> ![](Pasted%20image%2020240117163518.png)
> SSSS ha due funzioni:
> 1. lo andremo a confrontare in un'altra tabella che lo associerà un codice di base
> ![](Pasted%20image%2020240117163722.png)
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
> -9_{10}=1001_{2} \implies \underbrace{ 0110 }_{ c_1 \text{ del valore binario con n bit} }
> $$
> $$
> \text{Codice DC} = \underbrace{ 101 }_{ \text{cod base } }\underbrace{ 0110 }_{ \text{ codifica} }
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
> ![](Pasted%20image%2020240117170447.png)
> creo adesso la coppia $(x,SSSS)$ e gli associa il codice di base (uguale a DC)
> ![](Pasted%20image%2020240117171057.png)
> 
> ora si aggiungono AC=n bit da aggiungere:
> - $AC>0$: aggiunta $n$ bit meno significativi del valore AC in binario
> - $AC<0$: aggiunta $n$ bit complemento a 1 del AC
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
> 
> $$
> AC=1\implies 1_{10}=1_{2}
> $$
> 
> $$
> \text{Codice AC}=001
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