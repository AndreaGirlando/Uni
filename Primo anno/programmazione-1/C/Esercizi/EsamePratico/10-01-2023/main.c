#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct param{
    int n;
    char s1[256];
    char s2[256];
    char c;
};
typedef struct param param;
param decodeParameters();
char* replaceChar(char s1[256],char s2[256], char c);
int main(){

    param data = decodeParameters();

    printf("\ndata.n = %d", data.n);
    printf("\ndata.s1 = %s", data.s1);
    printf("\ndata.s2 = %s", data.s2);
    printf("\ndata.c = %c", data.c);

    printf("\n\nProva: %s",replaceChar(data.s1,data.s2,data.c));

    return 0;
}

char* replaceChar(char s1[256],char s2[256], char c){
    char *s3 = malloc(sizeof(char)*256);
    for(int i = 0; i < strlen(s1); i++){
        s3[i] = s1[i];
        if(s1[i] == c){
            s3[i] = s2[i];
        }
    }
    return s3;
}

param decodeParameters(){
    param res;
    printf("Inserisci n:");
    scanf("%d", &res.n);
    printf("Inserisci s1:");
    scanf("%s", res.s1);
    printf("Inserisci s2:");
    scanf("%s", res.s2);
    printf("Inserisci c:");
    scanf(" %c", &res.c);

    return res;

}