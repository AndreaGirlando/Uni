#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct param {
    char filename[100];
};
struct nodo {
    int d;
    struct nodo *next;
};

typedef struct param param;
typedef struct nodo nodo;


param decodeParameters(int argc, char**argv);

void push(nodo **testa, int n);
int pop(nodo **testa);
int printPila(nodo *testa);
nodo* readFile(char filename[100]);
float getMean(nodo **testa);
void fillP(nodo **testa, char filename[100], float media);
void sort(int *vettore, int len);
int* transferP(nodo **testa, int pilaLen);

int main(int argc, char** argv){

    param res = decodeParameters(argc,argv);
    printf("\n\nfilename: %s", res.filename);

    nodo *testa = readFile(res.filename);
    printPila(testa);

    float media = getMean(&testa);
    printf("\n\nLa media e': %.2f",media);

    fillP(&testa,res.filename,media);
    int pilaLen = printPila(testa);

    int *vettore = transferP(&testa,pilaLen);
    sort(vettore,pilaLen);

    printf("\n\nIl vettore ordinato: \n");
    for(int i = 0;i<pilaLen;i++){
        printf("%d\n",vettore[i]);
    }

    return 0;
}

void sort(int *vettore, int len){
    //Algoritmo usato per l'ordinamento: Bubble Sort
    for(int i = 0;i<len;i++){
        for(int j=0;j<len;j++){
            if(vettore[i]<vettore[j]){
                int temp = vettore[i];
                vettore[i] = vettore[j];
                vettore[j] = temp;
            }
        }
    }
}

int* transferP(nodo **testa, int pilaLen){
    int* vettore = malloc(sizeof(int)*pilaLen);
    for(int i = 0;i<pilaLen;i++){
        vettore[i] = pop(testa);
    }
    return vettore;
}

void fillP(nodo **testa, char filename[100], float media){

    FILE *filePtr = fopen(filename, "r");
    if(filePtr == NULL){
        printf("Il file specificato non è stato trovato");
    }else{
        while(!feof(filePtr)){
            int x = 0;
            fscanf(filePtr,"%d\n",&x);

            if(*(testa) == NULL){
                push(testa,x);
            }else{
                if(x > media){
                    push(testa,x);
                }else{
                    int y = pop(testa);
                    push(testa,(x+y)/2);
                }
            }

        }
    }


}

float getMean(nodo **testa){
    int numberOfElement = 0;
    int d = 0;
    while(*(testa) != NULL){
        d = d + pop(testa);
        numberOfElement++;
    }
    return (float)d/numberOfElement;


}

nodo* readFile(char filename[100]){
    nodo *testa = NULL;

    FILE *filePtr = fopen(filename,"r");
    if(filePtr == NULL){
        printf("Non è stato possibile aprire il file specificato");
        exit(EXIT_FAILURE);
    }
    while(!feof(filePtr)){
        int d = 0;
        fscanf(filePtr,"%d\n",&d);
        push(&testa,d);
    }

    return testa;
}

int pop(nodo **testa){

    if(testa != NULL){
        nodo *tempTesta = *(testa);
        int res = tempTesta->d;
        *(testa) = tempTesta->next;

        free(tempTesta);

        return res;
    }

    return 0;
}


void push(nodo **testa, int n){

    nodo *newNodo = malloc(sizeof(nodo));
    newNodo->d = n;
    newNodo->next = NULL;
    if(testa == NULL){
        *(testa) = newNodo;
    }else{
        newNodo->next = *(testa);
        *(testa) = newNodo;
    }

    return;
}

int printPila(nodo *testa){
    printf("\n\nIl contenuto della pila: \n");
    nodo *tempTesta = testa;
    int pilaLen = 0;
    while(tempTesta != NULL){
        printf("%d\n",tempTesta->d);
        tempTesta = tempTesta->next;
        pilaLen++;
    }
    return pilaLen;
}

param decodeParameters(int argc, char**argv){

    if(argc == 2){
        char *found = strstr(argv[1],".txt");
        if(found == NULL){
            printf("Il file deve contenere l'estensione .txt");
            exit(EXIT_FAILURE);
        }else{
            param res;
            strcpy(res.filename,argv[1]);
            return res;
        }
    }else{
        printf("Numero di parametri errato");
        exit(EXIT_FAILURE);
    }

}