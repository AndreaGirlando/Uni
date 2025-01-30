#include <stdio.h>
#include <stdlib.h>

struct param {
    int n;
    int m;
    int h;
};
typedef struct param param;
unsigned int get_random();
param decodeParameters(int argc, char**argv);
int *** getRandomMatrix(param req);
void printMatrix(param req, int ***matrice);
void removeMax(int *** A, int n,int col);
void modifyMatrix(int *** A, param req);
void printMatrixWithAsterisk(param req, int ***matrice);
int rowMinNull(param req, int ***matrice);
int numberOfNullByRow(param req, int ***matrice,int row);

int main(int argc, char**argv){

    param res = decodeParameters(argc,argv);
    printf("\nN: %d\n",res.n);
    printf("M: %d\n",res.m);

    printf("\nInserisci il valore H (compreso tra 10 e 100):\n");
    scanf("%d", &res.h);
    if(res.h < 10 || res.h > 100){
        printf("Errore nell'inserimento del valore H");
        exit(EXIT_FAILURE);
    }

    printf("\n\nLa matrice A: \n");
    int ***A = getRandomMatrix(res);
    printMatrix(res,A);

    printf("\n\nLa matrice A modificata: \n");
    modifyMatrix(A,res);
    printMatrixWithAsterisk(res,A);

    printf("\n\nRiga della matrice A con il minor numero di NULL: \n");
    int row = rowMinNull(res,A);


    for(int j = 0;j<res.m; j++){
        if(A[row][j] == NULL){
            printf("%10s", "*");
        }else{
            printf("%10d", *(A[row][j]));
        }
    }

    printf("\n\n\n\n");
    return 0;
}

unsigned int get_random() {
    static unsigned int m_w = 424242;
    static unsigned int m_z = 242424;
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return (m_z << 16) + m_w;
}

void printMatrix(param req, int ***matrice){
    for(int i = 0; i < req.n; i++){
        for(int j = 0;j<req.m; j++){
            printf("%10d", *(matrice[i][j]));
        }
        printf("\n");
    }
}

int rowMinNull(param req, int ***matrice){
    int row = 0;
    int min = numberOfNullByRow(req,matrice,0);
    for(int i = 0; i < req.n; i++){
        int temp = numberOfNullByRow(req,matrice,i);
        if(temp < min){
            min = temp;
            row = i;
        }
    }
    return row;
}

int numberOfNullByRow(param req, int ***matrice,int row){
    int count = 0;
    for(int i = 0;i<req.m;i++){
        if(matrice[row][i] == NULL){
            count = count + 1;
        }
    }
    return count;
}

void printMatrixWithAsterisk(param req, int ***matrice){
    for(int i = 0; i < req.n; i++){
        for(int j = 0;j<req.m; j++){
            if(matrice[i][j] == NULL){
                printf("%10s", "*");
            }else{
                printf("%10d", *(matrice[i][j]));
            }
        }
        printf("\n");
    }
}



void modifyMatrix(int *** A, param req){
    for(int i = 0;i<req.m;i++){
        removeMax(A,req.n,i);
        removeMax(A,req.n,i);
        removeMax(A,req.n,i);
    }
}

void removeMax(int *** A, int n, int col){
    int max = 0;
    int indexOfMax = 0;
    for(int i = 0;i<n;i++){
        if(A[i][col] != NULL){
            if(*(A[i][col]) > max){
                max  = *(A[i][col]);
                indexOfMax = i;
            }
        }
    }
    free(A[indexOfMax][col]);
    A[indexOfMax][col] = NULL;
}

int *** getRandomMatrix(param req){
    int *** matrice = malloc(sizeof(int**)*req.n);
    for(int i = 0; i < req.n; i++){
        matrice[i] = malloc(sizeof(int*)*req.m);
        for(int j = 0;j<req.m; j++){
            matrice[i][j] = malloc(sizeof(int));
            int random = get_random()%(req.h+1);
            // printf("%d\n",random);
            *(matrice[i][j]) = random;
        }
    }
    return matrice;
}

param decodeParameters(int argc, char**argv){
    if(argc == 3){
        param res;
        res.n = atoi(argv[1]);
        res.m = atoi(argv[2]);
        if(res.n >= 3 && res.n<=7 && res.m >= 3 && res.m<=7){

            return res;

        }else{
            printf("Errore nei parametri inseriti");
        }
    }else{
        printf("Numeri di parametri inseriti errato");
        exit(EXIT_FAILURE);
    }
}