#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct param {
    char inputFileName[256];
    int n;
    int lenOfA;
};
typedef struct param param;
struct nodo {
    float num;
    struct nodo *next;
};
typedef struct nodo nodo;

struct stackInfo{
    float max;
    float min;
    float mean;
};
typedef struct stackInfo stackInfo;

param decodeParameters(int argc, char** argv);
int* readInput(param req);
int getLenOfFile(param req);
void printPila(nodo *testa);
void push(nodo **testa, float num);
float pop(nodo **testa);
nodo * createStack(param req, int* A);
stackInfo findMinMaxMean(nodo* testa);

int main(int argc, char ** argv){

    param res = decodeParameters(argc,argv);
    printf("\nn: %d\n",res.n);
    printf("inputFileName: %s\n\n",res.inputFileName);

    res.lenOfA =  getLenOfFile(res);

    int * A = readInput(res);
    printf("Il contenuto di A è:");
    for(int i = 0;i<res.lenOfA;i++){
        printf("%d\n",A[i]);
    }


    printf("Il contenuto della pila S è:");
    nodo * testa = createStack(res,A);
    printPila(testa);

    stackInfo stackInfoRes = findMinMaxMean(testa);
    printf("\nMax: %.2lf",stackInfoRes.max);
    printf("\nMin: %.2lf",stackInfoRes.min);
    printf("\nMean: %.2lf",stackInfoRes.mean);

    printf("\n\n\n");
    return 0;
}

stackInfo findMinMaxMean(nodo* testa){
    stackInfo res;
    res.min = testa->num;
    res.max = testa->num;
    res.mean = 0;
    int pilaLen = 0;
    while(testa != NULL){
        pilaLen++;
        res.mean = res.mean + testa->num;

        if(testa->num > res.max){
            res.max = testa->num;
        }

        if(testa->num < res.min){
            res.min = testa->num;
        }


        testa = testa->next;
    }
    res.mean = res.mean/pilaLen;
    return res;
}

nodo * createStack(param req, int* A){
    nodo * testa = NULL;
    push(&testa,A[0]);
    for(int i = 1;i<req.lenOfA;i++){
        if(A[i]%req.n == 0){
            // printf("%d multiplo\n",A[i]);
            push(&testa,A[i]);
        }else{
            // printf("%d non multiplo\n",A[i]);
            float x = pop(&testa);
            float media = (x+A[i])/2;
            push(&testa,media);
        }
    }
    return testa;
}

void printPila(nodo *testa){
    printf("\n");
    while(testa != NULL){
        printf("%.2lf\n",testa->num);
        testa = testa->next;
    }
}

void push(nodo **testa, float num){

    nodo * newNodo = malloc(sizeof(nodo));
    newNodo->num = num;
    newNodo->next = *(testa);
    *(testa) = newNodo;

}

float pop(nodo **testa){
    nodo *tempTesta = *(testa);
    *(testa) = tempTesta->next;
    float res = tempTesta->num;
    free(tempTesta);
    return res;
}

int getLenOfFile(param req){
    FILE *filePtr = fopen(req.inputFileName,"r");
    if(filePtr == NULL){
        printf("Non è stato possibile aprire il file specificato");
    }
    int len = 0;
    while(!feof(filePtr)){
        int temp = 0;
        fscanf(filePtr,"%d\n",&temp);
        len++;
    }
    fclose(filePtr);
    return len;
}
int* readInput(param req){

    FILE *filePtr = fopen(req.inputFileName,"r");
    if(filePtr == NULL){
        printf("Non è stato possibile aprire il file specificato");
    }
    int *A = malloc(sizeof(int) * req.lenOfA);
    int contatore = 0;
    while(!feof(filePtr)){
        fscanf(filePtr,"%d\n",&A[contatore]);
        contatore++;
    }

    return A;
}

param decodeParameters(int argc, char** argv){
    if(argc == 3){
        param res;
        res.n = atoi(argv[1]);
        strcpy(res.inputFileName, argv[2]);
        if(res.n >= 5 && res.n<= 20 && strstr(res.inputFileName,".dat") != NULL){
            return res;
        }else{
            printf("Errore nei parametri inseriti\n\n\n");
            exit(EXIT_FAILURE);
        }
    }else{
        printf("Hai inserito il numero errato di parametri\n\n\n");
        exit(EXIT_FAILURE);
    }
}
