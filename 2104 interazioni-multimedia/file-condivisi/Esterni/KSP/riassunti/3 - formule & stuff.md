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
