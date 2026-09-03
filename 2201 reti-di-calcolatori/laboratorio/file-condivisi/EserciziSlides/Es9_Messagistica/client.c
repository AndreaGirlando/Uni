#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <pthread.h>
#include <arpa/inet.h>

typedef struct{

    char buffer[512];

}messaggio;

int main(int argc , char *argv[]){

    if(argc != 3){
        fprintf(stderr,"Errore devi avviarmi con <IP-server> <PORT-server>\n");
        exit(EXIT_FAILURE);
    }

    int socketClient;
    struct sockaddr_in indirizzoPortaServer;

    memset(&indirizzoPortaServer,0,sizeof(indirizzoPortaServer));
    indirizzoPortaServer.sin_family = AF_INET;
    indirizzoPortaServer.sin_port = htons(atoi(argv[1]));
    indirizzoPortaServer.sin_addr.s_addr = inet_addr(argv[2]);

    if((socketClient = socket(AF_INET,SOCK_STREAM,0)) < 0){
        fprintf(stderr,"Errore nella creazione della socket.\n");
        exit(EXIT_FAILURE);
    }

    if((connect(socketClient,(struct sockaddr*)&indirizzoPortaServer,sizeof(indirizzoPortaServer))) < 0){
        fprintf(stderr,"Errore nella connessione al server.\n");
        exit(EXIT_FAILURE);
    }

    printf("Connessione al server riuscita. Scrivi il messaggio da inviare.\n");

    messaggio dati;

    for(;;){
        printf("Scrivi il messaggio che vuoi inviare: \n");
        fgets(dati.buffer,sizeof(dati.buffer),stdin);
        dati.buffer[strcspn(dati.buffer,"\n")] = '\0';

        send(socketClient,&dati,sizeof(messaggio),0);
        fflush(stdin);
    }


}