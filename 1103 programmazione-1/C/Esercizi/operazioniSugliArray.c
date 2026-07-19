#include<stdio.h>
#define size 10
int indexOfMin(int a[], int n);
int indexOfMax(int a[], int n);
void stampaArray(int a[], int n);
int contaPari(int a[], int n);
int contaDispari(int a[], int n);
void invertiArray(int a[], int n);
int main() {

    int arr[size] = {2,4,6,8,15,12,14,16,18,20};

    int minIndex = indexOfMin(arr, size);
    int maxIndex = indexOfMax(arr, size);
    printf("Array default:");
    stampaArray(arr,size);
    int temp = arr[minIndex];
    arr[minIndex] = arr[maxIndex];
    arr[maxIndex] = temp;
    printf("Array con minimo e massimo invertiti: ");
    stampaArray(arr,size);


    printf("\n\nI numeri pari sono: %d", contaPari(arr, size));
    printf("\n\nI numeri dispari sono: %d", contaDispari(arr, size));

    printf("\n\nArray invertito: ");
    invertiArray(arr,size);


}
void invertiArray(int a[], int n){
    int tempArray[n];

    for(int i = 0; i < n; i++){
        tempArray[i] = a[n-1-i];
    }

    stampaArray(tempArray,size);

}

int contaDispari(int a[], int n){
    int nDispari = 0;
    for(int i=0; i<n; i++){
        if(a[i]%2 == 1){
            nDispari++;
        }
    }
    return nDispari;
}

int contaPari(int a[], int n){
    int nPari = 0;
    for(int i=0; i<n; i++){
        if(a[i]%2 == 0){
            nPari++;
        }
    }
    return nPari;
}

int indexOfMin(int a[], int n){
    int min = a[0];
    int index = 0;
    for(int i=0; i<n-1; i++){
        if(a[i]<min){
            min = a[i];
            index = i;
        }
    }
    return index;
}


int indexOfMax(int a[], int n){
    int max = a[0];
    int index = 0;
    for(int i = 0; i < n-1; i++){
        if(max < a[i]){
            max = a[i];
            index = i;
        }
    }
}

void stampaArray(int a[], int n){
    printf("\n");
    for(int i = 0; i<n;i++){
        printf("%6d", a[i]);
    }
    printf("\n");
}