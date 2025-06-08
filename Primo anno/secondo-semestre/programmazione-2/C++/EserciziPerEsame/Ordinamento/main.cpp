#include <iostream>
#include <cstring>
using namespace std;
#define LEN 10


void stampaArray(int* array, int len){
    cout << "Array:" << endl;
    for(int i = 0;i < len; i++){
        cout << array[i] << "\t";
    }
    cout << endl;
}
void generateRandomArray(int* array, int len){
    for(int i = 0;i < LEN; i++){
        array[i] = rand()%256;
    }
}
void scambia(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}
void bubbleSort(int* array, int len){
    for(int i = 0;i < len; i++){
        for(int j = 0; j<len; j++){
            if(array[i] < array[j]){
                scambia(array[i], array[j]);
            }
        }
    }
}
void selectionSort(int* array, int len){
    for(int i = 0; i < len; i++){
        int min = i;
        for(int j = i; j<len; j++){
            if(array[min]>array[j]){
                min = j;
            }
        }
        scambia(array[min], array[i]);
    }
}

void insertionSort(int* array, int len){
    for(int i = 1; i < len; i++){
        int temp = array[i];
        int j = i-1;
        while(j >= 0 && temp < array[j]){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = temp;
    }
}

void quickSort(int* array, size_t startIndex, size_t endIndex){
    if (endIndex <= startIndex)
        return; // siamo nel caso in cui l'array è formato da un solo elemento

    int pivot = array[endIndex]; // scegliamo l'ultimo elemento del nostro array come pivot
    size_t i = startIndex-1; // posizione dove inserire l'elemento < pivot
    size_t j = startIndex; // indice per scorrere tutto l'array

    //* obiettivo: cercare la corretta del pivot dentro il nostro array
    //? lo facciamo cercando e contando tutti gli elementi più piccoli
    while (j < endIndex) //j scorre fino a quando non raggiunge il pivot
    {
        if (array[j] <= pivot) // se incontra un valore più piccolo del pivot
        {
            i++; //counter elementi più piccoli del pivot, indice dove deve essere inserito l'elemento < pivot
            scambia(array[i], array[j]); // l'elemento i posizione j va in posizione i (che è l'indice dove inserire gli elementi < pivot)
        }
        j++; //passo all'elemento successivo
    }
    scambia(array[i+1],array[endIndex]); // inserisco il pivot nella posizione corretta: numero di elementi più piccoli + 1

    // a questo punto il nostro array avra una struttura del tipo:
    // {3,4,1,2 | pivot | 7, 9, 8, 6}
    // con tutti gli elementi < del pivot e sinistra e quelli > a destra

    quickSort(array,startIndex,i); //richiamiamo ricorsivamente questa funzione sul sottoarray che va dall'inzio fino al pivot
    quickSort(array, i+2, endIndex); // richiamiamo ricorsivamente questa funzione sul sottoarray che dopo il pivot fino alla fine
}

void mergeSort(int* array, size_t left, size_t right);

// Funzione principale che avvia il merge sort
void mergeSort(int* array, size_t size){
    mergeSort(array, 0, size - 1);
}

// Funzione che fonde due sottovettori ordinati array[left..mid] e array[mid+1..right]
void merge(int* array, size_t left, size_t mid, size_t right){
    size_t tempSize = right - left + 1; //calcolo la dimensione del array che mi è stato passato
    int* tempArray = new int[tempSize]; // creo un nuovo array della dimensione specificata dove andrò a copiare i nuovi elementi

    size_t indexLeft = left;       // indice di inizio per la prima metà
    size_t indexRight = mid + 1;   // indice di inizio per la seconda metà
    size_t indexTemp = 0;          // indice per il vettore temporaneo

    // Fusione dei due vettori dentro tempArray con annesso ordinamento
    while ((indexTemp < tempSize) && (indexLeft <= mid) && (indexRight <= right))
    {
        if (array[indexLeft] < array[indexRight]){ // se è vera vuol dire che devo inserire prima array[indexLeft] dentro tempArray
            tempArray[indexTemp] = array[indexLeft];
            indexLeft++;
        }else{ // se entro qui vuol dire che devo inserire prima array[IndexRight] dentro tempArray
            tempArray[indexTemp] = array[indexRight];
            indexRight++;
        }
        indexTemp++;
    }

    // se è vera questa cosa vuol dire che il mio array di sinistra ha degli elementi che non stati copiati
    while (indexLeft <= mid){
        tempArray[indexTemp] = array[indexLeft];
        indexTemp++;
        indexLeft++;
    }

    // se è vera questa cosa vuol dire che il mio array di destra ha degli elementi che non stati copiati
    while (indexRight <= right){
        tempArray[indexTemp] = array[indexRight];
        indexRight++;
        indexTemp++;
    }

    // Copia dell’array temporaneo nell’array originale
    memcpy(array + left, tempArray, tempSize * sizeof(int));
    delete[] tempArray; // deallocazione memoria
}

// Funzione ricorsiva che divide l’array e applica mergeSort
void mergeSort(int* array, size_t left, size_t right){
    if (right <= left)
        return;

    size_t mid = (left + right) / 2;

    // Ordina la prima metà
    mergeSort(array, left, mid);

    // Ordina la seconda metà
    mergeSort(array, mid + 1, right);

    // Combina le due metà ordinate
    merge(array, left, mid, right);
}



int main(){
    srand(time(NULL));
    int* array = new int[20];

    cout << "\nBubble sort ------------------" << endl;
    generateRandomArray(array,LEN);
    stampaArray(array,LEN);
    bubbleSort(array,LEN);
    stampaArray(array,LEN);

    cout << "\nSelection sort ------------------" << endl;
    generateRandomArray(array,LEN);
    stampaArray(array,LEN);
    selectionSort(array,LEN);
    stampaArray(array,LEN);

    cout << "\nInsertion sort ------------------" << endl;
    generateRandomArray(array,LEN);
    stampaArray(array,LEN);
    insertionSort(array,LEN);
    stampaArray(array,LEN);

    cout << "\nQuick sort ------------------" << endl;
    generateRandomArray(array,LEN);
    stampaArray(array,LEN);
    quickSort(array, 0, LEN-1);
    stampaArray(array,LEN);

    cout << "\nMerge sort ------------------" << endl;
    generateRandomArray(array,LEN);
    stampaArray(array,LEN);
    mergeSort(array, LEN);
    stampaArray(array,LEN);

    cout << endl;
    return 0;
}