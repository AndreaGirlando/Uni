#include <iostream>
using namespace std;

void quickSort(int vettore[], int p, int r);
void quickSort(int vettore[], int n);

void scambia(int& a, int& b) {
    int appoggio = a;
    a = b;
    b = appoggio;
}

void quickSort(int vettore[], int len) {
    quickSort(vettore, 0, len - 1);
}

void quickSort(int vettore[], int startIndex, int endIndex) {
    cout << endl << "start quickSort call: startIndex = " << startIndex << " endIndex = " << endIndex << endl;
    if (endIndex <= startIndex)
        return;

    int pivot = vettore[endIndex]; //* setto come pivot l'ultimo elemento del sottoarray

    size_t i = startIndex-1;
    size_t j = startIndex;

    while (j < endIndex){//* con questo while ordino tutti gli elementi che si trovano prima del mio pivot
        if (vettore[j] <= pivot){
            i++;//* questo conta quanti numeri sto scambiando
            scambia(vettore[i], vettore[j]);
        }
        j++;
    }

    scambia(vettore[i+1],vettore[endIndex]);//* Inserisco il pivot in posizione corretta, dopo tutti gli elementi ordinati

    quickSort(vettore,startIndex,i);//* richiamo la funzione quickSort per ordinare la parte sinistra del mio pivot
    quickSort(vettore,i+2,endIndex);//* richiamo la funzione quickSort per ordinare la parte destra del mio pivot (ovviamente salto il pivot stesso)
    cout << endl << "end quickSort call: startIndex = " << startIndex << " endIndex = " << endIndex << endl;
}

void print(int v[], int len) {
    cout << "\n\narray:\t";
    for (int i = 0; i < len; i++) {
        cout << v[i] << "\t";
    }
    cout << endl;
}

int main() {
    int array[] = {5, 1, 76, 46, 29};
    int len = sizeof(array) / sizeof(int);

    print(array, len);
    quickSort(array, len);
    print(array, len);

    return 0;
}
