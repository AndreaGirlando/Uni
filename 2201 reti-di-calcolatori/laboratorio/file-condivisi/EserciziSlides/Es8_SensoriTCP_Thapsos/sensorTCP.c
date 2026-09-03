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


typedef struct {

    int IDScavo;
    int humidity;
    int temperature;

} SensoreTCP;

int main(int argc, char *argv[]){

    if(argc != 4){
        fprintf(stderr,"Errore devi avviarmi con <PORT-server> <IP-server> <ID-scavo>\n");
        exit(EXIT_FAILURE);
    }
    
    srand(time(NULL));

    int socketSensor;
    struct sockaddr_in indirizzoPortaServer;

    memset(&indirizzoPortaServer,0,sizeof(indirizzoPortaServer));
    indirizzoPortaServer.sin_family = AF_INET;
    indirizzoPortaServer.sin_port = htons(atoi(argv[1]));
    indirizzoPortaServer.sin_addr.s_addr = inet_addr(argv[2]);

    if((socketSensor = socket(AF_INET,SOCK_STREAM,0)) < 0){
        fprintf(stderr,"Errore nella creazione della socket.\n");
        exit(EXIT_FAILURE);
    }

    if((connect(socketSensor,(struct sockaddr*)&indirizzoPortaServer,sizeof(indirizzoPortaServer))) < 0){
        fprintf(stderr,"Errore nella connessione al server.\n");
        exit(EXIT_FAILURE);
    }

    printf("Connesso al server %s - %s.\n",argv[2],argv[1]);


    for(;;){
        sleep(3);
        SensoreTCP dati;
        dati.IDScavo = atoi(argv[3]);
        dati.temperature = rand() % (48 - 2 + 1) + 2;
        dati.humidity = rand() % (85 - 5 + 1) + 5;

        send(socketSensor,&dati,sizeof(dati),0);

    }

    
}