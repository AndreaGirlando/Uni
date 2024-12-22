/*
**  insertion_sort.c
**
**  Codifica in linguaggio C dell'algoritmo Insertion
**  sort per l'ordinamento di un array di numeri interi.
**
**
**  Pseudo-codifica dell'algoritmo
**
**  Insertion_sort(V):
**    1. per ogni i=1, 2, ..., n-1 ripeti:
**    2.   poni x = V[i]
**    3.   inserisci x nella posizione corretta nel sotto-array
**         ordinato <V[0], ..., V[i-1]> spostando a destra
**         gli elementi V[k]>x (0≤k<i).
**  END
**
**
**
*/

#include <stdlib.h>
#include <stdio.h>

#define MAX 100

/*
 * Legge in input il numero n ed n numeri interi
 * che memorizza nell'array. Restituisce il numero
 * di elementi letti (n).
 */

int leggi_array(int x[]) {
  int i, n;
  printf("Numero di elementi: ");
  scanf("%d", &n);
  printf("Inserisci %d elementi: ", n);
  for (i=0; i<n; i++)
    scanf("%d", &x[i]);
  return(n);
}


/*
 * Stampa in output l'array.
 */

void stampa_array(int x[], int n) {
  int i;
  for (i=0; i<n; i++)
    printf("%d ", x[i]);
  printf("\n");
  return;
}


/*
 * Funzione che implementa l'algoritmo Insertion sort.
 * Riceve come argomento l'array ed il numero di
 * elementi contenuti nell'array. Non restituisce alcun
 * valore, ma modifica il contenuto dell'array, ordinandolo.
 */

void insertion_sort(int x[], int n) {
  int i, j, app;
  for (i=1; i<n; i++) {
    app = x[i];
    j = i-1;
    while (j>=0 && x[j]>app) {
      x[j+1] = x[j];
      j--;
    }
    x[j+1] = app;
  }
  return;
}


/*
 *  Funzione principale
 */

int main(void) {
  int v[MAX], n;
  n = leggi_array(v);
  stampa_array(v, n);
  insertion_sort(v, n);
  stampa_array(v, n);
  return(0);
}