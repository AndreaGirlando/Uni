# Implementazione del Selection Sort in C

Il seguente codice mostra un'implementazione del **Selection Sort** in linguaggio C. L'algoritmo ordina un array di numeri generati casualmente, stampando l'array ad ogni passo per mostrare l'evoluzione dell'ordinamento.

---

## Dettagli dell'algoritmo Selection Sort

Il **Selection Sort** funziona cercando iterativamente il minimo elemento non ancora ordinato nell'array e scambiandolo con l'elemento alla posizione corrente. Questo processo si ripete fino a quando l'intero array risulta ordinato.

### Passaggi principali:
1. Trovare l'indice dell'elemento più piccolo nella porzione non ordinata dell'array.
2. Scambiare l'elemento più piccolo con il primo elemento della porzione non ordinata.
3. Ripetere il processo per ogni posizione successiva nell'array fino alla fine.

---

## Codice completo

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define dim 10

void printArray(int tempV[dim]);

int main(){
    srand(time(NULL));
    int array[dim];

    // Popolamento dell'array con numeri casuali tra 1 e 100
    for(int i = 0; i < dim; i++){
        array[i] = rand() % 100 + 1;
    }

    // Stampa dell'array iniziale
    printArray(array);

    // Implementazione del Selection Sort
    for(int i = 0; i < dim; i++){
        int smallest = i; // Indice del minimo

        // Trova il minimo nella parte non ordinata
        for(int j = i+1; j < dim; j++){
            if(array[j] < array[smallest]){
                smallest = j;
            }
        }

        // Scambio degli elementi se necessario
        if(smallest != i){
            int temp = array[smallest];
            array[smallest] = array[i];
            array[i] = temp;
        }

        // Stampa dell'array dopo ogni passo
        printArray(array);
    }

    return 0;
}

void printArray(int tempV[dim]){
    printf("\n\n");
    for(int i = 0; i < dim; i++){
        printf("%5d", tempV[i]);
    }
}
```

---

## Spiegazione del codice

1. **Inclusione delle librerie**:
   - `stdio.h` per funzioni di input/output.
   - `stdlib.h` per l'utilizzo di `rand`.
   - `time.h` per inizializzare il seme del generatore di numeri casuali.

2. **Definizione della dimensione dell'array**:
   - La macro `#define dim 10` definisce la dimensione dell'array.

3. **Funzione `printArray`**:
   - Questa funzione stampa gli elementi dell'array con una formattazione semplice.

4. **Generazione di numeri casuali**:
   - L'array viene popolato con numeri casuali compresi tra 1 e 100.

5. **Algoritmo Selection Sort**:
   - **Trova l'indice del minimo**: il ciclo interno confronta ogni elemento nella porzione non ordinata per trovare il valore più piccolo.
   - **Scambia gli elementi**: una volta trovato il minimo, viene scambiato con l'elemento corrente.
   - Dopo ogni scambio, l'array viene stampato per mostrare il progresso dell'ordinamento.

---

## Esempio di output

Supponendo che l'array generato casualmente sia:
```
  45   12   78   34   56   90   11   23   67   89
```
L'algoritmo procederà come segue:

1. Trova il minimo (11) e scambialo con il primo elemento:
```
  11   12   78   34   56   90   45   23   67   89
```
2. Passa alla successiva porzione non ordinata e ripeti:
```
  11   12   23   34   56   90   45   78   67   89
```
...
3. Alla fine, l'array risulta ordinato:
```
  11   12   23   34   45   56   67   78   89   90
```

---

## Complessità dell'algoritmo

- **Caso migliore, caso medio e caso peggiore**: O(n²) a causa dei doppi cicli annidati.
- **Spazio**: O(1), in quanto non richiede memoria aggiuntiva significativa.

---

## Conclusione

Il Selection Sort è un algoritmo semplice e intuitivo, ma non è efficiente per array di grandi dimensioni a causa della sua complessità quadratica. Tuttavia, è utile per scopi didattici e per comprendere le basi degli algoritmi di ordinamento.

