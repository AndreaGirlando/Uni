#include <stdio.h>
#include <stdlib.h>
int addUtente(FILE *fileptr);
int getAllStudenti(FILE *filePtr);
int main(){

    FILE *alunniFile;

    if ((alunniFile = fopen("alunni.txt", "a")) == NULL) {
        puts("File could not be opened");
    }
    else{

        while(1){

            int scelta = 0;
            printf("Che cosa vuoi fare?\n");
            printf("1.Inserisci uno studente\n");
            printf("2.Modifica uno studente\n");
            printf("3.Elimina uno studente\n");
            printf("4.Lista studenti\n");
            printf("5.Chiudi\n");
            scanf("%d",&scelta);

            switch (scelta){
                case 1:
                    system("clear");
                    addUtente(alunniFile);
                    break;
                case 2:
                    system("clear");
                    puts("2");
                    break;
                case 3:
                    system("clear");
                    puts("3");
                    break;
                case 4:
                    system("clear");
                    getAllStudenti(alunniFile);
                    break;
                case 5:
                    system("clear");
                    puts("Chiusura");
                    fclose(alunniFile);
                    exit(EXIT_SUCCESS);
                default:
                    system("clear");
                    puts("Default");
                    break;
            }
        }

    }

    return 0;
}

int addUtente(FILE *filePtr){
    char nome[30];
    char cognome[30];
    char matricola[30];

    printf("Inserisci i dati dello studente in questo modo: Nome Cognome Matricola: ");
    scanf("%s %s %s",nome,cognome,matricola);
    fprintf(filePtr, "%s %s %s\n", nome,cognome,matricola);
    system("clear");

    return 0;
}

int getAllStudenti(FILE *filePtr) {
    char nome[30];
    char cognome[30];
    char matricola[30];
    rewind(filePtr); // Riporta il puntatore del file all'inizio
    printf("%-10s%-13s%s\n", "Nome", "Cognome", "Matricola");

    // Usa il valore restituito da fscanf per controllare la lettura
    while (!feof(filePtr)) {
        fscanf(filePtr, "%s %s %s", nome, cognome, matricola);
        printf("%-10s%-13s%s\n", nome, cognome, matricola);
    }

    getchar(); // Attende un input per fermare il programma
    return 0;
}


