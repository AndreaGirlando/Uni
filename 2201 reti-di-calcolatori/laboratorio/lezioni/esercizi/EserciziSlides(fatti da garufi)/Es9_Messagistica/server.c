#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <pthread.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 4

typedef struct{

    char buffer[512];

}messaggio;

typedef struct{

    int socketClient;
    messaggio *dati;

}client;

typedef struct{

    int count;
    client *list[MAX_CLIENTS];
    pthread_mutex_t mutex;
}listaClient;

listaClient lista = {.count = 0};

//pthread_mutex_t mutexLista = PTHREAD_MUTEX_INITIALIZER;

void * gestioneRicezione(void * arg){
    //printf("ENTRA\n");
    
    client *datiRicevuti = (client *)arg;
    datiRicevuti->dati = malloc(sizeof(messaggio));

    pthread_mutex_lock(&lista.mutex);
    int inserito = 0;
    for(int i = 0; i < MAX_CLIENTS ;i++){
        if(lista.list[i] == NULL){
            lista.list[i] = datiRicevuti;
            inserito = 1;
            lista.count++;
            break;
        }
    }

    if(inserito == 0){
        printf("Lista client piena.\n");
        close(datiRicevuti->socketClient);
        free(datiRicevuti->dati);
        free(datiRicevuti);
        return NULL;        
    }
    pthread_mutex_unlock(&lista.mutex);

    int bytesRicevuti = 0;

    do{
       
        bytesRicevuti = recv(datiRicevuti->socketClient,datiRicevuti->dati,sizeof(messaggio),0);
        if(bytesRicevuti == 0){
            fprintf(stderr,"Il client non comunica più forse si è disconnesso.\n");
            close(datiRicevuti->socketClient);
            free(datiRicevuti->dati);
            free(datiRicevuti);
            return NULL;
        } 
        
        printf("[IL CLIENT INVIA] -> %s\n",datiRicevuti->dati->buffer);
    }while(bytesRicevuti > 0);



    close(datiRicevuti->socketClient);
    free(datiRicevuti->dati);
    free(datiRicevuti);
    return NULL;

}

int main(int argc , char *argv[]){

    if(argc != 2){
        fprintf(stderr,"Errore devi avviarmi con <PORT-server>\n");
        exit(EXIT_FAILURE);        
    }

    pthread_mutex_init(&lista.mutex,NULL);

    int socketServer;
    struct sockaddr_in indirizzoServer;

    memset(&indirizzoServer,0,sizeof(indirizzoServer));
    indirizzoServer.sin_family = AF_INET;
    indirizzoServer.sin_port = htons(atoi(argv[1]));
    indirizzoServer.sin_addr.s_addr = INADDR_ANY;

    if((socketServer = socket(AF_INET,SOCK_STREAM,0)) < 0){
        fprintf(stderr,"Errore nella creazione della socket.\n");
        exit(EXIT_FAILURE);
    }

    if((bind(socketServer,(struct sockaddr*)&indirizzoServer,sizeof(indirizzoServer))) < 0){
        fprintf(stderr,"Errore nella bind della socket.\n");
        exit(EXIT_FAILURE);        
    }

    listen(socketServer,MAX_CLIENTS);

    printf("Server in ascolto sulla porta TCP %s.\n",argv[1]);

    for(;;){

        client *userMessaggi = malloc(sizeof(client));
        userMessaggi->socketClient = accept(socketServer,NULL,NULL);

        pthread_t threadRicezione;
        pthread_create(&threadRicezione,NULL,gestioneRicezione,(void *)userMessaggi);
        pthread_detach(threadRicezione);

    }


}