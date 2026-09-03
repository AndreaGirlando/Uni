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
    
    uint32_t temperature;
    uint16_t humidity;
    uint16_t air;  //0-5 scarsa, 6-10 media, 11-15 buona, 16 in su ottima.
    uint16_t sensorID;

} Sensor_info;



int main(int argc, char* argv[]){
    srand(time(NULL));

    if(argc != 4){
        fprintf(stderr,"Errore, devi avviarmi con <IP-del-sever> <PORT-del-sever> <ID-del-sensore>\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in indirizzoPortaServer;
    int socketSensor;
    Sensor_info datiDaInviare;

    memset(&indirizzoPortaServer,0,sizeof(indirizzoPortaServer));
    indirizzoPortaServer.sin_family = AF_INET;
    indirizzoPortaServer.sin_port = htons(atoi(argv[2]));   //converto in numero, poi in network byte order
    indirizzoPortaServer.sin_addr.s_addr = inet_addr(argv[1]);  //passo come stringa

    if((socketSensor = socket(AF_INET,SOCK_DGRAM,0)) < 0){  //utilizzo UDP
        fprintf(stderr,"Errore nella creazione della socket\n");
        exit(EXIT_FAILURE);
    }

    for(;;){
        sleep(3);
        //creo e invio dati
        printf("Creo e invio dati\n");
        float temp = (((float)rand() /RAND_MAX) *35.0); //dovro poi dividere per 100 al server
        datiDaInviare.temperature = htonl(temp*100);
        datiDaInviare.humidity = htons(((float)rand() /RAND_MAX) *100.0);
        datiDaInviare.air = htons(((float)rand() /RAND_MAX) *20.0);
        datiDaInviare.sensorID = htons((atoi(argv[3]))); 
        //printf("dati inviati: %d, %d, %d, %d\n",datiDaInviare.temperature,datiDaInviare.humidity,datiDaInviare.air,datiDaInviare.sensorID);
        if(sendto(socketSensor,&datiDaInviare,sizeof(datiDaInviare),0,(struct sockaddr*)&indirizzoPortaServer,sizeof(indirizzoPortaServer)) == -1){ //UDP
            fprintf(stderr,"Errore nella sendto()\n");
        }   

    }
    close(socketSensor);

}