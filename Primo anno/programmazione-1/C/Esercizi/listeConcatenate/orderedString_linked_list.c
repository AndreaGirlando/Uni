#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
struct nodo{
    char nome[20];
    struct nodo *next;
};
typedef struct nodo nodo;


unsigned int get_random() {
    static unsigned int m_w = 123456;
    static unsigned int m_z = 789123;
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return (m_z << 16) + m_w;
}

char* genString(int numeroCaratteri){

    char* string = malloc(numeroCaratteri * sizeof(char));

    for(int i = 0;i<numeroCaratteri;i++){
        string[i] = get_random() % (122 - 97 + 1) + 97;
    }
    string[numeroCaratteri] = '\0';

    return string;

}

void printList(nodo *testa);
void insertOrderedInList(nodo **testa);

int main(int argc, char ** argv){

    nodo *testa = NULL;
    int n = atoi(argv[1]);

    for(int i = 0; i < n; i++){
        insertOrderedInList(&testa);
        printList(testa);
    }


    return 0;
}



void insertOrderedInList(nodo **testa){

    nodo *newNodo = malloc(sizeof(nodo));
    newNodo->next = NULL;
    strcpy(newNodo->nome,genString(10));
    if((*testa) == NULL){
        (*testa) = newNodo;
    }else{
        nodo *tempTesta = (*testa);
        nodo *prec = NULL;
        while(tempTesta != NULL){
            if(strcmp(newNodo->nome,tempTesta->nome)<0){
                if(prec == NULL){
                    newNodo->next = (*testa);
                    (*testa) = newNodo;
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
    }

}
void printList(nodo *testa){
    printf("\n\n");
    nodo *tempTesta = testa;

    while(tempTesta != NULL){

        printf("|%s,%p|->",tempTesta->nome,tempTesta->next);

        tempTesta = tempTesta->next;
    }
    printf("NULL\n\n");

}


