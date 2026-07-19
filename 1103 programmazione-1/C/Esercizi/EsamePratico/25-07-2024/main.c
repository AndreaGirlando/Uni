#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct param {
    char input_filename[256];
    int m;
    int n;
};
typedef struct param param;

param decodeParameters(int argc, char **argv);
param readHeader(param req);

short*** readFile(param req);
short* getArray(param req, short ***X);
short*** processX(short ***X,short *Y,param req);

void printMatrice(param req, short ***matrice);
void printMatriceToError(param req, short ***matrice);
void printArray(short* array, int size);

int main(int argc, char **argv){

    param res = decodeParameters(argc, argv);
    printf("input_filename: %s", res.input_filename);
    res = readHeader(res);
    printf("\nm: %d\tn: %d", res.m, res.n);
    printf("\nLa matrice X: \n");
    short ***X = readFile(res);

    short *Y = getArray(res,X);
    processX(X,Y,res);
    printf("\n\nla matrice X modificata: \n");
    printMatrice(res,X);
    printf("\n\nla matrice X nello standard error: \n");
    printMatriceToError(res,X);
    return 0;
}
void printMatriceToError(param req, short ***matrice){
    for(int i = 0; i<req.m; i++){
        for(int j = 0; j<req.n; j++){
            if(matrice[i][j]==NULL){
                fprintf(stderr,"%5s", "-");
            }else{
                fprintf(stderr,"%5d", *(matrice[i][j]));
            }
        }
        printf("\n");
    }
}

short*** processX(short ***X,short *Y,param req){
    for(int i = 0; i<req.m;i++){
        for(int j = 0;j<req.n;j++){
            int formula = Y[i]/2+1;
            if(*(X[i][j])>formula){
                X[i][j] = NULL;
            }
        }
    }
    return X;
}

void printArray(short* array, int size){
    for(int i=0;i<size;i++){
       printf("%5d", array[i]);
    }
}

short* getArray(param req, short ***X){

    short *array = malloc(sizeof(int)*req.m);
    for(int i = 0; i<req.m;i++){
        int massimo = *(X[i][0]);
        for(int j = 0;j<req.n;j++){
            if(massimo < *(X[i][j])){
                massimo = *(X[i][j]);
            }
        }
        array[i] = massimo;
    }

    printf("\n\nArray Y:");
    printArray(array,req.m);

    for(int i=0;i<req.m;i++){
        for(int j=0;j<req.m;j++){
            if(array[i]>array[j]){
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }

    printf("\n\nArray Y Ordinato: ");
    printArray(array,req.m);

    return array;
}

void printMatrice(param req, short ***matrice){
    for(int i = 0; i<req.m; i++){
        for(int j = 0; j<req.n; j++){
            if(matrice[i][j]==NULL){
                printf("%5s", "*");
            }else{
                printf("%5d", *(matrice[i][j]));
            }
        }
        printf("\n");
    }
}


short*** readFile(param req){

    FILE *filePtr = fopen(req.input_filename, "r");
    int n,m = 0;
    fscanf(filePtr,"%d, %d", &req.m,&req.n);//Leggo la prima riga in modo da saltarla
    if(filePtr == NULL){
        printf("Il file non è stato trovato");
        exit(EXIT_FAILURE);
    }
    short ***matrice = malloc(sizeof(short**)*req.m);
    for(int i = 0; i<req.m; i++){
        matrice[i] = malloc(sizeof(short*)*req.n);
        int v[req.n];
        fscanf(filePtr, "%d,%d,%d,%d,%d,%d", &v[0],&v[1],&v[2],&v[3],&v[4],&v[5]);
        for(int j = 0; j<req.n; j++){
            matrice[i][j] = malloc(sizeof(short));
            *(matrice[i][j]) = v[j];
        }
    }
    printMatrice(req, matrice);

    return matrice;

}
param readHeader(param req){

    FILE *filePtr = fopen(req.input_filename, "r");
    if(filePtr == NULL){
        printf("Il file non è stato trovato");
        exit(EXIT_FAILURE);
    }
    fscanf(filePtr,"%d, %d", &req.m,&req.n);
    fclose(filePtr);
    return req;
}

param decodeParameters(int argc, char **argv){
    if(argc == 2){
        char *pos = strstr(argv[1], ".csv");
        if(pos == NULL){
            printf("Il file deve avere estensione .csv");
            exit(EXIT_FAILURE);
        }else{
            param res;
            strcpy(res.input_filename,argv[1]);
            return res;
        }
    }else{
        printf("Numero di parametri sbagliato");
        exit(EXIT_FAILURE);
    }
}
