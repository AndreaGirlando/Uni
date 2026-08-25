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

    int altitude;
    int ID;
    int battery;

} satelliteInfo;

int main(int argc, char* argv[]){

    if(argc != 2){
        fprintf(stderr,"Errore, devi avviarmi con <PORT-server>\n");
        exit(EXIT_FAILURE);
    }

    int socketServer;
    struct sockaddr_in indirizzoServer;

    memset(&indirizzoServer,0,sizeof(indirizzoServer));
    indirizzoServer.sin_family = AF_INET;
    indirizzoServer.sin_port = htons(atoi(argv[1]));
    indirizzoServer.sin_addr.s_addr = INADDR_ANY;

    if((socketServer = socket(AF_INET,SOCK_DGRAM,0)) < 0){
        fprintf(stderr,"Errore nella creazione della socket.\n");
        exit(EXIT_FAILURE);
    }

    if((bind(socketServer,(struct sockaddr*)&indirizzoServer,sizeof(indirizzoServer))) < 0){
        fprintf(stderr,"Errore nella bind della porta.\n");
        exit(EXIT_FAILURE);
    }

    printf("Server in ascolto sulla porta %s (UDP)\n",argv[1]);

    for(;;){
        satelliteInfo datiRicevuti;

        struct sockaddr_in indirizzoClient;
        socklen_t lunghezzaClient = sizeof(indirizzoClient);

        int bytesRicevuti = recvfrom(socketServer,&datiRicevuti,sizeof(satelliteInfo),0,(struct sockaddr*)&indirizzoClient,&lunghezzaClient);
        printf("%d     ",bytesRicevuti);
        printf("DATI IN ARRIVO DA: %s - %d : ID %d , Altitudine %d , Batteria %d%% \n",inet_ntoa(indirizzoClient.sin_addr),ntohs(indirizzoClient.sin_port),datiRicevuti.ID,datiRicevuti.altitude,datiRicevuti.battery);

    }




}