#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int numeroDiArgomenti = argc;
    system("cls");
    printf("\nDi seguito gli argomenti passati all'avvio: \n");
    for(int i=0;i<argc;i++){
        printf("%d - %15s\n\n",i, argv[i]);
    }


    printf("%d", (int)argv[1]);
}