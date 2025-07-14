#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define nDistinte 3*4*30
#define nProdotti 5
#define nAgenti 4

int salesPerProdotto(int idProdotto, int totalDistinte[nDistinte][3]);
int salesPerAgente(int idAgente, int totalDistinte[nDistinte][3]);
int salesPerProdottoPerAgente(int idAgente,int idProdotto, int totalDistinte[nDistinte][3]);
int totalSales(int totalDistinte[nDistinte][3]);
printTabella(int finalSales[nProdotti*nAgenti][3], int totalDistinte[nDistinte][3]);

int main()
{
    srand(time(NULL));
    system("cls");

    int distinte[nDistinte][3] = {0};
    int sales[nProdotti*nAgenti][3] = {0};

    for(int i = 0;i<nDistinte;i++){
        distinte[i][0] = 1 + rand()%nAgenti ; //numero agente
        distinte[i][1] = 1 + rand()%nProdotti; //numero prodotto
        distinte[i][2] = rand()%200; //totale generato
    }

    int count = 0;
    for(int i = 1; i<=nAgenti; i++){
        for(int j = 1; j<=nProdotti; j++){
            int temp = salesPerProdottoPerAgente(i,j,distinte);
            sales[count][0] = i;
            sales[count][1] = j;
            sales[count][2] = temp;
            count++;
            // printf("\nVendite totali del prodotto %d (fatte dall'agente %d) : %d",j,i,temp);
        }
        // printf("\n\n");
    }

    printf("\n\n\n\n\n");
    printTabella(sales, distinte);
    printf("\n\n\n\n\n");

}

int salesPerProdottoPerAgente(int idAgente,int idProdotto, int totalDistinte[nDistinte][3]){
    int sum = 0;
    for(int i = 0;i<nDistinte;i++){
        if(totalDistinte[i][1] == idProdotto && totalDistinte[i][0] == idAgente){
            sum = sum + totalDistinte[i][2];
        }
    }
    return sum;
}

int salesPerProdotto(int idProdotto, int totalDistinte[nDistinte][3]){
    int sum = 0;
    for(int i = 0;i<nDistinte;i++){
        if(totalDistinte[i][1] == idProdotto){
            sum = sum + totalDistinte[i][2];
        }
    }
    return sum;
}

int salesPerAgente(int idAgente, int totalDistinte[nDistinte][3]){
    int sum = 0;
    for(int i = 0;i<nDistinte;i++){
        if(totalDistinte[i][0] == idAgente){
            sum = sum + totalDistinte[i][2];
        }
    }
    return sum;
}

int totalSales(int totalDistinte[nDistinte][3]){
    int sum = 0;
    for(int i = 0;i<nDistinte;i++){
        sum = sum + totalDistinte[i][2];
    }
    return sum;
}

printTabella(int finalSales[nProdotti*nAgenti][3],int totalDistinte[nDistinte][3]){
    //La stampa della tabella non è responsive in base al numero di agenti e prodotti
    printf("\t\t%10s %10s %10s %10s %10s","Agente 1","Agente 2","Agente 3","Agente 4","Totale per prodotto");

    for(int j = 1; j<=nProdotti+1; j++){

        if(j<=nProdotti){
            printf("\nProdotto %d",j);
        }else{
            printf("\nTotale per agente");
            printf("%5d %11d %11d %11d", salesPerAgente(1,totalDistinte),salesPerAgente(2,totalDistinte),salesPerAgente(3,totalDistinte),salesPerAgente(4,totalDistinte));
        }

        for(int i = 1; i<=nAgenti; i++){
            for(int x = 0; x<nProdotti*nAgenti; x++){
                if(finalSales[x][0] == i && finalSales[x][1] == j){
                    printf("%12d",finalSales[x][2]);
                }
            }
        }

        if(j<=nProdotti){
            printf("%12d",salesPerProdotto(j,totalDistinte));
        }else{
            printf("%12d",totalSales(totalDistinte));
        }

    }
}