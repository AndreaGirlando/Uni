#include <stdio.h>
#include <stdlib.h>
int addUtente(FILE *fileptr);
int getAllStudenti(FILE *filePtr);
typedef struct {
    char nome[30];
    char cognome[30];
    char matricola[30];
} student;
int main(){

    FILE *alunniFile;

    if ((alunniFile = fopen("alunni.txt", "a+")) == NULL) {
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
                    system("cls");
                    addUtente(alunniFile);
                    break;
                case 2:
                    system("cls");
                    puts("2");
                    break;
                case 3:
                    system("cls");
                    puts("3");
                    break;
                case 4:
                    system("cls");
                    getAllStudenti(alunniFile);
                    break;
                case 5:
                    system("cls");
                    puts("Chiusura");
                    fclose(alunniFile);
                    exit(EXIT_SUCCESS);
                default:
                    system("cls");
                    puts("Default");
                    break;
            }
        }

    }

    return 0;
}

int addUtente(FILE *filePtr){
    student temp;

    printf("Inserisci i dati dello studente in questo modo: Nome Cognome Matricola: ");
    scanf("%s %s %s",temp.nome,temp.cognome,temp.matricola);
    fprintf(filePtr, "%s %s %s\n", temp.nome,temp.cognome,temp.matricola);
    system("cls");

    return 0;
}

int getAllStudenti(FILE *filePtr) {
    student temp;
    rewind(filePtr);
    printf("%-15s %-15s %-15s\n", "Nome", "Cognome", "Matricola");

    while (!feof(filePtr)) {
        fscanf(filePtr, "%15s %15s %15s", temp.nome,temp.cognome,temp.matricola);
        printf("%-15s %-15s %-15s\n", temp.nome,temp.cognome,temp.matricola);
    }

    system("pause");
    system("cls");
    return 0;
}


