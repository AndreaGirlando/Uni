// prenda un input da tastiera (argomenti della funzione main()) un intero k in [10,15], un
// carattere w in [‘a’-’z’] e due interi N ed M in [4,8]; se gli argomenti a riga di comando non
// rispondono ai suddetti requisiti, il programma stampa un messaggio di errore sullo standard
// error e termina la propria esecuzione con codice di errore “-1”

#include <stdio.h>
#include <stdlib.h>
#include "random.c"
struct params {
    int k;
    char w;
    int n;
    int m;
};
struct params checkMainArg(int size, char **argv);
void genString(int numeroCaratteri, char* string);
int main(int argc, char **argv){

    struct params res = checkMainArg(argc, argv);
    // printf("%d %c %d %d",res.k,res.w,res.n,res.m);



    char string[res.k];
    genString(res.k,string);
    printf("%s",string);

    return 0;
}

void genString(int numeroCaratteri, char* string){

    for(int i = 0;i<numeroCaratteri;i++){
        string[i] = get_random() % (122 - 97 + 1) + 97;
    }
    string[numeroCaratteri] = '\0';

}

struct params checkMainArg(int size, char **argv){
    if(size == 5){
        struct params res;
        res.k = atoi(argv[1]);
        res.w = *argv[2];
        res.n = atoi(argv[3]);
        res.m = atoi(argv[4]);

        if(res.k < 10 || res.k > 15){
            fprintf(stderr, "Valore k errato");
            exit(EXIT_FAILURE);
        }
        if(res.w < 97 || res.w > 122){
            fprintf(stderr, "Valore w errato");
            exit(EXIT_FAILURE);
        }
        if(res.n < 4 || res.n > 8){
            fprintf(stderr, "Valore n errato");
            exit(EXIT_FAILURE);
        }
        if(res.m < 4 || res.m > 8){
            fprintf(stderr, "Valore m errato");
            exit(EXIT_FAILURE);
        }

        return res;
    }else{
        fprintf(stderr, "Numero di argomenti errato");
        exit(EXIT_FAILURE);
    }
}