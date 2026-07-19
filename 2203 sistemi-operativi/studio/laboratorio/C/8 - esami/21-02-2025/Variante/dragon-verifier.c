#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 256

struct SharedData{
    pthread_mutex_t mutex;
    pthread_cond_t cond1;
    pthread_cond_t cond2;

    int eroePw;
    int dragoPw;
    int quest;
    int risultato;

    int ok_eroePw;
    int ok_dragoPw;
    int ok_quest;// 1-> somma ; 2 -> diff; 3 -> moltiplicazione

    int ok_risultato;
};

struct SharedData* initShared(struct SharedData* sh){
    pthread_mutex_init(&(sh->mutex), 0);
    pthread_cond_init(&(sh->cond1),0);
    pthread_cond_init(&(sh->cond2),0);

    sh->eroePw = sh->dragoPw = sh->quest = sh->risultato = 0;
    sh->ok_eroePw = sh->ok_dragoPw = sh->ok_quest = sh->ok_risultato = 0;

    return sh;
}
struct ThreadData{
    char* path;
    struct SharedData* shared;
};

void inserisciDati(struct SharedData* sh, int n, int chiSei){
    pthread_mutex_lock(&(sh->mutex));
    if(chiSei == 1){
        while(sh->ok_eroePw){
            pthread_cond_wait(&(sh->cond1), &(sh->mutex));
        }
        sh->eroePw = n;
        sh->ok_eroePw = 1;
    }
    else if(chiSei == 2){
        while(sh->ok_dragoPw){
            pthread_cond_wait(&(sh->cond1), &(sh->mutex));
        }
        sh->dragoPw = n;
        sh->ok_dragoPw = 1;
    }
    else if(chiSei == 3){
        while(sh->ok_quest){
            pthread_cond_wait(&(sh->cond1), &(sh->mutex));
        }
        sh->quest = n;
        sh->ok_quest = 1;
    }

    pthread_cond_broadcast(&(sh->cond1));
    pthread_mutex_unlock(&(sh->mutex));
}

int isValidQuest(char* value){
    if(strstr(value, "L")){
        return 1;
    }
    if(strstr(value, "C")){
        return 2;
    }
    if(strstr(value, "B")){
        return 3;
    }
    return -1;
}

void readData(struct SharedData* sh){
    pthread_mutex_lock(&(sh->mutex));
    printf("Eroe: %d Drago: %d Quest: %d Risultato: %d\n", sh->eroePw, sh->dragoPw, sh->quest, sh->risultato);
    pthread_mutex_unlock(&(sh->mutex));
}

void* EroeFunc(void* args){
    struct ThreadData* data = (struct ThreadData*)args;
    printf("[Eroe] Inizio a leggere il file %s\n", data->path);

    FILE* f = fopen(data->path, "r");
    char buffer[BUFFERSIZE];
    while(fgets(buffer, BUFFERSIZE, f)!=NULL){
        inserisciDati(data->shared, atoi(buffer), 1);
    }

    printf("[Eroe] Finito di leggere il file %s\n", data->path);
    return NULL;
}

void* DragoFunc(void* args){
    struct ThreadData* data = (struct ThreadData*)args;
    printf("[Drago] Inizio a leggere il file %s\n", data->path);

    FILE* f = fopen(data->path, "r");
    char buffer[BUFFERSIZE];
    while(fgets(buffer, BUFFERSIZE, f)!=NULL){
        inserisciDati(data->shared, atoi(buffer), 2);
    }

    printf("[Drago] Finito di leggere il file %s\n", data->path);
    return NULL;
}

void* QuestFunc(void* args){
    struct ThreadData* data = (struct ThreadData*)args;
    printf("[Quest] Inizio a leggere il file %s\n", data->path);

    FILE* f = fopen(data->path, "r");
    char buffer[BUFFERSIZE];
    int totale = 0;
    while(fgets(buffer, BUFFERSIZE, f)!=NULL){
        int op = isValidQuest(buffer);
        if(op!=-1){
            inserisciDati(data->shared, op, 3);
            pthread_mutex_lock(&(data->shared->mutex));
            while(!data->shared->ok_risultato){
                pthread_cond_wait(&(data->shared->cond2), &(data->shared->mutex));
            }
            totale += data->shared->risultato;
            data->shared->ok_risultato = false;
            pthread_cond_broadcast(&(data->shared->cond2));
            pthread_mutex_unlock(&(data->shared->mutex));
        }else{
            printf("[Quest] Ho letto il valore finale %d (è uguale a quello calcolato: %s)\n", atoi(buffer), atoi(buffer)==totale? "si": "no", totale);
            inserisciDati(data->shared, -1, 3);
            inserisciDati(data->shared, -1, 2);
            inserisciDati(data->shared, -1, 1);
            pthread_cond_broadcast(&(data->shared->cond1));
            pthread_cond_broadcast(&(data->shared->cond2));
            break;
        }
    }
    printf("[Quest] Finito di leggere il file %s\n", data->path);
    return NULL;
}

void* MotoreFunc(void* args){
    struct ThreadData* data = (struct ThreadData*)args;
    printf("[Motore] Inizio a calcolare \n");


    while(1){
        pthread_mutex_lock(&(data->shared->mutex));
        while(!data->shared->ok_eroePw || !data->shared->ok_dragoPw || !data->shared->ok_quest){
            pthread_cond_wait(&(data->shared->cond1), &(data->shared->mutex));
        }

        if(data->shared->quest == -1 && data->shared->dragoPw == -1 && data->shared->eroePw == -1){
            pthread_cond_broadcast(&(data->shared->cond1));
            pthread_cond_broadcast(&(data->shared->cond2));
            pthread_mutex_unlock(&(data->shared->mutex));
            break;
        }

        while(data->shared->ok_risultato){
            pthread_cond_wait(&(data->shared->cond2), &(data->shared->mutex));
        }

        if(data->shared->quest == 1){
            data->shared->risultato = data->shared->eroePw + data->shared->dragoPw;
        }
        if(data->shared->quest == 2){
            data->shared->risultato = data->shared->eroePw - data->shared->dragoPw;
        }
        if(data->shared->quest == 3){
            data->shared->risultato = data->shared->eroePw * data->shared->dragoPw;
        }

        data->shared->ok_risultato = 1;
        while(!data->shared->ok_risultato){
            pthread_cond_wait(&(data->shared->cond2), &(data->shared->mutex));
        }

        data->shared->ok_dragoPw = data->shared->ok_eroePw = data->shared->ok_quest = 0;
        data->shared->dragoPw = data->shared->eroePw = data->shared->quest = 0;

        pthread_cond_broadcast(&(data->shared->cond1));
        pthread_cond_broadcast(&(data->shared->cond2));
        pthread_mutex_unlock(&(data->shared->mutex));
    }

    printf("[Motore] Finito di calcolare \n");
    return NULL;
}


int main(int argc, char* argv[]){

    pthread_t eroe;
    pthread_t drago;
    pthread_t quest;
    pthread_t motore;

    struct SharedData* sh = malloc(sizeof(struct SharedData));
    sh = initShared(sh);

    struct ThreadData eroeData = {argv[1], sh};
    struct ThreadData dragoData = {argv[2], sh};
    struct ThreadData questData = {argv[3], sh};
    struct ThreadData motoreData = {NULL, sh};


    pthread_create((&eroe), NULL, EroeFunc, (void*)&eroeData);
    pthread_create((&drago), NULL, DragoFunc, (void*)&dragoData);
    pthread_create((&quest), NULL, QuestFunc, (void*)&questData);
    pthread_create((&motore), NULL, MotoreFunc, (void*)&motoreData);

    // while(1){
    //     readData(sh);
    // }

    pthread_join(eroe, NULL);
    pthread_join(drago, NULL);
    pthread_join(quest, NULL);
    pthread_join(motore, NULL);

}