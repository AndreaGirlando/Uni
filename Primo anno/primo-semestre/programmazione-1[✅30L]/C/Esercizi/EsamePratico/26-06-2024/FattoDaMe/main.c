#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct param {
    char input[13];
    char output[13];
    char fileString[128];
    int n;
};

struct nodo {
    char *string;
    struct nodo *next;
};

typedef struct param param;
typedef struct nodo nodo;

param decodeParameters(int argc, char **argv);
int* fibonacci(int n);
char* sampleString(char* alfabeto, int h);
char** getStringArray(int *A,int n, char* alfabeto);
unsigned int get_random();
void enqueue(nodo **head, nodo **tail, char* string);
void printQueue(nodo *head);
char* dequeue(nodo **head, nodo **tail);
void getQueue(char**B,nodo **head, nodo **tail, int n);
void writeToFile(nodo *head,char output[13]);
int main(int argc, char** argv){

    param res = decodeParameters(argc,argv);
    printf("Parametri passati: %s %s %d\n\n", res.input,res.output,res.n);
    printf("Stringa letta: %s", res.fileString);

    int *A = fibonacci(res.n);
    printf("\n\nSequenza di fibonacci: ");
    for(int i=0;i<res.n;i++){
        printf("%5d", A[i]);
    }

    char **B = getStringArray(A,res.n,res.fileString);
    printf("\n\nArray di Stringhe B:");
    for(int i=0;i<res.n;i++){
        printf("%s\n", B[i]);
    }

    nodo *head = NULL;
    nodo *tail = NULL;

    getQueue(B,&head,&tail,res.n);
    printQueue(head);
    writeToFile(head,res.output);
    return 0;
}

void writeToFile(nodo *head,char output[13]){
    nodo *tempTesta = head;
    FILE *filePtr = fopen(output,"w");
    if(filePtr == NULL){
        printf("Non è stato possibile aprire il file specificato");
    }
    while(tempTesta!=NULL){
        fprintf(filePtr,"%s\n",tempTesta->string);
        tempTesta = tempTesta->next;
    }
}
void getQueue(char**B,nodo **head, nodo **tail, int n){
    for(int i=0;i<n;i++){
        if(i==0){
            enqueue(head,tail,B[i]);
        }else{
            if(strlen(B[i])%2 == 1){
                char *stringToConcat = dequeue(head,tail);
                char *finalString = calloc(sizeof(char),(strlen(stringToConcat)+strlen(B[i])));
                strcat(finalString,B[i]);
                strcat(finalString,stringToConcat);
                enqueue(head,tail,finalString);
            }else{
                enqueue(head,tail,B[i]);
            }
        }
    }
}

char * dequeue(nodo **head, nodo **tail){
    nodo *tempNodo = malloc(sizeof(nodo));
    tempNodo = *(head);

    char *string = malloc(sizeof(char)*strlen(tempNodo->string));
    string = strdup(tempNodo->string);
    if(*(head) == *(tail)){
        *(head) = tempNodo->next;
        *(tail) = tempNodo->next;
        free(tempNodo->string);
        free(tempNodo);
    }else{
        *(head) = tempNodo->next;
        free(tempNodo->string);
        free(tempNodo);

    }

    return string;
}

void printQueue(nodo *head){
    printf("\n\nLa Coda: \n");
    nodo *tempTesta = head;
    while(tempTesta!=NULL){
        printf("%s->",tempTesta->string);
        tempTesta = tempTesta->next;
    }
    printf("NULL");
}



void enqueue(nodo **head, nodo **tail, char* string){

    nodo *newNodo = malloc(sizeof(nodo));
    newNodo->next = NULL;
    newNodo->string = malloc(sizeof(char)*strlen(string));
    strcpy(newNodo->string, string);
    if(*(head) == NULL && *(tail) == NULL){
        *(head) = newNodo;
        *(tail) = newNodo;
    }else{
        (*tail)->next = newNodo;
        *(tail) = newNodo;
    }


}





char** getStringArray(int *A,int n, char* alfabeto){
    char **array = malloc(sizeof(char*)*n);
    for(int i = 0;i<n;i++){
        array[i] = malloc(sizeof(char)*A[i]);
        strcpy(array[i],sampleString(alfabeto,A[i]));
    }
    return array;
}

char* sampleString(char* alfabeto, int h){
    char *resString = malloc(sizeof(char)*(h+1));

    for(int i=0;i<h;i++){
        resString[i] = alfabeto[get_random()%strlen(alfabeto)];
    }
    resString[h] = '\0';
    return resString;
}

int* fibonacci(int n){
    int *vettore = malloc(sizeof(int)*n);
    if(n>=3){
        vettore[0] = 0;
        vettore[1] = 1;
        for(int i = 2;i<n;i++){
            vettore[i] = vettore[i-1]+vettore[i-2];
        }
    }else{
        vettore[0] = 0;
        vettore[1] = 1;
    }

    return vettore;
}

param decodeParameters(int argc, char **argv){
    //TODO Stampare nello standard error
    if(argc == 4){
        int n = atoi(argv[2]);
        if(strlen(argv[1]) >= 8 && strlen(argv[1]) <= 12 && n >= 3 && n <= 12){
            param res;
            strcpy(res.input,argv[1]);
            strcpy(res.output,argv[3]);
            res.n = n;

            FILE *filePtr = fopen(res.input,"r");
            if(filePtr == NULL){
                fprintf(stderr,"%s\n","Non è stato possibile aprire il file specificato");
            }
            fscanf(filePtr,"%s",res.fileString);

            return res;
        }else{
            fprintf(stderr,"%s\n","Errore nei parametri passati");
            exit(EXIT_FAILURE);
        }
    }else{
        fprintf(stderr,"%s\n","Numero di argomenti errato");
        exit(EXIT_FAILURE);
    }
}

unsigned int get_random() {
    static unsigned int m_w = 424242;
    static unsigned int m_z = 242424;
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return (m_z << 16) + m_w;
}
