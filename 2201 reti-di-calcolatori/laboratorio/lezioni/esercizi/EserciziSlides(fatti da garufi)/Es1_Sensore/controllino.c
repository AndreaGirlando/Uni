#include <stdlib.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <pthread.h>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>

#define MAX_REQUEST 1

int socketServer;

typedef struct{

    uint32_t temperature;
    uint16_t air;  //0-5 scarsa, 6-10 media, 11-15 buona, 16 in su ottima.
    uint16_t sensorID;

} GestioneAllarme;

int main(int argc, char *argv[]){

    if(argc != 2){
        fprintf(stderr,"Errore: devi avviarmi con <PORT-server-controllo>\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in indirizzoServerControllo;

    indirizzoServerControllo.sin_family = AF_INET;
    indirizzoServerControllo.sin_port = htons(atoi(argv[1]));
    indirizzoServerControllo.sin_addr.s_addr = INADDR_ANY;

    if((socketServer = socket(AF_INET,SOCK_STREAM,0)) < 0){
        fprintf(stderr,"Errore nella creazione della socket\n");
        exit(EXIT_FAILURE);
    }

    if((bind(socketServer,(struct sockaddr*)&indirizzoServerControllo,sizeof(indirizzoServerControllo)) < 0)){
        fprintf(stderr,"Errore nella bind della socket\n");
        exit(EXIT_FAILURE);
    }

    listen(socketServer,MAX_REQUEST);

    printf("Server in ascolto sulla porta %d\n",atoi(argv[1]));
     
    int socketServerCentrale;
    socklen_t addrlen = sizeof(indirizzoServerControllo);
    socketServerCentrale = accept(socketServer,(struct sockaddr*)&indirizzoServerControllo,&addrlen);
    printf("Connessione accettata\n");
    GestioneAllarme allarme;
    for(;;){

        FILE* log = fopen("LOG.txt", "a");  //apro il file in modalità append
        if (!log){
            perror("File opening failed, impossibile scrivere il log");
            exit(EXIT_FAILURE);
        }else{
            printf("File di log aperto correttamente\n");
        }
        int bytesRicevuti = recv(socketServerCentrale,&allarme,sizeof(GestioneAllarme),0);

        if(bytesRicevuti == 0){
            printf("Il server non sta comunicando -> nessun allarme\n");
            break;
        }else{
            
            allarme.sensorID = ntohs(allarme.sensorID);
            allarme.temperature = ntohl(allarme.temperature);
            allarme.air = ntohs(allarme.air);

            float temp = (float)allarme.temperature/100;
            fprintf(log,"ALLARME ||| Temperatura: %.2f, Qualità aria: %d, ID sensore: %d\n",temp,allarme.air,allarme.sensorID);
            fprintf(log,"---------------------------\n");
            printf("Allarme registrato nel file di log\n");
        }
        fclose(log);

    }
    close(socketServerCentrale);
    close(socketServer);
}