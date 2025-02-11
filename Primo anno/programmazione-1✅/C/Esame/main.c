
//====================== main.c ======================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct param {
    char input_filename[256];
    char output_filename[256];
    int n;
    int mediana;
    float altezzaMedia;
};

struct persona {
    char nome[50];
    char cognome[50];
    int eta;
    float altezza;
};
typedef struct persona persona;
typedef struct param param;

param decodeParameters(int argc, char ** argv);
param readHeader(param req);
persona* readFile(param req);
int*extractAges(param req,persona* arr);
void printArrayZ(param req, int*Z);
void sortArray(param req, int* Z);
float calculateAverageHeight(param req, persona* persone);
void writeOutput(param req, persona* persone);

int main(int argc, char ** argv){

    param res = decodeParameters(argc,argv);
    printf("\n\ninput_filename: %s\n", res.input_filename);
    printf("output_filename: %s\n", res.output_filename);
    res = readHeader(res);
    printf("N: %d\n", res.n);

    persona* persone = readFile(res);

    for(int i = 0;i<res.n; i++){
        printf("\n%d. Nome:%s, Cognome:%s, EtÃ :%d, Altezza:%.2f\n",i+1,persone[i].nome,persone[i].cognome,persone[i].eta,persone[i].altezza);
    }

    int* Z = extractAges(res,persone);
    printf("\n\nValori di Z (non ordinato):");
    printArrayZ(res, Z);

    printf("\n\nValori di Z (ordinato in ordine crescente):");
    sortArray(res,Z);
    printArrayZ(res,Z);

    res.mediana = Z[res.n/2];
    printf("\n\nMediana delle etÃ : %d",res.mediana);

    res.altezzaMedia = calculateAverageHeight(res,persone);
    printf("\n\nAltezza media delle persone con etÃ  superiore alla mediana: %.2f", res.altezzaMedia);

    writeOutput(res,persone);

    printf("\n\n\n");
    return 0;
}

void writeOutput(param req, persona* persone){
    FILE *filePtr = fopen(req.output_filename, "w");
    if(filePtr == NULL){
        fprintf(stderr,"Errore durante l'apertura del file specificato");
        exit(EXIT_FAILURE);
    }
    for(int i = 0;i < req.n; i++){
        if(persone[i].altezza > req.altezzaMedia){
            fprintf(filePtr,"%s %s, EtÃ : %d, Altezza: %f\n",persone[i].nome,persone[i].cognome,persone[i].eta,persone[i].altezza);
        }
    }
    printf("\n\nFile scritto correttamente");
}

float calculateAverageHeight(param req, persona* persone){
    int numeroPersone = 0;
    float sumsOfAltezze = 0;
    for(int i = 0; i<req.n;i++){
        if(persone[i].eta > req.mediana){
            numeroPersone++;
            sumsOfAltezze = sumsOfAltezze + persone[i].altezza;
        }
    }
    return sumsOfAltezze/numeroPersone;
}

void sortArray(param req, int* Z){

    for(int i = 0;i<req.n;i++){
        for(int j = 0;j<req.n - i - 1;j++){
            if(Z[j+1] < Z[j]){
                int temp = Z[j+1];
                Z[j+1] = Z[j];
                Z[j] = temp;
            }
        }
    }

}

void printArrayZ(param req, int*Z){
    for(int i = 0;i<req.n;i++){
        printf("%5d", Z[i]);
    }
}

int*extractAges(param req,persona* arr){
    int* Z = malloc(sizeof(int)*req.n);

    for(int i = 0;i<req.n;i++){
        Z[i] = arr[i].eta;
    }

    return Z;
}

persona* readFile(param req){
    FILE *filePtr = fopen(req.input_filename, "r");
    if(filePtr == NULL){
        fprintf(stderr,"Errore durante l'apertura del file");
        exit(EXIT_FAILURE);
    }

    fseek(filePtr,1,SEEK_SET);

    persona* arr = malloc(sizeof(persona)*req.n);

    for(int i = 0;i<req.n;i++){
        persona temp;
        fscanf(filePtr, "%s %s %d %f\n", temp.nome,temp.cognome,&temp.eta,&temp.altezza);
        arr[i] = temp;
    }

    return arr;
}

param readHeader(param req){
    FILE *filePtr = fopen(req.input_filename, "r");
    if(filePtr == NULL){
        fprintf(stderr,"Errore durante l'apertura del file");
        exit(EXIT_FAILURE);
    }
    fscanf(filePtr,"%d",&req.n);
    return req;
}

param decodeParameters(int argc, char ** argv){
    if(argc == 3){
        param res;
        strcpy(res.input_filename, argv[1]);
        strcpy(res.output_filename, argv[2]);
        if(strstr(res.input_filename,".txt") != NULL && strstr(res.output_filename,".txt") != NULL){
            return res;
        }else{
            fprintf(stderr,"Errore nei parametri inseriti");
            exit(EXIT_FAILURE);
        }
    }else{
        fprintf(stderr,"Errore nel numero di parametri inseriti");
        exit(EXIT_FAILURE);
    }
}
