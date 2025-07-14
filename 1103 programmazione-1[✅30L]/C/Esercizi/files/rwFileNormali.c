#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct {
    char nome[30];
    int cilindrata;
    int cavalli;
}car;
/*
    ? fscanf(puntatoreAlFile,stringTemplate,variabiliDoveMettereIValori)
        * legge dal file (serve la & quando leggi variabili non stringa)
    ? fprintf(puntatoreAlFile,stringTemplate,variabiliDoveSiTrovanoIValori)
        * Scrive sul file
*/
void writeRecords(FILE *tempFilePtr, int numberOfRecords);
void readRecords(FILE *tempFilePtr);
void loadRecords(FILE *tempFilePtr,car tempV[], int numberOfRecords);
int numberOfRow(FILE *tempFilePtr);
int main(){
    srand(time(NULL));
    FILE *filePtr = NULL;
    filePtr = fopen("test.txt","w+");
    if(filePtr == NULL){
        exit(EXIT_FAILURE);
    }
    int randNumber = rand() % 50 + 1;


    writeRecords(filePtr,randNumber);
    rewind(filePtr);
    int n = numberOfRow(filePtr);
    rewind(filePtr);
    car vettore[n];
    loadRecords(filePtr,vettore,n);
    rewind(filePtr);

    //? Ordino tutte le macchine in base ai cavalli
    for(int i = 0; i<n; i++){
        for(int j = 0; j < n; j++){
            if(vettore[i].cavalli > vettore[j].cavalli){
                car temp = vettore[i];
                vettore[i] = vettore[j];
                vettore[j] = temp;
            }
        }
    }

    for(int i = 0;i<n;i++){
        printf("%s-%d-%d\n", vettore[i].nome,vettore[i].cilindrata,vettore[i].cavalli);
    }


    printf("\n<---------------------------->\n");
    rewind(filePtr);
    readRecords(filePtr);


    fclose(filePtr);
    return 0;
}
void readRecords(FILE *tempFilePtr){
    car temp;
    while(!feof(tempFilePtr)){
        fscanf(tempFilePtr, "%30s %d %d",temp.nome,&temp.cilindrata,&temp.cavalli);
        printf("%s %d %d\n", temp.nome,temp.cilindrata,temp.cavalli);
    }
}











void loadRecords(FILE *tempFilePtr,car tempV[], int numberOfRecords){
    for(int i = 0; i<numberOfRecords; i++){
        fscanf(tempFilePtr,"%30s %d %d",tempV[i].nome,&tempV[i].cilindrata,&tempV[i].cavalli);
    }
}


void writeRecords(FILE *tempFilePtr, int numberOfRecords){
    char *randomCarNames[7] = {"Ferrari", "Fiat", "Lamborghini","Mustang","Ford","Kia","Tesla"};
    for(int i = 0; i < numberOfRecords; i++){
        car temp;
        temp.cilindrata = rand() % 5000 + 1;
        temp.cavalli = rand() % 450 + 1;
        strcpy(temp.nome,randomCarNames[rand() % 6]);
        fprintf(tempFilePtr, "%s %d %d\n",temp.nome,temp.cilindrata,temp.cavalli);
    }
}


int numberOfRow(FILE *tempFilePtr){
    int n = 0;
    while(!feof(tempFilePtr)){
        car temp;
        n = n + 1;
        fscanf(tempFilePtr,"%30s %d %d",temp.nome,&temp.cilindrata,&temp.cavalli);
    }
    return n;
}

