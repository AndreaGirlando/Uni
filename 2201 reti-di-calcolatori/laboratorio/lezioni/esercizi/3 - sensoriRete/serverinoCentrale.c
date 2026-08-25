//il server ha bisogno di 3 socket
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <pthread.h>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 

#include "mioProtocollo.h"

int socketServerUDP, socketServerTCP, socketClientTCP;

#define MAX_SENSORS 64

typedef struct{

    int socketSensor;
    struct sockaddr_in indirizzoPorta;

    sensor_read_t dati;

}sensor_info_t;


typedef struct{
    sensors_list_t *list[MAX_SENSORS];
    unsigned int count;
    pthread_mutex_t mutex;
}sensors_list_t;

sensors_list_t listaSensori = {.count = 0};
struct sockaddr_in infoServerLog;


int createServer(uint16_t port, int typeSocket){
    int socketDaTornare;
    struct sockaddr_in infoSocket;
    infoSocket.sin_family = AF_INET;
    infoSocket.sin_port = htons(port);
    infoSocket.sin_addr.s_addr = INADDR_ANY;

    socketDaTornare = socket(AF_INET, typeSocket,0);

    if(bind(socketDaTornare,(struct sockaddr*)&infoSocket,sizeof(infoSocket)) < 0){
        printf("Errore nella bind della porta %d\n",port);
        exit(EXIT_FAILURE);
    }

    if(typeSocket == SOCK_STREAM){
        listen(socketDaTornare,MAX_SENSORS);
    }

    return socketDaTornare;

}


void * ricezioneUDP(void * arg){

    protocol_message_t buffer;

    for(;;){        //ad ogni messaggio che arriva creo un thread
        protocol_message_t *buffer = malloc(sizeof(protocol_message_t));
        recvfrom(socketServerUDP, &buffer, sizeof(buffer),0,NULL,NULL);
        pthread_t threadElaborazione;
        pthread_create(&threadElaborazione,NULL,elaborazioneDatiSensore,(void*)buffer);
        pthread_detach(threadElaborazione);
    }

    return NULL;
}

void * elaborazioneDatiSensore(void *arg){

    protocol_message_t *buffer = (protocol_message_t*) arg;
    if(buffer->type == TYPE_READ){
        sensor_read_t lettura;
        memcpy(&lettura, buffer->payload,sizeof(lettura));
        lettura.temperature = ntohl(lettura.temperature);
        lettura.humidity = ntohl(lettura.humidity);
        lettura.seonsorID = ntohs(lettura.seonsorID);
        pritnf("[SENSOR-%d] [%s] Temperatura: %f, Umidita' [%d], C'e' Riccobene? %s\n",lettura.seonsorID,lettura.citta,(float)lettura.temperature/100.0,lettura.humidity,(lettura.ceRiccobene));

    }

    free(buffer);
    return NULL;

}

void * gestioneConnessioneSensore(void *arg){

    sensor_info_t *sensorInfo = (sensor_info_t*) arg;
    //aggiorno la lista sensori
    int socketSensore = sensorInfo->socketSensor;
    int indiceSensoreInMemoria = 0;

    pthread_mutex_lock(&listaSensori.mutex);
    listaSensori.list[listaSensori.count] = sensorInfo;
    indiceSensoreInMemoria = listaSensori.count;
    listaSensori.count++;
    pthread_mutex_unlock(&listaSensori.mutex);

    protocol_message_t messaggioIn,messaggioFromLog;
    sensor_read_t ultimoAllarme;

    for(;;){

        int byteRicevuti = recv(socketSensore,&messaggioIn,sizeof(messaggioIn),0);

        if(byteRicevuti == 0){
            break;
        }

        if(messaggioIn.type == TYPE_READ){
            memcpy(&ultimoAllarme, messaggioIn.payload, sizeof(ultimoAllarme));

            // CORRETTO: parentesi sistemate, aggiunto %.2f e raddrizzati i parametri
            printf("[SENSOR-%d] [%s] [ALLARME] Temperatura: %.2f\n", 
                ntohs(ultimoAllarme.seonsorID), 
                ultimoAllarme.citta, 
                (float)ntohl(ultimoAllarme.temperature) / 100.0);
                
            memcpy(&listaSensori.list[indiceSensoreInMemoria]->dati, &ultimoAllarme, sizeof(ultimoAllarme));

            send(socketClientTCP, &messaggioIn, sizeof(messaggioIn), 0);
            /*int bytesRicevutiDaLog = recv(socketClientTCP,&messaggioFromLog,sizeof(messaggioFromLog),0);
            if(bytesRicevutiDaLog == 0){
                break;
            }*/
        }
    }


    pthread_mutex_lock(&listaSensori.mutex);
    for(int i = 0; i < listaSensori.count; i++){
        if(listaSensori.list[i]->socketSensor == socketSensore){
        //ho trovato il client che si sta disconnettendo
        free(listaSensori.list[i]);
        for(int j = i; j < listaSensori.count-1; j++){   //qui chiudo lo spazio vuoto lasciato dal client disconnesso
            listaSensori.list[j] = listaSensori.list[j+1];
        }
        listaSensori.count--;
        break;
    }
    }
    pthread_mutex_unlock(&listaSensori.mutex);

    return NULL;

}

void * gestioneRicezione(void* arg){

    protocol_message_t *messaggioIn = malloc(sizeof(protocol_message_t));

    for(;;){
        int bytesRicevuti = recv(socketClientTCP, &messaggioIn, sizeof(messaggioIn),0);
        if(bytesRicevuti == 0){
            exit(1);
        }

        pthread_t threadRicezioneTCP;
        pthread_create(&threadRicezioneTCP,NULL,gestioneRisveglioSensore,(void*)messaggioIn);
        pthread_detach(threadRicezioneTCP);

    }

}

void* gestioneRisveglioSensore(void *arg){

    protocol_message_t *messaggioRicevuto = (protocol_message_t*)arg;
    if(messaggioRicevuto->type == TYPE_UNLOCK){
        protocol_message_t messaggioUnlock;
        //memcpy(&)
    }


    free(messaggioRicevuto);
    return NULL;


}


//serverino <PORT-UDP> <PORT-TCP> <IP-server_LOG> <PORT-SERVER-LOG>

int main(int argc, char* argv[]){

    if(argc < 5){
        printf("Mi devi avviare con: <PORT-UDP> <PORT-TCP> <IP-server_LOG> <PORT-SERVER-LOG>\n");
        exit(EXIT_FAILURE);
    }

    pthread_mutex_init(&listaSensori.mutex, NULL);

    infoServerLog.sin_family = AF_INET;
    infoServerLog.sin_port = htons(atoi(argv[4]));
    infoServerLog.sin_addr.s_addr = inet_addr(argv[3]);

    socketServerUDP = createServer(atoi(argv[1]), SOCK_DGRAM);
    socketServerUDP = createServer(atoi(argv[2]), SOCK_STREAM);
    socketClientTCP = socket(AF_INET,SOCK_STREAM,0);

    //mi collego al server di log

    if(connect(socketClientTCP,(struct sockaddr*)&infoServerLog,sizeof(infoServerLog)) < 0){
        printf("Impossibile collegarsi al server di log\n");
        exit(EXIT_FAILURE);
    }

    //pthread_t 

    pthread_t threadUDP;
    pthread_create(&threadUDP,NULL,ricezioneUDP, NULL);
    pthread_detach(threadUDP);


    for(;;){
        //ricezione UDP
        sensor_info_t *sensorInfo = malloc(sizeof(sensor_info_t));  //alloco spazio per la struct client_info_t, "client" punta a questa struct
        socklen_t addrlen = sizeof(sensorInfo->indirizzoPorta);

        sensorInfo->socketSensor = accept(socketServerTCP,(struct sockaddr*)&sensorInfo->indirizzoPorta, &addrlen);

        pthread_t threadSensore;
        pthread_create(&threadSensore,NULL,gestioneConnessioneSensore, (void*)sensorInfo);
        pthread_detach(threadSensore);
        //connessione TCP
            //ricezione TCP per ogni connessione
        
    }



}
