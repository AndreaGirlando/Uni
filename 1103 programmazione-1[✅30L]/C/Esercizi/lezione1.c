#include <stdio.h>// Direttiva al preprocessore dicendo di includere questa libreria
int main()
#define PI 3.14159
{
    //printf("Ciao Mondo\t");//invocazione della funzione printf
    //printf("Ciao Mondo\n");//invocazione della funzione printf


    //! Somma tra 2 numeri

    //int integer1 = 0;
    //int integer2 = 0;
    //printf("Inserisci il primo numero: ");
    //scanf("%d", &integer1);

    //printf("Inserisci il secondo numero: ");
    //scanf("%d", &integer2);

    //printf("La somma è: %d\n", integer1+integer2);

    //Calcolo diametro, circonferenza e area di un cerchio
    //double raggio = 0;

    //printf("Inserisci il raggio di un cerchio: ");
    //scanf("%lf", &raggio);

    //printf("Diametro: %f\n",(double)raggio*2);
    //printf("Circonferenza: %f\n",(double)2*raggio*PI);
    //printf("Area: %f\n", (double)raggio*raggio*PI);

    int peso = 0;
    float altezza = 0;
    printf("Inserisci il tuo peso: ");
    scanf("%d", &peso);

    printf("Inserisci la tua altezza in metri: ");
    scanf("%f", &altezza);

    float bmi = peso/(altezza * altezza);
    printf("Il tuo BMI è: %f\n", bmi);

    printf("\nVALORI del BMI\n");
    printf("Sottopeso: \t meno di 18.5\n");
    printf("Normale: \t tra 18.5 e 24.9\n");
    printf("Sovrappeso: \t tra 25 e 29.9\n");
    printf("Obeso: \t\t 30 o oltre\n");

}
