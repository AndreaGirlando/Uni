#include <stdlib.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <pthread.h>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <time.h>

#define MAX_CLIENTS 4

typedef struct{

    int numeroClient;
    char buffer[32];
    int socketClient;

} messaggiClient;

void * gestioneClient(void *arg){
    messaggiClient *client;
    client = (messaggiClient*)arg;
    int socketAppoggio = client->socketClient;
    

    srand(time(NULL));
    int numeroRandom = rand() % 100;
    printf("Il numero random è: %d\n",numeroRandom);
    do{
        int bytesRicevuti = recv(socketAppoggio,client,sizeof(messaggiClient),0);
        if(bytesRicevuti == 0){
            fprintf(stderr,"Il client non manda dati, forse si è disconnesso\n");
            close(socketAppoggio);
            free(client);
            return NULL;
        }
        if(client->numeroClient == numeroRandom){
            printf("Il client ha vinto.\n");
            send(socketAppoggio,"HAI VINTO!",11,0);
        }else if(client->numeroClient > numeroRandom){
            printf("Troppo Alto\n");
            send(socketAppoggio,"Troppo Alto",12,0);
        }else if(client->numeroClient < numeroRandom){
            printf("Troppo Basso\n");
            send(socketAppoggio,"Troppo Basso",13,0);
        }

    }while(client->numeroClient != numeroRandom);

    close(socketAppoggio);
    free(client);
    return NULL;

}

int main(int argc, char *argv[]){

    if(argc != 2){
        fprintf(stderr,"Errore devi avviarmi con <PORT-server>\n");
        exit(EXIT_FAILURE);
    }

    int socketServer;
    struct sockaddr_in indirizzoServer;

    memset(&indirizzoServer,0,sizeof(indirizzoServer));
    indirizzoServer.sin_family = AF_INET;
    indirizzoServer.sin_port = htons(atoi(argv[1]));
    indirizzoServer.sin_addr.s_addr = INADDR_ANY;

    if((socketServer = socket(AF_INET,SOCK_STREAM,0)) < 0){
        fprintf(stderr,"Errore nella creazione della socket\n");
        exit(EXIT_FAILURE);
    }

    if((bind(socketServer,(struct sockaddr*)&indirizzoServer,sizeof(indirizzoServer))) < 0){
        fprintf(stderr,"Errore nella bind della socket.\n");
        exit(EXIT_FAILURE);
    }

    listen(socketServer,MAX_CLIENTS);
    printf("Server in ascolto sulla porta %s.\n",argv[1]);

    for(;;){

        messaggiClient *structClient = malloc(sizeof(messaggiClient));
        structClient->socketClient = accept(socketServer,NULL,NULL);

        pthread_t threadRicezione;
        pthread_create(&threadRicezione,NULL,gestioneClient,(void*)structClient);
        pthread_detach(threadRicezione);

    }
}