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

    //int socketClient;
    int numeroPilota;
    char statoMotore[36];
    int temperaturaMotore;

}infoMacchina;

void gestioneInvioAllarme(infoMacchina *datiArrivo, int socketTCP){
    printf("\n-------------------------------------------\n");
    printf("Allarme alla vettura numero %d. Invio i dati\n",datiArrivo->numeroPilota);
    printf("-------------------------------------------\n");
    send(socketTCP,datiArrivo,sizeof(infoMacchina),0);


}


int main(int argc, char *argv[]){

    if(argc != 4){
        fprintf(stderr,"Errore devi avviarmi con <PORT-server> <PORT-serverREMOTO> <IP-serverREMOTO> \n");
        exit(EXIT_FAILURE);
    }

    int socketServerUDP;
    int socketServerTCP;
    struct sockaddr_in indirizzoServerUDP;
    struct sockaddr_in indirizzoPortaServerCentro;

    //////////////////////////////UDP//////////////////////////
    memset(&indirizzoServerUDP,0,sizeof(indirizzoServerUDP));
    indirizzoServerUDP.sin_family = AF_INET;
    indirizzoServerUDP.sin_port = htons(atoi(argv[1]));
    indirizzoServerUDP.sin_addr.s_addr = INADDR_ANY;

    if((socketServerUDP = socket(AF_INET,SOCK_DGRAM,0)) < 0){
        fprintf(stderr,"Errore nella creazione della socket.\n");
        exit(EXIT_FAILURE);
    }

    if((bind(socketServerUDP,(struct sockaddr*)&indirizzoServerUDP,sizeof(indirizzoServerUDP))) < 0){
        fprintf(stderr,"Errore nella bind della socket.\n");
        exit(EXIT_FAILURE);
    }
    //////////////////////////////////////////////////////////
    printf("Server in ascolto sulla porta UDP: %s.\n",argv[1]);

    //////////////////////////////TCP//////////////////////////
    memset(&indirizzoPortaServerCentro,0,sizeof(indirizzoPortaServerCentro));
    indirizzoPortaServerCentro.sin_family = AF_INET;
    indirizzoPortaServerCentro.sin_port = htons(atoi(argv[2]));
    indirizzoPortaServerCentro.sin_addr.s_addr = inet_addr(argv[3]);

    if((socketServerTCP = socket(AF_INET,SOCK_STREAM,0)) < 0){
        fprintf(stderr,"Errore nella creazione della socket.\n");
        exit(EXIT_FAILURE);
    }

    if((connect(socketServerTCP,(struct sockaddr*)&indirizzoPortaServerCentro,sizeof(indirizzoPortaServerCentro))) < 0){
        fprintf(stderr,"Errore nel connettersi al server centrale remoto.\n");
        exit(EXIT_FAILURE);
    }
    //////////////////////////////////////////////////////////
    printf("Muretto BOX connesso al centro remoto.\n");


    for(;;){

        infoMacchina datiArrivo;

        int bytesRicevuti = recvfrom(socketServerUDP,&datiArrivo,sizeof(infoMacchina),0,NULL,NULL);

        if(bytesRicevuti == 0){
            printf("Le vetture non comunicano con il muretto BOX.\n");
        }

        if(strcmp(datiArrivo.statoMotore,"OK") == 0){
            printf("[MURETTO BOX] Parametri nominali per la vettura %d\n",datiArrivo.numeroPilota);
        }else{
            gestioneInvioAllarme(&datiArrivo,socketServerTCP);
        }

    }

}