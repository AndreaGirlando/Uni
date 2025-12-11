Ecco **un compito d’esame strutturato**, completamente analogo a quello che hai mostrato, **con lo stesso tipo di logica ma con un soggetto diverso**.  
Ho scelto come oggetto dei **quadrati che si muovono**, con una classe base e una derivata, input da tastiera, movimento, gravità, rimbalzi, ecc.

---

# 📘 **Compito d’esame – Programmazione Grafica con Processing**

## **Traccia**

Realizza un programma in Processing che simuli un insieme di **quadrati che si muovono sullo schermo**, rimbalzando sui bordi e subendo la gravità.

Il programma deve implementare **ereditarietà, overriding, array dinamici** e gestione della tastiera.

---

## **1. Requisiti**

### **1.1 Classe `Square` (classe base)**

Devi implementare una classe `Square` con:

- Variabili:
    
    - `float posX, posY` → posizione
        
    - `float size` → lato del quadrato
        
    - `float speedX, speedY` → velocità
        
- Costruttori:
    
    1. Uno che riceve **posizione, dimensione e velocità**
        
    2. Uno che crea un quadrato fermo (speedX = speedY = 0) dato solo posizione e dimensione
        
- Metodi:
    
    - `display()` → disegna un quadrato **rosso**
        
    - `move()` → aggiorna la posizione
        
    - `bounce()` → inverte le velocità quando tocca i bordi
        
    - `gravity()` → aumenta `speedY` di 0.15
        
    - `run()` → chiama in ordine: `gravity()`, `move()`, `bounce()`, `display()`
        

---

### **1.2 Classe `BlueSquare` (classe derivata)**

Questa classe deve **estendere `Square`**, cambiando solo il modo in cui viene disegnato:

- `display()` deve essere sovrascritto per disegnare un quadrato **blu**
    
- I costruttori devono richiamare `super(...)` come nel codice fornito a lezione
    

---

### **1.3 Funzioni principali**

Nel tuo sketch devi:

- Creare un `ArrayList<Square>` chiamato `as`
    
- Nel `draw()`:
    
    - Sfondo nero
        
    - Per ogni elemento della lista, chiamare `run()`
        

---

### **1.4 Gestione tastiera**

Implementa:

- `tasto 'r'` → crea un nuovo quadrato rosso (`Square`)
    
- `tasto 'b'` → crea un nuovo quadrato blu (`BlueSquare`)
    

Le proprietà dei nuovi quadrati devono essere scelte con:

- Posizione casuale, tale da stare sempre dentro allo schermo
    
- Dimensione tra 20 e 60
    
- Velocità orizzontale e verticale tra 1 e 8
    

---

## **2. Vincoli**

- Non usare array normali: solo `ArrayList`
    
- Usare l’ereditarietà per evitare duplicazioni di codice
    
- La classe derivata deve ridefinire solo il necessario, non riscrivere la logica già implementata nella classe base
    
- Non usare funzioni statiche o globali diverse da quelle viste nel corso
    

---

## **3. Domande teoriche (parte scritta)**

1. Spiega cosa significa **overriding** in Java e perché viene usato in questo esercizio.
    
2. Descrivi la differenza tra:
    
    - chiamare un metodo normale
        
    - chiamare un metodo attraverso l’oggetto contenuto in un `ArrayList`
        
3. Perché è utile avere la funzione `run()` invece di chiamare manualmente `display`, `move`, ecc. nel ciclo principale?
    
4. Perché nei rimbalzi si confronta `posX < size/2` invece di `posX < 0`?
    

---

## **4. Extra (per il 30 e lode)**

Aggiungere un'altra classe derivata, ad esempio `RotatingSquare`, che oltre ai metodi base:

- ruota lentamente il quadrato (`rotate()`)
    
- sovrascrive `display()` per applicare correttamente la rotazione
    

---

Se vuoi, posso anche:

✅ fornirti **la soluzione completa del compito**  
✅ creare **altri compiti simili** con cerchi, triangoli, astronavi, farfalle, emoji ecc.  
✅ creare un **mock di esame** con timer e griglia di valutazione

Vuoi la soluzione o un altro esempio?