#include <stdlib.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <pthread.h>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>

#define MAX_MACHINES 2

typedef struct{

    int numeroPilota;
    char statoMotore[36];
    int temperaturaMotore;

}infoMacchina;


typedef struct{

    int socketMurettoBOX;
    infoMacchina dati;
    //pthread_mutex_t mutex;

}socketTCP;

pthread_mutex_t mutexLog = PTHREAD_MUTEX_INITIALIZER;

void *gestioneRicezione(void *arg){
    socketTCP *datiArrivo = (socketTCP*)arg;

    int bytesRicevuti = 0;

    do{
        pthread_mutex_lock(&mutexLog);
        FILE* LOG = fopen("registro_guasti_motore.txt", "a");
        if(!LOG){
            fprintf(stderr,"Impossibile aprire il file di LOG.\n");
            exit(EXIT_FAILURE);
        }else{
            printf("File di log aperto correttamente\n");
        }
        pthread_mutex_unlock(&mutexLog);

        bytesRicevuti = recv(datiArrivo->socketMurettoBOX,&datiArrivo->dati,sizeof(infoMacchina),0);
        if(bytesRicevuti <= 0){
            fprintf(stderr,"Il MurettoBOX non comunica.\n");
            close(datiArrivo->socketMurettoBOX);
            free(datiArrivo);
            fclose(LOG);
            return NULL;
        }
        printf("🚨 ALLARME MOTORE VETTURA %d: %d°C! 🚨\n",datiArrivo->dati.numeroPilota,datiArrivo->dati.temperaturaMotore);

        pthread_mutex_lock(&mutexLog);
        fprintf(LOG,"🚨 ALLARME MOTORE VETTURA %d: %d°C! 🚨\n",datiArrivo->dati.numeroPilota,datiArrivo->dati.temperaturaMotore);
        fprintf(LOG,"-------------------------\n");
        fclose(LOG);
        pthread_mutex_unlock(&mutexLog);

    }while(bytesRicevuti > 0);

    return NULL;
}

int main(int argc, char *argv[]){

    if(argc != 2){
        fprintf(stderr,"Errore devi avviarmi con <PORT-serverREMOTO>\n");
        exit(EXIT_FAILURE);
    }

    int socketServer;
    struct sockaddr_in indirizzoServerRemoto;

    memset(&indirizzoServerRemoto,0,sizeof(indirizzoServerRemoto));
    indirizzoServerRemoto.sin_family = AF_INET;
    indirizzoServerRemoto.sin_port = htons(atoi(argv[1]));
    indirizzoServerRemoto.sin_addr.s_addr = INADDR_ANY;

    if((socketServer = socket(AF_INET,SOCK_STREAM,0)) < 0){
        fprintf(stderr,"Errore nella creazione della socket.\n");
        exit(EXIT_FAILURE);
    }

    if((bind(socketServer,(struct sockaddr*)&indirizzoServerRemoto,sizeof(indirizzoServerRemoto))) < 0){
        fprintf(stderr,"Errore nella bind della socket.\n");
        exit(EXIT_FAILURE);
    }

    listen(socketServer,MAX_MACHINES);
    printf("Server remoto in ascolto sulla porta TCP: %s\n",argv[1]);

    for(;;){
        socketTCP *indirizzo = malloc(sizeof(socketTCP));
        //pthread_mutex_init(&indirizzo->mutex,NULL);
        indirizzo->socketMurettoBOX = accept(socketServer,NULL,NULL);

        pthread_t threadRicezione;
        pthread_create(&threadRicezione,NULL,gestioneRicezione,(void *)indirizzo);
        pthread_detach(threadRicezione);

    }

}