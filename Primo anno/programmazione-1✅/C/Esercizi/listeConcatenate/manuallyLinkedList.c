#include <stdio.h>
struct nodo{
    int d;
    struct nodo *next;
};
typedef struct nodo nodo;
int main(){
    //? Creo i nodi, li collego e li stampo tutto manualmente
    nodo n1 = {5,NULL};
    nodo n2 = {6,NULL};
    nodo n3 = {12,NULL};
    nodo *testa = &n1;
    n1.next = &n2;
    n2.next = &n3;
    printf("n1(%p): {%d,%p}\n",&n1,n1.d,n1.next);
    printf("n2(%p): {%d,%p}\n",&n2,n2.d,n2.next);
    printf("n3(%p): {%d,%p}\n",&n3,n3.d,n3.next);
    return 0;
}