# Documento di Briefing: Elaborazione delle Immagini Digitali e Compressione

## Executive Summary

Questo documento fornisce una sintesi esaustiva dei principi fondamentali, delle tecniche di elaborazione e degli algoritmi di compressione relativi alle immagini digitali. Partendo dalle basi della percezione visiva umana, si analizza il processo di acquisizione e digitalizzazione, che include il funzionamento dei sensori (es. CCD con Bayer Pattern), il campionamento e la quantizzazione, evidenziando concetti chiave come il teorema di Shannon e il fenomeno dell'aliasing.

Viene offerta una trattazione approfondita della teoria del colore, esplorando i modelli percettivamente uniformi (CIELAB) e quelli orientati all'hardware (RGB, CMY) o alla trasmissione (YUV, YCbCr), oltre ai metodi di sintesi additiva e sottrattiva. Il nucleo del documento si concentra sulle operazioni di elaborazione delle immagini, distinte tra dominio spaziale e dominio delle frequenze. Nel dominio spaziale, vengono esaminate le operazioni puntuali (istogrammi, contrast stretching, equalizzazione, LUT) e le operazioni locali basate sulla convoluzione, con applicazioni che spaziano dalla riduzione del rumore (filtri mediani, di media) all'estrazione dei contorni (Sobel, Prewitt, Laplaciano). Nel dominio delle frequenze, viene introdotta la Trasformata di Fourier come strumento per l'analisi e il filtraggio, illustrando il Teorema della Convoluzione e l'applicazione di filtri passa-basso, passa-alto e band-reject.

Infine, il documento si conclude con un'analisi dettagliata delle tecniche di compressione. Vengono descritti gli algoritmi lossless, fondati sui concetti di entropia e sul teorema di Shannon, come la codifica di Huffman, Run-Length e differenziale, e la loro applicazione ai bit-plane (con un confronto tra codifica binaria e Gray). La sezione sulla compressione lossy è dedicata a una disamina minuziosa dello standard JPEG, illustrandone ogni fase: dalla trasformazione dello spazio colore (RGB a YCbCr) e sottocampionamento, alla divisione in blocchi, applicazione della DCT, quantizzazione e codifica entropica dei coefficienti DC e AC.

## 1. Fondamenti della Percezione Visiva e Rappresentazione delle Immagini

La comprensione delle immagini digitali inizia con l'analisi del sistema visivo umano, che non si limita a "vedere" ma elabora attivamente gli stimoli visivi. Questo processo è governato da principi psicologici e fenomeni ottici che influenzano la percezione.

### 1.1 Leggi della Percezione Visiva (Gestalt)

Il cervello umano tende a organizzare gli stimoli visivi in unità e modelli coerenti secondo principi specifici:

| Legge | Descrizione |
|---|---|
| **Vicinanza** | Parti vicine di un insieme tendono ad essere percepite come raggruppate in unità. |
| **Chiusura** | Le figure chiuse sono percepite più facilmente e tendono a prevalere su quelle aperte. Il cervello tende a "chiudere" le forme incomplete. |
| **Uguaglianza** | Elementi che si assomigliano per forma o colore vengono percepiti come un unico gruppo. |
| **Continuità** | Punti posti in successione tendono a formare una struttura unitaria, e si tende a far continuare forme nascoste. |
| **Buona Forma** | Le forme regolari, simmetriche e semplici sono percepite come più gradevoli e unitarie. |

### 1.2 Intensità Percepita e Illusioni Ottiche

La percezione della luminosità non è una funzione lineare dell'intensità luminosa incidente sull'occhio, ma segue una funzione logaritmica. Ciò significa che il sistema visivo umano riesce a discriminare meglio le variazioni di intensità in zone scure piuttosto che in zone chiare. Questo principio è alla base di diverse illusioni ottiche:

*   **Bande di Mach:** In una serie di bande adiacenti con luminosità costante, l'occhio percepisce un'intensità non uniforme vicino ai bordi, accentuando il contrasto.
*   **Contrasto Simultaneo:** Un'area di colore uniforme viene percepita come più chiara se posta su uno sfondo scuro, e più scura se posta su uno sfondo chiaro, nonostante il suo colore intrinseco non cambi.

### 1.3 L'Occhio Umano e la Formazione dell'Immagine

La retina è la membrana fotosensibile dell'occhio, composta da due tipi di fotorecettori:

*   **Coni:** Circa 6-7 milioni, concentrati nella fovea (una regione centrale di 1,5 x 1,5 mm). Sono estremamente sensibili al colore e responsabili della vista fotopica (a colori). Esistono tre tipi di coni, sensibili a diverse lunghezze d'onda: S (corte/blu), M (medie/verdi) e L (lunghe/rosse).
*   **Bastoncelli:** Circa 75-150 milioni, distribuiti su tutta la retina. Sono molto sensibili all'intensità luminosa ma poco al colore, responsabili della vista scotopica (monocromatica, in condizioni di scarsa luce).

La formazione dell'immagine avviene attraverso il cristallino, che agisce come una lente sottile. I muscoli oculari ne modificano la forma per variare la lunghezza focale (`f`), mettendo a fuoco oggetti a diverse distanze (`u`) sulla retina (`v`), secondo l'**equazione della lente sottile**:

$$\frac{1}{u} + \frac{1}{v} = \frac{1}{f}$$

Il **fattore di magnificazione** `m` descrive il rapporto tra la dimensione dell'immagine sulla retina (`h`) e quella dell'oggetto reale (`k`):

$$m = \frac{h}{k} = \frac{v}{u}$$

### 1.4 Rappresentazione dell'Immagine Digitale

Un'immagine digitale è una rappresentazione discreta di una scena continua. Matematicamente, può essere descritta come una funzione bidimensionale `f(x,y)`, dove `x` e `y` sono le coordinate spaziali. Il valore `f(x,y)` è proporzionale sia alla luce incidente (`i(x,y)`) che a quella riflessa dall'oggetto (`r(x,y)`):

$$f(x,y) = i(x,y) \cdot r(x,y)$$

Poiché i computer possono gestire solo valori discreti, la funzione continua `f(x,y)` deve essere digitalizzata attraverso due processi: **campionamento** (discretizzazione delle coordinate `x,y`) e **quantizzazione** (discretizzazione del valore di intensità `f`).

#### 1.4.1 Immagini Vettoriali vs. Raster

Esistono due approcci principali alla rappresentazione grafica:

| Caratteristica | Immagini Vettoriali | Immagini Raster |
| ------------------- | ------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------- |
| **Descrizione** | Insieme di primitive geometriche (linee, curve, poligoni) definite da equazioni matematiche. | Matrice di valori discreti chiamati pixel (Picture Element). |
| **Scalabilità** | Perfettamente scalabili senza perdita di qualità, poiché le trasformazioni modificano i parametri matematici. | La scalatura (zooming) richiede interpolazione e può causare perdita di qualità (sgranatura o sfocatura). |
| **Fotorealismo** | Generalmente non fotorealistiche, più adatte a disegni tecnici, loghi e illustrazioni. | Capaci di rappresentare scene fotorealistiche con grande dettaglio. |
| **Dimensioni File** | Solitamente più piccole, dipendono dalla complessità delle geometrie. | Più grandi, dipendono direttamente dalla risoluzione (numero di pixel) e dalla profondità di colore. |
| **Formati Esempio** | PDF, PS, EPS | JPEG, GIF, BMP, PNG |

Questo documento si concentra esclusivamente sulle immagini di tipo **raster**.

#### 1.4.2 Tipi di Immagini Raster

Le immagini raster sono rappresentate come matrici, con l'origine convenzionalmente posta in alto a sinistra. Si distinguono in base alla profondità di colore:

*   **Bianco/Nero:** 1 bit per pixel. Il valore può essere solo 0 (nero) o 1 (bianco).
*   **Scala di Grigi:** Generalmente 8 bit per pixel. Il valore è un intero compreso tra 0 (nero) e 255 (bianco).
*   **A Colori (RGB):** Generalmente 24 bit per pixel (8 bit per canale). Ogni pixel è rappresentato da una terna di valori `(R, G, B)` che indicano l'intensità delle componenti rossa, verde e blu.

## 2. Acquisizione e Digitalizzazione delle Immagini

Il processo di creazione di un'immagine digitale parte dalla cattura della luce riflessa da un oggetto tramite un sensore, che trasforma l'energia luminosa in un segnale elettrico, successivamente digitalizzato.

### 2.1 Sensori e Color Filter Array (CFA)

I sensori più diffusi nelle fotocamere digitali sono i **CCD (Charge-Coupled Device)**, array 2D di celle fotosensibili. Poiché ogni singola cella del sensore può misurare solo l'intensità luminosa totale e non il colore, viene posto davanti al sensore un mosaico di filtri colorati, chiamato **Color Filter Array (CFA)**.

*   **Bayer Pattern:** È il CFA più comune. Dispone i filtri secondo un rapporto di 2 verdi, 1 rosso e 1 blu (RGGB) su una griglia 2x2. Questa configurazione privilegia il verde perché l'occhio umano è più sensibile a questa lunghezza d'onda. L'immagine catturata in questo formato è detta **RAW**.

### 2.2 Color Interpolation (Demosaicing)

Poiché ogni pixel dell'immagine RAW contiene l'informazione di un solo canale di colore (R, G o B), è necessario un processo di interpolazione per ricostruire i due valori di colore mancanti per ogni pixel. Questo processo è noto come **demosaicing** o **color interpolation**. Gli algoritmi comuni includono:

*   **Replication (Nearest Neighbor):** Copia i valori dei canali mancanti dai pixel vicini. È veloce ma produce artefatti visibili.
*   **Interpolazione Bilineare:** Calcola i valori mancanti come media pesata dei 4 pixel vicini noti. Offre un compromesso migliore tra qualità e complessità.
*   **Interpolazione Bicubica:** Utilizza i 16 pixel più vicini per una stima più accurata, preservando meglio i dettagli. È lo standard in molti software di fotoritocco.

### 2.3 Risoluzione

La risoluzione indica il grado di dettaglio di un'immagine ed è definita come il numero di pixel per unità di misura, comunemente espressa in **DPI (Dots Per Inch)**. È un concetto relativo che varia a seconda del dispositivo:

*   **Apparecchiatura di Ripresa (es. Scanner, Fotocamere):** Misura la densità dei sensori. Uno scanner può raggiungere 6000 DPI, mentre per le fotocamere si parla di Megapixel (milioni di pixel totali).
*   **Apparecchiatura di Resa (es. Schermi, Stampanti):** Misura la densità degli elementi di visualizzazione. Gli schermi hanno tipicamente 72 DPI, mentre le stampanti possono superare i 3000 DPI.

Un'immagine deve essere visualizzata con una risoluzione adeguata al dispositivo di resa per massimizzare la qualità percepita.

### 2.4 Campionamento

Il campionamento è il processo di discretizzazione delle coordinate spaziali di un'immagine, ovvero la scelta di un numero finito di punti (campioni) da una scena continua. La "frequenza del segnale" in un'immagine corrisponde alla variazione di intensità luminosa tra pixel adiacenti.

*   **Teorema di Shannon:** Per ricostruire fedelmente un segnale, la frequenza di campionamento deve essere almeno il doppio della frequenza più alta presente nel segnale stesso (il **Nyquist Rate**).
*   **Aliasing:** Se il campionamento avviene a una frequenza inferiore al Nyquist Rate (sottocampionamento), si verifica l'aliasing. Questo fenomeno causa la perdita di dettagli ad alta frequenza e l'introduzione di artefatti non presenti nell'originale, come i **pattern di Moirè** (interferenze visive generate dalla sovrapposizione di griglie) o l'**effetto "wagon-wheel"** nelle animazioni (la percezione di una ruota che gira al contrario).

### 2.5 Quantizzazione

La quantizzazione è il processo di mappatura dei valori di intensità continui (numeri reali), misurati dai sensori, in un insieme finito di valori discreti.

*   **Procedura:** Il range di valori continui `[a, b]` viene suddiviso in `n` livelli. Ogni valore continuo `x` viene assegnato al livello `k` se `tk <= x < tk+1`. Il numero di bit necessari per rappresentare `n` livelli è `log₂(n)`.
*   **Tipi di Quantizzazione:**
    *   **Uniforme:** Tutti i livelli di quantizzazione hanno la stessa ampiezza. La formula per mappare un livello `L` da un range di `N` livelli a un range di `K` livelli è: $$L' = floor((L \cdot K) / N)$$
    *   **Non Uniforme (es. Logaritmica):** I livelli non hanno la stessa ampiezza. La quantizzazione logaritmica, usata in scanner e fotocamere, assegna più livelli alle aree scure (dove l'occhio è più sensibile) e meno alle aree chiare. La formula può essere: $$L' = floor((log₂(L) \cdot K) / log₂(N))$$
*   **Rumore di Quantizzazione:** Il processo introduce inevitabilmente un errore, detto rumore, dovuto alla perdita di precisione. Altre fonti di rumore includono difetti del sensore e perturbazioni termiche (es. "dark current" nei CCD).

## 3. Teoria e Modelli del Colore

Il colore è una percezione soggettiva legata alla lunghezza d'onda della luce riflessa da un oggetto. La sua specificazione richiede modelli standardizzati, noti come spazi di colore.

### 3.1 Sintesi Additiva e Sottrattiva

| Sintesi | Principio | Colori Primari | Colori Secondari | Risultato Somma | Applicazione |
|---|---|---|---|---|---|
| **Additiva** | Somma di luci colorate. Si parte dal nero (assenza di luce). | Rosso (R), Verde (G), Blu (B) | Ciano (C), Magenta (M), Giallo (Y) | Bianco (R+G+B) | Monitor, schermi, proiettori. |
| **Sottrattiva** | Sottrazione di luce da una fonte bianca tramite filtri o pigmenti. | Ciano (C), Magenta (M), Giallo (Y) | Rosso (R), Verde (G), Blu (B) | Nero (C+M+Y) | Stampa, pittura, fotografia a colori. |

I colori sono **complementari** se la loro somma additiva produce il bianco (es. Blu e Giallo, Rosso e Ciano, Verde e Magenta).

### 3.2 Spazi di Colore Standard (CIE)

La **CIE (Commission Internationale de l'Éclairage)** ha definito sistemi standard per la misurazione del colore.

*   **Spazio CIE 1931 XYZ:** Il primo tentativo di definire uno spazio colore basato sulla percezione umana media. I valori `X, Y, Z` (detti del tristimolo) rappresentano la risposta dei tre tipi di coni dell'occhio.
*   **Diagramma di Cromaticità CIE xyY:** Una proiezione 2D dello spazio XYZ che separa la crominanza (`x, y`) dalla luminanza (`Y`). Mostra tutti i colori percepibili dall'occhio umano (il "color gamut" umano). Dimostra che nessun insieme di tre colori primari può riprodurre tutti i colori visibili.
*   **Spazio CIELAB (L\*a\*b\*):** Uno spazio colore **percettivamente uniforme** standardizzato nel 1976. Le distanze euclidee in questo spazio corrispondono a differenze di colore percepite in modo uniforme. È definito da tre coordinate:
    *   `L*`: Luminanza (da 0=nero a 100=bianco).
    *   `a*`: Asse cromatico verde-rosso.
    *   `b*`: Asse cromatico blu-giallo. La differenza di colore $\Delta E^*$ è calcolata come:
        $$\Delta E^* = \sqrt{(\Delta L^*)^2 + (\Delta a^*)^2 + (\Delta b^*)^2}$$

### 3.3 Modelli di Colore Comuni

| Modello | Componenti | Descrizione | Pro | Contro |
|---|---|---|---|---|
| **RGB** | Rosso, Verde, Blu | Modello additivo, orientato all'hardware (monitor). Rappresentato come un cubo. | Semplice da implementare, standard de facto. | Percettivamente non intuitivo (difficile prevedere il risultato della miscelazione). |
| **CMY(K)** | Ciano, Magenta, Giallo, Nero | Modello sottrattivo, orientato all'hardware (stampa). Il nero (K) viene aggiunto per ottenere neri più profondi. | Standard per la stampa. | - |
| **HSV / HSL** | Tonalità (Hue), Saturazione, Valore/Luminosità | Modello più intuitivo, basato sul "modello del pittore". Rappresentato come un cono o un cilindro. | Percettivamente significativo e facile da comprendere. | Non lineare, computazionalmente più complesso di RGB. |
| **YUV / YCbCr** | Y (Luminanza), U/Cb, V/Cr (Crominanza) | Separa la luminanza (scala di grigi) dalle informazioni sul colore. Fondamentale per la compressione video e immagini. | Sfrutta la minore sensibilità dell'occhio alla crominanza per ridurre i dati (sottocampionamento). | - |

La conversione da RGB a Y (Luminanza) si basa su una media pesata:
$$Y = 0.299R + 0.587G + 0.114B$$

### 3.4 Immagini a Colori Indicizzati (Palette)

Per ridurre l'occupazione di memoria, invece di memorizzare la terna RGB per ogni pixel, si utilizza una **palette** (o Look-Up Table, LUT).

*   **Funzionamento:** Si crea una tabella (la palette) che contiene un numero limitato di colori (es. 256). L'immagine viene memorizzata come una matrice di indici, dove ogni indice punta a un colore nella palette.
*   **Re-indexing:** È una tecnica che riordina gli indici nella palette per minimizzare l'entropia della mappa degli indici. Associando indici numericamente vicini a colori simili in pixel adiacenti, si migliora l'efficienza della compressione lossless. Trovare l'ordinamento ottimale è un problema NP-hard.

## 4. Elaborazione delle Immagini nel Dominio Spaziale

Le operazioni nel dominio spaziale modificano direttamente i valori dei pixel di un'immagine. Possono essere classificate in base alla dimensione dell'intorno del pixel su cui operano.

### 4.1 Operazioni Puntuali

Un'operazione puntuale modifica il valore di un pixel basandosi unicamente sul suo valore originale, senza considerare i pixel vicini. Queste trasformazioni sono spesso descritte da una **Look-Up Table (LUT)**.

*   **Istogramma:** È un grafico che rappresenta la distribuzione dei livelli di intensità (toni di grigio) in un'immagine. Fornisce informazioni immediate su luminosità (immagini scure/chiare) e contrasto.
*   **Contrast Stretching (Normalizzazione):** Espande l'istogramma di un'immagine per coprire l'intero range dinamico possibile (es. da $[min, max]$ a $[0, 255]$). La formula di normalizzazione lineare è:
    $$v_{new} = 255 \cdot \frac{v_{old} - v_{min}}{v_{max} - v_{min}}$$
*   **Equalizzazione dell'Istogramma:** Ridistribuisce i valori di intensità per rendere l'istogramma il più uniforme possibile. Questo tende ad aumentare il contrasto globale dell'immagine.
*   **Operatore Negativo:** Inverte i valori di intensità: $$g(x,y) = 255 - f(x,y)$$
*   **Trasformazione Logaritmica:** Comprime i valori alti ed espande i valori bassi, utile per visualizzare dettagli nelle aree scure. $$g(x,y) = c \cdot \log(1 + f(x,y))$$
*   **Trasformazione di Potenza (Gamma):** Modifica la luminosità. Con $\gamma < 1$ schiarisce l'immagine (simile al logaritmo), con $\gamma > 1$ la scurisce. $$g(x,y) = c \cdot f(x,y) ^ \gamma$$
*   **Binarizzazione (Thresholding):** Converte un'immagine in scala di grigi in un'immagine binaria (bianco/nero) basandosi su una soglia `T`.

### 4.2 Operazioni Locali e Convoluzione

Le operazioni locali calcolano il nuovo valore di un pixel basandosi sui valori dei pixel in un suo intorno (vicinato). La maggior parte dei filtri locali lineari e invarianti per traslazione (shift-invariant) viene implementata tramite **convoluzione**.

La convoluzione è un'operazione matematica che combina un'immagine `f` con una piccola matrice chiamata **kernel** (o maschera) `h`. Per ogni pixel, il kernel viene sovrapposto all'intorno del pixel, si esegue un prodotto puntuale tra gli elementi del kernel e i pixel corrispondenti, e si sommano i risultati per ottenere il nuovo valore del pixel.

$$(f \oplus h)(x,y) = \sum_{s} \sum_{t} f(x-s, y-t)h(s,t)$$

Quando si applica la convoluzione ai bordi, dove l'intorno è incompleto, si possono adottare diverse strategie: considerare i pixel esterni come zero, replicare i valori dei bordi, o assumere una topologia toroidale.

#### 4.2.1 Filtri di Smoothing (Sfocatura) e Noise Cleaning

Questi filtri mediano i valori dei pixel in un intorno per ridurre il rumore e sfocare l'immagine.

*   **Filtro Mediano:** (Non lineare) Sostituisce il valore del pixel con la mediana dei valori nel suo intorno. È molto efficace contro il rumore impulsivo ("sale e pepe") perché ignora i valori anomali (estremi).
*   **Filtro di Media (N-box):** (Lineare) Sostituisce il valore del pixel con la media aritmetica dei valori nel suo intorno. È efficace contro il rumore gaussiano ma tende a sfocare maggiormente i contorni.
*   **Filtro Binomiale (Gaussiano):** (Lineare) Utilizza un kernel con pesi derivati dalla distribuzione binomiale (approssimazione della gaussiana). Produce una sfocatura più naturale e uniforme rispetto al filtro di media.
*   **Altri Filtri:**
    *   **Filtro Olimpico:** Scarta il minimo e il massimo dall'intorno e calcola la media dei restanti.
    *   **Filtro Outlier:** Sostituisce il pixel solo se la sua differenza dalla media dell'intorno supera una soglia.

#### 4.2.2 Filtri di Estrazione dei Contorni (Edge Detection)

I contorni (edge) sono discontinuità locali della luminanza. Gli edge detector li evidenziano calcolando approssimazioni delle derivate dell'immagine.

*   **Basati sulla Derivata Prima (Gradiente):** I contorni corrispondono ai massimi del gradiente. I kernel di **Sobel** e **Prewitt** calcolano il gradiente lungo le direzioni x e y. I risultati (`Gx` e `Gy`) vengono combinati per ottenere la magnitudo totale del gradiente: $$G = \sqrt{Gx^2 + Gy^2}$$
*   **Basati sulla Derivata Seconda (Laplaciano):** I contorni corrispondono ai passaggi per lo zero (zero-crossing) della derivata seconda. Il **kernel Laplaciano** è il più comune. È sensibile al rumore ma rileva i contorni in tutte le direzioni.
*   **Filtri di Sharpening:** Aumentano la nitidezza dell'immagine accentuando i contorni. Un kernel di sharpening comune è derivato dal Laplaciano e rinforza i valori dei pixel sui contorni sottraendo i valori dei vicini.

## 5. Elaborazione delle Immagini nel Dominio delle Frequenze

Un'immagine può essere vista non solo come una griglia di pixel (dominio spaziale) ma anche come una somma di onde sinusoidali di diverse frequenze (dominio delle frequenze). La **Trasformata di Fourier** è lo strumento matematico per passare da un dominio all'altro.

### 5.1 Trasformata di Fourier

La Trasformata Discreta di Fourier (DFT) scompone un'immagine nelle sue componenti di frequenza. Il risultato `F(u,v)` è una matrice di coefficienti complessi, dove ogni coefficiente rappresenta l'ampiezza e la fase di una specifica frequenza.

*   **Basse Frequenze:** Corrispondono alle aree omogenee e a variazioni lente dell'immagine. Nello spettro di Fourier, sono vicine al centro.
*   **Alte Frequenze:** Corrispondono a dettagli fini, contorni e rumore. Sono situate verso i bordi dello spettro.

Lo spettro $|F(u,v)|$ mostra quali frequenze sono presenti, mentre la fase $\phi(u,v)$ contiene l'informazione sulla loro posizione spaziale. Per la visualizzazione, lo spettro viene spesso compresso logaritmicamente a causa del suo ampio range dinamico.

### 5.2 Teorema della Convoluzione

Questo teorema fondamentale stabilisce che **la convoluzione nel dominio spaziale è equivalente a un prodotto puntuale nel dominio delle frequenze**.

$$\mathcal{F}(f \oplus h) = \mathcal{F}(f) \cdot \mathcal{F}(h)$$

Ciò significa che applicare un filtro convolutivo a un'immagine può essere fatto in modo più efficiente (specialmente per kernel grandi) eseguendo i seguenti passaggi:

1.  Calcolare la DFT dell'immagine (`F`) e del kernel (`H`).
2.  Moltiplicare puntualmente le due trasformate: $$G(u,v) = F(u,v) \cdot H(u,v)$$
3.  Calcolare l'antitrasformata di `G` per ottenere l'immagine filtrata.

### 5.3 Filtri nel Dominio delle Frequenze

Il filtraggio in questo dominio consiste nel moltiplicare la trasformata dell'immagine per una funzione filtro $H(u,v)$ che attenua o elimina determinate frequenze.

*   **Filtri Low-Pass (Passa-Basso):** Mantengono le basse frequenze e attenuano le alte. L'effetto è una sfocatura (smoothing) e una riduzione del rumore.
*   **Filtri High-Pass (Passa-Alto):** Mantengono le alte frequenze e attenuano le basse. L'effetto è un'accentuazione dei contorni e dei dettagli (sharpening).
*   **Filtri Band-Reject (Elimina-Banda):** Rimuovono una specifica banda di frequenze, utili per eliminare rumore periodico.

Per ciascuna categoria, esistono diverse implementazioni:

*   **Ideale:** Taglio netto delle frequenze. Produce artefatti noti come "ringing".
*   **Butterworth:** Transizione graduale tra le frequenze passanti e quelle bloccate, riducendo gli artefatti.
*   **Gaussiano:** Transizione molto dolce, non produce "ringing". La sua trasformata è anch'essa una gaussiana.

## 6. Codifica e Compressione delle Immagini

La compressione riduce la quantità di bit necessari per rappresentare un'immagine, eliminando la ridondanza.

### 6.1 Compressione Lossless

Ricostruisce l'immagine originale perfettamente, senza perdita di informazioni. Si basa sull'eliminazione della ridondanza statistica.

*   **Entropia:** Misura la quantità media di informazione per simbolo in una sorgente dati. $$E = - \sum f_i \cdot \log₂(f_i)$$
*   **Teorema di Shannon per la Compressione:** Stabilisce il limite teorico per la compressione lossless. Il bitrate minimo per rappresentare una sorgente è pari alla sua entropia.
*   **Codifica di Huffman:** Algoritmo che crea un codice a lunghezza variabile ottimale. Assegna codeword più corte ai simboli più frequenti e più lunghe a quelli meno frequenti.
*   **Run-Length Encoding (RLE):** Comprime sequenze di dati ripetuti (run) memorizzando il valore e il numero di ripetizioni (es. "AAAAA" diventa "(5, A)").
*   **Codifica Differenziale:** Memorizza il primo valore di una sequenza e poi solo le differenze tra valori consecutivi. È efficace quando i valori variano lentamente.

### 6.2 Bit-Planes

Un'immagine a `N` bit può essere scomposta in `N` immagini binarie (bit-plane), una per ogni posizione di bit.

*   **Codifica Binaria Pura:** Piccole variazioni di intensità (es. da 127 a 128) possono causare il cambiamento di molti bit, rendendo i bit-plane poco coerenti.
*   **Codifica Gray:** Codifica in cui valori consecutivi differiscono per un solo bit (distanza di Hamming = 1). Questo rende i bit-plane più coerenti e con minore entropia, facilitando la compressione (es. con RLE).

### 6.3 Compressione Lossy: lo Standard JPEG

La compressione lossy accetta una perdita di informazioni per ottenere rapporti di compressione molto più elevati. Lo standard **JPEG (Joint Photographic Experts Group)** è l'algoritmo lossy più diffuso per le immagini fisse.

I passaggi fondamentali della codifica JPEG sono:

1.  **Trasformazione dello Spazio Colore:** L'immagine viene convertita da RGB a **YCbCr** per separare la luminanza (Y) dalla crominanza (Cb, Cr).
2.  **Sottocampionamento della Crominanza (Chroma Subsampling):** Si riduce la risoluzione dei canali di crominanza (es. un campione di Cb e Cr ogni 4 pixel di Y). Questo passaggio è lossy e sfrutta la minore sensibilità dell'occhio umano al colore rispetto alla luminosità.
3.  **Divisione in Blocchi 8x8:** L'immagine viene suddivisa in blocchi non sovrapposti di 8x8 pixel.
4.  **Trasformata Discreta del Coseno (DCT):** Ogni blocco viene trasformato dal dominio spaziale a quello delle frequenze tramite la DCT. La DCT concentra l'energia del segnale nei coefficienti a bassa frequenza (in alto a sinistra nella matrice 8x8).
    *   Il primo coefficiente `(0,0)` è il **coefficiente DC** (componente continua, valore medio del blocco).
    *   Gli altri 63 sono i **coefficienti AC** (componenti alternate, dettagli ad alta frequenza).
5.  **Quantizzazione:** Questo è il principale passaggio lossy. Ogni coefficiente DCT di ogni blocco viene diviso per un valore corrispondente in una **matrice di quantizzazione Q** e arrotondato all'intero più vicino. I valori in Q sono più grandi per le alte frequenze, causando la perdita di molti dettagli fini (molti coefficienti AC diventano zero). La qualità dell'immagine finale è controllata dal "quality factor" che scala questa matrice.
6.  **Codifica Entropica:** I coefficienti quantizzati vengono codificati in modo lossless.
    *   **Scansione Zig-Zag:** I coefficienti AC di ogni blocco vengono letti secondo un percorso a zig-zag per raggruppare gli zeri consecutivi.
    *   **Codifica dei Coefficienti DC:** Viene applicata una codifica differenziale tra i coefficienti DC di blocchi adiacenti.
    *   **Codifica dei Coefficienti AC:** Le sequenze di zeri e i valori non nulli vengono codificati con una tecnica simile alla RLE.
    *   **Codifica di Huffman:** I risultati delle codifiche differenziali e RLE vengono ulteriormente compressi con la codifica di Huffman.

Il processo di decodifica inverte questi passaggi. La divisione in blocchi può causare l'artefatto di "blocking" (quadrettatura) a bassi livelli di qualità. **JPEG2000** è uno standard più recente che utilizza le wavelet invece della DCT, offrendo una compressione migliore e senza blocking, ma non ha mai raggiunto la stessa diffusione.

## 7. Informazioni sul Corso "Interazione e Multimedia"

Il materiale analizzato è parte integrante del corso "Interazione e Multimedia" e del relativo "Laboratorio di Interazione", offerti in diverse sezioni (A-L, M-Z) e tenuti dai professori Filippo Stanco, Dario Allegra e Francesco Guarnera.

### 7.1 Struttura e Contenuti del Corso

Il programma del corso copre in modo approfondito tutti i temi trattati in questo documento, dall'introduzione alle immagini digitali fino agli standard di compressione. Inoltre, una parte significativa del corso è dedicata al linguaggio di programmazione **Processing**, una libreria Java per la grafica e la multimedialità interattiva. Gli argomenti di Processing includono:

*   Interazione utente (mouse, tastiera).
*   Programmazione a oggetti (classi, ereditariità).
*   Elaborazione di immagini tramite la classe `PImage`.
*   Implementazione di algoritmi di image processing.

### 7.2 Modalità d'Esame

L'esame è composto da due parti:

1.  **Scritto (6 CFU):**
    *   Una prima fase con un test a risposta multipla (10 domande, superato con almeno 6 risposte corrette).
    *   Una seconda fase (per chi supera la prima) con un test a risposta aperta (2 domande).
    *   Il voto finale dello scritto è calcolato con la formula: $$3 \cdot A + (B - 4)$$ dove $A$ è il numero di risposte corrette al test multiplo e $B$ è il punteggio (0-8) del test aperto.
2.  **Laboratorio di Processing (3 CFU):**
    *   Esercizi da risolvere in tempo limitato sui PC del laboratorio.

Il **voto finale** è una media pesata: $$(Voto\ scritto \cdot 6 + Voto\ laboratorio \cdot 3) / 9$$ È possibile ottenere la lode.

### 7.3 Prove in Itinere

Sono previste due prove in itinere durante il corso. Il superamento di entrambe consente l'esonero dalla prova scritta.

### 7.4 Risorse e Contatti

*   **Libro di Testo:** "Elaborazione delle Immagini Digitali" di Gonzalez e Woods (Ediz. Pearson).
*   **Processing:** Documentazione ufficiale su `processing.org`.
*   **Comunicazioni:** Canali MS Teams, Telegram e contatti email dei docenti.
*   **Siti Web:** `iplab.dmi.unict.it`, `archeomatica.unict.it`.