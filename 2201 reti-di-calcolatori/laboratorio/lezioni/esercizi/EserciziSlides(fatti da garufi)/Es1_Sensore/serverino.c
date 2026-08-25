#include <stdlib.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <pthread.h>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <stdbool.h>

#define MAX_SENSORS 10
//UDP per ricevere dal sensore, TCP per il nodo di controllo
int socketServerUDP;
int socketServerTCP;

typedef struct{

    uint32_t temperature;
    uint16_t air;  //0-5 scarsa, 6-10 media, 11-15 buona, 16 in su ottima.
    uint16_t sensorID;

} GestioneAllarme;

typedef struct{

    uint32_t temperature;
    uint16_t humidity;
    uint16_t air;  //0-5 scarsa, 6-10 media, 11-15 buona, 16 in su ottima.
    uint16_t sensorID;

} SensorInfo;

typedef struct{
    int count;
    SensorInfo list[MAX_SENSORS];
    pthread_mutex_t mutex;

} SensorList;

SensorList sensori = {.count = 0};


void *gestioneRicezione(void *arg){ //(e invio al nodo di controllo in caso di allarme)
    bool trovato = 0;
    SensorInfo *infoSensore = (SensorInfo*)arg; //casting per tornare a tipo sensorinfo
    //il thread scorre la lista confrontando l'id se esiste gia aggiorno i valori altrimenti creo un nuovo elemento della lista (deve usare i semafori mutex)

    pthread_mutex_lock(&sensori.mutex);

    infoSensore->sensorID = ntohs(infoSensore->sensorID);
    infoSensore->temperature = ntohl(infoSensore->temperature);
    infoSensore->temperature = infoSensore->temperature;
    infoSensore->air = ntohs(infoSensore->air);
    infoSensore->humidity = ntohs(infoSensore->humidity);

    for(int i = 0; i < sensori.count; i++){     //scorro tutti i sensori

        if(sensori.list[i].sensorID == infoSensore->sensorID){
            sensori.list[i].temperature = infoSensore->temperature;
            sensori.list[i].humidity = infoSensore->humidity;
            sensori.list[i].air = infoSensore->air;
            trovato = 1;
            break;
        }
    }

    if(trovato == 0){   //c'è un sensore nuovo
        if(sensori.count < MAX_SENSORS){
            sensori.list[sensori.count] = *infoSensore;
            sensori.count++;
        }else{
            fprintf(stderr,"Errore: non posso gestire altri sensori");
        }
    }
    pthread_mutex_unlock(&sensori.mutex);  

    //se la temperatura è > 30 o qualità dell'aria è poor (0-5) invia comunicazione al nodo di controllo
    if(((float)infoSensore->temperature/100) > 30.0 || infoSensore->air >= 0 && infoSensore->air <= 5){  //se è vero invia un allarme
        GestioneAllarme allarme;
        allarme.air = htons(infoSensore->air);
        allarme.sensorID = htons(infoSensore->sensorID);
        allarme.temperature = htonl(infoSensore->temperature);
        send(socketServerTCP,&allarme,sizeof(GestioneAllarme),0);
    }

    free(infoSensore);

    return NULL;
}

void * gestioneStampa(void * arg){

    pthread_mutex_lock(&sensori.mutex);
    for(int i = 0; i < sensori.count; i++){
        float temp = (float)sensori.list[i].temperature/100;
        printf("STAMPA DATI: Temperatura - %.2f, Umidità - %d%%, Qualità dell'aria - %d, ID sensore - %d\n",temp,sensori.list[i].humidity,sensori.list[i].air,sensori.list[i].sensorID);
    }
    pthread_mutex_unlock(&sensori.mutex);  

}


int main(int argc, char *argv[]){

    if(argc != 4){
        fprintf(stderr,"Errore, devi avviarmi con <PORT-di-questo-sever> <IP-del_nodo_controllo> <PORT-del-nodo-controllo>\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in infoUDP;
    struct sockaddr_in infoTCP;
    pthread_mutex_init(&sensori.mutex, NULL);


    ///////////////////////socket UDP///////////////////////////
    memset(&infoUDP,0,sizeof(infoUDP));
    infoUDP.sin_family = AF_INET;
    infoUDP.sin_port = htons(atoi(argv[1]));
    infoUDP.sin_addr.s_addr = INADDR_ANY;
    
    if((socketServerUDP = socket(AF_INET,SOCK_DGRAM,0)) < 0){
        fprintf(stderr,"Errore nella creazione della socket UDP\n");
        exit(EXIT_FAILURE);
    }

    if((bind(socketServerUDP,(struct sockaddr*)&infoUDP,sizeof(infoUDP))) < 0){
        fprintf(stderr,"Errore nella bind\n");
        exit(EXIT_FAILURE);
    }

    printf("Server in ascolto sulla porta %d(UDP)\n",atoi(argv[1]));
    ///////////////////////////////////////////////////////////////



    ///////////////////////socket TCP///////////////////////////

    memset(&infoTCP,0,sizeof(infoTCP));
    infoTCP.sin_family = AF_INET;
    infoTCP.sin_port = htons(atoi(argv[3]));
    infoTCP.sin_addr.s_addr = inet_addr(argv[2]);

    if((socketServerTCP = socket(AF_INET,SOCK_STREAM,0)) < 0){
        fprintf(stderr,"Errore nella creazione della socket TCP\n");
        exit(EXIT_FAILURE);
    }

    if((connect(socketServerTCP,(struct sockaddr*)&infoTCP,sizeof(infoTCP))) < 0){
        fprintf(stderr,"Errore: server controllo irraggiungibile");
    }
    ///////////////////////////////////////////////////////////////

    for(;;){
        printf("\n\n");
        SensorInfo *datiRicevuti = malloc(sizeof(SensorInfo));      //alloco un istanza delle struct del sensore

        recvfrom(socketServerUDP,datiRicevuti,sizeof(SensorInfo),0,NULL,NULL);   //aspetto che mi arrivino i dati

        pthread_t threadRicezione;
        pthread_create(&threadRicezione,NULL,gestioneRicezione, (void*)datiRicevuti);   //una volta arrivati i dati creo il thread e vado nella funzione
        pthread_detach(threadRicezione);

        ////////////////////////////////////////////////////////////////////
        pthread_t threadStampa; //THREAD CHE SI OCCUPA DELLA STAMPA DEI DATI
        pthread_create(&threadStampa,NULL,gestioneStampa, NULL); 
        pthread_detach(threadStampa);
        ////////////////////////////////////////////////////////////////////

    }

}