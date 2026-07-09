#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <string.h>

#define BUFSIZE 1024

struct sharedData{
    long long operando_1;
    long long operando_2;
    int operazione; //1->somma 2->diff 3->moltiplicazione
    pthread_mutex_t mutex;
    pthread_cond_t cond1;
    pthread_cond_t cond2;
    long long risultato;

    int op1_pronto;
    int op2_pronto;
    int ops_pronto;
};

struct sharedData* initSharedData(struct sharedData* sh){
    pthread_mutex_init(&(sh->mutex), 0);
    pthread_cond_init(&(sh->cond1), 0);
    pthread_cond_init(&(sh->cond2), 0);
    sh->operando_1 = 0;
    sh->operando_2 = 0;
    sh->risultato = 0;
    sh->operazione = 0;
    sh->op1_pronto = 0;
    sh->op2_pronto = 0;
    sh->ops_pronto = 0;

    return sh;
}

void readSharedData(struct sharedData* sh){
    pthread_mutex_lock(&(sh->mutex));

    printf("Operando 1: %lld\n", sh->operando_1);
    printf("Operando 2: %lld\n", sh->operando_2);
    printf("Operazione: %d\n", sh->operazione);
    printf("Risultato: %lld\n", sh->risultato);

    pthread_mutex_unlock(&(sh->mutex));
}

long long getRisultato(struct sharedData* sh){
    pthread_mutex_lock(&(sh->mutex));

    while(sh->ops_pronto || sh->op1_pronto || sh->op2_pronto){
        pthread_cond_wait(&(sh->cond1), &(sh->mutex));
    }

    long long r = sh->risultato;

    pthread_mutex_unlock(&(sh->mutex));
    return r;
}

void insertData(int n, struct sharedData* sh, int chiSei){
    pthread_mutex_lock(&(sh->mutex));
    if(chiSei == 1){
        while(sh->op1_pronto){
            pthread_cond_wait(&(sh->cond1), &(sh->mutex));
        }
        sh->operando_1 = n;
        sh->op1_pronto = 1;
    }
    else if(chiSei == 2){
        while(sh->op2_pronto){
            pthread_cond_wait(&(sh->cond1), &(sh->mutex));
        }
        sh->operando_2 = n;
        sh->op2_pronto = 1;
    }
    else if(chiSei == 3){
        while(sh->ops_pronto){
            pthread_cond_wait(&(sh->cond2), &(sh->mutex));
        }
        sh->operazione = n;
        sh->ops_pronto = 1;
    }

    pthread_cond_broadcast(&(sh->cond1));
    pthread_cond_broadcast(&(sh->cond2));
    pthread_mutex_unlock(&(sh->mutex));
}

struct threadData{
    int id;
    char* path;
    struct sharedData* shared;
};

void* readOperando1(void *arg){
    struct threadData* data = (struct threadData*)arg;
    printf("[OP-%d] Sto inziando a leggere: %s\n", data->id, data->path);

    char buffer[BUFSIZE];
    FILE* fd = fopen(data->path, "r");
    while(fgets(buffer, BUFSIZE, fd)!=NULL){
        // printf("[OP-%d]: %d \n", data->id, atoi(buffer));
        insertData(atoi(buffer), data->shared, 1);
    }
    printf("[OP-%d] Ho finito di leggere: %s \n", data->id, data->path);

    return NULL;
}
void* readOperando2(void *arg){
    struct threadData* data = (struct threadData*)arg;
    printf("[OP-%d] Sto inziando a leggere: %s \n", data->id, data->path);

    char buffer[BUFSIZE];
    FILE* fd = fopen(data->path, "r");
    while(fgets(buffer, BUFSIZE, fd)!=NULL){
        // printf("[OP-%d]: %d \n", data->id, atoi(buffer));
        insertData(atoi(buffer), data->shared, 2);
    }
    printf("[OP-%d] Ho finito di leggere: %s \n", data->id, data->path);

    return NULL;
}

void* readOperazione(void *arg){
    struct threadData* data = (struct threadData*)arg;
    printf("[OPS] Sto inziando a leggere: %s \n", data->path);

    char buffer[BUFSIZE];
    FILE* fd = fopen(data->path, "r");
    while(fgets(buffer, BUFSIZE, fd)!=NULL){
        if(strstr(buffer, "+")!=NULL) insertData(1, data->shared, 3);
        else if(strstr(buffer, "-")!=NULL) insertData(2, data->shared, 3);
        else if(strstr(buffer, "x")!=NULL) insertData(3, data->shared, 3);
        else {
            long long atteso = atoll(buffer);
            long long ottenuto = getRisultato(data->shared);

            printf("[OPS] Ho appena letto il totale: %lld e questo coincide con quello ottenuto: %s (ottenuto: %lld)\n", atteso, atteso == ottenuto? "si":"no", ottenuto);
        }
    }
    insertData(-1, data->shared, 3);
    printf("[OPS] Ho finito di leggere: %s \n", data->path);

    return NULL;
}

void* makeOperazione(void *arg){
    struct threadData* data = (struct threadData*)arg;
    printf("[CALC] Sto inziando a calcolare\n");


    while(1){
        pthread_mutex_lock(&(data->shared->mutex));

        while(!data->shared->ops_pronto){
            pthread_cond_wait(&(data->shared->cond2),&(data->shared->mutex));
        }
        if(data->shared->operazione == -1) {
            pthread_mutex_unlock(&(data->shared->mutex));
            break;
        };

        while(!data->shared->op1_pronto || !data->shared->op2_pronto){
            pthread_cond_wait(&(data->shared->cond1),&(data->shared->mutex));
        }

        int parziale = 0;
        if(data->shared->operazione == 1) parziale = data->shared->operando_1 + data->shared->operando_2;
        else if(data->shared->operazione == 2) parziale = data->shared->operando_1 - data->shared->operando_2;
        else if(data->shared->operazione == 3) parziale = data->shared->operando_1 * data->shared->operando_2;

        data->shared->risultato += parziale;

        data->shared->op1_pronto = 0;
        data->shared->op2_pronto = 0;
        data->shared->ops_pronto = 0;

        data->shared->operando_1 = 0;
        data->shared->operando_2 = 0;
        data->shared->operazione = 0;

        pthread_cond_broadcast(&(data->shared->cond1));
        pthread_cond_broadcast(&(data->shared->cond2));

        pthread_mutex_unlock(&(data->shared->mutex));
    }

    printf("[CALC] Ho finito di calcolare\n");

    return NULL;
}

int main(int argc, char* argv[]){
    struct sharedData* sh = malloc(sizeof(struct sharedData));
    sh = initSharedData(sh);


    pthread_t OP1;
    struct threadData threadDataOP1 = {1,argv[1], sh};

    pthread_t OP2;
    struct threadData threadDataOP2 = {2,argv[2], sh};

    pthread_t OPS;
    struct threadData threadDataOPS = {3,argv[3], sh};

    pthread_t CALC;
    struct threadData threadDataCALC = {4, NULL, sh};


    pthread_create(&CALC, NULL, makeOperazione, (void*)(&threadDataCALC));
    pthread_create(&OPS, NULL, readOperazione, (void*)(&threadDataOPS));
    pthread_create(&OP1, NULL, readOperando1, (void*)(&threadDataOP1));
    pthread_create(&OP2, NULL, readOperando2, (void*)(&threadDataOP2));


    pthread_join(OP1, NULL);
    pthread_join(OP2, NULL);
    pthread_join(CALC, NULL);
    pthread_join(OPS, NULL);
}