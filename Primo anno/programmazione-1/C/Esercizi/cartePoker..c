#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct carta {
    char* seme;
    int numero;
};
#define nCarte 52
#define nfacce 13
#define nSemi 4
void stampaCarte(struct carta mazzoToPrint[nCarte]);
void shuffleCarte(struct carta * const newMazzo);


int main(){
    srand(time(NULL));
    char *semi[nSemi] = {"Cuori", "Quadri", "Fiori", "Picche"};
    struct carta mazzo[nCarte];

    for(int i = 0; i<nCarte; i++){
        mazzo[i].seme = semi[i/nfacce];
        mazzo[i].numero = i%nfacce + 1;
    }

    shuffleCarte(mazzo);
    stampaCarte(mazzo);

    printf("\n");
    return 0;
}
void stampaCarte(struct carta mazzoToPrint[52]){
    for(int i = 0; i<52; i++){
        printf("\n%d - %s\n", mazzoToPrint[i].numero, mazzoToPrint[i].seme);
    }
}
void shuffleCarte(struct carta * const newMazzo){
    for(int i = 0; i<nCarte; i++){
        int randNum = rand()%52 + 1;
        struct carta temp = newMazzo[randNum];
        newMazzo[randNum] = newMazzo[i];
        newMazzo[i] = temp;
    }
}