#include<stdio.h>

int main(void) {
    double altezza = 0;
    double peso = 0;
    double BMI = 0;

    printf("Quanto pesi? ");
    scanf("%lf", &peso);
    printf("Quanto sei alto? ");
    scanf("%lf", &altezza);

    BMI = peso / (altezza*altezza);

    printf("Il tuo BMI è: %f\n", BMI);
    
}