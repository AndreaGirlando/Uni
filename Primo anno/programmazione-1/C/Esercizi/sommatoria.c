#include<stdio.h>
int main() {

    int r = 0;
    int q = 0;
    printf("Inserisci R:");
    scanf("%d", &r);
    printf("\nInserisci Q:");
    scanf("%d", &q);

    while(r<0 || q<0 ||r < q){
        printf("Inserisci dei numeri validi\n");
        printf("Inserisci R:");
        scanf("%d", &r);
        printf("\nInserisci Q:");
        scanf("%d", &q);
    }

    float y = 0;
    while(q <= r){
        y = y + (1/(float)q);
        q++;
    }
    printf("\n\nLa sommatoria e': %f", y);


}
