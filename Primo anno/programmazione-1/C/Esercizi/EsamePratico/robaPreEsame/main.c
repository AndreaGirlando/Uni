#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct nodo {
    int d;
    struct nodo *next;
};
typedef struct nodo nodo;
void printList(nodo *testa);
void inserisciNodoOrdinato(nodo **testa, int d);
unsigned int get_random();
int main(){

    nodo * testa = NULL;
    for(int i = 0;i < 10 ; i++){
        int random = get_random()%256;
        // printf("\n%d: %d", i,random);
        inserisciNodoOrdinato(&testa,random);
    }

    printList(testa);

    return 0;
}

void inserisciNodoOrdinato(nodo **testa, int d){
    nodo *newNodo = malloc(sizeof(nodo));
    newNodo->d = d;
    newNodo->next = NULL;

    if(*(testa) == NULL){
        *(testa) = newNodo;
        return;
    }else{
        nodo *tempTesta = *(testa);
        nodo *prec = NULL;
        while(tempTesta != NULL){

            if(tempTesta->d < newNodo->d){

                if(prec == NULL){
                    newNodo->next = (*testa);
                    *(testa) = newNodo;
                }else{
                    newNodo->next = prec->next;
                    prec->next = newNodo;
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

void printList(nodo *testa){
    printf("\n\n\n");
    while(testa != NULL){
        printf("%d\n",testa->d);
        testa = testa->next;
    }
    printf("NULL");
}

unsigned int get_random() {
    static unsigned int m_w = 424242;
    static unsigned int m_z = 242424;
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return (m_z << 16) + m_w;
}
