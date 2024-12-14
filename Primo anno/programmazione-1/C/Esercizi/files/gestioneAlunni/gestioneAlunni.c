#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int addUtente(FILE *fileptr);
int getAllStudenti(FILE *filePtr);
int getNumberOfStudent(FILE *filePtr);
int updateStudente(FILE *filePtr);
typedef struct {
    char nome[30];
    char cognome[30];
    char matricola[30];
} student;

int main(){

    FILE *alunniFile;

    if ((alunniFile = fopen("alunni.dat", "rb+")) == NULL) {
        puts("File could not be opened");
    }
    else{

        while(1){

            int scelta = 0;
            printf("Che cosa vuoi fare?\n");
            printf("1.Inserisci uno studente\n");
            printf("2.Modifica uno studente\n");
            printf("3.Lista studenti\n");
            printf("4.Chiudi\n");
            scanf("%d",&scelta);

            switch (scelta){
                case 1:
                    system("cls");
                    addUtente(alunniFile);
                    break;
                case 2:
                    system("cls");
                    updateStudente(alunniFile);
                    break;
                case 3:
                    system("cls");
                    getAllStudenti(alunniFile);
                    break;
                case 4:
                    system("cls");
                    puts("Chiusura");
                    fclose(alunniFile);
                    exit(EXIT_SUCCESS);
                default:
                    system("cls");
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
    fwrite(&temp, sizeof(student), 1, filePtr);
    system("cls");

    return 0;
}

int updateStudente(FILE *filePtr) {
    student key, temp;
    long pos; // Variabile per salvare la posizione nel file
    printf("Inserisci i dati dello studente da modificare in questo modo: Nome Cognome Matricola: ");
    scanf("%s %s %s", key.nome, key.cognome, key.matricola);

    rewind(filePtr); // Torna all'inizio del file
    int found = 0; // Flag per indicare se lo studente è stato trovato

    while (fread(&temp, sizeof(student), 1, filePtr)) { // Leggi il file record per record
        if (strcmp(key.nome, temp.nome) == 0 && strcmp(key.cognome, temp.cognome) == 0 && strcmp(key.matricola, temp.matricola) == 0) {
            found = 1;
            pos = ftell(filePtr) - sizeof(student); // Calcola la posizione del record trovato
            printf("Trovato studente: {%s %s %s}\n", temp.nome, temp.cognome, temp.matricola);
            printf("Inserisci i nuovi dati dello studente in questo modo: Nome Cognome Matricola: ");
            scanf("%s %s %s", temp.nome, temp.cognome, temp.matricola);

            fseek(filePtr, pos, SEEK_SET); // Torna indietro alla posizione del record
            fwrite(&temp, sizeof(student), 1, filePtr); // Sovrascrivi il record
            printf("Studente aggiornato correttamente.\n");
            break;
        }
    }

    if (!found) {
        printf("Studente non trovato\n");
    }

    return 0;
}

int getAllStudenti(FILE *filePtr) {
    student temp;
    rewind(filePtr);
    printf("%-15s %-15s %-15s\n", "Nome", "Cognome", "Matricola");

    while (fread(&temp, sizeof(student), 1, filePtr) == 1) {
        printf("%-15s %-15s %-15s\n", temp.nome, temp.cognome, temp.matricola);
    }

    system("pause");
    system("cls");
    return 0;
}



