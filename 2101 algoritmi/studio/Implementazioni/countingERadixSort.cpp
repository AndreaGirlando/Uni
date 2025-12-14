#include <iostream>
#include <math.h>
using namespace std;

void printArray(int* array, int len){
    cout << endl;
    for(int i = 0; i < len; i++){
        cout << array[i] << "\t";
    }
    cout << endl;
}

int max(int* array, int len){
    int max = array[0];
    for(int i = 0; i < len; i++){
        if(array[i]>max) max = array[i];
    }
    return max;
}

void countingSort(int *A, int* B, int n){
    int k = max(A, n);
    int* C = new int[k+1];

    for(int i = 0; i <= k; i++)
        C[i] = 0;

    for(int i = 0; i < n; i++)
        C[A[i]] = C[A[i]] + 1;

    for(int i = 1; i <= k; i++)
        C[i] = C[i]+C[i-1];

    for(int i = n-1; i >= 0; i--){
        B[C[A[i]]-1] = A[i];
        C[A[i]] = C[A[i]] - 1;
    }
}

//! Main per provare il countingSort
// int main(){
//     int len = 5;
//     int array[len] = {2,6,1,7,8};
//     int* output = new int[len];

//     cout << "Array di base";
//     printArray(array, len);
//     countingSort(array, output, len);
//     printArray(array, len);


//     cout << "\n\n\n";
// }

int scegliCifra(int numero, int digit){
    return (numero/(int)pow(10,digit))%10;
}

void countingSortConCifraSpecifica(int *A, int n, int cifra) {
    const int k = 9;

    int* B = new int[n];
    int* C = new int[k + 1];

    for(int j = 0; j <= k; j++)
        C[j] = 0;

    for(int j = 0; j < n; j++) {
        C[scegliCifra(A[j], cifra)] = C[scegliCifra(A[j], cifra)] + 1;
    }

    for(int j = 1; j <= k; j++)
        C[j] = C[j] + C[j-1];

    for(int j = n - 1; j >= 0; j--) {
        int d = scegliCifra(A[j], cifra);
        B[C[d] - 1] = A[j];
        C[d] = C[d] - 1;
    }

    for (int j = 0; j < n; j++) {
        A[j] = B[j];
    }
}

void radixSort(int* A, int len, int h){
    for(int i = 0; i < h; i++){
        countingSortConCifraSpecifica(A, len, i);
    }
}

//! Main per provare il radixSort
int main(){
    int len = 5;
    int array[len] = {22,61,13,75,81};
    printArray(array, len);
    radixSort(array,len,2);
    printArray(array, len);
}