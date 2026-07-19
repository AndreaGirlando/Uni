###### Classi derivate
In C++ abbiamo le classi derivate, ovvero delle classi che ereditano i metodi della **classe base** (classe padre), la sintassi è la seguente:
```C++
class ClasseDerivata : [spec_acc] ClasseBase {
	membri; 
};
```
Dove "spec_acc" è lo specificatore di accesso e sono i seguenti:
- **public**: è il tipo di ereditarietà più utilizzato
- **private**: è il tipo di ereditarietà per default, in questo caso gli elementi pubblici della classe base sono privati in quella derivata
- **protected**: mantiene accessibili i membri pubblici e protetti nella classe derivata occultandoli all’esterno

Quando dichiariamo un'oggetto di una classe derivata prima che si attivi il costruttore della classe derivata si deve attivare il costruttore della classe base infatti l'oggetto deve esistere prima di diventare un oggetto della classe derivata
![[Pasted image 20250405095733.png]]
Come notiamo dall'output prima vengono avviati i costruttore di B1 e B2 e poi il costruttore di della classe D. Di seguito la dichiarazione del costruttore di una classe derivata:
```C++
ClasseDer::ClasseDer(paramD):ClasseBase(paramB), paramD() { 
	// corpo del costruttore della classe derivata 
};
```
Da questo snippet di codice si capisce meglio:
![[Pasted image 20250405100424.png]]
###### Binding
La connessione tra chiamata di funzione e il codice della funzione stessa viene chiamato **Binding** e ne esistono di 2 tipi:
- **Statico**: se il collegamento avviene in fase di compilazione (**Default**)
- **Dinamico**: se il collegamento avviene in fase di esecuzione (per specificare questo tipo di binding si usa la parola riservata **virtual** anteposto alla dichiarazione di funzione)

###### Funzioni virtuali
la parola **virtual** indica al nostro compilatore che:
- la funzione può essere ridefinita in una classe derivata
- la funzione se invocata tramite un puntatore alla classe base avrà comportamenti differenti in base alla classe derivata chiamante
**Guarda il file [[virtual.cpp]] per degli esempi** 