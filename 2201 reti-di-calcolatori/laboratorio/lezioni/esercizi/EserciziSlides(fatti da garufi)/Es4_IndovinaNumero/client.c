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

    int numeroClient;
    char buffer[32];
    int socketClient;

} messaggiClient;

int main(int argc, char *argv[]){

    if(argc != 3){
        fprintf(stderr,"Errore devi avviarmi con <PORT-server> <IP-server>\n");
        exit(EXIT_FAILURE);
    }

    int socketClient;
    struct sockaddr_in indirizzoPortaServer;

    memset(&indirizzoPortaServer,0,sizeof(indirizzoPortaServer));
    indirizzoPortaServer.sin_family = AF_INET;
    indirizzoPortaServer.sin_port = htons(atoi(argv[1]));
    indirizzoPortaServer.sin_addr.s_addr = inet_addr(argv[2]);

    if((socketClient = socket(AF_INET,SOCK_STREAM,0)) < 0){
        fprintf(stderr,"Errore nella creazione della socket\n");
        exit(EXIT_FAILURE);
    }
    
    if(connect(socketClient,(struct sockaddr*)&indirizzoPortaServer,sizeof(indirizzoPortaServer)) < 0){
        fprintf(stderr,"Errore nella connessione al server\n");
        exit(EXIT_FAILURE);
    }
    printf("Connesso correttamente al server, inizia il gioco.\n");

    for(;;){
        messaggiClient gioco;
        int numero = 0;
        printf("inserisci un numero per provare ad indovinare -> ");
        scanf(" %d",&gioco.numeroClient);
        send(socketClient,&gioco,sizeof(messaggiClient),0);
        int bytesRicevuti = recv(socketClient,gioco.buffer,sizeof(gioco.buffer),0);

        if(bytesRicevuti == 0){
            fprintf(stderr,"Il server non manda dati, forse si è disconnesso\n");
            exit(EXIT_FAILURE);
        }

        if(strcmp(gioco.buffer,"HAI VINTO!") == 0){
            printf("HAI VINTO!, chiudo la sessione.\n");
            exit(EXIT_SUCCESS);
        }else if(strcmp(gioco.buffer,"Troppo Alto") == 0){
            printf("Troppo Alto\n");
        }else if(strcmp(gioco.buffer,"Troppo Basso") == 0){
            printf("Troppo Basso\n");
        }


    }

}