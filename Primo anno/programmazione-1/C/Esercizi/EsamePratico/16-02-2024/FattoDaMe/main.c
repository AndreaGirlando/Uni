#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct param{
    char input[256];
    char output[256];
};
typedef struct param param;

struct nodo{
    char nome[255];
    char cognome[255];
    int eta;
    int peso;
    int altezza;
    char sesso;
    struct nodo *next;
};
typedef struct nodo nodo;

param readInput(int argc, char **argv);
void insertInList(nodo **testa,nodo req);
nodo* readFile(char input[255]);
void printList(nodo *testa);
float imc(nodo *element);
nodo* getMax(nodo *testa);
void deleteNodo(nodo **testa, nodo* element);
void insertInHead(nodo **testa,nodo req);
void writeFile(nodo *testa,char output[256]);

int main(int argc, char **argv){

    param res = readInput(argc,argv);
    printf("Input: %s\n",res.input);
    printf("Output: %s\n",res.output);


    printf("\n\nLa lista A:\n");
    nodo *testaA = readFile(res.input);
    printList(testaA);

    nodo *testaB = NULL;

    nodo *max = getMax(testaA);
    printf("\n\nUtente con il massimo IMC: %s %s %d %d %d %d %c\n\n",max->nome,max->cognome,max->eta,max->peso,max->altezza,max->sesso);

    for(int i = 0;i<3;i++){
        nodo *maxImc = getMax(testaA);
        insertInHead(&testaB,*maxImc);
        deleteNodo(&testaA,maxImc);
    }


    printf("\n\nLa lista A:\n");
    printList(testaA);
    printf("\n\nLa lista B:\n");
    printList(testaB);

    writeFile(testaB,res.output);

    return 0;
}

void writeFile(nodo *testa,char output[256]){
    FILE *filePtr = fopen(output,"w");
    while(testa!=NULL){
        fprintf(filePtr,"%s %s %d %d %d %c\n",testa->nome,testa->cognome,testa->eta,testa->peso,testa->altezza,testa->sesso);
        testa = testa->next;
    }
}

void insertInHead(nodo **testa,nodo req){

    nodo *newNodo = malloc(sizeof(nodo));
    strcpy(newNodo->nome,req.nome);
    strcpy(newNodo->cognome,req.cognome);
    newNodo->eta = req.eta;
    newNodo->peso = req.peso;
    newNodo->altezza = req.altezza;
    newNodo->sesso = req.sesso;
    newNodo->next = *(testa);

    *(testa) = newNodo;

}

void deleteNodo(nodo **testa, nodo* element){

    if(*(testa) == element){
        *(testa) = element->next;
        free(element->nome);
        free(element->cognome);
        free(element);
        return;
    }else{
        nodo *tempTesta = *(testa);
        nodo *prec = NULL;
        while(tempTesta != NULL){
            if(strcmp(tempTesta->nome,element->nome) == 0 && strcmp(tempTesta->cognome,element->cognome) == 0 && tempTesta->eta == element->eta){
                if(prec == NULL){
                    *(testa) = element->next;
                    free(element->nome);
                    free(element->cognome);
                    free(element);
                }else{
                    prec->next = tempTesta->next;
                    free(tempTesta->nome);
                    free(tempTesta->cognome);
                    free(tempTesta);
                    return;
                }
            }

            prec = tempTesta;
            tempTesta = tempTesta->next;
        }
    }

}

nodo* getMax(nodo *testa){
    int massimo = imc(testa);
    nodo *tempMaxNodo = testa;
    while(testa != NULL){
        int tempImc = imc(testa);
        if(tempImc > massimo){
            massimo = tempImc;
            tempMaxNodo = testa;
        }
        testa = testa->next;
    }
    return tempMaxNodo;
}

float imc(nodo *element){
    return (float)element->peso/(pow((float)element->altezza/100,2));
}

void printList(nodo *testa){
    printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n","Nome","Cognome","Eta","Peso","Altezza","Sesso","IMC");
    while(testa!=NULL){
        printf("%-10s %-10s %-10d %-10d %-10d %-10c %-10.2f\n",testa->nome,testa->cognome,testa->eta,testa->peso,testa->altezza,testa->sesso,imc(testa));
        // printf("%s %s %d \n",testa->nome,testa->cognome,testa->eta);
        testa = testa->next;
    }
    printf("\n\n");
}

nodo* readFile(char input[255]){
    FILE *filePtr = fopen(input,"r");
    nodo *testa = NULL;
    if(filePtr == NULL){
        printf("Non è stato possibile aprire il file");
        exit(EXIT_FAILURE);
    }
    while(!feof(filePtr)){
        nodo req;
        fscanf(filePtr,"%s %s %d %d %d %c\n",req.nome,req.cognome,&req.eta,&req.peso,&req.altezza,&req.sesso);
        insertInList(&testa,req);
    }
    return testa;
}

void insertInList(nodo **testa,nodo req){
    nodo *newNodo = malloc(sizeof(nodo));
    strcpy(newNodo->nome,req.nome);
    strcpy(newNodo->cognome,req.cognome);
    newNodo->eta = req.eta;
    newNodo->peso = req.peso;
    newNodo->altezza = req.altezza;
    newNodo->sesso = req.sesso;
    newNodo->next = NULL;


    if(*(testa) == NULL){
        *(testa) = newNodo;
        return;
    }else{

        nodo *tempTesta = *(testa);
        nodo *prec = NULL;
        while(tempTesta!=NULL){
            // printList(*testa);
            if(tempTesta->eta < newNodo->eta){
                if(prec == NULL){
                    newNodo->next = tempTesta;
                    *(testa) = newNodo;
                }else{
                    prec->next = newNodo;
                    newNodo->next = tempTesta;
                }
                return;
            }

            prec = tempTesta;
            tempTesta = tempTesta->next;
        }
        prec->next = newNodo;
        return;
    }

}


param readInput(int argc, char **argv){
    if(argc == 3){
        if(strstr(argv[1],".txt") && strstr(argv[2],".txt")){
            param res;
            strcpy(res.input,argv[1]);
            strcpy(res.output,argv[2]);
            return res;
        }else{
            printf("I file devono avere estensione .txt");
            exit(EXIT_FAILURE);
        }
    }else{
        printf("Numero di parametri errato");
        exit(EXIT_FAILURE);
    }
}