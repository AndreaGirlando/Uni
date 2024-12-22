/*
**  bubble_sort.c
**
**  Codifica in linguaggio C dell'algoritmo Bubble
**  sort per l'ordinamento di un array di numeri interi.
**
**
**  Pseudo-codifica dell'algoritmo
**
**  Bubble_sort(V):
**    1. flag = 1
**    2. k = n-1
**    3. fintanto che flag = 1 e k>0 ripeti:
**    4.   flag = 0
**    5.   per i=0, ..., k-1 ripeti:
**    6.     se a(i)>a(i+1) allora scambia a(i) ed a(i+1) e poni flag=1
**    7.   k=k-1
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
  for (i=0; i<n; i++) {
    scanf("%d", &x[i]);
  }
  return(n);
}


/*
 * Stampa in output l'array.
 */
void stampa_array(int x[], int n) {
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
 * Funzione che implementa l'algoritmo Bubble sort.
 * Riceve come argomento l'array ed il numero di
 * elementi contenuti nell'array. Non restituisce alcun
 * valore, ma modifica il contenuto dell'array, ordinandolo.
 */
void bubble_sort(int x[], int n) {
  int flag=1, k=n-1, i;

  while (flag == 1 && k > 0) {
    flag = 0;
    for (i=0; i<k; i++) {
      if (x[i]>x[i+1]) {
        scambia(&x[i], &x[i+1]);
        flag = 1;
      }
    }
    k = k-1;
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
  bubble_sort(v, n);
  stampa_array(v, n);
  return(0);
}