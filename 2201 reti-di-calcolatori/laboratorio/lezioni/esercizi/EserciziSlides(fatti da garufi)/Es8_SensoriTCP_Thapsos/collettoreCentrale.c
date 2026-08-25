#include <stdlib.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <pthread.h>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>

typedef struct {

    int IDScavo;
    int humidity;
    int temperature;

} SensoreTCP;


typedef struct{

    int socketSensor;
    SensoreTCP *dati;

} SocketDati;

pthread_mutex_t mutexLog = PTHREAD_MUTEX_INITIALIZER;

#define MAX_CLIENTS 10

void *gestioneRicezione(void *arg){

    SocketDati *datiArrivo = (SocketDati*)arg;
    datiArrivo->dati = malloc(sizeof(SensoreTCP));
    int bytesRicevuti = 0;
    do{


        bytesRicevuti = recv(datiArrivo->socketSensor,datiArrivo->dati,sizeof(SensoreTCP),0);

        if(bytesRicevuti == 0){
            fprintf(stderr,"Il sensore TCP non comunica, chiudo la connessione.\n");
            close(datiArrivo->socketSensor);
            free(datiArrivo);
            return NULL;
        }

        if(datiArrivo->dati->temperature > 38 || datiArrivo->dati->humidity < 30){
            printf("[ALLARME] -> scavo numero: %d, temperatura: %d, umidità: %d. Rischio degrado reperti.\n",datiArrivo->dati->IDScavo,datiArrivo->dati->temperature,datiArrivo->dati->humidity);
            
            pthread_mutex_lock(&mutexLog);
            FILE* LOG = fopen("clima_thapsos.log", "a");
            if (!LOG) {
                fprintf(stderr,"Impossibile aprire il file.\n");
            }else{
                fprintf(LOG,"[ALLARME] -> scavo numero: %d, temperatura: %d, umidità: %d. Rischio degrado reperti.\n",datiArrivo->dati->IDScavo,datiArrivo->dati->temperature,datiArrivo->dati->humidity);
                fclose(LOG);
            }
            pthread_mutex_unlock(&mutexLog);

        
        }

    }while(bytesRicevuti > 0);
    

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

        SocketDati *connessioneTCP = malloc(sizeof(SocketDati));

        connessioneTCP->socketSensor = accept(socketServer,NULL,NULL);

        pthread_t threadRicezione;
        pthread_create(&threadRicezione,NULL,gestioneRicezione,(void*)connessioneTCP);
        pthread_detach(threadRicezione);
        

    }


}