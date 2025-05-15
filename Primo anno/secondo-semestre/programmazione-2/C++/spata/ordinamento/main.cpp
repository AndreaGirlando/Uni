#include <iostream>
using namespace std;

void scambio(int& x, int& y){
    int aux = x;
    x = y;
    y = aux;
}

void bubbleSort(int* vettore, int len){

    for(int i = 0;i < len;i++){
        for(int j = 0;j<len;j++){
            if(vettore[i] < vettore[j]){
                scambio(vettore[i],vettore[j]);
            }
        }
    }

}

void insertionSort(int* arr, int len){
    for (int i = 1; i < len; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int *vettore, int len){

    for(int i = 0; i<len;i++){
        int minimo = i;
        for(int j = i+1;j<len;j++){
            if(vettore[minimo] > vettore[j]){
                minimo = j;
            }
        }
        scambio(vettore[i], vettore[minimo]);
    }

}

void stampaArray(int* vettore, int len){
    for(int i = 0;i<len;i++){
        cout << vettore[i] << "\t";
    }
    cout << "\n\n";
}

int main(){
    int input = 0;
    int len = 8;
    int array[len] = {42, 57, 14, 40, 96, 19, 8, 68};

    cout << "Con che cosa vuoi ordinare l'array?" << endl;
    cout << "1. Bubble sort" << endl;
    cout << "2. Selection sort" << endl;
    cout << "3. Insertion sort" << endl;
    cin >> input;

    if(input == 1){
        bubbleSort(array, len);
        stampaArray(array, len);
    }
    else if(input == 2){
        insertionSort(array, len);
        stampaArray(array, len);
    }
    else if(input == 3){
        selectionSort(array, len);
        stampaArray(array, len);
    }
    else{
        cout << "Inserisci un input valido";
    }



    cout << endl;
    return 0;
}