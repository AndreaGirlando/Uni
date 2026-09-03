#include <stdlib.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <pthread.h>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>

typedef struct{

    int numeroCarburante;
    char buffer[64];
    int socketClient;

} ComunicazioneClient;

int main(int argc, char *argv[]){

    if(argc != 3){
        fprintf(stderr,"Errore devi avviarmi con <PORT-server> <IP-server>");
        exit(EXIT_FAILURE);
    }

    int socketClient;
    struct sockaddr_in indirizzoPortaServer;

    memset(&indirizzoPortaServer,0,sizeof(indirizzoPortaServer));
    indirizzoPortaServer.sin_family = AF_INET;
    indirizzoPortaServer.sin_port = htons(atoi(argv[1]));
    indirizzoPortaServer.sin_addr.s_addr = inet_addr(argv[2]);

    if((socketClient = socket(AF_INET,SOCK_STREAM,0)) < 0){
        fprintf(stderr,"Errore nella creazione della socket");
        exit(EXIT_FAILURE);        
    }

    connect(socketClient,(struct sockaddr*)&indirizzoPortaServer,sizeof(indirizzoPortaServer));
    printf("Stazione collegata con successo.\n");

        ComunicazioneClient nave;
        printf("Inviare la quantità di carburante desiderata -> ");
        scanf( " %d",&nave.numeroCarburante);
        send(socketClient,&nave,sizeof(ComunicazioneClient),0);

        int bytesRicevuti = recv(socketClient,&nave,sizeof(ComunicazioneClient),0);

        if(bytesRicevuti == 0){
            fprintf(stderr,"La stazione non comunica.\n");
            close(socketClient);
            exit(EXIT_FAILURE);
        }

        if(strcmp(nave.buffer,"RIFORNIMENTO OK") == 0){
            printf("Rifornimento completato. Sgancio.\n");
            exit(EXIT_SUCCESS);
        }else{
            printf("Carburante insufficiente. Ripetere la procedura.\n");
            exit(EXIT_FAILURE);
        }


}