#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int arr[10], int len);

int main(){
    srand(time(NULL));
    int arr[10];
    int len = 10;

    for(int i = 0; i < len; i++){
        arr[i] = rand()%256;
    }

    printArray(arr,len);

    // for(int i = 0;i<len;i++){
    //     int minimo = i;
    //     for(int j = i;j<len;j++){
    //         if(arr[minimo] > arr[j]){
    //             minimo = j;
    //         }
    //     }
    //     int temp = arr[minimo];
    //     arr[minimo] = arr[i];
    //     arr[i] = temp;
    // }



    // for(int i = 0; i < len;i++){
    //     for(int j = 0;j<len;j++){
    //         if(arr[i]<arr[j]){
    //             int temp = arr[i];
    //             arr[i] = arr[j];
    //             arr[j] = temp;
    //         }
    //     }
    // }

    // for(int i = 0; i < len;i++){
    //     int temp = arr[i];
    //     int j = i-1;
    //     while(j >= 0 && temp < arr[j]){
    //         arr[j+1] = arr[j];
    //         j--;
    //     }
    //     arr[j+1] = temp;
    // }

    printArray(arr,len);

}

void printArray(int arr[10], int len){
    printf("\n\n\n\n");
    for(int i = 0; i < len; i++){
        printf("%10d", arr[i]);
    }
}