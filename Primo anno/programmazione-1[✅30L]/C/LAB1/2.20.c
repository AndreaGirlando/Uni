#include<stdio.h>

#define PI 3.14159

int main() {
    int raggio = 0;

    printf("Inserire il valore del raggio: ");
    scanf("%d", &raggio);

    printf("Il diametro è %d.\n", 2*raggio);
    printf("La circonferenza è %f.\n", 2*PI*raggio);
    printf("L'area è %f.\n", PI * raggio * raggio);

}