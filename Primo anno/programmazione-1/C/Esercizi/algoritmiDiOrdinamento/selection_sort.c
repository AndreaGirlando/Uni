/*
**  selection_sort.c
**
**  Codifica in linguaggio C dell'algoritmo Selection
**  sort per l'ordinamento di un array di numeri interi.
**
**
**  Pseudo-codifica dell'algoritmo
**
**  Selection_sort(V):
**    1. per ogni i=0, 1, 2, ..., n-1 ripeti:
**    2.   seleziona l'elemento minimo nel sotto array 
**         {V[i], V[i+1], ..., V[n-1]} e scambialo con l'elemento V[i]
**  END
**
**
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX 100

/*
 * Legge in input il numero n e genera una sequenza di n
 * interi casuali minori di 100 che memorizza nell'array.
 * Restituisce il numero di elementi generati (n).
 */

int generaArray(int x[]) {
  int i, n;
  printf("Numero di elementi: ");
  scanf("%d", &n);
  srand((unsigned)time(NULL));
  for (i=0; i<n; i++) {
    x[i] = rand() % 100;
  }
  return(n);
}


/*
 * Stampa in output l'array.
 */

void stampaArray(int x[], int n) {
  int i;
  for (i=0; i<n; i++) {
    printf("%d ", x[i]);
  }
  printf("\n");
  return;
}


/*
 * Scambia il contanuto delle due variabili
 * indirizzate dai puntatori x e y.
 */

void scambia(int *x, int *y) {
  int z;
  z = *x;
  *x = *y;
  *y = z;
  return;
}


/*
 * Funzione che implementa l'algoritmo Selection sort.
 * Riceve come argomento l'array ed il numero di
 * elementi contenuti nell'array. Non restituisce alcun
 * valore, ma modifica il contenuto dell'array, ordinandolo.
 */

void selectionSort(int x[], int n) {
  int i, j, min;
  for (i=0; i<n-1; i++) {
    min = i;
    for (j=i+1; j<n; j++)
      if (x[j]<x[min])
        min = j;
    scambia(&x[i], &x[min]);
  }
  return;
}


/*
 *  Funzione principale
 */

int main(void) {
  int v[MAX], n;

  n = generaArray(v);
  stampaArray(v, n);
  selectionSort(v, n);
  stampaArray(v, n);
  return(0);
}