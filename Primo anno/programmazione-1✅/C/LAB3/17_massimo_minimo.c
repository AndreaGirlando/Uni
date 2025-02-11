#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int value = 0;
    int max;
    int min;
    printf("Inserire 5 valori interi.\n");
    for(int i = 0; i<5; i++) {
        printf("Inserire valore: ");
        scanf("%d", &value);
        
        // Alternativamente: inizializza solo nella prima iterazione
        if(i==0) {
            max = value;
            min = value;
        }
        
        if(value>max) 
            max = value;
        
        if(value<min)
            min = value;
    }

    printf("Il massimo è: %d\n", max);
    printf("Il minimo è: %d\n", min);
}