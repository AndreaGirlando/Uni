#include<stdio.h>
#include<time.h>
#define Size 500
int main() {
    srand(time(NULL));
    int defaultArray[Size];
    printf("\n\n\n");

    for (int t = 0; t < Size ; t++){
        defaultArray[t] = 1 + rand()%100; //Qeusta riga genera un numero che va ad 0 a 100
    }

    for (int t = 0; t < Size ; t++){
        printf("%4d", defaultArray[t]);//Stampo tutto l'array specificando 4 caratteri di spazio tra un numero e un'altro
    }


    printf("\n\n\n");

    for(int i = 0; i < Size; i++){//Scorro tutti gli elementi dell'array

        for(int j = 0; j < Size; j++){//Confronto ogni singolo elemento con l'elemento successivo

            if(defaultArray[j] > defaultArray[j+1]){//Se l'elemento j è piu grande dell'elemento j+1 li scambio di posto
                int temp = defaultArray[j];
                defaultArray[j] = defaultArray[j+1];
                defaultArray[j+1] = temp;
            }
        }
    }

    for (int t = 0; t < Size ; t++){
        printf("%4d", defaultArray[t]);
    }
}