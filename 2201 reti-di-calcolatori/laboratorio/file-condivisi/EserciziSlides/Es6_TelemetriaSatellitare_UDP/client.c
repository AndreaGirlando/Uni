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

    int altitude;
    int ID;
    int battery;

} satelliteInfo;

int main(int argc, char* argv[]){

    if(argc != 4){
        fprintf(stderr,"Errore, devi avviarmi con <PORT-server> <IP-server> <ID-satellite>\n");
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
        fprintf(stderr,"Errore nella creazione della socket\n");
        exit(EXIT_FAILURE);
    }
    int batteria = 100;
    for(;;){
        //invio i dati dal satellite al server
        sleep(2);
        satelliteInfo dati;
        dati.ID = atoi(argv[3]);
        dati.altitude = rand() % (1000 - 500 + 1) + 500;
        
        batteria--;
        if(batteria <= 49){
            batteria = batteria + 30;
        }
        dati.battery = batteria;

        sendto(socketClient,&dati,sizeof(satelliteInfo),0,(struct sockaddr*)&indirizzoPortaServer,sizeof(indirizzoPortaServer));


    }


}