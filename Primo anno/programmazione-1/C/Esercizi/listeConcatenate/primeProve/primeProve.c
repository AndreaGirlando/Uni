#include "header.c"

int main(){
    srand(time(NULL));
    system("cls");
    FILE *filePtr = fopen("test.txt","a");
    // writeStructToFile(filePtr,temp);

    Studente *testaPtr = malloc(sizeof(Studente));

    testaPtr->idStudente = 5;
    strcpy(testaPtr->nome,"Andrea");
    strcpy(testaPtr->cognome,"Girlando");
    testaPtr->this = testaPtr;
    Studente *newPtr = testaPtr->next = malloc(sizeof(Studente));;

    writeStructToFile(filePtr, *testaPtr);

    int nodiDaCreare = 25;
    for(int i = 0;i<nodiDaCreare;i++){
        printf("\nCreazione %d struttura",i);

        newPtr->idStudente = rand() % 100 + 1;
        strcpy(newPtr->nome,"Andrea");
        strcpy(newPtr->cognome,"Girlando");
        newPtr->this = newPtr;
        if(i == nodiDaCreare-1){
            newPtr->next = NULL;
        }else{
            newPtr->next = malloc(sizeof(Studente));
        }

        writeStructToFile(filePtr, *newPtr);
        newPtr = newPtr->next;
    }



    fclose(filePtr);
    return 0;
}

