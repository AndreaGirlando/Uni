#include<stdio.h>

#define PI 3.14159

int main() {
    double raggio = 0;
    double diametro = 0;
    double area = 0;
    
    printf("Inserire il valore del raggio: ");
    scanf("%f", &raggio);

    diametro = 2*raggio;
    circonferenza = diametro*PI;
    area = PI * raggio * raggio;

    printf("Il diametro è %d.\n", diametro);
    printf("La circonferenza è %f.\n", circonferenza);
    printf("L'area è %f.\n", area);

}