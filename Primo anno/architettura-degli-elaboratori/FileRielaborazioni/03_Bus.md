Questo file è la rielaborazione delle slide [[03_Bus]]

Il bus è l'unità di interconnessione tra i vari componenti della macchina di von Neumann. Esso si presenta come un fascio ordinato di linee, ognuna delle quali può assumere il significato di un bit. Il bus quindi è come un mezzo di trasporto delle informazioni tra la CPU (detta Master) la memoria e I/O (detti slave). 
![[Pasted image 20241013094756.png]]
Da questa immagine riusciamo ad indentificare vari tipi di collegamenti:
- da processore a memoria
- da memoria a processore
- da processore a I/0 
- da I/O a processore
Considerando il processore come master. un'operazione che trasporta un dato dal processore alla memoria è detta operazione di ***Write***, nel verso opposto viene chiamata operazione di ***Read*** il tempo che intercorre tra il segnale di invio dell'operazione e l'operazione stessa si chiama **Lantenza**. Per riuscire a gestire il trasferimento dei dati il bus è diviso in tre diversi tipi di linea:
- ***Address bus*** (ABus)
- ***Data bus*** (DBus)
- ***Control bus*** (CBus)

Per una corretto trasferimento dei dati vengono usati tutti e tre i tipi di bus:
- le linee DBus usate per il trasferimento dei dati
- le linee ABus contenenti le informazioni su gli indirizzi da utilizzare per il trasferimento
- e svariate linee CBus ognuna con uno dei seguenti compiti:
	-  ***I/0-Mem***: un tipo di linea che indica la direzione del trasferimento:
		- **Dal processore alle periferiche I/O**: il valore del bus viene impostato a 1
		- **Dal processore alla memoria**: il valore del bus viene impostato a 0
	- ***R/W***: un tipo di linea che indica il tipo di trasferimento:
		- **Read**: il valore del bus viene impostato a 1
		- **Write**: il valore del bus viene impostato a 0
	- ***WAIT***: un tipo di linea che indica se il trasferimento è stato completato o se il trasferimento è in corso:
		- **Trasferimento completato**: il valore del bus viene impostato su 1
		- **Trasferimento in corso** :  il valore del bus viene impostato su 0

la velocità del bus è determinata da un "orologio" interno, chiamato "clock" che scandisce il tempo in modo costante, come un metronomo, e sincronizza tutte le operazioni che avvengono sul bus. Le dimensioni dei bus possono variare e soprattutto influenzano [[01_Architettura#Bottleneck|il collo di bottiglia]]:
- **ABus**: la dimensione di questo tipo di Bus specifica la quantità di memoria raggiungibile dai programmi e si calcola e elevando a 2 il numero di ABus
- **DBus**: la dimensione di questo tipo di Bus rappresenta invece il grado di parallelismo del processore, ovvero la quantità di dati che è in grado di elaborare simultaneamente
***<mark class="hltr-green">NB: stiamo parlando della dimensione dei gruppi di bus, infatti un singolo bus porta solo un bit come giù scritto all'inizio</mark>***
All'interno di una scheda madre è difficile vedere i bus di sistema, quindi tutto quello che è dedicato ai bus che siano le linee fisiche o i chip vengono indicati con il nome ***Chipset***. Ovviamente esistono vari tipi di bus ma quello più importanti è il PCI ultimamente molto diffuso e soprattutto la sua variante express usato principalmente per le schede video.

# Ci sono delle cose nuove nel pdf specificato, devono essere aggiunte