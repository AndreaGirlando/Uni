#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 

#define BUFFER_MAX 1024

int main(int argc, char* argv[]) { 
    if(argc <3){ //remember, argv[0] is the same program! 
        printf ("Devi avvisarmi usando <IP> <Port> \n");
        exit(1); 
    } 

    int socketFD;
    struct sockaddr_in indirizzoPortaServer;
    char bufferAux[BUFFER_MAX];

    memset(&indirizzoPortaServer, 0, sizeof(indirizzoPortaServer));
    indirizzoPortaServer.sin_family = AF_INET;
    indirizzoPortaServer.sin_port = htons(atoi(argv[2]));
    indirizzoPortaServer.sin_addr.s_addr = inet_addr(argv[1]);

    socketFD = socket(AF_INET, SOCK_STREAM,0);

    if(connect(socketFD, (struct sockaddr*)&indirizzoPortaServer,sizeof(indirizzoPortaServer)) < 0){
        printf("Errore di connessione: ");
        exit(1);
    }

    printf("Connesso al server %s:%s\n", argv[1],argv[2]);

    //fin qui ci siamo solamente connessi al server, questa parte è abbastanza standard per ogni esercizio
    //loop logico

    for(;;){

        fflush(stdout);

        fgets(bufferAux, BUFFER_MAX, stdin);

        bufferAux[strcspn(bufferAux, "\n")] = '0';
        if(strcmp(bufferAux, "esci") == 0){
            break;
        }

        send(socketFD,bufferAux, strlen(bufferAux),0);
        memset(bufferAux, 0, strlen(bufferAux)); //svuoto il buffer per prepararlo all'arrivo della risposta

        int bytesRicevuti = recv(socketFD, bufferAux, BUFFER_MAX,0);   //questa operazione è bloccante come la accept lato server

        if(bytesRicevuti < 0){
            printf("Errore in ricezione\n");
            continue;
        }else if(bytesRicevuti == 0){
            printf("Il server ha chiuso la connessione o è caduta");
            break;
        }

        printf("Ho ricevuto %s\n", bufferAux);

    }
    close(socketFD);

} 

