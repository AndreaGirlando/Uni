#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct param {
    char input[128];
    char output[128];
};
typedef struct param param;

struct nodo {
    char nome[255];
    char cognome[255];
    int numeroConto;
    int annoApertura;
    float saldo;
    struct nodo *next;
};
typedef struct nodo nodo;

param readInput(int argc, char ** argv);
void inserisciInLista(nodo **testa, nodo data);
nodo* readFile(char filename[128]);
void printList(nodo *testa);
float getMax(nodo *testa);
float getX(int annoApertura,float saldo,float m);
nodo* getMaxxedX(nodo *testa);
void removeAccount(nodo **testa, nodo *toRemove);
int getLenOfList(nodo *testa);
void writeFile(char filename[128], nodo *testa);

int main(int argc, char**argv){

    param res = readInput(argc,argv);
    printf("Input: %s\n",res.input);
    printf("Output: %s\n",res.output);

    nodo *testa = readFile(res.input);
    printf("La lista: \n");
    printList(testa);


    int h = getLenOfList(testa)/2;

    for(int i = 0;i < h; i++){
        removeAccount(&testa,getMaxxedX(testa));
    }

    printf("Lista dopo la rimozione degli account: \n");
    printList(testa);

    writeFile(res.output,testa);

    printf("\n\n\n");
    return 0;
}

void writeFile(char filename[128], nodo *testa){
    FILE *filePtr = fopen(filename,"w");
    while(testa!=NULL){
        fprintf(filePtr,"%s %s %d %d %f\n", testa->nome,testa->cognome,testa->numeroConto,testa->annoApertura,testa->saldo);
        testa = testa->next;
    }
}

int getLenOfList(nodo *testa){
    int len = 0;
    while(testa!=NULL){
        len++;
        testa = testa->next;
    }
    return len;
}

void removeAccount(nodo **testa, nodo *toRemove){
    nodo *tempTesta = *(testa);

    nodo *prec = NULL;
    while(tempTesta != NULL){

        if(strcmp(tempTesta->nome,toRemove->nome) == 0 && strcmp(tempTesta->cognome,toRemove->cognome) == 0 && tempTesta->saldo == toRemove->saldo){
            if(prec == NULL){
                *(testa) = tempTesta->next;
                free(tempTesta);
            }else{
                prec->next = tempTesta->next;
                free(tempTesta);
            }
        }

        prec = tempTesta;
        tempTesta = tempTesta->next;

    }

}


nodo* getMaxxedX(nodo *testa){
    float m = getMax(testa);
    float massimo = getX(testa->annoApertura,testa->saldo,m);
    nodo *massimoPtr = testa;
    while(testa != NULL){
        float temp = getX(testa->annoApertura,testa->saldo,m);
        if(temp>massimo){
            massimo = temp;
            massimoPtr = testa;
        }
        testa = testa->next;
    }

  return massimoPtr;
}

float getX(int annoApertura,float saldo,float m){
    float destra = (float)saldo/m; //parte destra della formula;
    float sinistra = (float)(2023-annoApertura)/5; //parte sinistra della formula;

    if(sinistra > 1){
        return destra;
    }else{
        return sinistra*destra;
    }
}

float getMax(nodo *testa){
  float massimo = testa->saldo;
  while(testa != NULL){
    if(testa->saldo>massimo){
        massimo = testa->saldo;
    }
    testa = testa->next;
  }
  return massimo;
}

void printList(nodo *testa){
    printf("\n\n%20s %20s %20s %20s %20s \n\n", "Nome","Cognome","Numero conto","Anno apertura","Saldo");
    while(testa!=NULL){
        printf("%20s %20s %20d %20d %20.2f \n\n", testa->nome,testa->cognome,testa->numeroConto,testa->annoApertura,testa->saldo);
        testa = testa->next;
    }
}

nodo* readFile(char filename[128]){
    nodo *testa = NULL;
    FILE *filePtr = fopen(filename,"r");
    if(filePtr == NULL){
        printf("Non è stato possibile aprire il file specificato");
        exit(EXIT_FAILURE);
    }
    while(!feof(filePtr)){
        nodo temp;
        fscanf(filePtr,"%s %s %d %d %f\n", temp.nome,temp.cognome,&temp.numeroConto,&temp.annoApertura,&temp.saldo);
        inserisciInLista(&testa,temp);
    }
    return testa;
}


void inserisciInLista(nodo **testa, nodo data){
    nodo *newNodo = malloc(sizeof(nodo));
    strcpy(newNodo->nome,data.nome);
    strcpy(newNodo->cognome,data.cognome);
    newNodo->numeroConto = data.numeroConto;
    newNodo->annoApertura = data.annoApertura;
    newNodo->saldo = data.saldo;


    if(*(testa) == NULL){
        *(testa) = newNodo;
        return;
    }else{
        nodo *tempTesta = *(testa);
        nodo *prec = NULL;

        while(tempTesta != NULL){

            if(newNodo->annoApertura < tempTesta->annoApertura){
                if(prec == NULL){
                    newNodo->next = tempTesta;
                    *(testa) = newNodo;

                    return;
                }else{
                    newNodo->next = tempTesta;
                    prec->next = newNodo;
                    return;
                }
            }

            prec = tempTesta;
            tempTesta = tempTesta->next;
        }
        prec->next = newNodo;
        return;
    }
}


param readInput(int argc, char ** argv){

    if(argc == 3){
        if(strstr(argv[1],".txt") != NULL && strstr(argv[2],".txt") != NULL){
            param res;
            strcpy(res.input,argv[1]);
            strcpy(res.output,argv[2]);
            return res;
        }else{
            printf("I file specificati devono avere l'estensione .txt\n\n");
            exit(EXIT_FAILURE);
        }
    }else{
        printf("Hai inserito il numero errato di parametri\n\n");
        exit(EXIT_FAILURE);
    }

}