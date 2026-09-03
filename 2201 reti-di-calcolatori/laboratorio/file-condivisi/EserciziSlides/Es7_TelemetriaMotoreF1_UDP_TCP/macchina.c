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

typedef struct{

    //int socketClient;
    int numeroPilota;
    char statoMotore[36];
    int temperaturaMotore;

}infoMacchina;


int main(int argc, char *argv[]){

    if(argc != 4){
        fprintf(stderr,"Errore devi avviarmi con <PORT-server> <IP-server> <Numero Pilota>\n");
        exit(EXIT_FAILURE);
    }
    srand(time(NULL));

    int socketClient;
    struct sockaddr_in indirizzoPortaServer;

    memset(&indirizzoPortaServer,0,sizeof(indirizzoPortaServer));
    indirizzoPortaServer.sin_family = AF_INET;
    indirizzoPortaServer.sin_port = htons(atoi(argv[1]));
    indirizzoPortaServer.sin_addr.s_addr = inet_addr(argv[2]);

    if((socketClient = socket(AF_INET,SOCK_DGRAM,0)) < 0){
        fprintf(stderr,"Errore nella creazione della socket.\n");
        exit(EXIT_FAILURE);
    }

    infoMacchina dati;
    dati.numeroPilota = atoi(argv[3]);
    printf("Invio dati.\n");

    for(;;){
        printf("\n");
        sleep(1);
        dati.temperaturaMotore = rand() % (150 - 60 + 1) + 60;
        if(dati.temperaturaMotore > 120){
            strcpy(dati.statoMotore,"OVERHEATING");
        }else{
            strcpy(dati.statoMotore,"OK");   
        }

        sendto(socketClient,&dati,sizeof(infoMacchina),0,(struct sockaddr*)&indirizzoPortaServer,sizeof(indirizzoPortaServer));

    }
}