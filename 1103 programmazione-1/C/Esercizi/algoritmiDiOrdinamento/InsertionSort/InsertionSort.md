# Implementazione di Insertion Sort in C

## Introduzione
Questo documento descrive il funzionamento dell'algoritmo **Insertion Sort**, implementato in linguaggio C. L'algoritmo ordina un array di numeri interi generati casualmente e utilizza una funzione per stampare l'array ad ogni passo significativo del processo di ordinamento.

---

## Codice Completo

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define dim 10

void printArray(int tempV[dim]);

int main(){
    srand(time(NULL));
    int array[dim];
    for(int i = 0; i < dim; i++){
        array[i] = rand() % 100 + 1;
    }

    printArray(array);

    for (int i = 1; i < dim; i++){
        int j = i - 1;
        int temp = array[i];

        while (j >= 0 && array[j] > temp)
        {
            array[j + 1] = array[j]; // Sposta l'elemento più grande verso destra
            j--;
            printArray(array);
        }

        // Inserisce temp nella posizione corretta più a sinistra possibile
        array[j + 1] = temp;

        printf("\n<------------------->\n");
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

## Dettagli dell'Algoritmo

### 1. Generazione dell'Array
L'array di dimensione `dim` viene riempito con numeri interi casuali compresi tra 1 e 100 grazie alla funzione:

```c
array[i] = rand() % 100 + 1;
```

Il seme della funzione random (“rand”) viene inizializzato con l'ora corrente tramite `srand(time(NULL))`.

### 2. Stampa dell'Array
La funzione ausiliaria `printArray` stampa l'intero contenuto dell'array formattato su una riga:

```c
void printArray(int tempV[dim]){
    printf("\n\n");
    for(int i = 0; i < dim; i++){
        printf("%5d", tempV[i]);
    }
}
```

Questa funzione viene invocata sia prima che durante il processo di ordinamento, per mostrare i progressi.

### 3. Ciclo Principale dell'Insertion Sort
L'algoritmo itera sull'array a partire dal secondo elemento:

```c
for (int i = 1; i < dim; i++){
    int j = i - 1;
    int temp = array[i];
```

Qui, `temp` rappresenta il valore che deve essere inserito nella porzione ordinata dell'array.

### 4. Spostamento degli Elementi
Confronta `temp` con gli elementi a sinistra (già ordinati):

```c
while (j >= 0 && array[j] > temp)
{
    array[j + 1] = array[j]; // Sposta l'elemento più grande verso destra
    j--;
    printArray(array);
}
```

Se un elemento è maggiore di `temp`, viene spostato di una posizione a destra per fare spazio al valore corrente.

### 5. Inserimento del Valore
Quando viene trovata la posizione corretta (o si raggiunge l'inizio dell'array), il valore di `temp` viene inserito:

```c
array[j + 1] = temp;
```

A questo punto, il sottovettore è ordinato fino alla posizione `i`.

### 6. Divisione in Passaggi
Dopo ogni iterazione del ciclo principale, viene stampato un divisore per separare i passaggi:

```c
printf("\n<------------------->\n");
```

---

## Output del Programma

Un esempio di output potrebbe essere:

```
   23   42   17   88   55   12   94   31   76   65

   23   42   42   88   55   12   94   31   76   65

   17   23   42   88   55   12   94   31   76   65

<------------------->

   17   23   42   88   88   12   94   31   76   65

   17   23   42   55   88   12   94   31   76   65

<------------------->
```

Ogni passo mostra lo stato attuale dell'array, illustrando come gli elementi vengono spostati e inseriti nella loro posizione corretta.

---

## Complessità Computazionale

- **Caso Peggiore**: \( O(n^2) \), quando l'array è ordinato in ordine decrescente.
- **Caso Medio**: \( O(n^2) \).
- **Caso Migliore**: \( O(n) \), quando l'array è già ordinato.

---

## Conclusioni
L'Insertion Sort è un algoritmo semplice e intuitivo, particolarmente efficiente per array piccoli o quasi ordinati. Tuttavia, per array più grandi, algoritmi più complessi come Quick Sort o Merge Sort sono generalmente preferibili a causa della loro migliore complessità nel caso medio.

