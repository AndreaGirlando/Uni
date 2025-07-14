#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct param{
    char *simboli;
    int n;
    char output[256];
    int l;
};
typedef struct param param;

struct nodo{
    char *string;
    struct nodo *next;
};
typedef struct nodo nodo;

param decodeParameters(int argc,char**argv);
int makeFattorialeFromNumber(int k);
int *readInput(param req);
unsigned int get_random();
char * sampleString(param req,int h);
char **getStringArray(param req,int *W);
void printStack(nodo *testa);
void push(nodo **testa,char *string);
char* pop(nodo **testa);
nodo* getStack(char **Q,param req);
void writeStackToFile(char filename[256],nodo *testa);

int main(int argc,char**argv){

    param res = decodeParameters(argc,argv);
    printf("simboli: %s\n",res.simboli);
    printf("n: %d\n",res.n);
    printf("output: %s\n",res.output);
    printf("l: %d\n",res.l);

    printf("\n\n\nValore di W:\n");
    int *W = readInput(res);
    for(int i = 0;i<res.n;i++){
        printf("%5d",W[i]);
    }

    printf("\n\n\nValore di Q:\n");
    char **Q = getStringArray(res,W);
    for(int i = 0;i<res.n;i++){
        printf("%s\n",Q[i]);
    }

    nodo *testa = getStack(Q,res);
    printStack(testa);

    writeStackToFile(res.output,testa);
    printf("\n\n\n");
    return 0;
}

void writeStackToFile(char filename[256],nodo *testa){
    FILE *filePtr = fopen(filename,"w");
    if(filePtr == NULL){
        printf("Non è stato possibile aprire il file specificato");
    }
    while(testa!=NULL){

        fprintf(filePtr,"%s\n",testa->string);

        testa = testa->next;
    }
}

nodo* getStack(char **Q,param req){
    nodo *testa = NULL;

    push(&testa,Q[0]);
    for(int i = 1;i<req.n;i++){
        if(strlen(Q[i])%2 == 0){
            push(&testa,Q[i]);
        }else{
            char* a = pop(&testa);
            char* b = malloc(sizeof(char)*strlen(a));
            int caratterInseriti = 0;
            for(int j = 0;j<strlen(a);j++){
                if(Q[i][j]==a[j]){
                    b[caratterInseriti] = a[j];
                    caratterInseriti++;
                }
            }
            push(&testa,b);
        }
    }

    return testa;
}

void printStack(nodo *testa){
    printf("\nDi seguito lo stack: \n");
    while(testa != NULL){
        printf("%s\n",testa->string);
        testa = testa->next;
    }
}

void push(nodo **testa,char *string){
    nodo * newNodo = malloc(sizeof(nodo));
    newNodo->string = malloc(sizeof(char)*strlen(string));
    strcpy(newNodo->string,string);
    newNodo->next = *(testa);
    *(testa) = newNodo;
}

char* pop(nodo **testa){

    nodo * tempNodo = *(testa);
    char * res = malloc(sizeof(char)*strlen(tempNodo->string));
    strcpy(res,tempNodo->string);
    *(testa) = tempNodo->next;

    free(tempNodo->string);
    free(tempNodo);

    return res;
}

char **getStringArray(param req,int *W){
    char **Q = malloc(sizeof(char*)*req.n);

    for(int i = 0;i<req.n;i++){
        int lenString = W[i]%req.l;
        Q[i] = sampleString(req,lenString);
    }

    return Q;
}

char * sampleString(param req,int h){
    char *string = malloc(sizeof(char)*(h+1));
    for(int i = 0;i<h;i++){
        int random = get_random()%req.l;
        string[i] = req.simboli[random];
    }
    string[h] = '\0';
    return string;
}

unsigned int get_random() {
    static unsigned int m_w = 424242;
    static unsigned int m_z = 242424;
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return (m_z << 16) + m_w;
}


int *readInput(param req){
    printf("Inserisci %d interi separati da un invio: ", req.n);
    int * W = malloc(sizeof(int)*req.n);
    for(int i = 0;i<req.n;i++){
        int temp = 0;
        scanf("%d",&temp);
        W[i] = makeFattorialeFromNumber(temp);
    }
    return W;
}

int makeFattorialeFromNumber(int k){
    int fattoriale = 1;
    for(int i = 0;i<k;i++){
        fattoriale = fattoriale * (k - i);
    }
    return fattoriale;
}

param decodeParameters(int argc,char**argv){

    if(argc == 4){
        param res;
        res.simboli = malloc(sizeof(char)*strlen(argv[1]));
        strcpy(res.simboli, argv[1]);
        res.n = atoi(argv[2]);
        strcpy(res.output, argv[3]);
        res.l = strlen(res.simboli);
        if(res.l >= 10 && res.l <= 20 && res.n >= 8 && res.n <= 18){
            return res;
        }else{
            printf("Errore nei parametri inseriti\n\n\n");
            exit(EXIT_FAILURE);
        }
    }else{
        printf("Errore nei parametri inseriti\n\n\n");
        exit(EXIT_FAILURE);
    }


}