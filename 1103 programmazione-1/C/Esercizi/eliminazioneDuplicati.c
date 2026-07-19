#include<stdio.h>
#include<time.h>
#define size 10
void stampaArray(int a[], int n);
int main() {
    // srand(time(NULL));
    int arr[size];
    int count = 0;
    // for(int i = 0; i < size; i++){
    //     arr[i] = rand()%100 + 9;
    // }

    for (int i = 0; i < size; i++){
        int value = 0;
        int duplicato = 0;
        printf("Inserisci un numero da 10 a 100:");
        scanf("%d", &value);

        if(value < 10 || value > 100){
            i --;
            printf("Numero non valido")
            continue;
        }

        for(int j = 0; j < i; j++){
            if(arr[j] == value){
                duplicato = 1;
                break;
            }
        }

        if(!duplicato){
            arr[count] = value;
            count++;
            printf("\nNumero univoco: %d\n", value);
        }else{
            printf("\nDuplicato inserito\n");
        }
    }

    for(int i = 0; i<count ;i++){
        printf("%6d", arr[i]);
    }
}