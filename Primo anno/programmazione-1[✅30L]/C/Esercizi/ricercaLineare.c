#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 100
int linearSearch(int key,int a[size]);
int main(){
    srand(123);
    int array[size] = {0};

    for(int i = 0; i<size; i++){
        array[i] = rand() % 100 + 1;
        printf("%5d", array[i]);
    }
    int key = 0;

    printf("\n\nInserisci il numero da cercare nella sequenza: ");
    scanf("%d", &key);

    int index = linearSearch(key, array);

    if(index == -1){
        printf("\nIl numero non è stato trovato\n");
    }else{
        printf("\nIl numero è stato trovato nell'indice: %d\n", index);
    }
    return 0;
}

int linearSearch(int key,int a[size]){
    for(int i = 0; i<size; i++){
        if(a[i] == key){
            return i;
        }
    }
    return -1;

}