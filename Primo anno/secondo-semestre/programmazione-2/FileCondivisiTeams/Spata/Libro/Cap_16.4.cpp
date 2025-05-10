// 16.4
/* Ordinare il vettore
42 57 14 40 96 19 08 68
mediante i metodi: (a) bubblesort; (b) selezione; (c) inserimento
*/

#include <iostream>
using namespace std;

template <typename T> void scambia (T& v1, T& v2) {
	T aux = v1;
	v1 = v2;
	v2 = aux;
}
  
template <typename T> void selezione(T a[], int n) {
	int indicemin;
    for (int i = 0; i < n - 1; i++) {
		indicemin = i;
        for (int j = i+1; j < n; j++)
            if (a[j] < a[indicemin]) indicemin = j;
              scambia(a[indicemin], a[i]);
	}
}

template <typename T> void bubbleSort(T a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; i < j; j--)
            if (a[j] < a[j - 1])
              scambia(a[j], a[j - 1]);
}

template <typename T> void inserimento(T a[], int n) {
	int j, appoggio;
    for (int i = 1; i < n; i++) {
		appoggio = a[i];
		j = i;
        while (j > 0 && appoggio < a[j-1]) {
			a[j] = a[j-1];
			j--;
			}
			a[j] = appoggio;
		}
}

int main() {
    int a[] = {42, 57, 14, 40, 96, 19, 8, 68};
    int b[] = {42, 57, 14, 40, 96, 19, 8, 68};
    int c[] = {42, 57, 14, 40, 96, 19, 8, 68};
    int n = sizeof(a) / sizeof(a[0]); 
    selezione <int>(a, n);
    cout << "\nVettore ordinato per selezione: \t";
    for (int i = 0; i < n; i++) cout << a[i] << '\t';
    bubbleSort <int>(b, n);
    cout << "\nVettore ordinato per bubblesort:\t";
    for (int i = 0; i < n; i++) cout << a[i] << '\t';
    inserimento <int>(c, n);
    cout << "\nVettore ordinato per inserimento:\t";
    for (int i = 0; i < n; i++) cout << a[i] << '\t';
    cout << endl;
  return 0;
}
