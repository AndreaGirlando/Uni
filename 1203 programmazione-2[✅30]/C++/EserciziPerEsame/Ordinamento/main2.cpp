#include <iostream>
using namespace std;
void stampaArray(int* array, int len){
    cout << "Array:" << endl;
    for(int i = 0;i < len; i++){
        cout << array[i] << "\t";
    }
    cout << endl;
}
void generateRandomArray(int* array, int len){
    for(int i = 0;i < len; i++){
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
        for(int j = 0;j < len; j++){
            if(array[i]>array[j]){
                scambia(array[i],array[j]);
            }
        }
    }
}

void selectionSort(int* array, int len){
    for(int i = 0;i < len; i++){
        int min = i;
        for(int j = i;j < len; j++){
            if(array[min]<array[j]){
                min = j;
            }
        }
        scambia(array[min], array[i]);
    }
}

void insertionSort(int* array, int len){
    for(int i = 0;i < len; i++){
        int temp = array[i];
        int j = i-1;
        while(j>=0 && temp >= array[j]){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = temp;
    }
}

int main(){
    int len = 25;
    int* array = new int[len];
    generateRandomArray(array,len);
    stampaArray(array,len);

    // bubbleSort(array,len);
    // selectionSort(array,len);
    insertionSort(array,len);
    stampaArray(array,len);

    return 0;
}