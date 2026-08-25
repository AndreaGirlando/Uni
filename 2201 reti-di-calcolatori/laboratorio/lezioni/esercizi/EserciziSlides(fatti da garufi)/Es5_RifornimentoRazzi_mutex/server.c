#include <stdlib.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <pthread.h>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>

#define MAX_CLIENTS 5

typedef struct{

    int numeroCarburante;
    char buffer[64];
    int socketClient;

} ComunicazioneClient;

typedef struct{

    pthread_mutex_t mutex;
    int litriCarburante;


} Rifornimento;
Rifornimento clients ={.litriCarburante = 5000};


void * gestioneRicezione(void *arg){

    ComunicazioneClient *nave = (ComunicazioneClient*)arg;
    int socketComunicazione = nave->socketClient;
    int bytesRicevuti = recv(socketComunicazione,nave,sizeof(ComunicazioneClient),0);

    if(bytesRicevuti == 0){
        fprintf(stderr,"La nave non comunica.\n");
        close(socketComunicazione);
        free(nave);
        return NULL;
    }
    printf("La navicella richiede [%d] litri di carburante.\n",nave->numeroCarburante);

    pthread_mutex_lock(&clients.mutex);
    int sottrazione = nave->numeroCarburante;   //la richiesta del client
    if((clients.litriCarburante - sottrazione) >= 0){
        clients.litriCarburante = clients.litriCarburante - sottrazione;

        nave->numeroCarburante = sottrazione;   //preparo tutto per mandare la struct
        strcpy(nave->buffer,"RIFORNIMENTO OK");
        printf("Propellente erogato con successo.\n");
        send(socketComunicazione,nave,sizeof(ComunicazioneClient),0);

    }else{
        nave->numeroCarburante = 0;

        strcpy(nave->buffer,"PROPELLENTE INSUFFICIENTE");
        printf("Propellente insufficiente.\n");
        send(socketComunicazione,nave,sizeof(ComunicazioneClient),0);
    }
    printf("Carburante restante: %d\n",clients.litriCarburante);
    pthread_mutex_unlock(&clients.mutex);

    close(socketComunicazione);
    free(nave);
    return NULL;
}


int main(int argc, char *argv[]){

    if(argc != 2){
        fprintf(stderr,"Errore devi avviarmi con <PORT-server> <IP-server>");
        exit(EXIT_FAILURE);
    }

    int socketServer;
    struct sockaddr_in indirizzoServer;
    pthread_mutex_init(&clients.mutex, NULL);

    memset(&indirizzoServer,0,sizeof(indirizzoServer));
    indirizzoServer.sin_family = AF_INET;
    indirizzoServer.sin_port = htons(atoi(argv[1]));
    indirizzoServer.sin_addr.s_addr = INADDR_ANY;

    if((socketServer = socket(AF_INET,SOCK_STREAM,0)) < 0){
        fprintf(stderr,"Errore nella creazione della porta");
        exit(EXIT_FAILURE);    
    }

    if((bind(socketServer,(struct sockaddr*)&indirizzoServer,sizeof(indirizzoServer))) < 0){
        fprintf(stderr,"Errore nella bind della porta");
        exit(EXIT_FAILURE);    
    }

    listen(socketServer,MAX_CLIENTS);
    printf("Server in ascolto sulla porta %s.\n",argv[1]);

    for(;;){

        ComunicazioneClient *nave = malloc(sizeof(ComunicazioneClient));
        nave->socketClient = accept(socketServer,NULL,NULL);

        pthread_t threadRicezione;
        pthread_create(&threadRicezione,NULL,gestioneRicezione,(void*)nave);
        pthread_detach(threadRicezione);

    }


}