#include <stdio.h>
/*
    ? Di seguito l'utlizzo di sprintf e sscanf
    ? sprintf inserisce la stringa passata in un array di char
    ? sscanf legge dalla stringa passata e in base al formato che passiamo legge i valori che trova
    * Usare queste funzionio potrebbe essere molto utile quando andiamo a creare delle stringhe formattate o leggiamo da quest'ultime
*/
int main() {
    // Variabili per dimostrare l'uso di sprintf e sscanf
    int age = 25;
    char name[] = "Alice";

    char buffer[100]; // Buffer per contenere la stringa formattata

    // Usando sprintf per formattare una stringa
    sprintf(buffer, "%s %d", name, age);

    // Ora buffer contiene la stringa formattata
    printf("Stringa formattata con sprintf: %s\n", buffer);

    // Variabili per il parsing
    char extracted_name[50];
    int extracted_age;

    // Usando sscanf per estrarre i dati dalla stringa
    // Modificato il formato per gestire correttamente la lettura
    sscanf(buffer, "%s %d", extracted_name, &extracted_age);

    // Ora possiamo vedere cosa abbiamo estratto dalla stringa
    printf("Dati estratti con sscanf:\n");
    printf("Name: %s\n", extracted_name);
    printf("Age: %d\n", extracted_age);

    return 0;
}
