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
char* invertString(char s3[256]);
char* sort(char s5[256]);
void printResult(char s6[256]);
int main(){

    param data = decodeParameters();

    printf("\ndata.n = %d", data.n);
    printf("\ndata.s1 = %s", data.s1);
    printf("\ndata.s2 = %s", data.s2);
    printf("\ndata.c = %c", data.c);

    char *s3 = replaceChar(data.s1,data.s2,data.c);
    printf("\n\ns3: %s",s3);
    char *s4 = invertString(s3);
    printf("\n\ns4: %s",s4);
    char *s5 = strcat(s3, s4);
    printf("\n\ns5: %s",s5);
    char *s6 = sort(s5);
    printf("\n\ns6: %s",s6);
    printResult(s6);
    return 0;
}

void printResult(char s6[256]){
    printf("\n\n\n\n\n\n");
    for(int i = 0;i < strlen(s6);i++){
        if(s6[i]%2 == 1){
            // printf("*");
        }else{
            printf("%c",s6[i]);
        }
    }
    printf("\n");
}

char* sort(char s5[256]){
    int len = strlen(s5);
    char *s6 = malloc(sizeof(char)*len);
    strcpy(s6,s5);
    for(int i = 0;i<len;i++){
        for(int j = 0;j<len-1;j++){
            if(s6[i]<s6[j]){
                char temp = s6[i];
                s6[i] = s6[j];
                s6[j] = temp;
            }
        }
    }
    return s6;
}
char* invertString(char s3[256]){
    char *s4 = malloc(sizeof(char)*256);
    for(int i = 0; i<strlen(s3); i++){
        s4[i] = s3[strlen(s3)-i-1];
    }
    s4[strlen(s3)] = '\0';
    return s4;
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